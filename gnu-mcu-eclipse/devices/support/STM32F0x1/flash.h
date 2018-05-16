/*
 * STM32 - Flash (Flash) emulation.
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

#ifndef STM32_Flash_H_
#define STM32_Flash_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_Flash DEVICE_PATH_STM32 "Flash"



// ----------------------------------------------------------------------------

#define TYPE_STM32_Flash TYPE_STM32_PREFIX "flash" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_Flash_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32FlashParentClass;
typedef PeripheralState STM32FlashParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_Flash_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32FlashClass, (obj), TYPE_STM32_Flash)
#define STM32_Flash_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32FlashClass, (klass), TYPE_STM32_Flash)

typedef struct {
    // private: 
    STM32FlashParentClass parent_class;
    // public: 

    // None, so far.
} STM32FlashClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_Flash_STATE(obj) \
    OBJECT_CHECK(STM32FlashState, (obj), TYPE_STM32_Flash)

typedef struct {
    // private:
    STM32FlashParentState parent_obj;
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
        // F0 Flash (Flash) registers.
        struct { 
          Object *acr; // 0x0 (Flash access control register) 
          Object *keyr; // 0x4 (Flash key register) 
          Object *optkeyr; // 0x8 (Flash option key register) 
          Object *sr; // 0xC (Flash status register) 
          Object *cr; // 0x10 (Flash control register) 
          Object *ar; // 0x14 (Flash address register) 
          Object *obr; // 0x1C (Option byte register) 
          Object *wrpr; // 0x20 (Write protection register) 
        } reg;

        struct { 
          
          // ACR (Flash access control register) bitfields.
          struct { 
            Object *latency; // [0:2] LATENCY 
            Object *prftbe; // [4:4] PRFTBE 
            Object *prftbs; // [5:5] PRFTBS  
          } acr; 
          
          // KEYR (Flash key register) bitfields.
          struct { 
            Object *fkeyr; // [0:31] Flash Key  
          } keyr; 
          
          // OPTKEYR (Flash option key register) bitfields.
          struct { 
            Object *optkeyr; // [0:31] Option byte key  
          } optkeyr; 
          
          // SR (Flash status register) bitfields.
          struct { 
            Object *bsy; // [0:0] Busy 
            Object *pgerr; // [2:2] Programming error 
            Object *wrprt; // [4:4] Write protection error 
            Object *eop; // [5:5] End of operation  
          } sr; 
          
          // CR (Flash control register) bitfields.
          struct { 
            Object *pg; // [0:0] Programming 
            Object *per; // [1:1] Page erase 
            Object *mer; // [2:2] Mass erase 
            Object *optpg; // [4:4] Option byte programming 
            Object *opter; // [5:5] Option byte erase 
            Object *strt; // [6:6] Start 
            Object *lock; // [7:7] Lock 
            Object *optwre; // [9:9] Option bytes write enable 
            Object *errie; // [10:10] Error interrupt enable 
            Object *eopie; // [12:12] End of operation interrupt enable 
            Object *force_optload; // [13:13] Force option byte loading  
          } cr; 
          
          // AR (Flash address register) bitfields.
          struct { 
            Object *far_; // [0:31] Flash address  
          } ar; 
          
          // OBR (Option byte register) bitfields.
          struct { 
            Object *opterr; // [0:0] Option byte error 
            Object *level1_prot; // [1:1] Level 1 protection status 
            Object *level2_prot; // [2:2] Level 2 protection status 
            Object *wdg_sw; // [8:8] WDG_SW 
            Object *nrst_stop; // [9:9] NRST_STOP 
            Object *nrst_stdby; // [10:10] NRST_STDBY 
            Object *boot1; // [12:12] BOOT1 
            Object *vdda_monitor; // [13:13] VDDA_MONITOR 
            Object *data0; // [16:23] Data0 
            Object *data1; // [24:31] Data1  
          } obr; 
          
          // WRPR (Write protection register) bitfields.
          struct { 
            Object *wrp; // [0:31] Write protect  
          } wrpr; 
        } fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32FlashState;

// ----------------------------------------------------------------------------

#endif /* STM32_Flash_H_ */
