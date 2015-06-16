/*
 * STM32 GPIO connected LED device emulation.
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

#ifndef STM32_GPIO_LED_H_
#define STM32_GPIO_LED_H_

#include "hw/display/generic-gpio-led.h"

/* ------------------------------------------------------------------------- */

#define TYPE_STM32_GPIO_LED "stm32-gpio-led"

#define STM32_GPIO_LED_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32GPIOLEDClass, (obj), TYPE_STM32_GPIO_LED)
#define STM32_GPIO_LED_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32GPIOLEDClass, (klass), TYPE_STM32_GPIO_LED)

typedef struct {
    /*< private >*/
    GPIOLEDClass parent_class;
    /*< public >*/

    /**
     * Constructor; does not much, just passes the Info structure
     * and a pointer to the MCU to the base class.
     */
    void (*construct)(Object *obj, GPIOLEDInfo* info, DeviceState *mcu);
} STM32GPIOLEDClass;

/* ------------------------------------------------------------------------- */

#define STM32_GPIO_LED_STATE(obj) \
    OBJECT_CHECK(STM32GPIOState, (obj), TYPE_GENERIC_GPIO_LED)

typedef struct {
    /*< private >*/
    GPIOLEDState parent_obj;
    /*< public >*/

    /* Currently there is nothing new here. */
} STM32GPIOLEDState;

/* ------------------------------------------------------------------------- */

#endif /* STM32_GPIO_LED_H_ */
