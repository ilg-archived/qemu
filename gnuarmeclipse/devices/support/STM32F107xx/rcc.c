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
static void stm32f107xx_rcc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32RCCState *state = STM32_RCC_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f1.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->u.f1.reg.cfgr = cm_object_get_child_by_name(obj, "CFGR");
    state->u.f1.reg.cir = cm_object_get_child_by_name(obj, "CIR");
    state->u.f1.reg.apb2rstr = cm_object_get_child_by_name(obj, "APB2RSTR");
    state->u.f1.reg.apb1rstr = cm_object_get_child_by_name(obj, "APB1RSTR");
    state->u.f1.reg.ahbenr = cm_object_get_child_by_name(obj, "AHBENR");
    state->u.f1.reg.apb2enr = cm_object_get_child_by_name(obj, "APB2ENR");
    state->u.f1.reg.apb1enr = cm_object_get_child_by_name(obj, "APB1ENR");
    state->u.f1.reg.bdcr = cm_object_get_child_by_name(obj, "BDCR");
    state->u.f1.reg.csr = cm_object_get_child_by_name(obj, "CSR");
    state->u.f1.reg.ahbrstr = cm_object_get_child_by_name(obj, "AHBRSTR");
    state->u.f1.reg.cfgr2 = cm_object_get_child_by_name(obj, "CFGR2");
    
    
    // CR bitfields.
    state->u.f1.fld.cr.hsion = cm_object_get_child_by_name(state->u.f1.reg.cr, "HSION"); 
    state->u.f1.fld.cr.hsirdy = cm_object_get_child_by_name(state->u.f1.reg.cr, "HSIRDY"); 
    state->u.f1.fld.cr.hsitrim = cm_object_get_child_by_name(state->u.f1.reg.cr, "HSITRIM"); 
    state->u.f1.fld.cr.hsical = cm_object_get_child_by_name(state->u.f1.reg.cr, "HSICAL"); 
    state->u.f1.fld.cr.hseon = cm_object_get_child_by_name(state->u.f1.reg.cr, "HSEON"); 
    state->u.f1.fld.cr.hserdy = cm_object_get_child_by_name(state->u.f1.reg.cr, "HSERDY"); 
    state->u.f1.fld.cr.hsebyp = cm_object_get_child_by_name(state->u.f1.reg.cr, "HSEBYP"); 
    state->u.f1.fld.cr.csson = cm_object_get_child_by_name(state->u.f1.reg.cr, "CSSON"); 
    state->u.f1.fld.cr.pllon = cm_object_get_child_by_name(state->u.f1.reg.cr, "PLLON"); 
    state->u.f1.fld.cr.pllrdy = cm_object_get_child_by_name(state->u.f1.reg.cr, "PLLRDY"); 
    state->u.f1.fld.cr.pll2on = cm_object_get_child_by_name(state->u.f1.reg.cr, "PLL2ON"); 
    state->u.f1.fld.cr.pll2rdy = cm_object_get_child_by_name(state->u.f1.reg.cr, "PLL2RDY"); 
    state->u.f1.fld.cr.pll3on = cm_object_get_child_by_name(state->u.f1.reg.cr, "PLL3ON"); 
    state->u.f1.fld.cr.pll3rdy = cm_object_get_child_by_name(state->u.f1.reg.cr, "PLL3RDY");  
    
    // CFGR bitfields.
    state->u.f1.fld.cfgr.sw = cm_object_get_child_by_name(state->u.f1.reg.cfgr, "SW"); 
    state->u.f1.fld.cfgr.sws = cm_object_get_child_by_name(state->u.f1.reg.cfgr, "SWS"); 
    state->u.f1.fld.cfgr.hpre = cm_object_get_child_by_name(state->u.f1.reg.cfgr, "HPRE"); 
    state->u.f1.fld.cfgr.ppre1 = cm_object_get_child_by_name(state->u.f1.reg.cfgr, "PPRE1"); 
    state->u.f1.fld.cfgr.ppre2 = cm_object_get_child_by_name(state->u.f1.reg.cfgr, "PPRE2"); 
    state->u.f1.fld.cfgr.adcpre = cm_object_get_child_by_name(state->u.f1.reg.cfgr, "ADCPRE"); 
    state->u.f1.fld.cfgr.pllsrc = cm_object_get_child_by_name(state->u.f1.reg.cfgr, "PLLSRC"); 
    state->u.f1.fld.cfgr.pllxtpre = cm_object_get_child_by_name(state->u.f1.reg.cfgr, "PLLXTPRE"); 
    state->u.f1.fld.cfgr.pllmul = cm_object_get_child_by_name(state->u.f1.reg.cfgr, "PLLMUL"); 
    state->u.f1.fld.cfgr.otgfspre = cm_object_get_child_by_name(state->u.f1.reg.cfgr, "OTGFSPRE"); 
    state->u.f1.fld.cfgr.mco = cm_object_get_child_by_name(state->u.f1.reg.cfgr, "MCO");  
    
    // CIR bitfields.
    state->u.f1.fld.cir.lsirdyf = cm_object_get_child_by_name(state->u.f1.reg.cir, "LSIRDYF"); 
    state->u.f1.fld.cir.lserdyf = cm_object_get_child_by_name(state->u.f1.reg.cir, "LSERDYF"); 
    state->u.f1.fld.cir.hsirdyf = cm_object_get_child_by_name(state->u.f1.reg.cir, "HSIRDYF"); 
    state->u.f1.fld.cir.hserdyf = cm_object_get_child_by_name(state->u.f1.reg.cir, "HSERDYF"); 
    state->u.f1.fld.cir.pllrdyf = cm_object_get_child_by_name(state->u.f1.reg.cir, "PLLRDYF"); 
    state->u.f1.fld.cir.pll2rdyf = cm_object_get_child_by_name(state->u.f1.reg.cir, "PLL2RDYF"); 
    state->u.f1.fld.cir.pll3rdyf = cm_object_get_child_by_name(state->u.f1.reg.cir, "PLL3RDYF"); 
    state->u.f1.fld.cir.cssf = cm_object_get_child_by_name(state->u.f1.reg.cir, "CSSF"); 
    state->u.f1.fld.cir.lsirdyie = cm_object_get_child_by_name(state->u.f1.reg.cir, "LSIRDYIE"); 
    state->u.f1.fld.cir.lserdyie = cm_object_get_child_by_name(state->u.f1.reg.cir, "LSERDYIE"); 
    state->u.f1.fld.cir.hsirdyie = cm_object_get_child_by_name(state->u.f1.reg.cir, "HSIRDYIE"); 
    state->u.f1.fld.cir.hserdyie = cm_object_get_child_by_name(state->u.f1.reg.cir, "HSERDYIE"); 
    state->u.f1.fld.cir.pllrdyie = cm_object_get_child_by_name(state->u.f1.reg.cir, "PLLRDYIE"); 
    state->u.f1.fld.cir.pll2rdyie = cm_object_get_child_by_name(state->u.f1.reg.cir, "PLL2RDYIE"); 
    state->u.f1.fld.cir.pll3rdyie = cm_object_get_child_by_name(state->u.f1.reg.cir, "PLL3RDYIE"); 
    state->u.f1.fld.cir.lsirdyc = cm_object_get_child_by_name(state->u.f1.reg.cir, "LSIRDYC"); 
    state->u.f1.fld.cir.lserdyc = cm_object_get_child_by_name(state->u.f1.reg.cir, "LSERDYC"); 
    state->u.f1.fld.cir.hsirdyc = cm_object_get_child_by_name(state->u.f1.reg.cir, "HSIRDYC"); 
    state->u.f1.fld.cir.hserdyc = cm_object_get_child_by_name(state->u.f1.reg.cir, "HSERDYC"); 
    state->u.f1.fld.cir.pllrdyc = cm_object_get_child_by_name(state->u.f1.reg.cir, "PLLRDYC"); 
    state->u.f1.fld.cir.pll2rdyc = cm_object_get_child_by_name(state->u.f1.reg.cir, "PLL2RDYC"); 
    state->u.f1.fld.cir.pll3rdyc = cm_object_get_child_by_name(state->u.f1.reg.cir, "PLL3RDYC"); 
    state->u.f1.fld.cir.cssc = cm_object_get_child_by_name(state->u.f1.reg.cir, "CSSC");  
    
    // APB2RSTR bitfields.
    state->u.f1.fld.apb2rstr.afiorst = cm_object_get_child_by_name(state->u.f1.reg.apb2rstr, "AFIORST"); 
    state->u.f1.fld.apb2rstr.ioparst = cm_object_get_child_by_name(state->u.f1.reg.apb2rstr, "IOPARST"); 
    state->u.f1.fld.apb2rstr.iopbrst = cm_object_get_child_by_name(state->u.f1.reg.apb2rstr, "IOPBRST"); 
    state->u.f1.fld.apb2rstr.iopcrst = cm_object_get_child_by_name(state->u.f1.reg.apb2rstr, "IOPCRST"); 
    state->u.f1.fld.apb2rstr.iopdrst = cm_object_get_child_by_name(state->u.f1.reg.apb2rstr, "IOPDRST"); 
    state->u.f1.fld.apb2rstr.ioperst = cm_object_get_child_by_name(state->u.f1.reg.apb2rstr, "IOPERST"); 
    state->u.f1.fld.apb2rstr.adc1rst = cm_object_get_child_by_name(state->u.f1.reg.apb2rstr, "ADC1RST"); 
    state->u.f1.fld.apb2rstr.adc2rst = cm_object_get_child_by_name(state->u.f1.reg.apb2rstr, "ADC2RST"); 
    state->u.f1.fld.apb2rstr.tim1rst = cm_object_get_child_by_name(state->u.f1.reg.apb2rstr, "TIM1RST"); 
    state->u.f1.fld.apb2rstr.spi1rst = cm_object_get_child_by_name(state->u.f1.reg.apb2rstr, "SPI1RST"); 
    state->u.f1.fld.apb2rstr.usart1rst = cm_object_get_child_by_name(state->u.f1.reg.apb2rstr, "USART1RST");  
    
    // APB1RSTR bitfields.
    state->u.f1.fld.apb1rstr.tim2rst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "TIM2RST"); 
    state->u.f1.fld.apb1rstr.tim3rst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "TIM3RST"); 
    state->u.f1.fld.apb1rstr.tim4rst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "TIM4RST"); 
    state->u.f1.fld.apb1rstr.tim5rst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "TIM5RST"); 
    state->u.f1.fld.apb1rstr.tim6rst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "TIM6RST"); 
    state->u.f1.fld.apb1rstr.tim7rst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "TIM7RST"); 
    state->u.f1.fld.apb1rstr.wwdgrst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "WWDGRST"); 
    state->u.f1.fld.apb1rstr.spi2rst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "SPI2RST"); 
    state->u.f1.fld.apb1rstr.spi3rst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "SPI3RST"); 
    state->u.f1.fld.apb1rstr.usart2rst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "USART2RST"); 
    state->u.f1.fld.apb1rstr.usart3rst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "USART3RST"); 
    state->u.f1.fld.apb1rstr.usart4rst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "USART4RST"); 
    state->u.f1.fld.apb1rstr.usart5rst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "USART5RST"); 
    state->u.f1.fld.apb1rstr.i2c1rst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "I2C1RST"); 
    state->u.f1.fld.apb1rstr.i2c2rst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "I2C2RST"); 
    state->u.f1.fld.apb1rstr.can1rst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "CAN1RST"); 
    state->u.f1.fld.apb1rstr.can2rst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "CAN2RST"); 
    state->u.f1.fld.apb1rstr.bkprst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "BKPRST"); 
    state->u.f1.fld.apb1rstr.pwrrst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "PWRRST"); 
    state->u.f1.fld.apb1rstr.dacrst = cm_object_get_child_by_name(state->u.f1.reg.apb1rstr, "DACRST");  
    
    // AHBENR bitfields.
    state->u.f1.fld.ahbenr.dma1en = cm_object_get_child_by_name(state->u.f1.reg.ahbenr, "DMA1EN"); 
    state->u.f1.fld.ahbenr.dma2en = cm_object_get_child_by_name(state->u.f1.reg.ahbenr, "DMA2EN"); 
    state->u.f1.fld.ahbenr.sramen = cm_object_get_child_by_name(state->u.f1.reg.ahbenr, "SRAMEN"); 
    state->u.f1.fld.ahbenr.flitfen = cm_object_get_child_by_name(state->u.f1.reg.ahbenr, "FLITFEN"); 
    state->u.f1.fld.ahbenr.crcen = cm_object_get_child_by_name(state->u.f1.reg.ahbenr, "CRCEN"); 
    state->u.f1.fld.ahbenr.otgfsen = cm_object_get_child_by_name(state->u.f1.reg.ahbenr, "OTGFSEN"); 
    state->u.f1.fld.ahbenr.ethmacen = cm_object_get_child_by_name(state->u.f1.reg.ahbenr, "ETHMACEN"); 
    state->u.f1.fld.ahbenr.ethmactxen = cm_object_get_child_by_name(state->u.f1.reg.ahbenr, "ETHMACTXEN"); 
    state->u.f1.fld.ahbenr.ethmacrxen = cm_object_get_child_by_name(state->u.f1.reg.ahbenr, "ETHMACRXEN");  
    
    // APB2ENR bitfields.
    state->u.f1.fld.apb2enr.afioen = cm_object_get_child_by_name(state->u.f1.reg.apb2enr, "AFIOEN"); 
    state->u.f1.fld.apb2enr.iopaen = cm_object_get_child_by_name(state->u.f1.reg.apb2enr, "IOPAEN"); 
    state->u.f1.fld.apb2enr.iopben = cm_object_get_child_by_name(state->u.f1.reg.apb2enr, "IOPBEN"); 
    state->u.f1.fld.apb2enr.iopcen = cm_object_get_child_by_name(state->u.f1.reg.apb2enr, "IOPCEN"); 
    state->u.f1.fld.apb2enr.iopden = cm_object_get_child_by_name(state->u.f1.reg.apb2enr, "IOPDEN"); 
    state->u.f1.fld.apb2enr.iopeen = cm_object_get_child_by_name(state->u.f1.reg.apb2enr, "IOPEEN"); 
    state->u.f1.fld.apb2enr.adc1en = cm_object_get_child_by_name(state->u.f1.reg.apb2enr, "ADC1EN"); 
    state->u.f1.fld.apb2enr.adc2en = cm_object_get_child_by_name(state->u.f1.reg.apb2enr, "ADC2EN"); 
    state->u.f1.fld.apb2enr.tim1en = cm_object_get_child_by_name(state->u.f1.reg.apb2enr, "TIM1EN"); 
    state->u.f1.fld.apb2enr.spi1en = cm_object_get_child_by_name(state->u.f1.reg.apb2enr, "SPI1EN"); 
    state->u.f1.fld.apb2enr.usart1en = cm_object_get_child_by_name(state->u.f1.reg.apb2enr, "USART1EN");  
    
    // APB1ENR bitfields.
    state->u.f1.fld.apb1enr.tim2en = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "TIM2EN"); 
    state->u.f1.fld.apb1enr.tim3en = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "TIM3EN"); 
    state->u.f1.fld.apb1enr.tim4en = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "TIM4EN"); 
    state->u.f1.fld.apb1enr.tim5en = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "TIM5EN"); 
    state->u.f1.fld.apb1enr.tim6en = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "TIM6EN"); 
    state->u.f1.fld.apb1enr.tim7en = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "TIM7EN"); 
    state->u.f1.fld.apb1enr.wwdgen = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "WWDGEN"); 
    state->u.f1.fld.apb1enr.spi2en = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "SPI2EN"); 
    state->u.f1.fld.apb1enr.spi3en = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "SPI3EN"); 
    state->u.f1.fld.apb1enr.usart2en = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "USART2EN"); 
    state->u.f1.fld.apb1enr.usart3en = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "USART3EN"); 
    state->u.f1.fld.apb1enr.uart4en = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "UART4EN"); 
    state->u.f1.fld.apb1enr.uart5en = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "UART5EN"); 
    state->u.f1.fld.apb1enr.i2c1en = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "I2C1EN"); 
    state->u.f1.fld.apb1enr.i2c2en = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "I2C2EN"); 
    state->u.f1.fld.apb1enr.can1en = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "CAN1EN"); 
    state->u.f1.fld.apb1enr.can2en = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "CAN2EN"); 
    state->u.f1.fld.apb1enr.bkpen = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "BKPEN"); 
    state->u.f1.fld.apb1enr.pwren = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "PWREN"); 
    state->u.f1.fld.apb1enr.dacen = cm_object_get_child_by_name(state->u.f1.reg.apb1enr, "DACEN");  
    
    // BDCR bitfields.
    state->u.f1.fld.bdcr.lseon = cm_object_get_child_by_name(state->u.f1.reg.bdcr, "LSEON"); 
    state->u.f1.fld.bdcr.lserdy = cm_object_get_child_by_name(state->u.f1.reg.bdcr, "LSERDY"); 
    state->u.f1.fld.bdcr.lsebyp = cm_object_get_child_by_name(state->u.f1.reg.bdcr, "LSEBYP"); 
    state->u.f1.fld.bdcr.rtcsel = cm_object_get_child_by_name(state->u.f1.reg.bdcr, "RTCSEL"); 
    state->u.f1.fld.bdcr.rtcen = cm_object_get_child_by_name(state->u.f1.reg.bdcr, "RTCEN"); 
    state->u.f1.fld.bdcr.bdrst = cm_object_get_child_by_name(state->u.f1.reg.bdcr, "BDRST");  
    
    // CSR bitfields.
    state->u.f1.fld.csr.lsion = cm_object_get_child_by_name(state->u.f1.reg.csr, "LSION"); 
    state->u.f1.fld.csr.lsirdy = cm_object_get_child_by_name(state->u.f1.reg.csr, "LSIRDY"); 
    state->u.f1.fld.csr.rmvf = cm_object_get_child_by_name(state->u.f1.reg.csr, "RMVF"); 
    state->u.f1.fld.csr.pinrstf = cm_object_get_child_by_name(state->u.f1.reg.csr, "PINRSTF"); 
    state->u.f1.fld.csr.porrstf = cm_object_get_child_by_name(state->u.f1.reg.csr, "PORRSTF"); 
    state->u.f1.fld.csr.sftrstf = cm_object_get_child_by_name(state->u.f1.reg.csr, "SFTRSTF"); 
    state->u.f1.fld.csr.iwdgrstf = cm_object_get_child_by_name(state->u.f1.reg.csr, "IWDGRSTF"); 
    state->u.f1.fld.csr.wwdgrstf = cm_object_get_child_by_name(state->u.f1.reg.csr, "WWDGRSTF"); 
    state->u.f1.fld.csr.lpwrrstf = cm_object_get_child_by_name(state->u.f1.reg.csr, "LPWRRSTF");  
    
    // AHBRSTR bitfields.
    state->u.f1.fld.ahbrstr.otgfsrst = cm_object_get_child_by_name(state->u.f1.reg.ahbrstr, "OTGFSRST"); 
    state->u.f1.fld.ahbrstr.ethmacrst = cm_object_get_child_by_name(state->u.f1.reg.ahbrstr, "ETHMACRST");  
    
    // CFGR2 bitfields.
    state->u.f1.fld.cfgr2.prediv1 = cm_object_get_child_by_name(state->u.f1.reg.cfgr2, "PREDIV1"); 
    state->u.f1.fld.cfgr2.prediv2 = cm_object_get_child_by_name(state->u.f1.reg.cfgr2, "PREDIV2"); 
    state->u.f1.fld.cfgr2.pll2mul = cm_object_get_child_by_name(state->u.f1.reg.cfgr2, "PLL2MUL"); 
    state->u.f1.fld.cfgr2.pll3mul = cm_object_get_child_by_name(state->u.f1.reg.cfgr2, "PLL3MUL"); 
    state->u.f1.fld.cfgr2.prediv1src = cm_object_get_child_by_name(state->u.f1.reg.cfgr2, "PREDIV1SRC"); 
    state->u.f1.fld.cfgr2.i2s2src = cm_object_get_child_by_name(state->u.f1.reg.cfgr2, "I2S2SRC"); 
    state->u.f1.fld.cfgr2.i2s3src = cm_object_get_child_by_name(state->u.f1.reg.cfgr2, "I2S3SRC");  
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
    case STM32_FAMILY_F1:

        if (capabilities->f1.is_107xx ) {

            stm32f107xx_rcc_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f1.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f1.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f1.reg.xxx, &stm32_rcc_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f1.reg.xxx, &stm32_rcc_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f1.reg.xxx, &stm32_rcc_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f1.reg.xxx, &stm32_rcc_xxx_post_write_callback);

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
