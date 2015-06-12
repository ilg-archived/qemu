/*
 * STM32 MCU - GPIO.
 *
 * Copyright (c) 2015 Liviu Ionescu
 * Copyright (c) 2010 Andre Beckus
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

#ifndef STM32_GPIO_H_
#define STM32_GPIO_H_

#include "config.h"
#include "hw/misc/stm32-sys-bus-device.h"
#include "exec/address-spaces.h"
#include "hw/misc/stm32-rcc.h"

#define TYPE_STM32_GPIO "stm32-gpio"

#define STM32_GPIO_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32GPIOClass, (obj), TYPE_STM32_GPIO)
#define STM32_GPIO_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32GPIOClass, (klass), TYPE_STM32_GPIO)

typedef struct {
    /*< private >*/
    SysBusDeviceClass parent_class;
    /*< public >*/

    /* No local virtual functions */
} STM32GPIOClass;

typedef enum {
    STM32_GPIO_PORT_A = 0,
    STM32_GPIO_PORT_B,
    STM32_GPIO_PORT_C,
    STM32_GPIO_PORT_D,
    STM32_GPIO_PORT_E,
    STM32_GPIO_PORT_F,
    STM32_GPIO_PORT_G,
    STM32_GPIO_PORT_UNDEFINED,
} stm32_gpio_index_t;

#define STM32_GPIO_PIN_COUNT    (16)

#define STM32_GPIO_STATE(obj) \
    OBJECT_CHECK(STM32GPIOState, (obj), TYPE_STM32_GPIO)

typedef struct {
    /*< private >*/
    STM32SysBusDevice parent_obj;
    /*< public >*/

    MemoryRegion mmio;

    stm32_gpio_index_t port_index;

    STM32RCCState* rcc;

    /**
     * IRQs used to communicate with the machine implementation.
     * There is one IRQ for each pin.  Note that for pins configured
     * as inputs, the output IRQ state has no meaning.  Perhaps
     * the output should be updated to match the input in this case....
     */
    qemu_irq out_irq[STM32_GPIO_PIN_COUNT];

    /**
     * IRQs which relay input pin changes to other STM32 peripherals
     * or to exception handlers.
     */
    qemu_irq in_irq[STM32_GPIO_PIN_COUNT];

    /**
     * Cached direction mask. 1 = output pin.
     */
    uint32_t dir_mask;

    /**
     * Mutually exclusive all families registers.
     * Address them like status->u.f1.reg.crl.
     * The 'reg' structure was used to mark explicitly that the member is
     * a MCU processor and also in case other family variables are needed.
     */
    union {
        struct {
            /* F1 specific registers */
            struct {
                uint32_t crl;
                uint32_t crh;
                uint32_t idr;
                uint32_t odr;
                uint32_t lckr;
            } reg;
        } f1;
        struct {
            /* F4 specific registers */
            struct {

            } reg;
        } f4;
    } u;
} STM32GPIOState;

#define DEFINE_PROP_STM32_GPIO_PORT_INDEX(_n, _s, _f, _d) \
    DEFINE_PROP_DEFAULT(_n, _s, _f, _d, qdev_prop_int32, stm32_gpio_index_t)

#endif /* STM32_GPIO_H_ */
