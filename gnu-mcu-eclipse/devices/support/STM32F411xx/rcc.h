/*
 * STM32 - RCC (Reset and clock control) emulation.
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

#define DEVICE_PATH_STM32_RCC DEVICE_PATH_STM32 "RCC"



// ----------------------------------------------------------------------------

#define TYPE_STM32_RCC TYPE_STM32_PREFIX "rcc" TYPE_PERIPHERAL_SUFFIX

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
        // F4 RCC (Reset and clock control) registers.
        struct { 
          Object *cr; // 0x0 (Clock control register) 
          Object *pllcfgr; // 0x4 (PLL configuration register) 
          Object *cfgr; // 0x8 (Clock configuration register) 
          Object *cir; // 0xC (Clock interrupt register) 
          Object *ahb1rstr; // 0x10 (AHB1 peripheral reset register) 
          Object *ahb2rstr; // 0x14 (AHB2 peripheral reset register) 
          Object *apb1rstr; // 0x20 (APB1 peripheral reset register) 
          Object *apb2rstr; // 0x24 (APB2 peripheral reset register) 
          Object *ahb1enr; // 0x30 (AHB1 peripheral clock register) 
          Object *ahb2enr; // 0x34 (AHB2 peripheral clock enable register) 
          Object *apb1enr; // 0x40 (APB1 peripheral clock enable register) 
          Object *apb2enr; // 0x44 (APB2 peripheral clock enable register) 
          Object *ahb1lpenr; // 0x50 (AHB1 peripheral clock enable in low power mode register) 
          Object *ahb2lpenr; // 0x54 (AHB2 peripheral clock enable in low power mode register) 
          Object *apb1lpenr; // 0x60 (APB1 peripheral clock enable in low power mode register) 
          Object *apb2lpenr; // 0x64 (APB2 peripheral clock enabled in low power mode register) 
          Object *bdcr; // 0x70 (Backup domain control register) 
          Object *csr; // 0x74 (Clock control & status register) 
          Object *sscgr; // 0x80 (Spread spectrum clock generation register) 
          Object *plli2scfgr; // 0x84 (PLLI2S configuration register) 
        } reg;

        struct { 
          
          // CR (Clock control register) bitfields.
          struct { 
            Object *hsion; // [0:0] Internal high-speed clock enable 
            Object *hsirdy; // [1:1] Internal high-speed clock ready flag 
            Object *hsitrim; // [3:7] Internal high-speed clock trimming 
            Object *hsical; // [8:15] Internal high-speed clock calibration 
            Object *hseon; // [16:16] HSE clock enable 
            Object *hserdy; // [17:17] HSE clock ready flag 
            Object *hsebyp; // [18:18] HSE clock bypass 
            Object *csson; // [19:19] Clock security system enable 
            Object *pllon; // [24:24] Main PLL (PLL) enable 
            Object *pllrdy; // [25:25] Main PLL (PLL) clock ready flag 
            Object *plli2son; // [26:26] PLLI2S enable 
            Object *plli2srdy; // [27:27] PLLI2S clock ready flag  
          } cr; 
          
          // PLLCFGR (PLL configuration register) bitfields.
          struct { 
            Object *pllm; // [0:5] Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock 
            Object *plln; // [6:14] Main PLL (PLL) multiplication factor for VCO 
            Object *pllp; // [16:17] Main PLL (PLL) division factor for main system clock 
            Object *pllsrc; // [22:22] Main PLL(PLL) and audio PLL (PLLI2S) entry clock source 
            Object *pllq; // [24:27] Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks  
          } pllcfgr; 
          
          // CFGR (Clock configuration register) bitfields.
          struct { 
            Object *sw; // [0:1] System clock switch 
            Object *sws; // [2:3] System clock switch status 
            Object *hpre; // [4:7] AHB prescaler 
            Object *ppre1; // [10:12] APB Low speed prescaler (APB1) 
            Object *ppre2; // [13:15] APB high-speed prescaler (APB2) 
            Object *rtcpre; // [16:20] HSE division factor for RTC clock 
            Object *mco1; // [21:22] Microcontroller clock output 1 
            Object *i2ssrc; // [23:23] I2S clock selection 
            Object *mco1pre; // [24:26] MCO1 prescaler 
            Object *mco2pre; // [27:29] MCO2 prescaler 
            Object *mco2; // [30:31] Microcontroller clock output 2  
          } cfgr; 
          
          // CIR (Clock interrupt register) bitfields.
          struct { 
            Object *lsirdyf; // [0:0] LSI ready interrupt flag 
            Object *lserdyf; // [1:1] LSE ready interrupt flag 
            Object *hsirdyf; // [2:2] HSI ready interrupt flag 
            Object *hserdyf; // [3:3] HSE ready interrupt flag 
            Object *pllrdyf; // [4:4] Main PLL (PLL) ready interrupt flag 
            Object *plli2srdyf; // [5:5] PLLI2S ready interrupt flag 
            Object *cssf; // [7:7] Clock security system interrupt flag 
            Object *lsirdyie; // [8:8] LSI ready interrupt enable 
            Object *lserdyie; // [9:9] LSE ready interrupt enable 
            Object *hsirdyie; // [10:10] HSI ready interrupt enable 
            Object *hserdyie; // [11:11] HSE ready interrupt enable 
            Object *pllrdyie; // [12:12] Main PLL (PLL) ready interrupt enable 
            Object *plli2srdyie; // [13:13] PLLI2S ready interrupt enable 
            Object *lsirdyc; // [16:16] LSI ready interrupt clear 
            Object *lserdyc; // [17:17] LSE ready interrupt clear 
            Object *hsirdyc; // [18:18] HSI ready interrupt clear 
            Object *hserdyc; // [19:19] HSE ready interrupt clear 
            Object *pllrdyc; // [20:20] Main PLL(PLL) ready interrupt clear 
            Object *plli2srdyc; // [21:21] PLLI2S ready interrupt clear 
            Object *cssc; // [23:23] Clock security system interrupt clear  
          } cir; 
          
          // AHB1RSTR (AHB1 peripheral reset register) bitfields.
          struct { 
            Object *gpioarst; // [0:0] IO port A reset 
            Object *gpiobrst; // [1:1] IO port B reset 
            Object *gpiocrst; // [2:2] IO port C reset 
            Object *gpiodrst; // [3:3] IO port D reset 
            Object *gpioerst; // [4:4] IO port E reset 
            Object *gpiohrst; // [7:7] IO port H reset 
            Object *crcrst; // [12:12] CRC reset 
            Object *dma1rst; // [21:21] DMA2 reset 
            Object *dma2rst; // [22:22] DMA2 reset  
          } ahb1rstr; 
          
          // AHB2RSTR (AHB2 peripheral reset register) bitfields.
          struct { 
            Object *otgfsrst; // [7:7] USB OTG FS module reset  
          } ahb2rstr; 
          
          // APB1RSTR (APB1 peripheral reset register) bitfields.
          struct { 
            Object *tim2rst; // [0:0] TIM2 reset 
            Object *tim3rst; // [1:1] TIM3 reset 
            Object *tim4rst; // [2:2] TIM4 reset 
            Object *tim5rst; // [3:3] TIM5 reset 
            Object *wwdgrst; // [11:11] Window watchdog reset 
            Object *spi2rst; // [14:14] SPI 2 reset 
            Object *spi3rst; // [15:15] SPI 3 reset 
            Object *uart2rst; // [17:17] USART 2 reset 
            Object *i2c1rst; // [21:21] I2C 1 reset 
            Object *i2c2rst; // [22:22] I2C 2 reset 
            Object *i2c3rst; // [23:23] I2C3 reset 
            Object *pwrrst; // [28:28] Power interface reset  
          } apb1rstr; 
          
          // APB2RSTR (APB2 peripheral reset register) bitfields.
          struct { 
            Object *tim1rst; // [0:0] TIM1 reset 
            Object *usart1rst; // [4:4] USART1 reset 
            Object *usart6rst; // [5:5] USART6 reset 
            Object *adcrst; // [8:8] ADC interface reset (common to all ADCs) 
            Object *sdiorst; // [11:11] SDIO reset 
            Object *spi1rst; // [12:12] SPI 1 reset 
            Object *syscfgrst; // [14:14] System configuration controller reset 
            Object *tim9rst; // [16:16] TIM9 reset 
            Object *tim10rst; // [17:17] TIM10 reset 
            Object *tim11rst; // [18:18] TIM11 reset  
          } apb2rstr; 
          
          // AHB1ENR (AHB1 peripheral clock register) bitfields.
          struct { 
            Object *gpioaen; // [0:0] IO port A clock enable 
            Object *gpioben; // [1:1] IO port B clock enable 
            Object *gpiocen; // [2:2] IO port C clock enable 
            Object *gpioden; // [3:3] IO port D clock enable 
            Object *gpioeen; // [4:4] IO port E clock enable 
            Object *gpiohen; // [7:7] IO port H clock enable 
            Object *crcen; // [12:12] CRC clock enable 
            Object *dma1en; // [21:21] DMA1 clock enable 
            Object *dma2en; // [22:22] DMA2 clock enable  
          } ahb1enr; 
          
          // AHB2ENR (AHB2 peripheral clock enable register) bitfields.
          struct { 
            Object *otgfsen; // [7:7] USB OTG FS clock enable  
          } ahb2enr; 
          
          // APB1ENR (APB1 peripheral clock enable register) bitfields.
          struct { 
            Object *tim2en; // [0:0] TIM2 clock enable 
            Object *tim3en; // [1:1] TIM3 clock enable 
            Object *tim4en; // [2:2] TIM4 clock enable 
            Object *tim5en; // [3:3] TIM5 clock enable 
            Object *wwdgen; // [11:11] Window watchdog clock enable 
            Object *spi2en; // [14:14] SPI2 clock enable 
            Object *spi3en; // [15:15] SPI3 clock enable 
            Object *usart2en; // [17:17] USART 2 clock enable 
            Object *i2c1en; // [21:21] I2C1 clock enable 
            Object *i2c2en; // [22:22] I2C2 clock enable 
            Object *i2c3en; // [23:23] I2C3 clock enable 
            Object *pwren; // [28:28] Power interface clock enable  
          } apb1enr; 
          
          // APB2ENR (APB2 peripheral clock enable register) bitfields.
          struct { 
            Object *tim1en; // [0:0] TIM1 clock enable 
            Object *usart1en; // [4:4] USART1 clock enable 
            Object *usart6en; // [5:5] USART6 clock enable 
            Object *adc1en; // [8:8] ADC1 clock enable 
            Object *sdioen; // [11:11] SDIO clock enable 
            Object *spi1en; // [12:12] SPI1 clock enable 
            Object *spi4en; // [13:13] SPI4 clock enable 
            Object *syscfgen; // [14:14] System configuration controller clock enable 
            Object *tim9en; // [16:16] TIM9 clock enable 
            Object *tim10en; // [17:17] TIM10 clock enable 
            Object *tim11en; // [18:18] TIM11 clock enable  
          } apb2enr; 
          
          // AHB1LPENR (AHB1 peripheral clock enable in low power mode register) bitfields.
          struct { 
            Object *gpioalpen; // [0:0] IO port A clock enable during sleep mode 
            Object *gpioblpen; // [1:1] IO port B clock enable during Sleep mode 
            Object *gpioclpen; // [2:2] IO port C clock enable during Sleep mode 
            Object *gpiodlpen; // [3:3] IO port D clock enable during Sleep mode 
            Object *gpioelpen; // [4:4] IO port E clock enable during Sleep mode 
            Object *gpiohlpen; // [7:7] IO port H clock enable during Sleep mode 
            Object *crclpen; // [12:12] CRC clock enable during Sleep mode 
            Object *flitflpen; // [15:15] Flash interface clock enable during Sleep mode 
            Object *sram1lpen; // [16:16] SRAM 1interface clock enable during Sleep mode 
            Object *dma1lpen; // [21:21] DMA1 clock enable during Sleep mode 
            Object *dma2lpen; // [22:22] DMA2 clock enable during Sleep mode  
          } ahb1lpenr; 
          
          // AHB2LPENR (AHB2 peripheral clock enable in low power mode register) bitfields.
          struct { 
            Object *otgfslpen; // [7:7] USB OTG FS clock enable during Sleep mode  
          } ahb2lpenr; 
          
          // APB1LPENR (APB1 peripheral clock enable in low power mode register) bitfields.
          struct { 
            Object *tim2lpen; // [0:0] TIM2 clock enable during Sleep mode 
            Object *tim3lpen; // [1:1] TIM3 clock enable during Sleep mode 
            Object *tim4lpen; // [2:2] TIM4 clock enable during Sleep mode 
            Object *tim5lpen; // [3:3] TIM5 clock enable during Sleep mode 
            Object *wwdglpen; // [11:11] Window watchdog clock enable during Sleep mode 
            Object *spi2lpen; // [14:14] SPI2 clock enable during Sleep mode 
            Object *spi3lpen; // [15:15] SPI3 clock enable during Sleep mode 
            Object *usart2lpen; // [17:17] USART2 clock enable during Sleep mode 
            Object *i2c1lpen; // [21:21] I2C1 clock enable during Sleep mode 
            Object *i2c2lpen; // [22:22] I2C2 clock enable during Sleep mode 
            Object *i2c3lpen; // [23:23] I2C3 clock enable during Sleep mode 
            Object *pwrlpen; // [28:28] Power interface clock enable during Sleep mode  
          } apb1lpenr; 
          
          // APB2LPENR (APB2 peripheral clock enabled in low power mode register) bitfields.
          struct { 
            Object *tim1lpen; // [0:0] TIM1 clock enable during Sleep mode 
            Object *usart1lpen; // [4:4] USART1 clock enable during Sleep mode 
            Object *usart6lpen; // [5:5] USART6 clock enable during Sleep mode 
            Object *adc1lpen; // [8:8] ADC1 clock enable during Sleep mode 
            Object *sdiolpen; // [11:11] SDIO clock enable during Sleep mode 
            Object *spi1lpen; // [12:12] SPI 1 clock enable during Sleep mode 
            Object *spi4lpen; // [13:13] SPI4 clock enable during Sleep mode 
            Object *syscfglpen; // [14:14] System configuration controller clock enable during Sleep mode 
            Object *tim9lpen; // [16:16] TIM9 clock enable during sleep mode 
            Object *tim10lpen; // [17:17] TIM10 clock enable during Sleep mode 
            Object *tim11lpen; // [18:18] TIM11 clock enable during Sleep mode  
          } apb2lpenr; 
          
          // BDCR (Backup domain control register) bitfields.
          struct { 
            Object *lseon; // [0:0] External low-speed oscillator enable 
            Object *lserdy; // [1:1] External low-speed oscillator ready 
            Object *lsebyp; // [2:2] External low-speed oscillator bypass 
            Object *rtcsel; // [8:9] RTC clock source selection 
            Object *rtcen; // [15:15] RTC clock enable 
            Object *bdrst; // [16:16] Backup domain software reset  
          } bdcr; 
          
          // CSR (Clock control & status register) bitfields.
          struct { 
            Object *lsion; // [0:0] Internal low-speed oscillator enable 
            Object *lsirdy; // [1:1] Internal low-speed oscillator ready 
            Object *rmvf; // [24:24] Remove reset flag 
            Object *borrstf; // [25:25] BOR reset flag 
            Object *padrstf; // [26:26] PIN reset flag 
            Object *porrstf; // [27:27] POR/PDR reset flag 
            Object *sftrstf; // [28:28] Software reset flag 
            Object *wdgrstf; // [29:29] Independent watchdog reset flag 
            Object *wwdgrstf; // [30:30] Window watchdog reset flag 
            Object *lpwrrstf; // [31:31] Low-power reset flag  
          } csr; 
          
          // SSCGR (Spread spectrum clock generation register) bitfields.
          struct { 
            Object *modper; // [0:12] Modulation period 
            Object *incstep; // [13:27] Incrementation step 
            Object *spreadsel; // [30:30] Spread Select 
            Object *sscgen; // [31:31] Spread spectrum modulation enable  
          } sscgr; 
          
          // PLLI2SCFGR (PLLI2S configuration register) bitfields.
          struct { 
            Object *plli2snx; // [6:14] PLLI2S multiplication factor for VCO 
            Object *plli2srx; // [28:30] PLLI2S division factor for I2S clocks  
          } plli2scfgr; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32RCCState;

// ----------------------------------------------------------------------------

#endif /* STM32_RCC_H_ */
