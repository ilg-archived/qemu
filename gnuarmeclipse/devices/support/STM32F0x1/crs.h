/*
 * STM32 - CRS (Clock recovery system) emulation.
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

#ifndef STM32_CRS_H_
#define STM32_CRS_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_CRS DEVICE_PATH_STM32 "CRS"



// ----------------------------------------------------------------------------

#define TYPE_STM32_CRS TYPE_STM32_PREFIX "crs" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_CRS_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32CRSParentClass;
typedef PeripheralState STM32CRSParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_CRS_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32CRSClass, (obj), TYPE_STM32_CRS)
#define STM32_CRS_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32CRSClass, (klass), TYPE_STM32_CRS)

typedef struct {
    // private: 
    STM32CRSParentClass parent_class;
    // public: 

    // None, so far.
} STM32CRSClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_CRS_STATE(obj) \
    OBJECT_CHECK(STM32CRSState, (obj), TYPE_STM32_CRS)

typedef struct {
    // private:
    STM32CRSParentState parent_obj;
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
        // F0 CRS (Clock recovery system) registers.
        struct { 
          Object *cr; // 0x0 (Control register) 
          Object *cfgr; // 0x4 (Configuration register) 
          Object *isr; // 0x8 (Interrupt and status register) 
          Object *icr; // 0xC (Interrupt flag clear register) 
        } reg;

        struct { 
          
          // CR (Control register) bitfields.
          struct { 
            Object *syncokie; // [0:0] SYNC event OK interrupt enable 
            Object *syncwarnie; // [1:1] SYNC warning interrupt enable 
            Object *errie; // [2:2] Synchronization or trimming error interrupt enable 
            Object *esyncie; // [3:3] Expected SYNC interrupt enable 
            Object *cen; // [5:5] Frequency error counter enable 
            Object *autotrimen; // [6:6] Automatic trimming enable 
            Object *swsync; // [7:7] Generate software SYNC event 
            Object *trim; // [8:13] HSI48 oscillator smooth trimming  
          } cr; 
          
          // CFGR (Configuration register) bitfields.
          struct { 
            Object *reload; // [0:15] Counter reload value 
            Object *felim; // [16:23] Frequency error limit 
            Object *syncdiv; // [24:26] SYNC divider 
            Object *syncsrc; // [28:29] SYNC signal source selection 
            Object *syncpol; // [31:31] SYNC polarity selection  
          } cfgr; 
          
          // ISR (Interrupt and status register) bitfields.
          struct { 
            Object *syncokf; // [0:0] SYNC event OK flag 
            Object *syncwarnf; // [1:1] SYNC warning flag 
            Object *errf; // [2:2] Error flag 
            Object *esyncf; // [3:3] Expected SYNC flag 
            Object *syncerr; // [8:8] SYNC error 
            Object *syncmiss; // [9:9] SYNC missed 
            Object *trimovf; // [10:10] Trimming overflow or underflow 
            Object *fedir; // [15:15] Frequency error direction 
            Object *fecap; // [16:31] Frequency error capture  
          } isr; 
          
          // ICR (Interrupt flag clear register) bitfields.
          struct { 
            Object *syncokc; // [0:0] SYNC event OK clear flag 
            Object *syncwarnc; // [1:1] SYNC warning clear flag 
            Object *errc; // [2:2] Error clear flag 
            Object *esyncc; // [3:3] Expected SYNC clear flag  
          } icr; 
        } fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32CRSState;

// ----------------------------------------------------------------------------

#endif /* STM32_CRS_H_ */
