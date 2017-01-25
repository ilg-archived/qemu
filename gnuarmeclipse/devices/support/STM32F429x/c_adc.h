/*
 * STM32 - C_ADC (Common ADC registers) emulation.
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

#ifndef STM32_C_ADC_H_
#define STM32_C_ADC_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_C_ADC DEVICE_PATH_STM32 "C_ADC"



// ----------------------------------------------------------------------------

#define TYPE_STM32_C_ADC TYPE_STM32_PREFIX "c_adc" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_C_ADC_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32C_ADCParentClass;
typedef PeripheralState STM32C_ADCParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_C_ADC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32C_ADCClass, (obj), TYPE_STM32_C_ADC)
#define STM32_C_ADC_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32C_ADCClass, (klass), TYPE_STM32_C_ADC)

typedef struct {
    // private: 
    STM32C_ADCParentClass parent_class;
    // public: 

    // None, so far.
} STM32C_ADCClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_C_ADC_STATE(obj) \
    OBJECT_CHECK(STM32C_ADCState, (obj), TYPE_STM32_C_ADC)

typedef struct {
    // private:
    STM32C_ADCParentState parent_obj;
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
        // F4 C_ADC (Common ADC registers) registers.
        struct { 
          Object *csr; // 0x0 (ADC Common status register) 
          Object *ccr; // 0x4 (ADC common control register) 
          Object *cdr; // 0x8 (ADC common regular data register for dual and triple modes) 
        } reg;

        struct { 
          
          // CSR (ADC Common status register) bitfields.
          struct { 
            Object *awd1; // [0:0] Analog watchdog flag of ADC 1 
            Object *eoc1; // [1:1] End of conversion of ADC 1 
            Object *jeoc1; // [2:2] Injected channel end of conversion of ADC 1 
            Object *jstrt1; // [3:3] Injected channel Start flag of ADC 1 
            Object *strt1; // [4:4] Regular channel Start flag of ADC 1 
            Object *ovr1; // [5:5] Overrun flag of ADC 1 
            Object *awd2; // [8:8] Analog watchdog flag of ADC 2 
            Object *eoc2; // [9:9] End of conversion of ADC 2 
            Object *jeoc2; // [10:10] Injected channel end of conversion of ADC 2 
            Object *jstrt2; // [11:11] Injected channel Start flag of ADC 2 
            Object *strt2; // [12:12] Regular channel Start flag of ADC 2 
            Object *ovr2; // [13:13] Overrun flag of ADC 2 
            Object *awd3; // [16:16] Analog watchdog flag of ADC 3 
            Object *eoc3; // [17:17] End of conversion of ADC 3 
            Object *jeoc3; // [18:18] Injected channel end of conversion of ADC 3 
            Object *jstrt3; // [19:19] Injected channel Start flag of ADC 3 
            Object *strt3; // [20:20] Regular channel Start flag of ADC 3 
            Object *ovr3; // [21:21] Overrun flag of ADC3  
          } csr; 
          
          // CCR (ADC common control register) bitfields.
          struct { 
            Object *mult; // [0:4] Multi ADC mode selection 
            Object *delay; // [8:11] Delay between 2 sampling phases 
            Object *dds; // [13:13] DMA disable selection for multi-ADC mode 
            Object *dma; // [14:15] Direct memory access mode for multi ADC mode 
            Object *adcpre; // [16:17] ADC prescaler 
            Object *vbate; // [22:22] VBAT enable 
            Object *tsvrefe; // [23:23] Temperature sensor and VREFINT enable  
          } ccr; 
          
          // CDR (ADC common regular data register for dual and triple modes) bitfields.
          struct { 
            Object *data1; // [0:15] 1st data item of a pair of regular conversions 
            Object *data2; // [16:31] 2nd data item of a pair of regular conversions  
          } cdr; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32C_ADCState;

// ----------------------------------------------------------------------------

#endif /* STM32_C_ADC_H_ */
