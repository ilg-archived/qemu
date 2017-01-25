/*
 * STM32- ETHERNET_DMA(Ethernet: DMA controller operation) emulation.
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

#ifndef STM32_ETHERNET_DMA_H_
#define STM32_ETHERNET_DMA_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_ETHERNET_DMADEVICE_PATH_STM32"ETHERNET_DMA"

// ----------------------------------------------------------------------------

#define TYPE_STM32_ETHERNET_DMATYPE_STM32_PREFIX "ethernet_dma" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_ETHERNET_DMA_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32ETHERNET_DMAParentClass;
typedef PeripheralState STM32ETHERNET_DMAParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_ETHERNET_DMA_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32ETHERNET_DMAClass, (obj), TYPE_STM32_ETHERNET_DMA)
#define STM32_ETHERNET_DMA_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32ETHERNET_DMAClass, (klass), TYPE_STM32_ETHERNET_DMA)

typedef struct {
    // private: 
    STM32ETHERNET_DMAParentClass parent_class;
    // public: 

    // None, so far.
} STM32ETHERNET_DMAClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_ETHERNET_DMA_STATE(obj) \
    OBJECT_CHECK(STM32ETHERNET_DMAState, (obj), TYPE_STM32_ETHERNET_DMA)

typedef struct {
    // private:
    STM32ETHERNET_DMAParentState parent_obj;
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
        // F1ETHERNET_DMA(Ethernet: DMA controller operation) registers.
        struct { 
Object *dmabmr; // 0x0(Ethernet DMA bus mode register) 
Object *dmatpdr; // 0x4(Ethernet DMA transmit poll demand register) 
Object *dmarpdr; // 0x8(EHERNET DMA receive poll demand register) 
Object *dmardlar; // 0xC(Ethernet DMA receive descriptor list address register) 
Object *dmatdlar; // 0x10(Ethernet DMA transmit descriptor list address register) 
Object *dmasr; // 0x14(Ethernet DMA status register) 
Object *dmaomr; // 0x18(Ethernet DMA operation mode register) 
Object *dmaier; // 0x1C(Ethernet DMA interrupt enable register) 
Object *dmamfbocr; // 0x20(Ethernet DMA missed frame and buffer overflow counter register) 
Object *dmachtdr; // 0x48(Ethernet DMA current host transmit descriptor register) 
Object *dmachrdr; // 0x4C(Ethernet DMA current host receive descriptor register) 
Object *dmachtbar; // 0x50(Ethernet DMA current host transmit buffer address register) 
Object *dmachrbar; // 0x54(Ethernet DMA current host receive buffer address register) 
} reg;

        struct { 
// DMABMR(Ethernet DMA bus mode register) bitfields.
          struct { 
Object *sr; // [0:0] Software resetObject *da; // [1:1] DMA ArbitrationObject *dsl; // [2:6] Descriptor skip lengthObject *pbl; // [8:13] Programmable burst lengthObject *rtpr; // [14:15] Rx Tx priority ratioObject *fb; // [16:16] Fixed burstObject *rdp; // [17:22] Rx DMA PBLObject *usp; // [23:23] Use separate PBLObject *fpm; // [24:24] 4xPBL modeObject *aab; // [25:25] Address-aligned beats} dmabmr; 
// DMATPDR(Ethernet DMA transmit poll demand register) bitfields.
          struct { 
Object *tpd; // [0:31] Transmit poll demand} dmatpdr; 
// DMARPDR(EHERNET DMA receive poll demand register) bitfields.
          struct { 
Object *rpd; // [0:31] Receive poll demand} dmarpdr; 
// DMARDLAR(Ethernet DMA receive descriptor list address register) bitfields.
          struct { 
Object *srl; // [0:31] Start of receive list} dmardlar; 
// DMATDLAR(Ethernet DMA transmit descriptor list address register) bitfields.
          struct { 
Object *stl; // [0:31] Start of transmit list} dmatdlar; 
// DMASR(Ethernet DMA status register) bitfields.
          struct { 
Object *ts; // [0:0] Transmit statusObject *tpss; // [1:1] Transmit process stopped statusObject *tbus; // [2:2] Transmit buffer unavailable statusObject *tjts; // [3:3] Transmit jabber timeout statusObject *ros; // [4:4] Receive overflow statusObject *tus; // [5:5] Transmit underflow statusObject *rs; // [6:6] Receive statusObject *rbus; // [7:7] Receive buffer unavailable statusObject *rpss; // [8:8] Receive process stopped statusObject *pwts; // [9:9] Receive watchdog timeout statusObject *ets; // [10:10] Early transmit statusObject *fbes; // [13:13] Fatal bus error statusObject *ers; // [14:14] Early receive statusObject *ais; // [15:15] Abnormal interrupt summaryObject *nis; // [16:16] Normal interrupt summaryObject *rps; // [17:19] Receive process stateObject *tps; // [20:22] Transmit process stateObject *ebs; // [23:25] Error bits statusObject *mmcs; // [27:27] MMC statusObject *pmts; // [28:28] PMT statusObject *tsts; // [29:29] Time stamp trigger status} dmasr; 
// DMAOMR(Ethernet DMA operation mode register) bitfields.
          struct { 
Object *sr; // [1:1] SRObject *osf; // [2:2] OSFObject *rtc; // [3:4] RTCObject *fugf; // [6:6] FUGFObject *fef; // [7:7] FEFObject *st; // [13:13] STObject *ttc; // [14:16] TTCObject *ftf; // [20:20] FTFObject *tsf; // [21:21] TSFObject *dfrf; // [24:24] DFRFObject *rsf; // [25:25] RSFObject *dtcefd; // [26:26] DTCEFD} dmaomr; 
// DMAIER(Ethernet DMA interrupt enable register) bitfields.
          struct { 
Object *tie; // [0:0] Transmit interrupt enableObject *tpsie; // [1:1] Transmit process stopped interrupt enableObject *tbuie; // [2:2] Transmit buffer unavailable interrupt enableObject *tjtie; // [3:3] Transmit jabber timeout interrupt enableObject *roie; // [4:4] Overflow interrupt enableObject *tuie; // [5:5] Underflow interrupt enableObject *rie; // [6:6] Receive interrupt enableObject *rbuie; // [7:7] Receive buffer unavailable interrupt enableObject *rpsie; // [8:8] Receive process stopped interrupt enableObject *rwtie; // [9:9] Receive watchdog timeout interrupt enableObject *etie; // [10:10] Early transmit interrupt enableObject *fbeie; // [13:13] Fatal bus error interrupt enableObject *erie; // [14:14] Early receive interrupt enableObject *aise; // [15:15] Abnormal interrupt summary enableObject *nise; // [16:16] Normal interrupt summary enable} dmaier; 
// DMAMFBOCR(Ethernet DMA missed frame and buffer overflow counter register) bitfields.
          struct { 
Object *mfc; // [0:15] Missed frames by the controllerObject *omfc; // [16:16] Overflow bit for missed frame counterObject *mfa; // [17:27] Missed frames by the applicationObject *ofoc; // [28:28] Overflow bit for FIFO overflow counter} dmamfbocr; 
// DMACHTDR(Ethernet DMA current host transmit descriptor register) bitfields.
          struct { 
Object *htdap; // [0:31] Host transmit descriptor address pointer} dmachtdr; 
// DMACHRDR(Ethernet DMA current host receive descriptor register) bitfields.
          struct { 
Object *hrdap; // [0:31] Host receive descriptor address pointer} dmachrdr; 
// DMACHTBAR(Ethernet DMA current host transmit buffer address register) bitfields.
          struct { 
Object *htbap; // [0:31] Host transmit buffer address pointer} dmachtbar; 
// DMACHRBAR(Ethernet DMA current host receive buffer address register) bitfields.
          struct { 
Object *hrbap; // [0:31] Host receive buffer address pointer} dmachrbar; 
} fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32ETHERNET_DMAState;

// ----------------------------------------------------------------------------

#endif /* STM32_ETHERNET_DMA_H_ */
