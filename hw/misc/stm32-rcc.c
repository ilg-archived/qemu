/*
 * STM32 MCU - RCC (Reset and Clock Control).
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

#include "hw/misc/stm32-rcc.h"
#include "hw/arm/cortexm-helper.h"

/**
 * This file implements the STM32 RCC (Reset and Clock Control).
 *
 * The initial implementation is intended only to pass CMSIS initialisations.
 * This means all writes store the correct values and all reads return the
 * written values.
 * Status bits (like PLL ready) are set during the writes, so all application
 * loops waiting for those events will complete immediately.
 * Clock trees and the bits to enable peripheral clocks are not yet used by
 * the peripherals.
 *
 * References:
 * - ST CD00171190.pdf, Doc ID 13902 Rev 15, "RM0008 Reference Manual,
 * STM32F101xx, STM32F102xx, STM32F103xx, STM32F105xx and STM32F107xx
 * advanced ARM®-based 32-bit MCUs"
 *
 * All STM32 reference manuals available from:
 * http://www.st.com/stonline/stappl/resourceSelector/\
 * app?page=fullResourceSelector&doctype=reference_manual&FamilyID=141
 */

static void stm32_rcc_update_clocks(STM32RCCState *state);

/* ------------------------------------------------------------------------- */

static void stm32f1_rcc_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value)
{
    STM32RCCState *state = STM32_RCC_STATE(periph);
    stm32_rcc_update_clocks(state);
}

/* ------------------------------------------------------------------------- */

/* STM32F1[LMHX]D */

static PeripheralRegisterInfo stm32f1_rcc_cr_info = {
    .desc = "Clock control register (RCC_CR)",
    .offset_bytes = 0x00,
    .reset_value = 0x00000083,
    .reset_mask = 0xFFFF00FF,
    .post_write = stm32f1_rcc_post_write_callback,
    .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "hsion",
                    .desc = "Internal high-speed clock enable",
                    .first_bit = 0, },
                {
                    .name = "hsirdy",
                    .desc = "Internal high-speed clock ready flag",
                    .first_bit = 1,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .follows = "hsion", },
                {
                    .name = "hsitrim",
                    .desc = "Internal high-speed clock trimming",
                    .first_bit = 3,
                    .width_bits = 5, },
                {
                    .name = "hsical",
                    .desc = "Internal high-speed clock calibration",
                    .first_bit = 8,
                    .width_bits = 8,
                    .rw_mode = REGISTER_RW_MODE_READ, },
                {
                    .name = "hseon",
                    .desc = "External clock enable",
                    .first_bit = 16, },
                {
                    .name = "hserdy",
                    .desc = "External high-speed clock ready flag",
                    .first_bit = 17,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .follows = "hseon", },
                {
                    .name = "hsebyp",
                    .desc = "External high-speed clock bypass",
                    .first_bit = 18, },
                {
                    .name = "csson",
                    .desc = "Clock security system enable",
                    .first_bit = 19, },
                {
                    .name = "pllon",
                    .desc = "PLL enable",
                    .first_bit = 24, },
                {
                    .name = "pllrdy",
                    .desc = "PLL clock ready flag",
                    .first_bit = 25,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .follows = "pllon", },
                { }, /**/
            } , /**/
};

static PeripheralRegisterInfo stm32f1_rcc_cfgr_info = {
    .desc = "Clock configuration register (RCC_CFGR)",
    .offset_bytes = 0x04,
    .reset_value = 0x00000000,
    .post_write = stm32f1_rcc_post_write_callback,
    .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "sw",
                    .desc = "System clock switch",
                    .first_bit = 0,
                    .width_bits = 2, },
                {
                    .name = "sws",
                    .desc = "System clock switch status",
                    .first_bit = 2,
                    .width_bits = 2,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .follows = "sw", },
                {
                    .name = "hpre",
                    .desc = "AHB prescaler",
                    .first_bit = 4,
                    .width_bits = 4, },
                {
                    .name = "ppre1",
                    .desc = "APB low-speed prescaler (APB1)",
                    .first_bit = 8,
                    .width_bits = 3, },
                {
                    .name = "ppre2",
                    .desc = "APB high-speed prescaler (APB2)",
                    .first_bit = 11,
                    .width_bits = 3, },
                {
                    .name = "adcpre",
                    .desc = "ADC prescaler",
                    .first_bit = 14,
                    .width_bits = 2, },
                {
                    .name = "pllsrc",
                    .desc = "PLL entry clock source",
                    .first_bit = 16, },
                {
                    .name = "pllxtpre",
                    .desc = "HSE divider for PLL entry",
                    .first_bit = 17, },
                {
                    .name = "pllmul",
                    .desc = "PLL multiplication factor",
                    .first_bit = 18,
                    .width_bits = 4, },
                {
                    .name = "usbpre",
                    .desc = "USB prescaler",
                    .first_bit = 22, },
                {
                    .name = "mco",
                    .desc = "Microcontroller clock output",
                    .first_bit = 24,
                    .width_bits = 3, },
                { }, /**/
            } , /**/
};

