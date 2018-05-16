/*
 * STM32- RCC(Reset and clock control) emulation.
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

#ifndef STM32_RCC_H_
#define STM32_RCC_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_RCCDEVICE_PATH_STM32"RCC"

// ----------------------------------------------------------------------------

#define TYPE_STM32_RCCTYPE_STM32_PREFIX "rcc" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_RCC_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32RCCParentClass;
typedef PeripheralState STM32RCCParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_RCC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32RCCClass, (obj), TYPE_STM32_RCC)
#define STM32_RCC_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32RCCClass, (klass), TYPE_STM32_RCC)

typedef struct {
    // private: 
    STM32RCCParentClass parent_class;
    // public: 

    // None, so far.
} STM32RCCClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_RCC_STATE(obj) \
    OBJECT_CHECK(STM32RCCState, (obj), TYPE_STM32_RCC)

typedef struct {
    // private:
    STM32RCCParentState parent_obj;
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
        // F0RCC(Reset and clock control) registers.
        struct { 
Object *cr; // 0x0(Clock control register) 
Object *cfgr; // 0x4(Clock configuration register (RCC_CFGR)) 
Object *cir; // 0x8(Clock interrupt register (RCC_CIR)) 
Object *apb2rstr; // 0xC(APB2 peripheral reset register (RCC_APB2RSTR)) 
Object *apb1rstr; // 0x10(APB1 peripheral reset register (RCC_APB1RSTR)) 
Object *ahbenr; // 0x14(AHB Peripheral Clock enable register (RCC_AHBENR)) 
Object *apb2enr; // 0x18(APB2 peripheral clock enable register (RCC_APB2ENR)) 
Object *apb1enr; // 0x1C(APB1 peripheral clock enable register (RCC_APB1ENR)) 
Object *bdcr; // 0x20(Backup domain control register (RCC_BDCR)) 
Object *csr; // 0x24(Control/status register (RCC_CSR)) 
Object *ahbrstr; // 0x28(AHB peripheral reset register) 
Object *cfgr2; // 0x2C(Clock configuration register 2) 
Object *cfgr3; // 0x30(Clock configuration register 3) 
Object *cr2; // 0x34(Clock control register 2) 
} reg;

        struct { 
// CR(Clock control register) bitfields.
          struct { 
Object *hsion; // [0:0] Internal High Speed clock enableObject *hsirdy; // [1:1] Internal High Speed clock ready flagObject *hsitrim; // [3:7] Internal High Speed clock trimmingObject *hsical; // [8:15] Internal High Speed clock CalibrationObject *hseon; // [16:16] External High Speed clock enableObject *hserdy; // [17:17] External High Speed clock ready flagObject *hsebyp; // [18:18] External High Speed clock BypassObject *csson; // [19:19] Clock Security System enableObject *pllon; // [24:24] PLL enableObject *pllrdy; // [25:25] PLL clock ready flag} cr; 
// CFGR(Clock configuration register (RCC_CFGR)) bitfields.
          struct { 
Object *sw; // [0:1] System clock SwitchObject *sws; // [2:3] System Clock Switch StatusObject *hpre; // [4:7] AHB prescalerObject *ppre; // [8:10] APB Low speed prescaler (APB1)Object *adcpre; // [14:14] ADC prescalerObject *pllsrc; // [15:16] PLL input clock sourceObject *pllxtpre; // [17:17] HSE divider for PLL entryObject *pllmul; // [18:21] PLL Multiplication FactorObject *mco; // [24:26] Microcontroller clock outputObject *mcopre; // [28:30] Microcontroller Clock Output PrescalerObject *pllnodiv; // [31:31] PLL clock not divided for MCO} cfgr; 
// CIR(Clock interrupt register (RCC_CIR)) bitfields.
          struct { 
Object *lsirdyf; // [0:0] LSI Ready Interrupt flagObject *lserdyf; // [1:1] LSE Ready Interrupt flagObject *hsirdyf; // [2:2] HSI Ready Interrupt flagObject *hserdyf; // [3:3] HSE Ready Interrupt flagObject *pllrdyf; // [4:4] PLL Ready Interrupt flagObject *hsi14rdyf; // [5:5] HSI14 ready interrupt flagObject *hsi48rdyf; // [6:6] HSI48 ready interrupt flagObject *cssf; // [7:7] Clock Security System Interrupt flagObject *lsirdyie; // [8:8] LSI Ready Interrupt EnableObject *lserdyie; // [9:9] LSE Ready Interrupt EnableObject *hsirdyie; // [10:10] HSI Ready Interrupt EnableObject *hserdyie; // [11:11] HSE Ready Interrupt EnableObject *pllrdyie; // [12:12] PLL Ready Interrupt EnableObject *hsi14rdye; // [13:13] HSI14 ready interrupt enableObject *hsi48rdyie; // [14:14] HSI48 ready interrupt enableObject *lsirdyc; // [16:16] LSI Ready Interrupt ClearObject *lserdyc; // [17:17] LSE Ready Interrupt ClearObject *hsirdyc; // [18:18] HSI Ready Interrupt ClearObject *hserdyc; // [19:19] HSE Ready Interrupt ClearObject *pllrdyc; // [20:20] PLL Ready Interrupt ClearObject *hsi14rdyc; // [21:21] HSI 14 MHz Ready Interrupt ClearObject *hsi48rdyc; // [22:22] HSI48 Ready Interrupt ClearObject *cssc; // [23:23] Clock security system interrupt clear} cir; 
// APB2RSTR(APB2 peripheral reset register (RCC_APB2RSTR)) bitfields.
          struct { 
Object *syscfgrst; // [0:0] SYSCFG and COMP resetObject *adcrst; // [9:9] ADC interface resetObject *tim1rst; // [11:11] TIM1 timer resetObject *spi1rst; // [12:12] SPI 1 resetObject *usart1rst; // [14:14] USART1 resetObject *tim15rst; // [16:16] TIM15 timer resetObject *tim16rst; // [17:17] TIM16 timer resetObject *tim17rst; // [18:18] TIM17 timer resetObject *dbgmcurst; // [22:22] Debug MCU reset} apb2rstr; 
// APB1RSTR(APB1 peripheral reset register (RCC_APB1RSTR)) bitfields.
          struct { 
Object *tim2rst; // [0:0] Timer 2 resetObject *tim3rst; // [1:1] Timer 3 resetObject *tim6rst; // [4:4] Timer 6 resetObject *tim7rst; // [5:5] TIM7 timer resetObject *tim14rst; // [8:8] Timer 14 resetObject *wwdgrst; // [11:11] Window watchdog resetObject *spi2rst; // [14:14] SPI2 resetObject *usart2rst; // [17:17] USART 2 resetObject *usart3rst; // [18:18] USART3 resetObject *usart4rst; // [19:19] USART4 resetObject *i2c1rst; // [21:21] I2C1 resetObject *i2c2rst; // [22:22] I2C2 resetObject *usbrst; // [23:23] USB interface resetObject *canrst; // [25:25] CAN interface resetObject *crsrst; // [27:27] Clock Recovery System interface resetObject *pwrrst; // [28:28] Power interface resetObject *dacrst; // [29:29] DAC interface resetObject *cecrst; // [30:30] HDMI CEC reset} apb1rstr; 
// AHBENR(AHB Peripheral Clock enable register (RCC_AHBENR)) bitfields.
          struct { 
Object *dma1en; // [0:0] DMA1 clock enableObject *sramen; // [2:2] SRAM interface clock enableObject *flitfen; // [4:4] FLITF clock enableObject *crcen; // [6:6] CRC clock enableObject *iopaen; // [17:17] I/O port A clock enableObject *iopben; // [18:18] I/O port B clock enableObject *iopcen; // [19:19] I/O port C clock enableObject *iopden; // [20:20] I/O port D clock enableObject *iopfen; // [22:22] I/O port F clock enableObject *tscen; // [24:24] Touch sensing controller clock enable} ahbenr; 
// APB2ENR(APB2 peripheral clock enable register (RCC_APB2ENR)) bitfields.
          struct { 
Object *syscfgen; // [0:0] SYSCFG clock enableObject *adcen; // [9:9] ADC 1 interface clock enableObject *tim1en; // [11:11] TIM1 Timer clock enableObject *spi1en; // [12:12] SPI 1 clock enableObject *usart1en; // [14:14] USART1 clock enableObject *tim15en; // [16:16] TIM15 timer clock enableObject *tim16en; // [17:17] TIM16 timer clock enableObject *tim17en; // [18:18] TIM17 timer clock enableObject *dbgmcuen; // [22:22] MCU debug module clock enable} apb2enr; 
// APB1ENR(APB1 peripheral clock enable register (RCC_APB1ENR)) bitfields.
          struct { 
Object *tim2en; // [0:0] Timer 2 clock enableObject *tim3en; // [1:1] Timer 3 clock enableObject *tim6en; // [4:4] Timer 6 clock enableObject *tim7en; // [5:5] TIM7 timer clock enableObject *tim14en; // [8:8] Timer 14 clock enableObject *wwdgen; // [11:11] Window watchdog clock enableObject *spi2en; // [14:14] SPI 2 clock enableObject *usart2en; // [17:17] USART 2 clock enableObject *usart3en; // [18:18] USART3 clock enableObject *usart4en; // [19:19] USART4 clock enableObject *i2c1en; // [21:21] I2C 1 clock enableObject *i2c2en; // [22:22] I2C 2 clock enableObject *usbrst; // [23:23] USB interface clock enableObject *canen; // [25:25] CAN interface clock enableObject *crsen; // [27:27] Clock Recovery System interface clock enableObject *pwren; // [28:28] Power interface clock enableObject *dacen; // [29:29] DAC interface clock enableObject *cecen; // [30:30] HDMI CEC interface clock enable} apb1enr; 
// BDCR(Backup domain control register (RCC_BDCR)) bitfields.
          struct { 
Object *lseon; // [0:0] External Low Speed oscillator enableObject *lserdy; // [1:1] External Low Speed oscillator readyObject *lsebyp; // [2:2] External Low Speed oscillator bypassObject *lsedrv; // [3:4] LSE oscillator drive capabilityObject *rtcsel; // [8:9] RTC clock source selectionObject *rtcen; // [15:15] RTC clock enableObject *bdrst; // [16:16] Backup domain software reset} bdcr; 
// CSR(Control/status register (RCC_CSR)) bitfields.
          struct { 
Object *lsion; // [0:0] Internal low speed oscillator enableObject *lsirdy; // [1:1] Internal low speed oscillator readyObject *rmvf; // [24:24] Remove reset flagObject *oblrstf; // [25:25] Option byte loader reset flagObject *pinrstf; // [26:26] PIN reset flagObject *porrstf; // [27:27] POR/PDR reset flagObject *sftrstf; // [28:28] Software reset flagObject *iwdgrstf; // [29:29] Independent watchdog reset flagObject *wwdgrstf; // [30:30] Window watchdog reset flagObject *lpwrrstf; // [31:31] Low-power reset flag} csr; 
// AHBRSTR(AHB peripheral reset register) bitfields.
          struct { 
Object *ioparst; // [17:17] I/O port A resetObject *iopbrst; // [18:18] I/O port B resetObject *iopcrst; // [19:19] I/O port C resetObject *iopdrst; // [20:20] I/O port D resetObject *iopfrst; // [22:22] I/O port F resetObject *tscrst; // [24:24] Touch sensing controller reset} ahbrstr; 
// CFGR2(Clock configuration register 2) bitfields.
          struct { 
Object *prediv; // [0:3] PREDIV division factor} cfgr2; 
// CFGR3(Clock configuration register 3) bitfields.
          struct { 
Object *usart1sw; // [0:1] USART1 clock source selectionObject *i2c1sw; // [4:4] I2C1 clock source selectionObject *cecsw; // [6:6] HDMI CEC clock source selectionObject *usbsw; // [7:7] USB clock source selectionObject *adcsw; // [8:8] ADC clock source selectionObject *usart2sw; // [16:17] USART2 clock source selection} cfgr3; 
// CR2(Clock control register 2) bitfields.
          struct { 
Object *hsi14on; // [0:0] HSI14 clock enableObject *hsi14rdy; // [1:1] HR14 clock ready flagObject *hsi14dis; // [2:2] HSI14 clock request from ADC disableObject *hsi14trim; // [3:7] HSI14 clock trimmingObject *hsi14cal; // [8:15] HSI14 clock calibrationObject *hsi48on; // [16:16] HSI48 clock enableObject *hsi48rdy; // [17:17] HSI48 clock ready flagObject *hsi48cal; // [24:24] HSI48 factory clock calibration} cr2; 
} fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32RCCState;

// ----------------------------------------------------------------------------

#endif /* STM32_RCC_H_ */
