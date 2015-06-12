/*
 * Generic GPIO connected LED device emulation.
 *
 * Copyright (c) 2015 Liviu Ionescu
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

#ifndef GENERIC_GPIO_LED_H_
#define GENERIC_GPIO_LED_H_

#include "hw/qdev.h"
#include "qemu/typedefs.h"

/* ------------------------------------------------------------------------- */

#define DEFINE_PROP_GENERIC_GPIO_LED_PTR(_n, _s, _f) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_ptr, GenericGPIOLEDInfo*)

typedef struct {
    const char *name;
    int port_index;
    int port_bit; //
    bool active_low;
    const char *on_message;
    const char *off_message; //
    bool use_stderr;
} GenericGPIOLEDInfo;

/* ------------------------------------------------------------------------- */

#define TYPE_GENERIC_GPIO_LED "generic-gpio-led"

#define GENERIC_GPIO_LED_GET_CLASS(obj) \
    OBJECT_GET_CLASS(GenericGPIOLEDClass, (obj), TYPE_GENERIC_GPIO_LED)
#define GENERIC_GPIO_LED_CLASS(obj) \
    OBJECT_CLASS_CHECK(GenericGPIOLEDClass, (obj), TYPE_GENERIC_GPIO_LED)

typedef struct {
    /*< private >*/
    DeviceClass parent_class;
    /*< public >*/

    DeviceState *(*get_gpio_dev)(DeviceState *dev, int port_index);
} GenericGPIOLEDClass;

/* ------------------------------------------------------------------------- */

#define GENERIC_GPIO_LED_STATE(obj) \
    OBJECT_CHECK(GenericGPIOLEDState, (obj), TYPE_GENERIC_GPIO_LED)

typedef struct {
    /*< private >*/
    DeviceState parent_obj;
    /*< public >*/

    GenericGPIOLEDInfo *info;

    DeviceState *mcu;
    DeviceState *gpio;
    qemu_irq *irq;

} GenericGPIOLEDState;

/* ------------------------------------------------------------------------- */

#endif /* GENERIC_GPIO_LED_H_ */
