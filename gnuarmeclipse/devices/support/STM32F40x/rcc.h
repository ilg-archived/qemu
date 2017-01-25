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
        // F4RCC(Reset and clock control) registers.
        struct { 
Object *cr; // 0x0(Clock control register) 
Object *pllcfgr; // 0x4(PLL configuration register) 
Object *cfgr; // 0x8(Clock configuration register) 
Object *cir; // 0xC(Clock interrupt register) 
Object *ahb1rstr; // 0x10(AHB1 peripheral reset register) 
Object *ahb2rstr; // 0x14(AHB2 peripheral reset register) 
Object *ahb3rstr; // 0x18(AHB3 peripheral reset register) 
Object *apb1rstr; // 0x20(APB1 peripheral reset register) 
Object *apb2rstr; // 0x24(APB2 peripheral reset register) 
Object *ahb1enr; // 0x30(AHB1 peripheral clock register) 
Object *ahb2enr; // 0x34(AHB2 peripheral clock enable register) 
Object *ahb3enr; // 0x38(AHB3 peripheral clock enable register) 
Object *apb1enr; // 0x40(APB1 peripheral clock enable register) 
Object *apb2enr; // 0x44(APB2 peripheral clock enable register) 
Object *ahb1lpenr; // 0x50(AHB1 peripheral clock enable in low power mode register) 
Object *ahb2lpenr; // 0x54(AHB2 peripheral clock enable in low power mode register) 
Object *ahb3lpenr; // 0x58(AHB3 peripheral clock enable in low power mode register) 
Object *apb1lpenr; // 0x60(APB1 peripheral clock enable in low power mode register) 
Object *apb2lpenr; // 0x64(APB2 peripheral clock enabled in low power mode register) 
Object *bdcr; // 0x70(Backup domain control register) 
Object *csr; // 0x74(Clock control & status register) 
Object *sscgr; // 0x80(Spread spectrum clock generation register) 
Object *plli2scfgr; // 0x84(PLLI2S configuration register) 
} reg;

        struct { 
// CR(Clock control register) bitfields.
          struct { 
Object *hsion; // [0:0] Internal high-speed clock enableObject *hsirdy; // [1:1] Internal high-speed clock ready flagObject *hsitrim; // [3:7] Internal high-speed clock trimmingObject *hsical; // [8:15] Internal high-speed clock calibrationObject *hseon; // [16:16] HSE clock enableObject *hserdy; // [17:17] HSE clock ready flagObject *hsebyp; // [18:18] HSE clock bypassObject *csson; // [19:19] Clock security system enableObject *pllon; // [24:24] Main PLL (PLL) enableObject *pllrdy; // [25:25] Main PLL (PLL) clock ready flagObject *plli2son; // [26:26] PLLI2S enableObject *plli2srdy; // [27:27] PLLI2S clock ready flag} cr; 
// PLLCFGR(PLL configuration register) bitfields.
          struct { 
Object *pllm; // [0:5] Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clockObject *plln; // [6:14] Main PLL (PLL) multiplication factor for VCOObject *pllp; // [16:17] Main PLL (PLL) division factor for main system clockObject *pllsrc; // [22:22] Main PLL(PLL) and audio PLL (PLLI2S) entry clock sourceObject *pllq; // [24:27] Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks} pllcfgr; 
// CFGR(Clock configuration register) bitfields.
          struct { 
Object *sw; // [0:1] System clock switchObject *sws; // [2:3] System clock switch statusObject *hpre; // [4:7] AHB prescalerObject *ppre1; // [10:12] APB Low speed prescaler (APB1)Object *ppre2; // [13:15] APB high-speed prescaler (APB2)Object *rtcpre; // [16:20] HSE division factor for RTC clockObject *mco1; // [21:22] Microcontroller clock output 1Object *i2ssrc; // [23:23] I2S clock selectionObject *mco1pre; // [24:26] MCO1 prescalerObject *mco2pre; // [27:29] MCO2 prescalerObject *mco2; // [30:31] Microcontroller clock output 2} cfgr; 
// CIR(Clock interrupt register) bitfields.
          struct { 
Object *lsirdyf; // [0:0] LSI ready interrupt flagObject *lserdyf; // [1:1] LSE ready interrupt flagObject *hsirdyf; // [2:2] HSI ready interrupt flagObject *hserdyf; // [3:3] HSE ready interrupt flagObject *pllrdyf; // [4:4] Main PLL (PLL) ready interrupt flagObject *plli2srdyf; // [5:5] PLLI2S ready interrupt flagObject *cssf; // [7:7] Clock security system interrupt flagObject *lsirdyie; // [8:8] LSI ready interrupt enableObject *lserdyie; // [9:9] LSE ready interrupt enableObject *hsirdyie; // [10:10] HSI ready interrupt enableObject *hserdyie; // [11:11] HSE ready interrupt enableObject *pllrdyie; // [12:12] Main PLL (PLL) ready interrupt enableObject *plli2srdyie; // [13:13] PLLI2S ready interrupt enableObject *lsirdyc; // [16:16] LSI ready interrupt clearObject *lserdyc; // [17:17] LSE ready interrupt clearObject *hsirdyc; // [18:18] HSI ready interrupt clearObject *hserdyc; // [19:19] HSE ready interrupt clearObject *pllrdyc; // [20:20] Main PLL(PLL) ready interrupt clearObject *plli2srdyc; // [21:21] PLLI2S ready interrupt clearObject *cssc; // [23:23] Clock security system interrupt clear} cir; 
// AHB1RSTR(AHB1 peripheral reset register) bitfields.
          struct { 
Object *gpioarst; // [0:0] IO port A resetObject *gpiobrst; // [1:1] IO port B resetObject *gpiocrst; // [2:2] IO port C resetObject *gpiodrst; // [3:3] IO port D resetObject *gpioerst; // [4:4] IO port E resetObject *gpiofrst; // [5:5] IO port F resetObject *gpiogrst; // [6:6] IO port G resetObject *gpiohrst; // [7:7] IO port H resetObject *gpioirst; // [8:8] IO port I resetObject *crcrst; // [12:12] CRC resetObject *dma1rst; // [21:21] DMA2 resetObject *dma2rst; // [22:22] DMA2 resetObject *ethmacrst; // [25:25] Ethernet MAC resetObject *otghsrst; // [29:29] USB OTG HS module reset} ahb1rstr; 
// AHB2RSTR(AHB2 peripheral reset register) bitfields.
          struct { 
Object *dcmirst; // [0:0] Camera interface resetObject *rngrst; // [6:6] Random number generator module resetObject *otgfsrst; // [7:7] USB OTG FS module reset} ahb2rstr; 
// AHB3RSTR(AHB3 peripheral reset register) bitfields.
          struct { 
Object *fsmcrst; // [0:0] Flexible static memory controller module reset} ahb3rstr; 
// APB1RSTR(APB1 peripheral reset register) bitfields.
          struct { 
Object *tim2rst; // [0:0] TIM2 resetObject *tim3rst; // [1:1] TIM3 resetObject *tim4rst; // [2:2] TIM4 resetObject *tim5rst; // [3:3] TIM5 resetObject *tim6rst; // [4:4] TIM6 resetObject *tim7rst; // [5:5] TIM7 resetObject *tim12rst; // [6:6] TIM12 resetObject *tim13rst; // [7:7] TIM13 resetObject *tim14rst; // [8:8] TIM14 resetObject *wwdgrst; // [11:11] Window watchdog resetObject *spi2rst; // [14:14] SPI 2 resetObject *spi3rst; // [15:15] SPI 3 resetObject *uart2rst; // [17:17] USART 2 resetObject *uart3rst; // [18:18] USART 3 resetObject *uart4rst; // [19:19] USART 4 resetObject *uart5rst; // [20:20] USART 5 resetObject *i2c1rst; // [21:21] I2C 1 resetObject *i2c2rst; // [22:22] I2C 2 resetObject *i2c3rst; // [23:23] I2C3 resetObject *can1rst; // [25:25] CAN1 resetObject *can2rst; // [26:26] CAN2 resetObject *pwrrst; // [28:28] Power interface resetObject *dacrst; // [29:29] DAC reset} apb1rstr; 
// APB2RSTR(APB2 peripheral reset register) bitfields.
          struct { 
Object *tim1rst; // [0:0] TIM1 resetObject *tim8rst; // [1:1] TIM8 resetObject *usart1rst; // [4:4] USART1 resetObject *usart6rst; // [5:5] USART6 resetObject *adcrst; // [8:8] ADC interface reset (common to all ADCs)Object *sdiorst; // [11:11] SDIO resetObject *spi1rst; // [12:12] SPI 1 resetObject *syscfgrst; // [14:14] System configuration controller resetObject *tim9rst; // [16:16] TIM9 resetObject *tim10rst; // [17:17] TIM10 resetObject *tim11rst; // [18:18] TIM11 reset} apb2rstr; 
// AHB1ENR(AHB1 peripheral clock register) bitfields.
          struct { 
Object *gpioaen; // [0:0] IO port A clock enableObject *gpioben; // [1:1] IO port B clock enableObject *gpiocen; // [2:2] IO port C clock enableObject *gpioden; // [3:3] IO port D clock enableObject *gpioeen; // [4:4] IO port E clock enableObject *gpiofen; // [5:5] IO port F clock enableObject *gpiogen; // [6:6] IO port G clock enableObject *gpiohen; // [7:7] IO port H clock enableObject *gpioien; // [8:8] IO port I clock enableObject *crcen; // [12:12] CRC clock enableObject *bkpsramen; // [18:18] Backup SRAM interface clock enableObject *dma1en; // [21:21] DMA1 clock enableObject *dma2en; // [22:22] DMA2 clock enableObject *ethmacen; // [25:25] Ethernet MAC clock enableObject *ethmactxen; // [26:26] Ethernet Transmission clock enableObject *ethmacrxen; // [27:27] Ethernet Reception clock enableObject *ethmacptpen; // [28:28] Ethernet PTP clock enableObject *otghsen; // [29:29] USB OTG HS clock enableObject *otghsulpien; // [30:30] USB OTG HSULPI clock enable} ahb1enr; 
// AHB2ENR(AHB2 peripheral clock enable register) bitfields.
          struct { 
Object *dcmien; // [0:0] Camera interface enableObject *rngen; // [6:6] Random number generator clock enableObject *otgfsen; // [7:7] USB OTG FS clock enable} ahb2enr; 
// AHB3ENR(AHB3 peripheral clock enable register) bitfields.
          struct { 
Object *fsmcen; // [0:0] Flexible static memory controller module clock enable} ahb3enr; 
// APB1ENR(APB1 peripheral clock enable register) bitfields.
          struct { 
Object *tim2en; // [0:0] TIM2 clock enableObject *tim3en; // [1:1] TIM3 clock enableObject *tim4en; // [2:2] TIM4 clock enableObject *tim5en; // [3:3] TIM5 clock enableObject *tim6en; // [4:4] TIM6 clock enableObject *tim7en; // [5:5] TIM7 clock enableObject *tim12en; // [6:6] TIM12 clock enableObject *tim13en; // [7:7] TIM13 clock enableObject *tim14en; // [8:8] TIM14 clock enableObject *wwdgen; // [11:11] Window watchdog clock enableObject *spi2en; // [14:14] SPI2 clock enableObject *spi3en; // [15:15] SPI3 clock enableObject *usart2en; // [17:17] USART 2 clock enableObject *usart3en; // [18:18] USART3 clock enableObject *uart4en; // [19:19] UART4 clock enableObject *uart5en; // [20:20] UART5 clock enableObject *i2c1en; // [21:21] I2C1 clock enableObject *i2c2en; // [22:22] I2C2 clock enableObject *i2c3en; // [23:23] I2C3 clock enableObject *can1en; // [25:25] CAN 1 clock enableObject *can2en; // [26:26] CAN 2 clock enableObject *pwren; // [28:28] Power interface clock enableObject *dacen; // [29:29] DAC interface clock enable} apb1enr; 
// APB2ENR(APB2 peripheral clock enable register) bitfields.
          struct { 
Object *tim1en; // [0:0] TIM1 clock enableObject *tim8en; // [1:1] TIM8 clock enableObject *usart1en; // [4:4] USART1 clock enableObject *usart6en; // [5:5] USART6 clock enableObject *adc1en; // [8:8] ADC1 clock enableObject *adc2en; // [9:9] ADC2 clock enableObject *adc3en; // [10:10] ADC3 clock enableObject *sdioen; // [11:11] SDIO clock enableObject *spi1en; // [12:12] SPI1 clock enableObject *syscfgen; // [14:14] System configuration controller clock enableObject *tim9en; // [16:16] TIM9 clock enableObject *tim10en; // [17:17] TIM10 clock enableObject *tim11en; // [18:18] TIM11 clock enable} apb2enr; 
// AHB1LPENR(AHB1 peripheral clock enable in low power mode register) bitfields.
          struct { 
Object *gpioalpen; // [0:0] IO port A clock enable during sleep modeObject *gpioblpen; // [1:1] IO port B clock enable during Sleep modeObject *gpioclpen; // [2:2] IO port C clock enable during Sleep modeObject *gpiodlpen; // [3:3] IO port D clock enable during Sleep modeObject *gpioelpen; // [4:4] IO port E clock enable during Sleep modeObject *gpioflpen; // [5:5] IO port F clock enable during Sleep modeObject *gpioglpen; // [6:6] IO port G clock enable during Sleep modeObject *gpiohlpen; // [7:7] IO port H clock enable during Sleep modeObject *gpioilpen; // [8:8] IO port I clock enable during Sleep modeObject *crclpen; // [12:12] CRC clock enable during Sleep modeObject *flitflpen; // [15:15] Flash interface clock enable during Sleep modeObject *sram1lpen; // [16:16] SRAM 1interface clock enable during Sleep modeObject *sram2lpen; // [17:17] SRAM 2 interface clock enable during Sleep modeObject *bkpsramlpen; // [18:18] Backup SRAM interface clock enable during Sleep modeObject *dma1lpen; // [21:21] DMA1 clock enable during Sleep modeObject *dma2lpen; // [22:22] DMA2 clock enable during Sleep modeObject *ethmaclpen; // [25:25] Ethernet MAC clock enable during Sleep modeObject *ethmactxlpen; // [26:26] Ethernet transmission clock enable during Sleep modeObject *ethmacrxlpen; // [27:27] Ethernet reception clock enable during Sleep modeObject *ethmacptplpen; // [28:28] Ethernet PTP clock enable during Sleep modeObject *otghslpen; // [29:29] USB OTG HS clock enable during Sleep modeObject *otghsulpilpen; // [30:30] USB OTG HS ULPI clock enable during Sleep mode} ahb1lpenr; 
// AHB2LPENR(AHB2 peripheral clock enable in low power mode register) bitfields.
          struct { 
Object *dcmilpen; // [0:0] Camera interface enable during Sleep modeObject *rnglpen; // [6:6] Random number generator clock enable during Sleep modeObject *otgfslpen; // [7:7] USB OTG FS clock enable during Sleep mode} ahb2lpenr; 
// AHB3LPENR(AHB3 peripheral clock enable in low power mode register) bitfields.
          struct { 
Object *fsmclpen; // [0:0] Flexible static memory controller module clock enable during Sleep mode} ahb3lpenr; 
// APB1LPENR(APB1 peripheral clock enable in low power mode register) bitfields.
          struct { 
Object *tim2lpen; // [0:0] TIM2 clock enable during Sleep modeObject *tim3lpen; // [1:1] TIM3 clock enable during Sleep modeObject *tim4lpen; // [2:2] TIM4 clock enable during Sleep modeObject *tim5lpen; // [3:3] TIM5 clock enable during Sleep modeObject *tim6lpen; // [4:4] TIM6 clock enable during Sleep modeObject *tim7lpen; // [5:5] TIM7 clock enable during Sleep modeObject *tim12lpen; // [6:6] TIM12 clock enable during Sleep modeObject *tim13lpen; // [7:7] TIM13 clock enable during Sleep modeObject *tim14lpen; // [8:8] TIM14 clock enable during Sleep modeObject *wwdglpen; // [11:11] Window watchdog clock enable during Sleep modeObject *spi2lpen; // [14:14] SPI2 clock enable during Sleep modeObject *spi3lpen; // [15:15] SPI3 clock enable during Sleep modeObject *usart2lpen; // [17:17] USART2 clock enable during Sleep modeObject *usart3lpen; // [18:18] USART3 clock enable during Sleep modeObject *uart4lpen; // [19:19] UART4 clock enable during Sleep modeObject *uart5lpen; // [20:20] UART5 clock enable during Sleep modeObject *i2c1lpen; // [21:21] I2C1 clock enable during Sleep modeObject *i2c2lpen; // [22:22] I2C2 clock enable during Sleep modeObject *i2c3lpen; // [23:23] I2C3 clock enable during Sleep modeObject *can1lpen; // [25:25] CAN 1 clock enable during Sleep modeObject *can2lpen; // [26:26] CAN 2 clock enable during Sleep modeObject *pwrlpen; // [28:28] Power interface clock enable during Sleep modeObject *daclpen; // [29:29] DAC interface clock enable during Sleep mode} apb1lpenr; 
// APB2LPENR(APB2 peripheral clock enabled in low power mode register) bitfields.
          struct { 
Object *tim1lpen; // [0:0] TIM1 clock enable during Sleep modeObject *tim8lpen; // [1:1] TIM8 clock enable during Sleep modeObject *usart1lpen; // [4:4] USART1 clock enable during Sleep modeObject *usart6lpen; // [5:5] USART6 clock enable during Sleep modeObject *adc1lpen; // [8:8] ADC1 clock enable during Sleep modeObject *adc2lpen; // [9:9] ADC2 clock enable during Sleep modeObject *adc3lpen; // [10:10] ADC 3 clock enable during Sleep modeObject *sdiolpen; // [11:11] SDIO clock enable during Sleep modeObject *spi1lpen; // [12:12] SPI 1 clock enable during Sleep modeObject *syscfglpen; // [14:14] System configuration controller clock enable during Sleep modeObject *tim9lpen; // [16:16] TIM9 clock enable during sleep modeObject *tim10lpen; // [17:17] TIM10 clock enable during Sleep modeObject *tim11lpen; // [18:18] TIM11 clock enable during Sleep mode} apb2lpenr; 
// BDCR(Backup domain control register) bitfields.
          struct { 
Object *lseon; // [0:0] External low-speed oscillator enableObject *lserdy; // [1:1] External low-speed oscillator readyObject *lsebyp; // [2:2] External low-speed oscillator bypassObject *rtcsel; // [8:9] RTC clock source selectionObject *rtcen; // [15:15] RTC clock enableObject *bdrst; // [16:16] Backup domain software reset} bdcr; 
// CSR(Clock control & status register) bitfields.
          struct { 
Object *lsion; // [0:0] Internal low-speed oscillator enableObject *lsirdy; // [1:1] Internal low-speed oscillator readyObject *rmvf; // [24:24] Remove reset flagObject *borrstf; // [25:25] BOR reset flagObject *padrstf; // [26:26] PIN reset flagObject *porrstf; // [27:27] POR/PDR reset flagObject *sftrstf; // [28:28] Software reset flagObject *wdgrstf; // [29:29] Independent watchdog reset flagObject *wwdgrstf; // [30:30] Window watchdog reset flagObject *lpwrrstf; // [31:31] Low-power reset flag} csr; 
// SSCGR(Spread spectrum clock generation register) bitfields.
          struct { 
Object *modper; // [0:12] Modulation periodObject *incstep; // [13:27] Incrementation stepObject *spreadsel; // [30:30] Spread SelectObject *sscgen; // [31:31] Spread spectrum modulation enable} sscgr; 
// PLLI2SCFGR(PLLI2S configuration register) bitfields.
          struct { 
Object *plli2snx; // [6:14] PLLI2S multiplication factor for VCOObject *plli2srx; // [28:30] PLLI2S division factor for I2S clocks} plli2scfgr; 
} fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32RCCState;

// ----------------------------------------------------------------------------

#endif /* STM32_RCC_H_ */
