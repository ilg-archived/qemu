/*
 * STM32 - OTG_FS_HOST (USB on the go full speed) emulation.
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

#include <hw/cortexm/stm32/otg_fs_host.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f40x_otg_fs_host_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32OTG_FS_HOSTState *state = STM32_OTG_FS_HOST_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.fs_hcfg = cm_object_get_child_by_name(obj, "FS_HCFG");
    state->u.f4.reg.hfir = cm_object_get_child_by_name(obj, "HFIR");
    state->u.f4.reg.fs_hfnum = cm_object_get_child_by_name(obj, "FS_HFNUM");
    state->u.f4.reg.fs_hptxsts = cm_object_get_child_by_name(obj, "FS_HPTXSTS");
    state->u.f4.reg.haint = cm_object_get_child_by_name(obj, "HAINT");
    state->u.f4.reg.haintmsk = cm_object_get_child_by_name(obj, "HAINTMSK");
    state->u.f4.reg.fs_hprt = cm_object_get_child_by_name(obj, "FS_HPRT");
    state->u.f4.reg.fs_hcchar0 = cm_object_get_child_by_name(obj, "FS_HCCHAR0");
    state->u.f4.reg.fs_hcchar1 = cm_object_get_child_by_name(obj, "FS_HCCHAR1");
    state->u.f4.reg.fs_hcchar2 = cm_object_get_child_by_name(obj, "FS_HCCHAR2");
    state->u.f4.reg.fs_hcchar3 = cm_object_get_child_by_name(obj, "FS_HCCHAR3");
    state->u.f4.reg.fs_hcchar4 = cm_object_get_child_by_name(obj, "FS_HCCHAR4");
    state->u.f4.reg.fs_hcchar5 = cm_object_get_child_by_name(obj, "FS_HCCHAR5");
    state->u.f4.reg.fs_hcchar6 = cm_object_get_child_by_name(obj, "FS_HCCHAR6");
    state->u.f4.reg.fs_hcchar7 = cm_object_get_child_by_name(obj, "FS_HCCHAR7");
    state->u.f4.reg.fs_hcint0 = cm_object_get_child_by_name(obj, "FS_HCINT0");
    state->u.f4.reg.fs_hcint1 = cm_object_get_child_by_name(obj, "FS_HCINT1");
    state->u.f4.reg.fs_hcint2 = cm_object_get_child_by_name(obj, "FS_HCINT2");
    state->u.f4.reg.fs_hcint3 = cm_object_get_child_by_name(obj, "FS_HCINT3");
    state->u.f4.reg.fs_hcint4 = cm_object_get_child_by_name(obj, "FS_HCINT4");
    state->u.f4.reg.fs_hcint5 = cm_object_get_child_by_name(obj, "FS_HCINT5");
    state->u.f4.reg.fs_hcint6 = cm_object_get_child_by_name(obj, "FS_HCINT6");
    state->u.f4.reg.fs_hcint7 = cm_object_get_child_by_name(obj, "FS_HCINT7");
    state->u.f4.reg.fs_hcintmsk0 = cm_object_get_child_by_name(obj, "FS_HCINTMSK0");
    state->u.f4.reg.fs_hcintmsk1 = cm_object_get_child_by_name(obj, "FS_HCINTMSK1");
    state->u.f4.reg.fs_hcintmsk2 = cm_object_get_child_by_name(obj, "FS_HCINTMSK2");
    state->u.f4.reg.fs_hcintmsk3 = cm_object_get_child_by_name(obj, "FS_HCINTMSK3");
    state->u.f4.reg.fs_hcintmsk4 = cm_object_get_child_by_name(obj, "FS_HCINTMSK4");
    state->u.f4.reg.fs_hcintmsk5 = cm_object_get_child_by_name(obj, "FS_HCINTMSK5");
    state->u.f4.reg.fs_hcintmsk6 = cm_object_get_child_by_name(obj, "FS_HCINTMSK6");
    state->u.f4.reg.fs_hcintmsk7 = cm_object_get_child_by_name(obj, "FS_HCINTMSK7");
    state->u.f4.reg.fs_hctsiz0 = cm_object_get_child_by_name(obj, "FS_HCTSIZ0");
    state->u.f4.reg.fs_hctsiz1 = cm_object_get_child_by_name(obj, "FS_HCTSIZ1");
    state->u.f4.reg.fs_hctsiz2 = cm_object_get_child_by_name(obj, "FS_HCTSIZ2");
    state->u.f4.reg.fs_hctsiz3 = cm_object_get_child_by_name(obj, "FS_HCTSIZ3");
    state->u.f4.reg.fs_hctsiz4 = cm_object_get_child_by_name(obj, "FS_HCTSIZ4");
    state->u.f4.reg.fs_hctsiz5 = cm_object_get_child_by_name(obj, "FS_HCTSIZ5");
    state->u.f4.reg.fs_hctsiz6 = cm_object_get_child_by_name(obj, "FS_HCTSIZ6");
    state->u.f4.reg.fs_hctsiz7 = cm_object_get_child_by_name(obj, "FS_HCTSIZ7");
    
    
    // FS_HCFG bitfields.
    state->u.f4.fld.fs_hcfg.fslspcs = cm_object_get_child_by_name(state->u.f4.reg.fs_hcfg, "FSLSPCS"); 
    state->u.f4.fld.fs_hcfg.fslss = cm_object_get_child_by_name(state->u.f4.reg.fs_hcfg, "FSLSS");  
    
    // HFIR bitfields.
    state->u.f4.fld.hfir.frivl = cm_object_get_child_by_name(state->u.f4.reg.hfir, "FRIVL");  
    
    // FS_HFNUM bitfields.
    state->u.f4.fld.fs_hfnum.frnum = cm_object_get_child_by_name(state->u.f4.reg.fs_hfnum, "FRNUM"); 
    state->u.f4.fld.fs_hfnum.ftrem = cm_object_get_child_by_name(state->u.f4.reg.fs_hfnum, "FTREM");  
    
    // FS_HPTXSTS bitfields.
    state->u.f4.fld.fs_hptxsts.ptxfsavl = cm_object_get_child_by_name(state->u.f4.reg.fs_hptxsts, "PTXFSAVL"); 
    state->u.f4.fld.fs_hptxsts.ptxqsav = cm_object_get_child_by_name(state->u.f4.reg.fs_hptxsts, "PTXQSAV"); 
    state->u.f4.fld.fs_hptxsts.ptxqtop = cm_object_get_child_by_name(state->u.f4.reg.fs_hptxsts, "PTXQTOP");  
    
    // HAINT bitfields.
    state->u.f4.fld.haint.haint = cm_object_get_child_by_name(state->u.f4.reg.haint, "HAINT");  
    
    // HAINTMSK bitfields.
    state->u.f4.fld.haintmsk.haintm = cm_object_get_child_by_name(state->u.f4.reg.haintmsk, "HAINTM");  
    
    // FS_HPRT bitfields.
    state->u.f4.fld.fs_hprt.pcsts = cm_object_get_child_by_name(state->u.f4.reg.fs_hprt, "PCSTS"); 
    state->u.f4.fld.fs_hprt.pcdet = cm_object_get_child_by_name(state->u.f4.reg.fs_hprt, "PCDET"); 
    state->u.f4.fld.fs_hprt.pena = cm_object_get_child_by_name(state->u.f4.reg.fs_hprt, "PENA"); 
    state->u.f4.fld.fs_hprt.penchng = cm_object_get_child_by_name(state->u.f4.reg.fs_hprt, "PENCHNG"); 
    state->u.f4.fld.fs_hprt.poca = cm_object_get_child_by_name(state->u.f4.reg.fs_hprt, "POCA"); 
    state->u.f4.fld.fs_hprt.pocchng = cm_object_get_child_by_name(state->u.f4.reg.fs_hprt, "POCCHNG"); 
    state->u.f4.fld.fs_hprt.pres = cm_object_get_child_by_name(state->u.f4.reg.fs_hprt, "PRES"); 
    state->u.f4.fld.fs_hprt.psusp = cm_object_get_child_by_name(state->u.f4.reg.fs_hprt, "PSUSP"); 
    state->u.f4.fld.fs_hprt.prst = cm_object_get_child_by_name(state->u.f4.reg.fs_hprt, "PRST"); 
    state->u.f4.fld.fs_hprt.plsts = cm_object_get_child_by_name(state->u.f4.reg.fs_hprt, "PLSTS"); 
    state->u.f4.fld.fs_hprt.ppwr = cm_object_get_child_by_name(state->u.f4.reg.fs_hprt, "PPWR"); 
    state->u.f4.fld.fs_hprt.ptctl = cm_object_get_child_by_name(state->u.f4.reg.fs_hprt, "PTCTL"); 
    state->u.f4.fld.fs_hprt.pspd = cm_object_get_child_by_name(state->u.f4.reg.fs_hprt, "PSPD");  
    
    // FS_HCCHAR0 bitfields.
    state->u.f4.fld.fs_hcchar0.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar0, "MPSIZ"); 
    state->u.f4.fld.fs_hcchar0.epnum = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar0, "EPNUM"); 
    state->u.f4.fld.fs_hcchar0.epdir = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar0, "EPDIR"); 
    state->u.f4.fld.fs_hcchar0.lsdev = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar0, "LSDEV"); 
    state->u.f4.fld.fs_hcchar0.eptyp = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar0, "EPTYP"); 
    state->u.f4.fld.fs_hcchar0.mcnt = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar0, "MCNT"); 
    state->u.f4.fld.fs_hcchar0.dad = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar0, "DAD"); 
    state->u.f4.fld.fs_hcchar0.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar0, "ODDFRM"); 
    state->u.f4.fld.fs_hcchar0.chdis = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar0, "CHDIS"); 
    state->u.f4.fld.fs_hcchar0.chena = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar0, "CHENA");  
    
    // FS_HCCHAR1 bitfields.
    state->u.f4.fld.fs_hcchar1.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar1, "MPSIZ"); 
    state->u.f4.fld.fs_hcchar1.epnum = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar1, "EPNUM"); 
    state->u.f4.fld.fs_hcchar1.epdir = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar1, "EPDIR"); 
    state->u.f4.fld.fs_hcchar1.lsdev = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar1, "LSDEV"); 
    state->u.f4.fld.fs_hcchar1.eptyp = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar1, "EPTYP"); 
    state->u.f4.fld.fs_hcchar1.mcnt = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar1, "MCNT"); 
    state->u.f4.fld.fs_hcchar1.dad = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar1, "DAD"); 
    state->u.f4.fld.fs_hcchar1.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar1, "ODDFRM"); 
    state->u.f4.fld.fs_hcchar1.chdis = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar1, "CHDIS"); 
    state->u.f4.fld.fs_hcchar1.chena = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar1, "CHENA");  
    
    // FS_HCCHAR2 bitfields.
    state->u.f4.fld.fs_hcchar2.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar2, "MPSIZ"); 
    state->u.f4.fld.fs_hcchar2.epnum = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar2, "EPNUM"); 
    state->u.f4.fld.fs_hcchar2.epdir = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar2, "EPDIR"); 
    state->u.f4.fld.fs_hcchar2.lsdev = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar2, "LSDEV"); 
    state->u.f4.fld.fs_hcchar2.eptyp = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar2, "EPTYP"); 
    state->u.f4.fld.fs_hcchar2.mcnt = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar2, "MCNT"); 
    state->u.f4.fld.fs_hcchar2.dad = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar2, "DAD"); 
    state->u.f4.fld.fs_hcchar2.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar2, "ODDFRM"); 
    state->u.f4.fld.fs_hcchar2.chdis = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar2, "CHDIS"); 
    state->u.f4.fld.fs_hcchar2.chena = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar2, "CHENA");  
    
    // FS_HCCHAR3 bitfields.
    state->u.f4.fld.fs_hcchar3.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar3, "MPSIZ"); 
    state->u.f4.fld.fs_hcchar3.epnum = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar3, "EPNUM"); 
    state->u.f4.fld.fs_hcchar3.epdir = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar3, "EPDIR"); 
    state->u.f4.fld.fs_hcchar3.lsdev = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar3, "LSDEV"); 
    state->u.f4.fld.fs_hcchar3.eptyp = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar3, "EPTYP"); 
    state->u.f4.fld.fs_hcchar3.mcnt = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar3, "MCNT"); 
    state->u.f4.fld.fs_hcchar3.dad = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar3, "DAD"); 
    state->u.f4.fld.fs_hcchar3.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar3, "ODDFRM"); 
    state->u.f4.fld.fs_hcchar3.chdis = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar3, "CHDIS"); 
    state->u.f4.fld.fs_hcchar3.chena = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar3, "CHENA");  
    
    // FS_HCCHAR4 bitfields.
    state->u.f4.fld.fs_hcchar4.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar4, "MPSIZ"); 
    state->u.f4.fld.fs_hcchar4.epnum = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar4, "EPNUM"); 
    state->u.f4.fld.fs_hcchar4.epdir = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar4, "EPDIR"); 
    state->u.f4.fld.fs_hcchar4.lsdev = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar4, "LSDEV"); 
    state->u.f4.fld.fs_hcchar4.eptyp = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar4, "EPTYP"); 
    state->u.f4.fld.fs_hcchar4.mcnt = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar4, "MCNT"); 
    state->u.f4.fld.fs_hcchar4.dad = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar4, "DAD"); 
    state->u.f4.fld.fs_hcchar4.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar4, "ODDFRM"); 
    state->u.f4.fld.fs_hcchar4.chdis = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar4, "CHDIS"); 
    state->u.f4.fld.fs_hcchar4.chena = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar4, "CHENA");  
    
    // FS_HCCHAR5 bitfields.
    state->u.f4.fld.fs_hcchar5.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar5, "MPSIZ"); 
    state->u.f4.fld.fs_hcchar5.epnum = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar5, "EPNUM"); 
    state->u.f4.fld.fs_hcchar5.epdir = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar5, "EPDIR"); 
    state->u.f4.fld.fs_hcchar5.lsdev = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar5, "LSDEV"); 
    state->u.f4.fld.fs_hcchar5.eptyp = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar5, "EPTYP"); 
    state->u.f4.fld.fs_hcchar5.mcnt = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar5, "MCNT"); 
    state->u.f4.fld.fs_hcchar5.dad = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar5, "DAD"); 
    state->u.f4.fld.fs_hcchar5.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar5, "ODDFRM"); 
    state->u.f4.fld.fs_hcchar5.chdis = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar5, "CHDIS"); 
    state->u.f4.fld.fs_hcchar5.chena = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar5, "CHENA");  
    
    // FS_HCCHAR6 bitfields.
    state->u.f4.fld.fs_hcchar6.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar6, "MPSIZ"); 
    state->u.f4.fld.fs_hcchar6.epnum = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar6, "EPNUM"); 
    state->u.f4.fld.fs_hcchar6.epdir = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar6, "EPDIR"); 
    state->u.f4.fld.fs_hcchar6.lsdev = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar6, "LSDEV"); 
    state->u.f4.fld.fs_hcchar6.eptyp = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar6, "EPTYP"); 
    state->u.f4.fld.fs_hcchar6.mcnt = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar6, "MCNT"); 
    state->u.f4.fld.fs_hcchar6.dad = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar6, "DAD"); 
    state->u.f4.fld.fs_hcchar6.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar6, "ODDFRM"); 
    state->u.f4.fld.fs_hcchar6.chdis = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar6, "CHDIS"); 
    state->u.f4.fld.fs_hcchar6.chena = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar6, "CHENA");  
    
    // FS_HCCHAR7 bitfields.
    state->u.f4.fld.fs_hcchar7.mpsiz = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar7, "MPSIZ"); 
    state->u.f4.fld.fs_hcchar7.epnum = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar7, "EPNUM"); 
    state->u.f4.fld.fs_hcchar7.epdir = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar7, "EPDIR"); 
    state->u.f4.fld.fs_hcchar7.lsdev = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar7, "LSDEV"); 
    state->u.f4.fld.fs_hcchar7.eptyp = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar7, "EPTYP"); 
    state->u.f4.fld.fs_hcchar7.mcnt = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar7, "MCNT"); 
    state->u.f4.fld.fs_hcchar7.dad = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar7, "DAD"); 
    state->u.f4.fld.fs_hcchar7.oddfrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar7, "ODDFRM"); 
    state->u.f4.fld.fs_hcchar7.chdis = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar7, "CHDIS"); 
    state->u.f4.fld.fs_hcchar7.chena = cm_object_get_child_by_name(state->u.f4.reg.fs_hcchar7, "CHENA");  
    
    // FS_HCINT0 bitfields.
    state->u.f4.fld.fs_hcint0.xfrc = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint0, "XFRC"); 
    state->u.f4.fld.fs_hcint0.chh = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint0, "CHH"); 
    state->u.f4.fld.fs_hcint0.stall = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint0, "STALL"); 
    state->u.f4.fld.fs_hcint0.nak = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint0, "NAK"); 
    state->u.f4.fld.fs_hcint0.ack = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint0, "ACK"); 
    state->u.f4.fld.fs_hcint0.txerr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint0, "TXERR"); 
    state->u.f4.fld.fs_hcint0.bberr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint0, "BBERR"); 
    state->u.f4.fld.fs_hcint0.frmor = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint0, "FRMOR"); 
    state->u.f4.fld.fs_hcint0.dterr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint0, "DTERR");  
    
    // FS_HCINT1 bitfields.
    state->u.f4.fld.fs_hcint1.xfrc = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint1, "XFRC"); 
    state->u.f4.fld.fs_hcint1.chh = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint1, "CHH"); 
    state->u.f4.fld.fs_hcint1.stall = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint1, "STALL"); 
    state->u.f4.fld.fs_hcint1.nak = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint1, "NAK"); 
    state->u.f4.fld.fs_hcint1.ack = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint1, "ACK"); 
    state->u.f4.fld.fs_hcint1.txerr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint1, "TXERR"); 
    state->u.f4.fld.fs_hcint1.bberr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint1, "BBERR"); 
    state->u.f4.fld.fs_hcint1.frmor = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint1, "FRMOR"); 
    state->u.f4.fld.fs_hcint1.dterr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint1, "DTERR");  
    
    // FS_HCINT2 bitfields.
    state->u.f4.fld.fs_hcint2.xfrc = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint2, "XFRC"); 
    state->u.f4.fld.fs_hcint2.chh = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint2, "CHH"); 
    state->u.f4.fld.fs_hcint2.stall = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint2, "STALL"); 
    state->u.f4.fld.fs_hcint2.nak = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint2, "NAK"); 
    state->u.f4.fld.fs_hcint2.ack = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint2, "ACK"); 
    state->u.f4.fld.fs_hcint2.txerr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint2, "TXERR"); 
    state->u.f4.fld.fs_hcint2.bberr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint2, "BBERR"); 
    state->u.f4.fld.fs_hcint2.frmor = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint2, "FRMOR"); 
    state->u.f4.fld.fs_hcint2.dterr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint2, "DTERR");  
    
    // FS_HCINT3 bitfields.
    state->u.f4.fld.fs_hcint3.xfrc = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint3, "XFRC"); 
    state->u.f4.fld.fs_hcint3.chh = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint3, "CHH"); 
    state->u.f4.fld.fs_hcint3.stall = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint3, "STALL"); 
    state->u.f4.fld.fs_hcint3.nak = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint3, "NAK"); 
    state->u.f4.fld.fs_hcint3.ack = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint3, "ACK"); 
    state->u.f4.fld.fs_hcint3.txerr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint3, "TXERR"); 
    state->u.f4.fld.fs_hcint3.bberr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint3, "BBERR"); 
    state->u.f4.fld.fs_hcint3.frmor = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint3, "FRMOR"); 
    state->u.f4.fld.fs_hcint3.dterr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint3, "DTERR");  
    
    // FS_HCINT4 bitfields.
    state->u.f4.fld.fs_hcint4.xfrc = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint4, "XFRC"); 
    state->u.f4.fld.fs_hcint4.chh = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint4, "CHH"); 
    state->u.f4.fld.fs_hcint4.stall = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint4, "STALL"); 
    state->u.f4.fld.fs_hcint4.nak = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint4, "NAK"); 
    state->u.f4.fld.fs_hcint4.ack = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint4, "ACK"); 
    state->u.f4.fld.fs_hcint4.txerr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint4, "TXERR"); 
    state->u.f4.fld.fs_hcint4.bberr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint4, "BBERR"); 
    state->u.f4.fld.fs_hcint4.frmor = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint4, "FRMOR"); 
    state->u.f4.fld.fs_hcint4.dterr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint4, "DTERR");  
    
    // FS_HCINT5 bitfields.
    state->u.f4.fld.fs_hcint5.xfrc = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint5, "XFRC"); 
    state->u.f4.fld.fs_hcint5.chh = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint5, "CHH"); 
    state->u.f4.fld.fs_hcint5.stall = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint5, "STALL"); 
    state->u.f4.fld.fs_hcint5.nak = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint5, "NAK"); 
    state->u.f4.fld.fs_hcint5.ack = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint5, "ACK"); 
    state->u.f4.fld.fs_hcint5.txerr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint5, "TXERR"); 
    state->u.f4.fld.fs_hcint5.bberr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint5, "BBERR"); 
    state->u.f4.fld.fs_hcint5.frmor = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint5, "FRMOR"); 
    state->u.f4.fld.fs_hcint5.dterr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint5, "DTERR");  
    
    // FS_HCINT6 bitfields.
    state->u.f4.fld.fs_hcint6.xfrc = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint6, "XFRC"); 
    state->u.f4.fld.fs_hcint6.chh = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint6, "CHH"); 
    state->u.f4.fld.fs_hcint6.stall = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint6, "STALL"); 
    state->u.f4.fld.fs_hcint6.nak = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint6, "NAK"); 
    state->u.f4.fld.fs_hcint6.ack = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint6, "ACK"); 
    state->u.f4.fld.fs_hcint6.txerr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint6, "TXERR"); 
    state->u.f4.fld.fs_hcint6.bberr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint6, "BBERR"); 
    state->u.f4.fld.fs_hcint6.frmor = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint6, "FRMOR"); 
    state->u.f4.fld.fs_hcint6.dterr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint6, "DTERR");  
    
    // FS_HCINT7 bitfields.
    state->u.f4.fld.fs_hcint7.xfrc = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint7, "XFRC"); 
    state->u.f4.fld.fs_hcint7.chh = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint7, "CHH"); 
    state->u.f4.fld.fs_hcint7.stall = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint7, "STALL"); 
    state->u.f4.fld.fs_hcint7.nak = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint7, "NAK"); 
    state->u.f4.fld.fs_hcint7.ack = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint7, "ACK"); 
    state->u.f4.fld.fs_hcint7.txerr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint7, "TXERR"); 
    state->u.f4.fld.fs_hcint7.bberr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint7, "BBERR"); 
    state->u.f4.fld.fs_hcint7.frmor = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint7, "FRMOR"); 
    state->u.f4.fld.fs_hcint7.dterr = cm_object_get_child_by_name(state->u.f4.reg.fs_hcint7, "DTERR");  
    
    // FS_HCINTMSK0 bitfields.
    state->u.f4.fld.fs_hcintmsk0.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk0, "XFRCM"); 
    state->u.f4.fld.fs_hcintmsk0.chhm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk0, "CHHM"); 
    state->u.f4.fld.fs_hcintmsk0.stallm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk0, "STALLM"); 
    state->u.f4.fld.fs_hcintmsk0.nakm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk0, "NAKM"); 
    state->u.f4.fld.fs_hcintmsk0.ackm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk0, "ACKM"); 
    state->u.f4.fld.fs_hcintmsk0.nyet = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk0, "NYET"); 
    state->u.f4.fld.fs_hcintmsk0.txerrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk0, "TXERRM"); 
    state->u.f4.fld.fs_hcintmsk0.bberrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk0, "BBERRM"); 
    state->u.f4.fld.fs_hcintmsk0.frmorm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk0, "FRMORM"); 
    state->u.f4.fld.fs_hcintmsk0.dterrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk0, "DTERRM");  
    
    // FS_HCINTMSK1 bitfields.
    state->u.f4.fld.fs_hcintmsk1.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk1, "XFRCM"); 
    state->u.f4.fld.fs_hcintmsk1.chhm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk1, "CHHM"); 
    state->u.f4.fld.fs_hcintmsk1.stallm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk1, "STALLM"); 
    state->u.f4.fld.fs_hcintmsk1.nakm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk1, "NAKM"); 
    state->u.f4.fld.fs_hcintmsk1.ackm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk1, "ACKM"); 
    state->u.f4.fld.fs_hcintmsk1.nyet = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk1, "NYET"); 
    state->u.f4.fld.fs_hcintmsk1.txerrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk1, "TXERRM"); 
    state->u.f4.fld.fs_hcintmsk1.bberrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk1, "BBERRM"); 
    state->u.f4.fld.fs_hcintmsk1.frmorm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk1, "FRMORM"); 
    state->u.f4.fld.fs_hcintmsk1.dterrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk1, "DTERRM");  
    
    // FS_HCINTMSK2 bitfields.
    state->u.f4.fld.fs_hcintmsk2.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk2, "XFRCM"); 
    state->u.f4.fld.fs_hcintmsk2.chhm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk2, "CHHM"); 
    state->u.f4.fld.fs_hcintmsk2.stallm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk2, "STALLM"); 
    state->u.f4.fld.fs_hcintmsk2.nakm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk2, "NAKM"); 
    state->u.f4.fld.fs_hcintmsk2.ackm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk2, "ACKM"); 
    state->u.f4.fld.fs_hcintmsk2.nyet = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk2, "NYET"); 
    state->u.f4.fld.fs_hcintmsk2.txerrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk2, "TXERRM"); 
    state->u.f4.fld.fs_hcintmsk2.bberrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk2, "BBERRM"); 
    state->u.f4.fld.fs_hcintmsk2.frmorm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk2, "FRMORM"); 
    state->u.f4.fld.fs_hcintmsk2.dterrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk2, "DTERRM");  
    
    // FS_HCINTMSK3 bitfields.
    state->u.f4.fld.fs_hcintmsk3.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk3, "XFRCM"); 
    state->u.f4.fld.fs_hcintmsk3.chhm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk3, "CHHM"); 
    state->u.f4.fld.fs_hcintmsk3.stallm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk3, "STALLM"); 
    state->u.f4.fld.fs_hcintmsk3.nakm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk3, "NAKM"); 
    state->u.f4.fld.fs_hcintmsk3.ackm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk3, "ACKM"); 
    state->u.f4.fld.fs_hcintmsk3.nyet = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk3, "NYET"); 
    state->u.f4.fld.fs_hcintmsk3.txerrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk3, "TXERRM"); 
    state->u.f4.fld.fs_hcintmsk3.bberrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk3, "BBERRM"); 
    state->u.f4.fld.fs_hcintmsk3.frmorm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk3, "FRMORM"); 
    state->u.f4.fld.fs_hcintmsk3.dterrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk3, "DTERRM");  
    
    // FS_HCINTMSK4 bitfields.
    state->u.f4.fld.fs_hcintmsk4.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk4, "XFRCM"); 
    state->u.f4.fld.fs_hcintmsk4.chhm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk4, "CHHM"); 
    state->u.f4.fld.fs_hcintmsk4.stallm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk4, "STALLM"); 
    state->u.f4.fld.fs_hcintmsk4.nakm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk4, "NAKM"); 
    state->u.f4.fld.fs_hcintmsk4.ackm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk4, "ACKM"); 
    state->u.f4.fld.fs_hcintmsk4.nyet = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk4, "NYET"); 
    state->u.f4.fld.fs_hcintmsk4.txerrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk4, "TXERRM"); 
    state->u.f4.fld.fs_hcintmsk4.bberrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk4, "BBERRM"); 
    state->u.f4.fld.fs_hcintmsk4.frmorm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk4, "FRMORM"); 
    state->u.f4.fld.fs_hcintmsk4.dterrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk4, "DTERRM");  
    
    // FS_HCINTMSK5 bitfields.
    state->u.f4.fld.fs_hcintmsk5.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk5, "XFRCM"); 
    state->u.f4.fld.fs_hcintmsk5.chhm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk5, "CHHM"); 
    state->u.f4.fld.fs_hcintmsk5.stallm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk5, "STALLM"); 
    state->u.f4.fld.fs_hcintmsk5.nakm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk5, "NAKM"); 
    state->u.f4.fld.fs_hcintmsk5.ackm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk5, "ACKM"); 
    state->u.f4.fld.fs_hcintmsk5.nyet = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk5, "NYET"); 
    state->u.f4.fld.fs_hcintmsk5.txerrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk5, "TXERRM"); 
    state->u.f4.fld.fs_hcintmsk5.bberrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk5, "BBERRM"); 
    state->u.f4.fld.fs_hcintmsk5.frmorm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk5, "FRMORM"); 
    state->u.f4.fld.fs_hcintmsk5.dterrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk5, "DTERRM");  
    
    // FS_HCINTMSK6 bitfields.
    state->u.f4.fld.fs_hcintmsk6.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk6, "XFRCM"); 
    state->u.f4.fld.fs_hcintmsk6.chhm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk6, "CHHM"); 
    state->u.f4.fld.fs_hcintmsk6.stallm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk6, "STALLM"); 
    state->u.f4.fld.fs_hcintmsk6.nakm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk6, "NAKM"); 
    state->u.f4.fld.fs_hcintmsk6.ackm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk6, "ACKM"); 
    state->u.f4.fld.fs_hcintmsk6.nyet = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk6, "NYET"); 
    state->u.f4.fld.fs_hcintmsk6.txerrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk6, "TXERRM"); 
    state->u.f4.fld.fs_hcintmsk6.bberrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk6, "BBERRM"); 
    state->u.f4.fld.fs_hcintmsk6.frmorm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk6, "FRMORM"); 
    state->u.f4.fld.fs_hcintmsk6.dterrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk6, "DTERRM");  
    
    // FS_HCINTMSK7 bitfields.
    state->u.f4.fld.fs_hcintmsk7.xfrcm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk7, "XFRCM"); 
    state->u.f4.fld.fs_hcintmsk7.chhm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk7, "CHHM"); 
    state->u.f4.fld.fs_hcintmsk7.stallm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk7, "STALLM"); 
    state->u.f4.fld.fs_hcintmsk7.nakm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk7, "NAKM"); 
    state->u.f4.fld.fs_hcintmsk7.ackm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk7, "ACKM"); 
    state->u.f4.fld.fs_hcintmsk7.nyet = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk7, "NYET"); 
    state->u.f4.fld.fs_hcintmsk7.txerrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk7, "TXERRM"); 
    state->u.f4.fld.fs_hcintmsk7.bberrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk7, "BBERRM"); 
    state->u.f4.fld.fs_hcintmsk7.frmorm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk7, "FRMORM"); 
    state->u.f4.fld.fs_hcintmsk7.dterrm = cm_object_get_child_by_name(state->u.f4.reg.fs_hcintmsk7, "DTERRM");  
    
    // FS_HCTSIZ0 bitfields.
    state->u.f4.fld.fs_hctsiz0.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz0, "XFRSIZ"); 
    state->u.f4.fld.fs_hctsiz0.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz0, "PKTCNT"); 
    state->u.f4.fld.fs_hctsiz0.dpid = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz0, "DPID");  
    
    // FS_HCTSIZ1 bitfields.
    state->u.f4.fld.fs_hctsiz1.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz1, "XFRSIZ"); 
    state->u.f4.fld.fs_hctsiz1.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz1, "PKTCNT"); 
    state->u.f4.fld.fs_hctsiz1.dpid = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz1, "DPID");  
    
    // FS_HCTSIZ2 bitfields.
    state->u.f4.fld.fs_hctsiz2.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz2, "XFRSIZ"); 
    state->u.f4.fld.fs_hctsiz2.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz2, "PKTCNT"); 
    state->u.f4.fld.fs_hctsiz2.dpid = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz2, "DPID");  
    
    // FS_HCTSIZ3 bitfields.
    state->u.f4.fld.fs_hctsiz3.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz3, "XFRSIZ"); 
    state->u.f4.fld.fs_hctsiz3.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz3, "PKTCNT"); 
    state->u.f4.fld.fs_hctsiz3.dpid = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz3, "DPID");  
    
    // FS_HCTSIZ4 bitfields.
    state->u.f4.fld.fs_hctsiz4.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz4, "XFRSIZ"); 
    state->u.f4.fld.fs_hctsiz4.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz4, "PKTCNT"); 
    state->u.f4.fld.fs_hctsiz4.dpid = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz4, "DPID");  
    
    // FS_HCTSIZ5 bitfields.
    state->u.f4.fld.fs_hctsiz5.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz5, "XFRSIZ"); 
    state->u.f4.fld.fs_hctsiz5.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz5, "PKTCNT"); 
    state->u.f4.fld.fs_hctsiz5.dpid = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz5, "DPID");  
    
    // FS_HCTSIZ6 bitfields.
    state->u.f4.fld.fs_hctsiz6.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz6, "XFRSIZ"); 
    state->u.f4.fld.fs_hctsiz6.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz6, "PKTCNT"); 
    state->u.f4.fld.fs_hctsiz6.dpid = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz6, "DPID");  
    
    // FS_HCTSIZ7 bitfields.
    state->u.f4.fld.fs_hctsiz7.xfrsiz = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz7, "XFRSIZ"); 
    state->u.f4.fld.fs_hctsiz7.pktcnt = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz7, "PKTCNT"); 
    state->u.f4.fld.fs_hctsiz7.dpid = cm_object_get_child_by_name(state->u.f4.reg.fs_hctsiz7, "DPID");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_otg_fs_host_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32OTG_FS_HOSTState *state = STM32_OTG_FS_HOST_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_otg_fs_host_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32OTG_FS_HOSTState *state = STM32_OTG_FS_HOST_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_otg_fs_host_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32OTG_FS_HOSTState *state = STM32_OTG_FS_HOST_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_otg_fs_host_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32OTG_FS_HOSTState *state = STM32_OTG_FS_HOST_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_otg_fs_host_is_enabled(Object *obj)
{
    STM32OTG_FS_HOSTState *state = STM32_OTG_FS_HOST_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_otg_fs_host_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32OTG_FS_HOSTState *state = STM32_OTG_FS_HOST_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_otg_fs_host_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_OTG_FS_HOST)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32OTG_FS_HOSTState *state = STM32_OTG_FS_HOST_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "OTG_FS_HOST";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_40x ) {

            stm32f40x_otg_fs_host_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_otg_fs_host_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_otg_fs_host_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_otg_fs_host_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_otg_fs_host_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/OTG_FS_HOSTEN");


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

static void stm32_otg_fs_host_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_OTG_FS_HOST);
}

static void stm32_otg_fs_host_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_otg_fs_host_reset_callback;
    dc->realize = stm32_otg_fs_host_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_otg_fs_host_is_enabled;
}

static const TypeInfo stm32_otg_fs_host_type_info = {
    .name = TYPE_STM32_OTG_FS_HOST,
    .parent = TYPE_STM32_OTG_FS_HOST_PARENT,
    .instance_init = stm32_otg_fs_host_instance_init_callback,
    .instance_size = sizeof(STM32OTG_FS_HOSTState),
    .class_init = stm32_otg_fs_host_class_init_callback,
    .class_size = sizeof(STM32OTG_FS_HOSTClass) };

static void stm32_otg_fs_host_register_types(void)
{
    type_register_static(&stm32_otg_fs_host_type_info);
}

type_init(stm32_otg_fs_host_register_types);

// ----------------------------------------------------------------------------
