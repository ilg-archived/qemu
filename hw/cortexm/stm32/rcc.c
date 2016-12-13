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

/*
 * For all other peripherals,
 * when the peripheral clock is not active,
 * the peripheral register values may not
 * be readable by software and the returned
 * value is always 0x0. */

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

// ----------------------------------------------------------------------------

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

static void stm32_rcc_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32RCCState *state = STM32_RCC_STATE(periph);
    stm32_rcc_update_clocks(state);
}

// ----------------------------------------------------------------------------

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

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);

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

static void stm32_rcc_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    dc->reset = stm32_rcc_reset_callback;
    dc->realize = stm32_rcc_realize_callback;
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

// ----------------------------------------------------------------------------
