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
 * - Doc ID 018909 Rev 6, "ST RM0090 Reference manual,
 * STM32F405xx/07xx, STM32F415xx/17xx, STM32F42xxx and STM32F43xxx
 * advanced ARM-based 32-bit MCUs"
 *
 * - Doc ID 026448 Rev 1, "ST RM0383 Reference manual,
 * STM32F411xC/E advanced ARM-based 32-bit MCUs"
 *
 * All STM32 reference manuals available from:
 * http://www.st.com/stonline/stappl/resourceSelector/\
 * app?page=fullResourceSelector&doctype=reference_manual&FamilyID=141
 */

static void stm32_rcc_update_clocks(STM32RCCState *state);

/* ------------------------------------------------------------------------- */

/* STM32F1[LMHX]D */

static PeripheralInfo stm32f1_rcc_info =
        {
            .desc = "Reset and clock control (RCC)",

            .registers =
                    (PeripheralRegisterInfo[] ) {
                                {
                                    .desc = "Clock control register (RCC_CR)",
                                    .name = "cr",
                                    .offset_bytes = 0x00,
                                    .reset_value = 0x00000083,
                                    .reset_mask = 0xFFFF00FF,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "hsion",
                                                            .desc =
                                                                    "Internal high-speed clock enable",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "hsirdy",
                                                            .desc =
                                                                    "Internal high-speed clock ready flag",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hsitrim",
                                                            .desc =
                                                                    "Internal high-speed clock trimming",
                                                            .first_bit = 3,
                                                            .width_bits = 5, },
                                                        {
                                                            .name = "hsical",
                                                            .desc =
                                                                    "Internal high-speed clock calibration",
                                                            .first_bit = 8,
                                                            .width_bits = 8,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hseon",
                                                            .desc =
                                                                    "External clock enable",
                                                            .first_bit = 16, },
                                                        {
                                                            .name = "hserdy",
                                                            .desc =
                                                                    "External high-speed clock ready flag",
                                                            .first_bit = 17,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hsebyp",
                                                            .desc =
                                                                    "External high-speed clock bypass",
                                                            .first_bit = 18, },
                                                        {
                                                            .name = "csson",
                                                            .desc =
                                                                    "Clock security system enable",
                                                            .first_bit = 19, },
                                                        {
                                                            .name = "pllon",
                                                            .desc = "PLL enable",
                                                            .first_bit = 24, },
                                                        {
                                                            .name = "pllrdy",
                                                            .desc =
                                                                    "PLL clock ready flag",
                                                            .first_bit = 25,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc =
                                            "Clock configuration register (RCC_CFGR)",
                                    .name = "cfgr",
                                    .offset_bytes = 0x04,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "sw",
                                                            .desc =
                                                                    "System clock switch",
                                                            .first_bit = 0,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "sws",
                                                            .desc =
                                                                    "System clock switch status",
                                                            .first_bit = 2,
                                                            .width_bits = 2,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hpre",
                                                            .desc =
                                                                    "AHB prescaler",
                                                            .first_bit = 4,
                                                            .width_bits = 4, },
                                                        {
                                                            .name = "ppre1",
                                                            .desc =
                                                                    "APB low-speed prescaler (APB1)",
                                                            .first_bit = 8,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "ppre2",
                                                            .desc =
                                                                    "APB high-speed prescaler (APB2)",
                                                            .first_bit = 11,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "adcpre",
                                                            .desc =
                                                                    "ADC prescaler",
                                                            .first_bit = 14,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "pllsrc",
                                                            .desc =
                                                                    "PLL entry clock source",
                                                            .first_bit = 16, },
                                                        {
                                                            .name = "pllxtpre",
                                                            .desc =
                                                                    "HSE divider for PLL entry",
                                                            .first_bit = 17, },
                                                        {
                                                            .name = "pllmul",
                                                            .desc =
                                                                    "PLL multiplication factor",
                                                            .first_bit = 18,
                                                            .width_bits = 4, },
                                                        {
                                                            .name = "usbpre",
                                                            .desc =
                                                                    "USB prescaler",
                                                            .first_bit = 22, },
                                                        {
                                                            .name = "mco",
                                                            .desc =
                                                                    "Microcontroller clock output",
                                                            .first_bit = 24,
                                                            .width_bits = 3, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc = "Clock interrupt register (RCC_CIR)",
                                    .name = "cir",
                                    .offset_bytes = 0x08,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lsirdyf",
                                                            .desc =
                                                                    "LSI ready interrupt flag",
                                                            .first_bit = 0,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "lserdyf",
                                                            .desc =
                                                                    "LSE ready interrupt flag",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hsirdyf",
                                                            .desc =
                                                                    "HSI ready interrupt flag",
                                                            .first_bit = 2,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hserdyf",
                                                            .desc =
                                                                    "HSE ready interrupt flag",
                                                            .first_bit = 3,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "pllrdyf",
                                                            .desc =
                                                                    "PLL ready interrupt flag",
                                                            .first_bit = 4,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "cssf",
                                                            .desc =
                                                                    "Clock security system interrupt flag",
                                                            .first_bit = 7,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "lsirdyie",
                                                            .desc =
                                                                    "LSI ready interrupt enable",
                                                            .first_bit = 8, },
                                                        {
                                                            .name = "lserdyie",
                                                            .desc =
                                                                    "LSE ready interrupt enable",
                                                            .first_bit = 9, },
                                                        {
                                                            .name = "hsirdyie",
                                                            .desc =
                                                                    "HSI ready interrupt enable",
                                                            .first_bit = 10, },
                                                        {
                                                            .name = "hserdyie",
                                                            .desc =
                                                                    "HSE ready interrupt enable",
                                                            .first_bit = 11, },
                                                        {
                                                            .name = "pllrdyie",
                                                            .desc =
                                                                    "PLL ready interrupt enable",
                                                            .first_bit = 12, },
                                                        {
                                                            .name = "lsirdyc",
                                                            .desc =
                                                                    "LSI ready interrupt clear",
                                                            .first_bit = 16,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "lserdyc",
                                                            .desc =
                                                                    "LSE ready interrupt clear",
                                                            .first_bit = 17,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "hsirdyc",
                                                            .desc =
                                                                    "HSI ready interrupt clear",
                                                            .first_bit = 18,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "hserdyc",
                                                            .desc =
                                                                    "HSE ready interrupt clear",
                                                            .first_bit = 19,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "pllrdyc",
                                                            .desc =
                                                                    "PLL ready interrupt clear",
                                                            .first_bit = 20,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "cssc",
                                                            .desc =
                                                                    "Clock security system interrupt clear",
                                                            .first_bit = 23,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc =
                                            "APB2 peripheral reset register (RCC_APB2RSTR)",
                                    .name = "apb2rstr",
                                    .offset_bytes = 0x0C,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x0038FFFD,
                                    .writable_bits = 0x0038FFFD, },
                                {
                                    .desc =
                                            "APB1 peripheral reset register (RCC_APB1RSTR)",
                                    .name = "apb1rstr",
                                    .offset_bytes = 0x10,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x3AFEC9FF,
                                    .writable_bits = 0x3AFEC9FF, },
                                {
                                    .desc =
                                            "AHB peripheral clock enable register (RCC_AHBENR)",
                                    .name = "ahbenr",
                                    .offset_bytes = 0x14,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x00000557,
                                    .writable_bits = 0x00000557, },
                                {
                                    .desc =
                                            "APB2 peripheral clock enable register (RCC_APB2ENR)",
                                    .name = "apb2enr",
                                    .offset_bytes = 0x18,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "afioen",
                                                            .desc =
                                                                    "Alternate function IO clock enable",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "iopaen",
                                                            .desc =
                                                                    "IO port A clock enable",
                                                            .first_bit = 2, },
                                                        {
                                                            .name = "iopben",
                                                            .desc =
                                                                    "IO port B clock enable",
                                                            .first_bit = 3, },
                                                        {
                                                            .name = "iopcen",
                                                            .desc =
                                                                    "IO port C clock enable",
                                                            .first_bit = 4, },
                                                        {
                                                            .name = "iopden",
                                                            .desc =
                                                                    "IO port D clock enable",
                                                            .first_bit = 5, },
                                                        {
                                                            .name = "iopeen",
                                                            .desc =
                                                                    "IO port E clock enable",
                                                            .first_bit = 6, },
                                                        {
                                                            .name = "iopfen",
                                                            .desc =
                                                                    "IO port F clock enable",
                                                            .first_bit = 7, },
                                                        {
                                                            .name = "iopgen",
                                                            .desc =
                                                                    "IO port G clock enable",
                                                            .first_bit = 8, },
                                                        {
                                                            .name = "adc1en",
                                                            .desc =
                                                                    "ADC1 interface clock enable",
                                                            .first_bit = 9, },
                                                        {
                                                            .name = "adc2en",
                                                            .desc =
                                                                    "ADC2 interface clock enable",
                                                            .first_bit = 10, },
                                                        {
                                                            .name = "tim1en",
                                                            .desc =
                                                                    "TIM1 timer clock enable",
                                                            .first_bit = 11, },
                                                        {
                                                            .name = "spi1en",
                                                            .desc =
                                                                    "SPI1 clock enable",
                                                            .first_bit = 12, },
                                                        {
                                                            .name = "tim8en",
                                                            .desc =
                                                                    "TIM8 timer clock enable",
                                                            .first_bit = 13, },
                                                        {
                                                            .name = "usart1en",
                                                            .desc =
                                                                    "USART1 clock enable",
                                                            .first_bit = 14, },
                                                        {
                                                            .name = "adc3en",
                                                            .desc =
                                                                    "ADC3 interface clock enable",
                                                            .first_bit = 15, },
                                                        {
                                                            .name = "tim9en",
                                                            .desc =
                                                                    "TIM9 timer clock enable",
                                                            .first_bit = 19, },
                                                        {
                                                            .name = "tim10en",
                                                            .desc =
                                                                    "TIM10 timer clock enable",
                                                            .first_bit = 20, },
                                                        {
                                                            .name = "tim11en",
                                                            .desc =
                                                                    "TIM11 timer clock enable",
                                                            .first_bit = 21, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc =
                                            "APB1 peripheral clock enable register (RCC_APB1ENR)",
                                    .name = "apb1enr",
                                    .offset_bytes = 0x1C,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x3AFEC9FF,
                                    .writable_bits = 0x3AFEC9FF, },
                                {
                                    .desc =
                                            "Backup domain control register (RCC_BDCR)",
                                    .name = "bdcr",
                                    .offset_bytes = 0x20,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lseon",
                                                            .desc =
                                                                    "External low-speed oscillator enable",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "lserdy",
                                                            .desc =
                                                                    "External low-speed oscillator ready",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "lsebyp",
                                                            .desc =
                                                                    "External low-speed oscillator bypass",
                                                            .first_bit = 2, },
                                                        {
                                                            .name = "rtcsel",
                                                            .desc =
                                                                    "RTC clock source selection",
                                                            .first_bit = 8,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "rtcen",
                                                            .desc =
                                                                    "RTC clock enable",
                                                            .first_bit = 15, },
                                                        {
                                                            .name = "bdrst",
                                                            .desc =
                                                                    "Backup domain software reset",
                                                            .first_bit = 16, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc = "Control/status register (RCC_CSR)",
                                    .name = "csr",
                                    .offset_bytes = 0x24,
                                    .reset_value = 0x0C000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lsion",
                                                            .desc =
                                                                    "Internal low-speed oscillator enable",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "lsirdy",
                                                            .desc =
                                                                    "Internal low-speed oscillator ready",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "rmvf",
                                                            .desc =
                                                                    "Remove reset flag",
                                                            .first_bit = 24, },
                                                        {
                                                            .name = "pinrstf",
                                                            .desc =
                                                                    "PIN reset flag",
                                                            .first_bit = 26, },
                                                        {
                                                            .name = "porrstf",
                                                            .desc =
                                                                    "POR/PDR reset flag",
                                                            .first_bit = 27, },
                                                        {
                                                            .name = "stfrstf",
                                                            .desc =
                                                                    "Software reset flag",
                                                            .first_bit = 28, },
                                                        {
                                                            .name = "iwdgrstf",
                                                            .desc =
                                                                    "Independent watchdog reset flag",
                                                            .first_bit = 29, },
                                                        {
                                                            .name = "wwdgrstf",
                                                            .desc =
                                                                    "Window watchdog reset flag",
                                                            .first_bit = 30, },
                                                        {
                                                            .name = "lrwrrstf",
                                                            .desc =
                                                                    "Low-power reset flag",
                                                            .first_bit = 31, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                { }, /**/
                            } , /**/
        };

static void stm32f1_rcc_create_objects(Object *obj)
{
    STM32RCCState *state = STM32_RCC_STATE(obj);

    peripheral_new_with_info(obj, NULL, &stm32f1_rcc_info);

    state->f1.reg.cr = cm_object_get_child_by_name(obj, "cr");
    state->f1.reg.cfgr = cm_object_get_child_by_name(obj, "cfgr");
    state->f1.reg.cir = cm_object_get_child_by_name(obj, "cir");
    state->f1.reg.apb2rstr = cm_object_get_child_by_name(obj, "apb2rstr");
    state->f1.reg.apb1rstr = cm_object_get_child_by_name(obj, "apb1rstr");
    state->f1.reg.ahbenr = cm_object_get_child_by_name(obj, "ahbenr");
    state->f1.reg.apb2enr = cm_object_get_child_by_name(obj, "apb2enr");

    state->f1.reg.apb1enr = cm_object_get_child_by_name(obj, "apb1enr");
    state->f1.reg.bdcr = cm_object_get_child_by_name(obj, "bdcr");
    state->f1.reg.csr = cm_object_get_child_by_name(obj, "csr");

    /* CR bitfields. */
    state->f1.cr.hsirdy = cm_object_get_child_by_name(state->f1.reg.cr,
            "hsirdy");
    state->f1.cr.hserdy = cm_object_get_child_by_name(state->f1.reg.cr,
            "hserdy");
    state->f1.cr.pllrdy = cm_object_get_child_by_name(state->f1.reg.cr,
            "pllrdy");

    /* CFGR bitfields. */
    state->f1.cfgr.sws = cm_object_get_child_by_name(state->f1.reg.cfgr, "sws");
    state->f1.cfgr.pllmul = cm_object_get_child_by_name(state->f1.reg.cfgr,
            "pllmul");
    state->f1.cfgr.pllsrc = cm_object_get_child_by_name(state->f1.reg.cfgr,
            "pllsrc");
    state->f1.cfgr.pllxtpre = cm_object_get_child_by_name(state->f1.reg.cfgr,
            "pllxtpre");
    state->f1.cfgr.hpre = cm_object_get_child_by_name(state->f1.reg.cfgr,
            "hpre");

    /* CIR bitfields. */
    state->f1.cir.lsirdyf = cm_object_get_child_by_name(state->f1.reg.cir,
            "lsirdyf");
    state->f1.cir.lserdyf = cm_object_get_child_by_name(state->f1.reg.cir,
            "lserdyf");
    state->f1.cir.hsirdyf = cm_object_get_child_by_name(state->f1.reg.cir,
            "hsirdyf");
    state->f1.cir.hserdyf = cm_object_get_child_by_name(state->f1.reg.cir,
            "hserdyf");
    state->f1.cir.pllrdyf = cm_object_get_child_by_name(state->f1.reg.cir,
            "pllrdyf");
    state->f1.cir.cssf = cm_object_get_child_by_name(state->f1.reg.cir, "cssf");

    /* BDCR bitfields. */
    state->f1.bdcr.lserdy = cm_object_get_child_by_name(state->f1.reg.bdcr,
            "lserdy");

    /* CSR bitfields. */
    state->f1.csr.lsirdy = cm_object_get_child_by_name(state->f1.reg.csr,
            "lsirdy");
    state->f1.csr.pinrstf = cm_object_get_child_by_name(state->f1.reg.csr,
            "pinrstf");
    state->f1.csr.porrstf = cm_object_get_child_by_name(state->f1.reg.csr,
            "porrstf");
    state->f1.csr.stfrstf = cm_object_get_child_by_name(state->f1.reg.csr,
            "stfrstf");
    state->f1.csr.iwdgrstf = cm_object_get_child_by_name(state->f1.reg.csr,
            "iwdgrstf");
    state->f1.csr.wwdgrstf = cm_object_get_child_by_name(state->f1.reg.csr,
            "wwdgrstf");
    state->f1.csr.lrwrrstf = cm_object_get_child_by_name(state->f1.reg.csr,
            "lrwrrstf");
}

/* ------------------------------------------------------------------------- */

/* STM32F1CL */

static PeripheralInfo stm32f1cl_rcc_info =
        {
            .desc = "Reset and clock control (RCC)",

            .registers =
                    (PeripheralRegisterInfo[] ) {
                                {
                                    .desc = "Clock control register (RCC_CR)",
                                    .name = "cr",
                                    .offset_bytes = 0x00,
                                    .reset_value = 0x00000083,
                                    .reset_mask = 0xFFFF00FF,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "hsion",
                                                            .desc =
                                                                    "Internal high-speed clock enable",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "hsirdy",
                                                            .desc =
                                                                    "Internal high-speed clock ready flag",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hsitrim",
                                                            .desc =
                                                                    "Internal high-speed clock trimming",
                                                            .first_bit = 3,
                                                            .width_bits = 5, },
                                                        {
                                                            .name = "hsical",
                                                            .desc =
                                                                    "Internal high-speed clock calibration",
                                                            .first_bit = 8,
                                                            .width_bits = 8,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hseon",
                                                            .desc =
                                                                    "External clock enable",
                                                            .first_bit = 16, },
                                                        {
                                                            .name = "hserdy",
                                                            .desc =
                                                                    "External high-speed clock ready flag",
                                                            .first_bit = 17,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hsebyp",
                                                            .desc =
                                                                    "External high-speed clock bypass",
                                                            .first_bit = 18, },
                                                        {
                                                            .name = "csson",
                                                            .desc =
                                                                    "Clock security system enable",
                                                            .first_bit = 19, },
                                                        {
                                                            .name = "pllon",
                                                            .desc = "PLL enable",
                                                            .first_bit = 24, },
                                                        {
                                                            .name = "pllrdy",
                                                            .desc =
                                                                    "PLL clock ready flag",
                                                            .first_bit = 25,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "pll2on",
                                                            .desc =
                                                                    "PLL2 enable",
                                                            .first_bit = 26, },
                                                        {
                                                            .name = "pll2rdy",
                                                            .desc =
                                                                    "PLL2 clock ready flag",
                                                            .first_bit = 27,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "pll3on",
                                                            .desc =
                                                                    "PLL3 enable",
                                                            .first_bit = 28, },
                                                        {
                                                            .name = "pll3rdy",
                                                            .desc =
                                                                    "PLL3 clock ready flag",
                                                            .first_bit = 29,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc =
                                            "Clock configuration register (RCC_CFGR)",
                                    .name = "cfgr",
                                    .offset_bytes = 0x04,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "sw",
                                                            .desc =
                                                                    "System clock switch",
                                                            .first_bit = 0,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "sws",
                                                            .desc =
                                                                    "System clock switch status",
                                                            .first_bit = 2,
                                                            .width_bits = 2,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hpre",
                                                            .desc =
                                                                    "AHB prescaler",
                                                            .first_bit = 4,
                                                            .width_bits = 4, },
                                                        {
                                                            .name = "ppre1",
                                                            .desc =
                                                                    "APB low-speed prescaler (APB1)",
                                                            .first_bit = 8,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "ppre2",
                                                            .desc =
                                                                    "APB high-speed prescaler (APB2)",
                                                            .first_bit = 11,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "adcpre",
                                                            .desc =
                                                                    "ADC prescaler",
                                                            .first_bit = 14,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "pllsrc",
                                                            .desc =
                                                                    "PLL entry clock source",
                                                            .first_bit = 16, },
                                                        {
                                                            .name = "pllxtpre",
                                                            .desc =
                                                                    "HSE divider for PLL entry",
                                                            .first_bit = 17, },
                                                        {
                                                            .name = "pllmul",
                                                            .desc =
                                                                    "PLL multiplication factor",
                                                            .first_bit = 18,
                                                            .width_bits = 4, },
                                                        {
                                                            .name = "otgfspre",
                                                            .desc =
                                                                    "OTG FS prescaler",
                                                            .first_bit = 22, },
                                                        {
                                                            .name = "mco",
                                                            .desc =
                                                                    "Microcontroller clock output",
                                                            .first_bit = 24,
                                                            .width_bits = 3, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc = "Clock interrupt register (RCC_CIR)",
                                    .name = "cir",
                                    .offset_bytes = 0x08,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lsirdyf",
                                                            .desc =
                                                                    "LSI ready interrupt flag",
                                                            .first_bit = 0,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "lserdyf",
                                                            .desc =
                                                                    "LSE ready interrupt flag",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hsirdyf",
                                                            .desc =
                                                                    "HSI ready interrupt flag",
                                                            .first_bit = 2,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hserdyf",
                                                            .desc =
                                                                    "HSE ready interrupt flag",
                                                            .first_bit = 3,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "pllrdyf",
                                                            .desc =
                                                                    "PLL ready interrupt flag",
                                                            .first_bit = 4,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "pll2rdyf",
                                                            .desc =
                                                                    "PLL2 ready interrupt flag",
                                                            .first_bit = 5,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "pll3rdyf",
                                                            .desc =
                                                                    "PLL3 ready interrupt flag",
                                                            .first_bit = 6,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "cssf",
                                                            .desc =
                                                                    "Clock security system interrupt flag",
                                                            .first_bit = 7,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "lsirdyie",
                                                            .desc =
                                                                    "LSI ready interrupt enable",
                                                            .first_bit = 8, },
                                                        {
                                                            .name = "lserdyie",
                                                            .desc =
                                                                    "LSE ready interrupt enable",
                                                            .first_bit = 9, },
                                                        {
                                                            .name = "hsirdyie",
                                                            .desc =
                                                                    "HSI ready interrupt enable",
                                                            .first_bit = 10, },
                                                        {
                                                            .name = "hserdyie",
                                                            .desc =
                                                                    "HSE ready interrupt enable",
                                                            .first_bit = 11, },
                                                        {
                                                            .name = "pllrdyie",
                                                            .desc =
                                                                    "PLL ready interrupt enable",
                                                            .first_bit = 12, },
                                                        {
                                                            .name = "pll2rdyie",
                                                            .desc =
                                                                    "PLL2 ready interrupt enable",
                                                            .first_bit = 13, },
                                                        {
                                                            .name = "pll3rdyie",
                                                            .desc =
                                                                    "PLL3 ready interrupt enable",
                                                            .first_bit = 14, },
                                                        {
                                                            .name = "lsirdyc",
                                                            .desc =
                                                                    "LSI ready interrupt clear",
                                                            .first_bit = 16,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "lserdyc",
                                                            .desc =
                                                                    "LSE ready interrupt clear",
                                                            .first_bit = 17,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "hsirdyc",
                                                            .desc =
                                                                    "HSI ready interrupt clear",
                                                            .first_bit = 18,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "hserdyc",
                                                            .desc =
                                                                    "HSE ready interrupt clear",
                                                            .first_bit = 19,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "pllrdyc",
                                                            .desc =
                                                                    "PLL ready interrupt clear",
                                                            .first_bit = 20,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "pll2rdyc",
                                                            .desc =
                                                                    "PLL2 ready interrupt clear",
                                                            .first_bit = 21,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "pll3rdyc",
                                                            .desc =
                                                                    "PLL3 ready interrupt clear",
                                                            .first_bit = 22,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "cssc",
                                                            .desc =
                                                                    "Clock security system interrupt clear",
                                                            .first_bit = 23,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc =
                                            "APB2 peripheral reset register (RCC_APB2RSTR)",
                                    .name = "apb2rstr",
                                    .offset_bytes = 0x0C,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x00005E7D,
                                    .writable_bits = 0x00005E7D, },
                                {
                                    .desc =
                                            "APB1 peripheral reset register (RCC_APB1RSTR)",
                                    .name = "apb1rstr",
                                    .offset_bytes = 0x10,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x377EC83F,
                                    .writable_bits = 0x377EC83F, },
                                {
                                    .desc =
                                            "AHB peripheral clock enable register (RCC_AHBENR)",
                                    .name = "ahbenr",
                                    .offset_bytes = 0x14,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x0001D057,
                                    .writable_bits = 0x0001D057, },
                                {
                                    .desc =
                                            "APB2 peripheral clock enable register (RCC_APB2ENR)",
                                    .name = "apb2enr",
                                    .offset_bytes = 0x18,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "afioen",
                                                            .desc =
                                                                    "Alternate function IO clock enable",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "iopaen",
                                                            .desc =
                                                                    "IO port A clock enable",
                                                            .first_bit = 2, },
                                                        {
                                                            .name = "iopben",
                                                            .desc =
                                                                    "IO port B clock enable",
                                                            .first_bit = 3, },
                                                        {
                                                            .name = "iopcen",
                                                            .desc =
                                                                    "IO port C clock enable",
                                                            .first_bit = 4, },
                                                        {
                                                            .name = "iopden",
                                                            .desc =
                                                                    "IO port D clock enable",
                                                            .first_bit = 5, },
                                                        {
                                                            .name = "iopeen",
                                                            .desc =
                                                                    "IO port E clock enable",
                                                            .first_bit = 6, },
                                                        {
                                                            .name = "adc1en",
                                                            .desc =
                                                                    "ADC1 interface clock enable",
                                                            .first_bit = 9, },
                                                        {
                                                            .name = "adc2en",
                                                            .desc =
                                                                    "ADC2 interface clock enable",
                                                            .first_bit = 10, },
                                                        {
                                                            .name = "tim1en",
                                                            .desc =
                                                                    "TIM1 timer clock enable",
                                                            .first_bit = 11, },
                                                        {
                                                            .name = "spi1en",
                                                            .desc =
                                                                    "SPI1 clock enable",
                                                            .first_bit = 12, },
                                                        {
                                                            .name = "usart1en",
                                                            .desc =
                                                                    "USART1 clock enable",
                                                            .first_bit = 14, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc =
                                            "APB1 peripheral clock enable register (RCC_APB1ENR)",
                                    .name = "apb1enr",
                                    .offset_bytes = 0x1C,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x3E7EC83F,
                                    .writable_bits = 0x3E7EC83F, },
                                {
                                    .desc =
                                            "Backup domain control register (RCC_BDCR)",
                                    .name = "bdcr",
                                    .offset_bytes = 0x20,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lseon",
                                                            .desc =
                                                                    "External low-speed oscillator enable",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "lserdy",
                                                            .desc =
                                                                    "External low-speed oscillator ready",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "lsebyp",
                                                            .desc =
                                                                    "External low-speed oscillator bypass",
                                                            .first_bit = 2, },
                                                        {
                                                            .name = "rtcsel",
                                                            .desc =
                                                                    "RTC clock source selection",
                                                            .first_bit = 8,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "rtcen",
                                                            .desc =
                                                                    "RTC clock enable",
                                                            .first_bit = 15, },
                                                        {
                                                            .name = "bdrst",
                                                            .desc =
                                                                    "Backup domain software reset",
                                                            .first_bit = 16, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc = "Control/status register (RCC_CSR)",
                                    .name = "csr",
                                    .offset_bytes = 0x24,
                                    .reset_value = 0x0C000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lsion",
                                                            .desc =
                                                                    "Internal low-speed oscillator enable",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "lsirdy",
                                                            .desc =
                                                                    "Internal low-speed oscillator ready",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "rmvf",
                                                            .desc =
                                                                    "Remove reset flag",
                                                            .first_bit = 24, },
                                                        {
                                                            .name = "pinrstf",
                                                            .desc =
                                                                    "PIN reset flag",
                                                            .first_bit = 26, },
                                                        {
                                                            .name = "porrstf",
                                                            .desc =
                                                                    "POR/PDR reset flag",
                                                            .first_bit = 27, },
                                                        {
                                                            .name = "stfrstf",
                                                            .desc =
                                                                    "Software reset flag",
                                                            .first_bit = 28, },
                                                        {
                                                            .name = "iwdgrstf",
                                                            .desc =
                                                                    "Independent watchdog reset flag",
                                                            .first_bit = 29, },
                                                        {
                                                            .name = "wwdgrstf",
                                                            .desc =
                                                                    "Window watchdog reset flag",
                                                            .first_bit = 30, },
                                                        {
                                                            .name = "lrwrrstf",
                                                            .desc =
                                                                    "Low-power reset flag",
                                                            .first_bit = 31, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc =
                                            "AHB peripheral clock reset register (RCC_AHBRSTR)",
                                    .name = "ahbrstr",
                                    .offset_bytes = 0x28,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x00005000,
                                    .writable_bits = 0x00005000, },
                                {
                                    .desc =
                                            "Clock configuration register2 (RCC_CFGR2)",
                                    .name = "cfgr2",
                                    .offset_bytes = 0x2C,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "prediv1",
                                                            .desc =
                                                                    "PREDIV1 division factor",
                                                            .first_bit = 0,
                                                            .width_bits = 4, },
                                                        {
                                                            .name = "prediv2",
                                                            .desc =
                                                                    "PREDIV2 division factor",
                                                            .first_bit = 4,
                                                            .width_bits = 4, },
                                                        {
                                                            .name = "pll2mul",
                                                            .desc =
                                                                    "PLL2 Multiplication factor",
                                                            .first_bit = 8,
                                                            .width_bits = 4, },
                                                        {
                                                            .name = "pll3mul",
                                                            .desc =
                                                                    "PLL3 Multiplication factor",
                                                            .first_bit = 12,
                                                            .width_bits = 4, },
                                                        {
                                                            .name = "prediv1src",
                                                            .desc =
                                                                    "PREDIV1 entry clock source",
                                                            .first_bit = 16, },
                                                        {
                                                            .name = "i2s2src",
                                                            .desc =
                                                                    "I2S2 clock source",
                                                            .first_bit = 17, },
                                                        {
                                                            .name = "i2s3src",
                                                            .desc =
                                                                    "I2S2 clock source",
                                                            .first_bit = 18, },
                                                        { }, /**/
                                                    } , /**/
                                },

                                { }, /**/
                            } , /**/
        };

