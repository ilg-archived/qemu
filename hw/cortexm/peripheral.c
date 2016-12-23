/*
 * 32-bits peripheral emulation.
 *
 * Copyright (c) 2015 Liviu Ionescu.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

#include "qemu/error-report.h"

#include "qapi/qmp/qstring.h"
#include "migration/qjson.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

// ----- Public ---------------------------------------------------------------

// Set the peripheral properties and add children registers from the
// info structure.

Object *peripheral_add_properties_and_children(Object *obj,
        PeripheralInfo *info)
{
    if (info->default_access_flags != 0) {
        cm_object_property_set_int(obj, info->default_access_flags,
                "default-access-flags");
    }

    if (info->register_size_bytes != 0) {
        cm_object_property_set_int(obj, info->register_size_bytes,
                "register-size-bytes");
    }

    if (info->registers) {
        PeripheralRegisterInfo *regs_info;
        for (regs_info = info->registers; regs_info->name; ++regs_info) {

            Object *reg = cm_object_new(obj, regs_info->name,
            TYPE_PERIPHERAL_REGISTER);

            // Store a local copy of the node name, for easier access.
            cm_object_property_set_str(reg, regs_info->name, "name");

            peripheral_register_add_properties_and_children(reg, regs_info);

            cm_object_realize(reg);
        }
    }

    return obj;
}

static const MemoryRegionOps register_ops;

void peripheral_create_memory_region(Object *obj)
{
    PeripheralState *state = PERIPHERAL_STATE(obj);
    DeviceState *dev = DEVICE(obj);

    const char *node_name = state->mmio_node_name;
    if (node_name == NULL) {
        node_name = "mmio";
    }
    memory_region_init_io(&state->mmio, OBJECT(dev), &register_ops, state,
            node_name, state->mmio_size_bytes);

    sysbus_init_mmio(SYS_BUS_DEVICE(dev), &state->mmio);
    sysbus_mmio_map(SYS_BUS_DEVICE(dev), 0x0, state->mmio_address);

    qemu_log_mask(LOG_FUNC,
            "%s() '%s', address: 0x%08"PRIX64", size: 0x%04"PRIX32"\n",
            __FUNCTION__, state->mmio_node_name, state->mmio_address,
            state->mmio_size_bytes);

#if defined(CONFIG_VERBOSE)
    if (verbosity_level >= VERBOSITY_DETAILED) {
        printf("'%s', address: 0x%08"PRIX64", size: 0x%04"PRIX32"\n",
                object_get_canonical_path(obj), state->mmio_address,
                state->mmio_size_bytes);
    }
#endif /* defined(CONFIG_VERBOSE) */

}

static int peripheral_compute_max_offset_foreach(Object *obj, void *opaque);
static int peripheral_populate_registers_array_foreach(Object *obj,
        void *opaque);

// For fast access, create an array of registers, indexed by
// offset, aligned to register size (4 or 8).
//
// Warning: for large, sparse, peripherals, this might use a lot
// of memory.

void peripheral_prepare_registers(Object *obj)
{
    PeripheralState *state = PERIPHERAL_STATE(obj);
    DeviceState *dev = DEVICE(obj);

    // Iterate children and determine the last register.
    state->max_offset_bytes = 0;
    object_child_foreach(OBJECT(dev), peripheral_compute_max_offset_foreach,
            (void *) dev);

    assert(state->max_offset_bytes < state->mmio_size_bytes);

    // Compute the number of pointers the array should contain.
    state->registers_size_ptrs = (state->max_offset_bytes
            / state->register_size_bytes) + 1;

    // Allocate the array of pointers to registers.
    state->registers = g_malloc0_n(state->registers_size_ptrs, sizeof(Object*));

    // Fill in the array with pointers to registers.
    object_child_foreach(OBJECT(dev),
            peripheral_populate_registers_array_foreach, (void *) dev);
}

// ----- Private --------------------------------------------------------------

