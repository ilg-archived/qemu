/*
 * STM32 - ETHERNET_MAC (Ethernet: media access control) emulation.
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

#ifndef STM32_ETHERNET_MAC_H_
#define STM32_ETHERNET_MAC_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_ETHERNET_MAC DEVICE_PATH_STM32 "ETHERNET_MAC"



// ----------------------------------------------------------------------------

#define TYPE_STM32_ETHERNET_MAC TYPE_STM32_PREFIX "ethernet_mac" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_ETHERNET_MAC_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32ETHERNET_MACParentClass;
typedef PeripheralState STM32ETHERNET_MACParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_ETHERNET_MAC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32ETHERNET_MACClass, (obj), TYPE_STM32_ETHERNET_MAC)
#define STM32_ETHERNET_MAC_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32ETHERNET_MACClass, (klass), TYPE_STM32_ETHERNET_MAC)

typedef struct {
    // private: 
    STM32ETHERNET_MACParentClass parent_class;
    // public: 

    // None, so far.
} STM32ETHERNET_MACClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_ETHERNET_MAC_STATE(obj) \
    OBJECT_CHECK(STM32ETHERNET_MACState, (obj), TYPE_STM32_ETHERNET_MAC)

typedef struct {
    // private:
    STM32ETHERNET_MACParentState parent_obj;
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
        // F1 ETHERNET_MAC (Ethernet: media access control) registers.
        struct { 
          Object *maccr; // 0x0 (Ethernet MAC configuration register (ETH_MACCR)) 
          Object *macffr; // 0x4 (Ethernet MAC frame filter register (ETH_MACCFFR)) 
          Object *machthr; // 0x8 (Ethernet MAC hash table high register) 
          Object *machtlr; // 0xC (Ethernet MAC hash table low register) 
          Object *macmiiar; // 0x10 (Ethernet MAC MII address register (ETH_MACMIIAR)) 
          Object *macmiidr; // 0x14 (Ethernet MAC MII data register (ETH_MACMIIDR)) 
          Object *macfcr; // 0x18 (Ethernet MAC flow control register (ETH_MACFCR)) 
          Object *macvlantr; // 0x1C (Ethernet MAC VLAN tag register (ETH_MACVLANTR)) 
          Object *macrwuffr; // 0x28 (Ethernet MAC remote wakeup frame filter register (ETH_MACRWUFFR)) 
          Object *macpmtcsr; // 0x2C (Ethernet MAC PMT control and status register (ETH_MACPMTCSR)) 
          Object *macsr; // 0x38 (Ethernet MAC interrupt status register (ETH_MACSR)) 
          Object *macimr; // 0x3C (Ethernet MAC interrupt mask register (ETH_MACIMR)) 
          Object *maca0hr; // 0x40 (Ethernet MAC address 0 high register (ETH_MACA0HR)) 
          Object *maca0lr; // 0x44 (Ethernet MAC address 0 low register) 
          Object *maca1hr; // 0x48 (Ethernet MAC address 1 high register (ETH_MACA1HR)) 
          Object *maca1lr; // 0x4C (Ethernet MAC address1 low register) 
          Object *maca2hr; // 0x50 (Ethernet MAC address 2 high register (ETH_MACA2HR)) 
          Object *maca2lr; // 0x54 (Ethernet MAC address 2 low register) 
          Object *maca3hr; // 0x58 (Ethernet MAC address 3 high register (ETH_MACA3HR)) 
          Object *maca3lr; // 0x5C (Ethernet MAC address 3 low register) 
        } reg;

        struct { 
          
          // MACCR (Ethernet MAC configuration register (ETH_MACCR)) bitfields.
          struct { 
            Object *re; // [2:2] Receiver enable 
            Object *te; // [3:3] Transmitter enable 
            Object *dc; // [4:4] Deferral check 
            Object *bl; // [5:6] Back-off limit 
            Object *apcs; // [7:7] Automatic pad/CRC stripping 
            Object *rd; // [9:9] Retry disable 
            Object *ipco; // [10:10] IPv4 checksum offload 
            Object *dm; // [11:11] Duplex mode 
            Object *lm; // [12:12] Loopback mode 
            Object *rod; // [13:13] Receive own disable 
            Object *fes; // [14:14] Fast Ethernet speed 
            Object *csd; // [16:16] Carrier sense disable 
            Object *ifg; // [17:19] Interframe gap 
            Object *jd; // [22:22] Jabber disable 
            Object *wd; // [23:23] Watchdog disable  
          } maccr; 
          
          // MACFFR (Ethernet MAC frame filter register (ETH_MACCFFR)) bitfields.
          struct { 
            Object *pm; // [0:0] Promiscuous mode 
            Object *hu; // [1:1] Hash unicast 
            Object *hm; // [2:2] Hash multicast 
            Object *daif; // [3:3] Destination address inverse filtering 
            Object *pam; // [4:4] Pass all multicast 
            Object *bfd; // [5:5] Broadcast frames disable 
            Object *pcf; // [6:7] Pass control frames 
            Object *saif; // [8:8] Source address inverse filtering 
            Object *saf; // [9:9] Source address filter 
            Object *hpf; // [10:10] Hash or perfect filter 
            Object *ra; // [31:31] Receive all  
          } macffr; 
          
          // MACHTHR (Ethernet MAC hash table high register) bitfields.
          struct { 
            Object *hth; // [0:31] Hash table high  
          } machthr; 
          
          // MACHTLR (Ethernet MAC hash table low register) bitfields.
          struct { 
            Object *htl; // [0:31] Hash table low  
          } machtlr; 
          
          // MACMIIAR (Ethernet MAC MII address register (ETH_MACMIIAR)) bitfields.
          struct { 
            Object *mb; // [0:0] MII busy 
            Object *mw; // [1:1] MII write 
            Object *cr; // [2:4] Clock range 
            Object *mr; // [6:10] MII register 
            Object *pa; // [11:15] PHY address  
          } macmiiar; 
          
          // MACMIIDR (Ethernet MAC MII data register (ETH_MACMIIDR)) bitfields.
          struct { 
            Object *md; // [0:15] MII data  
          } macmiidr; 
          
          // MACFCR (Ethernet MAC flow control register (ETH_MACFCR)) bitfields.
          struct { 
            Object *fcb_bpa; // [0:0] Flow control busy/back pressure activate 
            Object *tfce; // [1:1] Transmit flow control enable 
            Object *rfce; // [2:2] Receive flow control enable 
            Object *upfd; // [3:3] Unicast pause frame detect 
            Object *plt; // [4:5] Pause low threshold 
            Object *zqpd; // [7:7] Zero-quanta pause disable 
            Object *pt; // [16:31] Pass control frames  
          } macfcr; 
          
          // MACVLANTR (Ethernet MAC VLAN tag register (ETH_MACVLANTR)) bitfields.
          struct { 
            Object *vlanti; // [0:15] VLAN tag identifier (for receive frames) 
            Object *vlantc; // [16:16] 12-bit VLAN tag comparison  
          } macvlantr; 
          
          // MACRWUFFR (Ethernet MAC remote wakeup frame filter register (ETH_MACRWUFFR)) bitfields.
          struct { 
          } macrwuffr; 
          
          // MACPMTCSR (Ethernet MAC PMT control and status register (ETH_MACPMTCSR)) bitfields.
          struct { 
            Object *pd; // [0:0] Power down 
            Object *mpe; // [1:1] Magic Packet enable 
            Object *wfe; // [2:2] Wakeup frame enable 
            Object *mpr; // [5:5] Magic packet received 
            Object *wfr; // [6:6] Wakeup frame received 
            Object *gu; // [9:9] Global unicast 
            Object *wffrpr; // [31:31] Wakeup frame filter register pointer reset  
          } macpmtcsr; 
          
          // MACSR (Ethernet MAC interrupt status register (ETH_MACSR)) bitfields.
          struct { 
            Object *pmts; // [3:3] PMT status 
            Object *mmcs; // [4:4] MMC status 
            Object *mmcrs; // [5:5] MMC receive status 
            Object *mmcts; // [6:6] MMC transmit status 
            Object *tsts; // [9:9] Time stamp trigger status  
          } macsr; 
          
          // MACIMR (Ethernet MAC interrupt mask register (ETH_MACIMR)) bitfields.
          struct { 
            Object *pmtim; // [3:3] PMT interrupt mask 
            Object *tstim; // [9:9] Time stamp trigger interrupt mask  
          } macimr; 
          
          // MACA0HR (Ethernet MAC address 0 high register (ETH_MACA0HR)) bitfields.
          struct { 
            Object *maca0h; // [0:15] MAC address0 high 
            Object *mo; // [31:31] Always 1  
          } maca0hr; 
          
          // MACA0LR (Ethernet MAC address 0 low register) bitfields.
          struct { 
            Object *maca0l; // [0:31] MAC address0 low  
          } maca0lr; 
          
          // MACA1HR (Ethernet MAC address 1 high register (ETH_MACA1HR)) bitfields.
          struct { 
            Object *maca1h; // [0:15] MAC address1 high 
            Object *mbc; // [24:29] Mask byte control 
            Object *sa; // [30:30] Source address 
            Object *ae; // [31:31] Address enable  
          } maca1hr; 
          
          // MACA1LR (Ethernet MAC address1 low register) bitfields.
          struct { 
            Object *maca1l; // [0:31] MAC address1 low  
          } maca1lr; 
          
          // MACA2HR (Ethernet MAC address 2 high register (ETH_MACA2HR)) bitfields.
          struct { 
            Object *eth_maca2hr; // [0:15] Ethernet MAC address 2 high register 
            Object *mbc; // [24:29] Mask byte control 
            Object *sa; // [30:30] Source address 
            Object *ae; // [31:31] Address enable  
          } maca2hr; 
          
          // MACA2LR (Ethernet MAC address 2 low register) bitfields.
          struct { 
            Object *maca2l; // [0:30] MAC address2 low  
          } maca2lr; 
          
          // MACA3HR (Ethernet MAC address 3 high register (ETH_MACA3HR)) bitfields.
          struct { 
            Object *maca3h; // [0:15] MAC address3 high 
            Object *mbc; // [24:29] Mask byte control 
            Object *sa; // [30:30] Source address 
            Object *ae; // [31:31] Address enable  
          } maca3hr; 
          
          // MACA3LR (Ethernet MAC address 3 low register) bitfields.
          struct { 
            Object *mbca3l; // [0:31] MAC address3 low  
          } maca3lr; 
        } fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32ETHERNET_MACState;

// ----------------------------------------------------------------------------

#endif /* STM32_ETHERNET_MAC_H_ */
