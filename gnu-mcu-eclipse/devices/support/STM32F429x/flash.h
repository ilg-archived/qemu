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
        // F4 FLASH (FLASH) registers.
        struct { 
          Object *acr; // 0x0 (Flash access control register) 
          Object *keyr; // 0x4 (Flash key register) 
          Object *optkeyr; // 0x8 (Flash option key register) 
          Object *sr; // 0xC (Status register) 
          Object *cr; // 0x10 (Control register) 
          Object *optcr; // 0x14 (Flash option control register) 
          Object *optcr1; // 0x18 (Flash option control register 1) 
        } reg;

        struct { 
          
          // ACR (Flash access control register) bitfields.
          struct { 
            Object *latency; // [0:2] Latency 
            Object *prften; // [8:8] Prefetch enable 
            Object *icen; // [9:9] Instruction cache enable 
            Object *dcen; // [10:10] Data cache enable 
            Object *icrst; // [11:11] Instruction cache reset 
            Object *dcrst; // [12:12] Data cache reset  
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
            Object *eop; // [0:0] End of operation 
            Object *operr; // [1:1] Operation error 
            Object *wrperr; // [4:4] Write protection error 
            Object *pgaerr; // [5:5] Programming alignment error 
            Object *pgperr; // [6:6] Programming parallelism error 
            Object *pgserr; // [7:7] Programming sequence error 
            Object *bsy; // [16:16] Busy  
          } sr; 
          
          // CR (Control register) bitfields.
          struct { 
            Object *pg; // [0:0] Programming 
            Object *ser; // [1:1] Sector Erase 
            Object *mer; // [2:2] Mass Erase of sectors 0 to 11 
            Object *snb; // [3:7] Sector number 
            Object *psize; // [8:9] Program size 
            Object *mer1; // [15:15] Mass Erase of sectors 12 to 23 
            Object *strt; // [16:16] Start 
            Object *eopie; // [24:24] End of operation interrupt enable 
            Object *errie; // [25:25] Error interrupt enable 
            Object *lock; // [31:31] Lock  
          } cr; 
          
          // OPTCR (Flash option control register) bitfields.
          struct { 
            Object *optlock; // [0:0] Option lock 
            Object *optstrt; // [1:1] Option start 
            Object *bor_lev; // [2:3] BOR reset Level 
            Object *wdg_sw; // [5:5] WDG_SW User option bytes 
            Object *nrst_stop; // [6:6] NRST_STOP User option bytes 
            Object *nrst_stdby; // [7:7] NRST_STDBY User option bytes 
            Object *rdp; // [8:15] Read protect 
            Object *nwrp; // [16:27] Not write protect  
          } optcr; 
          
          // OPTCR1 (Flash option control register 1) bitfields.
          struct { 
            Object *nwrp; // [16:27] Not write protect  
          } optcr1; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32FLASHState;

// ----------------------------------------------------------------------------

#endif /* STM32_FLASH_H_ */