static PeripheralRegisterInfo stm32f1_rcc_cir_info = {
    .desc = "Clock interrupt register (RCC_CIR)",
    .offset_bytes = 0x08,
    .reset_value = 0x00000000,
    .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "lsirdyf",
                    .desc = "LSI ready interrupt flag",
                    .first_bit = 0,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .cleared_by = "lsirdyc", },
                {
                    .name = "lserdyf",
                    .desc = "LSE ready interrupt flag",
                    .first_bit = 1,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .cleared_by = "lserdyc", },
                {
                    .name = "hsirdyf",
                    .desc = "HSI ready interrupt flag",
                    .first_bit = 2,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .cleared_by = "hsirdyc", },
                {
                    .name = "hserdyf",
                    .desc = "HSE ready interrupt flag",
                    .first_bit = 3,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .cleared_by = "hserdyc", },
                {
                    .name = "pllrdyf",
                    .desc = "PLL ready interrupt flag",
                    .first_bit = 4,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .cleared_by = "pllrdyc", },
                {
                    .name = "cssf",
                    .desc = "Clock security system interrupt flag",
                    .first_bit = 7,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .cleared_by = "cssc", },
                {
                    .name = "lsirdyie",
                    .desc = "LSI ready interrupt enable",
                    .first_bit = 8, },
                {
                    .name = "lserdyie",
                    .desc = "LSE ready interrupt enable",
                    .first_bit = 9, },
                {
                    .name = "hsirdyie",
                    .desc = "HSI ready interrupt enable",
                    .first_bit = 10, },
                {
                    .name = "hserdyie",
                    .desc = "HSE ready interrupt enable",
                    .first_bit = 11, },
                {
                    .name = "pllrdyie",
                    .desc = "PLL ready interrupt enable",
                    .first_bit = 12, },
                {
                    .name = "lsirdyc",
                    .desc = "LSI ready interrupt clear",
                    .first_bit = 16,
                    .rw_mode = REGISTER_RW_MODE_WRITE, },
                {
                    .name = "lserdyc",
                    .desc = "LSE ready interrupt clear",
                    .first_bit = 17,
                    .rw_mode = REGISTER_RW_MODE_WRITE, },
                {
                    .name = "hsirdyc",
                    .desc = "HSI ready interrupt clear",
                    .first_bit = 18,
                    .rw_mode = REGISTER_RW_MODE_WRITE, },
                {
                    .name = "hserdyc",
                    .desc = "HSE ready interrupt clear",
                    .first_bit = 19,
                    .rw_mode = REGISTER_RW_MODE_WRITE, },
                {
                    .name = "pllrdyc",
                    .desc = "PLL ready interrupt clear",
                    .first_bit = 20,
                    .rw_mode = REGISTER_RW_MODE_WRITE, },
                {
                    .name = "cssc",
                    .desc = "Clock security system interrupt clear",
                    .first_bit = 23,
                    .rw_mode = REGISTER_RW_MODE_WRITE, },
                { }, /**/
            } , /**/
};

static PeripheralRegisterInfo stm32f1_rcc_apb2rstr_info = {
    .desc = "APB2 peripheral reset register (RCC_APB2RSTR)",
    .offset_bytes = 0x0C,
    .reset_value = 0x00000000,
    .readable_bits = 0x0038FFFD,
    .writable_bits = 0x0038FFFD, };

static PeripheralRegisterInfo stm32f1_rcc_apb1rstr_info = {
    .desc = "APB1 peripheral reset register (RCC_APB1RSTR)",
    .offset_bytes = 0x10,
    .reset_value = 0x00000000,
    .readable_bits = 0x3AFEC9FF,
    .writable_bits = 0x3AFEC9FF, };

static PeripheralRegisterInfo stm32f1_rcc_ahbenr_info = {
    .desc = "AHB peripheral clock enable register (RCC_AHBENR)",
    .offset_bytes = 0x14,
    .reset_value = 0x00000000,
    .readable_bits = 0x00000557,
    .writable_bits = 0x00000557, };

static PeripheralRegisterInfo stm32f1_rcc_apb2enr_info = {
    .desc = "APB2 peripheral clock enable register (RCC_APB2ENR)",
    .offset_bytes = 0x18,
    .reset_value = 0x00000000,
    .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "afioen",
                    .desc = "Alternate function IO clock enable",
                    .first_bit = 0, },
                {
                    .name = "iopaen",
                    .desc = "IO port A clock enable",
                    .first_bit = 2, },
                {
                    .name = "iopben",
                    .desc = "IO port B clock enable",
                    .first_bit = 3, },
                {
                    .name = "iopcen",
                    .desc = "IO port C clock enable",
                    .first_bit = 4, },
                {
                    .name = "iopden",
                    .desc = "IO port D clock enable",
                    .first_bit = 5, },
                {
                    .name = "iopeen",
                    .desc = "IO port E clock enable",
                    .first_bit = 6, },
                {
                    .name = "iopfen",
                    .desc = "IO port F clock enable",
                    .first_bit = 7, },
                {
                    .name = "iopgen",
                    .desc = "IO port G clock enable",
                    .first_bit = 8, },
                {
                    .name = "adc1en",
                    .desc = "ADC1 interface clock enable",
                    .first_bit = 9, },
                {
                    .name = "adc2en",
                    .desc = "ADC2 interface clock enable",
                    .first_bit = 10, },
                {
                    .name = "tim1en",
                    .desc = "TIM1 timer clock enable",
                    .first_bit = 11, },
                {
                    .name = "spi1en",
                    .desc = "SPI1 clock enable",
                    .first_bit = 12, },
                {
                    .name = "tim8en",
                    .desc = "TIM8 timer clock enable",
                    .first_bit = 13, },
                {
                    .name = "usart1en",
                    .desc = "USART1 clock enable",
                    .first_bit = 14, },
                {
                    .name = "adc3en",
                    .desc = "ADC3 interface clock enable",
                    .first_bit = 15, },
                {
                    .name = "tim9en",
                    .desc = "TIM9 timer clock enable",
                    .first_bit = 19, },
                {
                    .name = "tim10en",
                    .desc = "TIM10 timer clock enable",
                    .first_bit = 20, },
                {
                    .name = "tim11en",
                    .desc = "TIM11 timer clock enable",
                    .first_bit = 21, },
                { }, /**/
            } , /**/
};

