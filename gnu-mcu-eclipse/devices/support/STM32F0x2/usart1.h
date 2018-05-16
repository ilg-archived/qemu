/*
 * STM32- USART(Universal synchronous asynchronous receiver transmitter) emulation.
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

#define DEVICE_PATH_STM32_USARTDEVICE_PATH_STM32"USART"

// ----------------------------------------------------------------------------

// Note: the "port-index" property has type "int".
typedef enum {
    // TODO: keep this list in ascending order.
STM32_PORT_USART1,
STM32_PORT_USART2,
STM32_PORT_USART3,
STM32_PORT_USART4,
STM32_PORT_USART_UNDEFINED = 0xFF,
} stm32_usart_index_t;
// ----------------------------------------------------------------------------

#define TYPE_STM32_USARTTYPE_STM32_PREFIX "usart" TYPE_PERIPHERAL_SUFFIX

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
        // F0USART(Universal synchronous asynchronous receiver transmitter) registers.
        struct { 
Object *cr1; // 0x0(Control register 1) 
Object *cr2; // 0x4(Control register 2) 
Object *cr3; // 0x8(Control register 3) 
Object *brr; // 0xC(Baud rate register) 
Object *gtpr; // 0x10(Guard time and prescaler register) 
Object *rtor; // 0x14(Receiver timeout register) 
Object *rqr; // 0x18(Request register) 
Object *isr; // 0x1C(Interrupt & status register) 
Object *icr; // 0x20(Interrupt flag clear register) 
Object *rdr; // 0x24(Receive data register) 
Object *tdr; // 0x28(Transmit data register) 
} reg;

        struct { 
// CR1(Control register 1) bitfields.
          struct { 
Object *ue; // [0:0] USART enableObject *uesm; // [1:1] USART enable in Stop modeObject *re; // [2:2] Receiver enableObject *te; // [3:3] Transmitter enableObject *idleie; // [4:4] IDLE interrupt enableObject *rxneie; // [5:5] RXNE interrupt enableObject *tcie; // [6:6] Transmission complete interrupt enableObject *txeie; // [7:7] Interrupt enableObject *peie; // [8:8] PE interrupt enableObject *ps; // [9:9] Parity selectionObject *pce; // [10:10] Parity control enableObject *wake; // [11:11] Receiver wakeup methodObject *m; // [12:12] Word lengthObject *mme; // [13:13] Mute mode enableObject *cmie; // [14:14] Character match interrupt enableObject *over8; // [15:15] Oversampling modeObject *dedt; // [16:20] Driver Enable deassertion timeObject *deat; // [21:25] Driver Enable assertion timeObject *rtoie; // [26:26] Receiver timeout interrupt enableObject *eobie; // [27:27] End of Block interrupt enableObject *m1; // [28:28] Word length} cr1; 
// CR2(Control register 2) bitfields.
          struct { 
Object *addm7; // [4:4] 7-bit Address Detection/4-bit Address DetectionObject *lbdl; // [5:5] LIN break detection lengthObject *lbdie; // [6:6] LIN break detection interrupt enableObject *lbcl; // [8:8] Last bit clock pulseObject *cpha; // [9:9] Clock phaseObject *cpol; // [10:10] Clock polarityObject *clken; // [11:11] Clock enableObject *stop; // [12:13] STOP bitsObject *linen; // [14:14] LIN mode enableObject *swap; // [15:15] Swap TX/RX pinsObject *rxinv; // [16:16] RX pin active level inversionObject *txinv; // [17:17] TX pin active level inversionObject *datainv; // [18:18] Binary data inversionObject *msbfirst; // [19:19] Most significant bit firstObject *abren; // [20:20] Auto baud rate enableObject *abrmod; // [21:22] Auto baud rate modeObject *rtoen; // [23:23] Receiver timeout enableObject *add0; // [24:27] Address of the USART nodeObject *add4; // [28:31] Address of the USART node} cr2; 
// CR3(Control register 3) bitfields.
          struct { 
Object *eie; // [0:0] Error interrupt enableObject *iren; // [1:1] IrDA mode enableObject *irlp; // [2:2] IrDA low-powerObject *hdsel; // [3:3] Half-duplex selectionObject *nack; // [4:4] Smartcard NACK enableObject *scen; // [5:5] Smartcard mode enableObject *dmar; // [6:6] DMA enable receiverObject *dmat; // [7:7] DMA enable transmitterObject *rtse; // [8:8] RTS enableObject *ctse; // [9:9] CTS enableObject *ctsie; // [10:10] CTS interrupt enableObject *onebit; // [11:11] One sample bit method enableObject *ovrdis; // [12:12] Overrun DisableObject *ddre; // [13:13] DMA Disable on Reception ErrorObject *dem; // [14:14] Driver enable modeObject *dep; // [15:15] Driver enable polarity selectionObject *scarcnt; // [17:19] Smartcard auto-retry countObject *wus; // [20:21] Wakeup from Stop mode interrupt flag selectionObject *wufie; // [22:22] Wakeup from Stop mode interrupt enable} cr3; 
// BRR(Baud rate register) bitfields.
          struct { 
Object *div_fraction; // [0:3] Fraction of USARTDIVObject *div_mantissa; // [4:15] Mantissa of USARTDIV} brr; 
// GTPR(Guard time and prescaler register) bitfields.
          struct { 
Object *psc; // [0:7] Prescaler valueObject *gt; // [8:15] Guard time value} gtpr; 
// RTOR(Receiver timeout register) bitfields.
          struct { 
Object *rto; // [0:23] Receiver timeout valueObject *blen; // [24:31] Block Length} rtor; 
// RQR(Request register) bitfields.
          struct { 
Object *abrrq; // [0:0] Auto baud rate requestObject *sbkrq; // [1:1] Send break requestObject *mmrq; // [2:2] Mute mode requestObject *rxfrq; // [3:3] Receive data flush requestObject *txfrq; // [4:4] Transmit data flush request} rqr; 
// ISR(Interrupt & status register) bitfields.
          struct { 
Object *pe; // [0:0] Parity errorObject *fe; // [1:1] Framing errorObject *nf; // [2:2] Noise detected flagObject *ore; // [3:3] Overrun errorObject *idle; // [4:4] Idle line detectedObject *rxne; // [5:5] Read data register not emptyObject *tc; // [6:6] Transmission completeObject *txe; // [7:7] Transmit data register emptyObject *lbdf; // [8:8] LIN break detection flagObject *ctsif; // [9:9] CTS interrupt flagObject *cts; // [10:10] CTS flagObject *rtof; // [11:11] Receiver timeoutObject *eobf; // [12:12] End of block flagObject *abre; // [14:14] Auto baud rate errorObject *abrf; // [15:15] Auto baud rate flagObject *busy; // [16:16] Busy flagObject *cmf; // [17:17] Character match flagObject *sbkf; // [18:18] Send break flagObject *rwu; // [19:19] Receiver wakeup from Mute modeObject *wuf; // [20:20] Wakeup from Stop mode flagObject *teack; // [21:21] Transmit enable acknowledge flagObject *reack; // [22:22] Receive enable acknowledge flag} isr; 
// ICR(Interrupt flag clear register) bitfields.
          struct { 
Object *pecf; // [0:0] Parity error clear flagObject *fecf; // [1:1] Framing error clear flagObject *ncf; // [2:2] Noise detected clear flagObject *orecf; // [3:3] Overrun error clear flagObject *idlecf; // [4:4] Idle line detected clear flagObject *tccf; // [6:6] Transmission complete clear flagObject *lbdcf; // [8:8] LIN break detection clear flagObject *ctscf; // [9:9] CTS clear flagObject *rtocf; // [11:11] Receiver timeout clear flagObject *eobcf; // [12:12] End of timeout clear flagObject *cmcf; // [17:17] Character match clear flagObject *wucf; // [20:20] Wakeup from Stop mode clear flag} icr; 
// RDR(Receive data register) bitfields.
          struct { 
Object *rdr; // [0:8] Receive data value} rdr; 
// TDR(Transmit data register) bitfields.
          struct { 
Object *tdr; // [0:8] Transmit data value} tdr; 
} fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32USARTState;

// ----------------------------------------------------------------------------

#endif /* STM32_USART_H_ */
