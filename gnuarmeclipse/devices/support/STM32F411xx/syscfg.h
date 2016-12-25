/*
 * STM32 - SYSCFG (System configuration controller) emulation.
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

#ifndef STM32_SYSCFG_H_
#define STM32_SYSCFG_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_SYSCFG DEVICE_PATH_STM32 "SYSCFG"



// ----------------------------------------------------------------------------

#define TYPE_STM32_SYSCFG TYPE_STM32_PREFIX "syscfg" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_SYSCFG_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32SYSCFGParentClass;
typedef PeripheralState STM32SYSCFGParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_SYSCFG_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32SYSCFGClass, (obj), TYPE_STM32_SYSCFG)
#define STM32_SYSCFG_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32SYSCFGClass, (klass), TYPE_STM32_SYSCFG)

typedef struct {
    // private: 
    STM32SYSCFGParentClass parent_class;
    // public: 

    // None, so far.
} STM32SYSCFGClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_SYSCFG_STATE(obj) \
    OBJECT_CHECK(STM32SYSCFGState, (obj), TYPE_STM32_SYSCFG)

typedef struct {
    // private:
    STM32SYSCFGParentState parent_obj;
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
        // F4 SYSCFG (System configuration controller) registers.
        struct { 
          Object *memrm; // 0x0 (Memory remap register) 
          Object *pmc; // 0x4 (Peripheral mode configuration register) 
          Object *exticr1; // 0x8 (External interrupt configuration register 1) 
          Object *exticr2; // 0xC (External interrupt configuration register 2) 
          Object *exticr3; // 0x10 (External interrupt configuration register 3) 
          Object *exticr4; // 0x14 (External interrupt configuration register 4) 
          Object *cmpcr; // 0x20 (Compensation cell control register) 
        } reg;

        struct { 
          
          // MEMRM (Memory remap register) bitfields.
          struct { 
            Object *mem_mode; // [0:1] MEM_MODE  
          } memrm; 
          
          // PMC (Peripheral mode configuration register) bitfields.
          struct { 
            Object *adc1dc2; // [16:16] ADC1DC2  
          } pmc; 
          
          // EXTICR1 (External interrupt configuration register 1) bitfields.
          struct { 
            Object *exti0; // [0:3] EXTI x configuration (x = 0 to 3) 
            Object *exti1; // [4:7] EXTI x configuration (x = 0 to 3) 
            Object *exti2; // [8:11] EXTI x configuration (x = 0 to 3) 
            Object *exti3; // [12:15] EXTI x configuration (x = 0 to 3)  
          } exticr1; 
          
          // EXTICR2 (External interrupt configuration register 2) bitfields.
          struct { 
            Object *exti4; // [0:3] EXTI x configuration (x = 4 to 7) 
            Object *exti5; // [4:7] EXTI x configuration (x = 4 to 7) 
            Object *exti6; // [8:11] EXTI x configuration (x = 4 to 7) 
            Object *exti7; // [12:15] EXTI x configuration (x = 4 to 7)  
          } exticr2; 
          
          // EXTICR3 (External interrupt configuration register 3) bitfields.
          struct { 
            Object *exti8; // [0:3] EXTI x configuration (x = 8 to 11) 
            Object *exti9; // [4:7] EXTI x configuration (x = 8 to 11) 
            Object *exti10; // [8:11] EXTI10 
            Object *exti11; // [12:15] EXTI x configuration (x = 8 to 11)  
          } exticr3; 
          
          // EXTICR4 (External interrupt configuration register 4) bitfields.
          struct { 
            Object *exti12; // [0:3] EXTI x configuration (x = 12 to 15) 
            Object *exti13; // [4:7] EXTI x configuration (x = 12 to 15) 
            Object *exti14; // [8:11] EXTI x configuration (x = 12 to 15) 
            Object *exti15; // [12:15] EXTI x configuration (x = 12 to 15)  
          } exticr4; 
          
          // CMPCR (Compensation cell control register) bitfields.
          struct { 
            Object *cmp_pd; // [0:0] Compensation cell power-down 
            Object *ready; // [8:8] READY  
          } cmpcr; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32SYSCFGState;

// ----------------------------------------------------------------------------

#endif /* STM32_SYSCFG_H_ */
