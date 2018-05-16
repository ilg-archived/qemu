/*
 * STM32- ADC(Analog-to-digital converter) emulation.
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

#define DEVICE_PATH_STM32_ADCDEVICE_PATH_STM32"ADC"

// ----------------------------------------------------------------------------

#define TYPE_STM32_ADCTYPE_STM32_PREFIX "adc" TYPE_PERIPHERAL_SUFFIX

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

union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // F0ADC(Analog-to-digital converter) registers.
        struct { 
Object *isr; // 0x0(Interrupt and status register) 
Object *ier; // 0x4(Interrupt enable register) 
Object *cr; // 0x8(Control register) 
Object *cfgr1; // 0xC(Configuration register 1) 
Object *cfgr2; // 0x10(Configuration register 2) 
Object *smpr; // 0x14(Sampling time register) 
Object *tr; // 0x20(Watchdog threshold register) 
Object *chselr; // 0x28(Channel selection register) 
Object *dr; // 0x40(Data register) 
Object *ccr; // 0x308(Common configuration register) 
} reg;

        struct { 
// ISR(Interrupt and status register) bitfields.
          struct { 
Object *adrdy; // [0:0] ADC readyObject *eosmp; // [1:1] End of sampling flagObject *eoc; // [2:2] End of conversion flagObject *eos; // [3:3] End of sequence flagObject *ovr; // [4:4] ADC overrunObject *awd; // [7:7] Analog watchdog flag} isr; 
// IER(Interrupt enable register) bitfields.
          struct { 
Object *adrdyie; // [0:0] ADC ready interrupt enableObject *eosmpie; // [1:1] End of sampling flag interrupt enableObject *eocie; // [2:2] End of conversion interrupt enableObject *eosie; // [3:3] End of conversion sequence interrupt enableObject *ovrie; // [4:4] Overrun interrupt enableObject *awdie; // [7:7] Analog watchdog interrupt enable} ier; 
// CR(Control register) bitfields.
          struct { 
Object *aden; // [0:0] ADC enable commandObject *addis; // [1:1] ADC disable commandObject *adstart; // [2:2] ADC start conversion commandObject *adstp; // [4:4] ADC stop conversion commandObject *adcal; // [31:31] ADC calibration} cr; 
// CFGR1(Configuration register 1) bitfields.
          struct { 
Object *dmaen; // [0:0] Direct memory access enableObject *dmacfg; // [1:1] Direct memery access configurationObject *scandir; // [2:2] Scan sequence directionObject *res; // [3:4] Data resolutionObject *align; // [5:5] Data alignmentObject *extsel; // [6:8] External trigger selectionObject *exten; // [10:11] External trigger enable and polarity selectionObject *ovrmod; // [12:12] Overrun management modeObject *cont; // [13:13] Single / continuous conversion modeObject *autdly; // [14:14] Auto-delayed conversion modeObject *autoff; // [15:15] Auto-off modeObject *discen; // [16:16] Discontinuous modeObject *awdsgl; // [22:22] Enable the watchdog on a single channel or on all channelsObject *awden; // [23:23] Analog watchdog enableObject *awdch; // [26:30] Analog watchdog channel selection} cfgr1; 
// CFGR2(Configuration register 2) bitfields.
          struct { 
Object *jitoff_d2; // [30:30] JITOFF_D2Object *jitoff_d4; // [31:31] JITOFF_D4} cfgr2; 
// SMPR(Sampling time register) bitfields.
          struct { 
Object *smpr; // [0:2] Sampling time selection} smpr; 
// TR(Watchdog threshold register) bitfields.
          struct { 
Object *lt; // [0:11] Analog watchdog lower thresholdObject *ht; // [16:27] Analog watchdog higher threshold} tr; 
// CHSELR(Channel selection register) bitfields.
          struct { 
Object *chsel0; // [0:0] Channel-x selectionObject *chsel1; // [1:1] Channel-x selectionObject *chsel2; // [2:2] Channel-x selectionObject *chsel3; // [3:3] Channel-x selectionObject *chsel4; // [4:4] Channel-x selectionObject *chsel5; // [5:5] Channel-x selectionObject *chsel6; // [6:6] Channel-x selectionObject *chsel7; // [7:7] Channel-x selectionObject *chsel8; // [8:8] Channel-x selectionObject *chsel9; // [9:9] Channel-x selectionObject *chsel10; // [10:10] Channel-x selectionObject *chsel11; // [11:11] Channel-x selectionObject *chsel12; // [12:12] Channel-x selectionObject *chsel13; // [13:13] Channel-x selectionObject *chsel14; // [14:14] Channel-x selectionObject *chsel15; // [15:15] Channel-x selectionObject *chsel16; // [16:16] Channel-x selectionObject *chsel17; // [17:17] Channel-x selectionObject *chsel18; // [18:18] Channel-x selection} chselr; 
// DR(Data register) bitfields.
          struct { 
Object *data; // [0:15] Converted data} dr; 
// CCR(Common configuration register) bitfields.
          struct { 
Object *vrefen; // [22:22] Temperature sensor and VREFINT enableObject *tsen; // [23:23] Temperature sensor enableObject *vbaten; // [24:24] VBAT enable} ccr; 
} fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32ADCState;

// ----------------------------------------------------------------------------

#endif /* STM32_ADC_H_ */
