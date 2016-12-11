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

#include <hw/cortexm/stm32/rcc.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

#include "qemu/timer.h"

/*
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
 * TODO:
 * - implement peripheral reset
 */

// ----- Generated code -------------------------------------------------------
//
// STM32F051R8
// DO NOT EDIT! Automatically generated!
static void stm32f0x1_rcc_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32RCCState *state = STM32_RCC_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->f0.reg.cfgr = cm_object_get_child_by_name(obj, "CFGR");
    state->f0.reg.cir = cm_object_get_child_by_name(obj, "CIR");
    state->f0.reg.apb2rstr = cm_object_get_child_by_name(obj, "APB2RSTR");
    state->f0.reg.apb1rstr = cm_object_get_child_by_name(obj, "APB1RSTR");
    state->f0.reg.ahbenr = cm_object_get_child_by_name(obj, "AHBENR");
    state->f0.reg.apb2enr = cm_object_get_child_by_name(obj, "APB2ENR");
    state->f0.reg.apb1enr = cm_object_get_child_by_name(obj, "APB1ENR");
    state->f0.reg.bdcr = cm_object_get_child_by_name(obj, "BDCR");
    state->f0.reg.csr = cm_object_get_child_by_name(obj, "CSR");
    state->f0.reg.ahbrstr = cm_object_get_child_by_name(obj, "AHBRSTR");
    state->f0.reg.cfgr2 = cm_object_get_child_by_name(obj, "CFGR2");
    state->f0.reg.cfgr3 = cm_object_get_child_by_name(obj, "CFGR3");
    state->f0.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");

    // CR bitfields.
    state->f0.fld.cr.hsion = cm_object_get_child_by_name(state->f0.reg.cr,
            "HSION");
    state->f0.fld.cr.hsirdy = cm_object_get_child_by_name(state->f0.reg.cr,
            "HSIRDY");
    state->f0.fld.cr.hsitrim = cm_object_get_child_by_name(state->f0.reg.cr,
            "HSITRIM");
    state->f0.fld.cr.hsical = cm_object_get_child_by_name(state->f0.reg.cr,
            "HSICAL");
    state->f0.fld.cr.hseon = cm_object_get_child_by_name(state->f0.reg.cr,
            "HSEON");
    state->f0.fld.cr.hserdy = cm_object_get_child_by_name(state->f0.reg.cr,
            "HSERDY");
    state->f0.fld.cr.hsebyp = cm_object_get_child_by_name(state->f0.reg.cr,
            "HSEBYP");
    state->f0.fld.cr.csson = cm_object_get_child_by_name(state->f0.reg.cr,
            "CSSON");
    state->f0.fld.cr.pllon = cm_object_get_child_by_name(state->f0.reg.cr,
            "PLLON");
    state->f0.fld.cr.pllrdy = cm_object_get_child_by_name(state->f0.reg.cr,
            "PLLRDY");

    // CFGR bitfields.
    state->f0.fld.cfgr.sw = cm_object_get_child_by_name(state->f0.reg.cfgr,
            "SW");
    state->f0.fld.cfgr.sws = cm_object_get_child_by_name(state->f0.reg.cfgr,
            "SWS");
    state->f0.fld.cfgr.hpre = cm_object_get_child_by_name(state->f0.reg.cfgr,
            "HPRE");
    state->f0.fld.cfgr.ppre = cm_object_get_child_by_name(state->f0.reg.cfgr,
            "PPRE");
    state->f0.fld.cfgr.adcpre = cm_object_get_child_by_name(state->f0.reg.cfgr,
            "ADCPRE");
    state->f0.fld.cfgr.pllsrc = cm_object_get_child_by_name(state->f0.reg.cfgr,
            "PLLSRC");
    state->f0.fld.cfgr.pllxtpre = cm_object_get_child_by_name(
            state->f0.reg.cfgr, "PLLXTPRE");
    state->f0.fld.cfgr.pllmul = cm_object_get_child_by_name(state->f0.reg.cfgr,
            "PLLMUL");
    state->f0.fld.cfgr.mco = cm_object_get_child_by_name(state->f0.reg.cfgr,
            "MCO");
    state->f0.fld.cfgr.mcopre = cm_object_get_child_by_name(state->f0.reg.cfgr,
            "MCOPRE");
    state->f0.fld.cfgr.pllnodiv = cm_object_get_child_by_name(
            state->f0.reg.cfgr, "PLLNODIV");

    // CIR bitfields.
    state->f0.fld.cir.lsirdyf = cm_object_get_child_by_name(state->f0.reg.cir,
            "LSIRDYF");
    state->f0.fld.cir.lserdyf = cm_object_get_child_by_name(state->f0.reg.cir,
            "LSERDYF");
    state->f0.fld.cir.hsirdyf = cm_object_get_child_by_name(state->f0.reg.cir,
            "HSIRDYF");
    state->f0.fld.cir.hserdyf = cm_object_get_child_by_name(state->f0.reg.cir,
            "HSERDYF");
    state->f0.fld.cir.pllrdyf = cm_object_get_child_by_name(state->f0.reg.cir,
            "PLLRDYF");
    state->f0.fld.cir.hsi14rdyf = cm_object_get_child_by_name(state->f0.reg.cir,
            "HSI14RDYF");
    state->f0.fld.cir.hsi48rdyf = cm_object_get_child_by_name(state->f0.reg.cir,
            "HSI48RDYF");
    state->f0.fld.cir.cssf = cm_object_get_child_by_name(state->f0.reg.cir,
            "CSSF");
    state->f0.fld.cir.lsirdyie = cm_object_get_child_by_name(state->f0.reg.cir,
            "LSIRDYIE");
    state->f0.fld.cir.lserdyie = cm_object_get_child_by_name(state->f0.reg.cir,
            "LSERDYIE");
    state->f0.fld.cir.hsirdyie = cm_object_get_child_by_name(state->f0.reg.cir,
            "HSIRDYIE");
    state->f0.fld.cir.hserdyie = cm_object_get_child_by_name(state->f0.reg.cir,
            "HSERDYIE");
    state->f0.fld.cir.pllrdyie = cm_object_get_child_by_name(state->f0.reg.cir,
            "PLLRDYIE");
    state->f0.fld.cir.hsi14rdye = cm_object_get_child_by_name(state->f0.reg.cir,
            "HSI14RDYE");
    state->f0.fld.cir.hsi48rdyie = cm_object_get_child_by_name(
            state->f0.reg.cir, "HSI48RDYIE");
    state->f0.fld.cir.lsirdyc = cm_object_get_child_by_name(state->f0.reg.cir,
            "LSIRDYC");
    state->f0.fld.cir.lserdyc = cm_object_get_child_by_name(state->f0.reg.cir,
            "LSERDYC");
    state->f0.fld.cir.hsirdyc = cm_object_get_child_by_name(state->f0.reg.cir,
            "HSIRDYC");
    state->f0.fld.cir.hserdyc = cm_object_get_child_by_name(state->f0.reg.cir,
            "HSERDYC");
    state->f0.fld.cir.pllrdyc = cm_object_get_child_by_name(state->f0.reg.cir,
            "PLLRDYC");
    state->f0.fld.cir.hsi14rdyc = cm_object_get_child_by_name(state->f0.reg.cir,
            "HSI14RDYC");
    state->f0.fld.cir.hsi48rdyc = cm_object_get_child_by_name(state->f0.reg.cir,
            "HSI48RDYC");
    state->f0.fld.cir.cssc = cm_object_get_child_by_name(state->f0.reg.cir,
            "CSSC");

    // APB2RSTR bitfields.
    state->f0.fld.apb2rstr.syscfgrst = cm_object_get_child_by_name(
            state->f0.reg.apb2rstr, "SYSCFGRST");
    state->f0.fld.apb2rstr.adcrst = cm_object_get_child_by_name(
            state->f0.reg.apb2rstr, "ADCRST");
    state->f0.fld.apb2rstr.tim1rst = cm_object_get_child_by_name(
            state->f0.reg.apb2rstr, "TIM1RST");
    state->f0.fld.apb2rstr.spi1rst = cm_object_get_child_by_name(
            state->f0.reg.apb2rstr, "SPI1RST");
    state->f0.fld.apb2rstr.usart1rst = cm_object_get_child_by_name(
            state->f0.reg.apb2rstr, "USART1RST");
    state->f0.fld.apb2rstr.tim15rst = cm_object_get_child_by_name(
            state->f0.reg.apb2rstr, "TIM15RST");
    state->f0.fld.apb2rstr.tim16rst = cm_object_get_child_by_name(
            state->f0.reg.apb2rstr, "TIM16RST");
    state->f0.fld.apb2rstr.tim17rst = cm_object_get_child_by_name(
            state->f0.reg.apb2rstr, "TIM17RST");
    state->f0.fld.apb2rstr.dbgmcurst = cm_object_get_child_by_name(
            state->f0.reg.apb2rstr, "DBGMCURST");

    // APB1RSTR bitfields.
    state->f0.fld.apb1rstr.tim2rst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "TIM2RST");
    state->f0.fld.apb1rstr.tim3rst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "TIM3RST");
    state->f0.fld.apb1rstr.tim6rst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "TIM6RST");
    state->f0.fld.apb1rstr.tim7rst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "TIM7RST");
    state->f0.fld.apb1rstr.tim14rst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "TIM14RST");
    state->f0.fld.apb1rstr.wwdgrst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "WWDGRST");
    state->f0.fld.apb1rstr.spi2rst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "SPI2RST");
    state->f0.fld.apb1rstr.usart2rst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "USART2RST");
    state->f0.fld.apb1rstr.usart3rst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "USART3RST");
    state->f0.fld.apb1rstr.usart4rst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "USART4RST");
    state->f0.fld.apb1rstr.usart5rst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "USART5RST");
    state->f0.fld.apb1rstr.i2c1rst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "I2C1RST");
    state->f0.fld.apb1rstr.i2c2rst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "I2C2RST");
    state->f0.fld.apb1rstr.usbrst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "USBRST");
    state->f0.fld.apb1rstr.canrst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "CANRST");
    state->f0.fld.apb1rstr.crsrst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "CRSRST");
    state->f0.fld.apb1rstr.pwrrst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "PWRRST");
    state->f0.fld.apb1rstr.dacrst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "DACRST");
    state->f0.fld.apb1rstr.cecrst = cm_object_get_child_by_name(
            state->f0.reg.apb1rstr, "CECRST");

    // AHBENR bitfields.
    state->f0.fld.ahbenr.dma1en = cm_object_get_child_by_name(
            state->f0.reg.ahbenr, "DMA1EN");
    state->f0.fld.ahbenr.dma2en = cm_object_get_child_by_name(
            state->f0.reg.ahbenr, "DMA2EN");
    state->f0.fld.ahbenr.sramen = cm_object_get_child_by_name(
            state->f0.reg.ahbenr, "SRAMEN");
    state->f0.fld.ahbenr.flitfen = cm_object_get_child_by_name(
            state->f0.reg.ahbenr, "FLITFEN");
    state->f0.fld.ahbenr.crcen = cm_object_get_child_by_name(
            state->f0.reg.ahbenr, "CRCEN");
    state->f0.fld.ahbenr.iopaen = cm_object_get_child_by_name(
            state->f0.reg.ahbenr, "IOPAEN");
    state->f0.fld.ahbenr.iopben = cm_object_get_child_by_name(
            state->f0.reg.ahbenr, "IOPBEN");
    state->f0.fld.ahbenr.iopcen = cm_object_get_child_by_name(
            state->f0.reg.ahbenr, "IOPCEN");
    state->f0.fld.ahbenr.iopden = cm_object_get_child_by_name(
            state->f0.reg.ahbenr, "IOPDEN");
    state->f0.fld.ahbenr.iopfen = cm_object_get_child_by_name(
            state->f0.reg.ahbenr, "IOPFEN");
    state->f0.fld.ahbenr.tscen = cm_object_get_child_by_name(
            state->f0.reg.ahbenr, "TSCEN");

    // APB2ENR bitfields.
    state->f0.fld.apb2enr.syscfgen = cm_object_get_child_by_name(
            state->f0.reg.apb2enr, "SYSCFGEN");
    state->f0.fld.apb2enr.adcen = cm_object_get_child_by_name(
            state->f0.reg.apb2enr, "ADCEN");
    state->f0.fld.apb2enr.tim1en = cm_object_get_child_by_name(
            state->f0.reg.apb2enr, "TIM1EN");
    state->f0.fld.apb2enr.spi1en = cm_object_get_child_by_name(
            state->f0.reg.apb2enr, "SPI1EN");
    state->f0.fld.apb2enr.usart1en = cm_object_get_child_by_name(
            state->f0.reg.apb2enr, "USART1EN");
    state->f0.fld.apb2enr.tim15en = cm_object_get_child_by_name(
            state->f0.reg.apb2enr, "TIM15EN");
    state->f0.fld.apb2enr.tim16en = cm_object_get_child_by_name(
            state->f0.reg.apb2enr, "TIM16EN");
    state->f0.fld.apb2enr.tim17en = cm_object_get_child_by_name(
            state->f0.reg.apb2enr, "TIM17EN");
    state->f0.fld.apb2enr.dbgmcuen = cm_object_get_child_by_name(
            state->f0.reg.apb2enr, "DBGMCUEN");

    // APB1ENR bitfields.
    state->f0.fld.apb1enr.tim2en = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "TIM2EN");
    state->f0.fld.apb1enr.tim3en = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "TIM3EN");
    state->f0.fld.apb1enr.tim6en = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "TIM6EN");
    state->f0.fld.apb1enr.tim7en = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "TIM7EN");
    state->f0.fld.apb1enr.tim14en = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "TIM14EN");
    state->f0.fld.apb1enr.wwdgen = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "WWDGEN");
    state->f0.fld.apb1enr.spi2en = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "SPI2EN");
    state->f0.fld.apb1enr.usart2en = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "USART2EN");
    state->f0.fld.apb1enr.usart3en = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "USART3EN");
    state->f0.fld.apb1enr.usart4en = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "USART4EN");
    state->f0.fld.apb1enr.usart5en = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "USART5EN");
    state->f0.fld.apb1enr.i2c1en = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "I2C1EN");
    state->f0.fld.apb1enr.i2c2en = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "I2C2EN");
    state->f0.fld.apb1enr.usbrst = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "USBRST");
    state->f0.fld.apb1enr.canen = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "CANEN");
    state->f0.fld.apb1enr.crsen = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "CRSEN");
    state->f0.fld.apb1enr.pwren = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "PWREN");
    state->f0.fld.apb1enr.dacen = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "DACEN");
    state->f0.fld.apb1enr.cecen = cm_object_get_child_by_name(
            state->f0.reg.apb1enr, "CECEN");

    // BDCR bitfields.
    state->f0.fld.bdcr.lseon = cm_object_get_child_by_name(state->f0.reg.bdcr,
            "LSEON");
    state->f0.fld.bdcr.lserdy = cm_object_get_child_by_name(state->f0.reg.bdcr,
            "LSERDY");
    state->f0.fld.bdcr.lsebyp = cm_object_get_child_by_name(state->f0.reg.bdcr,
            "LSEBYP");
    state->f0.fld.bdcr.lsedrv = cm_object_get_child_by_name(state->f0.reg.bdcr,
            "LSEDRV");
    state->f0.fld.bdcr.rtcsel = cm_object_get_child_by_name(state->f0.reg.bdcr,
            "RTCSEL");
    state->f0.fld.bdcr.rtcen = cm_object_get_child_by_name(state->f0.reg.bdcr,
            "RTCEN");
    state->f0.fld.bdcr.bdrst = cm_object_get_child_by_name(state->f0.reg.bdcr,
            "BDRST");

    // CSR bitfields.
    state->f0.fld.csr.lsion = cm_object_get_child_by_name(state->f0.reg.csr,
            "LSION");
    state->f0.fld.csr.lsirdy = cm_object_get_child_by_name(state->f0.reg.csr,
            "LSIRDY");
    state->f0.fld.csr.rmvf = cm_object_get_child_by_name(state->f0.reg.csr,
            "RMVF");
    state->f0.fld.csr.oblrstf = cm_object_get_child_by_name(state->f0.reg.csr,
            "OBLRSTF");
    state->f0.fld.csr.pinrstf = cm_object_get_child_by_name(state->f0.reg.csr,
            "PINRSTF");
    state->f0.fld.csr.porrstf = cm_object_get_child_by_name(state->f0.reg.csr,
            "PORRSTF");
    state->f0.fld.csr.sftrstf = cm_object_get_child_by_name(state->f0.reg.csr,
            "SFTRSTF");
    state->f0.fld.csr.iwdgrstf = cm_object_get_child_by_name(state->f0.reg.csr,
            "IWDGRSTF");
    state->f0.fld.csr.wwdgrstf = cm_object_get_child_by_name(state->f0.reg.csr,
            "WWDGRSTF");
    state->f0.fld.csr.lpwrrstf = cm_object_get_child_by_name(state->f0.reg.csr,
            "LPWRRSTF");

    // AHBRSTR bitfields.
    state->f0.fld.ahbrstr.ioparst = cm_object_get_child_by_name(
            state->f0.reg.ahbrstr, "IOPARST");
    state->f0.fld.ahbrstr.iopbrst = cm_object_get_child_by_name(
            state->f0.reg.ahbrstr, "IOPBRST");
    state->f0.fld.ahbrstr.iopcrst = cm_object_get_child_by_name(
            state->f0.reg.ahbrstr, "IOPCRST");
    state->f0.fld.ahbrstr.iopdrst = cm_object_get_child_by_name(
            state->f0.reg.ahbrstr, "IOPDRST");
    state->f0.fld.ahbrstr.iopfrst = cm_object_get_child_by_name(
            state->f0.reg.ahbrstr, "IOPFRST");
    state->f0.fld.ahbrstr.tscrst = cm_object_get_child_by_name(
            state->f0.reg.ahbrstr, "TSCRST");

    // CFGR2 bitfields.
    state->f0.fld.cfgr2.prediv = cm_object_get_child_by_name(
            state->f0.reg.cfgr2, "PREDIV");

    // CFGR3 bitfields.
    state->f0.fld.cfgr3.usart1sw = cm_object_get_child_by_name(
            state->f0.reg.cfgr3, "USART1SW");
    state->f0.fld.cfgr3.i2c1sw = cm_object_get_child_by_name(
            state->f0.reg.cfgr3, "I2C1SW");
    state->f0.fld.cfgr3.cecsw = cm_object_get_child_by_name(state->f0.reg.cfgr3,
            "CECSW");
    state->f0.fld.cfgr3.usbsw = cm_object_get_child_by_name(state->f0.reg.cfgr3,
            "USBSW");
    state->f0.fld.cfgr3.adcsw = cm_object_get_child_by_name(state->f0.reg.cfgr3,
            "ADCSW");
    state->f0.fld.cfgr3.usart2sw = cm_object_get_child_by_name(
            state->f0.reg.cfgr3, "USART2SW");

    // CR2 bitfields.
    state->f0.fld.cr2.hsi14on = cm_object_get_child_by_name(state->f0.reg.cr2,
            "HSI14ON");
    state->f0.fld.cr2.hsi14rdy = cm_object_get_child_by_name(state->f0.reg.cr2,
            "HSI14RDY");
    state->f0.fld.cr2.hsi14dis = cm_object_get_child_by_name(state->f0.reg.cr2,
            "HSI14DIS");
    state->f0.fld.cr2.hsi14trim = cm_object_get_child_by_name(state->f0.reg.cr2,
            "HSI14TRIM");
    state->f0.fld.cr2.hsi14cal = cm_object_get_child_by_name(state->f0.reg.cr2,
            "HSI14CAL");
    state->f0.fld.cr2.hsi48on = cm_object_get_child_by_name(state->f0.reg.cr2,
            "HSI48ON");
    state->f0.fld.cr2.hsi48rdy = cm_object_get_child_by_name(state->f0.reg.cr2,
            "HSI48RDY");
    state->f0.fld.cr2.hsi48cal = cm_object_get_child_by_name(state->f0.reg.cr2,
            "HSI48CAL");
}

// ----------------------------------------------------------------------------

