/*
 * STM32 - OTG_HS_GLOBAL (USB on the go high speed) emulation.
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

#ifndef STM32_OTG_HS_GLOBAL_H_
#define STM32_OTG_HS_GLOBAL_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_OTG_HS_GLOBAL DEVICE_PATH_STM32 "OTG_HS_GLOBAL"



// ----------------------------------------------------------------------------

#define TYPE_STM32_OTG_HS_GLOBAL TYPE_STM32_PREFIX "otg_hs_global" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_OTG_HS_GLOBAL_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32OTG_HS_GLOBALParentClass;
typedef PeripheralState STM32OTG_HS_GLOBALParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_OTG_HS_GLOBAL_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32OTG_HS_GLOBALClass, (obj), TYPE_STM32_OTG_HS_GLOBAL)
#define STM32_OTG_HS_GLOBAL_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32OTG_HS_GLOBALClass, (klass), TYPE_STM32_OTG_HS_GLOBAL)

typedef struct {
    // private: 
    STM32OTG_HS_GLOBALParentClass parent_class;
    // public: 

    // None, so far.
} STM32OTG_HS_GLOBALClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_OTG_HS_GLOBAL_STATE(obj) \
    OBJECT_CHECK(STM32OTG_HS_GLOBALState, (obj), TYPE_STM32_OTG_HS_GLOBAL)

typedef struct {
    // private:
    STM32OTG_HS_GLOBALParentState parent_obj;
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
        // F4 OTG_HS_GLOBAL (USB on the go high speed) registers.
        struct { 
          Object *otg_hs_gotgctl; // 0x0 (OTG_HS control and status register) 
          Object *otg_hs_gotgint; // 0x4 (OTG_HS interrupt register) 
          Object *otg_hs_gahbcfg; // 0x8 (OTG_HS AHB configuration register) 
          Object *otg_hs_gusbcfg; // 0xC (OTG_HS USB configuration register) 
          Object *otg_hs_grstctl; // 0x10 (OTG_HS reset register) 
          Object *otg_hs_gintsts; // 0x14 (OTG_HS core interrupt register) 
          Object *otg_hs_gintmsk; // 0x18 (OTG_HS interrupt mask register) 
          Object *otg_hs_grxstsr_host; // 0x1C (OTG_HS Receive status debug read register (host mode)) 
          Object *otg_hs_grxstsp_host; // 0x20 (OTG_HS status read and pop register (host mode)) 
          Object *otg_hs_grxfsiz; // 0x24 (OTG_HS Receive FIFO size register) 
          Object *otg_hs_gnptxfsiz_host; // 0x28 (OTG_HS nonperiodic transmit FIFO size register (host mode)) 
          Object *otg_hs_tx0fsiz_peripheral; // 0x28 (Endpoint 0 transmit FIFO size (peripheral mode)) 
          Object *otg_hs_gnptxsts; // 0x2C (OTG_HS nonperiodic transmit FIFO/queue status register) 
          Object *otg_hs_gccfg; // 0x38 (OTG_HS general core configuration register) 
          Object *otg_hs_cid; // 0x3C (OTG_HS core ID register) 
          Object *otg_hs_hptxfsiz; // 0x100 (OTG_HS Host periodic transmit FIFO size register) 
          Object *otg_hs_dieptxf1; // 0x104 (OTG_HS device IN endpoint transmit FIFO size register) 
          Object *otg_hs_dieptxf2; // 0x108 (OTG_HS device IN endpoint transmit FIFO size register) 
          Object *otg_hs_dieptxf3; // 0x11C (OTG_HS device IN endpoint transmit FIFO size register) 
          Object *otg_hs_dieptxf4; // 0x120 (OTG_HS device IN endpoint transmit FIFO size register) 
          Object *otg_hs_dieptxf5; // 0x124 (OTG_HS device IN endpoint transmit FIFO size register) 
          Object *otg_hs_dieptxf6; // 0x128 (OTG_HS device IN endpoint transmit FIFO size register) 
          Object *otg_hs_dieptxf7; // 0x12C (OTG_HS device IN endpoint transmit FIFO size register) 
          Object *otg_hs_grxstsr_peripheral; // 0x1C (OTG_HS Receive status debug read register (peripheral mode mode)) 
          Object *otg_hs_grxstsp_peripheral; // 0x20 (OTG_HS status read and pop register (peripheral mode)) 
        } reg;

        struct { 
          
          // OTG_HS_GOTGCTL (OTG_HS control and status register) bitfields.
          struct { 
            Object *srqscs; // [0:0] Session request success 
            Object *srq; // [1:1] Session request 
            Object *hngscs; // [8:8] Host negotiation success 
            Object *hnprq; // [9:9] HNP request 
            Object *hshnpen; // [10:10] Host set HNP enable 
            Object *dhnpen; // [11:11] Device HNP enabled 
            Object *cidsts; // [16:16] Connector ID status 
            Object *dbct; // [17:17] Long/short debounce time 
            Object *asvld; // [18:18] A-session valid 
            Object *bsvld; // [19:19] B-session valid  
          } otg_hs_gotgctl; 
          
          // OTG_HS_GOTGINT (OTG_HS interrupt register) bitfields.
          struct { 
            Object *sedet; // [2:2] Session end detected 
            Object *srsschg; // [8:8] Session request success status change 
            Object *hnsschg; // [9:9] Host negotiation success status change 
            Object *hngdet; // [17:17] Host negotiation detected 
            Object *adtochg; // [18:18] A-device timeout change 
            Object *dbcdne; // [19:19] Debounce done  
          } otg_hs_gotgint; 
          
          // OTG_HS_GAHBCFG (OTG_HS AHB configuration register) bitfields.
          struct { 
            Object *gint; // [0:0] Global interrupt mask 
            Object *hbstlen; // [1:4] Burst length/type 
            Object *dmaen; // [5:5] DMA enable 
            Object *txfelvl; // [7:7] TxFIFO empty level 
            Object *ptxfelvl; // [8:8] Periodic TxFIFO empty level  
          } otg_hs_gahbcfg; 
          
          // OTG_HS_GUSBCFG (OTG_HS USB configuration register) bitfields.
          struct { 
            Object *tocal; // [0:2] FS timeout calibration 
            Object *physel; // [6:6] USB 2.0 high-speed ULPI PHY or USB 1.1 full-speed serial transceiver select 
            Object *srpcap; // [8:8] SRP-capable 
            Object *hnpcap; // [9:9] HNP-capable 
            Object *trdt; // [10:13] USB turnaround time 
            Object *phylpcs; // [15:15] PHY Low-power clock select 
            Object *ulpifsls; // [17:17] ULPI FS/LS select 
            Object *ulpiar; // [18:18] ULPI Auto-resume 
            Object *ulpicsm; // [19:19] ULPI Clock SuspendM 
            Object *ulpievbusd; // [20:20] ULPI External VBUS Drive 
            Object *ulpievbusi; // [21:21] ULPI external VBUS indicator 
            Object *tsdps; // [22:22] TermSel DLine pulsing selection 
            Object *pcci; // [23:23] Indicator complement 
            Object *ptci; // [24:24] Indicator pass through 
            Object *ulpiipd; // [25:25] ULPI interface protect disable 
            Object *fhmod; // [29:29] Forced host mode 
            Object *fdmod; // [30:30] Forced peripheral mode 
            Object *ctxpkt; // [31:31] Corrupt Tx packet  
          } otg_hs_gusbcfg; 
          
          // OTG_HS_GRSTCTL (OTG_HS reset register) bitfields.
          struct { 
            Object *csrst; // [0:0] Core soft reset 
            Object *hsrst; // [1:1] HCLK soft reset 
            Object *fcrst; // [2:2] Host frame counter reset 
            Object *rxfflsh; // [4:4] RxFIFO flush 
            Object *txfflsh; // [5:5] TxFIFO flush 
            Object *txfnum; // [6:10] TxFIFO number 
            Object *dmareq; // [30:30] DMA request signal 
            Object *ahbidl; // [31:31] AHB master idle  
          } otg_hs_grstctl; 
          
          // OTG_HS_GINTSTS (OTG_HS core interrupt register) bitfields.
          struct { 
            Object *cmod; // [0:0] Current mode of operation 
            Object *mmis; // [1:1] Mode mismatch interrupt 
            Object *otgint; // [2:2] OTG interrupt 
            Object *sof; // [3:3] Start of frame 
            Object *rxflvl; // [4:4] RxFIFO nonempty 
            Object *nptxfe; // [5:5] Nonperiodic TxFIFO empty 
            Object *ginakeff; // [6:6] Global IN nonperiodic NAK effective 
            Object *boutnakeff; // [7:7] Global OUT NAK effective 
            Object *esusp; // [10:10] Early suspend 
            Object *usbsusp; // [11:11] USB suspend 
            Object *usbrst; // [12:12] USB reset 
            Object *enumdne; // [13:13] Enumeration done 
            Object *isoodrp; // [14:14] Isochronous OUT packet dropped interrupt 
            Object *eopf; // [15:15] End of periodic frame interrupt 
            Object *iepint; // [18:18] IN endpoint interrupt 
            Object *oepint; // [19:19] OUT endpoint interrupt 
            Object *iisoixfr; // [20:20] Incomplete isochronous IN transfer 
            Object *pxfr_incompisoout; // [21:21] Incomplete periodic transfer 
            Object *datafsusp; // [22:22] Data fetch suspended 
            Object *hprtint; // [24:24] Host port interrupt 
            Object *hcint; // [25:25] Host channels interrupt 
            Object *ptxfe; // [26:26] Periodic TxFIFO empty 
            Object *cidschg; // [28:28] Connector ID status change 
            Object *discint; // [29:29] Disconnect detected interrupt 
            Object *srqint; // [30:30] Session request/new session detected interrupt 
            Object *wkuint; // [31:31] Resume/remote wakeup detected interrupt  
          } otg_hs_gintsts; 
          
          // OTG_HS_GINTMSK (OTG_HS interrupt mask register) bitfields.
          struct { 
            Object *mmism; // [1:1] Mode mismatch interrupt mask 
            Object *otgint; // [2:2] OTG interrupt mask 
            Object *sofm; // [3:3] Start of frame mask 
            Object *rxflvlm; // [4:4] Receive FIFO nonempty mask 
            Object *nptxfem; // [5:5] Nonperiodic TxFIFO empty mask 
            Object *ginakeffm; // [6:6] Global nonperiodic IN NAK effective mask 
            Object *gonakeffm; // [7:7] Global OUT NAK effective mask 
            Object *esuspm; // [10:10] Early suspend mask 
            Object *usbsuspm; // [11:11] USB suspend mask 
            Object *usbrst; // [12:12] USB reset mask 
            Object *enumdnem; // [13:13] Enumeration done mask 
            Object *isoodrpm; // [14:14] Isochronous OUT packet dropped interrupt mask 
            Object *eopfm; // [15:15] End of periodic frame interrupt mask 
            Object *epmism; // [17:17] Endpoint mismatch interrupt mask 
            Object *iepint; // [18:18] IN endpoints interrupt mask 
            Object *oepint; // [19:19] OUT endpoints interrupt mask 
            Object *iisoixfrm; // [20:20] Incomplete isochronous IN transfer mask 
            Object *pxfrm_iisooxfrm; // [21:21] Incomplete periodic transfer mask 
            Object *fsuspm; // [22:22] Data fetch suspended mask 
            Object *prtim; // [24:24] Host port interrupt mask 
            Object *hcim; // [25:25] Host channels interrupt mask 
            Object *ptxfem; // [26:26] Periodic TxFIFO empty mask 
            Object *cidschgm; // [28:28] Connector ID status change mask 
            Object *discint; // [29:29] Disconnect detected interrupt mask 
            Object *srqim; // [30:30] Session request/new session detected interrupt mask 
            Object *wuim; // [31:31] Resume/remote wakeup detected interrupt mask  
          } otg_hs_gintmsk; 
          
          // OTG_HS_GRXSTSR_Host (OTG_HS Receive status debug read register (host mode)) bitfields.
          struct { 
            Object *chnum; // [0:3] Channel number 
            Object *bcnt; // [4:14] Byte count 
            Object *dpid; // [15:16] Data PID 
            Object *pktsts; // [17:20] Packet status  
          } otg_hs_grxstsr_host; 
          
          // OTG_HS_GRXSTSP_Host (OTG_HS status read and pop register (host mode)) bitfields.
          struct { 
            Object *chnum; // [0:3] Channel number 
            Object *bcnt; // [4:14] Byte count 
            Object *dpid; // [15:16] Data PID 
            Object *pktsts; // [17:20] Packet status  
          } otg_hs_grxstsp_host; 
          
          // OTG_HS_GRXFSIZ (OTG_HS Receive FIFO size register) bitfields.
          struct { 
            Object *rxfd; // [0:15] RxFIFO depth  
          } otg_hs_grxfsiz; 
          
          // OTG_HS_GNPTXFSIZ_Host (OTG_HS nonperiodic transmit FIFO size register (host mode)) bitfields.
          struct { 
            Object *nptxfsa; // [0:15] Nonperiodic transmit RAM start address 
            Object *nptxfd; // [16:31] Nonperiodic TxFIFO depth  
          } otg_hs_gnptxfsiz_host; 
          
          // OTG_HS_TX0FSIZ_Peripheral (Endpoint 0 transmit FIFO size (peripheral mode)) bitfields.
          struct { 
            Object *tx0fsa; // [0:15] Endpoint 0 transmit RAM start address 
            Object *tx0fd; // [16:31] Endpoint 0 TxFIFO depth  
          } otg_hs_tx0fsiz_peripheral; 
          
          // OTG_HS_GNPTXSTS (OTG_HS nonperiodic transmit FIFO/queue status register) bitfields.
          struct { 
            Object *nptxfsav; // [0:15] Nonperiodic TxFIFO space available 
            Object *nptqxsav; // [16:23] Nonperiodic transmit request queue space available 
            Object *nptxqtop; // [24:30] Top of the nonperiodic transmit request queue  
          } otg_hs_gnptxsts; 
          
          // OTG_HS_GCCFG (OTG_HS general core configuration register) bitfields.
          struct { 
            Object *pwrdwn; // [16:16] Power down 
            Object *i2cpaden; // [17:17] Enable I2C bus connection for the external I2C PHY interface 
            Object *vbusasen; // [18:18] Enable the VBUS sensing device 
            Object *vbusbsen; // [19:19] Enable the VBUS sensing device 
            Object *sofouten; // [20:20] SOF output enable 
            Object *novbussens; // [21:21] VBUS sensing disable option  
          } otg_hs_gccfg; 
          
          // OTG_HS_CID (OTG_HS core ID register) bitfields.
          struct { 
            Object *product_id; // [0:31] Product ID field  
          } otg_hs_cid; 
          
          // OTG_HS_HPTXFSIZ (OTG_HS Host periodic transmit FIFO size register) bitfields.
          struct { 
            Object *ptxsa; // [0:15] Host periodic TxFIFO start address 
            Object *ptxfd; // [16:31] Host periodic TxFIFO depth  
          } otg_hs_hptxfsiz; 
          
          // OTG_HS_DIEPTXF1 (OTG_HS device IN endpoint transmit FIFO size register) bitfields.
          struct { 
            Object *ineptxsa; // [0:15] IN endpoint FIFOx transmit RAM start address 
            Object *ineptxfd; // [16:31] IN endpoint TxFIFO depth  
          } otg_hs_dieptxf1; 
          
          // OTG_HS_DIEPTXF2 (OTG_HS device IN endpoint transmit FIFO size register) bitfields.
          struct { 
            Object *ineptxsa; // [0:15] IN endpoint FIFOx transmit RAM start address 
            Object *ineptxfd; // [16:31] IN endpoint TxFIFO depth  
          } otg_hs_dieptxf2; 
          
          // OTG_HS_DIEPTXF3 (OTG_HS device IN endpoint transmit FIFO size register) bitfields.
          struct { 
            Object *ineptxsa; // [0:15] IN endpoint FIFOx transmit RAM start address 
            Object *ineptxfd; // [16:31] IN endpoint TxFIFO depth  
          } otg_hs_dieptxf3; 
          
          // OTG_HS_DIEPTXF4 (OTG_HS device IN endpoint transmit FIFO size register) bitfields.
          struct { 
            Object *ineptxsa; // [0:15] IN endpoint FIFOx transmit RAM start address 
            Object *ineptxfd; // [16:31] IN endpoint TxFIFO depth  
          } otg_hs_dieptxf4; 
          
          // OTG_HS_DIEPTXF5 (OTG_HS device IN endpoint transmit FIFO size register) bitfields.
          struct { 
            Object *ineptxsa; // [0:15] IN endpoint FIFOx transmit RAM start address 
            Object *ineptxfd; // [16:31] IN endpoint TxFIFO depth  
          } otg_hs_dieptxf5; 
          
          // OTG_HS_DIEPTXF6 (OTG_HS device IN endpoint transmit FIFO size register) bitfields.
          struct { 
            Object *ineptxsa; // [0:15] IN endpoint FIFOx transmit RAM start address 
            Object *ineptxfd; // [16:31] IN endpoint TxFIFO depth  
          } otg_hs_dieptxf6; 
          
          // OTG_HS_DIEPTXF7 (OTG_HS device IN endpoint transmit FIFO size register) bitfields.
          struct { 
            Object *ineptxsa; // [0:15] IN endpoint FIFOx transmit RAM start address 
            Object *ineptxfd; // [16:31] IN endpoint TxFIFO depth  
          } otg_hs_dieptxf7; 
          
          // OTG_HS_GRXSTSR_Peripheral (OTG_HS Receive status debug read register (peripheral mode mode)) bitfields.
          struct { 
            Object *epnum; // [0:3] Endpoint number 
            Object *bcnt; // [4:14] Byte count 
            Object *dpid; // [15:16] Data PID 
            Object *pktsts; // [17:20] Packet status 
            Object *frmnum; // [21:24] Frame number  
          } otg_hs_grxstsr_peripheral; 
          
          // OTG_HS_GRXSTSP_Peripheral (OTG_HS status read and pop register (peripheral mode)) bitfields.
          struct { 
            Object *epnum; // [0:3] Endpoint number 
            Object *bcnt; // [4:14] Byte count 
            Object *dpid; // [15:16] Data PID 
            Object *pktsts; // [17:20] Packet status 
            Object *frmnum; // [21:24] Frame number  
          } otg_hs_grxstsp_peripheral; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32OTG_HS_GLOBALState;

// ----------------------------------------------------------------------------

#endif /* STM32_OTG_HS_GLOBAL_H_ */
