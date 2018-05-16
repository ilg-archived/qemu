/*
 * STM32 - Ethernet_MMC (Ethernet: MAC management counters) emulation.
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

#ifndef STM32_Ethernet_MMC_H_
#define STM32_Ethernet_MMC_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_Ethernet_MMC DEVICE_PATH_STM32 "Ethernet_MMC"



// ----------------------------------------------------------------------------

#define TYPE_STM32_Ethernet_MMC TYPE_STM32_PREFIX "ethernet_mmc" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_Ethernet_MMC_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32Ethernet_MMCParentClass;
typedef PeripheralState STM32Ethernet_MMCParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_Ethernet_MMC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32Ethernet_MMCClass, (obj), TYPE_STM32_Ethernet_MMC)
#define STM32_Ethernet_MMC_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32Ethernet_MMCClass, (klass), TYPE_STM32_Ethernet_MMC)

typedef struct {
    // private: 
    STM32Ethernet_MMCParentClass parent_class;
    // public: 

    // None, so far.
} STM32Ethernet_MMCClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_Ethernet_MMC_STATE(obj) \
    OBJECT_CHECK(STM32Ethernet_MMCState, (obj), TYPE_STM32_Ethernet_MMC)

typedef struct {
    // private:
    STM32Ethernet_MMCParentState parent_obj;
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
        // F4 Ethernet_MMC (Ethernet: MAC management counters) registers.
        struct { 
          Object *mmccr; // 0x0 (Ethernet MMC control register) 
          Object *mmcrir; // 0x4 (Ethernet MMC receive interrupt register) 
          Object *mmctir; // 0x8 (Ethernet MMC transmit interrupt register) 
          Object *mmcrimr; // 0xC (Ethernet MMC receive interrupt mask register) 
          Object *mmctimr; // 0x10 (Ethernet MMC transmit interrupt mask register) 
          Object *mmctgfsccr; // 0x4C (Ethernet MMC transmitted good frames after a single collision counter) 
          Object *mmctgfmsccr; // 0x50 (Ethernet MMC transmitted good frames after more than a single collision) 
          Object *mmctgfcr; // 0x68 (Ethernet MMC transmitted good frames counter register) 
          Object *mmcrfcecr; // 0x94 (Ethernet MMC received frames with CRC error counter register) 
          Object *mmcrfaecr; // 0x98 (Ethernet MMC received frames with alignment error counter register) 
          Object *mmcrgufcr; // 0xC4 (MMC received good unicast frames counter register) 
        } reg;

        struct { 
          
          // MMCCR (Ethernet MMC control register) bitfields.
          struct { 
            Object *cr; // [0:0] No description available 
            Object *csr; // [1:1] No description available 
            Object *ror; // [2:2] No description available 
            Object *mcf; // [3:3] No description available 
            Object *mcp; // [4:4] No description available 
            Object *mcfhp; // [5:5] No description available  
          } mmccr; 
          
          // MMCRIR (Ethernet MMC receive interrupt register) bitfields.
          struct { 
            Object *rfces; // [5:5] No description available 
            Object *rfaes; // [6:6] No description available 
            Object *rgufs; // [17:17] No description available  
          } mmcrir; 
          
          // MMCTIR (Ethernet MMC transmit interrupt register) bitfields.
          struct { 
            Object *tgfscs; // [14:14] No description available 
            Object *tgfmscs; // [15:15] No description available 
            Object *tgfs; // [21:21] No description available  
          } mmctir; 
          
          // MMCRIMR (Ethernet MMC receive interrupt mask register) bitfields.
          struct { 
            Object *rfcem; // [5:5] No description available 
            Object *rfaem; // [6:6] No description available 
            Object *rgufm; // [17:17] No description available  
          } mmcrimr; 
          
          // MMCTIMR (Ethernet MMC transmit interrupt mask register) bitfields.
          struct { 
            Object *tgfscm; // [14:14] No description available 
            Object *tgfmscm; // [15:15] No description available 
            Object *tgfm; // [16:16] No description available  
          } mmctimr; 
          
          // MMCTGFSCCR (Ethernet MMC transmitted good frames after a single collision counter) bitfields.
          struct { 
            Object *tgfscc; // [0:31] No description available  
          } mmctgfsccr; 
          
          // MMCTGFMSCCR (Ethernet MMC transmitted good frames after more than a single collision) bitfields.
          struct { 
            Object *tgfmscc; // [0:31] No description available  
          } mmctgfmsccr; 
          
          // MMCTGFCR (Ethernet MMC transmitted good frames counter register) bitfields.
          struct { 
            Object *tgfc; // [0:31] HTL  
          } mmctgfcr; 
          
          // MMCRFCECR (Ethernet MMC received frames with CRC error counter register) bitfields.
          struct { 
            Object *rfcfc; // [0:31] No description available  
          } mmcrfcecr; 
          
          // MMCRFAECR (Ethernet MMC received frames with alignment error counter register) bitfields.
          struct { 
            Object *rfaec; // [0:31] No description available  
          } mmcrfaecr; 
          
          // MMCRGUFCR (MMC received good unicast frames counter register) bitfields.
          struct { 
            Object *rgufc; // [0:31] No description available  
          } mmcrgufcr; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32Ethernet_MMCState;

// ----------------------------------------------------------------------------

#endif /* STM32_Ethernet_MMC_H_ */
