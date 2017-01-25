/*
 * STM32 - WWDG (Window watchdog) emulation.
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

#ifndef STM32_WWDG_H_
#define STM32_WWDG_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_WWDG DEVICE_PATH_STM32 "WWDG"



// ----------------------------------------------------------------------------

#define TYPE_STM32_WWDG TYPE_STM32_PREFIX "wwdg" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_WWDG_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32WWDGParentClass;
typedef PeripheralState STM32WWDGParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_WWDG_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32WWDGClass, (obj), TYPE_STM32_WWDG)
#define STM32_WWDG_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32WWDGClass, (klass), TYPE_STM32_WWDG)

typedef struct {
    // private: 
    STM32WWDGParentClass parent_class;
    // public: 

    // None, so far.
} STM32WWDGClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_WWDG_STATE(obj) \
    OBJECT_CHECK(STM32WWDGState, (obj), TYPE_STM32_WWDG)

typedef struct {
    // private:
    STM32WWDGParentState parent_obj;
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
        // F4 WWDG (Window watchdog) registers.
        struct { 
          Object *cr; // 0x0 (Control register) 
          Object *cfr; // 0x4 (Configuration register) 
          Object *sr; // 0x8 (Status register) 
        } reg;

        struct { 
          
          // CR (Control register) bitfields.
          struct { 
            Object *t; // [0:6] 7-bit counter (MSB to LSB) 
            Object *wdga; // [7:7] Activation bit  
          } cr; 
          
          // CFR (Configuration register) bitfields.
          struct { 
            Object *w; // [0:6] 7-bit window value 
            Object *wdgtb0; // [7:7] Timer base 
            Object *wdgtb1; // [8:8] Timer base 
            Object *ewi; // [9:9] Early wakeup interrupt  
          } cfr; 
          
          // SR (Status register) bitfields.
          struct { 
            Object *ewif; // [0:0] Early wakeup interrupt flag  
          } sr; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32WWDGState;

// ----------------------------------------------------------------------------

#endif /* STM32_WWDG_H_ */
