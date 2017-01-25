/*
 * STM32- GPIO(General purpose I/O) emulation.
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

#define DEVICE_PATH_STM32_GPIODEVICE_PATH_STM32"GPIO"

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
STM32_PORT_GPIO_UNDEFINED = 0xFF,
} stm32_gpio_index_t;
// ----------------------------------------------------------------------------

#define TYPE_STM32_GPIOTYPE_STM32_PREFIX "gpio" TYPE_PERIPHERAL_SUFFIX

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
        // F1GPIO(General purpose I/O) registers.
        struct { 
Object *crl; // 0x0(Port configuration register low (GPIOn_CRL)) 
Object *crh; // 0x4(Port configuration register high (GPIOn_CRL)) 
Object *idr; // 0x8(Port input data register (GPIOn_IDR)) 
Object *odr; // 0xC(Port output data register (GPIOn_ODR)) 
Object *bsrr; // 0x10(Port bit set/reset register (GPIOn_BSRR)) 
Object *brr; // 0x14(Port bit reset register (GPIOn_BRR)) 
Object *lckr; // 0x18(Port configuration lock register) 
} reg;

        struct { 
// CRL(Port configuration register low (GPIOn_CRL)) bitfields.
          struct { 
Object *mode0; // [0:1] Port n.0 mode bitsObject *cnf0; // [2:3] Port n.0 configuration bitsObject *mode1; // [4:5] Port n.1 mode bitsObject *cnf1; // [6:7] Port n.1 configuration bitsObject *mode2; // [8:9] Port n.2 mode bitsObject *cnf2; // [10:11] Port n.2 configuration bitsObject *mode3; // [12:13] Port n.3 mode bitsObject *cnf3; // [14:15] Port n.3 configuration bitsObject *mode4; // [16:17] Port n.4 mode bitsObject *cnf4; // [18:19] Port n.4 configuration bitsObject *mode5; // [20:21] Port n.5 mode bitsObject *cnf5; // [22:23] Port n.5 configuration bitsObject *mode6; // [24:25] Port n.6 mode bitsObject *cnf6; // [26:27] Port n.6 configuration bitsObject *mode7; // [28:29] Port n.7 mode bitsObject *cnf7; // [30:31] Port n.7 configuration bits} crl; 
// CRH(Port configuration register high (GPIOn_CRL)) bitfields.
          struct { 
Object *mode8; // [0:1] Port n.8 mode bitsObject *cnf8; // [2:3] Port n.8 configuration bitsObject *mode9; // [4:5] Port n.9 mode bitsObject *cnf9; // [6:7] Port n.9 configuration bitsObject *mode10; // [8:9] Port n.10 mode bitsObject *cnf10; // [10:11] Port n.10 configuration bitsObject *mode11; // [12:13] Port n.11 mode bitsObject *cnf11; // [14:15] Port n.11 configuration bitsObject *mode12; // [16:17] Port n.12 mode bitsObject *cnf12; // [18:19] Port n.12 configuration bitsObject *mode13; // [20:21] Port n.13 mode bitsObject *cnf13; // [22:23] Port n.13 configuration bitsObject *mode14; // [24:25] Port n.14 mode bitsObject *cnf14; // [26:27] Port n.14 configuration bitsObject *mode15; // [28:29] Port n.15 mode bitsObject *cnf15; // [30:31] Port n.15 configuration bits} crh; 
// IDR(Port input data register (GPIOn_IDR)) bitfields.
          struct { 
Object *idr0; // [0:0] Port input dataObject *idr1; // [1:1] Port input dataObject *idr2; // [2:2] Port input dataObject *idr3; // [3:3] Port input dataObject *idr4; // [4:4] Port input dataObject *idr5; // [5:5] Port input dataObject *idr6; // [6:6] Port input dataObject *idr7; // [7:7] Port input dataObject *idr8; // [8:8] Port input dataObject *idr9; // [9:9] Port input dataObject *idr10; // [10:10] Port input dataObject *idr11; // [11:11] Port input dataObject *idr12; // [12:12] Port input dataObject *idr13; // [13:13] Port input dataObject *idr14; // [14:14] Port input dataObject *idr15; // [15:15] Port input data} idr; 
// ODR(Port output data register (GPIOn_ODR)) bitfields.
          struct { 
Object *odr0; // [0:0] Port output dataObject *odr1; // [1:1] Port output dataObject *odr2; // [2:2] Port output dataObject *odr3; // [3:3] Port output dataObject *odr4; // [4:4] Port output dataObject *odr5; // [5:5] Port output dataObject *odr6; // [6:6] Port output dataObject *odr7; // [7:7] Port output dataObject *odr8; // [8:8] Port output dataObject *odr9; // [9:9] Port output dataObject *odr10; // [10:10] Port output dataObject *odr11; // [11:11] Port output dataObject *odr12; // [12:12] Port output dataObject *odr13; // [13:13] Port output dataObject *odr14; // [14:14] Port output dataObject *odr15; // [15:15] Port output data} odr; 
// BSRR(Port bit set/reset register (GPIOn_BSRR)) bitfields.
          struct { 
Object *bs0; // [0:0] Set bit 0Object *bs1; // [1:1] Set bit 1Object *bs2; // [2:2] Set bit 1Object *bs3; // [3:3] Set bit 3Object *bs4; // [4:4] Set bit 4Object *bs5; // [5:5] Set bit 5Object *bs6; // [6:6] Set bit 6Object *bs7; // [7:7] Set bit 7Object *bs8; // [8:8] Set bit 8Object *bs9; // [9:9] Set bit 9Object *bs10; // [10:10] Set bit 10Object *bs11; // [11:11] Set bit 11Object *bs12; // [12:12] Set bit 12Object *bs13; // [13:13] Set bit 13Object *bs14; // [14:14] Set bit 14Object *bs15; // [15:15] Set bit 15Object *br0; // [16:16] Reset bit 0Object *br1; // [17:17] Reset bit 1Object *br2; // [18:18] Reset bit 2Object *br3; // [19:19] Reset bit 3Object *br4; // [20:20] Reset bit 4Object *br5; // [21:21] Reset bit 5Object *br6; // [22:22] Reset bit 6Object *br7; // [23:23] Reset bit 7Object *br8; // [24:24] Reset bit 8Object *br9; // [25:25] Reset bit 9Object *br10; // [26:26] Reset bit 10Object *br11; // [27:27] Reset bit 11Object *br12; // [28:28] Reset bit 12Object *br13; // [29:29] Reset bit 13Object *br14; // [30:30] Reset bit 14Object *br15; // [31:31] Reset bit 15} bsrr; 
// BRR(Port bit reset register (GPIOn_BRR)) bitfields.
          struct { 
Object *br0; // [0:0] Reset bit 0Object *br1; // [1:1] Reset bit 1Object *br2; // [2:2] Reset bit 1Object *br3; // [3:3] Reset bit 3Object *br4; // [4:4] Reset bit 4Object *br5; // [5:5] Reset bit 5Object *br6; // [6:6] Reset bit 6Object *br7; // [7:7] Reset bit 7Object *br8; // [8:8] Reset bit 8Object *br9; // [9:9] Reset bit 9Object *br10; // [10:10] Reset bit 10Object *br11; // [11:11] Reset bit 11Object *br12; // [12:12] Reset bit 12Object *br13; // [13:13] Reset bit 13Object *br14; // [14:14] Reset bit 14Object *br15; // [15:15] Reset bit 15} brr; 
// LCKR(Port configuration lock register) bitfields.
          struct { 
Object *lck0; // [0:0] Port A Lock bit 0Object *lck1; // [1:1] Port A Lock bit 1Object *lck2; // [2:2] Port A Lock bit 2Object *lck3; // [3:3] Port A Lock bit 3Object *lck4; // [4:4] Port A Lock bit 4Object *lck5; // [5:5] Port A Lock bit 5Object *lck6; // [6:6] Port A Lock bit 6Object *lck7; // [7:7] Port A Lock bit 7Object *lck8; // [8:8] Port A Lock bit 8Object *lck9; // [9:9] Port A Lock bit 9Object *lck10; // [10:10] Port A Lock bit 10Object *lck11; // [11:11] Port A Lock bit 11Object *lck12; // [12:12] Port A Lock bit 12Object *lck13; // [13:13] Port A Lock bit 13Object *lck14; // [14:14] Port A Lock bit 14Object *lck15; // [15:15] Port A Lock bit 15Object *lckk; // [16:16] Lock key} lckr; 
} fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32GPIOState;

// ----------------------------------------------------------------------------

#endif /* STM32_GPIO_H_ */