static void stm32f1cl_rcc_create_objects(Object *obj)
{
    STM32RCCState *state = STM32_RCC_STATE(obj);

    peripheral_new_with_info(obj, NULL, &stm32f1cl_rcc_info);

    state->f1.reg.cr = cm_object_get_child_by_name(obj, "cr");
    state->f1.reg.cfgr = cm_object_get_child_by_name(obj, "cfgr");
    state->f1.reg.cir = cm_object_get_child_by_name(obj, "cir");
    state->f1.reg.apb2rstr = cm_object_get_child_by_name(obj, "apb2rstr");
    state->f1.reg.apb1rstr = cm_object_get_child_by_name(obj, "apb1rstr");
    state->f1.reg.ahbenr = cm_object_get_child_by_name(obj, "ahbenr");
    state->f1.reg.apb2enr = cm_object_get_child_by_name(obj, "apb2enr");

    state->f1.reg.apb1enr = cm_object_get_child_by_name(obj, "apb1enr");
    state->f1.reg.bdcr = cm_object_get_child_by_name(obj, "bdcr");
    state->f1.reg.csr = cm_object_get_child_by_name(obj, "csr");

    state->f1.reg.ahbrstr = cm_object_get_child_by_name(obj, "ahbrstr");
    state->f1.reg.cfgr2 = cm_object_get_child_by_name(obj, "cfgr2");

    /* CR bitfields. */
    state->f1.cr.hsirdy = cm_object_get_child_by_name(state->f1.reg.cr,
            "hsirdy");
    state->f1.cr.hserdy = cm_object_get_child_by_name(state->f1.reg.cr,
            "hserdy");
    state->f1.cr.pllrdy = cm_object_get_child_by_name(state->f1.reg.cr,
            "pllrdy");
    state->f1.cr.pll2rdy = cm_object_get_child_by_name(state->f1.reg.cr,
            "pll2rdy");
    state->f1.cr.pll3rdy = cm_object_get_child_by_name(state->f1.reg.cr,
            "pll3rdy");

    /* CFGR bitfields. */
    state->f1.cfgr.sws = cm_object_get_child_by_name(state->f1.reg.cfgr, "sws");
    state->f1.cfgr.pllmul = cm_object_get_child_by_name(state->f1.reg.cfgr,
            "pllmul");
    state->f1.cfgr.pllsrc = cm_object_get_child_by_name(state->f1.reg.cfgr,
            "pllsrc");
    state->f1.cfgr.pllxtpre = cm_object_get_child_by_name(state->f1.reg.cfgr,
            "pllxtpre");
    state->f1.cfgr.hpre = cm_object_get_child_by_name(state->f1.reg.cfgr,
            "hpre");

    /* CIR bitfields. */
    state->f1.cir.lsirdyf = cm_object_get_child_by_name(state->f1.reg.cir,
            "lsirdyf");
    state->f1.cir.lserdyf = cm_object_get_child_by_name(state->f1.reg.cir,
            "lserdyf");
    state->f1.cir.hsirdyf = cm_object_get_child_by_name(state->f1.reg.cir,
            "hsirdyf");
    state->f1.cir.hserdyf = cm_object_get_child_by_name(state->f1.reg.cir,
            "hserdyf");
    state->f1.cir.pllrdyf = cm_object_get_child_by_name(state->f1.reg.cir,
            "pllrdyf");
    state->f1.cir.pll2rdyf = cm_object_get_child_by_name(state->f1.reg.cir,
            "pll2rdyf");
    state->f1.cir.pll3rdyf = cm_object_get_child_by_name(state->f1.reg.cir,
            "pll3rdyf");
    state->f1.cir.cssf = cm_object_get_child_by_name(state->f1.reg.cir, "cssf");

    /* BDCR bitfields. */
    state->f1.bdcr.lserdy = cm_object_get_child_by_name(state->f1.reg.bdcr,
            "lserdy");

    /* CSR bitfields. */
    state->f1.csr.lsirdy = cm_object_get_child_by_name(state->f1.reg.csr,
            "lsirdy");
    state->f1.csr.pinrstf = cm_object_get_child_by_name(state->f1.reg.csr,
            "pinrstf");
    state->f1.csr.porrstf = cm_object_get_child_by_name(state->f1.reg.csr,
            "porrstf");
    state->f1.csr.stfrstf = cm_object_get_child_by_name(state->f1.reg.csr,
            "stfrstf");
    state->f1.csr.iwdgrstf = cm_object_get_child_by_name(state->f1.reg.csr,
            "iwdgrstf");
    state->f1.csr.wwdgrstf = cm_object_get_child_by_name(state->f1.reg.csr,
            "wwdgrstf");
    state->f1.csr.lrwrrstf = cm_object_get_child_by_name(state->f1.reg.csr,
            "lrwrrstf");

    /* CFGR2 bitfields. */
    state->f1.cfgr2.prediv1 = cm_object_get_child_by_name(state->f1.reg.cfgr2,
            "prediv1");
    state->f1.cfgr2.prediv2 = cm_object_get_child_by_name(state->f1.reg.cfgr2,
            "prediv2");
    state->f1.cfgr2.pll2mul = cm_object_get_child_by_name(state->f1.reg.cfgr2,
            "pll2mul");
    state->f1.cfgr2.prediv1src = cm_object_get_child_by_name(
            state->f1.reg.cfgr2, "prediv1src");
}

