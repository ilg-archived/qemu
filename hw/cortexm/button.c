/*
 * Abstract graphic button.
 *
 * Copyright (c) 2016 Liviu Ionescu.
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

#include <hw/cortexm/button.h>
#include <hw/cortexm/helper.h>

#include "qemu/log.h"

// ----- Public ---------------------------------------------------------------

// ----- Private --------------------------------------------------------------

static void button_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    ButtonState *state = BUTTON_STATE(obj);

    state->value = 0;

#if defined(CONFIG_SDL)

    state->position.x_left = 0;
    state->position.x_right = 0;

    state->position.y_top = 0;
    state->position.y_bottom = 0;

    cm_object_property_add_int(obj, "x-left",
            (const int *) &state->position.x_left);
    cm_object_property_add_int(obj, "x-right",
            (const int *) &state->position.x_right);

    cm_object_property_add_int(obj, "y-top",
            (const int *) &state->position.y_top);
    cm_object_property_add_int(obj, "y-bottom",
            (const int *) &state->position.y_bottom);

#endif /* defined(CONFIG_SDL) */
}

static void button_class_init_callback(ObjectClass *klass, void *data)
{
    // Derived classes must define the realize_callback.
    // DeviceClass *dc = DEVICE_CLASS(klass);
    // dc->realize = button_realize_callback;
}

static const TypeInfo button_type_info = {
    .name = TYPE_BUTTON,
    .parent = TYPE_BUTTON_PARENT,
    .abstract = true,
    .instance_size = sizeof(ButtonState),
    .instance_init = button_instance_init_callback,
    .class_init = button_class_init_callback,
    .class_size = sizeof(ButtonClass)
/**/
};

static void button_type_init(void)
{
    type_register_static(&button_type_info);
}

type_init(button_type_init);

// ----------------------------------------------------------------------------
