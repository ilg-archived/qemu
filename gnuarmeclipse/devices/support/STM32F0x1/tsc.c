/*
 * STM32 - TSC (Touch sensing controller) emulation.
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

#include <hw/cortexm/stm32/tsc.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_tsc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32TSCState *state = STM32_TSC_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->u.f0.reg.ier = cm_object_get_child_by_name(obj, "IER");
    state->u.f0.reg.icr = cm_object_get_child_by_name(obj, "ICR");
    state->u.f0.reg.isr = cm_object_get_child_by_name(obj, "ISR");
    state->u.f0.reg.iohcr = cm_object_get_child_by_name(obj, "IOHCR");
    state->u.f0.reg.ioascr = cm_object_get_child_by_name(obj, "IOASCR");
    state->u.f0.reg.ioscr = cm_object_get_child_by_name(obj, "IOSCR");
    state->u.f0.reg.ioccr = cm_object_get_child_by_name(obj, "IOCCR");
    state->u.f0.reg.iogcsr = cm_object_get_child_by_name(obj, "IOGCSR");
    state->u.f0.reg.iog1cr = cm_object_get_child_by_name(obj, "IOG1CR");
    state->u.f0.reg.iog2cr = cm_object_get_child_by_name(obj, "IOG2CR");
    state->u.f0.reg.iog3cr = cm_object_get_child_by_name(obj, "IOG3CR");
    state->u.f0.reg.iog4cr = cm_object_get_child_by_name(obj, "IOG4CR");
    state->u.f0.reg.iog5cr = cm_object_get_child_by_name(obj, "IOG5CR");
    state->u.f0.reg.iog6cr = cm_object_get_child_by_name(obj, "IOG6CR");
    
    
    // CR bitfields.
    state->u.f0.fld.cr.tsce = cm_object_get_child_by_name(state->u.f0.reg.cr, "TSCE"); 
    state->u.f0.fld.cr.start = cm_object_get_child_by_name(state->u.f0.reg.cr, "START"); 
    state->u.f0.fld.cr.am = cm_object_get_child_by_name(state->u.f0.reg.cr, "AM"); 
    state->u.f0.fld.cr.syncpol = cm_object_get_child_by_name(state->u.f0.reg.cr, "SYNCPOL"); 
    state->u.f0.fld.cr.iodef = cm_object_get_child_by_name(state->u.f0.reg.cr, "IODEF"); 
    state->u.f0.fld.cr.mcv = cm_object_get_child_by_name(state->u.f0.reg.cr, "MCV"); 
    state->u.f0.fld.cr.pgpsc = cm_object_get_child_by_name(state->u.f0.reg.cr, "PGPSC"); 
    state->u.f0.fld.cr.sspsc = cm_object_get_child_by_name(state->u.f0.reg.cr, "SSPSC"); 
    state->u.f0.fld.cr.sse = cm_object_get_child_by_name(state->u.f0.reg.cr, "SSE"); 
    state->u.f0.fld.cr.ssd = cm_object_get_child_by_name(state->u.f0.reg.cr, "SSD"); 
    state->u.f0.fld.cr.ctpl = cm_object_get_child_by_name(state->u.f0.reg.cr, "CTPL"); 
    state->u.f0.fld.cr.ctph = cm_object_get_child_by_name(state->u.f0.reg.cr, "CTPH");  
    
    // IER bitfields.
    state->u.f0.fld.ier.eoaie = cm_object_get_child_by_name(state->u.f0.reg.ier, "EOAIE"); 
    state->u.f0.fld.ier.mceie = cm_object_get_child_by_name(state->u.f0.reg.ier, "MCEIE");  
    
    // ICR bitfields.
    state->u.f0.fld.icr.eoaic = cm_object_get_child_by_name(state->u.f0.reg.icr, "EOAIC"); 
    state->u.f0.fld.icr.mceic = cm_object_get_child_by_name(state->u.f0.reg.icr, "MCEIC");  
    
    // ISR bitfields.
    state->u.f0.fld.isr.eoaf = cm_object_get_child_by_name(state->u.f0.reg.isr, "EOAF"); 
    state->u.f0.fld.isr.mcef = cm_object_get_child_by_name(state->u.f0.reg.isr, "MCEF");  
    
    // IOHCR bitfields.
    state->u.f0.fld.iohcr.g1_io1 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G1_IO1"); 
    state->u.f0.fld.iohcr.g1_io2 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G1_IO2"); 
    state->u.f0.fld.iohcr.g1_io3 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G1_IO3"); 
    state->u.f0.fld.iohcr.g1_io4 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G1_IO4"); 
    state->u.f0.fld.iohcr.g2_io1 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G2_IO1"); 
    state->u.f0.fld.iohcr.g2_io2 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G2_IO2"); 
    state->u.f0.fld.iohcr.g2_io3 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G2_IO3"); 
    state->u.f0.fld.iohcr.g2_io4 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G2_IO4"); 
    state->u.f0.fld.iohcr.g3_io1 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G3_IO1"); 
    state->u.f0.fld.iohcr.g3_io2 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G3_IO2"); 
    state->u.f0.fld.iohcr.g3_io3 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G3_IO3"); 
    state->u.f0.fld.iohcr.g3_io4 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G3_IO4"); 
    state->u.f0.fld.iohcr.g4_io1 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G4_IO1"); 
    state->u.f0.fld.iohcr.g4_io2 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G4_IO2"); 
    state->u.f0.fld.iohcr.g4_io3 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G4_IO3"); 
    state->u.f0.fld.iohcr.g4_io4 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G4_IO4"); 
    state->u.f0.fld.iohcr.g5_io1 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G5_IO1"); 
    state->u.f0.fld.iohcr.g5_io2 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G5_IO2"); 
    state->u.f0.fld.iohcr.g5_io3 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G5_IO3"); 
    state->u.f0.fld.iohcr.g5_io4 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G5_IO4"); 
    state->u.f0.fld.iohcr.g6_io1 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G6_IO1"); 
    state->u.f0.fld.iohcr.g6_io2 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G6_IO2"); 
    state->u.f0.fld.iohcr.g6_io3 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G6_IO3"); 
    state->u.f0.fld.iohcr.g6_io4 = cm_object_get_child_by_name(state->u.f0.reg.iohcr, "G6_IO4");  
    
    // IOASCR bitfields.
    state->u.f0.fld.ioascr.g1_io1 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G1_IO1"); 
    state->u.f0.fld.ioascr.g1_io2 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G1_IO2"); 
    state->u.f0.fld.ioascr.g1_io3 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G1_IO3"); 
    state->u.f0.fld.ioascr.g1_io4 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G1_IO4"); 
    state->u.f0.fld.ioascr.g2_io1 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G2_IO1"); 
    state->u.f0.fld.ioascr.g2_io2 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G2_IO2"); 
    state->u.f0.fld.ioascr.g2_io3 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G2_IO3"); 
    state->u.f0.fld.ioascr.g2_io4 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G2_IO4"); 
    state->u.f0.fld.ioascr.g3_io1 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G3_IO1"); 
    state->u.f0.fld.ioascr.g3_io2 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G3_IO2"); 
    state->u.f0.fld.ioascr.g3_io3 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G3_IO3"); 
    state->u.f0.fld.ioascr.g3_io4 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G3_IO4"); 
    state->u.f0.fld.ioascr.g4_io1 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G4_IO1"); 
    state->u.f0.fld.ioascr.g4_io2 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G4_IO2"); 
    state->u.f0.fld.ioascr.g4_io3 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G4_IO3"); 
    state->u.f0.fld.ioascr.g4_io4 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G4_IO4"); 
    state->u.f0.fld.ioascr.g5_io1 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G5_IO1"); 
    state->u.f0.fld.ioascr.g5_io2 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G5_IO2"); 
    state->u.f0.fld.ioascr.g5_io3 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G5_IO3"); 
    state->u.f0.fld.ioascr.g5_io4 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G5_IO4"); 
    state->u.f0.fld.ioascr.g6_io1 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G6_IO1"); 
    state->u.f0.fld.ioascr.g6_io2 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G6_IO2"); 
    state->u.f0.fld.ioascr.g6_io3 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G6_IO3"); 
    state->u.f0.fld.ioascr.g6_io4 = cm_object_get_child_by_name(state->u.f0.reg.ioascr, "G6_IO4");  
    
    // IOSCR bitfields.
    state->u.f0.fld.ioscr.g1_io1 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G1_IO1"); 
    state->u.f0.fld.ioscr.g1_io2 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G1_IO2"); 
    state->u.f0.fld.ioscr.g1_io3 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G1_IO3"); 
    state->u.f0.fld.ioscr.g1_io4 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G1_IO4"); 
    state->u.f0.fld.ioscr.g2_io1 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G2_IO1"); 
    state->u.f0.fld.ioscr.g2_io2 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G2_IO2"); 
    state->u.f0.fld.ioscr.g2_io3 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G2_IO3"); 
    state->u.f0.fld.ioscr.g2_io4 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G2_IO4"); 
    state->u.f0.fld.ioscr.g3_io1 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G3_IO1"); 
    state->u.f0.fld.ioscr.g3_io2 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G3_IO2"); 
    state->u.f0.fld.ioscr.g3_io3 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G3_IO3"); 
    state->u.f0.fld.ioscr.g3_io4 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G3_IO4"); 
    state->u.f0.fld.ioscr.g4_io1 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G4_IO1"); 
    state->u.f0.fld.ioscr.g4_io2 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G4_IO2"); 
    state->u.f0.fld.ioscr.g4_io3 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G4_IO3"); 
    state->u.f0.fld.ioscr.g4_io4 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G4_IO4"); 
    state->u.f0.fld.ioscr.g5_io1 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G5_IO1"); 
    state->u.f0.fld.ioscr.g5_io2 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G5_IO2"); 
    state->u.f0.fld.ioscr.g5_io3 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G5_IO3"); 
    state->u.f0.fld.ioscr.g5_io4 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G5_IO4"); 
    state->u.f0.fld.ioscr.g6_io1 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G6_IO1"); 
    state->u.f0.fld.ioscr.g6_io2 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G6_IO2"); 
    state->u.f0.fld.ioscr.g6_io3 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G6_IO3"); 
    state->u.f0.fld.ioscr.g6_io4 = cm_object_get_child_by_name(state->u.f0.reg.ioscr, "G6_IO4");  
    
    // IOCCR bitfields.
    state->u.f0.fld.ioccr.g1_io1 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G1_IO1"); 
    state->u.f0.fld.ioccr.g1_io2 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G1_IO2"); 
    state->u.f0.fld.ioccr.g1_io3 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G1_IO3"); 
    state->u.f0.fld.ioccr.g1_io4 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G1_IO4"); 
    state->u.f0.fld.ioccr.g2_io1 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G2_IO1"); 
    state->u.f0.fld.ioccr.g2_io2 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G2_IO2"); 
    state->u.f0.fld.ioccr.g2_io3 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G2_IO3"); 
    state->u.f0.fld.ioccr.g2_io4 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G2_IO4"); 
    state->u.f0.fld.ioccr.g3_io1 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G3_IO1"); 
    state->u.f0.fld.ioccr.g3_io2 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G3_IO2"); 
    state->u.f0.fld.ioccr.g3_io3 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G3_IO3"); 
    state->u.f0.fld.ioccr.g3_io4 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G3_IO4"); 
    state->u.f0.fld.ioccr.g4_io1 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G4_IO1"); 
    state->u.f0.fld.ioccr.g4_io2 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G4_IO2"); 
    state->u.f0.fld.ioccr.g4_io3 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G4_IO3"); 
    state->u.f0.fld.ioccr.g4_io4 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G4_IO4"); 
    state->u.f0.fld.ioccr.g5_io1 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G5_IO1"); 
    state->u.f0.fld.ioccr.g5_io2 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G5_IO2"); 
    state->u.f0.fld.ioccr.g5_io3 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G5_IO3"); 
    state->u.f0.fld.ioccr.g5_io4 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G5_IO4"); 
    state->u.f0.fld.ioccr.g6_io1 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G6_IO1"); 
    state->u.f0.fld.ioccr.g6_io2 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G6_IO2"); 
    state->u.f0.fld.ioccr.g6_io3 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G6_IO3"); 
    state->u.f0.fld.ioccr.g6_io4 = cm_object_get_child_by_name(state->u.f0.reg.ioccr, "G6_IO4");  
    
    // IOGCSR bitfields.
    state->u.f0.fld.iogcsr.g1e = cm_object_get_child_by_name(state->u.f0.reg.iogcsr, "G1E"); 
    state->u.f0.fld.iogcsr.g2e = cm_object_get_child_by_name(state->u.f0.reg.iogcsr, "G2E"); 
    state->u.f0.fld.iogcsr.g3e = cm_object_get_child_by_name(state->u.f0.reg.iogcsr, "G3E"); 
    state->u.f0.fld.iogcsr.g4e = cm_object_get_child_by_name(state->u.f0.reg.iogcsr, "G4E"); 
    state->u.f0.fld.iogcsr.g5e = cm_object_get_child_by_name(state->u.f0.reg.iogcsr, "G5E"); 
    state->u.f0.fld.iogcsr.g6e = cm_object_get_child_by_name(state->u.f0.reg.iogcsr, "G6E"); 
    state->u.f0.fld.iogcsr.g7e = cm_object_get_child_by_name(state->u.f0.reg.iogcsr, "G7E"); 
    state->u.f0.fld.iogcsr.g8e = cm_object_get_child_by_name(state->u.f0.reg.iogcsr, "G8E"); 
    state->u.f0.fld.iogcsr.g1s = cm_object_get_child_by_name(state->u.f0.reg.iogcsr, "G1S"); 
    state->u.f0.fld.iogcsr.g2s = cm_object_get_child_by_name(state->u.f0.reg.iogcsr, "G2S"); 
    state->u.f0.fld.iogcsr.g3s = cm_object_get_child_by_name(state->u.f0.reg.iogcsr, "G3S"); 
    state->u.f0.fld.iogcsr.g4s = cm_object_get_child_by_name(state->u.f0.reg.iogcsr, "G4S"); 
    state->u.f0.fld.iogcsr.g5s = cm_object_get_child_by_name(state->u.f0.reg.iogcsr, "G5S"); 
    state->u.f0.fld.iogcsr.g6s = cm_object_get_child_by_name(state->u.f0.reg.iogcsr, "G6S"); 
    state->u.f0.fld.iogcsr.g7s = cm_object_get_child_by_name(state->u.f0.reg.iogcsr, "G7S"); 
    state->u.f0.fld.iogcsr.g8s = cm_object_get_child_by_name(state->u.f0.reg.iogcsr, "G8S");  
    
    // IOG1CR bitfields.
    state->u.f0.fld.iog1cr.cnt = cm_object_get_child_by_name(state->u.f0.reg.iog1cr, "CNT");  
    
    // IOG2CR bitfields.
    state->u.f0.fld.iog2cr.cnt = cm_object_get_child_by_name(state->u.f0.reg.iog2cr, "CNT");  
    
    // IOG3CR bitfields.
    state->u.f0.fld.iog3cr.cnt = cm_object_get_child_by_name(state->u.f0.reg.iog3cr, "CNT");  
    
    // IOG4CR bitfields.
    state->u.f0.fld.iog4cr.cnt = cm_object_get_child_by_name(state->u.f0.reg.iog4cr, "CNT");  
    
    // IOG5CR bitfields.
    state->u.f0.fld.iog5cr.cnt = cm_object_get_child_by_name(state->u.f0.reg.iog5cr, "CNT");  
    
    // IOG6CR bitfields.
    state->u.f0.fld.iog6cr.cnt = cm_object_get_child_by_name(state->u.f0.reg.iog6cr, "CNT");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_tsc_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32TSCState *state = STM32_TSC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_tsc_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32TSCState *state = STM32_TSC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_tsc_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32TSCState *state = STM32_TSC_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_tsc_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32TSCState *state = STM32_TSC_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_tsc_is_enabled(Object *obj)
{
    STM32TSCState *state = STM32_TSC_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_tsc_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32TSCState *state = STM32_TSC_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_tsc_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_TSC)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32TSCState *state = STM32_TSC_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "TSC";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x1 ) {

            stm32f0x1_tsc_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_tsc_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f0.reg.xxx, &stm32_tsc_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_tsc_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f0.reg.xxx, &stm32_tsc_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/TSCEN");


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

static void stm32_tsc_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_TSC);
}

static void stm32_tsc_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_tsc_reset_callback;
    dc->realize = stm32_tsc_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_tsc_is_enabled;
}

static const TypeInfo stm32_tsc_type_info = {
    .name = TYPE_STM32_TSC,
    .parent = TYPE_STM32_TSC_PARENT,
    .instance_init = stm32_tsc_instance_init_callback,
    .instance_size = sizeof(STM32TSCState),
    .class_init = stm32_tsc_class_init_callback,
    .class_size = sizeof(STM32TSCClass) };

static void stm32_tsc_register_types(void)
{
    type_register_static(&stm32_tsc_type_info);
}

type_init(stm32_tsc_register_types);

// ----------------------------------------------------------------------------
