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
static void stm32f429x_rcc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32RCCState *state = STM32_RCC_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->u.f4.reg.pllcfgr = cm_object_get_child_by_name(obj, "PLLCFGR");
    state->u.f4.reg.cfgr = cm_object_get_child_by_name(obj, "CFGR");
    state->u.f4.reg.cir = cm_object_get_child_by_name(obj, "CIR");
    state->u.f4.reg.ahb1rstr = cm_object_get_child_by_name(obj, "AHB1RSTR");
    state->u.f4.reg.ahb2rstr = cm_object_get_child_by_name(obj, "AHB2RSTR");
    state->u.f4.reg.ahb3rstr = cm_object_get_child_by_name(obj, "AHB3RSTR");
    state->u.f4.reg.apb1rstr = cm_object_get_child_by_name(obj, "APB1RSTR");
    state->u.f4.reg.apb2rstr = cm_object_get_child_by_name(obj, "APB2RSTR");
    state->u.f4.reg.ahb1enr = cm_object_get_child_by_name(obj, "AHB1ENR");
    state->u.f4.reg.ahb2enr = cm_object_get_child_by_name(obj, "AHB2ENR");
    state->u.f4.reg.ahb3enr = cm_object_get_child_by_name(obj, "AHB3ENR");
    state->u.f4.reg.apb1enr = cm_object_get_child_by_name(obj, "APB1ENR");
    state->u.f4.reg.apb2enr = cm_object_get_child_by_name(obj, "APB2ENR");
    state->u.f4.reg.ahb1lpenr = cm_object_get_child_by_name(obj, "AHB1LPENR");
    state->u.f4.reg.ahb2lpenr = cm_object_get_child_by_name(obj, "AHB2LPENR");
    state->u.f4.reg.ahb3lpenr = cm_object_get_child_by_name(obj, "AHB3LPENR");
    state->u.f4.reg.apb1lpenr = cm_object_get_child_by_name(obj, "APB1LPENR");
    state->u.f4.reg.apb2lpenr = cm_object_get_child_by_name(obj, "APB2LPENR");
    state->u.f4.reg.bdcr = cm_object_get_child_by_name(obj, "BDCR");
    state->u.f4.reg.csr = cm_object_get_child_by_name(obj, "CSR");
    state->u.f4.reg.sscgr = cm_object_get_child_by_name(obj, "SSCGR");
    state->u.f4.reg.plli2scfgr = cm_object_get_child_by_name(obj, "PLLI2SCFGR");
    state->u.f4.reg.pllsaicfgr = cm_object_get_child_by_name(obj, "PLLSAICFGR");
    state->u.f4.reg.dckcfgr = cm_object_get_child_by_name(obj, "DCKCFGR");
    
    
    // CR bitfields.
    state->u.f4.fld.cr.hsion = cm_object_get_child_by_name(state->u.f4.reg.cr, "HSION"); 
    state->u.f4.fld.cr.hsirdy = cm_object_get_child_by_name(state->u.f4.reg.cr, "HSIRDY"); 
    state->u.f4.fld.cr.hsitrim = cm_object_get_child_by_name(state->u.f4.reg.cr, "HSITRIM"); 
    state->u.f4.fld.cr.hsical = cm_object_get_child_by_name(state->u.f4.reg.cr, "HSICAL"); 
    state->u.f4.fld.cr.hseon = cm_object_get_child_by_name(state->u.f4.reg.cr, "HSEON"); 
    state->u.f4.fld.cr.hserdy = cm_object_get_child_by_name(state->u.f4.reg.cr, "HSERDY"); 
    state->u.f4.fld.cr.hsebyp = cm_object_get_child_by_name(state->u.f4.reg.cr, "HSEBYP"); 
    state->u.f4.fld.cr.csson = cm_object_get_child_by_name(state->u.f4.reg.cr, "CSSON"); 
    state->u.f4.fld.cr.pllon = cm_object_get_child_by_name(state->u.f4.reg.cr, "PLLON"); 
    state->u.f4.fld.cr.pllrdy = cm_object_get_child_by_name(state->u.f4.reg.cr, "PLLRDY"); 
    state->u.f4.fld.cr.plli2son = cm_object_get_child_by_name(state->u.f4.reg.cr, "PLLI2SON"); 
    state->u.f4.fld.cr.plli2srdy = cm_object_get_child_by_name(state->u.f4.reg.cr, "PLLI2SRDY");  
    
    // PLLCFGR bitfields.
    state->u.f4.fld.pllcfgr.pllm = cm_object_get_child_by_name(state->u.f4.reg.pllcfgr, "PLLM"); 
    state->u.f4.fld.pllcfgr.plln = cm_object_get_child_by_name(state->u.f4.reg.pllcfgr, "PLLN"); 
    state->u.f4.fld.pllcfgr.pllp = cm_object_get_child_by_name(state->u.f4.reg.pllcfgr, "PLLP"); 
    state->u.f4.fld.pllcfgr.pllsrc = cm_object_get_child_by_name(state->u.f4.reg.pllcfgr, "PLLSRC"); 
    state->u.f4.fld.pllcfgr.pllq = cm_object_get_child_by_name(state->u.f4.reg.pllcfgr, "PLLQ");  
    
    // CFGR bitfields.
    state->u.f4.fld.cfgr.sw = cm_object_get_child_by_name(state->u.f4.reg.cfgr, "SW"); 
    state->u.f4.fld.cfgr.sws = cm_object_get_child_by_name(state->u.f4.reg.cfgr, "SWS"); 
    state->u.f4.fld.cfgr.hpre = cm_object_get_child_by_name(state->u.f4.reg.cfgr, "HPRE"); 
    state->u.f4.fld.cfgr.ppre1 = cm_object_get_child_by_name(state->u.f4.reg.cfgr, "PPRE1"); 
    state->u.f4.fld.cfgr.ppre2 = cm_object_get_child_by_name(state->u.f4.reg.cfgr, "PPRE2"); 
    state->u.f4.fld.cfgr.rtcpre = cm_object_get_child_by_name(state->u.f4.reg.cfgr, "RTCPRE"); 
    state->u.f4.fld.cfgr.mco1 = cm_object_get_child_by_name(state->u.f4.reg.cfgr, "MCO1"); 
    state->u.f4.fld.cfgr.i2ssrc = cm_object_get_child_by_name(state->u.f4.reg.cfgr, "I2SSRC"); 
    state->u.f4.fld.cfgr.mco1pre = cm_object_get_child_by_name(state->u.f4.reg.cfgr, "MCO1PRE"); 
    state->u.f4.fld.cfgr.mco2pre = cm_object_get_child_by_name(state->u.f4.reg.cfgr, "MCO2PRE"); 
    state->u.f4.fld.cfgr.mco2 = cm_object_get_child_by_name(state->u.f4.reg.cfgr, "MCO2");  
    
    // CIR bitfields.
    state->u.f4.fld.cir.lsirdyf = cm_object_get_child_by_name(state->u.f4.reg.cir, "LSIRDYF"); 
    state->u.f4.fld.cir.lserdyf = cm_object_get_child_by_name(state->u.f4.reg.cir, "LSERDYF"); 
    state->u.f4.fld.cir.hsirdyf = cm_object_get_child_by_name(state->u.f4.reg.cir, "HSIRDYF"); 
    state->u.f4.fld.cir.hserdyf = cm_object_get_child_by_name(state->u.f4.reg.cir, "HSERDYF"); 
    state->u.f4.fld.cir.pllrdyf = cm_object_get_child_by_name(state->u.f4.reg.cir, "PLLRDYF"); 
    state->u.f4.fld.cir.plli2srdyf = cm_object_get_child_by_name(state->u.f4.reg.cir, "PLLI2SRDYF"); 
    state->u.f4.fld.cir.pllsairdyf = cm_object_get_child_by_name(state->u.f4.reg.cir, "PLLSAIRDYF"); 
    state->u.f4.fld.cir.cssf = cm_object_get_child_by_name(state->u.f4.reg.cir, "CSSF"); 
    state->u.f4.fld.cir.lsirdyie = cm_object_get_child_by_name(state->u.f4.reg.cir, "LSIRDYIE"); 
    state->u.f4.fld.cir.lserdyie = cm_object_get_child_by_name(state->u.f4.reg.cir, "LSERDYIE"); 
    state->u.f4.fld.cir.hsirdyie = cm_object_get_child_by_name(state->u.f4.reg.cir, "HSIRDYIE"); 
    state->u.f4.fld.cir.hserdyie = cm_object_get_child_by_name(state->u.f4.reg.cir, "HSERDYIE"); 
    state->u.f4.fld.cir.pllrdyie = cm_object_get_child_by_name(state->u.f4.reg.cir, "PLLRDYIE"); 
    state->u.f4.fld.cir.plli2srdyie = cm_object_get_child_by_name(state->u.f4.reg.cir, "PLLI2SRDYIE"); 
    state->u.f4.fld.cir.pllsairdyie = cm_object_get_child_by_name(state->u.f4.reg.cir, "PLLSAIRDYIE"); 
    state->u.f4.fld.cir.lsirdyc = cm_object_get_child_by_name(state->u.f4.reg.cir, "LSIRDYC"); 
    state->u.f4.fld.cir.lserdyc = cm_object_get_child_by_name(state->u.f4.reg.cir, "LSERDYC"); 
    state->u.f4.fld.cir.hsirdyc = cm_object_get_child_by_name(state->u.f4.reg.cir, "HSIRDYC"); 
    state->u.f4.fld.cir.hserdyc = cm_object_get_child_by_name(state->u.f4.reg.cir, "HSERDYC"); 
    state->u.f4.fld.cir.pllrdyc = cm_object_get_child_by_name(state->u.f4.reg.cir, "PLLRDYC"); 
    state->u.f4.fld.cir.plli2srdyc = cm_object_get_child_by_name(state->u.f4.reg.cir, "PLLI2SRDYC"); 
    state->u.f4.fld.cir.pllsairdyc = cm_object_get_child_by_name(state->u.f4.reg.cir, "PLLSAIRDYC"); 
    state->u.f4.fld.cir.cssc = cm_object_get_child_by_name(state->u.f4.reg.cir, "CSSC");  
    
    // AHB1RSTR bitfields.
    state->u.f4.fld.ahb1rstr.gpioarst = cm_object_get_child_by_name(state->u.f4.reg.ahb1rstr, "GPIOARST"); 
    state->u.f4.fld.ahb1rstr.gpiobrst = cm_object_get_child_by_name(state->u.f4.reg.ahb1rstr, "GPIOBRST"); 
    state->u.f4.fld.ahb1rstr.gpiocrst = cm_object_get_child_by_name(state->u.f4.reg.ahb1rstr, "GPIOCRST"); 
    state->u.f4.fld.ahb1rstr.gpiodrst = cm_object_get_child_by_name(state->u.f4.reg.ahb1rstr, "GPIODRST"); 
    state->u.f4.fld.ahb1rstr.gpioerst = cm_object_get_child_by_name(state->u.f4.reg.ahb1rstr, "GPIOERST"); 
    state->u.f4.fld.ahb1rstr.gpiofrst = cm_object_get_child_by_name(state->u.f4.reg.ahb1rstr, "GPIOFRST"); 
    state->u.f4.fld.ahb1rstr.gpiogrst = cm_object_get_child_by_name(state->u.f4.reg.ahb1rstr, "GPIOGRST"); 
    state->u.f4.fld.ahb1rstr.gpiohrst = cm_object_get_child_by_name(state->u.f4.reg.ahb1rstr, "GPIOHRST"); 
    state->u.f4.fld.ahb1rstr.gpioirst = cm_object_get_child_by_name(state->u.f4.reg.ahb1rstr, "GPIOIRST"); 
    state->u.f4.fld.ahb1rstr.gpiojrst = cm_object_get_child_by_name(state->u.f4.reg.ahb1rstr, "GPIOJRST"); 
    state->u.f4.fld.ahb1rstr.gpiokrst = cm_object_get_child_by_name(state->u.f4.reg.ahb1rstr, "GPIOKRST"); 
    state->u.f4.fld.ahb1rstr.crcrst = cm_object_get_child_by_name(state->u.f4.reg.ahb1rstr, "CRCRST"); 
    state->u.f4.fld.ahb1rstr.dma1rst = cm_object_get_child_by_name(state->u.f4.reg.ahb1rstr, "DMA1RST"); 
    state->u.f4.fld.ahb1rstr.dma2rst = cm_object_get_child_by_name(state->u.f4.reg.ahb1rstr, "DMA2RST"); 
    state->u.f4.fld.ahb1rstr.dma2drst = cm_object_get_child_by_name(state->u.f4.reg.ahb1rstr, "DMA2DRST"); 
    state->u.f4.fld.ahb1rstr.ethmacrst = cm_object_get_child_by_name(state->u.f4.reg.ahb1rstr, "ETHMACRST"); 
    state->u.f4.fld.ahb1rstr.otghsrst = cm_object_get_child_by_name(state->u.f4.reg.ahb1rstr, "OTGHSRST");  
    
    // AHB2RSTR bitfields.
    state->u.f4.fld.ahb2rstr.dcmirst = cm_object_get_child_by_name(state->u.f4.reg.ahb2rstr, "DCMIRST"); 
    state->u.f4.fld.ahb2rstr.rngrst = cm_object_get_child_by_name(state->u.f4.reg.ahb2rstr, "RNGRST"); 
    state->u.f4.fld.ahb2rstr.otgfsrst = cm_object_get_child_by_name(state->u.f4.reg.ahb2rstr, "OTGFSRST");  
    
    // AHB3RSTR bitfields.
    state->u.f4.fld.ahb3rstr.fmcrst = cm_object_get_child_by_name(state->u.f4.reg.ahb3rstr, "FMCRST");  
    
    // APB1RSTR bitfields.
    state->u.f4.fld.apb1rstr.tim2rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "TIM2RST"); 
    state->u.f4.fld.apb1rstr.tim3rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "TIM3RST"); 
    state->u.f4.fld.apb1rstr.tim4rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "TIM4RST"); 
    state->u.f4.fld.apb1rstr.tim5rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "TIM5RST"); 
    state->u.f4.fld.apb1rstr.tim6rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "TIM6RST"); 
    state->u.f4.fld.apb1rstr.tim7rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "TIM7RST"); 
    state->u.f4.fld.apb1rstr.tim12rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "TIM12RST"); 
    state->u.f4.fld.apb1rstr.tim13rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "TIM13RST"); 
    state->u.f4.fld.apb1rstr.tim14rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "TIM14RST"); 
    state->u.f4.fld.apb1rstr.wwdgrst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "WWDGRST"); 
    state->u.f4.fld.apb1rstr.spi2rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "SPI2RST"); 
    state->u.f4.fld.apb1rstr.spi3rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "SPI3RST"); 
    state->u.f4.fld.apb1rstr.uart2rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "UART2RST"); 
    state->u.f4.fld.apb1rstr.uart3rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "UART3RST"); 
    state->u.f4.fld.apb1rstr.uart4rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "UART4RST"); 
    state->u.f4.fld.apb1rstr.uart5rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "UART5RST"); 
    state->u.f4.fld.apb1rstr.i2c1rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "I2C1RST"); 
    state->u.f4.fld.apb1rstr.i2c2rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "I2C2RST"); 
    state->u.f4.fld.apb1rstr.i2c3rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "I2C3RST"); 
    state->u.f4.fld.apb1rstr.can1rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "CAN1RST"); 
    state->u.f4.fld.apb1rstr.can2rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "CAN2RST"); 
    state->u.f4.fld.apb1rstr.pwrrst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "PWRRST"); 
    state->u.f4.fld.apb1rstr.dacrst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "DACRST"); 
    state->u.f4.fld.apb1rstr.uart7rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "UART7RST"); 
    state->u.f4.fld.apb1rstr.uart8rst = cm_object_get_child_by_name(state->u.f4.reg.apb1rstr, "UART8RST");  
    
    // APB2RSTR bitfields.
    state->u.f4.fld.apb2rstr.tim1rst = cm_object_get_child_by_name(state->u.f4.reg.apb2rstr, "TIM1RST"); 
    state->u.f4.fld.apb2rstr.tim8rst = cm_object_get_child_by_name(state->u.f4.reg.apb2rstr, "TIM8RST"); 
    state->u.f4.fld.apb2rstr.usart1rst = cm_object_get_child_by_name(state->u.f4.reg.apb2rstr, "USART1RST"); 
    state->u.f4.fld.apb2rstr.usart6rst = cm_object_get_child_by_name(state->u.f4.reg.apb2rstr, "USART6RST"); 
    state->u.f4.fld.apb2rstr.adcrst = cm_object_get_child_by_name(state->u.f4.reg.apb2rstr, "ADCRST"); 
    state->u.f4.fld.apb2rstr.sdiorst = cm_object_get_child_by_name(state->u.f4.reg.apb2rstr, "SDIORST"); 
    state->u.f4.fld.apb2rstr.spi1rst = cm_object_get_child_by_name(state->u.f4.reg.apb2rstr, "SPI1RST"); 
    state->u.f4.fld.apb2rstr.spi4rst = cm_object_get_child_by_name(state->u.f4.reg.apb2rstr, "SPI4RST"); 
    state->u.f4.fld.apb2rstr.syscfgrst = cm_object_get_child_by_name(state->u.f4.reg.apb2rstr, "SYSCFGRST"); 
    state->u.f4.fld.apb2rstr.tim9rst = cm_object_get_child_by_name(state->u.f4.reg.apb2rstr, "TIM9RST"); 
    state->u.f4.fld.apb2rstr.tim10rst = cm_object_get_child_by_name(state->u.f4.reg.apb2rstr, "TIM10RST"); 
    state->u.f4.fld.apb2rstr.tim11rst = cm_object_get_child_by_name(state->u.f4.reg.apb2rstr, "TIM11RST"); 
    state->u.f4.fld.apb2rstr.spi5rst = cm_object_get_child_by_name(state->u.f4.reg.apb2rstr, "SPI5RST"); 
    state->u.f4.fld.apb2rstr.spi6rst = cm_object_get_child_by_name(state->u.f4.reg.apb2rstr, "SPI6RST"); 
    state->u.f4.fld.apb2rstr.sai1rst = cm_object_get_child_by_name(state->u.f4.reg.apb2rstr, "SAI1RST"); 
    state->u.f4.fld.apb2rstr.ltdcrst = cm_object_get_child_by_name(state->u.f4.reg.apb2rstr, "LTDCRST");  
    
    // AHB1ENR bitfields.
    state->u.f4.fld.ahb1enr.gpioaen = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "GPIOAEN"); 
    state->u.f4.fld.ahb1enr.gpioben = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "GPIOBEN"); 
    state->u.f4.fld.ahb1enr.gpiocen = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "GPIOCEN"); 
    state->u.f4.fld.ahb1enr.gpioden = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "GPIODEN"); 
    state->u.f4.fld.ahb1enr.gpioeen = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "GPIOEEN"); 
    state->u.f4.fld.ahb1enr.gpiofen = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "GPIOFEN"); 
    state->u.f4.fld.ahb1enr.gpiogen = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "GPIOGEN"); 
    state->u.f4.fld.ahb1enr.gpiohen = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "GPIOHEN"); 
    state->u.f4.fld.ahb1enr.gpioien = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "GPIOIEN"); 
    state->u.f4.fld.ahb1enr.gpiojen = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "GPIOJEN"); 
    state->u.f4.fld.ahb1enr.gpioken = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "GPIOKEN"); 
    state->u.f4.fld.ahb1enr.crcen = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "CRCEN"); 
    state->u.f4.fld.ahb1enr.bkpsramen = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "BKPSRAMEN"); 
    state->u.f4.fld.ahb1enr.ccmdataramen = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "CCMDATARAMEN"); 
    state->u.f4.fld.ahb1enr.dma1en = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "DMA1EN"); 
    state->u.f4.fld.ahb1enr.dma2en = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "DMA2EN"); 
    state->u.f4.fld.ahb1enr.dma2den = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "DMA2DEN"); 
    state->u.f4.fld.ahb1enr.ethmacen = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "ETHMACEN"); 
    state->u.f4.fld.ahb1enr.ethmactxen = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "ETHMACTXEN"); 
    state->u.f4.fld.ahb1enr.ethmacrxen = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "ETHMACRXEN"); 
    state->u.f4.fld.ahb1enr.ethmacptpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "ETHMACPTPEN"); 
    state->u.f4.fld.ahb1enr.otghsen = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "OTGHSEN"); 
    state->u.f4.fld.ahb1enr.otghsulpien = cm_object_get_child_by_name(state->u.f4.reg.ahb1enr, "OTGHSULPIEN");  
    
    // AHB2ENR bitfields.
    state->u.f4.fld.ahb2enr.dcmien = cm_object_get_child_by_name(state->u.f4.reg.ahb2enr, "DCMIEN"); 
    state->u.f4.fld.ahb2enr.rngen = cm_object_get_child_by_name(state->u.f4.reg.ahb2enr, "RNGEN"); 
    state->u.f4.fld.ahb2enr.otgfsen = cm_object_get_child_by_name(state->u.f4.reg.ahb2enr, "OTGFSEN");  
    
    // AHB3ENR bitfields.
    state->u.f4.fld.ahb3enr.fmcen = cm_object_get_child_by_name(state->u.f4.reg.ahb3enr, "FMCEN");  
    
    // APB1ENR bitfields.
    state->u.f4.fld.apb1enr.tim2en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "TIM2EN"); 
    state->u.f4.fld.apb1enr.tim3en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "TIM3EN"); 
    state->u.f4.fld.apb1enr.tim4en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "TIM4EN"); 
    state->u.f4.fld.apb1enr.tim5en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "TIM5EN"); 
    state->u.f4.fld.apb1enr.tim6en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "TIM6EN"); 
    state->u.f4.fld.apb1enr.tim7en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "TIM7EN"); 
    state->u.f4.fld.apb1enr.tim12en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "TIM12EN"); 
    state->u.f4.fld.apb1enr.tim13en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "TIM13EN"); 
    state->u.f4.fld.apb1enr.tim14en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "TIM14EN"); 
    state->u.f4.fld.apb1enr.wwdgen = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "WWDGEN"); 
    state->u.f4.fld.apb1enr.spi2en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "SPI2EN"); 
    state->u.f4.fld.apb1enr.spi3en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "SPI3EN"); 
    state->u.f4.fld.apb1enr.usart2en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "USART2EN"); 
    state->u.f4.fld.apb1enr.usart3en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "USART3EN"); 
    state->u.f4.fld.apb1enr.uart4en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "UART4EN"); 
    state->u.f4.fld.apb1enr.uart5en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "UART5EN"); 
    state->u.f4.fld.apb1enr.i2c1en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "I2C1EN"); 
    state->u.f4.fld.apb1enr.i2c2en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "I2C2EN"); 
    state->u.f4.fld.apb1enr.i2c3en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "I2C3EN"); 
    state->u.f4.fld.apb1enr.can1en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "CAN1EN"); 
    state->u.f4.fld.apb1enr.can2en = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "CAN2EN"); 
    state->u.f4.fld.apb1enr.pwren = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "PWREN"); 
    state->u.f4.fld.apb1enr.dacen = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "DACEN"); 
    state->u.f4.fld.apb1enr.uart7enr = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "UART7ENR"); 
    state->u.f4.fld.apb1enr.uart8enr = cm_object_get_child_by_name(state->u.f4.reg.apb1enr, "UART8ENR");  
    
    // APB2ENR bitfields.
    state->u.f4.fld.apb2enr.tim1en = cm_object_get_child_by_name(state->u.f4.reg.apb2enr, "TIM1EN"); 
    state->u.f4.fld.apb2enr.tim8en = cm_object_get_child_by_name(state->u.f4.reg.apb2enr, "TIM8EN"); 
    state->u.f4.fld.apb2enr.usart1en = cm_object_get_child_by_name(state->u.f4.reg.apb2enr, "USART1EN"); 
    state->u.f4.fld.apb2enr.usart6en = cm_object_get_child_by_name(state->u.f4.reg.apb2enr, "USART6EN"); 
    state->u.f4.fld.apb2enr.adc1en = cm_object_get_child_by_name(state->u.f4.reg.apb2enr, "ADC1EN"); 
    state->u.f4.fld.apb2enr.adc2en = cm_object_get_child_by_name(state->u.f4.reg.apb2enr, "ADC2EN"); 
    state->u.f4.fld.apb2enr.adc3en = cm_object_get_child_by_name(state->u.f4.reg.apb2enr, "ADC3EN"); 
    state->u.f4.fld.apb2enr.sdioen = cm_object_get_child_by_name(state->u.f4.reg.apb2enr, "SDIOEN"); 
    state->u.f4.fld.apb2enr.spi1en = cm_object_get_child_by_name(state->u.f4.reg.apb2enr, "SPI1EN"); 
    state->u.f4.fld.apb2enr.spi4enr = cm_object_get_child_by_name(state->u.f4.reg.apb2enr, "SPI4ENR"); 
    state->u.f4.fld.apb2enr.syscfgen = cm_object_get_child_by_name(state->u.f4.reg.apb2enr, "SYSCFGEN"); 
    state->u.f4.fld.apb2enr.tim9en = cm_object_get_child_by_name(state->u.f4.reg.apb2enr, "TIM9EN"); 
    state->u.f4.fld.apb2enr.tim10en = cm_object_get_child_by_name(state->u.f4.reg.apb2enr, "TIM10EN"); 
    state->u.f4.fld.apb2enr.tim11en = cm_object_get_child_by_name(state->u.f4.reg.apb2enr, "TIM11EN"); 
    state->u.f4.fld.apb2enr.spi5enr = cm_object_get_child_by_name(state->u.f4.reg.apb2enr, "SPI5ENR"); 
    state->u.f4.fld.apb2enr.spi6enr = cm_object_get_child_by_name(state->u.f4.reg.apb2enr, "SPI6ENR"); 
    state->u.f4.fld.apb2enr.sai1en = cm_object_get_child_by_name(state->u.f4.reg.apb2enr, "SAI1EN"); 
    state->u.f4.fld.apb2enr.ltdcen = cm_object_get_child_by_name(state->u.f4.reg.apb2enr, "LTDCEN");  
    
    // AHB1LPENR bitfields.
    state->u.f4.fld.ahb1lpenr.gpioalpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "GPIOALPEN"); 
    state->u.f4.fld.ahb1lpenr.gpioblpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "GPIOBLPEN"); 
    state->u.f4.fld.ahb1lpenr.gpioclpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "GPIOCLPEN"); 
    state->u.f4.fld.ahb1lpenr.gpiodlpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "GPIODLPEN"); 
    state->u.f4.fld.ahb1lpenr.gpioelpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "GPIOELPEN"); 
    state->u.f4.fld.ahb1lpenr.gpioflpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "GPIOFLPEN"); 
    state->u.f4.fld.ahb1lpenr.gpioglpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "GPIOGLPEN"); 
    state->u.f4.fld.ahb1lpenr.gpiohlpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "GPIOHLPEN"); 
    state->u.f4.fld.ahb1lpenr.gpioilpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "GPIOILPEN"); 
    state->u.f4.fld.ahb1lpenr.gpiojlpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "GPIOJLPEN"); 
    state->u.f4.fld.ahb1lpenr.gpioklpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "GPIOKLPEN"); 
    state->u.f4.fld.ahb1lpenr.crclpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "CRCLPEN"); 
    state->u.f4.fld.ahb1lpenr.flitflpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "FLITFLPEN"); 
    state->u.f4.fld.ahb1lpenr.sram1lpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "SRAM1LPEN"); 
    state->u.f4.fld.ahb1lpenr.sram2lpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "SRAM2LPEN"); 
    state->u.f4.fld.ahb1lpenr.bkpsramlpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "BKPSRAMLPEN"); 
    state->u.f4.fld.ahb1lpenr.sram3lpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "SRAM3LPEN"); 
    state->u.f4.fld.ahb1lpenr.dma1lpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "DMA1LPEN"); 
    state->u.f4.fld.ahb1lpenr.dma2lpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "DMA2LPEN"); 
    state->u.f4.fld.ahb1lpenr.dma2dlpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "DMA2DLPEN"); 
    state->u.f4.fld.ahb1lpenr.ethmaclpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "ETHMACLPEN"); 
    state->u.f4.fld.ahb1lpenr.ethmactxlpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "ETHMACTXLPEN"); 
    state->u.f4.fld.ahb1lpenr.ethmacrxlpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "ETHMACRXLPEN"); 
    state->u.f4.fld.ahb1lpenr.ethmacptplpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "ETHMACPTPLPEN"); 
    state->u.f4.fld.ahb1lpenr.otghslpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "OTGHSLPEN"); 
    state->u.f4.fld.ahb1lpenr.otghsulpilpen = cm_object_get_child_by_name(state->u.f4.reg.ahb1lpenr, "OTGHSULPILPEN");  
    
    // AHB2LPENR bitfields.
    state->u.f4.fld.ahb2lpenr.dcmilpen = cm_object_get_child_by_name(state->u.f4.reg.ahb2lpenr, "DCMILPEN"); 
    state->u.f4.fld.ahb2lpenr.rnglpen = cm_object_get_child_by_name(state->u.f4.reg.ahb2lpenr, "RNGLPEN"); 
    state->u.f4.fld.ahb2lpenr.otgfslpen = cm_object_get_child_by_name(state->u.f4.reg.ahb2lpenr, "OTGFSLPEN");  
    
    // AHB3LPENR bitfields.
    state->u.f4.fld.ahb3lpenr.fmclpen = cm_object_get_child_by_name(state->u.f4.reg.ahb3lpenr, "FMCLPEN");  
    
    // APB1LPENR bitfields.
    state->u.f4.fld.apb1lpenr.tim2lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "TIM2LPEN"); 
    state->u.f4.fld.apb1lpenr.tim3lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "TIM3LPEN"); 
    state->u.f4.fld.apb1lpenr.tim4lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "TIM4LPEN"); 
    state->u.f4.fld.apb1lpenr.tim5lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "TIM5LPEN"); 
    state->u.f4.fld.apb1lpenr.tim6lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "TIM6LPEN"); 
    state->u.f4.fld.apb1lpenr.tim7lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "TIM7LPEN"); 
    state->u.f4.fld.apb1lpenr.tim12lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "TIM12LPEN"); 
    state->u.f4.fld.apb1lpenr.tim13lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "TIM13LPEN"); 
    state->u.f4.fld.apb1lpenr.tim14lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "TIM14LPEN"); 
    state->u.f4.fld.apb1lpenr.wwdglpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "WWDGLPEN"); 
    state->u.f4.fld.apb1lpenr.spi2lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "SPI2LPEN"); 
    state->u.f4.fld.apb1lpenr.spi3lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "SPI3LPEN"); 
    state->u.f4.fld.apb1lpenr.usart2lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "USART2LPEN"); 
    state->u.f4.fld.apb1lpenr.usart3lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "USART3LPEN"); 
    state->u.f4.fld.apb1lpenr.uart4lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "UART4LPEN"); 
    state->u.f4.fld.apb1lpenr.uart5lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "UART5LPEN"); 
    state->u.f4.fld.apb1lpenr.i2c1lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "I2C1LPEN"); 
    state->u.f4.fld.apb1lpenr.i2c2lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "I2C2LPEN"); 
    state->u.f4.fld.apb1lpenr.i2c3lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "I2C3LPEN"); 
    state->u.f4.fld.apb1lpenr.can1lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "CAN1LPEN"); 
    state->u.f4.fld.apb1lpenr.can2lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "CAN2LPEN"); 
    state->u.f4.fld.apb1lpenr.pwrlpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "PWRLPEN"); 
    state->u.f4.fld.apb1lpenr.daclpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "DACLPEN"); 
    state->u.f4.fld.apb1lpenr.uart7lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "UART7LPEN"); 
    state->u.f4.fld.apb1lpenr.uart8lpen = cm_object_get_child_by_name(state->u.f4.reg.apb1lpenr, "UART8LPEN");  
    
    // APB2LPENR bitfields.
    state->u.f4.fld.apb2lpenr.tim1lpen = cm_object_get_child_by_name(state->u.f4.reg.apb2lpenr, "TIM1LPEN"); 
    state->u.f4.fld.apb2lpenr.tim8lpen = cm_object_get_child_by_name(state->u.f4.reg.apb2lpenr, "TIM8LPEN"); 
    state->u.f4.fld.apb2lpenr.usart1lpen = cm_object_get_child_by_name(state->u.f4.reg.apb2lpenr, "USART1LPEN"); 
    state->u.f4.fld.apb2lpenr.usart6lpen = cm_object_get_child_by_name(state->u.f4.reg.apb2lpenr, "USART6LPEN"); 
    state->u.f4.fld.apb2lpenr.adc1lpen = cm_object_get_child_by_name(state->u.f4.reg.apb2lpenr, "ADC1LPEN"); 
    state->u.f4.fld.apb2lpenr.adc2lpen = cm_object_get_child_by_name(state->u.f4.reg.apb2lpenr, "ADC2LPEN"); 
    state->u.f4.fld.apb2lpenr.adc3lpen = cm_object_get_child_by_name(state->u.f4.reg.apb2lpenr, "ADC3LPEN"); 
    state->u.f4.fld.apb2lpenr.sdiolpen = cm_object_get_child_by_name(state->u.f4.reg.apb2lpenr, "SDIOLPEN"); 
    state->u.f4.fld.apb2lpenr.spi1lpen = cm_object_get_child_by_name(state->u.f4.reg.apb2lpenr, "SPI1LPEN"); 
    state->u.f4.fld.apb2lpenr.spi4lpen = cm_object_get_child_by_name(state->u.f4.reg.apb2lpenr, "SPI4LPEN"); 
    state->u.f4.fld.apb2lpenr.syscfglpen = cm_object_get_child_by_name(state->u.f4.reg.apb2lpenr, "SYSCFGLPEN"); 
    state->u.f4.fld.apb2lpenr.tim9lpen = cm_object_get_child_by_name(state->u.f4.reg.apb2lpenr, "TIM9LPEN"); 
    state->u.f4.fld.apb2lpenr.tim10lpen = cm_object_get_child_by_name(state->u.f4.reg.apb2lpenr, "TIM10LPEN"); 
    state->u.f4.fld.apb2lpenr.tim11lpen = cm_object_get_child_by_name(state->u.f4.reg.apb2lpenr, "TIM11LPEN"); 
    state->u.f4.fld.apb2lpenr.spi5lpen = cm_object_get_child_by_name(state->u.f4.reg.apb2lpenr, "SPI5LPEN"); 
    state->u.f4.fld.apb2lpenr.spi6lpen = cm_object_get_child_by_name(state->u.f4.reg.apb2lpenr, "SPI6LPEN"); 
    state->u.f4.fld.apb2lpenr.sai1lpen = cm_object_get_child_by_name(state->u.f4.reg.apb2lpenr, "SAI1LPEN"); 
    state->u.f4.fld.apb2lpenr.ltdclpen = cm_object_get_child_by_name(state->u.f4.reg.apb2lpenr, "LTDCLPEN");  
    
    // BDCR bitfields.
    state->u.f4.fld.bdcr.lseon = cm_object_get_child_by_name(state->u.f4.reg.bdcr, "LSEON"); 
    state->u.f4.fld.bdcr.lserdy = cm_object_get_child_by_name(state->u.f4.reg.bdcr, "LSERDY"); 
    state->u.f4.fld.bdcr.lsebyp = cm_object_get_child_by_name(state->u.f4.reg.bdcr, "LSEBYP"); 
    state->u.f4.fld.bdcr.rtcsel = cm_object_get_child_by_name(state->u.f4.reg.bdcr, "RTCSEL"); 
    state->u.f4.fld.bdcr.rtcen = cm_object_get_child_by_name(state->u.f4.reg.bdcr, "RTCEN"); 
    state->u.f4.fld.bdcr.bdrst = cm_object_get_child_by_name(state->u.f4.reg.bdcr, "BDRST");  
    
    // CSR bitfields.
    state->u.f4.fld.csr.lsion = cm_object_get_child_by_name(state->u.f4.reg.csr, "LSION"); 
    state->u.f4.fld.csr.lsirdy = cm_object_get_child_by_name(state->u.f4.reg.csr, "LSIRDY"); 
    state->u.f4.fld.csr.rmvf = cm_object_get_child_by_name(state->u.f4.reg.csr, "RMVF"); 
    state->u.f4.fld.csr.borrstf = cm_object_get_child_by_name(state->u.f4.reg.csr, "BORRSTF"); 
    state->u.f4.fld.csr.padrstf = cm_object_get_child_by_name(state->u.f4.reg.csr, "PADRSTF"); 
    state->u.f4.fld.csr.porrstf = cm_object_get_child_by_name(state->u.f4.reg.csr, "PORRSTF"); 
    state->u.f4.fld.csr.sftrstf = cm_object_get_child_by_name(state->u.f4.reg.csr, "SFTRSTF"); 
    state->u.f4.fld.csr.wdgrstf = cm_object_get_child_by_name(state->u.f4.reg.csr, "WDGRSTF"); 
    state->u.f4.fld.csr.wwdgrstf = cm_object_get_child_by_name(state->u.f4.reg.csr, "WWDGRSTF"); 
    state->u.f4.fld.csr.lpwrrstf = cm_object_get_child_by_name(state->u.f4.reg.csr, "LPWRRSTF");  
    
    // SSCGR bitfields.
    state->u.f4.fld.sscgr.modper = cm_object_get_child_by_name(state->u.f4.reg.sscgr, "MODPER"); 
    state->u.f4.fld.sscgr.incstep = cm_object_get_child_by_name(state->u.f4.reg.sscgr, "INCSTEP"); 
    state->u.f4.fld.sscgr.spreadsel = cm_object_get_child_by_name(state->u.f4.reg.sscgr, "SPREADSEL"); 
    state->u.f4.fld.sscgr.sscgen = cm_object_get_child_by_name(state->u.f4.reg.sscgr, "SSCGEN");  
    
    // PLLI2SCFGR bitfields.
    state->u.f4.fld.plli2scfgr.plli2sn = cm_object_get_child_by_name(state->u.f4.reg.plli2scfgr, "PLLI2SN"); 
    state->u.f4.fld.plli2scfgr.plli2sq = cm_object_get_child_by_name(state->u.f4.reg.plli2scfgr, "PLLI2SQ"); 
    state->u.f4.fld.plli2scfgr.plli2sr = cm_object_get_child_by_name(state->u.f4.reg.plli2scfgr, "PLLI2SR");  
    
    // PLLSAICFGR bitfields.
    state->u.f4.fld.pllsaicfgr.pllsain = cm_object_get_child_by_name(state->u.f4.reg.pllsaicfgr, "PLLSAIN"); 
    state->u.f4.fld.pllsaicfgr.pllsaiq = cm_object_get_child_by_name(state->u.f4.reg.pllsaicfgr, "PLLSAIQ"); 
    state->u.f4.fld.pllsaicfgr.pllsair = cm_object_get_child_by_name(state->u.f4.reg.pllsaicfgr, "PLLSAIR");  
    
    // DCKCFGR bitfields.
    state->u.f4.fld.dckcfgr.plli2sdivq = cm_object_get_child_by_name(state->u.f4.reg.dckcfgr, "PLLI2SDIVQ"); 
    state->u.f4.fld.dckcfgr.pllsaidivq = cm_object_get_child_by_name(state->u.f4.reg.dckcfgr, "PLLSAIDIVQ"); 
    state->u.f4.fld.dckcfgr.pllsaidivr = cm_object_get_child_by_name(state->u.f4.reg.dckcfgr, "PLLSAIDIVR"); 
    state->u.f4.fld.dckcfgr.sai1asrc = cm_object_get_child_by_name(state->u.f4.reg.dckcfgr, "SAI1ASRC"); 
    state->u.f4.fld.dckcfgr.sai1bsrc = cm_object_get_child_by_name(state->u.f4.reg.dckcfgr, "SAI1BSRC"); 
    state->u.f4.fld.dckcfgr.timpre = cm_object_get_child_by_name(state->u.f4.reg.dckcfgr, "TIMPRE");  
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
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_429x ) {

            stm32f429x_rcc_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_rcc_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_rcc_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_rcc_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_rcc_xxx_post_write_callback);

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