// Memory region read callback.
//
// Forward the read to the register. The basic register will do the
// endianness and size magic and return the value from the internal storage.
//
// For special processing, create a new derived type with custom read()
// and add the required actions.
//
static uint64_t peripheral_read_callback(void *opaque, hwaddr addr,
        unsigned size)
{
    PeripheralState *state = (PeripheralState *) opaque;
    PeripheralClass *per_class = PERIPHERAL_GET_CLASS(opaque);

    if (per_class->is_enabled) {
        if (!per_class->is_enabled(OBJECT(state))) {
            // For all peripherals, when the peripheral is not active,
            // the peripheral register values may not be readable by
            // software and the returned value is always 0x0.
            qemu_log_mask(LOG_GUEST_ERROR,
                    "%s: Peripheral read of size %d at offset " "0x%"PRIX64 " on disabled peripheral, returns 0.\n",
                    object_get_typename(OBJECT(state)), size, addr);
            return 0;
        }
    }

    uint32_t index = addr / state->register_size_bytes;

#if 0
    assert(index < state->registers_size_ptrs);
#else
    if (index >= state->registers_size_ptrs) {
        qemu_log_mask(LOG_UNIMP,
                "%s: Peripheral read of size %d at offset " "0x%"PRIX64" outside peripheral area.\n",
                object_get_typename(OBJECT(state)), size, addr);
        return 0;
    }
#endif

    PeripheralRegisterState *reg = PERIPHERAL_REGISTER_STATE(
            state->registers[index]);
    if (reg == NULL) {
        qemu_log_mask(LOG_UNIMP,
                "%s: Peripheral read of size %d at offset " "0x%"PRIX64" not implemented.\n",
                object_get_typename(OBJECT(state)), size, addr);
        return 0;
    }

    // Align address to register margin and pass offset separately.
    uint32_t reg_addr = addr & ~(state->register_size_bytes - 1);
    uint32_t reg_offset = addr & (state->register_size_bytes - 1);

    PeripheralRegisterClass *reg_class = PERIPHERAL_REGISTER_GET_CLASS(reg);

    // Read the register value.
    uint64_t value = 0;
    if (reg_class->read) {
        value = reg_class->read(OBJECT(reg), OBJECT(state), reg_addr,
                reg_offset, size);
    }

    return value;
}

// Memory region write callback.
//
// Forward the write to the register. The basic register will do the
// endianness and size magic and store the value internally.
//
// For special processing, create a new derived type with custom write()
// and add the required actions.
//
static void peripheral_write_callback(void *opaque, hwaddr addr, uint64_t value,
        unsigned size)
{
    PeripheralState *state = (PeripheralState *) opaque;

    PeripheralClass *per_class = PERIPHERAL_GET_CLASS(opaque);

    if (per_class->is_enabled) {
        if (!per_class->is_enabled(OBJECT(state))) {
            // For all peripherals, when the peripheral is not active,
            // the peripheral register values may not be written by
            // software.
            qemu_log_mask(LOG_GUEST_ERROR,
                    "%s: Write of size %d at offset 0x%"PRIX64 " on disabled peripheral, ignored.\n",
                    object_get_typename(OBJECT(state)), size, addr);
            return;
        }
    }

    uint32_t index = addr / state->register_size_bytes;
#if 0
    assert(index < state->registers_size_ptrs);
#else
    if (index >= state->registers_size_ptrs) {
        qemu_log_mask(LOG_UNIMP,
                "%s: Peripheral write of size %d at offset " "0x%"PRIX64" outside peripheral area.\n",
                object_get_typename(OBJECT(state)), size, addr);
        return;
    }
#endif

    // Identify the register inside the peripheral, by index.
    PeripheralRegisterState *reg = PERIPHERAL_REGISTER_STATE(
            state->registers[index]);
    if (reg == NULL) {
        qemu_log_mask(LOG_UNIMP,
                "%s: Write of size %d at offset 0x%"PRIX64" not implemented.\n",
                object_get_typename(OBJECT(state)), size, addr);
        return;
    }

    // Align address to register margin and pass offset separately.
    uint32_t reg_addr = addr & ~(state->register_size_bytes - 1);
    uint32_t reg_offset = addr & (state->register_size_bytes - 1);

    PeripheralRegisterClass *reg_class = PERIPHERAL_REGISTER_GET_CLASS(reg);
    // Write the value to the register.
    if (reg_class->write) {
        reg_class->write(OBJECT(reg), OBJECT(state), reg_addr, reg_offset, size,
                value);
    }

}

static const MemoryRegionOps register_ops = {
    .read = peripheral_read_callback,
    .write = peripheral_write_callback,
    .endianness = DEVICE_NATIVE_ENDIAN,
/**/
};

