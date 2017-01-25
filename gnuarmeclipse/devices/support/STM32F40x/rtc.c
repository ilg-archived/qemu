/*
 * STM32 - RTC (Real-time clock) emulation.
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

#include <hw/cortexm/stm32/rtc.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f40x_rtc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32RTCState *state = STM32_RTC_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.tr = cm_object_get_child_by_name(obj, "TR");
    state->u.f4.reg.dr = cm_object_get_child_by_name(obj, "DR");
    state->u.f4.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->u.f4.reg.isr = cm_object_get_child_by_name(obj, "ISR");
    state->u.f4.reg.prer = cm_object_get_child_by_name(obj, "PRER");
    state->u.f4.reg.wutr = cm_object_get_child_by_name(obj, "WUTR");
    state->u.f4.reg.calibr = cm_object_get_child_by_name(obj, "CALIBR");
    state->u.f4.reg.alrmar = cm_object_get_child_by_name(obj, "ALRMAR");
    state->u.f4.reg.alrmbr = cm_object_get_child_by_name(obj, "ALRMBR");
    state->u.f4.reg.wpr = cm_object_get_child_by_name(obj, "WPR");
    state->u.f4.reg.ssr = cm_object_get_child_by_name(obj, "SSR");
    state->u.f4.reg.shiftr = cm_object_get_child_by_name(obj, "SHIFTR");
    state->u.f4.reg.tstr = cm_object_get_child_by_name(obj, "TSTR");
    state->u.f4.reg.tsdr = cm_object_get_child_by_name(obj, "TSDR");
    state->u.f4.reg.tsssr = cm_object_get_child_by_name(obj, "TSSSR");
    state->u.f4.reg.calr = cm_object_get_child_by_name(obj, "CALR");
    state->u.f4.reg.tafcr = cm_object_get_child_by_name(obj, "TAFCR");
    state->u.f4.reg.alrmassr = cm_object_get_child_by_name(obj, "ALRMASSR");
    state->u.f4.reg.alrmbssr = cm_object_get_child_by_name(obj, "ALRMBSSR");
    state->u.f4.reg.bkp0r = cm_object_get_child_by_name(obj, "BKP0R");
    state->u.f4.reg.bkp1r = cm_object_get_child_by_name(obj, "BKP1R");
    state->u.f4.reg.bkp2r = cm_object_get_child_by_name(obj, "BKP2R");
    state->u.f4.reg.bkp3r = cm_object_get_child_by_name(obj, "BKP3R");
    state->u.f4.reg.bkp4r = cm_object_get_child_by_name(obj, "BKP4R");
    state->u.f4.reg.bkp5r = cm_object_get_child_by_name(obj, "BKP5R");
    state->u.f4.reg.bkp6r = cm_object_get_child_by_name(obj, "BKP6R");
    state->u.f4.reg.bkp7r = cm_object_get_child_by_name(obj, "BKP7R");
    state->u.f4.reg.bkp8r = cm_object_get_child_by_name(obj, "BKP8R");
    state->u.f4.reg.bkp9r = cm_object_get_child_by_name(obj, "BKP9R");
    state->u.f4.reg.bkp10r = cm_object_get_child_by_name(obj, "BKP10R");
    state->u.f4.reg.bkp11r = cm_object_get_child_by_name(obj, "BKP11R");
    state->u.f4.reg.bkp12r = cm_object_get_child_by_name(obj, "BKP12R");
    state->u.f4.reg.bkp13r = cm_object_get_child_by_name(obj, "BKP13R");
    state->u.f4.reg.bkp14r = cm_object_get_child_by_name(obj, "BKP14R");
    state->u.f4.reg.bkp15r = cm_object_get_child_by_name(obj, "BKP15R");
    state->u.f4.reg.bkp16r = cm_object_get_child_by_name(obj, "BKP16R");
    state->u.f4.reg.bkp17r = cm_object_get_child_by_name(obj, "BKP17R");
    state->u.f4.reg.bkp18r = cm_object_get_child_by_name(obj, "BKP18R");
    state->u.f4.reg.bkp19r = cm_object_get_child_by_name(obj, "BKP19R");
    
    
    // TR bitfields.
    state->u.f4.fld.tr.su = cm_object_get_child_by_name(state->u.f4.reg.tr, "SU"); 
    state->u.f4.fld.tr.st = cm_object_get_child_by_name(state->u.f4.reg.tr, "ST"); 
    state->u.f4.fld.tr.mnu = cm_object_get_child_by_name(state->u.f4.reg.tr, "MNU"); 
    state->u.f4.fld.tr.mnt = cm_object_get_child_by_name(state->u.f4.reg.tr, "MNT"); 
    state->u.f4.fld.tr.hu = cm_object_get_child_by_name(state->u.f4.reg.tr, "HU"); 
    state->u.f4.fld.tr.ht = cm_object_get_child_by_name(state->u.f4.reg.tr, "HT"); 
    state->u.f4.fld.tr.pm = cm_object_get_child_by_name(state->u.f4.reg.tr, "PM");  
    
    // DR bitfields.
    state->u.f4.fld.dr.du = cm_object_get_child_by_name(state->u.f4.reg.dr, "DU"); 
    state->u.f4.fld.dr.dt = cm_object_get_child_by_name(state->u.f4.reg.dr, "DT"); 
    state->u.f4.fld.dr.mu = cm_object_get_child_by_name(state->u.f4.reg.dr, "MU"); 
    state->u.f4.fld.dr.mt = cm_object_get_child_by_name(state->u.f4.reg.dr, "MT"); 
    state->u.f4.fld.dr.wdu = cm_object_get_child_by_name(state->u.f4.reg.dr, "WDU"); 
    state->u.f4.fld.dr.yu = cm_object_get_child_by_name(state->u.f4.reg.dr, "YU"); 
    state->u.f4.fld.dr.yt = cm_object_get_child_by_name(state->u.f4.reg.dr, "YT");  
    
    // CR bitfields.
    state->u.f4.fld.cr.wcksel = cm_object_get_child_by_name(state->u.f4.reg.cr, "WCKSEL"); 
    state->u.f4.fld.cr.tsedge = cm_object_get_child_by_name(state->u.f4.reg.cr, "TSEDGE"); 
    state->u.f4.fld.cr.refckon = cm_object_get_child_by_name(state->u.f4.reg.cr, "REFCKON"); 
    state->u.f4.fld.cr.fmt = cm_object_get_child_by_name(state->u.f4.reg.cr, "FMT"); 
    state->u.f4.fld.cr.dce = cm_object_get_child_by_name(state->u.f4.reg.cr, "DCE"); 
    state->u.f4.fld.cr.alrae = cm_object_get_child_by_name(state->u.f4.reg.cr, "ALRAE"); 
    state->u.f4.fld.cr.alrbe = cm_object_get_child_by_name(state->u.f4.reg.cr, "ALRBE"); 
    state->u.f4.fld.cr.wute = cm_object_get_child_by_name(state->u.f4.reg.cr, "WUTE"); 
    state->u.f4.fld.cr.tse = cm_object_get_child_by_name(state->u.f4.reg.cr, "TSE"); 
    state->u.f4.fld.cr.alraie = cm_object_get_child_by_name(state->u.f4.reg.cr, "ALRAIE"); 
    state->u.f4.fld.cr.alrbie = cm_object_get_child_by_name(state->u.f4.reg.cr, "ALRBIE"); 
    state->u.f4.fld.cr.wutie = cm_object_get_child_by_name(state->u.f4.reg.cr, "WUTIE"); 
    state->u.f4.fld.cr.tsie = cm_object_get_child_by_name(state->u.f4.reg.cr, "TSIE"); 
    state->u.f4.fld.cr.add1h = cm_object_get_child_by_name(state->u.f4.reg.cr, "ADD1H"); 
    state->u.f4.fld.cr.sub1h = cm_object_get_child_by_name(state->u.f4.reg.cr, "SUB1H"); 
    state->u.f4.fld.cr.bkp = cm_object_get_child_by_name(state->u.f4.reg.cr, "BKP"); 
    state->u.f4.fld.cr.pol = cm_object_get_child_by_name(state->u.f4.reg.cr, "POL"); 
    state->u.f4.fld.cr.osel = cm_object_get_child_by_name(state->u.f4.reg.cr, "OSEL"); 
    state->u.f4.fld.cr.coe = cm_object_get_child_by_name(state->u.f4.reg.cr, "COE");  
    
    // ISR bitfields.
    state->u.f4.fld.isr.alrawf = cm_object_get_child_by_name(state->u.f4.reg.isr, "ALRAWF"); 
    state->u.f4.fld.isr.alrbwf = cm_object_get_child_by_name(state->u.f4.reg.isr, "ALRBWF"); 
    state->u.f4.fld.isr.wutwf = cm_object_get_child_by_name(state->u.f4.reg.isr, "WUTWF"); 
    state->u.f4.fld.isr.shpf = cm_object_get_child_by_name(state->u.f4.reg.isr, "SHPF"); 
    state->u.f4.fld.isr.inits = cm_object_get_child_by_name(state->u.f4.reg.isr, "INITS"); 
    state->u.f4.fld.isr.rsf = cm_object_get_child_by_name(state->u.f4.reg.isr, "RSF"); 
    state->u.f4.fld.isr.initf = cm_object_get_child_by_name(state->u.f4.reg.isr, "INITF"); 
    state->u.f4.fld.isr.init = cm_object_get_child_by_name(state->u.f4.reg.isr, "INIT"); 
    state->u.f4.fld.isr.alraf = cm_object_get_child_by_name(state->u.f4.reg.isr, "ALRAF"); 
    state->u.f4.fld.isr.alrbf = cm_object_get_child_by_name(state->u.f4.reg.isr, "ALRBF"); 
    state->u.f4.fld.isr.wutf = cm_object_get_child_by_name(state->u.f4.reg.isr, "WUTF"); 
    state->u.f4.fld.isr.tsf = cm_object_get_child_by_name(state->u.f4.reg.isr, "TSF"); 
    state->u.f4.fld.isr.tsovf = cm_object_get_child_by_name(state->u.f4.reg.isr, "TSOVF"); 
    state->u.f4.fld.isr.tamp1f = cm_object_get_child_by_name(state->u.f4.reg.isr, "TAMP1F"); 
    state->u.f4.fld.isr.tamp2f = cm_object_get_child_by_name(state->u.f4.reg.isr, "TAMP2F"); 
    state->u.f4.fld.isr.recalpf = cm_object_get_child_by_name(state->u.f4.reg.isr, "RECALPF");  
    
    // PRER bitfields.
    state->u.f4.fld.prer.prediv_s = cm_object_get_child_by_name(state->u.f4.reg.prer, "PREDIV_S"); 
    state->u.f4.fld.prer.prediv_a = cm_object_get_child_by_name(state->u.f4.reg.prer, "PREDIV_A");  
    
    // WUTR bitfields.
    state->u.f4.fld.wutr.wut = cm_object_get_child_by_name(state->u.f4.reg.wutr, "WUT");  
    
    // CALIBR bitfields.
    state->u.f4.fld.calibr.dc = cm_object_get_child_by_name(state->u.f4.reg.calibr, "DC"); 
    state->u.f4.fld.calibr.dcs = cm_object_get_child_by_name(state->u.f4.reg.calibr, "DCS");  
    
    // ALRMAR bitfields.
    state->u.f4.fld.alrmar.su = cm_object_get_child_by_name(state->u.f4.reg.alrmar, "SU"); 
    state->u.f4.fld.alrmar.st = cm_object_get_child_by_name(state->u.f4.reg.alrmar, "ST"); 
    state->u.f4.fld.alrmar.msk1 = cm_object_get_child_by_name(state->u.f4.reg.alrmar, "MSK1"); 
    state->u.f4.fld.alrmar.mnu = cm_object_get_child_by_name(state->u.f4.reg.alrmar, "MNU"); 
    state->u.f4.fld.alrmar.mnt = cm_object_get_child_by_name(state->u.f4.reg.alrmar, "MNT"); 
    state->u.f4.fld.alrmar.msk2 = cm_object_get_child_by_name(state->u.f4.reg.alrmar, "MSK2"); 
    state->u.f4.fld.alrmar.hu = cm_object_get_child_by_name(state->u.f4.reg.alrmar, "HU"); 
    state->u.f4.fld.alrmar.ht = cm_object_get_child_by_name(state->u.f4.reg.alrmar, "HT"); 
    state->u.f4.fld.alrmar.pm = cm_object_get_child_by_name(state->u.f4.reg.alrmar, "PM"); 
    state->u.f4.fld.alrmar.msk3 = cm_object_get_child_by_name(state->u.f4.reg.alrmar, "MSK3"); 
    state->u.f4.fld.alrmar.du = cm_object_get_child_by_name(state->u.f4.reg.alrmar, "DU"); 
    state->u.f4.fld.alrmar.dt = cm_object_get_child_by_name(state->u.f4.reg.alrmar, "DT"); 
    state->u.f4.fld.alrmar.wdsel = cm_object_get_child_by_name(state->u.f4.reg.alrmar, "WDSEL"); 
    state->u.f4.fld.alrmar.msk4 = cm_object_get_child_by_name(state->u.f4.reg.alrmar, "MSK4");  
    
    // ALRMBR bitfields.
    state->u.f4.fld.alrmbr.su = cm_object_get_child_by_name(state->u.f4.reg.alrmbr, "SU"); 
    state->u.f4.fld.alrmbr.st = cm_object_get_child_by_name(state->u.f4.reg.alrmbr, "ST"); 
    state->u.f4.fld.alrmbr.msk1 = cm_object_get_child_by_name(state->u.f4.reg.alrmbr, "MSK1"); 
    state->u.f4.fld.alrmbr.mnu = cm_object_get_child_by_name(state->u.f4.reg.alrmbr, "MNU"); 
    state->u.f4.fld.alrmbr.mnt = cm_object_get_child_by_name(state->u.f4.reg.alrmbr, "MNT"); 
    state->u.f4.fld.alrmbr.msk2 = cm_object_get_child_by_name(state->u.f4.reg.alrmbr, "MSK2"); 
    state->u.f4.fld.alrmbr.hu = cm_object_get_child_by_name(state->u.f4.reg.alrmbr, "HU"); 
    state->u.f4.fld.alrmbr.ht = cm_object_get_child_by_name(state->u.f4.reg.alrmbr, "HT"); 
    state->u.f4.fld.alrmbr.pm = cm_object_get_child_by_name(state->u.f4.reg.alrmbr, "PM"); 
    state->u.f4.fld.alrmbr.msk3 = cm_object_get_child_by_name(state->u.f4.reg.alrmbr, "MSK3"); 
    state->u.f4.fld.alrmbr.du = cm_object_get_child_by_name(state->u.f4.reg.alrmbr, "DU"); 
    state->u.f4.fld.alrmbr.dt = cm_object_get_child_by_name(state->u.f4.reg.alrmbr, "DT"); 
    state->u.f4.fld.alrmbr.wdsel = cm_object_get_child_by_name(state->u.f4.reg.alrmbr, "WDSEL"); 
    state->u.f4.fld.alrmbr.msk4 = cm_object_get_child_by_name(state->u.f4.reg.alrmbr, "MSK4");  
    
    // WPR bitfields.
    state->u.f4.fld.wpr.key = cm_object_get_child_by_name(state->u.f4.reg.wpr, "KEY");  
    
    // SSR bitfields.
    state->u.f4.fld.ssr.ss = cm_object_get_child_by_name(state->u.f4.reg.ssr, "SS");  
    
    // SHIFTR bitfields.
    state->u.f4.fld.shiftr.subfs = cm_object_get_child_by_name(state->u.f4.reg.shiftr, "SUBFS"); 
    state->u.f4.fld.shiftr.add1s = cm_object_get_child_by_name(state->u.f4.reg.shiftr, "ADD1S");  
    
    // TSTR bitfields.
    state->u.f4.fld.tstr.tamp1e = cm_object_get_child_by_name(state->u.f4.reg.tstr, "TAMP1E"); 
    state->u.f4.fld.tstr.tamp1trg = cm_object_get_child_by_name(state->u.f4.reg.tstr, "TAMP1TRG"); 
    state->u.f4.fld.tstr.tampie = cm_object_get_child_by_name(state->u.f4.reg.tstr, "TAMPIE"); 
    state->u.f4.fld.tstr.tamp1insel = cm_object_get_child_by_name(state->u.f4.reg.tstr, "TAMP1INSEL"); 
    state->u.f4.fld.tstr.tsinsel = cm_object_get_child_by_name(state->u.f4.reg.tstr, "TSINSEL"); 
    state->u.f4.fld.tstr.alarmouttype = cm_object_get_child_by_name(state->u.f4.reg.tstr, "ALARMOUTTYPE");  
    
    // TSDR bitfields.
    state->u.f4.fld.tsdr.du = cm_object_get_child_by_name(state->u.f4.reg.tsdr, "DU"); 
    state->u.f4.fld.tsdr.dt = cm_object_get_child_by_name(state->u.f4.reg.tsdr, "DT"); 
    state->u.f4.fld.tsdr.mu = cm_object_get_child_by_name(state->u.f4.reg.tsdr, "MU"); 
    state->u.f4.fld.tsdr.mt = cm_object_get_child_by_name(state->u.f4.reg.tsdr, "MT"); 
    state->u.f4.fld.tsdr.wdu = cm_object_get_child_by_name(state->u.f4.reg.tsdr, "WDU");  
    
    // TSSSR bitfields.
    state->u.f4.fld.tsssr.ss = cm_object_get_child_by_name(state->u.f4.reg.tsssr, "SS");  
    
    // CALR bitfields.
    state->u.f4.fld.calr.calm = cm_object_get_child_by_name(state->u.f4.reg.calr, "CALM"); 
    state->u.f4.fld.calr.calw16 = cm_object_get_child_by_name(state->u.f4.reg.calr, "CALW16"); 
    state->u.f4.fld.calr.calw8 = cm_object_get_child_by_name(state->u.f4.reg.calr, "CALW8"); 
    state->u.f4.fld.calr.calp = cm_object_get_child_by_name(state->u.f4.reg.calr, "CALP");  
    
    // TAFCR bitfields.
    state->u.f4.fld.tafcr.tamp1e = cm_object_get_child_by_name(state->u.f4.reg.tafcr, "TAMP1E"); 
    state->u.f4.fld.tafcr.tamp1trg = cm_object_get_child_by_name(state->u.f4.reg.tafcr, "TAMP1TRG"); 
    state->u.f4.fld.tafcr.tampie = cm_object_get_child_by_name(state->u.f4.reg.tafcr, "TAMPIE"); 
    state->u.f4.fld.tafcr.tamp2e = cm_object_get_child_by_name(state->u.f4.reg.tafcr, "TAMP2E"); 
    state->u.f4.fld.tafcr.tamp2trg = cm_object_get_child_by_name(state->u.f4.reg.tafcr, "TAMP2TRG"); 
    state->u.f4.fld.tafcr.tampts = cm_object_get_child_by_name(state->u.f4.reg.tafcr, "TAMPTS"); 
    state->u.f4.fld.tafcr.tampfreq = cm_object_get_child_by_name(state->u.f4.reg.tafcr, "TAMPFREQ"); 
    state->u.f4.fld.tafcr.tampflt = cm_object_get_child_by_name(state->u.f4.reg.tafcr, "TAMPFLT"); 
    state->u.f4.fld.tafcr.tampprch = cm_object_get_child_by_name(state->u.f4.reg.tafcr, "TAMPPRCH"); 
    state->u.f4.fld.tafcr.tamppudis = cm_object_get_child_by_name(state->u.f4.reg.tafcr, "TAMPPUDIS"); 
    state->u.f4.fld.tafcr.tamp1insel = cm_object_get_child_by_name(state->u.f4.reg.tafcr, "TAMP1INSEL"); 
    state->u.f4.fld.tafcr.tsinsel = cm_object_get_child_by_name(state->u.f4.reg.tafcr, "TSINSEL"); 
    state->u.f4.fld.tafcr.alarmouttype = cm_object_get_child_by_name(state->u.f4.reg.tafcr, "ALARMOUTTYPE");  
    
    // ALRMASSR bitfields.
    state->u.f4.fld.alrmassr.ss = cm_object_get_child_by_name(state->u.f4.reg.alrmassr, "SS"); 
    state->u.f4.fld.alrmassr.maskss = cm_object_get_child_by_name(state->u.f4.reg.alrmassr, "MASKSS");  
    
    // ALRMBSSR bitfields.
    state->u.f4.fld.alrmbssr.ss = cm_object_get_child_by_name(state->u.f4.reg.alrmbssr, "SS"); 
    state->u.f4.fld.alrmbssr.maskss = cm_object_get_child_by_name(state->u.f4.reg.alrmbssr, "MASKSS");  
    
    // BKP0R bitfields.
    state->u.f4.fld.bkp0r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp0r, "BKP");  
    
    // BKP1R bitfields.
    state->u.f4.fld.bkp1r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp1r, "BKP");  
    
    // BKP2R bitfields.
    state->u.f4.fld.bkp2r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp2r, "BKP");  
    
    // BKP3R bitfields.
    state->u.f4.fld.bkp3r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp3r, "BKP");  
    
    // BKP4R bitfields.
    state->u.f4.fld.bkp4r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp4r, "BKP");  
    
    // BKP5R bitfields.
    state->u.f4.fld.bkp5r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp5r, "BKP");  
    
    // BKP6R bitfields.
    state->u.f4.fld.bkp6r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp6r, "BKP");  
    
    // BKP7R bitfields.
    state->u.f4.fld.bkp7r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp7r, "BKP");  
    
    // BKP8R bitfields.
    state->u.f4.fld.bkp8r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp8r, "BKP");  
    
    // BKP9R bitfields.
    state->u.f4.fld.bkp9r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp9r, "BKP");  
    
    // BKP10R bitfields.
    state->u.f4.fld.bkp10r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp10r, "BKP");  
    
    // BKP11R bitfields.
    state->u.f4.fld.bkp11r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp11r, "BKP");  
    
    // BKP12R bitfields.
    state->u.f4.fld.bkp12r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp12r, "BKP");  
    
    // BKP13R bitfields.
    state->u.f4.fld.bkp13r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp13r, "BKP");  
    
    // BKP14R bitfields.
    state->u.f4.fld.bkp14r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp14r, "BKP");  
    
    // BKP15R bitfields.
    state->u.f4.fld.bkp15r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp15r, "BKP");  
    
    // BKP16R bitfields.
    state->u.f4.fld.bkp16r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp16r, "BKP");  
    
    // BKP17R bitfields.
    state->u.f4.fld.bkp17r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp17r, "BKP");  
    
    // BKP18R bitfields.
    state->u.f4.fld.bkp18r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp18r, "BKP");  
    
    // BKP19R bitfields.
    state->u.f4.fld.bkp19r.bkp = cm_object_get_child_by_name(state->u.f4.reg.bkp19r, "BKP");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_rtc_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32RTCState *state = STM32_RTC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_rtc_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32RTCState *state = STM32_RTC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_rtc_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32RTCState *state = STM32_RTC_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_rtc_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32RTCState *state = STM32_RTC_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_rtc_is_enabled(Object *obj)
{
    STM32RTCState *state = STM32_RTC_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_rtc_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32RTCState *state = STM32_RTC_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_rtc_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_RTC)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32RTCState *state = STM32_RTC_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "RTC";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_40x ) {

            stm32f40x_rtc_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_rtc_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_rtc_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_rtc_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_rtc_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/RTCEN");


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

static void stm32_rtc_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_RTC);
}

static void stm32_rtc_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_rtc_reset_callback;
    dc->realize = stm32_rtc_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_rtc_is_enabled;
}

static const TypeInfo stm32_rtc_type_info = {
    .name = TYPE_STM32_RTC,
    .parent = TYPE_STM32_RTC_PARENT,
    .instance_init = stm32_rtc_instance_init_callback,
    .instance_size = sizeof(STM32RTCState),
    .class_init = stm32_rtc_class_init_callback,
    .class_size = sizeof(STM32RTCClass) };

static void stm32_rtc_register_types(void)
{
    type_register_static(&stm32_rtc_type_info);
}

type_init(stm32_rtc_register_types);

// ----------------------------------------------------------------------------
