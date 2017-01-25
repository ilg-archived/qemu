/*
 * STM32 - CAN (Controller area network) emulation.
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

#include <hw/cortexm/stm32/can.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f429x_can_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32CANState *state = STM32_CAN_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.mcr = cm_object_get_child_by_name(obj, "MCR");
    state->u.f4.reg.msr = cm_object_get_child_by_name(obj, "MSR");
    state->u.f4.reg.tsr = cm_object_get_child_by_name(obj, "TSR");
    state->u.f4.reg.rf0r = cm_object_get_child_by_name(obj, "RF0R");
    state->u.f4.reg.rf1r = cm_object_get_child_by_name(obj, "RF1R");
    state->u.f4.reg.ier = cm_object_get_child_by_name(obj, "IER");
    state->u.f4.reg.esr = cm_object_get_child_by_name(obj, "ESR");
    state->u.f4.reg.btr = cm_object_get_child_by_name(obj, "BTR");
    state->u.f4.reg.ti0r = cm_object_get_child_by_name(obj, "TI0R");
    state->u.f4.reg.tdt0r = cm_object_get_child_by_name(obj, "TDT0R");
    state->u.f4.reg.tdl0r = cm_object_get_child_by_name(obj, "TDL0R");
    state->u.f4.reg.tdh0r = cm_object_get_child_by_name(obj, "TDH0R");
    state->u.f4.reg.ti1r = cm_object_get_child_by_name(obj, "TI1R");
    state->u.f4.reg.tdt1r = cm_object_get_child_by_name(obj, "TDT1R");
    state->u.f4.reg.tdl1r = cm_object_get_child_by_name(obj, "TDL1R");
    state->u.f4.reg.tdh1r = cm_object_get_child_by_name(obj, "TDH1R");
    state->u.f4.reg.ti2r = cm_object_get_child_by_name(obj, "TI2R");
    state->u.f4.reg.tdt2r = cm_object_get_child_by_name(obj, "TDT2R");
    state->u.f4.reg.tdl2r = cm_object_get_child_by_name(obj, "TDL2R");
    state->u.f4.reg.tdh2r = cm_object_get_child_by_name(obj, "TDH2R");
    state->u.f4.reg.ri0r = cm_object_get_child_by_name(obj, "RI0R");
    state->u.f4.reg.rdt0r = cm_object_get_child_by_name(obj, "RDT0R");
    state->u.f4.reg.rdl0r = cm_object_get_child_by_name(obj, "RDL0R");
    state->u.f4.reg.rdh0r = cm_object_get_child_by_name(obj, "RDH0R");
    state->u.f4.reg.ri1r = cm_object_get_child_by_name(obj, "RI1R");
    state->u.f4.reg.rdt1r = cm_object_get_child_by_name(obj, "RDT1R");
    state->u.f4.reg.rdl1r = cm_object_get_child_by_name(obj, "RDL1R");
    state->u.f4.reg.rdh1r = cm_object_get_child_by_name(obj, "RDH1R");
    state->u.f4.reg.fmr = cm_object_get_child_by_name(obj, "FMR");
    state->u.f4.reg.fm1r = cm_object_get_child_by_name(obj, "FM1R");
    state->u.f4.reg.fs1r = cm_object_get_child_by_name(obj, "FS1R");
    state->u.f4.reg.ffa1r = cm_object_get_child_by_name(obj, "FFA1R");
    state->u.f4.reg.fa1r = cm_object_get_child_by_name(obj, "FA1R");
    state->u.f4.reg.f0r1 = cm_object_get_child_by_name(obj, "F0R1");
    state->u.f4.reg.f0r2 = cm_object_get_child_by_name(obj, "F0R2");
    state->u.f4.reg.f1r1 = cm_object_get_child_by_name(obj, "F1R1");
    state->u.f4.reg.f1r2 = cm_object_get_child_by_name(obj, "F1R2");
    state->u.f4.reg.f2r1 = cm_object_get_child_by_name(obj, "F2R1");
    state->u.f4.reg.f2r2 = cm_object_get_child_by_name(obj, "F2R2");
    state->u.f4.reg.f3r1 = cm_object_get_child_by_name(obj, "F3R1");
    state->u.f4.reg.f3r2 = cm_object_get_child_by_name(obj, "F3R2");
    state->u.f4.reg.f4r1 = cm_object_get_child_by_name(obj, "F4R1");
    state->u.f4.reg.f4r2 = cm_object_get_child_by_name(obj, "F4R2");
    state->u.f4.reg.f5r1 = cm_object_get_child_by_name(obj, "F5R1");
    state->u.f4.reg.f5r2 = cm_object_get_child_by_name(obj, "F5R2");
    state->u.f4.reg.f6r1 = cm_object_get_child_by_name(obj, "F6R1");
    state->u.f4.reg.f6r2 = cm_object_get_child_by_name(obj, "F6R2");
    state->u.f4.reg.f7r1 = cm_object_get_child_by_name(obj, "F7R1");
    state->u.f4.reg.f7r2 = cm_object_get_child_by_name(obj, "F7R2");
    state->u.f4.reg.f8r1 = cm_object_get_child_by_name(obj, "F8R1");
    state->u.f4.reg.f8r2 = cm_object_get_child_by_name(obj, "F8R2");
    state->u.f4.reg.f9r1 = cm_object_get_child_by_name(obj, "F9R1");
    state->u.f4.reg.f9r2 = cm_object_get_child_by_name(obj, "F9R2");
    state->u.f4.reg.f10r1 = cm_object_get_child_by_name(obj, "F10R1");
    state->u.f4.reg.f10r2 = cm_object_get_child_by_name(obj, "F10R2");
    state->u.f4.reg.f11r1 = cm_object_get_child_by_name(obj, "F11R1");
    state->u.f4.reg.f11r2 = cm_object_get_child_by_name(obj, "F11R2");
    state->u.f4.reg.f12r1 = cm_object_get_child_by_name(obj, "F12R1");
    state->u.f4.reg.f12r2 = cm_object_get_child_by_name(obj, "F12R2");
    state->u.f4.reg.f13r1 = cm_object_get_child_by_name(obj, "F13R1");
    state->u.f4.reg.f13r2 = cm_object_get_child_by_name(obj, "F13R2");
    state->u.f4.reg.f14r1 = cm_object_get_child_by_name(obj, "F14R1");
    state->u.f4.reg.f14r2 = cm_object_get_child_by_name(obj, "F14R2");
    state->u.f4.reg.f15r1 = cm_object_get_child_by_name(obj, "F15R1");
    state->u.f4.reg.f15r2 = cm_object_get_child_by_name(obj, "F15R2");
    state->u.f4.reg.f16r1 = cm_object_get_child_by_name(obj, "F16R1");
    state->u.f4.reg.f16r2 = cm_object_get_child_by_name(obj, "F16R2");
    state->u.f4.reg.f17r1 = cm_object_get_child_by_name(obj, "F17R1");
    state->u.f4.reg.f17r2 = cm_object_get_child_by_name(obj, "F17R2");
    state->u.f4.reg.f18r1 = cm_object_get_child_by_name(obj, "F18R1");
    state->u.f4.reg.f18r2 = cm_object_get_child_by_name(obj, "F18R2");
    state->u.f4.reg.f19r1 = cm_object_get_child_by_name(obj, "F19R1");
    state->u.f4.reg.f19r2 = cm_object_get_child_by_name(obj, "F19R2");
    state->u.f4.reg.f20r1 = cm_object_get_child_by_name(obj, "F20R1");
    state->u.f4.reg.f20r2 = cm_object_get_child_by_name(obj, "F20R2");
    state->u.f4.reg.f21r1 = cm_object_get_child_by_name(obj, "F21R1");
    state->u.f4.reg.f21r2 = cm_object_get_child_by_name(obj, "F21R2");
    state->u.f4.reg.f22r1 = cm_object_get_child_by_name(obj, "F22R1");
    state->u.f4.reg.f22r2 = cm_object_get_child_by_name(obj, "F22R2");
    state->u.f4.reg.f23r1 = cm_object_get_child_by_name(obj, "F23R1");
    state->u.f4.reg.f23r2 = cm_object_get_child_by_name(obj, "F23R2");
    state->u.f4.reg.f24r1 = cm_object_get_child_by_name(obj, "F24R1");
    state->u.f4.reg.f24r2 = cm_object_get_child_by_name(obj, "F24R2");
    state->u.f4.reg.f25r1 = cm_object_get_child_by_name(obj, "F25R1");
    state->u.f4.reg.f25r2 = cm_object_get_child_by_name(obj, "F25R2");
    state->u.f4.reg.f26r1 = cm_object_get_child_by_name(obj, "F26R1");
    state->u.f4.reg.f26r2 = cm_object_get_child_by_name(obj, "F26R2");
    state->u.f4.reg.f27r1 = cm_object_get_child_by_name(obj, "F27R1");
    state->u.f4.reg.f27r2 = cm_object_get_child_by_name(obj, "F27R2");
    
    
    // MCR bitfields.
    state->u.f4.fld.mcr.inrq = cm_object_get_child_by_name(state->u.f4.reg.mcr, "INRQ"); 
    state->u.f4.fld.mcr.sleep = cm_object_get_child_by_name(state->u.f4.reg.mcr, "SLEEP"); 
    state->u.f4.fld.mcr.txfp = cm_object_get_child_by_name(state->u.f4.reg.mcr, "TXFP"); 
    state->u.f4.fld.mcr.rflm = cm_object_get_child_by_name(state->u.f4.reg.mcr, "RFLM"); 
    state->u.f4.fld.mcr.nart = cm_object_get_child_by_name(state->u.f4.reg.mcr, "NART"); 
    state->u.f4.fld.mcr.awum = cm_object_get_child_by_name(state->u.f4.reg.mcr, "AWUM"); 
    state->u.f4.fld.mcr.abom = cm_object_get_child_by_name(state->u.f4.reg.mcr, "ABOM"); 
    state->u.f4.fld.mcr.ttcm = cm_object_get_child_by_name(state->u.f4.reg.mcr, "TTCM"); 
    state->u.f4.fld.mcr.reset = cm_object_get_child_by_name(state->u.f4.reg.mcr, "RESET"); 
    state->u.f4.fld.mcr.dbf = cm_object_get_child_by_name(state->u.f4.reg.mcr, "DBF");  
    
    // MSR bitfields.
    state->u.f4.fld.msr.inak = cm_object_get_child_by_name(state->u.f4.reg.msr, "INAK"); 
    state->u.f4.fld.msr.slak = cm_object_get_child_by_name(state->u.f4.reg.msr, "SLAK"); 
    state->u.f4.fld.msr.erri = cm_object_get_child_by_name(state->u.f4.reg.msr, "ERRI"); 
    state->u.f4.fld.msr.wkui = cm_object_get_child_by_name(state->u.f4.reg.msr, "WKUI"); 
    state->u.f4.fld.msr.slaki = cm_object_get_child_by_name(state->u.f4.reg.msr, "SLAKI"); 
    state->u.f4.fld.msr.txm = cm_object_get_child_by_name(state->u.f4.reg.msr, "TXM"); 
    state->u.f4.fld.msr.rxm = cm_object_get_child_by_name(state->u.f4.reg.msr, "RXM"); 
    state->u.f4.fld.msr.samp = cm_object_get_child_by_name(state->u.f4.reg.msr, "SAMP"); 
    state->u.f4.fld.msr.rx = cm_object_get_child_by_name(state->u.f4.reg.msr, "RX");  
    
    // TSR bitfields.
    state->u.f4.fld.tsr.rqcp0 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "RQCP0"); 
    state->u.f4.fld.tsr.txok0 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "TXOK0"); 
    state->u.f4.fld.tsr.alst0 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "ALST0"); 
    state->u.f4.fld.tsr.terr0 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "TERR0"); 
    state->u.f4.fld.tsr.abrq0 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "ABRQ0"); 
    state->u.f4.fld.tsr.rqcp1 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "RQCP1"); 
    state->u.f4.fld.tsr.txok1 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "TXOK1"); 
    state->u.f4.fld.tsr.alst1 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "ALST1"); 
    state->u.f4.fld.tsr.terr1 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "TERR1"); 
    state->u.f4.fld.tsr.abrq1 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "ABRQ1"); 
    state->u.f4.fld.tsr.rqcp2 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "RQCP2"); 
    state->u.f4.fld.tsr.txok2 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "TXOK2"); 
    state->u.f4.fld.tsr.alst2 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "ALST2"); 
    state->u.f4.fld.tsr.terr2 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "TERR2"); 
    state->u.f4.fld.tsr.abrq2 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "ABRQ2"); 
    state->u.f4.fld.tsr.code = cm_object_get_child_by_name(state->u.f4.reg.tsr, "CODE"); 
    state->u.f4.fld.tsr.tme0 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "TME0"); 
    state->u.f4.fld.tsr.tme1 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "TME1"); 
    state->u.f4.fld.tsr.tme2 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "TME2"); 
    state->u.f4.fld.tsr.low0 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "LOW0"); 
    state->u.f4.fld.tsr.low1 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "LOW1"); 
    state->u.f4.fld.tsr.low2 = cm_object_get_child_by_name(state->u.f4.reg.tsr, "LOW2");  
    
    // RF0R bitfields.
    state->u.f4.fld.rf0r.fmp0 = cm_object_get_child_by_name(state->u.f4.reg.rf0r, "FMP0"); 
    state->u.f4.fld.rf0r.full0 = cm_object_get_child_by_name(state->u.f4.reg.rf0r, "FULL0"); 
    state->u.f4.fld.rf0r.fovr0 = cm_object_get_child_by_name(state->u.f4.reg.rf0r, "FOVR0"); 
    state->u.f4.fld.rf0r.rfom0 = cm_object_get_child_by_name(state->u.f4.reg.rf0r, "RFOM0");  
    
    // RF1R bitfields.
    state->u.f4.fld.rf1r.fmp1 = cm_object_get_child_by_name(state->u.f4.reg.rf1r, "FMP1"); 
    state->u.f4.fld.rf1r.full1 = cm_object_get_child_by_name(state->u.f4.reg.rf1r, "FULL1"); 
    state->u.f4.fld.rf1r.fovr1 = cm_object_get_child_by_name(state->u.f4.reg.rf1r, "FOVR1"); 
    state->u.f4.fld.rf1r.rfom1 = cm_object_get_child_by_name(state->u.f4.reg.rf1r, "RFOM1");  
    
    // IER bitfields.
    state->u.f4.fld.ier.tmeie = cm_object_get_child_by_name(state->u.f4.reg.ier, "TMEIE"); 
    state->u.f4.fld.ier.fmpie0 = cm_object_get_child_by_name(state->u.f4.reg.ier, "FMPIE0"); 
    state->u.f4.fld.ier.ffie0 = cm_object_get_child_by_name(state->u.f4.reg.ier, "FFIE0"); 
    state->u.f4.fld.ier.fovie0 = cm_object_get_child_by_name(state->u.f4.reg.ier, "FOVIE0"); 
    state->u.f4.fld.ier.fmpie1 = cm_object_get_child_by_name(state->u.f4.reg.ier, "FMPIE1"); 
    state->u.f4.fld.ier.ffie1 = cm_object_get_child_by_name(state->u.f4.reg.ier, "FFIE1"); 
    state->u.f4.fld.ier.fovie1 = cm_object_get_child_by_name(state->u.f4.reg.ier, "FOVIE1"); 
    state->u.f4.fld.ier.ewgie = cm_object_get_child_by_name(state->u.f4.reg.ier, "EWGIE"); 
    state->u.f4.fld.ier.epvie = cm_object_get_child_by_name(state->u.f4.reg.ier, "EPVIE"); 
    state->u.f4.fld.ier.bofie = cm_object_get_child_by_name(state->u.f4.reg.ier, "BOFIE"); 
    state->u.f4.fld.ier.lecie = cm_object_get_child_by_name(state->u.f4.reg.ier, "LECIE"); 
    state->u.f4.fld.ier.errie = cm_object_get_child_by_name(state->u.f4.reg.ier, "ERRIE"); 
    state->u.f4.fld.ier.wkuie = cm_object_get_child_by_name(state->u.f4.reg.ier, "WKUIE"); 
    state->u.f4.fld.ier.slkie = cm_object_get_child_by_name(state->u.f4.reg.ier, "SLKIE");  
    
    // ESR bitfields.
    state->u.f4.fld.esr.ewgf = cm_object_get_child_by_name(state->u.f4.reg.esr, "EWGF"); 
    state->u.f4.fld.esr.epvf = cm_object_get_child_by_name(state->u.f4.reg.esr, "EPVF"); 
    state->u.f4.fld.esr.boff = cm_object_get_child_by_name(state->u.f4.reg.esr, "BOFF"); 
    state->u.f4.fld.esr.lec = cm_object_get_child_by_name(state->u.f4.reg.esr, "LEC"); 
    state->u.f4.fld.esr.tec = cm_object_get_child_by_name(state->u.f4.reg.esr, "TEC"); 
    state->u.f4.fld.esr.rec = cm_object_get_child_by_name(state->u.f4.reg.esr, "REC");  
    
    // BTR bitfields.
    state->u.f4.fld.btr.brp = cm_object_get_child_by_name(state->u.f4.reg.btr, "BRP"); 
    state->u.f4.fld.btr.ts1 = cm_object_get_child_by_name(state->u.f4.reg.btr, "TS1"); 
    state->u.f4.fld.btr.ts2 = cm_object_get_child_by_name(state->u.f4.reg.btr, "TS2"); 
    state->u.f4.fld.btr.sjw = cm_object_get_child_by_name(state->u.f4.reg.btr, "SJW"); 
    state->u.f4.fld.btr.lbkm = cm_object_get_child_by_name(state->u.f4.reg.btr, "LBKM"); 
    state->u.f4.fld.btr.silm = cm_object_get_child_by_name(state->u.f4.reg.btr, "SILM");  
    
    // TI0R bitfields.
    state->u.f4.fld.ti0r.txrq = cm_object_get_child_by_name(state->u.f4.reg.ti0r, "TXRQ"); 
    state->u.f4.fld.ti0r.rtr = cm_object_get_child_by_name(state->u.f4.reg.ti0r, "RTR"); 
    state->u.f4.fld.ti0r.ide = cm_object_get_child_by_name(state->u.f4.reg.ti0r, "IDE"); 
    state->u.f4.fld.ti0r.exid = cm_object_get_child_by_name(state->u.f4.reg.ti0r, "EXID"); 
    state->u.f4.fld.ti0r.stid = cm_object_get_child_by_name(state->u.f4.reg.ti0r, "STID");  
    
    // TDT0R bitfields.
    state->u.f4.fld.tdt0r.dlc = cm_object_get_child_by_name(state->u.f4.reg.tdt0r, "DLC"); 
    state->u.f4.fld.tdt0r.tgt = cm_object_get_child_by_name(state->u.f4.reg.tdt0r, "TGT"); 
    state->u.f4.fld.tdt0r.time = cm_object_get_child_by_name(state->u.f4.reg.tdt0r, "TIME");  
    
    // TDL0R bitfields.
    state->u.f4.fld.tdl0r.data0 = cm_object_get_child_by_name(state->u.f4.reg.tdl0r, "DATA0"); 
    state->u.f4.fld.tdl0r.data1 = cm_object_get_child_by_name(state->u.f4.reg.tdl0r, "DATA1"); 
    state->u.f4.fld.tdl0r.data2 = cm_object_get_child_by_name(state->u.f4.reg.tdl0r, "DATA2"); 
    state->u.f4.fld.tdl0r.data3 = cm_object_get_child_by_name(state->u.f4.reg.tdl0r, "DATA3");  
    
    // TDH0R bitfields.
    state->u.f4.fld.tdh0r.data4 = cm_object_get_child_by_name(state->u.f4.reg.tdh0r, "DATA4"); 
    state->u.f4.fld.tdh0r.data5 = cm_object_get_child_by_name(state->u.f4.reg.tdh0r, "DATA5"); 
    state->u.f4.fld.tdh0r.data6 = cm_object_get_child_by_name(state->u.f4.reg.tdh0r, "DATA6"); 
    state->u.f4.fld.tdh0r.data7 = cm_object_get_child_by_name(state->u.f4.reg.tdh0r, "DATA7");  
    
    // TI1R bitfields.
    state->u.f4.fld.ti1r.txrq = cm_object_get_child_by_name(state->u.f4.reg.ti1r, "TXRQ"); 
    state->u.f4.fld.ti1r.rtr = cm_object_get_child_by_name(state->u.f4.reg.ti1r, "RTR"); 
    state->u.f4.fld.ti1r.ide = cm_object_get_child_by_name(state->u.f4.reg.ti1r, "IDE"); 
    state->u.f4.fld.ti1r.exid = cm_object_get_child_by_name(state->u.f4.reg.ti1r, "EXID"); 
    state->u.f4.fld.ti1r.stid = cm_object_get_child_by_name(state->u.f4.reg.ti1r, "STID");  
    
    // TDT1R bitfields.
    state->u.f4.fld.tdt1r.dlc = cm_object_get_child_by_name(state->u.f4.reg.tdt1r, "DLC"); 
    state->u.f4.fld.tdt1r.tgt = cm_object_get_child_by_name(state->u.f4.reg.tdt1r, "TGT"); 
    state->u.f4.fld.tdt1r.time = cm_object_get_child_by_name(state->u.f4.reg.tdt1r, "TIME");  
    
    // TDL1R bitfields.
    state->u.f4.fld.tdl1r.data0 = cm_object_get_child_by_name(state->u.f4.reg.tdl1r, "DATA0"); 
    state->u.f4.fld.tdl1r.data1 = cm_object_get_child_by_name(state->u.f4.reg.tdl1r, "DATA1"); 
    state->u.f4.fld.tdl1r.data2 = cm_object_get_child_by_name(state->u.f4.reg.tdl1r, "DATA2"); 
    state->u.f4.fld.tdl1r.data3 = cm_object_get_child_by_name(state->u.f4.reg.tdl1r, "DATA3");  
    
    // TDH1R bitfields.
    state->u.f4.fld.tdh1r.data4 = cm_object_get_child_by_name(state->u.f4.reg.tdh1r, "DATA4"); 
    state->u.f4.fld.tdh1r.data5 = cm_object_get_child_by_name(state->u.f4.reg.tdh1r, "DATA5"); 
    state->u.f4.fld.tdh1r.data6 = cm_object_get_child_by_name(state->u.f4.reg.tdh1r, "DATA6"); 
    state->u.f4.fld.tdh1r.data7 = cm_object_get_child_by_name(state->u.f4.reg.tdh1r, "DATA7");  
    
    // TI2R bitfields.
    state->u.f4.fld.ti2r.txrq = cm_object_get_child_by_name(state->u.f4.reg.ti2r, "TXRQ"); 
    state->u.f4.fld.ti2r.rtr = cm_object_get_child_by_name(state->u.f4.reg.ti2r, "RTR"); 
    state->u.f4.fld.ti2r.ide = cm_object_get_child_by_name(state->u.f4.reg.ti2r, "IDE"); 
    state->u.f4.fld.ti2r.exid = cm_object_get_child_by_name(state->u.f4.reg.ti2r, "EXID"); 
    state->u.f4.fld.ti2r.stid = cm_object_get_child_by_name(state->u.f4.reg.ti2r, "STID");  
    
    // TDT2R bitfields.
    state->u.f4.fld.tdt2r.dlc = cm_object_get_child_by_name(state->u.f4.reg.tdt2r, "DLC"); 
    state->u.f4.fld.tdt2r.tgt = cm_object_get_child_by_name(state->u.f4.reg.tdt2r, "TGT"); 
    state->u.f4.fld.tdt2r.time = cm_object_get_child_by_name(state->u.f4.reg.tdt2r, "TIME");  
    
    // TDL2R bitfields.
    state->u.f4.fld.tdl2r.data0 = cm_object_get_child_by_name(state->u.f4.reg.tdl2r, "DATA0"); 
    state->u.f4.fld.tdl2r.data1 = cm_object_get_child_by_name(state->u.f4.reg.tdl2r, "DATA1"); 
    state->u.f4.fld.tdl2r.data2 = cm_object_get_child_by_name(state->u.f4.reg.tdl2r, "DATA2"); 
    state->u.f4.fld.tdl2r.data3 = cm_object_get_child_by_name(state->u.f4.reg.tdl2r, "DATA3");  
    
    // TDH2R bitfields.
    state->u.f4.fld.tdh2r.data4 = cm_object_get_child_by_name(state->u.f4.reg.tdh2r, "DATA4"); 
    state->u.f4.fld.tdh2r.data5 = cm_object_get_child_by_name(state->u.f4.reg.tdh2r, "DATA5"); 
    state->u.f4.fld.tdh2r.data6 = cm_object_get_child_by_name(state->u.f4.reg.tdh2r, "DATA6"); 
    state->u.f4.fld.tdh2r.data7 = cm_object_get_child_by_name(state->u.f4.reg.tdh2r, "DATA7");  
    
    // RI0R bitfields.
    state->u.f4.fld.ri0r.rtr = cm_object_get_child_by_name(state->u.f4.reg.ri0r, "RTR"); 
    state->u.f4.fld.ri0r.ide = cm_object_get_child_by_name(state->u.f4.reg.ri0r, "IDE"); 
    state->u.f4.fld.ri0r.exid = cm_object_get_child_by_name(state->u.f4.reg.ri0r, "EXID"); 
    state->u.f4.fld.ri0r.stid = cm_object_get_child_by_name(state->u.f4.reg.ri0r, "STID");  
    
    // RDT0R bitfields.
    state->u.f4.fld.rdt0r.dlc = cm_object_get_child_by_name(state->u.f4.reg.rdt0r, "DLC"); 
    state->u.f4.fld.rdt0r.fmi = cm_object_get_child_by_name(state->u.f4.reg.rdt0r, "FMI"); 
    state->u.f4.fld.rdt0r.time = cm_object_get_child_by_name(state->u.f4.reg.rdt0r, "TIME");  
    
    // RDL0R bitfields.
    state->u.f4.fld.rdl0r.data0 = cm_object_get_child_by_name(state->u.f4.reg.rdl0r, "DATA0"); 
    state->u.f4.fld.rdl0r.data1 = cm_object_get_child_by_name(state->u.f4.reg.rdl0r, "DATA1"); 
    state->u.f4.fld.rdl0r.data2 = cm_object_get_child_by_name(state->u.f4.reg.rdl0r, "DATA2"); 
    state->u.f4.fld.rdl0r.data3 = cm_object_get_child_by_name(state->u.f4.reg.rdl0r, "DATA3");  
    
    // RDH0R bitfields.
    state->u.f4.fld.rdh0r.data4 = cm_object_get_child_by_name(state->u.f4.reg.rdh0r, "DATA4"); 
    state->u.f4.fld.rdh0r.data5 = cm_object_get_child_by_name(state->u.f4.reg.rdh0r, "DATA5"); 
    state->u.f4.fld.rdh0r.data6 = cm_object_get_child_by_name(state->u.f4.reg.rdh0r, "DATA6"); 
    state->u.f4.fld.rdh0r.data7 = cm_object_get_child_by_name(state->u.f4.reg.rdh0r, "DATA7");  
    
    // RI1R bitfields.
    state->u.f4.fld.ri1r.rtr = cm_object_get_child_by_name(state->u.f4.reg.ri1r, "RTR"); 
    state->u.f4.fld.ri1r.ide = cm_object_get_child_by_name(state->u.f4.reg.ri1r, "IDE"); 
    state->u.f4.fld.ri1r.exid = cm_object_get_child_by_name(state->u.f4.reg.ri1r, "EXID"); 
    state->u.f4.fld.ri1r.stid = cm_object_get_child_by_name(state->u.f4.reg.ri1r, "STID");  
    
    // RDT1R bitfields.
    state->u.f4.fld.rdt1r.dlc = cm_object_get_child_by_name(state->u.f4.reg.rdt1r, "DLC"); 
    state->u.f4.fld.rdt1r.fmi = cm_object_get_child_by_name(state->u.f4.reg.rdt1r, "FMI"); 
    state->u.f4.fld.rdt1r.time = cm_object_get_child_by_name(state->u.f4.reg.rdt1r, "TIME");  
    
    // RDL1R bitfields.
    state->u.f4.fld.rdl1r.data0 = cm_object_get_child_by_name(state->u.f4.reg.rdl1r, "DATA0"); 
    state->u.f4.fld.rdl1r.data1 = cm_object_get_child_by_name(state->u.f4.reg.rdl1r, "DATA1"); 
    state->u.f4.fld.rdl1r.data2 = cm_object_get_child_by_name(state->u.f4.reg.rdl1r, "DATA2"); 
    state->u.f4.fld.rdl1r.data3 = cm_object_get_child_by_name(state->u.f4.reg.rdl1r, "DATA3");  
    
    // RDH1R bitfields.
    state->u.f4.fld.rdh1r.data4 = cm_object_get_child_by_name(state->u.f4.reg.rdh1r, "DATA4"); 
    state->u.f4.fld.rdh1r.data5 = cm_object_get_child_by_name(state->u.f4.reg.rdh1r, "DATA5"); 
    state->u.f4.fld.rdh1r.data6 = cm_object_get_child_by_name(state->u.f4.reg.rdh1r, "DATA6"); 
    state->u.f4.fld.rdh1r.data7 = cm_object_get_child_by_name(state->u.f4.reg.rdh1r, "DATA7");  
    
    // FMR bitfields.
    state->u.f4.fld.fmr.finit = cm_object_get_child_by_name(state->u.f4.reg.fmr, "FINIT"); 
    state->u.f4.fld.fmr.can2sb = cm_object_get_child_by_name(state->u.f4.reg.fmr, "CAN2SB");  
    
    // FM1R bitfields.
    state->u.f4.fld.fm1r.fbm0 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM0"); 
    state->u.f4.fld.fm1r.fbm1 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM1"); 
    state->u.f4.fld.fm1r.fbm2 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM2"); 
    state->u.f4.fld.fm1r.fbm3 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM3"); 
    state->u.f4.fld.fm1r.fbm4 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM4"); 
    state->u.f4.fld.fm1r.fbm5 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM5"); 
    state->u.f4.fld.fm1r.fbm6 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM6"); 
    state->u.f4.fld.fm1r.fbm7 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM7"); 
    state->u.f4.fld.fm1r.fbm8 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM8"); 
    state->u.f4.fld.fm1r.fbm9 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM9"); 
    state->u.f4.fld.fm1r.fbm10 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM10"); 
    state->u.f4.fld.fm1r.fbm11 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM11"); 
    state->u.f4.fld.fm1r.fbm12 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM12"); 
    state->u.f4.fld.fm1r.fbm13 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM13"); 
    state->u.f4.fld.fm1r.fbm14 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM14"); 
    state->u.f4.fld.fm1r.fbm15 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM15"); 
    state->u.f4.fld.fm1r.fbm16 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM16"); 
    state->u.f4.fld.fm1r.fbm17 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM17"); 
    state->u.f4.fld.fm1r.fbm18 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM18"); 
    state->u.f4.fld.fm1r.fbm19 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM19"); 
    state->u.f4.fld.fm1r.fbm20 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM20"); 
    state->u.f4.fld.fm1r.fbm21 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM21"); 
    state->u.f4.fld.fm1r.fbm22 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM22"); 
    state->u.f4.fld.fm1r.fbm23 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM23"); 
    state->u.f4.fld.fm1r.fbm24 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM24"); 
    state->u.f4.fld.fm1r.fbm25 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM25"); 
    state->u.f4.fld.fm1r.fbm26 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM26"); 
    state->u.f4.fld.fm1r.fbm27 = cm_object_get_child_by_name(state->u.f4.reg.fm1r, "FBM27");  
    
    // FS1R bitfields.
    state->u.f4.fld.fs1r.fsc0 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC0"); 
    state->u.f4.fld.fs1r.fsc1 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC1"); 
    state->u.f4.fld.fs1r.fsc2 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC2"); 
    state->u.f4.fld.fs1r.fsc3 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC3"); 
    state->u.f4.fld.fs1r.fsc4 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC4"); 
    state->u.f4.fld.fs1r.fsc5 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC5"); 
    state->u.f4.fld.fs1r.fsc6 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC6"); 
    state->u.f4.fld.fs1r.fsc7 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC7"); 
    state->u.f4.fld.fs1r.fsc8 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC8"); 
    state->u.f4.fld.fs1r.fsc9 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC9"); 
    state->u.f4.fld.fs1r.fsc10 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC10"); 
    state->u.f4.fld.fs1r.fsc11 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC11"); 
    state->u.f4.fld.fs1r.fsc12 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC12"); 
    state->u.f4.fld.fs1r.fsc13 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC13"); 
    state->u.f4.fld.fs1r.fsc14 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC14"); 
    state->u.f4.fld.fs1r.fsc15 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC15"); 
    state->u.f4.fld.fs1r.fsc16 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC16"); 
    state->u.f4.fld.fs1r.fsc17 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC17"); 
    state->u.f4.fld.fs1r.fsc18 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC18"); 
    state->u.f4.fld.fs1r.fsc19 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC19"); 
    state->u.f4.fld.fs1r.fsc20 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC20"); 
    state->u.f4.fld.fs1r.fsc21 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC21"); 
    state->u.f4.fld.fs1r.fsc22 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC22"); 
    state->u.f4.fld.fs1r.fsc23 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC23"); 
    state->u.f4.fld.fs1r.fsc24 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC24"); 
    state->u.f4.fld.fs1r.fsc25 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC25"); 
    state->u.f4.fld.fs1r.fsc26 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC26"); 
    state->u.f4.fld.fs1r.fsc27 = cm_object_get_child_by_name(state->u.f4.reg.fs1r, "FSC27");  
    
    // FFA1R bitfields.
    state->u.f4.fld.ffa1r.ffa0 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA0"); 
    state->u.f4.fld.ffa1r.ffa1 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA1"); 
    state->u.f4.fld.ffa1r.ffa2 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA2"); 
    state->u.f4.fld.ffa1r.ffa3 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA3"); 
    state->u.f4.fld.ffa1r.ffa4 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA4"); 
    state->u.f4.fld.ffa1r.ffa5 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA5"); 
    state->u.f4.fld.ffa1r.ffa6 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA6"); 
    state->u.f4.fld.ffa1r.ffa7 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA7"); 
    state->u.f4.fld.ffa1r.ffa8 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA8"); 
    state->u.f4.fld.ffa1r.ffa9 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA9"); 
    state->u.f4.fld.ffa1r.ffa10 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA10"); 
    state->u.f4.fld.ffa1r.ffa11 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA11"); 
    state->u.f4.fld.ffa1r.ffa12 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA12"); 
    state->u.f4.fld.ffa1r.ffa13 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA13"); 
    state->u.f4.fld.ffa1r.ffa14 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA14"); 
    state->u.f4.fld.ffa1r.ffa15 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA15"); 
    state->u.f4.fld.ffa1r.ffa16 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA16"); 
    state->u.f4.fld.ffa1r.ffa17 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA17"); 
    state->u.f4.fld.ffa1r.ffa18 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA18"); 
    state->u.f4.fld.ffa1r.ffa19 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA19"); 
    state->u.f4.fld.ffa1r.ffa20 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA20"); 
    state->u.f4.fld.ffa1r.ffa21 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA21"); 
    state->u.f4.fld.ffa1r.ffa22 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA22"); 
    state->u.f4.fld.ffa1r.ffa23 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA23"); 
    state->u.f4.fld.ffa1r.ffa24 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA24"); 
    state->u.f4.fld.ffa1r.ffa25 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA25"); 
    state->u.f4.fld.ffa1r.ffa26 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA26"); 
    state->u.f4.fld.ffa1r.ffa27 = cm_object_get_child_by_name(state->u.f4.reg.ffa1r, "FFA27");  
    
    // FA1R bitfields.
    state->u.f4.fld.fa1r.fact0 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT0"); 
    state->u.f4.fld.fa1r.fact1 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT1"); 
    state->u.f4.fld.fa1r.fact2 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT2"); 
    state->u.f4.fld.fa1r.fact3 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT3"); 
    state->u.f4.fld.fa1r.fact4 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT4"); 
    state->u.f4.fld.fa1r.fact5 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT5"); 
    state->u.f4.fld.fa1r.fact6 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT6"); 
    state->u.f4.fld.fa1r.fact7 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT7"); 
    state->u.f4.fld.fa1r.fact8 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT8"); 
    state->u.f4.fld.fa1r.fact9 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT9"); 
    state->u.f4.fld.fa1r.fact10 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT10"); 
    state->u.f4.fld.fa1r.fact11 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT11"); 
    state->u.f4.fld.fa1r.fact12 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT12"); 
    state->u.f4.fld.fa1r.fact13 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT13"); 
    state->u.f4.fld.fa1r.fact14 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT14"); 
    state->u.f4.fld.fa1r.fact15 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT15"); 
    state->u.f4.fld.fa1r.fact16 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT16"); 
    state->u.f4.fld.fa1r.fact17 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT17"); 
    state->u.f4.fld.fa1r.fact18 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT18"); 
    state->u.f4.fld.fa1r.fact19 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT19"); 
    state->u.f4.fld.fa1r.fact20 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT20"); 
    state->u.f4.fld.fa1r.fact21 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT21"); 
    state->u.f4.fld.fa1r.fact22 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT22"); 
    state->u.f4.fld.fa1r.fact23 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT23"); 
    state->u.f4.fld.fa1r.fact24 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT24"); 
    state->u.f4.fld.fa1r.fact25 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT25"); 
    state->u.f4.fld.fa1r.fact26 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT26"); 
    state->u.f4.fld.fa1r.fact27 = cm_object_get_child_by_name(state->u.f4.reg.fa1r, "FACT27");  
    
    // F0R1 bitfields.
    state->u.f4.fld.f0r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB0"); 
    state->u.f4.fld.f0r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB1"); 
    state->u.f4.fld.f0r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB2"); 
    state->u.f4.fld.f0r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB3"); 
    state->u.f4.fld.f0r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB4"); 
    state->u.f4.fld.f0r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB5"); 
    state->u.f4.fld.f0r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB6"); 
    state->u.f4.fld.f0r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB7"); 
    state->u.f4.fld.f0r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB8"); 
    state->u.f4.fld.f0r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB9"); 
    state->u.f4.fld.f0r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB10"); 
    state->u.f4.fld.f0r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB11"); 
    state->u.f4.fld.f0r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB12"); 
    state->u.f4.fld.f0r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB13"); 
    state->u.f4.fld.f0r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB14"); 
    state->u.f4.fld.f0r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB15"); 
    state->u.f4.fld.f0r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB16"); 
    state->u.f4.fld.f0r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB17"); 
    state->u.f4.fld.f0r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB18"); 
    state->u.f4.fld.f0r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB19"); 
    state->u.f4.fld.f0r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB20"); 
    state->u.f4.fld.f0r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB21"); 
    state->u.f4.fld.f0r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB22"); 
    state->u.f4.fld.f0r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB23"); 
    state->u.f4.fld.f0r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB24"); 
    state->u.f4.fld.f0r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB25"); 
    state->u.f4.fld.f0r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB26"); 
    state->u.f4.fld.f0r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB27"); 
    state->u.f4.fld.f0r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB28"); 
    state->u.f4.fld.f0r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB29"); 
    state->u.f4.fld.f0r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB30"); 
    state->u.f4.fld.f0r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f0r1, "FB31");  
    
    // F0R2 bitfields.
    state->u.f4.fld.f0r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB0"); 
    state->u.f4.fld.f0r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB1"); 
    state->u.f4.fld.f0r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB2"); 
    state->u.f4.fld.f0r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB3"); 
    state->u.f4.fld.f0r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB4"); 
    state->u.f4.fld.f0r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB5"); 
    state->u.f4.fld.f0r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB6"); 
    state->u.f4.fld.f0r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB7"); 
    state->u.f4.fld.f0r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB8"); 
    state->u.f4.fld.f0r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB9"); 
    state->u.f4.fld.f0r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB10"); 
    state->u.f4.fld.f0r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB11"); 
    state->u.f4.fld.f0r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB12"); 
    state->u.f4.fld.f0r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB13"); 
    state->u.f4.fld.f0r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB14"); 
    state->u.f4.fld.f0r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB15"); 
    state->u.f4.fld.f0r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB16"); 
    state->u.f4.fld.f0r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB17"); 
    state->u.f4.fld.f0r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB18"); 
    state->u.f4.fld.f0r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB19"); 
    state->u.f4.fld.f0r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB20"); 
    state->u.f4.fld.f0r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB21"); 
    state->u.f4.fld.f0r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB22"); 
    state->u.f4.fld.f0r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB23"); 
    state->u.f4.fld.f0r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB24"); 
    state->u.f4.fld.f0r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB25"); 
    state->u.f4.fld.f0r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB26"); 
    state->u.f4.fld.f0r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB27"); 
    state->u.f4.fld.f0r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB28"); 
    state->u.f4.fld.f0r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB29"); 
    state->u.f4.fld.f0r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB30"); 
    state->u.f4.fld.f0r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f0r2, "FB31");  
    
    // F1R1 bitfields.
    state->u.f4.fld.f1r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB0"); 
    state->u.f4.fld.f1r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB1"); 
    state->u.f4.fld.f1r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB2"); 
    state->u.f4.fld.f1r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB3"); 
    state->u.f4.fld.f1r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB4"); 
    state->u.f4.fld.f1r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB5"); 
    state->u.f4.fld.f1r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB6"); 
    state->u.f4.fld.f1r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB7"); 
    state->u.f4.fld.f1r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB8"); 
    state->u.f4.fld.f1r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB9"); 
    state->u.f4.fld.f1r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB10"); 
    state->u.f4.fld.f1r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB11"); 
    state->u.f4.fld.f1r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB12"); 
    state->u.f4.fld.f1r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB13"); 
    state->u.f4.fld.f1r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB14"); 
    state->u.f4.fld.f1r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB15"); 
    state->u.f4.fld.f1r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB16"); 
    state->u.f4.fld.f1r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB17"); 
    state->u.f4.fld.f1r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB18"); 
    state->u.f4.fld.f1r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB19"); 
    state->u.f4.fld.f1r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB20"); 
    state->u.f4.fld.f1r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB21"); 
    state->u.f4.fld.f1r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB22"); 
    state->u.f4.fld.f1r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB23"); 
    state->u.f4.fld.f1r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB24"); 
    state->u.f4.fld.f1r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB25"); 
    state->u.f4.fld.f1r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB26"); 
    state->u.f4.fld.f1r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB27"); 
    state->u.f4.fld.f1r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB28"); 
    state->u.f4.fld.f1r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB29"); 
    state->u.f4.fld.f1r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB30"); 
    state->u.f4.fld.f1r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f1r1, "FB31");  
    
    // F1R2 bitfields.
    state->u.f4.fld.f1r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB0"); 
    state->u.f4.fld.f1r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB1"); 
    state->u.f4.fld.f1r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB2"); 
    state->u.f4.fld.f1r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB3"); 
    state->u.f4.fld.f1r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB4"); 
    state->u.f4.fld.f1r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB5"); 
    state->u.f4.fld.f1r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB6"); 
    state->u.f4.fld.f1r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB7"); 
    state->u.f4.fld.f1r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB8"); 
    state->u.f4.fld.f1r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB9"); 
    state->u.f4.fld.f1r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB10"); 
    state->u.f4.fld.f1r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB11"); 
    state->u.f4.fld.f1r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB12"); 
    state->u.f4.fld.f1r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB13"); 
    state->u.f4.fld.f1r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB14"); 
    state->u.f4.fld.f1r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB15"); 
    state->u.f4.fld.f1r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB16"); 
    state->u.f4.fld.f1r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB17"); 
    state->u.f4.fld.f1r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB18"); 
    state->u.f4.fld.f1r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB19"); 
    state->u.f4.fld.f1r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB20"); 
    state->u.f4.fld.f1r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB21"); 
    state->u.f4.fld.f1r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB22"); 
    state->u.f4.fld.f1r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB23"); 
    state->u.f4.fld.f1r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB24"); 
    state->u.f4.fld.f1r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB25"); 
    state->u.f4.fld.f1r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB26"); 
    state->u.f4.fld.f1r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB27"); 
    state->u.f4.fld.f1r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB28"); 
    state->u.f4.fld.f1r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB29"); 
    state->u.f4.fld.f1r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB30"); 
    state->u.f4.fld.f1r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f1r2, "FB31");  
    
    // F2R1 bitfields.
    state->u.f4.fld.f2r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB0"); 
    state->u.f4.fld.f2r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB1"); 
    state->u.f4.fld.f2r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB2"); 
    state->u.f4.fld.f2r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB3"); 
    state->u.f4.fld.f2r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB4"); 
    state->u.f4.fld.f2r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB5"); 
    state->u.f4.fld.f2r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB6"); 
    state->u.f4.fld.f2r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB7"); 
    state->u.f4.fld.f2r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB8"); 
    state->u.f4.fld.f2r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB9"); 
    state->u.f4.fld.f2r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB10"); 
    state->u.f4.fld.f2r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB11"); 
    state->u.f4.fld.f2r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB12"); 
    state->u.f4.fld.f2r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB13"); 
    state->u.f4.fld.f2r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB14"); 
    state->u.f4.fld.f2r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB15"); 
    state->u.f4.fld.f2r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB16"); 
    state->u.f4.fld.f2r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB17"); 
    state->u.f4.fld.f2r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB18"); 
    state->u.f4.fld.f2r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB19"); 
    state->u.f4.fld.f2r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB20"); 
    state->u.f4.fld.f2r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB21"); 
    state->u.f4.fld.f2r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB22"); 
    state->u.f4.fld.f2r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB23"); 
    state->u.f4.fld.f2r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB24"); 
    state->u.f4.fld.f2r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB25"); 
    state->u.f4.fld.f2r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB26"); 
    state->u.f4.fld.f2r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB27"); 
    state->u.f4.fld.f2r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB28"); 
    state->u.f4.fld.f2r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB29"); 
    state->u.f4.fld.f2r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB30"); 
    state->u.f4.fld.f2r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f2r1, "FB31");  
    
    // F2R2 bitfields.
    state->u.f4.fld.f2r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB0"); 
    state->u.f4.fld.f2r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB1"); 
    state->u.f4.fld.f2r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB2"); 
    state->u.f4.fld.f2r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB3"); 
    state->u.f4.fld.f2r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB4"); 
    state->u.f4.fld.f2r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB5"); 
    state->u.f4.fld.f2r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB6"); 
    state->u.f4.fld.f2r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB7"); 
    state->u.f4.fld.f2r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB8"); 
    state->u.f4.fld.f2r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB9"); 
    state->u.f4.fld.f2r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB10"); 
    state->u.f4.fld.f2r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB11"); 
    state->u.f4.fld.f2r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB12"); 
    state->u.f4.fld.f2r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB13"); 
    state->u.f4.fld.f2r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB14"); 
    state->u.f4.fld.f2r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB15"); 
    state->u.f4.fld.f2r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB16"); 
    state->u.f4.fld.f2r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB17"); 
    state->u.f4.fld.f2r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB18"); 
    state->u.f4.fld.f2r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB19"); 
    state->u.f4.fld.f2r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB20"); 
    state->u.f4.fld.f2r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB21"); 
    state->u.f4.fld.f2r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB22"); 
    state->u.f4.fld.f2r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB23"); 
    state->u.f4.fld.f2r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB24"); 
    state->u.f4.fld.f2r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB25"); 
    state->u.f4.fld.f2r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB26"); 
    state->u.f4.fld.f2r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB27"); 
    state->u.f4.fld.f2r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB28"); 
    state->u.f4.fld.f2r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB29"); 
    state->u.f4.fld.f2r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB30"); 
    state->u.f4.fld.f2r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f2r2, "FB31");  
    
    // F3R1 bitfields.
    state->u.f4.fld.f3r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB0"); 
    state->u.f4.fld.f3r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB1"); 
    state->u.f4.fld.f3r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB2"); 
    state->u.f4.fld.f3r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB3"); 
    state->u.f4.fld.f3r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB4"); 
    state->u.f4.fld.f3r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB5"); 
    state->u.f4.fld.f3r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB6"); 
    state->u.f4.fld.f3r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB7"); 
    state->u.f4.fld.f3r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB8"); 
    state->u.f4.fld.f3r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB9"); 
    state->u.f4.fld.f3r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB10"); 
    state->u.f4.fld.f3r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB11"); 
    state->u.f4.fld.f3r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB12"); 
    state->u.f4.fld.f3r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB13"); 
    state->u.f4.fld.f3r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB14"); 
    state->u.f4.fld.f3r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB15"); 
    state->u.f4.fld.f3r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB16"); 
    state->u.f4.fld.f3r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB17"); 
    state->u.f4.fld.f3r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB18"); 
    state->u.f4.fld.f3r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB19"); 
    state->u.f4.fld.f3r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB20"); 
    state->u.f4.fld.f3r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB21"); 
    state->u.f4.fld.f3r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB22"); 
    state->u.f4.fld.f3r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB23"); 
    state->u.f4.fld.f3r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB24"); 
    state->u.f4.fld.f3r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB25"); 
    state->u.f4.fld.f3r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB26"); 
    state->u.f4.fld.f3r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB27"); 
    state->u.f4.fld.f3r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB28"); 
    state->u.f4.fld.f3r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB29"); 
    state->u.f4.fld.f3r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB30"); 
    state->u.f4.fld.f3r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f3r1, "FB31");  
    
    // F3R2 bitfields.
    state->u.f4.fld.f3r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB0"); 
    state->u.f4.fld.f3r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB1"); 
    state->u.f4.fld.f3r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB2"); 
    state->u.f4.fld.f3r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB3"); 
    state->u.f4.fld.f3r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB4"); 
    state->u.f4.fld.f3r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB5"); 
    state->u.f4.fld.f3r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB6"); 
    state->u.f4.fld.f3r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB7"); 
    state->u.f4.fld.f3r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB8"); 
    state->u.f4.fld.f3r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB9"); 
    state->u.f4.fld.f3r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB10"); 
    state->u.f4.fld.f3r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB11"); 
    state->u.f4.fld.f3r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB12"); 
    state->u.f4.fld.f3r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB13"); 
    state->u.f4.fld.f3r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB14"); 
    state->u.f4.fld.f3r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB15"); 
    state->u.f4.fld.f3r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB16"); 
    state->u.f4.fld.f3r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB17"); 
    state->u.f4.fld.f3r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB18"); 
    state->u.f4.fld.f3r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB19"); 
    state->u.f4.fld.f3r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB20"); 
    state->u.f4.fld.f3r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB21"); 
    state->u.f4.fld.f3r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB22"); 
    state->u.f4.fld.f3r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB23"); 
    state->u.f4.fld.f3r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB24"); 
    state->u.f4.fld.f3r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB25"); 
    state->u.f4.fld.f3r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB26"); 
    state->u.f4.fld.f3r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB27"); 
    state->u.f4.fld.f3r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB28"); 
    state->u.f4.fld.f3r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB29"); 
    state->u.f4.fld.f3r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB30"); 
    state->u.f4.fld.f3r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f3r2, "FB31");  
    
    // F4R1 bitfields.
    state->u.f4.fld.f4r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB0"); 
    state->u.f4.fld.f4r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB1"); 
    state->u.f4.fld.f4r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB2"); 
    state->u.f4.fld.f4r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB3"); 
    state->u.f4.fld.f4r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB4"); 
    state->u.f4.fld.f4r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB5"); 
    state->u.f4.fld.f4r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB6"); 
    state->u.f4.fld.f4r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB7"); 
    state->u.f4.fld.f4r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB8"); 
    state->u.f4.fld.f4r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB9"); 
    state->u.f4.fld.f4r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB10"); 
    state->u.f4.fld.f4r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB11"); 
    state->u.f4.fld.f4r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB12"); 
    state->u.f4.fld.f4r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB13"); 
    state->u.f4.fld.f4r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB14"); 
    state->u.f4.fld.f4r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB15"); 
    state->u.f4.fld.f4r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB16"); 
    state->u.f4.fld.f4r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB17"); 
    state->u.f4.fld.f4r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB18"); 
    state->u.f4.fld.f4r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB19"); 
    state->u.f4.fld.f4r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB20"); 
    state->u.f4.fld.f4r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB21"); 
    state->u.f4.fld.f4r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB22"); 
    state->u.f4.fld.f4r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB23"); 
    state->u.f4.fld.f4r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB24"); 
    state->u.f4.fld.f4r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB25"); 
    state->u.f4.fld.f4r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB26"); 
    state->u.f4.fld.f4r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB27"); 
    state->u.f4.fld.f4r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB28"); 
    state->u.f4.fld.f4r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB29"); 
    state->u.f4.fld.f4r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB30"); 
    state->u.f4.fld.f4r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f4r1, "FB31");  
    
    // F4R2 bitfields.
    state->u.f4.fld.f4r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB0"); 
    state->u.f4.fld.f4r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB1"); 
    state->u.f4.fld.f4r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB2"); 
    state->u.f4.fld.f4r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB3"); 
    state->u.f4.fld.f4r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB4"); 
    state->u.f4.fld.f4r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB5"); 
    state->u.f4.fld.f4r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB6"); 
    state->u.f4.fld.f4r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB7"); 
    state->u.f4.fld.f4r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB8"); 
    state->u.f4.fld.f4r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB9"); 
    state->u.f4.fld.f4r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB10"); 
    state->u.f4.fld.f4r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB11"); 
    state->u.f4.fld.f4r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB12"); 
    state->u.f4.fld.f4r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB13"); 
    state->u.f4.fld.f4r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB14"); 
    state->u.f4.fld.f4r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB15"); 
    state->u.f4.fld.f4r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB16"); 
    state->u.f4.fld.f4r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB17"); 
    state->u.f4.fld.f4r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB18"); 
    state->u.f4.fld.f4r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB19"); 
    state->u.f4.fld.f4r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB20"); 
    state->u.f4.fld.f4r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB21"); 
    state->u.f4.fld.f4r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB22"); 
    state->u.f4.fld.f4r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB23"); 
    state->u.f4.fld.f4r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB24"); 
    state->u.f4.fld.f4r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB25"); 
    state->u.f4.fld.f4r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB26"); 
    state->u.f4.fld.f4r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB27"); 
    state->u.f4.fld.f4r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB28"); 
    state->u.f4.fld.f4r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB29"); 
    state->u.f4.fld.f4r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB30"); 
    state->u.f4.fld.f4r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f4r2, "FB31");  
    
    // F5R1 bitfields.
    state->u.f4.fld.f5r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB0"); 
    state->u.f4.fld.f5r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB1"); 
    state->u.f4.fld.f5r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB2"); 
    state->u.f4.fld.f5r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB3"); 
    state->u.f4.fld.f5r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB4"); 
    state->u.f4.fld.f5r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB5"); 
    state->u.f4.fld.f5r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB6"); 
    state->u.f4.fld.f5r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB7"); 
    state->u.f4.fld.f5r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB8"); 
    state->u.f4.fld.f5r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB9"); 
    state->u.f4.fld.f5r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB10"); 
    state->u.f4.fld.f5r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB11"); 
    state->u.f4.fld.f5r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB12"); 
    state->u.f4.fld.f5r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB13"); 
    state->u.f4.fld.f5r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB14"); 
    state->u.f4.fld.f5r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB15"); 
    state->u.f4.fld.f5r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB16"); 
    state->u.f4.fld.f5r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB17"); 
    state->u.f4.fld.f5r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB18"); 
    state->u.f4.fld.f5r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB19"); 
    state->u.f4.fld.f5r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB20"); 
    state->u.f4.fld.f5r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB21"); 
    state->u.f4.fld.f5r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB22"); 
    state->u.f4.fld.f5r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB23"); 
    state->u.f4.fld.f5r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB24"); 
    state->u.f4.fld.f5r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB25"); 
    state->u.f4.fld.f5r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB26"); 
    state->u.f4.fld.f5r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB27"); 
    state->u.f4.fld.f5r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB28"); 
    state->u.f4.fld.f5r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB29"); 
    state->u.f4.fld.f5r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB30"); 
    state->u.f4.fld.f5r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f5r1, "FB31");  
    
    // F5R2 bitfields.
    state->u.f4.fld.f5r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB0"); 
    state->u.f4.fld.f5r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB1"); 
    state->u.f4.fld.f5r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB2"); 
    state->u.f4.fld.f5r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB3"); 
    state->u.f4.fld.f5r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB4"); 
    state->u.f4.fld.f5r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB5"); 
    state->u.f4.fld.f5r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB6"); 
    state->u.f4.fld.f5r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB7"); 
    state->u.f4.fld.f5r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB8"); 
    state->u.f4.fld.f5r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB9"); 
    state->u.f4.fld.f5r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB10"); 
    state->u.f4.fld.f5r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB11"); 
    state->u.f4.fld.f5r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB12"); 
    state->u.f4.fld.f5r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB13"); 
    state->u.f4.fld.f5r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB14"); 
    state->u.f4.fld.f5r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB15"); 
    state->u.f4.fld.f5r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB16"); 
    state->u.f4.fld.f5r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB17"); 
    state->u.f4.fld.f5r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB18"); 
    state->u.f4.fld.f5r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB19"); 
    state->u.f4.fld.f5r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB20"); 
    state->u.f4.fld.f5r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB21"); 
    state->u.f4.fld.f5r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB22"); 
    state->u.f4.fld.f5r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB23"); 
    state->u.f4.fld.f5r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB24"); 
    state->u.f4.fld.f5r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB25"); 
    state->u.f4.fld.f5r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB26"); 
    state->u.f4.fld.f5r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB27"); 
    state->u.f4.fld.f5r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB28"); 
    state->u.f4.fld.f5r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB29"); 
    state->u.f4.fld.f5r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB30"); 
    state->u.f4.fld.f5r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f5r2, "FB31");  
    
    // F6R1 bitfields.
    state->u.f4.fld.f6r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB0"); 
    state->u.f4.fld.f6r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB1"); 
    state->u.f4.fld.f6r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB2"); 
    state->u.f4.fld.f6r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB3"); 
    state->u.f4.fld.f6r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB4"); 
    state->u.f4.fld.f6r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB5"); 
    state->u.f4.fld.f6r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB6"); 
    state->u.f4.fld.f6r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB7"); 
    state->u.f4.fld.f6r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB8"); 
    state->u.f4.fld.f6r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB9"); 
    state->u.f4.fld.f6r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB10"); 
    state->u.f4.fld.f6r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB11"); 
    state->u.f4.fld.f6r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB12"); 
    state->u.f4.fld.f6r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB13"); 
    state->u.f4.fld.f6r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB14"); 
    state->u.f4.fld.f6r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB15"); 
    state->u.f4.fld.f6r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB16"); 
    state->u.f4.fld.f6r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB17"); 
    state->u.f4.fld.f6r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB18"); 
    state->u.f4.fld.f6r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB19"); 
    state->u.f4.fld.f6r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB20"); 
    state->u.f4.fld.f6r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB21"); 
    state->u.f4.fld.f6r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB22"); 
    state->u.f4.fld.f6r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB23"); 
    state->u.f4.fld.f6r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB24"); 
    state->u.f4.fld.f6r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB25"); 
    state->u.f4.fld.f6r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB26"); 
    state->u.f4.fld.f6r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB27"); 
    state->u.f4.fld.f6r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB28"); 
    state->u.f4.fld.f6r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB29"); 
    state->u.f4.fld.f6r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB30"); 
    state->u.f4.fld.f6r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f6r1, "FB31");  
    
    // F6R2 bitfields.
    state->u.f4.fld.f6r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB0"); 
    state->u.f4.fld.f6r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB1"); 
    state->u.f4.fld.f6r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB2"); 
    state->u.f4.fld.f6r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB3"); 
    state->u.f4.fld.f6r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB4"); 
    state->u.f4.fld.f6r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB5"); 
    state->u.f4.fld.f6r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB6"); 
    state->u.f4.fld.f6r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB7"); 
    state->u.f4.fld.f6r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB8"); 
    state->u.f4.fld.f6r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB9"); 
    state->u.f4.fld.f6r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB10"); 
    state->u.f4.fld.f6r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB11"); 
    state->u.f4.fld.f6r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB12"); 
    state->u.f4.fld.f6r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB13"); 
    state->u.f4.fld.f6r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB14"); 
    state->u.f4.fld.f6r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB15"); 
    state->u.f4.fld.f6r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB16"); 
    state->u.f4.fld.f6r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB17"); 
    state->u.f4.fld.f6r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB18"); 
    state->u.f4.fld.f6r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB19"); 
    state->u.f4.fld.f6r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB20"); 
    state->u.f4.fld.f6r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB21"); 
    state->u.f4.fld.f6r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB22"); 
    state->u.f4.fld.f6r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB23"); 
    state->u.f4.fld.f6r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB24"); 
    state->u.f4.fld.f6r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB25"); 
    state->u.f4.fld.f6r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB26"); 
    state->u.f4.fld.f6r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB27"); 
    state->u.f4.fld.f6r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB28"); 
    state->u.f4.fld.f6r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB29"); 
    state->u.f4.fld.f6r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB30"); 
    state->u.f4.fld.f6r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f6r2, "FB31");  
    
    // F7R1 bitfields.
    state->u.f4.fld.f7r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB0"); 
    state->u.f4.fld.f7r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB1"); 
    state->u.f4.fld.f7r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB2"); 
    state->u.f4.fld.f7r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB3"); 
    state->u.f4.fld.f7r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB4"); 
    state->u.f4.fld.f7r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB5"); 
    state->u.f4.fld.f7r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB6"); 
    state->u.f4.fld.f7r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB7"); 
    state->u.f4.fld.f7r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB8"); 
    state->u.f4.fld.f7r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB9"); 
    state->u.f4.fld.f7r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB10"); 
    state->u.f4.fld.f7r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB11"); 
    state->u.f4.fld.f7r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB12"); 
    state->u.f4.fld.f7r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB13"); 
    state->u.f4.fld.f7r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB14"); 
    state->u.f4.fld.f7r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB15"); 
    state->u.f4.fld.f7r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB16"); 
    state->u.f4.fld.f7r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB17"); 
    state->u.f4.fld.f7r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB18"); 
    state->u.f4.fld.f7r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB19"); 
    state->u.f4.fld.f7r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB20"); 
    state->u.f4.fld.f7r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB21"); 
    state->u.f4.fld.f7r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB22"); 
    state->u.f4.fld.f7r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB23"); 
    state->u.f4.fld.f7r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB24"); 
    state->u.f4.fld.f7r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB25"); 
    state->u.f4.fld.f7r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB26"); 
    state->u.f4.fld.f7r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB27"); 
    state->u.f4.fld.f7r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB28"); 
    state->u.f4.fld.f7r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB29"); 
    state->u.f4.fld.f7r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB30"); 
    state->u.f4.fld.f7r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f7r1, "FB31");  
    
    // F7R2 bitfields.
    state->u.f4.fld.f7r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB0"); 
    state->u.f4.fld.f7r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB1"); 
    state->u.f4.fld.f7r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB2"); 
    state->u.f4.fld.f7r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB3"); 
    state->u.f4.fld.f7r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB4"); 
    state->u.f4.fld.f7r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB5"); 
    state->u.f4.fld.f7r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB6"); 
    state->u.f4.fld.f7r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB7"); 
    state->u.f4.fld.f7r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB8"); 
    state->u.f4.fld.f7r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB9"); 
    state->u.f4.fld.f7r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB10"); 
    state->u.f4.fld.f7r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB11"); 
    state->u.f4.fld.f7r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB12"); 
    state->u.f4.fld.f7r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB13"); 
    state->u.f4.fld.f7r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB14"); 
    state->u.f4.fld.f7r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB15"); 
    state->u.f4.fld.f7r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB16"); 
    state->u.f4.fld.f7r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB17"); 
    state->u.f4.fld.f7r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB18"); 
    state->u.f4.fld.f7r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB19"); 
    state->u.f4.fld.f7r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB20"); 
    state->u.f4.fld.f7r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB21"); 
    state->u.f4.fld.f7r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB22"); 
    state->u.f4.fld.f7r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB23"); 
    state->u.f4.fld.f7r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB24"); 
    state->u.f4.fld.f7r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB25"); 
    state->u.f4.fld.f7r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB26"); 
    state->u.f4.fld.f7r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB27"); 
    state->u.f4.fld.f7r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB28"); 
    state->u.f4.fld.f7r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB29"); 
    state->u.f4.fld.f7r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB30"); 
    state->u.f4.fld.f7r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f7r2, "FB31");  
    
    // F8R1 bitfields.
    state->u.f4.fld.f8r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB0"); 
    state->u.f4.fld.f8r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB1"); 
    state->u.f4.fld.f8r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB2"); 
    state->u.f4.fld.f8r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB3"); 
    state->u.f4.fld.f8r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB4"); 
    state->u.f4.fld.f8r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB5"); 
    state->u.f4.fld.f8r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB6"); 
    state->u.f4.fld.f8r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB7"); 
    state->u.f4.fld.f8r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB8"); 
    state->u.f4.fld.f8r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB9"); 
    state->u.f4.fld.f8r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB10"); 
    state->u.f4.fld.f8r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB11"); 
    state->u.f4.fld.f8r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB12"); 
    state->u.f4.fld.f8r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB13"); 
    state->u.f4.fld.f8r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB14"); 
    state->u.f4.fld.f8r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB15"); 
    state->u.f4.fld.f8r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB16"); 
    state->u.f4.fld.f8r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB17"); 
    state->u.f4.fld.f8r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB18"); 
    state->u.f4.fld.f8r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB19"); 
    state->u.f4.fld.f8r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB20"); 
    state->u.f4.fld.f8r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB21"); 
    state->u.f4.fld.f8r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB22"); 
    state->u.f4.fld.f8r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB23"); 
    state->u.f4.fld.f8r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB24"); 
    state->u.f4.fld.f8r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB25"); 
    state->u.f4.fld.f8r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB26"); 
    state->u.f4.fld.f8r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB27"); 
    state->u.f4.fld.f8r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB28"); 
    state->u.f4.fld.f8r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB29"); 
    state->u.f4.fld.f8r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB30"); 
    state->u.f4.fld.f8r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f8r1, "FB31");  
    
    // F8R2 bitfields.
    state->u.f4.fld.f8r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB0"); 
    state->u.f4.fld.f8r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB1"); 
    state->u.f4.fld.f8r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB2"); 
    state->u.f4.fld.f8r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB3"); 
    state->u.f4.fld.f8r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB4"); 
    state->u.f4.fld.f8r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB5"); 
    state->u.f4.fld.f8r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB6"); 
    state->u.f4.fld.f8r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB7"); 
    state->u.f4.fld.f8r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB8"); 
    state->u.f4.fld.f8r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB9"); 
    state->u.f4.fld.f8r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB10"); 
    state->u.f4.fld.f8r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB11"); 
    state->u.f4.fld.f8r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB12"); 
    state->u.f4.fld.f8r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB13"); 
    state->u.f4.fld.f8r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB14"); 
    state->u.f4.fld.f8r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB15"); 
    state->u.f4.fld.f8r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB16"); 
    state->u.f4.fld.f8r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB17"); 
    state->u.f4.fld.f8r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB18"); 
    state->u.f4.fld.f8r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB19"); 
    state->u.f4.fld.f8r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB20"); 
    state->u.f4.fld.f8r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB21"); 
    state->u.f4.fld.f8r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB22"); 
    state->u.f4.fld.f8r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB23"); 
    state->u.f4.fld.f8r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB24"); 
    state->u.f4.fld.f8r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB25"); 
    state->u.f4.fld.f8r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB26"); 
    state->u.f4.fld.f8r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB27"); 
    state->u.f4.fld.f8r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB28"); 
    state->u.f4.fld.f8r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB29"); 
    state->u.f4.fld.f8r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB30"); 
    state->u.f4.fld.f8r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f8r2, "FB31");  
    
    // F9R1 bitfields.
    state->u.f4.fld.f9r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB0"); 
    state->u.f4.fld.f9r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB1"); 
    state->u.f4.fld.f9r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB2"); 
    state->u.f4.fld.f9r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB3"); 
    state->u.f4.fld.f9r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB4"); 
    state->u.f4.fld.f9r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB5"); 
    state->u.f4.fld.f9r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB6"); 
    state->u.f4.fld.f9r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB7"); 
    state->u.f4.fld.f9r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB8"); 
    state->u.f4.fld.f9r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB9"); 
    state->u.f4.fld.f9r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB10"); 
    state->u.f4.fld.f9r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB11"); 
    state->u.f4.fld.f9r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB12"); 
    state->u.f4.fld.f9r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB13"); 
    state->u.f4.fld.f9r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB14"); 
    state->u.f4.fld.f9r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB15"); 
    state->u.f4.fld.f9r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB16"); 
    state->u.f4.fld.f9r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB17"); 
    state->u.f4.fld.f9r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB18"); 
    state->u.f4.fld.f9r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB19"); 
    state->u.f4.fld.f9r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB20"); 
    state->u.f4.fld.f9r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB21"); 
    state->u.f4.fld.f9r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB22"); 
    state->u.f4.fld.f9r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB23"); 
    state->u.f4.fld.f9r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB24"); 
    state->u.f4.fld.f9r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB25"); 
    state->u.f4.fld.f9r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB26"); 
    state->u.f4.fld.f9r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB27"); 
    state->u.f4.fld.f9r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB28"); 
    state->u.f4.fld.f9r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB29"); 
    state->u.f4.fld.f9r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB30"); 
    state->u.f4.fld.f9r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f9r1, "FB31");  
    
    // F9R2 bitfields.
    state->u.f4.fld.f9r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB0"); 
    state->u.f4.fld.f9r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB1"); 
    state->u.f4.fld.f9r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB2"); 
    state->u.f4.fld.f9r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB3"); 
    state->u.f4.fld.f9r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB4"); 
    state->u.f4.fld.f9r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB5"); 
    state->u.f4.fld.f9r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB6"); 
    state->u.f4.fld.f9r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB7"); 
    state->u.f4.fld.f9r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB8"); 
    state->u.f4.fld.f9r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB9"); 
    state->u.f4.fld.f9r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB10"); 
    state->u.f4.fld.f9r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB11"); 
    state->u.f4.fld.f9r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB12"); 
    state->u.f4.fld.f9r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB13"); 
    state->u.f4.fld.f9r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB14"); 
    state->u.f4.fld.f9r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB15"); 
    state->u.f4.fld.f9r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB16"); 
    state->u.f4.fld.f9r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB17"); 
    state->u.f4.fld.f9r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB18"); 
    state->u.f4.fld.f9r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB19"); 
    state->u.f4.fld.f9r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB20"); 
    state->u.f4.fld.f9r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB21"); 
    state->u.f4.fld.f9r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB22"); 
    state->u.f4.fld.f9r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB23"); 
    state->u.f4.fld.f9r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB24"); 
    state->u.f4.fld.f9r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB25"); 
    state->u.f4.fld.f9r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB26"); 
    state->u.f4.fld.f9r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB27"); 
    state->u.f4.fld.f9r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB28"); 
    state->u.f4.fld.f9r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB29"); 
    state->u.f4.fld.f9r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB30"); 
    state->u.f4.fld.f9r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f9r2, "FB31");  
    
    // F10R1 bitfields.
    state->u.f4.fld.f10r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB0"); 
    state->u.f4.fld.f10r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB1"); 
    state->u.f4.fld.f10r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB2"); 
    state->u.f4.fld.f10r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB3"); 
    state->u.f4.fld.f10r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB4"); 
    state->u.f4.fld.f10r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB5"); 
    state->u.f4.fld.f10r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB6"); 
    state->u.f4.fld.f10r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB7"); 
    state->u.f4.fld.f10r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB8"); 
    state->u.f4.fld.f10r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB9"); 
    state->u.f4.fld.f10r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB10"); 
    state->u.f4.fld.f10r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB11"); 
    state->u.f4.fld.f10r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB12"); 
    state->u.f4.fld.f10r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB13"); 
    state->u.f4.fld.f10r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB14"); 
    state->u.f4.fld.f10r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB15"); 
    state->u.f4.fld.f10r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB16"); 
    state->u.f4.fld.f10r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB17"); 
    state->u.f4.fld.f10r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB18"); 
    state->u.f4.fld.f10r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB19"); 
    state->u.f4.fld.f10r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB20"); 
    state->u.f4.fld.f10r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB21"); 
    state->u.f4.fld.f10r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB22"); 
    state->u.f4.fld.f10r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB23"); 
    state->u.f4.fld.f10r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB24"); 
    state->u.f4.fld.f10r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB25"); 
    state->u.f4.fld.f10r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB26"); 
    state->u.f4.fld.f10r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB27"); 
    state->u.f4.fld.f10r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB28"); 
    state->u.f4.fld.f10r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB29"); 
    state->u.f4.fld.f10r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB30"); 
    state->u.f4.fld.f10r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f10r1, "FB31");  
    
    // F10R2 bitfields.
    state->u.f4.fld.f10r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB0"); 
    state->u.f4.fld.f10r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB1"); 
    state->u.f4.fld.f10r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB2"); 
    state->u.f4.fld.f10r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB3"); 
    state->u.f4.fld.f10r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB4"); 
    state->u.f4.fld.f10r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB5"); 
    state->u.f4.fld.f10r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB6"); 
    state->u.f4.fld.f10r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB7"); 
    state->u.f4.fld.f10r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB8"); 
    state->u.f4.fld.f10r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB9"); 
    state->u.f4.fld.f10r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB10"); 
    state->u.f4.fld.f10r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB11"); 
    state->u.f4.fld.f10r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB12"); 
    state->u.f4.fld.f10r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB13"); 
    state->u.f4.fld.f10r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB14"); 
    state->u.f4.fld.f10r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB15"); 
    state->u.f4.fld.f10r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB16"); 
    state->u.f4.fld.f10r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB17"); 
    state->u.f4.fld.f10r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB18"); 
    state->u.f4.fld.f10r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB19"); 
    state->u.f4.fld.f10r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB20"); 
    state->u.f4.fld.f10r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB21"); 
    state->u.f4.fld.f10r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB22"); 
    state->u.f4.fld.f10r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB23"); 
    state->u.f4.fld.f10r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB24"); 
    state->u.f4.fld.f10r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB25"); 
    state->u.f4.fld.f10r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB26"); 
    state->u.f4.fld.f10r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB27"); 
    state->u.f4.fld.f10r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB28"); 
    state->u.f4.fld.f10r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB29"); 
    state->u.f4.fld.f10r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB30"); 
    state->u.f4.fld.f10r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f10r2, "FB31");  
    
    // F11R1 bitfields.
    state->u.f4.fld.f11r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB0"); 
    state->u.f4.fld.f11r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB1"); 
    state->u.f4.fld.f11r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB2"); 
    state->u.f4.fld.f11r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB3"); 
    state->u.f4.fld.f11r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB4"); 
    state->u.f4.fld.f11r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB5"); 
    state->u.f4.fld.f11r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB6"); 
    state->u.f4.fld.f11r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB7"); 
    state->u.f4.fld.f11r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB8"); 
    state->u.f4.fld.f11r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB9"); 
    state->u.f4.fld.f11r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB10"); 
    state->u.f4.fld.f11r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB11"); 
    state->u.f4.fld.f11r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB12"); 
    state->u.f4.fld.f11r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB13"); 
    state->u.f4.fld.f11r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB14"); 
    state->u.f4.fld.f11r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB15"); 
    state->u.f4.fld.f11r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB16"); 
    state->u.f4.fld.f11r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB17"); 
    state->u.f4.fld.f11r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB18"); 
    state->u.f4.fld.f11r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB19"); 
    state->u.f4.fld.f11r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB20"); 
    state->u.f4.fld.f11r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB21"); 
    state->u.f4.fld.f11r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB22"); 
    state->u.f4.fld.f11r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB23"); 
    state->u.f4.fld.f11r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB24"); 
    state->u.f4.fld.f11r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB25"); 
    state->u.f4.fld.f11r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB26"); 
    state->u.f4.fld.f11r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB27"); 
    state->u.f4.fld.f11r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB28"); 
    state->u.f4.fld.f11r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB29"); 
    state->u.f4.fld.f11r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB30"); 
    state->u.f4.fld.f11r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f11r1, "FB31");  
    
    // F11R2 bitfields.
    state->u.f4.fld.f11r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB0"); 
    state->u.f4.fld.f11r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB1"); 
    state->u.f4.fld.f11r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB2"); 
    state->u.f4.fld.f11r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB3"); 
    state->u.f4.fld.f11r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB4"); 
    state->u.f4.fld.f11r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB5"); 
    state->u.f4.fld.f11r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB6"); 
    state->u.f4.fld.f11r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB7"); 
    state->u.f4.fld.f11r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB8"); 
    state->u.f4.fld.f11r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB9"); 
    state->u.f4.fld.f11r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB10"); 
    state->u.f4.fld.f11r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB11"); 
    state->u.f4.fld.f11r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB12"); 
    state->u.f4.fld.f11r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB13"); 
    state->u.f4.fld.f11r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB14"); 
    state->u.f4.fld.f11r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB15"); 
    state->u.f4.fld.f11r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB16"); 
    state->u.f4.fld.f11r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB17"); 
    state->u.f4.fld.f11r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB18"); 
    state->u.f4.fld.f11r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB19"); 
    state->u.f4.fld.f11r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB20"); 
    state->u.f4.fld.f11r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB21"); 
    state->u.f4.fld.f11r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB22"); 
    state->u.f4.fld.f11r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB23"); 
    state->u.f4.fld.f11r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB24"); 
    state->u.f4.fld.f11r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB25"); 
    state->u.f4.fld.f11r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB26"); 
    state->u.f4.fld.f11r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB27"); 
    state->u.f4.fld.f11r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB28"); 
    state->u.f4.fld.f11r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB29"); 
    state->u.f4.fld.f11r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB30"); 
    state->u.f4.fld.f11r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f11r2, "FB31");  
    
    // F12R1 bitfields.
    state->u.f4.fld.f12r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB0"); 
    state->u.f4.fld.f12r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB1"); 
    state->u.f4.fld.f12r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB2"); 
    state->u.f4.fld.f12r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB3"); 
    state->u.f4.fld.f12r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB4"); 
    state->u.f4.fld.f12r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB5"); 
    state->u.f4.fld.f12r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB6"); 
    state->u.f4.fld.f12r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB7"); 
    state->u.f4.fld.f12r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB8"); 
    state->u.f4.fld.f12r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB9"); 
    state->u.f4.fld.f12r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB10"); 
    state->u.f4.fld.f12r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB11"); 
    state->u.f4.fld.f12r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB12"); 
    state->u.f4.fld.f12r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB13"); 
    state->u.f4.fld.f12r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB14"); 
    state->u.f4.fld.f12r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB15"); 
    state->u.f4.fld.f12r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB16"); 
    state->u.f4.fld.f12r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB17"); 
    state->u.f4.fld.f12r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB18"); 
    state->u.f4.fld.f12r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB19"); 
    state->u.f4.fld.f12r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB20"); 
    state->u.f4.fld.f12r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB21"); 
    state->u.f4.fld.f12r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB22"); 
    state->u.f4.fld.f12r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB23"); 
    state->u.f4.fld.f12r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB24"); 
    state->u.f4.fld.f12r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB25"); 
    state->u.f4.fld.f12r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB26"); 
    state->u.f4.fld.f12r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB27"); 
    state->u.f4.fld.f12r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB28"); 
    state->u.f4.fld.f12r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB29"); 
    state->u.f4.fld.f12r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB30"); 
    state->u.f4.fld.f12r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f12r1, "FB31");  
    
    // F12R2 bitfields.
    state->u.f4.fld.f12r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB0"); 
    state->u.f4.fld.f12r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB1"); 
    state->u.f4.fld.f12r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB2"); 
    state->u.f4.fld.f12r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB3"); 
    state->u.f4.fld.f12r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB4"); 
    state->u.f4.fld.f12r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB5"); 
    state->u.f4.fld.f12r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB6"); 
    state->u.f4.fld.f12r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB7"); 
    state->u.f4.fld.f12r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB8"); 
    state->u.f4.fld.f12r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB9"); 
    state->u.f4.fld.f12r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB10"); 
    state->u.f4.fld.f12r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB11"); 
    state->u.f4.fld.f12r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB12"); 
    state->u.f4.fld.f12r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB13"); 
    state->u.f4.fld.f12r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB14"); 
    state->u.f4.fld.f12r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB15"); 
    state->u.f4.fld.f12r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB16"); 
    state->u.f4.fld.f12r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB17"); 
    state->u.f4.fld.f12r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB18"); 
    state->u.f4.fld.f12r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB19"); 
    state->u.f4.fld.f12r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB20"); 
    state->u.f4.fld.f12r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB21"); 
    state->u.f4.fld.f12r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB22"); 
    state->u.f4.fld.f12r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB23"); 
    state->u.f4.fld.f12r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB24"); 
    state->u.f4.fld.f12r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB25"); 
    state->u.f4.fld.f12r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB26"); 
    state->u.f4.fld.f12r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB27"); 
    state->u.f4.fld.f12r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB28"); 
    state->u.f4.fld.f12r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB29"); 
    state->u.f4.fld.f12r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB30"); 
    state->u.f4.fld.f12r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f12r2, "FB31");  
    
    // F13R1 bitfields.
    state->u.f4.fld.f13r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB0"); 
    state->u.f4.fld.f13r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB1"); 
    state->u.f4.fld.f13r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB2"); 
    state->u.f4.fld.f13r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB3"); 
    state->u.f4.fld.f13r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB4"); 
    state->u.f4.fld.f13r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB5"); 
    state->u.f4.fld.f13r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB6"); 
    state->u.f4.fld.f13r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB7"); 
    state->u.f4.fld.f13r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB8"); 
    state->u.f4.fld.f13r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB9"); 
    state->u.f4.fld.f13r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB10"); 
    state->u.f4.fld.f13r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB11"); 
    state->u.f4.fld.f13r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB12"); 
    state->u.f4.fld.f13r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB13"); 
    state->u.f4.fld.f13r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB14"); 
    state->u.f4.fld.f13r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB15"); 
    state->u.f4.fld.f13r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB16"); 
    state->u.f4.fld.f13r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB17"); 
    state->u.f4.fld.f13r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB18"); 
    state->u.f4.fld.f13r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB19"); 
    state->u.f4.fld.f13r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB20"); 
    state->u.f4.fld.f13r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB21"); 
    state->u.f4.fld.f13r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB22"); 
    state->u.f4.fld.f13r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB23"); 
    state->u.f4.fld.f13r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB24"); 
    state->u.f4.fld.f13r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB25"); 
    state->u.f4.fld.f13r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB26"); 
    state->u.f4.fld.f13r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB27"); 
    state->u.f4.fld.f13r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB28"); 
    state->u.f4.fld.f13r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB29"); 
    state->u.f4.fld.f13r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB30"); 
    state->u.f4.fld.f13r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f13r1, "FB31");  
    
    // F13R2 bitfields.
    state->u.f4.fld.f13r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB0"); 
    state->u.f4.fld.f13r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB1"); 
    state->u.f4.fld.f13r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB2"); 
    state->u.f4.fld.f13r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB3"); 
    state->u.f4.fld.f13r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB4"); 
    state->u.f4.fld.f13r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB5"); 
    state->u.f4.fld.f13r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB6"); 
    state->u.f4.fld.f13r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB7"); 
    state->u.f4.fld.f13r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB8"); 
    state->u.f4.fld.f13r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB9"); 
    state->u.f4.fld.f13r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB10"); 
    state->u.f4.fld.f13r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB11"); 
    state->u.f4.fld.f13r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB12"); 
    state->u.f4.fld.f13r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB13"); 
    state->u.f4.fld.f13r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB14"); 
    state->u.f4.fld.f13r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB15"); 
    state->u.f4.fld.f13r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB16"); 
    state->u.f4.fld.f13r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB17"); 
    state->u.f4.fld.f13r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB18"); 
    state->u.f4.fld.f13r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB19"); 
    state->u.f4.fld.f13r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB20"); 
    state->u.f4.fld.f13r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB21"); 
    state->u.f4.fld.f13r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB22"); 
    state->u.f4.fld.f13r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB23"); 
    state->u.f4.fld.f13r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB24"); 
    state->u.f4.fld.f13r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB25"); 
    state->u.f4.fld.f13r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB26"); 
    state->u.f4.fld.f13r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB27"); 
    state->u.f4.fld.f13r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB28"); 
    state->u.f4.fld.f13r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB29"); 
    state->u.f4.fld.f13r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB30"); 
    state->u.f4.fld.f13r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f13r2, "FB31");  
    
    // F14R1 bitfields.
    state->u.f4.fld.f14r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB0"); 
    state->u.f4.fld.f14r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB1"); 
    state->u.f4.fld.f14r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB2"); 
    state->u.f4.fld.f14r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB3"); 
    state->u.f4.fld.f14r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB4"); 
    state->u.f4.fld.f14r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB5"); 
    state->u.f4.fld.f14r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB6"); 
    state->u.f4.fld.f14r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB7"); 
    state->u.f4.fld.f14r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB8"); 
    state->u.f4.fld.f14r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB9"); 
    state->u.f4.fld.f14r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB10"); 
    state->u.f4.fld.f14r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB11"); 
    state->u.f4.fld.f14r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB12"); 
    state->u.f4.fld.f14r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB13"); 
    state->u.f4.fld.f14r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB14"); 
    state->u.f4.fld.f14r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB15"); 
    state->u.f4.fld.f14r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB16"); 
    state->u.f4.fld.f14r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB17"); 
    state->u.f4.fld.f14r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB18"); 
    state->u.f4.fld.f14r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB19"); 
    state->u.f4.fld.f14r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB20"); 
    state->u.f4.fld.f14r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB21"); 
    state->u.f4.fld.f14r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB22"); 
    state->u.f4.fld.f14r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB23"); 
    state->u.f4.fld.f14r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB24"); 
    state->u.f4.fld.f14r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB25"); 
    state->u.f4.fld.f14r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB26"); 
    state->u.f4.fld.f14r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB27"); 
    state->u.f4.fld.f14r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB28"); 
    state->u.f4.fld.f14r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB29"); 
    state->u.f4.fld.f14r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB30"); 
    state->u.f4.fld.f14r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f14r1, "FB31");  
    
    // F14R2 bitfields.
    state->u.f4.fld.f14r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB0"); 
    state->u.f4.fld.f14r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB1"); 
    state->u.f4.fld.f14r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB2"); 
    state->u.f4.fld.f14r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB3"); 
    state->u.f4.fld.f14r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB4"); 
    state->u.f4.fld.f14r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB5"); 
    state->u.f4.fld.f14r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB6"); 
    state->u.f4.fld.f14r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB7"); 
    state->u.f4.fld.f14r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB8"); 
    state->u.f4.fld.f14r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB9"); 
    state->u.f4.fld.f14r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB10"); 
    state->u.f4.fld.f14r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB11"); 
    state->u.f4.fld.f14r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB12"); 
    state->u.f4.fld.f14r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB13"); 
    state->u.f4.fld.f14r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB14"); 
    state->u.f4.fld.f14r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB15"); 
    state->u.f4.fld.f14r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB16"); 
    state->u.f4.fld.f14r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB17"); 
    state->u.f4.fld.f14r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB18"); 
    state->u.f4.fld.f14r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB19"); 
    state->u.f4.fld.f14r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB20"); 
    state->u.f4.fld.f14r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB21"); 
    state->u.f4.fld.f14r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB22"); 
    state->u.f4.fld.f14r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB23"); 
    state->u.f4.fld.f14r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB24"); 
    state->u.f4.fld.f14r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB25"); 
    state->u.f4.fld.f14r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB26"); 
    state->u.f4.fld.f14r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB27"); 
    state->u.f4.fld.f14r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB28"); 
    state->u.f4.fld.f14r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB29"); 
    state->u.f4.fld.f14r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB30"); 
    state->u.f4.fld.f14r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f14r2, "FB31");  
    
    // F15R1 bitfields.
    state->u.f4.fld.f15r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB0"); 
    state->u.f4.fld.f15r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB1"); 
    state->u.f4.fld.f15r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB2"); 
    state->u.f4.fld.f15r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB3"); 
    state->u.f4.fld.f15r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB4"); 
    state->u.f4.fld.f15r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB5"); 
    state->u.f4.fld.f15r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB6"); 
    state->u.f4.fld.f15r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB7"); 
    state->u.f4.fld.f15r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB8"); 
    state->u.f4.fld.f15r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB9"); 
    state->u.f4.fld.f15r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB10"); 
    state->u.f4.fld.f15r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB11"); 
    state->u.f4.fld.f15r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB12"); 
    state->u.f4.fld.f15r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB13"); 
    state->u.f4.fld.f15r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB14"); 
    state->u.f4.fld.f15r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB15"); 
    state->u.f4.fld.f15r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB16"); 
    state->u.f4.fld.f15r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB17"); 
    state->u.f4.fld.f15r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB18"); 
    state->u.f4.fld.f15r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB19"); 
    state->u.f4.fld.f15r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB20"); 
    state->u.f4.fld.f15r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB21"); 
    state->u.f4.fld.f15r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB22"); 
    state->u.f4.fld.f15r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB23"); 
    state->u.f4.fld.f15r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB24"); 
    state->u.f4.fld.f15r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB25"); 
    state->u.f4.fld.f15r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB26"); 
    state->u.f4.fld.f15r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB27"); 
    state->u.f4.fld.f15r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB28"); 
    state->u.f4.fld.f15r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB29"); 
    state->u.f4.fld.f15r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB30"); 
    state->u.f4.fld.f15r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f15r1, "FB31");  
    
    // F15R2 bitfields.
    state->u.f4.fld.f15r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB0"); 
    state->u.f4.fld.f15r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB1"); 
    state->u.f4.fld.f15r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB2"); 
    state->u.f4.fld.f15r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB3"); 
    state->u.f4.fld.f15r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB4"); 
    state->u.f4.fld.f15r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB5"); 
    state->u.f4.fld.f15r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB6"); 
    state->u.f4.fld.f15r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB7"); 
    state->u.f4.fld.f15r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB8"); 
    state->u.f4.fld.f15r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB9"); 
    state->u.f4.fld.f15r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB10"); 
    state->u.f4.fld.f15r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB11"); 
    state->u.f4.fld.f15r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB12"); 
    state->u.f4.fld.f15r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB13"); 
    state->u.f4.fld.f15r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB14"); 
    state->u.f4.fld.f15r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB15"); 
    state->u.f4.fld.f15r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB16"); 
    state->u.f4.fld.f15r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB17"); 
    state->u.f4.fld.f15r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB18"); 
    state->u.f4.fld.f15r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB19"); 
    state->u.f4.fld.f15r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB20"); 
    state->u.f4.fld.f15r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB21"); 
    state->u.f4.fld.f15r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB22"); 
    state->u.f4.fld.f15r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB23"); 
    state->u.f4.fld.f15r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB24"); 
    state->u.f4.fld.f15r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB25"); 
    state->u.f4.fld.f15r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB26"); 
    state->u.f4.fld.f15r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB27"); 
    state->u.f4.fld.f15r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB28"); 
    state->u.f4.fld.f15r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB29"); 
    state->u.f4.fld.f15r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB30"); 
    state->u.f4.fld.f15r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f15r2, "FB31");  
    
    // F16R1 bitfields.
    state->u.f4.fld.f16r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB0"); 
    state->u.f4.fld.f16r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB1"); 
    state->u.f4.fld.f16r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB2"); 
    state->u.f4.fld.f16r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB3"); 
    state->u.f4.fld.f16r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB4"); 
    state->u.f4.fld.f16r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB5"); 
    state->u.f4.fld.f16r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB6"); 
    state->u.f4.fld.f16r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB7"); 
    state->u.f4.fld.f16r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB8"); 
    state->u.f4.fld.f16r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB9"); 
    state->u.f4.fld.f16r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB10"); 
    state->u.f4.fld.f16r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB11"); 
    state->u.f4.fld.f16r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB12"); 
    state->u.f4.fld.f16r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB13"); 
    state->u.f4.fld.f16r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB14"); 
    state->u.f4.fld.f16r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB15"); 
    state->u.f4.fld.f16r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB16"); 
    state->u.f4.fld.f16r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB17"); 
    state->u.f4.fld.f16r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB18"); 
    state->u.f4.fld.f16r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB19"); 
    state->u.f4.fld.f16r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB20"); 
    state->u.f4.fld.f16r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB21"); 
    state->u.f4.fld.f16r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB22"); 
    state->u.f4.fld.f16r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB23"); 
    state->u.f4.fld.f16r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB24"); 
    state->u.f4.fld.f16r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB25"); 
    state->u.f4.fld.f16r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB26"); 
    state->u.f4.fld.f16r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB27"); 
    state->u.f4.fld.f16r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB28"); 
    state->u.f4.fld.f16r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB29"); 
    state->u.f4.fld.f16r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB30"); 
    state->u.f4.fld.f16r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f16r1, "FB31");  
    
    // F16R2 bitfields.
    state->u.f4.fld.f16r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB0"); 
    state->u.f4.fld.f16r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB1"); 
    state->u.f4.fld.f16r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB2"); 
    state->u.f4.fld.f16r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB3"); 
    state->u.f4.fld.f16r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB4"); 
    state->u.f4.fld.f16r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB5"); 
    state->u.f4.fld.f16r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB6"); 
    state->u.f4.fld.f16r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB7"); 
    state->u.f4.fld.f16r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB8"); 
    state->u.f4.fld.f16r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB9"); 
    state->u.f4.fld.f16r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB10"); 
    state->u.f4.fld.f16r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB11"); 
    state->u.f4.fld.f16r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB12"); 
    state->u.f4.fld.f16r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB13"); 
    state->u.f4.fld.f16r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB14"); 
    state->u.f4.fld.f16r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB15"); 
    state->u.f4.fld.f16r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB16"); 
    state->u.f4.fld.f16r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB17"); 
    state->u.f4.fld.f16r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB18"); 
    state->u.f4.fld.f16r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB19"); 
    state->u.f4.fld.f16r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB20"); 
    state->u.f4.fld.f16r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB21"); 
    state->u.f4.fld.f16r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB22"); 
    state->u.f4.fld.f16r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB23"); 
    state->u.f4.fld.f16r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB24"); 
    state->u.f4.fld.f16r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB25"); 
    state->u.f4.fld.f16r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB26"); 
    state->u.f4.fld.f16r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB27"); 
    state->u.f4.fld.f16r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB28"); 
    state->u.f4.fld.f16r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB29"); 
    state->u.f4.fld.f16r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB30"); 
    state->u.f4.fld.f16r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f16r2, "FB31");  
    
    // F17R1 bitfields.
    state->u.f4.fld.f17r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB0"); 
    state->u.f4.fld.f17r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB1"); 
    state->u.f4.fld.f17r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB2"); 
    state->u.f4.fld.f17r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB3"); 
    state->u.f4.fld.f17r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB4"); 
    state->u.f4.fld.f17r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB5"); 
    state->u.f4.fld.f17r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB6"); 
    state->u.f4.fld.f17r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB7"); 
    state->u.f4.fld.f17r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB8"); 
    state->u.f4.fld.f17r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB9"); 
    state->u.f4.fld.f17r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB10"); 
    state->u.f4.fld.f17r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB11"); 
    state->u.f4.fld.f17r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB12"); 
    state->u.f4.fld.f17r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB13"); 
    state->u.f4.fld.f17r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB14"); 
    state->u.f4.fld.f17r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB15"); 
    state->u.f4.fld.f17r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB16"); 
    state->u.f4.fld.f17r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB17"); 
    state->u.f4.fld.f17r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB18"); 
    state->u.f4.fld.f17r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB19"); 
    state->u.f4.fld.f17r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB20"); 
    state->u.f4.fld.f17r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB21"); 
    state->u.f4.fld.f17r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB22"); 
    state->u.f4.fld.f17r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB23"); 
    state->u.f4.fld.f17r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB24"); 
    state->u.f4.fld.f17r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB25"); 
    state->u.f4.fld.f17r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB26"); 
    state->u.f4.fld.f17r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB27"); 
    state->u.f4.fld.f17r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB28"); 
    state->u.f4.fld.f17r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB29"); 
    state->u.f4.fld.f17r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB30"); 
    state->u.f4.fld.f17r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f17r1, "FB31");  
    
    // F17R2 bitfields.
    state->u.f4.fld.f17r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB0"); 
    state->u.f4.fld.f17r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB1"); 
    state->u.f4.fld.f17r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB2"); 
    state->u.f4.fld.f17r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB3"); 
    state->u.f4.fld.f17r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB4"); 
    state->u.f4.fld.f17r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB5"); 
    state->u.f4.fld.f17r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB6"); 
    state->u.f4.fld.f17r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB7"); 
    state->u.f4.fld.f17r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB8"); 
    state->u.f4.fld.f17r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB9"); 
    state->u.f4.fld.f17r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB10"); 
    state->u.f4.fld.f17r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB11"); 
    state->u.f4.fld.f17r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB12"); 
    state->u.f4.fld.f17r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB13"); 
    state->u.f4.fld.f17r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB14"); 
    state->u.f4.fld.f17r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB15"); 
    state->u.f4.fld.f17r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB16"); 
    state->u.f4.fld.f17r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB17"); 
    state->u.f4.fld.f17r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB18"); 
    state->u.f4.fld.f17r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB19"); 
    state->u.f4.fld.f17r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB20"); 
    state->u.f4.fld.f17r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB21"); 
    state->u.f4.fld.f17r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB22"); 
    state->u.f4.fld.f17r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB23"); 
    state->u.f4.fld.f17r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB24"); 
    state->u.f4.fld.f17r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB25"); 
    state->u.f4.fld.f17r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB26"); 
    state->u.f4.fld.f17r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB27"); 
    state->u.f4.fld.f17r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB28"); 
    state->u.f4.fld.f17r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB29"); 
    state->u.f4.fld.f17r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB30"); 
    state->u.f4.fld.f17r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f17r2, "FB31");  
    
    // F18R1 bitfields.
    state->u.f4.fld.f18r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB0"); 
    state->u.f4.fld.f18r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB1"); 
    state->u.f4.fld.f18r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB2"); 
    state->u.f4.fld.f18r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB3"); 
    state->u.f4.fld.f18r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB4"); 
    state->u.f4.fld.f18r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB5"); 
    state->u.f4.fld.f18r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB6"); 
    state->u.f4.fld.f18r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB7"); 
    state->u.f4.fld.f18r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB8"); 
    state->u.f4.fld.f18r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB9"); 
    state->u.f4.fld.f18r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB10"); 
    state->u.f4.fld.f18r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB11"); 
    state->u.f4.fld.f18r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB12"); 
    state->u.f4.fld.f18r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB13"); 
    state->u.f4.fld.f18r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB14"); 
    state->u.f4.fld.f18r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB15"); 
    state->u.f4.fld.f18r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB16"); 
    state->u.f4.fld.f18r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB17"); 
    state->u.f4.fld.f18r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB18"); 
    state->u.f4.fld.f18r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB19"); 
    state->u.f4.fld.f18r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB20"); 
    state->u.f4.fld.f18r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB21"); 
    state->u.f4.fld.f18r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB22"); 
    state->u.f4.fld.f18r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB23"); 
    state->u.f4.fld.f18r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB24"); 
    state->u.f4.fld.f18r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB25"); 
    state->u.f4.fld.f18r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB26"); 
    state->u.f4.fld.f18r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB27"); 
    state->u.f4.fld.f18r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB28"); 
    state->u.f4.fld.f18r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB29"); 
    state->u.f4.fld.f18r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB30"); 
    state->u.f4.fld.f18r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f18r1, "FB31");  
    
    // F18R2 bitfields.
    state->u.f4.fld.f18r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB0"); 
    state->u.f4.fld.f18r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB1"); 
    state->u.f4.fld.f18r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB2"); 
    state->u.f4.fld.f18r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB3"); 
    state->u.f4.fld.f18r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB4"); 
    state->u.f4.fld.f18r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB5"); 
    state->u.f4.fld.f18r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB6"); 
    state->u.f4.fld.f18r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB7"); 
    state->u.f4.fld.f18r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB8"); 
    state->u.f4.fld.f18r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB9"); 
    state->u.f4.fld.f18r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB10"); 
    state->u.f4.fld.f18r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB11"); 
    state->u.f4.fld.f18r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB12"); 
    state->u.f4.fld.f18r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB13"); 
    state->u.f4.fld.f18r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB14"); 
    state->u.f4.fld.f18r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB15"); 
    state->u.f4.fld.f18r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB16"); 
    state->u.f4.fld.f18r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB17"); 
    state->u.f4.fld.f18r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB18"); 
    state->u.f4.fld.f18r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB19"); 
    state->u.f4.fld.f18r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB20"); 
    state->u.f4.fld.f18r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB21"); 
    state->u.f4.fld.f18r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB22"); 
    state->u.f4.fld.f18r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB23"); 
    state->u.f4.fld.f18r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB24"); 
    state->u.f4.fld.f18r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB25"); 
    state->u.f4.fld.f18r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB26"); 
    state->u.f4.fld.f18r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB27"); 
    state->u.f4.fld.f18r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB28"); 
    state->u.f4.fld.f18r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB29"); 
    state->u.f4.fld.f18r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB30"); 
    state->u.f4.fld.f18r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f18r2, "FB31");  
    
    // F19R1 bitfields.
    state->u.f4.fld.f19r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB0"); 
    state->u.f4.fld.f19r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB1"); 
    state->u.f4.fld.f19r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB2"); 
    state->u.f4.fld.f19r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB3"); 
    state->u.f4.fld.f19r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB4"); 
    state->u.f4.fld.f19r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB5"); 
    state->u.f4.fld.f19r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB6"); 
    state->u.f4.fld.f19r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB7"); 
    state->u.f4.fld.f19r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB8"); 
    state->u.f4.fld.f19r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB9"); 
    state->u.f4.fld.f19r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB10"); 
    state->u.f4.fld.f19r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB11"); 
    state->u.f4.fld.f19r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB12"); 
    state->u.f4.fld.f19r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB13"); 
    state->u.f4.fld.f19r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB14"); 
    state->u.f4.fld.f19r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB15"); 
    state->u.f4.fld.f19r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB16"); 
    state->u.f4.fld.f19r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB17"); 
    state->u.f4.fld.f19r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB18"); 
    state->u.f4.fld.f19r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB19"); 
    state->u.f4.fld.f19r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB20"); 
    state->u.f4.fld.f19r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB21"); 
    state->u.f4.fld.f19r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB22"); 
    state->u.f4.fld.f19r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB23"); 
    state->u.f4.fld.f19r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB24"); 
    state->u.f4.fld.f19r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB25"); 
    state->u.f4.fld.f19r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB26"); 
    state->u.f4.fld.f19r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB27"); 
    state->u.f4.fld.f19r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB28"); 
    state->u.f4.fld.f19r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB29"); 
    state->u.f4.fld.f19r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB30"); 
    state->u.f4.fld.f19r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f19r1, "FB31");  
    
    // F19R2 bitfields.
    state->u.f4.fld.f19r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB0"); 
    state->u.f4.fld.f19r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB1"); 
    state->u.f4.fld.f19r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB2"); 
    state->u.f4.fld.f19r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB3"); 
    state->u.f4.fld.f19r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB4"); 
    state->u.f4.fld.f19r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB5"); 
    state->u.f4.fld.f19r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB6"); 
    state->u.f4.fld.f19r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB7"); 
    state->u.f4.fld.f19r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB8"); 
    state->u.f4.fld.f19r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB9"); 
    state->u.f4.fld.f19r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB10"); 
    state->u.f4.fld.f19r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB11"); 
    state->u.f4.fld.f19r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB12"); 
    state->u.f4.fld.f19r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB13"); 
    state->u.f4.fld.f19r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB14"); 
    state->u.f4.fld.f19r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB15"); 
    state->u.f4.fld.f19r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB16"); 
    state->u.f4.fld.f19r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB17"); 
    state->u.f4.fld.f19r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB18"); 
    state->u.f4.fld.f19r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB19"); 
    state->u.f4.fld.f19r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB20"); 
    state->u.f4.fld.f19r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB21"); 
    state->u.f4.fld.f19r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB22"); 
    state->u.f4.fld.f19r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB23"); 
    state->u.f4.fld.f19r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB24"); 
    state->u.f4.fld.f19r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB25"); 
    state->u.f4.fld.f19r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB26"); 
    state->u.f4.fld.f19r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB27"); 
    state->u.f4.fld.f19r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB28"); 
    state->u.f4.fld.f19r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB29"); 
    state->u.f4.fld.f19r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB30"); 
    state->u.f4.fld.f19r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f19r2, "FB31");  
    
    // F20R1 bitfields.
    state->u.f4.fld.f20r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB0"); 
    state->u.f4.fld.f20r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB1"); 
    state->u.f4.fld.f20r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB2"); 
    state->u.f4.fld.f20r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB3"); 
    state->u.f4.fld.f20r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB4"); 
    state->u.f4.fld.f20r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB5"); 
    state->u.f4.fld.f20r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB6"); 
    state->u.f4.fld.f20r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB7"); 
    state->u.f4.fld.f20r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB8"); 
    state->u.f4.fld.f20r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB9"); 
    state->u.f4.fld.f20r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB10"); 
    state->u.f4.fld.f20r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB11"); 
    state->u.f4.fld.f20r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB12"); 
    state->u.f4.fld.f20r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB13"); 
    state->u.f4.fld.f20r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB14"); 
    state->u.f4.fld.f20r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB15"); 
    state->u.f4.fld.f20r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB16"); 
    state->u.f4.fld.f20r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB17"); 
    state->u.f4.fld.f20r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB18"); 
    state->u.f4.fld.f20r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB19"); 
    state->u.f4.fld.f20r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB20"); 
    state->u.f4.fld.f20r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB21"); 
    state->u.f4.fld.f20r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB22"); 
    state->u.f4.fld.f20r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB23"); 
    state->u.f4.fld.f20r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB24"); 
    state->u.f4.fld.f20r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB25"); 
    state->u.f4.fld.f20r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB26"); 
    state->u.f4.fld.f20r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB27"); 
    state->u.f4.fld.f20r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB28"); 
    state->u.f4.fld.f20r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB29"); 
    state->u.f4.fld.f20r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB30"); 
    state->u.f4.fld.f20r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f20r1, "FB31");  
    
    // F20R2 bitfields.
    state->u.f4.fld.f20r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB0"); 
    state->u.f4.fld.f20r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB1"); 
    state->u.f4.fld.f20r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB2"); 
    state->u.f4.fld.f20r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB3"); 
    state->u.f4.fld.f20r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB4"); 
    state->u.f4.fld.f20r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB5"); 
    state->u.f4.fld.f20r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB6"); 
    state->u.f4.fld.f20r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB7"); 
    state->u.f4.fld.f20r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB8"); 
    state->u.f4.fld.f20r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB9"); 
    state->u.f4.fld.f20r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB10"); 
    state->u.f4.fld.f20r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB11"); 
    state->u.f4.fld.f20r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB12"); 
    state->u.f4.fld.f20r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB13"); 
    state->u.f4.fld.f20r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB14"); 
    state->u.f4.fld.f20r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB15"); 
    state->u.f4.fld.f20r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB16"); 
    state->u.f4.fld.f20r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB17"); 
    state->u.f4.fld.f20r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB18"); 
    state->u.f4.fld.f20r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB19"); 
    state->u.f4.fld.f20r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB20"); 
    state->u.f4.fld.f20r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB21"); 
    state->u.f4.fld.f20r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB22"); 
    state->u.f4.fld.f20r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB23"); 
    state->u.f4.fld.f20r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB24"); 
    state->u.f4.fld.f20r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB25"); 
    state->u.f4.fld.f20r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB26"); 
    state->u.f4.fld.f20r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB27"); 
    state->u.f4.fld.f20r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB28"); 
    state->u.f4.fld.f20r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB29"); 
    state->u.f4.fld.f20r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB30"); 
    state->u.f4.fld.f20r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f20r2, "FB31");  
    
    // F21R1 bitfields.
    state->u.f4.fld.f21r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB0"); 
    state->u.f4.fld.f21r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB1"); 
    state->u.f4.fld.f21r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB2"); 
    state->u.f4.fld.f21r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB3"); 
    state->u.f4.fld.f21r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB4"); 
    state->u.f4.fld.f21r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB5"); 
    state->u.f4.fld.f21r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB6"); 
    state->u.f4.fld.f21r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB7"); 
    state->u.f4.fld.f21r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB8"); 
    state->u.f4.fld.f21r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB9"); 
    state->u.f4.fld.f21r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB10"); 
    state->u.f4.fld.f21r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB11"); 
    state->u.f4.fld.f21r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB12"); 
    state->u.f4.fld.f21r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB13"); 
    state->u.f4.fld.f21r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB14"); 
    state->u.f4.fld.f21r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB15"); 
    state->u.f4.fld.f21r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB16"); 
    state->u.f4.fld.f21r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB17"); 
    state->u.f4.fld.f21r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB18"); 
    state->u.f4.fld.f21r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB19"); 
    state->u.f4.fld.f21r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB20"); 
    state->u.f4.fld.f21r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB21"); 
    state->u.f4.fld.f21r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB22"); 
    state->u.f4.fld.f21r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB23"); 
    state->u.f4.fld.f21r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB24"); 
    state->u.f4.fld.f21r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB25"); 
    state->u.f4.fld.f21r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB26"); 
    state->u.f4.fld.f21r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB27"); 
    state->u.f4.fld.f21r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB28"); 
    state->u.f4.fld.f21r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB29"); 
    state->u.f4.fld.f21r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB30"); 
    state->u.f4.fld.f21r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f21r1, "FB31");  
    
    // F21R2 bitfields.
    state->u.f4.fld.f21r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB0"); 
    state->u.f4.fld.f21r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB1"); 
    state->u.f4.fld.f21r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB2"); 
    state->u.f4.fld.f21r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB3"); 
    state->u.f4.fld.f21r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB4"); 
    state->u.f4.fld.f21r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB5"); 
    state->u.f4.fld.f21r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB6"); 
    state->u.f4.fld.f21r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB7"); 
    state->u.f4.fld.f21r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB8"); 
    state->u.f4.fld.f21r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB9"); 
    state->u.f4.fld.f21r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB10"); 
    state->u.f4.fld.f21r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB11"); 
    state->u.f4.fld.f21r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB12"); 
    state->u.f4.fld.f21r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB13"); 
    state->u.f4.fld.f21r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB14"); 
    state->u.f4.fld.f21r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB15"); 
    state->u.f4.fld.f21r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB16"); 
    state->u.f4.fld.f21r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB17"); 
    state->u.f4.fld.f21r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB18"); 
    state->u.f4.fld.f21r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB19"); 
    state->u.f4.fld.f21r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB20"); 
    state->u.f4.fld.f21r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB21"); 
    state->u.f4.fld.f21r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB22"); 
    state->u.f4.fld.f21r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB23"); 
    state->u.f4.fld.f21r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB24"); 
    state->u.f4.fld.f21r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB25"); 
    state->u.f4.fld.f21r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB26"); 
    state->u.f4.fld.f21r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB27"); 
    state->u.f4.fld.f21r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB28"); 
    state->u.f4.fld.f21r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB29"); 
    state->u.f4.fld.f21r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB30"); 
    state->u.f4.fld.f21r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f21r2, "FB31");  
    
    // F22R1 bitfields.
    state->u.f4.fld.f22r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB0"); 
    state->u.f4.fld.f22r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB1"); 
    state->u.f4.fld.f22r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB2"); 
    state->u.f4.fld.f22r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB3"); 
    state->u.f4.fld.f22r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB4"); 
    state->u.f4.fld.f22r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB5"); 
    state->u.f4.fld.f22r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB6"); 
    state->u.f4.fld.f22r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB7"); 
    state->u.f4.fld.f22r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB8"); 
    state->u.f4.fld.f22r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB9"); 
    state->u.f4.fld.f22r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB10"); 
    state->u.f4.fld.f22r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB11"); 
    state->u.f4.fld.f22r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB12"); 
    state->u.f4.fld.f22r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB13"); 
    state->u.f4.fld.f22r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB14"); 
    state->u.f4.fld.f22r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB15"); 
    state->u.f4.fld.f22r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB16"); 
    state->u.f4.fld.f22r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB17"); 
    state->u.f4.fld.f22r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB18"); 
    state->u.f4.fld.f22r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB19"); 
    state->u.f4.fld.f22r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB20"); 
    state->u.f4.fld.f22r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB21"); 
    state->u.f4.fld.f22r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB22"); 
    state->u.f4.fld.f22r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB23"); 
    state->u.f4.fld.f22r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB24"); 
    state->u.f4.fld.f22r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB25"); 
    state->u.f4.fld.f22r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB26"); 
    state->u.f4.fld.f22r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB27"); 
    state->u.f4.fld.f22r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB28"); 
    state->u.f4.fld.f22r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB29"); 
    state->u.f4.fld.f22r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB30"); 
    state->u.f4.fld.f22r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f22r1, "FB31");  
    
    // F22R2 bitfields.
    state->u.f4.fld.f22r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB0"); 
    state->u.f4.fld.f22r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB1"); 
    state->u.f4.fld.f22r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB2"); 
    state->u.f4.fld.f22r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB3"); 
    state->u.f4.fld.f22r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB4"); 
    state->u.f4.fld.f22r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB5"); 
    state->u.f4.fld.f22r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB6"); 
    state->u.f4.fld.f22r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB7"); 
    state->u.f4.fld.f22r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB8"); 
    state->u.f4.fld.f22r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB9"); 
    state->u.f4.fld.f22r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB10"); 
    state->u.f4.fld.f22r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB11"); 
    state->u.f4.fld.f22r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB12"); 
    state->u.f4.fld.f22r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB13"); 
    state->u.f4.fld.f22r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB14"); 
    state->u.f4.fld.f22r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB15"); 
    state->u.f4.fld.f22r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB16"); 
    state->u.f4.fld.f22r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB17"); 
    state->u.f4.fld.f22r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB18"); 
    state->u.f4.fld.f22r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB19"); 
    state->u.f4.fld.f22r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB20"); 
    state->u.f4.fld.f22r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB21"); 
    state->u.f4.fld.f22r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB22"); 
    state->u.f4.fld.f22r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB23"); 
    state->u.f4.fld.f22r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB24"); 
    state->u.f4.fld.f22r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB25"); 
    state->u.f4.fld.f22r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB26"); 
    state->u.f4.fld.f22r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB27"); 
    state->u.f4.fld.f22r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB28"); 
    state->u.f4.fld.f22r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB29"); 
    state->u.f4.fld.f22r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB30"); 
    state->u.f4.fld.f22r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f22r2, "FB31");  
    
    // F23R1 bitfields.
    state->u.f4.fld.f23r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB0"); 
    state->u.f4.fld.f23r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB1"); 
    state->u.f4.fld.f23r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB2"); 
    state->u.f4.fld.f23r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB3"); 
    state->u.f4.fld.f23r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB4"); 
    state->u.f4.fld.f23r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB5"); 
    state->u.f4.fld.f23r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB6"); 
    state->u.f4.fld.f23r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB7"); 
    state->u.f4.fld.f23r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB8"); 
    state->u.f4.fld.f23r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB9"); 
    state->u.f4.fld.f23r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB10"); 
    state->u.f4.fld.f23r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB11"); 
    state->u.f4.fld.f23r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB12"); 
    state->u.f4.fld.f23r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB13"); 
    state->u.f4.fld.f23r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB14"); 
    state->u.f4.fld.f23r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB15"); 
    state->u.f4.fld.f23r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB16"); 
    state->u.f4.fld.f23r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB17"); 
    state->u.f4.fld.f23r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB18"); 
    state->u.f4.fld.f23r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB19"); 
    state->u.f4.fld.f23r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB20"); 
    state->u.f4.fld.f23r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB21"); 
    state->u.f4.fld.f23r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB22"); 
    state->u.f4.fld.f23r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB23"); 
    state->u.f4.fld.f23r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB24"); 
    state->u.f4.fld.f23r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB25"); 
    state->u.f4.fld.f23r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB26"); 
    state->u.f4.fld.f23r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB27"); 
    state->u.f4.fld.f23r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB28"); 
    state->u.f4.fld.f23r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB29"); 
    state->u.f4.fld.f23r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB30"); 
    state->u.f4.fld.f23r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f23r1, "FB31");  
    
    // F23R2 bitfields.
    state->u.f4.fld.f23r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB0"); 
    state->u.f4.fld.f23r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB1"); 
    state->u.f4.fld.f23r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB2"); 
    state->u.f4.fld.f23r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB3"); 
    state->u.f4.fld.f23r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB4"); 
    state->u.f4.fld.f23r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB5"); 
    state->u.f4.fld.f23r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB6"); 
    state->u.f4.fld.f23r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB7"); 
    state->u.f4.fld.f23r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB8"); 
    state->u.f4.fld.f23r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB9"); 
    state->u.f4.fld.f23r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB10"); 
    state->u.f4.fld.f23r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB11"); 
    state->u.f4.fld.f23r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB12"); 
    state->u.f4.fld.f23r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB13"); 
    state->u.f4.fld.f23r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB14"); 
    state->u.f4.fld.f23r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB15"); 
    state->u.f4.fld.f23r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB16"); 
    state->u.f4.fld.f23r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB17"); 
    state->u.f4.fld.f23r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB18"); 
    state->u.f4.fld.f23r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB19"); 
    state->u.f4.fld.f23r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB20"); 
    state->u.f4.fld.f23r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB21"); 
    state->u.f4.fld.f23r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB22"); 
    state->u.f4.fld.f23r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB23"); 
    state->u.f4.fld.f23r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB24"); 
    state->u.f4.fld.f23r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB25"); 
    state->u.f4.fld.f23r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB26"); 
    state->u.f4.fld.f23r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB27"); 
    state->u.f4.fld.f23r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB28"); 
    state->u.f4.fld.f23r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB29"); 
    state->u.f4.fld.f23r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB30"); 
    state->u.f4.fld.f23r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f23r2, "FB31");  
    
    // F24R1 bitfields.
    state->u.f4.fld.f24r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB0"); 
    state->u.f4.fld.f24r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB1"); 
    state->u.f4.fld.f24r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB2"); 
    state->u.f4.fld.f24r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB3"); 
    state->u.f4.fld.f24r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB4"); 
    state->u.f4.fld.f24r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB5"); 
    state->u.f4.fld.f24r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB6"); 
    state->u.f4.fld.f24r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB7"); 
    state->u.f4.fld.f24r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB8"); 
    state->u.f4.fld.f24r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB9"); 
    state->u.f4.fld.f24r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB10"); 
    state->u.f4.fld.f24r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB11"); 
    state->u.f4.fld.f24r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB12"); 
    state->u.f4.fld.f24r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB13"); 
    state->u.f4.fld.f24r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB14"); 
    state->u.f4.fld.f24r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB15"); 
    state->u.f4.fld.f24r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB16"); 
    state->u.f4.fld.f24r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB17"); 
    state->u.f4.fld.f24r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB18"); 
    state->u.f4.fld.f24r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB19"); 
    state->u.f4.fld.f24r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB20"); 
    state->u.f4.fld.f24r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB21"); 
    state->u.f4.fld.f24r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB22"); 
    state->u.f4.fld.f24r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB23"); 
    state->u.f4.fld.f24r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB24"); 
    state->u.f4.fld.f24r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB25"); 
    state->u.f4.fld.f24r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB26"); 
    state->u.f4.fld.f24r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB27"); 
    state->u.f4.fld.f24r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB28"); 
    state->u.f4.fld.f24r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB29"); 
    state->u.f4.fld.f24r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB30"); 
    state->u.f4.fld.f24r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f24r1, "FB31");  
    
    // F24R2 bitfields.
    state->u.f4.fld.f24r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB0"); 
    state->u.f4.fld.f24r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB1"); 
    state->u.f4.fld.f24r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB2"); 
    state->u.f4.fld.f24r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB3"); 
    state->u.f4.fld.f24r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB4"); 
    state->u.f4.fld.f24r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB5"); 
    state->u.f4.fld.f24r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB6"); 
    state->u.f4.fld.f24r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB7"); 
    state->u.f4.fld.f24r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB8"); 
    state->u.f4.fld.f24r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB9"); 
    state->u.f4.fld.f24r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB10"); 
    state->u.f4.fld.f24r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB11"); 
    state->u.f4.fld.f24r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB12"); 
    state->u.f4.fld.f24r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB13"); 
    state->u.f4.fld.f24r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB14"); 
    state->u.f4.fld.f24r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB15"); 
    state->u.f4.fld.f24r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB16"); 
    state->u.f4.fld.f24r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB17"); 
    state->u.f4.fld.f24r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB18"); 
    state->u.f4.fld.f24r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB19"); 
    state->u.f4.fld.f24r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB20"); 
    state->u.f4.fld.f24r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB21"); 
    state->u.f4.fld.f24r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB22"); 
    state->u.f4.fld.f24r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB23"); 
    state->u.f4.fld.f24r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB24"); 
    state->u.f4.fld.f24r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB25"); 
    state->u.f4.fld.f24r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB26"); 
    state->u.f4.fld.f24r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB27"); 
    state->u.f4.fld.f24r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB28"); 
    state->u.f4.fld.f24r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB29"); 
    state->u.f4.fld.f24r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB30"); 
    state->u.f4.fld.f24r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f24r2, "FB31");  
    
    // F25R1 bitfields.
    state->u.f4.fld.f25r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB0"); 
    state->u.f4.fld.f25r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB1"); 
    state->u.f4.fld.f25r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB2"); 
    state->u.f4.fld.f25r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB3"); 
    state->u.f4.fld.f25r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB4"); 
    state->u.f4.fld.f25r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB5"); 
    state->u.f4.fld.f25r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB6"); 
    state->u.f4.fld.f25r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB7"); 
    state->u.f4.fld.f25r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB8"); 
    state->u.f4.fld.f25r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB9"); 
    state->u.f4.fld.f25r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB10"); 
    state->u.f4.fld.f25r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB11"); 
    state->u.f4.fld.f25r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB12"); 
    state->u.f4.fld.f25r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB13"); 
    state->u.f4.fld.f25r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB14"); 
    state->u.f4.fld.f25r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB15"); 
    state->u.f4.fld.f25r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB16"); 
    state->u.f4.fld.f25r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB17"); 
    state->u.f4.fld.f25r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB18"); 
    state->u.f4.fld.f25r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB19"); 
    state->u.f4.fld.f25r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB20"); 
    state->u.f4.fld.f25r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB21"); 
    state->u.f4.fld.f25r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB22"); 
    state->u.f4.fld.f25r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB23"); 
    state->u.f4.fld.f25r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB24"); 
    state->u.f4.fld.f25r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB25"); 
    state->u.f4.fld.f25r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB26"); 
    state->u.f4.fld.f25r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB27"); 
    state->u.f4.fld.f25r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB28"); 
    state->u.f4.fld.f25r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB29"); 
    state->u.f4.fld.f25r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB30"); 
    state->u.f4.fld.f25r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f25r1, "FB31");  
    
    // F25R2 bitfields.
    state->u.f4.fld.f25r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB0"); 
    state->u.f4.fld.f25r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB1"); 
    state->u.f4.fld.f25r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB2"); 
    state->u.f4.fld.f25r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB3"); 
    state->u.f4.fld.f25r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB4"); 
    state->u.f4.fld.f25r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB5"); 
    state->u.f4.fld.f25r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB6"); 
    state->u.f4.fld.f25r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB7"); 
    state->u.f4.fld.f25r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB8"); 
    state->u.f4.fld.f25r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB9"); 
    state->u.f4.fld.f25r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB10"); 
    state->u.f4.fld.f25r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB11"); 
    state->u.f4.fld.f25r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB12"); 
    state->u.f4.fld.f25r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB13"); 
    state->u.f4.fld.f25r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB14"); 
    state->u.f4.fld.f25r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB15"); 
    state->u.f4.fld.f25r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB16"); 
    state->u.f4.fld.f25r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB17"); 
    state->u.f4.fld.f25r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB18"); 
    state->u.f4.fld.f25r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB19"); 
    state->u.f4.fld.f25r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB20"); 
    state->u.f4.fld.f25r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB21"); 
    state->u.f4.fld.f25r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB22"); 
    state->u.f4.fld.f25r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB23"); 
    state->u.f4.fld.f25r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB24"); 
    state->u.f4.fld.f25r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB25"); 
    state->u.f4.fld.f25r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB26"); 
    state->u.f4.fld.f25r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB27"); 
    state->u.f4.fld.f25r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB28"); 
    state->u.f4.fld.f25r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB29"); 
    state->u.f4.fld.f25r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB30"); 
    state->u.f4.fld.f25r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f25r2, "FB31");  
    
    // F26R1 bitfields.
    state->u.f4.fld.f26r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB0"); 
    state->u.f4.fld.f26r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB1"); 
    state->u.f4.fld.f26r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB2"); 
    state->u.f4.fld.f26r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB3"); 
    state->u.f4.fld.f26r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB4"); 
    state->u.f4.fld.f26r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB5"); 
    state->u.f4.fld.f26r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB6"); 
    state->u.f4.fld.f26r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB7"); 
    state->u.f4.fld.f26r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB8"); 
    state->u.f4.fld.f26r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB9"); 
    state->u.f4.fld.f26r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB10"); 
    state->u.f4.fld.f26r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB11"); 
    state->u.f4.fld.f26r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB12"); 
    state->u.f4.fld.f26r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB13"); 
    state->u.f4.fld.f26r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB14"); 
    state->u.f4.fld.f26r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB15"); 
    state->u.f4.fld.f26r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB16"); 
    state->u.f4.fld.f26r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB17"); 
    state->u.f4.fld.f26r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB18"); 
    state->u.f4.fld.f26r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB19"); 
    state->u.f4.fld.f26r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB20"); 
    state->u.f4.fld.f26r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB21"); 
    state->u.f4.fld.f26r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB22"); 
    state->u.f4.fld.f26r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB23"); 
    state->u.f4.fld.f26r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB24"); 
    state->u.f4.fld.f26r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB25"); 
    state->u.f4.fld.f26r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB26"); 
    state->u.f4.fld.f26r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB27"); 
    state->u.f4.fld.f26r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB28"); 
    state->u.f4.fld.f26r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB29"); 
    state->u.f4.fld.f26r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB30"); 
    state->u.f4.fld.f26r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f26r1, "FB31");  
    
    // F26R2 bitfields.
    state->u.f4.fld.f26r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB0"); 
    state->u.f4.fld.f26r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB1"); 
    state->u.f4.fld.f26r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB2"); 
    state->u.f4.fld.f26r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB3"); 
    state->u.f4.fld.f26r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB4"); 
    state->u.f4.fld.f26r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB5"); 
    state->u.f4.fld.f26r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB6"); 
    state->u.f4.fld.f26r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB7"); 
    state->u.f4.fld.f26r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB8"); 
    state->u.f4.fld.f26r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB9"); 
    state->u.f4.fld.f26r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB10"); 
    state->u.f4.fld.f26r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB11"); 
    state->u.f4.fld.f26r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB12"); 
    state->u.f4.fld.f26r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB13"); 
    state->u.f4.fld.f26r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB14"); 
    state->u.f4.fld.f26r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB15"); 
    state->u.f4.fld.f26r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB16"); 
    state->u.f4.fld.f26r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB17"); 
    state->u.f4.fld.f26r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB18"); 
    state->u.f4.fld.f26r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB19"); 
    state->u.f4.fld.f26r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB20"); 
    state->u.f4.fld.f26r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB21"); 
    state->u.f4.fld.f26r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB22"); 
    state->u.f4.fld.f26r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB23"); 
    state->u.f4.fld.f26r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB24"); 
    state->u.f4.fld.f26r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB25"); 
    state->u.f4.fld.f26r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB26"); 
    state->u.f4.fld.f26r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB27"); 
    state->u.f4.fld.f26r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB28"); 
    state->u.f4.fld.f26r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB29"); 
    state->u.f4.fld.f26r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB30"); 
    state->u.f4.fld.f26r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f26r2, "FB31");  
    
    // F27R1 bitfields.
    state->u.f4.fld.f27r1.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB0"); 
    state->u.f4.fld.f27r1.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB1"); 
    state->u.f4.fld.f27r1.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB2"); 
    state->u.f4.fld.f27r1.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB3"); 
    state->u.f4.fld.f27r1.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB4"); 
    state->u.f4.fld.f27r1.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB5"); 
    state->u.f4.fld.f27r1.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB6"); 
    state->u.f4.fld.f27r1.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB7"); 
    state->u.f4.fld.f27r1.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB8"); 
    state->u.f4.fld.f27r1.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB9"); 
    state->u.f4.fld.f27r1.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB10"); 
    state->u.f4.fld.f27r1.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB11"); 
    state->u.f4.fld.f27r1.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB12"); 
    state->u.f4.fld.f27r1.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB13"); 
    state->u.f4.fld.f27r1.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB14"); 
    state->u.f4.fld.f27r1.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB15"); 
    state->u.f4.fld.f27r1.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB16"); 
    state->u.f4.fld.f27r1.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB17"); 
    state->u.f4.fld.f27r1.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB18"); 
    state->u.f4.fld.f27r1.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB19"); 
    state->u.f4.fld.f27r1.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB20"); 
    state->u.f4.fld.f27r1.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB21"); 
    state->u.f4.fld.f27r1.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB22"); 
    state->u.f4.fld.f27r1.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB23"); 
    state->u.f4.fld.f27r1.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB24"); 
    state->u.f4.fld.f27r1.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB25"); 
    state->u.f4.fld.f27r1.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB26"); 
    state->u.f4.fld.f27r1.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB27"); 
    state->u.f4.fld.f27r1.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB28"); 
    state->u.f4.fld.f27r1.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB29"); 
    state->u.f4.fld.f27r1.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB30"); 
    state->u.f4.fld.f27r1.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f27r1, "FB31");  
    
    // F27R2 bitfields.
    state->u.f4.fld.f27r2.fb0 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB0"); 
    state->u.f4.fld.f27r2.fb1 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB1"); 
    state->u.f4.fld.f27r2.fb2 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB2"); 
    state->u.f4.fld.f27r2.fb3 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB3"); 
    state->u.f4.fld.f27r2.fb4 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB4"); 
    state->u.f4.fld.f27r2.fb5 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB5"); 
    state->u.f4.fld.f27r2.fb6 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB6"); 
    state->u.f4.fld.f27r2.fb7 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB7"); 
    state->u.f4.fld.f27r2.fb8 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB8"); 
    state->u.f4.fld.f27r2.fb9 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB9"); 
    state->u.f4.fld.f27r2.fb10 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB10"); 
    state->u.f4.fld.f27r2.fb11 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB11"); 
    state->u.f4.fld.f27r2.fb12 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB12"); 
    state->u.f4.fld.f27r2.fb13 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB13"); 
    state->u.f4.fld.f27r2.fb14 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB14"); 
    state->u.f4.fld.f27r2.fb15 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB15"); 
    state->u.f4.fld.f27r2.fb16 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB16"); 
    state->u.f4.fld.f27r2.fb17 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB17"); 
    state->u.f4.fld.f27r2.fb18 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB18"); 
    state->u.f4.fld.f27r2.fb19 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB19"); 
    state->u.f4.fld.f27r2.fb20 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB20"); 
    state->u.f4.fld.f27r2.fb21 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB21"); 
    state->u.f4.fld.f27r2.fb22 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB22"); 
    state->u.f4.fld.f27r2.fb23 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB23"); 
    state->u.f4.fld.f27r2.fb24 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB24"); 
    state->u.f4.fld.f27r2.fb25 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB25"); 
    state->u.f4.fld.f27r2.fb26 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB26"); 
    state->u.f4.fld.f27r2.fb27 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB27"); 
    state->u.f4.fld.f27r2.fb28 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB28"); 
    state->u.f4.fld.f27r2.fb29 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB29"); 
    state->u.f4.fld.f27r2.fb30 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB30"); 
    state->u.f4.fld.f27r2.fb31 = cm_object_get_child_by_name(state->u.f4.reg.f27r2, "FB31");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_can_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32CANState *state = STM32_CAN_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_can_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32CANState *state = STM32_CAN_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_can_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32CANState *state = STM32_CAN_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_can_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32CANState *state = STM32_CAN_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_can_is_enabled(Object *obj)
{
    STM32CANState *state = STM32_CAN_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_can_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32CANState *state = STM32_CAN_STATE(obj);

    // Capabilities are not yet available.

    cm_object_property_add_int(obj, "port-index",
            (const int *) &state->port_index);
    state->port_index = STM32_PORT_CAN_UNDEFINED;

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_can_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_CAN)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32CANState *state = STM32_CAN_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "CAN";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_429x ) {

            stm32f429x_can_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_can_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_can_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_can_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_can_xxx_post_write_callback);

            // TODO: add interrupts.

           // TODO: remove this if the peripheral is always enabled.
           snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/CAN%dEN",
                1 + state->port_index - STM32_PORT_CAN1);


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

static void stm32_can_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_CAN);
}

static void stm32_can_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_can_reset_callback;
    dc->realize = stm32_can_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_can_is_enabled;
}

static const TypeInfo stm32_can_type_info = {
    .name = TYPE_STM32_CAN,
    .parent = TYPE_STM32_CAN_PARENT,
    .instance_init = stm32_can_instance_init_callback,
    .instance_size = sizeof(STM32CANState),
    .class_init = stm32_can_class_init_callback,
    .class_size = sizeof(STM32CANClass) };

static void stm32_can_register_types(void)
{
    type_register_static(&stm32_can_type_info);
}

type_init(stm32_can_register_types);

// ----------------------------------------------------------------------------