// STM32F103RB
// DO NOT EDIT! Automatically generated!
static void stm32f103xx_rcc_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32RCCState *state = STM32_RCC_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->f1.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->f1.reg.cfgr = cm_object_get_child_by_name(obj, "CFGR");
    state->f1.reg.cir = cm_object_get_child_by_name(obj, "CIR");
    state->f1.reg.apb2rstr = cm_object_get_child_by_name(obj, "APB2RSTR");
    state->f1.reg.apb1rstr = cm_object_get_child_by_name(obj, "APB1RSTR");
    state->f1.reg.ahbenr = cm_object_get_child_by_name(obj, "AHBENR");
    state->f1.reg.apb2enr = cm_object_get_child_by_name(obj, "APB2ENR");
    state->f1.reg.apb1enr = cm_object_get_child_by_name(obj, "APB1ENR");
    state->f1.reg.bdcr = cm_object_get_child_by_name(obj, "BDCR");
    state->f1.reg.csr = cm_object_get_child_by_name(obj, "CSR");

    // CR bitfields.
    state->f1.fld.cr.hsion = cm_object_get_child_by_name(state->f1.reg.cr,
            "HSION");
    state->f1.fld.cr.hsirdy = cm_object_get_child_by_name(state->f1.reg.cr,
            "HSIRDY");
    state->f1.fld.cr.hsitrim = cm_object_get_child_by_name(state->f1.reg.cr,
            "HSITRIM");
    state->f1.fld.cr.hsical = cm_object_get_child_by_name(state->f1.reg.cr,
            "HSICAL");
    state->f1.fld.cr.hseon = cm_object_get_child_by_name(state->f1.reg.cr,
            "HSEON");
    state->f1.fld.cr.hserdy = cm_object_get_child_by_name(state->f1.reg.cr,
            "HSERDY");
    state->f1.fld.cr.hsebyp = cm_object_get_child_by_name(state->f1.reg.cr,
            "HSEBYP");
    state->f1.fld.cr.csson = cm_object_get_child_by_name(state->f1.reg.cr,
            "CSSON");
    state->f1.fld.cr.pllon = cm_object_get_child_by_name(state->f1.reg.cr,
            "PLLON");
    state->f1.fld.cr.pllrdy = cm_object_get_child_by_name(state->f1.reg.cr,
            "PLLRDY");

    // CFGR bitfields.
    state->f1.fld.cfgr.sw = cm_object_get_child_by_name(state->f1.reg.cfgr,
            "SW");
    state->f1.fld.cfgr.sws = cm_object_get_child_by_name(state->f1.reg.cfgr,
            "SWS");
    state->f1.fld.cfgr.hpre = cm_object_get_child_by_name(state->f1.reg.cfgr,
            "HPRE");
    state->f1.fld.cfgr.ppre1 = cm_object_get_child_by_name(state->f1.reg.cfgr,
            "PPRE1");
    state->f1.fld.cfgr.ppre2 = cm_object_get_child_by_name(state->f1.reg.cfgr,
            "PPRE2");
    state->f1.fld.cfgr.adcpre = cm_object_get_child_by_name(state->f1.reg.cfgr,
            "ADCPRE");
    state->f1.fld.cfgr.pllsrc = cm_object_get_child_by_name(state->f1.reg.cfgr,
            "PLLSRC");
    state->f1.fld.cfgr.pllxtpre = cm_object_get_child_by_name(
            state->f1.reg.cfgr, "PLLXTPRE");
    state->f1.fld.cfgr.pllmul = cm_object_get_child_by_name(state->f1.reg.cfgr,
            "PLLMUL");
    state->f1.fld.cfgr.otgfspre = cm_object_get_child_by_name(
            state->f1.reg.cfgr, "OTGFSPRE");
    state->f1.fld.cfgr.mco = cm_object_get_child_by_name(state->f1.reg.cfgr,
            "MCO");

    // CIR bitfields.
    state->f1.fld.cir.lsirdyf = cm_object_get_child_by_name(state->f1.reg.cir,
            "LSIRDYF");
    state->f1.fld.cir.lserdyf = cm_object_get_child_by_name(state->f1.reg.cir,
            "LSERDYF");
    state->f1.fld.cir.hsirdyf = cm_object_get_child_by_name(state->f1.reg.cir,
            "HSIRDYF");
    state->f1.fld.cir.hserdyf = cm_object_get_child_by_name(state->f1.reg.cir,
            "HSERDYF");
    state->f1.fld.cir.pllrdyf = cm_object_get_child_by_name(state->f1.reg.cir,
            "PLLRDYF");
    state->f1.fld.cir.cssf = cm_object_get_child_by_name(state->f1.reg.cir,
            "CSSF");
    state->f1.fld.cir.lsirdyie = cm_object_get_child_by_name(state->f1.reg.cir,
            "LSIRDYIE");
    state->f1.fld.cir.lserdyie = cm_object_get_child_by_name(state->f1.reg.cir,
            "LSERDYIE");
    state->f1.fld.cir.hsirdyie = cm_object_get_child_by_name(state->f1.reg.cir,
            "HSIRDYIE");
    state->f1.fld.cir.hserdyie = cm_object_get_child_by_name(state->f1.reg.cir,
            "HSERDYIE");
    state->f1.fld.cir.pllrdyie = cm_object_get_child_by_name(state->f1.reg.cir,
            "PLLRDYIE");
    state->f1.fld.cir.lsirdyc = cm_object_get_child_by_name(state->f1.reg.cir,
            "LSIRDYC");
    state->f1.fld.cir.lserdyc = cm_object_get_child_by_name(state->f1.reg.cir,
            "LSERDYC");
    state->f1.fld.cir.hsirdyc = cm_object_get_child_by_name(state->f1.reg.cir,
            "HSIRDYC");
    state->f1.fld.cir.hserdyc = cm_object_get_child_by_name(state->f1.reg.cir,
            "HSERDYC");
    state->f1.fld.cir.pllrdyc = cm_object_get_child_by_name(state->f1.reg.cir,
            "PLLRDYC");
    state->f1.fld.cir.cssc = cm_object_get_child_by_name(state->f1.reg.cir,
            "CSSC");

    // APB2RSTR bitfields.
    state->f1.fld.apb2rstr.afiorst = cm_object_get_child_by_name(
            state->f1.reg.apb2rstr, "AFIORST");
    state->f1.fld.apb2rstr.ioparst = cm_object_get_child_by_name(
            state->f1.reg.apb2rstr, "IOPARST");
    state->f1.fld.apb2rstr.iopbrst = cm_object_get_child_by_name(
            state->f1.reg.apb2rstr, "IOPBRST");
    state->f1.fld.apb2rstr.iopcrst = cm_object_get_child_by_name(
            state->f1.reg.apb2rstr, "IOPCRST");
    state->f1.fld.apb2rstr.iopdrst = cm_object_get_child_by_name(
            state->f1.reg.apb2rstr, "IOPDRST");
    state->f1.fld.apb2rstr.ioperst = cm_object_get_child_by_name(
            state->f1.reg.apb2rstr, "IOPERST");
    state->f1.fld.apb2rstr.iopfrst = cm_object_get_child_by_name(
            state->f1.reg.apb2rstr, "IOPFRST");
    state->f1.fld.apb2rstr.iopgrst = cm_object_get_child_by_name(
            state->f1.reg.apb2rstr, "IOPGRST");
    state->f1.fld.apb2rstr.adc1rst = cm_object_get_child_by_name(
            state->f1.reg.apb2rstr, "ADC1RST");
    state->f1.fld.apb2rstr.adc2rst = cm_object_get_child_by_name(
            state->f1.reg.apb2rstr, "ADC2RST");
    state->f1.fld.apb2rstr.tim1rst = cm_object_get_child_by_name(
            state->f1.reg.apb2rstr, "TIM1RST");
    state->f1.fld.apb2rstr.spi1rst = cm_object_get_child_by_name(
            state->f1.reg.apb2rstr, "SPI1RST");
    state->f1.fld.apb2rstr.tim8rst = cm_object_get_child_by_name(
            state->f1.reg.apb2rstr, "TIM8RST");
    state->f1.fld.apb2rstr.usart1rst = cm_object_get_child_by_name(
            state->f1.reg.apb2rstr, "USART1RST");
    state->f1.fld.apb2rstr.adc3rst = cm_object_get_child_by_name(
            state->f1.reg.apb2rstr, "ADC3RST");
    state->f1.fld.apb2rstr.tim9rst = cm_object_get_child_by_name(
            state->f1.reg.apb2rstr, "TIM9RST");
    state->f1.fld.apb2rstr.tim10rst = cm_object_get_child_by_name(
            state->f1.reg.apb2rstr, "TIM10RST");
    state->f1.fld.apb2rstr.tim11rst = cm_object_get_child_by_name(
            state->f1.reg.apb2rstr, "TIM11RST");

    // APB1RSTR bitfields.
    state->f1.fld.apb1rstr.tim2rst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "TIM2RST");
    state->f1.fld.apb1rstr.tim3rst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "TIM3RST");
    state->f1.fld.apb1rstr.tim4rst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "TIM4RST");
    state->f1.fld.apb1rstr.tim5rst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "TIM5RST");
    state->f1.fld.apb1rstr.tim6rst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "TIM6RST");
    state->f1.fld.apb1rstr.tim7rst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "TIM7RST");
    state->f1.fld.apb1rstr.tim12rst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "TIM12RST");
    state->f1.fld.apb1rstr.tim13rst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "TIM13RST");
    state->f1.fld.apb1rstr.tim14rst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "TIM14RST");
    state->f1.fld.apb1rstr.wwdgrst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "WWDGRST");
    state->f1.fld.apb1rstr.spi2rst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "SPI2RST");
    state->f1.fld.apb1rstr.spi3rst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "SPI3RST");
    state->f1.fld.apb1rstr.usart2rst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "USART2RST");
    state->f1.fld.apb1rstr.usart3rst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "USART3RST");
    state->f1.fld.apb1rstr.uart4rst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "UART4RST");
    state->f1.fld.apb1rstr.uart5rst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "UART5RST");
    state->f1.fld.apb1rstr.i2c1rst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "I2C1RST");
    state->f1.fld.apb1rstr.i2c2rst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "I2C2RST");
    state->f1.fld.apb1rstr.usbrst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "USBRST");
    state->f1.fld.apb1rstr.canrst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "CANRST");
    state->f1.fld.apb1rstr.bkprst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "BKPRST");
    state->f1.fld.apb1rstr.pwrrst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "PWRRST");
    state->f1.fld.apb1rstr.dacrst = cm_object_get_child_by_name(
            state->f1.reg.apb1rstr, "DACRST");

    // AHBENR bitfields.
    state->f1.fld.ahbenr.dma1en = cm_object_get_child_by_name(
            state->f1.reg.ahbenr, "DMA1EN");
    state->f1.fld.ahbenr.dma2en = cm_object_get_child_by_name(
            state->f1.reg.ahbenr, "DMA2EN");
    state->f1.fld.ahbenr.sramen = cm_object_get_child_by_name(
            state->f1.reg.ahbenr, "SRAMEN");
    state->f1.fld.ahbenr.flitfen = cm_object_get_child_by_name(
            state->f1.reg.ahbenr, "FLITFEN");
    state->f1.fld.ahbenr.crcen = cm_object_get_child_by_name(
            state->f1.reg.ahbenr, "CRCEN");
    state->f1.fld.ahbenr.fsmcen = cm_object_get_child_by_name(
            state->f1.reg.ahbenr, "FSMCEN");
    state->f1.fld.ahbenr.sdioen = cm_object_get_child_by_name(
            state->f1.reg.ahbenr, "SDIOEN");

    // APB2ENR bitfields.
    state->f1.fld.apb2enr.afioen = cm_object_get_child_by_name(
            state->f1.reg.apb2enr, "AFIOEN");
    state->f1.fld.apb2enr.iopaen = cm_object_get_child_by_name(
            state->f1.reg.apb2enr, "IOPAEN");
    state->f1.fld.apb2enr.iopben = cm_object_get_child_by_name(
            state->f1.reg.apb2enr, "IOPBEN");
    state->f1.fld.apb2enr.iopcen = cm_object_get_child_by_name(
            state->f1.reg.apb2enr, "IOPCEN");
    state->f1.fld.apb2enr.iopden = cm_object_get_child_by_name(
            state->f1.reg.apb2enr, "IOPDEN");
    state->f1.fld.apb2enr.iopeen = cm_object_get_child_by_name(
            state->f1.reg.apb2enr, "IOPEEN");
    state->f1.fld.apb2enr.iopfen = cm_object_get_child_by_name(
            state->f1.reg.apb2enr, "IOPFEN");
    state->f1.fld.apb2enr.iopgen = cm_object_get_child_by_name(
            state->f1.reg.apb2enr, "IOPGEN");
    state->f1.fld.apb2enr.adc1en = cm_object_get_child_by_name(
            state->f1.reg.apb2enr, "ADC1EN");
    state->f1.fld.apb2enr.adc2en = cm_object_get_child_by_name(
            state->f1.reg.apb2enr, "ADC2EN");
    state->f1.fld.apb2enr.tim1en = cm_object_get_child_by_name(
            state->f1.reg.apb2enr, "TIM1EN");
    state->f1.fld.apb2enr.spi1en = cm_object_get_child_by_name(
            state->f1.reg.apb2enr, "SPI1EN");
    state->f1.fld.apb2enr.tim8en = cm_object_get_child_by_name(
            state->f1.reg.apb2enr, "TIM8EN");
    state->f1.fld.apb2enr.usart1en = cm_object_get_child_by_name(
            state->f1.reg.apb2enr, "USART1EN");
    state->f1.fld.apb2enr.adc3en = cm_object_get_child_by_name(
            state->f1.reg.apb2enr, "ADC3EN");
    state->f1.fld.apb2enr.tim9en = cm_object_get_child_by_name(
            state->f1.reg.apb2enr, "TIM9EN");
    state->f1.fld.apb2enr.tim10en = cm_object_get_child_by_name(
            state->f1.reg.apb2enr, "TIM10EN");
    state->f1.fld.apb2enr.tim11en = cm_object_get_child_by_name(
            state->f1.reg.apb2enr, "TIM11EN");

    // APB1ENR bitfields.
    state->f1.fld.apb1enr.tim2en = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "TIM2EN");
    state->f1.fld.apb1enr.tim3en = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "TIM3EN");
    state->f1.fld.apb1enr.tim4en = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "TIM4EN");
    state->f1.fld.apb1enr.tim5en = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "TIM5EN");
    state->f1.fld.apb1enr.tim6en = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "TIM6EN");
    state->f1.fld.apb1enr.tim7en = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "TIM7EN");
    state->f1.fld.apb1enr.tim12en = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "TIM12EN");
    state->f1.fld.apb1enr.tim13en = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "TIM13EN");
    state->f1.fld.apb1enr.tim14en = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "TIM14EN");
    state->f1.fld.apb1enr.wwdgen = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "WWDGEN");
    state->f1.fld.apb1enr.spi2en = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "SPI2EN");
    state->f1.fld.apb1enr.spi3en = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "SPI3EN");
    state->f1.fld.apb1enr.usart2en = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "USART2EN");
    state->f1.fld.apb1enr.usart3en = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "USART3EN");
    state->f1.fld.apb1enr.uart4en = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "UART4EN");
    state->f1.fld.apb1enr.uart5en = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "UART5EN");
    state->f1.fld.apb1enr.i2c1en = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "I2C1EN");
    state->f1.fld.apb1enr.i2c2en = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "I2C2EN");
    state->f1.fld.apb1enr.usben = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "USBEN");
    state->f1.fld.apb1enr.canen = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "CANEN");
    state->f1.fld.apb1enr.bkpen = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "BKPEN");
    state->f1.fld.apb1enr.pwren = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "PWREN");
    state->f1.fld.apb1enr.dacen = cm_object_get_child_by_name(
            state->f1.reg.apb1enr, "DACEN");

    // BDCR bitfields.
    state->f1.fld.bdcr.lseon = cm_object_get_child_by_name(state->f1.reg.bdcr,
            "LSEON");
    state->f1.fld.bdcr.lserdy = cm_object_get_child_by_name(state->f1.reg.bdcr,
            "LSERDY");
    state->f1.fld.bdcr.lsebyp = cm_object_get_child_by_name(state->f1.reg.bdcr,
            "LSEBYP");
    state->f1.fld.bdcr.rtcsel = cm_object_get_child_by_name(state->f1.reg.bdcr,
            "RTCSEL");
    state->f1.fld.bdcr.rtcen = cm_object_get_child_by_name(state->f1.reg.bdcr,
            "RTCEN");
    state->f1.fld.bdcr.bdrst = cm_object_get_child_by_name(state->f1.reg.bdcr,
            "BDRST");

    // CSR bitfields.
    state->f1.fld.csr.lsion = cm_object_get_child_by_name(state->f1.reg.csr,
            "LSION");
    state->f1.fld.csr.lsirdy = cm_object_get_child_by_name(state->f1.reg.csr,
            "LSIRDY");
    state->f1.fld.csr.rmvf = cm_object_get_child_by_name(state->f1.reg.csr,
            "RMVF");
    state->f1.fld.csr.pinrstf = cm_object_get_child_by_name(state->f1.reg.csr,
            "PINRSTF");
    state->f1.fld.csr.porrstf = cm_object_get_child_by_name(state->f1.reg.csr,
            "PORRSTF");
    state->f1.fld.csr.sftrstf = cm_object_get_child_by_name(state->f1.reg.csr,
            "SFTRSTF");
    state->f1.fld.csr.iwdgrstf = cm_object_get_child_by_name(state->f1.reg.csr,
            "IWDGRSTF");
    state->f1.fld.csr.wwdgrstf = cm_object_get_child_by_name(state->f1.reg.csr,
            "WWDGRSTF");
    state->f1.fld.csr.lpwrrstf = cm_object_get_child_by_name(state->f1.reg.csr,
            "LPWRRSTF");
}

// ----------------------------------------------------------------------------

// STM32F407VG

