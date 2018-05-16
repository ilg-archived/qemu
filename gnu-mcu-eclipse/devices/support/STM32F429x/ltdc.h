/*
 * STM32 - LTDC (LCD-TFT Controller) emulation.
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

#ifndef STM32_LTDC_H_
#define STM32_LTDC_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_LTDC DEVICE_PATH_STM32 "LTDC"



// ----------------------------------------------------------------------------

#define TYPE_STM32_LTDC TYPE_STM32_PREFIX "ltdc" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_LTDC_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32LTDCParentClass;
typedef PeripheralState STM32LTDCParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_LTDC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32LTDCClass, (obj), TYPE_STM32_LTDC)
#define STM32_LTDC_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32LTDCClass, (klass), TYPE_STM32_LTDC)

typedef struct {
    // private: 
    STM32LTDCParentClass parent_class;
    // public: 

    // None, so far.
} STM32LTDCClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_LTDC_STATE(obj) \
    OBJECT_CHECK(STM32LTDCState, (obj), TYPE_STM32_LTDC)

typedef struct {
    // private:
    STM32LTDCParentState parent_obj;
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
        // F4 LTDC (LCD-TFT Controller) registers.
        struct { 
          Object *sscr; // 0x8 (Synchronization Size Configuration Register) 
          Object *bpcr; // 0xC (Back Porch Configuration Register) 
          Object *awcr; // 0x10 (Active Width Configuration Register) 
          Object *twcr; // 0x14 (Total Width Configuration Register) 
          Object *gcr; // 0x18 (Global Control Register) 
          Object *srcr; // 0x24 (Shadow Reload Configuration Register) 
          Object *bccr; // 0x2C (Background Color Configuration Register) 
          Object *ier; // 0x34 (Interrupt Enable Register) 
          Object *isr; // 0x38 (Interrupt Status Register) 
          Object *icr; // 0x3C (Interrupt Clear Register) 
          Object *lipcr; // 0x40 (Line Interrupt Position Configuration Register) 
          Object *cpsr; // 0x44 (Current Position Status Register) 
          Object *cdsr; // 0x48 (Current Display Status Register) 
          Object *l1cr; // 0x84 (Layerx Control Register) 
          Object *l1whpcr; // 0x88 (Layerx Window Horizontal Position Configuration Register) 
          Object *l1wvpcr; // 0x8C (Layerx Window Vertical Position Configuration Register) 
          Object *l1ckcr; // 0x90 (Layerx Color Keying Configuration Register) 
          Object *l1pfcr; // 0x94 (Layerx Pixel Format Configuration Register) 
          Object *l1cacr; // 0x98 (Layerx Constant Alpha Configuration Register) 
          Object *l1dccr; // 0x9C (Layerx Default Color Configuration Register) 
          Object *l1bfcr; // 0xA0 (Layerx Blending Factors Configuration Register) 
          Object *l1cfbar; // 0xAC (Layerx Color Frame Buffer Address Register) 
          Object *l1cfblr; // 0xB0 (Layerx Color Frame Buffer Length Register) 
          Object *l1cfblnr; // 0xB4 (Layerx ColorFrame Buffer Line Number Register) 
          Object *l1clutwr; // 0xC4 (Layerx CLUT Write Register) 
          Object *l2cr; // 0x104 (Layerx Control Register) 
          Object *l2whpcr; // 0x108 (Layerx Window Horizontal Position Configuration Register) 
          Object *l2wvpcr; // 0x10C (Layerx Window Vertical Position Configuration Register) 
          Object *l2ckcr; // 0x110 (Layerx Color Keying Configuration Register) 
          Object *l2pfcr; // 0x114 (Layerx Pixel Format Configuration Register) 
          Object *l2cacr; // 0x118 (Layerx Constant Alpha Configuration Register) 
          Object *l2dccr; // 0x11C (Layerx Default Color Configuration Register) 
          Object *l2bfcr; // 0x120 (Layerx Blending Factors Configuration Register) 
          Object *l2cfbar; // 0x12C (Layerx Color Frame Buffer Address Register) 
          Object *l2cfblr; // 0x130 (Layerx Color Frame Buffer Length Register) 
          Object *l2cfblnr; // 0x134 (Layerx ColorFrame Buffer Line Number Register) 
          Object *l2clutwr; // 0x144 (Layerx CLUT Write Register) 
        } reg;

        struct { 
          
          // SSCR (Synchronization Size Configuration Register) bitfields.
          struct { 
            Object *vsh; // [0:10] Vertical Synchronization Height (in units of horizontal scan line) 
            Object *hsw; // [16:27] Horizontal Synchronization Width (in units of pixel clock period)  
          } sscr; 
          
          // BPCR (Back Porch Configuration Register) bitfields.
          struct { 
            Object *avbp; // [0:10] Accumulated Vertical back porch (in units of horizontal scan line) 
            Object *ahbp; // [16:27] Accumulated Horizontal back porch (in units of pixel clock period)  
          } bpcr; 
          
          // AWCR (Active Width Configuration Register) bitfields.
          struct { 
            Object *aah; // [0:10] Accumulated Active Height (in units of horizontal scan line) 
            Object *aaw; // [16:27] Accumulated Active Width (in units of pixel clock period)  
          } awcr; 
          
          // TWCR (Total Width Configuration Register) bitfields.
          struct { 
            Object *totalh; // [0:10] Total Height (in units of horizontal scan line) 
            Object *totalw; // [16:27] Total Width (in units of pixel clock period)  
          } twcr; 
          
          // GCR (Global Control Register) bitfields.
          struct { 
            Object *ltdcen; // [0:0] LCD-TFT controller enable bit 
            Object *dbw; // [4:6] Dither Blue Width 
            Object *dgw; // [8:10] Dither Green Width 
            Object *drw; // [12:14] Dither Red Width 
            Object *den; // [16:16] Dither Enable 
            Object *pcpol; // [28:28] Pixel Clock Polarity 
            Object *depol; // [29:29] Data Enable Polarity 
            Object *vspol; // [30:30] Vertical Synchronization Polarity 
            Object *hspol; // [31:31] Horizontal Synchronization Polarity  
          } gcr; 
          
          // SRCR (Shadow Reload Configuration Register) bitfields.
          struct { 
            Object *imr; // [0:0] Immediate Reload 
            Object *vbr; // [1:1] Vertical Blanking Reload  
          } srcr; 
          
          // BCCR (Background Color Configuration Register) bitfields.
          struct { 
            Object *bc; // [0:23] Background Color Red value  
          } bccr; 
          
          // IER (Interrupt Enable Register) bitfields.
          struct { 
            Object *lie; // [0:0] Line Interrupt Enable 
            Object *fuie; // [1:1] FIFO Underrun Interrupt Enable 
            Object *terrie; // [2:2] Transfer Error Interrupt Enable 
            Object *rrie; // [3:3] Register Reload interrupt enable  
          } ier; 
          
          // ISR (Interrupt Status Register) bitfields.
          struct { 
            Object *lif; // [0:0] Line Interrupt flag 
            Object *fuif; // [1:1] FIFO Underrun Interrupt flag 
            Object *terrif; // [2:2] Transfer Error interrupt flag 
            Object *rrif; // [3:3] Register Reload Interrupt Flag  
          } isr; 
          
          // ICR (Interrupt Clear Register) bitfields.
          struct { 
            Object *clif; // [0:0] Clears the Line Interrupt Flag 
            Object *cfuif; // [1:1] Clears the FIFO Underrun Interrupt flag 
            Object *cterrif; // [2:2] Clears the Transfer Error Interrupt Flag 
            Object *crrif; // [3:3] Clears Register Reload Interrupt Flag  
          } icr; 
          
          // LIPCR (Line Interrupt Position Configuration Register) bitfields.
          struct { 
            Object *lipos; // [0:10] Line Interrupt Position  
          } lipcr; 
          
          // CPSR (Current Position Status Register) bitfields.
          struct { 
            Object *cypos; // [0:15] Current Y Position 
            Object *cxpos; // [16:31] Current X Position  
          } cpsr; 
          
          // CDSR (Current Display Status Register) bitfields.
          struct { 
            Object *vdes; // [0:0] Vertical Data Enable display Status 
            Object *hdes; // [1:1] Horizontal Data Enable display Status 
            Object *vsyncs; // [2:2] Vertical Synchronization display Status 
            Object *hsyncs; // [3:3] Horizontal Synchronization display Status  
          } cdsr; 
          
          // L1CR (Layerx Control Register) bitfields.
          struct { 
            Object *len; // [0:0] Layer Enable 
            Object *colken; // [1:1] Color Keying Enable 
            Object *cluten; // [4:4] Color Look-Up Table Enable  
          } l1cr; 
          
          // L1WHPCR (Layerx Window Horizontal Position Configuration Register) bitfields.
          struct { 
            Object *whstpos; // [0:11] Window Horizontal Start Position 
            Object *whsppos; // [16:27] Window Horizontal Stop Position  
          } l1whpcr; 
          
          // L1WVPCR (Layerx Window Vertical Position Configuration Register) bitfields.
          struct { 
            Object *wvstpos; // [0:10] Window Vertical Start Position 
            Object *wvsppos; // [16:26] Window Vertical Stop Position  
          } l1wvpcr; 
          
          // L1CKCR (Layerx Color Keying Configuration Register) bitfields.
          struct { 
            Object *ckblue; // [0:7] Color Key Blue value 
            Object *ckgreen; // [8:15] Color Key Green value 
            Object *ckred; // [16:23] Color Key Red value  
          } l1ckcr; 
          
          // L1PFCR (Layerx Pixel Format Configuration Register) bitfields.
          struct { 
            Object *pf; // [0:2] Pixel Format  
          } l1pfcr; 
          
          // L1CACR (Layerx Constant Alpha Configuration Register) bitfields.
          struct { 
            Object *consta; // [0:7] Constant Alpha  
          } l1cacr; 
          
          // L1DCCR (Layerx Default Color Configuration Register) bitfields.
          struct { 
            Object *dcblue; // [0:7] Default Color Blue 
            Object *dcgreen; // [8:15] Default Color Green 
            Object *dcred; // [16:23] Default Color Red 
            Object *dcalpha; // [24:31] Default Color Alpha  
          } l1dccr; 
          
          // L1BFCR (Layerx Blending Factors Configuration Register) bitfields.
          struct { 
            Object *bf2; // [0:2] Blending Factor 2 
            Object *bf1; // [8:10] Blending Factor 1  
          } l1bfcr; 
          
          // L1CFBAR (Layerx Color Frame Buffer Address Register) bitfields.
          struct { 
            Object *cfbadd; // [0:31] Color Frame Buffer Start Address  
          } l1cfbar; 
          
          // L1CFBLR (Layerx Color Frame Buffer Length Register) bitfields.
          struct { 
            Object *cfbll; // [0:12] Color Frame Buffer Line Length 
            Object *cfbp; // [16:28] Color Frame Buffer Pitch in bytes  
          } l1cfblr; 
          
          // L1CFBLNR (Layerx ColorFrame Buffer Line Number Register) bitfields.
          struct { 
            Object *cfblnbr; // [0:10] Frame Buffer Line Number  
          } l1cfblnr; 
          
          // L1CLUTWR (Layerx CLUT Write Register) bitfields.
          struct { 
            Object *blue; // [0:7] Blue value 
            Object *green; // [8:15] Green value 
            Object *red; // [16:23] Red value 
            Object *clutadd; // [24:31] CLUT Address  
          } l1clutwr; 
          
          // L2CR (Layerx Control Register) bitfields.
          struct { 
            Object *len; // [0:0] Layer Enable 
            Object *colken; // [1:1] Color Keying Enable 
            Object *cluten; // [4:4] Color Look-Up Table Enable  
          } l2cr; 
          
          // L2WHPCR (Layerx Window Horizontal Position Configuration Register) bitfields.
          struct { 
            Object *whstpos; // [0:11] Window Horizontal Start Position 
            Object *whsppos; // [16:27] Window Horizontal Stop Position  
          } l2whpcr; 
          
          // L2WVPCR (Layerx Window Vertical Position Configuration Register) bitfields.
          struct { 
            Object *wvstpos; // [0:10] Window Vertical Start Position 
            Object *wvsppos; // [16:26] Window Vertical Stop Position  
          } l2wvpcr; 
          
          // L2CKCR (Layerx Color Keying Configuration Register) bitfields.
          struct { 
            Object *ckblue; // [0:7] Color Key Blue value 
            Object *ckgreen; // [8:14] Color Key Green value 
            Object *ckred; // [15:23] Color Key Red value  
          } l2ckcr; 
          
          // L2PFCR (Layerx Pixel Format Configuration Register) bitfields.
          struct { 
            Object *pf; // [0:2] Pixel Format  
          } l2pfcr; 
          
          // L2CACR (Layerx Constant Alpha Configuration Register) bitfields.
          struct { 
            Object *consta; // [0:7] Constant Alpha  
          } l2cacr; 
          
          // L2DCCR (Layerx Default Color Configuration Register) bitfields.
          struct { 
            Object *dcblue; // [0:7] Default Color Blue 
            Object *dcgreen; // [8:15] Default Color Green 
            Object *dcred; // [16:23] Default Color Red 
            Object *dcalpha; // [24:31] Default Color Alpha  
          } l2dccr; 
          
          // L2BFCR (Layerx Blending Factors Configuration Register) bitfields.
          struct { 
            Object *bf2; // [0:2] Blending Factor 2 
            Object *bf1; // [8:10] Blending Factor 1  
          } l2bfcr; 
          
          // L2CFBAR (Layerx Color Frame Buffer Address Register) bitfields.
          struct { 
            Object *cfbadd; // [0:31] Color Frame Buffer Start Address  
          } l2cfbar; 
          
          // L2CFBLR (Layerx Color Frame Buffer Length Register) bitfields.
          struct { 
            Object *cfbll; // [0:12] Color Frame Buffer Line Length 
            Object *cfbp; // [16:28] Color Frame Buffer Pitch in bytes  
          } l2cfblr; 
          
          // L2CFBLNR (Layerx ColorFrame Buffer Line Number Register) bitfields.
          struct { 
            Object *cfblnbr; // [0:10] Frame Buffer Line Number  
          } l2cfblnr; 
          
          // L2CLUTWR (Layerx CLUT Write Register) bitfields.
          struct { 
            Object *blue; // [0:7] Blue value 
            Object *green; // [8:15] Green value 
            Object *red; // [16:23] Red value 
            Object *clutadd; // [24:31] CLUT Address  
          } l2clutwr; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32LTDCState;

// ----------------------------------------------------------------------------

#endif /* STM32_LTDC_H_ */