static PeripheralRegisterInfo stm32f1_rcc_apb1enr_info = {
    .desc = "APB1 peripheral clock enable register (RCC_APB1ENR)",
    .offset_bytes = 0x1C,
    .reset_value = 0x00000000,
    .readable_bits = 0x3AFEC9FF,
    .writable_bits = 0x3AFEC9FF, };

static PeripheralRegisterInfo stm32f1_rcc_bdcr_info = {
    .desc = "Backup domain control register (RCC_BDCR)",
    .offset_bytes = 0x20,
    .reset_value = 0x00000000,
    .post_write = stm32f1_rcc_post_write_callback,
    .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "lseon",
                    .desc = "External low-speed oscillator enable",
                    .first_bit = 0, },
                {
                    .name = "lserdy",
                    .desc = "External low-speed oscillator ready",
                    .first_bit = 1,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .follows = "lseon", },
                {
                    .name = "lsebyp",
                    .desc = "External low-speed oscillator bypass",
                    .first_bit = 2, },
                {
                    .name = "rtcsel",
                    .desc = "RTC clock source selection",
                    .first_bit = 8,
                    .width_bits = 2, },
                {
                    .name = "rtcen",
                    .desc = "RTC clock enable",
                    .first_bit = 15, },
                {
                    .name = "bdrst",
                    .desc = "Backup domain software reset",
                    .first_bit = 16, },
                { }, /**/
            } , /**/
};

static PeripheralRegisterInfo stm32f1_rcc_csr_info = {
    .desc = "Control/status register (RCC_CSR)",
    .offset_bytes = 0x24,
    .reset_value = 0x0C000000,
    .post_write = stm32f1_rcc_post_write_callback,
    .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "lsion",
                    .desc = "Internal low-speed oscillator enable",
                    .first_bit = 0, },
                {
                    .name = "lsirdy",
                    .desc = "Internal low-speed oscillator ready",
                    .first_bit = 1,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .follows = "lsion", },
                {
                    .name = "rmvf",
                    .desc = "Remove reset flag",
                    .first_bit = 24, },
                {
                    .name = "pinrstf",
                    .desc = "PIN reset flag",
                    .first_bit = 26,
                    .cleared_by = "rmvf", },
                {
                    .name = "porrstf",
                    .desc = "POR/PDR reset flag",
                    .first_bit = 27,
                    .cleared_by = "rmvf", },
                {
                    .name = "stfrstf",
                    .desc = "Software reset flag",
                    .first_bit = 28,
                    .cleared_by = "rmvf", },
                {
                    .name = "iwdgrstf",
                    .desc = "Independent watchdog reset flag",
                    .first_bit = 29,
                    .cleared_by = "rmvf", },
                {
                    .name = "wwdgrstf",
                    .desc = "Window watchdog reset flag",
                    .first_bit = 30,
                    .cleared_by = "rmvf", },
                {
                    .name = "lrwrrstf",
                    .desc = "Low-power reset flag",
                    .first_bit = 31,
                    .cleared_by = "rmvf", },
                { }, /**/
            } , /**/
};

/* ------------------------------------------------------------------------- */

/* STM32F1CL */

static PeripheralRegisterInfo stm32f1cl_rcc_cr_info = {
    .desc = "Clock control register (RCC_CR)",
    .offset_bytes = 0x00,
    .reset_value = 0x00000083,
    .reset_mask = 0xFFFF00FF,
    .post_write = stm32f1_rcc_post_write_callback,
    .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "hsion",
                    .desc = "Internal high-speed clock enable",
                    .first_bit = 0, },
                {
                    .name = "hsirdy",
                    .desc = "Internal high-speed clock ready flag",
                    .first_bit = 1,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .follows = "hsion", },
                {
                    .name = "hsitrim",
                    .desc = "Internal high-speed clock trimming",
                    .first_bit = 3,
                    .width_bits = 5, },
                {
                    .name = "hsical",
                    .desc = "Internal high-speed clock calibration",
                    .first_bit = 8,
                    .width_bits = 8,
                    .rw_mode = REGISTER_RW_MODE_READ, },
                {
                    .name = "hseon",
                    .desc = "External clock enable",
                    .first_bit = 16, },
                {
                    .name = "hserdy",
                    .desc = "External high-speed clock ready flag",
                    .first_bit = 17,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .follows = "hseon", },
                {
                    .name = "hsebyp",
                    .desc = "External high-speed clock bypass",
                    .first_bit = 18, },
                {
                    .name = "csson",
                    .desc = "Clock security system enable",
                    .first_bit = 19, },
                {
                    .name = "pllon",
                    .desc = "PLL enable",
                    .first_bit = 24, },
                {
                    .name = "pllrdy",
                    .desc = "PLL clock ready flag",
                    .first_bit = 25,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .follows = "pllon", },
                {
                    .name = "pll2on",
                    .desc = "PLL2 enable",
                    .first_bit = 26, },
                {
                    .name = "pll2rdy",
                    .desc = "PLL2 clock ready flag",
                    .first_bit = 27,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .follows = "pll2on", },
                {
                    .name = "pll3on",
                    .desc = "PLL3 enable",
                    .first_bit = 28, },
                {
                    .name = "pll3rdy",
                    .desc = "PLL3 clock ready flag",
                    .first_bit = 29,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .follows = "pll3on", },
                { }, /**/
            } , /**/
};

