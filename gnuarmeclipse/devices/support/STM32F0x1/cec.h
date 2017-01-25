/*
 * STM32 - CEC (HDMI-CEC controller) emulation.
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

#define DEVICE_PATH_STM32_CEC DEVICE_PATH_STM32 "CEC"



// ----------------------------------------------------------------------------

#define TYPE_STM32_CEC TYPE_STM32_PREFIX "cec" TYPE_PERIPHERAL_SUFFIX

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
        // F0 CEC (HDMI-CEC controller) registers.
        struct { 
          Object *cr; // 0x0 (Control register) 
          Object *cfgr; // 0x4 (Configuration register) 
          Object *txdr; // 0x8 (Tx data register) 
          Object *rxdr; // 0xC (Rx Data Register) 
          Object *isr; // 0x10 (Interrupt and Status Register) 
          Object *ier; // 0x14 (Interrupt enable register) 
        } reg;

        struct { 
          
          // CR (Control register) bitfields.
          struct { 
            Object *cecen; // [0:0] CEC Enable 
            Object *txsom; // [1:1] Tx start of message 
            Object *txeom; // [2:2] Tx End Of Message  
          } cr; 
          
          // CFGR (Configuration register) bitfields.
          struct { 
            Object *oar; // [0:3] Own Address 
            Object *lstn; // [4:4] Listen mode 
            Object *sft; // [5:7] Signal Free Time 
            Object *rxtol; // [8:8] Rx-Tolerance 
            Object *brestp; // [9:9] Rx-stop on bit rising error 
            Object *bregen; // [10:10] Generate error-bit on bit rising error 
            Object *lbpegen; // [11:11] Generate Error-Bit on Long Bit Period Error  
          } cfgr; 
          
          // TXDR (Tx data register) bitfields.
          struct { 
            Object *txd; // [0:7] Tx Data register  
          } txdr; 
          
          // RXDR (Rx Data Register) bitfields.
          struct { 
            Object *rxdr; // [0:7] CEC Rx Data Register  
          } rxdr; 
          
          // ISR (Interrupt and Status Register) bitfields.
          struct { 
            Object *rxbr; // [0:0] Rx-Byte Received 
            Object *rxend; // [1:1] End Of Reception 
            Object *rxovr; // [2:2] Rx-Overrun 
            Object *bre; // [3:3] Rx-Bit rising error 
            Object *sbpe; // [4:4] Rx-Short Bit period error 
            Object *lbpe; // [5:5] Rx-Long Bit Period Error 
            Object *rxacke; // [6:6] Rx-Missing Acknowledge 
            Object *arblst; // [7:7] Arbitration Lost 
            Object *txbr; // [8:8] Tx-Byte Request 
            Object *txend; // [9:9] End of Transmission 
            Object *txudr; // [10:10] Tx-Buffer Underrun 
            Object *txerr; // [11:11] Tx-Error 
            Object *txacke; // [12:12] Tx-Missing acknowledge error  
          } isr; 
          
          // IER (Interrupt enable register) bitfields.
          struct { 
            Object *rxbrie; // [0:0] Rx-Byte Received Interrupt Enable 
            Object *rxendie; // [1:1] End Of Reception Interrupt Enable 
            Object *rxovrie; // [2:2] Rx-Buffer Overrun Interrupt Enable 
            Object *breie; // [3:3] Bit Rising Error Interrupt Enable 
            Object *sbpeie; // [4:4] Short Bit Period Error Interrupt Enable 
            Object *lbpeie; // [5:5] Long Bit Period Error Interrupt Enable 
            Object *rxackie; // [6:6] Rx-Missing Acknowledge Error Interrupt Enable 
            Object *arblstie; // [7:7] Arbitration Lost Interrupt Enable 
            Object *txbrie; // [8:8] Tx-Byte Request Interrupt Enable 
            Object *txendie; // [9:9] Tx-End of message interrupt enable 
            Object *txudrie; // [10:10] Tx-Underrun interrupt enable 
            Object *txerrie; // [11:11] Tx-Error Interrupt Enable 
            Object *txackie; // [12:12] Tx-Missing Acknowledge Error Interrupt Enable  
          } ier; 
        } fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32CECState;

// ----------------------------------------------------------------------------

#endif /* STM32_CEC_H_ */
