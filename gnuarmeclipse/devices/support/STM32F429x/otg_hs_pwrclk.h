/*
 * STM32 - OTG_HS_PWRCLK (USB on the go high speed) emulation.
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

#ifndef STM32_OTG_HS_PWRCLK_H_
#define STM32_OTG_HS_PWRCLK_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_OTG_HS_PWRCLK DEVICE_PATH_STM32 "OTG_HS_PWRCLK"



// ----------------------------------------------------------------------------

#define TYPE_STM32_OTG_HS_PWRCLK TYPE_STM32_PREFIX "otg_hs_pwrclk" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_OTG_HS_PWRCLK_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32OTG_HS_PWRCLKParentClass;
typedef PeripheralState STM32OTG_HS_PWRCLKParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_OTG_HS_PWRCLK_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32OTG_HS_PWRCLKClass, (obj), TYPE_STM32_OTG_HS_PWRCLK)
#define STM32_OTG_HS_PWRCLK_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32OTG_HS_PWRCLKClass, (klass), TYPE_STM32_OTG_HS_PWRCLK)

typedef struct {
    // private: 
    STM32OTG_HS_PWRCLKParentClass parent_class;
    // public: 

    // None, so far.
} STM32OTG_HS_PWRCLKClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_OTG_HS_PWRCLK_STATE(obj) \
    OBJECT_CHECK(STM32OTG_HS_PWRCLKState, (obj), TYPE_STM32_OTG_HS_PWRCLK)

typedef struct {
    // private:
    STM32OTG_HS_PWRCLKParentState parent_obj;
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
        // F4 OTG_HS_PWRCLK (USB on the go high speed) registers.
        struct { 
          Object *otg_hs_pcgcr; // 0x0 (Power and clock gating control register) 
        } reg;

        struct { 
          
          // OTG_HS_PCGCR (Power and clock gating control register) bitfields.
          struct { 
            Object *stppclk; // [0:0] Stop PHY clock 
            Object *gatehclk; // [1:1] Gate HCLK 
            Object *physusp; // [4:4] PHY suspended  
          } otg_hs_pcgcr; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32OTG_HS_PWRCLKState;

// ----------------------------------------------------------------------------

#endif /* STM32_OTG_HS_PWRCLK_H_ */
