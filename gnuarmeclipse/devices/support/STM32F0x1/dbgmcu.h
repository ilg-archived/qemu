/*
 * STM32 - DBGMCU (Debug support) emulation.
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

#ifndef STM32_DBGMCU_H_
#define STM32_DBGMCU_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_DBGMCU DEVICE_PATH_STM32 "DBGMCU"



// ----------------------------------------------------------------------------

#define TYPE_STM32_DBGMCU TYPE_STM32_PREFIX "dbgmcu" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_DBGMCU_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32DBGMCUParentClass;
typedef PeripheralState STM32DBGMCUParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_DBGMCU_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DBGMCUClass, (obj), TYPE_STM32_DBGMCU)
#define STM32_DBGMCU_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32DBGMCUClass, (klass), TYPE_STM32_DBGMCU)

typedef struct {
    // private: 
    STM32DBGMCUParentClass parent_class;
    // public: 

    // None, so far.
} STM32DBGMCUClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_DBGMCU_STATE(obj) \
    OBJECT_CHECK(STM32DBGMCUState, (obj), TYPE_STM32_DBGMCU)

typedef struct {
    // private:
    STM32DBGMCUParentState parent_obj;
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
        // F0 DBGMCU (Debug support) registers.
        struct { 
          Object *idcode; // 0x0 (MCU Device ID Code Register) 
          Object *cr; // 0x4 (Debug MCU Configuration Register) 
          Object *apblfz; // 0x8 (APB Low Freeze Register) 
          Object *apbhfz; // 0xC (APB High Freeze Register) 
        } reg;

        struct { 
          
          // IDCODE (MCU Device ID Code Register) bitfields.
          struct { 
            Object *dev_id; // [0:11] Device Identifier 
            Object *div_id; // [12:15] Division Identifier 
            Object *rev_id; // [16:31] Revision Identifier  
          } idcode; 
          
          // CR (Debug MCU Configuration Register) bitfields.
          struct { 
            Object *dbg_stop; // [1:1] Debug Stop Mode 
            Object *dbg_standby; // [2:2] Debug Standby Mode  
          } cr; 
          
          // APBLFZ (APB Low Freeze Register) bitfields.
          struct { 
            Object *dbg_timer2_stop; // [0:0] Debug Timer 2 stopped when Core is halted 
            Object *dbg_timer3_stop; // [1:1] Debug Timer 3 stopped when Core is halted 
            Object *dbg_timer6_stop; // [4:4] Debug Timer 6 stopped when Core is halted 
            Object *dbg_timer14_stop; // [8:8] Debug Timer 14 stopped when Core is halted 
            Object *dbg_rtc_stop; // [10:10] Debug RTC stopped when Core is halted 
            Object *dbg_wwdg_stop; // [11:11] Debug Window Wachdog stopped when Core is halted 
            Object *dbg_iwdg_stop; // [12:12] Debug Independent Wachdog stopped when Core is halted 
            Object *i2c1_smbus_timeout; // [21:21] SMBUS timeout mode stopped when Core is halted  
          } apblfz; 
          
          // APBHFZ (APB High Freeze Register) bitfields.
          struct { 
            Object *dbg_timer1_stop; // [11:11] Debug Timer 1 stopped when Core is halted 
            Object *dbg_timer15_sto; // [16:16] Debug Timer 15 stopped when Core is halted 
            Object *dbg_timer16_sto; // [17:17] Debug Timer 16 stopped when Core is halted 
            Object *dbg_timer17_sto; // [18:18] Debug Timer 17 stopped when Core is halted  
          } apbhfz; 
        } fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32DBGMCUState;

// ----------------------------------------------------------------------------

#endif /* STM32_DBGMCU_H_ */
