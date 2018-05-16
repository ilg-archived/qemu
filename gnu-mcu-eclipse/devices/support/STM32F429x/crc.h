/*
 * STM32 - CRC (Cryptographic processor) emulation.
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

#ifndef STM32_CRC_H_
#define STM32_CRC_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_CRC DEVICE_PATH_STM32 "CRC"



// ----------------------------------------------------------------------------

#define TYPE_STM32_CRC TYPE_STM32_PREFIX "crc" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_CRC_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32CRCParentClass;
typedef PeripheralState STM32CRCParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_CRC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32CRCClass, (obj), TYPE_STM32_CRC)
#define STM32_CRC_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32CRCClass, (klass), TYPE_STM32_CRC)

typedef struct {
    // private: 
    STM32CRCParentClass parent_class;
    // public: 

    // None, so far.
} STM32CRCClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_CRC_STATE(obj) \
    OBJECT_CHECK(STM32CRCState, (obj), TYPE_STM32_CRC)

typedef struct {
    // private:
    STM32CRCParentState parent_obj;
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
        // F4 CRC (Cryptographic processor) registers.
        struct { 
          Object *dr; // 0x0 (Data register) 
          Object *idr; // 0x4 (Independent Data register) 
          Object *cr; // 0x8 (Control register) 
        } reg;

        struct { 
          
          // DR (Data register) bitfields.
          struct { 
            Object *dr; // [0:31] Data Register  
          } dr; 
          
          // IDR (Independent Data register) bitfields.
          struct { 
            Object *idr; // [0:7] Independent Data register  
          } idr; 
          
          // CR (Control register) bitfields.
          struct { 
            Object *cr; // [0:0] Control regidter  
          } cr; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32CRCState;

// ----------------------------------------------------------------------------

#endif /* STM32_CRC_H_ */
