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
STM32_PORT_USART6,
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
        // F4USART(Universal synchronous asynchronous receiver transmitter) registers.
        struct { 
Object *sr; // 0x0(Status register) 
Object *dr; // 0x4(Data register) 
Object *brr; // 0x8(Baud rate register) 
Object *cr1; // 0xC(Control register 1) 
Object *cr2; // 0x10(Control register 2) 
Object *cr3; // 0x14(Control register 3) 
Object *gtpr; // 0x18(Guard time and prescaler register) 
} reg;

        struct { 
// SR(Status register) bitfields.
          struct { 
Object *pe; // [0:0] Parity errorObject *fe; // [1:1] Framing errorObject *nf; // [2:2] Noise detected flagObject *ore; // [3:3] Overrun errorObject *idle; // [4:4] IDLE line detectedObject *rxne; // [5:5] Read data register not emptyObject *tc; // [6:6] Transmission completeObject *txe; // [7:7] Transmit data register emptyObject *lbd; // [8:8] LIN break detection flagObject *cts; // [9:9] CTS flag} sr; 
// DR(Data register) bitfields.
          struct { 
Object *dr; // [0:8] Data value} dr; 
// BRR(Baud rate register) bitfields.
          struct { 
Object *div_fraction; // [0:3] Fraction of USARTDIVObject *div_mantissa; // [4:15] Mantissa of USARTDIV} brr; 
// CR1(Control register 1) bitfields.
          struct { 
Object *sbk; // [0:0] Send breakObject *rwu; // [1:1] Receiver wakeupObject *re; // [2:2] Receiver enableObject *te; // [3:3] Transmitter enableObject *idleie; // [4:4] IDLE interrupt enableObject *rxneie; // [5:5] RXNE interrupt enableObject *tcie; // [6:6] Transmission complete interrupt enableObject *txeie; // [7:7] TXE interrupt enableObject *peie; // [8:8] PE interrupt enableObject *ps; // [9:9] Parity selectionObject *pce; // [10:10] Parity control enableObject *wake; // [11:11] Wakeup methodObject *m; // [12:12] Word lengthObject *ue; // [13:13] USART enableObject *over8; // [15:15] Oversampling mode} cr1; 
// CR2(Control register 2) bitfields.
          struct { 
Object *add; // [0:3] Address of the USART nodeObject *lbdl; // [5:5] Lin break detection lengthObject *lbdie; // [6:6] LIN break detection interrupt enableObject *lbcl; // [8:8] Last bit clock pulseObject *cpha; // [9:9] Clock phaseObject *cpol; // [10:10] Clock polarityObject *clken; // [11:11] Clock enableObject *stop; // [12:13] STOP bitsObject *linen; // [14:14] LIN mode enable} cr2; 
// CR3(Control register 3) bitfields.
          struct { 
Object *eie; // [0:0] Error interrupt enableObject *iren; // [1:1] IrDA mode enableObject *irlp; // [2:2] IrDA low-powerObject *hdsel; // [3:3] Half-duplex selectionObject *nack; // [4:4] Smartcard NACK enableObject *scen; // [5:5] Smartcard mode enableObject *dmar; // [6:6] DMA enable receiverObject *dmat; // [7:7] DMA enable transmitterObject *rtse; // [8:8] RTS enableObject *ctse; // [9:9] CTS enableObject *ctsie; // [10:10] CTS interrupt enableObject *onebit; // [11:11] One sample bit method enable} cr3; 
// GTPR(Guard time and prescaler register) bitfields.
          struct { 
Object *psc; // [0:7] Prescaler valueObject *gt; // [8:15] Guard time value} gtpr; 
} fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32USARTState;

// ----------------------------------------------------------------------------

#endif /* STM32_USART_H_ */
