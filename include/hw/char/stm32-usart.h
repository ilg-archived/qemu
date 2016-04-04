/*
 * STM32 USART
 *
 * Copyright (c) 2015 Dimitri L. <dimdimdimdim at gmx dot fr>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef STM32_USART_H_
#define STM32_USART_H_

#include "hw/misc/peripheral.h"
#include "hw/arm/stm32-capabilities.h"

#include "config.h"
#include "hw/misc/stm32-sys-bus-device.h"
#include "exec/address-spaces.h"
#include "hw/misc/stm32-rcc.h"
#include "hw/intc/cortexm-nvic.h"
#include "hw/misc/peripheral.h"

#include "sysemu/char.h"

/* ------------------------------------------------------------------------- */

#define TYPE_STM32_USART TYPE_STM32_PREFIX "usart" TYPE_PERIPHERAL_SUFFIX

/* ------------------------------------------------------------------------- */

#define TYPE_STM32_USART_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32USARTParentClass;
typedef PeripheralState STM32USARTParentState;

/* ------------------------------------------------------------------------- */

#define STM32_USART_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32USARTClass, (obj), TYPE_STM32_USART)
#define STM32_USART_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32USARTClass, (klass), TYPE_STM32_USART)

typedef struct {
    /*< private >*/
    STM32USARTParentClass parent_class;
    /*< public >*/
} STM32USARTClass;

/* ------------------------------------------------------------------------- */

typedef enum {
    STM32_USART_1 = 0,
    STM32_USART_2,
    STM32_USART_3,
    STM32_UART_4,
    STM32_UART_5,
    STM32_USART_6,
    STM32_USART_PORT_UNDEFINED,
} stm32_usart_index_t;

#define STM32_EXCP_USART_1   53
#define STM32_EXCP_USART_2   54
#define STM32_EXCP_USART_3   55
#define STM32_EXCP_UART_4    68
#define STM32_EXCP_UART_5    69
#define STM32_EXCP_USART_6   87

#define STM32_USART_STATE(obj) \
    OBJECT_CHECK(STM32USARTState, (obj), TYPE_STM32_USART)

typedef struct {
    /*< private >*/
    STM32USARTParentState parent_obj;
    /*< public >*/

    MemoryRegion mmio;

    stm32_usart_index_t port_index;

    STM32RCCState *rcc;
    CortexMNVICState *nvic;

    CharDriverState *chr;

    /**
     * USART/UART peripherals seem to be very similar among all families,
     * so we have a common struct for all mcus.
     */
    struct {
        Object *sr;
        Object *dr;
        Object *brr;
        Object *cr1;
        Object *cr2;
        Object *cr3;
        Object *gtpr;
    } reg;

    const STM32Capabilities *capabilities;
} STM32USARTState;

/* ------------------------------------------------------------------------- */

#endif /* STM32_USART_H_ */

