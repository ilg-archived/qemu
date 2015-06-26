/*
 * 32-bits register emulation.
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

#include "hw/misc/register32.h"
#include "hw/arm/cortexm-helper.h"

/**
 * This file implements a 32-bits register. It extends all shorter accesses
 * to 32-bits and uses the defined masks to write/read the register.
 */


/* ----- Private ----------------------------------------------------------- */


static void register32_instance_init(Object *obj)
{
    qemu_log_function_name();

    Register32State *state = REGISTER32_STATE(obj);

    /* ... */
}

static void register32_realize(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /* Call parent realize(). */
    if (!cm_object_parent_realize(dev, errp, TYPE_REGISTER32)) {
        return;
    }

    Register32State *state = REGISTER32_STATE(dev);


    /* ... */
}

static void register32_reset(DeviceState *dev)
{
    qemu_log_function_name();

    /* Call parent reset(). */
    cm_object_parent_reset(dev, TYPE_REGISTER32);
  
    Register32State *state = REGISTER32_STATE(dev);

    /* ... */
}

static void register32_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = register32_reset;
    dc->realize = register32_realize;
}

static const TypeInfo register32_type_info = {
    .name = TYPE_REGISTER32,
    .parent = TYPE_REGISTER32_PARENT,
    .instance_init = register32_instance_init,
    .instance_size = sizeof(Register32State),
    .class_init = register32_class_init,
    .class_size = sizeof(Register32Class) };

static void register32_register_type(void)
{
    type_register_static(&register32_type_info);
}

type_init(register32_register_type);

/* ------------------------------------------------------------------------- */

