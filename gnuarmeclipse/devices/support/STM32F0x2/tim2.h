/*
 * STM32- TIM2(General-purpose-timers) emulation.
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

#ifndef STM32_TIM2_H_
#define STM32_TIM2_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_TIM2DEVICE_PATH_STM32"TIM2"

// ----------------------------------------------------------------------------

#define TYPE_STM32_TIM2TYPE_STM32_PREFIX "tim2" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_TIM2_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32TIM2ParentClass;
typedef PeripheralState STM32TIM2ParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_TIM2_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32TIM2Class, (obj), TYPE_STM32_TIM2)
#define STM32_TIM2_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32TIM2Class, (klass), TYPE_STM32_TIM2)

typedef struct {
    // private: 
    STM32TIM2ParentClass parent_class;
    // public: 

    // None, so far.
} STM32TIM2Class;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_TIM2_STATE(obj) \
    OBJECT_CHECK(STM32TIM2State, (obj), TYPE_STM32_TIM2)

typedef struct {
    // private:
    STM32TIM2ParentState parent_obj;
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
        // F0TIM2(General-purpose-timers) registers.
        struct { 
Object *cr1; // 0x0(Control register 1) 
Object *cr2; // 0x4(Control register 2) 
Object *smcr; // 0x8(Slave mode control register) 
Object *dier; // 0xC(DMA/Interrupt enable register) 
Object *sr; // 0x10(Status register) 
Object *egr; // 0x14(Event generation register) 
Object *ccmr1_output; // 0x18(Capture/compare mode register 1 (output mode)) 
Object *ccmr1_input; // 0x18(Capture/compare mode register 1 (input mode)) 
Object *ccmr2_output; // 0x1C(Capture/compare mode register 2 (output mode)) 
Object *ccmr2_input; // 0x1C(Capture/compare mode register 2 (input mode)) 
Object *ccer; // 0x20(Capture/compare enable register) 
Object *cnt; // 0x24(Counter) 
Object *psc; // 0x28(Prescaler) 
Object *arr; // 0x2C(Auto-reload register) 
Object *ccr1; // 0x34(Capture/compare register 1) 
Object *ccr2; // 0x38(Capture/compare register 2) 
Object *ccr3; // 0x3C(Capture/compare register 3) 
Object *ccr4; // 0x40(Capture/compare register 4) 
Object *dcr; // 0x48(DMA control register) 
Object *dmar; // 0x4C(DMA address for full transfer) 
} reg;

        struct { 
// CR1(Control register 1) bitfields.
          struct { 
Object *cen; // [0:0] Counter enableObject *udis; // [1:1] Update disableObject *urs; // [2:2] Update request sourceObject *opm; // [3:3] One-pulse modeObject *dir; // [4:4] DirectionObject *cms; // [5:6] Center-aligned mode selectionObject *arpe; // [7:7] Auto-reload preload enableObject *ckd; // [8:9] Clock division} cr1; 
// CR2(Control register 2) bitfields.
          struct { 
Object *ccds; // [3:3] Capture/compare DMA selectionObject *mms; // [4:6] Master mode selectionObject *ti1s; // [7:7] TI1 selection} cr2; 
// SMCR(Slave mode control register) bitfields.
          struct { 
Object *sms; // [0:2] Slave mode selectionObject *ts; // [4:6] Trigger selectionObject *msm; // [7:7] Master/Slave modeObject *etf; // [8:11] External trigger filterObject *etps; // [12:13] External trigger prescalerObject *ece; // [14:14] External clock enableObject *etp; // [15:15] External trigger polarity} smcr; 
// DIER(DMA/Interrupt enable register) bitfields.
          struct { 
Object *uie; // [0:0] Update interrupt enableObject *cc1ie; // [1:1] Capture/Compare 1 interrupt enableObject *cc2ie; // [2:2] Capture/Compare 2 interrupt enableObject *cc3ie; // [3:3] Capture/Compare 3 interrupt enableObject *cc4ie; // [4:4] Capture/Compare 4 interrupt enableObject *tie; // [6:6] Trigger interrupt enableObject *ude; // [8:8] Update DMA request enableObject *cc1de; // [9:9] Capture/Compare 1 DMA request enableObject *cc2de; // [10:10] Capture/Compare 2 DMA request enableObject *cc3de; // [11:11] Capture/Compare 3 DMA request enableObject *cc4de; // [12:12] Capture/Compare 4 DMA request enableObject *comde; // [13:13] ReservedObject *tde; // [14:14] Trigger DMA request enable} dier; 
// SR(Status register) bitfields.
          struct { 
Object *uif; // [0:0] Update interrupt flagObject *cc1if; // [1:1] Capture/compare 1 interrupt flagObject *cc2if; // [2:2] Capture/Compare 2 interrupt flagObject *cc3if; // [3:3] Capture/Compare 3 interrupt flagObject *cc4if; // [4:4] Capture/Compare 4 interrupt flagObject *tif; // [6:6] Trigger interrupt flagObject *cc1of; // [9:9] Capture/Compare 1 overcapture flagObject *cc2of; // [10:10] Capture/compare 2 overcapture flagObject *cc3of; // [11:11] Capture/Compare 3 overcapture flagObject *cc4of; // [12:12] Capture/Compare 4 overcapture flag} sr; 
// EGR(Event generation register) bitfields.
          struct { 
Object *ug; // [0:0] Update generationObject *cc1g; // [1:1] Capture/compare 1 generationObject *cc2g; // [2:2] Capture/compare 2 generationObject *cc3g; // [3:3] Capture/compare 3 generationObject *cc4g; // [4:4] Capture/compare 4 generationObject *tg; // [6:6] Trigger generation} egr; 
// CCMR1_Output(Capture/compare mode register 1 (output mode)) bitfields.
          struct { 
Object *cc1s; // [0:1] Capture/Compare 1 selectionObject *oc1fe; // [2:2] Output compare 1 fast enableObject *oc1pe; // [3:3] Output compare 1 preload enableObject *oc1m; // [4:6] Output compare 1 modeObject *oc1ce; // [7:7] Output compare 1 clear enableObject *cc2s; // [8:9] Capture/Compare 2 selectionObject *oc2fe; // [10:10] Output compare 2 fast enableObject *oc2pe; // [11:11] Output compare 2 preload enableObject *oc2m; // [12:14] Output compare 2 modeObject *oc2ce; // [15:15] Output compare 2 clear enable} ccmr1_output; 
// CCMR1_Input(Capture/compare mode register 1 (input mode)) bitfields.
          struct { 
Object *cc1s; // [0:1] Capture/Compare 1 selectionObject *ic1psc; // [2:3] Input capture 1 prescalerObject *ic1f; // [4:7] Input capture 1 filterObject *cc2s; // [8:9] Capture/compare 2 selectionObject *ic2psc; // [10:11] Input capture 2 prescalerObject *ic2f; // [12:15] Input capture 2 filter} ccmr1_input; 
// CCMR2_Output(Capture/compare mode register 2 (output mode)) bitfields.
          struct { 
Object *cc3s; // [0:1] Capture/Compare 3 selectionObject *oc3fe; // [2:2] Output compare 3 fast enableObject *oc3pe; // [3:3] Output compare 3 preload enableObject *oc3m; // [4:6] Output compare 3 modeObject *oc3ce; // [7:7] Output compare 3 clear enableObject *cc4s; // [8:9] Capture/Compare 4 selectionObject *oc4fe; // [10:10] Output compare 4 fast enableObject *oc4pe; // [11:11] Output compare 4 preload enableObject *oc4m; // [12:14] Output compare 4 modeObject *oc4ce; // [15:15] Output compare 4 clear enable} ccmr2_output; 
// CCMR2_Input(Capture/compare mode register 2 (input mode)) bitfields.
          struct { 
Object *cc3s; // [0:1] Capture/Compare 3 selectionObject *ic3psc; // [2:3] Input capture 3 prescalerObject *ic3f; // [4:7] Input capture 3 filterObject *cc4s; // [8:9] Capture/Compare 4 selectionObject *ic4psc; // [10:11] Input capture 4 prescalerObject *ic4f; // [12:15] Input capture 4 filter} ccmr2_input; 
// CCER(Capture/compare enable register) bitfields.
          struct { 
Object *cc1e; // [0:0] Capture/Compare 1 output enableObject *cc1p; // [1:1] Capture/Compare 1 output PolarityObject *cc1np; // [3:3] Capture/Compare 1 output PolarityObject *cc2e; // [4:4] Capture/Compare 2 output enableObject *cc2p; // [5:5] Capture/Compare 2 output PolarityObject *cc2np; // [7:7] Capture/Compare 2 output PolarityObject *cc3e; // [8:8] Capture/Compare 3 output enableObject *cc3p; // [9:9] Capture/Compare 3 output PolarityObject *cc3np; // [11:11] Capture/Compare 3 output PolarityObject *cc4e; // [12:12] Capture/Compare 4 output enableObject *cc4p; // [13:13] Capture/Compare 3 output PolarityObject *cc4np; // [15:15] Capture/Compare 4 output Polarity} ccer; 
// CNT(Counter) bitfields.
          struct { 
Object *cnt_l; // [0:15] Low counter valueObject *cnt_h; // [16:31] High counter value (TIM2 only)} cnt; 
// PSC(Prescaler) bitfields.
          struct { 
Object *psc; // [0:15] Prescaler value} psc; 
// ARR(Auto-reload register) bitfields.
          struct { 
Object *arr_l; // [0:15] Low Auto-reload valueObject *arr_h; // [16:31] High Auto-reload value (TIM2 only)} arr; 
// CCR1(Capture/compare register 1) bitfields.
          struct { 
Object *ccr1_l; // [0:15] Low Capture/Compare 1 valueObject *ccr1_h; // [16:31] High Capture/Compare 1 value (TIM2 only)} ccr1; 
// CCR2(Capture/compare register 2) bitfields.
          struct { 
Object *ccr2_l; // [0:15] Low Capture/Compare 2 valueObject *ccr2_h; // [16:31] High Capture/Compare 2 value (TIM2 only)} ccr2; 
// CCR3(Capture/compare register 3) bitfields.
          struct { 
Object *ccr3_l; // [0:15] Low Capture/Compare valueObject *ccr3_h; // [16:31] High Capture/Compare value (TIM2 only)} ccr3; 
// CCR4(Capture/compare register 4) bitfields.
          struct { 
Object *ccr4_l; // [0:15] Low Capture/Compare valueObject *ccr4_h; // [16:31] High Capture/Compare value (TIM2 only)} ccr4; 
// DCR(DMA control register) bitfields.
          struct { 
Object *dba; // [0:4] DMA base addressObject *dbl; // [8:12] DMA burst length} dcr; 
// DMAR(DMA address for full transfer) bitfields.
          struct { 
Object *dmar; // [0:15] DMA register for burst accesses} dmar; 
} fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32TIM2State;

// ----------------------------------------------------------------------------

#endif /* STM32_TIM2_H_ */
