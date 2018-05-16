/*
 * STM32 - Ethernet_DMA (Ethernet: DMA controller operation) emulation.
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

#ifndef STM32_Ethernet_DMA_H_
#define STM32_Ethernet_DMA_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_Ethernet_DMA DEVICE_PATH_STM32 "Ethernet_DMA"



// ----------------------------------------------------------------------------

#define TYPE_STM32_Ethernet_DMA TYPE_STM32_PREFIX "ethernet_dma" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_Ethernet_DMA_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32Ethernet_DMAParentClass;
typedef PeripheralState STM32Ethernet_DMAParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_Ethernet_DMA_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32Ethernet_DMAClass, (obj), TYPE_STM32_Ethernet_DMA)
#define STM32_Ethernet_DMA_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32Ethernet_DMAClass, (klass), TYPE_STM32_Ethernet_DMA)

typedef struct {
    // private: 
    STM32Ethernet_DMAParentClass parent_class;
    // public: 

    // None, so far.
} STM32Ethernet_DMAClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_Ethernet_DMA_STATE(obj) \
    OBJECT_CHECK(STM32Ethernet_DMAState, (obj), TYPE_STM32_Ethernet_DMA)

typedef struct {
    // private:
    STM32Ethernet_DMAParentState parent_obj;
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
        // F4 Ethernet_DMA (Ethernet: DMA controller operation) registers.
        struct { 
          Object *dmabmr; // 0x0 (Ethernet DMA bus mode register) 
          Object *dmatpdr; // 0x4 (Ethernet DMA transmit poll demand register) 
          Object *dmarpdr; // 0x8 (EHERNET DMA receive poll demand register) 
          Object *dmardlar; // 0xC (Ethernet DMA receive descriptor list address register) 
          Object *dmatdlar; // 0x10 (Ethernet DMA transmit descriptor list address register) 
          Object *dmasr; // 0x14 (Ethernet DMA status register) 
          Object *dmaomr; // 0x18 (Ethernet DMA operation mode register) 
          Object *dmaier; // 0x1C (Ethernet DMA interrupt enable register) 
          Object *dmamfbocr; // 0x20 (Ethernet DMA missed frame and buffer overflow counter register) 
          Object *dmarswtr; // 0x24 (Ethernet DMA receive status watchdog timer register) 
          Object *dmachtdr; // 0x48 (Ethernet DMA current host transmit descriptor register) 
          Object *dmachrdr; // 0x4C (Ethernet DMA current host receive descriptor register) 
          Object *dmachtbar; // 0x50 (Ethernet DMA current host transmit buffer address register) 
          Object *dmachrbar; // 0x54 (Ethernet DMA current host receive buffer address register) 
        } reg;

        struct { 
          
          // DMABMR (Ethernet DMA bus mode register) bitfields.
          struct { 
            Object *sr; // [0:0] No description available 
            Object *da; // [1:1] No description available 
            Object *dsl; // [2:6] No description available 
            Object *edfe; // [7:7] No description available 
            Object *pbl; // [8:13] No description available 
            Object *rtpr; // [14:15] No description available 
            Object *fb; // [16:16] No description available 
            Object *rdp; // [17:22] No description available 
            Object *usp; // [23:23] No description available 
            Object *fpm; // [24:24] No description available 
            Object *aab; // [25:25] No description available 
            Object *mb; // [26:26] No description available  
          } dmabmr; 
          
          // DMATPDR (Ethernet DMA transmit poll demand register) bitfields.
          struct { 
            Object *tpd; // [0:31] No description available  
          } dmatpdr; 
          
          // DMARPDR (EHERNET DMA receive poll demand register) bitfields.
          struct { 
            Object *rpd; // [0:31] RPD  
          } dmarpdr; 
          
          // DMARDLAR (Ethernet DMA receive descriptor list address register) bitfields.
          struct { 
            Object *srl; // [0:31] No description available  
          } dmardlar; 
          
          // DMATDLAR (Ethernet DMA transmit descriptor list address register) bitfields.
          struct { 
            Object *stl; // [0:31] No description available  
          } dmatdlar; 
          
          // DMASR (Ethernet DMA status register) bitfields.
          struct { 
            Object *ts; // [0:0] No description available 
            Object *tpss; // [1:1] No description available 
            Object *tbus; // [2:2] No description available 
            Object *tjts; // [3:3] No description available 
            Object *ros; // [4:4] No description available 
            Object *tus; // [5:5] No description available 
            Object *rs; // [6:6] No description available 
            Object *rbus; // [7:7] No description available 
            Object *rpss; // [8:8] No description available 
            Object *pwts; // [9:9] No description available 
            Object *ets; // [10:10] No description available 
            Object *fbes; // [13:13] No description available 
            Object *ers; // [14:14] No description available 
            Object *ais; // [15:15] No description available 
            Object *nis; // [16:16] No description available 
            Object *rps; // [17:19] No description available 
            Object *tps; // [20:22] No description available 
            Object *ebs; // [23:25] No description available 
            Object *mmcs; // [27:27] No description available 
            Object *pmts; // [28:28] No description available 
            Object *tsts; // [29:29] No description available  
          } dmasr; 
          
          // DMAOMR (Ethernet DMA operation mode register) bitfields.
          struct { 
            Object *sr; // [1:1] SR 
            Object *osf; // [2:2] OSF 
            Object *rtc; // [3:4] RTC 
            Object *fugf; // [6:6] FUGF 
            Object *fef; // [7:7] FEF 
            Object *st; // [13:13] ST 
            Object *ttc; // [14:16] TTC 
            Object *ftf; // [20:20] FTF 
            Object *tsf; // [21:21] TSF 
            Object *dfrf; // [24:24] DFRF 
            Object *rsf; // [25:25] RSF 
            Object *dtcefd; // [26:26] DTCEFD  
          } dmaomr; 
          
          // DMAIER (Ethernet DMA interrupt enable register) bitfields.
          struct { 
            Object *tie; // [0:0] No description available 
            Object *tpsie; // [1:1] No description available 
            Object *tbuie; // [2:2] No description available 
            Object *tjtie; // [3:3] No description available 
            Object *roie; // [4:4] No description available 
            Object *tuie; // [5:5] No description available 
            Object *rie; // [6:6] No description available 
            Object *rbuie; // [7:7] No description available 
            Object *rpsie; // [8:8] No description available 
            Object *rwtie; // [9:9] No description available 
            Object *etie; // [10:10] No description available 
            Object *fbeie; // [13:13] No description available 
            Object *erie; // [14:14] No description available 
            Object *aise; // [15:15] No description available 
            Object *nise; // [16:16] No description available  
          } dmaier; 
          
          // DMAMFBOCR (Ethernet DMA missed frame and buffer overflow counter register) bitfields.
          struct { 
            Object *mfc; // [0:15] No description available 
            Object *omfc; // [16:16] No description available 
            Object *mfa; // [17:27] No description available 
            Object *ofoc; // [28:28] No description available  
          } dmamfbocr; 
          
          // DMARSWTR (Ethernet DMA receive status watchdog timer register) bitfields.
          struct { 
            Object *rswtc; // [0:7] RSWTC  
          } dmarswtr; 
          
          // DMACHTDR (Ethernet DMA current host transmit descriptor register) bitfields.
          struct { 
            Object *htdap; // [0:31] HTDAP  
          } dmachtdr; 
          
          // DMACHRDR (Ethernet DMA current host receive descriptor register) bitfields.
          struct { 
            Object *hrdap; // [0:31] HRDAP  
          } dmachrdr; 
          
          // DMACHTBAR (Ethernet DMA current host transmit buffer address register) bitfields.
          struct { 
            Object *htbap; // [0:31] No description available  
          } dmachtbar; 
          
          // DMACHRBAR (Ethernet DMA current host receive buffer address register) bitfields.
          struct { 
            Object *hrbap; // [0:31] No description available  
          } dmachrbar; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32Ethernet_DMAState;

// ----------------------------------------------------------------------------

#endif /* STM32_Ethernet_DMA_H_ */
