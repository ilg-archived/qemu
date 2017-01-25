/*
 * STM32 - DMA2D (DMA2D controller) emulation.
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

#ifndef STM32_DMA2D_H_
#define STM32_DMA2D_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_DMA2D DEVICE_PATH_STM32 "DMA2D"



// ----------------------------------------------------------------------------

#define TYPE_STM32_DMA2D TYPE_STM32_PREFIX "dma2d" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_DMA2D_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32DMA2DParentClass;
typedef PeripheralState STM32DMA2DParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_DMA2D_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DMA2DClass, (obj), TYPE_STM32_DMA2D)
#define STM32_DMA2D_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32DMA2DClass, (klass), TYPE_STM32_DMA2D)

typedef struct {
    // private: 
    STM32DMA2DParentClass parent_class;
    // public: 

    // None, so far.
} STM32DMA2DClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_DMA2D_STATE(obj) \
    OBJECT_CHECK(STM32DMA2DState, (obj), TYPE_STM32_DMA2D)

typedef struct {
    // private:
    STM32DMA2DParentState parent_obj;
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
        // F4 DMA2D (DMA2D controller) registers.
        struct { 
          Object *cr; // 0x0 (Control register) 
          Object *isr; // 0x4 (Interrupt Status Register) 
          Object *ifcr; // 0x8 (Interrupt flag clear register) 
          Object *fgmar; // 0xC (Foreground memory address register) 
          Object *fgor; // 0x10 (Foreground offset register) 
          Object *bgmar; // 0x14 (Background memory address register) 
          Object *bgor; // 0x18 (Background offset register) 
          Object *fgpfccr; // 0x1C (Foreground PFC control register) 
          Object *fgcolr; // 0x20 (Foreground color register) 
          Object *bgpfccr; // 0x24 (Background PFC control register) 
          Object *bgcolr; // 0x28 (Background color register) 
          Object *fgcmar; // 0x2C (Foreground CLUT memory address register) 
          Object *bgcmar; // 0x30 (Background CLUT memory address register) 
          Object *opfccr; // 0x34 (Output PFC control register) 
          Object *ocolr; // 0x38 (Output color register) 
          Object *omar; // 0x3C (Output memory address register) 
          Object *oor; // 0x40 (Output offset register) 
          Object *nlr; // 0x44 (Number of line register) 
          Object *lwr; // 0x48 (Line watermark register) 
          Object *amtcr; // 0x4C (AHB master timer configuration register) 
          Object *fgclut; // 0x400 (FGCLUT) 
          Object *bgclut; // 0x800 (BGCLUT) 
        } reg;

        struct { 
          
          // CR (Control register) bitfields.
          struct { 
            Object *start; // [0:0] Start 
            Object *susp; // [1:1] Suspend 
            Object *abort; // [2:2] Abort 
            Object *teie; // [8:8] Transfer error interrupt enable 
            Object *tcie; // [9:9] Transfer complete interrupt enable 
            Object *twie; // [10:10] Transfer watermark interrupt enable 
            Object *caeie; // [11:11] CLUT access error interrupt enable 
            Object *ctcie; // [12:12] CLUT transfer complete interrupt enable 
            Object *ceie; // [13:13] Configuration Error Interrupt Enable 
            Object *mode; // [16:17] DMA2D mode  
          } cr; 
          
          // ISR (Interrupt Status Register) bitfields.
          struct { 
            Object *teif; // [0:0] Transfer error interrupt flag 
            Object *tcif; // [1:1] Transfer complete interrupt flag 
            Object *twif; // [2:2] Transfer watermark interrupt flag 
            Object *caeif; // [3:3] CLUT access error interrupt flag 
            Object *ctcif; // [4:4] CLUT transfer complete interrupt flag 
            Object *ceif; // [5:5] Configuration error interrupt flag  
          } isr; 
          
          // IFCR (Interrupt flag clear register) bitfields.
          struct { 
            Object *cteif; // [0:0] Clear Transfer error interrupt flag 
            Object *ctcif; // [1:1] Clear transfer complete interrupt flag 
            Object *ctwif; // [2:2] Clear transfer watermark interrupt flag 
            Object *caecif; // [3:3] Clear CLUT access error interrupt flag 
            Object *cctcif; // [4:4] Clear CLUT transfer complete interrupt flag 
            Object *cceif; // [5:5] Clear configuration error interrupt flag  
          } ifcr; 
          
          // FGMAR (Foreground memory address register) bitfields.
          struct { 
            Object *ma; // [0:31] Memory address  
          } fgmar; 
          
          // FGOR (Foreground offset register) bitfields.
          struct { 
            Object *lo; // [0:13] Line offset  
          } fgor; 
          
          // BGMAR (Background memory address register) bitfields.
          struct { 
            Object *ma; // [0:31] Memory address  
          } bgmar; 
          
          // BGOR (Background offset register) bitfields.
          struct { 
            Object *lo; // [0:13] Line offset  
          } bgor; 
          
          // FGPFCCR (Foreground PFC control register) bitfields.
          struct { 
            Object *cm; // [0:3] Color mode 
            Object *ccm; // [4:4] CLUT color mode 
            Object *start; // [5:5] Start 
            Object *cs; // [8:15] CLUT size 
            Object *am; // [16:17] Alpha mode 
            Object *alpha; // [24:31] Alpha value  
          } fgpfccr; 
          
          // FGCOLR (Foreground color register) bitfields.
          struct { 
            Object *blue; // [0:7] Blue Value 
            Object *green; // [8:15] Green Value 
            Object *red; // [16:23] Red Value  
          } fgcolr; 
          
          // BGPFCCR (Background PFC control register) bitfields.
          struct { 
            Object *cm; // [0:3] Color mode 
            Object *ccm; // [4:4] CLUT Color mode 
            Object *start; // [5:5] Start 
            Object *cs; // [8:15] CLUT size 
            Object *am; // [16:17] Alpha mode 
            Object *alpha; // [24:31] Alpha value  
          } bgpfccr; 
          
          // BGCOLR (Background color register) bitfields.
          struct { 
            Object *blue; // [0:7] Blue Value 
            Object *green; // [8:15] Green Value 
            Object *red; // [16:23] Red Value  
          } bgcolr; 
          
          // FGCMAR (Foreground CLUT memory address register) bitfields.
          struct { 
            Object *ma; // [0:31] Memory Address  
          } fgcmar; 
          
          // BGCMAR (Background CLUT memory address register) bitfields.
          struct { 
            Object *ma; // [0:31] Memory address  
          } bgcmar; 
          
          // OPFCCR (Output PFC control register) bitfields.
          struct { 
            Object *cm; // [0:2] Color mode  
          } opfccr; 
          
          // OCOLR (Output color register) bitfields.
          struct { 
            Object *blue; // [0:7] Blue Value 
            Object *green; // [8:15] Green Value 
            Object *red; // [16:23] Red Value 
            Object *aplha; // [24:31] Alpha Channel Value  
          } ocolr; 
          
          // OMAR (Output memory address register) bitfields.
          struct { 
            Object *ma; // [0:31] Memory Address  
          } omar; 
          
          // OOR (Output offset register) bitfields.
          struct { 
            Object *lo; // [0:13] Line Offset  
          } oor; 
          
          // NLR (Number of line register) bitfields.
          struct { 
            Object *nl; // [0:15] Number of lines 
            Object *pl; // [16:29] Pixel per lines  
          } nlr; 
          
          // LWR (Line watermark register) bitfields.
          struct { 
            Object *lw; // [0:15] Line watermark  
          } lwr; 
          
          // AMTCR (AHB master timer configuration register) bitfields.
          struct { 
            Object *en; // [0:0] Enable 
            Object *dt; // [8:15] Dead Time  
          } amtcr; 
          
          // FGCLUT (FGCLUT) bitfields.
          struct { 
            Object *blue; // [0:7] BLUE 
            Object *green; // [8:15] GREEN 
            Object *red; // [16:23] RED 
            Object *aplha; // [24:31] APLHA  
          } fgclut; 
          
          // BGCLUT (BGCLUT) bitfields.
          struct { 
            Object *blue; // [0:7] BLUE 
            Object *green; // [8:15] GREEN 
            Object *red; // [16:23] RED 
            Object *aplha; // [24:31] APLHA  
          } bgclut; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32DMA2DState;

// ----------------------------------------------------------------------------

#endif /* STM32_DMA2D_H_ */
