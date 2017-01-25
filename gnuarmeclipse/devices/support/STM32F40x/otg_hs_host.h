/*
 * STM32 - OTG_HS_HOST (USB on the go high speed) emulation.
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

#ifndef STM32_OTG_HS_HOST_H_
#define STM32_OTG_HS_HOST_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_OTG_HS_HOST DEVICE_PATH_STM32 "OTG_HS_HOST"



// ----------------------------------------------------------------------------

#define TYPE_STM32_OTG_HS_HOST TYPE_STM32_PREFIX "otg_hs_host" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_OTG_HS_HOST_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32OTG_HS_HOSTParentClass;
typedef PeripheralState STM32OTG_HS_HOSTParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_OTG_HS_HOST_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32OTG_HS_HOSTClass, (obj), TYPE_STM32_OTG_HS_HOST)
#define STM32_OTG_HS_HOST_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32OTG_HS_HOSTClass, (klass), TYPE_STM32_OTG_HS_HOST)

typedef struct {
    // private: 
    STM32OTG_HS_HOSTParentClass parent_class;
    // public: 

    // None, so far.
} STM32OTG_HS_HOSTClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_OTG_HS_HOST_STATE(obj) \
    OBJECT_CHECK(STM32OTG_HS_HOSTState, (obj), TYPE_STM32_OTG_HS_HOST)

typedef struct {
    // private:
    STM32OTG_HS_HOSTParentState parent_obj;
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
        // F4 OTG_HS_HOST (USB on the go high speed) registers.
        struct { 
          Object *otg_hs_hcfg; // 0x0 (OTG_HS host configuration register) 
          Object *otg_hs_hfir; // 0x4 (OTG_HS Host frame interval register) 
          Object *otg_hs_hfnum; // 0x8 (OTG_HS host frame number/frame time remaining register) 
          Object *otg_hs_hptxsts; // 0x10 (OTG_HS_Host periodic transmit FIFO/queue status register) 
          Object *otg_hs_haint; // 0x14 (OTG_HS Host all channels interrupt register) 
          Object *otg_hs_haintmsk; // 0x18 (OTG_HS host all channels interrupt mask register) 
          Object *otg_hs_hprt; // 0x40 (OTG_HS host port control and status register) 
          Object *otg_hs_hcchar0; // 0x100 (OTG_HS host channel-0 characteristics register) 
          Object *otg_hs_hcchar1; // 0x120 (OTG_HS host channel-1 characteristics register) 
          Object *otg_hs_hcchar2; // 0x140 (OTG_HS host channel-2 characteristics register) 
          Object *otg_hs_hcchar3; // 0x160 (OTG_HS host channel-3 characteristics register) 
          Object *otg_hs_hcchar4; // 0x180 (OTG_HS host channel-4 characteristics register) 
          Object *otg_hs_hcchar5; // 0x1A0 (OTG_HS host channel-5 characteristics register) 
          Object *otg_hs_hcchar6; // 0x1C0 (OTG_HS host channel-6 characteristics register) 
          Object *otg_hs_hcchar7; // 0x1E0 (OTG_HS host channel-7 characteristics register) 
          Object *otg_hs_hcchar8; // 0x200 (OTG_HS host channel-8 characteristics register) 
          Object *otg_hs_hcchar9; // 0x220 (OTG_HS host channel-9 characteristics register) 
          Object *otg_hs_hcchar10; // 0x240 (OTG_HS host channel-10 characteristics register) 
          Object *otg_hs_hcchar11; // 0x260 (OTG_HS host channel-11 characteristics register) 
          Object *otg_hs_hcsplt0; // 0x104 (OTG_HS host channel-0 split control register) 
          Object *otg_hs_hcsplt1; // 0x124 (OTG_HS host channel-1 split control register) 
          Object *otg_hs_hcsplt2; // 0x144 (OTG_HS host channel-2 split control register) 
          Object *otg_hs_hcsplt3; // 0x164 (OTG_HS host channel-3 split control register) 
          Object *otg_hs_hcsplt4; // 0x184 (OTG_HS host channel-4 split control register) 
          Object *otg_hs_hcsplt5; // 0x1A4 (OTG_HS host channel-5 split control register) 
          Object *otg_hs_hcsplt6; // 0x1C4 (OTG_HS host channel-6 split control register) 
          Object *otg_hs_hcsplt7; // 0x1E4 (OTG_HS host channel-7 split control register) 
          Object *otg_hs_hcsplt8; // 0x204 (OTG_HS host channel-8 split control register) 
          Object *otg_hs_hcsplt9; // 0x224 (OTG_HS host channel-9 split control register) 
          Object *otg_hs_hcsplt10; // 0x244 (OTG_HS host channel-10 split control register) 
          Object *otg_hs_hcsplt11; // 0x264 (OTG_HS host channel-11 split control register) 
          Object *otg_hs_hcint0; // 0x108 (OTG_HS host channel-11 interrupt register) 
          Object *otg_hs_hcint1; // 0x128 (OTG_HS host channel-1 interrupt register) 
          Object *otg_hs_hcint2; // 0x148 (OTG_HS host channel-2 interrupt register) 
          Object *otg_hs_hcint3; // 0x168 (OTG_HS host channel-3 interrupt register) 
          Object *otg_hs_hcint4; // 0x188 (OTG_HS host channel-4 interrupt register) 
          Object *otg_hs_hcint5; // 0x1A8 (OTG_HS host channel-5 interrupt register) 
          Object *otg_hs_hcint6; // 0x1C8 (OTG_HS host channel-6 interrupt register) 
          Object *otg_hs_hcint7; // 0x1E8 (OTG_HS host channel-7 interrupt register) 
          Object *otg_hs_hcint8; // 0x208 (OTG_HS host channel-8 interrupt register) 
          Object *otg_hs_hcint9; // 0x228 (OTG_HS host channel-9 interrupt register) 
          Object *otg_hs_hcint10; // 0x248 (OTG_HS host channel-10 interrupt register) 
          Object *otg_hs_hcint11; // 0x268 (OTG_HS host channel-11 interrupt register) 
          Object *otg_hs_hcintmsk0; // 0x10C (OTG_HS host channel-11 interrupt mask register) 
          Object *otg_hs_hcintmsk1; // 0x12C (OTG_HS host channel-1 interrupt mask register) 
          Object *otg_hs_hcintmsk2; // 0x14C (OTG_HS host channel-2 interrupt mask register) 
          Object *otg_hs_hcintmsk3; // 0x16C (OTG_HS host channel-3 interrupt mask register) 
          Object *otg_hs_hcintmsk4; // 0x18C (OTG_HS host channel-4 interrupt mask register) 
          Object *otg_hs_hcintmsk5; // 0x1AC (OTG_HS host channel-5 interrupt mask register) 
          Object *otg_hs_hcintmsk6; // 0x1CC (OTG_HS host channel-6 interrupt mask register) 
          Object *otg_hs_hcintmsk7; // 0x1EC (OTG_HS host channel-7 interrupt mask register) 
          Object *otg_hs_hcintmsk8; // 0x20C (OTG_HS host channel-8 interrupt mask register) 
          Object *otg_hs_hcintmsk9; // 0x22C (OTG_HS host channel-9 interrupt mask register) 
          Object *otg_hs_hcintmsk10; // 0x24C (OTG_HS host channel-10 interrupt mask register) 
          Object *otg_hs_hcintmsk11; // 0x26C (OTG_HS host channel-11 interrupt mask register) 
          Object *otg_hs_hctsiz0; // 0x110 (OTG_HS host channel-11 transfer size register) 
          Object *otg_hs_hctsiz1; // 0x130 (OTG_HS host channel-1 transfer size register) 
          Object *otg_hs_hctsiz2; // 0x150 (OTG_HS host channel-2 transfer size register) 
          Object *otg_hs_hctsiz3; // 0x170 (OTG_HS host channel-3 transfer size register) 
          Object *otg_hs_hctsiz4; // 0x190 (OTG_HS host channel-4 transfer size register) 
          Object *otg_hs_hctsiz5; // 0x1B0 (OTG_HS host channel-5 transfer size register) 
          Object *otg_hs_hctsiz6; // 0x1D0 (OTG_HS host channel-6 transfer size register) 
          Object *otg_hs_hctsiz7; // 0x1F0 (OTG_HS host channel-7 transfer size register) 
          Object *otg_hs_hctsiz8; // 0x210 (OTG_HS host channel-8 transfer size register) 
          Object *otg_hs_hctsiz9; // 0x230 (OTG_HS host channel-9 transfer size register) 
          Object *otg_hs_hctsiz10; // 0x250 (OTG_HS host channel-10 transfer size register) 
          Object *otg_hs_hctsiz11; // 0x270 (OTG_HS host channel-11 transfer size register) 
          Object *otg_hs_hcdma0; // 0x114 (OTG_HS host channel-0 DMA address register) 
          Object *otg_hs_hcdma1; // 0x134 (OTG_HS host channel-1 DMA address register) 
          Object *otg_hs_hcdma2; // 0x154 (OTG_HS host channel-2 DMA address register) 
          Object *otg_hs_hcdma3; // 0x174 (OTG_HS host channel-3 DMA address register) 
          Object *otg_hs_hcdma4; // 0x194 (OTG_HS host channel-4 DMA address register) 
          Object *otg_hs_hcdma5; // 0x1B4 (OTG_HS host channel-5 DMA address register) 
          Object *otg_hs_hcdma6; // 0x1D4 (OTG_HS host channel-6 DMA address register) 
          Object *otg_hs_hcdma7; // 0x1F4 (OTG_HS host channel-7 DMA address register) 
          Object *otg_hs_hcdma8; // 0x214 (OTG_HS host channel-8 DMA address register) 
          Object *otg_hs_hcdma9; // 0x234 (OTG_HS host channel-9 DMA address register) 
          Object *otg_hs_hcdma10; // 0x254 (OTG_HS host channel-10 DMA address register) 
          Object *otg_hs_hcdma11; // 0x274 (OTG_HS host channel-11 DMA address register) 
        } reg;

        struct { 
          
          // OTG_HS_HCFG (OTG_HS host configuration register) bitfields.
          struct { 
            Object *fslspcs; // [0:1] FS/LS PHY clock select 
            Object *fslss; // [2:2] FS- and LS-only support  
          } otg_hs_hcfg; 
          
          // OTG_HS_HFIR (OTG_HS Host frame interval register) bitfields.
          struct { 
            Object *frivl; // [0:15] Frame interval  
          } otg_hs_hfir; 
          
          // OTG_HS_HFNUM (OTG_HS host frame number/frame time remaining register) bitfields.
          struct { 
            Object *frnum; // [0:15] Frame number 
            Object *ftrem; // [16:31] Frame time remaining  
          } otg_hs_hfnum; 
          
          // OTG_HS_HPTXSTS (OTG_HS_Host periodic transmit FIFO/queue status register) bitfields.
          struct { 
            Object *ptxfsavl; // [0:15] Periodic transmit data FIFO space available 
            Object *ptxqsav; // [16:23] Periodic transmit request queue space available 
            Object *ptxqtop; // [24:31] Top of the periodic transmit request queue  
          } otg_hs_hptxsts; 
          
          // OTG_HS_HAINT (OTG_HS Host all channels interrupt register) bitfields.
          struct { 
            Object *haint; // [0:15] Channel interrupts  
          } otg_hs_haint; 
          
          // OTG_HS_HAINTMSK (OTG_HS host all channels interrupt mask register) bitfields.
          struct { 
            Object *haintm; // [0:15] Channel interrupt mask  
          } otg_hs_haintmsk; 
          
          // OTG_HS_HPRT (OTG_HS host port control and status register) bitfields.
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
          } otg_hs_hprt; 
          
          // OTG_HS_HCCHAR0 (OTG_HS host channel-0 characteristics register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mc; // [20:21] Multi Count (MC) / Error Count (EC) 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } otg_hs_hcchar0; 
          
          // OTG_HS_HCCHAR1 (OTG_HS host channel-1 characteristics register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mc; // [20:21] Multi Count (MC) / Error Count (EC) 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } otg_hs_hcchar1; 
          
          // OTG_HS_HCCHAR2 (OTG_HS host channel-2 characteristics register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mc; // [20:21] Multi Count (MC) / Error Count (EC) 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } otg_hs_hcchar2; 
          
          // OTG_HS_HCCHAR3 (OTG_HS host channel-3 characteristics register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mc; // [20:21] Multi Count (MC) / Error Count (EC) 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } otg_hs_hcchar3; 
          
          // OTG_HS_HCCHAR4 (OTG_HS host channel-4 characteristics register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mc; // [20:21] Multi Count (MC) / Error Count (EC) 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } otg_hs_hcchar4; 
          
          // OTG_HS_HCCHAR5 (OTG_HS host channel-5 characteristics register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mc; // [20:21] Multi Count (MC) / Error Count (EC) 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } otg_hs_hcchar5; 
          
          // OTG_HS_HCCHAR6 (OTG_HS host channel-6 characteristics register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mc; // [20:21] Multi Count (MC) / Error Count (EC) 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } otg_hs_hcchar6; 
          
          // OTG_HS_HCCHAR7 (OTG_HS host channel-7 characteristics register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mc; // [20:21] Multi Count (MC) / Error Count (EC) 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } otg_hs_hcchar7; 
          
          // OTG_HS_HCCHAR8 (OTG_HS host channel-8 characteristics register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mc; // [20:21] Multi Count (MC) / Error Count (EC) 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } otg_hs_hcchar8; 
          
          // OTG_HS_HCCHAR9 (OTG_HS host channel-9 characteristics register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mc; // [20:21] Multi Count (MC) / Error Count (EC) 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } otg_hs_hcchar9; 
          
          // OTG_HS_HCCHAR10 (OTG_HS host channel-10 characteristics register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mc; // [20:21] Multi Count (MC) / Error Count (EC) 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } otg_hs_hcchar10; 
          
          // OTG_HS_HCCHAR11 (OTG_HS host channel-11 characteristics register) bitfields.
          struct { 
            Object *mpsiz; // [0:10] Maximum packet size 
            Object *epnum; // [11:14] Endpoint number 
            Object *epdir; // [15:15] Endpoint direction 
            Object *lsdev; // [17:17] Low-speed device 
            Object *eptyp; // [18:19] Endpoint type 
            Object *mc; // [20:21] Multi Count (MC) / Error Count (EC) 
            Object *dad; // [22:28] Device address 
            Object *oddfrm; // [29:29] Odd frame 
            Object *chdis; // [30:30] Channel disable 
            Object *chena; // [31:31] Channel enable  
          } otg_hs_hcchar11; 
          
          // OTG_HS_HCSPLT0 (OTG_HS host channel-0 split control register) bitfields.
          struct { 
            Object *prtaddr; // [0:6] Port address 
            Object *hubaddr; // [7:13] Hub address 
            Object *xactpos; // [14:15] XACTPOS 
            Object *complsplt; // [16:16] Do complete split 
            Object *spliten; // [31:31] Split enable  
          } otg_hs_hcsplt0; 
          
          // OTG_HS_HCSPLT1 (OTG_HS host channel-1 split control register) bitfields.
          struct { 
            Object *prtaddr; // [0:6] Port address 
            Object *hubaddr; // [7:13] Hub address 
            Object *xactpos; // [14:15] XACTPOS 
            Object *complsplt; // [16:16] Do complete split 
            Object *spliten; // [31:31] Split enable  
          } otg_hs_hcsplt1; 
          
          // OTG_HS_HCSPLT2 (OTG_HS host channel-2 split control register) bitfields.
          struct { 
            Object *prtaddr; // [0:6] Port address 
            Object *hubaddr; // [7:13] Hub address 
            Object *xactpos; // [14:15] XACTPOS 
            Object *complsplt; // [16:16] Do complete split 
            Object *spliten; // [31:31] Split enable  
          } otg_hs_hcsplt2; 
          
          // OTG_HS_HCSPLT3 (OTG_HS host channel-3 split control register) bitfields.
          struct { 
            Object *prtaddr; // [0:6] Port address 
            Object *hubaddr; // [7:13] Hub address 
            Object *xactpos; // [14:15] XACTPOS 
            Object *complsplt; // [16:16] Do complete split 
            Object *spliten; // [31:31] Split enable  
          } otg_hs_hcsplt3; 
          
          // OTG_HS_HCSPLT4 (OTG_HS host channel-4 split control register) bitfields.
          struct { 
            Object *prtaddr; // [0:6] Port address 
            Object *hubaddr; // [7:13] Hub address 
            Object *xactpos; // [14:15] XACTPOS 
            Object *complsplt; // [16:16] Do complete split 
            Object *spliten; // [31:31] Split enable  
          } otg_hs_hcsplt4; 
          
          // OTG_HS_HCSPLT5 (OTG_HS host channel-5 split control register) bitfields.
          struct { 
            Object *prtaddr; // [0:6] Port address 
            Object *hubaddr; // [7:13] Hub address 
            Object *xactpos; // [14:15] XACTPOS 
            Object *complsplt; // [16:16] Do complete split 
            Object *spliten; // [31:31] Split enable  
          } otg_hs_hcsplt5; 
          
          // OTG_HS_HCSPLT6 (OTG_HS host channel-6 split control register) bitfields.
          struct { 
            Object *prtaddr; // [0:6] Port address 
            Object *hubaddr; // [7:13] Hub address 
            Object *xactpos; // [14:15] XACTPOS 
            Object *complsplt; // [16:16] Do complete split 
            Object *spliten; // [31:31] Split enable  
          } otg_hs_hcsplt6; 
          
          // OTG_HS_HCSPLT7 (OTG_HS host channel-7 split control register) bitfields.
          struct { 
            Object *prtaddr; // [0:6] Port address 
            Object *hubaddr; // [7:13] Hub address 
            Object *xactpos; // [14:15] XACTPOS 
            Object *complsplt; // [16:16] Do complete split 
            Object *spliten; // [31:31] Split enable  
          } otg_hs_hcsplt7; 
          
          // OTG_HS_HCSPLT8 (OTG_HS host channel-8 split control register) bitfields.
          struct { 
            Object *prtaddr; // [0:6] Port address 
            Object *hubaddr; // [7:13] Hub address 
            Object *xactpos; // [14:15] XACTPOS 
            Object *complsplt; // [16:16] Do complete split 
            Object *spliten; // [31:31] Split enable  
          } otg_hs_hcsplt8; 
          
          // OTG_HS_HCSPLT9 (OTG_HS host channel-9 split control register) bitfields.
          struct { 
            Object *prtaddr; // [0:6] Port address 
            Object *hubaddr; // [7:13] Hub address 
            Object *xactpos; // [14:15] XACTPOS 
            Object *complsplt; // [16:16] Do complete split 
            Object *spliten; // [31:31] Split enable  
          } otg_hs_hcsplt9; 
          
          // OTG_HS_HCSPLT10 (OTG_HS host channel-10 split control register) bitfields.
          struct { 
            Object *prtaddr; // [0:6] Port address 
            Object *hubaddr; // [7:13] Hub address 
            Object *xactpos; // [14:15] XACTPOS 
            Object *complsplt; // [16:16] Do complete split 
            Object *spliten; // [31:31] Split enable  
          } otg_hs_hcsplt10; 
          
          // OTG_HS_HCSPLT11 (OTG_HS host channel-11 split control register) bitfields.
          struct { 
            Object *prtaddr; // [0:6] Port address 
            Object *hubaddr; // [7:13] Hub address 
            Object *xactpos; // [14:15] XACTPOS 
            Object *complsplt; // [16:16] Do complete split 
            Object *spliten; // [31:31] Split enable  
          } otg_hs_hcsplt11; 
          
          // OTG_HS_HCINT0 (OTG_HS host channel-11 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *ahberr; // [2:2] AHB error 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *nyet; // [6:6] Response received interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } otg_hs_hcint0; 
          
          // OTG_HS_HCINT1 (OTG_HS host channel-1 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *ahberr; // [2:2] AHB error 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *nyet; // [6:6] Response received interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } otg_hs_hcint1; 
          
          // OTG_HS_HCINT2 (OTG_HS host channel-2 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *ahberr; // [2:2] AHB error 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *nyet; // [6:6] Response received interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } otg_hs_hcint2; 
          
          // OTG_HS_HCINT3 (OTG_HS host channel-3 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *ahberr; // [2:2] AHB error 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *nyet; // [6:6] Response received interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } otg_hs_hcint3; 
          
          // OTG_HS_HCINT4 (OTG_HS host channel-4 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *ahberr; // [2:2] AHB error 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *nyet; // [6:6] Response received interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } otg_hs_hcint4; 
          
          // OTG_HS_HCINT5 (OTG_HS host channel-5 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *ahberr; // [2:2] AHB error 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *nyet; // [6:6] Response received interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } otg_hs_hcint5; 
          
          // OTG_HS_HCINT6 (OTG_HS host channel-6 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *ahberr; // [2:2] AHB error 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *nyet; // [6:6] Response received interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } otg_hs_hcint6; 
          
          // OTG_HS_HCINT7 (OTG_HS host channel-7 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *ahberr; // [2:2] AHB error 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *nyet; // [6:6] Response received interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } otg_hs_hcint7; 
          
          // OTG_HS_HCINT8 (OTG_HS host channel-8 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *ahberr; // [2:2] AHB error 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *nyet; // [6:6] Response received interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } otg_hs_hcint8; 
          
          // OTG_HS_HCINT9 (OTG_HS host channel-9 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *ahberr; // [2:2] AHB error 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *nyet; // [6:6] Response received interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } otg_hs_hcint9; 
          
          // OTG_HS_HCINT10 (OTG_HS host channel-10 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *ahberr; // [2:2] AHB error 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *nyet; // [6:6] Response received interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } otg_hs_hcint10; 
          
          // OTG_HS_HCINT11 (OTG_HS host channel-11 interrupt register) bitfields.
          struct { 
            Object *xfrc; // [0:0] Transfer completed 
            Object *chh; // [1:1] Channel halted 
            Object *ahberr; // [2:2] AHB error 
            Object *stall; // [3:3] STALL response received interrupt 
            Object *nak; // [4:4] NAK response received interrupt 
            Object *ack; // [5:5] ACK response received/transmitted interrupt 
            Object *nyet; // [6:6] Response received interrupt 
            Object *txerr; // [7:7] Transaction error 
            Object *bberr; // [8:8] Babble error 
            Object *frmor; // [9:9] Frame overrun 
            Object *dterr; // [10:10] Data toggle error  
          } otg_hs_hcint11; 
          
          // OTG_HS_HCINTMSK0 (OTG_HS host channel-11 interrupt mask register) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *ahberr; // [2:2] AHB error 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } otg_hs_hcintmsk0; 
          
          // OTG_HS_HCINTMSK1 (OTG_HS host channel-1 interrupt mask register) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *ahberr; // [2:2] AHB error 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } otg_hs_hcintmsk1; 
          
          // OTG_HS_HCINTMSK2 (OTG_HS host channel-2 interrupt mask register) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *ahberr; // [2:2] AHB error 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } otg_hs_hcintmsk2; 
          
          // OTG_HS_HCINTMSK3 (OTG_HS host channel-3 interrupt mask register) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *ahberr; // [2:2] AHB error 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } otg_hs_hcintmsk3; 
          
          // OTG_HS_HCINTMSK4 (OTG_HS host channel-4 interrupt mask register) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *ahberr; // [2:2] AHB error 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } otg_hs_hcintmsk4; 
          
          // OTG_HS_HCINTMSK5 (OTG_HS host channel-5 interrupt mask register) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *ahberr; // [2:2] AHB error 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } otg_hs_hcintmsk5; 
          
          // OTG_HS_HCINTMSK6 (OTG_HS host channel-6 interrupt mask register) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *ahberr; // [2:2] AHB error 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } otg_hs_hcintmsk6; 
          
          // OTG_HS_HCINTMSK7 (OTG_HS host channel-7 interrupt mask register) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *ahberr; // [2:2] AHB error 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } otg_hs_hcintmsk7; 
          
          // OTG_HS_HCINTMSK8 (OTG_HS host channel-8 interrupt mask register) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *ahberr; // [2:2] AHB error 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } otg_hs_hcintmsk8; 
          
          // OTG_HS_HCINTMSK9 (OTG_HS host channel-9 interrupt mask register) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *ahberr; // [2:2] AHB error 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } otg_hs_hcintmsk9; 
          
          // OTG_HS_HCINTMSK10 (OTG_HS host channel-10 interrupt mask register) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *ahberr; // [2:2] AHB error 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } otg_hs_hcintmsk10; 
          
          // OTG_HS_HCINTMSK11 (OTG_HS host channel-11 interrupt mask register) bitfields.
          struct { 
            Object *xfrcm; // [0:0] Transfer completed mask 
            Object *chhm; // [1:1] Channel halted mask 
            Object *ahberr; // [2:2] AHB error 
            Object *stallm; // [3:3] STALL response received interrupt mask 
            Object *nakm; // [4:4] NAK response received interrupt mask 
            Object *ackm; // [5:5] ACK response received/transmitted interrupt mask 
            Object *nyet; // [6:6] Response received interrupt mask 
            Object *txerrm; // [7:7] Transaction error mask 
            Object *bberrm; // [8:8] Babble error mask 
            Object *frmorm; // [9:9] Frame overrun mask 
            Object *dterrm; // [10:10] Data toggle error mask  
          } otg_hs_hcintmsk11; 
          
          // OTG_HS_HCTSIZ0 (OTG_HS host channel-11 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } otg_hs_hctsiz0; 
          
          // OTG_HS_HCTSIZ1 (OTG_HS host channel-1 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } otg_hs_hctsiz1; 
          
          // OTG_HS_HCTSIZ2 (OTG_HS host channel-2 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } otg_hs_hctsiz2; 
          
          // OTG_HS_HCTSIZ3 (OTG_HS host channel-3 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } otg_hs_hctsiz3; 
          
          // OTG_HS_HCTSIZ4 (OTG_HS host channel-4 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } otg_hs_hctsiz4; 
          
          // OTG_HS_HCTSIZ5 (OTG_HS host channel-5 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } otg_hs_hctsiz5; 
          
          // OTG_HS_HCTSIZ6 (OTG_HS host channel-6 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } otg_hs_hctsiz6; 
          
          // OTG_HS_HCTSIZ7 (OTG_HS host channel-7 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } otg_hs_hctsiz7; 
          
          // OTG_HS_HCTSIZ8 (OTG_HS host channel-8 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } otg_hs_hctsiz8; 
          
          // OTG_HS_HCTSIZ9 (OTG_HS host channel-9 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } otg_hs_hctsiz9; 
          
          // OTG_HS_HCTSIZ10 (OTG_HS host channel-10 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } otg_hs_hctsiz10; 
          
          // OTG_HS_HCTSIZ11 (OTG_HS host channel-11 transfer size register) bitfields.
          struct { 
            Object *xfrsiz; // [0:18] Transfer size 
            Object *pktcnt; // [19:28] Packet count 
            Object *dpid; // [29:30] Data PID  
          } otg_hs_hctsiz11; 
          
          // OTG_HS_HCDMA0 (OTG_HS host channel-0 DMA address register) bitfields.
          struct { 
            Object *dmaaddr; // [0:31] DMA address  
          } otg_hs_hcdma0; 
          
          // OTG_HS_HCDMA1 (OTG_HS host channel-1 DMA address register) bitfields.
          struct { 
            Object *dmaaddr; // [0:31] DMA address  
          } otg_hs_hcdma1; 
          
          // OTG_HS_HCDMA2 (OTG_HS host channel-2 DMA address register) bitfields.
          struct { 
            Object *dmaaddr; // [0:31] DMA address  
          } otg_hs_hcdma2; 
          
          // OTG_HS_HCDMA3 (OTG_HS host channel-3 DMA address register) bitfields.
          struct { 
            Object *dmaaddr; // [0:31] DMA address  
          } otg_hs_hcdma3; 
          
          // OTG_HS_HCDMA4 (OTG_HS host channel-4 DMA address register) bitfields.
          struct { 
            Object *dmaaddr; // [0:31] DMA address  
          } otg_hs_hcdma4; 
          
          // OTG_HS_HCDMA5 (OTG_HS host channel-5 DMA address register) bitfields.
          struct { 
            Object *dmaaddr; // [0:31] DMA address  
          } otg_hs_hcdma5; 
          
          // OTG_HS_HCDMA6 (OTG_HS host channel-6 DMA address register) bitfields.
          struct { 
            Object *dmaaddr; // [0:31] DMA address  
          } otg_hs_hcdma6; 
          
          // OTG_HS_HCDMA7 (OTG_HS host channel-7 DMA address register) bitfields.
          struct { 
            Object *dmaaddr; // [0:31] DMA address  
          } otg_hs_hcdma7; 
          
          // OTG_HS_HCDMA8 (OTG_HS host channel-8 DMA address register) bitfields.
          struct { 
            Object *dmaaddr; // [0:31] DMA address  
          } otg_hs_hcdma8; 
          
          // OTG_HS_HCDMA9 (OTG_HS host channel-9 DMA address register) bitfields.
          struct { 
            Object *dmaaddr; // [0:31] DMA address  
          } otg_hs_hcdma9; 
          
          // OTG_HS_HCDMA10 (OTG_HS host channel-10 DMA address register) bitfields.
          struct { 
            Object *dmaaddr; // [0:31] DMA address  
          } otg_hs_hcdma10; 
          
          // OTG_HS_HCDMA11 (OTG_HS host channel-11 DMA address register) bitfields.
          struct { 
            Object *dmaaddr; // [0:31] DMA address  
          } otg_hs_hcdma11; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32OTG_HS_HOSTState;

// ----------------------------------------------------------------------------

#endif /* STM32_OTG_HS_HOST_H_ */
