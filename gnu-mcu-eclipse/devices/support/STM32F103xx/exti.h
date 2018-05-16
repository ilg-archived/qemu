/*
 * STM32 - EXTI (EXTI) emulation.
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

#ifndef STM32_EXTI_H_
#define STM32_EXTI_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_EXTI DEVICE_PATH_STM32 "EXTI"



// ----------------------------------------------------------------------------

#define TYPE_STM32_EXTI TYPE_STM32_PREFIX "exti" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_EXTI_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32EXTIParentClass;
typedef PeripheralState STM32EXTIParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_EXTI_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32EXTIClass, (obj), TYPE_STM32_EXTI)
#define STM32_EXTI_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32EXTIClass, (klass), TYPE_STM32_EXTI)

typedef struct {
    // private: 
    STM32EXTIParentClass parent_class;
    // public: 

    // None, so far.
} STM32EXTIClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_EXTI_STATE(obj) \
    OBJECT_CHECK(STM32EXTIState, (obj), TYPE_STM32_EXTI)

typedef struct {
    // private:
    STM32EXTIParentState parent_obj;
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
        // F1 EXTI (EXTI) registers.
        struct { 
          Object *imr; // 0x0 (Interrupt mask register (EXTI_IMR)) 
          Object *emr; // 0x4 (Event mask register (EXTI_EMR)) 
          Object *rtsr; // 0x8 (Rising Trigger selection register (EXTI_RTSR)) 
          Object *ftsr; // 0xC (Falling Trigger selection register (EXTI_FTSR)) 
          Object *swier; // 0x10 (Software interrupt event register (EXTI_SWIER)) 
          Object *pr; // 0x14 (Pending register (EXTI_PR)) 
        } reg;

        struct { 
          
          // IMR (Interrupt mask register (EXTI_IMR)) bitfields.
          struct { 
            Object *mr0; // [0:0] Interrupt Mask on line 0 
            Object *mr1; // [1:1] Interrupt Mask on line 1 
            Object *mr2; // [2:2] Interrupt Mask on line 2 
            Object *mr3; // [3:3] Interrupt Mask on line 3 
            Object *mr4; // [4:4] Interrupt Mask on line 4 
            Object *mr5; // [5:5] Interrupt Mask on line 5 
            Object *mr6; // [6:6] Interrupt Mask on line 6 
            Object *mr7; // [7:7] Interrupt Mask on line 7 
            Object *mr8; // [8:8] Interrupt Mask on line 8 
            Object *mr9; // [9:9] Interrupt Mask on line 9 
            Object *mr10; // [10:10] Interrupt Mask on line 10 
            Object *mr11; // [11:11] Interrupt Mask on line 11 
            Object *mr12; // [12:12] Interrupt Mask on line 12 
            Object *mr13; // [13:13] Interrupt Mask on line 13 
            Object *mr14; // [14:14] Interrupt Mask on line 14 
            Object *mr15; // [15:15] Interrupt Mask on line 15 
            Object *mr16; // [16:16] Interrupt Mask on line 16 
            Object *mr17; // [17:17] Interrupt Mask on line 17 
            Object *mr18; // [18:18] Interrupt Mask on line 18  
          } imr; 
          
          // EMR (Event mask register (EXTI_EMR)) bitfields.
          struct { 
            Object *mr0; // [0:0] Event Mask on line 0 
            Object *mr1; // [1:1] Event Mask on line 1 
            Object *mr2; // [2:2] Event Mask on line 2 
            Object *mr3; // [3:3] Event Mask on line 3 
            Object *mr4; // [4:4] Event Mask on line 4 
            Object *mr5; // [5:5] Event Mask on line 5 
            Object *mr6; // [6:6] Event Mask on line 6 
            Object *mr7; // [7:7] Event Mask on line 7 
            Object *mr8; // [8:8] Event Mask on line 8 
            Object *mr9; // [9:9] Event Mask on line 9 
            Object *mr10; // [10:10] Event Mask on line 10 
            Object *mr11; // [11:11] Event Mask on line 11 
            Object *mr12; // [12:12] Event Mask on line 12 
            Object *mr13; // [13:13] Event Mask on line 13 
            Object *mr14; // [14:14] Event Mask on line 14 
            Object *mr15; // [15:15] Event Mask on line 15 
            Object *mr16; // [16:16] Event Mask on line 16 
            Object *mr17; // [17:17] Event Mask on line 17 
            Object *mr18; // [18:18] Event Mask on line 18  
          } emr; 
          
          // RTSR (Rising Trigger selection register (EXTI_RTSR)) bitfields.
          struct { 
            Object *tr0; // [0:0] Rising trigger event configuration of line 0 
            Object *tr1; // [1:1] Rising trigger event configuration of line 1 
            Object *tr2; // [2:2] Rising trigger event configuration of line 2 
            Object *tr3; // [3:3] Rising trigger event configuration of line 3 
            Object *tr4; // [4:4] Rising trigger event configuration of line 4 
            Object *tr5; // [5:5] Rising trigger event configuration of line 5 
            Object *tr6; // [6:6] Rising trigger event configuration of line 6 
            Object *tr7; // [7:7] Rising trigger event configuration of line 7 
            Object *tr8; // [8:8] Rising trigger event configuration of line 8 
            Object *tr9; // [9:9] Rising trigger event configuration of line 9 
            Object *tr10; // [10:10] Rising trigger event configuration of line 10 
            Object *tr11; // [11:11] Rising trigger event configuration of line 11 
            Object *tr12; // [12:12] Rising trigger event configuration of line 12 
            Object *tr13; // [13:13] Rising trigger event configuration of line 13 
            Object *tr14; // [14:14] Rising trigger event configuration of line 14 
            Object *tr15; // [15:15] Rising trigger event configuration of line 15 
            Object *tr16; // [16:16] Rising trigger event configuration of line 16 
            Object *tr17; // [17:17] Rising trigger event configuration of line 17 
            Object *tr18; // [18:18] Rising trigger event configuration of line 18  
          } rtsr; 
          
          // FTSR (Falling Trigger selection register (EXTI_FTSR)) bitfields.
          struct { 
            Object *tr0; // [0:0] Falling trigger event configuration of line 0 
            Object *tr1; // [1:1] Falling trigger event configuration of line 1 
            Object *tr2; // [2:2] Falling trigger event configuration of line 2 
            Object *tr3; // [3:3] Falling trigger event configuration of line 3 
            Object *tr4; // [4:4] Falling trigger event configuration of line 4 
            Object *tr5; // [5:5] Falling trigger event configuration of line 5 
            Object *tr6; // [6:6] Falling trigger event configuration of line 6 
            Object *tr7; // [7:7] Falling trigger event configuration of line 7 
            Object *tr8; // [8:8] Falling trigger event configuration of line 8 
            Object *tr9; // [9:9] Falling trigger event configuration of line 9 
            Object *tr10; // [10:10] Falling trigger event configuration of line 10 
            Object *tr11; // [11:11] Falling trigger event configuration of line 11 
            Object *tr12; // [12:12] Falling trigger event configuration of line 12 
            Object *tr13; // [13:13] Falling trigger event configuration of line 13 
            Object *tr14; // [14:14] Falling trigger event configuration of line 14 
            Object *tr15; // [15:15] Falling trigger event configuration of line 15 
            Object *tr16; // [16:16] Falling trigger event configuration of line 16 
            Object *tr17; // [17:17] Falling trigger event configuration of line 17 
            Object *tr18; // [18:18] Falling trigger event configuration of line 18  
          } ftsr; 
          
          // SWIER (Software interrupt event register (EXTI_SWIER)) bitfields.
          struct { 
            Object *swier0; // [0:0] Software Interrupt on line 0 
            Object *swier1; // [1:1] Software Interrupt on line 1 
            Object *swier2; // [2:2] Software Interrupt on line 2 
            Object *swier3; // [3:3] Software Interrupt on line 3 
            Object *swier4; // [4:4] Software Interrupt on line 4 
            Object *swier5; // [5:5] Software Interrupt on line 5 
            Object *swier6; // [6:6] Software Interrupt on line 6 
            Object *swier7; // [7:7] Software Interrupt on line 7 
            Object *swier8; // [8:8] Software Interrupt on line 8 
            Object *swier9; // [9:9] Software Interrupt on line 9 
            Object *swier10; // [10:10] Software Interrupt on line 10 
            Object *swier11; // [11:11] Software Interrupt on line 11 
            Object *swier12; // [12:12] Software Interrupt on line 12 
            Object *swier13; // [13:13] Software Interrupt on line 13 
            Object *swier14; // [14:14] Software Interrupt on line 14 
            Object *swier15; // [15:15] Software Interrupt on line 15 
            Object *swier16; // [16:16] Software Interrupt on line 16 
            Object *swier17; // [17:17] Software Interrupt on line 17 
            Object *swier18; // [18:18] Software Interrupt on line 18  
          } swier; 
          
          // PR (Pending register (EXTI_PR)) bitfields.
          struct { 
            Object *pr0; // [0:0] Pending bit 0 
            Object *pr1; // [1:1] Pending bit 1 
            Object *pr2; // [2:2] Pending bit 2 
            Object *pr3; // [3:3] Pending bit 3 
            Object *pr4; // [4:4] Pending bit 4 
            Object *pr5; // [5:5] Pending bit 5 
            Object *pr6; // [6:6] Pending bit 6 
            Object *pr7; // [7:7] Pending bit 7 
            Object *pr8; // [8:8] Pending bit 8 
            Object *pr9; // [9:9] Pending bit 9 
            Object *pr10; // [10:10] Pending bit 10 
            Object *pr11; // [11:11] Pending bit 11 
            Object *pr12; // [12:12] Pending bit 12 
            Object *pr13; // [13:13] Pending bit 13 
            Object *pr14; // [14:14] Pending bit 14 
            Object *pr15; // [15:15] Pending bit 15 
            Object *pr16; // [16:16] Pending bit 16 
            Object *pr17; // [17:17] Pending bit 17 
            Object *pr18; // [18:18] Pending bit 18  
          } pr; 
        } fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32EXTIState;

// ----------------------------------------------------------------------------

#endif /* STM32_EXTI_H_ */
