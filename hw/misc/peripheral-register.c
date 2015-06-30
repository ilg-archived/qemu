/*
 * Peripheral register emulation.
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

#include "hw/misc/peripheral-register.h"
#include "hw/misc/peripheral.h"
#include "hw/arm/cortexm-helper.h"

/**
 * This file implements a peripheral register. It extends all shorter accesses
 * to register size and uses the defined masks to write/read the register.
 *
 * If custom read/write actions are needed, it is possible to define new
 * types that redefine these methods.
 */

static void derived_peripheral_register_instance_init_callback(Object *obj);
static void derived_peripheral_register_class_init_callback(ObjectClass *klass,
        void *data);

/* ----- Public ------------------------------------------------------------ */

uint64_t peripheral_register_get_value(Object* obj)
{
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(obj);

    return (state->value & state->readable_bits);
}

/**
 * Create a dynamic instance of the peripheral register object, using the
 * definitions in the Info structure. If present, children bitfields are
 * also created.
 */
Object *peripheral_register_new(Object *parent, const char *node_name,
        PeripheralRegisterInfo *info)
{
    Object *reg = cm_object_new(parent, node_name,
    TYPE_PERIPHERAL_REGISTER);

    cm_object_property_set_str(reg, node_name, "name");

    cm_object_property_set_int(reg, info->offset_bytes, "offset-bytes");
    if (info->reset_value != 0) {
        cm_object_property_set_int(reg, info->reset_value, "reset-value");
    }
    if (info->readable_bits != 0) {
        cm_object_property_set_int(reg, info->readable_bits, "readable-bits");
    }
    if (info->access_flags != 0) {
        cm_object_property_set_int(reg, info->access_flags, "access-flags");
    }

    int size_bits = 0;
    if (info->size_bits != 0) {
        size_bits = info->size_bits;
    } else {
        size_bits = PERIPHERAL_STATE(parent)->register_size_bits;
    }
    cm_object_property_set_int(reg, size_bits, "size-bits");

    if (info->bitfields) {

        RegisterBitfieldInfo *bifi_info;
        for (bifi_info = info->bitfields; bifi_info->name; ++bifi_info) {

            Object *bifi = cm_object_new(reg, bifi_info->name,
            TYPE_REGISTER_BITFIELD);

            cm_object_property_set_str(bifi, bifi_info->name, "name");

            assert(bifi_info->first_bit < 32);
            cm_object_property_set_int(bifi, bifi_info->first_bit, "first-bit");

            assert(bifi_info->last_bit < 32);
            if (bifi_info->last_bit != 0) {
                cm_object_property_set_int(bifi, bifi_info->last_bit,
                        "last-bit");
            }

            if (bifi_info->reset_value != 0) {
                cm_object_property_set_int(bifi, bifi_info->reset_value,
                        "reset-value");
            }

            if (bifi_info->rw_mode != 0) {
                if (bifi_info->rw_mode & REGISTER_RW_MODE_READ) {
                    cm_object_property_set_bool(bifi, true, "is-readable");
                } else {
                    cm_object_property_set_bool(bifi, false, "is-readable");
                }
                if (bifi_info->rw_mode & REGISTER_RW_MODE_WRITE) {
                    cm_object_property_set_bool(bifi, true, "is-writable");
                } else {
                    cm_object_property_set_bool(bifi, false, "is-writable");
                }
            }

            cm_object_property_set_int(bifi, size_bits, "register-size-bits");

            if (bifi_info->follows != NULL && strlen(bifi_info->follows) > 0) {
                cm_object_property_set_str(bifi, bifi_info->follows, "follows");
            }
            /* Should we delay until the register is realized()? */
            cm_object_realize(bifi);
        }
    }

    return reg;
}

Object *derived_peripheral_register_new(Object *parent, const char *node_name,
        const char *type_name)
{
    Object *obj = cm_object_new(parent, node_name, type_name);
    return obj;
}

void derived_peripheral_register_type_register(PeripheralRegisterTypeInfo *reg)
{
    TypeInfo ti = {
        .name = reg->name,
        .parent = TYPE_PERIPHERAL_REGISTER,
        .instance_init = derived_peripheral_register_instance_init_callback,
        .class_init = derived_peripheral_register_class_init_callback,
        .class_data = (void *) reg, /**/
    };

    type_register(&ti);
}

/* ----- Private ----------------------------------------------------------- */

static uint64_t peripheral_register_read_callback(Object *obj, hwaddr addr,
        unsigned size)
{
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(obj);

    uint64_t value = state->value & state->readable_bits;

    // TODO: consider size
    return value;
}

static void peripheral_register_write_callback(Object *obj, hwaddr addr,
        unsigned size, uint64_t value)
{
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(obj);

    uint32_t tmp;
    tmp = state->value & (~state->writable_bits);
    tmp |= (value & state->writable_bits);
    // TODO: process auto bits

    state->value = tmp;
}

/* ------------------------------------------------------------------------- */

