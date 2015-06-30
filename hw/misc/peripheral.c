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

/* ----- Public ------------------------------------------------------------ */

/* ----- Private ----------------------------------------------------------- */

#define STM32F1_FLASH_ACR_READ_MASK             (0x0000003F)
#define STM32F1_FLASH_ACR_WRITE_MASK            (0x0000001F)

static uint32_t acr;

static uint64_t peripheral_read_callback(void *opaque, hwaddr addr,
        unsigned size)
{
    PeripheralState *state = (PeripheralState *) opaque;
    uint32_t offset = addr;

    if (offset == 0) {
        return (acr & STM32F1_FLASH_ACR_READ_MASK);
    }
    return 0;
}

static void peripheral_write_callback(void *opaque, hwaddr addr, uint64_t value,
        unsigned size)
{
    PeripheralState *state = (PeripheralState *) opaque;
    uint32_t offset = addr;

    if (offset == 0) {
        uint32_t tmp;

        tmp = acr & (~STM32F1_FLASH_ACR_WRITE_MASK);
        tmp |= (value & STM32F1_FLASH_ACR_WRITE_MASK);
        tmp &= ~0x00000020; /* Clear ready bits */
        /* All enabled oscs are ready */
        tmp |= ((tmp & 0x00000010) << 1);
        acr = tmp;
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

    cm_object_property_add_uint32(obj, "mmio-size", &state->mmio_size);
    state->mmio_size = 0;

    cm_object_property_add_uint32(obj, "default-access-flags",
            &state->default_access_flags);
    /* Allow all */
    state->default_access_flags = PERIPHERAL_REGISTER_DEFAULT_ACCESS_FLAGS;
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
            node_name, state->mmio_size);

    sysbus_init_mmio(SYS_BUS_DEVICE(dev), &state->mmio);
    sysbus_mmio_map(SYS_BUS_DEVICE(dev), 0x0, state->mmio_address);

    /* ... */
}

static void peripheral_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    /* Call parent reset(). */
    cm_device_parent_reset(dev, TYPE_PERIPHERAL);

    PeripheralState *state = PERIPHERAL_STATE(dev);

    acr = 0;
    /* ... */
}

static void peripheral_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = peripheral_reset_callback;
    dc->realize = peripheral_realize_callback;
}

static const TypeInfo peripheral_type_info = {
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

