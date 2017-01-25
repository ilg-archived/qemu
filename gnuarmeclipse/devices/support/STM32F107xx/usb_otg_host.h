/*
 * STM32 - USB_OTG_HOST (USB on the go full speed) emulation.
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

#ifndef STM32_USB_OTG_HOST_H_
#define STM32_USB_OTG_HOST_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_USB_OTG_HOST DEVICE_PATH_STM32 "USB_OTG_HOST"



// ----------------------------------------------------------------------------

#define TYPE_STM32_USB_OTG_HOST TYPE_STM32_PREFIX "usb_otg_host" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_USB_OTG_HOST_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32USB_OTG_HOSTParentClass;
typedef PeripheralState STM32USB_OTG_HOSTParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_USB_OTG_HOST_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32USB_OTG_HOSTClass, (obj), TYPE_STM32_USB_OTG_HOST)
#define STM32_USB_OTG_HOST_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32USB_OTG_HOSTClass, (klass), TYPE_STM32_USB_OTG_HOST)

typedef struct {
    // private: 
    STM32USB_OTG_HOSTParentClass parent_class;
    // public: 

    // None, so far.
} STM32USB_OTG_HOSTClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_USB_OTG_HOST_STATE(obj) \
    OBJECT_CHECK(STM32USB_OTG_HOSTState, (obj), TYPE_STM32_USB_OTG_HOST)

typedef struct {
    // private:
    STM32USB_OTG_HOSTParentState parent_obj;
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
        // F1 USB_OTG_HOST (USB on the go full speed) registers.
        struct { 
          Object *fs_hcfg; // 0x0 (OTG_FS host configuration register (OTG_FS_HCFG)) 
          Object *hfir; // 0x4 (OTG_FS Host frame interval register) 
          Object *fs_hfnum; // 0x8 (OTG_FS host frame number/frame time remaining register (OTG_FS_HFNUM)) 
          Object *fs_hptxsts; // 0x10 (OTG_FS_Host periodic transmit FIFO/queue status register (OTG_FS_HPTXSTS)) 
          Object *haint; // 0x14 (OTG_FS Host all channels interrupt register) 
          Object *haintmsk; // 0x18 (OTG_FS host all channels interrupt mask register) 
          Object *fs_hprt; // 0x40 (OTG_FS host port control and status register (OTG_FS_HPRT)) 
          Object *fs_hcchar0; // 0x100 (OTG_FS host channel-0 characteristics register (OTG_FS_HCCHAR0)) 
          Object *fs_hcchar1; // 0x120 (OTG_FS host channel-1 characteristics register (OTG_FS_HCCHAR1)) 
          Object *fs_hcchar2; // 0x140 (OTG_FS host channel-2 characteristics register (OTG_FS_HCCHAR2)) 
          Object *fs_hcchar3; // 0x160 (OTG_FS host channel-3 characteristics register (OTG_FS_HCCHAR3)) 
          Object *fs_hcchar4; // 0x180 (OTG_FS host channel-4 characteristics register (OTG_FS_HCCHAR4)) 
          Object *fs_hcchar5; // 0x1A0 (OTG_FS host channel-5 characteristics register (OTG_FS_HCCHAR5)) 
          Object *fs_hcchar6; // 0x1C0 (OTG_FS host channel-6 characteristics register (OTG_FS_HCCHAR6)) 
          Object *fs_hcchar7; // 0x1E0 (OTG_FS host channel-7 characteristics register (OTG_FS_HCCHAR7)) 
          Object *fs_hcint0; // 0x108 (OTG_FS host channel-0 interrupt register (OTG_FS_HCINT0)) 
          Object *fs_hcint1; // 0x128 (OTG_FS host channel-1 interrupt register (OTG_FS_HCINT1)) 
          Object *fs_hcint2; // 0x148 (OTG_FS host channel-2 interrupt register (OTG_FS_HCINT2)) 
          Object *fs_hcint3; // 0x168 (OTG_FS host channel-3 interrupt register (OTG_FS_HCINT3)) 
          Object *fs_hcint4; // 0x188 (OTG_FS host channel-4 interrupt register (OTG_FS_HCINT4)) 
          Object *fs_hcint5; // 0x1A8 (OTG_FS host channel-5 interrupt register (OTG_FS_HCINT5)) 
          Object *fs_hcint6; // 0x1C8 (OTG_FS host channel-6 interrupt register (OTG_FS_HCINT6)) 
          Object *fs_hcint7; // 0x1E8 (OTG_FS host channel-7 interrupt register (OTG_FS_HCINT7)) 
          Object *fs_hcintmsk0; // 0x10C (OTG_FS host channel-0 mask register (OTG_FS_HCINTMSK0)) 
          Object *fs_hcintmsk1; // 0x12C (OTG_FS host channel-1 mask register (OTG_FS_HCINTMSK1)) 
          Object *fs_hcintmsk2; // 0x14C (OTG_FS host channel-2 mask register (OTG_FS_HCINTMSK2)) 
          Object *fs_hcintmsk3; // 0x16C (OTG_FS host channel-3 mask register (OTG_FS_HCINTMSK3)) 
          Object *fs_hcintmsk4; // 0x18C (OTG_FS host channel-4 mask register (OTG_FS_HCINTMSK4)) 
          Object *fs_hcintmsk5; // 0x1AC (OTG_FS host channel-5 mask register (OTG_FS_HCINTMSK5)) 
          Object *fs_hcintmsk6; // 0x1CC (OTG_FS host channel-6 mask register (OTG_FS_HCINTMSK6)) 
          Object *fs_hcintmsk7; // 0x1EC (OTG_FS host channel-7 mask register (OTG_FS_HCINTMSK7)) 
          Object *fs_hctsiz0; // 0x110 (OTG_FS host channel-0 transfer size register) 
          Object *fs_hctsiz1; // 0x130 (OTG_FS host channel-1 transfer size register) 
          Object *fs_hctsiz2; // 0x150 (OTG_FS host channel-2 transfer size register) 
          Object *fs_hctsiz3; // 0x170 (OTG_FS host channel-3 transfer size register) 
          Object *fs_hctsiz4; // 0x190 (OTG_FS host channel-x transfer size register) 
          Object *fs_hctsiz5; // 0x1B0 (OTG_FS host channel-5 transfer size register) 
          Object *fs_hctsiz6; // 0x1D0 (OTG_FS host channel-6 transfer size register) 
          Object *fs_hctsiz7; // 0x1F0 (OTG_FS host channel-7 transfer size register) 
        } reg;

        struct { 
          
          // FS_HCFG (OTG_FS host configuration register (OTG_FS_HCFG)) bitfields.
          struct { 
            Object *fslspcs; // [0:1] FS/LS PHY clock select 
            Object *fslss; // [2:2] FS- and LS-only support  
          } fs_hcfg; 
          
          // HFIR (OTG_FS Host frame interval register) bitfields.
          struct { 
            Object *frivl; // [0:15] Frame interval  
          } hfir; 
          
          // FS_HFNUM (OTG_FS host frame number/frame time remaining register (OTG_FS_HFNUM)) bitfields.
          struct { 
            Object *frnum; // [0:15] Frame number 
            Object *ftrem; // [16:31] Frame time remaining  
          } fs_hfnum; 
          
          // FS_HPTXSTS (OTG_FS_Host periodic transmit FIFO/queue status register (OTG_FS_HPTXSTS)) bitfields.
          struct { 
            Object *ptxfsavl; // [0:15] Periodic transmit data FIFO space available 
            Object *ptxqsav; // [16:23] Periodic transmit request queue space available 
            Object *ptxqtop; // [24:31] Top of the periodic transmit request queue  
          } fs_hptxsts; 
          
          // HAINT (OTG_FS Host all channels interrupt register) bitfields.
          struct { 
            Object *haint; // [0:15] Channel interrupts  
          } haint; 
          
          // HAINTMSK (OTG_FS host all channels interrupt mask register) bitfields.
          struct { 
            Object *haintm; // [0:15] Channel interrupt mask  
          } haintmsk; 
          
          // FS_HPRT (OTG_FS host port control and status register (OTG_FS_HPRT)) bitfields.
          struct { 
            Object *pcsts; // [0:0] Port connect status 
            Object *pcdet; // [1:1] Port connect detected 
            Object *pena; // [2:2] Port enable 
            Object *penchng; // [3:3] Port enable/disable change 
            Object *poca; // [4:4] Port overcurrent active 
            Object *pocchng; // [5:5] Port overcurrent change 
            Object *pres; // [6:6] Port resume 
            Object *psusp; // [7:7] Port suspend 
            Object *prst; // [8:8] Port reset 
            Object *plsts; // [10:11] Port line status 
            Object *ppwr; // [12:12] Port power 
            Object *ptctl; // [13:16] Port test control 
            Object *pspd; // [17:18] Port speed  
          } fs_hprt; 
          
          // FS_HCCHAR0 (OTG_FS host channel-0 characteristics register (OTG_FS_HCCHAR0)) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mcnt; // [20:21] Multicount 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } fs_hcchar0; 
          
          // FS_HCCHAR1 (OTG_FS host channel-1 characteristics register (OTG_FS_HCCHAR1)) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mcnt; // [20:21] Multicount 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } fs_hcchar1; 
          
          // FS_HCCHAR2 (OTG_FS host channel-2 characteristics register (OTG_FS_HCCHAR2)) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mcnt; // [20:21] Multicount 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } fs_hcchar2; 
          
          // FS_HCCHAR3 (OTG_FS host channel-3 characteristics register (OTG_FS_HCCHAR3)) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mcnt; // [20:21] Multicount 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } fs_hcchar3; 
          
          // FS_HCCHAR4 (OTG_FS host channel-4 characteristics register (OTG_FS_HCCHAR4)) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mcnt; // [20:21] Multicount 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } fs_hcchar4; 
          
          // FS_HCCHAR5 (OTG_FS host channel-5 characteristics register (OTG_FS_HCCHAR5)) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mcnt; // [20:21] Multicount 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } fs_hcchar5; 
          
          // FS_HCCHAR6 (OTG_FS host channel-6 characteristics register (OTG_FS_HCCHAR6)) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mcnt; // [20:21] Multicount 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } fs_hcchar6; 
          
          // FS_HCCHAR7 (OTG_FS host channel-7 characteristics register (OTG_FS_HCCHAR7)) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mcnt; // [20:21] Multicount 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } fs_hcchar7; 
          
          // FS_HCINT0 (OTG_FS host channel-0 interrupt register (OTG_FS_HCINT0)) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } fs_hcint0; 
          
          // FS_HCINT1 (OTG_FS host channel-1 interrupt register (OTG_FS_HCINT1)) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } fs_hcint1; 
          
          // FS_HCINT2 (OTG_FS host channel-2 interrupt register (OTG_FS_HCINT2)) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } fs_hcint2; 
          
          // FS_HCINT3 (OTG_FS host channel-3 interrupt register (OTG_FS_HCINT3)) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } fs_hcint3; 
          
          // FS_HCINT4 (OTG_FS host channel-4 interrupt register (OTG_FS_HCINT4)) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } fs_hcint4; 
          
          // FS_HCINT5 (OTG_FS host channel-5 interrupt register (OTG_FS_HCINT5)) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } fs_hcint5; 
          
          // FS_HCINT6 (OTG_FS host channel-6 interrupt register (OTG_FS_HCINT6)) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } fs_hcint6; 
          
          // FS_HCINT7 (OTG_FS host channel-7 interrupt register (OTG_FS_HCINT7)) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } fs_hcint7; 
          
          // FS_HCINTMSK0 (OTG_FS host channel-0 mask register (OTG_FS_HCINTMSK0)) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } fs_hcintmsk0; 
          
          // FS_HCINTMSK1 (OTG_FS host channel-1 mask register (OTG_FS_HCINTMSK1)) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } fs_hcintmsk1; 
          
          // FS_HCINTMSK2 (OTG_FS host channel-2 mask register (OTG_FS_HCINTMSK2)) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } fs_hcintmsk2; 
          
          // FS_HCINTMSK3 (OTG_FS host channel-3 mask register (OTG_FS_HCINTMSK3)) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } fs_hcintmsk3; 
          
          // FS_HCINTMSK4 (OTG_FS host channel-4 mask register (OTG_FS_HCINTMSK4)) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } fs_hcintmsk4; 
          
          // FS_HCINTMSK5 (OTG_FS host channel-5 mask register (OTG_FS_HCINTMSK5)) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } fs_hcintmsk5; 
          
          // FS_HCINTMSK6 (OTG_FS host channel-6 mask register (OTG_FS_HCINTMSK6)) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } fs_hcintmsk6; 
          
          // FS_HCINTMSK7 (OTG_FS host channel-7 mask register (OTG_FS_HCINTMSK7)) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } fs_hcintmsk7; 
          
          // FS_HCTSIZ0 (OTG_FS host channel-0 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } fs_hctsiz0; 
          
          // FS_HCTSIZ1 (OTG_FS host channel-1 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } fs_hctsiz1; 
          
          // FS_HCTSIZ2 (OTG_FS host channel-2 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } fs_hctsiz2; 
          
          // FS_HCTSIZ3 (OTG_FS host channel-3 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } fs_hctsiz3; 
          
          // FS_HCTSIZ4 (OTG_FS host channel-x transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } fs_hctsiz4; 
          
          // FS_HCTSIZ5 (OTG_FS host channel-5 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } fs_hctsiz5; 
          
          // FS_HCTSIZ6 (OTG_FS host channel-6 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } fs_hctsiz6; 
          
          // FS_HCTSIZ7 (OTG_FS host channel-7 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } fs_hctsiz7; 
        } fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32USB_OTG_HOSTState;

// ----------------------------------------------------------------------------

#endif /* STM32_USB_OTG_HOST_H_ */
