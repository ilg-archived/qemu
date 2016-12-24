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

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_USART DEVICE_PATH_STM32 "USART"

typedef enum {
    STM32_PORT_USART1 = 0,
    STM32_PORT_USART2,
    STM32_PORT_USART3,
    STM32_PORT_USART4,
    STM32_PORT_USART5,
    STM32_PORT_USART6,
    STM32_PORT_USART7,
    STM32_PORT_USART8,
    STM32_PORT_USART_UNDEFINED,
} stm32_usart_index_t;

typedef enum {
    STM32_PORT_UART1 = 0,
    STM32_PORT_UART2,
    STM32_PORT_UART3,
    STM32_PORT_UART4,
    STM32_PORT_UART5,
    STM32_PORT_UART6,
    STM32_PORT_UART7,
    STM32_PORT_UART8,
    STM32_PORT_UART_UNDEFINED,
} stm32_uart_index_t;

#define STM32_EXCP_USART_1   53
#define STM32_EXCP_USART_2   54
#define STM32_EXCP_USART_3   55
#define STM32_EXCP_UART_4    68
#define STM32_EXCP_UART_5    69
#define STM32_EXCP_USART_6   87

// ----------------------------------------------------------------------------

#define TYPE_STM32_USART TYPE_STM32_PREFIX "usart" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_USART_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32USARTParentClass;
typedef PeripheralState STM32USARTParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_USART_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32USARTClass, (obj), TYPE_STM32_USART)
#define STM32_USART_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32USARTClass, (klass), TYPE_STM32_USART)

typedef struct {
    // private:
    STM32USARTParentClass parent_class;
    // public:

    // None, so far.
} STM32USARTClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_USART_STATE(obj) \
    OBJECT_CHECK(STM32USARTState, (obj), TYPE_STM32_USART)