static void peripheral_register_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(obj);

    /* Add properties and set default values. */

    cm_object_property_add_const_str(obj, "name", &state->name);
    state->name = NULL;

    cm_object_property_add_uint64(obj, "offset-bytes", &state->offset_bytes);
    state->offset_bytes = 0x00000000;

    cm_object_property_add_uint64(obj, "reset-value", &state->reset_value);
    state->reset_value = 0x00000000;

    cm_object_property_add_uint64(obj, "readable-bits", &state->readable_bits);
    state->readable_bits = 0xFFFFFFFF;

    cm_object_property_add_uint64(obj, "writable-bits", &state->writable_bits);
    state->writable_bits = 0xFFFFFFFF;

    cm_object_property_add_uint32(obj, "access-flags", &state->access_flags);
    state->access_flags = PERIPHERAL_REGISTER_DEFAULT_ACCESS_FLAGS;

    cm_object_property_add_uint32(obj, "size-bits", &state->size_bits);
    /* Intentional 0. Default set again in realize(), possibly from parent. */
    state->size_bits = 0;

    cm_object_property_add_bool(obj, "is-readable", &state->is_readable);
    state->is_readable = true;

    cm_object_property_add_bool(obj, "is-writable", &state->is_writable);
    state->is_writable = true;

    /* Reset value. */
    state->value = 0x00000000;
}

#if 1
static void peripheral_register_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /* Call parent realize(). */
    if (!cm_device_parent_realize(dev, errp, TYPE_PERIPHERAL_REGISTER)) {
        return;
    }

    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(dev);

    if (state->size_bits == 0) {

        PeripheralState *parent = PERIPHERAL_STATE(
                cm_object_get_parent(OBJECT(dev)));

        if (parent->register_size_bits != 0) {
            state->size_bits = parent->register_size_bits;
        } else {
            state->size_bits = PERIPHERAL_REGISTER_DEFAULT_SIZE_BITS;
        }
    }

    /* Clear readable bits if non-readable. */
    if (!state->is_readable) {
        state->readable_bits = 0;
    }

    /* Clear writable bits if non-writable. */
    if (!state->is_writable) {
        state->writable_bits = 0;
    }
}
#endif

static void peripheral_register_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    /* Call parent reset(). */
    cm_device_parent_reset(dev, TYPE_PERIPHERAL_REGISTER);

    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(dev);

    state->value = state->reset_value;
}

static void peripheral_register_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = peripheral_register_reset_callback;
    dc->realize = peripheral_register_realize_callback;

    PeripheralRegisterClass *pr_class = PERIPHERAL_REGISTER_CLASS(klass);
    pr_class->read = peripheral_register_read_callback;
    pr_class->write = peripheral_register_write_callback;
}

static const TypeInfo peripheral_register_type_info = {
    .name = TYPE_PERIPHERAL_REGISTER,
    .parent = TYPE_PERIPHERAL_REGISTER_PARENT,
    .instance_init = peripheral_register_instance_init_callback,
    .instance_size = sizeof(PeripheralRegisterState),
    .class_init = peripheral_register_class_init,
    .class_size = sizeof(PeripheralRegisterClass) };

static void register_peripheral_register_types(void)
{
    type_register_static(&peripheral_register_type_info);
}

type_init(register_peripheral_register_types);

/* ------------------------------------------------------------------------- */

static void derived_peripheral_register_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    const char *type_name = object_get_typename(obj);
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(obj);
    PeripheralRegisterDerivedClass *klass =
            PERIPHERAL_REGISTER_DERIVED_GET_CLASS(obj, type_name);

    /*
     * After properties are set with default values, copy actual
     * values from class, if present.
     */
    state->offset_bytes = klass->offset_bytes;
    state->reset_value = klass->reset_value;
    if (klass->readable_bits != 0) {
        state->readable_bits = klass->readable_bits;
    }
    if (state->writable_bits != 0) {
        state->writable_bits = klass->writable_bits;
    }
    if (klass->access_flags != 0) {
        state->access_flags = klass->access_flags;
    }
    if (klass->rw_mode != 0) {
        if (klass->rw_mode & REGISTER_RW_MODE_READ) {
            state->is_readable = true;
        } else {
            state->is_readable = false;
        }
        if (klass->rw_mode & REGISTER_RW_MODE_WRITE) {
            state->is_writable = true;
        } else {
            state->is_writable = false;
        }
    } else {
        /* Default both read and write. */
        state->is_readable = true;
        state->is_writable = true;
    }

    if (klass->size_bits != 0) {
        state->size_bits = klass->size_bits;
    }

    state->value = klass->reset_value;
}

static void derived_peripheral_register_class_init_callback(ObjectClass *klass,
        void *data)
{
    PeripheralRegisterTypeInfo *ti = (PeripheralRegisterTypeInfo *) data;
    PeripheralRegisterClass *pr_class = PERIPHERAL_REGISTER_CLASS(klass);

    pr_class->read = ti->read;
    pr_class->write = ti->write;

    const char *type_name = object_class_get_name(klass);
    PeripheralRegisterDerivedClass *prd_class =
            PERIPHERAL_REGISTER_DERIVED_CLASS(klass, type_name);

    /* Copy info members into class. */
    prd_class->name = ti->name;
    prd_class->desc = ti->desc;
    prd_class->offset_bytes = ti->offset_bytes;
    prd_class->reset_value = ti->reset_value;
    prd_class->readable_bits = ti->readable_bits;
    prd_class->writable_bits = ti->writable_bits;
    prd_class->access_flags = ti->access_flags;
    prd_class->rw_mode = ti->rw_mode;
    prd_class->size_bits = ti->size_bits;

    prd_class->bitfields = ti->bitfields;
}

/* ------------------------------------------------------------------------- */

