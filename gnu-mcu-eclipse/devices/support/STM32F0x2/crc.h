/*
 * STM32- CRC(Cyclic redundancy check calculation unit) emulation.
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

#define DEVICE_PATH_STM32_CRCDEVICE_PATH_STM32"CRC"

// ----------------------------------------------------------------------------

#define TYPE_STM32_CRCTYPE_STM32_PREFIX "crc" TYPE_PERIPHERAL_SUFFIX

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
        // F0CRC(Cyclic redundancy check calculation unit) registers.
        struct { 
Object *dr; // 0x0(Data register) 
Object *idr; // 0x4(Independent data register) 
Object *cr; // 0x8(Control register) 
Object *init; // 0xC(Initial CRC value) 
} reg;

        struct { 
// DR(Data register) bitfields.
          struct { 
Object *dr; // [0:31] Data register bits} dr; 
// IDR(Independent data register) bitfields.
          struct { 
Object *idr; // [0:7] General-purpose 8-bit data register bits} idr; 
// CR(Control register) bitfields.
          struct { 
Object *reset; // [0:0] Reset bitObject *polysize; // [3:4] Polynomial sizeObject *rev_in; // [5:6] Reverse input dataObject *rev_out; // [7:7] Reverse output data} cr; 
// INIT(Initial CRC value) bitfields.
          struct { 
Object *init; // [0:31] Programmable initial CRC value} init; 
} fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32CRCState;

// ----------------------------------------------------------------------------

#endif /* STM32_CRC_H_ */