typedef struct {
    // private:
    STM32USARTParentState parent_obj;
    // public:

    const STM32Capabilities *capabilities;

    stm32_usart_index_t port_index;

    // Points to one RCC bitfield that enables the peripheral.
    Object *enabling_bit;

    CortexMNVICState *nvic;

    CharDriverState *chr;

    // USART/UART peripherals seem to be very similar among all families,
    // so we have a common struct for all mcus.

    struct {
        Object *sr;
        Object *dr;
        Object *brr;
        Object *cr1;
        Object *cr2;
        Object *cr3;
        Object *gtpr;
    } reg;

    union {
        // DO NOT EDIT! Automatically generated!
        struct {
            // F0 USART (Universal synchronous asynchronous receiver transmitter) registers.
            struct {
                Object *cr1; // 0x0 Control register 1
                Object *cr2; // 0x4 Control register 2
                Object *cr3; // 0x8 Control register 3
                Object *brr; // 0xC Baud rate register
                Object *gtpr; // 0x10 Guard time and prescaler register
                Object *rtor; // 0x14 Receiver timeout register
                Object *rqr; // 0x18 Request register
                Object *isr; // 0x1C Interrupt & status register
                Object *icr; // 0x20 Interrupt flag clear register
                Object *rdr; // 0x24 Receive data register
                Object *tdr; // 0x28 Transmit data register
            } reg;

            struct {

                // CR1 (Control register 1) bitfields.
                struct {
                    Object *ue; // [0:0] USART enable
                    Object *uesm; // [1:1] USART enable in Stop mode
                    Object *re; // [2:2] Receiver enable
                    Object *te; // [3:3] Transmitter enable
                    Object *idleie; // [4:4] IDLE interrupt enable
                    Object *rxneie; // [5:5] RXNE interrupt enable
                    Object *tcie; // [6:6] Transmission complete interrupt enable
                    Object *txeie; // [7:7] Interrupt enable
                    Object *peie; // [8:8] PE interrupt enable
                    Object *ps; // [9:9] Parity selection
                    Object *pce; // [10:10] Parity control enable
                    Object *wake; // [11:11] Receiver wakeup method
                    Object *m; // [12:12] Word length
                    Object *mme; // [13:13] Mute mode enable
                    Object *cmie; // [14:14] Character match interrupt enable
                    Object *over8; // [15:15] Oversampling mode
                    Object *dedt; // [16:20] Driver Enable deassertion time
                    Object *deat; // [21:25] Driver Enable assertion time
                    Object *rtoie; // [26:26] Receiver timeout interrupt enable
                    Object *eobie; // [27:27] End of Block interrupt enable
                    Object *m1; // [28:28] Word length
                } cr1;

                // CR2 (Control register 2) bitfields.
                struct {
                    Object *addm7; // [4:4] 7-bit Address Detection/4-bit Address Detection
                    Object *lbdl; // [5:5] LIN break detection length
                    Object *lbdie; // [6:6] LIN break detection interrupt enable
                    Object *lbcl; // [8:8] Last bit clock pulse
                    Object *cpha; // [9:9] Clock phase
                    Object *cpol; // [10:10] Clock polarity
                    Object *clken; // [11:11] Clock enable
                    Object *stop; // [12:13] STOP bits
                    Object *linen; // [14:14] LIN mode enable
                    Object *swap; // [15:15] Swap TX/RX pins
                    Object *rxinv; // [16:16] RX pin active level inversion
                    Object *txinv; // [17:17] TX pin active level inversion
                    Object *datainv; // [18:18] Binary data inversion
                    Object *msbfirst; // [19:19] Most significant bit first
                    Object *abren; // [20:20] Auto baud rate enable
                    Object *abrmod; // [21:22] Auto baud rate mode
                    Object *rtoen; // [23:23] Receiver timeout enable
                    Object *add0; // [24:27] Address of the USART node
                    Object *add4; // [28:31] Address of the USART node
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
                    Object *ovrdis; // [12:12] Overrun Disable
                    Object *ddre; // [13:13] DMA Disable on Reception Error
                    Object *dem; // [14:14] Driver enable mode
                    Object *dep; // [15:15] Driver enable polarity selection
                    Object *scarcnt; // [17:19] Smartcard auto-retry count
                    Object *wus; // [20:21] Wakeup from Stop mode interrupt flag selection
                    Object *wufie; // [22:22] Wakeup from Stop mode interrupt enable
                } cr3;

                // BRR (Baud rate register) bitfields.
                struct {
                    Object *div_fraction; // [0:3] Fraction of USARTDIV
                    Object *div_mantissa; // [4:15] Mantissa of USARTDIV
                } brr;

                // GTPR (Guard time and prescaler register) bitfields.
                struct {
                    Object *psc; // [0:7] Prescaler value
                    Object *gt; // [8:15] Guard time value
                } gtpr;

                // RTOR (Receiver timeout register) bitfields.
                struct {
                    Object *rto; // [0:23] Receiver timeout value
                    Object *blen; // [24:31] Block Length
                } rtor;

                // RQR (Request register) bitfields.
                struct {
                    Object *abrrq; // [0:0] Auto baud rate request
                    Object *sbkrq; // [1:1] Send break request
                    Object *mmrq; // [2:2] Mute mode request
                    Object *rxfrq; // [3:3] Receive data flush request
                    Object *txfrq; // [4:4] Transmit data flush request
                } rqr;

                // ISR (Interrupt & status register) bitfields.
                struct {
                    Object *pe; // [0:0] Parity error
                    Object *fe; // [1:1] Framing error
                    Object *nf; // [2:2] Noise detected flag
                    Object *ore; // [3:3] Overrun error
                    Object *idle; // [4:4] Idle line detected
                    Object *rxne; // [5:5] Read data register not empty
                    Object *tc; // [6:6] Transmission complete
                    Object *txe; // [7:7] Transmit data register empty
                    Object *lbdf; // [8:8] LIN break detection flag
                    Object *ctsif; // [9:9] CTS interrupt flag
                    Object *cts; // [10:10] CTS flag
                    Object *rtof; // [11:11] Receiver timeout
                    Object *eobf; // [12:12] End of block flag
                    Object *abre; // [14:14] Auto baud rate error
                    Object *abrf; // [15:15] Auto baud rate flag
                    Object *busy; // [16:16] Busy flag
                    Object *cmf; // [17:17] Character match flag
                    Object *sbkf; // [18:18] Send break flag
                    Object *rwu; // [19:19] Receiver wakeup from Mute mode
                    Object *wuf; // [20:20] Wakeup from Stop mode flag
                    Object *teack; // [21:21] Transmit enable acknowledge flag
                    Object *reack; // [22:22] Receive enable acknowledge flag
                } isr;

                // ICR (Interrupt flag clear register) bitfields.
                struct {
                    Object *pecf; // [0:0] Parity error clear flag
                    Object *fecf; // [1:1] Framing error clear flag
                    Object *ncf; // [2:2] Noise detected clear flag
                    Object *orecf; // [3:3] Overrun error clear flag
                    Object *idlecf; // [4:4] Idle line detected clear flag
                    Object *tccf; // [6:6] Transmission complete clear flag
                    Object *lbdcf; // [8:8] LIN break detection clear flag
                    Object *ctscf; // [9:9] CTS clear flag
                    Object *rtocf; // [11:11] Receiver timeout clear flag
                    Object *eobcf; // [12:12] End of timeout clear flag
                    Object *cmcf; // [17:17] Character match clear flag
                    Object *wucf; // [20:20] Wakeup from Stop mode clear flag
                } icr;

                // RDR (Receive data register) bitfields.
                struct {
                    Object *rdr; // [0:8] Receive data value
                } rdr;

                // TDR (Transmit data register) bitfields.
                struct {
                    Object *tdr; // [0:8] Transmit data value
                } tdr;
            } fld;
        } f0;

        // DO NOT EDIT! Automatically generated!
        struct {
            // F1 USART1 (Universal synchronous asynchronous receiver transmitter) registers.
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
                    Object *ne; // [2:2] Noise error flag
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
                } cr3;

                // GTPR (Guard time and prescaler register) bitfields.
                struct {
                    Object *psc; // [0:7] Prescaler value
                    Object *gt; // [8:15] Guard time value
                } gtpr;
            } fld;
        } f1;

        // DO NOT EDIT! Automatically generated!
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
    } u;

} STM32USARTState;

// ----- Public ---------------------------------------------------------------

Object* stm32_usart_create(Object *parent, stm32_usart_index_t index);

// ----------------------------------------------------------------------------

#endif /* STM32_USART_H_ */

