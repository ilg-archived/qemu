/*
 * STM32 - DCMI (Digital camera interface) emulation.
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

#ifndef STM32_DCMI_H_
#define STM32_DCMI_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_DCMI DEVICE_PATH_STM32 "DCMI"



// ----------------------------------------------------------------------------

#define TYPE_STM32_DCMI TYPE_STM32_PREFIX "dcmi" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_DCMI_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32DCMIParentClass;
typedef PeripheralState STM32DCMIParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_DCMI_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DCMIClass, (obj), TYPE_STM32_DCMI)
#define STM32_DCMI_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32DCMIClass, (klass), TYPE_STM32_DCMI)

typedef struct {
    // private: 
    STM32DCMIParentClass parent_class;
    // public: 

    // None, so far.
} STM32DCMIClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_DCMI_STATE(obj) \
    OBJECT_CHECK(STM32DCMIState, (obj), TYPE_STM32_DCMI)

typedef struct {
    // private:
    STM32DCMIParentState parent_obj;
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
        // F4 DCMI (Digital camera interface) registers.
        struct { 
          Object *cr; // 0x0 (Control register 1) 
          Object *sr; // 0x4 (Status register) 
          Object *ris; // 0x8 (Raw interrupt status register) 
          Object *ier; // 0xC (Interrupt enable register) 
          Object *mis; // 0x10 (Masked interrupt status register) 
          Object *icr; // 0x14 (Interrupt clear register) 
          Object *escr; // 0x18 (Embedded synchronization code register) 
          Object *esur; // 0x1C (Embedded synchronization unmask register) 
          Object *cwstrt; // 0x20 (Crop window start) 
          Object *cwsize; // 0x24 (Crop window size) 
          Object *dr; // 0x28 (Data register) 
        } reg;

        struct { 
          
          // CR (Control register 1) bitfields.
          struct { 
            Object *capture; // [0:0] Capture enable 
            Object *cm; // [1:1] Capture mode 
            Object *crop; // [2:2] Crop feature 
            Object *jpeg; // [3:3] JPEG format 
            Object *ess; // [4:4] Embedded synchronization select 
            Object *pckpol; // [5:5] Pixel clock polarity 
            Object *hspol; // [6:6] Horizontal synchronization polarity 
            Object *vspol; // [7:7] Vertical synchronization polarity 
            Object *fcrc; // [8:9] Frame capture rate control 
            Object *edm; // [10:11] Extended data mode 
            Object *enable; // [14:14] DCMI enable  
          } cr; 
          
          // SR (Status register) bitfields.
          struct { 
            Object *hsync; // [0:0] HSYNC 
            Object *vsync; // [1:1] VSYNC 
            Object *fne; // [2:2] FIFO not empty  
          } sr; 
          
          // RIS (Raw interrupt status register) bitfields.
          struct { 
            Object *frame_ris; // [0:0] Capture complete raw interrupt status 
            Object *ovr_ris; // [1:1] Overrun raw interrupt status 
            Object *err_ris; // [2:2] Synchronization error raw interrupt status 
            Object *vsync_ris; // [3:3] VSYNC raw interrupt status 
            Object *line_ris; // [4:4] Line raw interrupt status  
          } ris; 
          
          // IER (Interrupt enable register) bitfields.
          struct { 
            Object *frame_ie; // [0:0] Capture complete interrupt enable 
            Object *ovr_ie; // [1:1] Overrun interrupt enable 
            Object *err_ie; // [2:2] Synchronization error interrupt enable 
            Object *vsync_ie; // [3:3] VSYNC interrupt enable 
            Object *line_ie; // [4:4] Line interrupt enable  
          } ier; 
          
          // MIS (Masked interrupt status register) bitfields.
          struct { 
            Object *frame_mis; // [0:0] Capture complete masked interrupt status 
            Object *ovr_mis; // [1:1] Overrun masked interrupt status 
            Object *err_mis; // [2:2] Synchronization error masked interrupt status 
            Object *vsync_mis; // [3:3] VSYNC masked interrupt status 
            Object *line_mis; // [4:4] Line masked interrupt status  
          } mis; 
          
          // ICR (Interrupt clear register) bitfields.
          struct { 
            Object *frame_isc; // [0:0] Capture complete interrupt status clear 
            Object *ovr_isc; // [1:1] Overrun interrupt status clear 
            Object *err_isc; // [2:2] Synchronization error interrupt status clear 
            Object *vsync_isc; // [3:3] Vertical synch interrupt status clear 
            Object *line_isc; // [4:4] Line interrupt status clear  
          } icr; 
          
          // ESCR (Embedded synchronization code register) bitfields.
          struct { 
            Object *fsc; // [0:7] Frame start delimiter code 
            Object *lsc; // [8:15] Line start delimiter code 
            Object *lec; // [16:23] Line end delimiter code 
            Object *fec; // [24:31] Frame end delimiter code  
          } escr; 
          
          // ESUR (Embedded synchronization unmask register) bitfields.
          struct { 
            Object *fsu; // [0:7] Frame start delimiter unmask 
            Object *lsu; // [8:15] Line start delimiter unmask 
            Object *leu; // [16:23] Line end delimiter unmask 
            Object *feu; // [24:31] Frame end delimiter unmask  
          } esur; 
          
          // CWSTRT (Crop window start) bitfields.
          struct { 
            Object *hoffcnt; // [0:13] Horizontal offset count 
            Object *vst; // [16:28] Vertical start line count  
          } cwstrt; 
          
          // CWSIZE (Crop window size) bitfields.
          struct { 
            Object *capcnt; // [0:13] Capture count 
            Object *vline; // [16:29] Vertical line count  
          } cwsize; 
          
          // DR (Data register) bitfields.
          struct { 
            Object *byte0; // [0:7] Data byte 0 
            Object *byte1; // [8:15] Data byte 1 
            Object *byte2; // [16:23] Data byte 2 
            Object *byte3; // [24:31] Data byte 3  
          } dr; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32DCMIState;

// ----------------------------------------------------------------------------

#endif /* STM32_DCMI_H_ */