static void peripheral_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    PeripheralState *state = PERIPHERAL_STATE(obj);

    cm_object_property_add_const_str(obj, "mmio-node-name",
            &state->mmio_node_name);
    // Alias to the same variable.
    cm_object_property_add_const_str(obj, "name", &state->mmio_node_name);
    state->mmio_node_name = NULL;

    cm_object_property_add_uint64_callback(obj, "mmio-address",
            &state->mmio_address);
    state->mmio_address = 0;

    cm_object_property_add_uint32(obj, "mmio-size-bytes",
            &state->mmio_size_bytes);
    state->mmio_size_bytes = 0;

    cm_object_property_add_uint64_callback(obj, "default-access-flags",
            &state->default_access_flags);
    // Allow all
    state->default_access_flags = PERIPHERAL_REGISTER_DEFAULT_ACCESS_FLAGS;

    cm_object_property_add_uint32(obj, "register-size-bytes",
            &state->register_size_bytes);
    state->register_size_bytes = PERIPHERAL_REGISTER_DEFAULT_SIZE_BYTES;

    cm_object_property_add_bool(obj, "is-little-endian",
            &state->is_little_endian);
    state->is_little_endian = true;

    cm_object_property_add_const_str(obj, "svd-size", &state->svd.size);
    state->svd.size = NULL;

    cm_object_property_add_const_str(obj, "svd-access", &state->svd.access);
    state->svd.access = NULL;

    cm_object_property_add_const_str(obj, "svd-protection",
            &state->svd.protection);
    state->svd.protection = NULL;

    cm_object_property_add_const_str(obj, "svd-reset-value",
            &state->svd.reset_value);
    state->svd.reset_value = NULL;

    cm_object_property_add_const_str(obj, "svd-reset-mask",
            &state->svd.reset_mask);
    state->svd.reset_mask = NULL;
}

static int peripheral_compute_max_offset_foreach(Object *obj, void *opaque)
{
    PeripheralState *periph = PERIPHERAL_STATE(opaque);

    int count = 0;
    // Process only children that descend from a register.
    if (cm_object_is_instance_of_typename(obj, TYPE_PERIPHERAL_REGISTER)) {
        PeripheralRegisterState *reg = PERIPHERAL_REGISTER_STATE(obj);
        if (reg->offset_bytes > periph->max_offset_bytes) {
            periph->max_offset_bytes = reg->offset_bytes;
        }
        count++;
    }
    periph->num_registers = count;
    return 0;
}

static int peripheral_populate_registers_array_foreach(Object *obj,
        void *opaque)
{
    PeripheralState *periph = PERIPHERAL_STATE(opaque);

    // Process only children that descend from a register.
    if (cm_object_is_instance_of_typename(obj, TYPE_PERIPHERAL_REGISTER)) {
        PeripheralRegisterState *reg = PERIPHERAL_REGISTER_STATE(obj);

        uint32_t index = reg->offset_bytes / periph->register_size_bytes;
        assert(index < periph->registers_size_ptrs);
        if (periph->registers[index]) {
            error_report("Register %s overlaps %s at 0x%X", reg->name,
            PERIPHERAL_REGISTER_STATE(periph->registers[index])->name,
                    reg->offset_bytes);
        }

        periph->registers[index] = obj;

        peripheral_register_compute_auto_bits(obj);
    }

    return 0;
}

static void peripheral_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_PERIPHERAL)) {
        return;
    }

    // PeripheralState *state = PERIPHERAL_STATE(dev);
}

static void peripheral_reset_callback(DeviceState *dev)
{
    PeripheralState *state = PERIPHERAL_STATE(dev);

    assert(state->mmio_address != 0);

    qemu_log_mask(LOG_FUNC, "%s() '%s', address: 0x%08"PRIX64"\n", __FUNCTION__,
            state->mmio_node_name, state->mmio_address);

    // Call parent reset().
    cm_device_parent_reset(dev, TYPE_PERIPHERAL);

    assert(state->registers != NULL);

    // No bus used, explicitly reset all children registers.
    int i;
    for (i = 0; i < state->registers_size_ptrs; ++i) {
        if (state->registers[i] != NULL) {
            device_reset(DEVICE(state->registers[i]));
        }
    }
}

static void peripheral_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = peripheral_reset_callback;
    dc->realize = peripheral_realize_callback;
}

static const TypeInfo peripheral_type_info = {
    .abstract = true,
    .name = TYPE_PERIPHERAL,
    .parent = TYPE_PERIPHERAL_PARENT,
    .instance_init = peripheral_instance_init_callback,
    .instance_size = sizeof(PeripheralState),
    .class_init = peripheral_class_init,
    .class_size = sizeof(PeripheralClass)
/**/
};

static void peripheral_register_types(void)
{
    type_register_static(&peripheral_type_info);
}

type_init(peripheral_register_types);

// ----------------------------------------------------------------------------

