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
        // F0 DAC (Digital-to-analog converter) registers.
        struct { 
          Object *cr; // 0x0 (Control register) 
          Object *swtrigr; // 0x4 (Software trigger register) 
          Object *dhr12r1; // 0x8 (Channel1 12-bit right-aligned data holding register) 
          Object *dhr12l1; // 0xC (Channel1 12-bit left aligned data holding register) 
          Object *dhr8r1; // 0x10 (Channel1 8-bit right aligned data holding register) 
          Object *dor1; // 0x2C (Channel1 data output register) 
          Object *sr; // 0x34 (Status register) 
        } reg;

        struct { 
          
          // CR (Control register) bitfields.
          struct { 
            Object *lpds; // [0:0] Low-power deep sleep 
            Object *pdds; // [1:1] Power down deepsleep 
            Object *cwuf; // [2:2] Clear wakeup flag 
            Object *csbf; // [3:3] Clear standby flag 
            Object *pvde; // [4:4] Power voltage detector enable 
            Object *pls; // [5:7] PVD level selection 
            Object *dbp; // [8:8] Disable backup domain write protection  
          } cr; 
          
          // SWTRIGR (Software trigger register) bitfields.
          struct { 
            Object *swtrig1; // [0:0] DAC channel1 software trigger  
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
          
          // DOR1 (Channel1 data output register) bitfields.
          struct { 
            Object *dacc1dor; // [0:11] DAC channel1 data output  
          } dor1; 
          
          // SR (Status register) bitfields.
          struct { 
            Object *dmaudr1; // [13:13] DAC channel1 DMA underrun flag 
            Object *dmaudr2; // [29:29] DAC channel2 DMA underrun flag  
          } sr; 
        } fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32DACState;

// ----------------------------------------------------------------------------

#endif /* STM32_DAC_H_ */
