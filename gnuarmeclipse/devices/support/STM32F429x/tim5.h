/*
 * STM32 - TIM5 (General-purpose-timers) emulation.
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

#ifndef STM32_TIM5_H_
#define STM32_TIM5_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_TIM5 DEVICE_PATH_STM32 "TIM5"



// ----------------------------------------------------------------------------

#define TYPE_STM32_TIM5 TYPE_STM32_PREFIX "tim5" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_TIM5_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32TIM5ParentClass;
typedef PeripheralState STM32TIM5ParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_TIM5_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32TIM5Class, (obj), TYPE_STM32_TIM5)
#define STM32_TIM5_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32TIM5Class, (klass), TYPE_STM32_TIM5)

typedef struct {
    // private: 
    STM32TIM5ParentClass parent_class;
    // public: 

    // None, so far.
} STM32TIM5Class;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_TIM5_STATE(obj) \
    OBJECT_CHECK(STM32TIM5State, (obj), TYPE_STM32_TIM5)

typedef struct {
    // private:
    STM32TIM5ParentState parent_obj;
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
        // F4 TIM5 (General-purpose-timers) registers.
        struct { 
          Object *cr1; // 0x0 (Control register 1) 
          Object *cr2; // 0x4 (Control register 2) 
          Object *smcr; // 0x8 (Slave mode control register) 
          Object *dier; // 0xC (DMA/Interrupt enable register) 
          Object *sr; // 0x10 (Status register) 
          Object *egr; // 0x14 (Event generation register) 
          Object *ccmr1_output; // 0x18 (Capture/compare mode register 1 (output mode)) 
          Object *ccmr1_input; // 0x18 (Capture/compare mode register 1 (input mode)) 
          Object *ccmr2_output; // 0x1C (Capture/compare mode register 2 (output mode)) 
          Object *ccmr2_input; // 0x1C (Capture/compare mode register 2 (input mode)) 
          Object *ccer; // 0x20 (Capture/compare enable register) 
          Object *cnt; // 0x24 (Counter) 
          Object *psc; // 0x28 (Prescaler) 
          Object *arr; // 0x2C (Auto-reload register) 
          Object *ccr1; // 0x34 (Capture/compare register 1) 
          Object *ccr2; // 0x38 (Capture/compare register 2) 
          Object *ccr3; // 0x3C (Capture/compare register 3) 
          Object *ccr4; // 0x40 (Capture/compare register 4) 
          Object *dcr; // 0x48 (DMA control register) 
          Object *dmar; // 0x4C (DMA address for full transfer) 
          Object *or_; // 0x50 (TIM5 option register) 
        } reg;

        struct { 
          
          // CR1 (Control register 1) bitfields.
          struct { 
            Object *cen; // [0:0] Counter enable 
            Object *udis; // [1:1] Update disable 
            Object *urs; // [2:2] Update request source 
            Object *opm; // [3:3] One-pulse mode 
            Object *dir; // [4:4] Direction 
            Object *cms; // [5:6] Center-aligned mode selection 
            Object *arpe; // [7:7] Auto-reload preload enable 
            Object *ckd; // [8:9] Clock division  
          } cr1; 
          
          // CR2 (Control register 2) bitfields.
          struct { 
            Object *ccds; // [3:3] Capture/compare DMA selection 
            Object *mms; // [4:6] Master mode selection 
            Object *ti1s; // [7:7] TI1 selection  
          } cr2; 
          
          // SMCR (Slave mode control register) bitfields.
          struct { 
            Object *sms; // [0:2] Slave mode selection 
            Object *ts; // [4:6] Trigger selection 
            Object *msm; // [7:7] Master/Slave mode 
            Object *etf; // [8:11] External trigger filter 
            Object *etps; // [12:13] External trigger prescaler 
            Object *ece; // [14:14] External clock enable 
            Object *etp; // [15:15] External trigger polarity  
          } smcr; 
          
          // DIER (DMA/Interrupt enable register) bitfields.
          struct { 
            Object *uie; // [0:0] Update interrupt enable 
            Object *cc1ie; // [1:1] Capture/Compare 1 interrupt enable 
            Object *cc2ie; // [2:2] Capture/Compare 2 interrupt enable 
            Object *cc3ie; // [3:3] Capture/Compare 3 interrupt enable 
            Object *cc4ie; // [4:4] Capture/Compare 4 interrupt enable 
            Object *tie; // [6:6] Trigger interrupt enable 
            Object *ude; // [8:8] Update DMA request enable 
            Object *cc1de; // [9:9] Capture/Compare 1 DMA request enable 
            Object *cc2de; // [10:10] Capture/Compare 2 DMA request enable 
            Object *cc3de; // [11:11] Capture/Compare 3 DMA request enable 
            Object *cc4de; // [12:12] Capture/Compare 4 DMA request enable 
            Object *tde; // [14:14] Trigger DMA request enable  
          } dier; 
          
          // SR (Status register) bitfields.
          struct { 
            Object *uif; // [0:0] Update interrupt flag 
            Object *cc1if; // [1:1] Capture/compare 1 interrupt flag 
            Object *cc2if; // [2:2] Capture/Compare 2 interrupt flag 
            Object *cc3if; // [3:3] Capture/Compare 3 interrupt flag 
            Object *cc4if; // [4:4] Capture/Compare 4 interrupt flag 
            Object *tif; // [6:6] Trigger interrupt flag 
            Object *cc1of; // [9:9] Capture/Compare 1 overcapture flag 
            Object *cc2of; // [10:10] Capture/compare 2 overcapture flag 
            Object *cc3of; // [11:11] Capture/Compare 3 overcapture flag 
            Object *cc4of; // [12:12] Capture/Compare 4 overcapture flag  
          } sr; 
          
          // EGR (Event generation register) bitfields.
          struct { 
            Object *ug; // [0:0] Update generation 
            Object *cc1g; // [1:1] Capture/compare 1 generation 
            Object *cc2g; // [2:2] Capture/compare 2 generation 
            Object *cc3g; // [3:3] Capture/compare 3 generation 
            Object *cc4g; // [4:4] Capture/compare 4 generation 
            Object *tg; // [6:6] Trigger generation  
          } egr; 
          
          // CCMR1_Output (Capture/compare mode register 1 (output mode)) bitfields.
          struct { 
            Object *cc1s; // [0:1] CC1S 
            Object *oc1fe; // [2:2] OC1FE 
            Object *oc1pe; // [3:3] OC1PE 
            Object *oc1m; // [4:6] OC1M 
            Object *oc1ce; // [7:7] OC1CE 
            Object *cc2s; // [8:9] CC2S 
            Object *oc2fe; // [10:10] OC2FE 
            Object *oc2pe; // [11:11] OC2PE 
            Object *oc2m; // [12:14] OC2M 
            Object *oc2ce; // [15:15] OC2CE  
          } ccmr1_output; 
          
          // CCMR1_Input (Capture/compare mode register 1 (input mode)) bitfields.
          struct { 
            Object *cc1s; // [0:1] Capture/Compare 1 selection 
            Object *icpcs; // [2:3] Input capture 1 prescaler 
            Object *ic1f; // [4:7] Input capture 1 filter 
            Object *cc2s; // [8:9] Capture/Compare 2 selection 
            Object *ic2pcs; // [10:11] Input capture 2 prescaler 
            Object *ic2f; // [12:15] Input capture 2 filter  
          } ccmr1_input; 
          
          // CCMR2_Output (Capture/compare mode register 2 (output mode)) bitfields.
          struct { 
            Object *cc3s; // [0:1] CC3S 
            Object *oc3fe; // [2:2] OC3FE 
            Object *oc3pe; // [3:3] OC3PE 
            Object *oc3m; // [4:6] OC3M 
            Object *oc3ce; // [7:7] OC3CE 
            Object *cc4s; // [8:9] CC4S 
            Object *oc4fe; // [10:10] OC4FE 
            Object *oc4pe; // [11:11] OC4PE 
            Object *oc4m; // [12:14] OC4M 
            Object *o24ce; // [15:15] O24CE  
          } ccmr2_output; 
          
          // CCMR2_Input (Capture/compare mode register 2 (input mode)) bitfields.
          struct { 
            Object *cc3s; // [0:1] Capture/compare 3 selection 
            Object *ic3psc; // [2:3] Input capture 3 prescaler 
            Object *ic3f; // [4:7] Input capture 3 filter 
            Object *cc4s; // [8:9] Capture/Compare 4 selection 
            Object *ic4psc; // [10:11] Input capture 4 prescaler 
            Object *ic4f; // [12:15] Input capture 4 filter  
          } ccmr2_input; 
          
          // CCER (Capture/compare enable register) bitfields.
          struct { 
            Object *cc1e; // [0:0] Capture/Compare 1 output enable 
            Object *cc1p; // [1:1] Capture/Compare 1 output Polarity 
            Object *cc1np; // [3:3] Capture/Compare 1 output Polarity 
            Object *cc2e; // [4:4] Capture/Compare 2 output enable 
            Object *cc2p; // [5:5] Capture/Compare 2 output Polarity 
            Object *cc2np; // [7:7] Capture/Compare 2 output Polarity 
            Object *cc3e; // [8:8] Capture/Compare 3 output enable 
            Object *cc3p; // [9:9] Capture/Compare 3 output Polarity 
            Object *cc3np; // [11:11] Capture/Compare 3 output Polarity 
            Object *cc4e; // [12:12] Capture/Compare 4 output enable 
            Object *cc4p; // [13:13] Capture/Compare 3 output Polarity 
            Object *cc4np; // [15:15] Capture/Compare 4 output Polarity  
          } ccer; 
          
          // CNT (Counter) bitfields.
          struct { 
            Object *cnt_l; // [0:15] Low counter value 
            Object *cnt_h; // [16:31] High counter value  
          } cnt; 
          
          // PSC (Prescaler) bitfields.
          struct { 
            Object *psc; // [0:15] Prescaler value  
          } psc; 
          
          // ARR (Auto-reload register) bitfields.
          struct { 
            Object *arr_l; // [0:15] Low Auto-reload value 
            Object *arr_h; // [16:31] High Auto-reload value  
          } arr; 
          
          // CCR1 (Capture/compare register 1) bitfields.
          struct { 
            Object *ccr1_l; // [0:15] Low Capture/Compare 1 value 
            Object *ccr1_h; // [16:31] High Capture/Compare 1 value  
          } ccr1; 
          
          // CCR2 (Capture/compare register 2) bitfields.
          struct { 
            Object *ccr2_l; // [0:15] Low Capture/Compare 2 value 
            Object *ccr2_h; // [16:31] High Capture/Compare 2 value  
          } ccr2; 
          
          // CCR3 (Capture/compare register 3) bitfields.
          struct { 
            Object *ccr3_l; // [0:15] Low Capture/Compare value 
            Object *ccr3_h; // [16:31] High Capture/Compare value  
          } ccr3; 
          
          // CCR4 (Capture/compare register 4) bitfields.
          struct { 
            Object *ccr4_l; // [0:15] Low Capture/Compare value 
            Object *ccr4_h; // [16:31] High Capture/Compare value  
          } ccr4; 
          
          // DCR (DMA control register) bitfields.
          struct { 
            Object *dba; // [0:4] DMA base address 
            Object *dbl; // [8:12] DMA burst length  
          } dcr; 
          
          // DMAR (DMA address for full transfer) bitfields.
          struct { 
            Object *dmab; // [0:15] DMA register for burst accesses  
          } dmar; 
          
          // OR (TIM5 option register) bitfields.
          struct { 
            Object *it4_rmp; // [6:7] Timer Input 4 remap  
          } or_; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32TIM5State;

// ----------------------------------------------------------------------------

#endif /* STM32_TIM5_H_ */