static PeripheralRegisterInfo stm32f1cl_rcc_cfgr_info = {
    .desc = "Clock configuration register (RCC_CFGR)",
    .offset_bytes = 0x04,
    .reset_value = 0x00000000,
    .post_write = stm32f1_rcc_post_write_callback,
    .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "sw",
                    .desc = "System clock switch",
                    .first_bit = 0,
                    .width_bits = 2, },
                {
                    .name = "sws",
                    .desc = "System clock switch status",
                    .first_bit = 2,
                    .width_bits = 2,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .follows = "sw", },
                {
                    .name = "hpre",
                    .desc = "AHB prescaler",
                    .first_bit = 4,
                    .width_bits = 4, },
                {
                    .name = "ppre1",
                    .desc = "APB low-speed prescaler (APB1)",
                    .first_bit = 8,
                    .width_bits = 3, },
                {
                    .name = "ppre2",
                    .desc = "APB high-speed prescaler (APB2)",
                    .first_bit = 11,
                    .width_bits = 3, },
                {
                    .name = "adcpre",
                    .desc = "ADC prescaler",
                    .first_bit = 14,
                    .width_bits = 2, },
                {
                    .name = "pllsrc",
                    .desc = "PLL entry clock source",
                    .first_bit = 16, },
                {
                    .name = "pllxtpre",
                    .desc = "HSE divider for PLL entry",
                    .first_bit = 17, },
                {
                    .name = "pllmul",
                    .desc = "PLL multiplication factor",
                    .first_bit = 18,
                    .width_bits = 4, },
                {
                    .name = "otgfspre",
                    .desc = "OTG FS prescaler",
                    .first_bit = 22, },
                {
                    .name = "mco",
                    .desc = "Microcontroller clock output",
                    .first_bit = 24,
                    .width_bits = 3, },
                { }, /**/
            } , /**/
};

static PeripheralRegisterInfo stm32f1cl_rcc_cir_info = {
    .desc = "Clock interrupt register (RCC_CIR)",
    .offset_bytes = 0x08,
    .reset_value = 0x00000000,
    .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "lsirdyf",
                    .desc = "LSI ready interrupt flag",
                    .first_bit = 0,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .cleared_by = "lsirdyc", },
                {
                    .name = "lserdyf",
                    .desc = "LSE ready interrupt flag",
                    .first_bit = 1,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .cleared_by = "lserdyc", },
                {
                    .name = "hsirdyf",
                    .desc = "HSI ready interrupt flag",
                    .first_bit = 2,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .cleared_by = "hsirdyc", },
                {
                    .name = "hserdyf",
                    .desc = "HSE ready interrupt flag",
                    .first_bit = 3,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .cleared_by = "hserdyc", },
                {
                    .name = "pllrdyf",
                    .desc = "PLL ready interrupt flag",
                    .first_bit = 4,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .cleared_by = "pllrdyc", },
                {
                    .name = "pll2rdyf",
                    .desc = "PLL2 ready interrupt flag",
                    .first_bit = 5,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .cleared_by = "pll2rdyc", },
                {
                    .name = "pll3rdyf",
                    .desc = "PLL3 ready interrupt flag",
                    .first_bit = 6,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .cleared_by = "pll3rdyc", },
                {
                    .name = "cssf",
                    .desc = "Clock security system interrupt flag",
                    .first_bit = 7,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .cleared_by = "cssc", },
                {
                    .name = "lsirdyie",
                    .desc = "LSI ready interrupt enable",
                    .first_bit = 8, },
                {
                    .name = "lserdyie",
                    .desc = "LSE ready interrupt enable",
                    .first_bit = 9, },
                {
                    .name = "hsirdyie",
                    .desc = "HSI ready interrupt enable",
                    .first_bit = 10, },
                {
                    .name = "hserdyie",
                    .desc = "HSE ready interrupt enable",
                    .first_bit = 11, },
                {
                    .name = "pllrdyie",
                    .desc = "PLL ready interrupt enable",
                    .first_bit = 12, },
                {
                    .name = "pll2rdyie",
                    .desc = "PLL2 ready interrupt enable",
                    .first_bit = 13, },
                {
                    .name = "pll3rdyie",
                    .desc = "PLL3 ready interrupt enable",
                    .first_bit = 14, },
                {
                    .name = "lsirdyc",
                    .desc = "LSI ready interrupt clear",
                    .first_bit = 16,
                    .rw_mode = REGISTER_RW_MODE_WRITE, },
                {
                    .name = "lserdyc",
                    .desc = "LSE ready interrupt clear",
                    .first_bit = 17,
                    .rw_mode = REGISTER_RW_MODE_WRITE, },
                {
                    .name = "hsirdyc",
                    .desc = "HSI ready interrupt clear",
                    .first_bit = 18,
                    .rw_mode = REGISTER_RW_MODE_WRITE, },
                {
                    .name = "hserdyc",
                    .desc = "HSE ready interrupt clear",
                    .first_bit = 19,
                    .rw_mode = REGISTER_RW_MODE_WRITE, },
                {
                    .name = "pllrdyc",
                    .desc = "PLL ready interrupt clear",
                    .first_bit = 20,
                    .rw_mode = REGISTER_RW_MODE_WRITE, },
                {
                    .name = "pll2rdyc",
                    .desc = "PLL2 ready interrupt clear",
                    .first_bit = 21,
                    .rw_mode = REGISTER_RW_MODE_WRITE, },
                {
                    .name = "pll3rdyc",
                    .desc = "PLL3 ready interrupt clear",
                    .first_bit = 22,
                    .rw_mode = REGISTER_RW_MODE_WRITE, },
                {
                    .name = "cssc",
                    .desc = "Clock security system interrupt clear",
                    .first_bit = 23,
                    .rw_mode = REGISTER_RW_MODE_WRITE, },
                { }, /**/
            } , /**/
};

