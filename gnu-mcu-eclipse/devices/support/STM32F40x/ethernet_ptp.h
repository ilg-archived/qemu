/*
 * STM32 - Ethernet_PTP (Ethernet: Precision time protocol) emulation.
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

#ifndef STM32_Ethernet_PTP_H_
#define STM32_Ethernet_PTP_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_Ethernet_PTP DEVICE_PATH_STM32 "Ethernet_PTP"



// ----------------------------------------------------------------------------

#define TYPE_STM32_Ethernet_PTP TYPE_STM32_PREFIX "ethernet_ptp" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_Ethernet_PTP_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32Ethernet_PTPParentClass;
typedef PeripheralState STM32Ethernet_PTPParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_Ethernet_PTP_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32Ethernet_PTPClass, (obj), TYPE_STM32_Ethernet_PTP)
#define STM32_Ethernet_PTP_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32Ethernet_PTPClass, (klass), TYPE_STM32_Ethernet_PTP)

typedef struct {
    // private: 
    STM32Ethernet_PTPParentClass parent_class;
    // public: 

    // None, so far.
} STM32Ethernet_PTPClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_Ethernet_PTP_STATE(obj) \
    OBJECT_CHECK(STM32Ethernet_PTPState, (obj), TYPE_STM32_Ethernet_PTP)

typedef struct {
    // private:
    STM32Ethernet_PTPParentState parent_obj;
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
        // F4 Ethernet_PTP (Ethernet: Precision time protocol) registers.
        struct { 
          Object *ptptscr; // 0x0 (Ethernet PTP time stamp control register) 
          Object *ptpssir; // 0x4 (Ethernet PTP subsecond increment register) 
          Object *ptptshr; // 0x8 (Ethernet PTP time stamp high register) 
          Object *ptptslr; // 0xC (Ethernet PTP time stamp low register) 
          Object *ptptshur; // 0x10 (Ethernet PTP time stamp high update register) 
          Object *ptptslur; // 0x14 (Ethernet PTP time stamp low update register) 
          Object *ptptsar; // 0x18 (Ethernet PTP time stamp addend register) 
          Object *ptptthr; // 0x1C (Ethernet PTP target time high register) 
          Object *ptpttlr; // 0x20 (Ethernet PTP target time low register) 
          Object *ptptssr; // 0x28 (Ethernet PTP time stamp status register) 
          Object *ptpppscr; // 0x2C (Ethernet PTP PPS control register) 
        } reg;

        struct { 
          
          // PTPTSCR (Ethernet PTP time stamp control register) bitfields.
          struct { 
            Object *tse; // [0:0] No description available 
            Object *tsfcu; // [1:1] No description available 
            Object *tssti; // [2:2] No description available 
            Object *tsstu; // [3:3] No description available 
            Object *tsite; // [4:4] No description available 
            Object *ttsaru; // [5:5] No description available 
            Object *tssarfe; // [8:8] No description available 
            Object *tsssr; // [9:9] No description available 
            Object *tsptppsv2e; // [10:10] No description available 
            Object *tssptpoefe; // [11:11] No description available 
            Object *tssipv6fe; // [12:12] No description available 
            Object *tssipv4fe; // [13:13] No description available 
            Object *tsseme; // [14:14] No description available 
            Object *tssmrme; // [15:15] No description available 
            Object *tscnt; // [16:17] No description available 
            Object *tspffmae; // [18:18] No description available  
          } ptptscr; 
          
          // PTPSSIR (Ethernet PTP subsecond increment register) bitfields.
          struct { 
            Object *stssi; // [0:7] No description available  
          } ptpssir; 
          
          // PTPTSHR (Ethernet PTP time stamp high register) bitfields.
          struct { 
            Object *sts; // [0:31] No description available  
          } ptptshr; 
          
          // PTPTSLR (Ethernet PTP time stamp low register) bitfields.
          struct { 
            Object *stss; // [0:30] No description available 
            Object *stpns; // [31:31] No description available  
          } ptptslr; 
          
          // PTPTSHUR (Ethernet PTP time stamp high update register) bitfields.
          struct { 
            Object *tsus; // [0:31] No description available  
          } ptptshur; 
          
          // PTPTSLUR (Ethernet PTP time stamp low update register) bitfields.
          struct { 
            Object *tsuss; // [0:30] No description available 
            Object *tsupns; // [31:31] No description available  
          } ptptslur; 
          
          // PTPTSAR (Ethernet PTP time stamp addend register) bitfields.
          struct { 
            Object *tsa; // [0:31] No description available  
          } ptptsar; 
          
          // PTPTTHR (Ethernet PTP target time high register) bitfields.
          struct { 
            Object *ttsh; // [0:31] 0  
          } ptptthr; 
          
          // PTPTTLR (Ethernet PTP target time low register) bitfields.
          struct { 
            Object *ttsl; // [0:31] No description available  
          } ptpttlr; 
          
          // PTPTSSR (Ethernet PTP time stamp status register) bitfields.
          struct { 
            Object *tsso; // [0:0] No description available 
            Object *tsttr; // [1:1] No description available  
          } ptptssr; 
          
          // PTPPPSCR (Ethernet PTP PPS control register) bitfields.
          struct { 
            Object *tsso; // [0:0] TSSO 
            Object *tsttr; // [1:1] TSTTR  
          } ptpppscr; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32Ethernet_PTPState;

// ----------------------------------------------------------------------------

#endif /* STM32_Ethernet_PTP_H_ */