/* ------------------------------------------------------------------------- */

/* STM32F4_01_57_xx */

static PeripheralInfo stm32f4_01_57_xx_rcc_info =
        {
            .desc = "Reset and clock control (RCC)",

            .registers =
                    (PeripheralRegisterInfo[] ) {
                                {
                                    .desc = "Clock control register (RCC_CR)",
                                    .name = "cr",
                                    .offset_bytes = 0x00,
                                    .reset_value = 0x00000083,
                                    .reset_mask = 0xFFFF00FF,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "hsion",
                                                            .desc =
                                                                    "Internal high-speed clock enable",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "hsirdy",
                                                            .desc =
                                                                    "Internal high-speed clock ready flag",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hsitrim",
                                                            .desc =
                                                                    "Internal high-speed clock trimming",
                                                            .first_bit = 3,
                                                            .width_bits = 5, },
                                                        {
                                                            .name = "hsical",
                                                            .desc =
                                                                    "Internal high-speed clock calibration",
                                                            .first_bit = 8,
                                                            .width_bits = 8,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hseon",
                                                            .desc =
                                                                    "External clock enable",
                                                            .first_bit = 16, },
                                                        {
                                                            .name = "hserdy",
                                                            .desc =
                                                                    "External high-speed clock ready flag",
                                                            .first_bit = 17,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hsebyp",
                                                            .desc =
                                                                    "External high-speed clock bypass",
                                                            .first_bit = 18, },
                                                        {
                                                            .name = "csson",
                                                            .desc =
                                                                    "Clock security system enable",
                                                            .first_bit = 19, },
                                                        {
                                                            .name = "pllon",
                                                            .desc = "PLL enable",
                                                            .first_bit = 24, },
                                                        {
                                                            .name = "pllrdy",
                                                            .desc =
                                                                    "PLL clock ready flag",
                                                            .first_bit = 25,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "plli2son",
                                                            .desc =
                                                                    "PLL I2S enable",
                                                            .first_bit = 26, },
                                                        {
                                                            .name = "plli2srdy",
                                                            .desc =
                                                                    "PLL I2S clock ready flag",
                                                            .first_bit = 27,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },

                                                        { }, /**/
                                                    } , /**/},
                                {
                                    .desc =
                                            "RCC PLL configuration register (RCC_PLLCFGR)",
                                    .name = "pllcfgr",
                                    .offset_bytes = 0x04,
                                    .reset_value = 0x24003010,
                                    .readable_bits = 0x0F437FFF,
                                    .writable_bits = 0x0F437FFF,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "pllm",
                                                            .desc =
                                                                    "PLL division factor",
                                                            .first_bit = 0,
                                                            .width_bits = 6, },
                                                        {
                                                            .name = "plln",
                                                            .desc =
                                                                    "PLL multiplication factor",
                                                            .first_bit = 6,
                                                            .width_bits = 9, },
                                                        {
                                                            .name = "pllp",
                                                            .desc =
                                                                    "Main PLL (PLL) division factor",
                                                            .first_bit = 16,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "pllsrc",
                                                            .desc =
                                                                    "Main PLL (PLL) clock source",
                                                            .first_bit = 22, },
                                                        {
                                                            .name = "pllq",
                                                            .desc =
                                                                    "Main PLL (PLL) division factor",
                                                            .first_bit = 24,
                                                            .width_bits = 4, },
                                                        { }, } , },
                                {
                                    .desc =
                                            "RCC clock configuration register (RCC_CFGR)",
                                    .name = "cfgr",
                                    .offset_bytes = 0x08,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "sw",
                                                            .desc =
                                                                    "System clock switch",
                                                            .first_bit = 0,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "sws",
                                                            .desc =
                                                                    "System clock switch status",
                                                            .first_bit = 2,
                                                            .width_bits = 2,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hpre",
                                                            .desc =
                                                                    "AHB prescaler",
                                                            .first_bit = 4,
                                                            .width_bits = 4, },
                                                        {
                                                            .name = "ppre1",
                                                            .desc =
                                                                    "APB Low speed prescaler (APB1)",
                                                            .first_bit = 10,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "ppre2",
                                                            .desc =
                                                                    "APB high speed prescaler (APB2)",
                                                            .first_bit = 13,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "rtcpre",
                                                            .desc =
                                                                    "HSE division factor for RTC clock",
                                                            .first_bit = 16,
                                                            .width_bits = 5, },
                                                        {
                                                            .name = "mco1",
                                                            .desc =
                                                                    "Microcontroller clock output 1",
                                                            .first_bit = 21,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "i2ssrc",
                                                            .desc =
                                                                    "I2S clock selection",
                                                            .first_bit = 23, },
                                                        {
                                                            .name = "mco1pre",
                                                            .desc =
                                                                    "MCO1 prescaller",
                                                            .first_bit = 24,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "mco2pre",
                                                            .desc =
                                                                    "MCO2 prescaller",
                                                            .first_bit = 27,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "mco2",
                                                            .desc =
                                                                    "Microcontroller clock output 2",
                                                            .first_bit = 30,
                                                            .width_bits = 2, },
                                                        { }, /**/
                                                    } , /**/},
                                {
                                    .desc = "Clock interrupt register (RCC_CIR)",
                                    .name = "cir",
                                    .offset_bytes = 0x0C,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lsirdyf",
                                                            .desc =
                                                                    "LSI ready interrupt flag",
                                                            .first_bit = 0,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "lserdyf",
                                                            .desc =
                                                                    "LSE ready interrupt flag",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hsirdyf",
                                                            .desc =
                                                                    "HSI ready interrupt flag",
                                                            .first_bit = 2,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hserdyf",
                                                            .desc =
                                                                    "HSE ready interrupt flag",
                                                            .first_bit = 3,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "pllrdyf",
                                                            .desc =
                                                                    "PLL ready interrupt flag",
                                                            .first_bit = 4,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "plli2srdyf",
                                                            .desc =
                                                                    "PLL I2S ready interrupt flag",
                                                            .first_bit = 5,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "cssf",
                                                            .desc =
                                                                    "Clock security system interrupt flag",
                                                            .first_bit = 7,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "lsirdyie",
                                                            .desc =
                                                                    "LSI ready interrupt enable",
                                                            .first_bit = 8, },
                                                        {
                                                            .name = "lserdyie",
                                                            .desc =
                                                                    "LSE ready interrupt enable",
                                                            .first_bit = 9, },
                                                        {
                                                            .name = "hsirdyie",
                                                            .desc =
                                                                    "HSI ready interrupt enable",
                                                            .first_bit = 10, },
                                                        {
                                                            .name = "hserdyie",
                                                            .desc =
                                                                    "HSE ready interrupt enable",
                                                            .first_bit = 11, },
                                                        {
                                                            .name = "pllrdyie",
                                                            .desc =
                                                                    "PLL ready interrupt enable",
                                                            .first_bit = 12, },
                                                        {
                                                            .name =
                                                                    "plli2srdyie",
                                                            .desc =
                                                                    "PLL I2S ready interrupt enable",
                                                            .first_bit = 13, },
                                                        {
                                                            .name = "lsirdyc",
                                                            .desc =
                                                                    "LSI ready interrupt clear",
                                                            .first_bit = 16,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "lserdyc",
                                                            .desc =
                                                                    "LSE ready interrupt clear",
                                                            .first_bit = 17,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "hsirdyc",
                                                            .desc =
                                                                    "HSI ready interrupt clear",
                                                            .first_bit = 18,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "hserdyc",
                                                            .desc =
                                                                    "HSE ready interrupt clear",
                                                            .first_bit = 19,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "pllrdyc",
                                                            .desc =
                                                                    "PLL ready interrupt clear",
                                                            .first_bit = 20,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "plli2srdyc",
                                                            .desc =
                                                                    "PLL I2S ready interrupt clear",
                                                            .first_bit = 21,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "cssc",
                                                            .desc =
                                                                    "Clock security system interrupt clear",
                                                            .first_bit = 23,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc =
                                            "RCC AHB1 peripheral reset register (RCC_AHB1RSTR)",
                                    .name = "ahb1rstr",
                                    .offset_bytes = 0x10,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x226011FF,
                                    .writable_bits = 0x226011FF, },
                                {
                                    .desc =
                                            "RCC AHB2 peripheral reset register (RCC_AHB2RSTR)",
                                    .name = "ahb2rstr",
                                    .offset_bytes = 0x14,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x000000F1,
                                    .writable_bits = 0x000000F1, },
                                {
                                    .desc =
                                            "RCC AHB3 peripheral reset register (RCC_AHB3RSTR)",
                                    .name = "ahb3rstr",
                                    .offset_bytes = 0x18,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x00000001,
                                    .writable_bits = 0x00000001, },
                                {
                                    .desc =
                                            "RCC APB1 peripheral reset register (RCC_APB1RSTR)",
                                    .name = "apb1rstr",
                                    .offset_bytes = 0x20,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x36FEC9FF,
                                    .writable_bits = 0x36FEC9FF, },
                                {
                                    .desc =
                                            "RCC APB2 peripheral reset register (RCC_APB2RSTR)",
                                    .name = "apb2rstr",
                                    .offset_bytes = 0x24,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x00075933,
                                    .writable_bits = 0x00075933, },
                                {
                                    .desc =
                                            "RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)",
                                    .name = "ahb1enr",
                                    .offset_bytes = 0x30,
                                    .reset_value = 0x00100000,
                                    .readable_bits = 0x7E7C11FF,
                                    .writable_bits = 0x7E7C11FF, },
                                {
                                    .desc =
                                            "RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)",
                                    .name = "ahb2enr",
                                    .offset_bytes = 0x34,
                                    .reset_value = 0x00100000,
                                    .readable_bits = 0x000000F1,
                                    .writable_bits = 0x000000F1, },
                                {
                                    .desc =
                                            "RCC AHB3 peripheral clock enable register (RCC_AHB3ENR)",
                                    .name = "ahb3enr",
                                    .offset_bytes = 0x38,
                                    .reset_value = 0x00100000,
                                    .readable_bits = 0x00000001,
                                    .writable_bits = 0x00000001, },
                                {
                                    .desc =
                                            "APB1 peripheral clock enable register (RCC_APB1ENR)",
                                    .name = "apb1enr",
                                    .offset_bytes = 0x40,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x3CFEC9FF,
                                    .writable_bits = 0x3CFEC9FF, },
                                {
                                    .desc =
                                            "APB2 peripheral clock enable register (RCC_APB2ENR)",
                                    .name = "apb2enr",
                                    .offset_bytes = 0x44,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x00377F33,
                                    .writable_bits = 0x00377F33, },
                                {
                                    .desc =
                                            "RCC AHB1 peripheral clock enable in low power mode register (RCC_AHB1LPENR)",
                                    .name = "ahb1lpenr",
                                    .offset_bytes = 0x50,
                                    .reset_value = 0x7E6791FF,
                                    .readable_bits = 0x7E6791FF,
                                    .writable_bits = 0x7E6791FF, },
                                {
                                    .desc =
                                            "RCC AHB2 peripheral clock enable in low power mode register (RCC_AHB2LPENR)",
                                    .name = "ahb2lpenr",
                                    .offset_bytes = 0x54,
                                    .reset_value = 0x000000F1,
                                    .readable_bits = 0x000000F1,
                                    .writable_bits = 0x000000F1, },
                                {
                                    .desc =
                                            "RCC AHB3 peripheral clock enable in low power mode register (RCC_AHB3LPENR)",
                                    .name = "ahb3lpenr",
                                    .offset_bytes = 0x58,
                                    .reset_value = 0x00000001,
                                    .readable_bits = 0x00000001,
                                    .writable_bits = 0x00000001, },
                                {
                                    .desc =
                                            "RCC APB1 peripheral clock enable in low power mode register (RCC_APB1LPENR)",
                                    .name = "apb1lpenr",
                                    .offset_bytes = 0x60,
                                    .reset_value = 0x36FEC9FF,
                                    .readable_bits = 0x3EFEC9FF,
                                    .writable_bits = 0x3EFEC9FF, },
                                {
                                    .desc =
                                            "RCC APB2 peripheral clock enable in low power mode register (RCC_APB2LPENR)",
                                    .name = "apb2lpenr",
                                    .offset_bytes = 0x64,
                                    .reset_value = 0x00075F33,
                                    .readable_bits = 0x00079F33,
                                    .writable_bits = 0x00079F33, },
                                {
                                    .desc =
                                            "RCC Backup domain control register (RCC_BDCR)",
                                    .name = "bdcr",
                                    .offset_bytes = 0x70,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lseon",
                                                            .desc =
                                                                    "External low-speed oscillator enable",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "lserdy",
                                                            .desc =
                                                                    "External low-speed oscillator ready",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "lsebyp",
                                                            .desc =
                                                                    "External low-speed oscillator bypass",
                                                            .first_bit = 2, },
                                                        {
                                                            .name = "rtcsel",
                                                            .desc =
                                                                    "RTC clock source selection",
                                                            .first_bit = 8,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "rtcen",
                                                            .desc =
                                                                    "RTC clock enable",
                                                            .first_bit = 15, },
                                                        {
                                                            .name = "bdrst",
                                                            .desc =
                                                                    "Backup domain software reset",
                                                            .first_bit = 16, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc = "Control/status register (RCC_CSR)",
                                    .name = "csr",
                                    .offset_bytes = 0x74,
                                    .reset_value = 0x0E000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lsion",
                                                            .desc =
                                                                    "Internal low-speed oscillator enable",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "lsirdy",
                                                            .desc =
                                                                    "Internal low-speed oscillator ready",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "rmvf",
                                                            .desc =
                                                                    "Remove reset flag",
                                                            .first_bit = 24, },
                                                        {
                                                            .name = "borrstf",
                                                            .desc =
                                                                    "BOR reset flag",
                                                            .first_bit = 25, },
                                                        {
                                                            .name = "pinrstf",
                                                            .desc =
                                                                    "PIN reset flag",
                                                            .first_bit = 26, },
                                                        {
                                                            .name = "porrstf",
                                                            .desc =
                                                                    "POR/PDR reset flag",
                                                            .first_bit = 27, },
                                                        {
                                                            .name = "stfrstf",
                                                            .desc =
                                                                    "Software reset flag",
                                                            .first_bit = 28, },
                                                        {
                                                            .name = "iwdgrstf",
                                                            .desc =
                                                                    "Independent watchdog reset flag",
                                                            .first_bit = 29, },
                                                        {
                                                            .name = "wwdgrstf",
                                                            .desc =
                                                                    "Window watchdog reset flag",
                                                            .first_bit = 30, },
                                                        {
                                                            .name = "lpwrrstf",
                                                            .desc =
                                                                    "Low-power reset flag",
                                                            .first_bit = 31, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc =
                                            "RCC spread spectrum clock generation register (RCC_SSCGR)",
                                    .name = "sscgr",
                                    .offset_bytes = 0x80,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0xCEFFFFFF,
                                    .writable_bits = 0xCEFFFFFF, },
                                {
                                    .desc =
                                            "RCC PLLI2S configuration register (RCC_PLLI2SCFGR)",
                                    .name = "plli2scfgr",
                                    .offset_bytes = 0x84,
                                    .reset_value = 0x20003000,
                                    .readable_bits = 0x70007FC0,
                                    .writable_bits = 0x70007FC0, },
                                { }, /**/
                            } , /**/
        };

