/*
 * STM32 - RTC (Real time clock) emulation.
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

#ifndef STM32_RTC_H_
#define STM32_RTC_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_RTC DEVICE_PATH_STM32 "RTC"



// ----------------------------------------------------------------------------

#define TYPE_STM32_RTC TYPE_STM32_PREFIX "rtc" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_RTC_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32RTCParentClass;
typedef PeripheralState STM32RTCParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_RTC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32RTCClass, (obj), TYPE_STM32_RTC)
#define STM32_RTC_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32RTCClass, (klass), TYPE_STM32_RTC)

typedef struct {
    // private: 
    STM32RTCParentClass parent_class;
    // public: 

    // None, so far.
} STM32RTCClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_RTC_STATE(obj) \
    OBJECT_CHECK(STM32RTCState, (obj), TYPE_STM32_RTC)

typedef struct {
    // private:
    STM32RTCParentState parent_obj;
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
        // F1 RTC (Real time clock) registers.
        struct { 
          Object *crh; // 0x0 (RTC Control Register High) 
          Object *crl; // 0x4 (RTC Control Register Low) 
          Object *prlh; // 0x8 (RTC Prescaler Load Register High) 
          Object *prll; // 0xC (RTC Prescaler Load Register Low) 
          Object *divh; // 0x10 (RTC Prescaler Divider Register High) 
          Object *divl; // 0x14 (RTC Prescaler Divider Register Low) 
          Object *cnth; // 0x18 (RTC Counter Register High) 
          Object *cntl; // 0x1C (RTC Counter Register Low) 
          Object *alrh; // 0x20 (RTC Alarm Register High) 
          Object *alrl; // 0x24 (RTC Alarm Register Low) 
        } reg;

        struct { 
          
          // CRH (RTC Control Register High) bitfields.
          struct { 
            Object *secie; // [0:0] Second interrupt Enable 
            Object *alrie; // [1:1] Alarm interrupt Enable 
            Object *owie; // [2:2] Overflow interrupt Enable  
          } crh; 
          
          // CRL (RTC Control Register Low) bitfields.
          struct { 
            Object *secf; // [0:0] Second Flag 
            Object *alrf; // [1:1] Alarm Flag 
            Object *owf; // [2:2] Overflow Flag 
            Object *rsf; // [3:3] Registers Synchronized Flag 
            Object *cnf; // [4:4] Configuration Flag 
            Object *rtoff; // [5:5] RTC operation OFF  
          } crl; 
          
          // PRLH (RTC Prescaler Load Register High) bitfields.
          struct { 
            Object *prlh; // [0:3] RTC Prescaler Load Register High  
          } prlh; 
          
          // PRLL (RTC Prescaler Load Register Low) bitfields.
          struct { 
            Object *prll; // [0:15] RTC Prescaler Divider Register Low  
          } prll; 
          
          // DIVH (RTC Prescaler Divider Register High) bitfields.
          struct { 
            Object *divh; // [0:3] RTC prescaler divider register high  
          } divh; 
          
          // DIVL (RTC Prescaler Divider Register Low) bitfields.
          struct { 
            Object *divl; // [0:15] RTC prescaler divider register Low  
          } divl; 
          
          // CNTH (RTC Counter Register High) bitfields.
          struct { 
            Object *cnth; // [0:15] RTC counter register high  
          } cnth; 
          
          // CNTL (RTC Counter Register Low) bitfields.
          struct { 
            Object *cntl; // [0:15] RTC counter register Low  
          } cntl; 
          
          // ALRH (RTC Alarm Register High) bitfields.
          struct { 
            Object *alrh; // [0:15] RTC alarm register high  
          } alrh; 
          
          // ALRL (RTC Alarm Register Low) bitfields.
          struct { 
            Object *alrl; // [0:15] RTC alarm register low  
          } alrl; 
        } fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32RTCState;

// ----------------------------------------------------------------------------

#endif /* STM32_RTC_H_ */
