/*
 * STM32 MCU - GPIO emulation.
 *
 * Copyright (c) 2015 Liviu Ionescu.
 * Copyright (c) 2010 Andre Beckus.
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
#include <hw/cortexm/stm32/rcc.h>

#include <hw/cortexm/stm32/sys-bus-device.h>
#include "exec/address-spaces.h"
#include <hw/cortexm/stm32/rcc.h>
#include <hw/cortexm/stm32/syscfg.h>
#include <hw/cortexm/stm32/afio.h>
#include <hw/cortexm/peripheral.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_GPIO_A DEVICE_PATH_STM32 "GPIOA"
#define DEVICE_PATH_STM32_GPIO_B DEVICE_PATH_STM32 "GPIOB"
#define DEVICE_PATH_STM32_GPIO_C DEVICE_PATH_STM32 "GPIOC"
#define DEVICE_PATH_STM32_GPIO_D DEVICE_PATH_STM32 "GPIOD"
#define DEVICE_PATH_STM32_GPIO_E DEVICE_PATH_STM32 "GPIOE"
#define DEVICE_PATH_STM32_GPIO_F DEVICE_PATH_STM32 "GPIOF"
#define DEVICE_PATH_STM32_GPIO_G DEVICE_PATH_STM32 "GPIOG"
#define DEVICE_PATH_STM32_GPIO_H DEVICE_PATH_STM32 "GPIOH"
#define DEVICE_PATH_STM32_GPIO_I DEVICE_PATH_STM32 "GPIOI"
#define DEVICE_PATH_STM32_GPIO_J DEVICE_PATH_STM32 "GPIOJ"
#define DEVICE_PATH_STM32_GPIO_K DEVICE_PATH_STM32 "GPIOK"

// Note: the "port-index" property has type "int".
typedef enum {
    STM32_PORT_GPIOA = 0,
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

#define STM32_GPIO_PIN_COUNT    (16)

#define STM32_IRQ_GPIO_IDR_IN         "idr-in"
#define STM32_IRQ_GPIO_ODR_OUT        "odr-out"
#define STM32_IRQ_GPIO_EXTI_OUT       "exti-out"

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

    stm32_gpio_index_t port_index;

    // Points to one RCC bitfield that enables the peripheral.
    Object *enabling_bit;

    STM32SYSCFGState *syscfg;
    STM32AFIOState *afio;

    // IRQs used to communicate with the machine implementation, for
    // cases like blinking a LED.
    // There is one IRQ for each pin.  Note that for pins configured
    // as inputs, the output IRQ state has no meaning.  Perhaps
    // the output should be updated to match the input in this case...
    qemu_irq odr_irq[STM32_GPIO_PIN_COUNT];

    // IRQs used to communicate with EXTI.
    qemu_irq exti_irq[STM32_GPIO_PIN_COUNT];

    // Cached direction mask. 1 = output pin.
    // No more than 16 bits/port.
    uint16_t dir_mask;

    // Common to F4 and F0.
    struct {
        Object *moder;
        Object *otyper;
        Object *ospeeder;
        Object *pupdr;
        Object *idr;
        Object *odr;
        Object *bsrr;
        Object *lckr;
        Object *afrl;
        Object *afrh;
        Object *brr; // Not used in F4
    } reg;

    // Mutually exclusive families.
    // Address registers like status->u.f1.reg.crl.
    // The 'reg' structure was used to mark explicitly that the member is
    // a MCU processor and also in case other family variables are needed.

    union {
        // DO NOT EDIT! Automatically generated!
        struct {
            // F0 GPIO (General-purpose I/Os) registers.
            struct {
                Object *moder; // 0x0 GPIO port mode register
                Object *otyper; // 0x4 GPIO port output type register
                Object *ospeedr; // 0x8 GPIO port output speed register
                Object *pupdr; // 0xC GPIO port pull-up/pull-down register
                Object *idr; // 0x10 GPIO port input data register
                Object *odr; // 0x14 GPIO port output data register
                Object *bsrr; // 0x18 GPIO port bit set/reset register
                Object *lckr; // 0x1C GPIO port configuration lock register
                Object *afrl; // 0x20 GPIO alternate function low register
                Object *afrh; // 0x24 GPIO alternate function high register
                Object *brr; // 0x28 Port bit reset register
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

                // BRR (Port bit reset register) bitfields.
                struct {
                    Object *br0; // [0:0] Port x Reset bit y
                    Object *br1; // [1:1] Port x Reset bit y
                    Object *br2; // [2:2] Port x Reset bit y
                    Object *br3; // [3:3] Port x Reset bit y
                    Object *br4; // [4:4] Port x Reset bit y
                    Object *br5; // [5:5] Port x Reset bit y
                    Object *br6; // [6:6] Port x Reset bit y
                    Object *br7; // [7:7] Port x Reset bit y
                    Object *br8; // [8:8] Port x Reset bit y
                    Object *br9; // [9:9] Port x Reset bit y
                    Object *br10; // [10:10] Port x Reset bit y
                    Object *br11; // [11:11] Port x Reset bit y
                    Object *br12; // [12:12] Port x Reset bit y
                    Object *br13; // [13:13] Port x Reset bit y
                    Object *br14; // [14:14] Port x Reset bit y
                    Object *br15; // [15:15] Port x Reset bit y
                } brr;
            } fld;
        } f0;

        // DO NOT EDIT! Automatically generated!
        struct {
            // F1 GPIOA (General purpose I/O) registers.
            struct {
                Object *crl; // 0x0 Port configuration register low (GPIOn_CRL)
                Object *crh; // 0x4 Port configuration register high (GPIOn_CRL)
                Object *idr; // 0x8 Port input data register (GPIOn_IDR)
                Object *odr; // 0xC Port output data register (GPIOn_ODR)
                Object *bsrr; // 0x10 Port bit set/reset register (GPIOn_BSRR)
                Object *brr; // 0x14 Port bit reset register (GPIOn_BRR)
                Object *lckr; // 0x18 Port configuration lock register
            } reg;

            struct {

                // CRL (Port configuration register low (GPIOn_CRL)) bitfields.
                struct {
                    Object *mode0; // [0:1] Port n.0 mode bits
                    Object *cnf0; // [2:3] Port n.0 configuration bits
                    Object *mode1; // [4:5] Port n.1 mode bits
                    Object *cnf1; // [6:7] Port n.1 configuration bits
                    Object *mode2; // [8:9] Port n.2 mode bits
                    Object *cnf2; // [10:11] Port n.2 configuration bits
                    Object *mode3; // [12:13] Port n.3 mode bits
                    Object *cnf3; // [14:15] Port n.3 configuration bits
                    Object *mode4; // [16:17] Port n.4 mode bits
                    Object *cnf4; // [18:19] Port n.4 configuration bits
                    Object *mode5; // [20:21] Port n.5 mode bits
                    Object *cnf5; // [22:23] Port n.5 configuration bits
                    Object *mode6; // [24:25] Port n.6 mode bits
                    Object *cnf6; // [26:27] Port n.6 configuration bits
                    Object *mode7; // [28:29] Port n.7 mode bits
                    Object *cnf7; // [30:31] Port n.7 configuration bits
                } crl;

                // CRH (Port configuration register high (GPIOn_CRL)) bitfields.
                struct {
                    Object *mode8; // [0:1] Port n.8 mode bits
                    Object *cnf8; // [2:3] Port n.8 configuration bits
                    Object *mode9; // [4:5] Port n.9 mode bits
                    Object *cnf9; // [6:7] Port n.9 configuration bits
                    Object *mode10; // [8:9] Port n.10 mode bits
                    Object *cnf10; // [10:11] Port n.10 configuration bits
                    Object *mode11; // [12:13] Port n.11 mode bits
                    Object *cnf11; // [14:15] Port n.11 configuration bits
                    Object *mode12; // [16:17] Port n.12 mode bits
                    Object *cnf12; // [18:19] Port n.12 configuration bits
                    Object *mode13; // [20:21] Port n.13 mode bits
                    Object *cnf13; // [22:23] Port n.13 configuration bits
                    Object *mode14; // [24:25] Port n.14 mode bits
                    Object *cnf14; // [26:27] Port n.14 configuration bits
                    Object *mode15; // [28:29] Port n.15 mode bits
                    Object *cnf15; // [30:31] Port n.15 configuration bits
                } crh;

                // IDR (Port input data register (GPIOn_IDR)) bitfields.
                struct {
                    Object *idr0; // [0:0] Port input data
                    Object *idr1; // [1:1] Port input data
                    Object *idr2; // [2:2] Port input data
                    Object *idr3; // [3:3] Port input data
                    Object *idr4; // [4:4] Port input data
                    Object *idr5; // [5:5] Port input data
                    Object *idr6; // [6:6] Port input data
                    Object *idr7; // [7:7] Port input data
                    Object *idr8; // [8:8] Port input data
                    Object *idr9; // [9:9] Port input data
                    Object *idr10; // [10:10] Port input data
                    Object *idr11; // [11:11] Port input data
                    Object *idr12; // [12:12] Port input data
                    Object *idr13; // [13:13] Port input data
                    Object *idr14; // [14:14] Port input data
                    Object *idr15; // [15:15] Port input data
                } idr;

                // ODR (Port output data register (GPIOn_ODR)) bitfields.
                struct {
                    Object *odr0; // [0:0] Port output data
                    Object *odr1; // [1:1] Port output data
                    Object *odr2; // [2:2] Port output data
                    Object *odr3; // [3:3] Port output data
                    Object *odr4; // [4:4] Port output data
                    Object *odr5; // [5:5] Port output data
                    Object *odr6; // [6:6] Port output data
                    Object *odr7; // [7:7] Port output data
                    Object *odr8; // [8:8] Port output data
                    Object *odr9; // [9:9] Port output data
                    Object *odr10; // [10:10] Port output data
                    Object *odr11; // [11:11] Port output data
                    Object *odr12; // [12:12] Port output data
                    Object *odr13; // [13:13] Port output data
                    Object *odr14; // [14:14] Port output data
                    Object *odr15; // [15:15] Port output data
                } odr;

                // BSRR (Port bit set/reset register (GPIOn_BSRR)) bitfields.
                struct {
                    Object *bs0; // [0:0] Set bit 0
                    Object *bs1; // [1:1] Set bit 1
                    Object *bs2; // [2:2] Set bit 1
                    Object *bs3; // [3:3] Set bit 3
                    Object *bs4; // [4:4] Set bit 4
                    Object *bs5; // [5:5] Set bit 5
                    Object *bs6; // [6:6] Set bit 6
                    Object *bs7; // [7:7] Set bit 7
                    Object *bs8; // [8:8] Set bit 8
                    Object *bs9; // [9:9] Set bit 9
                    Object *bs10; // [10:10] Set bit 10
                    Object *bs11; // [11:11] Set bit 11
                    Object *bs12; // [12:12] Set bit 12
                    Object *bs13; // [13:13] Set bit 13
                    Object *bs14; // [14:14] Set bit 14
                    Object *bs15; // [15:15] Set bit 15
                    Object *br0; // [16:16] Reset bit 0
                    Object *br1; // [17:17] Reset bit 1
                    Object *br2; // [18:18] Reset bit 2
                    Object *br3; // [19:19] Reset bit 3
                    Object *br4; // [20:20] Reset bit 4
                    Object *br5; // [21:21] Reset bit 5
                    Object *br6; // [22:22] Reset bit 6
                    Object *br7; // [23:23] Reset bit 7
                    Object *br8; // [24:24] Reset bit 8
                    Object *br9; // [25:25] Reset bit 9
                    Object *br10; // [26:26] Reset bit 10
                    Object *br11; // [27:27] Reset bit 11
                    Object *br12; // [28:28] Reset bit 12
                    Object *br13; // [29:29] Reset bit 13
                    Object *br14; // [30:30] Reset bit 14
                    Object *br15; // [31:31] Reset bit 15
                } bsrr;

                // BRR (Port bit reset register (GPIOn_BRR)) bitfields.
                struct {
                    Object *br0; // [0:0] Reset bit 0
                    Object *br1; // [1:1] Reset bit 1
                    Object *br2; // [2:2] Reset bit 1
                    Object *br3; // [3:3] Reset bit 3
                    Object *br4; // [4:4] Reset bit 4
                    Object *br5; // [5:5] Reset bit 5
                    Object *br6; // [6:6] Reset bit 6
                    Object *br7; // [7:7] Reset bit 7
                    Object *br8; // [8:8] Reset bit 8
                    Object *br9; // [9:9] Reset bit 9
                    Object *br10; // [10:10] Reset bit 10
                    Object *br11; // [11:11] Reset bit 11
                    Object *br12; // [12:12] Reset bit 12
                    Object *br13; // [13:13] Reset bit 13
                    Object *br14; // [14:14] Reset bit 14
                    Object *br15; // [15:15] Reset bit 15
                } brr;

                // LCKR (Port configuration lock register) bitfields.
                struct {
                    Object *lck0; // [0:0] Port A Lock bit 0
                    Object *lck1; // [1:1] Port A Lock bit 1
                    Object *lck2; // [2:2] Port A Lock bit 2
                    Object *lck3; // [3:3] Port A Lock bit 3
                    Object *lck4; // [4:4] Port A Lock bit 4
                    Object *lck5; // [5:5] Port A Lock bit 5
                    Object *lck6; // [6:6] Port A Lock bit 6
                    Object *lck7; // [7:7] Port A Lock bit 7
                    Object *lck8; // [8:8] Port A Lock bit 8
                    Object *lck9; // [9:9] Port A Lock bit 9
                    Object *lck10; // [10:10] Port A Lock bit 10
                    Object *lck11; // [11:11] Port A Lock bit 11
                    Object *lck12; // [12:12] Port A Lock bit 12
                    Object *lck13; // [13:13] Port A Lock bit 13
                    Object *lck14; // [14:14] Port A Lock bit 14
                    Object *lck15; // [15:15] Port A Lock bit 15
                    Object *lckk; // [16:16] Lock key
                } lckr;
            } fld;
        } f1;

        // DO NOT EDIT! Automatically generated!
        struct {
            // F4 GPIOA (General-purpose I/Os) registers.
            struct {
                Object *moder; // 0x0 GPIO port mode register
                Object *otyper; // 0x4 GPIO port output type register
                Object *ospeedr; // 0x8 GPIO port output speed register
                Object *pupdr; // 0xC GPIO port pull-up/pull-down register
                Object *idr; // 0x10 GPIO port input data register
                Object *odr; // 0x14 GPIO port output data register
                Object *bsrr; // 0x18 GPIO port bit set/reset register
                Object *lckr; // 0x1C GPIO port configuration lock register
                Object *afrl; // 0x20 GPIO alternate function low register
                Object *afrh; // 0x24 GPIO alternate function high register
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
    } u;
} STM32GPIOState;

// ----- Public ---------------------------------------------------------------

Object* stm32_gpio_create(Object *parent, stm32_gpio_index_t index);

Object* stm32_gpio_get(int index);

// ----------------------------------------------------------------------------

#endif /* STM32_GPIO_H_ */
