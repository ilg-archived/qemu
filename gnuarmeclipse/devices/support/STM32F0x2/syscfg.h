/*
 * STM32- SYSCFG(System configuration controller) emulation.
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

#define DEVICE_PATH_STM32_SYSCFGDEVICE_PATH_STM32"SYSCFG"

// ----------------------------------------------------------------------------

#define TYPE_STM32_SYSCFGTYPE_STM32_PREFIX "syscfg" TYPE_PERIPHERAL_SUFFIX

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

    // TODO: remove this if the peripheral is always enabled.
    // Points to the bitfield that enables the peripheral.
    Object *enabling_bit;

union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // F0SYSCFG(System configuration controller) registers.
        struct { 
Object *cfgr1; // 0x0(Configuration register 1) 
Object *exticr1; // 0x8(External interrupt configuration register 1) 
Object *exticr2; // 0xC(External interrupt configuration register 2) 
Object *exticr3; // 0x10(External interrupt configuration register 3) 
Object *exticr4; // 0x14(External interrupt configuration register 4) 
Object *cfgr2; // 0x18(Configuration register 2) 
} reg;

        struct { 
// CFGR1(Configuration register 1) bitfields.
          struct { 
Object *mem_mode; // [0:1] Memory mapping selection bitsObject *adc_dma_rmp; // [8:8] ADC DMA remapping bitObject *usart1_tx_dma_rmp; // [9:9] USART1_TX DMA remapping bitObject *usart1_rx_dma_rmp; // [10:10] USART1_RX DMA request remapping bitObject *tim16_dma_rmp; // [11:11] TIM16 DMA request remapping bitObject *tim17_dma_rmp; // [12:12] TIM17 DMA request remapping bitObject *i2c_pb6_fm; // [16:16] Fast Mode Plus (FM plus) driving capability activation bits.Object *i2c_pb7_fm; // [17:17] Fast Mode Plus (FM+) driving capability activation bits.Object *i2c_pb8_fm; // [18:18] Fast Mode Plus (FM+) driving capability activation bits.Object *i2c_pb9_fm; // [19:19] Fast Mode Plus (FM+) driving capability activation bits.Object *i2c1_fm_plus; // [20:20] FM+ driving capability activation for I2C1Object *i2c2_fm_plus; // [21:21] FM+ driving capability activation for I2C2Object *spi2_dma_rmp; // [24:24] SPI2 DMA request remapping bitObject *usart2_dma_rmp; // [25:25] USART2 DMA request remapping bitObject *usart3_dma_rmp; // [26:26] USART3 DMA request remapping bitObject *i2c1_dma_rmp; // [27:27] I2C1 DMA request remapping bitObject *tim1_dma_rmp; // [28:28] TIM1 DMA request remapping bitObject *tim2_dma_rmp; // [29:29] TIM2 DMA request remapping bitObject *tim3_dma_rmp; // [30:30] TIM3 DMA request remapping bit} cfgr1; 
// EXTICR1(External interrupt configuration register 1) bitfields.
          struct { 
Object *exti0; // [0:3] EXTI 0 configuration bitsObject *exti1; // [4:7] EXTI 1 configuration bitsObject *exti2; // [8:11] EXTI 2 configuration bitsObject *exti3; // [12:15] EXTI 3 configuration bits} exticr1; 
// EXTICR2(External interrupt configuration register 2) bitfields.
          struct { 
Object *exti4; // [0:3] EXTI 4 configuration bitsObject *exti5; // [4:7] EXTI 5 configuration bitsObject *exti6; // [8:11] EXTI 6 configuration bitsObject *exti7; // [12:15] EXTI 7 configuration bits} exticr2; 
// EXTICR3(External interrupt configuration register 3) bitfields.
          struct { 
Object *exti8; // [0:3] EXTI 8 configuration bitsObject *exti9; // [4:7] EXTI 9 configuration bitsObject *exti10; // [8:11] EXTI 10 configuration bitsObject *exti11; // [12:15] EXTI 11 configuration bits} exticr3; 
// EXTICR4(External interrupt configuration register 4) bitfields.
          struct { 
Object *exti12; // [0:3] EXTI 12 configuration bitsObject *exti13; // [4:7] EXTI 13 configuration bitsObject *exti14; // [8:11] EXTI 14 configuration bitsObject *exti15; // [12:15] EXTI 15 configuration bits} exticr4; 
// CFGR2(Configuration register 2) bitfields.
          struct { 
Object *locup_lock; // [0:0] Cortex-M0 LOCKUP bit enable bitObject *sram_parity_lock; // [1:1] SRAM parity lock bitObject *pvd_lock; // [2:2] PVD lock enable bitObject *sram_pef; // [8:8] SRAM parity flag} cfgr2; 
} fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32SYSCFGState;

// ----------------------------------------------------------------------------

#endif /* STM32_SYSCFG_H_ */
