/*
 * Reset graphic button.
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

#include <hw/cortexm/button-reset.h>
#include <hw/cortexm/helper.h>

#include "qemu/log.h"
#include "sysemu/sysemu.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

// ----- Public ---------------------------------------------------------------

void button_reset_create_from_info(Object *parent, ButtonResetInfo *info,
        BoardGraphicContext *graphic_context)
{
    Object *button = cm_object_new(parent, "button:reset", TYPE_BUTTON_RESET);

    if (info->w && info->h) {
        /* Compute corner coordinates from centre coordinate. */
        cm_object_property_set_int(button, info->x - (info->w / 2), "x-left");
        cm_object_property_set_int(button, info->x + (info->w / 2), "x-right");
        cm_object_property_set_int(button, info->y - (info->h / 2), "y-top");
        cm_object_property_set_int(button, info->y + (info->h / 2), "y-bottom");
    }

    cm_object_realize(button);

    cortexm_graphic_board_add_button(graphic_context, BUTTON_STATE(button));

#if defined(CONFIG_VERBOSE)
    if (verbosity_level >= VERBOSITY_DETAILED) {
        printf("'%s'", object_get_canonical_path(button));
        if (info->w && info->h) {
            printf(" %d*%d @(%d,%d)", info->w, info->h, info->x, info->y);
        }
        printf("\n");
    }
#endif /* defined(CONFIG_VERBOSE) */
}

// ----- Private --------------------------------------------------------------

// Action when the button is pushed down.
static void button_reset_down_callback(ButtonState *button)
{
    qemu_log_function_name();

    printf("[%s down]", object_get_canonical_path_component(OBJECT(button)));

    qemu_reset_halt_request();
}

// Action when the button is released.
static void button_reset_up_callback(ButtonState *button)
{
    qemu_log_function_name();

    printf("[%s up]", object_get_canonical_path_component(OBJECT(button)));

    qemu_resume_request();
}

static void button_reset_instance_init_callback(Object *obj)
{
    qemu_log_function_name();
}

static void button_reset_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_BUTTON_RESET)) {
        return;
    }

}

// Currently not used.
static void button_reset_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_BUTTON_RESET);
}

static void button_reset_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    dc->reset = button_reset_reset_callback;
    dc->realize = button_reset_realize_callback;

    ButtonClass *bt_class = BUTTON_CLASS(klass);
    bt_class->down = button_reset_down_callback;
    bt_class->up = button_reset_up_callback;
}

static const TypeInfo button_reset_type_info = {
    .name = TYPE_BUTTON_RESET,
    .parent = TYPE_BUTTON_RESET_PARENT,
    .instance_size = sizeof(ButtonResetState),
    .instance_init = button_reset_instance_init_callback,
    .class_init = button_reset_class_init_callback,
    .class_size = sizeof(ButtonResetClass) };

static void button_reset_type_init(void)
{
    type_register_static(&button_reset_type_info);
}

type_init(button_reset_type_init);

// ----------------------------------------------------------------------------
