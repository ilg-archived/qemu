/*
 * STM32 - OTG_FS_DEVICE (USB on the go full speed) emulation.
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

#include <hw/cortexm/stm32/otg_fs_device.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f411xx_otg_fs_device_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32OTG_FS_DEVICEState *state = STM32_OTG_FS_DEVICE_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.fs_dcfg = cm_object_get_child_by_name(obj, "FS_DCFG");
    state->u.f4.reg.fs_dctl = cm_object_get_child_by_name(obj, "FS_DCTL");
    state->u.f4.reg.fs_dsts = cm_object_get_child_by_name(obj, "FS_DSTS");
    state->u.f4.reg.fs_diepmsk = cm_object_get_child_by_name(obj, "FS_DIEPMSK");
    state->u.f4.reg.fs_doepmsk = cm_object_get_child_by_name(obj, "FS_DOEPMSK");
    state->u.f4.reg.fs_daint = cm_object_get_child_by_name(obj, "FS_DAINT");
    state->u.f4.reg.fs_daintmsk = cm_object_get_child_by_name(obj, "FS_DAINTMSK");
    state->u.f4.reg.dvbusdis = cm_object_get_child_by_name(obj, "DVBUSDIS");
    state->u.f4.reg.dvbuspulse = cm_object_get_child_by_name(obj, "DVBUSPULSE");
    state->u.f4.reg.diepempmsk = cm_object_get_child_by_name(obj, "DIEPEMPMSK");
    state->u.f4.reg.fs_diepctl0 = cm_object_get_child_by_name(obj, "FS_DIEPCTL0");
    state->u.f4.reg.diepctl1 = cm_object_get_child_by_name(obj, "DIEPCTL1");
    state->u.f4.reg.diepctl2 = cm_object_get_child_by_name(obj, "DIEPCTL2");
    state->u.f4.reg.diepctl3 = cm_object_get_child_by_name(obj, "DIEPCTL3");
    state->u.f4.reg.doepctl0 = cm_object_get_child_by_name(obj, "DOEPCTL0");
    state->u.f4.reg.doepctl1 = cm_object_get_child_by_name(obj, "DOEPCTL1");
    state->u.f4.reg.doepctl2 = cm_object_get_child_by_name(obj, "DOEPCTL2");
    state->u.f4.reg.doepctl3 = cm_object_get_child_by_name(obj, "DOEPCTL3");
    state->u.f4.reg.diepint0 = cm_object_get_child_by_name(obj, "DIEPINT0");
    state->u.f4.reg.diepint1 = cm_object_get_child_by_name(obj, "DIEPINT1");
    state->u.f4.reg.diepint2 = cm_object_get_child_by_name(obj, "DIEPINT2");
    state->u.f4.reg.diepint3 = cm_object_get_child_by_name(obj, "DIEPINT3");
    state->u.f4.reg.doepint0 = cm_object_get_child_by_name(obj, "DOEPINT0");
    state->u.f4.reg.doepint1 = cm_object_get_child_by_name(obj, "DOEPINT1");
    state->u.f4.reg.doepint2 = cm_object_get_child_by_name(obj, "DOEPINT2");
    state->u.f4.reg.doepint3 = cm_object_get_child_by_name(obj, "DOEPINT3");
    state->u.f4.reg.dieptsiz0 = cm_object_get_child_by_name(obj, "DIEPTSIZ0");
    state->u.f4.reg.doeptsiz0 = cm_object_get_child_by_name(obj, "DOEPTSIZ0");
    state->u.f4.reg.dieptsiz1 = cm_object_get_child_by_name(obj, "DIEPTSIZ1");
    state->u.f4.reg.dieptsiz2 = cm_object_get_child_by_name(obj, "DIEPTSIZ2");
    state->u.f4.reg.dieptsiz3 = cm_object_get_child_by_name(obj, "DIEPTSIZ3");
    state->u.f4.reg.dtxfsts0 = cm_object_get_child_by_name(obj, "DTXFSTS0");
    state->u.f4.reg.dtxfsts1 = cm_object_get_child_by_name(obj, "DTXFSTS1");
    state->u.f4.reg.dtxfsts2 = cm_object_get_child_by_name(obj, "DTXFSTS2");
    state->u.f4.reg.dtxfsts3 = cm_object_get_child_by_name(obj, "DTXFSTS3");
    state->u.f4.reg.doeptsiz1 = cm_object_get_child_by_name(obj, "DOEPTSIZ1");
    state->u.f4.reg.doeptsiz2 = cm_object_get_child_by_name(obj, "DOEPTSIZ2");
    state->u.f4.reg.doeptsiz3 = cm_object_get_child_by_name(obj, "DOEPTSIZ3");
    
    
    // FS_DCFG bitfields.
    state->u.f4.fld.fs_dcfg.dspd = cm_object_get_child_by_name(state->u.f4.reg.fs_dcfg, "DSPD"); 
    state->u.f4.fld.fs_dcfg.nzlsohsk = cm_object_get_child_by_name(state->u.f4.reg.fs_dcfg, "NZLSOHSK"); 
    state->u.f4.fld.fs_dcfg.dad = cm_object_get_child_by_name(state->u.f4.reg.fs_dcfg, "DAD"); 
    state->u.f4.fld.fs_dcfg.pfivl = cm_object_get_child_by_name(state->u.f4.reg.fs_dcfg, "PFIVL");  
    
    // FS_DCTL bitfields.
    state->u.f4.fld.fs_dctl.rwusig = cm_object_get_child_by_name(state->u.f4.reg.fs_dctl, "RWUSIG"); 
    state->u.f4.fld.fs_dctl.sdis = cm_object_get_child_by_name(state->u.f4.reg.fs_dctl, "SDIS"); 
    state->u.f4.fld.fs_dctl.ginsts = cm_object_get_child_by_name(state->u.f4.reg.fs_dctl, "GINSTS"); 
    state->u.f4.fld.fs_dctl.gonsts = cm_object_get_child_by_name(state->u.f4.reg.fs_dctl, "GONSTS"); 
    state->u.f4.fld.fs_dctl.tctl = cm_object_get_child_by_name(state->u.f4.reg.fs_dctl, "TCTL"); 
    state->u.f4.fld.fs_dctl.sginak = cm_object_get_child_by_name(state->u.f4.reg.fs_dctl, "SGINAK"); 
    state->u.f4.fld.fs_dctl.cginak = cm_object_get_child_by_name(state->u.f4.reg.fs_dctl, "CGINAK"); 
    state->u.f4.fld.fs_dctl.sgonak = cm_object_get_child_by_name(state->u.f4.reg.fs_dctl, "SGONAK"); 
    state->u.f4.fld.fs_dctl.cgonak = cm_object_get_child_by_name(state->u.f4.reg.fs_dctl, "CGONAK"); 
    state->u.f4.fld.fs_dctl.poprgdne = cm_object_get_child_by_name(state->u.f4.reg.fs_dctl, "POPRGDNE");  
    
    // FS_DSTS bitfields.
    state->u.f4.fld.fs_dsts.suspsts = cm_object_get_child_by_name(state->u.f4.reg.fs_dsts, "SUSPSTS"); 
    state->u.f4.fld.fs_dsts.enumspd = cm_object_get_child_by_name(state->u.f4.reg.fs_dsts, "ENUMSPD"); 
    state->u.f4.fld.fs_dsts.eerr = cm_object_get_child_by_name(state->u.f4.reg.fs_dsts, "EERR"); 
    state->u.f4.fld.fs_dsts.fnsof = cm_object_get_child_by_name(state->u.f4.reg.fs_dsts, "FNSOF");  
    
    // FS_DIEPMSK bitfields.
    state->u.f4.fld.fs_diepmsk.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.fs_diepmsk, "XFRCM"); 
    state->u.f4.fld.fs_diepmsk.epdm = cm_object_get_child_by_name(state->u.f4.reg.fs_diepmsk, "EPDM"); 
    state->u.f4.fld.fs_diepmsk.tom = cm_object_get_child_by_name(state->u.f4.reg.fs_diepmsk, "TOM"); 
    state->u.f4.fld.fs_diepmsk.ittxfemsk = cm_object_get_child_by_name(state->u.f4.reg.fs_diepmsk, "ITTXFEMSK"); 
    state->u.f4.fld.fs_diepmsk.inepnmm = cm_object_get_child_by_name(state->u.f4.reg.fs_diepmsk, "INEPNMM"); 
    state->u.f4.fld.fs_diepmsk.inepnem = cm_object_get_child_by_name(state->u.f4.reg.fs_diepmsk, "INEPNEM");  
    
    // FS_DOEPMSK bitfields.
    state->u.f4.fld.fs_doepmsk.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.fs_doepmsk, "XFRCM"); 
    state->u.f4.fld.fs_doepmsk.epdm = cm_object_get_child_by_name(state->u.f4.reg.fs_doepmsk, "EPDM"); 
    state->u.f4.fld.fs_doepmsk.stupm = cm_object_get_child_by_name(state->u.f4.reg.fs_doepmsk, "STUPM"); 
    state->u.f4.fld.fs_doepmsk.otepdm = cm_object_get_child_by_name(state->u.f4.reg.fs_doepmsk, "OTEPDM");  
    
    // FS_DAINT bitfields.
    state->u.f4.fld.fs_daint.iepint = cm_object_get_child_by_name(state->u.f4.reg.fs_daint, "IEPINT"); 
    state->u.f4.fld.fs_daint.oepint = cm_object_get_child_by_name(state->u.f4.reg.fs_daint, "OEPINT");  
    
    // FS_DAINTMSK bitfields.
    state->u.f4.fld.fs_daintmsk.iepm = cm_object_get_child_by_name(state->u.f4.reg.fs_daintmsk, "IEPM"); 
    state->u.f4.fld.fs_daintmsk.oepint = cm_object_get_child_by_name(state->u.f4.reg.fs_daintmsk, "OEPINT");  
    
    // DVBUSDIS bitfields.
    state->u.f4.fld.dvbusdis.vbusdt = cm_object_get_child_by_name(state->u.f4.reg.dvbusdis, "VBUSDT");  
    
    // DVBUSPULSE bitfields.
    state->u.f4.fld.dvbuspulse.dvbusp = cm_object_get_child_by_name(state->u.f4.reg.dvbuspulse, "DVBUSP");  
    
    // DIEPEMPMSK bitfields.
    state->u.f4.fld.diepempmsk.ineptxfem = cm_object_get_child_by_name(state->u.f4.reg.diepempmsk, "INEPTXFEM");  
    
    // FS_DIEPCTL0 bitfields.
    state->u.f4.fld.fs_diepctl0.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.fs_diepctl0, "MPSIZ"); 
    state->u.f4.fld.fs_diepctl0.usbaep = cm_object_get_child_by_name(state->u.f4.reg.fs_diepctl0, "USBAEP"); 
    state->u.f4.fld.fs_diepctl0.naksts = cm_object_get_child_by_name(state->u.f4.reg.fs_diepctl0, "NAKSTS"); 
    state->u.f4.fld.fs_diepctl0.eptyp = cm_object_get_child_by_name(state->u.f4.reg.fs_diepctl0, "EPTYP"); 
    state->u.f4.fld.fs_diepctl0.stall = cm_object_get_child_by_name(state->u.f4.reg.fs_diepctl0, "STALL"); 
    state->u.f4.fld.fs_diepctl0.txfnum = cm_object_get_child_by_name(state->u.f4.reg.fs_diepctl0, "TXFNUM"); 
    state->u.f4.fld.fs_diepctl0.cnak = cm_object_get_child_by_name(state->u.f4.reg.fs_diepctl0, "CNAK"); 
    state->u.f4.fld.fs_diepctl0.snak = cm_object_get_child_by_name(state->u.f4.reg.fs_diepctl0, "SNAK"); 
    state->u.f4.fld.fs_diepctl0.epdis = cm_object_get_child_by_name(state->u.f4.reg.fs_diepctl0, "EPDIS"); 
    state->u.f4.fld.fs_diepctl0.epena = cm_object_get_child_by_name(state->u.f4.reg.fs_diepctl0, "EPENA");  
    
    // DIEPCTL1 bitfields.
    state->u.f4.fld.diepctl1.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.diepctl1, "MPSIZ"); 
    state->u.f4.fld.diepctl1.usbaep = cm_object_get_child_by_name(state->u.f4.reg.diepctl1, "USBAEP"); 
    state->u.f4.fld.diepctl1.eonum_dpid = cm_object_get_child_by_name(state->u.f4.reg.diepctl1, "EONUM_DPID"); 
    state->u.f4.fld.diepctl1.naksts = cm_object_get_child_by_name(state->u.f4.reg.diepctl1, "NAKSTS"); 
    state->u.f4.fld.diepctl1.eptyp = cm_object_get_child_by_name(state->u.f4.reg.diepctl1, "EPTYP"); 
    state->u.f4.fld.diepctl1.stall = cm_object_get_child_by_name(state->u.f4.reg.diepctl1, "Stall"); 
    state->u.f4.fld.diepctl1.txfnum = cm_object_get_child_by_name(state->u.f4.reg.diepctl1, "TXFNUM"); 
    state->u.f4.fld.diepctl1.cnak = cm_object_get_child_by_name(state->u.f4.reg.diepctl1, "CNAK"); 
    state->u.f4.fld.diepctl1.snak = cm_object_get_child_by_name(state->u.f4.reg.diepctl1, "SNAK"); 
    state->u.f4.fld.diepctl1.sd0pid_sevnfrm = cm_object_get_child_by_name(state->u.f4.reg.diepctl1, "SD0PID_SEVNFRM"); 
    state->u.f4.fld.diepctl1.soddfrm_sd1pid = cm_object_get_child_by_name(state->u.f4.reg.diepctl1, "SODDFRM_SD1PID"); 
    state->u.f4.fld.diepctl1.epdis = cm_object_get_child_by_name(state->u.f4.reg.diepctl1, "EPDIS"); 
    state->u.f4.fld.diepctl1.epena = cm_object_get_child_by_name(state->u.f4.reg.diepctl1, "EPENA");  
    
    // DIEPCTL2 bitfields.
    state->u.f4.fld.diepctl2.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.diepctl2, "MPSIZ"); 
    state->u.f4.fld.diepctl2.usbaep = cm_object_get_child_by_name(state->u.f4.reg.diepctl2, "USBAEP"); 
    state->u.f4.fld.diepctl2.eonum_dpid = cm_object_get_child_by_name(state->u.f4.reg.diepctl2, "EONUM_DPID"); 
    state->u.f4.fld.diepctl2.naksts = cm_object_get_child_by_name(state->u.f4.reg.diepctl2, "NAKSTS"); 
    state->u.f4.fld.diepctl2.eptyp = cm_object_get_child_by_name(state->u.f4.reg.diepctl2, "EPTYP"); 
    state->u.f4.fld.diepctl2.stall = cm_object_get_child_by_name(state->u.f4.reg.diepctl2, "Stall"); 
    state->u.f4.fld.diepctl2.txfnum = cm_object_get_child_by_name(state->u.f4.reg.diepctl2, "TXFNUM"); 
    state->u.f4.fld.diepctl2.cnak = cm_object_get_child_by_name(state->u.f4.reg.diepctl2, "CNAK"); 
    state->u.f4.fld.diepctl2.snak = cm_object_get_child_by_name(state->u.f4.reg.diepctl2, "SNAK"); 
    state->u.f4.fld.diepctl2.sd0pid_sevnfrm = cm_object_get_child_by_name(state->u.f4.reg.diepctl2, "SD0PID_SEVNFRM"); 
    state->u.f4.fld.diepctl2.soddfrm = cm_object_get_child_by_name(state->u.f4.reg.diepctl2, "SODDFRM"); 
    state->u.f4.fld.diepctl2.epdis = cm_object_get_child_by_name(state->u.f4.reg.diepctl2, "EPDIS"); 
    state->u.f4.fld.diepctl2.epena = cm_object_get_child_by_name(state->u.f4.reg.diepctl2, "EPENA");  
    
    // DIEPCTL3 bitfields.
    state->u.f4.fld.diepctl3.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.diepctl3, "MPSIZ"); 
    state->u.f4.fld.diepctl3.usbaep = cm_object_get_child_by_name(state->u.f4.reg.diepctl3, "USBAEP"); 
    state->u.f4.fld.diepctl3.eonum_dpid = cm_object_get_child_by_name(state->u.f4.reg.diepctl3, "EONUM_DPID"); 
    state->u.f4.fld.diepctl3.naksts = cm_object_get_child_by_name(state->u.f4.reg.diepctl3, "NAKSTS"); 
    state->u.f4.fld.diepctl3.eptyp = cm_object_get_child_by_name(state->u.f4.reg.diepctl3, "EPTYP"); 
    state->u.f4.fld.diepctl3.stall = cm_object_get_child_by_name(state->u.f4.reg.diepctl3, "Stall"); 
    state->u.f4.fld.diepctl3.txfnum = cm_object_get_child_by_name(state->u.f4.reg.diepctl3, "TXFNUM"); 
    state->u.f4.fld.diepctl3.cnak = cm_object_get_child_by_name(state->u.f4.reg.diepctl3, "CNAK"); 
    state->u.f4.fld.diepctl3.snak = cm_object_get_child_by_name(state->u.f4.reg.diepctl3, "SNAK"); 
    state->u.f4.fld.diepctl3.sd0pid_sevnfrm = cm_object_get_child_by_name(state->u.f4.reg.diepctl3, "SD0PID_SEVNFRM"); 
    state->u.f4.fld.diepctl3.soddfrm = cm_object_get_child_by_name(state->u.f4.reg.diepctl3, "SODDFRM"); 
    state->u.f4.fld.diepctl3.epdis = cm_object_get_child_by_name(state->u.f4.reg.diepctl3, "EPDIS"); 
    state->u.f4.fld.diepctl3.epena = cm_object_get_child_by_name(state->u.f4.reg.diepctl3, "EPENA");  
    
    // DOEPCTL0 bitfields.
    state->u.f4.fld.doepctl0.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.doepctl0, "MPSIZ"); 
    state->u.f4.fld.doepctl0.usbaep = cm_object_get_child_by_name(state->u.f4.reg.doepctl0, "USBAEP"); 
    state->u.f4.fld.doepctl0.naksts = cm_object_get_child_by_name(state->u.f4.reg.doepctl0, "NAKSTS"); 
    state->u.f4.fld.doepctl0.eptyp = cm_object_get_child_by_name(state->u.f4.reg.doepctl0, "EPTYP"); 
    state->u.f4.fld.doepctl0.snpm = cm_object_get_child_by_name(state->u.f4.reg.doepctl0, "SNPM"); 
    state->u.f4.fld.doepctl0.stall = cm_object_get_child_by_name(state->u.f4.reg.doepctl0, "Stall"); 
    state->u.f4.fld.doepctl0.cnak = cm_object_get_child_by_name(state->u.f4.reg.doepctl0, "CNAK"); 
    state->u.f4.fld.doepctl0.snak = cm_object_get_child_by_name(state->u.f4.reg.doepctl0, "SNAK"); 
    state->u.f4.fld.doepctl0.epdis = cm_object_get_child_by_name(state->u.f4.reg.doepctl0, "EPDIS"); 
    state->u.f4.fld.doepctl0.epena = cm_object_get_child_by_name(state->u.f4.reg.doepctl0, "EPENA");  
    
    // DOEPCTL1 bitfields.
    state->u.f4.fld.doepctl1.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.doepctl1, "MPSIZ"); 
    state->u.f4.fld.doepctl1.usbaep = cm_object_get_child_by_name(state->u.f4.reg.doepctl1, "USBAEP"); 
    state->u.f4.fld.doepctl1.eonum_dpid = cm_object_get_child_by_name(state->u.f4.reg.doepctl1, "EONUM_DPID"); 
    state->u.f4.fld.doepctl1.naksts = cm_object_get_child_by_name(state->u.f4.reg.doepctl1, "NAKSTS"); 
    state->u.f4.fld.doepctl1.eptyp = cm_object_get_child_by_name(state->u.f4.reg.doepctl1, "EPTYP"); 
    state->u.f4.fld.doepctl1.snpm = cm_object_get_child_by_name(state->u.f4.reg.doepctl1, "SNPM"); 
    state->u.f4.fld.doepctl1.stall = cm_object_get_child_by_name(state->u.f4.reg.doepctl1, "Stall"); 
    state->u.f4.fld.doepctl1.cnak = cm_object_get_child_by_name(state->u.f4.reg.doepctl1, "CNAK"); 
    state->u.f4.fld.doepctl1.snak = cm_object_get_child_by_name(state->u.f4.reg.doepctl1, "SNAK"); 
    state->u.f4.fld.doepctl1.sd0pid_sevnfrm = cm_object_get_child_by_name(state->u.f4.reg.doepctl1, "SD0PID_SEVNFRM"); 
    state->u.f4.fld.doepctl1.soddfrm = cm_object_get_child_by_name(state->u.f4.reg.doepctl1, "SODDFRM"); 
    state->u.f4.fld.doepctl1.epdis = cm_object_get_child_by_name(state->u.f4.reg.doepctl1, "EPDIS"); 
    state->u.f4.fld.doepctl1.epena = cm_object_get_child_by_name(state->u.f4.reg.doepctl1, "EPENA");  
    
    // DOEPCTL2 bitfields.
    state->u.f4.fld.doepctl2.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.doepctl2, "MPSIZ"); 
    state->u.f4.fld.doepctl2.usbaep = cm_object_get_child_by_name(state->u.f4.reg.doepctl2, "USBAEP"); 
    state->u.f4.fld.doepctl2.eonum_dpid = cm_object_get_child_by_name(state->u.f4.reg.doepctl2, "EONUM_DPID"); 
    state->u.f4.fld.doepctl2.naksts = cm_object_get_child_by_name(state->u.f4.reg.doepctl2, "NAKSTS"); 
    state->u.f4.fld.doepctl2.eptyp = cm_object_get_child_by_name(state->u.f4.reg.doepctl2, "EPTYP"); 
    state->u.f4.fld.doepctl2.snpm = cm_object_get_child_by_name(state->u.f4.reg.doepctl2, "SNPM"); 
    state->u.f4.fld.doepctl2.stall = cm_object_get_child_by_name(state->u.f4.reg.doepctl2, "Stall"); 
    state->u.f4.fld.doepctl2.cnak = cm_object_get_child_by_name(state->u.f4.reg.doepctl2, "CNAK"); 
    state->u.f4.fld.doepctl2.snak = cm_object_get_child_by_name(state->u.f4.reg.doepctl2, "SNAK"); 
    state->u.f4.fld.doepctl2.sd0pid_sevnfrm = cm_object_get_child_by_name(state->u.f4.reg.doepctl2, "SD0PID_SEVNFRM"); 
    state->u.f4.fld.doepctl2.soddfrm = cm_object_get_child_by_name(state->u.f4.reg.doepctl2, "SODDFRM"); 
    state->u.f4.fld.doepctl2.epdis = cm_object_get_child_by_name(state->u.f4.reg.doepctl2, "EPDIS"); 
    state->u.f4.fld.doepctl2.epena = cm_object_get_child_by_name(state->u.f4.reg.doepctl2, "EPENA");  
    
    // DOEPCTL3 bitfields.
    state->u.f4.fld.doepctl3.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.doepctl3, "MPSIZ"); 
    state->u.f4.fld.doepctl3.usbaep = cm_object_get_child_by_name(state->u.f4.reg.doepctl3, "USBAEP"); 
    state->u.f4.fld.doepctl3.eonum_dpid = cm_object_get_child_by_name(state->u.f4.reg.doepctl3, "EONUM_DPID"); 
    state->u.f4.fld.doepctl3.naksts = cm_object_get_child_by_name(state->u.f4.reg.doepctl3, "NAKSTS"); 
    state->u.f4.fld.doepctl3.eptyp = cm_object_get_child_by_name(state->u.f4.reg.doepctl3, "EPTYP"); 
    state->u.f4.fld.doepctl3.snpm = cm_object_get_child_by_name(state->u.f4.reg.doepctl3, "SNPM"); 
    state->u.f4.fld.doepctl3.stall = cm_object_get_child_by_name(state->u.f4.reg.doepctl3, "Stall"); 
    state->u.f4.fld.doepctl3.cnak = cm_object_get_child_by_name(state->u.f4.reg.doepctl3, "CNAK"); 
    state->u.f4.fld.doepctl3.snak = cm_object_get_child_by_name(state->u.f4.reg.doepctl3, "SNAK"); 
    state->u.f4.fld.doepctl3.sd0pid_sevnfrm = cm_object_get_child_by_name(state->u.f4.reg.doepctl3, "SD0PID_SEVNFRM"); 
    state->u.f4.fld.doepctl3.soddfrm = cm_object_get_child_by_name(state->u.f4.reg.doepctl3, "SODDFRM"); 
    state->u.f4.fld.doepctl3.epdis = cm_object_get_child_by_name(state->u.f4.reg.doepctl3, "EPDIS"); 
    state->u.f4.fld.doepctl3.epena = cm_object_get_child_by_name(state->u.f4.reg.doepctl3, "EPENA");  
    
    // DIEPINT0 bitfields.
    state->u.f4.fld.diepint0.xfrc = cm_object_get_child_by_name(state->u.f4.reg.diepint0, "XFRC"); 
    state->u.f4.fld.diepint0.epdisd = cm_object_get_child_by_name(state->u.f4.reg.diepint0, "EPDISD"); 
    state->u.f4.fld.diepint0.toc = cm_object_get_child_by_name(state->u.f4.reg.diepint0, "TOC"); 
    state->u.f4.fld.diepint0.ittxfe = cm_object_get_child_by_name(state->u.f4.reg.diepint0, "ITTXFE"); 
    state->u.f4.fld.diepint0.inepne = cm_object_get_child_by_name(state->u.f4.reg.diepint0, "INEPNE"); 
    state->u.f4.fld.diepint0.txfe = cm_object_get_child_by_name(state->u.f4.reg.diepint0, "TXFE");  
    
    // DIEPINT1 bitfields.
    state->u.f4.fld.diepint1.xfrc = cm_object_get_child_by_name(state->u.f4.reg.diepint1, "XFRC"); 
    state->u.f4.fld.diepint1.epdisd = cm_object_get_child_by_name(state->u.f4.reg.diepint1, "EPDISD"); 
    state->u.f4.fld.diepint1.toc = cm_object_get_child_by_name(state->u.f4.reg.diepint1, "TOC"); 
    state->u.f4.fld.diepint1.ittxfe = cm_object_get_child_by_name(state->u.f4.reg.diepint1, "ITTXFE"); 
    state->u.f4.fld.diepint1.inepne = cm_object_get_child_by_name(state->u.f4.reg.diepint1, "INEPNE"); 
    state->u.f4.fld.diepint1.txfe = cm_object_get_child_by_name(state->u.f4.reg.diepint1, "TXFE");  
    
    // DIEPINT2 bitfields.
    state->u.f4.fld.diepint2.xfrc = cm_object_get_child_by_name(state->u.f4.reg.diepint2, "XFRC"); 
    state->u.f4.fld.diepint2.epdisd = cm_object_get_child_by_name(state->u.f4.reg.diepint2, "EPDISD"); 
    state->u.f4.fld.diepint2.toc = cm_object_get_child_by_name(state->u.f4.reg.diepint2, "TOC"); 
    state->u.f4.fld.diepint2.ittxfe = cm_object_get_child_by_name(state->u.f4.reg.diepint2, "ITTXFE"); 
    state->u.f4.fld.diepint2.inepne = cm_object_get_child_by_name(state->u.f4.reg.diepint2, "INEPNE"); 
    state->u.f4.fld.diepint2.txfe = cm_object_get_child_by_name(state->u.f4.reg.diepint2, "TXFE");  
    
    // DIEPINT3 bitfields.
    state->u.f4.fld.diepint3.xfrc = cm_object_get_child_by_name(state->u.f4.reg.diepint3, "XFRC"); 
    state->u.f4.fld.diepint3.epdisd = cm_object_get_child_by_name(state->u.f4.reg.diepint3, "EPDISD"); 
    state->u.f4.fld.diepint3.toc = cm_object_get_child_by_name(state->u.f4.reg.diepint3, "TOC"); 
    state->u.f4.fld.diepint3.ittxfe = cm_object_get_child_by_name(state->u.f4.reg.diepint3, "ITTXFE"); 
    state->u.f4.fld.diepint3.inepne = cm_object_get_child_by_name(state->u.f4.reg.diepint3, "INEPNE"); 
    state->u.f4.fld.diepint3.txfe = cm_object_get_child_by_name(state->u.f4.reg.diepint3, "TXFE");  
    
    // DOEPINT0 bitfields.
    state->u.f4.fld.doepint0.xfrc = cm_object_get_child_by_name(state->u.f4.reg.doepint0, "XFRC"); 
    state->u.f4.fld.doepint0.epdisd = cm_object_get_child_by_name(state->u.f4.reg.doepint0, "EPDISD"); 
    state->u.f4.fld.doepint0.stup = cm_object_get_child_by_name(state->u.f4.reg.doepint0, "STUP"); 
    state->u.f4.fld.doepint0.otepdis = cm_object_get_child_by_name(state->u.f4.reg.doepint0, "OTEPDIS"); 
    state->u.f4.fld.doepint0.b2bstup = cm_object_get_child_by_name(state->u.f4.reg.doepint0, "B2BSTUP");  
    
    // DOEPINT1 bitfields.
    state->u.f4.fld.doepint1.xfrc = cm_object_get_child_by_name(state->u.f4.reg.doepint1, "XFRC"); 
    state->u.f4.fld.doepint1.epdisd = cm_object_get_child_by_name(state->u.f4.reg.doepint1, "EPDISD"); 
    state->u.f4.fld.doepint1.stup = cm_object_get_child_by_name(state->u.f4.reg.doepint1, "STUP"); 
    state->u.f4.fld.doepint1.otepdis = cm_object_get_child_by_name(state->u.f4.reg.doepint1, "OTEPDIS"); 
    state->u.f4.fld.doepint1.b2bstup = cm_object_get_child_by_name(state->u.f4.reg.doepint1, "B2BSTUP");  
    
    // DOEPINT2 bitfields.
    state->u.f4.fld.doepint2.xfrc = cm_object_get_child_by_name(state->u.f4.reg.doepint2, "XFRC"); 
    state->u.f4.fld.doepint2.epdisd = cm_object_get_child_by_name(state->u.f4.reg.doepint2, "EPDISD"); 
    state->u.f4.fld.doepint2.stup = cm_object_get_child_by_name(state->u.f4.reg.doepint2, "STUP"); 
    state->u.f4.fld.doepint2.otepdis = cm_object_get_child_by_name(state->u.f4.reg.doepint2, "OTEPDIS"); 
    state->u.f4.fld.doepint2.b2bstup = cm_object_get_child_by_name(state->u.f4.reg.doepint2, "B2BSTUP");  
    
    // DOEPINT3 bitfields.
    state->u.f4.fld.doepint3.xfrc = cm_object_get_child_by_name(state->u.f4.reg.doepint3, "XFRC"); 
    state->u.f4.fld.doepint3.epdisd = cm_object_get_child_by_name(state->u.f4.reg.doepint3, "EPDISD"); 
    state->u.f4.fld.doepint3.stup = cm_object_get_child_by_name(state->u.f4.reg.doepint3, "STUP"); 
    state->u.f4.fld.doepint3.otepdis = cm_object_get_child_by_name(state->u.f4.reg.doepint3, "OTEPDIS"); 
    state->u.f4.fld.doepint3.b2bstup = cm_object_get_child_by_name(state->u.f4.reg.doepint3, "B2BSTUP");  
    
    // DIEPTSIZ0 bitfields.
    state->u.f4.fld.dieptsiz0.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.dieptsiz0, "XFRSIZ"); 
    state->u.f4.fld.dieptsiz0.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.dieptsiz0, "PKTCNT");  
    
    // DOEPTSIZ0 bitfields.
    state->u.f4.fld.doeptsiz0.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.doeptsiz0, "XFRSIZ"); 
    state->u.f4.fld.doeptsiz0.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.doeptsiz0, "PKTCNT"); 
    state->u.f4.fld.doeptsiz0.stupcnt = cm_object_get_child_by_name(state->u.f4.reg.doeptsiz0, "STUPCNT");  
    
    // DIEPTSIZ1 bitfields.
    state->u.f4.fld.dieptsiz1.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.dieptsiz1, "XFRSIZ"); 
    state->u.f4.fld.dieptsiz1.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.dieptsiz1, "PKTCNT"); 
    state->u.f4.fld.dieptsiz1.mcnt = cm_object_get_child_by_name(state->u.f4.reg.dieptsiz1, "MCNT");  
    
    // DIEPTSIZ2 bitfields.
    state->u.f4.fld.dieptsiz2.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.dieptsiz2, "XFRSIZ"); 
    state->u.f4.fld.dieptsiz2.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.dieptsiz2, "PKTCNT"); 
    state->u.f4.fld.dieptsiz2.mcnt = cm_object_get_child_by_name(state->u.f4.reg.dieptsiz2, "MCNT");  
    
    // DIEPTSIZ3 bitfields.
    state->u.f4.fld.dieptsiz3.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.dieptsiz3, "XFRSIZ"); 
    state->u.f4.fld.dieptsiz3.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.dieptsiz3, "PKTCNT"); 
    state->u.f4.fld.dieptsiz3.mcnt = cm_object_get_child_by_name(state->u.f4.reg.dieptsiz3, "MCNT");  
    
    // DTXFSTS0 bitfields.
    state->u.f4.fld.dtxfsts0.ineptfsav = cm_object_get_child_by_name(state->u.f4.reg.dtxfsts0, "INEPTFSAV");  
    
    // DTXFSTS1 bitfields.
    state->u.f4.fld.dtxfsts1.ineptfsav = cm_object_get_child_by_name(state->u.f4.reg.dtxfsts1, "INEPTFSAV");  
    
    // DTXFSTS2 bitfields.
    state->u.f4.fld.dtxfsts2.ineptfsav = cm_object_get_child_by_name(state->u.f4.reg.dtxfsts2, "INEPTFSAV");  
    
    // DTXFSTS3 bitfields.
    state->u.f4.fld.dtxfsts3.ineptfsav = cm_object_get_child_by_name(state->u.f4.reg.dtxfsts3, "INEPTFSAV");  
    
    // DOEPTSIZ1 bitfields.
    state->u.f4.fld.doeptsiz1.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.doeptsiz1, "XFRSIZ"); 
    state->u.f4.fld.doeptsiz1.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.doeptsiz1, "PKTCNT"); 
    state->u.f4.fld.doeptsiz1.rxdpid_stupcnt = cm_object_get_child_by_name(state->u.f4.reg.doeptsiz1, "RXDPID_STUPCNT");  
    
    // DOEPTSIZ2 bitfields.
    state->u.f4.fld.doeptsiz2.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.doeptsiz2, "XFRSIZ"); 
    state->u.f4.fld.doeptsiz2.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.doeptsiz2, "PKTCNT"); 
    state->u.f4.fld.doeptsiz2.rxdpid_stupcnt = cm_object_get_child_by_name(state->u.f4.reg.doeptsiz2, "RXDPID_STUPCNT");  
    
    // DOEPTSIZ3 bitfields.
    state->u.f4.fld.doeptsiz3.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.doeptsiz3, "XFRSIZ"); 
    state->u.f4.fld.doeptsiz3.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.doeptsiz3, "PKTCNT"); 
    state->u.f4.fld.doeptsiz3.rxdpid_stupcnt = cm_object_get_child_by_name(state->u.f4.reg.doeptsiz3, "RXDPID_STUPCNT");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_otg_fs_device_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32OTG_FS_DEVICEState *state = STM32_OTG_FS_DEVICE_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_otg_fs_device_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32OTG_FS_DEVICEState *state = STM32_OTG_FS_DEVICE_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_otg_fs_device_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32OTG_FS_DEVICEState *state = STM32_OTG_FS_DEVICE_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_otg_fs_device_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32OTG_FS_DEVICEState *state = STM32_OTG_FS_DEVICE_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_otg_fs_device_is_enabled(Object *obj)
{
    STM32OTG_FS_DEVICEState *state = STM32_OTG_FS_DEVICE_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_otg_fs_device_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32OTG_FS_DEVICEState *state = STM32_OTG_FS_DEVICE_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_otg_fs_device_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_OTG_FS_DEVICE)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32OTG_FS_DEVICEState *state = STM32_OTG_FS_DEVICE_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "OTG_FS_DEVICE";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_411xx ) {

            stm32f411xx_otg_fs_device_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_otg_fs_device_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_otg_fs_device_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_otg_fs_device_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_otg_fs_device_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/OTG_FS_DEVICEEN");


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

static void stm32_otg_fs_device_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_OTG_FS_DEVICE);
}

static void stm32_otg_fs_device_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_otg_fs_device_reset_callback;
    dc->realize = stm32_otg_fs_device_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_otg_fs_device_is_enabled;
}

static const TypeInfo stm32_otg_fs_device_type_info = {
    .name = TYPE_STM32_OTG_FS_DEVICE,
    .parent = TYPE_STM32_OTG_FS_DEVICE_PARENT,
    .instance_init = stm32_otg_fs_device_instance_init_callback,
    .instance_size = sizeof(STM32OTG_FS_DEVICEState),
    .class_init = stm32_otg_fs_device_class_init_callback,
    .class_size = sizeof(STM32OTG_FS_DEVICEClass) };

static void stm32_otg_fs_device_register_types(void)
{
    type_register_static(&stm32_otg_fs_device_type_info);
}

type_init(stm32_otg_fs_device_register_types);

// ----------------------------------------------------------------------------
