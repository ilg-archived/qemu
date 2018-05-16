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
static void stm32f0x1_dma_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32DMAState *state = STM32_DMA_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f0.reg.isr = cm_object_get_child_by_name(obj, "ISR");
    state->u.f0.reg.ifcr = cm_object_get_child_by_name(obj, "IFCR");
    state->u.f0.reg.ccr1 = cm_object_get_child_by_name(obj, "CCR1");
    state->u.f0.reg.cndtr1 = cm_object_get_child_by_name(obj, "CNDTR1");
    state->u.f0.reg.cpar1 = cm_object_get_child_by_name(obj, "CPAR1");
    state->u.f0.reg.cmar1 = cm_object_get_child_by_name(obj, "CMAR1");
    state->u.f0.reg.ccr2 = cm_object_get_child_by_name(obj, "CCR2");
    state->u.f0.reg.cndtr2 = cm_object_get_child_by_name(obj, "CNDTR2");
    state->u.f0.reg.cpar2 = cm_object_get_child_by_name(obj, "CPAR2");
    state->u.f0.reg.cmar2 = cm_object_get_child_by_name(obj, "CMAR2");
    state->u.f0.reg.ccr3 = cm_object_get_child_by_name(obj, "CCR3");
    state->u.f0.reg.cndtr3 = cm_object_get_child_by_name(obj, "CNDTR3");
    state->u.f0.reg.cpar3 = cm_object_get_child_by_name(obj, "CPAR3");
    state->u.f0.reg.cmar3 = cm_object_get_child_by_name(obj, "CMAR3");
    state->u.f0.reg.ccr4 = cm_object_get_child_by_name(obj, "CCR4");
    state->u.f0.reg.cndtr4 = cm_object_get_child_by_name(obj, "CNDTR4");
    state->u.f0.reg.cpar4 = cm_object_get_child_by_name(obj, "CPAR4");
    state->u.f0.reg.cmar4 = cm_object_get_child_by_name(obj, "CMAR4");
    state->u.f0.reg.ccr5 = cm_object_get_child_by_name(obj, "CCR5");
    state->u.f0.reg.cndtr5 = cm_object_get_child_by_name(obj, "CNDTR5");
    state->u.f0.reg.cpar5 = cm_object_get_child_by_name(obj, "CPAR5");
    state->u.f0.reg.cmar5 = cm_object_get_child_by_name(obj, "CMAR5");
    state->u.f0.reg.ccr6 = cm_object_get_child_by_name(obj, "CCR6");
    state->u.f0.reg.cndtr6 = cm_object_get_child_by_name(obj, "CNDTR6");
    state->u.f0.reg.cpar6 = cm_object_get_child_by_name(obj, "CPAR6");
    state->u.f0.reg.cmar6 = cm_object_get_child_by_name(obj, "CMAR6");
    state->u.f0.reg.ccr7 = cm_object_get_child_by_name(obj, "CCR7");
    state->u.f0.reg.cndtr7 = cm_object_get_child_by_name(obj, "CNDTR7");
    state->u.f0.reg.cpar7 = cm_object_get_child_by_name(obj, "CPAR7");
    state->u.f0.reg.cmar7 = cm_object_get_child_by_name(obj, "CMAR7");
    
    
    // ISR bitfields.
    state->u.f0.fld.isr.gif1 = cm_object_get_child_by_name(state->u.f0.reg.isr, "GIF1"); 
    state->u.f0.fld.isr.tcif1 = cm_object_get_child_by_name(state->u.f0.reg.isr, "TCIF1"); 
    state->u.f0.fld.isr.htif1 = cm_object_get_child_by_name(state->u.f0.reg.isr, "HTIF1"); 
    state->u.f0.fld.isr.teif1 = cm_object_get_child_by_name(state->u.f0.reg.isr, "TEIF1"); 
    state->u.f0.fld.isr.gif2 = cm_object_get_child_by_name(state->u.f0.reg.isr, "GIF2"); 
    state->u.f0.fld.isr.tcif2 = cm_object_get_child_by_name(state->u.f0.reg.isr, "TCIF2"); 
    state->u.f0.fld.isr.htif2 = cm_object_get_child_by_name(state->u.f0.reg.isr, "HTIF2"); 
    state->u.f0.fld.isr.teif2 = cm_object_get_child_by_name(state->u.f0.reg.isr, "TEIF2"); 
    state->u.f0.fld.isr.gif3 = cm_object_get_child_by_name(state->u.f0.reg.isr, "GIF3"); 
    state->u.f0.fld.isr.tcif3 = cm_object_get_child_by_name(state->u.f0.reg.isr, "TCIF3"); 
    state->u.f0.fld.isr.htif3 = cm_object_get_child_by_name(state->u.f0.reg.isr, "HTIF3"); 
    state->u.f0.fld.isr.teif3 = cm_object_get_child_by_name(state->u.f0.reg.isr, "TEIF3"); 
    state->u.f0.fld.isr.gif4 = cm_object_get_child_by_name(state->u.f0.reg.isr, "GIF4"); 
    state->u.f0.fld.isr.tcif4 = cm_object_get_child_by_name(state->u.f0.reg.isr, "TCIF4"); 
    state->u.f0.fld.isr.htif4 = cm_object_get_child_by_name(state->u.f0.reg.isr, "HTIF4"); 
    state->u.f0.fld.isr.teif4 = cm_object_get_child_by_name(state->u.f0.reg.isr, "TEIF4"); 
    state->u.f0.fld.isr.gif5 = cm_object_get_child_by_name(state->u.f0.reg.isr, "GIF5"); 
    state->u.f0.fld.isr.tcif5 = cm_object_get_child_by_name(state->u.f0.reg.isr, "TCIF5"); 
    state->u.f0.fld.isr.htif5 = cm_object_get_child_by_name(state->u.f0.reg.isr, "HTIF5"); 
    state->u.f0.fld.isr.teif5 = cm_object_get_child_by_name(state->u.f0.reg.isr, "TEIF5"); 
    state->u.f0.fld.isr.gif6 = cm_object_get_child_by_name(state->u.f0.reg.isr, "GIF6"); 
    state->u.f0.fld.isr.tcif6 = cm_object_get_child_by_name(state->u.f0.reg.isr, "TCIF6"); 
    state->u.f0.fld.isr.htif6 = cm_object_get_child_by_name(state->u.f0.reg.isr, "HTIF6"); 
    state->u.f0.fld.isr.teif6 = cm_object_get_child_by_name(state->u.f0.reg.isr, "TEIF6"); 
    state->u.f0.fld.isr.gif7 = cm_object_get_child_by_name(state->u.f0.reg.isr, "GIF7"); 
    state->u.f0.fld.isr.tcif7 = cm_object_get_child_by_name(state->u.f0.reg.isr, "TCIF7"); 
    state->u.f0.fld.isr.htif7 = cm_object_get_child_by_name(state->u.f0.reg.isr, "HTIF7"); 
    state->u.f0.fld.isr.teif7 = cm_object_get_child_by_name(state->u.f0.reg.isr, "TEIF7");  
    
    // IFCR bitfields.
    state->u.f0.fld.ifcr.cgif1 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CGIF1"); 
    state->u.f0.fld.ifcr.ctcif1 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CTCIF1"); 
    state->u.f0.fld.ifcr.chtif1 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CHTIF1"); 
    state->u.f0.fld.ifcr.cteif1 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CTEIF1"); 
    state->u.f0.fld.ifcr.cgif2 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CGIF2"); 
    state->u.f0.fld.ifcr.ctcif2 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CTCIF2"); 
    state->u.f0.fld.ifcr.chtif2 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CHTIF2"); 
    state->u.f0.fld.ifcr.cteif2 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CTEIF2"); 
    state->u.f0.fld.ifcr.cgif3 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CGIF3"); 
    state->u.f0.fld.ifcr.ctcif3 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CTCIF3"); 
    state->u.f0.fld.ifcr.chtif3 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CHTIF3"); 
    state->u.f0.fld.ifcr.cteif3 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CTEIF3"); 
    state->u.f0.fld.ifcr.cgif4 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CGIF4"); 
    state->u.f0.fld.ifcr.ctcif4 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CTCIF4"); 
    state->u.f0.fld.ifcr.chtif4 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CHTIF4"); 
    state->u.f0.fld.ifcr.cteif4 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CTEIF4"); 
    state->u.f0.fld.ifcr.cgif5 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CGIF5"); 
    state->u.f0.fld.ifcr.ctcif5 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CTCIF5"); 
    state->u.f0.fld.ifcr.chtif5 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CHTIF5"); 
    state->u.f0.fld.ifcr.cteif5 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CTEIF5"); 
    state->u.f0.fld.ifcr.cgif6 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CGIF6"); 
    state->u.f0.fld.ifcr.ctcif6 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CTCIF6"); 
    state->u.f0.fld.ifcr.chtif6 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CHTIF6"); 
    state->u.f0.fld.ifcr.cteif6 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CTEIF6"); 
    state->u.f0.fld.ifcr.cgif7 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CGIF7"); 
    state->u.f0.fld.ifcr.ctcif7 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CTCIF7"); 
    state->u.f0.fld.ifcr.chtif7 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CHTIF7"); 
    state->u.f0.fld.ifcr.cteif7 = cm_object_get_child_by_name(state->u.f0.reg.ifcr, "CTEIF7");  
    
    // CCR1 bitfields.
    state->u.f0.fld.ccr1.en = cm_object_get_child_by_name(state->u.f0.reg.ccr1, "EN"); 
    state->u.f0.fld.ccr1.tcie = cm_object_get_child_by_name(state->u.f0.reg.ccr1, "TCIE"); 
    state->u.f0.fld.ccr1.htie = cm_object_get_child_by_name(state->u.f0.reg.ccr1, "HTIE"); 
    state->u.f0.fld.ccr1.teie = cm_object_get_child_by_name(state->u.f0.reg.ccr1, "TEIE"); 
    state->u.f0.fld.ccr1.dir = cm_object_get_child_by_name(state->u.f0.reg.ccr1, "DIR"); 
    state->u.f0.fld.ccr1.circ = cm_object_get_child_by_name(state->u.f0.reg.ccr1, "CIRC"); 
    state->u.f0.fld.ccr1.pinc = cm_object_get_child_by_name(state->u.f0.reg.ccr1, "PINC"); 
    state->u.f0.fld.ccr1.minc = cm_object_get_child_by_name(state->u.f0.reg.ccr1, "MINC"); 
    state->u.f0.fld.ccr1.psize = cm_object_get_child_by_name(state->u.f0.reg.ccr1, "PSIZE"); 
    state->u.f0.fld.ccr1.msize = cm_object_get_child_by_name(state->u.f0.reg.ccr1, "MSIZE"); 
    state->u.f0.fld.ccr1.pl = cm_object_get_child_by_name(state->u.f0.reg.ccr1, "PL"); 
    state->u.f0.fld.ccr1.mem2mem = cm_object_get_child_by_name(state->u.f0.reg.ccr1, "MEM2MEM");  
    
    // CNDTR1 bitfields.
    state->u.f0.fld.cndtr1.ndt = cm_object_get_child_by_name(state->u.f0.reg.cndtr1, "NDT");  
    
    // CPAR1 bitfields.
    state->u.f0.fld.cpar1.pa = cm_object_get_child_by_name(state->u.f0.reg.cpar1, "PA");  
    
    // CMAR1 bitfields.
    state->u.f0.fld.cmar1.ma = cm_object_get_child_by_name(state->u.f0.reg.cmar1, "MA");  
    
    // CCR2 bitfields.
    state->u.f0.fld.ccr2.en = cm_object_get_child_by_name(state->u.f0.reg.ccr2, "EN"); 
    state->u.f0.fld.ccr2.tcie = cm_object_get_child_by_name(state->u.f0.reg.ccr2, "TCIE"); 
    state->u.f0.fld.ccr2.htie = cm_object_get_child_by_name(state->u.f0.reg.ccr2, "HTIE"); 
    state->u.f0.fld.ccr2.teie = cm_object_get_child_by_name(state->u.f0.reg.ccr2, "TEIE"); 
    state->u.f0.fld.ccr2.dir = cm_object_get_child_by_name(state->u.f0.reg.ccr2, "DIR"); 
    state->u.f0.fld.ccr2.circ = cm_object_get_child_by_name(state->u.f0.reg.ccr2, "CIRC"); 
    state->u.f0.fld.ccr2.pinc = cm_object_get_child_by_name(state->u.f0.reg.ccr2, "PINC"); 
    state->u.f0.fld.ccr2.minc = cm_object_get_child_by_name(state->u.f0.reg.ccr2, "MINC"); 
    state->u.f0.fld.ccr2.psize = cm_object_get_child_by_name(state->u.f0.reg.ccr2, "PSIZE"); 
    state->u.f0.fld.ccr2.msize = cm_object_get_child_by_name(state->u.f0.reg.ccr2, "MSIZE"); 
    state->u.f0.fld.ccr2.pl = cm_object_get_child_by_name(state->u.f0.reg.ccr2, "PL"); 
    state->u.f0.fld.ccr2.mem2mem = cm_object_get_child_by_name(state->u.f0.reg.ccr2, "MEM2MEM");  
    
    // CNDTR2 bitfields.
    state->u.f0.fld.cndtr2.ndt = cm_object_get_child_by_name(state->u.f0.reg.cndtr2, "NDT");  
    
    // CPAR2 bitfields.
    state->u.f0.fld.cpar2.pa = cm_object_get_child_by_name(state->u.f0.reg.cpar2, "PA");  
    
    // CMAR2 bitfields.
    state->u.f0.fld.cmar2.ma = cm_object_get_child_by_name(state->u.f0.reg.cmar2, "MA");  
    
    // CCR3 bitfields.
    state->u.f0.fld.ccr3.en = cm_object_get_child_by_name(state->u.f0.reg.ccr3, "EN"); 
    state->u.f0.fld.ccr3.tcie = cm_object_get_child_by_name(state->u.f0.reg.ccr3, "TCIE"); 
    state->u.f0.fld.ccr3.htie = cm_object_get_child_by_name(state->u.f0.reg.ccr3, "HTIE"); 
    state->u.f0.fld.ccr3.teie = cm_object_get_child_by_name(state->u.f0.reg.ccr3, "TEIE"); 
    state->u.f0.fld.ccr3.dir = cm_object_get_child_by_name(state->u.f0.reg.ccr3, "DIR"); 
    state->u.f0.fld.ccr3.circ = cm_object_get_child_by_name(state->u.f0.reg.ccr3, "CIRC"); 
    state->u.f0.fld.ccr3.pinc = cm_object_get_child_by_name(state->u.f0.reg.ccr3, "PINC"); 
    state->u.f0.fld.ccr3.minc = cm_object_get_child_by_name(state->u.f0.reg.ccr3, "MINC"); 
    state->u.f0.fld.ccr3.psize = cm_object_get_child_by_name(state->u.f0.reg.ccr3, "PSIZE"); 
    state->u.f0.fld.ccr3.msize = cm_object_get_child_by_name(state->u.f0.reg.ccr3, "MSIZE"); 
    state->u.f0.fld.ccr3.pl = cm_object_get_child_by_name(state->u.f0.reg.ccr3, "PL"); 
    state->u.f0.fld.ccr3.mem2mem = cm_object_get_child_by_name(state->u.f0.reg.ccr3, "MEM2MEM");  
    
    // CNDTR3 bitfields.
    state->u.f0.fld.cndtr3.ndt = cm_object_get_child_by_name(state->u.f0.reg.cndtr3, "NDT");  
    
    // CPAR3 bitfields.
    state->u.f0.fld.cpar3.pa = cm_object_get_child_by_name(state->u.f0.reg.cpar3, "PA");  
    
    // CMAR3 bitfields.
    state->u.f0.fld.cmar3.ma = cm_object_get_child_by_name(state->u.f0.reg.cmar3, "MA");  
    
    // CCR4 bitfields.
    state->u.f0.fld.ccr4.en = cm_object_get_child_by_name(state->u.f0.reg.ccr4, "EN"); 
    state->u.f0.fld.ccr4.tcie = cm_object_get_child_by_name(state->u.f0.reg.ccr4, "TCIE"); 
    state->u.f0.fld.ccr4.htie = cm_object_get_child_by_name(state->u.f0.reg.ccr4, "HTIE"); 
    state->u.f0.fld.ccr4.teie = cm_object_get_child_by_name(state->u.f0.reg.ccr4, "TEIE"); 
    state->u.f0.fld.ccr4.dir = cm_object_get_child_by_name(state->u.f0.reg.ccr4, "DIR"); 
    state->u.f0.fld.ccr4.circ = cm_object_get_child_by_name(state->u.f0.reg.ccr4, "CIRC"); 
    state->u.f0.fld.ccr4.pinc = cm_object_get_child_by_name(state->u.f0.reg.ccr4, "PINC"); 
    state->u.f0.fld.ccr4.minc = cm_object_get_child_by_name(state->u.f0.reg.ccr4, "MINC"); 
    state->u.f0.fld.ccr4.psize = cm_object_get_child_by_name(state->u.f0.reg.ccr4, "PSIZE"); 
    state->u.f0.fld.ccr4.msize = cm_object_get_child_by_name(state->u.f0.reg.ccr4, "MSIZE"); 
    state->u.f0.fld.ccr4.pl = cm_object_get_child_by_name(state->u.f0.reg.ccr4, "PL"); 
    state->u.f0.fld.ccr4.mem2mem = cm_object_get_child_by_name(state->u.f0.reg.ccr4, "MEM2MEM");  
    
    // CNDTR4 bitfields.
    state->u.f0.fld.cndtr4.ndt = cm_object_get_child_by_name(state->u.f0.reg.cndtr4, "NDT");  
    
    // CPAR4 bitfields.
    state->u.f0.fld.cpar4.pa = cm_object_get_child_by_name(state->u.f0.reg.cpar4, "PA");  
    
    // CMAR4 bitfields.
    state->u.f0.fld.cmar4.ma = cm_object_get_child_by_name(state->u.f0.reg.cmar4, "MA");  
    
    // CCR5 bitfields.
    state->u.f0.fld.ccr5.en = cm_object_get_child_by_name(state->u.f0.reg.ccr5, "EN"); 
    state->u.f0.fld.ccr5.tcie = cm_object_get_child_by_name(state->u.f0.reg.ccr5, "TCIE"); 
    state->u.f0.fld.ccr5.htie = cm_object_get_child_by_name(state->u.f0.reg.ccr5, "HTIE"); 
    state->u.f0.fld.ccr5.teie = cm_object_get_child_by_name(state->u.f0.reg.ccr5, "TEIE"); 
    state->u.f0.fld.ccr5.dir = cm_object_get_child_by_name(state->u.f0.reg.ccr5, "DIR"); 
    state->u.f0.fld.ccr5.circ = cm_object_get_child_by_name(state->u.f0.reg.ccr5, "CIRC"); 
    state->u.f0.fld.ccr5.pinc = cm_object_get_child_by_name(state->u.f0.reg.ccr5, "PINC"); 
    state->u.f0.fld.ccr5.minc = cm_object_get_child_by_name(state->u.f0.reg.ccr5, "MINC"); 
    state->u.f0.fld.ccr5.psize = cm_object_get_child_by_name(state->u.f0.reg.ccr5, "PSIZE"); 
    state->u.f0.fld.ccr5.msize = cm_object_get_child_by_name(state->u.f0.reg.ccr5, "MSIZE"); 
    state->u.f0.fld.ccr5.pl = cm_object_get_child_by_name(state->u.f0.reg.ccr5, "PL"); 
    state->u.f0.fld.ccr5.mem2mem = cm_object_get_child_by_name(state->u.f0.reg.ccr5, "MEM2MEM");  
    
    // CNDTR5 bitfields.
    state->u.f0.fld.cndtr5.ndt = cm_object_get_child_by_name(state->u.f0.reg.cndtr5, "NDT");  
    
    // CPAR5 bitfields.
    state->u.f0.fld.cpar5.pa = cm_object_get_child_by_name(state->u.f0.reg.cpar5, "PA");  
    
    // CMAR5 bitfields.
    state->u.f0.fld.cmar5.ma = cm_object_get_child_by_name(state->u.f0.reg.cmar5, "MA");  
    
    // CCR6 bitfields.
    state->u.f0.fld.ccr6.en = cm_object_get_child_by_name(state->u.f0.reg.ccr6, "EN"); 
    state->u.f0.fld.ccr6.tcie = cm_object_get_child_by_name(state->u.f0.reg.ccr6, "TCIE"); 
    state->u.f0.fld.ccr6.htie = cm_object_get_child_by_name(state->u.f0.reg.ccr6, "HTIE"); 
    state->u.f0.fld.ccr6.teie = cm_object_get_child_by_name(state->u.f0.reg.ccr6, "TEIE"); 
    state->u.f0.fld.ccr6.dir = cm_object_get_child_by_name(state->u.f0.reg.ccr6, "DIR"); 
    state->u.f0.fld.ccr6.circ = cm_object_get_child_by_name(state->u.f0.reg.ccr6, "CIRC"); 
    state->u.f0.fld.ccr6.pinc = cm_object_get_child_by_name(state->u.f0.reg.ccr6, "PINC"); 
    state->u.f0.fld.ccr6.minc = cm_object_get_child_by_name(state->u.f0.reg.ccr6, "MINC"); 
    state->u.f0.fld.ccr6.psize = cm_object_get_child_by_name(state->u.f0.reg.ccr6, "PSIZE"); 
    state->u.f0.fld.ccr6.msize = cm_object_get_child_by_name(state->u.f0.reg.ccr6, "MSIZE"); 
    state->u.f0.fld.ccr6.pl = cm_object_get_child_by_name(state->u.f0.reg.ccr6, "PL"); 
    state->u.f0.fld.ccr6.mem2mem = cm_object_get_child_by_name(state->u.f0.reg.ccr6, "MEM2MEM");  
    
    // CNDTR6 bitfields.
    state->u.f0.fld.cndtr6.ndt = cm_object_get_child_by_name(state->u.f0.reg.cndtr6, "NDT");  
    
    // CPAR6 bitfields.
    state->u.f0.fld.cpar6.pa = cm_object_get_child_by_name(state->u.f0.reg.cpar6, "PA");  
    
    // CMAR6 bitfields.
    state->u.f0.fld.cmar6.ma = cm_object_get_child_by_name(state->u.f0.reg.cmar6, "MA");  
    
    // CCR7 bitfields.
    state->u.f0.fld.ccr7.en = cm_object_get_child_by_name(state->u.f0.reg.ccr7, "EN"); 
    state->u.f0.fld.ccr7.tcie = cm_object_get_child_by_name(state->u.f0.reg.ccr7, "TCIE"); 
    state->u.f0.fld.ccr7.htie = cm_object_get_child_by_name(state->u.f0.reg.ccr7, "HTIE"); 
    state->u.f0.fld.ccr7.teie = cm_object_get_child_by_name(state->u.f0.reg.ccr7, "TEIE"); 
    state->u.f0.fld.ccr7.dir = cm_object_get_child_by_name(state->u.f0.reg.ccr7, "DIR"); 
    state->u.f0.fld.ccr7.circ = cm_object_get_child_by_name(state->u.f0.reg.ccr7, "CIRC"); 
    state->u.f0.fld.ccr7.pinc = cm_object_get_child_by_name(state->u.f0.reg.ccr7, "PINC"); 
    state->u.f0.fld.ccr7.minc = cm_object_get_child_by_name(state->u.f0.reg.ccr7, "MINC"); 
    state->u.f0.fld.ccr7.psize = cm_object_get_child_by_name(state->u.f0.reg.ccr7, "PSIZE"); 
    state->u.f0.fld.ccr7.msize = cm_object_get_child_by_name(state->u.f0.reg.ccr7, "MSIZE"); 
    state->u.f0.fld.ccr7.pl = cm_object_get_child_by_name(state->u.f0.reg.ccr7, "PL"); 
    state->u.f0.fld.ccr7.mem2mem = cm_object_get_child_by_name(state->u.f0.reg.ccr7, "MEM2MEM");  
    
    // CNDTR7 bitfields.
    state->u.f0.fld.cndtr7.ndt = cm_object_get_child_by_name(state->u.f0.reg.cndtr7, "NDT");  
    
    // CPAR7 bitfields.
    state->u.f0.fld.cpar7.pa = cm_object_get_child_by_name(state->u.f0.reg.cpar7, "PA");  
    
    // CMAR7 bitfields.
    state->u.f0.fld.cmar7.ma = cm_object_get_child_by_name(state->u.f0.reg.cmar7, "MA");  
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
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x1 ) {

            stm32f0x1_dma_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_dma_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f0.reg.xxx, &stm32_dma_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_dma_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f0.reg.xxx, &stm32_dma_xxx_post_write_callback);

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