// DO NOT EDIT! Automatically generated!
static void stm32f40x_rcc_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32RCCState *state = STM32_RCC_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->f4.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->f4.reg.pllcfgr = cm_object_get_child_by_name(obj, "PLLCFGR");
    state->f4.reg.cfgr = cm_object_get_child_by_name(obj, "CFGR");
    state->f4.reg.cir = cm_object_get_child_by_name(obj, "CIR");
    state->f4.reg.ahb1rstr = cm_object_get_child_by_name(obj, "AHB1RSTR");
    state->f4.reg.ahb2rstr = cm_object_get_child_by_name(obj, "AHB2RSTR");
    state->f4.reg.ahb3rstr = cm_object_get_child_by_name(obj, "AHB3RSTR");
    state->f4.reg.apb1rstr = cm_object_get_child_by_name(obj, "APB1RSTR");
    state->f4.reg.apb2rstr = cm_object_get_child_by_name(obj, "APB2RSTR");
    state->f4.reg.ahb1enr = cm_object_get_child_by_name(obj, "AHB1ENR");
    state->f4.reg.ahb2enr = cm_object_get_child_by_name(obj, "AHB2ENR");
    state->f4.reg.ahb3enr = cm_object_get_child_by_name(obj, "AHB3ENR");
    state->f4.reg.apb1enr = cm_object_get_child_by_name(obj, "APB1ENR");
    state->f4.reg.apb2enr = cm_object_get_child_by_name(obj, "APB2ENR");
    state->f4.reg.ahb1lpenr = cm_object_get_child_by_name(obj, "AHB1LPENR");
    state->f4.reg.ahb2lpenr = cm_object_get_child_by_name(obj, "AHB2LPENR");
    state->f4.reg.ahb3lpenr = cm_object_get_child_by_name(obj, "AHB3LPENR");
    state->f4.reg.apb1lpenr = cm_object_get_child_by_name(obj, "APB1LPENR");
    state->f4.reg.apb2lpenr = cm_object_get_child_by_name(obj, "APB2LPENR");
    state->f4.reg.bdcr = cm_object_get_child_by_name(obj, "BDCR");
    state->f4.reg.csr = cm_object_get_child_by_name(obj, "CSR");
    state->f4.reg.sscgr = cm_object_get_child_by_name(obj, "SSCGR");
    state->f4.reg.plli2scfgr = cm_object_get_child_by_name(obj, "PLLI2SCFGR");

    // CR bitfields.
    state->f4.fld.cr.hsion = cm_object_get_child_by_name(state->f4.reg.cr,
            "HSION");
    state->f4.fld.cr.hsirdy = cm_object_get_child_by_name(state->f4.reg.cr,
            "HSIRDY");
    state->f4.fld.cr.hsitrim = cm_object_get_child_by_name(state->f4.reg.cr,
            "HSITRIM");
    state->f4.fld.cr.hsical = cm_object_get_child_by_name(state->f4.reg.cr,
            "HSICAL");
    state->f4.fld.cr.hseon = cm_object_get_child_by_name(state->f4.reg.cr,
            "HSEON");
    state->f4.fld.cr.hserdy = cm_object_get_child_by_name(state->f4.reg.cr,
            "HSERDY");
    state->f4.fld.cr.hsebyp = cm_object_get_child_by_name(state->f4.reg.cr,
            "HSEBYP");
    state->f4.fld.cr.csson = cm_object_get_child_by_name(state->f4.reg.cr,
            "CSSON");
    state->f4.fld.cr.pllon = cm_object_get_child_by_name(state->f4.reg.cr,
            "PLLON");
    state->f4.fld.cr.pllrdy = cm_object_get_child_by_name(state->f4.reg.cr,
            "PLLRDY");
    state->f4.fld.cr.plli2son = cm_object_get_child_by_name(state->f4.reg.cr,
            "PLLI2SON");
    state->f4.fld.cr.plli2srdy = cm_object_get_child_by_name(state->f4.reg.cr,
            "PLLI2SRDY");

    // PLLCFGR bitfields.
    state->f4.fld.pllcfgr.pllm = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "PLLM");
    state->f4.fld.pllcfgr.plln = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "PLLN");
    state->f4.fld.pllcfgr.pllp = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "PLLP");
    state->f4.fld.pllcfgr.pllsrc = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "PLLSRC");
    state->f4.fld.pllcfgr.pllq = cm_object_get_child_by_name(
            state->f4.reg.pllcfgr, "PLLQ");

    // CFGR bitfields.
    state->f4.fld.cfgr.sw = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "SW");
    state->f4.fld.cfgr.sws = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "SWS");
    state->f4.fld.cfgr.hpre = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "HPRE");
    state->f4.fld.cfgr.ppre1 = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "PPRE1");
    state->f4.fld.cfgr.ppre2 = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "PPRE2");
    state->f4.fld.cfgr.rtcpre = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "RTCPRE");
    state->f4.fld.cfgr.mco1 = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "MCO1");
    state->f4.fld.cfgr.i2ssrc = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "I2SSRC");
    state->f4.fld.cfgr.mco1pre = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "MCO1PRE");
    state->f4.fld.cfgr.mco2pre = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "MCO2PRE");
    state->f4.fld.cfgr.mco2 = cm_object_get_child_by_name(state->f4.reg.cfgr,
            "MCO2");

    // CIR bitfields.
    state->f4.fld.cir.lsirdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "LSIRDYF");
    state->f4.fld.cir.lserdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "LSERDYF");
    state->f4.fld.cir.hsirdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "HSIRDYF");
    state->f4.fld.cir.hserdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "HSERDYF");
    state->f4.fld.cir.pllrdyf = cm_object_get_child_by_name(state->f4.reg.cir,
            "PLLRDYF");
    state->f4.fld.cir.plli2srdyf = cm_object_get_child_by_name(
            state->f4.reg.cir, "PLLI2SRDYF");
    state->f4.fld.cir.cssf = cm_object_get_child_by_name(state->f4.reg.cir,
            "CSSF");
    state->f4.fld.cir.lsirdyie = cm_object_get_child_by_name(state->f4.reg.cir,
            "LSIRDYIE");
    state->f4.fld.cir.lserdyie = cm_object_get_child_by_name(state->f4.reg.cir,
            "LSERDYIE");
    state->f4.fld.cir.hsirdyie = cm_object_get_child_by_name(state->f4.reg.cir,
            "HSIRDYIE");
    state->f4.fld.cir.hserdyie = cm_object_get_child_by_name(state->f4.reg.cir,
            "HSERDYIE");
    state->f4.fld.cir.pllrdyie = cm_object_get_child_by_name(state->f4.reg.cir,
            "PLLRDYIE");
    state->f4.fld.cir.plli2srdyie = cm_object_get_child_by_name(
            state->f4.reg.cir, "PLLI2SRDYIE");
    state->f4.fld.cir.lsirdyc = cm_object_get_child_by_name(state->f4.reg.cir,
            "LSIRDYC");
    state->f4.fld.cir.lserdyc = cm_object_get_child_by_name(state->f4.reg.cir,
            "LSERDYC");
    state->f4.fld.cir.hsirdyc = cm_object_get_child_by_name(state->f4.reg.cir,
            "HSIRDYC");
    state->f4.fld.cir.hserdyc = cm_object_get_child_by_name(state->f4.reg.cir,
            "HSERDYC");
    state->f4.fld.cir.pllrdyc = cm_object_get_child_by_name(state->f4.reg.cir,
            "PLLRDYC");
    state->f4.fld.cir.plli2srdyc = cm_object_get_child_by_name(
            state->f4.reg.cir, "PLLI2SRDYC");
    state->f4.fld.cir.cssc = cm_object_get_child_by_name(state->f4.reg.cir,
            "CSSC");

    // AHB1RSTR bitfields.
    state->f4.fld.ahb1rstr.gpioarst = cm_object_get_child_by_name(
            state->f4.reg.ahb1rstr, "GPIOARST");
    state->f4.fld.ahb1rstr.gpiobrst = cm_object_get_child_by_name(
            state->f4.reg.ahb1rstr, "GPIOBRST");
    state->f4.fld.ahb1rstr.gpiocrst = cm_object_get_child_by_name(
            state->f4.reg.ahb1rstr, "GPIOCRST");
    state->f4.fld.ahb1rstr.gpiodrst = cm_object_get_child_by_name(
            state->f4.reg.ahb1rstr, "GPIODRST");
    state->f4.fld.ahb1rstr.gpioerst = cm_object_get_child_by_name(
            state->f4.reg.ahb1rstr, "GPIOERST");
    state->f4.fld.ahb1rstr.gpiofrst = cm_object_get_child_by_name(
            state->f4.reg.ahb1rstr, "GPIOFRST");
    state->f4.fld.ahb1rstr.gpiogrst = cm_object_get_child_by_name(
            state->f4.reg.ahb1rstr, "GPIOGRST");
    state->f4.fld.ahb1rstr.gpiohrst = cm_object_get_child_by_name(
            state->f4.reg.ahb1rstr, "GPIOHRST");
    state->f4.fld.ahb1rstr.gpioirst = cm_object_get_child_by_name(
            state->f4.reg.ahb1rstr, "GPIOIRST");
    state->f4.fld.ahb1rstr.crcrst = cm_object_get_child_by_name(
            state->f4.reg.ahb1rstr, "CRCRST");
    state->f4.fld.ahb1rstr.dma1rst = cm_object_get_child_by_name(
            state->f4.reg.ahb1rstr, "DMA1RST");
    state->f4.fld.ahb1rstr.dma2rst = cm_object_get_child_by_name(
            state->f4.reg.ahb1rstr, "DMA2RST");
    state->f4.fld.ahb1rstr.ethmacrst = cm_object_get_child_by_name(
            state->f4.reg.ahb1rstr, "ETHMACRST");
    state->f4.fld.ahb1rstr.otghsrst = cm_object_get_child_by_name(
            state->f4.reg.ahb1rstr, "OTGHSRST");

    // AHB2RSTR bitfields.
    state->f4.fld.ahb2rstr.dcmirst = cm_object_get_child_by_name(
            state->f4.reg.ahb2rstr, "DCMIRST");
    state->f4.fld.ahb2rstr.rngrst = cm_object_get_child_by_name(
            state->f4.reg.ahb2rstr, "RNGRST");
    state->f4.fld.ahb2rstr.otgfsrst = cm_object_get_child_by_name(
            state->f4.reg.ahb2rstr, "OTGFSRST");

    // AHB3RSTR bitfields.
    state->f4.fld.ahb3rstr.fsmcrst = cm_object_get_child_by_name(
            state->f4.reg.ahb3rstr, "FSMCRST");

    // APB1RSTR bitfields.
    state->f4.fld.apb1rstr.tim2rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "TIM2RST");
    state->f4.fld.apb1rstr.tim3rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "TIM3RST");
    state->f4.fld.apb1rstr.tim4rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "TIM4RST");
    state->f4.fld.apb1rstr.tim5rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "TIM5RST");
    state->f4.fld.apb1rstr.tim6rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "TIM6RST");
    state->f4.fld.apb1rstr.tim7rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "TIM7RST");
    state->f4.fld.apb1rstr.tim12rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "TIM12RST");
    state->f4.fld.apb1rstr.tim13rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "TIM13RST");
    state->f4.fld.apb1rstr.tim14rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "TIM14RST");
    state->f4.fld.apb1rstr.wwdgrst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "WWDGRST");
    state->f4.fld.apb1rstr.spi2rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "SPI2RST");
    state->f4.fld.apb1rstr.spi3rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "SPI3RST");
    state->f4.fld.apb1rstr.uart2rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "UART2RST");
    state->f4.fld.apb1rstr.uart3rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "UART3RST");
    state->f4.fld.apb1rstr.uart4rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "UART4RST");
    state->f4.fld.apb1rstr.uart5rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "UART5RST");
    state->f4.fld.apb1rstr.i2c1rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "I2C1RST");
    state->f4.fld.apb1rstr.i2c2rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "I2C2RST");
    state->f4.fld.apb1rstr.i2c3rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "I2C3RST");
    state->f4.fld.apb1rstr.can1rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "CAN1RST");
    state->f4.fld.apb1rstr.can2rst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "CAN2RST");
    state->f4.fld.apb1rstr.pwrrst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "PWRRST");
    state->f4.fld.apb1rstr.dacrst = cm_object_get_child_by_name(
            state->f4.reg.apb1rstr, "DACRST");

    // APB2RSTR bitfields.
    state->f4.fld.apb2rstr.tim1rst = cm_object_get_child_by_name(
            state->f4.reg.apb2rstr, "TIM1RST");
    state->f4.fld.apb2rstr.tim8rst = cm_object_get_child_by_name(
            state->f4.reg.apb2rstr, "TIM8RST");
    state->f4.fld.apb2rstr.usart1rst = cm_object_get_child_by_name(
            state->f4.reg.apb2rstr, "USART1RST");
    state->f4.fld.apb2rstr.usart6rst = cm_object_get_child_by_name(
            state->f4.reg.apb2rstr, "USART6RST");
    state->f4.fld.apb2rstr.adcrst = cm_object_get_child_by_name(
            state->f4.reg.apb2rstr, "ADCRST");
    state->f4.fld.apb2rstr.sdiorst = cm_object_get_child_by_name(
            state->f4.reg.apb2rstr, "SDIORST");
    state->f4.fld.apb2rstr.spi1rst = cm_object_get_child_by_name(
            state->f4.reg.apb2rstr, "SPI1RST");
    state->f4.fld.apb2rstr.syscfgrst = cm_object_get_child_by_name(
            state->f4.reg.apb2rstr, "SYSCFGRST");
    state->f4.fld.apb2rstr.tim9rst = cm_object_get_child_by_name(
            state->f4.reg.apb2rstr, "TIM9RST");
    state->f4.fld.apb2rstr.tim10rst = cm_object_get_child_by_name(
            state->f4.reg.apb2rstr, "TIM10RST");
    state->f4.fld.apb2rstr.tim11rst = cm_object_get_child_by_name(
            state->f4.reg.apb2rstr, "TIM11RST");

    // AHB1ENR bitfields.
    state->f4.fld.ahb1enr.gpioaen = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "GPIOAEN");
    state->f4.fld.ahb1enr.gpioben = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "GPIOBEN");
    state->f4.fld.ahb1enr.gpiocen = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "GPIOCEN");
    state->f4.fld.ahb1enr.gpioden = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "GPIODEN");
    state->f4.fld.ahb1enr.gpioeen = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "GPIOEEN");
    state->f4.fld.ahb1enr.gpiofen = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "GPIOFEN");
    state->f4.fld.ahb1enr.gpiogen = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "GPIOGEN");
    state->f4.fld.ahb1enr.gpiohen = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "GPIOHEN");
    state->f4.fld.ahb1enr.gpioien = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "GPIOIEN");
    state->f4.fld.ahb1enr.crcen = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "CRCEN");
    state->f4.fld.ahb1enr.bkpsramen = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "BKPSRAMEN");
    state->f4.fld.ahb1enr.dma1en = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "DMA1EN");
    state->f4.fld.ahb1enr.dma2en = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "DMA2EN");
    state->f4.fld.ahb1enr.ethmacen = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "ETHMACEN");
    state->f4.fld.ahb1enr.ethmactxen = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "ETHMACTXEN");
    state->f4.fld.ahb1enr.ethmacrxen = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "ETHMACRXEN");
    state->f4.fld.ahb1enr.ethmacptpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "ETHMACPTPEN");
    state->f4.fld.ahb1enr.otghsen = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "OTGHSEN");
    state->f4.fld.ahb1enr.otghsulpien = cm_object_get_child_by_name(
            state->f4.reg.ahb1enr, "OTGHSULPIEN");

    // AHB2ENR bitfields.
    state->f4.fld.ahb2enr.dcmien = cm_object_get_child_by_name(
            state->f4.reg.ahb2enr, "DCMIEN");
    state->f4.fld.ahb2enr.rngen = cm_object_get_child_by_name(
            state->f4.reg.ahb2enr, "RNGEN");
    state->f4.fld.ahb2enr.otgfsen = cm_object_get_child_by_name(
            state->f4.reg.ahb2enr, "OTGFSEN");

    // AHB3ENR bitfields.
    state->f4.fld.ahb3enr.fsmcen = cm_object_get_child_by_name(
            state->f4.reg.ahb3enr, "FSMCEN");

    // APB1ENR bitfields.
    state->f4.fld.apb1enr.tim2en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "TIM2EN");
    state->f4.fld.apb1enr.tim3en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "TIM3EN");
    state->f4.fld.apb1enr.tim4en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "TIM4EN");
    state->f4.fld.apb1enr.tim5en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "TIM5EN");
    state->f4.fld.apb1enr.tim6en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "TIM6EN");
    state->f4.fld.apb1enr.tim7en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "TIM7EN");
    state->f4.fld.apb1enr.tim12en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "TIM12EN");
    state->f4.fld.apb1enr.tim13en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "TIM13EN");
    state->f4.fld.apb1enr.tim14en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "TIM14EN");
    state->f4.fld.apb1enr.wwdgen = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "WWDGEN");
    state->f4.fld.apb1enr.spi2en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "SPI2EN");
    state->f4.fld.apb1enr.spi3en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "SPI3EN");
    state->f4.fld.apb1enr.usart2en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "USART2EN");
    state->f4.fld.apb1enr.usart3en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "USART3EN");
    state->f4.fld.apb1enr.uart4en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "UART4EN");
    state->f4.fld.apb1enr.uart5en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "UART5EN");
    state->f4.fld.apb1enr.i2c1en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "I2C1EN");
    state->f4.fld.apb1enr.i2c2en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "I2C2EN");
    state->f4.fld.apb1enr.i2c3en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "I2C3EN");
    state->f4.fld.apb1enr.can1en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "CAN1EN");
    state->f4.fld.apb1enr.can2en = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "CAN2EN");
    state->f4.fld.apb1enr.pwren = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "PWREN");
    state->f4.fld.apb1enr.dacen = cm_object_get_child_by_name(
            state->f4.reg.apb1enr, "DACEN");

    // APB2ENR bitfields.
    state->f4.fld.apb2enr.tim1en = cm_object_get_child_by_name(
            state->f4.reg.apb2enr, "TIM1EN");
    state->f4.fld.apb2enr.tim8en = cm_object_get_child_by_name(
            state->f4.reg.apb2enr, "TIM8EN");
    state->f4.fld.apb2enr.usart1en = cm_object_get_child_by_name(
            state->f4.reg.apb2enr, "USART1EN");
    state->f4.fld.apb2enr.usart6en = cm_object_get_child_by_name(
            state->f4.reg.apb2enr, "USART6EN");
    state->f4.fld.apb2enr.adc1en = cm_object_get_child_by_name(
            state->f4.reg.apb2enr, "ADC1EN");
    state->f4.fld.apb2enr.adc2en = cm_object_get_child_by_name(
            state->f4.reg.apb2enr, "ADC2EN");
    state->f4.fld.apb2enr.adc3en = cm_object_get_child_by_name(
            state->f4.reg.apb2enr, "ADC3EN");
    state->f4.fld.apb2enr.sdioen = cm_object_get_child_by_name(
            state->f4.reg.apb2enr, "SDIOEN");
    state->f4.fld.apb2enr.spi1en = cm_object_get_child_by_name(
            state->f4.reg.apb2enr, "SPI1EN");
    state->f4.fld.apb2enr.syscfgen = cm_object_get_child_by_name(
            state->f4.reg.apb2enr, "SYSCFGEN");
    state->f4.fld.apb2enr.tim9en = cm_object_get_child_by_name(
            state->f4.reg.apb2enr, "TIM9EN");
    state->f4.fld.apb2enr.tim10en = cm_object_get_child_by_name(
            state->f4.reg.apb2enr, "TIM10EN");
    state->f4.fld.apb2enr.tim11en = cm_object_get_child_by_name(
            state->f4.reg.apb2enr, "TIM11EN");

    // AHB1LPENR bitfields.
    state->f4.fld.ahb1lpenr.gpioalpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "GPIOALPEN");
    state->f4.fld.ahb1lpenr.gpioblpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "GPIOBLPEN");
    state->f4.fld.ahb1lpenr.gpioclpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "GPIOCLPEN");
    state->f4.fld.ahb1lpenr.gpiodlpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "GPIODLPEN");
    state->f4.fld.ahb1lpenr.gpioelpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "GPIOELPEN");
    state->f4.fld.ahb1lpenr.gpioflpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "GPIOFLPEN");
    state->f4.fld.ahb1lpenr.gpioglpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "GPIOGLPEN");
    state->f4.fld.ahb1lpenr.gpiohlpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "GPIOHLPEN");
    state->f4.fld.ahb1lpenr.gpioilpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "GPIOILPEN");
    state->f4.fld.ahb1lpenr.crclpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "CRCLPEN");
    state->f4.fld.ahb1lpenr.flitflpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "FLITFLPEN");
    state->f4.fld.ahb1lpenr.sram1lpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "SRAM1LPEN");
    state->f4.fld.ahb1lpenr.sram2lpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "SRAM2LPEN");
    state->f4.fld.ahb1lpenr.bkpsramlpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "BKPSRAMLPEN");
    state->f4.fld.ahb1lpenr.dma1lpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "DMA1LPEN");
    state->f4.fld.ahb1lpenr.dma2lpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "DMA2LPEN");
    state->f4.fld.ahb1lpenr.ethmaclpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "ETHMACLPEN");
    state->f4.fld.ahb1lpenr.ethmactxlpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "ETHMACTXLPEN");
    state->f4.fld.ahb1lpenr.ethmacrxlpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "ETHMACRXLPEN");
    state->f4.fld.ahb1lpenr.ethmacptplpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "ETHMACPTPLPEN");
    state->f4.fld.ahb1lpenr.otghslpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "OTGHSLPEN");
    state->f4.fld.ahb1lpenr.otghsulpilpen = cm_object_get_child_by_name(
            state->f4.reg.ahb1lpenr, "OTGHSULPILPEN");

    // AHB2LPENR bitfields.
    state->f4.fld.ahb2lpenr.dcmilpen = cm_object_get_child_by_name(
            state->f4.reg.ahb2lpenr, "DCMILPEN");
    state->f4.fld.ahb2lpenr.rnglpen = cm_object_get_child_by_name(
            state->f4.reg.ahb2lpenr, "RNGLPEN");
    state->f4.fld.ahb2lpenr.otgfslpen = cm_object_get_child_by_name(
            state->f4.reg.ahb2lpenr, "OTGFSLPEN");

    // AHB3LPENR bitfields.
    state->f4.fld.ahb3lpenr.fsmclpen = cm_object_get_child_by_name(
            state->f4.reg.ahb3lpenr, "FSMCLPEN");

    // APB1LPENR bitfields.
    state->f4.fld.apb1lpenr.tim2lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "TIM2LPEN");
    state->f4.fld.apb1lpenr.tim3lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "TIM3LPEN");
    state->f4.fld.apb1lpenr.tim4lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "TIM4LPEN");
    state->f4.fld.apb1lpenr.tim5lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "TIM5LPEN");
    state->f4.fld.apb1lpenr.tim6lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "TIM6LPEN");
    state->f4.fld.apb1lpenr.tim7lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "TIM7LPEN");
    state->f4.fld.apb1lpenr.tim12lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "TIM12LPEN");
    state->f4.fld.apb1lpenr.tim13lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "TIM13LPEN");
    state->f4.fld.apb1lpenr.tim14lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "TIM14LPEN");
    state->f4.fld.apb1lpenr.wwdglpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "WWDGLPEN");
    state->f4.fld.apb1lpenr.spi2lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "SPI2LPEN");
    state->f4.fld.apb1lpenr.spi3lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "SPI3LPEN");
    state->f4.fld.apb1lpenr.usart2lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "USART2LPEN");
    state->f4.fld.apb1lpenr.usart3lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "USART3LPEN");
    state->f4.fld.apb1lpenr.uart4lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "UART4LPEN");
    state->f4.fld.apb1lpenr.uart5lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "UART5LPEN");
    state->f4.fld.apb1lpenr.i2c1lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "I2C1LPEN");
    state->f4.fld.apb1lpenr.i2c2lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "I2C2LPEN");
    state->f4.fld.apb1lpenr.i2c3lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "I2C3LPEN");
    state->f4.fld.apb1lpenr.can1lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "CAN1LPEN");
    state->f4.fld.apb1lpenr.can2lpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "CAN2LPEN");
    state->f4.fld.apb1lpenr.pwrlpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "PWRLPEN");
    state->f4.fld.apb1lpenr.daclpen = cm_object_get_child_by_name(
            state->f4.reg.apb1lpenr, "DACLPEN");

    // APB2LPENR bitfields.
    state->f4.fld.apb2lpenr.tim1lpen = cm_object_get_child_by_name(
            state->f4.reg.apb2lpenr, "TIM1LPEN");
    state->f4.fld.apb2lpenr.tim8lpen = cm_object_get_child_by_name(
            state->f4.reg.apb2lpenr, "TIM8LPEN");
    state->f4.fld.apb2lpenr.usart1lpen = cm_object_get_child_by_name(
            state->f4.reg.apb2lpenr, "USART1LPEN");
    state->f4.fld.apb2lpenr.usart6lpen = cm_object_get_child_by_name(
            state->f4.reg.apb2lpenr, "USART6LPEN");
    state->f4.fld.apb2lpenr.adc1lpen = cm_object_get_child_by_name(
            state->f4.reg.apb2lpenr, "ADC1LPEN");
    state->f4.fld.apb2lpenr.adc2lpen = cm_object_get_child_by_name(
            state->f4.reg.apb2lpenr, "ADC2LPEN");
    state->f4.fld.apb2lpenr.adc3lpen = cm_object_get_child_by_name(
            state->f4.reg.apb2lpenr, "ADC3LPEN");
    state->f4.fld.apb2lpenr.sdiolpen = cm_object_get_child_by_name(
            state->f4.reg.apb2lpenr, "SDIOLPEN");
    state->f4.fld.apb2lpenr.spi1lpen = cm_object_get_child_by_name(
            state->f4.reg.apb2lpenr, "SPI1LPEN");
    state->f4.fld.apb2lpenr.syscfglpen = cm_object_get_child_by_name(
            state->f4.reg.apb2lpenr, "SYSCFGLPEN");
    state->f4.fld.apb2lpenr.tim9lpen = cm_object_get_child_by_name(
            state->f4.reg.apb2lpenr, "TIM9LPEN");
    state->f4.fld.apb2lpenr.tim10lpen = cm_object_get_child_by_name(
            state->f4.reg.apb2lpenr, "TIM10LPEN");
    state->f4.fld.apb2lpenr.tim11lpen = cm_object_get_child_by_name(
            state->f4.reg.apb2lpenr, "TIM11LPEN");

    // BDCR bitfields.
    state->f4.fld.bdcr.lseon = cm_object_get_child_by_name(state->f4.reg.bdcr,
            "LSEON");
    state->f4.fld.bdcr.lserdy = cm_object_get_child_by_name(state->f4.reg.bdcr,
            "LSERDY");
    state->f4.fld.bdcr.lsebyp = cm_object_get_child_by_name(state->f4.reg.bdcr,
            "LSEBYP");
    state->f4.fld.bdcr.rtcsel = cm_object_get_child_by_name(state->f4.reg.bdcr,
            "RTCSEL");
    state->f4.fld.bdcr.rtcen = cm_object_get_child_by_name(state->f4.reg.bdcr,
            "RTCEN");
    state->f4.fld.bdcr.bdrst = cm_object_get_child_by_name(state->f4.reg.bdcr,
            "BDRST");

    // CSR bitfields.
    state->f4.fld.csr.lsion = cm_object_get_child_by_name(state->f4.reg.csr,
            "LSION");
    state->f4.fld.csr.lsirdy = cm_object_get_child_by_name(state->f4.reg.csr,
            "LSIRDY");
    state->f4.fld.csr.rmvf = cm_object_get_child_by_name(state->f4.reg.csr,
            "RMVF");
    state->f4.fld.csr.borrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "BORRSTF");
    state->f4.fld.csr.padrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "PADRSTF");
    state->f4.fld.csr.porrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "PORRSTF");
    state->f4.fld.csr.sftrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "SFTRSTF");
    state->f4.fld.csr.wdgrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "WDGRSTF");
    state->f4.fld.csr.wwdgrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "WWDGRSTF");
    state->f4.fld.csr.lpwrrstf = cm_object_get_child_by_name(state->f4.reg.csr,
            "LPWRRSTF");

    // SSCGR bitfields.
    state->f4.fld.sscgr.modper = cm_object_get_child_by_name(
            state->f4.reg.sscgr, "MODPER");
    state->f4.fld.sscgr.incstep = cm_object_get_child_by_name(
            state->f4.reg.sscgr, "INCSTEP");
    state->f4.fld.sscgr.spreadsel = cm_object_get_child_by_name(
            state->f4.reg.sscgr, "SPREADSEL");
    state->f4.fld.sscgr.sscgen = cm_object_get_child_by_name(
            state->f4.reg.sscgr, "SSCGEN");

    // PLLI2SCFGR bitfields.
    state->f4.fld.plli2scfgr.plli2snx = cm_object_get_child_by_name(
            state->f4.reg.plli2scfgr, "PLLI2SNx");
    state->f4.fld.plli2scfgr.plli2srx = cm_object_get_child_by_name(
            state->f4.reg.plli2scfgr, "PLLI2SRx");
}

