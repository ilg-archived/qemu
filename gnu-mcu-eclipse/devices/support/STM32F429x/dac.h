/*
 * STM32 - DAC (Digital-to-analog converter) emulation.
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

#ifndef STM32_DAC_H_
#define STM32_DAC_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_DAC DEVICE_PATH_STM32 "DAC"



// ----------------------------------------------------------------------------

#define TYPE_STM32_DAC TYPE_STM32_PREFIX "dac" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_DAC_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32DACParentClass;
typedef PeripheralState STM32DACParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_DAC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DACClass, (obj), TYPE_STM32_DAC)
#define STM32_DAC_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32DACClass, (klass), TYPE_STM32_DAC)

typedef struct {
    // private: 
    STM32DACParentClass parent_class;
    // public: 

    // None, so far.
} STM32DACClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_DAC_STATE(obj) \
    OBJECT_CHECK(STM32DACState, (obj), TYPE_STM32_DAC)

typedef struct {
    // private:
    STM32DACParentState parent_obj;
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
        // F4 DAC (Digital-to-analog converter) registers.
        struct { 
          Object *cr; // 0x0 (Control register) 
          Object *swtrigr; // 0x4 (Software trigger register) 
          Object *dhr12r1; // 0x8 (Channel1 12-bit right-aligned data holding register) 
          Object *dhr12l1; // 0xC (Channel1 12-bit left aligned data holding register) 
          Object *dhr8r1; // 0x10 (Channel1 8-bit right aligned data holding register) 
          Object *dhr12r2; // 0x14 (Channel2 12-bit right aligned data holding register) 
          Object *dhr12l2; // 0x18 (Channel2 12-bit left aligned data holding register) 
          Object *dhr8r2; // 0x1C (Channel2 8-bit right-aligned data holding register) 
          Object *dhr12rd; // 0x20 (Dual DAC 12-bit right-aligned data holding register) 
          Object *dhr12ld; // 0x24 (DUAL DAC 12-bit left aligned data holding register) 
          Object *dhr8rd; // 0x28 (DUAL DAC 8-bit right aligned data holding register) 
          Object *dor1; // 0x2C (Channel1 data output register) 
          Object *dor2; // 0x30 (Channel2 data output register) 
          Object *sr; // 0x34 (Status register) 
        } reg;

        struct { 
          
          // CR (Control register) bitfields.
          struct { 
            Object *en1; // [0:0] DAC channel1 enable 
            Object *boff1; // [1:1] DAC channel1 output buffer disable 
            Object *ten1; // [2:2] DAC channel1 trigger enable 
            Object *tsel1; // [3:5] DAC channel1 trigger selection 
            Object *wave1; // [6:7] DAC channel1 noise/triangle wave generation enable 
            Object *mamp1; // [8:11] DAC channel1 mask/amplitude selector 
            Object *dmaen1; // [12:12] DAC channel1 DMA enable 
            Object *dmaudrie1; // [13:13] DAC channel1 DMA Underrun Interrupt enable 
            Object *en2; // [16:16] DAC channel2 enable 
            Object *boff2; // [17:17] DAC channel2 output buffer disable 
            Object *ten2; // [18:18] DAC channel2 trigger enable 
            Object *tsel2; // [19:21] DAC channel2 trigger selection 
            Object *wave2; // [22:23] DAC channel2 noise/triangle wave generation enable 
            Object *mamp2; // [24:27] DAC channel2 mask/amplitude selector 
            Object *dmaen2; // [28:28] DAC channel2 DMA enable 
            Object *dmaudrie2; // [29:29] DAC channel2 DMA underrun interrupt enable  
          } cr; 
          
          // SWTRIGR (Software trigger register) bitfields.
          struct { 
            Object *swtrig1; // [0:0] DAC channel1 software trigger 
            Object *swtrig2; // [1:1] DAC channel2 software trigger  
          } swtrigr; 
          
          // DHR12R1 (Channel1 12-bit right-aligned data holding register) bitfields.
          struct { 
            Object *dacc1dhr; // [0:11] DAC channel1 12-bit right-aligned data  
          } dhr12r1; 
          
          // DHR12L1 (Channel1 12-bit left aligned data holding register) bitfields.
          struct { 
            Object *dacc1dhr; // [4:15] DAC channel1 12-bit left-aligned data  
          } dhr12l1; 
          
          // DHR8R1 (Channel1 8-bit right aligned data holding register) bitfields.
          struct { 
            Object *dacc1dhr; // [0:7] DAC channel1 8-bit right-aligned data  
          } dhr8r1; 
          
          // DHR12R2 (Channel2 12-bit right aligned data holding register) bitfields.
          struct { 
            Object *dacc2dhr; // [0:11] DAC channel2 12-bit right-aligned data  
          } dhr12r2; 
          
          // DHR12L2 (Channel2 12-bit left aligned data holding register) bitfields.
          struct { 
            Object *dacc2dhr; // [4:15] DAC channel2 12-bit left-aligned data  
          } dhr12l2; 
          
          // DHR8R2 (Channel2 8-bit right-aligned data holding register) bitfields.
          struct { 
            Object *dacc2dhr; // [0:7] DAC channel2 8-bit right-aligned data  
          } dhr8r2; 
          
          // DHR12RD (Dual DAC 12-bit right-aligned data holding register) bitfields.
          struct { 
            Object *dacc1dhr; // [0:11] DAC channel1 12-bit right-aligned data 
            Object *dacc2dhr; // [16:27] DAC channel2 12-bit right-aligned data  
          } dhr12rd; 
          
          // DHR12LD (DUAL DAC 12-bit left aligned data holding register) bitfields.
          struct { 
            Object *dacc1dhr; // [4:15] DAC channel1 12-bit left-aligned data 
            Object *dacc2dhr; // [20:31] DAC channel2 12-bit left-aligned data  
          } dhr12ld; 
          
          // DHR8RD (DUAL DAC 8-bit right aligned data holding register) bitfields.
          struct { 
            Object *dacc1dhr; // [0:7] DAC channel1 8-bit right-aligned data 
            Object *dacc2dhr; // [8:15] DAC channel2 8-bit right-aligned data  
          } dhr8rd; 
          
          // DOR1 (Channel1 data output register) bitfields.
          struct { 
            Object *dacc1dor; // [0:11] DAC channel1 data output  
          } dor1; 
          
          // DOR2 (Channel2 data output register) bitfields.
          struct { 
            Object *dacc2dor; // [0:11] DAC channel2 data output  
          } dor2; 
          
          // SR (Status register) bitfields.
          struct { 
            Object *dmaudr1; // [13:13] DAC channel1 DMA underrun flag 
            Object *dmaudr2; // [29:29] DAC channel2 DMA underrun flag  
          } sr; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32DACState;

// ----------------------------------------------------------------------------

#endif /* STM32_DAC_H_ */
