/*
 * STM32 - DMA (DMA controller) emulation.
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

#include <hw/cortexm/stm32/dma.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f429x_dma_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32DMAState *state = STM32_DMA_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.lisr = cm_object_get_child_by_name(obj, "LISR");
    state->u.f4.reg.hisr = cm_object_get_child_by_name(obj, "HISR");
    state->u.f4.reg.lifcr = cm_object_get_child_by_name(obj, "LIFCR");
    state->u.f4.reg.hifcr = cm_object_get_child_by_name(obj, "HIFCR");
    state->u.f4.reg.s0cr = cm_object_get_child_by_name(obj, "S0CR");
    state->u.f4.reg.s0ndtr = cm_object_get_child_by_name(obj, "S0NDTR");
    state->u.f4.reg.s0par = cm_object_get_child_by_name(obj, "S0PAR");
    state->u.f4.reg.s0m0ar = cm_object_get_child_by_name(obj, "S0M0AR");
    state->u.f4.reg.s0m1ar = cm_object_get_child_by_name(obj, "S0M1AR");
    state->u.f4.reg.s0fcr = cm_object_get_child_by_name(obj, "S0FCR");
    state->u.f4.reg.s1cr = cm_object_get_child_by_name(obj, "S1CR");
    state->u.f4.reg.s1ndtr = cm_object_get_child_by_name(obj, "S1NDTR");
    state->u.f4.reg.s1par = cm_object_get_child_by_name(obj, "S1PAR");
    state->u.f4.reg.s1m0ar = cm_object_get_child_by_name(obj, "S1M0AR");
    state->u.f4.reg.s1m1ar = cm_object_get_child_by_name(obj, "S1M1AR");
    state->u.f4.reg.s1fcr = cm_object_get_child_by_name(obj, "S1FCR");
    state->u.f4.reg.s2cr = cm_object_get_child_by_name(obj, "S2CR");
    state->u.f4.reg.s2ndtr = cm_object_get_child_by_name(obj, "S2NDTR");
    state->u.f4.reg.s2par = cm_object_get_child_by_name(obj, "S2PAR");
    state->u.f4.reg.s2m0ar = cm_object_get_child_by_name(obj, "S2M0AR");
    state->u.f4.reg.s2m1ar = cm_object_get_child_by_name(obj, "S2M1AR");
    state->u.f4.reg.s2fcr = cm_object_get_child_by_name(obj, "S2FCR");
    state->u.f4.reg.s3cr = cm_object_get_child_by_name(obj, "S3CR");
    state->u.f4.reg.s3ndtr = cm_object_get_child_by_name(obj, "S3NDTR");
    state->u.f4.reg.s3par = cm_object_get_child_by_name(obj, "S3PAR");
    state->u.f4.reg.s3m0ar = cm_object_get_child_by_name(obj, "S3M0AR");
    state->u.f4.reg.s3m1ar = cm_object_get_child_by_name(obj, "S3M1AR");
    state->u.f4.reg.s3fcr = cm_object_get_child_by_name(obj, "S3FCR");
    state->u.f4.reg.s4cr = cm_object_get_child_by_name(obj, "S4CR");
    state->u.f4.reg.s4ndtr = cm_object_get_child_by_name(obj, "S4NDTR");
    state->u.f4.reg.s4par = cm_object_get_child_by_name(obj, "S4PAR");
    state->u.f4.reg.s4m0ar = cm_object_get_child_by_name(obj, "S4M0AR");
    state->u.f4.reg.s4m1ar = cm_object_get_child_by_name(obj, "S4M1AR");
    state->u.f4.reg.s4fcr = cm_object_get_child_by_name(obj, "S4FCR");
    state->u.f4.reg.s5cr = cm_object_get_child_by_name(obj, "S5CR");
    state->u.f4.reg.s5ndtr = cm_object_get_child_by_name(obj, "S5NDTR");
    state->u.f4.reg.s5par = cm_object_get_child_by_name(obj, "S5PAR");
    state->u.f4.reg.s5m0ar = cm_object_get_child_by_name(obj, "S5M0AR");
    state->u.f4.reg.s5m1ar = cm_object_get_child_by_name(obj, "S5M1AR");
    state->u.f4.reg.s5fcr = cm_object_get_child_by_name(obj, "S5FCR");
    state->u.f4.reg.s6cr = cm_object_get_child_by_name(obj, "S6CR");
    state->u.f4.reg.s6ndtr = cm_object_get_child_by_name(obj, "S6NDTR");
    state->u.f4.reg.s6par = cm_object_get_child_by_name(obj, "S6PAR");
    state->u.f4.reg.s6m0ar = cm_object_get_child_by_name(obj, "S6M0AR");
    state->u.f4.reg.s6m1ar = cm_object_get_child_by_name(obj, "S6M1AR");
    state->u.f4.reg.s6fcr = cm_object_get_child_by_name(obj, "S6FCR");
    state->u.f4.reg.s7cr = cm_object_get_child_by_name(obj, "S7CR");
    state->u.f4.reg.s7ndtr = cm_object_get_child_by_name(obj, "S7NDTR");
    state->u.f4.reg.s7par = cm_object_get_child_by_name(obj, "S7PAR");
    state->u.f4.reg.s7m0ar = cm_object_get_child_by_name(obj, "S7M0AR");
    state->u.f4.reg.s7m1ar = cm_object_get_child_by_name(obj, "S7M1AR");
    state->u.f4.reg.s7fcr = cm_object_get_child_by_name(obj, "S7FCR");
    
    
    // LISR bitfields.
    state->u.f4.fld.lisr.feif0 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "FEIF0"); 
    state->u.f4.fld.lisr.dmeif0 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "DMEIF0"); 
    state->u.f4.fld.lisr.teif0 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "TEIF0"); 
    state->u.f4.fld.lisr.htif0 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "HTIF0"); 
    state->u.f4.fld.lisr.tcif0 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "TCIF0"); 
    state->u.f4.fld.lisr.feif1 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "FEIF1"); 
    state->u.f4.fld.lisr.dmeif1 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "DMEIF1"); 
    state->u.f4.fld.lisr.teif1 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "TEIF1"); 
    state->u.f4.fld.lisr.htif1 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "HTIF1"); 
    state->u.f4.fld.lisr.tcif1 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "TCIF1"); 
    state->u.f4.fld.lisr.feif2 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "FEIF2"); 
    state->u.f4.fld.lisr.dmeif2 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "DMEIF2"); 
    state->u.f4.fld.lisr.teif2 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "TEIF2"); 
    state->u.f4.fld.lisr.htif2 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "HTIF2"); 
    state->u.f4.fld.lisr.tcif2 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "TCIF2"); 
    state->u.f4.fld.lisr.feif3 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "FEIF3"); 
    state->u.f4.fld.lisr.dmeif3 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "DMEIF3"); 
    state->u.f4.fld.lisr.teif3 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "TEIF3"); 
    state->u.f4.fld.lisr.htif3 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "HTIF3"); 
    state->u.f4.fld.lisr.tcif3 = cm_object_get_child_by_name(state->u.f4.reg.lisr, "TCIF3");  
    
    // HISR bitfields.
    state->u.f4.fld.hisr.feif4 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "FEIF4"); 
    state->u.f4.fld.hisr.dmeif4 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "DMEIF4"); 
    state->u.f4.fld.hisr.teif4 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "TEIF4"); 
    state->u.f4.fld.hisr.htif4 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "HTIF4"); 
    state->u.f4.fld.hisr.tcif4 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "TCIF4"); 
    state->u.f4.fld.hisr.feif5 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "FEIF5"); 
    state->u.f4.fld.hisr.dmeif5 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "DMEIF5"); 
    state->u.f4.fld.hisr.teif5 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "TEIF5"); 
    state->u.f4.fld.hisr.htif5 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "HTIF5"); 
    state->u.f4.fld.hisr.tcif5 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "TCIF5"); 
    state->u.f4.fld.hisr.feif6 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "FEIF6"); 
    state->u.f4.fld.hisr.dmeif6 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "DMEIF6"); 
    state->u.f4.fld.hisr.teif6 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "TEIF6"); 
    state->u.f4.fld.hisr.htif6 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "HTIF6"); 
    state->u.f4.fld.hisr.tcif6 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "TCIF6"); 
    state->u.f4.fld.hisr.feif7 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "FEIF7"); 
    state->u.f4.fld.hisr.dmeif7 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "DMEIF7"); 
    state->u.f4.fld.hisr.teif7 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "TEIF7"); 
    state->u.f4.fld.hisr.htif7 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "HTIF7"); 
    state->u.f4.fld.hisr.tcif7 = cm_object_get_child_by_name(state->u.f4.reg.hisr, "TCIF7");  
    
    // LIFCR bitfields.
    state->u.f4.fld.lifcr.cfeif0 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CFEIF0"); 
    state->u.f4.fld.lifcr.cdmeif0 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CDMEIF0"); 
    state->u.f4.fld.lifcr.cteif0 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CTEIF0"); 
    state->u.f4.fld.lifcr.chtif0 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CHTIF0"); 
    state->u.f4.fld.lifcr.ctcif0 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CTCIF0"); 
    state->u.f4.fld.lifcr.cfeif1 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CFEIF1"); 
    state->u.f4.fld.lifcr.cdmeif1 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CDMEIF1"); 
    state->u.f4.fld.lifcr.cteif1 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CTEIF1"); 
    state->u.f4.fld.lifcr.chtif1 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CHTIF1"); 
    state->u.f4.fld.lifcr.ctcif1 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CTCIF1"); 
    state->u.f4.fld.lifcr.cfeif2 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CFEIF2"); 
    state->u.f4.fld.lifcr.cdmeif2 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CDMEIF2"); 
    state->u.f4.fld.lifcr.cteif2 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CTEIF2"); 
    state->u.f4.fld.lifcr.chtif2 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CHTIF2"); 
    state->u.f4.fld.lifcr.ctcif2 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CTCIF2"); 
    state->u.f4.fld.lifcr.cfeif3 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CFEIF3"); 
    state->u.f4.fld.lifcr.cdmeif3 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CDMEIF3"); 
    state->u.f4.fld.lifcr.cteif3 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CTEIF3"); 
    state->u.f4.fld.lifcr.chtif3 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CHTIF3"); 
    state->u.f4.fld.lifcr.ctcif3 = cm_object_get_child_by_name(state->u.f4.reg.lifcr, "CTCIF3");  
    
    // HIFCR bitfields.
    state->u.f4.fld.hifcr.cfeif4 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CFEIF4"); 
    state->u.f4.fld.hifcr.cdmeif4 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CDMEIF4"); 
    state->u.f4.fld.hifcr.cteif4 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CTEIF4"); 
    state->u.f4.fld.hifcr.chtif4 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CHTIF4"); 
    state->u.f4.fld.hifcr.ctcif4 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CTCIF4"); 
    state->u.f4.fld.hifcr.cfeif5 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CFEIF5"); 
    state->u.f4.fld.hifcr.cdmeif5 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CDMEIF5"); 
    state->u.f4.fld.hifcr.cteif5 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CTEIF5"); 
    state->u.f4.fld.hifcr.chtif5 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CHTIF5"); 
    state->u.f4.fld.hifcr.ctcif5 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CTCIF5"); 
    state->u.f4.fld.hifcr.cfeif6 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CFEIF6"); 
    state->u.f4.fld.hifcr.cdmeif6 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CDMEIF6"); 
    state->u.f4.fld.hifcr.cteif6 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CTEIF6"); 
    state->u.f4.fld.hifcr.chtif6 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CHTIF6"); 
    state->u.f4.fld.hifcr.ctcif6 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CTCIF6"); 
    state->u.f4.fld.hifcr.cfeif7 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CFEIF7"); 
    state->u.f4.fld.hifcr.cdmeif7 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CDMEIF7"); 
    state->u.f4.fld.hifcr.cteif7 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CTEIF7"); 
    state->u.f4.fld.hifcr.chtif7 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CHTIF7"); 
    state->u.f4.fld.hifcr.ctcif7 = cm_object_get_child_by_name(state->u.f4.reg.hifcr, "CTCIF7");  
    
    // S0CR bitfields.
    state->u.f4.fld.s0cr.en = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "EN"); 
    state->u.f4.fld.s0cr.dmeie = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "DMEIE"); 
    state->u.f4.fld.s0cr.teie = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "TEIE"); 
    state->u.f4.fld.s0cr.htie = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "HTIE"); 
    state->u.f4.fld.s0cr.tcie = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "TCIE"); 
    state->u.f4.fld.s0cr.pfctrl = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "PFCTRL"); 
    state->u.f4.fld.s0cr.dir = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "DIR"); 
    state->u.f4.fld.s0cr.circ = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "CIRC"); 
    state->u.f4.fld.s0cr.pinc = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "PINC"); 
    state->u.f4.fld.s0cr.minc = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "MINC"); 
    state->u.f4.fld.s0cr.psize = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "PSIZE"); 
    state->u.f4.fld.s0cr.msize = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "MSIZE"); 
    state->u.f4.fld.s0cr.pincos = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "PINCOS"); 
    state->u.f4.fld.s0cr.pl = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "PL"); 
    state->u.f4.fld.s0cr.dbm = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "DBM"); 
    state->u.f4.fld.s0cr.ct = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "CT"); 
    state->u.f4.fld.s0cr.pburst = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "PBURST"); 
    state->u.f4.fld.s0cr.mburst = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "MBURST"); 
    state->u.f4.fld.s0cr.chsel = cm_object_get_child_by_name(state->u.f4.reg.s0cr, "CHSEL");  
    
    // S0NDTR bitfields.
    state->u.f4.fld.s0ndtr.ndt = cm_object_get_child_by_name(state->u.f4.reg.s0ndtr, "NDT");  
    
    // S0PAR bitfields.
    state->u.f4.fld.s0par.pa = cm_object_get_child_by_name(state->u.f4.reg.s0par, "PA");  
    
    // S0M0AR bitfields.
    state->u.f4.fld.s0m0ar.m0a = cm_object_get_child_by_name(state->u.f4.reg.s0m0ar, "M0A");  
    
    // S0M1AR bitfields.
    state->u.f4.fld.s0m1ar.m1a = cm_object_get_child_by_name(state->u.f4.reg.s0m1ar, "M1A");  
    
    // S0FCR bitfields.
    state->u.f4.fld.s0fcr.fth = cm_object_get_child_by_name(state->u.f4.reg.s0fcr, "FTH"); 
    state->u.f4.fld.s0fcr.dmdis = cm_object_get_child_by_name(state->u.f4.reg.s0fcr, "DMDIS"); 
    state->u.f4.fld.s0fcr.fs = cm_object_get_child_by_name(state->u.f4.reg.s0fcr, "FS"); 
    state->u.f4.fld.s0fcr.feie = cm_object_get_child_by_name(state->u.f4.reg.s0fcr, "FEIE");  
    
    // S1CR bitfields.
    state->u.f4.fld.s1cr.en = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "EN"); 
    state->u.f4.fld.s1cr.dmeie = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "DMEIE"); 
    state->u.f4.fld.s1cr.teie = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "TEIE"); 
    state->u.f4.fld.s1cr.htie = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "HTIE"); 
    state->u.f4.fld.s1cr.tcie = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "TCIE"); 
    state->u.f4.fld.s1cr.pfctrl = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "PFCTRL"); 
    state->u.f4.fld.s1cr.dir = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "DIR"); 
    state->u.f4.fld.s1cr.circ = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "CIRC"); 
    state->u.f4.fld.s1cr.pinc = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "PINC"); 
    state->u.f4.fld.s1cr.minc = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "MINC"); 
    state->u.f4.fld.s1cr.psize = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "PSIZE"); 
    state->u.f4.fld.s1cr.msize = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "MSIZE"); 
    state->u.f4.fld.s1cr.pincos = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "PINCOS"); 
    state->u.f4.fld.s1cr.pl = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "PL"); 
    state->u.f4.fld.s1cr.dbm = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "DBM"); 
    state->u.f4.fld.s1cr.ct = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "CT"); 
    state->u.f4.fld.s1cr.ack = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "ACK"); 
    state->u.f4.fld.s1cr.pburst = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "PBURST"); 
    state->u.f4.fld.s1cr.mburst = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "MBURST"); 
    state->u.f4.fld.s1cr.chsel = cm_object_get_child_by_name(state->u.f4.reg.s1cr, "CHSEL");  
    
    // S1NDTR bitfields.
    state->u.f4.fld.s1ndtr.ndt = cm_object_get_child_by_name(state->u.f4.reg.s1ndtr, "NDT");  
    
    // S1PAR bitfields.
    state->u.f4.fld.s1par.pa = cm_object_get_child_by_name(state->u.f4.reg.s1par, "PA");  
    
    // S1M0AR bitfields.
    state->u.f4.fld.s1m0ar.m0a = cm_object_get_child_by_name(state->u.f4.reg.s1m0ar, "M0A");  
    
    // S1M1AR bitfields.
    state->u.f4.fld.s1m1ar.m1a = cm_object_get_child_by_name(state->u.f4.reg.s1m1ar, "M1A");  
    
    // S1FCR bitfields.
    state->u.f4.fld.s1fcr.fth = cm_object_get_child_by_name(state->u.f4.reg.s1fcr, "FTH"); 
    state->u.f4.fld.s1fcr.dmdis = cm_object_get_child_by_name(state->u.f4.reg.s1fcr, "DMDIS"); 
    state->u.f4.fld.s1fcr.fs = cm_object_get_child_by_name(state->u.f4.reg.s1fcr, "FS"); 
    state->u.f4.fld.s1fcr.feie = cm_object_get_child_by_name(state->u.f4.reg.s1fcr, "FEIE");  
    
    // S2CR bitfields.
    state->u.f4.fld.s2cr.en = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "EN"); 
    state->u.f4.fld.s2cr.dmeie = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "DMEIE"); 
    state->u.f4.fld.s2cr.teie = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "TEIE"); 
    state->u.f4.fld.s2cr.htie = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "HTIE"); 
    state->u.f4.fld.s2cr.tcie = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "TCIE"); 
    state->u.f4.fld.s2cr.pfctrl = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "PFCTRL"); 
    state->u.f4.fld.s2cr.dir = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "DIR"); 
    state->u.f4.fld.s2cr.circ = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "CIRC"); 
    state->u.f4.fld.s2cr.pinc = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "PINC"); 
    state->u.f4.fld.s2cr.minc = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "MINC"); 
    state->u.f4.fld.s2cr.psize = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "PSIZE"); 
    state->u.f4.fld.s2cr.msize = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "MSIZE"); 
    state->u.f4.fld.s2cr.pincos = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "PINCOS"); 
    state->u.f4.fld.s2cr.pl = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "PL"); 
    state->u.f4.fld.s2cr.dbm = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "DBM"); 
    state->u.f4.fld.s2cr.ct = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "CT"); 
    state->u.f4.fld.s2cr.ack = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "ACK"); 
    state->u.f4.fld.s2cr.pburst = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "PBURST"); 
    state->u.f4.fld.s2cr.mburst = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "MBURST"); 
    state->u.f4.fld.s2cr.chsel = cm_object_get_child_by_name(state->u.f4.reg.s2cr, "CHSEL");  
    
    // S2NDTR bitfields.
    state->u.f4.fld.s2ndtr.ndt = cm_object_get_child_by_name(state->u.f4.reg.s2ndtr, "NDT");  
    
    // S2PAR bitfields.
    state->u.f4.fld.s2par.pa = cm_object_get_child_by_name(state->u.f4.reg.s2par, "PA");  
    
    // S2M0AR bitfields.
    state->u.f4.fld.s2m0ar.m0a = cm_object_get_child_by_name(state->u.f4.reg.s2m0ar, "M0A");  
    
    // S2M1AR bitfields.
    state->u.f4.fld.s2m1ar.m1a = cm_object_get_child_by_name(state->u.f4.reg.s2m1ar, "M1A");  
    
    // S2FCR bitfields.
    state->u.f4.fld.s2fcr.fth = cm_object_get_child_by_name(state->u.f4.reg.s2fcr, "FTH"); 
    state->u.f4.fld.s2fcr.dmdis = cm_object_get_child_by_name(state->u.f4.reg.s2fcr, "DMDIS"); 
    state->u.f4.fld.s2fcr.fs = cm_object_get_child_by_name(state->u.f4.reg.s2fcr, "FS"); 
    state->u.f4.fld.s2fcr.feie = cm_object_get_child_by_name(state->u.f4.reg.s2fcr, "FEIE");  
    
    // S3CR bitfields.
    state->u.f4.fld.s3cr.en = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "EN"); 
    state->u.f4.fld.s3cr.dmeie = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "DMEIE"); 
    state->u.f4.fld.s3cr.teie = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "TEIE"); 
    state->u.f4.fld.s3cr.htie = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "HTIE"); 
    state->u.f4.fld.s3cr.tcie = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "TCIE"); 
    state->u.f4.fld.s3cr.pfctrl = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "PFCTRL"); 
    state->u.f4.fld.s3cr.dir = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "DIR"); 
    state->u.f4.fld.s3cr.circ = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "CIRC"); 
    state->u.f4.fld.s3cr.pinc = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "PINC"); 
    state->u.f4.fld.s3cr.minc = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "MINC"); 
    state->u.f4.fld.s3cr.psize = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "PSIZE"); 
    state->u.f4.fld.s3cr.msize = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "MSIZE"); 
    state->u.f4.fld.s3cr.pincos = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "PINCOS"); 
    state->u.f4.fld.s3cr.pl = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "PL"); 
    state->u.f4.fld.s3cr.dbm = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "DBM"); 
    state->u.f4.fld.s3cr.ct = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "CT"); 
    state->u.f4.fld.s3cr.ack = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "ACK"); 
    state->u.f4.fld.s3cr.pburst = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "PBURST"); 
    state->u.f4.fld.s3cr.mburst = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "MBURST"); 
    state->u.f4.fld.s3cr.chsel = cm_object_get_child_by_name(state->u.f4.reg.s3cr, "CHSEL");  
    
    // S3NDTR bitfields.
    state->u.f4.fld.s3ndtr.ndt = cm_object_get_child_by_name(state->u.f4.reg.s3ndtr, "NDT");  
    
    // S3PAR bitfields.
    state->u.f4.fld.s3par.pa = cm_object_get_child_by_name(state->u.f4.reg.s3par, "PA");  
    
    // S3M0AR bitfields.
    state->u.f4.fld.s3m0ar.m0a = cm_object_get_child_by_name(state->u.f4.reg.s3m0ar, "M0A");  
    
    // S3M1AR bitfields.
    state->u.f4.fld.s3m1ar.m1a = cm_object_get_child_by_name(state->u.f4.reg.s3m1ar, "M1A");  
    
    // S3FCR bitfields.
    state->u.f4.fld.s3fcr.fth = cm_object_get_child_by_name(state->u.f4.reg.s3fcr, "FTH"); 
    state->u.f4.fld.s3fcr.dmdis = cm_object_get_child_by_name(state->u.f4.reg.s3fcr, "DMDIS"); 
    state->u.f4.fld.s3fcr.fs = cm_object_get_child_by_name(state->u.f4.reg.s3fcr, "FS"); 
    state->u.f4.fld.s3fcr.feie = cm_object_get_child_by_name(state->u.f4.reg.s3fcr, "FEIE");  
    
    // S4CR bitfields.
    state->u.f4.fld.s4cr.en = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "EN"); 
    state->u.f4.fld.s4cr.dmeie = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "DMEIE"); 
    state->u.f4.fld.s4cr.teie = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "TEIE"); 
    state->u.f4.fld.s4cr.htie = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "HTIE"); 
    state->u.f4.fld.s4cr.tcie = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "TCIE"); 
    state->u.f4.fld.s4cr.pfctrl = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "PFCTRL"); 
    state->u.f4.fld.s4cr.dir = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "DIR"); 
    state->u.f4.fld.s4cr.circ = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "CIRC"); 
    state->u.f4.fld.s4cr.pinc = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "PINC"); 
    state->u.f4.fld.s4cr.minc = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "MINC"); 
    state->u.f4.fld.s4cr.psize = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "PSIZE"); 
    state->u.f4.fld.s4cr.msize = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "MSIZE"); 
    state->u.f4.fld.s4cr.pincos = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "PINCOS"); 
    state->u.f4.fld.s4cr.pl = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "PL"); 
    state->u.f4.fld.s4cr.dbm = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "DBM"); 
    state->u.f4.fld.s4cr.ct = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "CT"); 
    state->u.f4.fld.s4cr.ack = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "ACK"); 
    state->u.f4.fld.s4cr.pburst = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "PBURST"); 
    state->u.f4.fld.s4cr.mburst = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "MBURST"); 
    state->u.f4.fld.s4cr.chsel = cm_object_get_child_by_name(state->u.f4.reg.s4cr, "CHSEL");  
    
    // S4NDTR bitfields.
    state->u.f4.fld.s4ndtr.ndt = cm_object_get_child_by_name(state->u.f4.reg.s4ndtr, "NDT");  
    
    // S4PAR bitfields.
    state->u.f4.fld.s4par.pa = cm_object_get_child_by_name(state->u.f4.reg.s4par, "PA");  
    
    // S4M0AR bitfields.
    state->u.f4.fld.s4m0ar.m0a = cm_object_get_child_by_name(state->u.f4.reg.s4m0ar, "M0A");  
    
    // S4M1AR bitfields.
    state->u.f4.fld.s4m1ar.m1a = cm_object_get_child_by_name(state->u.f4.reg.s4m1ar, "M1A");  
    
    // S4FCR bitfields.
    state->u.f4.fld.s4fcr.fth = cm_object_get_child_by_name(state->u.f4.reg.s4fcr, "FTH"); 
    state->u.f4.fld.s4fcr.dmdis = cm_object_get_child_by_name(state->u.f4.reg.s4fcr, "DMDIS"); 
    state->u.f4.fld.s4fcr.fs = cm_object_get_child_by_name(state->u.f4.reg.s4fcr, "FS"); 
    state->u.f4.fld.s4fcr.feie = cm_object_get_child_by_name(state->u.f4.reg.s4fcr, "FEIE");  
    
    // S5CR bitfields.
    state->u.f4.fld.s5cr.en = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "EN"); 
    state->u.f4.fld.s5cr.dmeie = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "DMEIE"); 
    state->u.f4.fld.s5cr.teie = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "TEIE"); 
    state->u.f4.fld.s5cr.htie = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "HTIE"); 
    state->u.f4.fld.s5cr.tcie = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "TCIE"); 
    state->u.f4.fld.s5cr.pfctrl = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "PFCTRL"); 
    state->u.f4.fld.s5cr.dir = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "DIR"); 
    state->u.f4.fld.s5cr.circ = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "CIRC"); 
    state->u.f4.fld.s5cr.pinc = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "PINC"); 
    state->u.f4.fld.s5cr.minc = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "MINC"); 
    state->u.f4.fld.s5cr.psize = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "PSIZE"); 
    state->u.f4.fld.s5cr.msize = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "MSIZE"); 
    state->u.f4.fld.s5cr.pincos = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "PINCOS"); 
    state->u.f4.fld.s5cr.pl = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "PL"); 
    state->u.f4.fld.s5cr.dbm = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "DBM"); 
    state->u.f4.fld.s5cr.ct = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "CT"); 
    state->u.f4.fld.s5cr.ack = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "ACK"); 
    state->u.f4.fld.s5cr.pburst = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "PBURST"); 
    state->u.f4.fld.s5cr.mburst = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "MBURST"); 
    state->u.f4.fld.s5cr.chsel = cm_object_get_child_by_name(state->u.f4.reg.s5cr, "CHSEL");  
    
    // S5NDTR bitfields.
    state->u.f4.fld.s5ndtr.ndt = cm_object_get_child_by_name(state->u.f4.reg.s5ndtr, "NDT");  
    
    // S5PAR bitfields.
    state->u.f4.fld.s5par.pa = cm_object_get_child_by_name(state->u.f4.reg.s5par, "PA");  
    
    // S5M0AR bitfields.
    state->u.f4.fld.s5m0ar.m0a = cm_object_get_child_by_name(state->u.f4.reg.s5m0ar, "M0A");  
    
    // S5M1AR bitfields.
    state->u.f4.fld.s5m1ar.m1a = cm_object_get_child_by_name(state->u.f4.reg.s5m1ar, "M1A");  
    
    // S5FCR bitfields.
    state->u.f4.fld.s5fcr.fth = cm_object_get_child_by_name(state->u.f4.reg.s5fcr, "FTH"); 
    state->u.f4.fld.s5fcr.dmdis = cm_object_get_child_by_name(state->u.f4.reg.s5fcr, "DMDIS"); 
    state->u.f4.fld.s5fcr.fs = cm_object_get_child_by_name(state->u.f4.reg.s5fcr, "FS"); 
    state->u.f4.fld.s5fcr.feie = cm_object_get_child_by_name(state->u.f4.reg.s5fcr, "FEIE");  
    
    // S6CR bitfields.
    state->u.f4.fld.s6cr.en = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "EN"); 
    state->u.f4.fld.s6cr.dmeie = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "DMEIE"); 
    state->u.f4.fld.s6cr.teie = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "TEIE"); 
    state->u.f4.fld.s6cr.htie = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "HTIE"); 
    state->u.f4.fld.s6cr.tcie = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "TCIE"); 
    state->u.f4.fld.s6cr.pfctrl = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "PFCTRL"); 
    state->u.f4.fld.s6cr.dir = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "DIR"); 
    state->u.f4.fld.s6cr.circ = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "CIRC"); 
    state->u.f4.fld.s6cr.pinc = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "PINC"); 
    state->u.f4.fld.s6cr.minc = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "MINC"); 
    state->u.f4.fld.s6cr.psize = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "PSIZE"); 
    state->u.f4.fld.s6cr.msize = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "MSIZE"); 
    state->u.f4.fld.s6cr.pincos = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "PINCOS"); 
    state->u.f4.fld.s6cr.pl = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "PL"); 
    state->u.f4.fld.s6cr.dbm = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "DBM"); 
    state->u.f4.fld.s6cr.ct = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "CT"); 
    state->u.f4.fld.s6cr.ack = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "ACK"); 
    state->u.f4.fld.s6cr.pburst = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "PBURST"); 
    state->u.f4.fld.s6cr.mburst = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "MBURST"); 
    state->u.f4.fld.s6cr.chsel = cm_object_get_child_by_name(state->u.f4.reg.s6cr, "CHSEL");  
    
    // S6NDTR bitfields.
    state->u.f4.fld.s6ndtr.ndt = cm_object_get_child_by_name(state->u.f4.reg.s6ndtr, "NDT");  
    
    // S6PAR bitfields.
    state->u.f4.fld.s6par.pa = cm_object_get_child_by_name(state->u.f4.reg.s6par, "PA");  
    
    // S6M0AR bitfields.
    state->u.f4.fld.s6m0ar.m0a = cm_object_get_child_by_name(state->u.f4.reg.s6m0ar, "M0A");  
    
    // S6M1AR bitfields.
    state->u.f4.fld.s6m1ar.m1a = cm_object_get_child_by_name(state->u.f4.reg.s6m1ar, "M1A");  
    
    // S6FCR bitfields.
    state->u.f4.fld.s6fcr.fth = cm_object_get_child_by_name(state->u.f4.reg.s6fcr, "FTH"); 
    state->u.f4.fld.s6fcr.dmdis = cm_object_get_child_by_name(state->u.f4.reg.s6fcr, "DMDIS"); 
    state->u.f4.fld.s6fcr.fs = cm_object_get_child_by_name(state->u.f4.reg.s6fcr, "FS"); 
    state->u.f4.fld.s6fcr.feie = cm_object_get_child_by_name(state->u.f4.reg.s6fcr, "FEIE");  
    
    // S7CR bitfields.
    state->u.f4.fld.s7cr.en = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "EN"); 
    state->u.f4.fld.s7cr.dmeie = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "DMEIE"); 
    state->u.f4.fld.s7cr.teie = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "TEIE"); 
    state->u.f4.fld.s7cr.htie = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "HTIE"); 
    state->u.f4.fld.s7cr.tcie = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "TCIE"); 
    state->u.f4.fld.s7cr.pfctrl = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "PFCTRL"); 
    state->u.f4.fld.s7cr.dir = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "DIR"); 
    state->u.f4.fld.s7cr.circ = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "CIRC"); 
    state->u.f4.fld.s7cr.pinc = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "PINC"); 
    state->u.f4.fld.s7cr.minc = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "MINC"); 
    state->u.f4.fld.s7cr.psize = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "PSIZE"); 
    state->u.f4.fld.s7cr.msize = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "MSIZE"); 
    state->u.f4.fld.s7cr.pincos = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "PINCOS"); 
    state->u.f4.fld.s7cr.pl = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "PL"); 
    state->u.f4.fld.s7cr.dbm = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "DBM"); 
    state->u.f4.fld.s7cr.ct = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "CT"); 
    state->u.f4.fld.s7cr.ack = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "ACK"); 
    state->u.f4.fld.s7cr.pburst = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "PBURST"); 
    state->u.f4.fld.s7cr.mburst = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "MBURST"); 
    state->u.f4.fld.s7cr.chsel = cm_object_get_child_by_name(state->u.f4.reg.s7cr, "CHSEL");  
    
    // S7NDTR bitfields.
    state->u.f4.fld.s7ndtr.ndt = cm_object_get_child_by_name(state->u.f4.reg.s7ndtr, "NDT");  
    
    // S7PAR bitfields.
    state->u.f4.fld.s7par.pa = cm_object_get_child_by_name(state->u.f4.reg.s7par, "PA");  
    
    // S7M0AR bitfields.
    state->u.f4.fld.s7m0ar.m0a = cm_object_get_child_by_name(state->u.f4.reg.s7m0ar, "M0A");  
    
    // S7M1AR bitfields.
    state->u.f4.fld.s7m1ar.m1a = cm_object_get_child_by_name(state->u.f4.reg.s7m1ar, "M1A");  
    
    // S7FCR bitfields.
    state->u.f4.fld.s7fcr.fth = cm_object_get_child_by_name(state->u.f4.reg.s7fcr, "FTH"); 
    state->u.f4.fld.s7fcr.dmdis = cm_object_get_child_by_name(state->u.f4.reg.s7fcr, "DMDIS"); 
    state->u.f4.fld.s7fcr.fs = cm_object_get_child_by_name(state->u.f4.reg.s7fcr, "FS"); 
    state->u.f4.fld.s7fcr.feie = cm_object_get_child_by_name(state->u.f4.reg.s7fcr, "FEIE");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_dma_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32DMAState *state = STM32_DMA_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_dma_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32DMAState *state = STM32_DMA_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_dma_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32DMAState *state = STM32_DMA_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_dma_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32DMAState *state = STM32_DMA_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_dma_is_enabled(Object *obj)
{
    STM32DMAState *state = STM32_DMA_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_dma_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32DMAState *state = STM32_DMA_STATE(obj);

    // Capabilities are not yet available.

    cm_object_property_add_int(obj, "port-index",
            (const int *) &state->port_index);
    state->port_index = STM32_PORT_DMA_UNDEFINED;

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_dma_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_DMA)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32DMAState *state = STM32_DMA_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "DMA";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_429x ) {

            stm32f429x_dma_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_dma_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_dma_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_dma_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_dma_xxx_post_write_callback);

            // TODO: add interrupts.

           // TODO: remove this if the peripheral is always enabled.
           snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/DMA%dEN",
                1 + state->port_index - STM32_PORT_DMA1);


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

static void stm32_dma_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_DMA);
}

static void stm32_dma_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_dma_reset_callback;
    dc->realize = stm32_dma_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_dma_is_enabled;
}

static const TypeInfo stm32_dma_type_info = {
    .name = TYPE_STM32_DMA,
    .parent = TYPE_STM32_DMA_PARENT,
    .instance_init = stm32_dma_instance_init_callback,
    .instance_size = sizeof(STM32DMAState),
    .class_init = stm32_dma_class_init_callback,
    .class_size = sizeof(STM32DMAClass) };

static void stm32_dma_register_types(void)
{
    type_register_static(&stm32_dma_type_info);
}

type_init(stm32_dma_register_types);

// ----------------------------------------------------------------------------
