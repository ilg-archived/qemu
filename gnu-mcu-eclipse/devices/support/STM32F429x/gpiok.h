/*
 * STM32 - GPIO (General-purpose I/Os) emulation.
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

#ifndef STM32_GPIO_H_
#define STM32_GPIO_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_GPIO DEVICE_PATH_STM32 "GPIO"

// ----------------------------------------------------------------------------

// Note: the "port-index" property has type "int".
typedef enum {
    // TODO: keep this list in ascending order.
    STM32_PORT_GPIOA,
    STM32_PORT_GPIOB,
    STM32_PORT_GPIOC,
    STM32_PORT_GPIOD,
    STM32_PORT_GPIOE,
    STM32_PORT_GPIOF,
    STM32_PORT_GPIOG,
    STM32_PORT_GPIOH,
    STM32_PORT_GPIOI,
    STM32_PORT_GPIOJ,
    STM32_PORT_GPIOK,
    STM32_PORT_GPIO_UNDEFINED = 0xFF,
} stm32_gpio_index_t;

// ----------------------------------------------------------------------------

#define TYPE_STM32_GPIO TYPE_STM32_PREFIX "gpio" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_GPIO_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32GPIOParentClass;
typedef PeripheralState STM32GPIOParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_GPIO_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32GPIOClass, (obj), TYPE_STM32_GPIO)
#define STM32_GPIO_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32GPIOClass, (klass), TYPE_STM32_GPIO)

typedef struct {
    // private: 
    STM32GPIOParentClass parent_class;
    // public: 

    // None, so far.
} STM32GPIOClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_GPIO_STATE(obj) \
    OBJECT_CHECK(STM32GPIOState, (obj), TYPE_STM32_GPIO)

typedef struct {
    // private:
    STM32GPIOParentState parent_obj;
    // public:

    const STM32Capabilities *capabilities;

    // TODO: remove this if the peripheral is always enabled.
    // Points to the bitfield that enables the peripheral.
    Object *enabling_bit;

    // Remove it if there is only one port
    stm32_gpio_index_t port_index;

    union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // F4 GPIO (General-purpose I/Os) registers.
        struct { 
          Object *moder; // 0x0 (GPIO port mode register) 
          Object *otyper; // 0x4 (GPIO port output type register) 
          Object *ospeedr; // 0x8 (GPIO port output speed register) 
          Object *pupdr; // 0xC (GPIO port pull-up/pull-down register) 
          Object *idr; // 0x10 (GPIO port input data register) 
          Object *odr; // 0x14 (GPIO port output data register) 
          Object *bsrr; // 0x18 (GPIO port bit set/reset register) 
          Object *lckr; // 0x1C (GPIO port configuration lock register) 
          Object *afrl; // 0x20 (GPIO alternate function low register) 
          Object *afrh; // 0x24 (GPIO alternate function high register) 
        } reg;

        struct { 
          
          // MODER (GPIO port mode register) bitfields.
          struct { 
            Object *moder0; // [0:1] Port x configuration bits (y = 0..15) 
            Object *moder1; // [2:3] Port x configuration bits (y = 0..15) 
            Object *moder2; // [4:5] Port x configuration bits (y = 0..15) 
            Object *moder3; // [6:7] Port x configuration bits (y = 0..15) 
            Object *moder4; // [8:9] Port x configuration bits (y = 0..15) 
            Object *moder5; // [10:11] Port x configuration bits (y = 0..15) 
            Object *moder6; // [12:13] Port x configuration bits (y = 0..15) 
            Object *moder7; // [14:15] Port x configuration bits (y = 0..15) 
            Object *moder8; // [16:17] Port x configuration bits (y = 0..15) 
            Object *moder9; // [18:19] Port x configuration bits (y = 0..15) 
            Object *moder10; // [20:21] Port x configuration bits (y = 0..15) 
            Object *moder11; // [22:23] Port x configuration bits (y = 0..15) 
            Object *moder12; // [24:25] Port x configuration bits (y = 0..15) 
            Object *moder13; // [26:27] Port x configuration bits (y = 0..15) 
            Object *moder14; // [28:29] Port x configuration bits (y = 0..15) 
            Object *moder15; // [30:31] Port x configuration bits (y = 0..15)  
          } moder; 
          
          // OTYPER (GPIO port output type register) bitfields.
          struct { 
            Object *ot0; // [0:0] Port x configuration bits (y = 0..15) 
            Object *ot1; // [1:1] Port x configuration bits (y = 0..15) 
            Object *ot2; // [2:2] Port x configuration bits (y = 0..15) 
            Object *ot3; // [3:3] Port x configuration bits (y = 0..15) 
            Object *ot4; // [4:4] Port x configuration bits (y = 0..15) 
            Object *ot5; // [5:5] Port x configuration bits (y = 0..15) 
            Object *ot6; // [6:6] Port x configuration bits (y = 0..15) 
            Object *ot7; // [7:7] Port x configuration bits (y = 0..15) 
            Object *ot8; // [8:8] Port x configuration bits (y = 0..15) 
            Object *ot9; // [9:9] Port x configuration bits (y = 0..15) 
            Object *ot10; // [10:10] Port x configuration bits (y = 0..15) 
            Object *ot11; // [11:11] Port x configuration bits (y = 0..15) 
            Object *ot12; // [12:12] Port x configuration bits (y = 0..15) 
            Object *ot13; // [13:13] Port x configuration bits (y = 0..15) 
            Object *ot14; // [14:14] Port x configuration bits (y = 0..15) 
            Object *ot15; // [15:15] Port x configuration bits (y = 0..15)  
          } otyper; 
          
          // OSPEEDR (GPIO port output speed register) bitfields.
          struct { 
            Object *ospeedr0; // [0:1] Port x configuration bits (y = 0..15) 
            Object *ospeedr1; // [2:3] Port x configuration bits (y = 0..15) 
            Object *ospeedr2; // [4:5] Port x configuration bits (y = 0..15) 
            Object *ospeedr3; // [6:7] Port x configuration bits (y = 0..15) 
            Object *ospeedr4; // [8:9] Port x configuration bits (y = 0..15) 
            Object *ospeedr5; // [10:11] Port x configuration bits (y = 0..15) 
            Object *ospeedr6; // [12:13] Port x configuration bits (y = 0..15) 
            Object *ospeedr7; // [14:15] Port x configuration bits (y = 0..15) 
            Object *ospeedr8; // [16:17] Port x configuration bits (y = 0..15) 
            Object *ospeedr9; // [18:19] Port x configuration bits (y = 0..15) 
            Object *ospeedr10; // [20:21] Port x configuration bits (y = 0..15) 
            Object *ospeedr11; // [22:23] Port x configuration bits (y = 0..15) 
            Object *ospeedr12; // [24:25] Port x configuration bits (y = 0..15) 
            Object *ospeedr13; // [26:27] Port x configuration bits (y = 0..15) 
            Object *ospeedr14; // [28:29] Port x configuration bits (y = 0..15) 
            Object *ospeedr15; // [30:31] Port x configuration bits (y = 0..15)  
          } ospeedr; 
          
          // PUPDR (GPIO port pull-up/pull-down register) bitfields.
          struct { 
            Object *pupdr0; // [0:1] Port x configuration bits (y = 0..15) 
            Object *pupdr1; // [2:3] Port x configuration bits (y = 0..15) 
            Object *pupdr2; // [4:5] Port x configuration bits (y = 0..15) 
            Object *pupdr3; // [6:7] Port x configuration bits (y = 0..15) 
            Object *pupdr4; // [8:9] Port x configuration bits (y = 0..15) 
            Object *pupdr5; // [10:11] Port x configuration bits (y = 0..15) 
            Object *pupdr6; // [12:13] Port x configuration bits (y = 0..15) 
            Object *pupdr7; // [14:15] Port x configuration bits (y = 0..15) 
            Object *pupdr8; // [16:17] Port x configuration bits (y = 0..15) 
            Object *pupdr9; // [18:19] Port x configuration bits (y = 0..15) 
            Object *pupdr10; // [20:21] Port x configuration bits (y = 0..15) 
            Object *pupdr11; // [22:23] Port x configuration bits (y = 0..15) 
            Object *pupdr12; // [24:25] Port x configuration bits (y = 0..15) 
            Object *pupdr13; // [26:27] Port x configuration bits (y = 0..15) 
            Object *pupdr14; // [28:29] Port x configuration bits (y = 0..15) 
            Object *pupdr15; // [30:31] Port x configuration bits (y = 0..15)  
          } pupdr; 
          
          // IDR (GPIO port input data register) bitfields.
          struct { 
            Object *idr0; // [0:0] Port input data (y = 0..15) 
            Object *idr1; // [1:1] Port input data (y = 0..15) 
            Object *idr2; // [2:2] Port input data (y = 0..15) 
            Object *idr3; // [3:3] Port input data (y = 0..15) 
            Object *idr4; // [4:4] Port input data (y = 0..15) 
            Object *idr5; // [5:5] Port input data (y = 0..15) 
            Object *idr6; // [6:6] Port input data (y = 0..15) 
            Object *idr7; // [7:7] Port input data (y = 0..15) 
            Object *idr8; // [8:8] Port input data (y = 0..15) 
            Object *idr9; // [9:9] Port input data (y = 0..15) 
            Object *idr10; // [10:10] Port input data (y = 0..15) 
            Object *idr11; // [11:11] Port input data (y = 0..15) 
            Object *idr12; // [12:12] Port input data (y = 0..15) 
            Object *idr13; // [13:13] Port input data (y = 0..15) 
            Object *idr14; // [14:14] Port input data (y = 0..15) 
            Object *idr15; // [15:15] Port input data (y = 0..15)  
          } idr; 
          
          // ODR (GPIO port output data register) bitfields.
          struct { 
            Object *odr0; // [0:0] Port output data (y = 0..15) 
            Object *odr1; // [1:1] Port output data (y = 0..15) 
            Object *odr2; // [2:2] Port output data (y = 0..15) 
            Object *odr3; // [3:3] Port output data (y = 0..15) 
            Object *odr4; // [4:4] Port output data (y = 0..15) 
            Object *odr5; // [5:5] Port output data (y = 0..15) 
            Object *odr6; // [6:6] Port output data (y = 0..15) 
            Object *odr7; // [7:7] Port output data (y = 0..15) 
            Object *odr8; // [8:8] Port output data (y = 0..15) 
            Object *odr9; // [9:9] Port output data (y = 0..15) 
            Object *odr10; // [10:10] Port output data (y = 0..15) 
            Object *odr11; // [11:11] Port output data (y = 0..15) 
            Object *odr12; // [12:12] Port output data (y = 0..15) 
            Object *odr13; // [13:13] Port output data (y = 0..15) 
            Object *odr14; // [14:14] Port output data (y = 0..15) 
            Object *odr15; // [15:15] Port output data (y = 0..15)  
          } odr; 
          
          // BSRR (GPIO port bit set/reset register) bitfields.
          struct { 
            Object *bs0; // [0:0] Port x set bit y (y= 0..15) 
            Object *bs1; // [1:1] Port x set bit y (y= 0..15) 
            Object *bs2; // [2:2] Port x set bit y (y= 0..15) 
            Object *bs3; // [3:3] Port x set bit y (y= 0..15) 
            Object *bs4; // [4:4] Port x set bit y (y= 0..15) 
            Object *bs5; // [5:5] Port x set bit y (y= 0..15) 
            Object *bs6; // [6:6] Port x set bit y (y= 0..15) 
            Object *bs7; // [7:7] Port x set bit y (y= 0..15) 
            Object *bs8; // [8:8] Port x set bit y (y= 0..15) 
            Object *bs9; // [9:9] Port x set bit y (y= 0..15) 
            Object *bs10; // [10:10] Port x set bit y (y= 0..15) 
            Object *bs11; // [11:11] Port x set bit y (y= 0..15) 
            Object *bs12; // [12:12] Port x set bit y (y= 0..15) 
            Object *bs13; // [13:13] Port x set bit y (y= 0..15) 
            Object *bs14; // [14:14] Port x set bit y (y= 0..15) 
            Object *bs15; // [15:15] Port x set bit y (y= 0..15) 
            Object *br0; // [16:16] Port x set bit y (y= 0..15) 
            Object *br1; // [17:17] Port x reset bit y (y = 0..15) 
            Object *br2; // [18:18] Port x reset bit y (y = 0..15) 
            Object *br3; // [19:19] Port x reset bit y (y = 0..15) 
            Object *br4; // [20:20] Port x reset bit y (y = 0..15) 
            Object *br5; // [21:21] Port x reset bit y (y = 0..15) 
            Object *br6; // [22:22] Port x reset bit y (y = 0..15) 
            Object *br7; // [23:23] Port x reset bit y (y = 0..15) 
            Object *br8; // [24:24] Port x reset bit y (y = 0..15) 
            Object *br9; // [25:25] Port x reset bit y (y = 0..15) 
            Object *br10; // [26:26] Port x reset bit y (y = 0..15) 
            Object *br11; // [27:27] Port x reset bit y (y = 0..15) 
            Object *br12; // [28:28] Port x reset bit y (y = 0..15) 
            Object *br13; // [29:29] Port x reset bit y (y = 0..15) 
            Object *br14; // [30:30] Port x reset bit y (y = 0..15) 
            Object *br15; // [31:31] Port x reset bit y (y = 0..15)  
          } bsrr; 
          
          // LCKR (GPIO port configuration lock register) bitfields.
          struct { 
            Object *lck0; // [0:0] Port x lock bit y (y= 0..15) 
            Object *lck1; // [1:1] Port x lock bit y (y= 0..15) 
            Object *lck2; // [2:2] Port x lock bit y (y= 0..15) 
            Object *lck3; // [3:3] Port x lock bit y (y= 0..15) 
            Object *lck4; // [4:4] Port x lock bit y (y= 0..15) 
            Object *lck5; // [5:5] Port x lock bit y (y= 0..15) 
            Object *lck6; // [6:6] Port x lock bit y (y= 0..15) 
            Object *lck7; // [7:7] Port x lock bit y (y= 0..15) 
            Object *lck8; // [8:8] Port x lock bit y (y= 0..15) 
            Object *lck9; // [9:9] Port x lock bit y (y= 0..15) 
            Object *lck10; // [10:10] Port x lock bit y (y= 0..15) 
            Object *lck11; // [11:11] Port x lock bit y (y= 0..15) 
            Object *lck12; // [12:12] Port x lock bit y (y= 0..15) 
            Object *lck13; // [13:13] Port x lock bit y (y= 0..15) 
            Object *lck14; // [14:14] Port x lock bit y (y= 0..15) 
            Object *lck15; // [15:15] Port x lock bit y (y= 0..15) 
            Object *lckk; // [16:16] Port x lock bit y (y= 0..15)  
          } lckr; 
          
          // AFRL (GPIO alternate function low register) bitfields.
          struct { 
            Object *afrl0; // [0:3] Alternate function selection for port x bit y (y = 0..7) 
            Object *afrl1; // [4:7] Alternate function selection for port x bit y (y = 0..7) 
            Object *afrl2; // [8:11] Alternate function selection for port x bit y (y = 0..7) 
            Object *afrl3; // [12:15] Alternate function selection for port x bit y (y = 0..7) 
            Object *afrl4; // [16:19] Alternate function selection for port x bit y (y = 0..7) 
            Object *afrl5; // [20:23] Alternate function selection for port x bit y (y = 0..7) 
            Object *afrl6; // [24:27] Alternate function selection for port x bit y (y = 0..7) 
            Object *afrl7; // [28:31] Alternate function selection for port x bit y (y = 0..7)  
          } afrl; 
          
          // AFRH (GPIO alternate function high register) bitfields.
          struct { 
            Object *afrh8; // [0:3] Alternate function selection for port x bit y (y = 8..15) 
            Object *afrh9; // [4:7] Alternate function selection for port x bit y (y = 8..15) 
            Object *afrh10; // [8:11] Alternate function selection for port x bit y (y = 8..15) 
            Object *afrh11; // [12:15] Alternate function selection for port x bit y (y = 8..15) 
            Object *afrh12; // [16:19] Alternate function selection for port x bit y (y = 8..15) 
            Object *afrh13; // [20:23] Alternate function selection for port x bit y (y = 8..15) 
            Object *afrh14; // [24:27] Alternate function selection for port x bit y (y = 8..15) 
            Object *afrh15; // [28:31] Alternate function selection for port x bit y (y = 8..15)  
          } afrh; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32GPIOState;

// ----------------------------------------------------------------------------

#endif /* STM32_GPIO_H_ */