static void stm32f4_01_57_xx_rcc_create_objects(Object *obj)
{
    STM32RCCState *state = STM32_RCC_STATE(obj);

    peripheral_new_with_info(obj, NULL, &stm32f4_01_57_xx_rcc_info);

    state->f4.reg.cr = cm_object_get_child_by_name(obj, "cr");
    state->f4.reg.pllcfgr = cm_object_get_child_by_name(obj, "pllcfgr");
    state->f4.reg.cfgr = cm_object_get_child_by_name(obj, "cfgr");
    state->f4.reg.cir = cm_object_get_child_by_name(obj, "cir");
    state->f4.reg.ahb1rstr = cm_object_get_child_by_name(obj, "ahb1rstr");
    state->f4.reg.ahb2rstr = cm_object_get_child_by_name(obj, "ahb2rstr");
    state->f4.reg.ahb3rstr = cm_object_get_child_by_name(obj, "ahb3rstr");
    state->f4.reg.apb1rstr = cm_object_get_child_by_name(obj, "apb1rstr");
    state->f4.reg.apb2rstr = cm_object_get_child_by_name(obj, "apb2rstr");
    state->f4.reg.ahb1enr = cm_object_get_child_by_name(obj, "ahb1enr");
    state->f4.reg.ahb2enr = cm_object_get_child_by_name(obj, "ahb2enr");
    state->f4.reg.ahb3enr = cm_object_get_child_by_name(obj, "ahb3enr");
    state->f4.reg.apb1enr = cm_object_get_child_by_name(obj, "apb1enr");
    state->f4.reg.apb2enr = cm_object_get_child_by_name(obj, "apb2enr");
    state->f4.reg.ahb1lpenr = cm_object_get_child_by_name(obj, "ahb1lpenr");
    state->f4.reg.ahb2lpenr = cm_object_get_child_by_name(obj, "ahb2lpenr");
    state->f4.reg.ahb3lpenr = cm_object_get_child_by_name(obj, "ahb3lpenr");
    state->f4.reg.apb1lpenr = cm_object_get_child_by_name(obj, "apb1lpenr");
    state->f4.reg.apb2lpenr = cm_object_get_child_by_name(obj, "apb2lpenr");
    state->f4.reg.bdcr = cm_object_get_child_by_name(obj, "bdcr");
    state->f4.reg.csr = cm_object_get_child_by_name(obj, "csr");
    state->f4.reg.bdcr = cm_object_get_child_by_name(obj, "bdcr");
    state->f4.reg.sscgr = cm_object_get_child_by_name(obj, "sscgr");

    /* CR bitfields. */
    state->f4.fld.cr.hsion = cm_object_get_child_by_name(state->f4.reg.cr,
            "hsion");
    state->f4.fld.cr.hsirdy = cm_object_get_child_by_name(state->f4.reg.cr,
            "hsirdy");
    state->f4.fld.cr.hsitrim = cm_object_get_child_by_name(state->f4.reg.cr,
            "hsitrim");
    state->f4.fld.cr.hsical = cm_object_get_child_by_name(state->f4.reg.cr,
            "hsical");
    state->f4.fld.cr.hseon = cm_object_get_child_by_name(state->f4.reg.cr,
            "hseon");
    state->f4.fld.cr.hserdy = cm_object_get_child_by_name(state->f4.reg.cr,
            "hserdy");
    state->f4.fld.cr.hsebyp = cm_object_get_child_by_name(state->f4.reg.cr,
            "hsebyp");
    state->f4.fld.cr.csson = cm_object_get_child_by_name(state->f4.reg.cr,
            "csson");
    state->f4.fld.cr.pllon = cm_object_get_child_by_name(state->f4.reg.cr,
            "pllon");
    state->f4.fld.cr.pllrdy = cm_object_get_child_by_name(state->f4.reg.cr,
            "pllrdy");
    state->f4.fld.cr.plli2son = cm_object_get_child_by_name(state->f4.reg.cr,
            "plli2son");
    state->f4.fld.cr.plli2srdy = cm_object_get_child_by_name(state->f4.reg.cr,
            "plli2srdy");

    /* PLLCFGR bitfields. */
    state->f4.fld.pllcfgr.pllm = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "pllm");
    state->f4.fld.pllcfgr.plln = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "plln");
    state->f4.fld.pllcfgr.pllp = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "pllp");
    state->f4.fld.pllcfgr.pllsrc = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "pllsrc");
    state->f4.fld.pllcfgr.pllq = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "pllq");

    /* CFGR bitfields. */
    state->f4.fld.cfgr.sw = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "sw");
    state->f4.fld.cfgr.sws = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "sws");
    state->f4.fld.cfgr.hpre = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "hpre");
    state->f4.fld.cfgr.ppre1 = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "ppre1");
    state->f4.fld.cfgr.ppre2 = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "ppre2");
    state->f4.fld.cfgr.rtcpre = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "rtcpre");
    state->f4.fld.cfgr.mco1 = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "mco1");
    state->f4.fld.cfgr.i2ssrc = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "i2ssrc");
    state->f4.fld.cfgr.mco1pre = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "mco1pre");
    state->f4.fld.cfgr.mco2pre = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "mco2pre");
    state->f4.fld.cfgr.mco2 = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "mco2");

    /* CIR bitfields. */
    state->f4.fld.cir.lsirdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "lsirdyf");
    state->f4.fld.cir.lserdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "lserdyf");
    state->f4.fld.cir.hsirdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "hsirdyf");
    state->f4.fld.cir.hserdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "hserdyf");
    state->f4.fld.cir.pllrdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "pllrdyf");
    state->f4.fld.cir.plli2srdyf = cm_object_get_child_by_name(
            state->f4.reg.cir, "plli2srdyf");
    state->f4.fld.cir.cssf = cm_object_get_child_by_name(state->f4.reg.cir,
            "cssf");

    /* BDCR bitfields. */
    state->f4.fld.bdcr.lserdy = cm_object_get_child_by_name(state->f4.reg.bdcr,
            "lserdy");

    /* CSR bitfields. */
    state->f4.fld.csr.lsirdy = cm_object_get_child_by_name(state->f4.reg.csr,
            "lsirdy");
    state->f4.fld.csr.pinrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "pinrstf");
    state->f4.fld.csr.porrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "porrstf");
    state->f4.fld.csr.stfrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "stfrstf");
    state->f4.fld.csr.iwdgrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "iwdgrstf");
    state->f4.fld.csr.wwdgrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "wwdgrstf");
    state->f4.fld.csr.lpwrrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "lpwrrstf");

}

