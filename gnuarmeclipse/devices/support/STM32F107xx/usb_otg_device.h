/*
 * STM32- USB_OTG_DEVICE(USB on the go full speed) emulation.
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

#ifndef STM32_USB_OTG_DEVICE_H_
#define STM32_USB_OTG_DEVICE_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_USB_OTG_DEVICEDEVICE_PATH_STM32"USB_OTG_DEVICE"

// ----------------------------------------------------------------------------

#define TYPE_STM32_USB_OTG_DEVICETYPE_STM32_PREFIX "usb_otg_device" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_USB_OTG_DEVICE_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32USB_OTG_DEVICEParentClass;
typedef PeripheralState STM32USB_OTG_DEVICEParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_USB_OTG_DEVICE_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32USB_OTG_DEVICEClass, (obj), TYPE_STM32_USB_OTG_DEVICE)
#define STM32_USB_OTG_DEVICE_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32USB_OTG_DEVICEClass, (klass), TYPE_STM32_USB_OTG_DEVICE)

typedef struct {
    // private: 
    STM32USB_OTG_DEVICEParentClass parent_class;
    // public: 

    // None, so far.
} STM32USB_OTG_DEVICEClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_USB_OTG_DEVICE_STATE(obj) \
    OBJECT_CHECK(STM32USB_OTG_DEVICEState, (obj), TYPE_STM32_USB_OTG_DEVICE)

typedef struct {
    // private:
    STM32USB_OTG_DEVICEParentState parent_obj;
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
        // F1USB_OTG_DEVICE(USB on the go full speed) registers.
        struct { 
Object *fs_dcfg; // 0x0(OTG_FS device configuration register (OTG_FS_DCFG)) 
Object *fs_dctl; // 0x4(OTG_FS device control register (OTG_FS_DCTL)) 
Object *fs_dsts; // 0x8(OTG_FS device status register (OTG_FS_DSTS)) 
Object *fs_diepmsk; // 0x10(OTG_FS device IN endpoint common interrupt mask register (OTG_FS_DIEPMSK)) 
Object *fs_doepmsk; // 0x14(OTG_FS device OUT endpoint common interrupt mask register (OTG_FS_DOEPMSK)) 
Object *fs_daint; // 0x18(OTG_FS device all endpoints interrupt register (OTG_FS_DAINT)) 
Object *fs_daintmsk; // 0x1C(OTG_FS all endpoints interrupt mask register (OTG_FS_DAINTMSK)) 
Object *dvbusdis; // 0x28(OTG_FS device VBUS discharge time register) 
Object *dvbuspulse; // 0x2C(OTG_FS device VBUS pulsing time register) 
Object *diepempmsk; // 0x34(OTG_FS device IN endpoint FIFO empty interrupt mask register) 
Object *fs_diepctl0; // 0x100(OTG_FS device control IN endpoint 0 control register (OTG_FS_DIEPCTL0)) 
Object *diepctl1; // 0x120(OTG device endpoint-1 control register) 
Object *diepctl2; // 0x140(OTG device endpoint-2 control register) 
Object *diepctl3; // 0x160(OTG device endpoint-3 control register) 
Object *doepctl0; // 0x300(Device endpoint-0 control register) 
Object *doepctl1; // 0x320(Device endpoint-1 control register) 
Object *doepctl2; // 0x340(Device endpoint-2 control register) 
Object *doepctl3; // 0x360(Device endpoint-3 control register) 
Object *diepint0; // 0x108(Device endpoint-x interrupt register) 
Object *diepint1; // 0x128(Device endpoint-1 interrupt register) 
Object *diepint2; // 0x148(Device endpoint-2 interrupt register) 
Object *diepint3; // 0x168(Device endpoint-3 interrupt register) 
Object *doepint0; // 0x308(Device endpoint-0 interrupt register) 
Object *doepint1; // 0x328(Device endpoint-1 interrupt register) 
Object *doepint2; // 0x348(Device endpoint-2 interrupt register) 
Object *doepint3; // 0x368(Device endpoint-3 interrupt register) 
Object *dieptsiz0; // 0x110(Device endpoint-0 transfer size register) 
Object *doeptsiz0; // 0x310(Device OUT endpoint-0 transfer size register) 
Object *dieptsiz1; // 0x130(Device endpoint-1 transfer size register) 
Object *dieptsiz2; // 0x150(Device endpoint-2 transfer size register) 
Object *dieptsiz3; // 0x170(Device endpoint-3 transfer size register) 
Object *dtxfsts0; // 0x118(OTG_FS device IN endpoint transmit FIFO status register) 
Object *dtxfsts1; // 0x138(OTG_FS device IN endpoint transmit FIFO status register) 
Object *dtxfsts2; // 0x158(OTG_FS device IN endpoint transmit FIFO status register) 
Object *dtxfsts3; // 0x178(OTG_FS device IN endpoint transmit FIFO status register) 
Object *doeptsiz1; // 0x330(Device OUT endpoint-1 transfer size register) 
Object *doeptsiz2; // 0x350(Device OUT endpoint-2 transfer size register) 
Object *doeptsiz3; // 0x370(Device OUT endpoint-3 transfer size register) 
} reg;

        struct { 
// FS_DCFG(OTG_FS device configuration register (OTG_FS_DCFG)) bitfields.
          struct { 
Object *dspd; // [0:1] Device speedObject *nzlsohsk; // [2:2] Non-zero-length status OUT handshakeObject *dad; // [4:10] Device addressObject *pfivl; // [11:12] Periodic frame interval} fs_dcfg; 
// FS_DCTL(OTG_FS device control register (OTG_FS_DCTL)) bitfields.
          struct { 
Object *rwusig; // [0:0] Remote wakeup signalingObject *sdis; // [1:1] Soft disconnectObject *ginsts; // [2:2] Global IN NAK statusObject *gonsts; // [3:3] Global OUT NAK statusObject *tctl; // [4:6] Test controlObject *sginak; // [7:7] Set global IN NAKObject *cginak; // [8:8] Clear global IN NAKObject *sgonak; // [9:9] Set global OUT NAKObject *cgonak; // [10:10] Clear global OUT NAKObject *poprgdne; // [11:11] Power-on programming done} fs_dctl; 
// FS_DSTS(OTG_FS device status register (OTG_FS_DSTS)) bitfields.
          struct { 
Object *suspsts; // [0:0] Suspend statusObject *enumspd; // [1:2] Enumerated speedObject *eerr; // [3:3] Erratic errorObject *fnsof; // [8:21] Frame number of the received SOF} fs_dsts; 
// FS_DIEPMSK(OTG_FS device IN endpoint common interrupt mask register (OTG_FS_DIEPMSK)) bitfields.
          struct { 
Object *xfrcm; // [0:0] Transfer completed interrupt maskObject *epdm; // [1:1] Endpoint disabled interrupt maskObject *tom; // [3:3] Timeout condition mask (Non-isochronous endpoints)Object *ittxfemsk; // [4:4] IN token received when TxFIFO empty maskObject *inepnmm; // [5:5] IN token received with EP mismatch maskObject *inepnem; // [6:6] IN endpoint NAK effective mask} fs_diepmsk; 
// FS_DOEPMSK(OTG_FS device OUT endpoint common interrupt mask register (OTG_FS_DOEPMSK)) bitfields.
          struct { 
Object *xfrcm; // [0:0] Transfer completed interrupt maskObject *epdm; // [1:1] Endpoint disabled interrupt maskObject *stupm; // [3:3] SETUP phase done maskObject *otepdm; // [4:4] OUT token received when endpoint disabled mask} fs_doepmsk; 
// FS_DAINT(OTG_FS device all endpoints interrupt register (OTG_FS_DAINT)) bitfields.
          struct { 
Object *iepint; // [0:15] IN endpoint interrupt bitsObject *oepint; // [16:31] OUT endpoint interrupt bits} fs_daint; 
// FS_DAINTMSK(OTG_FS all endpoints interrupt mask register (OTG_FS_DAINTMSK)) bitfields.
          struct { 
Object *iepm; // [0:15] IN EP interrupt mask bitsObject *oepint; // [16:31] OUT endpoint interrupt bits} fs_daintmsk; 
// DVBUSDIS(OTG_FS device VBUS discharge time register) bitfields.
          struct { 
Object *vbusdt; // [0:15] Device VBUS discharge time} dvbusdis; 
// DVBUSPULSE(OTG_FS device VBUS pulsing time register) bitfields.
          struct { 
Object *dvbusp; // [0:11] Device VBUS pulsing time} dvbuspulse; 
// DIEPEMPMSK(OTG_FS device IN endpoint FIFO empty interrupt mask register) bitfields.
          struct { 
Object *ineptxfem; // [0:15] IN EP Tx FIFO empty interrupt mask bits} diepempmsk; 
// FS_DIEPCTL0(OTG_FS device control IN endpoint 0 control register (OTG_FS_DIEPCTL0)) bitfields.
          struct { 
Object *mpsiz; // [0:1] Maximum packet sizeObject *usbaep; // [15:15] USB active endpointObject *naksts; // [17:17] NAK statusObject *eptyp; // [18:19] Endpoint typeObject *stall; // [21:21] STALL handshakeObject *txfnum; // [22:25] TxFIFO numberObject *cnak; // [26:26] Clear NAKObject *snak; // [27:27] Set NAKObject *epdis; // [30:30] Endpoint disableObject *epena; // [31:31] Endpoint enable} fs_diepctl0; 
// DIEPCTL1(OTG device endpoint-1 control register) bitfields.
          struct { 
Object *mpsiz; // [0:10] MPSIZObject *usbaep; // [15:15] USBAEPObject *eonum_dpid; // [16:16] EONUM/DPIDObject *naksts; // [17:17] NAKSTSObject *eptyp; // [18:19] EPTYPObject *stall; // [21:21] StallObject *txfnum; // [22:25] TXFNUMObject *cnak; // [26:26] CNAKObject *snak; // [27:27] SNAKObject *sd0pid_sevnfrm; // [28:28] SD0PID/SEVNFRMObject *soddfrm_sd1pid; // [29:29] SODDFRM/SD1PIDObject *epdis; // [30:30] EPDISObject *epena; // [31:31] EPENA} diepctl1; 
// DIEPCTL2(OTG device endpoint-2 control register) bitfields.
          struct { 
Object *mpsiz; // [0:10] MPSIZObject *usbaep; // [15:15] USBAEPObject *eonum_dpid; // [16:16] EONUM/DPIDObject *naksts; // [17:17] NAKSTSObject *eptyp; // [18:19] EPTYPObject *stall; // [21:21] StallObject *txfnum; // [22:25] TXFNUMObject *cnak; // [26:26] CNAKObject *snak; // [27:27] SNAKObject *sd0pid_sevnfrm; // [28:28] SD0PID/SEVNFRMObject *soddfrm; // [29:29] SODDFRMObject *epdis; // [30:30] EPDISObject *epena; // [31:31] EPENA} diepctl2; 
// DIEPCTL3(OTG device endpoint-3 control register) bitfields.
          struct { 
Object *mpsiz; // [0:10] MPSIZObject *usbaep; // [15:15] USBAEPObject *eonum_dpid; // [16:16] EONUM/DPIDObject *naksts; // [17:17] NAKSTSObject *eptyp; // [18:19] EPTYPObject *stall; // [21:21] StallObject *txfnum; // [22:25] TXFNUMObject *cnak; // [26:26] CNAKObject *snak; // [27:27] SNAKObject *sd0pid_sevnfrm; // [28:28] SD0PID/SEVNFRMObject *soddfrm; // [29:29] SODDFRMObject *epdis; // [30:30] EPDISObject *epena; // [31:31] EPENA} diepctl3; 
// DOEPCTL0(Device endpoint-0 control register) bitfields.
          struct { 
Object *mpsiz; // [0:1] MPSIZObject *usbaep; // [15:15] USBAEPObject *naksts; // [17:17] NAKSTSObject *eptyp; // [18:19] EPTYPObject *snpm; // [20:20] SNPMObject *stall; // [21:21] StallObject *cnak; // [26:26] CNAKObject *snak; // [27:27] SNAKObject *epdis; // [30:30] EPDISObject *epena; // [31:31] EPENA} doepctl0; 
// DOEPCTL1(Device endpoint-1 control register) bitfields.
          struct { 
Object *mpsiz; // [0:10] MPSIZObject *usbaep; // [15:15] USBAEPObject *eonum_dpid; // [16:16] EONUM/DPIDObject *naksts; // [17:17] NAKSTSObject *eptyp; // [18:19] EPTYPObject *snpm; // [20:20] SNPMObject *stall; // [21:21] StallObject *cnak; // [26:26] CNAKObject *snak; // [27:27] SNAKObject *sd0pid_sevnfrm; // [28:28] SD0PID/SEVNFRMObject *soddfrm; // [29:29] SODDFRMObject *epdis; // [30:30] EPDISObject *epena; // [31:31] EPENA} doepctl1; 
// DOEPCTL2(Device endpoint-2 control register) bitfields.
          struct { 
Object *mpsiz; // [0:10] MPSIZObject *usbaep; // [15:15] USBAEPObject *eonum_dpid; // [16:16] EONUM/DPIDObject *naksts; // [17:17] NAKSTSObject *eptyp; // [18:19] EPTYPObject *snpm; // [20:20] SNPMObject *stall; // [21:21] StallObject *cnak; // [26:26] CNAKObject *snak; // [27:27] SNAKObject *sd0pid_sevnfrm; // [28:28] SD0PID/SEVNFRMObject *soddfrm; // [29:29] SODDFRMObject *epdis; // [30:30] EPDISObject *epena; // [31:31] EPENA} doepctl2; 
// DOEPCTL3(Device endpoint-3 control register) bitfields.
          struct { 
Object *mpsiz; // [0:10] MPSIZObject *usbaep; // [15:15] USBAEPObject *eonum_dpid; // [16:16] EONUM/DPIDObject *naksts; // [17:17] NAKSTSObject *eptyp; // [18:19] EPTYPObject *snpm; // [20:20] SNPMObject *stall; // [21:21] StallObject *cnak; // [26:26] CNAKObject *snak; // [27:27] SNAKObject *sd0pid_sevnfrm; // [28:28] SD0PID/SEVNFRMObject *soddfrm; // [29:29] SODDFRMObject *epdis; // [30:30] EPDISObject *epena; // [31:31] EPENA} doepctl3; 
// DIEPINT0(Device endpoint-x interrupt register) bitfields.
          struct { 
Object *xfrc; // [0:0] XFRCObject *epdisd; // [1:1] EPDISDObject *toc; // [3:3] TOCObject *ittxfe; // [4:4] ITTXFEObject *inepne; // [6:6] INEPNEObject *txfe; // [7:7] TXFE} diepint0; 
// DIEPINT1(Device endpoint-1 interrupt register) bitfields.
          struct { 
Object *xfrc; // [0:0] XFRCObject *epdisd; // [1:1] EPDISDObject *toc; // [3:3] TOCObject *ittxfe; // [4:4] ITTXFEObject *inepne; // [6:6] INEPNEObject *txfe; // [7:7] TXFE} diepint1; 
// DIEPINT2(Device endpoint-2 interrupt register) bitfields.
          struct { 
Object *xfrc; // [0:0] XFRCObject *epdisd; // [1:1] EPDISDObject *toc; // [3:3] TOCObject *ittxfe; // [4:4] ITTXFEObject *inepne; // [6:6] INEPNEObject *txfe; // [7:7] TXFE} diepint2; 
// DIEPINT3(Device endpoint-3 interrupt register) bitfields.
          struct { 
Object *xfrc; // [0:0] XFRCObject *epdisd; // [1:1] EPDISDObject *toc; // [3:3] TOCObject *ittxfe; // [4:4] ITTXFEObject *inepne; // [6:6] INEPNEObject *txfe; // [7:7] TXFE} diepint3; 
// DOEPINT0(Device endpoint-0 interrupt register) bitfields.
          struct { 
Object *xfrc; // [0:0] XFRCObject *epdisd; // [1:1] EPDISDObject *stup; // [3:3] STUPObject *otepdis; // [4:4] OTEPDISObject *b2bstup; // [6:6] B2BSTUP} doepint0; 
// DOEPINT1(Device endpoint-1 interrupt register) bitfields.
          struct { 
Object *xfrc; // [0:0] XFRCObject *epdisd; // [1:1] EPDISDObject *stup; // [3:3] STUPObject *otepdis; // [4:4] OTEPDISObject *b2bstup; // [6:6] B2BSTUP} doepint1; 
// DOEPINT2(Device endpoint-2 interrupt register) bitfields.
          struct { 
Object *xfrc; // [0:0] XFRCObject *epdisd; // [1:1] EPDISDObject *stup; // [3:3] STUPObject *otepdis; // [4:4] OTEPDISObject *b2bstup; // [6:6] B2BSTUP} doepint2; 
// DOEPINT3(Device endpoint-3 interrupt register) bitfields.
          struct { 
Object *xfrc; // [0:0] XFRCObject *epdisd; // [1:1] EPDISDObject *stup; // [3:3] STUPObject *otepdis; // [4:4] OTEPDISObject *b2bstup; // [6:6] B2BSTUP} doepint3; 
// DIEPTSIZ0(Device endpoint-0 transfer size register) bitfields.
          struct { 
Object *xfrsiz; // [0:6] Transfer sizeObject *pktcnt; // [19:20] Packet count} dieptsiz0; 
// DOEPTSIZ0(Device OUT endpoint-0 transfer size register) bitfields.
          struct { 
Object *xfrsiz; // [0:6] Transfer sizeObject *pktcnt; // [19:19] Packet countObject *stupcnt; // [29:30] SETUP packet count} doeptsiz0; 
// DIEPTSIZ1(Device endpoint-1 transfer size register) bitfields.
          struct { 
Object *xfrsiz; // [0:18] Transfer sizeObject *pktcnt; // [19:28] Packet countObject *mcnt; // [29:30] Multi count} dieptsiz1; 
// DIEPTSIZ2(Device endpoint-2 transfer size register) bitfields.
          struct { 
Object *xfrsiz; // [0:18] Transfer sizeObject *pktcnt; // [19:28] Packet countObject *mcnt; // [29:30] Multi count} dieptsiz2; 
// DIEPTSIZ3(Device endpoint-3 transfer size register) bitfields.
          struct { 
Object *xfrsiz; // [0:18] Transfer sizeObject *pktcnt; // [19:28] Packet countObject *mcnt; // [29:30] Multi count} dieptsiz3; 
// DTXFSTS0(OTG_FS device IN endpoint transmit FIFO status register) bitfields.
          struct { 
Object *ineptfsav; // [0:15] IN endpoint TxFIFO space available} dtxfsts0; 
// DTXFSTS1(OTG_FS device IN endpoint transmit FIFO status register) bitfields.
          struct { 
Object *ineptfsav; // [0:15] IN endpoint TxFIFO space available} dtxfsts1; 
// DTXFSTS2(OTG_FS device IN endpoint transmit FIFO status register) bitfields.
          struct { 
Object *ineptfsav; // [0:15] IN endpoint TxFIFO space available} dtxfsts2; 
// DTXFSTS3(OTG_FS device IN endpoint transmit FIFO status register) bitfields.
          struct { 
Object *ineptfsav; // [0:15] IN endpoint TxFIFO space available} dtxfsts3; 
// DOEPTSIZ1(Device OUT endpoint-1 transfer size register) bitfields.
          struct { 
Object *xfrsiz; // [0:18] Transfer sizeObject *pktcnt; // [19:28] Packet countObject *rxdpid_stupcnt; // [29:30] Received data PID/SETUP packet count} doeptsiz1; 
// DOEPTSIZ2(Device OUT endpoint-2 transfer size register) bitfields.
          struct { 
Object *xfrsiz; // [0:18] Transfer sizeObject *pktcnt; // [19:28] Packet countObject *rxdpid_stupcnt; // [29:30] Received data PID/SETUP packet count} doeptsiz2; 
// DOEPTSIZ3(Device OUT endpoint-3 transfer size register) bitfields.
          struct { 
Object *xfrsiz; // [0:18] Transfer sizeObject *pktcnt; // [19:28] Packet countObject *rxdpid_stupcnt; // [29:30] Received data PID/SETUP packet count} doeptsiz3; 
} fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32USB_OTG_DEVICEState;

// ----------------------------------------------------------------------------

#endif /* STM32_USB_OTG_DEVICE_H_ */
