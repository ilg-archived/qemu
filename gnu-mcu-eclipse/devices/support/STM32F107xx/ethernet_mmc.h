/*
 * STM32 - ETHERNET_MMC (Ethernet: MAC management counters) emulation.
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

#ifndef STM32_ETHERNET_MMC_H_
#define STM32_ETHERNET_MMC_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_ETHERNET_MMC DEVICE_PATH_STM32 "ETHERNET_MMC"



// ----------------------------------------------------------------------------

#define TYPE_STM32_ETHERNET_MMC TYPE_STM32_PREFIX "ethernet_mmc" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_ETHERNET_MMC_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32ETHERNET_MMCParentClass;
typedef PeripheralState STM32ETHERNET_MMCParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_ETHERNET_MMC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32ETHERNET_MMCClass, (obj), TYPE_STM32_ETHERNET_MMC)
#define STM32_ETHERNET_MMC_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32ETHERNET_MMCClass, (klass), TYPE_STM32_ETHERNET_MMC)

typedef struct {
    // private: 
    STM32ETHERNET_MMCParentClass parent_class;
    // public: 

    // None, so far.
} STM32ETHERNET_MMCClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_ETHERNET_MMC_STATE(obj) \
    OBJECT_CHECK(STM32ETHERNET_MMCState, (obj), TYPE_STM32_ETHERNET_MMC)

typedef struct {
    // private:
    STM32ETHERNET_MMCParentState parent_obj;
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
        // F1 ETHERNET_MMC (Ethernet: MAC management counters) registers.
        struct { 
          Object *mmccr; // 0x0 (Ethernet MMC control register (ETH_MMCCR)) 
          Object *mmcrir; // 0x4 (Ethernet MMC receive interrupt register (ETH_MMCRIR)) 
          Object *mmctir; // 0x8 (Ethernet MMC transmit interrupt register (ETH_MMCTIR)) 
          Object *mmcrimr; // 0xC (Ethernet MMC receive interrupt mask register (ETH_MMCRIMR)) 
          Object *mmctimr; // 0x10 (Ethernet MMC transmit interrupt mask register (ETH_MMCTIMR)) 
          Object *mmctgfsccr; // 0x4C (Ethernet MMC transmitted good frames after a single collision counter) 
          Object *mmctgfmsccr; // 0x50 (Ethernet MMC transmitted good frames after more than a single collision) 
          Object *mmctgfcr; // 0x68 (Ethernet MMC transmitted good frames counter register) 
          Object *mmcrfcecr; // 0x94 (Ethernet MMC received frames with CRC error counter register) 
          Object *mmcrfaecr; // 0x98 (Ethernet MMC received frames with alignment error counter register) 
          Object *mmcrgufcr; // 0xC4 (MMC received good unicast frames counter register) 
        } reg;

        struct { 
          
          // MMCCR (Ethernet MMC control register (ETH_MMCCR)) bitfields.
          struct { 
            Object *cr; // [0:0] Counter reset 
            Object *csr; // [1:1] Counter stop rollover 
            Object *ror; // [2:2] Reset on read 
            Object *mcf; // [31:31] MMC counter freeze  
          } mmccr; 
          
          // MMCRIR (Ethernet MMC receive interrupt register (ETH_MMCRIR)) bitfields.
          struct { 
            Object *rfces; // [5:5] Received frames CRC error status 
            Object *rfaes; // [6:6] Received frames alignment error status 
            Object *rgufs; // [17:17] Received Good Unicast Frames Status  
          } mmcrir; 
          
          // MMCTIR (Ethernet MMC transmit interrupt register (ETH_MMCTIR)) bitfields.
          struct { 
            Object *tgfscs; // [14:14] Transmitted good frames single collision status 
            Object *tgfmscs; // [15:15] Transmitted good frames more single collision status 
            Object *tgfs; // [21:21] Transmitted good frames status  
          } mmctir; 
          
          // MMCRIMR (Ethernet MMC receive interrupt mask register (ETH_MMCRIMR)) bitfields.
          struct { 
            Object *rfcem; // [5:5] Received frame CRC error mask 
            Object *rfaem; // [6:6] Received frames alignment error mask 
            Object *rgufm; // [17:17] Received good unicast frames mask  
          } mmcrimr; 
          
          // MMCTIMR (Ethernet MMC transmit interrupt mask register (ETH_MMCTIMR)) bitfields.
          struct { 
            Object *tgfscm; // [14:14] Transmitted good frames single collision mask 
            Object *tgfmscm; // [15:15] Transmitted good frames more single collision mask 
            Object *tgfm; // [21:21] Transmitted good frames mask  
          } mmctimr; 
          
          // MMCTGFSCCR (Ethernet MMC transmitted good frames after a single collision counter) bitfields.
          struct { 
            Object *tgfscc; // [0:31] Transmitted good frames after a single collision counter  
          } mmctgfsccr; 
          
          // MMCTGFMSCCR (Ethernet MMC transmitted good frames after more than a single collision) bitfields.
          struct { 
            Object *tgfmscc; // [0:31] Transmitted good frames after more than a single collision counter  
          } mmctgfmsccr; 
          
          // MMCTGFCR (Ethernet MMC transmitted good frames counter register) bitfields.
          struct { 
            Object *tgfc; // [0:31] Transmitted good frames counter  
          } mmctgfcr; 
          
          // MMCRFCECR (Ethernet MMC received frames with CRC error counter register) bitfields.
          struct { 
            Object *rfcfc; // [0:31] Received frames with CRC error counter  
          } mmcrfcecr; 
          
          // MMCRFAECR (Ethernet MMC received frames with alignment error counter register) bitfields.
          struct { 
            Object *rfaec; // [0:31] Received frames with alignment error counter  
          } mmcrfaecr; 
          
          // MMCRGUFCR (MMC received good unicast frames counter register) bitfields.
          struct { 
            Object *rgufc; // [0:31] Received good unicast frames counter  
          } mmcrgufcr; 
        } fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32ETHERNET_MMCState;

// ----------------------------------------------------------------------------

#endif /* STM32_ETHERNET_MMC_H_ */