static PeripheralRegisterInfo stm32f1cl_rcc_apb2rstr_info = {
    .desc = "APB2 peripheral reset register (RCC_APB2RSTR)",
    .offset_bytes = 0x0C,
    .reset_value = 0x00000000,
    .readable_bits = 0x00005E7D,
    .writable_bits = 0x00005E7D, };

static PeripheralRegisterInfo stm32f1cl_rcc_apb1rstr_info = {
    .desc = "APB1 peripheral reset register (RCC_APB1RSTR)",
    .offset_bytes = 0x10,
    .reset_value = 0x00000000,
    .readable_bits = 0x377EC83F,
    .writable_bits = 0x377EC83F, };

static PeripheralRegisterInfo stm32f1cl_rcc_ahbenr_info = {
    .desc = "AHB peripheral clock enable register (RCC_AHBENR)",
    .offset_bytes = 0x14,
    .reset_value = 0x00000000,
    .readable_bits = 0x0001D057,
    .writable_bits = 0x0001D057, };

static PeripheralRegisterInfo stm32f1cl_rcc_apb2enr_info = {
    .desc = "APB2 peripheral clock enable register (RCC_APB2ENR)",
    .offset_bytes = 0x18,
    .reset_value = 0x00000000,
    .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "afioen",
                    .desc = "Alternate function IO clock enable",
                    .first_bit = 0, },
                {
                    .name = "iopaen",
                    .desc = "IO port A clock enable",
                    .first_bit = 2, },
                {
                    .name = "iopben",
                    .desc = "IO port B clock enable",
                    .first_bit = 3, },
                {
                    .name = "iopcen",
                    .desc = "IO port C clock enable",
                    .first_bit = 4, },
                {
                    .name = "iopden",
                    .desc = "IO port D clock enable",
                    .first_bit = 5, },
                {
                    .name = "iopeen",
                    .desc = "IO port E clock enable",
                    .first_bit = 6, },
                {
                    .name = "adc1en",
                    .desc = "ADC1 interface clock enable",
                    .first_bit = 9, },
                {
                    .name = "adc2en",
                    .desc = "ADC2 interface clock enable",
                    .first_bit = 10, },
                {
                    .name = "tim1en",
                    .desc = "TIM1 timer clock enable",
                    .first_bit = 11, },
                {
                    .name = "spi1en",
                    .desc = "SPI1 clock enable",
                    .first_bit = 12, },
                {
                    .name = "usart1en",
                    .desc = "USART1 clock enable",
                    .first_bit = 14, },
                { }, /**/
            } , /**/
};

static PeripheralRegisterInfo stm32f1cl_rcc_apb1enr_info = {
    .desc = "APB1 peripheral clock enable register (RCC_APB1ENR)",
    .offset_bytes = 0x1C,
    .reset_value = 0x00000000,
    .readable_bits = 0x3E7EC83F,
    .writable_bits = 0x3E7EC83F, };

static PeripheralRegisterInfo stm32f1cl_rcc_bdcr_info = {
    .desc = "Backup domain control register (RCC_BDCR)",
    .offset_bytes = 0x20,
    .reset_value = 0x00000000,
    .post_write = stm32f1_rcc_post_write_callback,
    .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "lseon",
                    .desc = "External low-speed oscillator enable",
                    .first_bit = 0, },
                {
                    .name = "lserdy",
                    .desc = "External low-speed oscillator ready",
                    .first_bit = 1,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .follows = "lseon", },
                {
                    .name = "lsebyp",
                    .desc = "External low-speed oscillator bypass",
                    .first_bit = 2, },
                {
                    .name = "rtcsel",
                    .desc = "RTC clock source selection",
                    .first_bit = 8,
                    .width_bits = 2, },
                {
                    .name = "rtcen",
                    .desc = "RTC clock enable",
                    .first_bit = 15, },
                {
                    .name = "bdrst",
                    .desc = "Backup domain software reset",
                    .first_bit = 16, },
                { }, /**/
            } , /**/
};

static PeripheralRegisterInfo stm32f1cl_rcc_csr_info = {
    .desc = "Control/status register (RCC_CSR)",
    .offset_bytes = 0x24,
    .reset_value = 0x0C000000,
    .post_write = stm32f1_rcc_post_write_callback,
    .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "lsion",
                    .desc = "Internal low-speed oscillator enable",
                    .first_bit = 0, },
                {
                    .name = "lsirdy",
                    .desc = "Internal low-speed oscillator ready",
                    .first_bit = 1,
                    .rw_mode = REGISTER_RW_MODE_READ,
                    .follows = "lsion", },
                {
                    .name = "rmvf",
                    .desc = "Remove reset flag",
                    .first_bit = 24, },
                {
                    .name = "pinrstf",
                    .desc = "PIN reset flag",
                    .first_bit = 26,
                    .cleared_by = "rmvf", },
                {
                    .name = "porrstf",
                    .desc = "POR/PDR reset flag",
                    .first_bit = 27,
                    .cleared_by = "rmvf", },
                {
                    .name = "stfrstf",
                    .desc = "Software reset flag",
                    .first_bit = 28,
                    .cleared_by = "rmvf", },
                {
                    .name = "iwdgrstf",
                    .desc = "Independent watchdog reset flag",
                    .first_bit = 29,
                    .cleared_by = "rmvf", },
                {
                    .name = "wwdgrstf",
                    .desc = "Window watchdog reset flag",
                    .first_bit = 30,
                    .cleared_by = "rmvf", },
                {
                    .name = "lrwrrstf",
                    .desc = "Low-power reset flag",
                    .first_bit = 31,
                    .cleared_by = "rmvf", },
                { }, /**/
            } , /**/
};

