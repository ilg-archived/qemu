/*
 * STM32 - USART (Universal synchronous asynchronous receiver transmitter) emulation.
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

#ifndef STM32_USART_H_
#define STM32_USART_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_USART DEVICE_PATH_STM32 "USART"

// ----------------------------------------------------------------------------

// Note: the "port-index" property has type "int".
typedef enum {
    // TODO: keep this list in ascending order.
    STM32_PORT_USART1,
    STM32_PORT_USART2,
    STM32_PORT_USART3,
    STM32_PORT_USART4,
    STM32_PORT_USART5,
    STM32_PORT_USART6,
    STM32_PORT_USART7,
    STM32_PORT_USART8,
    STM32_PORT_USART_UNDEFINED = 0xFF,
} stm32_usart_index_t;

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

    // TODO: remove this if the peripheral is always enabled.
    // Points to the bitfield that enables the peripheral.
    Object *enabling_bit;

    // Remove it if there is only one port
    stm32_usart_index_t port_index;

    union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // F0 USART (Universal synchronous asynchronous receiver transmitter) registers.
        struct { 
          Object *cr1; // 0x0 (Control register 1) 
          Object *cr2; // 0x4 (Control register 2) 
          Object *cr3; // 0x8 (Control register 3) 
          Object *brr; // 0xC (Baud rate register) 
          Object *gtpr; // 0x10 (Guard time and prescaler register) 
          Object *rtor; // 0x14 (Receiver timeout register) 
          Object *rqr; // 0x18 (Request register) 
          Object *isr; // 0x1C (Interrupt & status register) 
          Object *icr; // 0x20 (Interrupt flag clear register) 
          Object *rdr; // 0x24 (Receive data register) 
          Object *tdr; // 0x28 (Transmit data register) 
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

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32USARTState;

// ----------------------------------------------------------------------------

#endif /* STM32_USART_H_ */