// ----- Private --------------------------------------------------------------

static void stm32_rcc_update_clocks(STM32RCCState *state);

/* ------------------------------------------------------------------------- */

#if 0
static PeripheralInfo stm32f051xx_rcc_info =
{
    .desc = "Reset and clock control (RCC)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_ALL,

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
                    "HSI clock enable",
                    .first_bit = 0,},
                {
                    .name = "hsirdy",
                    .desc =
                    "HSI clock ready flag",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsitrim",
                    .desc =
                    "HSI clock trimming",
                    .first_bit = 3,
                    .width_bits = 5,},
                {
                    .name = "hsical",
                    .desc =
                    "HSI clock calibration",
                    .first_bit = 8,
                    .width_bits = 8,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hseon",
                    .desc =
                    "HSE clock enable",
                    .first_bit = 16,},
                {
                    .name = "hserdy",
                    .desc =
                    "EHSE clock ready flag",
                    .first_bit = 17,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsebyp",
                    .desc =
                    "HSE crystal oscillator bypass",
                    .first_bit = 18,},
                {
                    .name = "csson",
                    .desc =
                    "Clock security system enable",
                    .first_bit = 19,},
                {
                    .name = "pllon",
                    .desc = "PLL enable",
                    .first_bit = 24,},
                {
                    .name = "pllrdy",
                    .desc =
                    "PLL clock ready flag",
                    .first_bit = 25,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {}, /**/
            },
            /**/
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
                    .width_bits = 2,},
                {
                    .name = "sws",
                    .desc =
                    "System clock switch status",
                    .first_bit = 2,
                    .width_bits = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hpre",
                    .desc =
                    "HLCK prescaler",
                    .first_bit = 4,
                    .width_bits = 4,},
                {
                    .name = "ppre",
                    .desc =
                    "PCLK prescaler",
                    .first_bit = 8,
                    .width_bits = 3,},
                {
                    .name = "adcpre",
                    .desc =
                    "ADC prescaler",
                    .first_bit = 14,
                    .width_bits = 1,},
                {
                    .name = "pllsrc",
                    .desc =
                    "PLL input clock source",
                    .first_bit = 15,
                    .width_bits = 2,},
                {
                    .name = "pllxtpre",
                    .desc =
                    "HSE divider for PLL entry",
                    .first_bit = 17,},
                {
                    .name = "pllmul",
                    .desc =
                    "PLL multiplication factor",
                    .first_bit = 18,
                    .width_bits = 4,},
                {
                    .name = "mco",
                    .desc =
                    "Microcontroller clock output",
                    .first_bit = 24,
                    .width_bits = 3,},
                {
                    .name = "mcopre",
                    .desc =
                    "Microcontroller Clock Output Prescaler (not available on STM32F05x devices)",
                    .first_bit = 28,
                    .width_bits = 3,},
                {
                    .name = "pllnodiv",
                    .desc =
                    "PLL clock not divided for MCO (not available on STM32F05x devices)",
                    .first_bit = 31,},
                {}, /**/
            },
            /**/
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
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lserdyf",
                    .desc =
                    "LSE ready interrupt flag",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsirdyf",
                    .desc =
                    "HSI ready interrupt flag",
                    .first_bit = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hserdyf",
                    .desc =
                    "HSE ready interrupt flag",
                    .first_bit = 3,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "pllrdyf",
                    .desc =
                    "PLL ready interrupt flag",
                    .first_bit = 4,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsi14rdyf",
                    .desc =
                    "HSI14 ready interrupt flag",
                    .first_bit = 5,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsi48rdyf",
                    .desc =
                    "HSI48 ready interrupt flag",
                    .first_bit = 6,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "cssf",
                    .desc =
                    "Clock security system interrupt flag",
                    .first_bit = 7,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lsirdyie",
                    .desc =
                    "LSI ready interrupt enable",
                    .first_bit = 8,},
                {
                    .name = "lserdyie",
                    .desc =
                    "LSE ready interrupt enable",
                    .first_bit = 9,},
                {
                    .name = "hsirdyie",
                    .desc =
                    "HSI ready interrupt enable",
                    .first_bit = 10,},
                {
                    .name = "hserdyie",
                    .desc =
                    "HSE ready interrupt enable",
                    .first_bit = 11,},
                {
                    .name = "pllrdyie",
                    .desc =
                    "PLL ready interrupt enable",
                    .first_bit = 12,},
                {
                    .name = "hsi14rdye",
                    .desc =
                    "HSI14 ready interrupt enable",
                    .first_bit = 13,},
                {
                    .name = "hsi48rdye",
                    .desc =
                    "HSI48 ready interrupt enable",
                    .first_bit = 14,},
                {
                    .name = "lsirdyc",
                    .desc =
                    "LSI ready interrupt clear",
                    .first_bit = 16,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "lserdyc",
                    .desc =
                    "LSE ready interrupt clear",
                    .first_bit = 17,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "hsirdyc",
                    .desc =
                    "HSI ready interrupt clear",
                    .first_bit = 18,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "hserdyc",
                    .desc =
                    "HSE ready interrupt clear",
                    .first_bit = 19,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "pllrdyc",
                    .desc =
                    "PLL ready interrupt clear",
                    .first_bit = 20,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "hsi14rdyc",
                    .desc =
                    "HSI14 ready interrupt clear",
                    .first_bit = 21,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "hsi48rdyc",
                    .desc =
                    "HSI48 ready interrupt clear",
                    .first_bit = 22,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "cssc",
                    .desc =
                    "Clock security system interrupt clear",
                    .first_bit = 23,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {}, /**/
            },
            /**/
        },
        {
            .desc =
            "APB2 peripheral reset register (RCC_APB2RSTR)",
            .name = "apb2rstr",
            .offset_bytes = 0x0C,
            .reset_value = 0x00000000,
            .readable_bits = 0x00475DE1,
            .writable_bits = 0x00475DE1,
            /**/
        },
        {
            .desc =
            "APB1 peripheral reset register (RCC_APB1RSTR)",
            .name = "apb1rstr",
            .offset_bytes = 0x10,
            .reset_value = 0x00000000,
            .readable_bits = 0x7AFE4933,
            .writable_bits = 0x7AFE4933,
            /**/
        },
        {
            /* When the peripheral clock is not active,
             * the peripheral register values may not
             * be readable by software and the returned
             * value is always 0x0. */
            .desc =
            "AHB peripheral clock enable register (RCC_AHBENR)",
            .name = "ahbenr",
            .offset_bytes = 0x14,
            .reset_value = 0x00000000,
            .readable_bits = 0x017E0057,
            .writable_bits = 0x017E0057,
            /**/
        },
        {
            /* When the peripheral clock is not active,
             * the peripheral register values may not
             * be readable by software and the returned
             * value is always 0x0. */
            .desc =
            "APB2 peripheral clock enable register (RCC_APB2ENR)",
            .name = "apb2enr",
            .offset_bytes = 0x18,
            .reset_value = 0x00000000,
            .readable_bits = 0x00475AE1,
            .writable_bits = 0x00475AE1,
            /**/
        },
        {
            /* When the peripheral clock is not active,
             * the peripheral register values may not
             * be readable by software and the returned
             * value is always 0x0. */
            .desc =
            "APB1 peripheral clock enable register (RCC_APB1ENR)",
            .name = "apb1enr",
            .offset_bytes = 0x1C,
            .reset_value = 0x00000000,
            .readable_bits = 0x3E7EC83F,
            .writable_bits = 0x3E7EC83F,
            /**/
        },
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
                    "LSE oscillator enable",
                    .first_bit = 0,},
                {
                    .name = "lserdy",
                    .desc =
                    "LSE oscillator ready",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lsebyp",
                    .desc =
                    "LSE oscillator bypass",
                    .first_bit = 2,},
                {
                    .name = "lsedrv",
                    .desc =
                    "LSE oscillator drive capability",
                    .first_bit = 3,
                    .width_bits = 2,},
                {
                    .name = "rtcsel",
                    .desc =
                    "RTC clock source selection",
                    .first_bit = 8,
                    .width_bits = 2,},
                {
                    .name = "rtcen",
                    .desc =
                    "RTC clock enable",
                    .first_bit = 15,},
                {
                    .name = "bdrst",
                    .desc =
                    "RTC domain software reset",
                    .first_bit = 16,},
                {}, /**/
            },
            /**/
        },
        {
            .desc = "Control/status register (RCC_CSR)",
            .name = "csr",
            .offset_bytes = 0x24,
            /* reset by system Reset, except reset flags by power Reset only. */
            .reset_value = 0x0C000000,
            .reset_mask = 0x000FFFFF,
            .bitfields =
            (RegisterBitfieldInfo[] ) {
                {
                    .name = "lsion",
                    .desc =
                    "Internal low-speed oscillator enable",
                    .first_bit = 0,},
                {
                    .name = "lsirdy",
                    .desc =
                    "Internal low-speed oscillator ready",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "v18pwrrstf",
                    .desc =
                    "Remove reset flag",
                    .first_bit = 23,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    /* rt_w, 1 = clear the reset flags */
                    .name = "rmvf",
                    .desc =
                    "Remove reset flag",
                    .first_bit = 24,},
                {
                    .name = "oblrstf",
                    .desc =
                    "Option byte loader reset flag",
                    .first_bit = 25,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "pinrstf",
                    .desc =
                    "PIN reset flag",
                    .first_bit = 26,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "porrstf",
                    .desc =
                    "POR/PDR reset flag",
                    .first_bit = 27,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "stfrstf",
                    .desc =
                    "Software reset flag",
                    .first_bit = 28,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "iwdgrstf",
                    .desc =
                    "Independent watchdog reset flag",
                    .first_bit = 29,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "wwdgrstf",
                    .desc =
                    "Window watchdog reset flag",
                    .first_bit = 30,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lpwrrstf",
                    .desc =
                    "Low-power reset flag",
                    .first_bit = 31,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {}, /**/
            },
            /**/
        },
        {
            .desc =
            "AHB peripheral clock reset register (RCC_AHBRSTR)",
            .name = "ahbrstr",
            .offset_bytes = 0x28,
            .reset_value = 0x00000000,
            .readable_bits = 0x017E0000,
            .writable_bits = 0x017E0000,
            /**/
        },
        {
            .desc =
            "Clock configuration register 2 (RCC_CFGR2)",
            .name = "cfgr2",
            .offset_bytes = 0x2C,
            .reset_value = 0x00000000,
            .bitfields =
            (RegisterBitfieldInfo[] ) {
                {
                    .name = "prediv",
                    .desc =
                    "PREDIV1 division factor",
                    .first_bit = 0,
                    .width_bits = 4,},
                {}, /**/
            },
            /**/
        },
        {
            .desc =
            "Clock configuration register 3 (RCC_CFGR3)",
            .name = "cfgr3",
            .offset_bytes = 0x30,
            .reset_value = 0x00000000,
            .readable_bits = 0x000F01D3,
            .writable_bits = 0x000F01D3,
            /**/
        },
        {
            .desc = "Clock control register 2 (RCC_CR2)",
            .name = "cr2",
            .offset_bytes = 0x34,
            .reset_value = 0x00000080,
            .reset_mask = 0x00FF00FF,
            .readable_bits = 0xFF03FFFF,
            .writable_bits = 0x000100FD,
            /**/
        },
        {}, /**/
    }, /**/
};
#endif

#if 0
static void stm32f051_rcc_create_objects(Object *obj, JSON_Value *family)
{
    STM32RCCState *state = STM32_RCC_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family, "stm32f051:rcc");

    peripheral_add_properties_and_children2(obj, info);

    state->f0.reg.cr = cm_object_get_child_by_name(obj, "cr");
    state->f0.reg.cfgr = cm_object_get_child_by_name(obj, "cfgr");
    state->f0.reg.cir = cm_object_get_child_by_name(obj, "cir");
    state->f0.reg.apb2rstr = cm_object_get_child_by_name(obj, "apb2rstr");
    state->f0.reg.apb1rstr = cm_object_get_child_by_name(obj, "apb1rstr");
    state->f0.reg.ahbenr = cm_object_get_child_by_name(obj, "ahbenr");
    state->f0.reg.apb2enr = cm_object_get_child_by_name(obj, "apb2enr");
    state->f0.reg.apb1enr = cm_object_get_child_by_name(obj, "apb1enr");
    state->f0.reg.bdcr = cm_object_get_child_by_name(obj, "bdcr");
    state->f0.reg.csr = cm_object_get_child_by_name(obj, "csr");
    state->f0.reg.ahbrstr = cm_object_get_child_by_name(obj, "ahbrstr");
    state->f0.reg.cfgr2 = cm_object_get_child_by_name(obj, "cfgr2");
    state->f0.reg.cfgr3 = cm_object_get_child_by_name(obj, "cfgr3");
    state->f0.reg.cr2 = cm_object_get_child_by_name(obj, "cr2");

    /* CR bitfields. */
    state->f0.cr.hsion = cm_object_get_child_by_name(state->f0.reg.cr, "hsion");
    state->f0.cr.hsirdy = cm_object_get_child_by_name(state->f0.reg.cr,
            "hsirdy");
    state->f0.cr.hsitrim = cm_object_get_child_by_name(state->f0.reg.cr,
            "hsitrim");
    state->f0.cr.hsical = cm_object_get_child_by_name(state->f0.reg.cr,
            "hsical");
    state->f0.cr.hseon = cm_object_get_child_by_name(state->f0.reg.cr, "hseon");
    state->f0.cr.hserdy = cm_object_get_child_by_name(state->f0.reg.cr,
            "hserdy");
    state->f0.cr.hsebyp = cm_object_get_child_by_name(state->f0.reg.cr,
            "hsebyp");
    state->f0.cr.csson = cm_object_get_child_by_name(state->f0.reg.cr, "csson");
    state->f0.cr.pllon = cm_object_get_child_by_name(state->f0.reg.cr, "pllon");
    state->f0.cr.pllrdy = cm_object_get_child_by_name(state->f0.reg.cr,
            "pllrdy");

    /* CFGR bitfields. */
    state->f0.cfgr.sw = cm_object_get_child_by_name(state->f0.reg.cfgr, "sw");
    state->f0.cfgr.sws = cm_object_get_child_by_name(state->f0.reg.cfgr, "sws");
    state->f0.cfgr.hpre = cm_object_get_child_by_name(state->f0.reg.cfgr,
            "hpre");
    state->f0.cfgr.ppre = cm_object_get_child_by_name(state->f0.reg.cfgr,
            "ppre");
    state->f0.cfgr.adcpre = cm_object_get_child_by_name(state->f0.reg.cfgr,
            "adcpre");
    state->f0.cfgr.pllsrc = cm_object_get_child_by_name(state->f0.reg.cfgr,
            "pllsrc");
    state->f0.cfgr.pllxtpre = cm_object_get_child_by_name(state->f0.reg.cfgr,
            "pllxtpre");
    state->f0.cfgr.pllmul = cm_object_get_child_by_name(state->f0.reg.cfgr,
            "pllmul");
    state->f0.cfgr.mco = cm_object_get_child_by_name(state->f0.reg.cfgr, "mco");
    state->f0.cfgr.mcopre = cm_object_get_child_by_name(state->f0.reg.cfgr,
            "mcopre");
    state->f0.cfgr.pllnodiv = cm_object_get_child_by_name(state->f0.reg.cfgr,
            "pllnodiv");

    /* CIR bitfields. */
    state->f0.cir.lsirdyf = cm_object_get_child_by_name(state->f0.reg.cir,
            "lsirdyf");
    state->f0.cir.lserdyf = cm_object_get_child_by_name(state->f0.reg.cir,
            "lserdyf");
    state->f0.cir.hsirdyf = cm_object_get_child_by_name(state->f0.reg.cir,
            "hsirdyf");
    state->f0.cir.hserdyf = cm_object_get_child_by_name(state->f0.reg.cir,
            "hserdyf");
    state->f0.cir.pllrdyf = cm_object_get_child_by_name(state->f0.reg.cir,
            "pllrdyf");
    state->f0.cir.hsi14rdyf = cm_object_get_child_by_name(state->f0.reg.cir,
            "hsi14rdyf");
    state->f0.cir.hsi48rdyf = cm_object_get_child_by_name(state->f0.reg.cir,
            "hsi48rdyf");
    state->f0.cir.cssf = cm_object_get_child_by_name(state->f0.reg.cir, "cssf");

    /* BDCR bitfields. */
    state->f0.bdcr.lserdy = cm_object_get_child_by_name(state->f0.reg.bdcr,
            "lserdy");

    /* CSR bitfields. */
    state->f0.csr.lsion = cm_object_get_child_by_name(state->f0.reg.csr,
            "lsion");
    state->f0.csr.lsirdy = cm_object_get_child_by_name(state->f0.reg.csr,
            "lsirdy");
    state->f0.csr.v18pwrrstf = cm_object_get_child_by_name(state->f0.reg.csr,
            "v18pwrrstf");
    state->f0.csr.rmvf = cm_object_get_child_by_name(state->f0.reg.csr, "rmvf");
    state->f0.csr.oblrstf = cm_object_get_child_by_name(state->f0.reg.csr,
            "oblrstf");
    state->f0.csr.pinrstf = cm_object_get_child_by_name(state->f0.reg.csr,
            "pinrstf");
    state->f0.csr.porrstf = cm_object_get_child_by_name(state->f0.reg.csr,
            "porrstf");
    state->f0.csr.stfrstf = cm_object_get_child_by_name(state->f0.reg.csr,
            "stfrstf");
    state->f0.csr.iwdgrstf = cm_object_get_child_by_name(state->f0.reg.csr,
            "iwdgrstf");
    state->f0.csr.wwdgrstf = cm_object_get_child_by_name(state->f0.reg.csr,
            "wwdgrstf");
    state->f0.csr.lpwrrstf = cm_object_get_child_by_name(state->f0.reg.csr,
            "lpwrrstf");

    /* CFGR2 bitfields. */
    state->f0.cfgr2.prediv = cm_object_get_child_by_name(state->f0.reg.cfgr2,
            "prediv");
}
#endif