static PeripheralRegisterInfo stm32f1cl_rcc_ahbrstr_info = {
    .desc = "AHB peripheral clock reset register (RCC_AHBRSTR)",
    .offset_bytes = 0x28,
    .reset_value = 0x00000000,
    .readable_bits = 0x00005000,
    .writable_bits = 0x00005000, };

static PeripheralRegisterInfo stm32f1cl_rcc_cfgr2_info = {
    .desc = "Clock configuration register2 (RCC_CFGR2)",
    .offset_bytes = 0x2C,
    .reset_value = 0x00000000,
    .post_write = stm32f1_rcc_post_write_callback,
    .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "prediv1",
                    .desc = "PREDIV1 division factor",
                    .first_bit = 0,
                    .width_bits = 4, },
                {
                    .name = "prediv2",
                    .desc = "PREDIV2 division factor",
                    .first_bit = 4,
                    .width_bits = 4, },
                {
                    .name = "pll2mul",
                    .desc = "PLL2 Multiplication factor",
                    .first_bit = 8,
                    .width_bits = 4, },
                {
                    .name = "pll3mul",
                    .desc = "PLL3 Multiplication factor",
                    .first_bit = 12,
                    .width_bits = 4, },
                {
                    .name = "prediv1src",
                    .desc = "PREDIV1 entry clock source",
                    .first_bit = 16, },
                {
                    .name = "i2s2src",
                    .desc = "I2S2 clock source",
                    .first_bit = 17, },
                {
                    .name = "i2s3src",
                    .desc = "I2S2 clock source",
                    .first_bit = 18, },
                { }, /**/
            } , /**/
};

/* ------------------------------------------------------------------------- */

static uint8_t AHBPrescTable[16] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    2,
    3,
    4,
    6,
    7,
    8,
    9 };

extern int system_clock_scale;

/**
 * Recompute the system clock, after each change in the RCC registers.
 * The code is inspired by CMSIS init sequences.
 */
static void stm32_rcc_update_clocks(STM32RCCState *state)
{
    const STM32Capabilities *capabilities = state->capabilities;

    uint32_t cpu_freq_hz = 0;

    switch (capabilities->family) {
    case STM32_FAMILY_F1:

        /* The following code was copied from the CMSIS system_stm32f10x.c  */

        switch (register_bitfield_read_value(state->f1.cfgr.sws)) {
        case 0:
            /* HSI used as system clock. */
            cpu_freq_hz = state->hsi_freq_hz;
            break;

        case 1:
            /* HSE used as system clock. */
            cpu_freq_hz = state->hse_freq_hz;
            break;

        case 2:
            /* PLL used as system clock. */
            if (!capabilities->f1.is_cl) {
                /* Most F1 families, except CL. */

                /* Get PLL clock source and multiplication factor. */
                uint32_t pllmul = register_bitfield_read_value(
                        state->f1.cfgr.pllmul) + 2;
                if (register_bitfield_is_zero(state->f1.cfgr.pllsrc)) {
                    /* HSI oscillator clock divided by 2 selected as PLL
                     * clock entry */
                    cpu_freq_hz = (state->hsi_freq_hz >> 1) * pllmul;
                } else {
                    if (capabilities->f1.is_ldvl || capabilities->f1.is_mdvl
                            || capabilities->f1.is_hdvl) {
                        /* The value line families use the CFGR2. */
                        uint32_t prediv1factor = 0;
                        prediv1factor = register_bitfield_read_value(
                                state->f1.cfgr2.prediv1) + 1;
                        /*
                         * HSE oscillator clock selected as PREDIV1
                         * clock entry.
                         */
                        cpu_freq_hz = (state->hse_freq_hz / prediv1factor)
                                * pllmul;
                    } else {
                        /* HSE selected as PLL clock entry. */
                        if (!register_bitfield_is_zero(
                                state->f1.cfgr.pllxtpre)) {
                            /* HSE oscillator clock divided by 2. */
                            cpu_freq_hz = (state->hse_freq_hz >> 1) * pllmul;
                        } else {
                            cpu_freq_hz = state->hse_freq_hz * pllmul;
                        }
                    }
                }
            } else {
                /* The F1 CL family. */
                uint32_t pllmul = register_bitfield_read_value(
                        state->f1.cfgr.pllmul);

                if (pllmul != 13) {
                    pllmul += 2;
                } else {
                    /* PLL multiplication factor = PLL input clock * 6.5 */
                    pllmul = 13 / 2;
                }

                if (register_bitfield_is_zero(state->f1.cfgr.pllsrc)) {
                    /*
                     * HSI oscillator clock divided by 2 selected as PLL
                     * clock entry.
                     */
                    cpu_freq_hz = (state->hsi_freq_hz >> 1) * pllmul;
                } else {
                    /*
                     * PREDIV1 selected as PLL clock entry.
                     * Get PREDIV1 clock source and division factor.
                     */
                    uint32_t prediv1factor = register_bitfield_read_value(
                            state->f1.cfgr2.prediv1) + 1;

                    if (register_bitfield_is_zero(state->f1.cfgr2.prediv1src)) {
                        /*
                         * HSE oscillator clock selected as PREDIV1
                         * clock entry.
                         */
                        cpu_freq_hz = (state->hse_freq_hz / prediv1factor)
                                * pllmul;
                    } else {
                        /*
                         * PLL2 clock selected as PREDIV1 clock entry.
                         * Get PREDIV2 division factor and PLL2
                         * multiplication factor.
                         */
                        uint32_t prediv2factor = register_bitfield_read_value(
                                state->f1.cfgr2.prediv2) + 1;
                        uint32_t pll2mull = register_bitfield_read_value(
                                state->f1.cfgr2.pll2mul) + 2;
                        cpu_freq_hz = (((state->hse_freq_hz / prediv2factor)
                                * pll2mull) / prediv1factor) * pllmul;
                    }
                }
            }
            break;

        default:
            cpu_freq_hz = state->hsi_freq_hz;
            break;
        }

        /*
         * Compute HCLK clock frequency. Get HCLK pre-scaler.
         */
        int pre_scaler = AHBPrescTable[register_bitfield_read_value(
                state->f1.cfgr.hpre)];
        /* HCLK clock frequency */
        cpu_freq_hz >>= pre_scaler;

        break;
    default:
        break;
    }

    if (cpu_freq_hz == 0) {
        cpu_freq_hz = state->hsi_freq_hz; /* Should be non-zero. */
    }
    state->cpu_freq_hz = cpu_freq_hz;

    system_clock_scale = get_ticks_per_sec() / cpu_freq_hz;
    if (system_clock_scale == 0) {
        system_clock_scale = 1;
    }
    qemu_log_mask(LOG_TRACE, "%s() %d, system_clock_scale=%d\n", __FUNCTION__,
            cpu_freq_hz, system_clock_scale);
}