/* ------------------------------------------------------------------------- */

/* STM32F411xx */

static PeripheralInfo stm32f411xx_rcc_info =
        {
            .desc = "Reset and clock control (RCC)",

            .registers =
                    (PeripheralRegisterInfo[] ) {
                                {
                                    .desc = "Clock control register (RCC_CR)",
                                    .name = "cr",
                                    .offset_bytes = 0x00,
                                    .reset_value = 0x00000083, /* not 81 */
                                    .reset_mask = 0xFFFF00FF,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "hsion",
                                                            .desc =
                                                                    "Internal high-speed clock enable",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "hsirdy",
                                                            .desc =
                                                                    "Internal high-speed clock ready flag",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hsitrim",
                                                            .desc =
                                                                    "Internal high-speed clock trimming",
                                                            .first_bit = 3,
                                                            .width_bits = 5, },
                                                        {
                                                            .name = "hsical",
                                                            .desc =
                                                                    "Internal high-speed clock calibration",
                                                            .first_bit = 8,
                                                            .width_bits = 8,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hseon",
                                                            .desc =
                                                                    "External clock enable",
                                                            .first_bit = 16, },
                                                        {
                                                            .name = "hserdy",
                                                            .desc =
                                                                    "External high-speed clock ready flag",
                                                            .first_bit = 17,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hsebyp",
                                                            .desc =
                                                                    "External high-speed clock bypass",
                                                            .first_bit = 18, },
                                                        {
                                                            .name = "csson",
                                                            .desc =
                                                                    "Clock security system enable",
                                                            .first_bit = 19, },
                                                        {
                                                            .name = "pllon",
                                                            .desc = "PLL enable",
                                                            .first_bit = 24, },
                                                        {
                                                            .name = "pllrdy",
                                                            .desc =
                                                                    "PLL clock ready flag",
                                                            .first_bit = 25,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "plli2son",
                                                            .desc =
                                                                    "PLL I2S enable",
                                                            .first_bit = 26, },
                                                        {
                                                            .name = "plli2srdy",
                                                            .desc =
                                                                    "PLL I2S clock ready flag",
                                                            .first_bit = 27,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },

                                                        { }, /**/
                                                    } , /**/},
                                {
                                    .desc =
                                            "RCC PLL configuration register (RCC_PLLCFGR)",
                                    .name = "pllcfgr",
                                    .offset_bytes = 0x04,
                                    .reset_value = 0x24003010,
                                    .readable_bits = 0x0F437FFF,
                                    .writable_bits = 0x0F437FFF,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "pllm",
                                                            .desc =
                                                                    "PLL division factor",
                                                            .first_bit = 0,
                                                            .width_bits = 6, },
                                                        {
                                                            .name = "plln",
                                                            .desc =
                                                                    "PLL multiplication factor",
                                                            .first_bit = 6,
                                                            .width_bits = 9, },
                                                        {
                                                            .name = "pllp",
                                                            .desc =
                                                                    "Main PLL (PLL) division factor",
                                                            .first_bit = 16,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "pllsrc",
                                                            .desc =
                                                                    "Main PLL (PLL) clock source",
                                                            .first_bit = 22, },
                                                        {
                                                            .name = "pllq",
                                                            .desc =
                                                                    "Main PLL (PLL) division factor",
                                                            .first_bit = 24,
                                                            .width_bits = 4, },
                                                        { }, } , },
                                {
                                    .desc =
                                            "RCC clock configuration register (RCC_CFGR)",
                                    .name = "cfgr",
                                    .offset_bytes = 0x08,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "sw",
                                                            .desc =
                                                                    "System clock switch",
                                                            .first_bit = 0,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "sws",
                                                            .desc =
                                                                    "System clock switch status",
                                                            .first_bit = 2,
                                                            .width_bits = 2,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hpre",
                                                            .desc =
                                                                    "AHB prescaler",
                                                            .first_bit = 4,
                                                            .width_bits = 4, },
                                                        {
                                                            .name = "ppre1",
                                                            .desc =
                                                                    "APB Low speed prescaler (APB1)",
                                                            .first_bit = 10,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "ppre2",
                                                            .desc =
                                                                    "APB high speed prescaler (APB2)",
                                                            .first_bit = 13,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "rtcpre",
                                                            .desc =
                                                                    "HSE division factor for RTC clock",
                                                            .first_bit = 16,
                                                            .width_bits = 5, },
                                                        {
                                                            .name = "mco1",
                                                            .desc =
                                                                    "Microcontroller clock output 1",
                                                            .first_bit = 21,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "i2ssrc",
                                                            .desc =
                                                                    "I2S clock selection",
                                                            .first_bit = 23, },
                                                        {
                                                            .name = "mco1pre",
                                                            .desc =
                                                                    "MCO1 prescaller",
                                                            .first_bit = 24,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "mco2pre",
                                                            .desc =
                                                                    "MCO2 prescaller",
                                                            .first_bit = 27,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "mco2",
                                                            .desc =
                                                                    "Microcontroller clock output 2",
                                                            .first_bit = 30,
                                                            .width_bits = 2, },
                                                        { }, /**/
                                                    } , /**/},
                                {
                                    .desc = "Clock interrupt register (RCC_CIR)",
                                    .name = "cir",
                                    .offset_bytes = 0x0C,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lsirdyf",
                                                            .desc =
                                                                    "LSI ready interrupt flag",
                                                            .first_bit = 0,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "lserdyf",
                                                            .desc =
                                                                    "LSE ready interrupt flag",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hsirdyf",
                                                            .desc =
                                                                    "HSI ready interrupt flag",
                                                            .first_bit = 2,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hserdyf",
                                                            .desc =
                                                                    "HSE ready interrupt flag",
                                                            .first_bit = 3,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "pllrdyf",
                                                            .desc =
                                                                    "PLL ready interrupt flag",
                                                            .first_bit = 4,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "plli2srdyf",
                                                            .desc =
                                                                    "PLL I2S ready interrupt flag",
                                                            .first_bit = 5,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "cssf",
                                                            .desc =
                                                                    "Clock security system interrupt flag",
                                                            .first_bit = 7,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "lsirdyie",
                                                            .desc =
                                                                    "LSI ready interrupt enable",
                                                            .first_bit = 8, },
                                                        {
                                                            .name = "lserdyie",
                                                            .desc =
                                                                    "LSE ready interrupt enable",
                                                            .first_bit = 9, },
                                                        {
                                                            .name = "hsirdyie",
                                                            .desc =
                                                                    "HSI ready interrupt enable",
                                                            .first_bit = 10, },
                                                        {
                                                            .name = "hserdyie",
                                                            .desc =
                                                                    "HSE ready interrupt enable",
                                                            .first_bit = 11, },
                                                        {
                                                            .name = "pllrdyie",
                                                            .desc =
                                                                    "PLL ready interrupt enable",
                                                            .first_bit = 12, },
                                                        {
                                                            .name =
                                                                    "plli2srdyie",
                                                            .desc =
                                                                    "PLL I2S ready interrupt enable",
                                                            .first_bit = 13, },
                                                        {
                                                            .name = "lsirdyc",
                                                            .desc =
                                                                    "LSI ready interrupt clear",
                                                            .first_bit = 16,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "lserdyc",
                                                            .desc =
                                                                    "LSE ready interrupt clear",
                                                            .first_bit = 17,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "hsirdyc",
                                                            .desc =
                                                                    "HSI ready interrupt clear",
                                                            .first_bit = 18,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "hserdyc",
                                                            .desc =
                                                                    "HSE ready interrupt clear",
                                                            .first_bit = 19,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "pllrdyc",
                                                            .desc =
                                                                    "PLL ready interrupt clear",
                                                            .first_bit = 20,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "plli2srdyc",
                                                            .desc =
                                                                    "PLL I2S ready interrupt clear",
                                                            .first_bit = 21,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "cssc",
                                                            .desc =
                                                                    "Clock security system interrupt clear",
                                                            .first_bit = 23,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc =
                                            "RCC AHB1 peripheral reset register (RCC_AHB1RSTR)",
                                    .name = "ahb1rstr",
                                    .offset_bytes = 0x10,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x0060109F,
                                    .writable_bits = 0x0060109F, },
                                {
                                    .desc =
                                            "RCC AHB2 peripheral reset register (RCC_AHB2RSTR)",
                                    .name = "ahb2rstr",
                                    .offset_bytes = 0x14,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x00000080,
                                    .writable_bits = 0x00000080, },
                                {
                                    .desc =
                                            "RCC APB1 peripheral reset register (RCC_APB1RSTR)",
                                    .name = "apb1rstr",
                                    .offset_bytes = 0x20,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x10E2C80F,
                                    .writable_bits = 0x10E2C80F, },
                                {
                                    .desc =
                                            "RCC APB2 peripheral reset register (RCC_APB2RSTR)",
                                    .name = "apb2rstr",
                                    .offset_bytes = 0x24,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x00177931,
                                    .writable_bits = 0x00177931, },
                                {
                                    .desc =
                                            "RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)",
                                    .name = "ahb1enr",
                                    .offset_bytes = 0x30,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x0050101F,
                                    .writable_bits = 0x0050101F, },
                                {
                                    .desc =
                                            "RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)",
                                    .name = "ahb2enr",
                                    .offset_bytes = 0x34,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x00000080,
                                    .writable_bits = 0x00000080, },
                                {
                                    .desc =
                                            "APB1 peripheral clock enable register (RCC_APB1ENR)",
                                    .name = "apb1enr",
                                    .offset_bytes = 0x40,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x10E2C80F,
                                    .writable_bits = 0x10E2C80F, },
                                {
                                    .desc =
                                            "APB2 peripheral clock enable register (RCC_APB2ENR)",
                                    .name = "apb2enr",
                                    .offset_bytes = 0x44,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x00177931,
                                    .writable_bits = 0x00177931, },
                                {
                                    .desc =
                                            "RCC AHB1 peripheral clock enable in low power mode register (RCC_AHB1LPENR)",
                                    .name = "ahb1lpenr",
                                    .offset_bytes = 0x50,
                                    .reset_value = 0x0061900F,
                                    .readable_bits = 0x0061909F,
                                    .writable_bits = 0x0061909F, },
                                {
                                    .desc =
                                            "RCC AHB2 peripheral clock enable in low power mode register (RCC_AHB2LPENR)",
                                    .name = "ahb2lpenr",
                                    .offset_bytes = 0x54,
                                    .reset_value = 0x00000080,
                                    .readable_bits = 0x00000080,
                                    .writable_bits = 0x00000080, },
                                {
                                    .desc =
                                            "RCC APB1 peripheral clock enable in low power mode register (RCC_APB1LPENR)",
                                    .name = "apb1lpenr",
                                    .offset_bytes = 0x60,
                                    .reset_value = 0x10E2C80F,
                                    .readable_bits = 0x10E2C80F,
                                    .writable_bits = 0x10E2C80F, },
                                {
                                    .desc =
                                            "RCC APB2 peripheral clock enable in low power mode register (RCC_APB2LPENR)",
                                    .name = "apb2lpenr",
                                    .offset_bytes = 0x64,
                                    .reset_value = 0x00077930,
                                    .readable_bits = 0x00179F31,
                                    .writable_bits = 0x00179F31, },
                                {
                                    .desc =
                                            "RCC Backup domain control register (RCC_BDCR)",
                                    .name = "bdcr",
                                    .offset_bytes = 0x70,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lseon",
                                                            .desc =
                                                                    "External low-speed oscillator enable",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "lserdy",
                                                            .desc =
                                                                    "External low-speed oscillator ready",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "lsebyp",
                                                            .desc =
                                                                    "External low-speed oscillator bypass",
                                                            .first_bit = 2, },
                                                        {
                                                            .name = "lsemod",
                                                            .desc =
                                                                    "External low-speed oscillator bypass",
                                                            .first_bit = 3, },
                                                        {
                                                            .name = "rtcsel",
                                                            .desc =
                                                                    "RTC clock source selection",
                                                            .first_bit = 8,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "rtcen",
                                                            .desc =
                                                                    "RTC clock enable",
                                                            .first_bit = 15, },
                                                        {
                                                            .name = "bdrst",
                                                            .desc =
                                                                    "Backup domain software reset",
                                                            .first_bit = 16, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc = "Control/status register (RCC_CSR)",
                                    .name = "csr",
                                    .offset_bytes = 0x74,
                                    .reset_value = 0x0E000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lsion",
                                                            .desc =
                                                                    "Internal low-speed oscillator enable",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "lsirdy",
                                                            .desc =
                                                                    "Internal low-speed oscillator ready",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "rmvf",
                                                            .desc =
                                                                    "Remove reset flag",
                                                            .first_bit = 24, },
                                                        {
                                                            .name = "borrstf",
                                                            .desc =
                                                                    "BOR reset flag",
                                                            .first_bit = 25, },
                                                        {
                                                            .name = "pinrstf",
                                                            .desc =
                                                                    "PIN reset flag",
                                                            .first_bit = 26, },
                                                        {
                                                            .name = "porrstf",
                                                            .desc =
                                                                    "POR/PDR reset flag",
                                                            .first_bit = 27, },
                                                        {
                                                            .name = "stfrstf",
                                                            .desc =
                                                                    "Software reset flag",
                                                            .first_bit = 28, },
                                                        {
                                                            .name = "iwdgrstf",
                                                            .desc =
                                                                    "Independent watchdog reset flag",
                                                            .first_bit = 29, },
                                                        {
                                                            .name = "wwdgrstf",
                                                            .desc =
                                                                    "Window watchdog reset flag",
                                                            .first_bit = 30, },
                                                        {
                                                            .name = "lpwrrstf",
                                                            .desc =
                                                                    "Low-power reset flag",
                                                            .first_bit = 31, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc =
                                            "RCC spread spectrum clock generation register (RCC_SSCGR)",
                                    .name = "sscgr",
                                    .offset_bytes = 0x80,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0xE0FFFFFF,
                                    .writable_bits = 0xE0FFFFFF, },
                                {
                                    .desc =
                                            "RCC PLLI2S configuration register (RCC_PLLI2SCFGR)",
                                    .name = "plli2scfgr",
                                    .offset_bytes = 0x84,
                                    .reset_value = 0x24003000,
                                    .readable_bits = 0x70007FFF,
                                    .writable_bits = 0x70007FFF, },
                                {
                                    .desc =
                                            "RCC Dedicated Clocks Configuration Register (RCC_DCKCFGR)",
                                    .name = "dckcfgr",
                                    .offset_bytes = 0x8C,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x01000000,
                                    .writable_bits = 0x01000000, },
                                { }, /**/
                            } , /**/
        };