/* ------------------------------------------------------------------------- */

#if 0
static PeripheralInfo stm32f1_rcc_info =
{
    .desc = "Reset and clock control (RCC)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_ALL,

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
                    .first_bit = 0,},
                {
                    .name = "hsirdy",
                    .desc =
                    "Internal high-speed clock ready flag",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsitrim",
                    .desc =
                    "Internal high-speed clock trimming",
                    .first_bit = 3,
                    .width_bits = 5,},
                {
                    .name = "hsical",
                    .desc =
                    "Internal high-speed clock calibration",
                    .first_bit = 8,
                    .width_bits = 8,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hseon",
                    .desc =
                    "External clock enable",
                    .first_bit = 16,},
                {
                    .name = "hserdy",
                    .desc =
                    "External high-speed clock ready flag",
                    .first_bit = 17,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsebyp",
                    .desc =
                    "External high-speed clock bypass",
                    .first_bit = 18,},
                {
                    .name = "csson",
                    .desc =
                    "Clock security system enable",
                    .first_bit = 19,},
                {
                    .name = "pllon",
                    .desc = "PLL enable",
                    .first_bit = 24,},
                {
                    .name = "pllrdy",
                    .desc =
                    "PLL clock ready flag",
                    .first_bit = 25,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {}, /**/
            },
            /**/
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
                    .width_bits = 2,},
                {
                    .name = "sws",
                    .desc =
                    "System clock switch status",
                    .first_bit = 2,
                    .width_bits = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hpre",
                    .desc =
                    "AHB prescaler",
                    .first_bit = 4,
                    .width_bits = 4,},
                {
                    .name = "ppre1",
                    .desc =
                    "APB low-speed prescaler (APB1)",
                    .first_bit = 8,
                    .width_bits = 3,},
                {
                    .name = "ppre2",
                    .desc =
                    "APB high-speed prescaler (APB2)",
                    .first_bit = 11,
                    .width_bits = 3,},
                {
                    .name = "adcpre",
                    .desc =
                    "ADC prescaler",
                    .first_bit = 14,
                    .width_bits = 2,},
                {
                    .name = "pllsrc",
                    .desc =
                    "PLL entry clock source",
                    .first_bit = 16,},
                {
                    .name = "pllxtpre",
                    .desc =
                    "HSE divider for PLL entry",
                    .first_bit = 17,},
                {
                    .name = "pllmul",
                    .desc =
                    "PLL multiplication factor",
                    .first_bit = 18,
                    .width_bits = 4,},
                {
                    .name = "usbpre",
                    .desc =
                    "USB prescaler",
                    .first_bit = 22,},
                {
                    .name = "mco",
                    .desc =
                    "Microcontroller clock output",
                    .first_bit = 24,
                    .width_bits = 3,},
                {}, /**/
            },
            /**/
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
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lserdyf",
                    .desc =
                    "LSE ready interrupt flag",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsirdyf",
                    .desc =
                    "HSI ready interrupt flag",
                    .first_bit = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hserdyf",
                    .desc =
                    "HSE ready interrupt flag",
                    .first_bit = 3,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "pllrdyf",
                    .desc =
                    "PLL ready interrupt flag",
                    .first_bit = 4,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "cssf",
                    .desc =
                    "Clock security system interrupt flag",
                    .first_bit = 7,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lsirdyie",
                    .desc =
                    "LSI ready interrupt enable",
                    .first_bit = 8,},
                {
                    .name = "lserdyie",
                    .desc =
                    "LSE ready interrupt enable",
                    .first_bit = 9,},
                {
                    .name = "hsirdyie",
                    .desc =
                    "HSI ready interrupt enable",
                    .first_bit = 10,},
                {
                    .name = "hserdyie",
                    .desc =
                    "HSE ready interrupt enable",
                    .first_bit = 11,},
                {
                    .name = "pllrdyie",
                    .desc =
                    "PLL ready interrupt enable",
                    .first_bit = 12,},
                {
                    .name = "lsirdyc",
                    .desc =
                    "LSI ready interrupt clear",
                    .first_bit = 16,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "lserdyc",
                    .desc =
                    "LSE ready interrupt clear",
                    .first_bit = 17,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "hsirdyc",
                    .desc =
                    "HSI ready interrupt clear",
                    .first_bit = 18,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "hserdyc",
                    .desc =
                    "HSE ready interrupt clear",
                    .first_bit = 19,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "pllrdyc",
                    .desc =
                    "PLL ready interrupt clear",
                    .first_bit = 20,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "cssc",
                    .desc =
                    "Clock security system interrupt clear",
                    .first_bit = 23,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {}, /**/
            },
            /**/
        },
        {
            .desc =
            "APB2 peripheral reset register (RCC_APB2RSTR)",
            .name = "apb2rstr",
            .offset_bytes = 0x0C,
            .reset_value = 0x00000000,
            .readable_bits = 0x0038FFFD,
            .writable_bits = 0x0038FFFD,
            /**/
        },
        {
            .desc =
            "APB1 peripheral reset register (RCC_APB1RSTR)",
            .name = "apb1rstr",
            .offset_bytes = 0x10,
            .reset_value = 0x00000000,
            .readable_bits = 0x3AFEC9FF,
            .writable_bits = 0x3AFEC9FF,
            /**/
        },
        {
            .desc =
            "AHB peripheral clock enable register (RCC_AHBENR)",
            .name = "ahbenr",
            .offset_bytes = 0x14,
            .reset_value = 0x00000000,
            .readable_bits = 0x00000557,
            .writable_bits = 0x00000557,
            /**/
        },
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
                    .first_bit = 0,},
                {
                    .name = "iopaen",
                    .desc =
                    "IO port A clock enable",
                    .first_bit = 2,},
                {
                    .name = "iopben",
                    .desc =
                    "IO port B clock enable",
                    .first_bit = 3,},
                {
                    .name = "iopcen",
                    .desc =
                    "IO port C clock enable",
                    .first_bit = 4,},
                {
                    .name = "iopden",
                    .desc =
                    "IO port D clock enable",
                    .first_bit = 5,},
                {
                    .name = "iopeen",
                    .desc =
                    "IO port E clock enable",
                    .first_bit = 6,},
                {
                    .name = "iopfen",
                    .desc =
                    "IO port F clock enable",
                    .first_bit = 7,},
                {
                    .name = "iopgen",
                    .desc =
                    "IO port G clock enable",
                    .first_bit = 8,},
                {
                    .name = "adc1en",
                    .desc =
                    "ADC1 interface clock enable",
                    .first_bit = 9,},
                {
                    .name = "adc2en",
                    .desc =
                    "ADC2 interface clock enable",
                    .first_bit = 10,},
                {
                    .name = "tim1en",
                    .desc =
                    "TIM1 timer clock enable",
                    .first_bit = 11,},
                {
                    .name = "spi1en",
                    .desc =
                    "SPI1 clock enable",
                    .first_bit = 12,},
                {
                    .name = "tim8en",
                    .desc =
                    "TIM8 timer clock enable",
                    .first_bit = 13,},
                {
                    .name = "usart1en",
                    .desc =
                    "USART1 clock enable",
                    .first_bit = 14,},
                {
                    .name = "adc3en",
                    .desc =
                    "ADC3 interface clock enable",
                    .first_bit = 15,},
                {
                    .name = "tim9en",
                    .desc =
                    "TIM9 timer clock enable",
                    .first_bit = 19,},
                {
                    .name = "tim10en",
                    .desc =
                    "TIM10 timer clock enable",
                    .first_bit = 20,},
                {
                    .name = "tim11en",
                    .desc =
                    "TIM11 timer clock enable",
                    .first_bit = 21,},
                {}, /**/
            },
            /**/
        },
        {
            .desc =
            "APB1 peripheral clock enable register (RCC_APB1ENR)",
            .name = "apb1enr",
            .offset_bytes = 0x1C,
            .reset_value = 0x00000000,
            .readable_bits = 0x3AFEC9FF,
            .writable_bits = 0x3AFEC9FF,
            /**/
        },
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
                    .first_bit = 0,},
                {
                    .name = "lserdy",
                    .desc =
                    "External low-speed oscillator ready",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lsebyp",
                    .desc =
                    "External low-speed oscillator bypass",
                    .first_bit = 2,},
                {
                    .name = "rtcsel",
                    .desc =
                    "RTC clock source selection",
                    .first_bit = 8,
                    .width_bits = 2,},
                {
                    .name = "rtcen",
                    .desc =
                    "RTC clock enable",
                    .first_bit = 15,},
                {
                    .name = "bdrst",
                    .desc =
                    "Backup domain software reset",
                    .first_bit = 16,},
                {}, /**/
            },
            /**/
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
                    .first_bit = 0,},
                {
                    .name = "lsirdy",
                    .desc =
                    "Internal low-speed oscillator ready",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "rmvf",
                    .desc =
                    "Remove reset flag",
                    .first_bit = 24,},
                {
                    .name = "pinrstf",
                    .desc =
                    "PIN reset flag",
                    .first_bit = 26,},
                {
                    .name = "porrstf",
                    .desc =
                    "POR/PDR reset flag",
                    .first_bit = 27,},
                {
                    .name = "stfrstf",
                    .desc =
                    "Software reset flag",
                    .first_bit = 28,},
                {
                    .name = "iwdgrstf",
                    .desc =
                    "Independent watchdog reset flag",
                    .first_bit = 29,},
                {
                    .name = "wwdgrstf",
                    .desc =
                    "Window watchdog reset flag",
                    .first_bit = 30,},
                {
                    .name = "lrwrrstf",
                    .desc =
                    "Low-power reset flag",
                    .first_bit = 31,},
                {}, /**/
            },
            /**/
        },
        {}, /**/
    }, /**/
};
#endif

#if 0
static void stm32f1xx_rcc_create_objects(Object *obj, JSON_Value *family)
{
    STM32RCCState *state = STM32_RCC_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family, "stm32f1xx:rcc");

    peripheral_add_properties_and_children2(obj, info);

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
#endif

/* ------------------------------------------------------------------------- */

/* STM32F1CL */

#if 0
static PeripheralInfo stm32f1cl_rcc_info =
{
    .desc = "Reset and clock control (RCC)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_ALL,

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
                    .first_bit = 0,},
                {
                    .name = "hsirdy",
                    .desc =
                    "Internal high-speed clock ready flag",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsitrim",
                    .desc =
                    "Internal high-speed clock trimming",
                    .first_bit = 3,
                    .width_bits = 5,},
                {
                    .name = "hsical",
                    .desc =
                    "Internal high-speed clock calibration",
                    .first_bit = 8,
                    .width_bits = 8,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hseon",
                    .desc =
                    "External clock enable",
                    .first_bit = 16,},
                {
                    .name = "hserdy",
                    .desc =
                    "External high-speed clock ready flag",
                    .first_bit = 17,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsebyp",
                    .desc =
                    "External high-speed clock bypass",
                    .first_bit = 18,},
                {
                    .name = "csson",
                    .desc =
                    "Clock security system enable",
                    .first_bit = 19,},
                {
                    .name = "pllon",
                    .desc = "PLL enable",
                    .first_bit = 24,},
                {
                    .name = "pllrdy",
                    .desc =
                    "PLL clock ready flag",
                    .first_bit = 25,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "pll2on",
                    .desc =
                    "PLL2 enable",
                    .first_bit = 26,},
                {
                    .name = "pll2rdy",
                    .desc =
                    "PLL2 clock ready flag",
                    .first_bit = 27,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "pll3on",
                    .desc =
                    "PLL3 enable",
                    .first_bit = 28,},
                {
                    .name = "pll3rdy",
                    .desc =
                    "PLL3 clock ready flag",
                    .first_bit = 29,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {}, /**/
            },
            /**/
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
                    .width_bits = 2,},
                {
                    .name = "sws",
                    .desc =
                    "System clock switch status",
                    .first_bit = 2,
                    .width_bits = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hpre",
                    .desc =
                    "AHB prescaler",
                    .first_bit = 4,
                    .width_bits = 4,},
                {
                    .name = "ppre1",
                    .desc =
                    "APB low-speed prescaler (APB1)",
                    .first_bit = 8,
                    .width_bits = 3,},
                {
                    .name = "ppre2",
                    .desc =
                    "APB high-speed prescaler (APB2)",
                    .first_bit = 11,
                    .width_bits = 3,},
                {
                    .name = "adcpre",
                    .desc =
                    "ADC prescaler",
                    .first_bit = 14,
                    .width_bits = 2,},
                {
                    .name = "pllsrc",
                    .desc =
                    "PLL entry clock source",
                    .first_bit = 16,},
                {
                    .name = "pllxtpre",
                    .desc =
                    "HSE divider for PLL entry",
                    .first_bit = 17,},
                {
                    .name = "pllmul",
                    .desc =
                    "PLL multiplication factor",
                    .first_bit = 18,
                    .width_bits = 4,},
                {
                    .name = "otgfspre",
                    .desc =
                    "OTG FS prescaler",
                    .first_bit = 22,},
                {
                    .name = "mco",
                    .desc =
                    "Microcontroller clock output",
                    .first_bit = 24,
                    .width_bits = 3,},
                {}, /**/
            },
            /**/
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
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lserdyf",
                    .desc =
                    "LSE ready interrupt flag",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsirdyf",
                    .desc =
                    "HSI ready interrupt flag",
                    .first_bit = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hserdyf",
                    .desc =
                    "HSE ready interrupt flag",
                    .first_bit = 3,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "pllrdyf",
                    .desc =
                    "PLL ready interrupt flag",
                    .first_bit = 4,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "pll2rdyf",
                    .desc =
                    "PLL2 ready interrupt flag",
                    .first_bit = 5,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "pll3rdyf",
                    .desc =
                    "PLL3 ready interrupt flag",
                    .first_bit = 6,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "cssf",
                    .desc =
                    "Clock security system interrupt flag",
                    .first_bit = 7,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lsirdyie",
                    .desc =
                    "LSI ready interrupt enable",
                    .first_bit = 8,},
                {
                    .name = "lserdyie",
                    .desc =
                    "LSE ready interrupt enable",
                    .first_bit = 9,},
                {
                    .name = "hsirdyie",
                    .desc =
                    "HSI ready interrupt enable",
                    .first_bit = 10,},
                {
                    .name = "hserdyie",
                    .desc =
                    "HSE ready interrupt enable",
                    .first_bit = 11,},
                {
                    .name = "pllrdyie",
                    .desc =
                    "PLL ready interrupt enable",
                    .first_bit = 12,},
                {
                    .name = "pll2rdyie",
                    .desc =
                    "PLL2 ready interrupt enable",
                    .first_bit = 13,},
                {
                    .name = "pll3rdyie",
                    .desc =
                    "PLL3 ready interrupt enable",
                    .first_bit = 14,},
                {
                    .name = "lsirdyc",
                    .desc =
                    "LSI ready interrupt clear",
                    .first_bit = 16,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "lserdyc",
                    .desc =
                    "LSE ready interrupt clear",
                    .first_bit = 17,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "hsirdyc",
                    .desc =
                    "HSI ready interrupt clear",
                    .first_bit = 18,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "hserdyc",
                    .desc =
                    "HSE ready interrupt clear",
                    .first_bit = 19,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "pllrdyc",
                    .desc =
                    "PLL ready interrupt clear",
                    .first_bit = 20,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "pll2rdyc",
                    .desc =
                    "PLL2 ready interrupt clear",
                    .first_bit = 21,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "pll3rdyc",
                    .desc =
                    "PLL3 ready interrupt clear",
                    .first_bit = 22,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "cssc",
                    .desc =
                    "Clock security system interrupt clear",
                    .first_bit = 23,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {}, /**/
            },
            /**/
        },
        {
            .desc =
            "APB2 peripheral reset register (RCC_APB2RSTR)",
            .name = "apb2rstr",
            .offset_bytes = 0x0C,
            .reset_value = 0x00000000,
            .readable_bits = 0x00005E7D,
            .writable_bits = 0x00005E7D,
            /**/
        },
        {
            .desc =
            "APB1 peripheral reset register (RCC_APB1RSTR)",
            .name = "apb1rstr",
            .offset_bytes = 0x10,
            .reset_value = 0x00000000,
            .readable_bits = 0x377EC83F,
            .writable_bits = 0x377EC83F,
            /**/
        },
        {
            .desc =
            "AHB peripheral clock enable register (RCC_AHBENR)",
            .name = "ahbenr",
            .offset_bytes = 0x14,
            .reset_value = 0x00000000,
            .readable_bits = 0x0001D057,
            .writable_bits = 0x0001D057,
            /**/
        },
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
                    .first_bit = 0,},
                {
                    .name = "iopaen",
                    .desc =
                    "IO port A clock enable",
                    .first_bit = 2,},
                {
                    .name = "iopben",
                    .desc =
                    "IO port B clock enable",
                    .first_bit = 3,},
                {
                    .name = "iopcen",
                    .desc =
                    "IO port C clock enable",
                    .first_bit = 4,},
                {
                    .name = "iopden",
                    .desc =
                    "IO port D clock enable",
                    .first_bit = 5,},
                {
                    .name = "iopeen",
                    .desc =
                    "IO port E clock enable",
                    .first_bit = 6,},
                {
                    .name = "adc1en",
                    .desc =
                    "ADC1 interface clock enable",
                    .first_bit = 9,},
                {
                    .name = "adc2en",
                    .desc =
                    "ADC2 interface clock enable",
                    .first_bit = 10,},
                {
                    .name = "tim1en",
                    .desc =
                    "TIM1 timer clock enable",
                    .first_bit = 11,},
                {
                    .name = "spi1en",
                    .desc =
                    "SPI1 clock enable",
                    .first_bit = 12,},
                {
                    .name = "usart1en",
                    .desc =
                    "USART1 clock enable",
                    .first_bit = 14,},
                {}, /**/
            },
            /**/
        },
        {
            .desc =
            "APB1 peripheral clock enable register (RCC_APB1ENR)",
            .name = "apb1enr",
            .offset_bytes = 0x1C,
            .reset_value = 0x00000000,
            .readable_bits = 0x3E7EC83F,
            .writable_bits = 0x3E7EC83F,
            /**/
        },
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
                    .first_bit = 0,},
                {
                    .name = "lserdy",
                    .desc =
                    "External low-speed oscillator ready",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lsebyp",
                    .desc =
                    "External low-speed oscillator bypass",
                    .first_bit = 2,},
                {
                    .name = "rtcsel",
                    .desc =
                    "RTC clock source selection",
                    .first_bit = 8,
                    .width_bits = 2,},
                {
                    .name = "rtcen",
                    .desc =
                    "RTC clock enable",
                    .first_bit = 15,},
                {
                    .name = "bdrst",
                    .desc =
                    "Backup domain software reset",
                    .first_bit = 16,},
                {}, /**/
            },
            /**/
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
                    .first_bit = 0,},
                {
                    .name = "lsirdy",
                    .desc =
                    "Internal low-speed oscillator ready",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "rmvf",
                    .desc =
                    "Remove reset flag",
                    .first_bit = 24,},
                {
                    .name = "pinrstf",
                    .desc =
                    "PIN reset flag",
                    .first_bit = 26,},
                {
                    .name = "porrstf",
                    .desc =
                    "POR/PDR reset flag",
                    .first_bit = 27,},
                {
                    .name = "stfrstf",
                    .desc =
                    "Software reset flag",
                    .first_bit = 28,},
                {
                    .name = "iwdgrstf",
                    .desc =
                    "Independent watchdog reset flag",
                    .first_bit = 29,},
                {
                    .name = "wwdgrstf",
                    .desc =
                    "Window watchdog reset flag",
                    .first_bit = 30,},
                {
                    .name = "lrwrrstf",
                    .desc =
                    "Low-power reset flag",
                    .first_bit = 31,},
                {}, /**/
            },
            /**/
        },
        {
            .desc =
            "AHB peripheral clock reset register (RCC_AHBRSTR)",
            .name = "ahbrstr",
            .offset_bytes = 0x28,
            .reset_value = 0x00000000,
            .readable_bits = 0x00005000,
            .writable_bits = 0x00005000,
            /**/
        },
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
                    .width_bits = 4,},
                {
                    .name = "prediv2",
                    .desc =
                    "PREDIV2 division factor",
                    .first_bit = 4,
                    .width_bits = 4,},
                {
                    .name = "pll2mul",
                    .desc =
                    "PLL2 Multiplication factor",
                    .first_bit = 8,
                    .width_bits = 4,},
                {
                    .name = "pll3mul",
                    .desc =
                    "PLL3 Multiplication factor",
                    .first_bit = 12,
                    .width_bits = 4,},
                {
                    .name = "prediv1src",
                    .desc =
                    "PREDIV1 entry clock source",
                    .first_bit = 16,},
                {
                    .name = "i2s2src",
                    .desc =
                    "I2S2 clock source",
                    .first_bit = 17,},
                {
                    .name = "i2s3src",
                    .desc =
                    "I2S2 clock source",
                    .first_bit = 18,},
                {}, /**/
            },
            /**/
        },

        {}, /**/
    }, /**/
};
#endif

