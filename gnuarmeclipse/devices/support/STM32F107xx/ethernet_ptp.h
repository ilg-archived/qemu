/*
 * STM32 - ETHERNET_PTP (Ethernet: Precision time protocol) emulation.
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

#ifndef STM32_ETHERNET_PTP_H_
#define STM32_ETHERNET_PTP_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_ETHERNET_PTP DEVICE_PATH_STM32 "ETHERNET_PTP"



// ----------------------------------------------------------------------------

#define TYPE_STM32_ETHERNET_PTP TYPE_STM32_PREFIX "ethernet_ptp" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_ETHERNET_PTP_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32ETHERNET_PTPParentClass;
typedef PeripheralState STM32ETHERNET_PTPParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_ETHERNET_PTP_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32ETHERNET_PTPClass, (obj), TYPE_STM32_ETHERNET_PTP)
#define STM32_ETHERNET_PTP_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32ETHERNET_PTPClass, (klass), TYPE_STM32_ETHERNET_PTP)

typedef struct {
    // private: 
    STM32ETHERNET_PTPParentClass parent_class;
    // public: 

    // None, so far.
} STM32ETHERNET_PTPClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_ETHERNET_PTP_STATE(obj) \
    OBJECT_CHECK(STM32ETHERNET_PTPState, (obj), TYPE_STM32_ETHERNET_PTP)

typedef struct {
    // private:
    STM32ETHERNET_PTPParentState parent_obj;
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
        // F1 ETHERNET_PTP (Ethernet: Precision time protocol) registers.
        struct { 
          Object *ptptscr; // 0x0 (Ethernet PTP time stamp control register (ETH_PTPTSCR)) 
          Object *ptpssir; // 0x4 (Ethernet PTP subsecond increment register) 
          Object *ptptshr; // 0x8 (Ethernet PTP time stamp high register) 
          Object *ptptslr; // 0xC (Ethernet PTP time stamp low register (ETH_PTPTSLR)) 
          Object *ptptshur; // 0x10 (Ethernet PTP time stamp high update register) 
          Object *ptptslur; // 0x14 (Ethernet PTP time stamp low update register (ETH_PTPTSLUR)) 
          Object *ptptsar; // 0x18 (Ethernet PTP time stamp addend register) 
          Object *ptptthr; // 0x1C (Ethernet PTP target time high register) 
          Object *ptpttlr; // 0x20 (Ethernet PTP target time low register) 
        } reg;

        struct { 
          
          // PTPTSCR (Ethernet PTP time stamp control register (ETH_PTPTSCR)) bitfields.
          struct { 
            Object *tse; // [0:0] Time stamp enable 
            Object *tsfcu; // [1:1] Time stamp fine or coarse update 
            Object *tssti; // [2:2] Time stamp system time initialize 
            Object *tsstu; // [3:3] Time stamp system time update 
            Object *tsite; // [4:4] Time stamp interrupt trigger enable 
            Object *tsaru; // [5:5] Time stamp addend register update  
          } ptptscr; 
          
          // PTPSSIR (Ethernet PTP subsecond increment register) bitfields.
          struct { 
            Object *stssi; // [0:7] System time subsecond increment  
          } ptpssir; 
          
          // PTPTSHR (Ethernet PTP time stamp high register) bitfields.
          struct { 
            Object *sts; // [0:31] System time second  
          } ptptshr; 
          
          // PTPTSLR (Ethernet PTP time stamp low register (ETH_PTPTSLR)) bitfields.
          struct { 
            Object *stss; // [0:30] System time subseconds 
            Object *stpns; // [31:31] System time positive or negative sign  
          } ptptslr; 
          
          // PTPTSHUR (Ethernet PTP time stamp high update register) bitfields.
          struct { 
            Object *tsus; // [0:31] Time stamp update second  
          } ptptshur; 
          
          // PTPTSLUR (Ethernet PTP time stamp low update register (ETH_PTPTSLUR)) bitfields.
          struct { 
            Object *tsuss; // [0:30] Time stamp update subseconds 
            Object *tsupns; // [31:31] Time stamp update positive or negative sign  
          } ptptslur; 
          
          // PTPTSAR (Ethernet PTP time stamp addend register) bitfields.
          struct { 
            Object *tsa; // [0:31] Time stamp addend  
          } ptptsar; 
          
          // PTPTTHR (Ethernet PTP target time high register) bitfields.
          struct { 
            Object *ttsh; // [0:31] Target time stamp high  
          } ptptthr; 
          
          // PTPTTLR (Ethernet PTP target time low register) bitfields.
          struct { 
            Object *ttsl; // [0:31] Target time stamp low  
          } ptpttlr; 
        } fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32ETHERNET_PTPState;

// ----------------------------------------------------------------------------

#endif /* STM32_ETHERNET_PTP_H_ */
