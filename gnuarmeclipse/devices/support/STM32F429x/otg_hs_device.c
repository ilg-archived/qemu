/*
 * STM32 - OTG_HS_DEVICE (USB on the go high speed) emulation.
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

#include <hw/cortexm/stm32/otg_hs_device.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f429x_otg_hs_device_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32OTG_HS_DEVICEState *state = STM32_OTG_HS_DEVICE_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.otg_hs_dcfg = cm_object_get_child_by_name(obj, "OTG_HS_DCFG");
    state->u.f4.reg.otg_hs_dctl = cm_object_get_child_by_name(obj, "OTG_HS_DCTL");
    state->u.f4.reg.otg_hs_dsts = cm_object_get_child_by_name(obj, "OTG_HS_DSTS");
    state->u.f4.reg.otg_hs_diepmsk = cm_object_get_child_by_name(obj, "OTG_HS_DIEPMSK");
    state->u.f4.reg.otg_hs_doepmsk = cm_object_get_child_by_name(obj, "OTG_HS_DOEPMSK");
    state->u.f4.reg.otg_hs_daint = cm_object_get_child_by_name(obj, "OTG_HS_DAINT");
    state->u.f4.reg.otg_hs_daintmsk = cm_object_get_child_by_name(obj, "OTG_HS_DAINTMSK");
    state->u.f4.reg.otg_hs_dvbusdis = cm_object_get_child_by_name(obj, "OTG_HS_DVBUSDIS");
    state->u.f4.reg.otg_hs_dvbuspulse = cm_object_get_child_by_name(obj, "OTG_HS_DVBUSPULSE");
    state->u.f4.reg.otg_hs_dthrctl = cm_object_get_child_by_name(obj, "OTG_HS_DTHRCTL");
    state->u.f4.reg.otg_hs_diepempmsk = cm_object_get_child_by_name(obj, "OTG_HS_DIEPEMPMSK");
    state->u.f4.reg.otg_hs_deachint = cm_object_get_child_by_name(obj, "OTG_HS_DEACHINT");
    state->u.f4.reg.otg_hs_deachintmsk = cm_object_get_child_by_name(obj, "OTG_HS_DEACHINTMSK");
    state->u.f4.reg.otg_hs_diepeachmsk1 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPEACHMSK1");
    state->u.f4.reg.otg_hs_doepeachmsk1 = cm_object_get_child_by_name(obj, "OTG_HS_DOEPEACHMSK1");
    state->u.f4.reg.otg_hs_diepctl0 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPCTL0");
    state->u.f4.reg.otg_hs_diepctl1 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPCTL1");
    state->u.f4.reg.otg_hs_diepctl2 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPCTL2");
    state->u.f4.reg.otg_hs_diepctl3 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPCTL3");
    state->u.f4.reg.otg_hs_diepctl4 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPCTL4");
    state->u.f4.reg.otg_hs_diepctl5 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPCTL5");
    state->u.f4.reg.otg_hs_diepctl6 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPCTL6");
    state->u.f4.reg.otg_hs_diepctl7 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPCTL7");
    state->u.f4.reg.otg_hs_diepint0 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPINT0");
    state->u.f4.reg.otg_hs_diepint1 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPINT1");
    state->u.f4.reg.otg_hs_diepint2 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPINT2");
    state->u.f4.reg.otg_hs_diepint3 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPINT3");
    state->u.f4.reg.otg_hs_diepint4 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPINT4");
    state->u.f4.reg.otg_hs_diepint5 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPINT5");
    state->u.f4.reg.otg_hs_diepint6 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPINT6");
    state->u.f4.reg.otg_hs_diepint7 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPINT7");
    state->u.f4.reg.otg_hs_dieptsiz0 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPTSIZ0");
    state->u.f4.reg.otg_hs_diepdma1 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPDMA1");
    state->u.f4.reg.otg_hs_diepdma2 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPDMA2");
    state->u.f4.reg.otg_hs_diepdma3 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPDMA3");
    state->u.f4.reg.otg_hs_diepdma4 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPDMA4");
    state->u.f4.reg.otg_hs_diepdma5 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPDMA5");
    state->u.f4.reg.otg_hs_dtxfsts0 = cm_object_get_child_by_name(obj, "OTG_HS_DTXFSTS0");
    state->u.f4.reg.otg_hs_dtxfsts1 = cm_object_get_child_by_name(obj, "OTG_HS_DTXFSTS1");
    state->u.f4.reg.otg_hs_dtxfsts2 = cm_object_get_child_by_name(obj, "OTG_HS_DTXFSTS2");
    state->u.f4.reg.otg_hs_dtxfsts3 = cm_object_get_child_by_name(obj, "OTG_HS_DTXFSTS3");
    state->u.f4.reg.otg_hs_dtxfsts4 = cm_object_get_child_by_name(obj, "OTG_HS_DTXFSTS4");
    state->u.f4.reg.otg_hs_dtxfsts5 = cm_object_get_child_by_name(obj, "OTG_HS_DTXFSTS5");
    state->u.f4.reg.otg_hs_dieptsiz1 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPTSIZ1");
    state->u.f4.reg.otg_hs_dieptsiz2 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPTSIZ2");
    state->u.f4.reg.otg_hs_dieptsiz3 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPTSIZ3");
    state->u.f4.reg.otg_hs_dieptsiz4 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPTSIZ4");
    state->u.f4.reg.otg_hs_dieptsiz5 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPTSIZ5");
    state->u.f4.reg.otg_hs_doepctl0 = cm_object_get_child_by_name(obj, "OTG_HS_DOEPCTL0");
    state->u.f4.reg.otg_hs_doepctl1 = cm_object_get_child_by_name(obj, "OTG_HS_DOEPCTL1");
    state->u.f4.reg.otg_hs_doepctl2 = cm_object_get_child_by_name(obj, "OTG_HS_DOEPCTL2");
    state->u.f4.reg.otg_hs_doepctl3 = cm_object_get_child_by_name(obj, "OTG_HS_DOEPCTL3");
    state->u.f4.reg.otg_hs_doepint0 = cm_object_get_child_by_name(obj, "OTG_HS_DOEPINT0");
    state->u.f4.reg.otg_hs_doepint1 = cm_object_get_child_by_name(obj, "OTG_HS_DOEPINT1");
    state->u.f4.reg.otg_hs_doepint2 = cm_object_get_child_by_name(obj, "OTG_HS_DOEPINT2");
    state->u.f4.reg.otg_hs_doepint3 = cm_object_get_child_by_name(obj, "OTG_HS_DOEPINT3");
    state->u.f4.reg.otg_hs_doepint4 = cm_object_get_child_by_name(obj, "OTG_HS_DOEPINT4");
    state->u.f4.reg.otg_hs_doepint5 = cm_object_get_child_by_name(obj, "OTG_HS_DOEPINT5");
    state->u.f4.reg.otg_hs_doepint6 = cm_object_get_child_by_name(obj, "OTG_HS_DOEPINT6");
    state->u.f4.reg.otg_hs_doepint7 = cm_object_get_child_by_name(obj, "OTG_HS_DOEPINT7");
    state->u.f4.reg.otg_hs_doeptsiz0 = cm_object_get_child_by_name(obj, "OTG_HS_DOEPTSIZ0");
    state->u.f4.reg.otg_hs_doeptsiz1 = cm_object_get_child_by_name(obj, "OTG_HS_DOEPTSIZ1");
    state->u.f4.reg.otg_hs_doeptsiz2 = cm_object_get_child_by_name(obj, "OTG_HS_DOEPTSIZ2");
    state->u.f4.reg.otg_hs_doeptsiz3 = cm_object_get_child_by_name(obj, "OTG_HS_DOEPTSIZ3");
    state->u.f4.reg.otg_hs_doeptsiz4 = cm_object_get_child_by_name(obj, "OTG_HS_DOEPTSIZ4");
    
    
    // OTG_HS_DCFG bitfields.
    state->u.f4.fld.otg_hs_dcfg.dspd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dcfg, "DSPD"); 
    state->u.f4.fld.otg_hs_dcfg.nzlsohsk = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dcfg, "NZLSOHSK"); 
    state->u.f4.fld.otg_hs_dcfg.dad = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dcfg, "DAD"); 
    state->u.f4.fld.otg_hs_dcfg.pfivl = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dcfg, "PFIVL"); 
    state->u.f4.fld.otg_hs_dcfg.perschivl = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dcfg, "PERSCHIVL");  
    
    // OTG_HS_DCTL bitfields.
    state->u.f4.fld.otg_hs_dctl.rwusig = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dctl, "RWUSIG"); 
    state->u.f4.fld.otg_hs_dctl.sdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dctl, "SDIS"); 
    state->u.f4.fld.otg_hs_dctl.ginsts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dctl, "GINSTS"); 
    state->u.f4.fld.otg_hs_dctl.gonsts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dctl, "GONSTS"); 
    state->u.f4.fld.otg_hs_dctl.tctl = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dctl, "TCTL"); 
    state->u.f4.fld.otg_hs_dctl.sginak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dctl, "SGINAK"); 
    state->u.f4.fld.otg_hs_dctl.cginak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dctl, "CGINAK"); 
    state->u.f4.fld.otg_hs_dctl.sgonak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dctl, "SGONAK"); 
    state->u.f4.fld.otg_hs_dctl.cgonak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dctl, "CGONAK"); 
    state->u.f4.fld.otg_hs_dctl.poprgdne = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dctl, "POPRGDNE");  
    
    // OTG_HS_DSTS bitfields.
    state->u.f4.fld.otg_hs_dsts.suspsts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dsts, "SUSPSTS"); 
    state->u.f4.fld.otg_hs_dsts.enumspd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dsts, "ENUMSPD"); 
    state->u.f4.fld.otg_hs_dsts.eerr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dsts, "EERR"); 
    state->u.f4.fld.otg_hs_dsts.fnsof = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dsts, "FNSOF");  
    
    // OTG_HS_DIEPMSK bitfields.
    state->u.f4.fld.otg_hs_diepmsk.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepmsk, "XFRCM"); 
    state->u.f4.fld.otg_hs_diepmsk.epdm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepmsk, "EPDM"); 
    state->u.f4.fld.otg_hs_diepmsk.tom = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepmsk, "TOM"); 
    state->u.f4.fld.otg_hs_diepmsk.ittxfemsk = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepmsk, "ITTXFEMSK"); 
    state->u.f4.fld.otg_hs_diepmsk.inepnmm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepmsk, "INEPNMM"); 
    state->u.f4.fld.otg_hs_diepmsk.inepnem = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepmsk, "INEPNEM"); 
    state->u.f4.fld.otg_hs_diepmsk.txfurm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepmsk, "TXFURM"); 
    state->u.f4.fld.otg_hs_diepmsk.bim = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepmsk, "BIM");  
    
    // OTG_HS_DOEPMSK bitfields.
    state->u.f4.fld.otg_hs_doepmsk.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepmsk, "XFRCM"); 
    state->u.f4.fld.otg_hs_doepmsk.epdm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepmsk, "EPDM"); 
    state->u.f4.fld.otg_hs_doepmsk.stupm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepmsk, "STUPM"); 
    state->u.f4.fld.otg_hs_doepmsk.otepdm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepmsk, "OTEPDM"); 
    state->u.f4.fld.otg_hs_doepmsk.b2bstup = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepmsk, "B2BSTUP"); 
    state->u.f4.fld.otg_hs_doepmsk.opem = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepmsk, "OPEM"); 
    state->u.f4.fld.otg_hs_doepmsk.boim = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepmsk, "BOIM");  
    
    // OTG_HS_DAINT bitfields.
    state->u.f4.fld.otg_hs_daint.iepint = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_daint, "IEPINT"); 
    state->u.f4.fld.otg_hs_daint.oepint = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_daint, "OEPINT");  
    
    // OTG_HS_DAINTMSK bitfields.
    state->u.f4.fld.otg_hs_daintmsk.iepm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_daintmsk, "IEPM"); 
    state->u.f4.fld.otg_hs_daintmsk.oepm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_daintmsk, "OEPM");  
    
    // OTG_HS_DVBUSDIS bitfields.
    state->u.f4.fld.otg_hs_dvbusdis.vbusdt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dvbusdis, "VBUSDT");  
    
    // OTG_HS_DVBUSPULSE bitfields.
    state->u.f4.fld.otg_hs_dvbuspulse.dvbusp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dvbuspulse, "DVBUSP");  
    
    // OTG_HS_DTHRCTL bitfields.
    state->u.f4.fld.otg_hs_dthrctl.nonisothren = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dthrctl, "NONISOTHREN"); 
    state->u.f4.fld.otg_hs_dthrctl.isothren = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dthrctl, "ISOTHREN"); 
    state->u.f4.fld.otg_hs_dthrctl.txthrlen = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dthrctl, "TXTHRLEN"); 
    state->u.f4.fld.otg_hs_dthrctl.rxthren = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dthrctl, "RXTHREN"); 
    state->u.f4.fld.otg_hs_dthrctl.rxthrlen = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dthrctl, "RXTHRLEN"); 
    state->u.f4.fld.otg_hs_dthrctl.arpen = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dthrctl, "ARPEN");  
    
    // OTG_HS_DIEPEMPMSK bitfields.
    state->u.f4.fld.otg_hs_diepempmsk.ineptxfem = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepempmsk, "INEPTXFEM");  
    
    // OTG_HS_DEACHINT bitfields.
    state->u.f4.fld.otg_hs_deachint.iep1int = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_deachint, "IEP1INT"); 
    state->u.f4.fld.otg_hs_deachint.oep1int = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_deachint, "OEP1INT");  
    
    // OTG_HS_DEACHINTMSK bitfields.
    state->u.f4.fld.otg_hs_deachintmsk.iep1intm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_deachintmsk, "IEP1INTM"); 
    state->u.f4.fld.otg_hs_deachintmsk.oep1intm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_deachintmsk, "OEP1INTM");  
    
    // OTG_HS_DIEPEACHMSK1 bitfields.
    state->u.f4.fld.otg_hs_diepeachmsk1.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepeachmsk1, "XFRCM"); 
    state->u.f4.fld.otg_hs_diepeachmsk1.epdm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepeachmsk1, "EPDM"); 
    state->u.f4.fld.otg_hs_diepeachmsk1.tom = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepeachmsk1, "TOM"); 
    state->u.f4.fld.otg_hs_diepeachmsk1.ittxfemsk = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepeachmsk1, "ITTXFEMSK"); 
    state->u.f4.fld.otg_hs_diepeachmsk1.inepnmm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepeachmsk1, "INEPNMM"); 
    state->u.f4.fld.otg_hs_diepeachmsk1.inepnem = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepeachmsk1, "INEPNEM"); 
    state->u.f4.fld.otg_hs_diepeachmsk1.txfurm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepeachmsk1, "TXFURM"); 
    state->u.f4.fld.otg_hs_diepeachmsk1.bim = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepeachmsk1, "BIM"); 
    state->u.f4.fld.otg_hs_diepeachmsk1.nakm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepeachmsk1, "NAKM");  
    
    // OTG_HS_DOEPEACHMSK1 bitfields.
    state->u.f4.fld.otg_hs_doepeachmsk1.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepeachmsk1, "XFRCM"); 
    state->u.f4.fld.otg_hs_doepeachmsk1.epdm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepeachmsk1, "EPDM"); 
    state->u.f4.fld.otg_hs_doepeachmsk1.tom = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepeachmsk1, "TOM"); 
    state->u.f4.fld.otg_hs_doepeachmsk1.ittxfemsk = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepeachmsk1, "ITTXFEMSK"); 
    state->u.f4.fld.otg_hs_doepeachmsk1.inepnmm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepeachmsk1, "INEPNMM"); 
    state->u.f4.fld.otg_hs_doepeachmsk1.inepnem = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepeachmsk1, "INEPNEM"); 
    state->u.f4.fld.otg_hs_doepeachmsk1.txfurm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepeachmsk1, "TXFURM"); 
    state->u.f4.fld.otg_hs_doepeachmsk1.bim = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepeachmsk1, "BIM"); 
    state->u.f4.fld.otg_hs_doepeachmsk1.berrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepeachmsk1, "BERRM"); 
    state->u.f4.fld.otg_hs_doepeachmsk1.nakm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepeachmsk1, "NAKM"); 
    state->u.f4.fld.otg_hs_doepeachmsk1.nyetm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepeachmsk1, "NYETM");  
    
    // OTG_HS_DIEPCTL0 bitfields.
    state->u.f4.fld.otg_hs_diepctl0.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl0, "MPSIZ"); 
    state->u.f4.fld.otg_hs_diepctl0.usbaep = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl0, "USBAEP"); 
    state->u.f4.fld.otg_hs_diepctl0.eonum_dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl0, "EONUM_DPID"); 
    state->u.f4.fld.otg_hs_diepctl0.naksts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl0, "NAKSTS"); 
    state->u.f4.fld.otg_hs_diepctl0.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl0, "EPTYP"); 
    state->u.f4.fld.otg_hs_diepctl0.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl0, "Stall"); 
    state->u.f4.fld.otg_hs_diepctl0.txfnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl0, "TXFNUM"); 
    state->u.f4.fld.otg_hs_diepctl0.cnak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl0, "CNAK"); 
    state->u.f4.fld.otg_hs_diepctl0.snak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl0, "SNAK"); 
    state->u.f4.fld.otg_hs_diepctl0.sd0pid_sevnfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl0, "SD0PID_SEVNFRM"); 
    state->u.f4.fld.otg_hs_diepctl0.soddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl0, "SODDFRM"); 
    state->u.f4.fld.otg_hs_diepctl0.epdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl0, "EPDIS"); 
    state->u.f4.fld.otg_hs_diepctl0.epena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl0, "EPENA");  
    
    // OTG_HS_DIEPCTL1 bitfields.
    state->u.f4.fld.otg_hs_diepctl1.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl1, "MPSIZ"); 
    state->u.f4.fld.otg_hs_diepctl1.usbaep = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl1, "USBAEP"); 
    state->u.f4.fld.otg_hs_diepctl1.eonum_dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl1, "EONUM_DPID"); 
    state->u.f4.fld.otg_hs_diepctl1.naksts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl1, "NAKSTS"); 
    state->u.f4.fld.otg_hs_diepctl1.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl1, "EPTYP"); 
    state->u.f4.fld.otg_hs_diepctl1.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl1, "Stall"); 
    state->u.f4.fld.otg_hs_diepctl1.txfnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl1, "TXFNUM"); 
    state->u.f4.fld.otg_hs_diepctl1.cnak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl1, "CNAK"); 
    state->u.f4.fld.otg_hs_diepctl1.snak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl1, "SNAK"); 
    state->u.f4.fld.otg_hs_diepctl1.sd0pid_sevnfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl1, "SD0PID_SEVNFRM"); 
    state->u.f4.fld.otg_hs_diepctl1.soddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl1, "SODDFRM"); 
    state->u.f4.fld.otg_hs_diepctl1.epdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl1, "EPDIS"); 
    state->u.f4.fld.otg_hs_diepctl1.epena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl1, "EPENA");  
    
    // OTG_HS_DIEPCTL2 bitfields.
    state->u.f4.fld.otg_hs_diepctl2.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl2, "MPSIZ"); 
    state->u.f4.fld.otg_hs_diepctl2.usbaep = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl2, "USBAEP"); 
    state->u.f4.fld.otg_hs_diepctl2.eonum_dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl2, "EONUM_DPID"); 
    state->u.f4.fld.otg_hs_diepctl2.naksts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl2, "NAKSTS"); 
    state->u.f4.fld.otg_hs_diepctl2.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl2, "EPTYP"); 
    state->u.f4.fld.otg_hs_diepctl2.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl2, "Stall"); 
    state->u.f4.fld.otg_hs_diepctl2.txfnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl2, "TXFNUM"); 
    state->u.f4.fld.otg_hs_diepctl2.cnak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl2, "CNAK"); 
    state->u.f4.fld.otg_hs_diepctl2.snak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl2, "SNAK"); 
    state->u.f4.fld.otg_hs_diepctl2.sd0pid_sevnfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl2, "SD0PID_SEVNFRM"); 
    state->u.f4.fld.otg_hs_diepctl2.soddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl2, "SODDFRM"); 
    state->u.f4.fld.otg_hs_diepctl2.epdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl2, "EPDIS"); 
    state->u.f4.fld.otg_hs_diepctl2.epena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl2, "EPENA");  
    
    // OTG_HS_DIEPCTL3 bitfields.
    state->u.f4.fld.otg_hs_diepctl3.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl3, "MPSIZ"); 
    state->u.f4.fld.otg_hs_diepctl3.usbaep = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl3, "USBAEP"); 
    state->u.f4.fld.otg_hs_diepctl3.eonum_dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl3, "EONUM_DPID"); 
    state->u.f4.fld.otg_hs_diepctl3.naksts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl3, "NAKSTS"); 
    state->u.f4.fld.otg_hs_diepctl3.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl3, "EPTYP"); 
    state->u.f4.fld.otg_hs_diepctl3.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl3, "Stall"); 
    state->u.f4.fld.otg_hs_diepctl3.txfnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl3, "TXFNUM"); 
    state->u.f4.fld.otg_hs_diepctl3.cnak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl3, "CNAK"); 
    state->u.f4.fld.otg_hs_diepctl3.snak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl3, "SNAK"); 
    state->u.f4.fld.otg_hs_diepctl3.sd0pid_sevnfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl3, "SD0PID_SEVNFRM"); 
    state->u.f4.fld.otg_hs_diepctl3.soddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl3, "SODDFRM"); 
    state->u.f4.fld.otg_hs_diepctl3.epdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl3, "EPDIS"); 
    state->u.f4.fld.otg_hs_diepctl3.epena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl3, "EPENA");  
    
    // OTG_HS_DIEPCTL4 bitfields.
    state->u.f4.fld.otg_hs_diepctl4.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl4, "MPSIZ"); 
    state->u.f4.fld.otg_hs_diepctl4.usbaep = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl4, "USBAEP"); 
    state->u.f4.fld.otg_hs_diepctl4.eonum_dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl4, "EONUM_DPID"); 
    state->u.f4.fld.otg_hs_diepctl4.naksts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl4, "NAKSTS"); 
    state->u.f4.fld.otg_hs_diepctl4.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl4, "EPTYP"); 
    state->u.f4.fld.otg_hs_diepctl4.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl4, "Stall"); 
    state->u.f4.fld.otg_hs_diepctl4.txfnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl4, "TXFNUM"); 
    state->u.f4.fld.otg_hs_diepctl4.cnak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl4, "CNAK"); 
    state->u.f4.fld.otg_hs_diepctl4.snak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl4, "SNAK"); 
    state->u.f4.fld.otg_hs_diepctl4.sd0pid_sevnfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl4, "SD0PID_SEVNFRM"); 
    state->u.f4.fld.otg_hs_diepctl4.soddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl4, "SODDFRM"); 
    state->u.f4.fld.otg_hs_diepctl4.epdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl4, "EPDIS"); 
    state->u.f4.fld.otg_hs_diepctl4.epena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl4, "EPENA");  
    
    // OTG_HS_DIEPCTL5 bitfields.
    state->u.f4.fld.otg_hs_diepctl5.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl5, "MPSIZ"); 
    state->u.f4.fld.otg_hs_diepctl5.usbaep = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl5, "USBAEP"); 
    state->u.f4.fld.otg_hs_diepctl5.eonum_dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl5, "EONUM_DPID"); 
    state->u.f4.fld.otg_hs_diepctl5.naksts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl5, "NAKSTS"); 
    state->u.f4.fld.otg_hs_diepctl5.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl5, "EPTYP"); 
    state->u.f4.fld.otg_hs_diepctl5.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl5, "Stall"); 
    state->u.f4.fld.otg_hs_diepctl5.txfnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl5, "TXFNUM"); 
    state->u.f4.fld.otg_hs_diepctl5.cnak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl5, "CNAK"); 
    state->u.f4.fld.otg_hs_diepctl5.snak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl5, "SNAK"); 
    state->u.f4.fld.otg_hs_diepctl5.sd0pid_sevnfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl5, "SD0PID_SEVNFRM"); 
    state->u.f4.fld.otg_hs_diepctl5.soddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl5, "SODDFRM"); 
    state->u.f4.fld.otg_hs_diepctl5.epdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl5, "EPDIS"); 
    state->u.f4.fld.otg_hs_diepctl5.epena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl5, "EPENA");  
    
    // OTG_HS_DIEPCTL6 bitfields.
    state->u.f4.fld.otg_hs_diepctl6.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl6, "MPSIZ"); 
    state->u.f4.fld.otg_hs_diepctl6.usbaep = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl6, "USBAEP"); 
    state->u.f4.fld.otg_hs_diepctl6.eonum_dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl6, "EONUM_DPID"); 
    state->u.f4.fld.otg_hs_diepctl6.naksts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl6, "NAKSTS"); 
    state->u.f4.fld.otg_hs_diepctl6.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl6, "EPTYP"); 
    state->u.f4.fld.otg_hs_diepctl6.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl6, "Stall"); 
    state->u.f4.fld.otg_hs_diepctl6.txfnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl6, "TXFNUM"); 
    state->u.f4.fld.otg_hs_diepctl6.cnak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl6, "CNAK"); 
    state->u.f4.fld.otg_hs_diepctl6.snak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl6, "SNAK"); 
    state->u.f4.fld.otg_hs_diepctl6.sd0pid_sevnfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl6, "SD0PID_SEVNFRM"); 
    state->u.f4.fld.otg_hs_diepctl6.soddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl6, "SODDFRM"); 
    state->u.f4.fld.otg_hs_diepctl6.epdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl6, "EPDIS"); 
    state->u.f4.fld.otg_hs_diepctl6.epena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl6, "EPENA");  
    
    // OTG_HS_DIEPCTL7 bitfields.
    state->u.f4.fld.otg_hs_diepctl7.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl7, "MPSIZ"); 
    state->u.f4.fld.otg_hs_diepctl7.usbaep = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl7, "USBAEP"); 
    state->u.f4.fld.otg_hs_diepctl7.eonum_dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl7, "EONUM_DPID"); 
    state->u.f4.fld.otg_hs_diepctl7.naksts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl7, "NAKSTS"); 
    state->u.f4.fld.otg_hs_diepctl7.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl7, "EPTYP"); 
    state->u.f4.fld.otg_hs_diepctl7.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl7, "Stall"); 
    state->u.f4.fld.otg_hs_diepctl7.txfnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl7, "TXFNUM"); 
    state->u.f4.fld.otg_hs_diepctl7.cnak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl7, "CNAK"); 
    state->u.f4.fld.otg_hs_diepctl7.snak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl7, "SNAK"); 
    state->u.f4.fld.otg_hs_diepctl7.sd0pid_sevnfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl7, "SD0PID_SEVNFRM"); 
    state->u.f4.fld.otg_hs_diepctl7.soddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl7, "SODDFRM"); 
    state->u.f4.fld.otg_hs_diepctl7.epdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl7, "EPDIS"); 
    state->u.f4.fld.otg_hs_diepctl7.epena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepctl7, "EPENA");  
    
    // OTG_HS_DIEPINT0 bitfields.
    state->u.f4.fld.otg_hs_diepint0.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint0, "XFRC"); 
    state->u.f4.fld.otg_hs_diepint0.epdisd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint0, "EPDISD"); 
    state->u.f4.fld.otg_hs_diepint0.toc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint0, "TOC"); 
    state->u.f4.fld.otg_hs_diepint0.ittxfe = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint0, "ITTXFE"); 
    state->u.f4.fld.otg_hs_diepint0.inepne = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint0, "INEPNE"); 
    state->u.f4.fld.otg_hs_diepint0.txfe = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint0, "TXFE"); 
    state->u.f4.fld.otg_hs_diepint0.txfifoudrn = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint0, "TXFIFOUDRN"); 
    state->u.f4.fld.otg_hs_diepint0.bna = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint0, "BNA"); 
    state->u.f4.fld.otg_hs_diepint0.pktdrpsts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint0, "PKTDRPSTS"); 
    state->u.f4.fld.otg_hs_diepint0.berr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint0, "BERR"); 
    state->u.f4.fld.otg_hs_diepint0.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint0, "NAK");  
    
    // OTG_HS_DIEPINT1 bitfields.
    state->u.f4.fld.otg_hs_diepint1.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint1, "XFRC"); 
    state->u.f4.fld.otg_hs_diepint1.epdisd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint1, "EPDISD"); 
    state->u.f4.fld.otg_hs_diepint1.toc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint1, "TOC"); 
    state->u.f4.fld.otg_hs_diepint1.ittxfe = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint1, "ITTXFE"); 
    state->u.f4.fld.otg_hs_diepint1.inepne = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint1, "INEPNE"); 
    state->u.f4.fld.otg_hs_diepint1.txfe = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint1, "TXFE"); 
    state->u.f4.fld.otg_hs_diepint1.txfifoudrn = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint1, "TXFIFOUDRN"); 
    state->u.f4.fld.otg_hs_diepint1.bna = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint1, "BNA"); 
    state->u.f4.fld.otg_hs_diepint1.pktdrpsts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint1, "PKTDRPSTS"); 
    state->u.f4.fld.otg_hs_diepint1.berr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint1, "BERR"); 
    state->u.f4.fld.otg_hs_diepint1.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint1, "NAK");  
    
    // OTG_HS_DIEPINT2 bitfields.
    state->u.f4.fld.otg_hs_diepint2.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint2, "XFRC"); 
    state->u.f4.fld.otg_hs_diepint2.epdisd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint2, "EPDISD"); 
    state->u.f4.fld.otg_hs_diepint2.toc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint2, "TOC"); 
    state->u.f4.fld.otg_hs_diepint2.ittxfe = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint2, "ITTXFE"); 
    state->u.f4.fld.otg_hs_diepint2.inepne = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint2, "INEPNE"); 
    state->u.f4.fld.otg_hs_diepint2.txfe = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint2, "TXFE"); 
    state->u.f4.fld.otg_hs_diepint2.txfifoudrn = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint2, "TXFIFOUDRN"); 
    state->u.f4.fld.otg_hs_diepint2.bna = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint2, "BNA"); 
    state->u.f4.fld.otg_hs_diepint2.pktdrpsts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint2, "PKTDRPSTS"); 
    state->u.f4.fld.otg_hs_diepint2.berr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint2, "BERR"); 
    state->u.f4.fld.otg_hs_diepint2.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint2, "NAK");  
    
    // OTG_HS_DIEPINT3 bitfields.
    state->u.f4.fld.otg_hs_diepint3.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint3, "XFRC"); 
    state->u.f4.fld.otg_hs_diepint3.epdisd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint3, "EPDISD"); 
    state->u.f4.fld.otg_hs_diepint3.toc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint3, "TOC"); 
    state->u.f4.fld.otg_hs_diepint3.ittxfe = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint3, "ITTXFE"); 
    state->u.f4.fld.otg_hs_diepint3.inepne = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint3, "INEPNE"); 
    state->u.f4.fld.otg_hs_diepint3.txfe = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint3, "TXFE"); 
    state->u.f4.fld.otg_hs_diepint3.txfifoudrn = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint3, "TXFIFOUDRN"); 
    state->u.f4.fld.otg_hs_diepint3.bna = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint3, "BNA"); 
    state->u.f4.fld.otg_hs_diepint3.pktdrpsts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint3, "PKTDRPSTS"); 
    state->u.f4.fld.otg_hs_diepint3.berr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint3, "BERR"); 
    state->u.f4.fld.otg_hs_diepint3.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint3, "NAK");  
    
    // OTG_HS_DIEPINT4 bitfields.
    state->u.f4.fld.otg_hs_diepint4.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint4, "XFRC"); 
    state->u.f4.fld.otg_hs_diepint4.epdisd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint4, "EPDISD"); 
    state->u.f4.fld.otg_hs_diepint4.toc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint4, "TOC"); 
    state->u.f4.fld.otg_hs_diepint4.ittxfe = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint4, "ITTXFE"); 
    state->u.f4.fld.otg_hs_diepint4.inepne = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint4, "INEPNE"); 
    state->u.f4.fld.otg_hs_diepint4.txfe = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint4, "TXFE"); 
    state->u.f4.fld.otg_hs_diepint4.txfifoudrn = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint4, "TXFIFOUDRN"); 
    state->u.f4.fld.otg_hs_diepint4.bna = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint4, "BNA"); 
    state->u.f4.fld.otg_hs_diepint4.pktdrpsts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint4, "PKTDRPSTS"); 
    state->u.f4.fld.otg_hs_diepint4.berr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint4, "BERR"); 
    state->u.f4.fld.otg_hs_diepint4.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint4, "NAK");  
    
    // OTG_HS_DIEPINT5 bitfields.
    state->u.f4.fld.otg_hs_diepint5.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint5, "XFRC"); 
    state->u.f4.fld.otg_hs_diepint5.epdisd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint5, "EPDISD"); 
    state->u.f4.fld.otg_hs_diepint5.toc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint5, "TOC"); 
    state->u.f4.fld.otg_hs_diepint5.ittxfe = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint5, "ITTXFE"); 
    state->u.f4.fld.otg_hs_diepint5.inepne = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint5, "INEPNE"); 
    state->u.f4.fld.otg_hs_diepint5.txfe = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint5, "TXFE"); 
    state->u.f4.fld.otg_hs_diepint5.txfifoudrn = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint5, "TXFIFOUDRN"); 
    state->u.f4.fld.otg_hs_diepint5.bna = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint5, "BNA"); 
    state->u.f4.fld.otg_hs_diepint5.pktdrpsts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint5, "PKTDRPSTS"); 
    state->u.f4.fld.otg_hs_diepint5.berr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint5, "BERR"); 
    state->u.f4.fld.otg_hs_diepint5.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint5, "NAK");  
    
    // OTG_HS_DIEPINT6 bitfields.
    state->u.f4.fld.otg_hs_diepint6.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint6, "XFRC"); 
    state->u.f4.fld.otg_hs_diepint6.epdisd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint6, "EPDISD"); 
    state->u.f4.fld.otg_hs_diepint6.toc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint6, "TOC"); 
    state->u.f4.fld.otg_hs_diepint6.ittxfe = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint6, "ITTXFE"); 
    state->u.f4.fld.otg_hs_diepint6.inepne = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint6, "INEPNE"); 
    state->u.f4.fld.otg_hs_diepint6.txfe = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint6, "TXFE"); 
    state->u.f4.fld.otg_hs_diepint6.txfifoudrn = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint6, "TXFIFOUDRN"); 
    state->u.f4.fld.otg_hs_diepint6.bna = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint6, "BNA"); 
    state->u.f4.fld.otg_hs_diepint6.pktdrpsts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint6, "PKTDRPSTS"); 
    state->u.f4.fld.otg_hs_diepint6.berr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint6, "BERR"); 
    state->u.f4.fld.otg_hs_diepint6.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint6, "NAK");  
    
    // OTG_HS_DIEPINT7 bitfields.
    state->u.f4.fld.otg_hs_diepint7.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint7, "XFRC"); 
    state->u.f4.fld.otg_hs_diepint7.epdisd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint7, "EPDISD"); 
    state->u.f4.fld.otg_hs_diepint7.toc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint7, "TOC"); 
    state->u.f4.fld.otg_hs_diepint7.ittxfe = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint7, "ITTXFE"); 
    state->u.f4.fld.otg_hs_diepint7.inepne = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint7, "INEPNE"); 
    state->u.f4.fld.otg_hs_diepint7.txfe = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint7, "TXFE"); 
    state->u.f4.fld.otg_hs_diepint7.txfifoudrn = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint7, "TXFIFOUDRN"); 
    state->u.f4.fld.otg_hs_diepint7.bna = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint7, "BNA"); 
    state->u.f4.fld.otg_hs_diepint7.pktdrpsts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint7, "PKTDRPSTS"); 
    state->u.f4.fld.otg_hs_diepint7.berr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint7, "BERR"); 
    state->u.f4.fld.otg_hs_diepint7.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepint7, "NAK");  
    
    // OTG_HS_DIEPTSIZ0 bitfields.
    state->u.f4.fld.otg_hs_dieptsiz0.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptsiz0, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_dieptsiz0.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptsiz0, "PKTCNT");  
    
    // OTG_HS_DIEPDMA1 bitfields.
    state->u.f4.fld.otg_hs_diepdma1.dmaaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepdma1, "DMAADDR");  
    
    // OTG_HS_DIEPDMA2 bitfields.
    state->u.f4.fld.otg_hs_diepdma2.dmaaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepdma2, "DMAADDR");  
    
    // OTG_HS_DIEPDMA3 bitfields.
    state->u.f4.fld.otg_hs_diepdma3.dmaaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepdma3, "DMAADDR");  
    
    // OTG_HS_DIEPDMA4 bitfields.
    state->u.f4.fld.otg_hs_diepdma4.dmaaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepdma4, "DMAADDR");  
    
    // OTG_HS_DIEPDMA5 bitfields.
    state->u.f4.fld.otg_hs_diepdma5.dmaaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_diepdma5, "DMAADDR");  
    
    // OTG_HS_DTXFSTS0 bitfields.
    state->u.f4.fld.otg_hs_dtxfsts0.ineptfsav = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dtxfsts0, "INEPTFSAV");  
    
    // OTG_HS_DTXFSTS1 bitfields.
    state->u.f4.fld.otg_hs_dtxfsts1.ineptfsav = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dtxfsts1, "INEPTFSAV");  
    
    // OTG_HS_DTXFSTS2 bitfields.
    state->u.f4.fld.otg_hs_dtxfsts2.ineptfsav = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dtxfsts2, "INEPTFSAV");  
    
    // OTG_HS_DTXFSTS3 bitfields.
    state->u.f4.fld.otg_hs_dtxfsts3.ineptfsav = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dtxfsts3, "INEPTFSAV");  
    
    // OTG_HS_DTXFSTS4 bitfields.
    state->u.f4.fld.otg_hs_dtxfsts4.ineptfsav = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dtxfsts4, "INEPTFSAV");  
    
    // OTG_HS_DTXFSTS5 bitfields.
    state->u.f4.fld.otg_hs_dtxfsts5.ineptfsav = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dtxfsts5, "INEPTFSAV");  
    
    // OTG_HS_DIEPTSIZ1 bitfields.
    state->u.f4.fld.otg_hs_dieptsiz1.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptsiz1, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_dieptsiz1.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptsiz1, "PKTCNT"); 
    state->u.f4.fld.otg_hs_dieptsiz1.mcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptsiz1, "MCNT");  
    
    // OTG_HS_DIEPTSIZ2 bitfields.
    state->u.f4.fld.otg_hs_dieptsiz2.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptsiz2, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_dieptsiz2.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptsiz2, "PKTCNT"); 
    state->u.f4.fld.otg_hs_dieptsiz2.mcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptsiz2, "MCNT");  
    
    // OTG_HS_DIEPTSIZ3 bitfields.
    state->u.f4.fld.otg_hs_dieptsiz3.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptsiz3, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_dieptsiz3.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptsiz3, "PKTCNT"); 
    state->u.f4.fld.otg_hs_dieptsiz3.mcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptsiz3, "MCNT");  
    
    // OTG_HS_DIEPTSIZ4 bitfields.
    state->u.f4.fld.otg_hs_dieptsiz4.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptsiz4, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_dieptsiz4.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptsiz4, "PKTCNT"); 
    state->u.f4.fld.otg_hs_dieptsiz4.mcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptsiz4, "MCNT");  
    
    // OTG_HS_DIEPTSIZ5 bitfields.
    state->u.f4.fld.otg_hs_dieptsiz5.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptsiz5, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_dieptsiz5.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptsiz5, "PKTCNT"); 
    state->u.f4.fld.otg_hs_dieptsiz5.mcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptsiz5, "MCNT");  
    
    // OTG_HS_DOEPCTL0 bitfields.
    state->u.f4.fld.otg_hs_doepctl0.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl0, "MPSIZ"); 
    state->u.f4.fld.otg_hs_doepctl0.usbaep = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl0, "USBAEP"); 
    state->u.f4.fld.otg_hs_doepctl0.naksts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl0, "NAKSTS"); 
    state->u.f4.fld.otg_hs_doepctl0.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl0, "EPTYP"); 
    state->u.f4.fld.otg_hs_doepctl0.snpm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl0, "SNPM"); 
    state->u.f4.fld.otg_hs_doepctl0.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl0, "Stall"); 
    state->u.f4.fld.otg_hs_doepctl0.cnak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl0, "CNAK"); 
    state->u.f4.fld.otg_hs_doepctl0.snak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl0, "SNAK"); 
    state->u.f4.fld.otg_hs_doepctl0.epdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl0, "EPDIS"); 
    state->u.f4.fld.otg_hs_doepctl0.epena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl0, "EPENA");  
    
    // OTG_HS_DOEPCTL1 bitfields.
    state->u.f4.fld.otg_hs_doepctl1.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl1, "MPSIZ"); 
    state->u.f4.fld.otg_hs_doepctl1.usbaep = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl1, "USBAEP"); 
    state->u.f4.fld.otg_hs_doepctl1.eonum_dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl1, "EONUM_DPID"); 
    state->u.f4.fld.otg_hs_doepctl1.naksts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl1, "NAKSTS"); 
    state->u.f4.fld.otg_hs_doepctl1.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl1, "EPTYP"); 
    state->u.f4.fld.otg_hs_doepctl1.snpm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl1, "SNPM"); 
    state->u.f4.fld.otg_hs_doepctl1.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl1, "Stall"); 
    state->u.f4.fld.otg_hs_doepctl1.cnak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl1, "CNAK"); 
    state->u.f4.fld.otg_hs_doepctl1.snak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl1, "SNAK"); 
    state->u.f4.fld.otg_hs_doepctl1.sd0pid_sevnfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl1, "SD0PID_SEVNFRM"); 
    state->u.f4.fld.otg_hs_doepctl1.soddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl1, "SODDFRM"); 
    state->u.f4.fld.otg_hs_doepctl1.epdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl1, "EPDIS"); 
    state->u.f4.fld.otg_hs_doepctl1.epena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl1, "EPENA");  
    
    // OTG_HS_DOEPCTL2 bitfields.
    state->u.f4.fld.otg_hs_doepctl2.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl2, "MPSIZ"); 
    state->u.f4.fld.otg_hs_doepctl2.usbaep = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl2, "USBAEP"); 
    state->u.f4.fld.otg_hs_doepctl2.eonum_dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl2, "EONUM_DPID"); 
    state->u.f4.fld.otg_hs_doepctl2.naksts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl2, "NAKSTS"); 
    state->u.f4.fld.otg_hs_doepctl2.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl2, "EPTYP"); 
    state->u.f4.fld.otg_hs_doepctl2.snpm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl2, "SNPM"); 
    state->u.f4.fld.otg_hs_doepctl2.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl2, "Stall"); 
    state->u.f4.fld.otg_hs_doepctl2.cnak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl2, "CNAK"); 
    state->u.f4.fld.otg_hs_doepctl2.snak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl2, "SNAK"); 
    state->u.f4.fld.otg_hs_doepctl2.sd0pid_sevnfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl2, "SD0PID_SEVNFRM"); 
    state->u.f4.fld.otg_hs_doepctl2.soddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl2, "SODDFRM"); 
    state->u.f4.fld.otg_hs_doepctl2.epdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl2, "EPDIS"); 
    state->u.f4.fld.otg_hs_doepctl2.epena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl2, "EPENA");  
    
    // OTG_HS_DOEPCTL3 bitfields.
    state->u.f4.fld.otg_hs_doepctl3.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl3, "MPSIZ"); 
    state->u.f4.fld.otg_hs_doepctl3.usbaep = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl3, "USBAEP"); 
    state->u.f4.fld.otg_hs_doepctl3.eonum_dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl3, "EONUM_DPID"); 
    state->u.f4.fld.otg_hs_doepctl3.naksts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl3, "NAKSTS"); 
    state->u.f4.fld.otg_hs_doepctl3.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl3, "EPTYP"); 
    state->u.f4.fld.otg_hs_doepctl3.snpm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl3, "SNPM"); 
    state->u.f4.fld.otg_hs_doepctl3.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl3, "Stall"); 
    state->u.f4.fld.otg_hs_doepctl3.cnak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl3, "CNAK"); 
    state->u.f4.fld.otg_hs_doepctl3.snak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl3, "SNAK"); 
    state->u.f4.fld.otg_hs_doepctl3.sd0pid_sevnfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl3, "SD0PID_SEVNFRM"); 
    state->u.f4.fld.otg_hs_doepctl3.soddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl3, "SODDFRM"); 
    state->u.f4.fld.otg_hs_doepctl3.epdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl3, "EPDIS"); 
    state->u.f4.fld.otg_hs_doepctl3.epena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepctl3, "EPENA");  
    
    // OTG_HS_DOEPINT0 bitfields.
    state->u.f4.fld.otg_hs_doepint0.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint0, "XFRC"); 
    state->u.f4.fld.otg_hs_doepint0.epdisd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint0, "EPDISD"); 
    state->u.f4.fld.otg_hs_doepint0.stup = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint0, "STUP"); 
    state->u.f4.fld.otg_hs_doepint0.otepdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint0, "OTEPDIS"); 
    state->u.f4.fld.otg_hs_doepint0.b2bstup = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint0, "B2BSTUP"); 
    state->u.f4.fld.otg_hs_doepint0.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint0, "NYET");  
    
    // OTG_HS_DOEPINT1 bitfields.
    state->u.f4.fld.otg_hs_doepint1.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint1, "XFRC"); 
    state->u.f4.fld.otg_hs_doepint1.epdisd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint1, "EPDISD"); 
    state->u.f4.fld.otg_hs_doepint1.stup = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint1, "STUP"); 
    state->u.f4.fld.otg_hs_doepint1.otepdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint1, "OTEPDIS"); 
    state->u.f4.fld.otg_hs_doepint1.b2bstup = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint1, "B2BSTUP"); 
    state->u.f4.fld.otg_hs_doepint1.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint1, "NYET");  
    
    // OTG_HS_DOEPINT2 bitfields.
    state->u.f4.fld.otg_hs_doepint2.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint2, "XFRC"); 
    state->u.f4.fld.otg_hs_doepint2.epdisd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint2, "EPDISD"); 
    state->u.f4.fld.otg_hs_doepint2.stup = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint2, "STUP"); 
    state->u.f4.fld.otg_hs_doepint2.otepdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint2, "OTEPDIS"); 
    state->u.f4.fld.otg_hs_doepint2.b2bstup = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint2, "B2BSTUP"); 
    state->u.f4.fld.otg_hs_doepint2.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint2, "NYET");  
    
    // OTG_HS_DOEPINT3 bitfields.
    state->u.f4.fld.otg_hs_doepint3.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint3, "XFRC"); 
    state->u.f4.fld.otg_hs_doepint3.epdisd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint3, "EPDISD"); 
    state->u.f4.fld.otg_hs_doepint3.stup = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint3, "STUP"); 
    state->u.f4.fld.otg_hs_doepint3.otepdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint3, "OTEPDIS"); 
    state->u.f4.fld.otg_hs_doepint3.b2bstup = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint3, "B2BSTUP"); 
    state->u.f4.fld.otg_hs_doepint3.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint3, "NYET");  
    
    // OTG_HS_DOEPINT4 bitfields.
    state->u.f4.fld.otg_hs_doepint4.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint4, "XFRC"); 
    state->u.f4.fld.otg_hs_doepint4.epdisd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint4, "EPDISD"); 
    state->u.f4.fld.otg_hs_doepint4.stup = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint4, "STUP"); 
    state->u.f4.fld.otg_hs_doepint4.otepdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint4, "OTEPDIS"); 
    state->u.f4.fld.otg_hs_doepint4.b2bstup = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint4, "B2BSTUP"); 
    state->u.f4.fld.otg_hs_doepint4.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint4, "NYET");  
    
    // OTG_HS_DOEPINT5 bitfields.
    state->u.f4.fld.otg_hs_doepint5.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint5, "XFRC"); 
    state->u.f4.fld.otg_hs_doepint5.epdisd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint5, "EPDISD"); 
    state->u.f4.fld.otg_hs_doepint5.stup = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint5, "STUP"); 
    state->u.f4.fld.otg_hs_doepint5.otepdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint5, "OTEPDIS"); 
    state->u.f4.fld.otg_hs_doepint5.b2bstup = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint5, "B2BSTUP"); 
    state->u.f4.fld.otg_hs_doepint5.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint5, "NYET");  
    
    // OTG_HS_DOEPINT6 bitfields.
    state->u.f4.fld.otg_hs_doepint6.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint6, "XFRC"); 
    state->u.f4.fld.otg_hs_doepint6.epdisd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint6, "EPDISD"); 
    state->u.f4.fld.otg_hs_doepint6.stup = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint6, "STUP"); 
    state->u.f4.fld.otg_hs_doepint6.otepdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint6, "OTEPDIS"); 
    state->u.f4.fld.otg_hs_doepint6.b2bstup = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint6, "B2BSTUP"); 
    state->u.f4.fld.otg_hs_doepint6.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint6, "NYET");  
    
    // OTG_HS_DOEPINT7 bitfields.
    state->u.f4.fld.otg_hs_doepint7.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint7, "XFRC"); 
    state->u.f4.fld.otg_hs_doepint7.epdisd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint7, "EPDISD"); 
    state->u.f4.fld.otg_hs_doepint7.stup = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint7, "STUP"); 
    state->u.f4.fld.otg_hs_doepint7.otepdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint7, "OTEPDIS"); 
    state->u.f4.fld.otg_hs_doepint7.b2bstup = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint7, "B2BSTUP"); 
    state->u.f4.fld.otg_hs_doepint7.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doepint7, "NYET");  
    
    // OTG_HS_DOEPTSIZ0 bitfields.
    state->u.f4.fld.otg_hs_doeptsiz0.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doeptsiz0, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_doeptsiz0.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doeptsiz0, "PKTCNT"); 
    state->u.f4.fld.otg_hs_doeptsiz0.stupcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doeptsiz0, "STUPCNT");  
    
    // OTG_HS_DOEPTSIZ1 bitfields.
    state->u.f4.fld.otg_hs_doeptsiz1.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doeptsiz1, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_doeptsiz1.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doeptsiz1, "PKTCNT"); 
    state->u.f4.fld.otg_hs_doeptsiz1.rxdpid_stupcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doeptsiz1, "RXDPID_STUPCNT");  
    
    // OTG_HS_DOEPTSIZ2 bitfields.
    state->u.f4.fld.otg_hs_doeptsiz2.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doeptsiz2, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_doeptsiz2.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doeptsiz2, "PKTCNT"); 
    state->u.f4.fld.otg_hs_doeptsiz2.rxdpid_stupcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doeptsiz2, "RXDPID_STUPCNT");  
    
    // OTG_HS_DOEPTSIZ3 bitfields.
    state->u.f4.fld.otg_hs_doeptsiz3.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doeptsiz3, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_doeptsiz3.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doeptsiz3, "PKTCNT"); 
    state->u.f4.fld.otg_hs_doeptsiz3.rxdpid_stupcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doeptsiz3, "RXDPID_STUPCNT");  
    
    // OTG_HS_DOEPTSIZ4 bitfields.
    state->u.f4.fld.otg_hs_doeptsiz4.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doeptsiz4, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_doeptsiz4.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doeptsiz4, "PKTCNT"); 
    state->u.f4.fld.otg_hs_doeptsiz4.rxdpid_stupcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_doeptsiz4, "RXDPID_STUPCNT");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_otg_hs_device_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32OTG_HS_DEVICEState *state = STM32_OTG_HS_DEVICE_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_otg_hs_device_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32OTG_HS_DEVICEState *state = STM32_OTG_HS_DEVICE_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_otg_hs_device_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32OTG_HS_DEVICEState *state = STM32_OTG_HS_DEVICE_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_otg_hs_device_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32OTG_HS_DEVICEState *state = STM32_OTG_HS_DEVICE_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_otg_hs_device_is_enabled(Object *obj)
{
    STM32OTG_HS_DEVICEState *state = STM32_OTG_HS_DEVICE_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_otg_hs_device_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32OTG_HS_DEVICEState *state = STM32_OTG_HS_DEVICE_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_otg_hs_device_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_OTG_HS_DEVICE)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32OTG_HS_DEVICEState *state = STM32_OTG_HS_DEVICE_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "OTG_HS_DEVICE";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_429x ) {

            stm32f429x_otg_hs_device_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_otg_hs_device_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_otg_hs_device_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_otg_hs_device_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_otg_hs_device_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/OTG_HS_DEVICEEN");


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

static void stm32_otg_hs_device_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_OTG_HS_DEVICE);
}

static void stm32_otg_hs_device_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_otg_hs_device_reset_callback;
    dc->realize = stm32_otg_hs_device_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_otg_hs_device_is_enabled;
}

static const TypeInfo stm32_otg_hs_device_type_info = {
    .name = TYPE_STM32_OTG_HS_DEVICE,
    .parent = TYPE_STM32_OTG_HS_DEVICE_PARENT,
    .instance_init = stm32_otg_hs_device_instance_init_callback,
    .instance_size = sizeof(STM32OTG_HS_DEVICEState),
    .class_init = stm32_otg_hs_device_class_init_callback,
    .class_size = sizeof(STM32OTG_HS_DEVICEClass) };

static void stm32_otg_hs_device_register_types(void)
{
    type_register_static(&stm32_otg_hs_device_type_info);
}

type_init(stm32_otg_hs_device_register_types);

// ----------------------------------------------------------------------------