/* ------------------------------------------------------------------------- */

static void stm32_rcc_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32RCCState *state = STM32_RCC_STATE(obj);

    cm_object_property_add_uint32(obj, "hse-freq-hz", &state->hse_freq_hz);
    state->hse_freq_hz = DEFAULT_HSE_FREQ_HZ;

    cm_object_property_add_uint32(obj, "lse-freq-hz", &state->lse_freq_hz);
    state->lse_freq_hz = DEFAULT_RTC_FREQ_HZ;

    cm_object_property_add_uint32(obj, "hsi-freq-hz", &state->hsi_freq_hz);
    state->hsi_freq_hz = HSI_FREQ_HZ;

    cm_object_property_add_uint32(obj, "lsi-freq-hz", &state->lsi_freq_hz);
    state->lsi_freq_hz = LSI_FREQ_HZ;
}

static void stm32_rcc_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /*
     * Parent realize() is called after setting properties and creating
     * registers.
     */
    STM32RCCState *state = STM32_RCC_STATE(dev);

    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    /* Must be defined before creating registers. */
    cm_object_property_set_int(obj, 4, "register-size-bytes");

    /* TODO: get it from MCU */
    cm_object_property_set_bool(obj, true, "is-little-endian");

    uint32_t size;
    hwaddr addr;
    switch (capabilities->family) {
    case STM32_FAMILY_F1:
        addr = 0x40021000;
        size = 0x400;
        break;

    default:
        /*
         * This will trigger an assertion to fail when creating the
         * memory region in the parent class.
         */
        size = 0;
        addr = 0;
        break;
    }

    cm_object_property_set_int(obj, addr, "mmio-address");
    cm_object_property_set_int(obj, size, "mmio-size-bytes");

    /* Set defaults, need to be non-zero */
    if (state->hsi_freq_hz == 0) {
        state->hsi_freq_hz = HSI_FREQ_HZ;
    }

    if (state->lsi_freq_hz == 0) {
        state->lsi_freq_hz = LSI_FREQ_HZ;
    }

    Object *reg;
    switch (capabilities->family) {
    case STM32_FAMILY_F1:

        if (!capabilities->f1.is_cl) {
            reg = peripheral_register_new_with_info(obj, "cr",
                    &stm32f1_rcc_cr_info);
            cm_object_realize(reg);
            state->f1.reg.cr = reg;

            reg = peripheral_register_new_with_info(obj, "cfgr",
                    &stm32f1_rcc_cfgr_info);
            cm_object_realize(reg);
            state->f1.reg.cfgr = reg;

            state->f1.cfgr.sws = cm_object_get_child_by_name(reg, "sws");
            state->f1.cfgr.pllmul = cm_object_get_child_by_name(reg, "pllmul");
            state->f1.cfgr.pllsrc = cm_object_get_child_by_name(reg, "pllsrc");
            state->f1.cfgr.pllxtpre = cm_object_get_child_by_name(reg,
                    "pllxtpre");
            state->f1.cfgr.hpre = cm_object_get_child_by_name(reg, "hpre");

            reg = peripheral_register_new_with_info(obj, "cir",
                    &stm32f1_rcc_cir_info);
            cm_object_realize(reg);
            state->f1.reg.cir = reg;

            reg = peripheral_register_new_with_info(obj, "apb2rstr",
                    &stm32f1_rcc_apb2rstr_info);
            cm_object_realize(reg);
            state->f1.reg.apb2rstr = reg;

            reg = peripheral_register_new_with_info(obj, "apb1rstr",
                    &stm32f1_rcc_apb1rstr_info);
            cm_object_realize(reg);
            state->f1.reg.apb1rstr = reg;

            reg = peripheral_register_new_with_info(obj, "ahbenr",
                    &stm32f1_rcc_ahbenr_info);
            cm_object_realize(reg);
            state->f1.reg.ahbenr = reg;

            reg = peripheral_register_new_with_info(obj, "apb2enr",
                    &stm32f1_rcc_apb2enr_info);
            cm_object_realize(reg);
            state->f1.reg.apb2enr = reg;

            reg = peripheral_register_new_with_info(obj, "apb1enr",
                    &stm32f1_rcc_apb1enr_info);
            cm_object_realize(reg);
            state->f1.reg.apb1enr = reg;

            reg = peripheral_register_new_with_info(obj, "bdcr",
                    &stm32f1_rcc_bdcr_info);
            cm_object_realize(reg);
            state->f1.reg.bdcr = reg;

            reg = peripheral_register_new_with_info(obj, "csr",
                    &stm32f1_rcc_csr_info);
            cm_object_realize(reg);
            state->f1.reg.csr = reg;
        } else {
            reg = peripheral_register_new_with_info(obj, "cr",
                    &stm32f1cl_rcc_cr_info);
            cm_object_realize(reg);
            state->f1.reg.cr = reg;

            reg = peripheral_register_new_with_info(obj, "cfgr",
                    &stm32f1cl_rcc_cfgr_info);
            cm_object_realize(reg);
            state->f1.reg.cfgr = reg;

            state->f1.cfgr.sws = cm_object_get_child_by_name(reg, "sws");
            state->f1.cfgr.hpre = cm_object_get_child_by_name(reg, "hpre");
            state->f1.cfgr.pllmul = cm_object_get_child_by_name(reg, "pllmul");
            state->f1.cfgr.pllsrc = cm_object_get_child_by_name(reg, "pllsrc");

            reg = peripheral_register_new_with_info(obj, "cir",
                    &stm32f1cl_rcc_cir_info);
            cm_object_realize(reg);
            state->f1.reg.cir = reg;

            reg = peripheral_register_new_with_info(obj, "apb2rstr",
                    &stm32f1cl_rcc_apb2rstr_info);
            cm_object_realize(reg);
            state->f1.reg.apb2rstr = reg;

            reg = peripheral_register_new_with_info(obj, "apb1rstr",
                    &stm32f1cl_rcc_apb1rstr_info);
            cm_object_realize(reg);
            state->f1.reg.apb1rstr = reg;

            reg = peripheral_register_new_with_info(obj, "ahbenr",
                    &stm32f1cl_rcc_ahbenr_info);
            cm_object_realize(reg);
            state->f1.reg.ahbenr = reg;

            reg = peripheral_register_new_with_info(obj, "apb2enr",
                    &stm32f1cl_rcc_apb2enr_info);
            cm_object_realize(reg);
            state->f1.reg.apb2enr = reg;

            reg = peripheral_register_new_with_info(obj, "apb1enr",
                    &stm32f1cl_rcc_apb1enr_info);
            cm_object_realize(reg);
            state->f1.reg.apb1enr = reg;

            reg = peripheral_register_new_with_info(obj, "bdcr",
                    &stm32f1cl_rcc_bdcr_info);
            cm_object_realize(reg);
            state->f1.reg.bdcr = reg;

            reg = peripheral_register_new_with_info(obj, "csr",
                    &stm32f1cl_rcc_csr_info);
            cm_object_realize(reg);
            state->f1.reg.csr = reg;

            reg = peripheral_register_new_with_info(obj, "ahbrstr",
                    &stm32f1cl_rcc_ahbrstr_info);
            cm_object_realize(reg);
            state->f1.reg.ahbrstr = reg;

            reg = peripheral_register_new_with_info(obj, "cfgr2",
                    &stm32f1cl_rcc_cfgr2_info);
            cm_object_realize(reg);
            state->f1.reg.cfgr2 = reg;

            state->f1.cfgr2.prediv1 = cm_object_get_child_by_name(reg,
                    "prediv1");
            state->f1.cfgr2.prediv2 = cm_object_get_child_by_name(reg,
                    "prediv2");
            state->f1.cfgr2.pll2mul = cm_object_get_child_by_name(reg,
                    "pll2mul");
            state->f1.cfgr2.prediv1src = cm_object_get_child_by_name(reg,
                    "prediv1src");
        }
        break;

    default:
        break;
    }

    /* Call parent realize(). */
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_RCC)) {
        return;
    }
}