#if 0
static void stm32f1cl_rcc_create_objects(Object *obj, JSON_Value *family)
{
    STM32RCCState *state = STM32_RCC_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family, "stm32f1cl:rcc");

    peripheral_add_properties_and_children2(obj, info);

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
#endif

/* ------------------------------------------------------------------------- */

/* STM32F4_01_57_xx */

#if 0
static PeripheralInfo stm32f4_01_57_xx_rcc_info =
{
    .desc = "Reset and clock control (RCC)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_ALL,

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
                    .first_bit = 0,},
                {
                    .name = "hsirdy",
                    .desc =
                    "Internal high-speed clock ready flag",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsitrim",
                    .desc =
                    "Internal high-speed clock trimming",
                    .first_bit = 3,
                    .width_bits = 5,},
                {
                    .name = "hsical",
                    .desc =
                    "Internal high-speed clock calibration",
                    .first_bit = 8,
                    .width_bits = 8,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hseon",
                    .desc =
                    "External clock enable",
                    .first_bit = 16,},
                {
                    .name = "hserdy",
                    .desc =
                    "External high-speed clock ready flag",
                    .first_bit = 17,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsebyp",
                    .desc =
                    "External high-speed clock bypass",
                    .first_bit = 18,},
                {
                    .name = "csson",
                    .desc =
                    "Clock security system enable",
                    .first_bit = 19,},
                {
                    .name = "pllon",
                    .desc = "PLL enable",
                    .first_bit = 24,},
                {
                    .name = "pllrdy",
                    .desc =
                    "PLL clock ready flag",
                    .first_bit = 25,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "plli2son",
                    .desc =
                    "PLL I2S enable",
                    .first_bit = 26,},
                {
                    .name = "plli2srdy",
                    .desc =
                    "PLL I2S clock ready flag",
                    .first_bit = 27,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},

                {}, /**/
            },
            /**/
        },
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
                    .width_bits = 6,},
                {
                    .name = "plln",
                    .desc =
                    "PLL multiplication factor",
                    .first_bit = 6,
                    .width_bits = 9,},
                {
                    .name = "pllp",
                    .desc =
                    "Main PLL (PLL) division factor",
                    .first_bit = 16,
                    .width_bits = 2,},
                {
                    .name = "pllsrc",
                    .desc =
                    "Main PLL (PLL) clock source",
                    .first_bit = 22,},
                {
                    .name = "pllq",
                    .desc =
                    "Main PLL (PLL) division factor",
                    .first_bit = 24,
                    .width_bits = 4,},
                {},},
            /**/
        },
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
                    .width_bits = 2,},
                {
                    .name = "sws",
                    .desc =
                    "System clock switch status",
                    .first_bit = 2,
                    .width_bits = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hpre",
                    .desc =
                    "AHB prescaler",
                    .first_bit = 4,
                    .width_bits = 4,},
                {
                    .name = "ppre1",
                    .desc =
                    "APB Low speed prescaler (APB1)",
                    .first_bit = 10,
                    .width_bits = 3,},
                {
                    .name = "ppre2",
                    .desc =
                    "APB high speed prescaler (APB2)",
                    .first_bit = 13,
                    .width_bits = 3,},
                {
                    .name = "rtcpre",
                    .desc =
                    "HSE division factor for RTC clock",
                    .first_bit = 16,
                    .width_bits = 5,},
                {
                    .name = "mco1",
                    .desc =
                    "Microcontroller clock output 1",
                    .first_bit = 21,
                    .width_bits = 2,},
                {
                    .name = "i2ssrc",
                    .desc =
                    "I2S clock selection",
                    .first_bit = 23,},
                {
                    .name = "mco1pre",
                    .desc =
                    "MCO1 prescaller",
                    .first_bit = 24,
                    .width_bits = 3,},
                {
                    .name = "mco2pre",
                    .desc =
                    "MCO2 prescaller",
                    .first_bit = 27,
                    .width_bits = 3,},
                {
                    .name = "mco2",
                    .desc =
                    "Microcontroller clock output 2",
                    .first_bit = 30,
                    .width_bits = 2,},
                {}, /**/
            },
            /**/
        },
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
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lserdyf",
                    .desc =
                    "LSE ready interrupt flag",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsirdyf",
                    .desc =
                    "HSI ready interrupt flag",
                    .first_bit = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hserdyf",
                    .desc =
                    "HSE ready interrupt flag",
                    .first_bit = 3,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "pllrdyf",
                    .desc =
                    "PLL ready interrupt flag",
                    .first_bit = 4,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "plli2srdyf",
                    .desc =
                    "PLL I2S ready interrupt flag",
                    .first_bit = 5,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "cssf",
                    .desc =
                    "Clock security system interrupt flag",
                    .first_bit = 7,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lsirdyie",
                    .desc =
                    "LSI ready interrupt enable",
                    .first_bit = 8,},
                {
                    .name = "lserdyie",
                    .desc =
                    "LSE ready interrupt enable",
                    .first_bit = 9,},
                {
                    .name = "hsirdyie",
                    .desc =
                    "HSI ready interrupt enable",
                    .first_bit = 10,},
                {
                    .name = "hserdyie",
                    .desc =
                    "HSE ready interrupt enable",
                    .first_bit = 11,},
                {
                    .name = "pllrdyie",
                    .desc =
                    "PLL ready interrupt enable",
                    .first_bit = 12,},
                {
                    .name =
                    "plli2srdyie",
                    .desc =
                    "PLL I2S ready interrupt enable",
                    .first_bit = 13,},
                {
                    .name = "lsirdyc",
                    .desc =
                    "LSI ready interrupt clear",
                    .first_bit = 16,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "lserdyc",
                    .desc =
                    "LSE ready interrupt clear",
                    .first_bit = 17,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "hsirdyc",
                    .desc =
                    "HSI ready interrupt clear",
                    .first_bit = 18,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "hserdyc",
                    .desc =
                    "HSE ready interrupt clear",
                    .first_bit = 19,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "pllrdyc",
                    .desc =
                    "PLL ready interrupt clear",
                    .first_bit = 20,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "plli2srdyc",
                    .desc =
                    "PLL I2S ready interrupt clear",
                    .first_bit = 21,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "cssc",
                    .desc =
                    "Clock security system interrupt clear",
                    .first_bit = 23,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {}, /**/
            },
            /**/
        },
        {
            .desc =
            "RCC AHB1 peripheral reset register (RCC_AHB1RSTR)",
            .name = "ahb1rstr",
            .offset_bytes = 0x10,
            .reset_value = 0x00000000,
            .readable_bits = 0x226011FF,
            .writable_bits = 0x226011FF,
            /**/
        },
        {
            .desc =
            "RCC AHB2 peripheral reset register (RCC_AHB2RSTR)",
            .name = "ahb2rstr",
            .offset_bytes = 0x14,
            .reset_value = 0x00000000,
            .readable_bits = 0x000000F1,
            .writable_bits = 0x000000F1,
            /**/
        },
        {
            .desc =
            "RCC AHB3 peripheral reset register (RCC_AHB3RSTR)",
            .name = "ahb3rstr",
            .offset_bytes = 0x18,
            .reset_value = 0x00000000,
            .readable_bits = 0x00000001,
            .writable_bits = 0x00000001,
            /**/
        },
        {
            .desc =
            "RCC APB1 peripheral reset register (RCC_APB1RSTR)",
            .name = "apb1rstr",
            .offset_bytes = 0x20,
            .reset_value = 0x00000000,
            .readable_bits = 0x36FEC9FF,
            .writable_bits = 0x36FEC9FF,
            /**/
        },
        {
            .desc =
            "RCC APB2 peripheral reset register (RCC_APB2RSTR)",
            .name = "apb2rstr",
            .offset_bytes = 0x24,
            .reset_value = 0x00000000,
            .readable_bits = 0x00075933,
            .writable_bits = 0x00075933,
            /**/
        },
        {
            .desc =
            "RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)",
            .name = "ahb1enr",
            .offset_bytes = 0x30,
            .reset_value = 0x00100000,
            .readable_bits = 0x7E7C11FF,
            .writable_bits = 0x7E7C11FF,
            /**/
        },
        {
            .desc =
            "RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)",
            .name = "ahb2enr",
            .offset_bytes = 0x34,
            .reset_value = 0x00100000,
            .readable_bits = 0x000000F1,
            .writable_bits = 0x000000F1,
            /**/
        },
        {
            .desc =
            "RCC AHB3 peripheral clock enable register (RCC_AHB3ENR)",
            .name = "ahb3enr",
            .offset_bytes = 0x38,
            .reset_value = 0x00100000,
            .readable_bits = 0x00000001,
            .writable_bits = 0x00000001,
            /**/
        },
        {
            .desc =
            "APB1 peripheral clock enable register (RCC_APB1ENR)",
            .name = "apb1enr",
            .offset_bytes = 0x40,
            .reset_value = 0x00000000,
            .readable_bits = 0x3CFEC9FF,
            .writable_bits = 0x3CFEC9FF,
            /**/
        },
        {
            .desc =
            "APB2 peripheral clock enable register (RCC_APB2ENR)",
            .name = "apb2enr",
            .offset_bytes = 0x44,
            .reset_value = 0x00000000,
            .readable_bits = 0x00377F33,
            .writable_bits = 0x00377F33,
            /**/
        },
        {
            .desc =
            "RCC AHB1 peripheral clock enable in low power mode register (RCC_AHB1LPENR)",
            .name = "ahb1lpenr",
            .offset_bytes = 0x50,
            .reset_value = 0x7E6791FF,
            .readable_bits = 0x7E6791FF,
            .writable_bits = 0x7E6791FF,
            /**/
        },
        {
            .desc =
            "RCC AHB2 peripheral clock enable in low power mode register (RCC_AHB2LPENR)",
            .name = "ahb2lpenr",
            .offset_bytes = 0x54,
            .reset_value = 0x000000F1,
            .readable_bits = 0x000000F1,
            .writable_bits = 0x000000F1,
            /**/
        },
        {
            .desc =
            "RCC AHB3 peripheral clock enable in low power mode register (RCC_AHB3LPENR)",
            .name = "ahb3lpenr",
            .offset_bytes = 0x58,
            .reset_value = 0x00000001,
            .readable_bits = 0x00000001,
            .writable_bits = 0x00000001,
            /**/
        },
        {
            .desc =
            "RCC APB1 peripheral clock enable in low power mode register (RCC_APB1LPENR)",
            .name = "apb1lpenr",
            .offset_bytes = 0x60,
            .reset_value = 0x36FEC9FF,
            .readable_bits = 0x3EFEC9FF,
            .writable_bits = 0x3EFEC9FF,
            /**/
        },
        {
            .desc =
            "RCC APB2 peripheral clock enable in low power mode register (RCC_APB2LPENR)",
            .name = "apb2lpenr",
            .offset_bytes = 0x64,
            .reset_value = 0x00075F33,
            .readable_bits = 0x00079F33,
            .writable_bits = 0x00079F33,
            /**/
        },
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
                    .first_bit = 0,},
                {
                    .name = "lserdy",
                    .desc =
                    "External low-speed oscillator ready",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lsebyp",
                    .desc =
                    "External low-speed oscillator bypass",
                    .first_bit = 2,},
                {
                    .name = "rtcsel",
                    .desc =
                    "RTC clock source selection",
                    .first_bit = 8,
                    .width_bits = 2,},
                {
                    .name = "rtcen",
                    .desc =
                    "RTC clock enable",
                    .first_bit = 15,},
                {
                    .name = "bdrst",
                    .desc =
                    "Backup domain software reset",
                    .first_bit = 16,},
                {}, /**/
            },
            /**/
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
                    .first_bit = 0,},
                {
                    .name = "lsirdy",
                    .desc =
                    "Internal low-speed oscillator ready",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "rmvf",
                    .desc =
                    "Remove reset flag",
                    .first_bit = 24,},
                {
                    .name = "borrstf",
                    .desc =
                    "BOR reset flag",
                    .first_bit = 25,},
                {
                    .name = "pinrstf",
                    .desc =
                    "PIN reset flag",
                    .first_bit = 26,},
                {
                    .name = "porrstf",
                    .desc =
                    "POR/PDR reset flag",
                    .first_bit = 27,},
                {
                    .name = "stfrstf",
                    .desc =
                    "Software reset flag",
                    .first_bit = 28,},
                {
                    .name = "iwdgrstf",
                    .desc =
                    "Independent watchdog reset flag",
                    .first_bit = 29,},
                {
                    .name = "wwdgrstf",
                    .desc =
                    "Window watchdog reset flag",
                    .first_bit = 30,},
                {
                    .name = "lpwrrstf",
                    .desc =
                    "Low-power reset flag",
                    .first_bit = 31,},
                {}, /**/
            },
            /**/
        },
        {
            .desc =
            "RCC spread spectrum clock generation register (RCC_SSCGR)",
            .name = "sscgr",
            .offset_bytes = 0x80,
            .reset_value = 0x00000000,
            .readable_bits = 0xCEFFFFFF,
            .writable_bits = 0xCEFFFFFF,
            /**/
        },
        {
            .desc =
            "RCC PLLI2S configuration register (RCC_PLLI2SCFGR)",
            .name = "plli2scfgr",
            .offset_bytes = 0x84,
            .reset_value = 0x20003000,
            .readable_bits = 0x70007FC0,
            .writable_bits = 0x70007FC0,},
        {}, /**/
    },
    /**/
};
#endif

#if 0
static void stm32f4_01_57_rcc_create_objects(Object *obj, JSON_Value *family)
{
    // STM32RCCState *state = STM32_RCC_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family,
            "stm32f4_01_57:rcc");

    peripheral_add_properties_and_children2(obj, info);

#if 0
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
//    state->f4.fld.csr.pinrstf = cm_object_get_child_by_name(state->f4.reg.csr,
//            "pinrstf");
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
#endif
}
#endif

/* ------------------------------------------------------------------------- */

/* STM32F411xx */

