/*
 * STM32 capabilities definitions.
 *
 * Copyright (c) 2015 Liviu Ionescu.
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

#ifndef STM32_CAPABILITIES_H_
#define STM32_CAPABILITIES_H_

#include <stdint.h>

/**
 * This file defines the members used in the structure used to describe
 * the capabilities of the STM32 MCUs.
 *
 * STM32 MCUs are grouped by families and sub-families.
 */

/**
 * The family is the main differentiator for STM32 MCUs.
 */
typedef enum {
    STM32_FAMILY_UNKNOWN,
    STM32_FAMILY_F0,
    STM32_FAMILY_F1,
    STM32_FAMILY_F2,
    STM32_FAMILY_F3,
    STM32_FAMILY_F4,
    STM32_FAMILY_L1,
} stm32_family_t;

#define STM32_MAX_GPIO  (8)

typedef struct {

    stm32_family_t family;

    /*
     * Properties common to all families
     */
    uint32_t hsi_freq_hz;
    uint32_t lsi_freq_hz;

    uint32_t eeprom_size_kb;
    uint32_t ccm_size_kb; /* size of CCM area, in KB */
    uint32_t back_sram_size_kb; /* size of backup SRAM area, in KB */

    /*
     * Peripherals common to all families.
     */
    unsigned int has_rcc :1;
    unsigned int has_pwr :1;

    /* GPIOs */
    unsigned int has_gpioa :1;
    unsigned int has_gpiob :1;
    unsigned int has_gpioc :1;
    unsigned int has_gpiod :1;
    unsigned int has_gpioe :1;
    unsigned int has_gpiof :1;
    unsigned int has_gpiog :1;
    unsigned int has_gpioh :1; /* Used by L1 */
    unsigned int has_gpioi :1; /* Used by F4 */

    /* EXTI */
    unsigned int has_exti :1;
    /* DMA */
    unsigned int has_dma :1;
    unsigned int has_dma1 :1;
    unsigned int has_dma2 :1;

    /* Advanced control timers */
    unsigned int has_ac_tim1 :1;
    unsigned int has_ac_tim8 :1;
    /* General-purpose timers */
    unsigned int has_gp_tim2 :1;
    unsigned int has_gp_tim5 :1;
    /* General-purpose timers */
    unsigned int has_gp_tim3 :1;
    unsigned int has_gp_tim4 :1;
    /* General-purpose timers */
    unsigned int has_gp_tim9 :1;
    unsigned int has_gp_tim12 :1;
    /* General-purpose timers */
    unsigned int has_gp_tim10 :1;
    unsigned int has_gp_tim11 :1;
    unsigned int has_gp_tim13 :1;
    unsigned int has_gp_tim14 :1;
    /* Basic timers */
    unsigned int has_bc_tim6 :1;
    unsigned int has_bc_tim7 :1;
    /* Watchdogs */
    unsigned int has_iwdg :1;
    unsigned int has_wwdg :1;

    /* I2C */
    unsigned int has_i2c :1;
    unsigned int has_i2c1 :1;
    unsigned int has_i2c2 :1;
    unsigned int has_i2c3 :1;

    /* Universal synchronous/asynchronous */
    unsigned int has_usart1 :1;
    unsigned int has_usart2 :1;
    unsigned int has_usart3 :1;
    unsigned int has_usart6 :1;
    /* Universal asynchronous */
    unsigned int has_uart4 :1;
    unsigned int has_uart5 :1;

    /* SPI */
    unsigned int has_spi1 :1;
    unsigned int has_spi2 :1;
    unsigned int has_spi3 :1;

    /* I2S */
    unsigned int has_i2s1 :1;
    unsigned int has_i2s2 :1;

    unsigned int has_plli2s :1;

    /* Memory */
    unsigned int has_fsmc :1;

    /* SDIO */
    unsigned int has_sdio :1;

    /* Ethernet */
    unsigned int has_eth :1;
    /* CAN */
    unsigned int has_bx_can1 :1;
    unsigned int has_bx_can2 :1;
    unsigned int has_can1 :1;
    unsigned int has_can2 :1;
    /* ADC */
    unsigned int has_adc :1;
    unsigned int has_adc1 :1;
    unsigned int has_adc2 :1;
    unsigned int has_adc3 :1;
    /* DAC */
    unsigned int has_dac :1;
    unsigned int has_dac1 :1;
    unsigned int has_dac2 :1;
    /* USB */
    unsigned int has_usb_fs :1;
    unsigned int has_usb_otg_fs :1;
    unsigned int has_usb_otg_hs :1;

    /* RTC */
    unsigned int has_rtc :1;

    /* CRC */
    unsigned int has_crc :1;

    /* Temperature sensor */
    unsigned int has_ts :1;

    unsigned int has_dcmi :1;
    unsigned int has_rng :1;

    /* Keep them together */
    unsigned char num_exti;
    unsigned char num_dma1;
    unsigned char num_dma2;
    unsigned char num_dma;

    /* Number of backup bytes */
    uint32_t num_back_bytes;



    /*
     * Note: the family definitions are mutual exclusive, and could
     * be packed in a union, but this makes writing the definitions
     * more complicated and was discarded.
     * The memory penalty is not significant.
     */
    struct {
        unsigned int is_ld :1; /* is low density */
        unsigned int is_md :1; /* is medium density */
        unsigned int is_hd :1; /* is high density */
        unsigned int is_xd :1; /* is extra density */
        unsigned int is_cl :1; /* is Connectivity Line */
        unsigned int is_ldvl :1; /* is low density */
        unsigned int is_mdvl :1; /* is medium density */
        unsigned int is_hdvl :1; /* is high density */

    } f1;

    struct {
        unsigned int is_01_57_xx :1;
        unsigned int is_23_xxx :1;
    } f4;
    /* TODO: add other families that have sub-families. */

} STM32Capabilities;

#endif /* STM32_CAPABILITIES_H_ */
