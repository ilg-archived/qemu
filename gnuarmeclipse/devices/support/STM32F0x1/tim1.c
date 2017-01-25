/*
 * STM32 - TIM1 (Advanced-timers) emulation.
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

#include <hw/cortexm/stm32/tim1.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_tim1_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32TIM1State *state = STM32_TIM1_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f0.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
    state->u.f0.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
    state->u.f0.reg.smcr = cm_object_get_child_by_name(obj, "SMCR");
    state->u.f0.reg.dier = cm_object_get_child_by_name(obj, "DIER");
    state->u.f0.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->u.f0.reg.egr = cm_object_get_child_by_name(obj, "EGR");
    state->u.f0.reg.ccmr1_output = cm_object_get_child_by_name(obj, "CCMR1_Output");
    state->u.f0.reg.ccmr1_input = cm_object_get_child_by_name(obj, "CCMR1_Input");
    state->u.f0.reg.ccmr2_output = cm_object_get_child_by_name(obj, "CCMR2_Output");
    state->u.f0.reg.ccmr2_input = cm_object_get_child_by_name(obj, "CCMR2_Input");
    state->u.f0.reg.ccer = cm_object_get_child_by_name(obj, "CCER");
    state->u.f0.reg.cnt = cm_object_get_child_by_name(obj, "CNT");
    state->u.f0.reg.psc = cm_object_get_child_by_name(obj, "PSC");
    state->u.f0.reg.arr = cm_object_get_child_by_name(obj, "ARR");
    state->u.f0.reg.rcr = cm_object_get_child_by_name(obj, "RCR");
    state->u.f0.reg.ccr1 = cm_object_get_child_by_name(obj, "CCR1");
    state->u.f0.reg.ccr2 = cm_object_get_child_by_name(obj, "CCR2");
    state->u.f0.reg.ccr3 = cm_object_get_child_by_name(obj, "CCR3");
    state->u.f0.reg.ccr4 = cm_object_get_child_by_name(obj, "CCR4");
    state->u.f0.reg.bdtr = cm_object_get_child_by_name(obj, "BDTR");
    state->u.f0.reg.dcr = cm_object_get_child_by_name(obj, "DCR");
    state->u.f0.reg.dmar = cm_object_get_child_by_name(obj, "DMAR");
    
    
    // CR1 bitfields.
    state->u.f0.fld.cr1.cen = cm_object_get_child_by_name(state->u.f0.reg.cr1, "CEN"); 
    state->u.f0.fld.cr1.udis = cm_object_get_child_by_name(state->u.f0.reg.cr1, "UDIS"); 
    state->u.f0.fld.cr1.urs = cm_object_get_child_by_name(state->u.f0.reg.cr1, "URS"); 
    state->u.f0.fld.cr1.opm = cm_object_get_child_by_name(state->u.f0.reg.cr1, "OPM"); 
    state->u.f0.fld.cr1.dir = cm_object_get_child_by_name(state->u.f0.reg.cr1, "DIR"); 
    state->u.f0.fld.cr1.cms = cm_object_get_child_by_name(state->u.f0.reg.cr1, "CMS"); 
    state->u.f0.fld.cr1.arpe = cm_object_get_child_by_name(state->u.f0.reg.cr1, "ARPE"); 
    state->u.f0.fld.cr1.ckd = cm_object_get_child_by_name(state->u.f0.reg.cr1, "CKD");  
    
    // CR2 bitfields.
    state->u.f0.fld.cr2.ccpc = cm_object_get_child_by_name(state->u.f0.reg.cr2, "CCPC"); 
    state->u.f0.fld.cr2.ccus = cm_object_get_child_by_name(state->u.f0.reg.cr2, "CCUS"); 
    state->u.f0.fld.cr2.ccds = cm_object_get_child_by_name(state->u.f0.reg.cr2, "CCDS"); 
    state->u.f0.fld.cr2.mms = cm_object_get_child_by_name(state->u.f0.reg.cr2, "MMS"); 
    state->u.f0.fld.cr2.ti1s = cm_object_get_child_by_name(state->u.f0.reg.cr2, "TI1S"); 
    state->u.f0.fld.cr2.ois1 = cm_object_get_child_by_name(state->u.f0.reg.cr2, "OIS1"); 
    state->u.f0.fld.cr2.ois1n = cm_object_get_child_by_name(state->u.f0.reg.cr2, "OIS1N"); 
    state->u.f0.fld.cr2.ois2 = cm_object_get_child_by_name(state->u.f0.reg.cr2, "OIS2"); 
    state->u.f0.fld.cr2.ois2n = cm_object_get_child_by_name(state->u.f0.reg.cr2, "OIS2N"); 
    state->u.f0.fld.cr2.ois3 = cm_object_get_child_by_name(state->u.f0.reg.cr2, "OIS3"); 
    state->u.f0.fld.cr2.ois3n = cm_object_get_child_by_name(state->u.f0.reg.cr2, "OIS3N"); 
    state->u.f0.fld.cr2.ois4 = cm_object_get_child_by_name(state->u.f0.reg.cr2, "OIS4");  
    
    // SMCR bitfields.
    state->u.f0.fld.smcr.sms = cm_object_get_child_by_name(state->u.f0.reg.smcr, "SMS"); 
    state->u.f0.fld.smcr.ts = cm_object_get_child_by_name(state->u.f0.reg.smcr, "TS"); 
    state->u.f0.fld.smcr.msm = cm_object_get_child_by_name(state->u.f0.reg.smcr, "MSM"); 
    state->u.f0.fld.smcr.etf = cm_object_get_child_by_name(state->u.f0.reg.smcr, "ETF"); 
    state->u.f0.fld.smcr.etps = cm_object_get_child_by_name(state->u.f0.reg.smcr, "ETPS"); 
    state->u.f0.fld.smcr.ece = cm_object_get_child_by_name(state->u.f0.reg.smcr, "ECE"); 
    state->u.f0.fld.smcr.etp = cm_object_get_child_by_name(state->u.f0.reg.smcr, "ETP");  
    
    // DIER bitfields.
    state->u.f0.fld.dier.uie = cm_object_get_child_by_name(state->u.f0.reg.dier, "UIE"); 
    state->u.f0.fld.dier.cc1ie = cm_object_get_child_by_name(state->u.f0.reg.dier, "CC1IE"); 
    state->u.f0.fld.dier.cc2ie = cm_object_get_child_by_name(state->u.f0.reg.dier, "CC2IE"); 
    state->u.f0.fld.dier.cc3ie = cm_object_get_child_by_name(state->u.f0.reg.dier, "CC3IE"); 
    state->u.f0.fld.dier.cc4ie = cm_object_get_child_by_name(state->u.f0.reg.dier, "CC4IE"); 
    state->u.f0.fld.dier.comie = cm_object_get_child_by_name(state->u.f0.reg.dier, "COMIE"); 
    state->u.f0.fld.dier.tie = cm_object_get_child_by_name(state->u.f0.reg.dier, "TIE"); 
    state->u.f0.fld.dier.bie = cm_object_get_child_by_name(state->u.f0.reg.dier, "BIE"); 
    state->u.f0.fld.dier.ude = cm_object_get_child_by_name(state->u.f0.reg.dier, "UDE"); 
    state->u.f0.fld.dier.cc1de = cm_object_get_child_by_name(state->u.f0.reg.dier, "CC1DE"); 
    state->u.f0.fld.dier.cc2de = cm_object_get_child_by_name(state->u.f0.reg.dier, "CC2DE"); 
    state->u.f0.fld.dier.cc3de = cm_object_get_child_by_name(state->u.f0.reg.dier, "CC3DE"); 
    state->u.f0.fld.dier.cc4de = cm_object_get_child_by_name(state->u.f0.reg.dier, "CC4DE"); 
    state->u.f0.fld.dier.comde = cm_object_get_child_by_name(state->u.f0.reg.dier, "COMDE"); 
    state->u.f0.fld.dier.tde = cm_object_get_child_by_name(state->u.f0.reg.dier, "TDE");  
    
    // SR bitfields.
    state->u.f0.fld.sr.uif = cm_object_get_child_by_name(state->u.f0.reg.sr, "UIF"); 
    state->u.f0.fld.sr.cc1if = cm_object_get_child_by_name(state->u.f0.reg.sr, "CC1IF"); 
    state->u.f0.fld.sr.cc2if = cm_object_get_child_by_name(state->u.f0.reg.sr, "CC2IF"); 
    state->u.f0.fld.sr.cc3if = cm_object_get_child_by_name(state->u.f0.reg.sr, "CC3IF"); 
    state->u.f0.fld.sr.cc4if = cm_object_get_child_by_name(state->u.f0.reg.sr, "CC4IF"); 
    state->u.f0.fld.sr.comif = cm_object_get_child_by_name(state->u.f0.reg.sr, "COMIF"); 
    state->u.f0.fld.sr.tif = cm_object_get_child_by_name(state->u.f0.reg.sr, "TIF"); 
    state->u.f0.fld.sr.bif = cm_object_get_child_by_name(state->u.f0.reg.sr, "BIF"); 
    state->u.f0.fld.sr.cc1of = cm_object_get_child_by_name(state->u.f0.reg.sr, "CC1OF"); 
    state->u.f0.fld.sr.cc2of = cm_object_get_child_by_name(state->u.f0.reg.sr, "CC2OF"); 
    state->u.f0.fld.sr.cc3of = cm_object_get_child_by_name(state->u.f0.reg.sr, "CC3OF"); 
    state->u.f0.fld.sr.cc4of = cm_object_get_child_by_name(state->u.f0.reg.sr, "CC4OF");  
    
    // EGR bitfields.
    state->u.f0.fld.egr.ug = cm_object_get_child_by_name(state->u.f0.reg.egr, "UG"); 
    state->u.f0.fld.egr.cc1g = cm_object_get_child_by_name(state->u.f0.reg.egr, "CC1G"); 
    state->u.f0.fld.egr.cc2g = cm_object_get_child_by_name(state->u.f0.reg.egr, "CC2G"); 
    state->u.f0.fld.egr.cc3g = cm_object_get_child_by_name(state->u.f0.reg.egr, "CC3G"); 
    state->u.f0.fld.egr.cc4g = cm_object_get_child_by_name(state->u.f0.reg.egr, "CC4G"); 
    state->u.f0.fld.egr.comg = cm_object_get_child_by_name(state->u.f0.reg.egr, "COMG"); 
    state->u.f0.fld.egr.tg = cm_object_get_child_by_name(state->u.f0.reg.egr, "TG"); 
    state->u.f0.fld.egr.bg = cm_object_get_child_by_name(state->u.f0.reg.egr, "BG");  
    
    // CCMR1_Output bitfields.
    state->u.f0.fld.ccmr1_output.cc1s = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_output, "CC1S"); 
    state->u.f0.fld.ccmr1_output.oc1fe = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_output, "OC1FE"); 
    state->u.f0.fld.ccmr1_output.oc1pe = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_output, "OC1PE"); 
    state->u.f0.fld.ccmr1_output.oc1m = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_output, "OC1M"); 
    state->u.f0.fld.ccmr1_output.oc1ce = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_output, "OC1CE"); 
    state->u.f0.fld.ccmr1_output.cc2s = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_output, "CC2S"); 
    state->u.f0.fld.ccmr1_output.oc2fe = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_output, "OC2FE"); 
    state->u.f0.fld.ccmr1_output.oc2pe = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_output, "OC2PE"); 
    state->u.f0.fld.ccmr1_output.oc2m = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_output, "OC2M"); 
    state->u.f0.fld.ccmr1_output.oc2ce = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_output, "OC2CE");  
    
    // CCMR1_Input bitfields.
    state->u.f0.fld.ccmr1_input.cc1s = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_input, "CC1S"); 
    state->u.f0.fld.ccmr1_input.ic1pcs = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_input, "IC1PCS"); 
    state->u.f0.fld.ccmr1_input.ic1f = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_input, "IC1F"); 
    state->u.f0.fld.ccmr1_input.cc2s = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_input, "CC2S"); 
    state->u.f0.fld.ccmr1_input.ic2pcs = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_input, "IC2PCS"); 
    state->u.f0.fld.ccmr1_input.ic2f = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_input, "IC2F");  
    
    // CCMR2_Output bitfields.
    state->u.f0.fld.ccmr2_output.cc3s = cm_object_get_child_by_name(state->u.f0.reg.ccmr2_output, "CC3S"); 
    state->u.f0.fld.ccmr2_output.oc3fe = cm_object_get_child_by_name(state->u.f0.reg.ccmr2_output, "OC3FE"); 
    state->u.f0.fld.ccmr2_output.oc3pe = cm_object_get_child_by_name(state->u.f0.reg.ccmr2_output, "OC3PE"); 
    state->u.f0.fld.ccmr2_output.oc3m = cm_object_get_child_by_name(state->u.f0.reg.ccmr2_output, "OC3M"); 
    state->u.f0.fld.ccmr2_output.oc3ce = cm_object_get_child_by_name(state->u.f0.reg.ccmr2_output, "OC3CE"); 
    state->u.f0.fld.ccmr2_output.cc4s = cm_object_get_child_by_name(state->u.f0.reg.ccmr2_output, "CC4S"); 
    state->u.f0.fld.ccmr2_output.oc4fe = cm_object_get_child_by_name(state->u.f0.reg.ccmr2_output, "OC4FE"); 
    state->u.f0.fld.ccmr2_output.oc4pe = cm_object_get_child_by_name(state->u.f0.reg.ccmr2_output, "OC4PE"); 
    state->u.f0.fld.ccmr2_output.oc4m = cm_object_get_child_by_name(state->u.f0.reg.ccmr2_output, "OC4M"); 
    state->u.f0.fld.ccmr2_output.oc4ce = cm_object_get_child_by_name(state->u.f0.reg.ccmr2_output, "OC4CE");  
    
    // CCMR2_Input bitfields.
    state->u.f0.fld.ccmr2_input.cc3s = cm_object_get_child_by_name(state->u.f0.reg.ccmr2_input, "CC3S"); 
    state->u.f0.fld.ccmr2_input.ic3psc = cm_object_get_child_by_name(state->u.f0.reg.ccmr2_input, "IC3PSC"); 
    state->u.f0.fld.ccmr2_input.ic3f = cm_object_get_child_by_name(state->u.f0.reg.ccmr2_input, "IC3F"); 
    state->u.f0.fld.ccmr2_input.cc4s = cm_object_get_child_by_name(state->u.f0.reg.ccmr2_input, "CC4S"); 
    state->u.f0.fld.ccmr2_input.ic4psc = cm_object_get_child_by_name(state->u.f0.reg.ccmr2_input, "IC4PSC"); 
    state->u.f0.fld.ccmr2_input.ic4f = cm_object_get_child_by_name(state->u.f0.reg.ccmr2_input, "IC4F");  
    
    // CCER bitfields.
    state->u.f0.fld.ccer.cc1e = cm_object_get_child_by_name(state->u.f0.reg.ccer, "CC1E"); 
    state->u.f0.fld.ccer.cc1p = cm_object_get_child_by_name(state->u.f0.reg.ccer, "CC1P"); 
    state->u.f0.fld.ccer.cc1ne = cm_object_get_child_by_name(state->u.f0.reg.ccer, "CC1NE"); 
    state->u.f0.fld.ccer.cc1np = cm_object_get_child_by_name(state->u.f0.reg.ccer, "CC1NP"); 
    state->u.f0.fld.ccer.cc2e = cm_object_get_child_by_name(state->u.f0.reg.ccer, "CC2E"); 
    state->u.f0.fld.ccer.cc2p = cm_object_get_child_by_name(state->u.f0.reg.ccer, "CC2P"); 
    state->u.f0.fld.ccer.cc2ne = cm_object_get_child_by_name(state->u.f0.reg.ccer, "CC2NE"); 
    state->u.f0.fld.ccer.cc2np = cm_object_get_child_by_name(state->u.f0.reg.ccer, "CC2NP"); 
    state->u.f0.fld.ccer.cc3e = cm_object_get_child_by_name(state->u.f0.reg.ccer, "CC3E"); 
    state->u.f0.fld.ccer.cc3p = cm_object_get_child_by_name(state->u.f0.reg.ccer, "CC3P"); 
    state->u.f0.fld.ccer.cc3ne = cm_object_get_child_by_name(state->u.f0.reg.ccer, "CC3NE"); 
    state->u.f0.fld.ccer.cc3np = cm_object_get_child_by_name(state->u.f0.reg.ccer, "CC3NP"); 
    state->u.f0.fld.ccer.cc4e = cm_object_get_child_by_name(state->u.f0.reg.ccer, "CC4E"); 
    state->u.f0.fld.ccer.cc4p = cm_object_get_child_by_name(state->u.f0.reg.ccer, "CC4P");  
    
    // CNT bitfields.
    state->u.f0.fld.cnt.cnt = cm_object_get_child_by_name(state->u.f0.reg.cnt, "CNT");  
    
    // PSC bitfields.
    state->u.f0.fld.psc.psc = cm_object_get_child_by_name(state->u.f0.reg.psc, "PSC");  
    
    // ARR bitfields.
    state->u.f0.fld.arr.arr = cm_object_get_child_by_name(state->u.f0.reg.arr, "ARR");  
    
    // RCR bitfields.
    state->u.f0.fld.rcr.rep = cm_object_get_child_by_name(state->u.f0.reg.rcr, "REP");  
    
    // CCR1 bitfields.
    state->u.f0.fld.ccr1.ccr1 = cm_object_get_child_by_name(state->u.f0.reg.ccr1, "CCR1");  
    
    // CCR2 bitfields.
    state->u.f0.fld.ccr2.ccr2 = cm_object_get_child_by_name(state->u.f0.reg.ccr2, "CCR2");  
    
    // CCR3 bitfields.
    state->u.f0.fld.ccr3.ccr3 = cm_object_get_child_by_name(state->u.f0.reg.ccr3, "CCR3");  
    
    // CCR4 bitfields.
    state->u.f0.fld.ccr4.ccr4 = cm_object_get_child_by_name(state->u.f0.reg.ccr4, "CCR4");  
    
    // BDTR bitfields.
    state->u.f0.fld.bdtr.dtg = cm_object_get_child_by_name(state->u.f0.reg.bdtr, "DTG"); 
    state->u.f0.fld.bdtr.lock = cm_object_get_child_by_name(state->u.f0.reg.bdtr, "LOCK"); 
    state->u.f0.fld.bdtr.ossi = cm_object_get_child_by_name(state->u.f0.reg.bdtr, "OSSI"); 
    state->u.f0.fld.bdtr.ossr = cm_object_get_child_by_name(state->u.f0.reg.bdtr, "OSSR"); 
    state->u.f0.fld.bdtr.bke = cm_object_get_child_by_name(state->u.f0.reg.bdtr, "BKE"); 
    state->u.f0.fld.bdtr.bkp = cm_object_get_child_by_name(state->u.f0.reg.bdtr, "BKP"); 
    state->u.f0.fld.bdtr.aoe = cm_object_get_child_by_name(state->u.f0.reg.bdtr, "AOE"); 
    state->u.f0.fld.bdtr.moe = cm_object_get_child_by_name(state->u.f0.reg.bdtr, "MOE");  
    
    // DCR bitfields.
    state->u.f0.fld.dcr.dba = cm_object_get_child_by_name(state->u.f0.reg.dcr, "DBA"); 
    state->u.f0.fld.dcr.dbl = cm_object_get_child_by_name(state->u.f0.reg.dcr, "DBL");  
    
    // DMAR bitfields.
    state->u.f0.fld.dmar.dmab = cm_object_get_child_by_name(state->u.f0.reg.dmar, "DMAB");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_tim1_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32TIM1State *state = STM32_TIM1_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_tim1_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32TIM1State *state = STM32_TIM1_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_tim1_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32TIM1State *state = STM32_TIM1_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_tim1_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32TIM1State *state = STM32_TIM1_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_tim1_is_enabled(Object *obj)
{
    STM32TIM1State *state = STM32_TIM1_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_tim1_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32TIM1State *state = STM32_TIM1_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_tim1_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_TIM1)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32TIM1State *state = STM32_TIM1_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "TIM1";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x1 ) {

            stm32f0x1_tim1_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_tim1_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f0.reg.xxx, &stm32_tim1_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_tim1_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f0.reg.xxx, &stm32_tim1_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/TIM1EN");


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

static void stm32_tim1_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_TIM1);
}

static void stm32_tim1_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_tim1_reset_callback;
    dc->realize = stm32_tim1_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_tim1_is_enabled;
}

static const TypeInfo stm32_tim1_type_info = {
    .name = TYPE_STM32_TIM1,
    .parent = TYPE_STM32_TIM1_PARENT,
    .instance_init = stm32_tim1_instance_init_callback,
    .instance_size = sizeof(STM32TIM1State),
    .class_init = stm32_tim1_class_init_callback,
    .class_size = sizeof(STM32TIM1Class) };

static void stm32_tim1_register_types(void)
{
    type_register_static(&stm32_tim1_type_info);
}

type_init(stm32_tim1_register_types);

// ----------------------------------------------------------------------------
