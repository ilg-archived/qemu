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
#include "hw/sysbus.h"

/* ------------------------------------------------------------------------- */

#define DEFINE_PROP_GPIO_LED_PTR(_n, _s, _f) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_ptr, GPIOLEDInfo*)

/**
 * This structure must be passed via the constructor, to configure the
 * LED connectivity, logic and message.
 */
typedef struct {
    const char *desc;
    int port_index;
    int port_bit; //
    bool active_low;
    const char *on_message;
    const char *off_message; //
} GPIOLEDInfo;

/* ------------------------------------------------------------------------- */

#define TYPE_GPIO_LED "gpio-led"

#define GPIO_LED_GET_CLASS(obj) \
    OBJECT_GET_CLASS(GPIOLEDClass, (obj), TYPE_GPIO_LED)
#define GPIO_LED_CLASS(klass) \
    OBJECT_CLASS_CHECK(GPIOLEDClass, (klass), TYPE_GPIO_LED)

// TODO: Change this to TYPE_DEVICE
#define TYPE_GPIO_LED_PARENT TYPE_SYS_BUS_DEVICE
typedef SysBusDeviceClass GPIOLEDParentClass;
typedef SysBusDevice GPIOLEDParentState;

typedef struct {
    /*< private >*/
    GPIOLEDParentClass parent_class;
    /*< public >*/

    /**
     * Constructor; it uses the Info structure and a pointer to the MCU
     * to get the GPIO(n) port and to connect to the pin.
     */
    void (*construct)(Object *obj, GPIOLEDInfo* info);

} GPIOLEDClass;

/* ------------------------------------------------------------------------- */

#define GPIO_LED_STATE(obj) \
    OBJECT_CHECK(GPIOLEDState, (obj), TYPE_GPIO_LED)

typedef struct {
    /*< private >*/
    GPIOLEDParentState parent_obj;
    /*< public >*/

    GPIOLEDInfo *info;

    /**
     * The actual irq used to blink the LED. It works connected to
     * a GPIO device outgoing irq.
     */
    qemu_irq irq;

} GPIOLEDState;

/* ------------------------------------------------------------------------- */

#endif /* GENERIC_GPIO_LED_H_ */
