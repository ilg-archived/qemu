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

#include "hw/misc/register.h"
#include "hw/arm/cortexm-helper.h"

/**
 * This file implements a peripheral register. It extends all shorter accesses
 * to register size and uses the defined masks to write/read the register.
 */

/* ----- Public ------------------------------------------------------------ */

uint64_t register_get_value(Object* obj)
{
    RegisterState *state = REGISTER_STATE(obj);

    return (state->value & state->readable_bits);
}

/* ----- Private ----------------------------------------------------------- */

#if 0
static void register_instance_init(Object *obj)
{
    qemu_log_function_name();

    RegisterState *state = REGISTER_STATE(obj);

    /* ... */
}
#endif

static void register_realize(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /* Call parent realize(). */
    if (!cm_device_parent_realize(dev, errp, TYPE_REGISTER)) {
        return;
    }

    RegisterState *state = REGISTER_STATE(dev);

    /* ... */
}

static void register_reset(DeviceState *dev)
{
    qemu_log_function_name();

    /* Call parent reset(). */
    cm_device_parent_reset(dev, TYPE_REGISTER);

    RegisterState *state = REGISTER_STATE(dev);

    state->value = state->reset_value;
}

static Property register_properties[] = {

        DEFINE_PROP_UINT64("offset", RegisterState, offset,
                0x00000000),
        DEFINE_PROP_UINT64("reset-value", RegisterState, reset_value,
                0x00000000),
        DEFINE_PROP_UINT64("readable-bits", RegisterState, readable_bits,
                0xFFFFFFFF),
        DEFINE_PROP_UINT64("writable-bits", RegisterState, writable_bits,
                0xFFFFFFFF),
        DEFINE_PROP_UINT32("access-flags", RegisterState, access_flags,
                REGISTER_DEFAULT_ACCESS_FLAGS),
        DEFINE_PROP_UINT32("array-size", RegisterState, array_size,
                0),

    DEFINE_PROP_END_OF_LIST(), };

static void register_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = register_reset;
    dc->realize = register_realize;
    dc->props = register_properties;
}

static const TypeInfo register_type_info = {
    .name = TYPE_REGISTER,
    .parent = TYPE_REGISTER_PARENT,
    //.instance_init = register_instance_init,
    .instance_size = sizeof(RegisterState),
    .class_init = register_class_init,
    .class_size = sizeof(RegisterClass) };

static void register_register_types(void)
{
    type_register_static(&register_type_info);
}

type_init(register_register_types);

/* ------------------------------------------------------------------------- */

