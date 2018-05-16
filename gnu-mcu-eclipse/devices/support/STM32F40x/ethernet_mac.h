/*
 * STM32 - Ethernet_MAC (Ethernet: media access control (MAC)) emulation.
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

#ifndef STM32_Ethernet_MAC_H_
#define STM32_Ethernet_MAC_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_Ethernet_MAC DEVICE_PATH_STM32 "Ethernet_MAC"



// ----------------------------------------------------------------------------

#define TYPE_STM32_Ethernet_MAC TYPE_STM32_PREFIX "ethernet_mac" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_Ethernet_MAC_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32Ethernet_MACParentClass;
typedef PeripheralState STM32Ethernet_MACParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_Ethernet_MAC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32Ethernet_MACClass, (obj), TYPE_STM32_Ethernet_MAC)
#define STM32_Ethernet_MAC_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32Ethernet_MACClass, (klass), TYPE_STM32_Ethernet_MAC)

typedef struct {
    // private: 
    STM32Ethernet_MACParentClass parent_class;
    // public: 

    // None, so far.
} STM32Ethernet_MACClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_Ethernet_MAC_STATE(obj) \
    OBJECT_CHECK(STM32Ethernet_MACState, (obj), TYPE_STM32_Ethernet_MAC)

typedef struct {
    // private:
    STM32Ethernet_MACParentState parent_obj;
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
        // F4 Ethernet_MAC (Ethernet: media access control (MAC)) registers.
        struct { 
          Object *maccr; // 0x0 (Ethernet MAC configuration register) 
          Object *macffr; // 0x4 (Ethernet MAC frame filter register) 
          Object *machthr; // 0x8 (Ethernet MAC hash table high register) 
          Object *machtlr; // 0xC (Ethernet MAC hash table low register) 
          Object *macmiiar; // 0x10 (Ethernet MAC MII address register) 
          Object *macmiidr; // 0x14 (Ethernet MAC MII data register) 
          Object *macfcr; // 0x18 (Ethernet MAC flow control register) 
          Object *macvlantr; // 0x1C (Ethernet MAC VLAN tag register) 
          Object *macpmtcsr; // 0x2C (Ethernet MAC PMT control and status register) 
          Object *macdbgr; // 0x34 (Ethernet MAC debug register) 
          Object *macsr; // 0x38 (Ethernet MAC interrupt status register) 
          Object *macimr; // 0x3C (Ethernet MAC interrupt mask register) 
          Object *maca0hr; // 0x40 (Ethernet MAC address 0 high register) 
          Object *maca0lr; // 0x44 (Ethernet MAC address 0 low register) 
          Object *maca1hr; // 0x48 (Ethernet MAC address 1 high register) 
          Object *maca1lr; // 0x4C (Ethernet MAC address1 low register) 
          Object *maca2hr; // 0x50 (Ethernet MAC address 2 high register) 
          Object *maca2lr; // 0x54 (Ethernet MAC address 2 low register) 
          Object *maca3hr; // 0x58 (Ethernet MAC address 3 high register) 
          Object *maca3lr; // 0x5C (Ethernet MAC address 3 low register) 
        } reg;

        struct { 
          
          // MACCR (Ethernet MAC configuration register) bitfields.
          struct { 
            Object *re; // [2:2] RE 
            Object *te; // [3:3] TE 
            Object *dc; // [4:4] DC 
            Object *bl; // [5:6] BL 
            Object *apcs; // [7:7] APCS 
            Object *rd; // [9:9] RD 
            Object *ipco; // [10:10] IPCO 
            Object *dm; // [11:11] DM 
            Object *lm; // [12:12] LM 
            Object *rod; // [13:13] ROD 
            Object *fes; // [14:14] FES 
            Object *csd; // [16:16] CSD 
            Object *ifg; // [17:19] IFG 
            Object *jd; // [22:22] JD 
            Object *wd; // [23:23] WD 
            Object *cstf; // [25:25] CSTF  
          } maccr; 
          
          // MACFFR (Ethernet MAC frame filter register) bitfields.
          struct { 
            Object *pm; // [0:0] No description available 
            Object *hu; // [1:1] No description available 
            Object *hm; // [2:2] No description available 
            Object *daif; // [3:3] No description available 
            Object *ram; // [4:4] No description available 
            Object *bfd; // [5:5] No description available 
            Object *pcf; // [6:6] No description available 
            Object *saif; // [7:7] No description available 
            Object *saf; // [8:8] No description available 
            Object *hpf; // [9:9] No description available 
            Object *ra; // [31:31] No description available  
          } macffr; 
          
          // MACHTHR (Ethernet MAC hash table high register) bitfields.
          struct { 
            Object *hth; // [0:31] No description available  
          } machthr; 
          
          // MACHTLR (Ethernet MAC hash table low register) bitfields.
          struct { 
            Object *htl; // [0:31] No description available  
          } machtlr; 
          
          // MACMIIAR (Ethernet MAC MII address register) bitfields.
          struct { 
            Object *mb; // [0:0] No description available 
            Object *mw; // [1:1] No description available 
            Object *cr; // [2:4] No description available 
            Object *mr; // [6:10] No description available 
            Object *pa; // [11:15] No description available  
          } macmiiar; 
          
          // MACMIIDR (Ethernet MAC MII data register) bitfields.
          struct { 
            Object *td; // [0:15] No description available  
          } macmiidr; 
          
          // MACFCR (Ethernet MAC flow control register) bitfields.
          struct { 
            Object *fcb; // [0:0] No description available 
            Object *tfce; // [1:1] No description available 
            Object *rfce; // [2:2] No description available 
            Object *upfd; // [3:3] No description available 
            Object *plt; // [4:5] No description available 
            Object *zqpd; // [7:7] No description available 
            Object *pt; // [16:31] No description available  
          } macfcr; 
          
          // MACVLANTR (Ethernet MAC VLAN tag register) bitfields.
          struct { 
            Object *vlanti; // [0:15] No description available 
            Object *vlantc; // [16:16] No description available  
          } macvlantr; 
          
          // MACPMTCSR (Ethernet MAC PMT control and status register) bitfields.
          struct { 
            Object *pd; // [0:0] No description available 
            Object *mpe; // [1:1] No description available 
            Object *wfe; // [2:2] No description available 
            Object *mpr; // [5:5] No description available 
            Object *wfr; // [6:6] No description available 
            Object *gu; // [9:9] No description available 
            Object *wffrpr; // [31:31] No description available  
          } macpmtcsr; 
          
          // MACDBGR (Ethernet MAC debug register) bitfields.
          struct { 
            Object *cr; // [0:0] CR 
            Object *csr; // [1:1] CSR 
            Object *ror; // [2:2] ROR 
            Object *mcf; // [3:3] MCF 
            Object *mcp; // [4:4] MCP 
            Object *mcfhp; // [5:5] MCFHP  
          } macdbgr; 
          
          // MACSR (Ethernet MAC interrupt status register) bitfields.
          struct { 
            Object *pmts; // [3:3] No description available 
            Object *mmcs; // [4:4] No description available 
            Object *mmcrs; // [5:5] No description available 
            Object *mmcts; // [6:6] No description available 
            Object *tsts; // [9:9] No description available  
          } macsr; 
          
          // MACIMR (Ethernet MAC interrupt mask register) bitfields.
          struct { 
            Object *pmtim; // [3:3] No description available 
            Object *tstim; // [9:9] No description available  
          } macimr; 
          
          // MACA0HR (Ethernet MAC address 0 high register) bitfields.
          struct { 
            Object *maca0h; // [0:15] MAC address0 high 
            Object *mo; // [31:31] Always 1  
          } maca0hr; 
          
          // MACA0LR (Ethernet MAC address 0 low register) bitfields.
          struct { 
            Object *maca0l; // [0:31] 0  
          } maca0lr; 
          
          // MACA1HR (Ethernet MAC address 1 high register) bitfields.
          struct { 
            Object *maca1h; // [0:15] No description available 
            Object *mbc; // [24:29] No description available 
            Object *sa; // [30:30] No description available 
            Object *ae; // [31:31] No description available  
          } maca1hr; 
          
          // MACA1LR (Ethernet MAC address1 low register) bitfields.
          struct { 
            Object *maca1lr; // [0:31] No description available  
          } maca1lr; 
          
          // MACA2HR (Ethernet MAC address 2 high register) bitfields.
          struct { 
            Object *mac2ah; // [0:15] No description available 
            Object *mbc; // [24:29] No description available 
            Object *sa; // [30:30] No description available 
            Object *ae; // [31:31] No description available  
          } maca2hr; 
          
          // MACA2LR (Ethernet MAC address 2 low register) bitfields.
          struct { 
            Object *maca2l; // [0:30] No description available  
          } maca2lr; 
          
          // MACA3HR (Ethernet MAC address 3 high register) bitfields.
          struct { 
            Object *maca3h; // [0:15] No description available 
            Object *mbc; // [24:29] No description available 
            Object *sa; // [30:30] No description available 
            Object *ae; // [31:31] No description available  
          } maca3hr; 
          
          // MACA3LR (Ethernet MAC address 3 low register) bitfields.
          struct { 
            Object *mbca3l; // [0:31] No description available  
          } maca3lr; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32Ethernet_MACState;

// ----------------------------------------------------------------------------

#endif /* STM32_Ethernet_MAC_H_ */