#if 0
static PeripheralInfo stm32f411xx_rcc_info =
{
    .desc = "Reset and clock control (RCC)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_ALL,

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
                    .first_bit = 0,},
                {
                    .name = "hsirdy",
                    .desc =
                    "Internal high-speed clock ready flag",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsitrim",
                    .desc =
                    "Internal high-speed clock trimming",
                    .first_bit = 3,
                    .width_bits = 5,},
                {
                    .name = "hsical",
                    .desc =
                    "Internal high-speed clock calibration",
                    .first_bit = 8,
                    .width_bits = 8,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hseon",
                    .desc =
                    "External clock enable",
                    .first_bit = 16,},
                {
                    .name = "hserdy",
                    .desc =
                    "External high-speed clock ready flag",
                    .first_bit = 17,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsebyp",
                    .desc =
                    "External high-speed clock bypass",
                    .first_bit = 18,},
                {
                    .name = "csson",
                    .desc =
                    "Clock security system enable",
                    .first_bit = 19,},
                {
                    .name = "pllon",
                    .desc = "PLL enable",
                    .first_bit = 24,},
                {
                    .name = "pllrdy",
                    .desc =
                    "PLL clock ready flag",
                    .first_bit = 25,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "plli2son",
                    .desc =
                    "PLL I2S enable",
                    .first_bit = 26,},
                {
                    .name = "plli2srdy",
                    .desc =
                    "PLL I2S clock ready flag",
                    .first_bit = 27,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},

                {}, /**/
            },
            /**/
        },
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
                    .width_bits = 6,},
                {
                    .name = "plln",
                    .desc =
                    "PLL multiplication factor",
                    .first_bit = 6,
                    .width_bits = 9,},
                {
                    .name = "pllp",
                    .desc =
                    "Main PLL (PLL) division factor",
                    .first_bit = 16,
                    .width_bits = 2,},
                {
                    .name = "pllsrc",
                    .desc =
                    "Main PLL (PLL) clock source",
                    .first_bit = 22,},
                {
                    .name = "pllq",
                    .desc =
                    "Main PLL (PLL) division factor",
                    .first_bit = 24,
                    .width_bits = 4,},
                {},},
            /**/
        },
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
                    .width_bits = 2,},
                {
                    .name = "sws",
                    .desc =
                    "System clock switch status",
                    .first_bit = 2,
                    .width_bits = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hpre",
                    .desc =
                    "AHB prescaler",
                    .first_bit = 4,
                    .width_bits = 4,},
                {
                    .name = "ppre1",
                    .desc =
                    "APB Low speed prescaler (APB1)",
                    .first_bit = 10,
                    .width_bits = 3,},
                {
                    .name = "ppre2",
                    .desc =
                    "APB high speed prescaler (APB2)",
                    .first_bit = 13,
                    .width_bits = 3,},
                {
                    .name = "rtcpre",
                    .desc =
                    "HSE division factor for RTC clock",
                    .first_bit = 16,
                    .width_bits = 5,},
                {
                    .name = "mco1",
                    .desc =
                    "Microcontroller clock output 1",
                    .first_bit = 21,
                    .width_bits = 2,},
                {
                    .name = "i2ssrc",
                    .desc =
                    "I2S clock selection",
                    .first_bit = 23,},
                {
                    .name = "mco1pre",
                    .desc =
                    "MCO1 prescaller",
                    .first_bit = 24,
                    .width_bits = 3,},
                {
                    .name = "mco2pre",
                    .desc =
                    "MCO2 prescaller",
                    .first_bit = 27,
                    .width_bits = 3,},
                {
                    .name = "mco2",
                    .desc =
                    "Microcontroller clock output 2",
                    .first_bit = 30,
                    .width_bits = 2,},
                {}, /**/
            },
            /**/
        },
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
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lserdyf",
                    .desc =
                    "LSE ready interrupt flag",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsirdyf",
                    .desc =
                    "HSI ready interrupt flag",
                    .first_bit = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hserdyf",
                    .desc =
                    "HSE ready interrupt flag",
                    .first_bit = 3,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "pllrdyf",
                    .desc =
                    "PLL ready interrupt flag",
                    .first_bit = 4,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "plli2srdyf",
                    .desc =
                    "PLL I2S ready interrupt flag",
                    .first_bit = 5,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "cssf",
                    .desc =
                    "Clock security system interrupt flag",
                    .first_bit = 7,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lsirdyie",
                    .desc =
                    "LSI ready interrupt enable",
                    .first_bit = 8,},
                {
                    .name = "lserdyie",
                    .desc =
                    "LSE ready interrupt enable",
                    .first_bit = 9,},
                {
                    .name = "hsirdyie",
                    .desc =
                    "HSI ready interrupt enable",
                    .first_bit = 10,},
                {
                    .name = "hserdyie",
                    .desc =
                    "HSE ready interrupt enable",
                    .first_bit = 11,},
                {
                    .name = "pllrdyie",
                    .desc =
                    "PLL ready interrupt enable",
                    .first_bit = 12,},
                {
                    .name =
                    "plli2srdyie",
                    .desc =
                    "PLL I2S ready interrupt enable",
                    .first_bit = 13,},
                {
                    .name = "lsirdyc",
                    .desc =
                    "LSI ready interrupt clear",
                    .first_bit = 16,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "lserdyc",
                    .desc =
                    "LSE ready interrupt clear",
                    .first_bit = 17,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "hsirdyc",
                    .desc =
                    "HSI ready interrupt clear",
                    .first_bit = 18,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "hserdyc",
                    .desc =
                    "HSE ready interrupt clear",
                    .first_bit = 19,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "pllrdyc",
                    .desc =
                    "PLL ready interrupt clear",
                    .first_bit = 20,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "plli2srdyc",
                    .desc =
                    "PLL I2S ready interrupt clear",
                    .first_bit = 21,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "cssc",
                    .desc =
                    "Clock security system interrupt clear",
                    .first_bit = 23,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {}, /**/
            },
            /**/
        },
        {
            .desc =
            "RCC AHB1 peripheral reset register (RCC_AHB1RSTR)",
            .name = "ahb1rstr",
            .offset_bytes = 0x10,
            .reset_value = 0x00000000,
            .readable_bits = 0x0060109F,
            .writable_bits = 0x0060109F,
            /**/
        },
        {
            .desc =
            "RCC AHB2 peripheral reset register (RCC_AHB2RSTR)",
            .name = "ahb2rstr",
            .offset_bytes = 0x14,
            .reset_value = 0x00000000,
            .readable_bits = 0x00000080,
            .writable_bits = 0x00000080,
            /**/
        },
        {
            .desc =
            "RCC APB1 peripheral reset register (RCC_APB1RSTR)",
            .name = "apb1rstr",
            .offset_bytes = 0x20,
            .reset_value = 0x00000000,
            .readable_bits = 0x10E2C80F,
            .writable_bits = 0x10E2C80F,
            /**/
        },
        {
            .desc =
            "RCC APB2 peripheral reset register (RCC_APB2RSTR)",
            .name = "apb2rstr",
            .offset_bytes = 0x24,
            .reset_value = 0x00000000,
            .readable_bits = 0x00177931,
            .writable_bits = 0x00177931,
            /**/
        },
        {
            .desc =
            "RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)",
            .name = "ahb1enr",
            .offset_bytes = 0x30,
            .reset_value = 0x00000000,
            .readable_bits = 0x0050101F,
            .writable_bits = 0x0050101F,
            /**/
        },
        {
            .desc =
            "RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)",
            .name = "ahb2enr",
            .offset_bytes = 0x34,
            .reset_value = 0x00000000,
            .readable_bits = 0x00000080,
            .writable_bits = 0x00000080,
            /**/
        },
        {
            .desc =
            "APB1 peripheral clock enable register (RCC_APB1ENR)",
            .name = "apb1enr",
            .offset_bytes = 0x40,
            .reset_value = 0x00000000,
            .readable_bits = 0x10E2C80F,
            .writable_bits = 0x10E2C80F,
            /**/
        },
        {
            .desc =
            "APB2 peripheral clock enable register (RCC_APB2ENR)",
            .name = "apb2enr",
            .offset_bytes = 0x44,
            .reset_value = 0x00000000,
            .readable_bits = 0x00177931,
            .writable_bits = 0x00177931,
            /**/
        },
        {
            .desc =
            "RCC AHB1 peripheral clock enable in low power mode register (RCC_AHB1LPENR)",
            .name = "ahb1lpenr",
            .offset_bytes = 0x50,
            .reset_value = 0x0061900F,
            .readable_bits = 0x0061909F,
            .writable_bits = 0x0061909F,
            /**/
        },
        {
            .desc =
            "RCC AHB2 peripheral clock enable in low power mode register (RCC_AHB2LPENR)",
            .name = "ahb2lpenr",
            .offset_bytes = 0x54,
            .reset_value = 0x00000080,
            .readable_bits = 0x00000080,
            .writable_bits = 0x00000080,
            /**/
        },
        {
            .desc =
            "RCC APB1 peripheral clock enable in low power mode register (RCC_APB1LPENR)",
            .name = "apb1lpenr",
            .offset_bytes = 0x60,
            .reset_value = 0x10E2C80F,
            .readable_bits = 0x10E2C80F,
            .writable_bits = 0x10E2C80F,
            /**/
        },
        {
            .desc =
            "RCC APB2 peripheral clock enable in low power mode register (RCC_APB2LPENR)",
            .name = "apb2lpenr",
            .offset_bytes = 0x64,
            .reset_value = 0x00077930,
            .readable_bits = 0x00179F31,
            .writable_bits = 0x00179F31,
            /**/
        },
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
                    .first_bit = 0,},
                {
                    .name = "lserdy",
                    .desc =
                    "External low-speed oscillator ready",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lsebyp",
                    .desc =
                    "External low-speed oscillator bypass",
                    .first_bit = 2,},
                {
                    .name = "lsemod",
                    .desc =
                    "External low-speed oscillator bypass",
                    .first_bit = 3,},
                {
                    .name = "rtcsel",
                    .desc =
                    "RTC clock source selection",
                    .first_bit = 8,
                    .width_bits = 2,},
                {
                    .name = "rtcen",
                    .desc =
                    "RTC clock enable",
                    .first_bit = 15,},
                {
                    .name = "bdrst",
                    .desc =
                    "Backup domain software reset",
                    .first_bit = 16,},
                {}, /**/
            },
            /**/
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
                    .first_bit = 0,},
                {
                    .name = "lsirdy",
                    .desc =
                    "Internal low-speed oscillator ready",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "rmvf",
                    .desc =
                    "Remove reset flag",
                    .first_bit = 24,},
                {
                    .name = "borrstf",
                    .desc =
                    "BOR reset flag",
                    .first_bit = 25,},
                {
                    .name = "pinrstf",
                    .desc =
                    "PIN reset flag",
                    .first_bit = 26,},
                {
                    .name = "porrstf",
                    .desc =
                    "POR/PDR reset flag",
                    .first_bit = 27,},
                {
                    .name = "stfrstf",
                    .desc =
                    "Software reset flag",
                    .first_bit = 28,},
                {
                    .name = "iwdgrstf",
                    .desc =
                    "Independent watchdog reset flag",
                    .first_bit = 29,},
                {
                    .name = "wwdgrstf",
                    .desc =
                    "Window watchdog reset flag",
                    .first_bit = 30,},
                {
                    .name = "lpwrrstf",
                    .desc =
                    "Low-power reset flag",
                    .first_bit = 31,},
                {}, /**/
            },
            /**/
        },
        {
            .desc =
            "RCC spread spectrum clock generation register (RCC_SSCGR)",
            .name = "sscgr",
            .offset_bytes = 0x80,
            .reset_value = 0x00000000,
            .readable_bits = 0xE0FFFFFF,
            .writable_bits = 0xE0FFFFFF,
            /**/
        },
        {
            .desc =
            "RCC PLLI2S configuration register (RCC_PLLI2SCFGR)",
            .name = "plli2scfgr",
            .offset_bytes = 0x84,
            .reset_value = 0x24003000,
            .readable_bits = 0x70007FFF,
            .writable_bits = 0x70007FFF,
            /**/
        },
        {
            .desc =
            "RCC Dedicated Clocks Configuration Register (RCC_DCKCFGR)",
            .name = "dckcfgr",
            .offset_bytes = 0x8C,
            .reset_value = 0x00000000,
            .readable_bits = 0x01000000,
            .writable_bits = 0x01000000,
            /**/
        },
        {}, /**/
    },
    /**/
};
#endif

#if 0
static void stm32f411_rcc_create_objects(Object *obj, JSON_Value *family)
{
    // STM32RCCState *state = STM32_RCC_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family, "stm32f411:rcc");

    peripheral_add_properties_and_children2(obj, info);

#if 0
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
#endif
}
#endif

/* ------------------------------------------------------------------------- */

/* STM32F4_23_xxx */

#if 0
static PeripheralInfo stm32f4_23_xxx_rcc_info =
{
    .desc = "Reset and clock control (RCC)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_ALL,

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
                    .first_bit = 0,},
                {
                    .name = "hsirdy",
                    .desc =
                    "Internal high-speed clock ready flag",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsitrim",
                    .desc =
                    "Internal high-speed clock trimming",
                    .first_bit = 3,
                    .width_bits = 5,},
                {
                    .name = "hsical",
                    .desc =
                    "Internal high-speed clock calibration",
                    .first_bit = 8,
                    .width_bits = 8,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hseon",
                    .desc =
                    "External clock enable",
                    .first_bit = 16,},
                {
                    .name = "hserdy",
                    .desc =
                    "External high-speed clock ready flag",
                    .first_bit = 17,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsebyp",
                    .desc =
                    "External high-speed clock bypass",
                    .first_bit = 18,},
                {
                    .name = "csson",
                    .desc =
                    "Clock security system enable",
                    .first_bit = 19,},
                {
                    .name = "pllon",
                    .desc = "PLL enable",
                    .first_bit = 24,},
                {
                    .name = "pllrdy",
                    .desc =
                    "PLL clock ready flag",
                    .first_bit = 25,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "plli2son",
                    .desc =
                    "PLL I2S enable",
                    .first_bit = 26,},
                {
                    .name = "plli2srdy",
                    .desc =
                    "PLL I2S clock ready flag",
                    .first_bit = 27,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "pllsaion",
                    .desc =
                    "PLL SAI enable",
                    .first_bit = 28,},
                {
                    .name = "pllsairdy",
                    .desc =
                    "PLL SAI clock ready flag",
                    .first_bit = 29,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {}, /**/
            }, /**/},
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
                    .width_bits = 6,},
                {
                    .name = "plln",
                    .desc =
                    "PLL multiplication factor",
                    .first_bit = 6,
                    .width_bits = 9,},
                {
                    .name = "pllp",
                    .desc =
                    "Main PLL (PLL) division factor",
                    .first_bit = 16,
                    .width_bits = 2,},
                {
                    .name = "pllsrc",
                    .desc =
                    "Main PLL (PLL) clock source",
                    .first_bit = 22,},
                {
                    .name = "pllq",
                    .desc =
                    "Main PLL (PLL) division factor",
                    .first_bit = 24,
                    .width_bits = 4,},
                {},},},
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
                    .width_bits = 2,},
                {
                    .name = "sws",
                    .desc =
                    "System clock switch status",
                    .first_bit = 2,
                    .width_bits = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hpre",
                    .desc =
                    "AHB prescaler",
                    .first_bit = 4,
                    .width_bits = 4,},
                {
                    .name = "ppre1",
                    .desc =
                    "APB Low speed prescaler (APB1)",
                    .first_bit = 10,
                    .width_bits = 3,},
                {
                    .name = "ppre2",
                    .desc =
                    "APB high speed prescaler (APB2)",
                    .first_bit = 13,
                    .width_bits = 3,},
                {
                    .name = "rtcpre",
                    .desc =
                    "HSE division factor for RTC clock",
                    .first_bit = 16,
                    .width_bits = 5,},
                {
                    .name = "mco1",
                    .desc =
                    "Microcontroller clock output 1",
                    .first_bit = 21,
                    .width_bits = 2,},
                {
                    .name = "i2ssrc",
                    .desc =
                    "I2S clock selection",
                    .first_bit = 23,},
                {
                    .name = "mco1pre",
                    .desc =
                    "MCO1 prescaller",
                    .first_bit = 24,
                    .width_bits = 3,},
                {
                    .name = "mco2pre",
                    .desc =
                    "MCO2 prescaller",
                    .first_bit = 27,
                    .width_bits = 3,},
                {
                    .name = "mco2",
                    .desc =
                    "Microcontroller clock output 2",
                    .first_bit = 30,
                    .width_bits = 2,},
                {}, /**/
            }, /**/},
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
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lserdyf",
                    .desc =
                    "LSE ready interrupt flag",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hsirdyf",
                    .desc =
                    "HSI ready interrupt flag",
                    .first_bit = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "hserdyf",
                    .desc =
                    "HSE ready interrupt flag",
                    .first_bit = 3,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "pllrdyf",
                    .desc =
                    "PLL ready interrupt flag",
                    .first_bit = 4,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "plli2srdyf",
                    .desc =
                    "PLL I2S ready interrupt flag",
                    .first_bit = 5,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "pllsairdyf",
                    .desc =
                    "PLL SAI ready interrupt flag",
                    .first_bit = 6,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "cssf",
                    .desc =
                    "Clock security system interrupt flag",
                    .first_bit = 7,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lsirdyie",
                    .desc =
                    "LSI ready interrupt enable",
                    .first_bit = 8,},
                {
                    .name = "lserdyie",
                    .desc =
                    "LSE ready interrupt enable",
                    .first_bit = 9,},
                {
                    .name = "hsirdyie",
                    .desc =
                    "HSI ready interrupt enable",
                    .first_bit = 10,},
                {
                    .name = "hserdyie",
                    .desc =
                    "HSE ready interrupt enable",
                    .first_bit = 11,},
                {
                    .name = "pllrdyie",
                    .desc =
                    "PLL ready interrupt enable",
                    .first_bit = 12,},
                {
                    .name =
                    "plli2srdyie",
                    .desc =
                    "PLL I2S ready interrupt enable",
                    .first_bit = 13,},
                {
                    .name =
                    "pllsairdyie",
                    .desc =
                    "PLL SAI ready interrupt enable",
                    .first_bit = 14,},
                {
                    .name = "lsirdyc",
                    .desc =
                    "LSI ready interrupt clear",
                    .first_bit = 16,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "lserdyc",
                    .desc =
                    "LSE ready interrupt clear",
                    .first_bit = 17,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "hsirdyc",
                    .desc =
                    "HSI ready interrupt clear",
                    .first_bit = 18,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "hserdyc",
                    .desc =
                    "HSE ready interrupt clear",
                    .first_bit = 19,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "pllrdyc",
                    .desc =
                    "PLL ready interrupt clear",
                    .first_bit = 20,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "plli2srdyc",
                    .desc =
                    "PLL I2S ready interrupt clear",
                    .first_bit = 21,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "pllsairdyc",
                    .desc =
                    "PLL SAI ready interrupt clear",
                    .first_bit = 22,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "cssc",
                    .desc =
                    "Clock security system interrupt clear",
                    .first_bit = 23,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {}, /**/
            }, /**/
        },
        {
            .desc =
            "RCC AHB1 peripheral reset register (RCC_AHB1RSTR)",
            .name = "ahb1rstr",
            .offset_bytes = 0x10,
            .reset_value = 0x00000000,
            .readable_bits = 0x22E017FF,
            .writable_bits = 0x22E017FF,},
        {
            .desc =
            "RCC AHB2 peripheral reset register (RCC_AHB2RSTR)",
            .name = "ahb2rstr",
            .offset_bytes = 0x14,
            .reset_value = 0x00000000,
            .readable_bits = 0x000000F1,
            .writable_bits = 0x000000F1,},
        {
            .desc =
            "RCC AHB3 peripheral reset register (RCC_AHB3RSTR)",
            .name = "ahb3rstr",
            .offset_bytes = 0x18,
            .reset_value = 0x00000000,
            .readable_bits = 0x00000001,
            .writable_bits = 0x00000001,},
        {
            .desc =
            "RCC APB1 peripheral reset register (RCC_APB1RSTR)",
            .name = "apb1rstr",
            .offset_bytes = 0x20,
            .reset_value = 0x00000000,
            .readable_bits = 0xF6FEC9FF,
            .writable_bits = 0xF6FEC9FF,},
        {
            .desc =
            "RCC APB2 peripheral reset register (RCC_APB2RSTR)",
            .name = "apb2rstr",
            .offset_bytes = 0x24,
            .reset_value = 0x00000000,
            .readable_bits = 0x04777933,
            .writable_bits = 0x04777933,},
        {
            .desc =
            "RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)",
            .name = "ahb1enr",
            .offset_bytes = 0x30,
            .reset_value = 0x00100000,
            .readable_bits = 0x7EFC17FF,
            .writable_bits = 0x7EFC17FF,},
        {
            .desc =
            "RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)",
            .name = "ahb2enr",
            .offset_bytes = 0x34,
            .reset_value = 0x00100000,
            .readable_bits = 0x000000F1,
            .writable_bits = 0x000000F1,},
        {
            .desc =
            "RCC AHB3 peripheral clock enable register (RCC_AHB3ENR)",
            .name = "ahb3enr",
            .offset_bytes = 0x38,
            .reset_value = 0x00100000,
            .readable_bits = 0x00000001,
            .writable_bits = 0x00000001,},
        {
            .desc =
            "APB1 peripheral clock enable register (RCC_APB1ENR)",
            .name = "apb1enr",
            .offset_bytes = 0x40,
            .reset_value = 0x00000000,
            .readable_bits = 0xF6FEC9FF,
            .writable_bits = 0xF6FEC9FF,},
        {
            .desc =
            "APB2 peripheral clock enable register (RCC_APB2ENR)",
            .name = "apb2enr",
            .offset_bytes = 0x44,
            .reset_value = 0x00000000,
            .readable_bits = 0x04777F33,
            .writable_bits = 0x04777F33,},
        {
            .desc =
            "RCC AHB1 peripheral clock enable in low power mode register (RCC_AHB1LPENR)",
            .name = "ahb1lpenr",
            .offset_bytes = 0x50,
            .reset_value = 0x7E6791FF,
            .readable_bits = 0x7EEF9EFF,
            .writable_bits = 0x7EEF9EFF,},
        {
            .desc =
            "RCC AHB2 peripheral clock enable in low power mode register (RCC_AHB2LPENR)",
            .name = "ahb2lpenr",
            .offset_bytes = 0x54,
            .reset_value = 0x000000F1,
            .readable_bits = 0x000000F1,
            .writable_bits = 0x000000F1,},
        {
            .desc =
            "RCC AHB3 peripheral clock enable in low power mode register (RCC_AHB3LPENR)",
            .name = "ahb3lpenr",
            .offset_bytes = 0x58,
            .reset_value = 0x00000001,
            .readable_bits = 0x00000001,
            .writable_bits = 0x00000001,},
        {
            .desc =
            "RCC APB1 peripheral clock enable in low power mode register (RCC_APB1LPENR)",
            .name = "apb1lpenr",
            .offset_bytes = 0x60,
            .reset_value = 0x36FEC9FF,
            .readable_bits = 0xFEFEC9FF,
            .writable_bits = 0xFEFEC9FF,},
        {
            .desc =
            "RCC APB2 peripheral clock enable in low power mode register (RCC_APB2LPENR)",
            .name = "apb2lpenr",
            .offset_bytes = 0x64,
            .reset_value = 0x00075F33,
            .readable_bits = 0x04777F33,
            .writable_bits = 0x04777F33,},
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
                    .first_bit = 0,},
                {
                    .name = "lserdy",
                    .desc =
                    "External low-speed oscillator ready",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "lsebyp",
                    .desc =
                    "External low-speed oscillator bypass",
                    .first_bit = 2,},
                {
                    .name = "rtcsel",
                    .desc =
                    "RTC clock source selection",
                    .first_bit = 8,
                    .width_bits = 2,},
                {
                    .name = "rtcen",
                    .desc =
                    "RTC clock enable",
                    .first_bit = 15,},
                {
                    .name = "bdrst",
                    .desc =
                    "Backup domain software reset",
                    .first_bit = 16,},
                {}, /**/
            }, /**/
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
                    .first_bit = 0,},
                {
                    .name = "lsirdy",
                    .desc =
                    "Internal low-speed oscillator ready",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "rmvf",
                    .desc =
                    "Remove reset flag",
                    .first_bit = 24,},
                {
                    .name = "borrstf",
                    .desc =
                    "BOR reset flag",
                    .first_bit = 25,},
                {
                    .name = "pinrstf",
                    .desc =
                    "PIN reset flag",
                    .first_bit = 26,},
                {
                    .name = "porrstf",
                    .desc =
                    "POR/PDR reset flag",
                    .first_bit = 27,},
                {
                    .name = "stfrstf",
                    .desc =
                    "Software reset flag",
                    .first_bit = 28,},
                {
                    .name = "iwdgrstf",
                    .desc =
                    "Independent watchdog reset flag",
                    .first_bit = 29,},
                {
                    .name = "wwdgrstf",
                    .desc =
                    "Window watchdog reset flag",
                    .first_bit = 30,},
                {
                    .name = "lpwrrstf",
                    .desc =
                    "Low-power reset flag",
                    .first_bit = 31,},
                {}, /**/
            }, /**/
        },
        {
            .desc =
            "RCC spread spectrum clock generation register (RCC_SSCGR)",
            .name = "sscgr",
            .offset_bytes = 0x80,
            .reset_value = 0x00000000,
            .readable_bits = 0xCEFFFFFF,
            .writable_bits = 0xCEFFFFFF,},
        {
            .desc =
            "RCC PLLI2S configuration register (RCC_PLLI2SCFGR)",
            .name = "plli2scfgr",
            .offset_bytes = 0x84,
            .reset_value = 0x20003000,
            .readable_bits = 0x7F007FC0,
            .writable_bits = 0x7F007FC0,},
        {
            .desc =
            "RCC PLLSAI configuration register (RCC_PLLI2SCFGR)",
            .name = "pllsaicfgr",
            .offset_bytes = 0x88,
            .reset_value = 0x24003000,
            .readable_bits = 0x7F007FC0,
            .writable_bits = 0x7F007FC0,},
        {
            .desc =
            "RCC Dedicated Clock Configuration Register (RCC_DCKCFGR)",
            .name = "plldckcfgr",
            .offset_bytes = 0x8C,
            .reset_value = 0x00000000,
            .readable_bits = 0x01F31F1F,
            .writable_bits = 0x01F31F1F,},
        {}, /**/
    }, /**/
};
#endif