static void stm32f411xx_rcc_create_objects(Object *obj)
{
    STM32RCCState *state = STM32_RCC_STATE(obj);

    peripheral_new_with_info(obj, NULL, &stm32f411xx_rcc_info);

    state->f4.reg.cr = cm_object_get_child_by_name(obj, "cr");
    state->f4.reg.pllcfgr = cm_object_get_child_by_name(obj, "pllcfgr");
    state->f4.reg.cfgr = cm_object_get_child_by_name(obj, "cfgr");
    state->f4.reg.cir = cm_object_get_child_by_name(obj, "cir");
    state->f4.reg.ahb1rstr = cm_object_get_child_by_name(obj, "ahb1rstr");
    state->f4.reg.ahb2rstr = cm_object_get_child_by_name(obj, "ahb2rstr");
    state->f4.reg.apb1rstr = cm_object_get_child_by_name(obj, "apb1rstr");
    state->f4.reg.apb2rstr = cm_object_get_child_by_name(obj, "apb2rstr");
    state->f4.reg.ahb1enr = cm_object_get_child_by_name(obj, "ahb1enr");
    state->f4.reg.ahb2enr = cm_object_get_child_by_name(obj, "ahb2enr");
    state->f4.reg.apb1enr = cm_object_get_child_by_name(obj, "apb1enr");
    state->f4.reg.apb2enr = cm_object_get_child_by_name(obj, "apb2enr");
    state->f4.reg.ahb1lpenr = cm_object_get_child_by_name(obj, "ahb1lpenr");
    state->f4.reg.ahb2lpenr = cm_object_get_child_by_name(obj, "ahb2lpenr");
    state->f4.reg.apb1lpenr = cm_object_get_child_by_name(obj, "apb1lpenr");
    state->f4.reg.apb2lpenr = cm_object_get_child_by_name(obj, "apb2lpenr");
    state->f4.reg.bdcr = cm_object_get_child_by_name(obj, "bdcr");
    state->f4.reg.csr = cm_object_get_child_by_name(obj, "csr");
    state->f4.reg.bdcr = cm_object_get_child_by_name(obj, "bdcr");
    state->f4.reg.sscgr = cm_object_get_child_by_name(obj, "sscgr");

    /* CR bitfields. */
    state->f4.fld.cr.hsion = cm_object_get_child_by_name(state->f4.reg.cr,
            "hsion");
    state->f4.fld.cr.hsirdy = cm_object_get_child_by_name(state->f4.reg.cr,
            "hsirdy");
    state->f4.fld.cr.hsitrim = cm_object_get_child_by_name(state->f4.reg.cr,
            "hsitrim");
    state->f4.fld.cr.hsical = cm_object_get_child_by_name(state->f4.reg.cr,
            "hsical");
    state->f4.fld.cr.hseon = cm_object_get_child_by_name(state->f4.reg.cr,
            "hseon");
    state->f4.fld.cr.hserdy = cm_object_get_child_by_name(state->f4.reg.cr,
            "hserdy");
    state->f4.fld.cr.hsebyp = cm_object_get_child_by_name(state->f4.reg.cr,
            "hsebyp");
    state->f4.fld.cr.csson = cm_object_get_child_by_name(state->f4.reg.cr,
            "csson");
    state->f4.fld.cr.pllon = cm_object_get_child_by_name(state->f4.reg.cr,
            "pllon");
    state->f4.fld.cr.pllrdy = cm_object_get_child_by_name(state->f4.reg.cr,
            "pllrdy");
    state->f4.fld.cr.plli2son = cm_object_get_child_by_name(state->f4.reg.cr,
            "plli2son");
    state->f4.fld.cr.plli2srdy = cm_object_get_child_by_name(state->f4.reg.cr,
            "plli2srdy");

    /* PLLCFGR bitfields. */
    state->f4.fld.pllcfgr.pllm = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "pllm");
    state->f4.fld.pllcfgr.plln = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "plln");
    state->f4.fld.pllcfgr.pllp = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "pllp");
    state->f4.fld.pllcfgr.pllsrc = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "pllsrc");
    state->f4.fld.pllcfgr.pllq = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "pllq");

    /* CFGR bitfields. */
    state->f4.fld.cfgr.sw = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "sw");
    state->f4.fld.cfgr.sws = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "sws");
    state->f4.fld.cfgr.hpre = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "hpre");
    state->f4.fld.cfgr.ppre1 = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "ppre1");
    state->f4.fld.cfgr.ppre2 = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "ppre2");
    state->f4.fld.cfgr.rtcpre = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "rtcpre");
    state->f4.fld.cfgr.mco1 = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "mco1");
    state->f4.fld.cfgr.i2ssrc = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "i2ssrc");
    state->f4.fld.cfgr.mco1pre = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "mco1pre");
    state->f4.fld.cfgr.mco2pre = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "mco2pre");
    state->f4.fld.cfgr.mco2 = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "mco2");

    /* CIR bitfields. */
    state->f4.fld.cir.lsirdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "lsirdyf");
    state->f4.fld.cir.lserdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "lserdyf");
    state->f4.fld.cir.hsirdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "hsirdyf");
    state->f4.fld.cir.hserdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "hserdyf");
    state->f4.fld.cir.pllrdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "pllrdyf");
    state->f4.fld.cir.plli2srdyf = cm_object_get_child_by_name(
            state->f4.reg.cir, "plli2srdyf");
    state->f4.fld.cir.cssf = cm_object_get_child_by_name(state->f4.reg.cir,
            "cssf");

    /* BDCR bitfields. */
    state->f4.fld.bdcr.lserdy = cm_object_get_child_by_name(state->f4.reg.bdcr,
            "lserdy");

    /* CSR bitfields. */
    state->f4.fld.csr.lsirdy = cm_object_get_child_by_name(state->f4.reg.csr,
            "lsirdy");
    state->f4.fld.csr.pinrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "pinrstf");
    state->f4.fld.csr.porrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "porrstf");
    state->f4.fld.csr.stfrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "stfrstf");
    state->f4.fld.csr.iwdgrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "iwdgrstf");
    state->f4.fld.csr.wwdgrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "wwdgrstf");
    state->f4.fld.csr.lpwrrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "lpwrrstf");

}

/* ------------------------------------------------------------------------- */

/* STM32F4_23_xxx */

