/*
 * STM32 - RNG (Random number generator) emulation.
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

#ifndef STM32_RNG_H_
#define STM32_RNG_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_RNG DEVICE_PATH_STM32 "RNG"



// ----------------------------------------------------------------------------

#define TYPE_STM32_RNG TYPE_STM32_PREFIX "rng" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_RNG_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32RNGParentClass;
typedef PeripheralState STM32RNGParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_RNG_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32RNGClass, (obj), TYPE_STM32_RNG)
#define STM32_RNG_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32RNGClass, (klass), TYPE_STM32_RNG)

typedef struct {
    // private: 
    STM32RNGParentClass parent_class;
    // public: 

    // None, so far.
} STM32RNGClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_RNG_STATE(obj) \
    OBJECT_CHECK(STM32RNGState, (obj), TYPE_STM32_RNG)

typedef struct {
    // private:
    STM32RNGParentState parent_obj;
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
        // F4 RNG (Random number generator) registers.
        struct { 
          Object *cr; // 0x0 (Control register) 
          Object *sr; // 0x4 (Status register) 
          Object *dr; // 0x8 (Data register) 
        } reg;

        struct { 
          
          // CR (Control register) bitfields.
          struct { 
            Object *rngen; // [2:2] Random number generator enable 
            Object *ie; // [3:3] Interrupt enable  
          } cr; 
          
          // SR (Status register) bitfields.
          struct { 
            Object *drdy; // [0:0] Data ready 
            Object *cecs; // [1:1] Clock error current status 
            Object *secs; // [2:2] Seed error current status 
            Object *ceis; // [5:5] Clock error interrupt status 
            Object *seis; // [6:6] Seed error interrupt status  
          } sr; 
          
          // DR (Data register) bitfields.
          struct { 
            Object *rndata; // [0:31] Random data  
          } dr; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32RNGState;

// ----------------------------------------------------------------------------

#endif /* STM32_RNG_H_ */
