/*
 * STM32 - OTG_HS_HOST (USB on the go high speed) emulation.
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

#include <hw/cortexm/stm32/otg_hs_host.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f429x_otg_hs_host_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32OTG_HS_HOSTState *state = STM32_OTG_HS_HOST_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.otg_hs_hcfg = cm_object_get_child_by_name(obj, "OTG_HS_HCFG");
    state->u.f4.reg.otg_hs_hfir = cm_object_get_child_by_name(obj, "OTG_HS_HFIR");
    state->u.f4.reg.otg_hs_hfnum = cm_object_get_child_by_name(obj, "OTG_HS_HFNUM");
    state->u.f4.reg.otg_hs_hptxsts = cm_object_get_child_by_name(obj, "OTG_HS_HPTXSTS");
    state->u.f4.reg.otg_hs_haint = cm_object_get_child_by_name(obj, "OTG_HS_HAINT");
    state->u.f4.reg.otg_hs_haintmsk = cm_object_get_child_by_name(obj, "OTG_HS_HAINTMSK");
    state->u.f4.reg.otg_hs_hprt = cm_object_get_child_by_name(obj, "OTG_HS_HPRT");
    state->u.f4.reg.otg_hs_hcchar0 = cm_object_get_child_by_name(obj, "OTG_HS_HCCHAR0");
    state->u.f4.reg.otg_hs_hcchar1 = cm_object_get_child_by_name(obj, "OTG_HS_HCCHAR1");
    state->u.f4.reg.otg_hs_hcchar2 = cm_object_get_child_by_name(obj, "OTG_HS_HCCHAR2");
    state->u.f4.reg.otg_hs_hcchar3 = cm_object_get_child_by_name(obj, "OTG_HS_HCCHAR3");
    state->u.f4.reg.otg_hs_hcchar4 = cm_object_get_child_by_name(obj, "OTG_HS_HCCHAR4");
    state->u.f4.reg.otg_hs_hcchar5 = cm_object_get_child_by_name(obj, "OTG_HS_HCCHAR5");
    state->u.f4.reg.otg_hs_hcchar6 = cm_object_get_child_by_name(obj, "OTG_HS_HCCHAR6");
    state->u.f4.reg.otg_hs_hcchar7 = cm_object_get_child_by_name(obj, "OTG_HS_HCCHAR7");
    state->u.f4.reg.otg_hs_hcchar8 = cm_object_get_child_by_name(obj, "OTG_HS_HCCHAR8");
    state->u.f4.reg.otg_hs_hcchar9 = cm_object_get_child_by_name(obj, "OTG_HS_HCCHAR9");
    state->u.f4.reg.otg_hs_hcchar10 = cm_object_get_child_by_name(obj, "OTG_HS_HCCHAR10");
    state->u.f4.reg.otg_hs_hcchar11 = cm_object_get_child_by_name(obj, "OTG_HS_HCCHAR11");
    state->u.f4.reg.otg_hs_hcsplt0 = cm_object_get_child_by_name(obj, "OTG_HS_HCSPLT0");
    state->u.f4.reg.otg_hs_hcsplt1 = cm_object_get_child_by_name(obj, "OTG_HS_HCSPLT1");
    state->u.f4.reg.otg_hs_hcsplt2 = cm_object_get_child_by_name(obj, "OTG_HS_HCSPLT2");
    state->u.f4.reg.otg_hs_hcsplt3 = cm_object_get_child_by_name(obj, "OTG_HS_HCSPLT3");
    state->u.f4.reg.otg_hs_hcsplt4 = cm_object_get_child_by_name(obj, "OTG_HS_HCSPLT4");
    state->u.f4.reg.otg_hs_hcsplt5 = cm_object_get_child_by_name(obj, "OTG_HS_HCSPLT5");
    state->u.f4.reg.otg_hs_hcsplt6 = cm_object_get_child_by_name(obj, "OTG_HS_HCSPLT6");
    state->u.f4.reg.otg_hs_hcsplt7 = cm_object_get_child_by_name(obj, "OTG_HS_HCSPLT7");
    state->u.f4.reg.otg_hs_hcsplt8 = cm_object_get_child_by_name(obj, "OTG_HS_HCSPLT8");
    state->u.f4.reg.otg_hs_hcsplt9 = cm_object_get_child_by_name(obj, "OTG_HS_HCSPLT9");
    state->u.f4.reg.otg_hs_hcsplt10 = cm_object_get_child_by_name(obj, "OTG_HS_HCSPLT10");
    state->u.f4.reg.otg_hs_hcsplt11 = cm_object_get_child_by_name(obj, "OTG_HS_HCSPLT11");
    state->u.f4.reg.otg_hs_hcint0 = cm_object_get_child_by_name(obj, "OTG_HS_HCINT0");
    state->u.f4.reg.otg_hs_hcint1 = cm_object_get_child_by_name(obj, "OTG_HS_HCINT1");
    state->u.f4.reg.otg_hs_hcint2 = cm_object_get_child_by_name(obj, "OTG_HS_HCINT2");
    state->u.f4.reg.otg_hs_hcint3 = cm_object_get_child_by_name(obj, "OTG_HS_HCINT3");
    state->u.f4.reg.otg_hs_hcint4 = cm_object_get_child_by_name(obj, "OTG_HS_HCINT4");
    state->u.f4.reg.otg_hs_hcint5 = cm_object_get_child_by_name(obj, "OTG_HS_HCINT5");
    state->u.f4.reg.otg_hs_hcint6 = cm_object_get_child_by_name(obj, "OTG_HS_HCINT6");
    state->u.f4.reg.otg_hs_hcint7 = cm_object_get_child_by_name(obj, "OTG_HS_HCINT7");
    state->u.f4.reg.otg_hs_hcint8 = cm_object_get_child_by_name(obj, "OTG_HS_HCINT8");
    state->u.f4.reg.otg_hs_hcint9 = cm_object_get_child_by_name(obj, "OTG_HS_HCINT9");
    state->u.f4.reg.otg_hs_hcint10 = cm_object_get_child_by_name(obj, "OTG_HS_HCINT10");
    state->u.f4.reg.otg_hs_hcint11 = cm_object_get_child_by_name(obj, "OTG_HS_HCINT11");
    state->u.f4.reg.otg_hs_hcintmsk0 = cm_object_get_child_by_name(obj, "OTG_HS_HCINTMSK0");
    state->u.f4.reg.otg_hs_hcintmsk1 = cm_object_get_child_by_name(obj, "OTG_HS_HCINTMSK1");
    state->u.f4.reg.otg_hs_hcintmsk2 = cm_object_get_child_by_name(obj, "OTG_HS_HCINTMSK2");
    state->u.f4.reg.otg_hs_hcintmsk3 = cm_object_get_child_by_name(obj, "OTG_HS_HCINTMSK3");
    state->u.f4.reg.otg_hs_hcintmsk4 = cm_object_get_child_by_name(obj, "OTG_HS_HCINTMSK4");
    state->u.f4.reg.otg_hs_hcintmsk5 = cm_object_get_child_by_name(obj, "OTG_HS_HCINTMSK5");
    state->u.f4.reg.otg_hs_hcintmsk6 = cm_object_get_child_by_name(obj, "OTG_HS_HCINTMSK6");
    state->u.f4.reg.otg_hs_hcintmsk7 = cm_object_get_child_by_name(obj, "OTG_HS_HCINTMSK7");
    state->u.f4.reg.otg_hs_hcintmsk8 = cm_object_get_child_by_name(obj, "OTG_HS_HCINTMSK8");
    state->u.f4.reg.otg_hs_hcintmsk9 = cm_object_get_child_by_name(obj, "OTG_HS_HCINTMSK9");
    state->u.f4.reg.otg_hs_hcintmsk10 = cm_object_get_child_by_name(obj, "OTG_HS_HCINTMSK10");
    state->u.f4.reg.otg_hs_hcintmsk11 = cm_object_get_child_by_name(obj, "OTG_HS_HCINTMSK11");
    state->u.f4.reg.otg_hs_hctsiz0 = cm_object_get_child_by_name(obj, "OTG_HS_HCTSIZ0");
    state->u.f4.reg.otg_hs_hctsiz1 = cm_object_get_child_by_name(obj, "OTG_HS_HCTSIZ1");
    state->u.f4.reg.otg_hs_hctsiz2 = cm_object_get_child_by_name(obj, "OTG_HS_HCTSIZ2");
    state->u.f4.reg.otg_hs_hctsiz3 = cm_object_get_child_by_name(obj, "OTG_HS_HCTSIZ3");
    state->u.f4.reg.otg_hs_hctsiz4 = cm_object_get_child_by_name(obj, "OTG_HS_HCTSIZ4");
    state->u.f4.reg.otg_hs_hctsiz5 = cm_object_get_child_by_name(obj, "OTG_HS_HCTSIZ5");
    state->u.f4.reg.otg_hs_hctsiz6 = cm_object_get_child_by_name(obj, "OTG_HS_HCTSIZ6");
    state->u.f4.reg.otg_hs_hctsiz7 = cm_object_get_child_by_name(obj, "OTG_HS_HCTSIZ7");
    state->u.f4.reg.otg_hs_hctsiz8 = cm_object_get_child_by_name(obj, "OTG_HS_HCTSIZ8");
    state->u.f4.reg.otg_hs_hctsiz9 = cm_object_get_child_by_name(obj, "OTG_HS_HCTSIZ9");
    state->u.f4.reg.otg_hs_hctsiz10 = cm_object_get_child_by_name(obj, "OTG_HS_HCTSIZ10");
    state->u.f4.reg.otg_hs_hctsiz11 = cm_object_get_child_by_name(obj, "OTG_HS_HCTSIZ11");
    state->u.f4.reg.otg_hs_hcdma0 = cm_object_get_child_by_name(obj, "OTG_HS_HCDMA0");
    state->u.f4.reg.otg_hs_hcdma1 = cm_object_get_child_by_name(obj, "OTG_HS_HCDMA1");
    state->u.f4.reg.otg_hs_hcdma2 = cm_object_get_child_by_name(obj, "OTG_HS_HCDMA2");
    state->u.f4.reg.otg_hs_hcdma3 = cm_object_get_child_by_name(obj, "OTG_HS_HCDMA3");
    state->u.f4.reg.otg_hs_hcdma4 = cm_object_get_child_by_name(obj, "OTG_HS_HCDMA4");
    state->u.f4.reg.otg_hs_hcdma5 = cm_object_get_child_by_name(obj, "OTG_HS_HCDMA5");
    state->u.f4.reg.otg_hs_hcdma6 = cm_object_get_child_by_name(obj, "OTG_HS_HCDMA6");
    state->u.f4.reg.otg_hs_hcdma7 = cm_object_get_child_by_name(obj, "OTG_HS_HCDMA7");
    state->u.f4.reg.otg_hs_hcdma8 = cm_object_get_child_by_name(obj, "OTG_HS_HCDMA8");
    state->u.f4.reg.otg_hs_hcdma9 = cm_object_get_child_by_name(obj, "OTG_HS_HCDMA9");
    state->u.f4.reg.otg_hs_hcdma10 = cm_object_get_child_by_name(obj, "OTG_HS_HCDMA10");
    state->u.f4.reg.otg_hs_hcdma11 = cm_object_get_child_by_name(obj, "OTG_HS_HCDMA11");
    
    
    // OTG_HS_HCFG bitfields.
    state->u.f4.fld.otg_hs_hcfg.fslspcs = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcfg, "FSLSPCS"); 
    state->u.f4.fld.otg_hs_hcfg.fslss = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcfg, "FSLSS");  
    
    // OTG_HS_HFIR bitfields.
    state->u.f4.fld.otg_hs_hfir.frivl = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hfir, "FRIVL");  
    
    // OTG_HS_HFNUM bitfields.
    state->u.f4.fld.otg_hs_hfnum.frnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hfnum, "FRNUM"); 
    state->u.f4.fld.otg_hs_hfnum.ftrem = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hfnum, "FTREM");  
    
    // OTG_HS_HPTXSTS bitfields.
    state->u.f4.fld.otg_hs_hptxsts.ptxfsavl = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hptxsts, "PTXFSAVL"); 
    state->u.f4.fld.otg_hs_hptxsts.ptxqsav = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hptxsts, "PTXQSAV"); 
    state->u.f4.fld.otg_hs_hptxsts.ptxqtop = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hptxsts, "PTXQTOP");  
    
    // OTG_HS_HAINT bitfields.
    state->u.f4.fld.otg_hs_haint.haint = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_haint, "HAINT");  
    
    // OTG_HS_HAINTMSK bitfields.
    state->u.f4.fld.otg_hs_haintmsk.haintm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_haintmsk, "HAINTM");  
    
    // OTG_HS_HPRT bitfields.
    state->u.f4.fld.otg_hs_hprt.pcsts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hprt, "PCSTS"); 
    state->u.f4.fld.otg_hs_hprt.pcdet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hprt, "PCDET"); 
    state->u.f4.fld.otg_hs_hprt.pena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hprt, "PENA"); 
    state->u.f4.fld.otg_hs_hprt.penchng = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hprt, "PENCHNG"); 
    state->u.f4.fld.otg_hs_hprt.poca = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hprt, "POCA"); 
    state->u.f4.fld.otg_hs_hprt.pocchng = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hprt, "POCCHNG"); 
    state->u.f4.fld.otg_hs_hprt.pres = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hprt, "PRES"); 
    state->u.f4.fld.otg_hs_hprt.psusp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hprt, "PSUSP"); 
    state->u.f4.fld.otg_hs_hprt.prst = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hprt, "PRST"); 
    state->u.f4.fld.otg_hs_hprt.plsts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hprt, "PLSTS"); 
    state->u.f4.fld.otg_hs_hprt.ppwr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hprt, "PPWR"); 
    state->u.f4.fld.otg_hs_hprt.ptctl = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hprt, "PTCTL"); 
    state->u.f4.fld.otg_hs_hprt.pspd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hprt, "PSPD");  
    
    // OTG_HS_HCCHAR0 bitfields.
    state->u.f4.fld.otg_hs_hcchar0.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar0, "MPSIZ"); 
    state->u.f4.fld.otg_hs_hcchar0.epnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar0, "EPNUM"); 
    state->u.f4.fld.otg_hs_hcchar0.epdir = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar0, "EPDIR"); 
    state->u.f4.fld.otg_hs_hcchar0.lsdev = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar0, "LSDEV"); 
    state->u.f4.fld.otg_hs_hcchar0.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar0, "EPTYP"); 
    state->u.f4.fld.otg_hs_hcchar0.mc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar0, "MC"); 
    state->u.f4.fld.otg_hs_hcchar0.dad = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar0, "DAD"); 
    state->u.f4.fld.otg_hs_hcchar0.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar0, "ODDFRM"); 
    state->u.f4.fld.otg_hs_hcchar0.chdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar0, "CHDIS"); 
    state->u.f4.fld.otg_hs_hcchar0.chena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar0, "CHENA");  
    
    // OTG_HS_HCCHAR1 bitfields.
    state->u.f4.fld.otg_hs_hcchar1.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar1, "MPSIZ"); 
    state->u.f4.fld.otg_hs_hcchar1.epnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar1, "EPNUM"); 
    state->u.f4.fld.otg_hs_hcchar1.epdir = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar1, "EPDIR"); 
    state->u.f4.fld.otg_hs_hcchar1.lsdev = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar1, "LSDEV"); 
    state->u.f4.fld.otg_hs_hcchar1.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar1, "EPTYP"); 
    state->u.f4.fld.otg_hs_hcchar1.mc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar1, "MC"); 
    state->u.f4.fld.otg_hs_hcchar1.dad = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar1, "DAD"); 
    state->u.f4.fld.otg_hs_hcchar1.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar1, "ODDFRM"); 
    state->u.f4.fld.otg_hs_hcchar1.chdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar1, "CHDIS"); 
    state->u.f4.fld.otg_hs_hcchar1.chena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar1, "CHENA");  
    
    // OTG_HS_HCCHAR2 bitfields.
    state->u.f4.fld.otg_hs_hcchar2.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar2, "MPSIZ"); 
    state->u.f4.fld.otg_hs_hcchar2.epnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar2, "EPNUM"); 
    state->u.f4.fld.otg_hs_hcchar2.epdir = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar2, "EPDIR"); 
    state->u.f4.fld.otg_hs_hcchar2.lsdev = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar2, "LSDEV"); 
    state->u.f4.fld.otg_hs_hcchar2.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar2, "EPTYP"); 
    state->u.f4.fld.otg_hs_hcchar2.mc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar2, "MC"); 
    state->u.f4.fld.otg_hs_hcchar2.dad = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar2, "DAD"); 
    state->u.f4.fld.otg_hs_hcchar2.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar2, "ODDFRM"); 
    state->u.f4.fld.otg_hs_hcchar2.chdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar2, "CHDIS"); 
    state->u.f4.fld.otg_hs_hcchar2.chena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar2, "CHENA");  
    
    // OTG_HS_HCCHAR3 bitfields.
    state->u.f4.fld.otg_hs_hcchar3.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar3, "MPSIZ"); 
    state->u.f4.fld.otg_hs_hcchar3.epnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar3, "EPNUM"); 
    state->u.f4.fld.otg_hs_hcchar3.epdir = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar3, "EPDIR"); 
    state->u.f4.fld.otg_hs_hcchar3.lsdev = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar3, "LSDEV"); 
    state->u.f4.fld.otg_hs_hcchar3.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar3, "EPTYP"); 
    state->u.f4.fld.otg_hs_hcchar3.mc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar3, "MC"); 
    state->u.f4.fld.otg_hs_hcchar3.dad = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar3, "DAD"); 
    state->u.f4.fld.otg_hs_hcchar3.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar3, "ODDFRM"); 
    state->u.f4.fld.otg_hs_hcchar3.chdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar3, "CHDIS"); 
    state->u.f4.fld.otg_hs_hcchar3.chena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar3, "CHENA");  
    
    // OTG_HS_HCCHAR4 bitfields.
    state->u.f4.fld.otg_hs_hcchar4.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar4, "MPSIZ"); 
    state->u.f4.fld.otg_hs_hcchar4.epnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar4, "EPNUM"); 
    state->u.f4.fld.otg_hs_hcchar4.epdir = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar4, "EPDIR"); 
    state->u.f4.fld.otg_hs_hcchar4.lsdev = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar4, "LSDEV"); 
    state->u.f4.fld.otg_hs_hcchar4.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar4, "EPTYP"); 
    state->u.f4.fld.otg_hs_hcchar4.mc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar4, "MC"); 
    state->u.f4.fld.otg_hs_hcchar4.dad = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar4, "DAD"); 
    state->u.f4.fld.otg_hs_hcchar4.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar4, "ODDFRM"); 
    state->u.f4.fld.otg_hs_hcchar4.chdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar4, "CHDIS"); 
    state->u.f4.fld.otg_hs_hcchar4.chena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar4, "CHENA");  
    
    // OTG_HS_HCCHAR5 bitfields.
    state->u.f4.fld.otg_hs_hcchar5.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar5, "MPSIZ"); 
    state->u.f4.fld.otg_hs_hcchar5.epnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar5, "EPNUM"); 
    state->u.f4.fld.otg_hs_hcchar5.epdir = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar5, "EPDIR"); 
    state->u.f4.fld.otg_hs_hcchar5.lsdev = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar5, "LSDEV"); 
    state->u.f4.fld.otg_hs_hcchar5.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar5, "EPTYP"); 
    state->u.f4.fld.otg_hs_hcchar5.mc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar5, "MC"); 
    state->u.f4.fld.otg_hs_hcchar5.dad = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar5, "DAD"); 
    state->u.f4.fld.otg_hs_hcchar5.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar5, "ODDFRM"); 
    state->u.f4.fld.otg_hs_hcchar5.chdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar5, "CHDIS"); 
    state->u.f4.fld.otg_hs_hcchar5.chena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar5, "CHENA");  
    
    // OTG_HS_HCCHAR6 bitfields.
    state->u.f4.fld.otg_hs_hcchar6.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar6, "MPSIZ"); 
    state->u.f4.fld.otg_hs_hcchar6.epnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar6, "EPNUM"); 
    state->u.f4.fld.otg_hs_hcchar6.epdir = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar6, "EPDIR"); 
    state->u.f4.fld.otg_hs_hcchar6.lsdev = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar6, "LSDEV"); 
    state->u.f4.fld.otg_hs_hcchar6.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar6, "EPTYP"); 
    state->u.f4.fld.otg_hs_hcchar6.mc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar6, "MC"); 
    state->u.f4.fld.otg_hs_hcchar6.dad = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar6, "DAD"); 
    state->u.f4.fld.otg_hs_hcchar6.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar6, "ODDFRM"); 
    state->u.f4.fld.otg_hs_hcchar6.chdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar6, "CHDIS"); 
    state->u.f4.fld.otg_hs_hcchar6.chena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar6, "CHENA");  
    
    // OTG_HS_HCCHAR7 bitfields.
    state->u.f4.fld.otg_hs_hcchar7.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar7, "MPSIZ"); 
    state->u.f4.fld.otg_hs_hcchar7.epnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar7, "EPNUM"); 
    state->u.f4.fld.otg_hs_hcchar7.epdir = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar7, "EPDIR"); 
    state->u.f4.fld.otg_hs_hcchar7.lsdev = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar7, "LSDEV"); 
    state->u.f4.fld.otg_hs_hcchar7.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar7, "EPTYP"); 
    state->u.f4.fld.otg_hs_hcchar7.mc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar7, "MC"); 
    state->u.f4.fld.otg_hs_hcchar7.dad = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar7, "DAD"); 
    state->u.f4.fld.otg_hs_hcchar7.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar7, "ODDFRM"); 
    state->u.f4.fld.otg_hs_hcchar7.chdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar7, "CHDIS"); 
    state->u.f4.fld.otg_hs_hcchar7.chena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar7, "CHENA");  
    
    // OTG_HS_HCCHAR8 bitfields.
    state->u.f4.fld.otg_hs_hcchar8.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar8, "MPSIZ"); 
    state->u.f4.fld.otg_hs_hcchar8.epnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar8, "EPNUM"); 
    state->u.f4.fld.otg_hs_hcchar8.epdir = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar8, "EPDIR"); 
    state->u.f4.fld.otg_hs_hcchar8.lsdev = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar8, "LSDEV"); 
    state->u.f4.fld.otg_hs_hcchar8.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar8, "EPTYP"); 
    state->u.f4.fld.otg_hs_hcchar8.mc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar8, "MC"); 
    state->u.f4.fld.otg_hs_hcchar8.dad = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar8, "DAD"); 
    state->u.f4.fld.otg_hs_hcchar8.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar8, "ODDFRM"); 
    state->u.f4.fld.otg_hs_hcchar8.chdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar8, "CHDIS"); 
    state->u.f4.fld.otg_hs_hcchar8.chena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar8, "CHENA");  
    
    // OTG_HS_HCCHAR9 bitfields.
    state->u.f4.fld.otg_hs_hcchar9.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar9, "MPSIZ"); 
    state->u.f4.fld.otg_hs_hcchar9.epnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar9, "EPNUM"); 
    state->u.f4.fld.otg_hs_hcchar9.epdir = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar9, "EPDIR"); 
    state->u.f4.fld.otg_hs_hcchar9.lsdev = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar9, "LSDEV"); 
    state->u.f4.fld.otg_hs_hcchar9.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar9, "EPTYP"); 
    state->u.f4.fld.otg_hs_hcchar9.mc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar9, "MC"); 
    state->u.f4.fld.otg_hs_hcchar9.dad = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar9, "DAD"); 
    state->u.f4.fld.otg_hs_hcchar9.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar9, "ODDFRM"); 
    state->u.f4.fld.otg_hs_hcchar9.chdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar9, "CHDIS"); 
    state->u.f4.fld.otg_hs_hcchar9.chena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar9, "CHENA");  
    
    // OTG_HS_HCCHAR10 bitfields.
    state->u.f4.fld.otg_hs_hcchar10.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar10, "MPSIZ"); 
    state->u.f4.fld.otg_hs_hcchar10.epnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar10, "EPNUM"); 
    state->u.f4.fld.otg_hs_hcchar10.epdir = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar10, "EPDIR"); 
    state->u.f4.fld.otg_hs_hcchar10.lsdev = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar10, "LSDEV"); 
    state->u.f4.fld.otg_hs_hcchar10.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar10, "EPTYP"); 
    state->u.f4.fld.otg_hs_hcchar10.mc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar10, "MC"); 
    state->u.f4.fld.otg_hs_hcchar10.dad = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar10, "DAD"); 
    state->u.f4.fld.otg_hs_hcchar10.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar10, "ODDFRM"); 
    state->u.f4.fld.otg_hs_hcchar10.chdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar10, "CHDIS"); 
    state->u.f4.fld.otg_hs_hcchar10.chena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar10, "CHENA");  
    
    // OTG_HS_HCCHAR11 bitfields.
    state->u.f4.fld.otg_hs_hcchar11.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar11, "MPSIZ"); 
    state->u.f4.fld.otg_hs_hcchar11.epnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar11, "EPNUM"); 
    state->u.f4.fld.otg_hs_hcchar11.epdir = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar11, "EPDIR"); 
    state->u.f4.fld.otg_hs_hcchar11.lsdev = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar11, "LSDEV"); 
    state->u.f4.fld.otg_hs_hcchar11.eptyp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar11, "EPTYP"); 
    state->u.f4.fld.otg_hs_hcchar11.mc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar11, "MC"); 
    state->u.f4.fld.otg_hs_hcchar11.dad = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar11, "DAD"); 
    state->u.f4.fld.otg_hs_hcchar11.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar11, "ODDFRM"); 
    state->u.f4.fld.otg_hs_hcchar11.chdis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar11, "CHDIS"); 
    state->u.f4.fld.otg_hs_hcchar11.chena = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcchar11, "CHENA");  
    
    // OTG_HS_HCSPLT0 bitfields.
    state->u.f4.fld.otg_hs_hcsplt0.prtaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt0, "PRTADDR"); 
    state->u.f4.fld.otg_hs_hcsplt0.hubaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt0, "HUBADDR"); 
    state->u.f4.fld.otg_hs_hcsplt0.xactpos = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt0, "XACTPOS"); 
    state->u.f4.fld.otg_hs_hcsplt0.complsplt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt0, "COMPLSPLT"); 
    state->u.f4.fld.otg_hs_hcsplt0.spliten = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt0, "SPLITEN");  
    
    // OTG_HS_HCSPLT1 bitfields.
    state->u.f4.fld.otg_hs_hcsplt1.prtaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt1, "PRTADDR"); 
    state->u.f4.fld.otg_hs_hcsplt1.hubaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt1, "HUBADDR"); 
    state->u.f4.fld.otg_hs_hcsplt1.xactpos = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt1, "XACTPOS"); 
    state->u.f4.fld.otg_hs_hcsplt1.complsplt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt1, "COMPLSPLT"); 
    state->u.f4.fld.otg_hs_hcsplt1.spliten = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt1, "SPLITEN");  
    
    // OTG_HS_HCSPLT2 bitfields.
    state->u.f4.fld.otg_hs_hcsplt2.prtaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt2, "PRTADDR"); 
    state->u.f4.fld.otg_hs_hcsplt2.hubaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt2, "HUBADDR"); 
    state->u.f4.fld.otg_hs_hcsplt2.xactpos = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt2, "XACTPOS"); 
    state->u.f4.fld.otg_hs_hcsplt2.complsplt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt2, "COMPLSPLT"); 
    state->u.f4.fld.otg_hs_hcsplt2.spliten = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt2, "SPLITEN");  
    
    // OTG_HS_HCSPLT3 bitfields.
    state->u.f4.fld.otg_hs_hcsplt3.prtaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt3, "PRTADDR"); 
    state->u.f4.fld.otg_hs_hcsplt3.hubaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt3, "HUBADDR"); 
    state->u.f4.fld.otg_hs_hcsplt3.xactpos = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt3, "XACTPOS"); 
    state->u.f4.fld.otg_hs_hcsplt3.complsplt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt3, "COMPLSPLT"); 
    state->u.f4.fld.otg_hs_hcsplt3.spliten = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt3, "SPLITEN");  
    
    // OTG_HS_HCSPLT4 bitfields.
    state->u.f4.fld.otg_hs_hcsplt4.prtaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt4, "PRTADDR"); 
    state->u.f4.fld.otg_hs_hcsplt4.hubaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt4, "HUBADDR"); 
    state->u.f4.fld.otg_hs_hcsplt4.xactpos = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt4, "XACTPOS"); 
    state->u.f4.fld.otg_hs_hcsplt4.complsplt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt4, "COMPLSPLT"); 
    state->u.f4.fld.otg_hs_hcsplt4.spliten = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt4, "SPLITEN");  
    
    // OTG_HS_HCSPLT5 bitfields.
    state->u.f4.fld.otg_hs_hcsplt5.prtaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt5, "PRTADDR"); 
    state->u.f4.fld.otg_hs_hcsplt5.hubaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt5, "HUBADDR"); 
    state->u.f4.fld.otg_hs_hcsplt5.xactpos = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt5, "XACTPOS"); 
    state->u.f4.fld.otg_hs_hcsplt5.complsplt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt5, "COMPLSPLT"); 
    state->u.f4.fld.otg_hs_hcsplt5.spliten = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt5, "SPLITEN");  
    
    // OTG_HS_HCSPLT6 bitfields.
    state->u.f4.fld.otg_hs_hcsplt6.prtaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt6, "PRTADDR"); 
    state->u.f4.fld.otg_hs_hcsplt6.hubaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt6, "HUBADDR"); 
    state->u.f4.fld.otg_hs_hcsplt6.xactpos = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt6, "XACTPOS"); 
    state->u.f4.fld.otg_hs_hcsplt6.complsplt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt6, "COMPLSPLT"); 
    state->u.f4.fld.otg_hs_hcsplt6.spliten = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt6, "SPLITEN");  
    
    // OTG_HS_HCSPLT7 bitfields.
    state->u.f4.fld.otg_hs_hcsplt7.prtaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt7, "PRTADDR"); 
    state->u.f4.fld.otg_hs_hcsplt7.hubaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt7, "HUBADDR"); 
    state->u.f4.fld.otg_hs_hcsplt7.xactpos = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt7, "XACTPOS"); 
    state->u.f4.fld.otg_hs_hcsplt7.complsplt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt7, "COMPLSPLT"); 
    state->u.f4.fld.otg_hs_hcsplt7.spliten = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt7, "SPLITEN");  
    
    // OTG_HS_HCSPLT8 bitfields.
    state->u.f4.fld.otg_hs_hcsplt8.prtaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt8, "PRTADDR"); 
    state->u.f4.fld.otg_hs_hcsplt8.hubaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt8, "HUBADDR"); 
    state->u.f4.fld.otg_hs_hcsplt8.xactpos = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt8, "XACTPOS"); 
    state->u.f4.fld.otg_hs_hcsplt8.complsplt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt8, "COMPLSPLT"); 
    state->u.f4.fld.otg_hs_hcsplt8.spliten = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt8, "SPLITEN");  
    
    // OTG_HS_HCSPLT9 bitfields.
    state->u.f4.fld.otg_hs_hcsplt9.prtaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt9, "PRTADDR"); 
    state->u.f4.fld.otg_hs_hcsplt9.hubaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt9, "HUBADDR"); 
    state->u.f4.fld.otg_hs_hcsplt9.xactpos = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt9, "XACTPOS"); 
    state->u.f4.fld.otg_hs_hcsplt9.complsplt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt9, "COMPLSPLT"); 
    state->u.f4.fld.otg_hs_hcsplt9.spliten = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt9, "SPLITEN");  
    
    // OTG_HS_HCSPLT10 bitfields.
    state->u.f4.fld.otg_hs_hcsplt10.prtaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt10, "PRTADDR"); 
    state->u.f4.fld.otg_hs_hcsplt10.hubaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt10, "HUBADDR"); 
    state->u.f4.fld.otg_hs_hcsplt10.xactpos = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt10, "XACTPOS"); 
    state->u.f4.fld.otg_hs_hcsplt10.complsplt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt10, "COMPLSPLT"); 
    state->u.f4.fld.otg_hs_hcsplt10.spliten = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt10, "SPLITEN");  
    
    // OTG_HS_HCSPLT11 bitfields.
    state->u.f4.fld.otg_hs_hcsplt11.prtaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt11, "PRTADDR"); 
    state->u.f4.fld.otg_hs_hcsplt11.hubaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt11, "HUBADDR"); 
    state->u.f4.fld.otg_hs_hcsplt11.xactpos = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt11, "XACTPOS"); 
    state->u.f4.fld.otg_hs_hcsplt11.complsplt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt11, "COMPLSPLT"); 
    state->u.f4.fld.otg_hs_hcsplt11.spliten = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcsplt11, "SPLITEN");  
    
    // OTG_HS_HCINT0 bitfields.
    state->u.f4.fld.otg_hs_hcint0.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint0, "XFRC"); 
    state->u.f4.fld.otg_hs_hcint0.chh = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint0, "CHH"); 
    state->u.f4.fld.otg_hs_hcint0.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint0, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcint0.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint0, "STALL"); 
    state->u.f4.fld.otg_hs_hcint0.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint0, "NAK"); 
    state->u.f4.fld.otg_hs_hcint0.ack = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint0, "ACK"); 
    state->u.f4.fld.otg_hs_hcint0.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint0, "NYET"); 
    state->u.f4.fld.otg_hs_hcint0.txerr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint0, "TXERR"); 
    state->u.f4.fld.otg_hs_hcint0.bberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint0, "BBERR"); 
    state->u.f4.fld.otg_hs_hcint0.frmor = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint0, "FRMOR"); 
    state->u.f4.fld.otg_hs_hcint0.dterr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint0, "DTERR");  
    
    // OTG_HS_HCINT1 bitfields.
    state->u.f4.fld.otg_hs_hcint1.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint1, "XFRC"); 
    state->u.f4.fld.otg_hs_hcint1.chh = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint1, "CHH"); 
    state->u.f4.fld.otg_hs_hcint1.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint1, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcint1.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint1, "STALL"); 
    state->u.f4.fld.otg_hs_hcint1.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint1, "NAK"); 
    state->u.f4.fld.otg_hs_hcint1.ack = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint1, "ACK"); 
    state->u.f4.fld.otg_hs_hcint1.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint1, "NYET"); 
    state->u.f4.fld.otg_hs_hcint1.txerr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint1, "TXERR"); 
    state->u.f4.fld.otg_hs_hcint1.bberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint1, "BBERR"); 
    state->u.f4.fld.otg_hs_hcint1.frmor = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint1, "FRMOR"); 
    state->u.f4.fld.otg_hs_hcint1.dterr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint1, "DTERR");  
    
    // OTG_HS_HCINT2 bitfields.
    state->u.f4.fld.otg_hs_hcint2.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint2, "XFRC"); 
    state->u.f4.fld.otg_hs_hcint2.chh = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint2, "CHH"); 
    state->u.f4.fld.otg_hs_hcint2.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint2, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcint2.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint2, "STALL"); 
    state->u.f4.fld.otg_hs_hcint2.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint2, "NAK"); 
    state->u.f4.fld.otg_hs_hcint2.ack = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint2, "ACK"); 
    state->u.f4.fld.otg_hs_hcint2.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint2, "NYET"); 
    state->u.f4.fld.otg_hs_hcint2.txerr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint2, "TXERR"); 
    state->u.f4.fld.otg_hs_hcint2.bberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint2, "BBERR"); 
    state->u.f4.fld.otg_hs_hcint2.frmor = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint2, "FRMOR"); 
    state->u.f4.fld.otg_hs_hcint2.dterr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint2, "DTERR");  
    
    // OTG_HS_HCINT3 bitfields.
    state->u.f4.fld.otg_hs_hcint3.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint3, "XFRC"); 
    state->u.f4.fld.otg_hs_hcint3.chh = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint3, "CHH"); 
    state->u.f4.fld.otg_hs_hcint3.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint3, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcint3.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint3, "STALL"); 
    state->u.f4.fld.otg_hs_hcint3.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint3, "NAK"); 
    state->u.f4.fld.otg_hs_hcint3.ack = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint3, "ACK"); 
    state->u.f4.fld.otg_hs_hcint3.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint3, "NYET"); 
    state->u.f4.fld.otg_hs_hcint3.txerr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint3, "TXERR"); 
    state->u.f4.fld.otg_hs_hcint3.bberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint3, "BBERR"); 
    state->u.f4.fld.otg_hs_hcint3.frmor = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint3, "FRMOR"); 
    state->u.f4.fld.otg_hs_hcint3.dterr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint3, "DTERR");  
    
    // OTG_HS_HCINT4 bitfields.
    state->u.f4.fld.otg_hs_hcint4.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint4, "XFRC"); 
    state->u.f4.fld.otg_hs_hcint4.chh = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint4, "CHH"); 
    state->u.f4.fld.otg_hs_hcint4.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint4, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcint4.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint4, "STALL"); 
    state->u.f4.fld.otg_hs_hcint4.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint4, "NAK"); 
    state->u.f4.fld.otg_hs_hcint4.ack = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint4, "ACK"); 
    state->u.f4.fld.otg_hs_hcint4.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint4, "NYET"); 
    state->u.f4.fld.otg_hs_hcint4.txerr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint4, "TXERR"); 
    state->u.f4.fld.otg_hs_hcint4.bberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint4, "BBERR"); 
    state->u.f4.fld.otg_hs_hcint4.frmor = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint4, "FRMOR"); 
    state->u.f4.fld.otg_hs_hcint4.dterr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint4, "DTERR");  
    
    // OTG_HS_HCINT5 bitfields.
    state->u.f4.fld.otg_hs_hcint5.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint5, "XFRC"); 
    state->u.f4.fld.otg_hs_hcint5.chh = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint5, "CHH"); 
    state->u.f4.fld.otg_hs_hcint5.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint5, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcint5.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint5, "STALL"); 
    state->u.f4.fld.otg_hs_hcint5.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint5, "NAK"); 
    state->u.f4.fld.otg_hs_hcint5.ack = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint5, "ACK"); 
    state->u.f4.fld.otg_hs_hcint5.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint5, "NYET"); 
    state->u.f4.fld.otg_hs_hcint5.txerr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint5, "TXERR"); 
    state->u.f4.fld.otg_hs_hcint5.bberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint5, "BBERR"); 
    state->u.f4.fld.otg_hs_hcint5.frmor = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint5, "FRMOR"); 
    state->u.f4.fld.otg_hs_hcint5.dterr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint5, "DTERR");  
    
    // OTG_HS_HCINT6 bitfields.
    state->u.f4.fld.otg_hs_hcint6.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint6, "XFRC"); 
    state->u.f4.fld.otg_hs_hcint6.chh = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint6, "CHH"); 
    state->u.f4.fld.otg_hs_hcint6.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint6, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcint6.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint6, "STALL"); 
    state->u.f4.fld.otg_hs_hcint6.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint6, "NAK"); 
    state->u.f4.fld.otg_hs_hcint6.ack = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint6, "ACK"); 
    state->u.f4.fld.otg_hs_hcint6.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint6, "NYET"); 
    state->u.f4.fld.otg_hs_hcint6.txerr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint6, "TXERR"); 
    state->u.f4.fld.otg_hs_hcint6.bberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint6, "BBERR"); 
    state->u.f4.fld.otg_hs_hcint6.frmor = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint6, "FRMOR"); 
    state->u.f4.fld.otg_hs_hcint6.dterr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint6, "DTERR");  
    
    // OTG_HS_HCINT7 bitfields.
    state->u.f4.fld.otg_hs_hcint7.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint7, "XFRC"); 
    state->u.f4.fld.otg_hs_hcint7.chh = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint7, "CHH"); 
    state->u.f4.fld.otg_hs_hcint7.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint7, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcint7.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint7, "STALL"); 
    state->u.f4.fld.otg_hs_hcint7.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint7, "NAK"); 
    state->u.f4.fld.otg_hs_hcint7.ack = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint7, "ACK"); 
    state->u.f4.fld.otg_hs_hcint7.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint7, "NYET"); 
    state->u.f4.fld.otg_hs_hcint7.txerr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint7, "TXERR"); 
    state->u.f4.fld.otg_hs_hcint7.bberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint7, "BBERR"); 
    state->u.f4.fld.otg_hs_hcint7.frmor = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint7, "FRMOR"); 
    state->u.f4.fld.otg_hs_hcint7.dterr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint7, "DTERR");  
    
    // OTG_HS_HCINT8 bitfields.
    state->u.f4.fld.otg_hs_hcint8.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint8, "XFRC"); 
    state->u.f4.fld.otg_hs_hcint8.chh = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint8, "CHH"); 
    state->u.f4.fld.otg_hs_hcint8.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint8, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcint8.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint8, "STALL"); 
    state->u.f4.fld.otg_hs_hcint8.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint8, "NAK"); 
    state->u.f4.fld.otg_hs_hcint8.ack = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint8, "ACK"); 
    state->u.f4.fld.otg_hs_hcint8.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint8, "NYET"); 
    state->u.f4.fld.otg_hs_hcint8.txerr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint8, "TXERR"); 
    state->u.f4.fld.otg_hs_hcint8.bberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint8, "BBERR"); 
    state->u.f4.fld.otg_hs_hcint8.frmor = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint8, "FRMOR"); 
    state->u.f4.fld.otg_hs_hcint8.dterr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint8, "DTERR");  
    
    // OTG_HS_HCINT9 bitfields.
    state->u.f4.fld.otg_hs_hcint9.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint9, "XFRC"); 
    state->u.f4.fld.otg_hs_hcint9.chh = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint9, "CHH"); 
    state->u.f4.fld.otg_hs_hcint9.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint9, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcint9.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint9, "STALL"); 
    state->u.f4.fld.otg_hs_hcint9.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint9, "NAK"); 
    state->u.f4.fld.otg_hs_hcint9.ack = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint9, "ACK"); 
    state->u.f4.fld.otg_hs_hcint9.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint9, "NYET"); 
    state->u.f4.fld.otg_hs_hcint9.txerr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint9, "TXERR"); 
    state->u.f4.fld.otg_hs_hcint9.bberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint9, "BBERR"); 
    state->u.f4.fld.otg_hs_hcint9.frmor = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint9, "FRMOR"); 
    state->u.f4.fld.otg_hs_hcint9.dterr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint9, "DTERR");  
    
    // OTG_HS_HCINT10 bitfields.
    state->u.f4.fld.otg_hs_hcint10.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint10, "XFRC"); 
    state->u.f4.fld.otg_hs_hcint10.chh = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint10, "CHH"); 
    state->u.f4.fld.otg_hs_hcint10.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint10, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcint10.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint10, "STALL"); 
    state->u.f4.fld.otg_hs_hcint10.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint10, "NAK"); 
    state->u.f4.fld.otg_hs_hcint10.ack = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint10, "ACK"); 
    state->u.f4.fld.otg_hs_hcint10.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint10, "NYET"); 
    state->u.f4.fld.otg_hs_hcint10.txerr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint10, "TXERR"); 
    state->u.f4.fld.otg_hs_hcint10.bberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint10, "BBERR"); 
    state->u.f4.fld.otg_hs_hcint10.frmor = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint10, "FRMOR"); 
    state->u.f4.fld.otg_hs_hcint10.dterr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint10, "DTERR");  
    
    // OTG_HS_HCINT11 bitfields.
    state->u.f4.fld.otg_hs_hcint11.xfrc = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint11, "XFRC"); 
    state->u.f4.fld.otg_hs_hcint11.chh = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint11, "CHH"); 
    state->u.f4.fld.otg_hs_hcint11.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint11, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcint11.stall = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint11, "STALL"); 
    state->u.f4.fld.otg_hs_hcint11.nak = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint11, "NAK"); 
    state->u.f4.fld.otg_hs_hcint11.ack = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint11, "ACK"); 
    state->u.f4.fld.otg_hs_hcint11.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint11, "NYET"); 
    state->u.f4.fld.otg_hs_hcint11.txerr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint11, "TXERR"); 
    state->u.f4.fld.otg_hs_hcint11.bberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint11, "BBERR"); 
    state->u.f4.fld.otg_hs_hcint11.frmor = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint11, "FRMOR"); 
    state->u.f4.fld.otg_hs_hcint11.dterr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcint11, "DTERR");  
    
    // OTG_HS_HCINTMSK0 bitfields.
    state->u.f4.fld.otg_hs_hcintmsk0.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk0, "XFRCM"); 
    state->u.f4.fld.otg_hs_hcintmsk0.chhm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk0, "CHHM"); 
    state->u.f4.fld.otg_hs_hcintmsk0.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk0, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcintmsk0.stallm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk0, "STALLM"); 
    state->u.f4.fld.otg_hs_hcintmsk0.nakm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk0, "NAKM"); 
    state->u.f4.fld.otg_hs_hcintmsk0.ackm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk0, "ACKM"); 
    state->u.f4.fld.otg_hs_hcintmsk0.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk0, "NYET"); 
    state->u.f4.fld.otg_hs_hcintmsk0.txerrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk0, "TXERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk0.bberrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk0, "BBERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk0.frmorm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk0, "FRMORM"); 
    state->u.f4.fld.otg_hs_hcintmsk0.dterrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk0, "DTERRM");  
    
    // OTG_HS_HCINTMSK1 bitfields.
    state->u.f4.fld.otg_hs_hcintmsk1.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk1, "XFRCM"); 
    state->u.f4.fld.otg_hs_hcintmsk1.chhm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk1, "CHHM"); 
    state->u.f4.fld.otg_hs_hcintmsk1.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk1, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcintmsk1.stallm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk1, "STALLM"); 
    state->u.f4.fld.otg_hs_hcintmsk1.nakm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk1, "NAKM"); 
    state->u.f4.fld.otg_hs_hcintmsk1.ackm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk1, "ACKM"); 
    state->u.f4.fld.otg_hs_hcintmsk1.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk1, "NYET"); 
    state->u.f4.fld.otg_hs_hcintmsk1.txerrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk1, "TXERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk1.bberrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk1, "BBERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk1.frmorm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk1, "FRMORM"); 
    state->u.f4.fld.otg_hs_hcintmsk1.dterrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk1, "DTERRM");  
    
    // OTG_HS_HCINTMSK2 bitfields.
    state->u.f4.fld.otg_hs_hcintmsk2.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk2, "XFRCM"); 
    state->u.f4.fld.otg_hs_hcintmsk2.chhm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk2, "CHHM"); 
    state->u.f4.fld.otg_hs_hcintmsk2.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk2, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcintmsk2.stallm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk2, "STALLM"); 
    state->u.f4.fld.otg_hs_hcintmsk2.nakm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk2, "NAKM"); 
    state->u.f4.fld.otg_hs_hcintmsk2.ackm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk2, "ACKM"); 
    state->u.f4.fld.otg_hs_hcintmsk2.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk2, "NYET"); 
    state->u.f4.fld.otg_hs_hcintmsk2.txerrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk2, "TXERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk2.bberrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk2, "BBERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk2.frmorm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk2, "FRMORM"); 
    state->u.f4.fld.otg_hs_hcintmsk2.dterrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk2, "DTERRM");  
    
    // OTG_HS_HCINTMSK3 bitfields.
    state->u.f4.fld.otg_hs_hcintmsk3.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk3, "XFRCM"); 
    state->u.f4.fld.otg_hs_hcintmsk3.chhm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk3, "CHHM"); 
    state->u.f4.fld.otg_hs_hcintmsk3.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk3, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcintmsk3.stallm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk3, "STALLM"); 
    state->u.f4.fld.otg_hs_hcintmsk3.nakm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk3, "NAKM"); 
    state->u.f4.fld.otg_hs_hcintmsk3.ackm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk3, "ACKM"); 
    state->u.f4.fld.otg_hs_hcintmsk3.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk3, "NYET"); 
    state->u.f4.fld.otg_hs_hcintmsk3.txerrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk3, "TXERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk3.bberrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk3, "BBERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk3.frmorm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk3, "FRMORM"); 
    state->u.f4.fld.otg_hs_hcintmsk3.dterrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk3, "DTERRM");  
    
    // OTG_HS_HCINTMSK4 bitfields.
    state->u.f4.fld.otg_hs_hcintmsk4.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk4, "XFRCM"); 
    state->u.f4.fld.otg_hs_hcintmsk4.chhm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk4, "CHHM"); 
    state->u.f4.fld.otg_hs_hcintmsk4.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk4, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcintmsk4.stallm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk4, "STALLM"); 
    state->u.f4.fld.otg_hs_hcintmsk4.nakm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk4, "NAKM"); 
    state->u.f4.fld.otg_hs_hcintmsk4.ackm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk4, "ACKM"); 
    state->u.f4.fld.otg_hs_hcintmsk4.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk4, "NYET"); 
    state->u.f4.fld.otg_hs_hcintmsk4.txerrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk4, "TXERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk4.bberrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk4, "BBERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk4.frmorm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk4, "FRMORM"); 
    state->u.f4.fld.otg_hs_hcintmsk4.dterrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk4, "DTERRM");  
    
    // OTG_HS_HCINTMSK5 bitfields.
    state->u.f4.fld.otg_hs_hcintmsk5.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk5, "XFRCM"); 
    state->u.f4.fld.otg_hs_hcintmsk5.chhm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk5, "CHHM"); 
    state->u.f4.fld.otg_hs_hcintmsk5.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk5, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcintmsk5.stallm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk5, "STALLM"); 
    state->u.f4.fld.otg_hs_hcintmsk5.nakm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk5, "NAKM"); 
    state->u.f4.fld.otg_hs_hcintmsk5.ackm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk5, "ACKM"); 
    state->u.f4.fld.otg_hs_hcintmsk5.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk5, "NYET"); 
    state->u.f4.fld.otg_hs_hcintmsk5.txerrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk5, "TXERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk5.bberrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk5, "BBERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk5.frmorm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk5, "FRMORM"); 
    state->u.f4.fld.otg_hs_hcintmsk5.dterrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk5, "DTERRM");  
    
    // OTG_HS_HCINTMSK6 bitfields.
    state->u.f4.fld.otg_hs_hcintmsk6.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk6, "XFRCM"); 
    state->u.f4.fld.otg_hs_hcintmsk6.chhm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk6, "CHHM"); 
    state->u.f4.fld.otg_hs_hcintmsk6.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk6, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcintmsk6.stallm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk6, "STALLM"); 
    state->u.f4.fld.otg_hs_hcintmsk6.nakm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk6, "NAKM"); 
    state->u.f4.fld.otg_hs_hcintmsk6.ackm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk6, "ACKM"); 
    state->u.f4.fld.otg_hs_hcintmsk6.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk6, "NYET"); 
    state->u.f4.fld.otg_hs_hcintmsk6.txerrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk6, "TXERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk6.bberrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk6, "BBERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk6.frmorm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk6, "FRMORM"); 
    state->u.f4.fld.otg_hs_hcintmsk6.dterrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk6, "DTERRM");  
    
    // OTG_HS_HCINTMSK7 bitfields.
    state->u.f4.fld.otg_hs_hcintmsk7.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk7, "XFRCM"); 
    state->u.f4.fld.otg_hs_hcintmsk7.chhm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk7, "CHHM"); 
    state->u.f4.fld.otg_hs_hcintmsk7.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk7, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcintmsk7.stallm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk7, "STALLM"); 
    state->u.f4.fld.otg_hs_hcintmsk7.nakm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk7, "NAKM"); 
    state->u.f4.fld.otg_hs_hcintmsk7.ackm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk7, "ACKM"); 
    state->u.f4.fld.otg_hs_hcintmsk7.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk7, "NYET"); 
    state->u.f4.fld.otg_hs_hcintmsk7.txerrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk7, "TXERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk7.bberrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk7, "BBERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk7.frmorm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk7, "FRMORM"); 
    state->u.f4.fld.otg_hs_hcintmsk7.dterrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk7, "DTERRM");  
    
    // OTG_HS_HCINTMSK8 bitfields.
    state->u.f4.fld.otg_hs_hcintmsk8.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk8, "XFRCM"); 
    state->u.f4.fld.otg_hs_hcintmsk8.chhm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk8, "CHHM"); 
    state->u.f4.fld.otg_hs_hcintmsk8.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk8, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcintmsk8.stallm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk8, "STALLM"); 
    state->u.f4.fld.otg_hs_hcintmsk8.nakm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk8, "NAKM"); 
    state->u.f4.fld.otg_hs_hcintmsk8.ackm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk8, "ACKM"); 
    state->u.f4.fld.otg_hs_hcintmsk8.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk8, "NYET"); 
    state->u.f4.fld.otg_hs_hcintmsk8.txerrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk8, "TXERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk8.bberrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk8, "BBERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk8.frmorm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk8, "FRMORM"); 
    state->u.f4.fld.otg_hs_hcintmsk8.dterrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk8, "DTERRM");  
    
    // OTG_HS_HCINTMSK9 bitfields.
    state->u.f4.fld.otg_hs_hcintmsk9.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk9, "XFRCM"); 
    state->u.f4.fld.otg_hs_hcintmsk9.chhm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk9, "CHHM"); 
    state->u.f4.fld.otg_hs_hcintmsk9.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk9, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcintmsk9.stallm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk9, "STALLM"); 
    state->u.f4.fld.otg_hs_hcintmsk9.nakm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk9, "NAKM"); 
    state->u.f4.fld.otg_hs_hcintmsk9.ackm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk9, "ACKM"); 
    state->u.f4.fld.otg_hs_hcintmsk9.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk9, "NYET"); 
    state->u.f4.fld.otg_hs_hcintmsk9.txerrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk9, "TXERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk9.bberrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk9, "BBERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk9.frmorm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk9, "FRMORM"); 
    state->u.f4.fld.otg_hs_hcintmsk9.dterrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk9, "DTERRM");  
    
    // OTG_HS_HCINTMSK10 bitfields.
    state->u.f4.fld.otg_hs_hcintmsk10.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk10, "XFRCM"); 
    state->u.f4.fld.otg_hs_hcintmsk10.chhm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk10, "CHHM"); 
    state->u.f4.fld.otg_hs_hcintmsk10.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk10, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcintmsk10.stallm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk10, "STALLM"); 
    state->u.f4.fld.otg_hs_hcintmsk10.nakm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk10, "NAKM"); 
    state->u.f4.fld.otg_hs_hcintmsk10.ackm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk10, "ACKM"); 
    state->u.f4.fld.otg_hs_hcintmsk10.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk10, "NYET"); 
    state->u.f4.fld.otg_hs_hcintmsk10.txerrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk10, "TXERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk10.bberrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk10, "BBERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk10.frmorm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk10, "FRMORM"); 
    state->u.f4.fld.otg_hs_hcintmsk10.dterrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk10, "DTERRM");  
    
    // OTG_HS_HCINTMSK11 bitfields.
    state->u.f4.fld.otg_hs_hcintmsk11.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk11, "XFRCM"); 
    state->u.f4.fld.otg_hs_hcintmsk11.chhm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk11, "CHHM"); 
    state->u.f4.fld.otg_hs_hcintmsk11.ahberr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk11, "AHBERR"); 
    state->u.f4.fld.otg_hs_hcintmsk11.stallm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk11, "STALLM"); 
    state->u.f4.fld.otg_hs_hcintmsk11.nakm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk11, "NAKM"); 
    state->u.f4.fld.otg_hs_hcintmsk11.ackm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk11, "ACKM"); 
    state->u.f4.fld.otg_hs_hcintmsk11.nyet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk11, "NYET"); 
    state->u.f4.fld.otg_hs_hcintmsk11.txerrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk11, "TXERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk11.bberrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk11, "BBERRM"); 
    state->u.f4.fld.otg_hs_hcintmsk11.frmorm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk11, "FRMORM"); 
    state->u.f4.fld.otg_hs_hcintmsk11.dterrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcintmsk11, "DTERRM");  
    
    // OTG_HS_HCTSIZ0 bitfields.
    state->u.f4.fld.otg_hs_hctsiz0.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz0, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_hctsiz0.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz0, "PKTCNT"); 
    state->u.f4.fld.otg_hs_hctsiz0.dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz0, "DPID");  
    
    // OTG_HS_HCTSIZ1 bitfields.
    state->u.f4.fld.otg_hs_hctsiz1.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz1, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_hctsiz1.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz1, "PKTCNT"); 
    state->u.f4.fld.otg_hs_hctsiz1.dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz1, "DPID");  
    
    // OTG_HS_HCTSIZ2 bitfields.
    state->u.f4.fld.otg_hs_hctsiz2.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz2, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_hctsiz2.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz2, "PKTCNT"); 
    state->u.f4.fld.otg_hs_hctsiz2.dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz2, "DPID");  
    
    // OTG_HS_HCTSIZ3 bitfields.
    state->u.f4.fld.otg_hs_hctsiz3.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz3, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_hctsiz3.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz3, "PKTCNT"); 
    state->u.f4.fld.otg_hs_hctsiz3.dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz3, "DPID");  
    
    // OTG_HS_HCTSIZ4 bitfields.
    state->u.f4.fld.otg_hs_hctsiz4.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz4, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_hctsiz4.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz4, "PKTCNT"); 
    state->u.f4.fld.otg_hs_hctsiz4.dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz4, "DPID");  
    
    // OTG_HS_HCTSIZ5 bitfields.
    state->u.f4.fld.otg_hs_hctsiz5.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz5, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_hctsiz5.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz5, "PKTCNT"); 
    state->u.f4.fld.otg_hs_hctsiz5.dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz5, "DPID");  
    
    // OTG_HS_HCTSIZ6 bitfields.
    state->u.f4.fld.otg_hs_hctsiz6.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz6, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_hctsiz6.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz6, "PKTCNT"); 
    state->u.f4.fld.otg_hs_hctsiz6.dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz6, "DPID");  
    
    // OTG_HS_HCTSIZ7 bitfields.
    state->u.f4.fld.otg_hs_hctsiz7.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz7, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_hctsiz7.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz7, "PKTCNT"); 
    state->u.f4.fld.otg_hs_hctsiz7.dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz7, "DPID");  
    
    // OTG_HS_HCTSIZ8 bitfields.
    state->u.f4.fld.otg_hs_hctsiz8.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz8, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_hctsiz8.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz8, "PKTCNT"); 
    state->u.f4.fld.otg_hs_hctsiz8.dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz8, "DPID");  
    
    // OTG_HS_HCTSIZ9 bitfields.
    state->u.f4.fld.otg_hs_hctsiz9.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz9, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_hctsiz9.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz9, "PKTCNT"); 
    state->u.f4.fld.otg_hs_hctsiz9.dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz9, "DPID");  
    
    // OTG_HS_HCTSIZ10 bitfields.
    state->u.f4.fld.otg_hs_hctsiz10.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz10, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_hctsiz10.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz10, "PKTCNT"); 
    state->u.f4.fld.otg_hs_hctsiz10.dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz10, "DPID");  
    
    // OTG_HS_HCTSIZ11 bitfields.
    state->u.f4.fld.otg_hs_hctsiz11.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz11, "XFRSIZ"); 
    state->u.f4.fld.otg_hs_hctsiz11.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz11, "PKTCNT"); 
    state->u.f4.fld.otg_hs_hctsiz11.dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hctsiz11, "DPID");  
    
    // OTG_HS_HCDMA0 bitfields.
    state->u.f4.fld.otg_hs_hcdma0.dmaaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcdma0, "DMAADDR");  
    
    // OTG_HS_HCDMA1 bitfields.
    state->u.f4.fld.otg_hs_hcdma1.dmaaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcdma1, "DMAADDR");  
    
    // OTG_HS_HCDMA2 bitfields.
    state->u.f4.fld.otg_hs_hcdma2.dmaaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcdma2, "DMAADDR");  
    
    // OTG_HS_HCDMA3 bitfields.
    state->u.f4.fld.otg_hs_hcdma3.dmaaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcdma3, "DMAADDR");  
    
    // OTG_HS_HCDMA4 bitfields.
    state->u.f4.fld.otg_hs_hcdma4.dmaaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcdma4, "DMAADDR");  
    
    // OTG_HS_HCDMA5 bitfields.
    state->u.f4.fld.otg_hs_hcdma5.dmaaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcdma5, "DMAADDR");  
    
    // OTG_HS_HCDMA6 bitfields.
    state->u.f4.fld.otg_hs_hcdma6.dmaaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcdma6, "DMAADDR");  
    
    // OTG_HS_HCDMA7 bitfields.
    state->u.f4.fld.otg_hs_hcdma7.dmaaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcdma7, "DMAADDR");  
    
    // OTG_HS_HCDMA8 bitfields.
    state->u.f4.fld.otg_hs_hcdma8.dmaaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcdma8, "DMAADDR");  
    
    // OTG_HS_HCDMA9 bitfields.
    state->u.f4.fld.otg_hs_hcdma9.dmaaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcdma9, "DMAADDR");  
    
    // OTG_HS_HCDMA10 bitfields.
    state->u.f4.fld.otg_hs_hcdma10.dmaaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcdma10, "DMAADDR");  
    
    // OTG_HS_HCDMA11 bitfields.
    state->u.f4.fld.otg_hs_hcdma11.dmaaddr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hcdma11, "DMAADDR");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_otg_hs_host_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32OTG_HS_HOSTState *state = STM32_OTG_HS_HOST_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_otg_hs_host_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32OTG_HS_HOSTState *state = STM32_OTG_HS_HOST_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_otg_hs_host_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32OTG_HS_HOSTState *state = STM32_OTG_HS_HOST_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_otg_hs_host_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32OTG_HS_HOSTState *state = STM32_OTG_HS_HOST_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_otg_hs_host_is_enabled(Object *obj)
{
    STM32OTG_HS_HOSTState *state = STM32_OTG_HS_HOST_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_otg_hs_host_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32OTG_HS_HOSTState *state = STM32_OTG_HS_HOST_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_otg_hs_host_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_OTG_HS_HOST)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32OTG_HS_HOSTState *state = STM32_OTG_HS_HOST_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "OTG_HS_HOST";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_429x ) {

            stm32f429x_otg_hs_host_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_otg_hs_host_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_otg_hs_host_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_otg_hs_host_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_otg_hs_host_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/OTG_HS_HOSTEN");


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

static void stm32_otg_hs_host_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_OTG_HS_HOST);
}

static void stm32_otg_hs_host_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_otg_hs_host_reset_callback;
    dc->realize = stm32_otg_hs_host_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_otg_hs_host_is_enabled;
}

static const TypeInfo stm32_otg_hs_host_type_info = {
    .name = TYPE_STM32_OTG_HS_HOST,
    .parent = TYPE_STM32_OTG_HS_HOST_PARENT,
    .instance_init = stm32_otg_hs_host_instance_init_callback,
    .instance_size = sizeof(STM32OTG_HS_HOSTState),
    .class_init = stm32_otg_hs_host_class_init_callback,
    .class_size = sizeof(STM32OTG_HS_HOSTClass) };

static void stm32_otg_hs_host_register_types(void)
{
    type_register_static(&stm32_otg_hs_host_type_info);
}

type_init(stm32_otg_hs_host_register_types);

// ----------------------------------------------------------------------------
