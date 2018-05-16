/*
 * STM32 - TIM6 (Basic-timers) emulation.
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

#ifndef STM32_TIM6_H_
#define STM32_TIM6_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_TIM6 DEVICE_PATH_STM32 "TIM6"



// ----------------------------------------------------------------------------

#define TYPE_STM32_TIM6 TYPE_STM32_PREFIX "tim6" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_TIM6_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32TIM6ParentClass;
typedef PeripheralState STM32TIM6ParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_TIM6_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32TIM6Class, (obj), TYPE_STM32_TIM6)
#define STM32_TIM6_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32TIM6Class, (klass), TYPE_STM32_TIM6)

typedef struct {
    // private: 
    STM32TIM6ParentClass parent_class;
    // public: 

    // None, so far.
} STM32TIM6Class;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_TIM6_STATE(obj) \
    OBJECT_CHECK(STM32TIM6State, (obj), TYPE_STM32_TIM6)

typedef struct {
    // private:
    STM32TIM6ParentState parent_obj;
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
        // F0 TIM6 (Basic-timers) registers.
        struct { 
          Object *cr1; // 0x0 (Control register 1) 
          Object *cr2; // 0x4 (Control register 2) 
          Object *dier; // 0xC (DMA/Interrupt enable register) 
          Object *sr; // 0x10 (Status register) 
          Object *egr; // 0x14 (Event generation register) 
          Object *cnt; // 0x24 (Counter) 
          Object *psc; // 0x28 (Prescaler) 
          Object *arr; // 0x2C (Auto-reload register) 
        } reg;

        struct { 
          
          // CR1 (Control register 1) bitfields.
          struct { 
            Object *cen; // [0:0] Counter enable 
            Object *udis; // [1:1] Update disable 
            Object *urs; // [2:2] Update request source 
            Object *opm; // [3:3] One-pulse mode 
            Object *arpe; // [7:7] Auto-reload preload enable  
          } cr1; 
          
          // CR2 (Control register 2) bitfields.
          struct { 
            Object *mms; // [4:6] Master mode selection  
          } cr2; 
          
          // DIER (DMA/Interrupt enable register) bitfields.
          struct { 
            Object *uie; // [0:0] Update interrupt enable 
            Object *ude; // [8:8] Update DMA request enable  
          } dier; 
          
          // SR (Status register) bitfields.
          struct { 
            Object *uif; // [0:0] Update interrupt flag  
          } sr; 
          
          // EGR (Event generation register) bitfields.
          struct { 
            Object *ug; // [0:0] Update generation  
          } egr; 
          
          // CNT (Counter) bitfields.
          struct { 
            Object *cnt; // [0:15] Low counter value  
          } cnt; 
          
          // PSC (Prescaler) bitfields.
          struct { 
            Object *psc; // [0:15] Prescaler value  
          } psc; 
          
          // ARR (Auto-reload register) bitfields.
          struct { 
            Object *arr; // [0:15] Low Auto-reload value  
          } arr; 
        } fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32TIM6State;

// ----------------------------------------------------------------------------

#endif /* STM32_TIM6_H_ */
