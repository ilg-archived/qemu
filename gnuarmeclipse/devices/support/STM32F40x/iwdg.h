/*
 * STM32 - IWDG (Independent watchdog) emulation.
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

#ifndef STM32_IWDG_H_
#define STM32_IWDG_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_IWDG DEVICE_PATH_STM32 "IWDG"



// ----------------------------------------------------------------------------

#define TYPE_STM32_IWDG TYPE_STM32_PREFIX "iwdg" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_IWDG_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32IWDGParentClass;
typedef PeripheralState STM32IWDGParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_IWDG_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32IWDGClass, (obj), TYPE_STM32_IWDG)
#define STM32_IWDG_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32IWDGClass, (klass), TYPE_STM32_IWDG)

typedef struct {
    // private: 
    STM32IWDGParentClass parent_class;
    // public: 

    // None, so far.
} STM32IWDGClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_IWDG_STATE(obj) \
    OBJECT_CHECK(STM32IWDGState, (obj), TYPE_STM32_IWDG)

typedef struct {
    // private:
    STM32IWDGParentState parent_obj;
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
        // F4 IWDG (Independent watchdog) registers.
        struct { 
          Object *kr; // 0x0 (Key register) 
          Object *pr; // 0x4 (Prescaler register) 
          Object *rlr; // 0x8 (Reload register) 
          Object *sr; // 0xC (Status register) 
        } reg;

        struct { 
          
          // KR (Key register) bitfields.
          struct { 
            Object *key; // [0:15] Key value (write only, read 0000h)  
          } kr; 
          
          // PR (Prescaler register) bitfields.
          struct { 
            Object *pr; // [0:2] Prescaler divider  
          } pr; 
          
          // RLR (Reload register) bitfields.
          struct { 
            Object *rl; // [0:11] Watchdog counter reload value  
          } rlr; 
          
          // SR (Status register) bitfields.
          struct { 
            Object *pvu; // [0:0] Watchdog prescaler value update 
            Object *rvu; // [1:1] Watchdog counter reload value update  
          } sr; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32IWDGState;

// ----------------------------------------------------------------------------

#endif /* STM32_IWDG_H_ */