static void stm32_rcc_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    /* No need to call parent reset(). */

    STM32RCCState *state = STM32_RCC_STATE(dev);

    /* Call parent reset(). */
    cm_device_parent_reset(dev, TYPE_STM32_RCC);

    stm32_rcc_update_clocks(state);
}

static Property stm32_rcc_properties[] = {
        DEFINE_PROP_NON_VOID_PTR("capabilities", STM32RCCState,
                capabilities, const STM32Capabilities *),
    DEFINE_PROP_END_OF_LIST(), };

static void stm32_rcc_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    dc->reset = stm32_rcc_reset_callback;
    dc->realize = stm32_rcc_realize_callback;
    dc->props = stm32_rcc_properties;
}

static const TypeInfo stm32_rcc_type_info = {
    .name = TYPE_STM32_RCC,
    .parent = TYPE_STM32_RCC_PARENT,
    .instance_init = stm32_rcc_instance_init_callback,
    .instance_size = sizeof(STM32RCCState),
    .class_init = stm32_rcc_class_init_callback,
    .class_size = sizeof(STM32RCCState) /**/
};

static void stm32_rcc_register_types(void)
{
    type_register_static(&stm32_rcc_type_info);
}

type_init(stm32_rcc_register_types);

/* ------------------------------------------------------------------------- */