#if 0
static void stm32f4_23_x_rcc_create_objects(Object *obj, JSON_Value *family)
{
    // STM32RCCState *state = STM32_RCC_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family,
            "stm32f4_23_x:rcc");

    peripheral_add_properties_and_children2(obj, info);

#if 0
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

#endif
}
#endif

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
    9
/**/
};

extern int system_clock_scale;

/* ------------------------------------------------------------------------- */

static void stm32_rcc_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32RCCState *state = STM32_RCC_STATE(periph);
    stm32_rcc_update_clocks(state);
}

/*
 * Recompute the system clock, after each change in the RCC registers.
 * The code is inspired by CMSIS init sequences.
 */
static void stm32_rcc_update_clocks(STM32RCCState *state)
{
    const STM32Capabilities *capabilities = state->capabilities;

    uint32_t cpu_freq_hz = 0;
    uint32_t pre_scaler;

    switch (capabilities->family) {
    case STM32_FAMILY_F0:
        /* The following code was copied from the CMSIS system_stm32f0xx.c  */

        switch (register_bitfield_read_value(state->f0.fld.cfgr.sws)) {
        case 0:
            /* HSI used as system clock. */
            cpu_freq_hz = state->hsi_freq_hz;
            break;

        case 1:
            /* HSE used as system clock. */
            cpu_freq_hz = state->hse_freq_hz;
            break;

        case 2: {
            /* PLL used as system clock. */
            /* Get PLL clock source and multiplication factor. */
            uint32_t pllmul = register_bitfield_read_value(
                    state->f0.fld.cfgr.pllmul) + 2;
            uint32_t pllsrc = register_bitfield_read_value(
                    state->f0.fld.cfgr.pllsrc);

            uint32_t prediv_factor = 0;
            prediv_factor = register_bitfield_read_value(
                    state->f0.fld.cfgr2.prediv) + 1;

            switch (pllsrc) {
            case 0:
                /* HSI oscillator clock divided by 2 selected as PLL
                 * clock entry */
                cpu_freq_hz = (state->hsi_freq_hz >> 1) * pllmul;
                break;

            case 1:

                cpu_freq_hz = state->hsi_freq_hz / prediv_factor;
                break;

            case 2:
                cpu_freq_hz = state->hsi_freq_hz / prediv_factor;
                break;

            case 3:
                // HSI48/PREDIV selected as PLL input clock
                assert(false);

            }
        }
        }
        pre_scaler = AHBPrescTable[register_bitfield_read_value(
                state->f0.fld.cfgr.hpre)];
        /* HCLK frequency */
        cpu_freq_hz >>= pre_scaler;

        break;

    case STM32_FAMILY_F1:

        /* The following code was copied from the CMSIS system_stm32f10x.c  */

        switch (register_bitfield_read_value(state->f1.fld.cfgr.sws)) {
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
                        state->f1.fld.cfgr.pllmul) + 2;
                if (register_bitfield_is_zero(state->f1.fld.cfgr.pllsrc)) {
                    /* HSI oscillator clock divided by 2 selected as PLL
                     * clock entry */
                    cpu_freq_hz = (state->hsi_freq_hz >> 1) * pllmul;
                } else {
#if 0
                    if (capabilities->f1.is_ldvl || capabilities->f1.is_mdvl
                            || capabilities->f1.is_hdvl) {
                        /* The value line families use the CFGR2. */
                        uint32_t prediv1factor = 0;
                        prediv1factor = register_bitfield_read_value(
                                state->f1.fld.cfgr2.prediv1) + 1;
                        /*
                         * HSE oscillator clock selected as PREDIV1
                         * clock entry.
                         */
                        cpu_freq_hz = (state->hse_freq_hz / prediv1factor)
                        * pllmul;
                    } else {
#endif
                    /* HSE selected as PLL clock entry. */
                    if (!register_bitfield_is_zero(
                            state->f1.fld.cfgr.pllxtpre)) {
                        /* HSE oscillator clock divided by 2. */
                        cpu_freq_hz = (state->hse_freq_hz >> 1) * pllmul;
                    } else {
                        cpu_freq_hz = state->hse_freq_hz * pllmul;
                    }
#if 0
                }
#endif
                }
#if 0
            } else {
                /* The F1 CL family. */
                uint32_t pllmul = register_bitfield_read_value(
                        state->f1.fld.cfgr.pllmul);

                if (pllmul != 13) {
                    pllmul += 2;
                } else {
                    /* PLL multiplication factor = PLL input clock * 6.5 */
                    pllmul = 13 / 2;
                }

                if (register_bitfield_is_zero(state->f1.fld.cfgr.pllsrc)) {
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
                            state->f1.fld.cfgr2.prediv1) + 1;

                    if (register_bitfield_is_zero(state->f1.fld.cfgr2.prediv1src)) {
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
                                state->f1.fld.cfgr2.prediv2) + 1;
                        uint32_t pll2mull = register_bitfield_read_value(
                                state->f1.fld.cfgr2.pll2mul) + 2;
                        cpu_freq_hz = (((state->hse_freq_hz / prediv2factor)
                                        * pll2mull) / prediv1factor) * pllmul;
                    }
                }
#endif
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
                state->f1.fld.cfgr.hpre)];
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
        assert(false);
        break;
    }

    if (cpu_freq_hz == 0) {
        cpu_freq_hz = state->hsi_freq_hz; /* Should be non-zero. */
    }
    state->cpu_freq_hz = cpu_freq_hz;

    system_clock_scale = NANOSECONDS_PER_SECOND / cpu_freq_hz;
    if (system_clock_scale == 0) {
        system_clock_scale = 1;
    }
    qemu_log_mask(LOG_FUNC, "%s() %d, system_clock_scale=%d\n", __FUNCTION__,
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

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32RCCState *state = STM32_RCC_STATE(dev);
    /* First thing first: get capabilities from MCU, needed everywhere. */
    state->capabilities = mcu->capabilities;

    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "RCC";

    /* Must be defined before creating registers. */
    cm_object_property_set_int(obj, 4, "register-size-bytes");

    /* TODO: get it from MCU */
    cm_object_property_set_bool(obj, true, "is-little-endian");

    /*
     * Creating the memory region in the parent class will trigger
     * an assertion if zro address or size.
     */
    uint32_t size = 0;
    hwaddr addr = 0;

    switch (capabilities->family) {
    case STM32_FAMILY_F0:
    case STM32_FAMILY_F1:
        addr = 0x40021000;
        size = 0x400;
        break;

    case STM32_FAMILY_F4:
        addr = 0x40023800;
        size = 0x400;
        break;

    default:
        assert(false);
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
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x1) {

            stm32f0x1_rcc_create_objects(obj, cm_state->svd_json, periph_name);

            /* Add callbacks. */
            peripheral_register_set_post_write(state->f0.reg.cr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f0.reg.cfgr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f0.reg.bdcr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f0.reg.csr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f0.reg.cfgr2,
                    &stm32_rcc_post_write_callback);

            /* Auto bits. */
            cm_object_property_set_str(state->f0.fld.cr.hsirdy, "HSION",
                    "follows");
            if (state->hse_freq_hz) {
                cm_object_property_set_str(state->f0.fld.cr.hserdy, "HSEON",
                        "follows");
            }
            cm_object_property_set_str(state->f0.fld.cr.pllrdy, "PLLON",
                    "follows");

            cm_object_property_set_str(state->f0.fld.cfgr.sws, "SW", "follows");

            cm_object_property_set_str(state->f0.fld.cir.lsirdyf, "LSIRDYC",
                    "cleared-by");
            cm_object_property_set_str(state->f0.fld.cir.lserdyf, "LSERDYC",
                    "cleared-by");
            cm_object_property_set_str(state->f0.fld.cir.hsirdyf, "HSIRDYC",
                    "cleared-by");
            cm_object_property_set_str(state->f0.fld.cir.hserdyf, "HSERDYC",
                    "cleared-by");
            cm_object_property_set_str(state->f0.fld.cir.pllrdyf, "PLLRDYC",
                    "cleared-by");
            cm_object_property_set_str(state->f0.fld.cir.hsi14rdyf, "HSI14RDYF",
                    "cleared-by");
            cm_object_property_set_str(state->f0.fld.cir.hsi48rdyf, "HSI48RDYF",
                    "cleared-by");
            cm_object_property_set_str(state->f0.fld.cir.cssf, "CSSC",
                    "cleared-by");

            cm_object_property_set_str(state->f0.fld.bdcr.lserdy, "LSEON",
                    "follows");

#if 1
            cm_object_property_set_str(state->f0.fld.csr.lsirdy, "LSION",
                    "follows");
//            cm_object_property_set_str(state->f0.fld.csr.v18pwrrstf, "RMVF",
//                    "cleared-by");
            cm_object_property_set_str(state->f0.fld.csr.oblrstf, "RMVF",
                    "cleared-by");
            cm_object_property_set_str(state->f0.fld.csr.porrstf, "RMVF",
                    "cleared-by");
            cm_object_property_set_str(state->f0.fld.csr.sftrstf, "RMVF",
                    "cleared-by");
            cm_object_property_set_str(state->f0.fld.csr.iwdgrstf, "RMVF",
                    "cleared-by");
            cm_object_property_set_str(state->f0.fld.csr.wwdgrstf, "RMVF",
                    "cleared-by");
            cm_object_property_set_str(state->f0.fld.csr.lpwrrstf, "RMVF",
                    "cleared-by");
#endif
            // TODO: add CR2 actions

#if 0
        } else if (capabilities->f0.is_51xx) {

            stm32f051_rcc_create_objects(obj, mcu->family_json);

            /* Add callbacks. */
            peripheral_register_set_post_write(state->f0.reg.cr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f0.reg.cfgr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f0.reg.bdcr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f0.reg.csr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f0.reg.cfgr2,
                    &stm32_rcc_post_write_callback);

            /* Auto bits. */
            cm_object_property_set_str(state->f0.fld.cr.hsirdy, "hsion", "follows");
            if (state->hse_freq_hz != 0) {
                cm_object_property_set_str(state->f0.fld.cr.hserdy, "hseon",
                        "follows");
            }
            cm_object_property_set_str(state->f0.cr.pllrdy, "pllon", "follows");

            cm_object_property_set_str(state->f0.cfgr.sws, "sw", "follows");

            cm_object_property_set_str(state->f0.cir.lsirdyf, "lsirdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f0.cir.lserdyf, "lserdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f0.cir.hsirdyf, "hsirdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f0.cir.hserdyf, "hserdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f0.cir.pllrdyf, "pllrdyc",
                    "cleared-by");
            cm_object_property_set_str(state->f0.cir.hsi14rdyf, "hsi14rdyf",
                    "cleared-by");
            cm_object_property_set_str(state->f0.cir.hsi48rdyf, "hsi48rdyf",
                    "cleared-by");
            cm_object_property_set_str(state->f0.cir.cssf, "cssc",
                    "cleared-by");

            cm_object_property_set_str(state->f0.bdcr.lserdy, "lseon",
                    "follows");

            cm_object_property_set_str(state->f0.csr.lsirdy, "lsion",
                    "follows");
            cm_object_property_set_str(state->f0.csr.v18pwrrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f0.csr.oblrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f0.csr.porrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f0.csr.stfrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f0.csr.iwdgrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f0.csr.wwdgrstf, "rmvf",
                    "cleared-by");
            cm_object_property_set_str(state->f0.csr.lpwrrstf, "rmvf",
                    "cleared-by");

            // TODO: clear RMVF?

            // TODO: add CR2 actions
#endif
        } else {
            assert(false);
        }
        break;

    case STM32_FAMILY_F1:

        if (capabilities->f1.is_103xx) {

            stm32f103xx_rcc_create_objects(obj, cm_state->svd_json,
                    periph_name);

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
            cm_object_property_set_str(state->f1.fld.cr.hsirdy, "HSION",
                    "follows");

            if (state->hse_freq_hz) {
                cm_object_property_set_str(state->f1.fld.cr.hserdy, "HSEON",
                        "follows");
            }
            cm_object_property_set_str(state->f1.fld.cr.pllrdy, "PLLON",
                    "follows");

            cm_object_property_set_str(state->f1.fld.cfgr.sws, "SW", "follows");

            cm_object_property_set_str(state->f1.fld.cir.lsirdyf, "LSIRDYC",
                    "cleared-by");
            cm_object_property_set_str(state->f1.fld.cir.lserdyf, "LSERDYC",
                    "cleared-by");
            cm_object_property_set_str(state->f1.fld.cir.hsirdyf, "HSIRDYC",
                    "cleared-by");
            cm_object_property_set_str(state->f1.fld.cir.hserdyf, "HSERDYC",
                    "cleared-by");
            cm_object_property_set_str(state->f1.fld.cir.pllrdyf, "PLLRDYC",
                    "cleared-by");
            cm_object_property_set_str(state->f1.fld.cir.cssf, "CSSC",
                    "cleared-by");

            cm_object_property_set_str(state->f1.fld.bdcr.lserdy, "LSEON",
                    "follows");

            cm_object_property_set_str(state->f1.fld.csr.lsirdy, "LSION",
                    "follows");
            cm_object_property_set_str(state->f1.fld.csr.pinrstf, "RMVF",
                    "cleared-by");
            cm_object_property_set_str(state->f1.fld.csr.porrstf, "RMVF",
                    "cleared-by");
            cm_object_property_set_str(state->f1.fld.csr.sftrstf, "RMVF",
                    "cleared-by");
            cm_object_property_set_str(state->f1.fld.csr.iwdgrstf, "RMVF",
                    "cleared-by");
            cm_object_property_set_str(state->f1.fld.csr.wwdgrstf, "RMVF",
                    "cleared-by");
            cm_object_property_set_str(state->f1.fld.csr.lpwrrstf, "RMVF",
                    "cleared-by");

#if 0
        } else if (capabilities->f1.is_hd || capabilities->f1.is_hdvl
                || capabilities->f1.is_ld || capabilities->f1.is_ldvl
                || capabilities->f1.is_md || capabilities->f1.is_mdvl
                || capabilities->f1.is_xd) {

            stm32f1xx_rcc_create_objects(obj, mcu->family_json);

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

        } else if (capabilities->f1.is_cl) {

            stm32f1cl_rcc_create_objects(obj, mcu->family_json);

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
#endif
        } else {
            assert(false);
        }

        break;

    case STM32_FAMILY_F4:

        if (capabilities->f4.is_40x) {

            stm32f40x_rcc_create_objects(obj, cm_state->svd_json, periph_name);

            /* Add callbacks. */
            peripheral_register_set_post_write(state->f4.reg.pllcfgr,
                    &stm32_rcc_post_write_callback);
            peripheral_register_set_post_write(state->f4.reg.cfgr,
                    &stm32_rcc_post_write_callback);

            /* Auto bits. */
            cm_object_property_set_str(state->f4.fld.cr.hsirdy, "HSION",
                    "follows");
            if (state->hse_freq_hz) {
                cm_object_property_set_str(state->f4.fld.cr.hserdy, "HSEON",
                        "follows");
            }
            cm_object_property_set_str(state->f4.fld.cr.pllrdy, "PLLON",
                    "follows");
            cm_object_property_set_str(state->f4.fld.cr.plli2srdy, "PLLI2SON",
                    "follows");

            cm_object_property_set_str(state->f4.fld.cfgr.sws, "SW", "follows");

            cm_object_property_set_str(state->f4.fld.cir.lsirdyf, "LSIRDYC",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.lserdyf, "LSERDYC",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.hsirdyf, "HSIRDYC",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.hserdyf, "HSERDYC",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.pllrdyf, "PLLRDYC",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.plli2srdyf,
                    "PLLI2SRDYC", "cleared-by");
            cm_object_property_set_str(state->f4.fld.cir.cssf, "CSSC",
                    "cleared-by");

            cm_object_property_set_str(state->f4.fld.bdcr.lserdy, "LSEON",
                    "follows");

#if 1
            cm_object_property_set_str(state->f4.fld.csr.lsirdy, "LSION",
                    "follows");
            cm_object_property_set_str(state->f4.fld.csr.padrstf, "RMVF",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.borrstf, "RMVF",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.porrstf, "RMVF",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.sftrstf, "RMVF",
                    "cleared-by");
            // Errata: The RM0090 manual refers to wdgrstf as IWDGRSTF
            cm_object_property_set_str(state->f4.fld.csr.wdgrstf, "RMVF",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.wwdgrstf, "RMVF",
                    "cleared-by");
            cm_object_property_set_str(state->f4.fld.csr.lpwrrstf, "RMVF",
                    "cleared-by");
#endif

#if 0
        } else if (capabilities->f4.is_01_57_xx) {

            stm32f4_01_57_rcc_create_objects(obj, mcu->family_json);

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

#if 0
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
#endif
        } else if (capabilities->f4.is11xx) {

            stm32f411_rcc_create_objects(obj, mcu->family_json);

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

#if 0
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
#endif
        } else if (capabilities->f4.is_23_xxx) {

            stm32f4_23_x_rcc_create_objects(obj, mcu->family_json);

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

#if 0
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
#endif
#endif
        } else {
            assert(false);
        }

        break;

    default:
        assert(false);
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

#if 0
    peripheral_serialize_info("f051-rcc.json", "stm32f051:rcc", &stm32f051xx_rcc_info);
    peripheral_serialize_info("f1xx-rcc.json", "stm32f1xx:rcc", &stm32f1_rcc_info);
    peripheral_serialize_info("f1cl-rcc.json", "stm32f1cl:rcc", &stm32f1cl_rcc_info);

    peripheral_serialize_info("f4_01_57-rcc.json", "stm32f4_01_57:rcc", &stm32f4_01_57_xx_rcc_info);
    peripheral_serialize_info("f4_23_x-rcc.json", "stm32f4_23_x:rcc", &stm32f4_23_xxx_rcc_info);
    peripheral_serialize_info("f411-rcc.json", "stm32f411:rcc", &stm32f411xx_rcc_info);
#endif
}

type_init(stm32_rcc_register_types);

/* ------------------------------------------------------------------------- */
