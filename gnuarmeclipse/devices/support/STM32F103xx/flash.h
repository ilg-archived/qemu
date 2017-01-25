/*
 * STM32 - FLASH (FLASH) emulation.
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

#ifndef STM32_FLASH_H_
#define STM32_FLASH_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_FLASH DEVICE_PATH_STM32 "FLASH"



// ----------------------------------------------------------------------------

#define TYPE_STM32_FLASH TYPE_STM32_PREFIX "flash" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_FLASH_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32FLASHParentClass;
typedef PeripheralState STM32FLASHParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_FLASH_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32FLASHClass, (obj), TYPE_STM32_FLASH)
#define STM32_FLASH_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32FLASHClass, (klass), TYPE_STM32_FLASH)

typedef struct {
    // private: 
    STM32FLASHParentClass parent_class;
    // public: 

    // None, so far.
} STM32FLASHClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_FLASH_STATE(obj) \
    OBJECT_CHECK(STM32FLASHState, (obj), TYPE_STM32_FLASH)

typedef struct {
    // private:
    STM32FLASHParentState parent_obj;
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
        // F1 FLASH (FLASH) registers.
        struct { 
          Object *acr; // 0x0 (Flash access control register) 
          Object *keyr; // 0x4 (Flash key register) 
          Object *optkeyr; // 0x8 (Flash option key register) 
          Object *sr; // 0xC (Status register) 
          Object *cr; // 0x10 (Control register) 
          Object *ar; // 0x14 (Flash address register) 
          Object *obr; // 0x1C (Option byte register) 
          Object *wrpr; // 0x20 (Write protection register) 
        } reg;

        struct { 
          
          // ACR (Flash access control register) bitfields.
          struct { 
            Object *latency; // [0:2] Latency 
            Object *hlfcya; // [3:3] Flash half cycle access enable 
            Object *prftbe; // [4:4] Prefetch buffer enable 
            Object *prftbs; // [5:5] Prefetch buffer status  
          } acr; 
          
          // KEYR (Flash key register) bitfields.
          struct { 
            Object *key; // [0:31] FPEC key  
          } keyr; 
          
          // OPTKEYR (Flash option key register) bitfields.
          struct { 
            Object *optkey; // [0:31] Option byte key  
          } optkeyr; 
          
          // SR (Status register) bitfields.
          struct { 
            Object *bsy; // [0:0] Busy 
            Object *pgerr; // [2:2] Programming error 
            Object *wrprterr; // [4:4] Write protection error 
            Object *eop; // [5:5] End of operation  
          } sr; 
          
          // CR (Control register) bitfields.
          struct { 
            Object *pg; // [0:0] Programming 
            Object *per; // [1:1] Page Erase 
            Object *mer; // [2:2] Mass Erase 
            Object *optpg; // [4:4] Option byte programming 
            Object *opter; // [5:5] Option byte erase 
            Object *strt; // [6:6] Start 
            Object *lock; // [7:7] Lock 
            Object *optwre; // [9:9] Option bytes write enable 
            Object *errie; // [10:10] Error interrupt enable 
            Object *eopie; // [12:12] End of operation interrupt enable  
          } cr; 
          
          // AR (Flash address register) bitfields.
          struct { 
            Object *far_; // [0:31] Flash Address  
          } ar; 
          
          // OBR (Option byte register) bitfields.
          struct { 
            Object *opterr; // [0:0] Option byte error 
            Object *rdprt; // [1:1] Read protection 
            Object *wdg_sw; // [2:2] WDG_SW 
            Object *nrst_stop; // [3:3] NRST_STOP 
            Object *nrst_stdby; // [4:4] NRST_STDBY 
            Object *data0; // [10:17] Data0 
            Object *data1; // [18:25] Data1  
          } obr; 
          
          // WRPR (Write protection register) bitfields.
          struct { 
            Object *wrp; // [0:31] Write protect  
          } wrpr; 
        } fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32FLASHState;

// ----------------------------------------------------------------------------

#endif /* STM32_FLASH_H_ */
