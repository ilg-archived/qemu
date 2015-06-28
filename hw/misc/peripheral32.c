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

#include "hw/misc/peripheral32.h"
#include "hw/arm/cortexm-helper.h"

/* ----- Public ------------------------------------------------------------ */

void peripheral32_add_registers(DeviceState *dev, RegisterInfo *regs)
{
    RegisterInfo *preg;
    for (preg = regs; preg->name; ++preg) {

        Object *obj_reg = cm_object_new(OBJECT(dev), preg->name,
        TYPE_REGISTER);

        printf("Register %s\n", preg->name);
        cm_object_property_set_int(obj_reg, preg->offset, "offset");
        cm_object_property_set_int(obj_reg, preg->reset_value, "reset-value");
        cm_object_property_set_int(obj_reg, preg->readable_bits,
                "readable-bits");
        cm_object_property_set_int(obj_reg, preg->access_flags, "access-flags");
        cm_object_property_set_int(obj_reg, preg->array_size, "array-size");

        if (preg->bitfields) {

            BitfieldInfo *pbf;
            for (pbf = preg->bitfields; pbf->name; ++pbf) {
                printf("Bitfield %s\n", pbf->name);

                Object *obj_bf = cm_object_new(obj_reg, pbf->name,
                TYPE_BITFIELD);

                assert(pbf->first_bit < 32);
                cm_object_property_set_int(obj_bf, pbf->first_bit, "first-bit");

                assert(pbf->last_bit < 32);
                cm_object_property_set_int(obj_bf, pbf->last_bit, "last-bit");
                cm_object_property_set_int(obj_bf, pbf->reset_value,
                        "reset-value");
                if (pbf->mode & BITFIELD_MODE_READ) {
                    cm_object_property_set_bool(obj_bf, true, "is-readable");
                }
                if (pbf->mode & BITFIELD_MODE_WRITE) {
                    cm_object_property_set_bool(obj_bf, true, "is-writable");
                }
                cm_object_property_set_str(obj_bf, pbf->follows, "follows");

                cm_object_realize(obj_bf);
            }
        }
        cm_object_realize(obj_reg);
    }
}

/* ----- Private ----------------------------------------------------------- */

#define STM32F1_FLASH_ACR_READ_MASK             (0x0000003F)
#define STM32F1_FLASH_ACR_WRITE_MASK            (0x0000001F)

static uint32_t acr;

static uint64_t peripheral32_read_callback(void *opaque, hwaddr addr,
        unsigned size)
{
    Peripheral32State *state = (Peripheral32State *) opaque;
    uint32_t offset = addr;

    if (offset == 0) {
        return (acr & STM32F1_FLASH_ACR_READ_MASK);
    }
    return 0;
}

static void peripheral32_write_callback(void *opaque, hwaddr addr,
        uint64_t value, unsigned size)
{
    Peripheral32State *state = (Peripheral32State *) opaque;
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

static const MemoryRegionOps register32_ops = {
    .read = peripheral32_read_callback,
    .write = peripheral32_write_callback,
    .endianness = DEVICE_NATIVE_ENDIAN, };

static void peripheral32_instance_init(Object *obj)
{
    qemu_log_function_name();

    Peripheral32State *state = PERIPHERAL32_STATE(obj);

    /* ... */
}

static void peripheral32_realize(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /* Call parent realize(). */
    if (!cm_device_parent_realize(dev, errp, TYPE_PERIPHERAL32)) {
        return;
    }

    Peripheral32State *state = PERIPHERAL32_STATE(dev);

    const char *node_name = state->mmio_node_name;
    if (node_name == NULL) {
        node_name = "mmio";
    }
    memory_region_init_io(&state->mmio, OBJECT(dev), &register32_ops, state,
            node_name, state->mmio_size);

    sysbus_init_mmio(SYS_BUS_DEVICE(dev), &state->mmio);
    sysbus_mmio_map(SYS_BUS_DEVICE(dev), 0x0, state->mmio_address);

    /* ... */
}

static void peripheral32_reset(DeviceState *dev)
{
    qemu_log_function_name();

    /* Call parent reset(). */
    cm_device_parent_reset(dev, TYPE_PERIPHERAL32);

    Peripheral32State *state = PERIPHERAL32_STATE(dev);

    acr = 0;
    /* ... */
}

static Property peripheral32_properties[] = {
        DEFINE_PROP_CONST_STRING("mmio-node-name", Peripheral32State, mmio_node_name),
        DEFINE_PROP_UINT64("mmio-address", Peripheral32State, mmio_address, 0),
        DEFINE_PROP_UINT32("mmio-size", Peripheral32State, mmio_size, 0),
        DEFINE_PROP_UINT32("default-access-flags", Peripheral32State,
                default_access_flags, 0xFFF), /* Allow all */
    DEFINE_PROP_END_OF_LIST() };

static void peripheral32_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = peripheral32_reset;
    dc->realize = peripheral32_realize;
    dc->props = peripheral32_properties;
}

static const TypeInfo peripheral32_type_info = {
    .name = TYPE_PERIPHERAL32,
    .parent = TYPE_PERIPHERAL32_PARENT,
    .instance_init = peripheral32_instance_init,
    .instance_size = sizeof(Peripheral32State),
    .class_init = peripheral32_class_init,
    .class_size = sizeof(Peripheral32Class) };

static void peripheral32_register_types(void)
{
    type_register_static(&peripheral32_type_info);
}

type_init(peripheral32_register_types);

/* ------------------------------------------------------------------------- */

