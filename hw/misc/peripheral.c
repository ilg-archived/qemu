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

#include "hw/misc/peripheral.h"
#include "hw/arm/cortexm-helper.h"
#include "qemu/error-report.h"

/* ----- Public ------------------------------------------------------------ */

Object *peripheral_new_with_info(Object *parent_obj, const char *node_name,
        PeripheralInfo *info)
{
    Object *obj = parent_obj;
    if (node_name) {
        obj = cm_object_new(parent_obj, node_name, TYPE_PERIPHERAL);
    }
    /* TODO: Add properties. */

    if (info->registers) {
        PeripheralRegisterInfo *bifi_info;
        for (bifi_info = info->registers; bifi_info->name; ++bifi_info) {

            Object *bifi = peripheral_register_new_with_info(obj,
                    bifi_info->name, bifi_info);

            cm_object_realize(bifi);
        }
    }

    return obj;
}

/* ----- Private ----------------------------------------------------------- */

/**
 * Memory region read callback.
 *
 * Forward the read to the register. The basic register will do the
 * endiannes and size magic and return the value from the internal storage.
 *
 * For special processing, create a new derived type with custom read()
 * and add the required actions.
 */
static uint64_t peripheral_read_callback(void *opaque, hwaddr addr,
        unsigned size)
{
    PeripheralState *state = (PeripheralState *) opaque;
    PeripheralClass *per_class = PERIPHERAL_GET_CLASS(opaque);

    if (per_class->is_enabled) {
        if (!per_class->is_enabled(OBJECT(state))) {
            /* If peripheral is not enabled, return a convenience value. */
            return 0;
        }
    }

    uint32_t index = addr / state->register_size_bytes;
    assert(index < state->registers_size_ptrs);

    PeripheralRegisterState *reg = PERIPHERAL_REGISTER_STATE(
            state->registers[index]);
    if (reg == NULL) {
        qemu_log_mask(LOG_UNIMP, "%s: Peripheral read of size %d at offset "
                "0x%llX not implemented.\n", object_get_typename(OBJECT(state)),
                size, addr);
        return 0;
    }

    /* Align address to register margin and pass offset separately. */
    uint32_t reg_addr = addr & ~(state->register_size_bytes - 1);
    uint32_t reg_offset = addr & (state->register_size_bytes - 1);

    PeripheralRegisterClass *reg_class = PERIPHERAL_REGISTER_GET_CLASS(reg);

    /* Read the register value. */
    uint64_t value = 0;
    if (reg_class->read) {
        value = reg_class->read(OBJECT(reg), OBJECT(state), reg_addr,
                reg_offset, size);
    }

    return value;
}

/**
 * Memory region write callback.
 *
 * Forward the write to the register. The basic register will do the
 * endiannes and size magic and store the value internally.
 *
 * For special processing, create a new derived type with custom write()
 * and add the required actions.
 */
static void peripheral_write_callback(void *opaque, hwaddr addr, uint64_t value,
        unsigned size)
{
    PeripheralState *state = (PeripheralState *) opaque;

    PeripheralClass *per_class = PERIPHERAL_GET_CLASS(opaque);

    if (per_class->is_enabled) {
        if (!per_class->is_enabled(OBJECT(state))) {
            /* If peripheral is not enabled, do not attempt any write. */
            return;
        }
    }

    uint32_t index = addr / state->register_size_bytes;
    assert(index < state->registers_size_ptrs);

    PeripheralRegisterState *reg = PERIPHERAL_REGISTER_STATE(
            state->registers[index]);
    if (reg == NULL) {
        qemu_log_mask(LOG_UNIMP,
                "%s: Write of size %d at offset 0x%llX not implemented.\n",
                object_get_typename(OBJECT(state)), size, addr);
        return;
    }

    /* Align address to register margin and pass offset separately. */
    uint32_t reg_addr = addr & ~(state->register_size_bytes - 1);
    uint32_t reg_offset = addr & (state->register_size_bytes - 1);

    PeripheralRegisterClass *reg_class = PERIPHERAL_REGISTER_GET_CLASS(reg);
    /* Write the value to the register. */
    if (reg_class->write) {
        reg_class->write(OBJECT(reg), OBJECT(state), reg_addr, reg_offset, size,
                value);
    }

}

