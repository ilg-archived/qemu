/*
 * STM32 - BKP (Backup registers) emulation.
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

#ifndef STM32_BKP_H_
#define STM32_BKP_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_BKP DEVICE_PATH_STM32 "BKP"



// ----------------------------------------------------------------------------

#define TYPE_STM32_BKP TYPE_STM32_PREFIX "bkp" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_BKP_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32BKPParentClass;
typedef PeripheralState STM32BKPParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_BKP_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32BKPClass, (obj), TYPE_STM32_BKP)
#define STM32_BKP_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32BKPClass, (klass), TYPE_STM32_BKP)

typedef struct {
    // private: 
    STM32BKPParentClass parent_class;
    // public: 

    // None, so far.
} STM32BKPClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_BKP_STATE(obj) \
    OBJECT_CHECK(STM32BKPState, (obj), TYPE_STM32_BKP)

typedef struct {
    // private:
    STM32BKPParentState parent_obj;
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
        // F1 BKP (Backup registers) registers.
        struct { 
          Object *dr1; // 0x0 (Backup data register (BKP_DR)) 
          Object *dr2; // 0x4 (Backup data register (BKP_DR)) 
          Object *dr3; // 0x8 (Backup data register (BKP_DR)) 
          Object *dr4; // 0xC (Backup data register (BKP_DR)) 
          Object *dr5; // 0x10 (Backup data register (BKP_DR)) 
          Object *dr6; // 0x14 (Backup data register (BKP_DR)) 
          Object *dr7; // 0x18 (Backup data register (BKP_DR)) 
          Object *dr8; // 0x1C (Backup data register (BKP_DR)) 
          Object *dr9; // 0x20 (Backup data register (BKP_DR)) 
          Object *dr10; // 0x24 (Backup data register (BKP_DR)) 
          Object *dr11; // 0x3C (Backup data register (BKP_DR)) 
          Object *dr12; // 0x40 (Backup data register (BKP_DR)) 
          Object *dr13; // 0x44 (Backup data register (BKP_DR)) 
          Object *dr14; // 0x48 (Backup data register (BKP_DR)) 
          Object *dr15; // 0x4C (Backup data register (BKP_DR)) 
          Object *dr16; // 0x50 (Backup data register (BKP_DR)) 
          Object *dr17; // 0x54 (Backup data register (BKP_DR)) 
          Object *dr18; // 0x58 (Backup data register (BKP_DR)) 
          Object *dr19; // 0x5C (Backup data register (BKP_DR)) 
          Object *dr20; // 0x60 (Backup data register (BKP_DR)) 
          Object *dr21; // 0x64 (Backup data register (BKP_DR)) 
          Object *dr22; // 0x68 (Backup data register (BKP_DR)) 
          Object *dr23; // 0x6C (Backup data register (BKP_DR)) 
          Object *dr24; // 0x70 (Backup data register (BKP_DR)) 
          Object *dr25; // 0x74 (Backup data register (BKP_DR)) 
          Object *dr26; // 0x78 (Backup data register (BKP_DR)) 
          Object *dr27; // 0x7C (Backup data register (BKP_DR)) 
          Object *dr28; // 0x80 (Backup data register (BKP_DR)) 
          Object *dr29; // 0x84 (Backup data register (BKP_DR)) 
          Object *dr30; // 0x88 (Backup data register (BKP_DR)) 
          Object *dr31; // 0x8C (Backup data register (BKP_DR)) 
          Object *dr32; // 0x90 (Backup data register (BKP_DR)) 
          Object *dr33; // 0x94 (Backup data register (BKP_DR)) 
          Object *dr34; // 0x98 (Backup data register (BKP_DR)) 
          Object *dr35; // 0x9C (Backup data register (BKP_DR)) 
          Object *dr36; // 0xA0 (Backup data register (BKP_DR)) 
          Object *dr37; // 0xA4 (Backup data register (BKP_DR)) 
          Object *dr38; // 0xA8 (Backup data register (BKP_DR)) 
          Object *dr39; // 0xAC (Backup data register (BKP_DR)) 
          Object *dr40; // 0xB0 (Backup data register (BKP_DR)) 
          Object *dr41; // 0xB4 (Backup data register (BKP_DR)) 
          Object *dr42; // 0xB8 (Backup data register (BKP_DR)) 
          Object *rtccr; // 0x28 (RTC clock calibration register (BKP_RTCCR)) 
          Object *cr; // 0x2C (Backup control register (BKP_CR)) 
          Object *csr; // 0x30 (BKP_CSR control/status register (BKP_CSR)) 
        } reg;

        struct { 
          
          // DR1 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d1; // [0:15] Backup data  
          } dr1; 
          
          // DR2 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d2; // [0:15] Backup data  
          } dr2; 
          
          // DR3 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d3; // [0:15] Backup data  
          } dr3; 
          
          // DR4 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d4; // [0:15] Backup data  
          } dr4; 
          
          // DR5 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d5; // [0:15] Backup data  
          } dr5; 
          
          // DR6 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d6; // [0:15] Backup data  
          } dr6; 
          
          // DR7 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d7; // [0:15] Backup data  
          } dr7; 
          
          // DR8 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d8; // [0:15] Backup data  
          } dr8; 
          
          // DR9 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d9; // [0:15] Backup data  
          } dr9; 
          
          // DR10 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d10; // [0:15] Backup data  
          } dr10; 
          
          // DR11 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *dr11; // [0:15] Backup data  
          } dr11; 
          
          // DR12 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *dr12; // [0:15] Backup data  
          } dr12; 
          
          // DR13 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *dr13; // [0:15] Backup data  
          } dr13; 
          
          // DR14 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d14; // [0:15] Backup data  
          } dr14; 
          
          // DR15 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d15; // [0:15] Backup data  
          } dr15; 
          
          // DR16 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d16; // [0:15] Backup data  
          } dr16; 
          
          // DR17 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d17; // [0:15] Backup data  
          } dr17; 
          
          // DR18 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d18; // [0:15] Backup data  
          } dr18; 
          
          // DR19 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d19; // [0:15] Backup data  
          } dr19; 
          
          // DR20 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d20; // [0:15] Backup data  
          } dr20; 
          
          // DR21 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d21; // [0:15] Backup data  
          } dr21; 
          
          // DR22 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d22; // [0:15] Backup data  
          } dr22; 
          
          // DR23 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d23; // [0:15] Backup data  
          } dr23; 
          
          // DR24 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d24; // [0:15] Backup data  
          } dr24; 
          
          // DR25 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d25; // [0:15] Backup data  
          } dr25; 
          
          // DR26 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d26; // [0:15] Backup data  
          } dr26; 
          
          // DR27 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d27; // [0:15] Backup data  
          } dr27; 
          
          // DR28 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d28; // [0:15] Backup data  
          } dr28; 
          
          // DR29 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d29; // [0:15] Backup data  
          } dr29; 
          
          // DR30 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d30; // [0:15] Backup data  
          } dr30; 
          
          // DR31 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d31; // [0:15] Backup data  
          } dr31; 
          
          // DR32 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d32; // [0:15] Backup data  
          } dr32; 
          
          // DR33 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d33; // [0:15] Backup data  
          } dr33; 
          
          // DR34 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d34; // [0:15] Backup data  
          } dr34; 
          
          // DR35 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d35; // [0:15] Backup data  
          } dr35; 
          
          // DR36 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d36; // [0:15] Backup data  
          } dr36; 
          
          // DR37 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d37; // [0:15] Backup data  
          } dr37; 
          
          // DR38 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d38; // [0:15] Backup data  
          } dr38; 
          
          // DR39 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d39; // [0:15] Backup data  
          } dr39; 
          
          // DR40 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d40; // [0:15] Backup data  
          } dr40; 
          
          // DR41 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d41; // [0:15] Backup data  
          } dr41; 
          
          // DR42 (Backup data register (BKP_DR)) bitfields.
          struct { 
            Object *d42; // [0:15] Backup data  
          } dr42; 
          
          // RTCCR (RTC clock calibration register (BKP_RTCCR)) bitfields.
          struct { 
            Object *cal; // [0:6] Calibration value 
            Object *cco; // [7:7] Calibration Clock Output 
            Object *asoe; // [8:8] Alarm or second output enable 
            Object *asos; // [9:9] Alarm or second output selection  
          } rtccr; 
          
          // CR (Backup control register (BKP_CR)) bitfields.
          struct { 
            Object *tpe; // [0:0] Tamper pin enable 
            Object *tpal; // [1:1] Tamper pin active level  
          } cr; 
          
          // CSR (BKP_CSR control/status register (BKP_CSR)) bitfields.
          struct { 
            Object *cte; // [0:0] Clear Tamper event 
            Object *cti; // [1:1] Clear Tamper Interrupt 
            Object *tpie; // [2:2] Tamper Pin interrupt enable 
            Object *tef; // [8:8] Tamper Event Flag 
            Object *tif; // [9:9] Tamper Interrupt Flag  
          } csr; 
        } fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32BKPState;

// ----------------------------------------------------------------------------

#endif /* STM32_BKP_H_ */