static PeripheralInfo stm32f4_23_xxx_rcc_info =
        {
            .desc = "Reset and clock control (RCC)",

            .registers =
                    (PeripheralRegisterInfo[] ) {
                                {
                                    .desc = "Clock control register (RCC_CR)",
                                    .name = "cr",
                                    .offset_bytes = 0x00,
                                    .reset_value = 0x00000083,
                                    .reset_mask = 0xFFFF00FF,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "hsion",
                                                            .desc =
                                                                    "Internal high-speed clock enable",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "hsirdy",
                                                            .desc =
                                                                    "Internal high-speed clock ready flag",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hsitrim",
                                                            .desc =
                                                                    "Internal high-speed clock trimming",
                                                            .first_bit = 3,
                                                            .width_bits = 5, },
                                                        {
                                                            .name = "hsical",
                                                            .desc =
                                                                    "Internal high-speed clock calibration",
                                                            .first_bit = 8,
                                                            .width_bits = 8,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hseon",
                                                            .desc =
                                                                    "External clock enable",
                                                            .first_bit = 16, },
                                                        {
                                                            .name = "hserdy",
                                                            .desc =
                                                                    "External high-speed clock ready flag",
                                                            .first_bit = 17,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hsebyp",
                                                            .desc =
                                                                    "External high-speed clock bypass",
                                                            .first_bit = 18, },
                                                        {
                                                            .name = "csson",
                                                            .desc =
                                                                    "Clock security system enable",
                                                            .first_bit = 19, },
                                                        {
                                                            .name = "pllon",
                                                            .desc = "PLL enable",
                                                            .first_bit = 24, },
                                                        {
                                                            .name = "pllrdy",
                                                            .desc =
                                                                    "PLL clock ready flag",
                                                            .first_bit = 25,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "plli2son",
                                                            .desc =
                                                                    "PLL I2S enable",
                                                            .first_bit = 26, },
                                                        {
                                                            .name = "plli2srdy",
                                                            .desc =
                                                                    "PLL I2S clock ready flag",
                                                            .first_bit = 27,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "pllsaion",
                                                            .desc =
                                                                    "PLL SAI enable",
                                                            .first_bit = 28, },
                                                        {
                                                            .name = "pllsairdy",
                                                            .desc =
                                                                    "PLL SAI clock ready flag",
                                                            .first_bit = 29,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        { }, /**/
                                                    } , /**/},
                                {
                                    .desc =
                                            "RCC PLL configuration register (RCC_PLLCFGR)",
                                    .name = "pllcfgr",
                                    .offset_bytes = 0x04,
                                    .reset_value = 0x24003010,
                                    .readable_bits = 0x0F437FFF,
                                    .writable_bits = 0x0F437FFF,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "pllm",
                                                            .desc =
                                                                    "PLL division factor",
                                                            .first_bit = 0,
                                                            .width_bits = 6, },
                                                        {
                                                            .name = "plln",
                                                            .desc =
                                                                    "PLL multiplication factor",
                                                            .first_bit = 6,
                                                            .width_bits = 9, },
                                                        {
                                                            .name = "pllp",
                                                            .desc =
                                                                    "Main PLL (PLL) division factor",
                                                            .first_bit = 16,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "pllsrc",
                                                            .desc =
                                                                    "Main PLL (PLL) clock source",
                                                            .first_bit = 22, },
                                                        {
                                                            .name = "pllq",
                                                            .desc =
                                                                    "Main PLL (PLL) division factor",
                                                            .first_bit = 24,
                                                            .width_bits = 4, },
                                                        { }, } , },
                                {
                                    .desc =
                                            "RCC clock configuration register (RCC_CFGR)",
                                    .name = "cfgr",
                                    .offset_bytes = 0x08,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "sw",
                                                            .desc =
                                                                    "System clock switch",
                                                            .first_bit = 0,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "sws",
                                                            .desc =
                                                                    "System clock switch status",
                                                            .first_bit = 2,
                                                            .width_bits = 2,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hpre",
                                                            .desc =
                                                                    "AHB prescaler",
                                                            .first_bit = 4,
                                                            .width_bits = 4, },
                                                        {
                                                            .name = "ppre1",
                                                            .desc =
                                                                    "APB Low speed prescaler (APB1)",
                                                            .first_bit = 10,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "ppre2",
                                                            .desc =
                                                                    "APB high speed prescaler (APB2)",
                                                            .first_bit = 13,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "rtcpre",
                                                            .desc =
                                                                    "HSE division factor for RTC clock",
                                                            .first_bit = 16,
                                                            .width_bits = 5, },
                                                        {
                                                            .name = "mco1",
                                                            .desc =
                                                                    "Microcontroller clock output 1",
                                                            .first_bit = 21,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "i2ssrc",
                                                            .desc =
                                                                    "I2S clock selection",
                                                            .first_bit = 23, },
                                                        {
                                                            .name = "mco1pre",
                                                            .desc =
                                                                    "MCO1 prescaller",
                                                            .first_bit = 24,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "mco2pre",
                                                            .desc =
                                                                    "MCO2 prescaller",
                                                            .first_bit = 27,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "mco2",
                                                            .desc =
                                                                    "Microcontroller clock output 2",
                                                            .first_bit = 30,
                                                            .width_bits = 2, },
                                                        { }, /**/
                                                    } , /**/},
                                {
                                    .desc = "Clock interrupt register (RCC_CIR)",
                                    .name = "cir",
                                    .offset_bytes = 0x0C,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lsirdyf",
                                                            .desc =
                                                                    "LSI ready interrupt flag",
                                                            .first_bit = 0,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "lserdyf",
                                                            .desc =
                                                                    "LSE ready interrupt flag",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hsirdyf",
                                                            .desc =
                                                                    "HSI ready interrupt flag",
                                                            .first_bit = 2,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "hserdyf",
                                                            .desc =
                                                                    "HSE ready interrupt flag",
                                                            .first_bit = 3,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "pllrdyf",
                                                            .desc =
                                                                    "PLL ready interrupt flag",
                                                            .first_bit = 4,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "plli2srdyf",
                                                            .desc =
                                                                    "PLL I2S ready interrupt flag",
                                                            .first_bit = 5,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "pllsairdyf",
                                                            .desc =
                                                                    "PLL SAI ready interrupt flag",
                                                            .first_bit = 6,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "cssf",
                                                            .desc =
                                                                    "Clock security system interrupt flag",
                                                            .first_bit = 7,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "lsirdyie",
                                                            .desc =
                                                                    "LSI ready interrupt enable",
                                                            .first_bit = 8, },
                                                        {
                                                            .name = "lserdyie",
                                                            .desc =
                                                                    "LSE ready interrupt enable",
                                                            .first_bit = 9, },
                                                        {
                                                            .name = "hsirdyie",
                                                            .desc =
                                                                    "HSI ready interrupt enable",
                                                            .first_bit = 10, },
                                                        {
                                                            .name = "hserdyie",
                                                            .desc =
                                                                    "HSE ready interrupt enable",
                                                            .first_bit = 11, },
                                                        {
                                                            .name = "pllrdyie",
                                                            .desc =
                                                                    "PLL ready interrupt enable",
                                                            .first_bit = 12, },
                                                        {
                                                            .name =
                                                                    "plli2srdyie",
                                                            .desc =
                                                                    "PLL I2S ready interrupt enable",
                                                            .first_bit = 13, },
                                                        {
                                                            .name =
                                                                    "pllsairdyie",
                                                            .desc =
                                                                    "PLL SAI ready interrupt enable",
                                                            .first_bit = 14, },
                                                        {
                                                            .name = "lsirdyc",
                                                            .desc =
                                                                    "LSI ready interrupt clear",
                                                            .first_bit = 16,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "lserdyc",
                                                            .desc =
                                                                    "LSE ready interrupt clear",
                                                            .first_bit = 17,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "hsirdyc",
                                                            .desc =
                                                                    "HSI ready interrupt clear",
                                                            .first_bit = 18,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "hserdyc",
                                                            .desc =
                                                                    "HSE ready interrupt clear",
                                                            .first_bit = 19,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "pllrdyc",
                                                            .desc =
                                                                    "PLL ready interrupt clear",
                                                            .first_bit = 20,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "plli2srdyc",
                                                            .desc =
                                                                    "PLL I2S ready interrupt clear",
                                                            .first_bit = 21,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "pllsairdyc",
                                                            .desc =
                                                                    "PLL SAI ready interrupt clear",
                                                            .first_bit = 22,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "cssc",
                                                            .desc =
                                                                    "Clock security system interrupt clear",
                                                            .first_bit = 23,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc =
                                            "RCC AHB1 peripheral reset register (RCC_AHB1RSTR)",
                                    .name = "ahb1rstr",
                                    .offset_bytes = 0x10,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x22E017FF,
                                    .writable_bits = 0x22E017FF, },
                                {
                                    .desc =
                                            "RCC AHB2 peripheral reset register (RCC_AHB2RSTR)",
                                    .name = "ahb2rstr",
                                    .offset_bytes = 0x14,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x000000F1,
                                    .writable_bits = 0x000000F1, },
                                {
                                    .desc =
                                            "RCC AHB3 peripheral reset register (RCC_AHB3RSTR)",
                                    .name = "ahb3rstr",
                                    .offset_bytes = 0x18,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x00000001,
                                    .writable_bits = 0x00000001, },
                                {
                                    .desc =
                                            "RCC APB1 peripheral reset register (RCC_APB1RSTR)",
                                    .name = "apb1rstr",
                                    .offset_bytes = 0x20,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0xF6FEC9FF,
                                    .writable_bits = 0xF6FEC9FF, },
                                {
                                    .desc =
                                            "RCC APB2 peripheral reset register (RCC_APB2RSTR)",
                                    .name = "apb2rstr",
                                    .offset_bytes = 0x24,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x04777933,
                                    .writable_bits = 0x04777933, },
                                {
                                    .desc =
                                            "RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)",
                                    .name = "ahb1enr",
                                    .offset_bytes = 0x30,
                                    .reset_value = 0x00100000,
                                    .readable_bits = 0x7EFC17FF,
                                    .writable_bits = 0x7EFC17FF, },
                                {
                                    .desc =
                                            "RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)",
                                    .name = "ahb2enr",
                                    .offset_bytes = 0x34,
                                    .reset_value = 0x00100000,
                                    .readable_bits = 0x000000F1,
                                    .writable_bits = 0x000000F1, },
                                {
                                    .desc =
                                            "RCC AHB3 peripheral clock enable register (RCC_AHB3ENR)",
                                    .name = "ahb3enr",
                                    .offset_bytes = 0x38,
                                    .reset_value = 0x00100000,
                                    .readable_bits = 0x00000001,
                                    .writable_bits = 0x00000001, },
                                {
                                    .desc =
                                            "APB1 peripheral clock enable register (RCC_APB1ENR)",
                                    .name = "apb1enr",
                                    .offset_bytes = 0x40,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0xF6FEC9FF,
                                    .writable_bits = 0xF6FEC9FF, },
                                {
                                    .desc =
                                            "APB2 peripheral clock enable register (RCC_APB2ENR)",
                                    .name = "apb2enr",
                                    .offset_bytes = 0x44,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x04777F33,
                                    .writable_bits = 0x04777F33, },
                                {
                                    .desc =
                                            "RCC AHB1 peripheral clock enable in low power mode register (RCC_AHB1LPENR)",
                                    .name = "ahb1lpenr",
                                    .offset_bytes = 0x50,
                                    .reset_value = 0x7E6791FF,
                                    .readable_bits = 0x7EEF9EFF,
                                    .writable_bits = 0x7EEF9EFF, },
                                {
                                    .desc =
                                            "RCC AHB2 peripheral clock enable in low power mode register (RCC_AHB2LPENR)",
                                    .name = "ahb2lpenr",
                                    .offset_bytes = 0x54,
                                    .reset_value = 0x000000F1,
                                    .readable_bits = 0x000000F1,
                                    .writable_bits = 0x000000F1, },
                                {
                                    .desc =
                                            "RCC AHB3 peripheral clock enable in low power mode register (RCC_AHB3LPENR)",
                                    .name = "ahb3lpenr",
                                    .offset_bytes = 0x58,
                                    .reset_value = 0x00000001,
                                    .readable_bits = 0x00000001,
                                    .writable_bits = 0x00000001, },
                                {
                                    .desc =
                                            "RCC APB1 peripheral clock enable in low power mode register (RCC_APB1LPENR)",
                                    .name = "apb1lpenr",
                                    .offset_bytes = 0x60,
                                    .reset_value = 0x36FEC9FF,
                                    .readable_bits = 0xFEFEC9FF,
                                    .writable_bits = 0xFEFEC9FF, },
                                {
                                    .desc =
                                            "RCC APB2 peripheral clock enable in low power mode register (RCC_APB2LPENR)",
                                    .name = "apb2lpenr",
                                    .offset_bytes = 0x64,
                                    .reset_value = 0x00075F33,
                                    .readable_bits = 0x04777F33,
                                    .writable_bits = 0x04777F33, },
                                {
                                    .desc =
                                            "RCC Backup domain control register (RCC_BDCR)",
                                    .name = "bdcr",
                                    .offset_bytes = 0x70,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lseon",
                                                            .desc =
                                                                    "External low-speed oscillator enable",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "lserdy",
                                                            .desc =
                                                                    "External low-speed oscillator ready",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "lsebyp",
                                                            .desc =
                                                                    "External low-speed oscillator bypass",
                                                            .first_bit = 2, },
                                                        {
                                                            .name = "rtcsel",
                                                            .desc =
                                                                    "RTC clock source selection",
                                                            .first_bit = 8,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "rtcen",
                                                            .desc =
                                                                    "RTC clock enable",
                                                            .first_bit = 15, },
                                                        {
                                                            .name = "bdrst",
                                                            .desc =
                                                                    "Backup domain software reset",
                                                            .first_bit = 16, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc = "Control/status register (RCC_CSR)",
                                    .name = "csr",
                                    .offset_bytes = 0x74,
                                    .reset_value = 0x0E000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lsion",
                                                            .desc =
                                                                    "Internal low-speed oscillator enable",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "lsirdy",
                                                            .desc =
                                                                    "Internal low-speed oscillator ready",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "rmvf",
                                                            .desc =
                                                                    "Remove reset flag",
                                                            .first_bit = 24, },
                                                        {
                                                            .name = "borrstf",
                                                            .desc =
                                                                    "BOR reset flag",
                                                            .first_bit = 25, },
                                                        {
                                                            .name = "pinrstf",
                                                            .desc =
                                                                    "PIN reset flag",
                                                            .first_bit = 26, },
                                                        {
                                                            .name = "porrstf",
                                                            .desc =
                                                                    "POR/PDR reset flag",
                                                            .first_bit = 27, },
                                                        {
                                                            .name = "stfrstf",
                                                            .desc =
                                                                    "Software reset flag",
                                                            .first_bit = 28, },
                                                        {
                                                            .name = "iwdgrstf",
                                                            .desc =
                                                                    "Independent watchdog reset flag",
                                                            .first_bit = 29, },
                                                        {
                                                            .name = "wwdgrstf",
                                                            .desc =
                                                                    "Window watchdog reset flag",
                                                            .first_bit = 30, },
                                                        {
                                                            .name = "lpwrrstf",
                                                            .desc =
                                                                    "Low-power reset flag",
                                                            .first_bit = 31, },
                                                        { }, /**/
                                                    } , /**/
                                },
                                {
                                    .desc =
                                            "RCC spread spectrum clock generation register (RCC_SSCGR)",
                                    .name = "sscgr",
                                    .offset_bytes = 0x80,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0xCEFFFFFF,
                                    .writable_bits = 0xCEFFFFFF, },
                                {
                                    .desc =
                                            "RCC PLLI2S configuration register (RCC_PLLI2SCFGR)",
                                    .name = "plli2scfgr",
                                    .offset_bytes = 0x84,
                                    .reset_value = 0x20003000,
                                    .readable_bits = 0x7F007FC0,
                                    .writable_bits = 0x7F007FC0, },
                                {
                                    .desc =
                                            "RCC PLLSAI configuration register (RCC_PLLI2SCFGR)",
                                    .name = "pllsaicfgr",
                                    .offset_bytes = 0x88,
                                    .reset_value = 0x24003000,
                                    .readable_bits = 0x7F007FC0,
                                    .writable_bits = 0x7F007FC0, },
                                {
                                    .desc =
                                            "RCC Dedicated Clock Configuration Register (RCC_DCKCFGR)",
                                    .name = "plldckcfgr",
                                    .offset_bytes = 0x8C,
                                    .reset_value = 0x00000000,
                                    .readable_bits = 0x01F31F1F,
                                    .writable_bits = 0x01F31F1F, },
                                { }, /**/
                            } , /**/
        };

static void stm32f4_23_xxx_rcc_create_objects(Object *obj)
{
    STM32RCCState *state = STM32_RCC_STATE(obj);

    peripheral_new_with_info(obj, NULL, &stm32f4_23_xxx_rcc_info);

    state->f4.reg.cr = cm_object_get_child_by_name(obj, "cr");
    state->f4.reg.pllcfgr = cm_object_get_child_by_name(obj, "pllcfgr");
    state->f4.reg.cfgr = cm_object_get_child_by_name(obj, "cfgr");
    state->f4.reg.cir = cm_object_get_child_by_name(obj, "cir");
    state->f4.reg.ahb1rstr = cm_object_get_child_by_name(obj, "ahb1rstr");
    state->f4.reg.ahb2rstr = cm_object_get_child_by_name(obj, "ahb2rstr");
    state->f4.reg.ahb3rstr = cm_object_get_child_by_name(obj, "ahb3rstr");
    state->f4.reg.apb1rstr = cm_object_get_child_by_name(obj, "apb1rstr");
    state->f4.reg.apb2rstr = cm_object_get_child_by_name(obj, "apb2rstr");
    state->f4.reg.ahb1enr = cm_object_get_child_by_name(obj, "ahb1enr");
    state->f4.reg.ahb2enr = cm_object_get_child_by_name(obj, "ahb2enr");
    state->f4.reg.ahb3enr = cm_object_get_child_by_name(obj, "ahb3enr");
    state->f4.reg.apb1enr = cm_object_get_child_by_name(obj, "apb1enr");
    state->f4.reg.apb2enr = cm_object_get_child_by_name(obj, "apb2enr");
    state->f4.reg.ahb1lpenr = cm_object_get_child_by_name(obj, "ahb1lpenr");
    state->f4.reg.ahb2lpenr = cm_object_get_child_by_name(obj, "ahb2lpenr");
    state->f4.reg.ahb3lpenr = cm_object_get_child_by_name(obj, "ahb3lpenr");
    state->f4.reg.apb1lpenr = cm_object_get_child_by_name(obj, "apb1lpenr");
    state->f4.reg.apb2lpenr = cm_object_get_child_by_name(obj, "apb2lpenr");
    state->f4.reg.bdcr = cm_object_get_child_by_name(obj, "bdcr");
    state->f4.reg.csr = cm_object_get_child_by_name(obj, "csr");
    state->f4.reg.bdcr = cm_object_get_child_by_name(obj, "bdcr");
    state->f4.reg.sscgr = cm_object_get_child_by_name(obj, "sscgr");
    state->f4.reg.plli2scfgr = cm_object_get_child_by_name(obj, "plli2scfgr");
    state->f4.reg.pllsaicfgr = cm_object_get_child_by_name(obj, "pllsaicfgr");
    state->f4.reg.plldckcfgr = cm_object_get_child_by_name(obj, "plldckcfgr");

    /* CR bitfields. */
    state->f4.fld.cr.hsion = cm_object_get_child_by_name(state->f4.reg.cr,
            "hsion");
    state->f4.fld.cr.hsirdy = cm_object_get_child_by_name(state->f4.reg.cr,
            "hsirdy");
    state->f4.fld.cr.hsitrim = cm_object_get_child_by_name(state->f4.reg.cr,
            "hsitrim");
    state->f4.fld.cr.hsical = cm_object_get_child_by_name(state->f4.reg.cr,
            "hsical");
    state->f4.fld.cr.hseon = cm_object_get_child_by_name(state->f4.reg.cr,
            "hseon");
    state->f4.fld.cr.hserdy = cm_object_get_child_by_name(state->f4.reg.cr,
            "hserdy");
    state->f4.fld.cr.hsebyp = cm_object_get_child_by_name(state->f4.reg.cr,
            "hsebyp");
    state->f4.fld.cr.csson = cm_object_get_child_by_name(state->f4.reg.cr,
            "csson");
    state->f4.fld.cr.pllon = cm_object_get_child_by_name(state->f4.reg.cr,
            "pllon");
    state->f4.fld.cr.pllrdy = cm_object_get_child_by_name(state->f4.reg.cr,
            "pllrdy");
    state->f4.fld.cr.plli2son = cm_object_get_child_by_name(state->f4.reg.cr,
            "plli2son");
    state->f4.fld.cr.plli2srdy = cm_object_get_child_by_name(state->f4.reg.cr,
            "plli2srdy");
    state->f4.fld.cr.pllsaion = cm_object_get_child_by_name(state->f4.reg.cr,
            "pllsaion");
    state->f4.fld.cr.pllsairdy = cm_object_get_child_by_name(state->f4.reg.cr,
            "pllsairdy");

    /* PLLCFGR bitfields. */
    state->f4.fld.pllcfgr.pllm = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "pllm");
    state->f4.fld.pllcfgr.plln = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "plln");
    state->f4.fld.pllcfgr.pllp = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "pllp");
    state->f4.fld.pllcfgr.pllsrc = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "pllsrc");
    state->f4.fld.pllcfgr.pllq = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "pllq");

    /* CFGR bitfields. */
    state->f4.fld.cfgr.sw = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "sw");
    state->f4.fld.cfgr.sws = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "sws");
    state->f4.fld.cfgr.hpre = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "hpre");
    state->f4.fld.cfgr.ppre1 = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "ppre1");
    state->f4.fld.cfgr.ppre2 = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "ppre2");
    state->f4.fld.cfgr.rtcpre = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "rtcpre");
    state->f4.fld.cfgr.mco1 = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "mco1");
    state->f4.fld.cfgr.i2ssrc = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "i2ssrc");
    state->f4.fld.cfgr.mco1pre = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "mco1pre");
    state->f4.fld.cfgr.mco2pre = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "mco2pre");
    state->f4.fld.cfgr.mco2 = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "mco2");

    /* CIR bitfields. */
    state->f4.fld.cir.lsirdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "lsirdyf");
    state->f4.fld.cir.lserdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "lserdyf");
    state->f4.fld.cir.hsirdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "hsirdyf");
    state->f4.fld.cir.hserdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "hserdyf");
    state->f4.fld.cir.pllrdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "pllrdyf");
    state->f4.fld.cir.plli2srdyf = cm_object_get_child_by_name(
            state->f4.reg.cir, "plli2srdyf");
    state->f4.fld.cir.pllsairdyf = cm_object_get_child_by_name(
            state->f4.reg.cir, "pllsairdyf");
    state->f4.fld.cir.cssf = cm_object_get_child_by_name(state->f4.reg.cir,
            "cssf");

    /* BDCR bitfields. */
    state->f4.fld.bdcr.lserdy = cm_object_get_child_by_name(state->f4.reg.bdcr,
            "lserdy");

    /* CSR bitfields. */
    state->f4.fld.csr.lsirdy = cm_object_get_child_by_name(state->f4.reg.csr,
            "lsirdy");
    state->f4.fld.csr.borrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "borrstf");
    state->f4.fld.csr.pinrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "pinrstf");
    state->f4.fld.csr.porrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "porrstf");
    state->f4.fld.csr.stfrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "stfrstf");
    state->f4.fld.csr.iwdgrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "iwdgrstf");
    state->f4.fld.csr.wwdgrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "wwdgrstf");
    state->f4.fld.csr.lpwrrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "lpwrrstf");

}

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

