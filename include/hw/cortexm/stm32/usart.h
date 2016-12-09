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

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

#include <hw/cortexm/stm32/sys-bus-device.h>
#include "exec/address-spaces.h"
#include <hw/cortexm/stm32/rcc.h>
#include <hw/cortexm/nvic.h>
#include <hw/cortexm/peripheral.h>

#include "sysemu/char.h"

/* ------------------------------------------------------------------------- */

#define DEVICE_PATH_STM32_USART DEVICE_PATH_STM32 "USART"

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

    /*
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

    struct {
        // F4 USART6 (Universal synchronous asynchronous receiver transmitter) registers.
        struct {
            Object *sr; // 0x0 Status register
            Object *dr; // 0x4 Data register
            Object *brr; // 0x8 Baud rate register
            Object *cr1; // 0xC Control register 1
            Object *cr2; // 0x10 Control register 2
            Object *cr3; // 0x14 Control register 3
            Object *gtpr; // 0x18 Guard time and prescaler register
        } reg;

        struct {

            // SR (Status register) bitfields.
            struct {
                Object *pe; // [0:0] Parity error
                Object *fe; // [1:1] Framing error
                Object *nf; // [2:2] Noise detected flag
                Object *ore; // [3:3] Overrun error
                Object *idle; // [4:4] IDLE line detected
                Object *rxne; // [5:5] Read data register not empty
                Object *tc; // [6:6] Transmission complete
                Object *txe; // [7:7] Transmit data register empty
                Object *lbd; // [8:8] LIN break detection flag
                Object *cts; // [9:9] CTS flag
            } sr;

            // DR (Data register) bitfields.
            struct {
                Object *dr; // [0:8] Data value
            } dr;

            // BRR (Baud rate register) bitfields.
            struct {
                Object *div_fraction; // [0:3] Fraction of USARTDIV
                Object *div_mantissa; // [4:15] Mantissa of USARTDIV
            } brr;

            // CR1 (Control register 1) bitfields.
            struct {
                Object *sbk; // [0:0] Send break
                Object *rwu; // [1:1] Receiver wakeup
                Object *re; // [2:2] Receiver enable
                Object *te; // [3:3] Transmitter enable
                Object *idleie; // [4:4] IDLE interrupt enable
                Object *rxneie; // [5:5] RXNE interrupt enable
                Object *tcie; // [6:6] Transmission complete interrupt enable
                Object *txeie; // [7:7] TXE interrupt enable
                Object *peie; // [8:8] PE interrupt enable
                Object *ps; // [9:9] Parity selection
                Object *pce; // [10:10] Parity control enable
                Object *wake; // [11:11] Wakeup method
                Object *m; // [12:12] Word length
                Object *ue; // [13:13] USART enable
                Object *over8; // [15:15] Oversampling mode
            } cr1;

            // CR2 (Control register 2) bitfields.
            struct {
                Object *add; // [0:3] Address of the USART node
                Object *lbdl; // [5:5] Lin break detection length
                Object *lbdie; // [6:6] LIN break detection interrupt enable
                Object *lbcl; // [8:8] Last bit clock pulse
                Object *cpha; // [9:9] Clock phase
                Object *cpol; // [10:10] Clock polarity
                Object *clken; // [11:11] Clock enable
                Object *stop; // [12:13] STOP bits
                Object *linen; // [14:14] LIN mode enable
            } cr2;

            // CR3 (Control register 3) bitfields.
            struct {
                Object *eie; // [0:0] Error interrupt enable
                Object *iren; // [1:1] IrDA mode enable
                Object *irlp; // [2:2] IrDA low-power
                Object *hdsel; // [3:3] Half-duplex selection
                Object *nack; // [4:4] Smartcard NACK enable
                Object *scen; // [5:5] Smartcard mode enable
                Object *dmar; // [6:6] DMA enable receiver
                Object *dmat; // [7:7] DMA enable transmitter
                Object *rtse; // [8:8] RTS enable
                Object *ctse; // [9:9] CTS enable
                Object *ctsie; // [10:10] CTS interrupt enable
                Object *onebit; // [11:11] One sample bit method enable
            } cr3;

            // GTPR (Guard time and prescaler register) bitfields.
            struct {
                Object *psc; // [0:7] Prescaler value
                Object *gt; // [8:15] Guard time value
            } gtpr;
        } fld;
    } f4;

    const STM32Capabilities *capabilities;
} STM32USARTState;

/* ------------------------------------------------------------------------- */

#endif /* STM32_USART_H_ */

