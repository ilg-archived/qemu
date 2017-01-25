/*
 * STM32 - USB_OTG_GLOBAL (USB on the go full speed) emulation.
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

#ifndef STM32_USB_OTG_GLOBAL_H_
#define STM32_USB_OTG_GLOBAL_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_USB_OTG_GLOBAL DEVICE_PATH_STM32 "USB_OTG_GLOBAL"



// ----------------------------------------------------------------------------

#define TYPE_STM32_USB_OTG_GLOBAL TYPE_STM32_PREFIX "usb_otg_global" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_USB_OTG_GLOBAL_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32USB_OTG_GLOBALParentClass;
typedef PeripheralState STM32USB_OTG_GLOBALParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_USB_OTG_GLOBAL_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32USB_OTG_GLOBALClass, (obj), TYPE_STM32_USB_OTG_GLOBAL)
#define STM32_USB_OTG_GLOBAL_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32USB_OTG_GLOBALClass, (klass), TYPE_STM32_USB_OTG_GLOBAL)

typedef struct {
    // private: 
    STM32USB_OTG_GLOBALParentClass parent_class;
    // public: 

    // None, so far.
} STM32USB_OTG_GLOBALClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_USB_OTG_GLOBAL_STATE(obj) \
    OBJECT_CHECK(STM32USB_OTG_GLOBALState, (obj), TYPE_STM32_USB_OTG_GLOBAL)

typedef struct {
    // private:
    STM32USB_OTG_GLOBALParentState parent_obj;
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
        // F1 USB_OTG_GLOBAL (USB on the go full speed) registers.
        struct { 
          Object *fs_gotgctl; // 0x0 (OTG_FS control and status register (OTG_FS_GOTGCTL)) 
          Object *fs_gotgint; // 0x4 (OTG_FS interrupt register (OTG_FS_GOTGINT)) 
          Object *fs_gahbcfg; // 0x8 (OTG_FS AHB configuration register (OTG_FS_GAHBCFG)) 
          Object *fs_gusbcfg; // 0xC (OTG_FS USB configuration register (OTG_FS_GUSBCFG)) 
          Object *fs_grstctl; // 0x10 (OTG_FS reset register (OTG_FS_GRSTCTL)) 
          Object *fs_gintsts; // 0x14 (OTG_FS core interrupt register (OTG_FS_GINTSTS)) 
          Object *fs_gintmsk; // 0x18 (OTG_FS interrupt mask register (OTG_FS_GINTMSK)) 
          Object *fs_grxstsr_device; // 0x1C (OTG_FS Receive status debug read(Device mode)) 
          Object *fs_grxstsr_host; // 0x1C (OTG_FS Receive status debug read(Host mode)) 
          Object *fs_grxfsiz; // 0x24 (OTG_FS Receive FIFO size register (OTG_FS_GRXFSIZ)) 
          Object *fs_gnptxfsiz_device; // 0x28 (OTG_FS non-periodic transmit FIFO size register (Device mode)) 
          Object *fs_gnptxfsiz_host; // 0x28 (OTG_FS non-periodic transmit FIFO size register (Host mode)) 
          Object *fs_gnptxsts; // 0x2C (OTG_FS non-periodic transmit FIFO/queue status register (OTG_FS_GNPTXSTS)) 
          Object *fs_gccfg; // 0x38 (OTG_FS general core configuration register (OTG_FS_GCCFG)) 
          Object *fs_cid; // 0x3C (Core ID register) 
          Object *fs_hptxfsiz; // 0x100 (OTG_FS Host periodic transmit FIFO size register (OTG_FS_HPTXFSIZ)) 
          Object *fs_dieptxf1; // 0x104 (OTG_FS device IN endpoint transmit FIFO size register (OTG_FS_DIEPTXF2)) 
          Object *fs_dieptxf2; // 0x108 (OTG_FS device IN endpoint transmit FIFO size register (OTG_FS_DIEPTXF3)) 
          Object *fs_dieptxf3; // 0x10C (OTG_FS device IN endpoint transmit FIFO size register (OTG_FS_DIEPTXF4)) 
        } reg;

        struct { 
          
          // FS_GOTGCTL (OTG_FS control and status register (OTG_FS_GOTGCTL)) bitfields.
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
          } fs_gotgctl; 
          
          // FS_GOTGINT (OTG_FS interrupt register (OTG_FS_GOTGINT)) bitfields.
          struct { 
            Object *sedet; // [2:2] Session end detected 
            Object *srsschg; // [8:8] Session request success status change 
            Object *hnsschg; // [9:9] Host negotiation success status change 
            Object *hngdet; // [17:17] Host negotiation detected 
            Object *adtochg; // [18:18] A-device timeout change 
            Object *dbcdne; // [19:19] Debounce done  
          } fs_gotgint; 
          
          // FS_GAHBCFG (OTG_FS AHB configuration register (OTG_FS_GAHBCFG)) bitfields.
          struct { 
            Object *gint; // [0:0] Global interrupt mask 
            Object *txfelvl; // [7:7] TxFIFO empty level 
            Object *ptxfelvl; // [8:8] Periodic TxFIFO empty level  
          } fs_gahbcfg; 
          
          // FS_GUSBCFG (OTG_FS USB configuration register (OTG_FS_GUSBCFG)) bitfields.
          struct { 
            Object *tocal; // [0:2] FS timeout calibration 
            Object *physel; // [7:7] Full Speed serial transceiver select 
            Object *srpcap; // [8:8] SRP-capable 
            Object *hnpcap; // [9:9] HNP-capable 
            Object *trdt; // [10:13] USB turnaround time 
            Object *fhmod; // [29:29] Force host mode 
            Object *fdmod; // [30:30] Force device mode 
            Object *ctxpkt; // [31:31] Corrupt Tx packet  
          } fs_gusbcfg; 
          
          // FS_GRSTCTL (OTG_FS reset register (OTG_FS_GRSTCTL)) bitfields.
          struct { 
            Object *csrst; // [0:0] Core soft reset 
            Object *hsrst; // [1:1] HCLK soft reset 
            Object *fcrst; // [2:2] Host frame counter reset 
            Object *rxfflsh; // [4:4] RxFIFO flush 
            Object *txfflsh; // [5:5] TxFIFO flush 
            Object *txfnum; // [6:10] TxFIFO number 
            Object *ahbidl; // [31:31] AHB master idle  
          } fs_grstctl; 
          
          // FS_GINTSTS (OTG_FS core interrupt register (OTG_FS_GINTSTS)) bitfields.
          struct { 
            Object *cmod; // [0:0] Current mode of operation 
            Object *mmis; // [1:1] Mode mismatch interrupt 
            Object *otgint; // [2:2] OTG interrupt 
            Object *sof; // [3:3] Start of frame 
            Object *rxflvl; // [4:4] RxFIFO non-empty 
            Object *nptxfe; // [5:5] Non-periodic TxFIFO empty 
            Object *ginakeff; // [6:6] Global IN non-periodic NAK effective 
            Object *goutnakeff; // [7:7] Global OUT NAK effective 
            Object *esusp; // [10:10] Early suspend 
            Object *usbsusp; // [11:11] USB suspend 
            Object *usbrst; // [12:12] USB reset 
            Object *enumdne; // [13:13] Enumeration done 
            Object *isoodrp; // [14:14] Isochronous OUT packet dropped interrupt 
            Object *eopf; // [15:15] End of periodic frame interrupt 
            Object *iepint; // [18:18] IN endpoint interrupt 
            Object *oepint; // [19:19] OUT endpoint interrupt 
            Object *iisoixfr; // [20:20] Incomplete isochronous IN transfer 
            Object *ipxfr_incompisoout; // [21:21] Incomplete periodic transfer(Host mode)/Incomplete isochronous OUT transfer(Device mode) 
            Object *hprtint; // [24:24] Host port interrupt 
            Object *hcint; // [25:25] Host channels interrupt 
            Object *ptxfe; // [26:26] Periodic TxFIFO empty 
            Object *cidschg; // [28:28] Connector ID status change 
            Object *discint; // [29:29] Disconnect detected interrupt 
            Object *srqint; // [30:30] Session request/new session detected interrupt 
            Object *wkupint; // [31:31] Resume/remote wakeup detected interrupt  
          } fs_gintsts; 
          
          // FS_GINTMSK (OTG_FS interrupt mask register (OTG_FS_GINTMSK)) bitfields.
          struct { 
            Object *mmism; // [1:1] Mode mismatch interrupt mask 
            Object *otgint; // [2:2] OTG interrupt mask 
            Object *sofm; // [3:3] Start of frame mask 
            Object *rxflvlm; // [4:4] Receive FIFO non-empty mask 
            Object *nptxfem; // [5:5] Non-periodic TxFIFO empty mask 
            Object *ginakeffm; // [6:6] Global non-periodic IN NAK effective mask 
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
            Object *ipxfrm_iisooxfrm; // [21:21] Incomplete periodic transfer mask(Host mode)/Incomplete isochronous OUT transfer mask(Device mode) 
            Object *prtim; // [24:24] Host port interrupt mask 
            Object *hcim; // [25:25] Host channels interrupt mask 
            Object *ptxfem; // [26:26] Periodic TxFIFO empty mask 
            Object *cidschgm; // [28:28] Connector ID status change mask 
            Object *discint; // [29:29] Disconnect detected interrupt mask 
            Object *srqim; // [30:30] Session request/new session detected interrupt mask 
            Object *wuim; // [31:31] Resume/remote wakeup detected interrupt mask  
          } fs_gintmsk; 
          
          // FS_GRXSTSR_Device (OTG_FS Receive status debug read(Device mode)) bitfields.
          struct { 
            Object *epnum; // [0:3] Endpoint number 
            Object *bcnt; // [4:14] Byte count 
            Object *dpid; // [15:16] Data PID 
            Object *pktsts; // [17:20] Packet status 
            Object *frmnum; // [21:24] Frame number  
          } fs_grxstsr_device; 
          
          // FS_GRXSTSR_Host (OTG_FS Receive status debug read(Host mode)) bitfields.
          struct { 
            Object *epnum; // [0:3] Endpoint number 
            Object *bcnt; // [4:14] Byte count 
            Object *dpid; // [15:16] Data PID 
            Object *pktsts; // [17:20] Packet status 
            Object *frmnum; // [21:24] Frame number  
          } fs_grxstsr_host; 
          
          // FS_GRXFSIZ (OTG_FS Receive FIFO size register (OTG_FS_GRXFSIZ)) bitfields.
          struct { 
            Object *rxfd; // [0:15] RxFIFO depth  
          } fs_grxfsiz; 
          
          // FS_GNPTXFSIZ_Device (OTG_FS non-periodic transmit FIFO size register (Device mode)) bitfields.
          struct { 
            Object *tx0fsa; // [0:15] Endpoint 0 transmit RAM start address 
            Object *tx0fd; // [16:31] Endpoint 0 TxFIFO depth  
          } fs_gnptxfsiz_device; 
          
          // FS_GNPTXFSIZ_Host (OTG_FS non-periodic transmit FIFO size register (Host mode)) bitfields.
          struct { 
            Object *nptxfsa; // [0:15] Non-periodic transmit RAM start address 
            Object *nptxfd; // [16:31] Non-periodic TxFIFO depth  
          } fs_gnptxfsiz_host; 
          
          // FS_GNPTXSTS (OTG_FS non-periodic transmit FIFO/queue status register (OTG_FS_GNPTXSTS)) bitfields.
          struct { 
            Object *nptxfsav; // [0:15] Non-periodic TxFIFO space available 
            Object *nptqxsav; // [16:23] Non-periodic transmit request queue space available 
            Object *nptxqtop; // [24:30] Top of the non-periodic transmit request queue  
          } fs_gnptxsts; 
          
          // FS_GCCFG (OTG_FS general core configuration register (OTG_FS_GCCFG)) bitfields.
          struct { 
            Object *pwrdwn; // [16:16] Power down 
            Object *vbusasen; // [18:18] Enable the VBUS sensing device 
            Object *vbusbsen; // [19:19] Enable the VBUS sensing device 
            Object *sofouten; // [20:20] SOF output enable  
          } fs_gccfg; 
          
          // FS_CID (Core ID register) bitfields.
          struct { 
            Object *product_id; // [0:31] Product ID field  
          } fs_cid; 
          
          // FS_HPTXFSIZ (OTG_FS Host periodic transmit FIFO size register (OTG_FS_HPTXFSIZ)) bitfields.
          struct { 
            Object *ptxsa; // [0:15] Host periodic TxFIFO start address 
            Object *ptxfsiz; // [16:31] Host periodic TxFIFO depth  
          } fs_hptxfsiz; 
          
          // FS_DIEPTXF1 (OTG_FS device IN endpoint transmit FIFO size register (OTG_FS_DIEPTXF2)) bitfields.
          struct { 
            Object *ineptxsa; // [0:15] IN endpoint FIFO2 transmit RAM start address 
            Object *ineptxfd; // [16:31] IN endpoint TxFIFO depth  
          } fs_dieptxf1; 
          
          // FS_DIEPTXF2 (OTG_FS device IN endpoint transmit FIFO size register (OTG_FS_DIEPTXF3)) bitfields.
          struct { 
            Object *ineptxsa; // [0:15] IN endpoint FIFO3 transmit RAM start address 
            Object *ineptxfd; // [16:31] IN endpoint TxFIFO depth  
          } fs_dieptxf2; 
          
          // FS_DIEPTXF3 (OTG_FS device IN endpoint transmit FIFO size register (OTG_FS_DIEPTXF4)) bitfields.
          struct { 
            Object *ineptxsa; // [0:15] IN endpoint FIFO4 transmit RAM start address 
            Object *ineptxfd; // [16:31] IN endpoint TxFIFO depth  
          } fs_dieptxf3; 
        } fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32USB_OTG_GLOBALState;

// ----------------------------------------------------------------------------

#endif /* STM32_USB_OTG_GLOBAL_H_ */
