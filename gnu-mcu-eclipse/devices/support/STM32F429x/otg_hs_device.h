/*
 * STM32 - OTG_HS_DEVICE (USB on the go high speed) emulation.
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

#ifndef STM32_OTG_HS_DEVICE_H_
#define STM32_OTG_HS_DEVICE_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_OTG_HS_DEVICE DEVICE_PATH_STM32 "OTG_HS_DEVICE"



// ----------------------------------------------------------------------------

#define TYPE_STM32_OTG_HS_DEVICE TYPE_STM32_PREFIX "otg_hs_device" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_OTG_HS_DEVICE_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32OTG_HS_DEVICEParentClass;
typedef PeripheralState STM32OTG_HS_DEVICEParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_OTG_HS_DEVICE_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32OTG_HS_DEVICEClass, (obj), TYPE_STM32_OTG_HS_DEVICE)
#define STM32_OTG_HS_DEVICE_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32OTG_HS_DEVICEClass, (klass), TYPE_STM32_OTG_HS_DEVICE)

typedef struct {
    // private: 
    STM32OTG_HS_DEVICEParentClass parent_class;
    // public: 

    // None, so far.
} STM32OTG_HS_DEVICEClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_OTG_HS_DEVICE_STATE(obj) \
    OBJECT_CHECK(STM32OTG_HS_DEVICEState, (obj), TYPE_STM32_OTG_HS_DEVICE)

typedef struct {
    // private:
    STM32OTG_HS_DEVICEParentState parent_obj;
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
        // F4 OTG_HS_DEVICE (USB on the go high speed) registers.
        struct { 
          Object *otg_hs_dcfg; // 0x0 (OTG_HS device configuration register) 
          Object *otg_hs_dctl; // 0x4 (OTG_HS device control register) 
          Object *otg_hs_dsts; // 0x8 (OTG_HS device status register) 
          Object *otg_hs_diepmsk; // 0x10 (OTG_HS device IN endpoint common interrupt mask register) 
          Object *otg_hs_doepmsk; // 0x14 (OTG_HS device OUT endpoint common interrupt mask register) 
          Object *otg_hs_daint; // 0x18 (OTG_HS device all endpoints interrupt register) 
          Object *otg_hs_daintmsk; // 0x1C (OTG_HS all endpoints interrupt mask register) 
          Object *otg_hs_dvbusdis; // 0x28 (OTG_HS device VBUS discharge time register) 
          Object *otg_hs_dvbuspulse; // 0x2C (OTG_HS device VBUS pulsing time register) 
          Object *otg_hs_dthrctl; // 0x30 (OTG_HS Device threshold control register) 
          Object *otg_hs_diepempmsk; // 0x34 (OTG_HS device IN endpoint FIFO empty interrupt mask register) 
          Object *otg_hs_deachint; // 0x38 (OTG_HS device each endpoint interrupt register) 
          Object *otg_hs_deachintmsk; // 0x3C (OTG_HS device each endpoint interrupt register mask) 
          Object *otg_hs_diepeachmsk1; // 0x40 (OTG_HS device each in endpoint-1 interrupt register) 
          Object *otg_hs_doepeachmsk1; // 0x80 (OTG_HS device each OUT endpoint-1 interrupt register) 
          Object *otg_hs_diepctl0; // 0x100 (OTG device endpoint-0 control register) 
          Object *otg_hs_diepctl1; // 0x120 (OTG device endpoint-1 control register) 
          Object *otg_hs_diepctl2; // 0x140 (OTG device endpoint-2 control register) 
          Object *otg_hs_diepctl3; // 0x160 (OTG device endpoint-3 control register) 
          Object *otg_hs_diepctl4; // 0x180 (OTG device endpoint-4 control register) 
          Object *otg_hs_diepctl5; // 0x1A0 (OTG device endpoint-5 control register) 
          Object *otg_hs_diepctl6; // 0x1C0 (OTG device endpoint-6 control register) 
          Object *otg_hs_diepctl7; // 0x1E0 (OTG device endpoint-7 control register) 
          Object *otg_hs_diepint0; // 0x108 (OTG device endpoint-0 interrupt register) 
          Object *otg_hs_diepint1; // 0x128 (OTG device endpoint-1 interrupt register) 
          Object *otg_hs_diepint2; // 0x148 (OTG device endpoint-2 interrupt register) 
          Object *otg_hs_diepint3; // 0x168 (OTG device endpoint-3 interrupt register) 
          Object *otg_hs_diepint4; // 0x188 (OTG device endpoint-4 interrupt register) 
          Object *otg_hs_diepint5; // 0x1A8 (OTG device endpoint-5 interrupt register) 
          Object *otg_hs_diepint6; // 0x1C8 (OTG device endpoint-6 interrupt register) 
          Object *otg_hs_diepint7; // 0x1E8 (OTG device endpoint-7 interrupt register) 
          Object *otg_hs_dieptsiz0; // 0x110 (OTG_HS device IN endpoint 0 transfer size register) 
          Object *otg_hs_diepdma1; // 0x114 (OTG_HS device endpoint-1 DMA address register) 
          Object *otg_hs_diepdma2; // 0x134 (OTG_HS device endpoint-2 DMA address register) 
          Object *otg_hs_diepdma3; // 0x154 (OTG_HS device endpoint-3 DMA address register) 
          Object *otg_hs_diepdma4; // 0x174 (OTG_HS device endpoint-4 DMA address register) 
          Object *otg_hs_diepdma5; // 0x194 (OTG_HS device endpoint-5 DMA address register) 
          Object *otg_hs_dtxfsts0; // 0x118 (OTG_HS device IN endpoint transmit FIFO status register) 
          Object *otg_hs_dtxfsts1; // 0x138 (OTG_HS device IN endpoint transmit FIFO status register) 
          Object *otg_hs_dtxfsts2; // 0x158 (OTG_HS device IN endpoint transmit FIFO status register) 
          Object *otg_hs_dtxfsts3; // 0x178 (OTG_HS device IN endpoint transmit FIFO status register) 
          Object *otg_hs_dtxfsts4; // 0x198 (OTG_HS device IN endpoint transmit FIFO status register) 
          Object *otg_hs_dtxfsts5; // 0x1B8 (OTG_HS device IN endpoint transmit FIFO status register) 
          Object *otg_hs_dieptsiz1; // 0x130 (OTG_HS device endpoint transfer size register) 
          Object *otg_hs_dieptsiz2; // 0x150 (OTG_HS device endpoint transfer size register) 
          Object *otg_hs_dieptsiz3; // 0x170 (OTG_HS device endpoint transfer size register) 
          Object *otg_hs_dieptsiz4; // 0x190 (OTG_HS device endpoint transfer size register) 
          Object *otg_hs_dieptsiz5; // 0x1B0 (OTG_HS device endpoint transfer size register) 
          Object *otg_hs_doepctl0; // 0x300 (OTG_HS device control OUT endpoint 0 control register) 
          Object *otg_hs_doepctl1; // 0x320 (OTG device endpoint-1 control register) 
          Object *otg_hs_doepctl2; // 0x340 (OTG device endpoint-2 control register) 
          Object *otg_hs_doepctl3; // 0x360 (OTG device endpoint-3 control register) 
          Object *otg_hs_doepint0; // 0x308 (OTG_HS device endpoint-0 interrupt register) 
          Object *otg_hs_doepint1; // 0x328 (OTG_HS device endpoint-1 interrupt register) 
          Object *otg_hs_doepint2; // 0x348 (OTG_HS device endpoint-2 interrupt register) 
          Object *otg_hs_doepint3; // 0x368 (OTG_HS device endpoint-3 interrupt register) 
          Object *otg_hs_doepint4; // 0x388 (OTG_HS device endpoint-4 interrupt register) 
          Object *otg_hs_doepint5; // 0x3A8 (OTG_HS device endpoint-5 interrupt register) 
          Object *otg_hs_doepint6; // 0x3C8 (OTG_HS device endpoint-6 interrupt register) 
          Object *otg_hs_doepint7; // 0x3E8 (OTG_HS device endpoint-7 interrupt register) 
          Object *otg_hs_doeptsiz0; // 0x310 (OTG_HS device endpoint-1 transfer size register) 
          Object *otg_hs_doeptsiz1; // 0x330 (OTG_HS device endpoint-2 transfer size register) 
          Object *otg_hs_doeptsiz2; // 0x350 (OTG_HS device endpoint-3 transfer size register) 
          Object *otg_hs_doeptsiz3; // 0x370 (OTG_HS device endpoint-4 transfer size register) 
          Object *otg_hs_doeptsiz4; // 0x390 (OTG_HS device endpoint-5 transfer size register) 
        } reg;

        struct { 
          
          // OTG_HS_DCFG (OTG_HS device configuration register) bitfields.
          struct { 
            Object *dspd; // [0:1] Device speed 
            Object *nzlsohsk; // [2:2] Nonzero-length status OUT handshake 
            Object *dad; // [4:10] Device address 
            Object *pfivl; // [11:12] Periodic (micro)frame interval 
            Object *perschivl; // [24:25] Periodic scheduling interval  
          } otg_hs_dcfg; 
          
          // OTG_HS_DCTL (OTG_HS device control register) bitfields.
          struct { 
            Object *rwusig; // [0:0] Remote wakeup signaling 
            Object *sdis; // [1:1] Soft disconnect 
            Object *ginsts; // [2:2] Global IN NAK status 
            Object *gonsts; // [3:3] Global OUT NAK status 
            Object *tctl; // [4:6] Test control 
            Object *sginak; // [7:7] Set global IN NAK 
            Object *cginak; // [8:8] Clear global IN NAK 
            Object *sgonak; // [9:9] Set global OUT NAK 
            Object *cgonak; // [10:10] Clear global OUT NAK 
            Object *poprgdne; // [11:11] Power-on programming done  
          } otg_hs_dctl; 
          
          // OTG_HS_DSTS (OTG_HS device status register) bitfields.
          struct { 
            Object *suspsts; // [0:0] Suspend status 
            Object *enumspd; // [1:2] Enumerated speed 
            Object *eerr; // [3:3] Erratic error 
            Object *fnsof; // [8:21] Frame number of the received SOF  
          } otg_hs_dsts; 
          
          // OTG_HS_DIEPMSK (OTG_HS device IN endpoint common interrupt mask register) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed interrupt mask 
            Object *epdm; // [1:1] Endpoint disabled interrupt mask 
            Object *tom; // [3:3] Timeout condition mask (nonisochronous endpoints) 
            Object *ittxfemsk; // [4:4] IN token received when TxFIFO empty mask 
            Object *inepnmm; // [5:5] IN token received with EP mismatch mask 
            Object *inepnem; // [6:6] IN endpoint NAK effective mask 
            Object *txfurm; // [8:8] FIFO underrun mask 
            Object *bim; // [9:9] BNA interrupt mask  
          } otg_hs_diepmsk; 
          
          // OTG_HS_DOEPMSK (OTG_HS device OUT endpoint common interrupt mask register) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed interrupt mask 
            Object *epdm; // [1:1] Endpoint disabled interrupt mask 
            Object *stupm; // [3:3] SETUP phase done mask 
            Object *otepdm; // [4:4] OUT token received when endpoint disabled mask 
            Object *b2bstup; // [6:6] Back-to-back SETUP packets received mask 
            Object *opem; // [8:8] OUT packet error mask 
            Object *boim; // [9:9] BNA interrupt mask  
          } otg_hs_doepmsk; 
          
          // OTG_HS_DAINT (OTG_HS device all endpoints interrupt register) bitfields.
          struct { 
            Object *iepint; // [0:15] IN endpoint interrupt bits 
            Object *oepint; // [16:31] OUT endpoint interrupt bits  
          } otg_hs_daint; 
          
          // OTG_HS_DAINTMSK (OTG_HS all endpoints interrupt mask register) bitfields.
          struct { 
            Object *iepm; // [0:15] IN EP interrupt mask bits 
            Object *oepm; // [16:31] OUT EP interrupt mask bits  
          } otg_hs_daintmsk; 
          
          // OTG_HS_DVBUSDIS (OTG_HS device VBUS discharge time register) bitfields.
          struct { 
            Object *vbusdt; // [0:15] Device VBUS discharge time  
          } otg_hs_dvbusdis; 
          
          // OTG_HS_DVBUSPULSE (OTG_HS device VBUS pulsing time register) bitfields.
          struct { 
            Object *dvbusp; // [0:11] Device VBUS pulsing time  
          } otg_hs_dvbuspulse; 
          
          // OTG_HS_DTHRCTL (OTG_HS Device threshold control register) bitfields.
          struct { 
            Object *nonisothren; // [0:0] Nonisochronous IN endpoints threshold enable 
            Object *isothren; // [1:1] ISO IN endpoint threshold enable 
            Object *txthrlen; // [2:10] Transmit threshold length 
            Object *rxthren; // [16:16] Receive threshold enable 
            Object *rxthrlen; // [17:25] Receive threshold length 
            Object *arpen; // [27:27] Arbiter parking enable  
          } otg_hs_dthrctl; 
          
          // OTG_HS_DIEPEMPMSK (OTG_HS device IN endpoint FIFO empty interrupt mask register) bitfields.
          struct { 
            Object *ineptxfem; // [0:15] IN EP Tx FIFO empty interrupt mask bits  
          } otg_hs_diepempmsk; 
          
          // OTG_HS_DEACHINT (OTG_HS device each endpoint interrupt register) bitfields.
          struct { 
            Object *iep1int; // [1:1] IN endpoint 1interrupt bit 
            Object *oep1int; // [17:17] OUT endpoint 1 interrupt bit  
          } otg_hs_deachint; 
          
          // OTG_HS_DEACHINTMSK (OTG_HS device each endpoint interrupt register mask) bitfields.
          struct { 
            Object *iep1intm; // [1:1] IN Endpoint 1 interrupt mask bit 
            Object *oep1intm; // [17:17] OUT Endpoint 1 interrupt mask bit  
          } otg_hs_deachintmsk; 
          
          // OTG_HS_DIEPEACHMSK1 (OTG_HS device each in endpoint-1 interrupt register) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed interrupt mask 
            Object *epdm; // [1:1] Endpoint disabled interrupt mask 
            Object *tom; // [3:3] Timeout condition mask (nonisochronous endpoints) 
            Object *ittxfemsk; // [4:4] IN token received when TxFIFO empty mask 
            Object *inepnmm; // [5:5] IN token received with EP mismatch mask 
            Object *inepnem; // [6:6] IN endpoint NAK effective mask 
            Object *txfurm; // [8:8] FIFO underrun mask 
            Object *bim; // [9:9] BNA interrupt mask 
            Object *nakm; // [13:13] NAK interrupt mask  
          } otg_hs_diepeachmsk1; 
          
          // OTG_HS_DOEPEACHMSK1 (OTG_HS device each OUT endpoint-1 interrupt register) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed interrupt mask 
            Object *epdm; // [1:1] Endpoint disabled interrupt mask 
            Object *tom; // [3:3] Timeout condition mask 
            Object *ittxfemsk; // [4:4] IN token received when TxFIFO empty mask 
            Object *inepnmm; // [5:5] IN token received with EP mismatch mask 
            Object *inepnem; // [6:6] IN endpoint NAK effective mask 
            Object *txfurm; // [8:8] OUT packet error mask 
            Object *bim; // [9:9] BNA interrupt mask 
            Object *berrm; // [12:12] Bubble error interrupt mask 
            Object *nakm; // [13:13] NAK interrupt mask 
            Object *nyetm; // [14:14] NYET interrupt mask  
          } otg_hs_doepeachmsk1; 
          
          // OTG_HS_DIEPCTL0 (OTG device endpoint-0 control register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *usbaep; // [15:15] USB active endpoint 
            Object *eonum_dpid; // [16:16] Even/odd frame 
            Object *naksts; // [17:17] NAK status 
            Object *eptyp; // [18:19] Endpoint type 
            Object *stall; // [21:21] STALL handshake 
            Object *txfnum; // [22:25] TxFIFO number 
            Object *cnak; // [26:26] Clear NAK 
            Object *snak; // [27:27] Set NAK 
            Object *sd0pid_sevnfrm; // [28:28] Set DATA0 PID 
            Object *soddfrm; // [29:29] Set odd frame 
            Object *epdis; // [30:30] Endpoint disable 
            Object *epena; // [31:31] Endpoint enable  
          } otg_hs_diepctl0; 
          
          // OTG_HS_DIEPCTL1 (OTG device endpoint-1 control register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *usbaep; // [15:15] USB active endpoint 
            Object *eonum_dpid; // [16:16] Even/odd frame 
            Object *naksts; // [17:17] NAK status 
            Object *eptyp; // [18:19] Endpoint type 
            Object *stall; // [21:21] STALL handshake 
            Object *txfnum; // [22:25] TxFIFO number 
            Object *cnak; // [26:26] Clear NAK 
            Object *snak; // [27:27] Set NAK 
            Object *sd0pid_sevnfrm; // [28:28] Set DATA0 PID 
            Object *soddfrm; // [29:29] Set odd frame 
            Object *epdis; // [30:30] Endpoint disable 
            Object *epena; // [31:31] Endpoint enable  
          } otg_hs_diepctl1; 
          
          // OTG_HS_DIEPCTL2 (OTG device endpoint-2 control register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *usbaep; // [15:15] USB active endpoint 
            Object *eonum_dpid; // [16:16] Even/odd frame 
            Object *naksts; // [17:17] NAK status 
            Object *eptyp; // [18:19] Endpoint type 
            Object *stall; // [21:21] STALL handshake 
            Object *txfnum; // [22:25] TxFIFO number 
            Object *cnak; // [26:26] Clear NAK 
            Object *snak; // [27:27] Set NAK 
            Object *sd0pid_sevnfrm; // [28:28] Set DATA0 PID 
            Object *soddfrm; // [29:29] Set odd frame 
            Object *epdis; // [30:30] Endpoint disable 
            Object *epena; // [31:31] Endpoint enable  
          } otg_hs_diepctl2; 
          
          // OTG_HS_DIEPCTL3 (OTG device endpoint-3 control register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *usbaep; // [15:15] USB active endpoint 
            Object *eonum_dpid; // [16:16] Even/odd frame 
            Object *naksts; // [17:17] NAK status 
            Object *eptyp; // [18:19] Endpoint type 
            Object *stall; // [21:21] STALL handshake 
            Object *txfnum; // [22:25] TxFIFO number 
            Object *cnak; // [26:26] Clear NAK 
            Object *snak; // [27:27] Set NAK 
            Object *sd0pid_sevnfrm; // [28:28] Set DATA0 PID 
            Object *soddfrm; // [29:29] Set odd frame 
            Object *epdis; // [30:30] Endpoint disable 
            Object *epena; // [31:31] Endpoint enable  
          } otg_hs_diepctl3; 
          
          // OTG_HS_DIEPCTL4 (OTG device endpoint-4 control register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *usbaep; // [15:15] USB active endpoint 
            Object *eonum_dpid; // [16:16] Even/odd frame 
            Object *naksts; // [17:17] NAK status 
            Object *eptyp; // [18:19] Endpoint type 
            Object *stall; // [21:21] STALL handshake 
            Object *txfnum; // [22:25] TxFIFO number 
            Object *cnak; // [26:26] Clear NAK 
            Object *snak; // [27:27] Set NAK 
            Object *sd0pid_sevnfrm; // [28:28] Set DATA0 PID 
            Object *soddfrm; // [29:29] Set odd frame 
            Object *epdis; // [30:30] Endpoint disable 
            Object *epena; // [31:31] Endpoint enable  
          } otg_hs_diepctl4; 
          
          // OTG_HS_DIEPCTL5 (OTG device endpoint-5 control register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *usbaep; // [15:15] USB active endpoint 
            Object *eonum_dpid; // [16:16] Even/odd frame 
            Object *naksts; // [17:17] NAK status 
            Object *eptyp; // [18:19] Endpoint type 
            Object *stall; // [21:21] STALL handshake 
            Object *txfnum; // [22:25] TxFIFO number 
            Object *cnak; // [26:26] Clear NAK 
            Object *snak; // [27:27] Set NAK 
            Object *sd0pid_sevnfrm; // [28:28] Set DATA0 PID 
            Object *soddfrm; // [29:29] Set odd frame 
            Object *epdis; // [30:30] Endpoint disable 
            Object *epena; // [31:31] Endpoint enable  
          } otg_hs_diepctl5; 
          
          // OTG_HS_DIEPCTL6 (OTG device endpoint-6 control register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *usbaep; // [15:15] USB active endpoint 
            Object *eonum_dpid; // [16:16] Even/odd frame 
            Object *naksts; // [17:17] NAK status 
            Object *eptyp; // [18:19] Endpoint type 
            Object *stall; // [21:21] STALL handshake 
            Object *txfnum; // [22:25] TxFIFO number 
            Object *cnak; // [26:26] Clear NAK 
            Object *snak; // [27:27] Set NAK 
            Object *sd0pid_sevnfrm; // [28:28] Set DATA0 PID 
            Object *soddfrm; // [29:29] Set odd frame 
            Object *epdis; // [30:30] Endpoint disable 
            Object *epena; // [31:31] Endpoint enable  
          } otg_hs_diepctl6; 
          
          // OTG_HS_DIEPCTL7 (OTG device endpoint-7 control register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *usbaep; // [15:15] USB active endpoint 
            Object *eonum_dpid; // [16:16] Even/odd frame 
            Object *naksts; // [17:17] NAK status 
            Object *eptyp; // [18:19] Endpoint type 
            Object *stall; // [21:21] STALL handshake 
            Object *txfnum; // [22:25] TxFIFO number 
            Object *cnak; // [26:26] Clear NAK 
            Object *snak; // [27:27] Set NAK 
            Object *sd0pid_sevnfrm; // [28:28] Set DATA0 PID 
            Object *soddfrm; // [29:29] Set odd frame 
            Object *epdis; // [30:30] Endpoint disable 
            Object *epena; // [31:31] Endpoint enable  
          } otg_hs_diepctl7; 
          
          // OTG_HS_DIEPINT0 (OTG device endpoint-0 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed interrupt 
            Object *epdisd; // [1:1] Endpoint disabled interrupt 
            Object *toc; // [3:3] Timeout condition 
            Object *ittxfe; // [4:4] IN token received when TxFIFO is empty 
            Object *inepne; // [6:6] IN endpoint NAK effective 
            Object *txfe; // [7:7] Transmit FIFO empty 
            Object *txfifoudrn; // [8:8] Transmit Fifo Underrun 
            Object *bna; // [9:9] Buffer not available interrupt 
            Object *pktdrpsts; // [11:11] Packet dropped status 
            Object *berr; // [12:12] Babble error interrupt 
            Object *nak; // [13:13] NAK interrupt  
          } otg_hs_diepint0; 
          
          // OTG_HS_DIEPINT1 (OTG device endpoint-1 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed interrupt 
            Object *epdisd; // [1:1] Endpoint disabled interrupt 
            Object *toc; // [3:3] Timeout condition 
            Object *ittxfe; // [4:4] IN token received when TxFIFO is empty 
            Object *inepne; // [6:6] IN endpoint NAK effective 
            Object *txfe; // [7:7] Transmit FIFO empty 
            Object *txfifoudrn; // [8:8] Transmit Fifo Underrun 
            Object *bna; // [9:9] Buffer not available interrupt 
            Object *pktdrpsts; // [11:11] Packet dropped status 
            Object *berr; // [12:12] Babble error interrupt 
            Object *nak; // [13:13] NAK interrupt  
          } otg_hs_diepint1; 
          
          // OTG_HS_DIEPINT2 (OTG device endpoint-2 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed interrupt 
            Object *epdisd; // [1:1] Endpoint disabled interrupt 
            Object *toc; // [3:3] Timeout condition 
            Object *ittxfe; // [4:4] IN token received when TxFIFO is empty 
            Object *inepne; // [6:6] IN endpoint NAK effective 
            Object *txfe; // [7:7] Transmit FIFO empty 
            Object *txfifoudrn; // [8:8] Transmit Fifo Underrun 
            Object *bna; // [9:9] Buffer not available interrupt 
            Object *pktdrpsts; // [11:11] Packet dropped status 
            Object *berr; // [12:12] Babble error interrupt 
            Object *nak; // [13:13] NAK interrupt  
          } otg_hs_diepint2; 
          
          // OTG_HS_DIEPINT3 (OTG device endpoint-3 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed interrupt 
            Object *epdisd; // [1:1] Endpoint disabled interrupt 
            Object *toc; // [3:3] Timeout condition 
            Object *ittxfe; // [4:4] IN token received when TxFIFO is empty 
            Object *inepne; // [6:6] IN endpoint NAK effective 
            Object *txfe; // [7:7] Transmit FIFO empty 
            Object *txfifoudrn; // [8:8] Transmit Fifo Underrun 
            Object *bna; // [9:9] Buffer not available interrupt 
            Object *pktdrpsts; // [11:11] Packet dropped status 
            Object *berr; // [12:12] Babble error interrupt 
            Object *nak; // [13:13] NAK interrupt  
          } otg_hs_diepint3; 
          
          // OTG_HS_DIEPINT4 (OTG device endpoint-4 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed interrupt 
            Object *epdisd; // [1:1] Endpoint disabled interrupt 
            Object *toc; // [3:3] Timeout condition 
            Object *ittxfe; // [4:4] IN token received when TxFIFO is empty 
            Object *inepne; // [6:6] IN endpoint NAK effective 
            Object *txfe; // [7:7] Transmit FIFO empty 
            Object *txfifoudrn; // [8:8] Transmit Fifo Underrun 
            Object *bna; // [9:9] Buffer not available interrupt 
            Object *pktdrpsts; // [11:11] Packet dropped status 
            Object *berr; // [12:12] Babble error interrupt 
            Object *nak; // [13:13] NAK interrupt  
          } otg_hs_diepint4; 
          
          // OTG_HS_DIEPINT5 (OTG device endpoint-5 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed interrupt 
            Object *epdisd; // [1:1] Endpoint disabled interrupt 
            Object *toc; // [3:3] Timeout condition 
            Object *ittxfe; // [4:4] IN token received when TxFIFO is empty 
            Object *inepne; // [6:6] IN endpoint NAK effective 
            Object *txfe; // [7:7] Transmit FIFO empty 
            Object *txfifoudrn; // [8:8] Transmit Fifo Underrun 
            Object *bna; // [9:9] Buffer not available interrupt 
            Object *pktdrpsts; // [11:11] Packet dropped status 
            Object *berr; // [12:12] Babble error interrupt 
            Object *nak; // [13:13] NAK interrupt  
          } otg_hs_diepint5; 
          
          // OTG_HS_DIEPINT6 (OTG device endpoint-6 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed interrupt 
            Object *epdisd; // [1:1] Endpoint disabled interrupt 
            Object *toc; // [3:3] Timeout condition 
            Object *ittxfe; // [4:4] IN token received when TxFIFO is empty 
            Object *inepne; // [6:6] IN endpoint NAK effective 
            Object *txfe; // [7:7] Transmit FIFO empty 
            Object *txfifoudrn; // [8:8] Transmit Fifo Underrun 
            Object *bna; // [9:9] Buffer not available interrupt 
            Object *pktdrpsts; // [11:11] Packet dropped status 
            Object *berr; // [12:12] Babble error interrupt 
            Object *nak; // [13:13] NAK interrupt  
          } otg_hs_diepint6; 
          
          // OTG_HS_DIEPINT7 (OTG device endpoint-7 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed interrupt 
            Object *epdisd; // [1:1] Endpoint disabled interrupt 
            Object *toc; // [3:3] Timeout condition 
            Object *ittxfe; // [4:4] IN token received when TxFIFO is empty 
            Object *inepne; // [6:6] IN endpoint NAK effective 
            Object *txfe; // [7:7] Transmit FIFO empty 
            Object *txfifoudrn; // [8:8] Transmit Fifo Underrun 
            Object *bna; // [9:9] Buffer not available interrupt 
            Object *pktdrpsts; // [11:11] Packet dropped status 
            Object *berr; // [12:12] Babble error interrupt 
            Object *nak; // [13:13] NAK interrupt  
          } otg_hs_diepint7; 
          
          // OTG_HS_DIEPTSIZ0 (OTG_HS device IN endpoint 0 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:6] Transfer size 
            Object *pktcnt; // [19:20] Packet count  
          } otg_hs_dieptsiz0; 
          
          // OTG_HS_DIEPDMA1 (OTG_HS device endpoint-1 DMA address register) bitfields.
          struct { 
            Object *dmaaddr; // [0:31] DMA address  
          } otg_hs_diepdma1; 
          
          // OTG_HS_DIEPDMA2 (OTG_HS device endpoint-2 DMA address register) bitfields.
          struct { 
            Object *dmaaddr; // [0:31] DMA address  
          } otg_hs_diepdma2; 
          
          // OTG_HS_DIEPDMA3 (OTG_HS device endpoint-3 DMA address register) bitfields.
          struct { 
            Object *dmaaddr; // [0:31] DMA address  
          } otg_hs_diepdma3; 
          
          // OTG_HS_DIEPDMA4 (OTG_HS device endpoint-4 DMA address register) bitfields.
          struct { 
            Object *dmaaddr; // [0:31] DMA address  
          } otg_hs_diepdma4; 
          
          // OTG_HS_DIEPDMA5 (OTG_HS device endpoint-5 DMA address register) bitfields.
          struct { 
            Object *dmaaddr; // [0:31] DMA address  
          } otg_hs_diepdma5; 
          
          // OTG_HS_DTXFSTS0 (OTG_HS device IN endpoint transmit FIFO status register) bitfields.
          struct { 
            Object *ineptfsav; // [0:15] IN endpoint TxFIFO space avail  
          } otg_hs_dtxfsts0; 
          
          // OTG_HS_DTXFSTS1 (OTG_HS device IN endpoint transmit FIFO status register) bitfields.
          struct { 
            Object *ineptfsav; // [0:15] IN endpoint TxFIFO space avail  
          } otg_hs_dtxfsts1; 
          
          // OTG_HS_DTXFSTS2 (OTG_HS device IN endpoint transmit FIFO status register) bitfields.
          struct { 
            Object *ineptfsav; // [0:15] IN endpoint TxFIFO space avail  
          } otg_hs_dtxfsts2; 
          
          // OTG_HS_DTXFSTS3 (OTG_HS device IN endpoint transmit FIFO status register) bitfields.
          struct { 
            Object *ineptfsav; // [0:15] IN endpoint TxFIFO space avail  
          } otg_hs_dtxfsts3; 
          
          // OTG_HS_DTXFSTS4 (OTG_HS device IN endpoint transmit FIFO status register) bitfields.
          struct { 
            Object *ineptfsav; // [0:15] IN endpoint TxFIFO space avail  
          } otg_hs_dtxfsts4; 
          
          // OTG_HS_DTXFSTS5 (OTG_HS device IN endpoint transmit FIFO status register) bitfields.
          struct { 
            Object *ineptfsav; // [0:15] IN endpoint TxFIFO space avail  
          } otg_hs_dtxfsts5; 
          
          // OTG_HS_DIEPTSIZ1 (OTG_HS device endpoint transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *mcnt; // [29:30] Multi count  
          } otg_hs_dieptsiz1; 
          
          // OTG_HS_DIEPTSIZ2 (OTG_HS device endpoint transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *mcnt; // [29:30] Multi count  
          } otg_hs_dieptsiz2; 
          
          // OTG_HS_DIEPTSIZ3 (OTG_HS device endpoint transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *mcnt; // [29:30] Multi count  
          } otg_hs_dieptsiz3; 
          
          // OTG_HS_DIEPTSIZ4 (OTG_HS device endpoint transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *mcnt; // [29:30] Multi count  
          } otg_hs_dieptsiz4; 
          
          // OTG_HS_DIEPTSIZ5 (OTG_HS device endpoint transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *mcnt; // [29:30] Multi count  
          } otg_hs_dieptsiz5; 
          
          // OTG_HS_DOEPCTL0 (OTG_HS device control OUT endpoint 0 control register) bitfields.
          struct { 
            Object *mpsiz; // [0:1] Maximum packet size 
            Object *usbaep; // [15:15] USB active endpoint 
            Object *naksts; // [17:17] NAK status 
            Object *eptyp; // [18:19] Endpoint type 
            Object *snpm; // [20:20] Snoop mode 
            Object *stall; // [21:21] STALL handshake 
            Object *cnak; // [26:26] Clear NAK 
            Object *snak; // [27:27] Set NAK 
            Object *epdis; // [30:30] Endpoint disable 
            Object *epena; // [31:31] Endpoint enable  
          } otg_hs_doepctl0; 
          
          // OTG_HS_DOEPCTL1 (OTG device endpoint-1 control register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *usbaep; // [15:15] USB active endpoint 
            Object *eonum_dpid; // [16:16] Even odd frame/Endpoint data PID 
            Object *naksts; // [17:17] NAK status 
            Object *eptyp; // [18:19] Endpoint type 
            Object *snpm; // [20:20] Snoop mode 
            Object *stall; // [21:21] STALL handshake 
            Object *cnak; // [26:26] Clear NAK 
            Object *snak; // [27:27] Set NAK 
            Object *sd0pid_sevnfrm; // [28:28] Set DATA0 PID/Set even frame 
            Object *soddfrm; // [29:29] Set odd frame 
            Object *epdis; // [30:30] Endpoint disable 
            Object *epena; // [31:31] Endpoint enable  
          } otg_hs_doepctl1; 
          
          // OTG_HS_DOEPCTL2 (OTG device endpoint-2 control register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *usbaep; // [15:15] USB active endpoint 
            Object *eonum_dpid; // [16:16] Even odd frame/Endpoint data PID 
            Object *naksts; // [17:17] NAK status 
            Object *eptyp; // [18:19] Endpoint type 
            Object *snpm; // [20:20] Snoop mode 
            Object *stall; // [21:21] STALL handshake 
            Object *cnak; // [26:26] Clear NAK 
            Object *snak; // [27:27] Set NAK 
            Object *sd0pid_sevnfrm; // [28:28] Set DATA0 PID/Set even frame 
            Object *soddfrm; // [29:29] Set odd frame 
            Object *epdis; // [30:30] Endpoint disable 
            Object *epena; // [31:31] Endpoint enable  
          } otg_hs_doepctl2; 
          
          // OTG_HS_DOEPCTL3 (OTG device endpoint-3 control register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *usbaep; // [15:15] USB active endpoint 
            Object *eonum_dpid; // [16:16] Even odd frame/Endpoint data PID 
            Object *naksts; // [17:17] NAK status 
            Object *eptyp; // [18:19] Endpoint type 
            Object *snpm; // [20:20] Snoop mode 
            Object *stall; // [21:21] STALL handshake 
            Object *cnak; // [26:26] Clear NAK 
            Object *snak; // [27:27] Set NAK 
            Object *sd0pid_sevnfrm; // [28:28] Set DATA0 PID/Set even frame 
            Object *soddfrm; // [29:29] Set odd frame 
            Object *epdis; // [30:30] Endpoint disable 
            Object *epena; // [31:31] Endpoint enable  
          } otg_hs_doepctl3; 
          
          // OTG_HS_DOEPINT0 (OTG_HS device endpoint-0 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed interrupt 
            Object *epdisd; // [1:1] Endpoint disabled interrupt 
            Object *stup; // [3:3] SETUP phase done 
            Object *otepdis; // [4:4] OUT token received when endpoint disabled 
            Object *b2bstup; // [6:6] Back-to-back SETUP packets received 
            Object *nyet; // [14:14] NYET interrupt  
          } otg_hs_doepint0; 
          
          // OTG_HS_DOEPINT1 (OTG_HS device endpoint-1 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed interrupt 
            Object *epdisd; // [1:1] Endpoint disabled interrupt 
            Object *stup; // [3:3] SETUP phase done 
            Object *otepdis; // [4:4] OUT token received when endpoint disabled 
            Object *b2bstup; // [6:6] Back-to-back SETUP packets received 
            Object *nyet; // [14:14] NYET interrupt  
          } otg_hs_doepint1; 
          
          // OTG_HS_DOEPINT2 (OTG_HS device endpoint-2 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed interrupt 
            Object *epdisd; // [1:1] Endpoint disabled interrupt 
            Object *stup; // [3:3] SETUP phase done 
            Object *otepdis; // [4:4] OUT token received when endpoint disabled 
            Object *b2bstup; // [6:6] Back-to-back SETUP packets received 
            Object *nyet; // [14:14] NYET interrupt  
          } otg_hs_doepint2; 
          
          // OTG_HS_DOEPINT3 (OTG_HS device endpoint-3 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed interrupt 
            Object *epdisd; // [1:1] Endpoint disabled interrupt 
            Object *stup; // [3:3] SETUP phase done 
            Object *otepdis; // [4:4] OUT token received when endpoint disabled 
            Object *b2bstup; // [6:6] Back-to-back SETUP packets received 
            Object *nyet; // [14:14] NYET interrupt  
          } otg_hs_doepint3; 
          
          // OTG_HS_DOEPINT4 (OTG_HS device endpoint-4 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed interrupt 
            Object *epdisd; // [1:1] Endpoint disabled interrupt 
            Object *stup; // [3:3] SETUP phase done 
            Object *otepdis; // [4:4] OUT token received when endpoint disabled 
            Object *b2bstup; // [6:6] Back-to-back SETUP packets received 
            Object *nyet; // [14:14] NYET interrupt  
          } otg_hs_doepint4; 
          
          // OTG_HS_DOEPINT5 (OTG_HS device endpoint-5 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed interrupt 
            Object *epdisd; // [1:1] Endpoint disabled interrupt 
            Object *stup; // [3:3] SETUP phase done 
            Object *otepdis; // [4:4] OUT token received when endpoint disabled 
            Object *b2bstup; // [6:6] Back-to-back SETUP packets received 
            Object *nyet; // [14:14] NYET interrupt  
          } otg_hs_doepint5; 
          
          // OTG_HS_DOEPINT6 (OTG_HS device endpoint-6 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed interrupt 
            Object *epdisd; // [1:1] Endpoint disabled interrupt 
            Object *stup; // [3:3] SETUP phase done 
            Object *otepdis; // [4:4] OUT token received when endpoint disabled 
            Object *b2bstup; // [6:6] Back-to-back SETUP packets received 
            Object *nyet; // [14:14] NYET interrupt  
          } otg_hs_doepint6; 
          
          // OTG_HS_DOEPINT7 (OTG_HS device endpoint-7 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed interrupt 
            Object *epdisd; // [1:1] Endpoint disabled interrupt 
            Object *stup; // [3:3] SETUP phase done 
            Object *otepdis; // [4:4] OUT token received when endpoint disabled 
            Object *b2bstup; // [6:6] Back-to-back SETUP packets received 
            Object *nyet; // [14:14] NYET interrupt  
          } otg_hs_doepint7; 
          
          // OTG_HS_DOEPTSIZ0 (OTG_HS device endpoint-1 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:6] Transfer size 
            Object *pktcnt; // [19:19] Packet count 
            Object *stupcnt; // [29:30] SETUP packet count  
          } otg_hs_doeptsiz0; 
          
          // OTG_HS_DOEPTSIZ1 (OTG_HS device endpoint-2 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *rxdpid_stupcnt; // [29:30] Received data PID/SETUP packet count  
          } otg_hs_doeptsiz1; 
          
          // OTG_HS_DOEPTSIZ2 (OTG_HS device endpoint-3 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *rxdpid_stupcnt; // [29:30] Received data PID/SETUP packet count  
          } otg_hs_doeptsiz2; 
          
          // OTG_HS_DOEPTSIZ3 (OTG_HS device endpoint-4 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *rxdpid_stupcnt; // [29:30] Received data PID/SETUP packet count  
          } otg_hs_doeptsiz3; 
          
          // OTG_HS_DOEPTSIZ4 (OTG_HS device endpoint-5 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *rxdpid_stupcnt; // [29:30] Received data PID/SETUP packet count  
          } otg_hs_doeptsiz4; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32OTG_HS_DEVICEState;

// ----------------------------------------------------------------------------

#endif /* STM32_OTG_HS_DEVICE_H_ */
