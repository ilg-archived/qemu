/*
 * STM32 MCU - SYSCFG (system configuration controller) emulation.
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

#ifndef STM32_SYSCFG_H_
#define STM32_SYSCFG_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_SYSCFG DEVICE_PATH_STM32 "SYSCFG"

// ----------------------------------------------------------------------------

#define TYPE_STM32_SYSCFG TYPE_STM32_PREFIX "syscfg" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_SYSCFG_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32SYSCFGParentClass;
typedef PeripheralState STM32SYSCFGParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_SYSCFG_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32SYSCFGClass, (obj), TYPE_STM32_SYSCFG)
#define STM32_SYSCFG_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32SYSCFGClass, (klass), TYPE_STM32_SYSCFG)

typedef struct {
    // private:
    STM32SYSCFGParentClass parent_class;
    // public:

    // None, so far.
} STM32SYSCFGClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_SYSCFG_STATE(obj) \
    OBJECT_CHECK(STM32SYSCFGState, (obj), TYPE_STM32_SYSCFG)

typedef struct {
    // private:
    STM32SYSCFGParentState parent_obj;
    // public:

    const STM32Capabilities *capabilities;

    // Points to one RCC bitfield that enables the peripheral.
    Object *enabling_bit;

    // Used in GPIOs, it is easier to make it common to all families.
    struct {
        Object *exti[16];
    } exticr;

    union {
        // DO NOT EDIT! Automatically generated!
        struct {
            // F0 SYSCFG (System configuration controller) registers.
            struct {
                Object *cfgr1; // 0x0 Configuration register 1
                Object *exticr1; // 0x8 External interrupt configuration register 1
                Object *exticr2; // 0xC External interrupt configuration register 2
                Object *exticr3; // 0x10 External interrupt configuration register 3
                Object *exticr4; // 0x14 External interrupt configuration register 4
                Object *cfgr2; // 0x18 Configuration register 2
            } reg;

            struct {

                // CFGR1 (Configuration register 1) bitfields.
                struct {
                    Object *mem_mode; // [0:1] Memory mapping selection bits
                    Object *adc_dma_rmp; // [8:8] ADC DMA remapping bit
                    Object *usart1_tx_dma_rmp; // [9:9] USART1_TX DMA remapping bit
                    Object *usart1_rx_dma_rmp; // [10:10] USART1_RX DMA request remapping bit
                    Object *tim16_dma_rmp; // [11:11] TIM16 DMA request remapping bit
                    Object *tim17_dma_rmp; // [12:12] TIM17 DMA request remapping bit
                    Object *i2c_pb6_fm; // [16:16] Fast Mode Plus (FM plus) driving capability activation bits.
                    Object *i2c_pb7_fm; // [17:17] Fast Mode Plus (FM+) driving capability activation bits.
                    Object *i2c_pb8_fm; // [18:18] Fast Mode Plus (FM+) driving capability activation bits.
                    Object *i2c_pb9_fm; // [19:19] Fast Mode Plus (FM+) driving capability activation bits.
                    Object *i2c1_fm_plus; // [20:20] FM+ driving capability activation for I2C1
                    Object *i2c2_fm_plus; // [21:21] FM+ driving capability activation for I2C2
                    Object *spi2_dma_rmp; // [24:24] SPI2 DMA request remapping bit
                    Object *usart2_dma_rmp; // [25:25] USART2 DMA request remapping bit
                    Object *usart3_dma_rmp; // [26:26] USART3 DMA request remapping bit
                    Object *i2c1_dma_rmp; // [27:27] I2C1 DMA request remapping bit
                    Object *tim1_dma_rmp; // [28:28] TIM1 DMA request remapping bit
                    Object *tim2_dma_rmp; // [29:29] TIM2 DMA request remapping bit
                    Object *tim3_dma_rmp; // [30:30] TIM3 DMA request remapping bit
                } cfgr1;

                // EXTICR1 (External interrupt configuration register 1) bitfields.
                struct {
                    Object *exti0; // [0:3] EXTI 0 configuration bits
                    Object *exti1; // [4:7] EXTI 1 configuration bits
                    Object *exti2; // [8:11] EXTI 2 configuration bits
                    Object *exti3; // [12:15] EXTI 3 configuration bits
                } exticr1;

                // EXTICR2 (External interrupt configuration register 2) bitfields.
                struct {
                    Object *exti4; // [0:3] EXTI 4 configuration bits
                    Object *exti5; // [4:7] EXTI 5 configuration bits
                    Object *exti6; // [8:11] EXTI 6 configuration bits
                    Object *exti7; // [12:15] EXTI 7 configuration bits
                } exticr2;

                // EXTICR3 (External interrupt configuration register 3) bitfields.
                struct {
                    Object *exti8; // [0:3] EXTI 8 configuration bits
                    Object *exti9; // [4:7] EXTI 9 configuration bits
                    Object *exti10; // [8:11] EXTI 10 configuration bits
                    Object *exti11; // [12:15] EXTI 11 configuration bits
                } exticr3;

                // EXTICR4 (External interrupt configuration register 4) bitfields.
                struct {
                    Object *exti12; // [0:3] EXTI 12 configuration bits
                    Object *exti13; // [4:7] EXTI 13 configuration bits
                    Object *exti14; // [8:11] EXTI 14 configuration bits
                    Object *exti15; // [12:15] EXTI 15 configuration bits
                } exticr4;

                // CFGR2 (Configuration register 2) bitfields.
                struct {
                    Object *locup_lock; // [0:0] Cortex-M0 LOCKUP bit enable bit
                    Object *sram_parity_lock; // [1:1] SRAM parity lock bit
                    Object *pvd_lock; // [2:2] PVD lock enable bit
                    Object *sram_pef; // [8:8] SRAM parity flag
                } cfgr2;
            } fld;
        } f0;

        // DO NOT EDIT! Automatically generated!
        struct {
            // F4 SYSCFG (System configuration controller) registers.
            struct {
                Object *memrm; // 0x0 Memory remap register
                Object *pmc; // 0x4 Peripheral mode configuration register
                Object *exticr1; // 0x8 External interrupt configuration register 1
                Object *exticr2; // 0xC External interrupt configuration register 2
                Object *exticr3; // 0x10 External interrupt configuration register 3
                Object *exticr4; // 0x14 External interrupt configuration register 4
                Object *cmpcr; // 0x20 Compensation cell control register
            } reg;

            struct {

                // MEMRM (Memory remap register) bitfields.
                struct {
                    Object *mem_mode; // [0:1] MEM_MODE

                    // F429
                    Object *fb_mode; // [8:8] Flash bank mode selection
                    Object *swp_fmc; // [10:11] FMC memory mapping swap

                } memrm;

                // PMC (Peripheral mode configuration register) bitfields.
                struct {

                    // F429
                    Object *adc1dc2; // [16:16] ADC1DC2
                    Object *adc2dc2; // [17:17] ADC2DC2
                    Object *adc3dc2; // [18:18] ADC3DC2

                    Object *mii_rmii_sel; // [23:23] Ethernet PHY interface selection
                } pmc;

                // EXTICR1 (External interrupt configuration register 1) bitfields.
                struct {
                    Object *exti0; // [0:3] EXTI x configuration (x = 0 to 3)
                    Object *exti1; // [4:7] EXTI x configuration (x = 0 to 3)
                    Object *exti2; // [8:11] EXTI x configuration (x = 0 to 3)
                    Object *exti3; // [12:15] EXTI x configuration (x = 0 to 3)
                } exticr1;

                // EXTICR2 (External interrupt configuration register 2) bitfields.
                struct {
                    Object *exti4; // [0:3] EXTI x configuration (x = 4 to 7)
                    Object *exti5; // [4:7] EXTI x configuration (x = 4 to 7)
                    Object *exti6; // [8:11] EXTI x configuration (x = 4 to 7)
                    Object *exti7; // [12:15] EXTI x configuration (x = 4 to 7)
                } exticr2;

                // EXTICR3 (External interrupt configuration register 3) bitfields.
                struct {
                    Object *exti8; // [0:3] EXTI x configuration (x = 8 to 11)
                    Object *exti9; // [4:7] EXTI x configuration (x = 8 to 11)
                    Object *exti10; // [8:11] EXTI10
                    Object *exti11; // [12:15] EXTI x configuration (x = 8 to 11)
                } exticr3;

                // EXTICR4 (External interrupt configuration register 4) bitfields.
                struct {
                    Object *exti12; // [0:3] EXTI x configuration (x = 12 to 15)
                    Object *exti13; // [4:7] EXTI x configuration (x = 12 to 15)
                    Object *exti14; // [8:11] EXTI x configuration (x = 12 to 15)
                    Object *exti15; // [12:15] EXTI x configuration (x = 12 to 15)
                } exticr4;

                // CMPCR (Compensation cell control register) bitfields.
                struct {
                    Object *cmp_pd; // [0:0] Compensation cell power-down
                    Object *ready; // [8:8] READY
                } cmpcr;
            } fld;
        } f4;
    } u;

} STM32SYSCFGState;

// ----------------------------------------------------------------------------

#endif /* STM32_SYSCFG_H_ */
