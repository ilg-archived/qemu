/*
 * STM32- UART(Universal asynchronous receiver transmitter) emulation.
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

#ifndef STM32_UART_H_
#define STM32_UART_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_UARTDEVICE_PATH_STM32"UART"

// ----------------------------------------------------------------------------

// Note: the "port-index" property has type "int".
typedef enum {
    // TODO: keep this list in ascending order.
STM32_PORT_UART4,
STM32_PORT_UART5,
STM32_PORT_UART_UNDEFINED = 0xFF,
} stm32_uart_index_t;
// ----------------------------------------------------------------------------

#define TYPE_STM32_UARTTYPE_STM32_PREFIX "uart" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_UART_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32UARTParentClass;
typedef PeripheralState STM32UARTParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_UART_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32UARTClass, (obj), TYPE_STM32_UART)
#define STM32_UART_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32UARTClass, (klass), TYPE_STM32_UART)

typedef struct {
    // private: 
    STM32UARTParentClass parent_class;
    // public: 

    // None, so far.
} STM32UARTClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_UART_STATE(obj) \
    OBJECT_CHECK(STM32UARTState, (obj), TYPE_STM32_UART)

typedef struct {
    // private:
    STM32UARTParentState parent_obj;
    // public:

    const STM32Capabilities *capabilities;

    // TODO: remove this if the peripheral is always enabled.
    // Points to the bitfield that enables the peripheral.
    Object *enabling_bit;

// Remove it if there is only one port
    stm32_uart_index_t port_index;
union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // F1UART(Universal asynchronous receiver transmitter) registers.
        struct { 
Object *sr; // 0x0(UART5 SR) 
Object *dr; // 0x4(UART5 DR) 
Object *brr; // 0x8(UART5 BRR) 
Object *cr1; // 0xC(UART5 CR1) 
Object *cr2; // 0x10(UART5 CR2) 
Object *cr3; // 0x14(UART5 CR3) 
} reg;

        struct { 
// SR(UART5 SR) bitfields.
          struct { 
Object *pe; // [0:0] PEObject *fe; // [1:1] FEObject *ne; // [2:2] NEObject *ore; // [3:3] OREObject *idle; // [4:4] IDLEObject *rxne; // [5:5] RXNEObject *tc; // [6:6] TCObject *txe; // [7:7] TXEObject *lbd; // [8:8] LBD} sr; 
// DR(UART5 DR) bitfields.
          struct { 
Object *dr; // [0:8] DR} dr; 
// BRR(UART5 BRR) bitfields.
          struct { 
Object *div_fraction; // [0:3] DIV_FractionObject *div_mantissa; // [4:15] DIV_Mantissa} brr; 
// CR1(UART5 CR1) bitfields.
          struct { 
Object *sbk; // [0:0] SBKObject *rwu; // [1:1] RWUObject *re; // [2:2] REObject *te; // [3:3] TEObject *idleie; // [4:4] IDLEIEObject *rxneie; // [5:5] RXNEIEObject *tcie; // [6:6] TCIEObject *txeie; // [7:7] TXEIEObject *peie; // [8:8] PEIEObject *ps; // [9:9] PSObject *pce; // [10:10] PCEObject *wake; // [11:11] WAKEObject *m; // [12:12] MObject *ue; // [13:13] UE} cr1; 
// CR2(UART5 CR2) bitfields.
          struct { 
Object *add; // [0:3] ADDObject *lbdl; // [5:5] LBDLObject *lbdie; // [6:6] LBDIEObject *stop; // [12:13] STOPObject *linen; // [14:14] LINEN} cr2; 
// CR3(UART5 CR3) bitfields.
          struct { 
Object *eie; // [0:0] Error interrupt enableObject *iren; // [1:1] IrDA mode enableObject *irlp; // [2:2] IrDA low-powerObject *hdsel; // [3:3] Half-duplex selectionObject *dmat; // [7:7] DMA enable transmitter} cr3; 
} fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32UARTState;

// ----------------------------------------------------------------------------

#endif /* STM32_UART_H_ */
