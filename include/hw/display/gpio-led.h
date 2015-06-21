/*
 * GPIO connected LED device emulation.
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

#ifndef GPIO_LED_H_
#define GPIO_LED_H_

#include "hw/qdev.h"
#include "qemu/typedefs.h"
#include "hw/sysbus.h"

/* ------------------------------------------------------------------------- */

#define DEFINE_PROP_GPIO_LED_PTR(_n, _s, _f) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_ptr, GPIOLEDInfo*)

/* ------------------------------------------------------------------------- */

#define TYPE_GPIO_LED "gpio-led"

// TODO: Change this to TYPE_DEVICE
#define TYPE_GPIO_LED_PARENT TYPE_SYS_BUS_DEVICE
typedef SysBusDeviceClass GPIOLEDParentClass;
typedef SysBusDevice GPIOLEDParentState;

#define GPIO_LED_GET_CLASS(obj) \
    OBJECT_GET_CLASS(GPIOLEDClass, (obj), TYPE_GPIO_LED)
#define GPIO_LED_CLASS(klass) \
    OBJECT_CLASS_CHECK(GPIOLEDClass, (klass), TYPE_GPIO_LED)

/* ------------------------------------------------------------------------- */

typedef struct {
    /*< private >*/
    GPIOLEDParentClass parent_class;
    /*< public >*/

} GPIOLEDClass;

/* ------------------------------------------------------------------------- */

#define GPIO_LED_STATE(obj) \
    OBJECT_CHECK(GPIOLEDState, (obj), TYPE_GPIO_LED)

typedef struct {
    /*< private >*/
    GPIOLEDParentState parent_obj;
    /*< public >*/

    bool active_low;
    const char *on_message;
    const char *off_message;

    /**
     * The actual irq used to blink the LED. It works connected to
     * a GPIO device outgoing irq.
     */
    qemu_irq irq;

} GPIOLEDState;

void gpio_led_connect(DeviceState *dev, const char *port_name, int port_bit);

/* ------------------------------------------------------------------------- */

#endif /* GPIO_LED_H_ */
