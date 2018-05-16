/*
 * STM32 - TIM10 (General purpose timer) emulation.
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

#ifndef STM32_TIM10_H_
#define STM32_TIM10_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_TIM10 DEVICE_PATH_STM32 "TIM10"



// ----------------------------------------------------------------------------

#define TYPE_STM32_TIM10 TYPE_STM32_PREFIX "tim10" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_TIM10_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32TIM10ParentClass;
typedef PeripheralState STM32TIM10ParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_TIM10_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32TIM10Class, (obj), TYPE_STM32_TIM10)
#define STM32_TIM10_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32TIM10Class, (klass), TYPE_STM32_TIM10)

typedef struct {
    // private: 
    STM32TIM10ParentClass parent_class;
    // public: 

    // None, so far.
} STM32TIM10Class;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_TIM10_STATE(obj) \
    OBJECT_CHECK(STM32TIM10State, (obj), TYPE_STM32_TIM10)

typedef struct {
    // private:
    STM32TIM10ParentState parent_obj;
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
        // F1 TIM10 (General purpose timer) registers.
        struct { 
          Object *cr1; // 0x0 (Control register 1) 
          Object *cr2; // 0x4 (Control register 2) 
          Object *dier; // 0xC (DMA/Interrupt enable register) 
          Object *sr; // 0x10 (Status register) 
          Object *egr; // 0x14 (Event generation register) 
          Object *ccmr1_output; // 0x18 (Capture/compare mode register (output mode)) 
          Object *ccmr1_input; // 0x18 (Capture/compare mode register (input mode)) 
          Object *ccer; // 0x20 (Capture/compare enable register) 
          Object *cnt; // 0x24 (Counter) 
          Object *psc; // 0x28 (Prescaler) 
          Object *arr; // 0x2C (Auto-reload register) 
          Object *ccr1; // 0x34 (Capture/compare register 1) 
        } reg;

        struct { 
          
          // CR1 (Control register 1) bitfields.
          struct { 
            Object *cen; // [0:0] Counter enable 
            Object *udis; // [1:1] Update disable 
            Object *urs; // [2:2] Update request source 
            Object *arpe; // [7:7] Auto-reload preload enable 
            Object *ckd; // [8:9] Clock division  
          } cr1; 
          
          // CR2 (Control register 2) bitfields.
          struct { 
            Object *mms; // [4:6] Master mode selection  
          } cr2; 
          
          // DIER (DMA/Interrupt enable register) bitfields.
          struct { 
            Object *uie; // [0:0] Update interrupt enable 
            Object *cc1ie; // [1:1] Capture/Compare 1 interrupt enable  
          } dier; 
          
          // SR (Status register) bitfields.
          struct { 
            Object *uif; // [0:0] Update interrupt flag 
            Object *cc1if; // [1:1] Capture/compare 1 interrupt flag 
            Object *cc1of; // [9:9] Capture/Compare 1 overcapture flag  
          } sr; 
          
          // EGR (Event generation register) bitfields.
          struct { 
            Object *ug; // [0:0] Update generation 
            Object *cc1g; // [1:1] Capture/compare 1 generation  
          } egr; 
          
          // CCMR1_Output (Capture/compare mode register (output mode)) bitfields.
          struct { 
            Object *cc1s; // [0:1] Capture/Compare 1 selection 
            Object *oc1pe; // [3:3] Output Compare 1 preload enable 
            Object *oc1m; // [4:6] Output Compare 1 mode  
          } ccmr1_output; 
          
          // CCMR1_Input (Capture/compare mode register (input mode)) bitfields.
          struct { 
            Object *cc1s; // [0:1] Capture/Compare 1 selection 
            Object *ic1psc; // [2:3] Input capture 1 prescaler 
            Object *ic1f; // [4:7] Input capture 1 filter  
          } ccmr1_input; 
          
          // CCER (Capture/compare enable register) bitfields.
          struct { 
            Object *cc1e; // [0:0] Capture/Compare 1 output enable 
            Object *cc1p; // [1:1] Capture/Compare 1 output Polarity 
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
          
          // CCR1 (Capture/compare register 1) bitfields.
          struct { 
            Object *ccr1; // [0:15] Capture/Compare 1 value  
          } ccr1; 
        } fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32TIM10State;

// ----------------------------------------------------------------------------

#endif /* STM32_TIM10_H_ */