/* ------------------------------------------------------------------------- */

static void stm32_rcc_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value)
{
    STM32RCCState *state = STM32_RCC_STATE(periph);
    stm32_rcc_update_clocks(state);
}

/**
 * Recompute the system clock, after each change in the RCC registers.
 * The code is inspired by CMSIS init sequences.
 */
static void stm32_rcc_update_clocks(STM32RCCState *state)
{
    const STM32Capabilities *capabilities = state->capabilities;

    uint32_t cpu_freq_hz = 0;
    uint32_t pre_scaler;

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
        pre_scaler = AHBPrescTable[register_bitfield_read_value(
                state->f1.cfgr.hpre)];
        /* HCLK clock frequency */
        cpu_freq_hz >>= pre_scaler;

        break;

    case STM32_FAMILY_F4:

        /* The following code was copied from the CMSIS system_stm32f4xx.c  */

        /* Get SYSCLK source */
        switch (register_bitfield_read_value(state->f4.fld.cfgr.sws)) {
        case 0:
            /* HSI used as system clock source */
            cpu_freq_hz = state->hsi_freq_hz;
            break;

        case 1:
            /* HSE used as system clock source */
            cpu_freq_hz = state->hse_freq_hz;
            break;

        case 2:

            /* PLL used as system clock source */
        {
            uint32_t pllm;
            uint32_t pllvco = 0;
            /*
             * PLL_VCO = (HSE_VALUE or HSI_VALUE / PLL_M) * PLL_N
             * SYSCLK = PLL_VCO / PLL_P
             */
            pllm = register_bitfield_read_value(state->f4.fld.pllcfgr.pllm);
            if (!register_bitfield_is_zero(state->f4.fld.pllcfgr.pllsrc)) {
                /* HSE used as PLL clock source */
                pllvco = (state->hse_freq_hz / pllm)
                        * register_bitfield_read_value(
                                state->f4.fld.pllcfgr.plln);
            } else {
                /* HSI used as PLL clock source */
                pllvco = (state->hsi_freq_hz / pllm)
                        * register_bitfield_read_value(
                                state->f4.fld.pllcfgr.plln);
            }

            uint32_t pllp;
            pllp = ((register_bitfield_read_value(state->f4.fld.pllcfgr.pllp))
                    + 1) * 2;
            cpu_freq_hz = pllvco / pllp;
        }
            break;
        default:
            cpu_freq_hz = state->hsi_freq_hz;
            break;
        }
        /*
         * Compute HCLK clock frequency. Get HCLK pre-scaler.
         */
        pre_scaler = AHBPrescTable[register_bitfield_read_value(
                state->f4.fld.cfgr.hpre)];
        /* HCLK frequency */
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
    state->hse_freq_hz = 0; /* No HSE */

    cm_object_property_add_uint32(obj, "lse-freq-hz", &state->lse_freq_hz);
    state->lse_freq_hz = 0; /* No LSE */

    cm_object_property_add_uint32(obj, "hsi-freq-hz", &state->hsi_freq_hz);
    state->hsi_freq_hz = 0;

    cm_object_property_add_uint32(obj, "lsi-freq-hz", &state->lsi_freq_hz);
    state->lsi_freq_hz = 0;
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

    case STM32_FAMILY_F4:
        addr = 0x40023800;
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

    assert(capabilities->hsi_freq_hz);
    assert(capabilities->lsi_freq_hz);

    /* Set defaults, need to be non-zero */
    if (state->hsi_freq_hz == 0) {
        state->hsi_freq_hz = capabilities->hsi_freq_hz;
    }

    if (state->lsi_freq_hz == 0) {
        state->lsi_freq_hz = capabilities->lsi_freq_hz;
    }

    switch (capabilities->family) {
    case STM32_FAMILY_F1:

        if (!capabilities->f1.is_cl) {

            stm32f1_rcc_create_objects(obj);

            /* Callbacks. */
            peripheral_register_set_post_write(state->f1.reg.cr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f1.reg.cfgr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f1.reg.bdcr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f1.reg.csr,
                    &stm32_rcc_post_write_callback);

            /* Auto bits. */
            cm_object_property_set_str(state->f1.cr.hsirdy, "hsion", "follows");

            if (state->hse_freq_hz) {
                cm_object_property_set_str(state->f1.cr.hserdy, "hseon",
                        "follows");
            }
            cm_object_property_set_str(state->f1.cr.pllrdy, "pllon", "follows");

            cm_object_property_set_str(state->f1.cfgr.sws, "sw", "follows");

            cm_object_property_set_str(state->f1.cir.lsirdyf, "lsirdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f1.cir.lserdyf, "lserdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f1.cir.hsirdyf, "hsirdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f1.cir.hserdyf, "hserdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f1.cir.pllrdyf, "pllrdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f1.cir.cssf, "cssc",
                    "cleared-by");

            cm_object_property_set_str(state->f1.bdcr.lserdy, "lseon",
                    "follows");

            cm_object_property_set_str(state->f1.csr.lsirdy, "lsion",
                    "follows");
            cm_object_property_set_str(state->f1.csr.pinrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f1.csr.porrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f1.csr.stfrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f1.csr.iwdgrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f1.csr.wwdgrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f1.csr.lrwrrstf, "rmvf",
                    "cleared-by");

        } else {

            stm32f1cl_rcc_create_objects(obj);

            /* Add callbacks. */
            peripheral_register_set_post_write(state->f1.reg.cr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f1.reg.cfgr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f1.reg.bdcr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f1.reg.csr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f1.reg.cfgr2,
                    &stm32_rcc_post_write_callback);

            /* Auto bits. */
            cm_object_property_set_str(state->f1.cr.hsirdy, "hsion", "follows");
            if (state->hse_freq_hz) {
                cm_object_property_set_str(state->f1.cr.hserdy, "hseon",
                        "follows");
            }
            cm_object_property_set_str(state->f1.cr.pllrdy, "pllon", "follows");
            cm_object_property_set_str(state->f1.cr.pll2rdy, "pll2on",
                    "follows");
            cm_object_property_set_str(state->f1.cr.pll3rdy, "pll3on",
                    "follows");

            cm_object_property_set_str(state->f1.cfgr.sws, "sw", "follows");

            cm_object_property_set_str(state->f1.cir.lsirdyf, "lsirdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f1.cir.lserdyf, "lserdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f1.cir.hsirdyf, "hsirdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f1.cir.hserdyf, "hserdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f1.cir.pllrdyf, "pllrdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f1.cir.pll2rdyf, "pll2rdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f1.cir.pll3rdyf, "pll3rdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f1.cir.cssf, "cssc",
                    "cleared-by");

            cm_object_property_set_str(state->f1.bdcr.lserdy, "lseon",
                    "follows");

            cm_object_property_set_str(state->f1.csr.lsirdy, "lsion",
                    "follows");
            cm_object_property_set_str(state->f1.csr.pinrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f1.csr.porrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f1.csr.stfrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f1.csr.iwdgrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f1.csr.wwdgrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f1.csr.lrwrrstf, "rmvf",
                    "cleared-by");
        }
        break;

    case STM32_FAMILY_F4:

        if (capabilities->f4.is_01_57_xx) {

            stm32f4_01_57_xx_rcc_create_objects(obj);

            /* Add callbacks. */
            peripheral_register_set_post_write(state->f4.reg.pllcfgr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f4.reg.cfgr,
                    &stm32_rcc_post_write_callback);

            /* Auto bits. */
            cm_object_property_set_str(state->f4.fld.cr.hsirdy, "hsion",
                    "follows");
            if (state->hse_freq_hz) {
                cm_object_property_set_str(state->f4.fld.cr.hserdy, "hseon",
                        "follows");
            }
            cm_object_property_set_str(state->f4.fld.cr.pllrdy, "pllon",
                    "follows");
            cm_object_property_set_str(state->f4.fld.cr.plli2srdy, "plli2son",
                    "follows");

            cm_object_property_set_str(state->f4.fld.cfgr.sws, "sw", "follows");

            cm_object_property_set_str(state->f4.fld.cir.lsirdyf, "lsirdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.lserdyf, "lserdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.hsirdyf, "hsirdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.hserdyf, "hserdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.pllrdyf, "pllrdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.plli2srdyf,
                    "plli2srdyc", "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.cssf, "cssc",
                    "cleared-by");

            cm_object_property_set_str(state->f4.fld.bdcr.lserdy, "lseon",
                    "follows");

            cm_object_property_set_str(state->f4.fld.csr.lsirdy, "lsion",
                    "follows");
            cm_object_property_set_str(state->f4.fld.csr.pinrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.porrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.stfrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.iwdgrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.wwdgrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.lpwrrstf, "rmvf",
                    "cleared-by");

        } else if (capabilities->f4.is11xx) {

            stm32f411xx_rcc_create_objects(obj);

            /* Add callbacks. */
            peripheral_register_set_post_write(state->f4.reg.pllcfgr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f4.reg.cfgr,
                    &stm32_rcc_post_write_callback);

            /* Auto bits. */
            cm_object_property_set_str(state->f4.fld.cr.hsirdy, "hsion",
                    "follows");
            if (state->hse_freq_hz) {
                cm_object_property_set_str(state->f4.fld.cr.hserdy, "hseon",
                        "follows");
            }
            cm_object_property_set_str(state->f4.fld.cr.pllrdy, "pllon",
                    "follows");
            cm_object_property_set_str(state->f4.fld.cr.plli2srdy, "plli2son",
                    "follows");

            cm_object_property_set_str(state->f4.fld.cfgr.sws, "sw", "follows");

            cm_object_property_set_str(state->f4.fld.cir.lsirdyf, "lsirdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.lserdyf, "lserdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.hsirdyf, "hsirdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.hserdyf, "hserdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.pllrdyf, "pllrdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.plli2srdyf,
                    "plli2srdyc", "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.cssf, "cssc",
                    "cleared-by");

            cm_object_property_set_str(state->f4.fld.bdcr.lserdy, "lseon",
                    "follows");

            cm_object_property_set_str(state->f4.fld.csr.lsirdy, "lsion",
                    "follows");
            cm_object_property_set_str(state->f4.fld.csr.pinrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.porrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.stfrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.iwdgrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.wwdgrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.lpwrrstf, "rmvf",
                    "cleared-by");

        } else if (capabilities->f4.is_23_xxx) {

            stm32f4_23_xxx_rcc_create_objects(obj);

            /* Add callbacks. */
            peripheral_register_set_post_write(state->f4.reg.pllcfgr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f4.reg.cfgr,
                    &stm32_rcc_post_write_callback);

            /* Auto bits. */
            cm_object_property_set_str(state->f4.fld.cr.hsirdy, "hsion",
                    "follows");
            if (state->hse_freq_hz) {
                cm_object_property_set_str(state->f4.fld.cr.hserdy, "hseon",
                        "follows");
            }
            cm_object_property_set_str(state->f4.fld.cr.pllrdy, "pllon",
                    "follows");
            cm_object_property_set_str(state->f4.fld.cr.plli2srdy, "plli2son",
                    "follows");

            cm_object_property_set_str(state->f4.fld.cfgr.sws, "sw", "follows");

            cm_object_property_set_str(state->f4.fld.cir.lsirdyf, "lsirdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.lserdyf, "lserdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.hsirdyf, "hsirdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.hserdyf, "hserdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.pllrdyf, "pllrdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.plli2srdyf,
                    "plli2srdyc", "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.cssf, "cssc",
                    "cleared-by");

            cm_object_property_set_str(state->f4.fld.bdcr.lserdy, "lseon",
                    "follows");

            cm_object_property_set_str(state->f4.fld.csr.lsirdy, "lsion",
                    "follows");

            cm_object_property_set_str(state->f4.fld.csr.borrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.pinrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.pinrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.porrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.stfrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.iwdgrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.wwdgrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.lpwrrstf, "rmvf",
                    "cleared-by");
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

    /* Call parent reset(). */
    cm_device_parent_reset(dev, TYPE_STM32_RCC);

    STM32RCCState *state = STM32_RCC_STATE(dev);

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
