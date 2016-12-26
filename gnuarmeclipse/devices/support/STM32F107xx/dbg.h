/*
 * STM32 - DBG (Debug support) emulation.
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

#ifndef STM32_DBG_H_
#define STM32_DBG_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_DBG DEVICE_PATH_STM32 "DBG"



// ----------------------------------------------------------------------------

#define TYPE_STM32_DBG TYPE_STM32_PREFIX "dbg" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_DBG_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32DBGParentClass;
typedef PeripheralState STM32DBGParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_DBG_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DBGClass, (obj), TYPE_STM32_DBG)
#define STM32_DBG_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32DBGClass, (klass), TYPE_STM32_DBG)

typedef struct {
    // private: 
    STM32DBGParentClass parent_class;
    // public: 

    // None, so far.
} STM32DBGClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_DBG_STATE(obj) \
    OBJECT_CHECK(STM32DBGState, (obj), TYPE_STM32_DBG)

typedef struct {
    // private:
    STM32DBGParentState parent_obj;
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
        // F1 DBG (Debug support) registers.
        struct { 
          Object *idcode; // 0x0 (DBGMCU_IDCODE) 
          Object *cr; // 0x4 (DBGMCU_CR) 
        } reg;

        struct { 
          
          // IDCODE (DBGMCU_IDCODE) bitfields.
          struct { 
            Object *dev_id; // [0:11] DEV_ID 
            Object *rev_id; // [16:31] REV_ID  
          } idcode; 
          
          // CR (DBGMCU_CR) bitfields.
          struct { 
            Object *dbg_sleep; // [0:0] DBG_SLEEP 
            Object *dbg_stop; // [1:1] DBG_STOP 
            Object *dbg_standby; // [2:2] DBG_STANDBY 
            Object *trace_ioen; // [5:5] TRACE_IOEN 
            Object *trace_mode; // [6:7] TRACE_MODE 
            Object *dbg_iwdg_stop; // [8:8] DBG_IWDG_STOP 
            Object *dbg_wwdg_stop; // [9:9] DBG_WWDG_STOP 
            Object *dbg_tim1_stop; // [10:10] DBG_TIM1_STOP 
            Object *dbg_tim2_stop; // [11:11] DBG_TIM2_STOP 
            Object *dbg_tim3_stop; // [12:12] DBG_TIM3_STOP 
            Object *dbg_tim4_stop; // [13:13] DBG_TIM4_STOP 
            Object *dbg_can1_stop; // [14:14] DBG_CAN1_STOP 
            Object *dbg_i2c1_smbus_timeout; // [15:15] DBG_I2C1_SMBUS_TIMEOUT 
            Object *dbg_i2c2_smbus_timeout; // [16:16] DBG_I2C2_SMBUS_TIMEOUT 
            Object *dbg_tim5_stop; // [18:18] DBG_TIM5_STOP 
            Object *dbg_tim6_stop; // [19:19] DBG_TIM6_STOP 
            Object *dbg_tim7_stop; // [20:20] DBG_TIM7_STOP 
            Object *dbg_can2_stop; // [21:21] DBG_CAN2_STOP  
          } cr; 
        } fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32DBGState;

// ----------------------------------------------------------------------------

#endif /* STM32_DBG_H_ */
