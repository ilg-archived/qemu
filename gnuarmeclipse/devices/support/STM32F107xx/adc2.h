/*
 * STM32 - ADC (Analog to digital converter) emulation.
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

#ifndef STM32_ADC_H_
#define STM32_ADC_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_ADC DEVICE_PATH_STM32 "ADC"

// ----------------------------------------------------------------------------

// Note: the "port-index" property has type "int".
typedef enum {
    // TODO: keep this list in ascending order.
    STM32_PORT_ADC1,
    STM32_PORT_ADC2,
    STM32_PORT_ADC_UNDEFINED = 0xFF,
} stm32_adc_index_t;

// ----------------------------------------------------------------------------

#define TYPE_STM32_ADC TYPE_STM32_PREFIX "adc" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_ADC_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32ADCParentClass;
typedef PeripheralState STM32ADCParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_ADC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32ADCClass, (obj), TYPE_STM32_ADC)
#define STM32_ADC_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32ADCClass, (klass), TYPE_STM32_ADC)

typedef struct {
    // private: 
    STM32ADCParentClass parent_class;
    // public: 

    // None, so far.
} STM32ADCClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_ADC_STATE(obj) \
    OBJECT_CHECK(STM32ADCState, (obj), TYPE_STM32_ADC)

typedef struct {
    // private:
    STM32ADCParentState parent_obj;
    // public:

    const STM32Capabilities *capabilities;

    // TODO: remove this if the peripheral is always enabled.
    // Points to the bitfield that enables the peripheral.
    Object *enabling_bit;

    // Remove it if there is only one port
    stm32_adc_index_t port_index;

    union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // F1 ADC (Analog to digital converter) registers.
        struct { 
          Object *sr; // 0x0 (Status register) 
          Object *cr1; // 0x4 (Control register 1) 
          Object *cr2; // 0x8 (Control register 2) 
          Object *smpr1; // 0xC (Sample time register 1) 
          Object *smpr2; // 0x10 (Sample time register 2) 
          Object *jofr1; // 0x14 (Injected channel data offset register x) 
          Object *jofr2; // 0x18 (Injected channel data offset register x) 
          Object *jofr3; // 0x1C (Injected channel data offset register x) 
          Object *jofr4; // 0x20 (Injected channel data offset register x) 
          Object *htr; // 0x24 (Watchdog higher threshold register) 
          Object *ltr; // 0x28 (Watchdog lower threshold register) 
          Object *sqr1; // 0x2C (Regular sequence register 1) 
          Object *sqr2; // 0x30 (Regular sequence register 2) 
          Object *sqr3; // 0x34 (Regular sequence register 3) 
          Object *jsqr; // 0x38 (Injected sequence register) 
          Object *jdr1; // 0x3C (Injected data register x) 
          Object *jdr2; // 0x40 (Injected data register x) 
          Object *jdr3; // 0x44 (Injected data register x) 
          Object *jdr4; // 0x48 (Injected data register x) 
          Object *dr; // 0x4C (Regular data register) 
        } reg;

        struct { 
          
          // SR (Status register) bitfields.
          struct { 
            Object *awd; // [0:0] Analog watchdog flag 
            Object *eoc; // [1:1] Regular channel end of conversion 
            Object *jeoc; // [2:2] Injected channel end of conversion 
            Object *jstrt; // [3:3] Injected channel start flag 
            Object *strt; // [4:4] Regular channel start flag  
          } sr; 
          
          // CR1 (Control register 1) bitfields.
          struct { 
            Object *awdch; // [0:4] Analog watchdog channel select bits 
            Object *eocie; // [5:5] Interrupt enable for EOC 
            Object *awdie; // [6:6] Analog watchdog interrupt enable 
            Object *jeocie; // [7:7] Interrupt enable for injected channels 
            Object *scan; // [8:8] Scan mode 
            Object *awdsgl; // [9:9] Enable the watchdog on a single channel in scan mode 
            Object *jauto; // [10:10] Automatic injected group conversion 
            Object *discen; // [11:11] Discontinuous mode on regular channels 
            Object *jdiscen; // [12:12] Discontinuous mode on injected channels 
            Object *discnum; // [13:15] Discontinuous mode channel count 
            Object *jawden; // [22:22] Analog watchdog enable on injected channels 
            Object *awden; // [23:23] Analog watchdog enable on regular channels  
          } cr1; 
          
          // CR2 (Control register 2) bitfields.
          struct { 
            Object *adon; // [0:0] A/D converter ON / OFF 
            Object *cont; // [1:1] Continuous conversion 
            Object *cal; // [2:2] A/D calibration 
            Object *rstcal; // [3:3] Reset calibration 
            Object *dma; // [8:8] Direct memory access mode 
            Object *align; // [11:11] Data alignment 
            Object *jextsel; // [12:14] External event select for injected group 
            Object *jexttrig; // [15:15] External trigger conversion mode for injected channels 
            Object *extsel; // [17:19] External event select for regular group 
            Object *exttrig; // [20:20] External trigger conversion mode for regular channels 
            Object *jswstart; // [21:21] Start conversion of injected channels 
            Object *swstart; // [22:22] Start conversion of regular channels 
            Object *tsvrefe; // [23:23] Temperature sensor and VREFINT enable  
          } cr2; 
          
          // SMPR1 (Sample time register 1) bitfields.
          struct { 
            Object *smp10; // [0:2] Channel 10 sampling time selection 
            Object *smp11; // [3:5] Channel 11 sampling time selection 
            Object *smp12; // [6:8] Channel 12 sampling time selection 
            Object *smp13; // [9:11] Channel 13 sampling time selection 
            Object *smp14; // [12:14] Channel 14 sampling time selection 
            Object *smp15; // [15:17] Channel 15 sampling time selection 
            Object *smp16; // [18:20] Channel 16 sampling time selection 
            Object *smp17; // [21:23] Channel 17 sampling time selection  
          } smpr1; 
          
          // SMPR2 (Sample time register 2) bitfields.
          struct { 
            Object *smp0; // [0:2] Channel 0 sampling time selection 
            Object *smp1; // [3:5] Channel 1 sampling time selection 
            Object *smp2; // [6:8] Channel 2 sampling time selection 
            Object *smp3; // [9:11] Channel 3 sampling time selection 
            Object *smp4; // [12:14] Channel 4 sampling time selection 
            Object *smp5; // [15:17] Channel 5 sampling time selection 
            Object *smp6; // [18:20] Channel 6 sampling time selection 
            Object *smp7; // [21:23] Channel 7 sampling time selection 
            Object *smp8; // [24:26] Channel 8 sampling time selection 
            Object *smp9; // [27:29] Channel 9 sampling time selection  
          } smpr2; 
          
          // JOFR1 (Injected channel data offset register x) bitfields.
          struct { 
            Object *joffset1; // [0:11] Data offset for injected channel x  
          } jofr1; 
          
          // JOFR2 (Injected channel data offset register x) bitfields.
          struct { 
            Object *joffset2; // [0:11] Data offset for injected channel x  
          } jofr2; 
          
          // JOFR3 (Injected channel data offset register x) bitfields.
          struct { 
            Object *joffset3; // [0:11] Data offset for injected channel x  
          } jofr3; 
          
          // JOFR4 (Injected channel data offset register x) bitfields.
          struct { 
            Object *joffset4; // [0:11] Data offset for injected channel x  
          } jofr4; 
          
          // HTR (Watchdog higher threshold register) bitfields.
          struct { 
            Object *ht; // [0:11] Analog watchdog higher threshold  
          } htr; 
          
          // LTR (Watchdog lower threshold register) bitfields.
          struct { 
            Object *lt; // [0:11] Analog watchdog lower threshold  
          } ltr; 
          
          // SQR1 (Regular sequence register 1) bitfields.
          struct { 
            Object *sq13; // [0:4] 13th conversion in regular sequence 
            Object *sq14; // [5:9] 14th conversion in regular sequence 
            Object *sq15; // [10:14] 15th conversion in regular sequence 
            Object *sq16; // [15:19] 16th conversion in regular sequence 
            Object *l; // [20:23] Regular channel sequence length  
          } sqr1; 
          
          // SQR2 (Regular sequence register 2) bitfields.
          struct { 
            Object *sq7; // [0:4] 7th conversion in regular sequence 
            Object *sq8; // [5:9] 8th conversion in regular sequence 
            Object *sq9; // [10:14] 9th conversion in regular sequence 
            Object *sq10; // [15:19] 10th conversion in regular sequence 
            Object *sq11; // [20:24] 11th conversion in regular sequence 
            Object *sq12; // [25:29] 12th conversion in regular sequence  
          } sqr2; 
          
          // SQR3 (Regular sequence register 3) bitfields.
          struct { 
            Object *sq1; // [0:4] 1st conversion in regular sequence 
            Object *sq2; // [5:9] 2nd conversion in regular sequence 
            Object *sq3; // [10:14] 3rd conversion in regular sequence 
            Object *sq4; // [15:19] 4th conversion in regular sequence 
            Object *sq5; // [20:24] 5th conversion in regular sequence 
            Object *sq6; // [25:29] 6th conversion in regular sequence  
          } sqr3; 
          
          // JSQR (Injected sequence register) bitfields.
          struct { 
            Object *jsq1; // [0:4] 1st conversion in injected sequence 
            Object *jsq2; // [5:9] 2nd conversion in injected sequence 
            Object *jsq3; // [10:14] 3rd conversion in injected sequence 
            Object *jsq4; // [15:19] 4th conversion in injected sequence 
            Object *jl; // [20:21] Injected sequence length  
          } jsqr; 
          
          // JDR1 (Injected data register x) bitfields.
          struct { 
            Object *jdata; // [0:15] Injected data  
          } jdr1; 
          
          // JDR2 (Injected data register x) bitfields.
          struct { 
            Object *jdata; // [0:15] Injected data  
          } jdr2; 
          
          // JDR3 (Injected data register x) bitfields.
          struct { 
            Object *jdata; // [0:15] Injected data  
          } jdr3; 
          
          // JDR4 (Injected data register x) bitfields.
          struct { 
            Object *jdata; // [0:15] Injected data  
          } jdr4; 
          
          // DR (Regular data register) bitfields.
          struct { 
            Object *data; // [0:15] Regular data  
          } dr; 
        } fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32ADCState;

// ----------------------------------------------------------------------------

#endif /* STM32_ADC_H_ */
