/*
 * STM32 - NVIC (Nested Vectored Interrupt Controller) emulation.
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

#ifndef STM32_NVIC_H_
#define STM32_NVIC_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_NVIC DEVICE_PATH_STM32 "NVIC"



// ----------------------------------------------------------------------------

#define TYPE_STM32_NVIC TYPE_STM32_PREFIX "nvic" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_NVIC_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32NVICParentClass;
typedef PeripheralState STM32NVICParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_NVIC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32NVICClass, (obj), TYPE_STM32_NVIC)
#define STM32_NVIC_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32NVICClass, (klass), TYPE_STM32_NVIC)

typedef struct {
    // private: 
    STM32NVICParentClass parent_class;
    // public: 

    // None, so far.
} STM32NVICClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_NVIC_STATE(obj) \
    OBJECT_CHECK(STM32NVICState, (obj), TYPE_STM32_NVIC)

typedef struct {
    // private:
    STM32NVICParentState parent_obj;
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
        // F4 NVIC (Nested Vectored Interrupt Controller) registers.
        struct { 
          Object *ictr; // 0x4 (Interrupt Controller Type Register) 
          Object *stir; // 0xF00 (Software Triggered Interrupt Register) 
          Object *iser0; // 0x100 (Interrupt Set-Enable Register) 
          Object *iser1; // 0x104 (Interrupt Set-Enable Register) 
          Object *iser2; // 0x108 (Interrupt Set-Enable Register) 
          Object *icer0; // 0x180 (Interrupt Clear-Enable Register) 
          Object *icer1; // 0x184 (Interrupt Clear-Enable Register) 
          Object *icer2; // 0x188 (Interrupt Clear-Enable Register) 
          Object *ispr0; // 0x200 (Interrupt Set-Pending Register) 
          Object *ispr1; // 0x204 (Interrupt Set-Pending Register) 
          Object *ispr2; // 0x208 (Interrupt Set-Pending Register) 
          Object *icpr0; // 0x280 (Interrupt Clear-Pending Register) 
          Object *icpr1; // 0x284 (Interrupt Clear-Pending Register) 
          Object *icpr2; // 0x288 (Interrupt Clear-Pending Register) 
          Object *iabr0; // 0x300 (Interrupt Active Bit Register) 
          Object *iabr1; // 0x304 (Interrupt Active Bit Register) 
          Object *iabr2; // 0x308 (Interrupt Active Bit Register) 
          Object *ipr0; // 0x400 (Interrupt Priority Register) 
          Object *ipr1; // 0x404 (Interrupt Priority Register) 
          Object *ipr2; // 0x408 (Interrupt Priority Register) 
          Object *ipr3; // 0x40C (Interrupt Priority Register) 
          Object *ipr4; // 0x410 (Interrupt Priority Register) 
          Object *ipr5; // 0x414 (Interrupt Priority Register) 
          Object *ipr6; // 0x418 (Interrupt Priority Register) 
          Object *ipr7; // 0x41C (Interrupt Priority Register) 
          Object *ipr8; // 0x420 (Interrupt Priority Register) 
          Object *ipr9; // 0x424 (Interrupt Priority Register) 
          Object *ipr10; // 0x428 (Interrupt Priority Register) 
          Object *ipr11; // 0x42C (Interrupt Priority Register) 
          Object *ipr12; // 0x430 (Interrupt Priority Register) 
          Object *ipr13; // 0x434 (Interrupt Priority Register) 
          Object *ipr14; // 0x438 (Interrupt Priority Register) 
          Object *ipr15; // 0x43C (Interrupt Priority Register) 
          Object *ipr16; // 0x440 (Interrupt Priority Register) 
          Object *ipr17; // 0x444 (Interrupt Priority Register) 
          Object *ipr18; // 0x448 (Interrupt Priority Register) 
          Object *ipr19; // 0x44C (Interrupt Priority Register) 
          Object *ipr20; // 0x450 (Interrupt Priority Register) 
        } reg;

        struct { 
          
          // ICTR (Interrupt Controller Type Register) bitfields.
          struct { 
            Object *intlinesnum; // [0:3] Total number of interrupt lines in groups  
          } ictr; 
          
          // STIR (Software Triggered Interrupt Register) bitfields.
          struct { 
            Object *intid; // [0:8] Interrupt to be triggered  
          } stir; 
          
          // ISER0 (Interrupt Set-Enable Register) bitfields.
          struct { 
            Object *setena; // [0:31] SETENA  
          } iser0; 
          
          // ISER1 (Interrupt Set-Enable Register) bitfields.
          struct { 
            Object *setena; // [0:31] SETENA  
          } iser1; 
          
          // ISER2 (Interrupt Set-Enable Register) bitfields.
          struct { 
            Object *setena; // [0:31] SETENA  
          } iser2; 
          
          // ICER0 (Interrupt Clear-Enable Register) bitfields.
          struct { 
            Object *clrena; // [0:31] CLRENA  
          } icer0; 
          
          // ICER1 (Interrupt Clear-Enable Register) bitfields.
          struct { 
            Object *clrena; // [0:31] CLRENA  
          } icer1; 
          
          // ICER2 (Interrupt Clear-Enable Register) bitfields.
          struct { 
            Object *clrena; // [0:31] CLRENA  
          } icer2; 
          
          // ISPR0 (Interrupt Set-Pending Register) bitfields.
          struct { 
            Object *setpend; // [0:31] SETPEND  
          } ispr0; 
          
          // ISPR1 (Interrupt Set-Pending Register) bitfields.
          struct { 
            Object *setpend; // [0:31] SETPEND  
          } ispr1; 
          
          // ISPR2 (Interrupt Set-Pending Register) bitfields.
          struct { 
            Object *setpend; // [0:31] SETPEND  
          } ispr2; 
          
          // ICPR0 (Interrupt Clear-Pending Register) bitfields.
          struct { 
            Object *clrpend; // [0:31] CLRPEND  
          } icpr0; 
          
          // ICPR1 (Interrupt Clear-Pending Register) bitfields.
          struct { 
            Object *clrpend; // [0:31] CLRPEND  
          } icpr1; 
          
          // ICPR2 (Interrupt Clear-Pending Register) bitfields.
          struct { 
            Object *clrpend; // [0:31] CLRPEND  
          } icpr2; 
          
          // IABR0 (Interrupt Active Bit Register) bitfields.
          struct { 
            Object *active; // [0:31] ACTIVE  
          } iabr0; 
          
          // IABR1 (Interrupt Active Bit Register) bitfields.
          struct { 
            Object *active; // [0:31] ACTIVE  
          } iabr1; 
          
          // IABR2 (Interrupt Active Bit Register) bitfields.
          struct { 
            Object *active; // [0:31] ACTIVE  
          } iabr2; 
          
          // IPR0 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr0; 
          
          // IPR1 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr1; 
          
          // IPR2 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr2; 
          
          // IPR3 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr3; 
          
          // IPR4 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr4; 
          
          // IPR5 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr5; 
          
          // IPR6 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr6; 
          
          // IPR7 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr7; 
          
          // IPR8 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr8; 
          
          // IPR9 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr9; 
          
          // IPR10 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr10; 
          
          // IPR11 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr11; 
          
          // IPR12 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr12; 
          
          // IPR13 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr13; 
          
          // IPR14 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr14; 
          
          // IPR15 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr15; 
          
          // IPR16 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr16; 
          
          // IPR17 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr17; 
          
          // IPR18 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr18; 
          
          // IPR19 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr19; 
          
          // IPR20 (Interrupt Priority Register) bitfields.
          struct { 
            Object *ipr_n0; // [0:7] IPR_N0 
            Object *ipr_n1; // [8:15] IPR_N1 
            Object *ipr_n2; // [16:23] IPR_N2 
            Object *ipr_n3; // [24:31] IPR_N3  
          } ipr20; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32NVICState;

// ----------------------------------------------------------------------------

#endif /* STM32_NVIC_H_ */
