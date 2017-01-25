/*
 * STM32- COMP(Comparator) emulation.
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

#ifndef STM32_COMP_H_
#define STM32_COMP_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_COMPDEVICE_PATH_STM32"COMP"

// ----------------------------------------------------------------------------

#define TYPE_STM32_COMPTYPE_STM32_PREFIX "comp" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_COMP_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32COMPParentClass;
typedef PeripheralState STM32COMPParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_COMP_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32COMPClass, (obj), TYPE_STM32_COMP)
#define STM32_COMP_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32COMPClass, (klass), TYPE_STM32_COMP)

typedef struct {
    // private: 
    STM32COMPParentClass parent_class;
    // public: 

    // None, so far.
} STM32COMPClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_COMP_STATE(obj) \
    OBJECT_CHECK(STM32COMPState, (obj), TYPE_STM32_COMP)

typedef struct {
    // private:
    STM32COMPParentState parent_obj;
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
        // F0COMP(Comparator) registers.
        struct { 
Object *csr; // 0x0(Control and status register) 
} reg;

        struct { 
// CSR(Control and status register) bitfields.
          struct { 
Object *comp1en; // [0:0] Comparator 1 enableObject *comp1_inp_dac; // [1:1] COMP1_INP_DACObject *comp1mode; // [2:3] Comparator 1 modeObject *comp1insel; // [4:6] Comparator 1 inverting input selectionObject *comp1outsel; // [8:10] Comparator 1 output selectionObject *comp1pol; // [11:11] Comparator 1 output polarityObject *comp1hyst; // [12:13] Comparator 1 hysteresisObject *comp1out; // [14:14] Comparator 1 outputObject *comp1lock; // [15:15] Comparator 1 lockObject *comp2en; // [16:16] Comparator 2 enableObject *comp2mode; // [18:19] Comparator 2 modeObject *comp2insel; // [20:22] Comparator 2 inverting input selectionObject *wndwen; // [23:23] Window mode enableObject *comp2outsel; // [24:26] Comparator 2 output selectionObject *comp2pol; // [27:27] Comparator 2 output polarityObject *comp2hyst; // [28:29] Comparator 2 hysteresisObject *comp2out; // [30:30] Comparator 2 outputObject *comp2lock; // [31:31] Comparator 2 lock} csr; 
} fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32COMPState;

// ----------------------------------------------------------------------------

#endif /* STM32_COMP_H_ */
