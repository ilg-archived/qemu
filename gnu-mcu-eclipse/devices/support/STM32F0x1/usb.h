/*
 * STM32 - USB (Universal serial bus full-speed device interface) emulation.
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

#ifndef STM32_USB_H_
#define STM32_USB_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_USB DEVICE_PATH_STM32 "USB"



// ----------------------------------------------------------------------------

#define TYPE_STM32_USB TYPE_STM32_PREFIX "usb" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_USB_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32USBParentClass;
typedef PeripheralState STM32USBParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_USB_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32USBClass, (obj), TYPE_STM32_USB)
#define STM32_USB_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32USBClass, (klass), TYPE_STM32_USB)

typedef struct {
    // private: 
    STM32USBParentClass parent_class;
    // public: 

    // None, so far.
} STM32USBClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_USB_STATE(obj) \
    OBJECT_CHECK(STM32USBState, (obj), TYPE_STM32_USB)

typedef struct {
    // private:
    STM32USBParentState parent_obj;
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
        // F0 USB (Universal serial bus full-speed device interface) registers.
        struct { 
          Object *ep0r; // 0x0 (Endpoint 0 register) 
          Object *ep1r; // 0x4 (Endpoint 1 register) 
          Object *ep2r; // 0x8 (Endpoint 2 register) 
          Object *ep3r; // 0xC (Endpoint 3 register) 
          Object *ep4r; // 0x10 (Endpoint 4 register) 
          Object *ep5r; // 0x14 (Endpoint 5 register) 
          Object *ep6r; // 0x18 (Endpoint 6 register) 
          Object *ep7r; // 0x1C (Endpoint 7 register) 
          Object *cntr; // 0x40 (Control register) 
          Object *istr; // 0x44 (Interrupt status register) 
          Object *fnr; // 0x48 (Frame number register) 
          Object *daddr; // 0x4C (Device address) 
          Object *btable; // 0x50 (Buffer table address) 
          Object *lpmcsr; // 0x54 (LPM control and status register) 
          Object *bcdr; // 0x58 (Battery charging detector) 
        } reg;

        struct { 
          
          // EP0R (Endpoint 0 register) bitfields.
          struct { 
            Object *ea; // [0:3] Endpoint address 
            Object *stat_tx; // [4:5] Status bits, for transmission transfers 
            Object *dtog_tx; // [6:6] Data Toggle, for transmission transfers 
            Object *ctr_tx; // [7:7] Correct Transfer for transmission 
            Object *ep_kind; // [8:8] Endpoint kind 
            Object *ep_type; // [9:10] Endpoint type 
            Object *setup; // [11:11] Setup transaction completed 
            Object *stat_rx; // [12:13] Status bits, for reception transfers 
            Object *dtog_rx; // [14:14] Data Toggle, for reception transfers 
            Object *ctr_rx; // [15:15] Correct transfer for reception  
          } ep0r; 
          
          // EP1R (Endpoint 1 register) bitfields.
          struct { 
            Object *ea; // [0:3] Endpoint address 
            Object *stat_tx; // [4:5] Status bits, for transmission transfers 
            Object *dtog_tx; // [6:6] Data Toggle, for transmission transfers 
            Object *ctr_tx; // [7:7] Correct Transfer for transmission 
            Object *ep_kind; // [8:8] Endpoint kind 
            Object *ep_type; // [9:10] Endpoint type 
            Object *setup; // [11:11] Setup transaction completed 
            Object *stat_rx; // [12:13] Status bits, for reception transfers 
            Object *dtog_rx; // [14:14] Data Toggle, for reception transfers 
            Object *ctr_rx; // [15:15] Correct transfer for reception  
          } ep1r; 
          
          // EP2R (Endpoint 2 register) bitfields.
          struct { 
            Object *ea; // [0:3] Endpoint address 
            Object *stat_tx; // [4:5] Status bits, for transmission transfers 
            Object *dtog_tx; // [6:6] Data Toggle, for transmission transfers 
            Object *ctr_tx; // [7:7] Correct Transfer for transmission 
            Object *ep_kind; // [8:8] Endpoint kind 
            Object *ep_type; // [9:10] Endpoint type 
            Object *setup; // [11:11] Setup transaction completed 
            Object *stat_rx; // [12:13] Status bits, for reception transfers 
            Object *dtog_rx; // [14:14] Data Toggle, for reception transfers 
            Object *ctr_rx; // [15:15] Correct transfer for reception  
          } ep2r; 
          
          // EP3R (Endpoint 3 register) bitfields.
          struct { 
            Object *ea; // [0:3] Endpoint address 
            Object *stat_tx; // [4:5] Status bits, for transmission transfers 
            Object *dtog_tx; // [6:6] Data Toggle, for transmission transfers 
            Object *ctr_tx; // [7:7] Correct Transfer for transmission 
            Object *ep_kind; // [8:8] Endpoint kind 
            Object *ep_type; // [9:10] Endpoint type 
            Object *setup; // [11:11] Setup transaction completed 
            Object *stat_rx; // [12:13] Status bits, for reception transfers 
            Object *dtog_rx; // [14:14] Data Toggle, for reception transfers 
            Object *ctr_rx; // [15:15] Correct transfer for reception  
          } ep3r; 
          
          // EP4R (Endpoint 4 register) bitfields.
          struct { 
            Object *ea; // [0:3] Endpoint address 
            Object *stat_tx; // [4:5] Status bits, for transmission transfers 
            Object *dtog_tx; // [6:6] Data Toggle, for transmission transfers 
            Object *ctr_tx; // [7:7] Correct Transfer for transmission 
            Object *ep_kind; // [8:8] Endpoint kind 
            Object *ep_type; // [9:10] Endpoint type 
            Object *setup; // [11:11] Setup transaction completed 
            Object *stat_rx; // [12:13] Status bits, for reception transfers 
            Object *dtog_rx; // [14:14] Data Toggle, for reception transfers 
            Object *ctr_rx; // [15:15] Correct transfer for reception  
          } ep4r; 
          
          // EP5R (Endpoint 5 register) bitfields.
          struct { 
            Object *ea; // [0:3] Endpoint address 
            Object *stat_tx; // [4:5] Status bits, for transmission transfers 
            Object *dtog_tx; // [6:6] Data Toggle, for transmission transfers 
            Object *ctr_tx; // [7:7] Correct Transfer for transmission 
            Object *ep_kind; // [8:8] Endpoint kind 
            Object *ep_type; // [9:10] Endpoint type 
            Object *setup; // [11:11] Setup transaction completed 
            Object *stat_rx; // [12:13] Status bits, for reception transfers 
            Object *dtog_rx; // [14:14] Data Toggle, for reception transfers 
            Object *ctr_rx; // [15:15] Correct transfer for reception  
          } ep5r; 
          
          // EP6R (Endpoint 6 register) bitfields.
          struct { 
            Object *ea; // [0:3] Endpoint address 
            Object *stat_tx; // [4:5] Status bits, for transmission transfers 
            Object *dtog_tx; // [6:6] Data Toggle, for transmission transfers 
            Object *ctr_tx; // [7:7] Correct Transfer for transmission 
            Object *ep_kind; // [8:8] Endpoint kind 
            Object *ep_type; // [9:10] Endpoint type 
            Object *setup; // [11:11] Setup transaction completed 
            Object *stat_rx; // [12:13] Status bits, for reception transfers 
            Object *dtog_rx; // [14:14] Data Toggle, for reception transfers 
            Object *ctr_rx; // [15:15] Correct transfer for reception  
          } ep6r; 
          
          // EP7R (Endpoint 7 register) bitfields.
          struct { 
            Object *ea; // [0:3] Endpoint address 
            Object *stat_tx; // [4:5] Status bits, for transmission transfers 
            Object *dtog_tx; // [6:6] Data Toggle, for transmission transfers 
            Object *ctr_tx; // [7:7] Correct Transfer for transmission 
            Object *ep_kind; // [8:8] Endpoint kind 
            Object *ep_type; // [9:10] Endpoint type 
            Object *setup; // [11:11] Setup transaction completed 
            Object *stat_rx; // [12:13] Status bits, for reception transfers 
            Object *dtog_rx; // [14:14] Data Toggle, for reception transfers 
            Object *ctr_rx; // [15:15] Correct transfer for reception  
          } ep7r; 
          
          // CNTR (Control register) bitfields.
          struct { 
            Object *fres; // [0:0] Force USB Reset 
            Object *pdwn; // [1:1] Power down 
            Object *lpmode; // [2:2] Low-power mode 
            Object *fsusp; // [3:3] Force suspend 
            Object *resume; // [4:4] Resume request 
            Object *l1resume; // [5:5] LPM L1 Resume request 
            Object *l1reqm; // [7:7] LPM L1 state request interrupt mask 
            Object *esofm; // [8:8] Expected start of frame interrupt mask 
            Object *sofm; // [9:9] Start of frame interrupt mask 
            Object *resetm; // [10:10] USB reset interrupt mask 
            Object *suspm; // [11:11] Suspend mode interrupt mask 
            Object *wkupm; // [12:12] Wakeup interrupt mask 
            Object *errm; // [13:13] Error interrupt mask 
            Object *pmaovrm; // [14:14] Packet memory area over / underrun interrupt mask 
            Object *ctrm; // [15:15] Correct transfer interrupt mask  
          } cntr; 
          
          // ISTR (Interrupt status register) bitfields.
          struct { 
            Object *ep_id; // [0:3] Endpoint Identifier 
            Object *dir; // [4:4] Direction of transaction 
            Object *l1req; // [7:7] LPM L1 state request 
            Object *esof; // [8:8] Expected start frame 
            Object *sof; // [9:9] Start of frame 
            Object *reset; // [10:10] Reset request 
            Object *susp; // [11:11] Suspend mode request 
            Object *wkup; // [12:12] Wakeup 
            Object *err; // [13:13] Error 
            Object *pmaovr; // [14:14] Packet memory area over / underrun 
            Object *ctr; // [15:15] Correct transfer  
          } istr; 
          
          // FNR (Frame number register) bitfields.
          struct { 
            Object *fn; // [0:10] Frame number 
            Object *lsof; // [11:12] Lost SOF 
            Object *lck; // [13:13] Locked 
            Object *rxdm; // [14:14] Receive data - line status 
            Object *rxdp; // [15:15] Receive data + line status  
          } fnr; 
          
          // DADDR (Device address) bitfields.
          struct { 
            Object *add; // [0:6] Device address 
            Object *ef; // [7:7] Enable function  
          } daddr; 
          
          // BTABLE (Buffer table address) bitfields.
          struct { 
            Object *btable; // [3:15] Buffer table  
          } btable; 
          
          // LPMCSR (LPM control and status register) bitfields.
          struct { 
            Object *lpmen; // [0:0] LPM support enable 
            Object *lpmack; // [1:1] LPM Token acknowledge enable 
            Object *remwake; // [3:3] BRemoteWake value 
            Object *besl; // [4:7] BESL value  
          } lpmcsr; 
          
          // BCDR (Battery charging detector) bitfields.
          struct { 
            Object *bcden; // [0:0] Battery charging detector (BCD) enable 
            Object *dcden; // [1:1] Data contact detection (DCD) mode enable 
            Object *pden; // [2:2] Primary detection (PD) mode enable 
            Object *sden; // [3:3] Secondary detection (SD) mode enable 
            Object *dcdet; // [4:4] Data contact detection (DCD) status 
            Object *pdet; // [5:5] Primary detection (PD) status 
            Object *sdet; // [6:6] Secondary detection (SD) status 
            Object *ps2det; // [7:7] DM pull-up detection status 
            Object *dppu; // [15:15] DP pull-up control  
          } bcdr; 
        } fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32USBState;

// ----------------------------------------------------------------------------

#endif /* STM32_USB_H_ */