static const MemoryRegionOps register_ops = {
    .read = peripheral_read_callback,
    .write = peripheral_write_callback,
    .endianness = DEVICE_NATIVE_ENDIAN, };

static void peripheral_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    PeripheralState *state = PERIPHERAL_STATE(obj);

    cm_object_property_add_const_str(obj, "mmio-node-name",
            &state->mmio_node_name);
    state->mmio_node_name = NULL;

    cm_object_property_add_uint64(obj, "mmio-address", &state->mmio_address);
    state->mmio_address = 0;

    cm_object_property_add_uint32(obj, "mmio-size-bytes",
            &state->mmio_size_bytes);
    state->mmio_size_bytes = 0;

    cm_object_property_add_uint64(obj, "default-access-flags",
            &state->default_access_flags);
    /* Allow all */
    state->default_access_flags = PERIPHERAL_REGISTER_DEFAULT_ACCESS_FLAGS;

    cm_object_property_add_uint32(obj, "register-size-bytes",
            &state->register_size_bytes);
    state->register_size_bytes = PERIPHERAL_REGISTER_DEFAULT_SIZE_BYTES;

    cm_object_property_add_bool(obj, "is-little-endian",
            &state->is_little_endian);
    state->is_little_endian = true;
}

static int peripheral_compute_max_offset_foreach(Object *obj, void *opaque)
{
    PeripheralState *periph = PERIPHERAL_STATE(opaque);

    int count = 0;
    /* Process only children that descend from a register. */
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

    /* Process only children that descend from a register. */
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

    /* Call parent realize(). */
    if (!cm_device_parent_realize(dev, errp, TYPE_PERIPHERAL)) {
        return;
    }

    PeripheralState *state = PERIPHERAL_STATE(dev);

    const char *node_name = state->mmio_node_name;
    if (node_name == NULL) {
        node_name = "mmio";
    }
    memory_region_init_io(&state->mmio, OBJECT(dev), &register_ops, state,
            node_name, state->mmio_size_bytes);

    sysbus_init_mmio(SYS_BUS_DEVICE(dev), &state->mmio);
    sysbus_mmio_map(SYS_BUS_DEVICE(dev), 0x0, state->mmio_address);

    /*
     * For fast access, create an array of registers, indexed by
     * offset, aligned to register size (4 or 8).
     *
     * Warning: for large, sparse, peripherals, this might use a lot
     * of memory.
     */

    /* Iterate children and determine the last register. */
    state->max_offset_bytes = 0;
    object_child_foreach(OBJECT(dev), peripheral_compute_max_offset_foreach,
            (void *) dev);

    assert(state->max_offset_bytes < state->mmio_size_bytes);

    /* Compute the number of pointers the array should contain. */
    state->registers_size_ptrs = (state->max_offset_bytes
            / state->register_size_bytes) + 1;

    /* Allocate the array of pointers to registers. */
    state->registers = g_malloc0_n(state->registers_size_ptrs, sizeof(Object*));

    /* Fill in the array with pointers to registers. */
    object_child_foreach(OBJECT(dev),
            peripheral_populate_registers_array_foreach, (void *) dev);
}

static void peripheral_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    /* Call parent reset(). */
    cm_device_parent_reset(dev, TYPE_PERIPHERAL);

    PeripheralState *state = PERIPHERAL_STATE(dev);

    /* No bus used, explicitly reset all children registers. */
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
    .class_size = sizeof(PeripheralClass) };

static void peripheral_register_types(void)
{
    type_register_static(&peripheral_type_info);
}

type_init(peripheral_register_types);

/* ------------------------------------------------------------------------- */

