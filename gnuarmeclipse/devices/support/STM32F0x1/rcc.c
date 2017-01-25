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

#include <hw/cortexm/stm32/rcc.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_rcc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32RCCState *state = STM32_RCC_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->u.f0.reg.cfgr = cm_object_get_child_by_name(obj, "CFGR");
    state->u.f0.reg.cir = cm_object_get_child_by_name(obj, "CIR");
    state->u.f0.reg.apb2rstr = cm_object_get_child_by_name(obj, "APB2RSTR");
    state->u.f0.reg.apb1rstr = cm_object_get_child_by_name(obj, "APB1RSTR");
    state->u.f0.reg.ahbenr = cm_object_get_child_by_name(obj, "AHBENR");
    state->u.f0.reg.apb2enr = cm_object_get_child_by_name(obj, "APB2ENR");
    state->u.f0.reg.apb1enr = cm_object_get_child_by_name(obj, "APB1ENR");
    state->u.f0.reg.bdcr = cm_object_get_child_by_name(obj, "BDCR");
    state->u.f0.reg.csr = cm_object_get_child_by_name(obj, "CSR");
    state->u.f0.reg.ahbrstr = cm_object_get_child_by_name(obj, "AHBRSTR");
    state->u.f0.reg.cfgr2 = cm_object_get_child_by_name(obj, "CFGR2");
    state->u.f0.reg.cfgr3 = cm_object_get_child_by_name(obj, "CFGR3");
    state->u.f0.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
    
    
    // CR bitfields.
    state->u.f0.fld.cr.hsion = cm_object_get_child_by_name(state->u.f0.reg.cr, "HSION"); 
    state->u.f0.fld.cr.hsirdy = cm_object_get_child_by_name(state->u.f0.reg.cr, "HSIRDY"); 
    state->u.f0.fld.cr.hsitrim = cm_object_get_child_by_name(state->u.f0.reg.cr, "HSITRIM"); 
    state->u.f0.fld.cr.hsical = cm_object_get_child_by_name(state->u.f0.reg.cr, "HSICAL"); 
    state->u.f0.fld.cr.hseon = cm_object_get_child_by_name(state->u.f0.reg.cr, "HSEON"); 
    state->u.f0.fld.cr.hserdy = cm_object_get_child_by_name(state->u.f0.reg.cr, "HSERDY"); 
    state->u.f0.fld.cr.hsebyp = cm_object_get_child_by_name(state->u.f0.reg.cr, "HSEBYP"); 
    state->u.f0.fld.cr.csson = cm_object_get_child_by_name(state->u.f0.reg.cr, "CSSON"); 
    state->u.f0.fld.cr.pllon = cm_object_get_child_by_name(state->u.f0.reg.cr, "PLLON"); 
    state->u.f0.fld.cr.pllrdy = cm_object_get_child_by_name(state->u.f0.reg.cr, "PLLRDY");  
    
    // CFGR bitfields.
    state->u.f0.fld.cfgr.sw = cm_object_get_child_by_name(state->u.f0.reg.cfgr, "SW"); 
    state->u.f0.fld.cfgr.sws = cm_object_get_child_by_name(state->u.f0.reg.cfgr, "SWS"); 
    state->u.f0.fld.cfgr.hpre = cm_object_get_child_by_name(state->u.f0.reg.cfgr, "HPRE"); 
    state->u.f0.fld.cfgr.ppre = cm_object_get_child_by_name(state->u.f0.reg.cfgr, "PPRE"); 
    state->u.f0.fld.cfgr.adcpre = cm_object_get_child_by_name(state->u.f0.reg.cfgr, "ADCPRE"); 
    state->u.f0.fld.cfgr.pllsrc = cm_object_get_child_by_name(state->u.f0.reg.cfgr, "PLLSRC"); 
    state->u.f0.fld.cfgr.pllxtpre = cm_object_get_child_by_name(state->u.f0.reg.cfgr, "PLLXTPRE"); 
    state->u.f0.fld.cfgr.pllmul = cm_object_get_child_by_name(state->u.f0.reg.cfgr, "PLLMUL"); 
    state->u.f0.fld.cfgr.mco = cm_object_get_child_by_name(state->u.f0.reg.cfgr, "MCO"); 
    state->u.f0.fld.cfgr.mcopre = cm_object_get_child_by_name(state->u.f0.reg.cfgr, "MCOPRE"); 
    state->u.f0.fld.cfgr.pllnodiv = cm_object_get_child_by_name(state->u.f0.reg.cfgr, "PLLNODIV");  
    
    // CIR bitfields.
    state->u.f0.fld.cir.lsirdyf = cm_object_get_child_by_name(state->u.f0.reg.cir, "LSIRDYF"); 
    state->u.f0.fld.cir.lserdyf = cm_object_get_child_by_name(state->u.f0.reg.cir, "LSERDYF"); 
    state->u.f0.fld.cir.hsirdyf = cm_object_get_child_by_name(state->u.f0.reg.cir, "HSIRDYF"); 
    state->u.f0.fld.cir.hserdyf = cm_object_get_child_by_name(state->u.f0.reg.cir, "HSERDYF"); 
    state->u.f0.fld.cir.pllrdyf = cm_object_get_child_by_name(state->u.f0.reg.cir, "PLLRDYF"); 
    state->u.f0.fld.cir.hsi14rdyf = cm_object_get_child_by_name(state->u.f0.reg.cir, "HSI14RDYF"); 
    state->u.f0.fld.cir.hsi48rdyf = cm_object_get_child_by_name(state->u.f0.reg.cir, "HSI48RDYF"); 
    state->u.f0.fld.cir.cssf = cm_object_get_child_by_name(state->u.f0.reg.cir, "CSSF"); 
    state->u.f0.fld.cir.lsirdyie = cm_object_get_child_by_name(state->u.f0.reg.cir, "LSIRDYIE"); 
    state->u.f0.fld.cir.lserdyie = cm_object_get_child_by_name(state->u.f0.reg.cir, "LSERDYIE"); 
    state->u.f0.fld.cir.hsirdyie = cm_object_get_child_by_name(state->u.f0.reg.cir, "HSIRDYIE"); 
    state->u.f0.fld.cir.hserdyie = cm_object_get_child_by_name(state->u.f0.reg.cir, "HSERDYIE"); 
    state->u.f0.fld.cir.pllrdyie = cm_object_get_child_by_name(state->u.f0.reg.cir, "PLLRDYIE"); 
    state->u.f0.fld.cir.hsi14rdye = cm_object_get_child_by_name(state->u.f0.reg.cir, "HSI14RDYE"); 
    state->u.f0.fld.cir.hsi48rdyie = cm_object_get_child_by_name(state->u.f0.reg.cir, "HSI48RDYIE"); 
    state->u.f0.fld.cir.lsirdyc = cm_object_get_child_by_name(state->u.f0.reg.cir, "LSIRDYC"); 
    state->u.f0.fld.cir.lserdyc = cm_object_get_child_by_name(state->u.f0.reg.cir, "LSERDYC"); 
    state->u.f0.fld.cir.hsirdyc = cm_object_get_child_by_name(state->u.f0.reg.cir, "HSIRDYC"); 
    state->u.f0.fld.cir.hserdyc = cm_object_get_child_by_name(state->u.f0.reg.cir, "HSERDYC"); 
    state->u.f0.fld.cir.pllrdyc = cm_object_get_child_by_name(state->u.f0.reg.cir, "PLLRDYC"); 
    state->u.f0.fld.cir.hsi14rdyc = cm_object_get_child_by_name(state->u.f0.reg.cir, "HSI14RDYC"); 
    state->u.f0.fld.cir.hsi48rdyc = cm_object_get_child_by_name(state->u.f0.reg.cir, "HSI48RDYC"); 
    state->u.f0.fld.cir.cssc = cm_object_get_child_by_name(state->u.f0.reg.cir, "CSSC");  
    
    // APB2RSTR bitfields.
    state->u.f0.fld.apb2rstr.syscfgrst = cm_object_get_child_by_name(state->u.f0.reg.apb2rstr, "SYSCFGRST"); 
    state->u.f0.fld.apb2rstr.adcrst = cm_object_get_child_by_name(state->u.f0.reg.apb2rstr, "ADCRST"); 
    state->u.f0.fld.apb2rstr.tim1rst = cm_object_get_child_by_name(state->u.f0.reg.apb2rstr, "TIM1RST"); 
    state->u.f0.fld.apb2rstr.spi1rst = cm_object_get_child_by_name(state->u.f0.reg.apb2rstr, "SPI1RST"); 
    state->u.f0.fld.apb2rstr.usart1rst = cm_object_get_child_by_name(state->u.f0.reg.apb2rstr, "USART1RST"); 
    state->u.f0.fld.apb2rstr.tim15rst = cm_object_get_child_by_name(state->u.f0.reg.apb2rstr, "TIM15RST"); 
    state->u.f0.fld.apb2rstr.tim16rst = cm_object_get_child_by_name(state->u.f0.reg.apb2rstr, "TIM16RST"); 
    state->u.f0.fld.apb2rstr.tim17rst = cm_object_get_child_by_name(state->u.f0.reg.apb2rstr, "TIM17RST"); 
    state->u.f0.fld.apb2rstr.dbgmcurst = cm_object_get_child_by_name(state->u.f0.reg.apb2rstr, "DBGMCURST");  
    
    // APB1RSTR bitfields.
    state->u.f0.fld.apb1rstr.tim2rst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "TIM2RST"); 
    state->u.f0.fld.apb1rstr.tim3rst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "TIM3RST"); 
    state->u.f0.fld.apb1rstr.tim6rst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "TIM6RST"); 
    state->u.f0.fld.apb1rstr.tim7rst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "TIM7RST"); 
    state->u.f0.fld.apb1rstr.tim14rst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "TIM14RST"); 
    state->u.f0.fld.apb1rstr.wwdgrst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "WWDGRST"); 
    state->u.f0.fld.apb1rstr.spi2rst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "SPI2RST"); 
    state->u.f0.fld.apb1rstr.usart2rst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "USART2RST"); 
    state->u.f0.fld.apb1rstr.usart3rst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "USART3RST"); 
    state->u.f0.fld.apb1rstr.usart4rst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "USART4RST"); 
    state->u.f0.fld.apb1rstr.usart5rst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "USART5RST"); 
    state->u.f0.fld.apb1rstr.i2c1rst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "I2C1RST"); 
    state->u.f0.fld.apb1rstr.i2c2rst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "I2C2RST"); 
    state->u.f0.fld.apb1rstr.usbrst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "USBRST"); 
    state->u.f0.fld.apb1rstr.canrst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "CANRST"); 
    state->u.f0.fld.apb1rstr.crsrst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "CRSRST"); 
    state->u.f0.fld.apb1rstr.pwrrst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "PWRRST"); 
    state->u.f0.fld.apb1rstr.dacrst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "DACRST"); 
    state->u.f0.fld.apb1rstr.cecrst = cm_object_get_child_by_name(state->u.f0.reg.apb1rstr, "CECRST");  
    
    // AHBENR bitfields.
    state->u.f0.fld.ahbenr.dma1en = cm_object_get_child_by_name(state->u.f0.reg.ahbenr, "DMA1EN"); 
    state->u.f0.fld.ahbenr.dma2en = cm_object_get_child_by_name(state->u.f0.reg.ahbenr, "DMA2EN"); 
    state->u.f0.fld.ahbenr.sramen = cm_object_get_child_by_name(state->u.f0.reg.ahbenr, "SRAMEN"); 
    state->u.f0.fld.ahbenr.flitfen = cm_object_get_child_by_name(state->u.f0.reg.ahbenr, "FLITFEN"); 
    state->u.f0.fld.ahbenr.crcen = cm_object_get_child_by_name(state->u.f0.reg.ahbenr, "CRCEN"); 
    state->u.f0.fld.ahbenr.iopaen = cm_object_get_child_by_name(state->u.f0.reg.ahbenr, "IOPAEN"); 
    state->u.f0.fld.ahbenr.iopben = cm_object_get_child_by_name(state->u.f0.reg.ahbenr, "IOPBEN"); 
    state->u.f0.fld.ahbenr.iopcen = cm_object_get_child_by_name(state->u.f0.reg.ahbenr, "IOPCEN"); 
    state->u.f0.fld.ahbenr.iopden = cm_object_get_child_by_name(state->u.f0.reg.ahbenr, "IOPDEN"); 
    state->u.f0.fld.ahbenr.iopfen = cm_object_get_child_by_name(state->u.f0.reg.ahbenr, "IOPFEN"); 
    state->u.f0.fld.ahbenr.tscen = cm_object_get_child_by_name(state->u.f0.reg.ahbenr, "TSCEN");  
    
    // APB2ENR bitfields.
    state->u.f0.fld.apb2enr.syscfgen = cm_object_get_child_by_name(state->u.f0.reg.apb2enr, "SYSCFGEN"); 
    state->u.f0.fld.apb2enr.adcen = cm_object_get_child_by_name(state->u.f0.reg.apb2enr, "ADCEN"); 
    state->u.f0.fld.apb2enr.tim1en = cm_object_get_child_by_name(state->u.f0.reg.apb2enr, "TIM1EN"); 
    state->u.f0.fld.apb2enr.spi1en = cm_object_get_child_by_name(state->u.f0.reg.apb2enr, "SPI1EN"); 
    state->u.f0.fld.apb2enr.usart1en = cm_object_get_child_by_name(state->u.f0.reg.apb2enr, "USART1EN"); 
    state->u.f0.fld.apb2enr.tim15en = cm_object_get_child_by_name(state->u.f0.reg.apb2enr, "TIM15EN"); 
    state->u.f0.fld.apb2enr.tim16en = cm_object_get_child_by_name(state->u.f0.reg.apb2enr, "TIM16EN"); 
    state->u.f0.fld.apb2enr.tim17en = cm_object_get_child_by_name(state->u.f0.reg.apb2enr, "TIM17EN"); 
    state->u.f0.fld.apb2enr.dbgmcuen = cm_object_get_child_by_name(state->u.f0.reg.apb2enr, "DBGMCUEN");  
    
    // APB1ENR bitfields.
    state->u.f0.fld.apb1enr.tim2en = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "TIM2EN"); 
    state->u.f0.fld.apb1enr.tim3en = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "TIM3EN"); 
    state->u.f0.fld.apb1enr.tim6en = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "TIM6EN"); 
    state->u.f0.fld.apb1enr.tim7en = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "TIM7EN"); 
    state->u.f0.fld.apb1enr.tim14en = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "TIM14EN"); 
    state->u.f0.fld.apb1enr.wwdgen = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "WWDGEN"); 
    state->u.f0.fld.apb1enr.spi2en = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "SPI2EN"); 
    state->u.f0.fld.apb1enr.usart2en = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "USART2EN"); 
    state->u.f0.fld.apb1enr.usart3en = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "USART3EN"); 
    state->u.f0.fld.apb1enr.usart4en = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "USART4EN"); 
    state->u.f0.fld.apb1enr.usart5en = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "USART5EN"); 
    state->u.f0.fld.apb1enr.i2c1en = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "I2C1EN"); 
    state->u.f0.fld.apb1enr.i2c2en = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "I2C2EN"); 
    state->u.f0.fld.apb1enr.usbrst = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "USBRST"); 
    state->u.f0.fld.apb1enr.canen = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "CANEN"); 
    state->u.f0.fld.apb1enr.crsen = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "CRSEN"); 
    state->u.f0.fld.apb1enr.pwren = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "PWREN"); 
    state->u.f0.fld.apb1enr.dacen = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "DACEN"); 
    state->u.f0.fld.apb1enr.cecen = cm_object_get_child_by_name(state->u.f0.reg.apb1enr, "CECEN");  
    
    // BDCR bitfields.
    state->u.f0.fld.bdcr.lseon = cm_object_get_child_by_name(state->u.f0.reg.bdcr, "LSEON"); 
    state->u.f0.fld.bdcr.lserdy = cm_object_get_child_by_name(state->u.f0.reg.bdcr, "LSERDY"); 
    state->u.f0.fld.bdcr.lsebyp = cm_object_get_child_by_name(state->u.f0.reg.bdcr, "LSEBYP"); 
    state->u.f0.fld.bdcr.lsedrv = cm_object_get_child_by_name(state->u.f0.reg.bdcr, "LSEDRV"); 
    state->u.f0.fld.bdcr.rtcsel = cm_object_get_child_by_name(state->u.f0.reg.bdcr, "RTCSEL"); 
    state->u.f0.fld.bdcr.rtcen = cm_object_get_child_by_name(state->u.f0.reg.bdcr, "RTCEN"); 
    state->u.f0.fld.bdcr.bdrst = cm_object_get_child_by_name(state->u.f0.reg.bdcr, "BDRST");  
    
    // CSR bitfields.
    state->u.f0.fld.csr.lsion = cm_object_get_child_by_name(state->u.f0.reg.csr, "LSION"); 
    state->u.f0.fld.csr.lsirdy = cm_object_get_child_by_name(state->u.f0.reg.csr, "LSIRDY"); 
    state->u.f0.fld.csr.rmvf = cm_object_get_child_by_name(state->u.f0.reg.csr, "RMVF"); 
    state->u.f0.fld.csr.oblrstf = cm_object_get_child_by_name(state->u.f0.reg.csr, "OBLRSTF"); 
    state->u.f0.fld.csr.pinrstf = cm_object_get_child_by_name(state->u.f0.reg.csr, "PINRSTF"); 
    state->u.f0.fld.csr.porrstf = cm_object_get_child_by_name(state->u.f0.reg.csr, "PORRSTF"); 
    state->u.f0.fld.csr.sftrstf = cm_object_get_child_by_name(state->u.f0.reg.csr, "SFTRSTF"); 
    state->u.f0.fld.csr.iwdgrstf = cm_object_get_child_by_name(state->u.f0.reg.csr, "IWDGRSTF"); 
    state->u.f0.fld.csr.wwdgrstf = cm_object_get_child_by_name(state->u.f0.reg.csr, "WWDGRSTF"); 
    state->u.f0.fld.csr.lpwrrstf = cm_object_get_child_by_name(state->u.f0.reg.csr, "LPWRRSTF");  
    
    // AHBRSTR bitfields.
    state->u.f0.fld.ahbrstr.ioparst = cm_object_get_child_by_name(state->u.f0.reg.ahbrstr, "IOPARST"); 
    state->u.f0.fld.ahbrstr.iopbrst = cm_object_get_child_by_name(state->u.f0.reg.ahbrstr, "IOPBRST"); 
    state->u.f0.fld.ahbrstr.iopcrst = cm_object_get_child_by_name(state->u.f0.reg.ahbrstr, "IOPCRST"); 
    state->u.f0.fld.ahbrstr.iopdrst = cm_object_get_child_by_name(state->u.f0.reg.ahbrstr, "IOPDRST"); 
    state->u.f0.fld.ahbrstr.iopfrst = cm_object_get_child_by_name(state->u.f0.reg.ahbrstr, "IOPFRST"); 
    state->u.f0.fld.ahbrstr.tscrst = cm_object_get_child_by_name(state->u.f0.reg.ahbrstr, "TSCRST");  
    
    // CFGR2 bitfields.
    state->u.f0.fld.cfgr2.prediv = cm_object_get_child_by_name(state->u.f0.reg.cfgr2, "PREDIV");  
    
    // CFGR3 bitfields.
    state->u.f0.fld.cfgr3.usart1sw = cm_object_get_child_by_name(state->u.f0.reg.cfgr3, "USART1SW"); 
    state->u.f0.fld.cfgr3.i2c1sw = cm_object_get_child_by_name(state->u.f0.reg.cfgr3, "I2C1SW"); 
    state->u.f0.fld.cfgr3.cecsw = cm_object_get_child_by_name(state->u.f0.reg.cfgr3, "CECSW"); 
    state->u.f0.fld.cfgr3.usbsw = cm_object_get_child_by_name(state->u.f0.reg.cfgr3, "USBSW"); 
    state->u.f0.fld.cfgr3.adcsw = cm_object_get_child_by_name(state->u.f0.reg.cfgr3, "ADCSW"); 
    state->u.f0.fld.cfgr3.usart2sw = cm_object_get_child_by_name(state->u.f0.reg.cfgr3, "USART2SW");  
    
    // CR2 bitfields.
    state->u.f0.fld.cr2.hsi14on = cm_object_get_child_by_name(state->u.f0.reg.cr2, "HSI14ON"); 
    state->u.f0.fld.cr2.hsi14rdy = cm_object_get_child_by_name(state->u.f0.reg.cr2, "HSI14RDY"); 
    state->u.f0.fld.cr2.hsi14dis = cm_object_get_child_by_name(state->u.f0.reg.cr2, "HSI14DIS"); 
    state->u.f0.fld.cr2.hsi14trim = cm_object_get_child_by_name(state->u.f0.reg.cr2, "HSI14TRIM"); 
    state->u.f0.fld.cr2.hsi14cal = cm_object_get_child_by_name(state->u.f0.reg.cr2, "HSI14CAL"); 
    state->u.f0.fld.cr2.hsi48on = cm_object_get_child_by_name(state->u.f0.reg.cr2, "HSI48ON"); 
    state->u.f0.fld.cr2.hsi48rdy = cm_object_get_child_by_name(state->u.f0.reg.cr2, "HSI48RDY"); 
    state->u.f0.fld.cr2.hsi48cal = cm_object_get_child_by_name(state->u.f0.reg.cr2, "HSI48CAL");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_rcc_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32RCCState *state = STM32_RCC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_rcc_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32RCCState *state = STM32_RCC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_rcc_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32RCCState *state = STM32_RCC_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_rcc_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32RCCState *state = STM32_RCC_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_rcc_is_enabled(Object *obj)
{
    STM32RCCState *state = STM32_RCC_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_rcc_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32RCCState *state = STM32_RCC_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_rcc_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_RCC)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32RCCState *state = STM32_RCC_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "RCC";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x1 ) {

            stm32f0x1_rcc_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_rcc_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f0.reg.xxx, &stm32_rcc_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_rcc_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f0.reg.xxx, &stm32_rcc_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/RCCEN");


        } else {
            assert(false);
        }

        break;

    default:
        assert(false);
        break;
    }

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = OBJECT(cm_device_by_name(enabling_bit_name));

    peripheral_prepare_registers(obj);
}

static void stm32_rcc_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_RCC);
}

static void stm32_rcc_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_rcc_reset_callback;
    dc->realize = stm32_rcc_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_rcc_is_enabled;
}

static const TypeInfo stm32_rcc_type_info = {
    .name = TYPE_STM32_RCC,
    .parent = TYPE_STM32_RCC_PARENT,
    .instance_init = stm32_rcc_instance_init_callback,
    .instance_size = sizeof(STM32RCCState),
    .class_init = stm32_rcc_class_init_callback,
    .class_size = sizeof(STM32RCCClass) };

static void stm32_rcc_register_types(void)
{
    type_register_static(&stm32_rcc_type_info);
}

type_init(stm32_rcc_register_types);

// ----------------------------------------------------------------------------
