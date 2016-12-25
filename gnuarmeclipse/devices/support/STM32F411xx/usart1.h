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
    STM32_PORT_USART6,
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
        // F4 USART (Universal synchronous asynchronous receiver transmitter) registers.
        struct { 
          Object *sr; // 0x0 (Status register) 
          Object *dr; // 0x4 (Data register) 
          Object *brr; // 0x8 (Baud rate register) 
          Object *cr1; // 0xC (Control register 1) 
          Object *cr2; // 0x10 (Control register 2) 
          Object *cr3; // 0x14 (Control register 3) 
          Object *gtpr; // 0x18 (Guard time and prescaler register) 
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

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32USARTState;

// ----------------------------------------------------------------------------

#endif /* STM32_USART_H_ */
