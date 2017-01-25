/*
 * STM32- CEC(HDMI-CEC controller) emulation.
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

#ifndef STM32_CEC_H_
#define STM32_CEC_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_CECDEVICE_PATH_STM32"CEC"

// ----------------------------------------------------------------------------

#define TYPE_STM32_CECTYPE_STM32_PREFIX "cec" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_CEC_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32CECParentClass;
typedef PeripheralState STM32CECParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_CEC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32CECClass, (obj), TYPE_STM32_CEC)
#define STM32_CEC_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32CECClass, (klass), TYPE_STM32_CEC)

typedef struct {
    // private: 
    STM32CECParentClass parent_class;
    // public: 

    // None, so far.
} STM32CECClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_CEC_STATE(obj) \
    OBJECT_CHECK(STM32CECState, (obj), TYPE_STM32_CEC)

typedef struct {
    // private:
    STM32CECParentState parent_obj;
    // public:

    const STM32Capabilities *capabilities;

    // TODO: remove this if the peripheral is always enabled.
    // Points to the bitfield that enables the peripheral.
    Object *enabling_bit;

union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // F0CEC(HDMI-CEC controller) registers.
        struct { 
Object *cr; // 0x0(Control register) 
Object *cfgr; // 0x4(Configuration register) 
Object *txdr; // 0x8(Tx data register) 
Object *rxdr; // 0xC(Rx Data Register) 
Object *isr; // 0x10(Interrupt and Status Register) 
Object *ier; // 0x14(Interrupt enable register) 
} reg;

        struct { 
// CR(Control register) bitfields.
          struct { 
Object *cecen; // [0:0] CEC EnableObject *txsom; // [1:1] Tx start of messageObject *txeom; // [2:2] Tx End Of Message} cr; 
// CFGR(Configuration register) bitfields.
          struct { 
Object *oar; // [0:3] Own AddressObject *lstn; // [4:4] Listen modeObject *sft; // [5:7] Signal Free TimeObject *rxtol; // [8:8] Rx-ToleranceObject *brestp; // [9:9] Rx-stop on bit rising errorObject *bregen; // [10:10] Generate error-bit on bit rising errorObject *lbpegen; // [11:11] Generate Error-Bit on Long Bit Period Error} cfgr; 
// TXDR(Tx data register) bitfields.
          struct { 
Object *txd; // [0:7] Tx Data register} txdr; 
// RXDR(Rx Data Register) bitfields.
          struct { 
Object *rxdr; // [0:7] CEC Rx Data Register} rxdr; 
// ISR(Interrupt and Status Register) bitfields.
          struct { 
Object *rxbr; // [0:0] Rx-Byte ReceivedObject *rxend; // [1:1] End Of ReceptionObject *rxovr; // [2:2] Rx-OverrunObject *bre; // [3:3] Rx-Bit rising errorObject *sbpe; // [4:4] Rx-Short Bit period errorObject *lbpe; // [5:5] Rx-Long Bit Period ErrorObject *rxacke; // [6:6] Rx-Missing AcknowledgeObject *arblst; // [7:7] Arbitration LostObject *txbr; // [8:8] Tx-Byte RequestObject *txend; // [9:9] End of TransmissionObject *txudr; // [10:10] Tx-Buffer UnderrunObject *txerr; // [11:11] Tx-ErrorObject *txacke; // [12:12] Tx-Missing acknowledge error} isr; 
// IER(Interrupt enable register) bitfields.
          struct { 
Object *rxbrie; // [0:0] Rx-Byte Received Interrupt EnableObject *rxendie; // [1:1] End Of Reception Interrupt EnableObject *rxovrie; // [2:2] Rx-Buffer Overrun Interrupt EnableObject *breie; // [3:3] Bit Rising Error Interrupt EnableObject *sbpeie; // [4:4] Short Bit Period Error Interrupt EnableObject *lbpeie; // [5:5] Long Bit Period Error Interrupt EnableObject *rxackie; // [6:6] Rx-Missing Acknowledge Error Interrupt EnableObject *arblstie; // [7:7] Arbitration Lost Interrupt EnableObject *txbrie; // [8:8] Tx-Byte Request Interrupt EnableObject *txendie; // [9:9] Tx-End of message interrupt enableObject *txudrie; // [10:10] Tx-Underrun interrupt enableObject *txerrie; // [11:11] Tx-Error Interrupt EnableObject *txackie; // [12:12] Tx-Missing Acknowledge Error Interrupt Enable} ier; 
} fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32CECState;

// ----------------------------------------------------------------------------

#endif /* STM32_CEC_H_ */
