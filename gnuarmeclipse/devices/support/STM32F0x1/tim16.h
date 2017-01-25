/*
 * STM32 - TIM16 (General-purpose-timers) emulation.
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

#ifndef STM32_TIM16_H_
#define STM32_TIM16_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_TIM16 DEVICE_PATH_STM32 "TIM16"



// ----------------------------------------------------------------------------

#define TYPE_STM32_TIM16 TYPE_STM32_PREFIX "tim16" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_TIM16_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32TIM16ParentClass;
typedef PeripheralState STM32TIM16ParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_TIM16_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32TIM16Class, (obj), TYPE_STM32_TIM16)
#define STM32_TIM16_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32TIM16Class, (klass), TYPE_STM32_TIM16)

typedef struct {
    // private: 
    STM32TIM16ParentClass parent_class;
    // public: 

    // None, so far.
} STM32TIM16Class;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_TIM16_STATE(obj) \
    OBJECT_CHECK(STM32TIM16State, (obj), TYPE_STM32_TIM16)

typedef struct {
    // private:
    STM32TIM16ParentState parent_obj;
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
        // F0 TIM16 (General-purpose-timers) registers.
        struct { 
          Object *cr1; // 0x0 (Control register 1) 
          Object *cr2; // 0x4 (Control register 2) 
          Object *dier; // 0xC (DMA/Interrupt enable register) 
          Object *sr; // 0x10 (Status register) 
          Object *egr; // 0x14 (Event generation register) 
          Object *ccmr1_output; // 0x18 (Capture/compare mode register (output mode)) 
          Object *ccmr1_input; // 0x18 (Capture/compare mode register 1 (input mode)) 
          Object *ccer; // 0x20 (Capture/compare enable register) 
          Object *cnt; // 0x24 (Counter) 
          Object *psc; // 0x28 (Prescaler) 
          Object *arr; // 0x2C (Auto-reload register) 
          Object *rcr; // 0x30 (Repetition counter register) 
          Object *ccr1; // 0x34 (Capture/compare register 1) 
          Object *bdtr; // 0x44 (Break and dead-time register) 
          Object *dcr; // 0x48 (DMA control register) 
          Object *dmar; // 0x4C (DMA address for full transfer) 
        } reg;

        struct { 
          
          // CR1 (Control register 1) bitfields.
          struct { 
            Object *cen; // [0:0] Counter enable 
            Object *udis; // [1:1] Update disable 
            Object *urs; // [2:2] Update request source 
            Object *opm; // [3:3] One-pulse mode 
            Object *arpe; // [7:7] Auto-reload preload enable 
            Object *ckd; // [8:9] Clock division  
          } cr1; 
          
          // CR2 (Control register 2) bitfields.
          struct { 
            Object *ccpc; // [0:0] Capture/compare preloaded control 
            Object *ccus; // [2:2] Capture/compare control update selection 
            Object *ccds; // [3:3] Capture/compare DMA selection 
            Object *ois1; // [8:8] Output Idle state 1 
            Object *ois1n; // [9:9] Output Idle state 1  
          } cr2; 
          
          // DIER (DMA/Interrupt enable register) bitfields.
          struct { 
            Object *uie; // [0:0] Update interrupt enable 
            Object *cc1ie; // [1:1] Capture/Compare 1 interrupt enable 
            Object *comie; // [5:5] COM interrupt enable 
            Object *tie; // [6:6] Trigger interrupt enable 
            Object *bie; // [7:7] Break interrupt enable 
            Object *ude; // [8:8] Update DMA request enable 
            Object *cc1de; // [9:9] Capture/Compare 1 DMA request enable 
            Object *tde; // [14:14] Trigger DMA request enable  
          } dier; 
          
          // SR (Status register) bitfields.
          struct { 
            Object *uif; // [0:0] Update interrupt flag 
            Object *cc1if; // [1:1] Capture/compare 1 interrupt flag 
            Object *comif; // [5:5] COM interrupt flag 
            Object *tif; // [6:6] Trigger interrupt flag 
            Object *bif; // [7:7] Break interrupt flag 
            Object *cc1of; // [9:9] Capture/Compare 1 overcapture flag  
          } sr; 
          
          // EGR (Event generation register) bitfields.
          struct { 
            Object *ug; // [0:0] Update generation 
            Object *cc1g; // [1:1] Capture/compare 1 generation 
            Object *comg; // [5:5] Capture/Compare control update generation 
            Object *tg; // [6:6] Trigger generation 
            Object *bg; // [7:7] Break generation  
          } egr; 
          
          // CCMR1_Output (Capture/compare mode register (output mode)) bitfields.
          struct { 
            Object *cc1s; // [0:1] Capture/Compare 1 selection 
            Object *oc1fe; // [2:2] Output Compare 1 fast enable 
            Object *oc1pe; // [3:3] Output Compare 1 preload enable 
            Object *oc1m; // [4:6] Output Compare 1 mode  
          } ccmr1_output; 
          
          // CCMR1_Input (Capture/compare mode register 1 (input mode)) bitfields.
          struct { 
            Object *cc1s; // [0:1] Capture/Compare 1 selection 
            Object *ic1psc; // [2:3] Input capture 1 prescaler 
            Object *ic1f; // [4:7] Input capture 1 filter  
          } ccmr1_input; 
          
          // CCER (Capture/compare enable register) bitfields.
          struct { 
            Object *cc1e; // [0:0] Capture/Compare 1 output enable 
            Object *cc1p; // [1:1] Capture/Compare 1 output Polarity 
            Object *cc1ne; // [2:2] Capture/Compare 1 complementary output enable 
            Object *cc1np; // [3:3] Capture/Compare 1 output Polarity  
          } ccer; 
          
          // CNT (Counter) bitfields.
          struct { 
            Object *cnt; // [0:15] Counter value  
          } cnt; 
          
          // PSC (Prescaler) bitfields.
          struct { 
            Object *psc; // [0:15] Prescaler value  
          } psc; 
          
          // ARR (Auto-reload register) bitfields.
          struct { 
            Object *arr; // [0:15] Auto-reload value  
          } arr; 
          
          // RCR (Repetition counter register) bitfields.
          struct { 
            Object *rep; // [0:7] Repetition counter value  
          } rcr; 
          
          // CCR1 (Capture/compare register 1) bitfields.
          struct { 
            Object *ccr1; // [0:15] Capture/Compare 1 value  
          } ccr1; 
          
          // BDTR (Break and dead-time register) bitfields.
          struct { 
            Object *dtg; // [0:7] Dead-time generator setup 
            Object *lock; // [8:9] Lock configuration 
            Object *ossi; // [10:10] Off-state selection for Idle mode 
            Object *ossr; // [11:11] Off-state selection for Run mode 
            Object *bke; // [12:12] Break enable 
            Object *bkp; // [13:13] Break polarity 
            Object *aoe; // [14:14] Automatic output enable 
            Object *moe; // [15:15] Main output enable  
          } bdtr; 
          
          // DCR (DMA control register) bitfields.
          struct { 
            Object *dba; // [0:4] DMA base address 
            Object *dbl; // [8:12] DMA burst length  
          } dcr; 
          
          // DMAR (DMA address for full transfer) bitfields.
          struct { 
            Object *dmab; // [0:15] DMA register for burst accesses  
          } dmar; 
        } fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32TIM16State;

// ----------------------------------------------------------------------------

#endif /* STM32_TIM16_H_ */
