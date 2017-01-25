/*
 * STM32- CAN(Controller area network) emulation.
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
static void stm32f0x2_can_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32CANState *state = STM32_CAN_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
state->u.f0.reg.can_mcr= cm_object_get_child_by_name(obj, "CAN_MCR");
state->u.f0.reg.can_msr= cm_object_get_child_by_name(obj, "CAN_MSR");
state->u.f0.reg.can_tsr= cm_object_get_child_by_name(obj, "CAN_TSR");
state->u.f0.reg.can_rf0r= cm_object_get_child_by_name(obj, "CAN_RF0R");
state->u.f0.reg.can_rf1r= cm_object_get_child_by_name(obj, "CAN_RF1R");
state->u.f0.reg.can_ier= cm_object_get_child_by_name(obj, "CAN_IER");
state->u.f0.reg.can_esr= cm_object_get_child_by_name(obj, "CAN_ESR");
state->u.f0.reg.can_btr= cm_object_get_child_by_name(obj, "CAN_BTR");
state->u.f0.reg.can_ti0r= cm_object_get_child_by_name(obj, "CAN_TI0R");
state->u.f0.reg.can_tdt0r= cm_object_get_child_by_name(obj, "CAN_TDT0R");
state->u.f0.reg.can_tdl0r= cm_object_get_child_by_name(obj, "CAN_TDL0R");
state->u.f0.reg.can_tdh0r= cm_object_get_child_by_name(obj, "CAN_TDH0R");
state->u.f0.reg.can_ti1r= cm_object_get_child_by_name(obj, "CAN_TI1R");
state->u.f0.reg.can_tdt1r= cm_object_get_child_by_name(obj, "CAN_TDT1R");
state->u.f0.reg.can_tdl1r= cm_object_get_child_by_name(obj, "CAN_TDL1R");
state->u.f0.reg.can_tdh1r= cm_object_get_child_by_name(obj, "CAN_TDH1R");
state->u.f0.reg.can_ti2r= cm_object_get_child_by_name(obj, "CAN_TI2R");
state->u.f0.reg.can_tdt2r= cm_object_get_child_by_name(obj, "CAN_TDT2R");
state->u.f0.reg.can_tdl2r= cm_object_get_child_by_name(obj, "CAN_TDL2R");
state->u.f0.reg.can_tdh2r= cm_object_get_child_by_name(obj, "CAN_TDH2R");
state->u.f0.reg.can_ri0r= cm_object_get_child_by_name(obj, "CAN_RI0R");
state->u.f0.reg.can_rdt0r= cm_object_get_child_by_name(obj, "CAN_RDT0R");
state->u.f0.reg.can_rdl0r= cm_object_get_child_by_name(obj, "CAN_RDL0R");
state->u.f0.reg.can_rdh0r= cm_object_get_child_by_name(obj, "CAN_RDH0R");
state->u.f0.reg.can_ri1r= cm_object_get_child_by_name(obj, "CAN_RI1R");
state->u.f0.reg.can_rdt1r= cm_object_get_child_by_name(obj, "CAN_RDT1R");
state->u.f0.reg.can_rdl1r= cm_object_get_child_by_name(obj, "CAN_RDL1R");
state->u.f0.reg.can_rdh1r= cm_object_get_child_by_name(obj, "CAN_RDH1R");
state->u.f0.reg.can_fmr= cm_object_get_child_by_name(obj, "CAN_FMR");
state->u.f0.reg.can_fm1r= cm_object_get_child_by_name(obj, "CAN_FM1R");
state->u.f0.reg.can_fs1r= cm_object_get_child_by_name(obj, "CAN_FS1R");
state->u.f0.reg.can_ffa1r= cm_object_get_child_by_name(obj, "CAN_FFA1R");
state->u.f0.reg.can_fa1r= cm_object_get_child_by_name(obj, "CAN_FA1R");
state->u.f0.reg.f0r1= cm_object_get_child_by_name(obj, "F0R1");
state->u.f0.reg.f0r2= cm_object_get_child_by_name(obj, "F0R2");
state->u.f0.reg.f1r1= cm_object_get_child_by_name(obj, "F1R1");
state->u.f0.reg.f1r2= cm_object_get_child_by_name(obj, "F1R2");
state->u.f0.reg.f2r1= cm_object_get_child_by_name(obj, "F2R1");
state->u.f0.reg.f2r2= cm_object_get_child_by_name(obj, "F2R2");
state->u.f0.reg.f3r1= cm_object_get_child_by_name(obj, "F3R1");
state->u.f0.reg.f3r2= cm_object_get_child_by_name(obj, "F3R2");
state->u.f0.reg.f4r1= cm_object_get_child_by_name(obj, "F4R1");
state->u.f0.reg.f4r2= cm_object_get_child_by_name(obj, "F4R2");
state->u.f0.reg.f5r1= cm_object_get_child_by_name(obj, "F5R1");
state->u.f0.reg.f5r2= cm_object_get_child_by_name(obj, "F5R2");
state->u.f0.reg.f6r1= cm_object_get_child_by_name(obj, "F6R1");
state->u.f0.reg.f6r2= cm_object_get_child_by_name(obj, "F6R2");
state->u.f0.reg.f7r1= cm_object_get_child_by_name(obj, "F7R1");
state->u.f0.reg.f7r2= cm_object_get_child_by_name(obj, "F7R2");
state->u.f0.reg.f8r1= cm_object_get_child_by_name(obj, "F8R1");
state->u.f0.reg.f8r2= cm_object_get_child_by_name(obj, "F8R2");
state->u.f0.reg.f9r1= cm_object_get_child_by_name(obj, "F9R1");
state->u.f0.reg.f9r2= cm_object_get_child_by_name(obj, "F9R2");
state->u.f0.reg.f10r1= cm_object_get_child_by_name(obj, "F10R1");
state->u.f0.reg.f10r2= cm_object_get_child_by_name(obj, "F10R2");
state->u.f0.reg.f11r1= cm_object_get_child_by_name(obj, "F11R1");
state->u.f0.reg.f11r2= cm_object_get_child_by_name(obj, "F11R2");
state->u.f0.reg.f12r1= cm_object_get_child_by_name(obj, "F12R1");
state->u.f0.reg.f12r2= cm_object_get_child_by_name(obj, "F12R2");
state->u.f0.reg.f13r1= cm_object_get_child_by_name(obj, "F13R1");
state->u.f0.reg.f13r2= cm_object_get_child_by_name(obj, "F13R2");
state->u.f0.reg.f14r1= cm_object_get_child_by_name(obj, "F14R1");
state->u.f0.reg.f14r2= cm_object_get_child_by_name(obj, "F14R2");
state->u.f0.reg.f15r1= cm_object_get_child_by_name(obj, "F15R1");
state->u.f0.reg.f15r2= cm_object_get_child_by_name(obj, "F15R2");
state->u.f0.reg.f16r1= cm_object_get_child_by_name(obj, "F16R1");
state->u.f0.reg.f16r2= cm_object_get_child_by_name(obj, "F16R2");
state->u.f0.reg.f17r1= cm_object_get_child_by_name(obj, "F17R1");
state->u.f0.reg.f17r2= cm_object_get_child_by_name(obj, "F17R2");
state->u.f0.reg.f18r1= cm_object_get_child_by_name(obj, "F18R1");
state->u.f0.reg.f18r2= cm_object_get_child_by_name(obj, "F18R2");
state->u.f0.reg.f19r1= cm_object_get_child_by_name(obj, "F19R1");
state->u.f0.reg.f19r2= cm_object_get_child_by_name(obj, "F19R2");
state->u.f0.reg.f20r1= cm_object_get_child_by_name(obj, "F20R1");
state->u.f0.reg.f20r2= cm_object_get_child_by_name(obj, "F20R2");
state->u.f0.reg.f21r1= cm_object_get_child_by_name(obj, "F21R1");
state->u.f0.reg.f21r2= cm_object_get_child_by_name(obj, "F21R2");
state->u.f0.reg.f22r1= cm_object_get_child_by_name(obj, "F22R1");
state->u.f0.reg.f22r2= cm_object_get_child_by_name(obj, "F22R2");
state->u.f0.reg.f23r1= cm_object_get_child_by_name(obj, "F23R1");
state->u.f0.reg.f23r2= cm_object_get_child_by_name(obj, "F23R2");
state->u.f0.reg.f24r1= cm_object_get_child_by_name(obj, "F24R1");
state->u.f0.reg.f24r2= cm_object_get_child_by_name(obj, "F24R2");
state->u.f0.reg.f25r1= cm_object_get_child_by_name(obj, "F25R1");
state->u.f0.reg.f25r2= cm_object_get_child_by_name(obj, "F25R2");
state->u.f0.reg.f26r1= cm_object_get_child_by_name(obj, "F26R1");
state->u.f0.reg.f26r2= cm_object_get_child_by_name(obj, "F26R2");
state->u.f0.reg.f27r1= cm_object_get_child_by_name(obj, "F27R1");
state->u.f0.reg.f27r2= cm_object_get_child_by_name(obj, "F27R2");
// CAN_MCRbitfields.
state->u.f0.fld.can_mcr.inrq= cm_object_get_child_by_name(state->u.f0.reg.can_mcr, "INRQ"); 
state->u.f0.fld.can_mcr.sleep= cm_object_get_child_by_name(state->u.f0.reg.can_mcr, "SLEEP"); 
state->u.f0.fld.can_mcr.txfp= cm_object_get_child_by_name(state->u.f0.reg.can_mcr, "TXFP"); 
state->u.f0.fld.can_mcr.rflm= cm_object_get_child_by_name(state->u.f0.reg.can_mcr, "RFLM"); 
state->u.f0.fld.can_mcr.nart= cm_object_get_child_by_name(state->u.f0.reg.can_mcr, "NART"); 
state->u.f0.fld.can_mcr.awum= cm_object_get_child_by_name(state->u.f0.reg.can_mcr, "AWUM"); 
state->u.f0.fld.can_mcr.abom= cm_object_get_child_by_name(state->u.f0.reg.can_mcr, "ABOM"); 
state->u.f0.fld.can_mcr.ttcm= cm_object_get_child_by_name(state->u.f0.reg.can_mcr, "TTCM"); 
state->u.f0.fld.can_mcr.reset= cm_object_get_child_by_name(state->u.f0.reg.can_mcr, "RESET"); 
state->u.f0.fld.can_mcr.dbf= cm_object_get_child_by_name(state->u.f0.reg.can_mcr, "DBF"); 
// CAN_MSRbitfields.
state->u.f0.fld.can_msr.inak= cm_object_get_child_by_name(state->u.f0.reg.can_msr, "INAK"); 
state->u.f0.fld.can_msr.slak= cm_object_get_child_by_name(state->u.f0.reg.can_msr, "SLAK"); 
state->u.f0.fld.can_msr.erri= cm_object_get_child_by_name(state->u.f0.reg.can_msr, "ERRI"); 
state->u.f0.fld.can_msr.wkui= cm_object_get_child_by_name(state->u.f0.reg.can_msr, "WKUI"); 
state->u.f0.fld.can_msr.slaki= cm_object_get_child_by_name(state->u.f0.reg.can_msr, "SLAKI"); 
state->u.f0.fld.can_msr.txm= cm_object_get_child_by_name(state->u.f0.reg.can_msr, "TXM"); 
state->u.f0.fld.can_msr.rxm= cm_object_get_child_by_name(state->u.f0.reg.can_msr, "RXM"); 
state->u.f0.fld.can_msr.samp= cm_object_get_child_by_name(state->u.f0.reg.can_msr, "SAMP"); 
state->u.f0.fld.can_msr.rx= cm_object_get_child_by_name(state->u.f0.reg.can_msr, "RX"); 
// CAN_TSRbitfields.
state->u.f0.fld.can_tsr.rqcp0= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "RQCP0"); 
state->u.f0.fld.can_tsr.txok0= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "TXOK0"); 
state->u.f0.fld.can_tsr.alst0= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "ALST0"); 
state->u.f0.fld.can_tsr.terr0= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "TERR0"); 
state->u.f0.fld.can_tsr.abrq0= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "ABRQ0"); 
state->u.f0.fld.can_tsr.rqcp1= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "RQCP1"); 
state->u.f0.fld.can_tsr.txok1= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "TXOK1"); 
state->u.f0.fld.can_tsr.alst1= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "ALST1"); 
state->u.f0.fld.can_tsr.terr1= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "TERR1"); 
state->u.f0.fld.can_tsr.abrq1= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "ABRQ1"); 
state->u.f0.fld.can_tsr.rqcp2= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "RQCP2"); 
state->u.f0.fld.can_tsr.txok2= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "TXOK2"); 
state->u.f0.fld.can_tsr.alst2= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "ALST2"); 
state->u.f0.fld.can_tsr.terr2= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "TERR2"); 
state->u.f0.fld.can_tsr.abrq2= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "ABRQ2"); 
state->u.f0.fld.can_tsr.code= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "CODE"); 
state->u.f0.fld.can_tsr.tme0= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "TME0"); 
state->u.f0.fld.can_tsr.tme1= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "TME1"); 
state->u.f0.fld.can_tsr.tme2= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "TME2"); 
state->u.f0.fld.can_tsr.low0= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "LOW0"); 
state->u.f0.fld.can_tsr.low1= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "LOW1"); 
state->u.f0.fld.can_tsr.low2= cm_object_get_child_by_name(state->u.f0.reg.can_tsr, "LOW2"); 
// CAN_RF0Rbitfields.
state->u.f0.fld.can_rf0r.fmp0= cm_object_get_child_by_name(state->u.f0.reg.can_rf0r, "FMP0"); 
state->u.f0.fld.can_rf0r.full0= cm_object_get_child_by_name(state->u.f0.reg.can_rf0r, "FULL0"); 
state->u.f0.fld.can_rf0r.fovr0= cm_object_get_child_by_name(state->u.f0.reg.can_rf0r, "FOVR0"); 
state->u.f0.fld.can_rf0r.rfom0= cm_object_get_child_by_name(state->u.f0.reg.can_rf0r, "RFOM0"); 
// CAN_RF1Rbitfields.
state->u.f0.fld.can_rf1r.fmp1= cm_object_get_child_by_name(state->u.f0.reg.can_rf1r, "FMP1"); 
state->u.f0.fld.can_rf1r.full1= cm_object_get_child_by_name(state->u.f0.reg.can_rf1r, "FULL1"); 
state->u.f0.fld.can_rf1r.fovr1= cm_object_get_child_by_name(state->u.f0.reg.can_rf1r, "FOVR1"); 
state->u.f0.fld.can_rf1r.rfom1= cm_object_get_child_by_name(state->u.f0.reg.can_rf1r, "RFOM1"); 
// CAN_IERbitfields.
state->u.f0.fld.can_ier.tmeie= cm_object_get_child_by_name(state->u.f0.reg.can_ier, "TMEIE"); 
state->u.f0.fld.can_ier.fmpie0= cm_object_get_child_by_name(state->u.f0.reg.can_ier, "FMPIE0"); 
state->u.f0.fld.can_ier.ffie0= cm_object_get_child_by_name(state->u.f0.reg.can_ier, "FFIE0"); 
state->u.f0.fld.can_ier.fovie0= cm_object_get_child_by_name(state->u.f0.reg.can_ier, "FOVIE0"); 
state->u.f0.fld.can_ier.fmpie1= cm_object_get_child_by_name(state->u.f0.reg.can_ier, "FMPIE1"); 
state->u.f0.fld.can_ier.ffie1= cm_object_get_child_by_name(state->u.f0.reg.can_ier, "FFIE1"); 
state->u.f0.fld.can_ier.fovie1= cm_object_get_child_by_name(state->u.f0.reg.can_ier, "FOVIE1"); 
state->u.f0.fld.can_ier.ewgie= cm_object_get_child_by_name(state->u.f0.reg.can_ier, "EWGIE"); 
state->u.f0.fld.can_ier.epvie= cm_object_get_child_by_name(state->u.f0.reg.can_ier, "EPVIE"); 
state->u.f0.fld.can_ier.bofie= cm_object_get_child_by_name(state->u.f0.reg.can_ier, "BOFIE"); 
state->u.f0.fld.can_ier.lecie= cm_object_get_child_by_name(state->u.f0.reg.can_ier, "LECIE"); 
state->u.f0.fld.can_ier.errie= cm_object_get_child_by_name(state->u.f0.reg.can_ier, "ERRIE"); 
state->u.f0.fld.can_ier.wkuie= cm_object_get_child_by_name(state->u.f0.reg.can_ier, "WKUIE"); 
state->u.f0.fld.can_ier.slkie= cm_object_get_child_by_name(state->u.f0.reg.can_ier, "SLKIE"); 
// CAN_ESRbitfields.
state->u.f0.fld.can_esr.ewgf= cm_object_get_child_by_name(state->u.f0.reg.can_esr, "EWGF"); 
state->u.f0.fld.can_esr.epvf= cm_object_get_child_by_name(state->u.f0.reg.can_esr, "EPVF"); 
state->u.f0.fld.can_esr.boff= cm_object_get_child_by_name(state->u.f0.reg.can_esr, "BOFF"); 
state->u.f0.fld.can_esr.lec= cm_object_get_child_by_name(state->u.f0.reg.can_esr, "LEC"); 
state->u.f0.fld.can_esr.tec= cm_object_get_child_by_name(state->u.f0.reg.can_esr, "TEC"); 
state->u.f0.fld.can_esr.rec= cm_object_get_child_by_name(state->u.f0.reg.can_esr, "REC"); 
// CAN_BTRbitfields.
state->u.f0.fld.can_btr.brp= cm_object_get_child_by_name(state->u.f0.reg.can_btr, "BRP"); 
state->u.f0.fld.can_btr.ts1= cm_object_get_child_by_name(state->u.f0.reg.can_btr, "TS1"); 
state->u.f0.fld.can_btr.ts2= cm_object_get_child_by_name(state->u.f0.reg.can_btr, "TS2"); 
state->u.f0.fld.can_btr.sjw= cm_object_get_child_by_name(state->u.f0.reg.can_btr, "SJW"); 
state->u.f0.fld.can_btr.lbkm= cm_object_get_child_by_name(state->u.f0.reg.can_btr, "LBKM"); 
state->u.f0.fld.can_btr.silm= cm_object_get_child_by_name(state->u.f0.reg.can_btr, "SILM"); 
// CAN_TI0Rbitfields.
state->u.f0.fld.can_ti0r.txrq= cm_object_get_child_by_name(state->u.f0.reg.can_ti0r, "TXRQ"); 
state->u.f0.fld.can_ti0r.rtr= cm_object_get_child_by_name(state->u.f0.reg.can_ti0r, "RTR"); 
state->u.f0.fld.can_ti0r.ide= cm_object_get_child_by_name(state->u.f0.reg.can_ti0r, "IDE"); 
state->u.f0.fld.can_ti0r.exid= cm_object_get_child_by_name(state->u.f0.reg.can_ti0r, "EXID"); 
state->u.f0.fld.can_ti0r.stid= cm_object_get_child_by_name(state->u.f0.reg.can_ti0r, "STID"); 
// CAN_TDT0Rbitfields.
state->u.f0.fld.can_tdt0r.dlc= cm_object_get_child_by_name(state->u.f0.reg.can_tdt0r, "DLC"); 
state->u.f0.fld.can_tdt0r.tgt= cm_object_get_child_by_name(state->u.f0.reg.can_tdt0r, "TGT"); 
state->u.f0.fld.can_tdt0r.time= cm_object_get_child_by_name(state->u.f0.reg.can_tdt0r, "TIME"); 
// CAN_TDL0Rbitfields.
state->u.f0.fld.can_tdl0r.data0= cm_object_get_child_by_name(state->u.f0.reg.can_tdl0r, "DATA0"); 
state->u.f0.fld.can_tdl0r.data1= cm_object_get_child_by_name(state->u.f0.reg.can_tdl0r, "DATA1"); 
state->u.f0.fld.can_tdl0r.data2= cm_object_get_child_by_name(state->u.f0.reg.can_tdl0r, "DATA2"); 
state->u.f0.fld.can_tdl0r.data3= cm_object_get_child_by_name(state->u.f0.reg.can_tdl0r, "DATA3"); 
// CAN_TDH0Rbitfields.
state->u.f0.fld.can_tdh0r.data4= cm_object_get_child_by_name(state->u.f0.reg.can_tdh0r, "DATA4"); 
state->u.f0.fld.can_tdh0r.data5= cm_object_get_child_by_name(state->u.f0.reg.can_tdh0r, "DATA5"); 
state->u.f0.fld.can_tdh0r.data6= cm_object_get_child_by_name(state->u.f0.reg.can_tdh0r, "DATA6"); 
state->u.f0.fld.can_tdh0r.data7= cm_object_get_child_by_name(state->u.f0.reg.can_tdh0r, "DATA7"); 
// CAN_TI1Rbitfields.
state->u.f0.fld.can_ti1r.txrq= cm_object_get_child_by_name(state->u.f0.reg.can_ti1r, "TXRQ"); 
state->u.f0.fld.can_ti1r.rtr= cm_object_get_child_by_name(state->u.f0.reg.can_ti1r, "RTR"); 
state->u.f0.fld.can_ti1r.ide= cm_object_get_child_by_name(state->u.f0.reg.can_ti1r, "IDE"); 
state->u.f0.fld.can_ti1r.exid= cm_object_get_child_by_name(state->u.f0.reg.can_ti1r, "EXID"); 
state->u.f0.fld.can_ti1r.stid= cm_object_get_child_by_name(state->u.f0.reg.can_ti1r, "STID"); 
// CAN_TDT1Rbitfields.
state->u.f0.fld.can_tdt1r.dlc= cm_object_get_child_by_name(state->u.f0.reg.can_tdt1r, "DLC"); 
state->u.f0.fld.can_tdt1r.tgt= cm_object_get_child_by_name(state->u.f0.reg.can_tdt1r, "TGT"); 
state->u.f0.fld.can_tdt1r.time= cm_object_get_child_by_name(state->u.f0.reg.can_tdt1r, "TIME"); 
// CAN_TDL1Rbitfields.
state->u.f0.fld.can_tdl1r.data0= cm_object_get_child_by_name(state->u.f0.reg.can_tdl1r, "DATA0"); 
state->u.f0.fld.can_tdl1r.data1= cm_object_get_child_by_name(state->u.f0.reg.can_tdl1r, "DATA1"); 
state->u.f0.fld.can_tdl1r.data2= cm_object_get_child_by_name(state->u.f0.reg.can_tdl1r, "DATA2"); 
state->u.f0.fld.can_tdl1r.data3= cm_object_get_child_by_name(state->u.f0.reg.can_tdl1r, "DATA3"); 
// CAN_TDH1Rbitfields.
state->u.f0.fld.can_tdh1r.data4= cm_object_get_child_by_name(state->u.f0.reg.can_tdh1r, "DATA4"); 
state->u.f0.fld.can_tdh1r.data5= cm_object_get_child_by_name(state->u.f0.reg.can_tdh1r, "DATA5"); 
state->u.f0.fld.can_tdh1r.data6= cm_object_get_child_by_name(state->u.f0.reg.can_tdh1r, "DATA6"); 
state->u.f0.fld.can_tdh1r.data7= cm_object_get_child_by_name(state->u.f0.reg.can_tdh1r, "DATA7"); 
// CAN_TI2Rbitfields.
state->u.f0.fld.can_ti2r.txrq= cm_object_get_child_by_name(state->u.f0.reg.can_ti2r, "TXRQ"); 
state->u.f0.fld.can_ti2r.rtr= cm_object_get_child_by_name(state->u.f0.reg.can_ti2r, "RTR"); 
state->u.f0.fld.can_ti2r.ide= cm_object_get_child_by_name(state->u.f0.reg.can_ti2r, "IDE"); 
state->u.f0.fld.can_ti2r.exid= cm_object_get_child_by_name(state->u.f0.reg.can_ti2r, "EXID"); 
state->u.f0.fld.can_ti2r.stid= cm_object_get_child_by_name(state->u.f0.reg.can_ti2r, "STID"); 
// CAN_TDT2Rbitfields.
state->u.f0.fld.can_tdt2r.dlc= cm_object_get_child_by_name(state->u.f0.reg.can_tdt2r, "DLC"); 
state->u.f0.fld.can_tdt2r.tgt= cm_object_get_child_by_name(state->u.f0.reg.can_tdt2r, "TGT"); 
state->u.f0.fld.can_tdt2r.time= cm_object_get_child_by_name(state->u.f0.reg.can_tdt2r, "TIME"); 
// CAN_TDL2Rbitfields.
state->u.f0.fld.can_tdl2r.data0= cm_object_get_child_by_name(state->u.f0.reg.can_tdl2r, "DATA0"); 
state->u.f0.fld.can_tdl2r.data1= cm_object_get_child_by_name(state->u.f0.reg.can_tdl2r, "DATA1"); 
state->u.f0.fld.can_tdl2r.data2= cm_object_get_child_by_name(state->u.f0.reg.can_tdl2r, "DATA2"); 
state->u.f0.fld.can_tdl2r.data3= cm_object_get_child_by_name(state->u.f0.reg.can_tdl2r, "DATA3"); 
// CAN_TDH2Rbitfields.
state->u.f0.fld.can_tdh2r.data4= cm_object_get_child_by_name(state->u.f0.reg.can_tdh2r, "DATA4"); 
state->u.f0.fld.can_tdh2r.data5= cm_object_get_child_by_name(state->u.f0.reg.can_tdh2r, "DATA5"); 
state->u.f0.fld.can_tdh2r.data6= cm_object_get_child_by_name(state->u.f0.reg.can_tdh2r, "DATA6"); 
state->u.f0.fld.can_tdh2r.data7= cm_object_get_child_by_name(state->u.f0.reg.can_tdh2r, "DATA7"); 
// CAN_RI0Rbitfields.
state->u.f0.fld.can_ri0r.rtr= cm_object_get_child_by_name(state->u.f0.reg.can_ri0r, "RTR"); 
state->u.f0.fld.can_ri0r.ide= cm_object_get_child_by_name(state->u.f0.reg.can_ri0r, "IDE"); 
state->u.f0.fld.can_ri0r.exid= cm_object_get_child_by_name(state->u.f0.reg.can_ri0r, "EXID"); 
state->u.f0.fld.can_ri0r.stid= cm_object_get_child_by_name(state->u.f0.reg.can_ri0r, "STID"); 
// CAN_RDT0Rbitfields.
state->u.f0.fld.can_rdt0r.dlc= cm_object_get_child_by_name(state->u.f0.reg.can_rdt0r, "DLC"); 
state->u.f0.fld.can_rdt0r.fmi= cm_object_get_child_by_name(state->u.f0.reg.can_rdt0r, "FMI"); 
state->u.f0.fld.can_rdt0r.time= cm_object_get_child_by_name(state->u.f0.reg.can_rdt0r, "TIME"); 
// CAN_RDL0Rbitfields.
state->u.f0.fld.can_rdl0r.data0= cm_object_get_child_by_name(state->u.f0.reg.can_rdl0r, "DATA0"); 
state->u.f0.fld.can_rdl0r.data1= cm_object_get_child_by_name(state->u.f0.reg.can_rdl0r, "DATA1"); 
state->u.f0.fld.can_rdl0r.data2= cm_object_get_child_by_name(state->u.f0.reg.can_rdl0r, "DATA2"); 
state->u.f0.fld.can_rdl0r.data3= cm_object_get_child_by_name(state->u.f0.reg.can_rdl0r, "DATA3"); 
// CAN_RDH0Rbitfields.
state->u.f0.fld.can_rdh0r.data4= cm_object_get_child_by_name(state->u.f0.reg.can_rdh0r, "DATA4"); 
state->u.f0.fld.can_rdh0r.data5= cm_object_get_child_by_name(state->u.f0.reg.can_rdh0r, "DATA5"); 
state->u.f0.fld.can_rdh0r.data6= cm_object_get_child_by_name(state->u.f0.reg.can_rdh0r, "DATA6"); 
state->u.f0.fld.can_rdh0r.data7= cm_object_get_child_by_name(state->u.f0.reg.can_rdh0r, "DATA7"); 
// CAN_RI1Rbitfields.
state->u.f0.fld.can_ri1r.rtr= cm_object_get_child_by_name(state->u.f0.reg.can_ri1r, "RTR"); 
state->u.f0.fld.can_ri1r.ide= cm_object_get_child_by_name(state->u.f0.reg.can_ri1r, "IDE"); 
state->u.f0.fld.can_ri1r.exid= cm_object_get_child_by_name(state->u.f0.reg.can_ri1r, "EXID"); 
state->u.f0.fld.can_ri1r.stid= cm_object_get_child_by_name(state->u.f0.reg.can_ri1r, "STID"); 
// CAN_RDT1Rbitfields.
state->u.f0.fld.can_rdt1r.dlc= cm_object_get_child_by_name(state->u.f0.reg.can_rdt1r, "DLC"); 
state->u.f0.fld.can_rdt1r.fmi= cm_object_get_child_by_name(state->u.f0.reg.can_rdt1r, "FMI"); 
state->u.f0.fld.can_rdt1r.time= cm_object_get_child_by_name(state->u.f0.reg.can_rdt1r, "TIME"); 
// CAN_RDL1Rbitfields.
state->u.f0.fld.can_rdl1r.data0= cm_object_get_child_by_name(state->u.f0.reg.can_rdl1r, "DATA0"); 
state->u.f0.fld.can_rdl1r.data1= cm_object_get_child_by_name(state->u.f0.reg.can_rdl1r, "DATA1"); 
state->u.f0.fld.can_rdl1r.data2= cm_object_get_child_by_name(state->u.f0.reg.can_rdl1r, "DATA2"); 
state->u.f0.fld.can_rdl1r.data3= cm_object_get_child_by_name(state->u.f0.reg.can_rdl1r, "DATA3"); 
// CAN_RDH1Rbitfields.
state->u.f0.fld.can_rdh1r.data4= cm_object_get_child_by_name(state->u.f0.reg.can_rdh1r, "DATA4"); 
state->u.f0.fld.can_rdh1r.data5= cm_object_get_child_by_name(state->u.f0.reg.can_rdh1r, "DATA5"); 
state->u.f0.fld.can_rdh1r.data6= cm_object_get_child_by_name(state->u.f0.reg.can_rdh1r, "DATA6"); 
state->u.f0.fld.can_rdh1r.data7= cm_object_get_child_by_name(state->u.f0.reg.can_rdh1r, "DATA7"); 
// CAN_FMRbitfields.
state->u.f0.fld.can_fmr.finit= cm_object_get_child_by_name(state->u.f0.reg.can_fmr, "FINIT"); 
state->u.f0.fld.can_fmr.can2sb= cm_object_get_child_by_name(state->u.f0.reg.can_fmr, "CAN2SB"); 
// CAN_FM1Rbitfields.
state->u.f0.fld.can_fm1r.fbm0= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM0"); 
state->u.f0.fld.can_fm1r.fbm1= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM1"); 
state->u.f0.fld.can_fm1r.fbm2= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM2"); 
state->u.f0.fld.can_fm1r.fbm3= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM3"); 
state->u.f0.fld.can_fm1r.fbm4= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM4"); 
state->u.f0.fld.can_fm1r.fbm5= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM5"); 
state->u.f0.fld.can_fm1r.fbm6= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM6"); 
state->u.f0.fld.can_fm1r.fbm7= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM7"); 
state->u.f0.fld.can_fm1r.fbm8= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM8"); 
state->u.f0.fld.can_fm1r.fbm9= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM9"); 
state->u.f0.fld.can_fm1r.fbm10= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM10"); 
state->u.f0.fld.can_fm1r.fbm11= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM11"); 
state->u.f0.fld.can_fm1r.fbm12= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM12"); 
state->u.f0.fld.can_fm1r.fbm13= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM13"); 
state->u.f0.fld.can_fm1r.fbm14= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM14"); 
state->u.f0.fld.can_fm1r.fbm15= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM15"); 
state->u.f0.fld.can_fm1r.fbm16= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM16"); 
state->u.f0.fld.can_fm1r.fbm17= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM17"); 
state->u.f0.fld.can_fm1r.fbm18= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM18"); 
state->u.f0.fld.can_fm1r.fbm19= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM19"); 
state->u.f0.fld.can_fm1r.fbm20= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM20"); 
state->u.f0.fld.can_fm1r.fbm21= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM21"); 
state->u.f0.fld.can_fm1r.fbm22= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM22"); 
state->u.f0.fld.can_fm1r.fbm23= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM23"); 
state->u.f0.fld.can_fm1r.fbm24= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM24"); 
state->u.f0.fld.can_fm1r.fbm25= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM25"); 
state->u.f0.fld.can_fm1r.fbm26= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM26"); 
state->u.f0.fld.can_fm1r.fbm27= cm_object_get_child_by_name(state->u.f0.reg.can_fm1r, "FBM27"); 
// CAN_FS1Rbitfields.
state->u.f0.fld.can_fs1r.fsc0= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC0"); 
state->u.f0.fld.can_fs1r.fsc1= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC1"); 
state->u.f0.fld.can_fs1r.fsc2= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC2"); 
state->u.f0.fld.can_fs1r.fsc3= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC3"); 
state->u.f0.fld.can_fs1r.fsc4= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC4"); 
state->u.f0.fld.can_fs1r.fsc5= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC5"); 
state->u.f0.fld.can_fs1r.fsc6= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC6"); 
state->u.f0.fld.can_fs1r.fsc7= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC7"); 
state->u.f0.fld.can_fs1r.fsc8= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC8"); 
state->u.f0.fld.can_fs1r.fsc9= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC9"); 
state->u.f0.fld.can_fs1r.fsc10= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC10"); 
state->u.f0.fld.can_fs1r.fsc11= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC11"); 
state->u.f0.fld.can_fs1r.fsc12= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC12"); 
state->u.f0.fld.can_fs1r.fsc13= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC13"); 
state->u.f0.fld.can_fs1r.fsc14= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC14"); 
state->u.f0.fld.can_fs1r.fsc15= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC15"); 
state->u.f0.fld.can_fs1r.fsc16= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC16"); 
state->u.f0.fld.can_fs1r.fsc17= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC17"); 
state->u.f0.fld.can_fs1r.fsc18= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC18"); 
state->u.f0.fld.can_fs1r.fsc19= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC19"); 
state->u.f0.fld.can_fs1r.fsc20= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC20"); 
state->u.f0.fld.can_fs1r.fsc21= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC21"); 
state->u.f0.fld.can_fs1r.fsc22= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC22"); 
state->u.f0.fld.can_fs1r.fsc23= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC23"); 
state->u.f0.fld.can_fs1r.fsc24= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC24"); 
state->u.f0.fld.can_fs1r.fsc25= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC25"); 
state->u.f0.fld.can_fs1r.fsc26= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC26"); 
state->u.f0.fld.can_fs1r.fsc27= cm_object_get_child_by_name(state->u.f0.reg.can_fs1r, "FSC27"); 
// CAN_FFA1Rbitfields.
state->u.f0.fld.can_ffa1r.ffa0= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA0"); 
state->u.f0.fld.can_ffa1r.ffa1= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA1"); 
state->u.f0.fld.can_ffa1r.ffa2= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA2"); 
state->u.f0.fld.can_ffa1r.ffa3= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA3"); 
state->u.f0.fld.can_ffa1r.ffa4= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA4"); 
state->u.f0.fld.can_ffa1r.ffa5= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA5"); 
state->u.f0.fld.can_ffa1r.ffa6= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA6"); 
state->u.f0.fld.can_ffa1r.ffa7= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA7"); 
state->u.f0.fld.can_ffa1r.ffa8= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA8"); 
state->u.f0.fld.can_ffa1r.ffa9= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA9"); 
state->u.f0.fld.can_ffa1r.ffa10= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA10"); 
state->u.f0.fld.can_ffa1r.ffa11= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA11"); 
state->u.f0.fld.can_ffa1r.ffa12= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA12"); 
state->u.f0.fld.can_ffa1r.ffa13= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA13"); 
state->u.f0.fld.can_ffa1r.ffa14= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA14"); 
state->u.f0.fld.can_ffa1r.ffa15= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA15"); 
state->u.f0.fld.can_ffa1r.ffa16= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA16"); 
state->u.f0.fld.can_ffa1r.ffa17= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA17"); 
state->u.f0.fld.can_ffa1r.ffa18= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA18"); 
state->u.f0.fld.can_ffa1r.ffa19= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA19"); 
state->u.f0.fld.can_ffa1r.ffa20= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA20"); 
state->u.f0.fld.can_ffa1r.ffa21= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA21"); 
state->u.f0.fld.can_ffa1r.ffa22= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA22"); 
state->u.f0.fld.can_ffa1r.ffa23= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA23"); 
state->u.f0.fld.can_ffa1r.ffa24= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA24"); 
state->u.f0.fld.can_ffa1r.ffa25= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA25"); 
state->u.f0.fld.can_ffa1r.ffa26= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA26"); 
state->u.f0.fld.can_ffa1r.ffa27= cm_object_get_child_by_name(state->u.f0.reg.can_ffa1r, "FFA27"); 
// CAN_FA1Rbitfields.
state->u.f0.fld.can_fa1r.fact0= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT0"); 
state->u.f0.fld.can_fa1r.fact1= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT1"); 
state->u.f0.fld.can_fa1r.fact2= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT2"); 
state->u.f0.fld.can_fa1r.fact3= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT3"); 
state->u.f0.fld.can_fa1r.fact4= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT4"); 
state->u.f0.fld.can_fa1r.fact5= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT5"); 
state->u.f0.fld.can_fa1r.fact6= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT6"); 
state->u.f0.fld.can_fa1r.fact7= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT7"); 
state->u.f0.fld.can_fa1r.fact8= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT8"); 
state->u.f0.fld.can_fa1r.fact9= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT9"); 
state->u.f0.fld.can_fa1r.fact10= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT10"); 
state->u.f0.fld.can_fa1r.fact11= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT11"); 
state->u.f0.fld.can_fa1r.fact12= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT12"); 
state->u.f0.fld.can_fa1r.fact13= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT13"); 
state->u.f0.fld.can_fa1r.fact14= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT14"); 
state->u.f0.fld.can_fa1r.fact15= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT15"); 
state->u.f0.fld.can_fa1r.fact16= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT16"); 
state->u.f0.fld.can_fa1r.fact17= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT17"); 
state->u.f0.fld.can_fa1r.fact18= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT18"); 
state->u.f0.fld.can_fa1r.fact19= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT19"); 
state->u.f0.fld.can_fa1r.fact20= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT20"); 
state->u.f0.fld.can_fa1r.fact21= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT21"); 
state->u.f0.fld.can_fa1r.fact22= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT22"); 
state->u.f0.fld.can_fa1r.fact23= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT23"); 
state->u.f0.fld.can_fa1r.fact24= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT24"); 
state->u.f0.fld.can_fa1r.fact25= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT25"); 
state->u.f0.fld.can_fa1r.fact26= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT26"); 
state->u.f0.fld.can_fa1r.fact27= cm_object_get_child_by_name(state->u.f0.reg.can_fa1r, "FACT27"); 
// F0R1bitfields.
state->u.f0.fld.f0r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB0"); 
state->u.f0.fld.f0r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB1"); 
state->u.f0.fld.f0r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB2"); 
state->u.f0.fld.f0r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB3"); 
state->u.f0.fld.f0r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB4"); 
state->u.f0.fld.f0r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB5"); 
state->u.f0.fld.f0r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB6"); 
state->u.f0.fld.f0r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB7"); 
state->u.f0.fld.f0r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB8"); 
state->u.f0.fld.f0r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB9"); 
state->u.f0.fld.f0r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB10"); 
state->u.f0.fld.f0r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB11"); 
state->u.f0.fld.f0r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB12"); 
state->u.f0.fld.f0r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB13"); 
state->u.f0.fld.f0r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB14"); 
state->u.f0.fld.f0r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB15"); 
state->u.f0.fld.f0r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB16"); 
state->u.f0.fld.f0r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB17"); 
state->u.f0.fld.f0r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB18"); 
state->u.f0.fld.f0r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB19"); 
state->u.f0.fld.f0r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB20"); 
state->u.f0.fld.f0r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB21"); 
state->u.f0.fld.f0r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB22"); 
state->u.f0.fld.f0r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB23"); 
state->u.f0.fld.f0r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB24"); 
state->u.f0.fld.f0r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB25"); 
state->u.f0.fld.f0r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB26"); 
state->u.f0.fld.f0r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB27"); 
state->u.f0.fld.f0r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB28"); 
state->u.f0.fld.f0r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB29"); 
state->u.f0.fld.f0r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB30"); 
state->u.f0.fld.f0r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f0r1, "FB31"); 
// F0R2bitfields.
state->u.f0.fld.f0r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB0"); 
state->u.f0.fld.f0r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB1"); 
state->u.f0.fld.f0r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB2"); 
state->u.f0.fld.f0r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB3"); 
state->u.f0.fld.f0r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB4"); 
state->u.f0.fld.f0r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB5"); 
state->u.f0.fld.f0r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB6"); 
state->u.f0.fld.f0r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB7"); 
state->u.f0.fld.f0r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB8"); 
state->u.f0.fld.f0r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB9"); 
state->u.f0.fld.f0r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB10"); 
state->u.f0.fld.f0r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB11"); 
state->u.f0.fld.f0r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB12"); 
state->u.f0.fld.f0r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB13"); 
state->u.f0.fld.f0r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB14"); 
state->u.f0.fld.f0r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB15"); 
state->u.f0.fld.f0r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB16"); 
state->u.f0.fld.f0r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB17"); 
state->u.f0.fld.f0r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB18"); 
state->u.f0.fld.f0r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB19"); 
state->u.f0.fld.f0r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB20"); 
state->u.f0.fld.f0r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB21"); 
state->u.f0.fld.f0r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB22"); 
state->u.f0.fld.f0r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB23"); 
state->u.f0.fld.f0r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB24"); 
state->u.f0.fld.f0r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB25"); 
state->u.f0.fld.f0r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB26"); 
state->u.f0.fld.f0r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB27"); 
state->u.f0.fld.f0r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB28"); 
state->u.f0.fld.f0r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB29"); 
state->u.f0.fld.f0r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB30"); 
state->u.f0.fld.f0r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f0r2, "FB31"); 
// F1R1bitfields.
state->u.f0.fld.f1r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB0"); 
state->u.f0.fld.f1r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB1"); 
state->u.f0.fld.f1r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB2"); 
state->u.f0.fld.f1r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB3"); 
state->u.f0.fld.f1r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB4"); 
state->u.f0.fld.f1r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB5"); 
state->u.f0.fld.f1r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB6"); 
state->u.f0.fld.f1r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB7"); 
state->u.f0.fld.f1r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB8"); 
state->u.f0.fld.f1r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB9"); 
state->u.f0.fld.f1r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB10"); 
state->u.f0.fld.f1r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB11"); 
state->u.f0.fld.f1r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB12"); 
state->u.f0.fld.f1r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB13"); 
state->u.f0.fld.f1r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB14"); 
state->u.f0.fld.f1r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB15"); 
state->u.f0.fld.f1r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB16"); 
state->u.f0.fld.f1r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB17"); 
state->u.f0.fld.f1r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB18"); 
state->u.f0.fld.f1r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB19"); 
state->u.f0.fld.f1r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB20"); 
state->u.f0.fld.f1r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB21"); 
state->u.f0.fld.f1r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB22"); 
state->u.f0.fld.f1r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB23"); 
state->u.f0.fld.f1r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB24"); 
state->u.f0.fld.f1r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB25"); 
state->u.f0.fld.f1r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB26"); 
state->u.f0.fld.f1r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB27"); 
state->u.f0.fld.f1r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB28"); 
state->u.f0.fld.f1r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB29"); 
state->u.f0.fld.f1r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB30"); 
state->u.f0.fld.f1r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f1r1, "FB31"); 
// F1R2bitfields.
state->u.f0.fld.f1r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB0"); 
state->u.f0.fld.f1r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB1"); 
state->u.f0.fld.f1r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB2"); 
state->u.f0.fld.f1r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB3"); 
state->u.f0.fld.f1r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB4"); 
state->u.f0.fld.f1r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB5"); 
state->u.f0.fld.f1r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB6"); 
state->u.f0.fld.f1r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB7"); 
state->u.f0.fld.f1r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB8"); 
state->u.f0.fld.f1r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB9"); 
state->u.f0.fld.f1r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB10"); 
state->u.f0.fld.f1r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB11"); 
state->u.f0.fld.f1r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB12"); 
state->u.f0.fld.f1r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB13"); 
state->u.f0.fld.f1r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB14"); 
state->u.f0.fld.f1r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB15"); 
state->u.f0.fld.f1r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB16"); 
state->u.f0.fld.f1r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB17"); 
state->u.f0.fld.f1r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB18"); 
state->u.f0.fld.f1r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB19"); 
state->u.f0.fld.f1r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB20"); 
state->u.f0.fld.f1r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB21"); 
state->u.f0.fld.f1r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB22"); 
state->u.f0.fld.f1r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB23"); 
state->u.f0.fld.f1r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB24"); 
state->u.f0.fld.f1r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB25"); 
state->u.f0.fld.f1r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB26"); 
state->u.f0.fld.f1r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB27"); 
state->u.f0.fld.f1r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB28"); 
state->u.f0.fld.f1r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB29"); 
state->u.f0.fld.f1r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB30"); 
state->u.f0.fld.f1r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f1r2, "FB31"); 
// F2R1bitfields.
state->u.f0.fld.f2r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB0"); 
state->u.f0.fld.f2r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB1"); 
state->u.f0.fld.f2r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB2"); 
state->u.f0.fld.f2r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB3"); 
state->u.f0.fld.f2r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB4"); 
state->u.f0.fld.f2r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB5"); 
state->u.f0.fld.f2r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB6"); 
state->u.f0.fld.f2r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB7"); 
state->u.f0.fld.f2r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB8"); 
state->u.f0.fld.f2r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB9"); 
state->u.f0.fld.f2r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB10"); 
state->u.f0.fld.f2r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB11"); 
state->u.f0.fld.f2r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB12"); 
state->u.f0.fld.f2r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB13"); 
state->u.f0.fld.f2r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB14"); 
state->u.f0.fld.f2r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB15"); 
state->u.f0.fld.f2r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB16"); 
state->u.f0.fld.f2r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB17"); 
state->u.f0.fld.f2r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB18"); 
state->u.f0.fld.f2r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB19"); 
state->u.f0.fld.f2r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB20"); 
state->u.f0.fld.f2r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB21"); 
state->u.f0.fld.f2r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB22"); 
state->u.f0.fld.f2r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB23"); 
state->u.f0.fld.f2r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB24"); 
state->u.f0.fld.f2r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB25"); 
state->u.f0.fld.f2r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB26"); 
state->u.f0.fld.f2r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB27"); 
state->u.f0.fld.f2r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB28"); 
state->u.f0.fld.f2r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB29"); 
state->u.f0.fld.f2r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB30"); 
state->u.f0.fld.f2r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f2r1, "FB31"); 
// F2R2bitfields.
state->u.f0.fld.f2r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB0"); 
state->u.f0.fld.f2r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB1"); 
state->u.f0.fld.f2r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB2"); 
state->u.f0.fld.f2r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB3"); 
state->u.f0.fld.f2r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB4"); 
state->u.f0.fld.f2r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB5"); 
state->u.f0.fld.f2r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB6"); 
state->u.f0.fld.f2r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB7"); 
state->u.f0.fld.f2r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB8"); 
state->u.f0.fld.f2r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB9"); 
state->u.f0.fld.f2r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB10"); 
state->u.f0.fld.f2r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB11"); 
state->u.f0.fld.f2r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB12"); 
state->u.f0.fld.f2r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB13"); 
state->u.f0.fld.f2r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB14"); 
state->u.f0.fld.f2r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB15"); 
state->u.f0.fld.f2r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB16"); 
state->u.f0.fld.f2r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB17"); 
state->u.f0.fld.f2r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB18"); 
state->u.f0.fld.f2r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB19"); 
state->u.f0.fld.f2r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB20"); 
state->u.f0.fld.f2r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB21"); 
state->u.f0.fld.f2r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB22"); 
state->u.f0.fld.f2r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB23"); 
state->u.f0.fld.f2r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB24"); 
state->u.f0.fld.f2r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB25"); 
state->u.f0.fld.f2r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB26"); 
state->u.f0.fld.f2r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB27"); 
state->u.f0.fld.f2r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB28"); 
state->u.f0.fld.f2r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB29"); 
state->u.f0.fld.f2r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB30"); 
state->u.f0.fld.f2r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f2r2, "FB31"); 
// F3R1bitfields.
state->u.f0.fld.f3r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB0"); 
state->u.f0.fld.f3r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB1"); 
state->u.f0.fld.f3r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB2"); 
state->u.f0.fld.f3r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB3"); 
state->u.f0.fld.f3r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB4"); 
state->u.f0.fld.f3r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB5"); 
state->u.f0.fld.f3r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB6"); 
state->u.f0.fld.f3r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB7"); 
state->u.f0.fld.f3r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB8"); 
state->u.f0.fld.f3r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB9"); 
state->u.f0.fld.f3r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB10"); 
state->u.f0.fld.f3r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB11"); 
state->u.f0.fld.f3r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB12"); 
state->u.f0.fld.f3r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB13"); 
state->u.f0.fld.f3r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB14"); 
state->u.f0.fld.f3r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB15"); 
state->u.f0.fld.f3r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB16"); 
state->u.f0.fld.f3r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB17"); 
state->u.f0.fld.f3r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB18"); 
state->u.f0.fld.f3r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB19"); 
state->u.f0.fld.f3r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB20"); 
state->u.f0.fld.f3r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB21"); 
state->u.f0.fld.f3r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB22"); 
state->u.f0.fld.f3r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB23"); 
state->u.f0.fld.f3r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB24"); 
state->u.f0.fld.f3r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB25"); 
state->u.f0.fld.f3r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB26"); 
state->u.f0.fld.f3r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB27"); 
state->u.f0.fld.f3r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB28"); 
state->u.f0.fld.f3r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB29"); 
state->u.f0.fld.f3r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB30"); 
state->u.f0.fld.f3r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f3r1, "FB31"); 
// F3R2bitfields.
state->u.f0.fld.f3r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB0"); 
state->u.f0.fld.f3r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB1"); 
state->u.f0.fld.f3r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB2"); 
state->u.f0.fld.f3r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB3"); 
state->u.f0.fld.f3r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB4"); 
state->u.f0.fld.f3r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB5"); 
state->u.f0.fld.f3r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB6"); 
state->u.f0.fld.f3r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB7"); 
state->u.f0.fld.f3r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB8"); 
state->u.f0.fld.f3r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB9"); 
state->u.f0.fld.f3r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB10"); 
state->u.f0.fld.f3r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB11"); 
state->u.f0.fld.f3r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB12"); 
state->u.f0.fld.f3r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB13"); 
state->u.f0.fld.f3r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB14"); 
state->u.f0.fld.f3r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB15"); 
state->u.f0.fld.f3r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB16"); 
state->u.f0.fld.f3r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB17"); 
state->u.f0.fld.f3r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB18"); 
state->u.f0.fld.f3r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB19"); 
state->u.f0.fld.f3r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB20"); 
state->u.f0.fld.f3r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB21"); 
state->u.f0.fld.f3r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB22"); 
state->u.f0.fld.f3r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB23"); 
state->u.f0.fld.f3r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB24"); 
state->u.f0.fld.f3r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB25"); 
state->u.f0.fld.f3r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB26"); 
state->u.f0.fld.f3r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB27"); 
state->u.f0.fld.f3r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB28"); 
state->u.f0.fld.f3r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB29"); 
state->u.f0.fld.f3r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB30"); 
state->u.f0.fld.f3r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f3r2, "FB31"); 
// F4R1bitfields.
state->u.f0.fld.f4r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB0"); 
state->u.f0.fld.f4r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB1"); 
state->u.f0.fld.f4r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB2"); 
state->u.f0.fld.f4r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB3"); 
state->u.f0.fld.f4r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB4"); 
state->u.f0.fld.f4r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB5"); 
state->u.f0.fld.f4r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB6"); 
state->u.f0.fld.f4r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB7"); 
state->u.f0.fld.f4r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB8"); 
state->u.f0.fld.f4r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB9"); 
state->u.f0.fld.f4r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB10"); 
state->u.f0.fld.f4r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB11"); 
state->u.f0.fld.f4r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB12"); 
state->u.f0.fld.f4r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB13"); 
state->u.f0.fld.f4r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB14"); 
state->u.f0.fld.f4r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB15"); 
state->u.f0.fld.f4r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB16"); 
state->u.f0.fld.f4r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB17"); 
state->u.f0.fld.f4r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB18"); 
state->u.f0.fld.f4r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB19"); 
state->u.f0.fld.f4r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB20"); 
state->u.f0.fld.f4r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB21"); 
state->u.f0.fld.f4r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB22"); 
state->u.f0.fld.f4r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB23"); 
state->u.f0.fld.f4r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB24"); 
state->u.f0.fld.f4r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB25"); 
state->u.f0.fld.f4r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB26"); 
state->u.f0.fld.f4r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB27"); 
state->u.f0.fld.f4r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB28"); 
state->u.f0.fld.f4r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB29"); 
state->u.f0.fld.f4r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB30"); 
state->u.f0.fld.f4r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f4r1, "FB31"); 
// F4R2bitfields.
state->u.f0.fld.f4r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB0"); 
state->u.f0.fld.f4r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB1"); 
state->u.f0.fld.f4r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB2"); 
state->u.f0.fld.f4r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB3"); 
state->u.f0.fld.f4r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB4"); 
state->u.f0.fld.f4r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB5"); 
state->u.f0.fld.f4r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB6"); 
state->u.f0.fld.f4r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB7"); 
state->u.f0.fld.f4r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB8"); 
state->u.f0.fld.f4r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB9"); 
state->u.f0.fld.f4r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB10"); 
state->u.f0.fld.f4r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB11"); 
state->u.f0.fld.f4r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB12"); 
state->u.f0.fld.f4r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB13"); 
state->u.f0.fld.f4r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB14"); 
state->u.f0.fld.f4r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB15"); 
state->u.f0.fld.f4r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB16"); 
state->u.f0.fld.f4r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB17"); 
state->u.f0.fld.f4r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB18"); 
state->u.f0.fld.f4r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB19"); 
state->u.f0.fld.f4r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB20"); 
state->u.f0.fld.f4r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB21"); 
state->u.f0.fld.f4r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB22"); 
state->u.f0.fld.f4r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB23"); 
state->u.f0.fld.f4r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB24"); 
state->u.f0.fld.f4r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB25"); 
state->u.f0.fld.f4r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB26"); 
state->u.f0.fld.f4r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB27"); 
state->u.f0.fld.f4r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB28"); 
state->u.f0.fld.f4r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB29"); 
state->u.f0.fld.f4r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB30"); 
state->u.f0.fld.f4r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f4r2, "FB31"); 
// F5R1bitfields.
state->u.f0.fld.f5r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB0"); 
state->u.f0.fld.f5r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB1"); 
state->u.f0.fld.f5r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB2"); 
state->u.f0.fld.f5r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB3"); 
state->u.f0.fld.f5r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB4"); 
state->u.f0.fld.f5r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB5"); 
state->u.f0.fld.f5r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB6"); 
state->u.f0.fld.f5r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB7"); 
state->u.f0.fld.f5r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB8"); 
state->u.f0.fld.f5r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB9"); 
state->u.f0.fld.f5r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB10"); 
state->u.f0.fld.f5r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB11"); 
state->u.f0.fld.f5r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB12"); 
state->u.f0.fld.f5r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB13"); 
state->u.f0.fld.f5r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB14"); 
state->u.f0.fld.f5r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB15"); 
state->u.f0.fld.f5r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB16"); 
state->u.f0.fld.f5r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB17"); 
state->u.f0.fld.f5r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB18"); 
state->u.f0.fld.f5r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB19"); 
state->u.f0.fld.f5r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB20"); 
state->u.f0.fld.f5r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB21"); 
state->u.f0.fld.f5r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB22"); 
state->u.f0.fld.f5r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB23"); 
state->u.f0.fld.f5r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB24"); 
state->u.f0.fld.f5r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB25"); 
state->u.f0.fld.f5r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB26"); 
state->u.f0.fld.f5r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB27"); 
state->u.f0.fld.f5r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB28"); 
state->u.f0.fld.f5r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB29"); 
state->u.f0.fld.f5r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB30"); 
state->u.f0.fld.f5r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f5r1, "FB31"); 
// F5R2bitfields.
state->u.f0.fld.f5r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB0"); 
state->u.f0.fld.f5r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB1"); 
state->u.f0.fld.f5r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB2"); 
state->u.f0.fld.f5r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB3"); 
state->u.f0.fld.f5r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB4"); 
state->u.f0.fld.f5r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB5"); 
state->u.f0.fld.f5r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB6"); 
state->u.f0.fld.f5r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB7"); 
state->u.f0.fld.f5r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB8"); 
state->u.f0.fld.f5r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB9"); 
state->u.f0.fld.f5r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB10"); 
state->u.f0.fld.f5r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB11"); 
state->u.f0.fld.f5r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB12"); 
state->u.f0.fld.f5r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB13"); 
state->u.f0.fld.f5r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB14"); 
state->u.f0.fld.f5r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB15"); 
state->u.f0.fld.f5r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB16"); 
state->u.f0.fld.f5r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB17"); 
state->u.f0.fld.f5r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB18"); 
state->u.f0.fld.f5r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB19"); 
state->u.f0.fld.f5r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB20"); 
state->u.f0.fld.f5r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB21"); 
state->u.f0.fld.f5r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB22"); 
state->u.f0.fld.f5r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB23"); 
state->u.f0.fld.f5r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB24"); 
state->u.f0.fld.f5r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB25"); 
state->u.f0.fld.f5r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB26"); 
state->u.f0.fld.f5r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB27"); 
state->u.f0.fld.f5r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB28"); 
state->u.f0.fld.f5r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB29"); 
state->u.f0.fld.f5r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB30"); 
state->u.f0.fld.f5r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f5r2, "FB31"); 
// F6R1bitfields.
state->u.f0.fld.f6r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB0"); 
state->u.f0.fld.f6r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB1"); 
state->u.f0.fld.f6r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB2"); 
state->u.f0.fld.f6r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB3"); 
state->u.f0.fld.f6r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB4"); 
state->u.f0.fld.f6r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB5"); 
state->u.f0.fld.f6r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB6"); 
state->u.f0.fld.f6r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB7"); 
state->u.f0.fld.f6r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB8"); 
state->u.f0.fld.f6r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB9"); 
state->u.f0.fld.f6r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB10"); 
state->u.f0.fld.f6r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB11"); 
state->u.f0.fld.f6r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB12"); 
state->u.f0.fld.f6r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB13"); 
state->u.f0.fld.f6r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB14"); 
state->u.f0.fld.f6r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB15"); 
state->u.f0.fld.f6r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB16"); 
state->u.f0.fld.f6r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB17"); 
state->u.f0.fld.f6r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB18"); 
state->u.f0.fld.f6r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB19"); 
state->u.f0.fld.f6r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB20"); 
state->u.f0.fld.f6r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB21"); 
state->u.f0.fld.f6r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB22"); 
state->u.f0.fld.f6r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB23"); 
state->u.f0.fld.f6r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB24"); 
state->u.f0.fld.f6r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB25"); 
state->u.f0.fld.f6r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB26"); 
state->u.f0.fld.f6r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB27"); 
state->u.f0.fld.f6r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB28"); 
state->u.f0.fld.f6r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB29"); 
state->u.f0.fld.f6r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB30"); 
state->u.f0.fld.f6r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f6r1, "FB31"); 
// F6R2bitfields.
state->u.f0.fld.f6r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB0"); 
state->u.f0.fld.f6r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB1"); 
state->u.f0.fld.f6r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB2"); 
state->u.f0.fld.f6r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB3"); 
state->u.f0.fld.f6r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB4"); 
state->u.f0.fld.f6r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB5"); 
state->u.f0.fld.f6r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB6"); 
state->u.f0.fld.f6r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB7"); 
state->u.f0.fld.f6r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB8"); 
state->u.f0.fld.f6r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB9"); 
state->u.f0.fld.f6r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB10"); 
state->u.f0.fld.f6r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB11"); 
state->u.f0.fld.f6r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB12"); 
state->u.f0.fld.f6r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB13"); 
state->u.f0.fld.f6r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB14"); 
state->u.f0.fld.f6r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB15"); 
state->u.f0.fld.f6r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB16"); 
state->u.f0.fld.f6r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB17"); 
state->u.f0.fld.f6r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB18"); 
state->u.f0.fld.f6r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB19"); 
state->u.f0.fld.f6r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB20"); 
state->u.f0.fld.f6r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB21"); 
state->u.f0.fld.f6r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB22"); 
state->u.f0.fld.f6r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB23"); 
state->u.f0.fld.f6r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB24"); 
state->u.f0.fld.f6r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB25"); 
state->u.f0.fld.f6r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB26"); 
state->u.f0.fld.f6r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB27"); 
state->u.f0.fld.f6r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB28"); 
state->u.f0.fld.f6r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB29"); 
state->u.f0.fld.f6r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB30"); 
state->u.f0.fld.f6r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f6r2, "FB31"); 
// F7R1bitfields.
state->u.f0.fld.f7r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB0"); 
state->u.f0.fld.f7r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB1"); 
state->u.f0.fld.f7r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB2"); 
state->u.f0.fld.f7r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB3"); 
state->u.f0.fld.f7r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB4"); 
state->u.f0.fld.f7r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB5"); 
state->u.f0.fld.f7r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB6"); 
state->u.f0.fld.f7r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB7"); 
state->u.f0.fld.f7r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB8"); 
state->u.f0.fld.f7r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB9"); 
state->u.f0.fld.f7r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB10"); 
state->u.f0.fld.f7r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB11"); 
state->u.f0.fld.f7r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB12"); 
state->u.f0.fld.f7r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB13"); 
state->u.f0.fld.f7r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB14"); 
state->u.f0.fld.f7r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB15"); 
state->u.f0.fld.f7r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB16"); 
state->u.f0.fld.f7r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB17"); 
state->u.f0.fld.f7r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB18"); 
state->u.f0.fld.f7r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB19"); 
state->u.f0.fld.f7r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB20"); 
state->u.f0.fld.f7r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB21"); 
state->u.f0.fld.f7r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB22"); 
state->u.f0.fld.f7r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB23"); 
state->u.f0.fld.f7r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB24"); 
state->u.f0.fld.f7r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB25"); 
state->u.f0.fld.f7r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB26"); 
state->u.f0.fld.f7r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB27"); 
state->u.f0.fld.f7r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB28"); 
state->u.f0.fld.f7r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB29"); 
state->u.f0.fld.f7r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB30"); 
state->u.f0.fld.f7r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f7r1, "FB31"); 
// F7R2bitfields.
state->u.f0.fld.f7r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB0"); 
state->u.f0.fld.f7r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB1"); 
state->u.f0.fld.f7r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB2"); 
state->u.f0.fld.f7r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB3"); 
state->u.f0.fld.f7r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB4"); 
state->u.f0.fld.f7r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB5"); 
state->u.f0.fld.f7r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB6"); 
state->u.f0.fld.f7r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB7"); 
state->u.f0.fld.f7r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB8"); 
state->u.f0.fld.f7r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB9"); 
state->u.f0.fld.f7r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB10"); 
state->u.f0.fld.f7r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB11"); 
state->u.f0.fld.f7r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB12"); 
state->u.f0.fld.f7r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB13"); 
state->u.f0.fld.f7r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB14"); 
state->u.f0.fld.f7r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB15"); 
state->u.f0.fld.f7r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB16"); 
state->u.f0.fld.f7r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB17"); 
state->u.f0.fld.f7r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB18"); 
state->u.f0.fld.f7r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB19"); 
state->u.f0.fld.f7r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB20"); 
state->u.f0.fld.f7r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB21"); 
state->u.f0.fld.f7r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB22"); 
state->u.f0.fld.f7r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB23"); 
state->u.f0.fld.f7r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB24"); 
state->u.f0.fld.f7r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB25"); 
state->u.f0.fld.f7r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB26"); 
state->u.f0.fld.f7r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB27"); 
state->u.f0.fld.f7r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB28"); 
state->u.f0.fld.f7r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB29"); 
state->u.f0.fld.f7r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB30"); 
state->u.f0.fld.f7r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f7r2, "FB31"); 
// F8R1bitfields.
state->u.f0.fld.f8r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB0"); 
state->u.f0.fld.f8r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB1"); 
state->u.f0.fld.f8r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB2"); 
state->u.f0.fld.f8r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB3"); 
state->u.f0.fld.f8r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB4"); 
state->u.f0.fld.f8r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB5"); 
state->u.f0.fld.f8r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB6"); 
state->u.f0.fld.f8r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB7"); 
state->u.f0.fld.f8r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB8"); 
state->u.f0.fld.f8r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB9"); 
state->u.f0.fld.f8r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB10"); 
state->u.f0.fld.f8r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB11"); 
state->u.f0.fld.f8r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB12"); 
state->u.f0.fld.f8r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB13"); 
state->u.f0.fld.f8r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB14"); 
state->u.f0.fld.f8r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB15"); 
state->u.f0.fld.f8r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB16"); 
state->u.f0.fld.f8r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB17"); 
state->u.f0.fld.f8r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB18"); 
state->u.f0.fld.f8r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB19"); 
state->u.f0.fld.f8r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB20"); 
state->u.f0.fld.f8r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB21"); 
state->u.f0.fld.f8r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB22"); 
state->u.f0.fld.f8r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB23"); 
state->u.f0.fld.f8r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB24"); 
state->u.f0.fld.f8r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB25"); 
state->u.f0.fld.f8r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB26"); 
state->u.f0.fld.f8r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB27"); 
state->u.f0.fld.f8r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB28"); 
state->u.f0.fld.f8r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB29"); 
state->u.f0.fld.f8r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB30"); 
state->u.f0.fld.f8r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f8r1, "FB31"); 
// F8R2bitfields.
state->u.f0.fld.f8r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB0"); 
state->u.f0.fld.f8r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB1"); 
state->u.f0.fld.f8r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB2"); 
state->u.f0.fld.f8r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB3"); 
state->u.f0.fld.f8r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB4"); 
state->u.f0.fld.f8r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB5"); 
state->u.f0.fld.f8r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB6"); 
state->u.f0.fld.f8r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB7"); 
state->u.f0.fld.f8r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB8"); 
state->u.f0.fld.f8r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB9"); 
state->u.f0.fld.f8r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB10"); 
state->u.f0.fld.f8r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB11"); 
state->u.f0.fld.f8r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB12"); 
state->u.f0.fld.f8r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB13"); 
state->u.f0.fld.f8r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB14"); 
state->u.f0.fld.f8r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB15"); 
state->u.f0.fld.f8r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB16"); 
state->u.f0.fld.f8r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB17"); 
state->u.f0.fld.f8r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB18"); 
state->u.f0.fld.f8r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB19"); 
state->u.f0.fld.f8r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB20"); 
state->u.f0.fld.f8r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB21"); 
state->u.f0.fld.f8r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB22"); 
state->u.f0.fld.f8r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB23"); 
state->u.f0.fld.f8r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB24"); 
state->u.f0.fld.f8r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB25"); 
state->u.f0.fld.f8r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB26"); 
state->u.f0.fld.f8r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB27"); 
state->u.f0.fld.f8r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB28"); 
state->u.f0.fld.f8r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB29"); 
state->u.f0.fld.f8r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB30"); 
state->u.f0.fld.f8r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f8r2, "FB31"); 
// F9R1bitfields.
state->u.f0.fld.f9r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB0"); 
state->u.f0.fld.f9r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB1"); 
state->u.f0.fld.f9r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB2"); 
state->u.f0.fld.f9r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB3"); 
state->u.f0.fld.f9r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB4"); 
state->u.f0.fld.f9r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB5"); 
state->u.f0.fld.f9r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB6"); 
state->u.f0.fld.f9r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB7"); 
state->u.f0.fld.f9r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB8"); 
state->u.f0.fld.f9r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB9"); 
state->u.f0.fld.f9r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB10"); 
state->u.f0.fld.f9r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB11"); 
state->u.f0.fld.f9r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB12"); 
state->u.f0.fld.f9r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB13"); 
state->u.f0.fld.f9r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB14"); 
state->u.f0.fld.f9r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB15"); 
state->u.f0.fld.f9r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB16"); 
state->u.f0.fld.f9r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB17"); 
state->u.f0.fld.f9r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB18"); 
state->u.f0.fld.f9r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB19"); 
state->u.f0.fld.f9r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB20"); 
state->u.f0.fld.f9r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB21"); 
state->u.f0.fld.f9r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB22"); 
state->u.f0.fld.f9r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB23"); 
state->u.f0.fld.f9r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB24"); 
state->u.f0.fld.f9r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB25"); 
state->u.f0.fld.f9r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB26"); 
state->u.f0.fld.f9r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB27"); 
state->u.f0.fld.f9r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB28"); 
state->u.f0.fld.f9r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB29"); 
state->u.f0.fld.f9r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB30"); 
state->u.f0.fld.f9r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f9r1, "FB31"); 
// F9R2bitfields.
state->u.f0.fld.f9r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB0"); 
state->u.f0.fld.f9r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB1"); 
state->u.f0.fld.f9r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB2"); 
state->u.f0.fld.f9r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB3"); 
state->u.f0.fld.f9r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB4"); 
state->u.f0.fld.f9r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB5"); 
state->u.f0.fld.f9r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB6"); 
state->u.f0.fld.f9r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB7"); 
state->u.f0.fld.f9r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB8"); 
state->u.f0.fld.f9r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB9"); 
state->u.f0.fld.f9r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB10"); 
state->u.f0.fld.f9r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB11"); 
state->u.f0.fld.f9r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB12"); 
state->u.f0.fld.f9r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB13"); 
state->u.f0.fld.f9r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB14"); 
state->u.f0.fld.f9r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB15"); 
state->u.f0.fld.f9r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB16"); 
state->u.f0.fld.f9r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB17"); 
state->u.f0.fld.f9r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB18"); 
state->u.f0.fld.f9r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB19"); 
state->u.f0.fld.f9r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB20"); 
state->u.f0.fld.f9r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB21"); 
state->u.f0.fld.f9r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB22"); 
state->u.f0.fld.f9r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB23"); 
state->u.f0.fld.f9r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB24"); 
state->u.f0.fld.f9r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB25"); 
state->u.f0.fld.f9r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB26"); 
state->u.f0.fld.f9r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB27"); 
state->u.f0.fld.f9r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB28"); 
state->u.f0.fld.f9r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB29"); 
state->u.f0.fld.f9r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB30"); 
state->u.f0.fld.f9r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f9r2, "FB31"); 
// F10R1bitfields.
state->u.f0.fld.f10r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB0"); 
state->u.f0.fld.f10r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB1"); 
state->u.f0.fld.f10r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB2"); 
state->u.f0.fld.f10r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB3"); 
state->u.f0.fld.f10r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB4"); 
state->u.f0.fld.f10r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB5"); 
state->u.f0.fld.f10r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB6"); 
state->u.f0.fld.f10r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB7"); 
state->u.f0.fld.f10r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB8"); 
state->u.f0.fld.f10r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB9"); 
state->u.f0.fld.f10r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB10"); 
state->u.f0.fld.f10r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB11"); 
state->u.f0.fld.f10r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB12"); 
state->u.f0.fld.f10r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB13"); 
state->u.f0.fld.f10r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB14"); 
state->u.f0.fld.f10r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB15"); 
state->u.f0.fld.f10r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB16"); 
state->u.f0.fld.f10r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB17"); 
state->u.f0.fld.f10r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB18"); 
state->u.f0.fld.f10r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB19"); 
state->u.f0.fld.f10r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB20"); 
state->u.f0.fld.f10r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB21"); 
state->u.f0.fld.f10r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB22"); 
state->u.f0.fld.f10r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB23"); 
state->u.f0.fld.f10r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB24"); 
state->u.f0.fld.f10r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB25"); 
state->u.f0.fld.f10r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB26"); 
state->u.f0.fld.f10r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB27"); 
state->u.f0.fld.f10r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB28"); 
state->u.f0.fld.f10r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB29"); 
state->u.f0.fld.f10r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB30"); 
state->u.f0.fld.f10r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f10r1, "FB31"); 
// F10R2bitfields.
state->u.f0.fld.f10r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB0"); 
state->u.f0.fld.f10r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB1"); 
state->u.f0.fld.f10r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB2"); 
state->u.f0.fld.f10r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB3"); 
state->u.f0.fld.f10r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB4"); 
state->u.f0.fld.f10r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB5"); 
state->u.f0.fld.f10r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB6"); 
state->u.f0.fld.f10r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB7"); 
state->u.f0.fld.f10r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB8"); 
state->u.f0.fld.f10r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB9"); 
state->u.f0.fld.f10r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB10"); 
state->u.f0.fld.f10r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB11"); 
state->u.f0.fld.f10r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB12"); 
state->u.f0.fld.f10r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB13"); 
state->u.f0.fld.f10r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB14"); 
state->u.f0.fld.f10r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB15"); 
state->u.f0.fld.f10r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB16"); 
state->u.f0.fld.f10r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB17"); 
state->u.f0.fld.f10r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB18"); 
state->u.f0.fld.f10r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB19"); 
state->u.f0.fld.f10r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB20"); 
state->u.f0.fld.f10r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB21"); 
state->u.f0.fld.f10r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB22"); 
state->u.f0.fld.f10r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB23"); 
state->u.f0.fld.f10r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB24"); 
state->u.f0.fld.f10r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB25"); 
state->u.f0.fld.f10r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB26"); 
state->u.f0.fld.f10r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB27"); 
state->u.f0.fld.f10r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB28"); 
state->u.f0.fld.f10r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB29"); 
state->u.f0.fld.f10r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB30"); 
state->u.f0.fld.f10r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f10r2, "FB31"); 
// F11R1bitfields.
state->u.f0.fld.f11r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB0"); 
state->u.f0.fld.f11r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB1"); 
state->u.f0.fld.f11r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB2"); 
state->u.f0.fld.f11r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB3"); 
state->u.f0.fld.f11r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB4"); 
state->u.f0.fld.f11r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB5"); 
state->u.f0.fld.f11r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB6"); 
state->u.f0.fld.f11r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB7"); 
state->u.f0.fld.f11r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB8"); 
state->u.f0.fld.f11r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB9"); 
state->u.f0.fld.f11r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB10"); 
state->u.f0.fld.f11r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB11"); 
state->u.f0.fld.f11r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB12"); 
state->u.f0.fld.f11r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB13"); 
state->u.f0.fld.f11r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB14"); 
state->u.f0.fld.f11r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB15"); 
state->u.f0.fld.f11r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB16"); 
state->u.f0.fld.f11r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB17"); 
state->u.f0.fld.f11r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB18"); 
state->u.f0.fld.f11r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB19"); 
state->u.f0.fld.f11r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB20"); 
state->u.f0.fld.f11r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB21"); 
state->u.f0.fld.f11r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB22"); 
state->u.f0.fld.f11r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB23"); 
state->u.f0.fld.f11r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB24"); 
state->u.f0.fld.f11r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB25"); 
state->u.f0.fld.f11r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB26"); 
state->u.f0.fld.f11r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB27"); 
state->u.f0.fld.f11r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB28"); 
state->u.f0.fld.f11r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB29"); 
state->u.f0.fld.f11r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB30"); 
state->u.f0.fld.f11r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f11r1, "FB31"); 
// F11R2bitfields.
state->u.f0.fld.f11r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB0"); 
state->u.f0.fld.f11r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB1"); 
state->u.f0.fld.f11r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB2"); 
state->u.f0.fld.f11r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB3"); 
state->u.f0.fld.f11r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB4"); 
state->u.f0.fld.f11r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB5"); 
state->u.f0.fld.f11r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB6"); 
state->u.f0.fld.f11r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB7"); 
state->u.f0.fld.f11r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB8"); 
state->u.f0.fld.f11r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB9"); 
state->u.f0.fld.f11r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB10"); 
state->u.f0.fld.f11r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB11"); 
state->u.f0.fld.f11r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB12"); 
state->u.f0.fld.f11r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB13"); 
state->u.f0.fld.f11r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB14"); 
state->u.f0.fld.f11r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB15"); 
state->u.f0.fld.f11r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB16"); 
state->u.f0.fld.f11r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB17"); 
state->u.f0.fld.f11r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB18"); 
state->u.f0.fld.f11r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB19"); 
state->u.f0.fld.f11r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB20"); 
state->u.f0.fld.f11r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB21"); 
state->u.f0.fld.f11r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB22"); 
state->u.f0.fld.f11r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB23"); 
state->u.f0.fld.f11r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB24"); 
state->u.f0.fld.f11r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB25"); 
state->u.f0.fld.f11r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB26"); 
state->u.f0.fld.f11r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB27"); 
state->u.f0.fld.f11r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB28"); 
state->u.f0.fld.f11r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB29"); 
state->u.f0.fld.f11r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB30"); 
state->u.f0.fld.f11r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f11r2, "FB31"); 
// F12R1bitfields.
state->u.f0.fld.f12r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB0"); 
state->u.f0.fld.f12r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB1"); 
state->u.f0.fld.f12r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB2"); 
state->u.f0.fld.f12r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB3"); 
state->u.f0.fld.f12r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB4"); 
state->u.f0.fld.f12r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB5"); 
state->u.f0.fld.f12r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB6"); 
state->u.f0.fld.f12r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB7"); 
state->u.f0.fld.f12r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB8"); 
state->u.f0.fld.f12r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB9"); 
state->u.f0.fld.f12r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB10"); 
state->u.f0.fld.f12r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB11"); 
state->u.f0.fld.f12r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB12"); 
state->u.f0.fld.f12r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB13"); 
state->u.f0.fld.f12r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB14"); 
state->u.f0.fld.f12r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB15"); 
state->u.f0.fld.f12r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB16"); 
state->u.f0.fld.f12r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB17"); 
state->u.f0.fld.f12r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB18"); 
state->u.f0.fld.f12r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB19"); 
state->u.f0.fld.f12r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB20"); 
state->u.f0.fld.f12r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB21"); 
state->u.f0.fld.f12r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB22"); 
state->u.f0.fld.f12r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB23"); 
state->u.f0.fld.f12r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB24"); 
state->u.f0.fld.f12r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB25"); 
state->u.f0.fld.f12r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB26"); 
state->u.f0.fld.f12r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB27"); 
state->u.f0.fld.f12r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB28"); 
state->u.f0.fld.f12r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB29"); 
state->u.f0.fld.f12r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB30"); 
state->u.f0.fld.f12r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f12r1, "FB31"); 
// F12R2bitfields.
state->u.f0.fld.f12r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB0"); 
state->u.f0.fld.f12r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB1"); 
state->u.f0.fld.f12r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB2"); 
state->u.f0.fld.f12r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB3"); 
state->u.f0.fld.f12r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB4"); 
state->u.f0.fld.f12r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB5"); 
state->u.f0.fld.f12r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB6"); 
state->u.f0.fld.f12r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB7"); 
state->u.f0.fld.f12r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB8"); 
state->u.f0.fld.f12r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB9"); 
state->u.f0.fld.f12r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB10"); 
state->u.f0.fld.f12r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB11"); 
state->u.f0.fld.f12r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB12"); 
state->u.f0.fld.f12r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB13"); 
state->u.f0.fld.f12r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB14"); 
state->u.f0.fld.f12r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB15"); 
state->u.f0.fld.f12r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB16"); 
state->u.f0.fld.f12r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB17"); 
state->u.f0.fld.f12r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB18"); 
state->u.f0.fld.f12r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB19"); 
state->u.f0.fld.f12r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB20"); 
state->u.f0.fld.f12r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB21"); 
state->u.f0.fld.f12r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB22"); 
state->u.f0.fld.f12r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB23"); 
state->u.f0.fld.f12r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB24"); 
state->u.f0.fld.f12r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB25"); 
state->u.f0.fld.f12r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB26"); 
state->u.f0.fld.f12r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB27"); 
state->u.f0.fld.f12r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB28"); 
state->u.f0.fld.f12r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB29"); 
state->u.f0.fld.f12r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB30"); 
state->u.f0.fld.f12r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f12r2, "FB31"); 
// F13R1bitfields.
state->u.f0.fld.f13r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB0"); 
state->u.f0.fld.f13r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB1"); 
state->u.f0.fld.f13r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB2"); 
state->u.f0.fld.f13r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB3"); 
state->u.f0.fld.f13r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB4"); 
state->u.f0.fld.f13r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB5"); 
state->u.f0.fld.f13r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB6"); 
state->u.f0.fld.f13r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB7"); 
state->u.f0.fld.f13r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB8"); 
state->u.f0.fld.f13r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB9"); 
state->u.f0.fld.f13r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB10"); 
state->u.f0.fld.f13r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB11"); 
state->u.f0.fld.f13r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB12"); 
state->u.f0.fld.f13r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB13"); 
state->u.f0.fld.f13r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB14"); 
state->u.f0.fld.f13r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB15"); 
state->u.f0.fld.f13r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB16"); 
state->u.f0.fld.f13r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB17"); 
state->u.f0.fld.f13r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB18"); 
state->u.f0.fld.f13r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB19"); 
state->u.f0.fld.f13r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB20"); 
state->u.f0.fld.f13r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB21"); 
state->u.f0.fld.f13r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB22"); 
state->u.f0.fld.f13r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB23"); 
state->u.f0.fld.f13r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB24"); 
state->u.f0.fld.f13r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB25"); 
state->u.f0.fld.f13r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB26"); 
state->u.f0.fld.f13r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB27"); 
state->u.f0.fld.f13r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB28"); 
state->u.f0.fld.f13r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB29"); 
state->u.f0.fld.f13r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB30"); 
state->u.f0.fld.f13r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f13r1, "FB31"); 
// F13R2bitfields.
state->u.f0.fld.f13r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB0"); 
state->u.f0.fld.f13r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB1"); 
state->u.f0.fld.f13r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB2"); 
state->u.f0.fld.f13r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB3"); 
state->u.f0.fld.f13r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB4"); 
state->u.f0.fld.f13r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB5"); 
state->u.f0.fld.f13r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB6"); 
state->u.f0.fld.f13r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB7"); 
state->u.f0.fld.f13r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB8"); 
state->u.f0.fld.f13r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB9"); 
state->u.f0.fld.f13r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB10"); 
state->u.f0.fld.f13r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB11"); 
state->u.f0.fld.f13r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB12"); 
state->u.f0.fld.f13r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB13"); 
state->u.f0.fld.f13r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB14"); 
state->u.f0.fld.f13r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB15"); 
state->u.f0.fld.f13r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB16"); 
state->u.f0.fld.f13r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB17"); 
state->u.f0.fld.f13r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB18"); 
state->u.f0.fld.f13r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB19"); 
state->u.f0.fld.f13r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB20"); 
state->u.f0.fld.f13r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB21"); 
state->u.f0.fld.f13r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB22"); 
state->u.f0.fld.f13r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB23"); 
state->u.f0.fld.f13r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB24"); 
state->u.f0.fld.f13r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB25"); 
state->u.f0.fld.f13r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB26"); 
state->u.f0.fld.f13r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB27"); 
state->u.f0.fld.f13r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB28"); 
state->u.f0.fld.f13r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB29"); 
state->u.f0.fld.f13r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB30"); 
state->u.f0.fld.f13r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f13r2, "FB31"); 
// F14R1bitfields.
state->u.f0.fld.f14r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB0"); 
state->u.f0.fld.f14r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB1"); 
state->u.f0.fld.f14r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB2"); 
state->u.f0.fld.f14r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB3"); 
state->u.f0.fld.f14r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB4"); 
state->u.f0.fld.f14r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB5"); 
state->u.f0.fld.f14r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB6"); 
state->u.f0.fld.f14r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB7"); 
state->u.f0.fld.f14r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB8"); 
state->u.f0.fld.f14r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB9"); 
state->u.f0.fld.f14r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB10"); 
state->u.f0.fld.f14r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB11"); 
state->u.f0.fld.f14r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB12"); 
state->u.f0.fld.f14r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB13"); 
state->u.f0.fld.f14r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB14"); 
state->u.f0.fld.f14r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB15"); 
state->u.f0.fld.f14r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB16"); 
state->u.f0.fld.f14r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB17"); 
state->u.f0.fld.f14r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB18"); 
state->u.f0.fld.f14r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB19"); 
state->u.f0.fld.f14r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB20"); 
state->u.f0.fld.f14r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB21"); 
state->u.f0.fld.f14r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB22"); 
state->u.f0.fld.f14r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB23"); 
state->u.f0.fld.f14r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB24"); 
state->u.f0.fld.f14r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB25"); 
state->u.f0.fld.f14r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB26"); 
state->u.f0.fld.f14r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB27"); 
state->u.f0.fld.f14r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB28"); 
state->u.f0.fld.f14r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB29"); 
state->u.f0.fld.f14r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB30"); 
state->u.f0.fld.f14r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f14r1, "FB31"); 
// F14R2bitfields.
state->u.f0.fld.f14r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB0"); 
state->u.f0.fld.f14r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB1"); 
state->u.f0.fld.f14r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB2"); 
state->u.f0.fld.f14r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB3"); 
state->u.f0.fld.f14r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB4"); 
state->u.f0.fld.f14r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB5"); 
state->u.f0.fld.f14r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB6"); 
state->u.f0.fld.f14r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB7"); 
state->u.f0.fld.f14r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB8"); 
state->u.f0.fld.f14r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB9"); 
state->u.f0.fld.f14r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB10"); 
state->u.f0.fld.f14r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB11"); 
state->u.f0.fld.f14r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB12"); 
state->u.f0.fld.f14r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB13"); 
state->u.f0.fld.f14r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB14"); 
state->u.f0.fld.f14r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB15"); 
state->u.f0.fld.f14r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB16"); 
state->u.f0.fld.f14r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB17"); 
state->u.f0.fld.f14r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB18"); 
state->u.f0.fld.f14r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB19"); 
state->u.f0.fld.f14r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB20"); 
state->u.f0.fld.f14r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB21"); 
state->u.f0.fld.f14r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB22"); 
state->u.f0.fld.f14r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB23"); 
state->u.f0.fld.f14r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB24"); 
state->u.f0.fld.f14r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB25"); 
state->u.f0.fld.f14r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB26"); 
state->u.f0.fld.f14r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB27"); 
state->u.f0.fld.f14r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB28"); 
state->u.f0.fld.f14r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB29"); 
state->u.f0.fld.f14r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB30"); 
state->u.f0.fld.f14r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f14r2, "FB31"); 
// F15R1bitfields.
state->u.f0.fld.f15r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB0"); 
state->u.f0.fld.f15r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB1"); 
state->u.f0.fld.f15r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB2"); 
state->u.f0.fld.f15r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB3"); 
state->u.f0.fld.f15r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB4"); 
state->u.f0.fld.f15r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB5"); 
state->u.f0.fld.f15r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB6"); 
state->u.f0.fld.f15r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB7"); 
state->u.f0.fld.f15r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB8"); 
state->u.f0.fld.f15r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB9"); 
state->u.f0.fld.f15r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB10"); 
state->u.f0.fld.f15r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB11"); 
state->u.f0.fld.f15r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB12"); 
state->u.f0.fld.f15r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB13"); 
state->u.f0.fld.f15r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB14"); 
state->u.f0.fld.f15r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB15"); 
state->u.f0.fld.f15r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB16"); 
state->u.f0.fld.f15r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB17"); 
state->u.f0.fld.f15r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB18"); 
state->u.f0.fld.f15r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB19"); 
state->u.f0.fld.f15r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB20"); 
state->u.f0.fld.f15r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB21"); 
state->u.f0.fld.f15r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB22"); 
state->u.f0.fld.f15r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB23"); 
state->u.f0.fld.f15r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB24"); 
state->u.f0.fld.f15r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB25"); 
state->u.f0.fld.f15r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB26"); 
state->u.f0.fld.f15r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB27"); 
state->u.f0.fld.f15r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB28"); 
state->u.f0.fld.f15r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB29"); 
state->u.f0.fld.f15r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB30"); 
state->u.f0.fld.f15r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f15r1, "FB31"); 
// F15R2bitfields.
state->u.f0.fld.f15r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB0"); 
state->u.f0.fld.f15r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB1"); 
state->u.f0.fld.f15r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB2"); 
state->u.f0.fld.f15r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB3"); 
state->u.f0.fld.f15r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB4"); 
state->u.f0.fld.f15r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB5"); 
state->u.f0.fld.f15r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB6"); 
state->u.f0.fld.f15r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB7"); 
state->u.f0.fld.f15r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB8"); 
state->u.f0.fld.f15r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB9"); 
state->u.f0.fld.f15r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB10"); 
state->u.f0.fld.f15r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB11"); 
state->u.f0.fld.f15r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB12"); 
state->u.f0.fld.f15r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB13"); 
state->u.f0.fld.f15r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB14"); 
state->u.f0.fld.f15r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB15"); 
state->u.f0.fld.f15r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB16"); 
state->u.f0.fld.f15r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB17"); 
state->u.f0.fld.f15r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB18"); 
state->u.f0.fld.f15r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB19"); 
state->u.f0.fld.f15r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB20"); 
state->u.f0.fld.f15r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB21"); 
state->u.f0.fld.f15r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB22"); 
state->u.f0.fld.f15r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB23"); 
state->u.f0.fld.f15r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB24"); 
state->u.f0.fld.f15r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB25"); 
state->u.f0.fld.f15r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB26"); 
state->u.f0.fld.f15r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB27"); 
state->u.f0.fld.f15r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB28"); 
state->u.f0.fld.f15r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB29"); 
state->u.f0.fld.f15r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB30"); 
state->u.f0.fld.f15r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f15r2, "FB31"); 
// F16R1bitfields.
state->u.f0.fld.f16r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB0"); 
state->u.f0.fld.f16r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB1"); 
state->u.f0.fld.f16r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB2"); 
state->u.f0.fld.f16r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB3"); 
state->u.f0.fld.f16r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB4"); 
state->u.f0.fld.f16r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB5"); 
state->u.f0.fld.f16r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB6"); 
state->u.f0.fld.f16r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB7"); 
state->u.f0.fld.f16r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB8"); 
state->u.f0.fld.f16r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB9"); 
state->u.f0.fld.f16r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB10"); 
state->u.f0.fld.f16r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB11"); 
state->u.f0.fld.f16r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB12"); 
state->u.f0.fld.f16r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB13"); 
state->u.f0.fld.f16r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB14"); 
state->u.f0.fld.f16r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB15"); 
state->u.f0.fld.f16r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB16"); 
state->u.f0.fld.f16r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB17"); 
state->u.f0.fld.f16r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB18"); 
state->u.f0.fld.f16r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB19"); 
state->u.f0.fld.f16r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB20"); 
state->u.f0.fld.f16r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB21"); 
state->u.f0.fld.f16r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB22"); 
state->u.f0.fld.f16r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB23"); 
state->u.f0.fld.f16r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB24"); 
state->u.f0.fld.f16r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB25"); 
state->u.f0.fld.f16r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB26"); 
state->u.f0.fld.f16r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB27"); 
state->u.f0.fld.f16r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB28"); 
state->u.f0.fld.f16r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB29"); 
state->u.f0.fld.f16r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB30"); 
state->u.f0.fld.f16r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f16r1, "FB31"); 
// F16R2bitfields.
state->u.f0.fld.f16r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB0"); 
state->u.f0.fld.f16r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB1"); 
state->u.f0.fld.f16r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB2"); 
state->u.f0.fld.f16r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB3"); 
state->u.f0.fld.f16r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB4"); 
state->u.f0.fld.f16r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB5"); 
state->u.f0.fld.f16r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB6"); 
state->u.f0.fld.f16r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB7"); 
state->u.f0.fld.f16r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB8"); 
state->u.f0.fld.f16r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB9"); 
state->u.f0.fld.f16r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB10"); 
state->u.f0.fld.f16r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB11"); 
state->u.f0.fld.f16r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB12"); 
state->u.f0.fld.f16r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB13"); 
state->u.f0.fld.f16r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB14"); 
state->u.f0.fld.f16r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB15"); 
state->u.f0.fld.f16r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB16"); 
state->u.f0.fld.f16r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB17"); 
state->u.f0.fld.f16r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB18"); 
state->u.f0.fld.f16r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB19"); 
state->u.f0.fld.f16r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB20"); 
state->u.f0.fld.f16r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB21"); 
state->u.f0.fld.f16r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB22"); 
state->u.f0.fld.f16r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB23"); 
state->u.f0.fld.f16r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB24"); 
state->u.f0.fld.f16r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB25"); 
state->u.f0.fld.f16r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB26"); 
state->u.f0.fld.f16r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB27"); 
state->u.f0.fld.f16r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB28"); 
state->u.f0.fld.f16r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB29"); 
state->u.f0.fld.f16r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB30"); 
state->u.f0.fld.f16r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f16r2, "FB31"); 
// F17R1bitfields.
state->u.f0.fld.f17r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB0"); 
state->u.f0.fld.f17r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB1"); 
state->u.f0.fld.f17r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB2"); 
state->u.f0.fld.f17r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB3"); 
state->u.f0.fld.f17r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB4"); 
state->u.f0.fld.f17r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB5"); 
state->u.f0.fld.f17r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB6"); 
state->u.f0.fld.f17r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB7"); 
state->u.f0.fld.f17r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB8"); 
state->u.f0.fld.f17r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB9"); 
state->u.f0.fld.f17r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB10"); 
state->u.f0.fld.f17r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB11"); 
state->u.f0.fld.f17r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB12"); 
state->u.f0.fld.f17r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB13"); 
state->u.f0.fld.f17r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB14"); 
state->u.f0.fld.f17r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB15"); 
state->u.f0.fld.f17r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB16"); 
state->u.f0.fld.f17r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB17"); 
state->u.f0.fld.f17r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB18"); 
state->u.f0.fld.f17r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB19"); 
state->u.f0.fld.f17r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB20"); 
state->u.f0.fld.f17r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB21"); 
state->u.f0.fld.f17r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB22"); 
state->u.f0.fld.f17r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB23"); 
state->u.f0.fld.f17r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB24"); 
state->u.f0.fld.f17r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB25"); 
state->u.f0.fld.f17r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB26"); 
state->u.f0.fld.f17r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB27"); 
state->u.f0.fld.f17r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB28"); 
state->u.f0.fld.f17r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB29"); 
state->u.f0.fld.f17r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB30"); 
state->u.f0.fld.f17r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f17r1, "FB31"); 
// F17R2bitfields.
state->u.f0.fld.f17r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB0"); 
state->u.f0.fld.f17r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB1"); 
state->u.f0.fld.f17r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB2"); 
state->u.f0.fld.f17r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB3"); 
state->u.f0.fld.f17r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB4"); 
state->u.f0.fld.f17r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB5"); 
state->u.f0.fld.f17r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB6"); 
state->u.f0.fld.f17r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB7"); 
state->u.f0.fld.f17r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB8"); 
state->u.f0.fld.f17r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB9"); 
state->u.f0.fld.f17r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB10"); 
state->u.f0.fld.f17r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB11"); 
state->u.f0.fld.f17r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB12"); 
state->u.f0.fld.f17r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB13"); 
state->u.f0.fld.f17r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB14"); 
state->u.f0.fld.f17r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB15"); 
state->u.f0.fld.f17r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB16"); 
state->u.f0.fld.f17r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB17"); 
state->u.f0.fld.f17r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB18"); 
state->u.f0.fld.f17r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB19"); 
state->u.f0.fld.f17r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB20"); 
state->u.f0.fld.f17r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB21"); 
state->u.f0.fld.f17r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB22"); 
state->u.f0.fld.f17r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB23"); 
state->u.f0.fld.f17r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB24"); 
state->u.f0.fld.f17r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB25"); 
state->u.f0.fld.f17r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB26"); 
state->u.f0.fld.f17r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB27"); 
state->u.f0.fld.f17r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB28"); 
state->u.f0.fld.f17r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB29"); 
state->u.f0.fld.f17r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB30"); 
state->u.f0.fld.f17r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f17r2, "FB31"); 
// F18R1bitfields.
state->u.f0.fld.f18r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB0"); 
state->u.f0.fld.f18r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB1"); 
state->u.f0.fld.f18r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB2"); 
state->u.f0.fld.f18r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB3"); 
state->u.f0.fld.f18r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB4"); 
state->u.f0.fld.f18r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB5"); 
state->u.f0.fld.f18r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB6"); 
state->u.f0.fld.f18r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB7"); 
state->u.f0.fld.f18r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB8"); 
state->u.f0.fld.f18r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB9"); 
state->u.f0.fld.f18r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB10"); 
state->u.f0.fld.f18r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB11"); 
state->u.f0.fld.f18r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB12"); 
state->u.f0.fld.f18r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB13"); 
state->u.f0.fld.f18r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB14"); 
state->u.f0.fld.f18r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB15"); 
state->u.f0.fld.f18r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB16"); 
state->u.f0.fld.f18r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB17"); 
state->u.f0.fld.f18r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB18"); 
state->u.f0.fld.f18r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB19"); 
state->u.f0.fld.f18r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB20"); 
state->u.f0.fld.f18r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB21"); 
state->u.f0.fld.f18r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB22"); 
state->u.f0.fld.f18r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB23"); 
state->u.f0.fld.f18r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB24"); 
state->u.f0.fld.f18r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB25"); 
state->u.f0.fld.f18r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB26"); 
state->u.f0.fld.f18r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB27"); 
state->u.f0.fld.f18r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB28"); 
state->u.f0.fld.f18r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB29"); 
state->u.f0.fld.f18r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB30"); 
state->u.f0.fld.f18r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f18r1, "FB31"); 
// F18R2bitfields.
state->u.f0.fld.f18r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB0"); 
state->u.f0.fld.f18r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB1"); 
state->u.f0.fld.f18r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB2"); 
state->u.f0.fld.f18r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB3"); 
state->u.f0.fld.f18r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB4"); 
state->u.f0.fld.f18r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB5"); 
state->u.f0.fld.f18r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB6"); 
state->u.f0.fld.f18r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB7"); 
state->u.f0.fld.f18r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB8"); 
state->u.f0.fld.f18r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB9"); 
state->u.f0.fld.f18r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB10"); 
state->u.f0.fld.f18r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB11"); 
state->u.f0.fld.f18r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB12"); 
state->u.f0.fld.f18r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB13"); 
state->u.f0.fld.f18r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB14"); 
state->u.f0.fld.f18r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB15"); 
state->u.f0.fld.f18r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB16"); 
state->u.f0.fld.f18r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB17"); 
state->u.f0.fld.f18r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB18"); 
state->u.f0.fld.f18r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB19"); 
state->u.f0.fld.f18r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB20"); 
state->u.f0.fld.f18r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB21"); 
state->u.f0.fld.f18r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB22"); 
state->u.f0.fld.f18r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB23"); 
state->u.f0.fld.f18r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB24"); 
state->u.f0.fld.f18r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB25"); 
state->u.f0.fld.f18r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB26"); 
state->u.f0.fld.f18r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB27"); 
state->u.f0.fld.f18r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB28"); 
state->u.f0.fld.f18r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB29"); 
state->u.f0.fld.f18r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB30"); 
state->u.f0.fld.f18r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f18r2, "FB31"); 
// F19R1bitfields.
state->u.f0.fld.f19r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB0"); 
state->u.f0.fld.f19r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB1"); 
state->u.f0.fld.f19r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB2"); 
state->u.f0.fld.f19r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB3"); 
state->u.f0.fld.f19r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB4"); 
state->u.f0.fld.f19r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB5"); 
state->u.f0.fld.f19r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB6"); 
state->u.f0.fld.f19r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB7"); 
state->u.f0.fld.f19r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB8"); 
state->u.f0.fld.f19r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB9"); 
state->u.f0.fld.f19r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB10"); 
state->u.f0.fld.f19r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB11"); 
state->u.f0.fld.f19r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB12"); 
state->u.f0.fld.f19r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB13"); 
state->u.f0.fld.f19r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB14"); 
state->u.f0.fld.f19r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB15"); 
state->u.f0.fld.f19r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB16"); 
state->u.f0.fld.f19r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB17"); 
state->u.f0.fld.f19r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB18"); 
state->u.f0.fld.f19r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB19"); 
state->u.f0.fld.f19r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB20"); 
state->u.f0.fld.f19r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB21"); 
state->u.f0.fld.f19r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB22"); 
state->u.f0.fld.f19r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB23"); 
state->u.f0.fld.f19r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB24"); 
state->u.f0.fld.f19r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB25"); 
state->u.f0.fld.f19r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB26"); 
state->u.f0.fld.f19r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB27"); 
state->u.f0.fld.f19r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB28"); 
state->u.f0.fld.f19r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB29"); 
state->u.f0.fld.f19r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB30"); 
state->u.f0.fld.f19r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f19r1, "FB31"); 
// F19R2bitfields.
state->u.f0.fld.f19r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB0"); 
state->u.f0.fld.f19r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB1"); 
state->u.f0.fld.f19r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB2"); 
state->u.f0.fld.f19r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB3"); 
state->u.f0.fld.f19r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB4"); 
state->u.f0.fld.f19r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB5"); 
state->u.f0.fld.f19r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB6"); 
state->u.f0.fld.f19r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB7"); 
state->u.f0.fld.f19r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB8"); 
state->u.f0.fld.f19r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB9"); 
state->u.f0.fld.f19r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB10"); 
state->u.f0.fld.f19r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB11"); 
state->u.f0.fld.f19r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB12"); 
state->u.f0.fld.f19r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB13"); 
state->u.f0.fld.f19r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB14"); 
state->u.f0.fld.f19r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB15"); 
state->u.f0.fld.f19r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB16"); 
state->u.f0.fld.f19r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB17"); 
state->u.f0.fld.f19r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB18"); 
state->u.f0.fld.f19r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB19"); 
state->u.f0.fld.f19r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB20"); 
state->u.f0.fld.f19r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB21"); 
state->u.f0.fld.f19r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB22"); 
state->u.f0.fld.f19r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB23"); 
state->u.f0.fld.f19r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB24"); 
state->u.f0.fld.f19r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB25"); 
state->u.f0.fld.f19r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB26"); 
state->u.f0.fld.f19r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB27"); 
state->u.f0.fld.f19r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB28"); 
state->u.f0.fld.f19r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB29"); 
state->u.f0.fld.f19r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB30"); 
state->u.f0.fld.f19r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f19r2, "FB31"); 
// F20R1bitfields.
state->u.f0.fld.f20r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB0"); 
state->u.f0.fld.f20r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB1"); 
state->u.f0.fld.f20r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB2"); 
state->u.f0.fld.f20r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB3"); 
state->u.f0.fld.f20r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB4"); 
state->u.f0.fld.f20r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB5"); 
state->u.f0.fld.f20r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB6"); 
state->u.f0.fld.f20r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB7"); 
state->u.f0.fld.f20r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB8"); 
state->u.f0.fld.f20r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB9"); 
state->u.f0.fld.f20r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB10"); 
state->u.f0.fld.f20r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB11"); 
state->u.f0.fld.f20r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB12"); 
state->u.f0.fld.f20r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB13"); 
state->u.f0.fld.f20r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB14"); 
state->u.f0.fld.f20r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB15"); 
state->u.f0.fld.f20r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB16"); 
state->u.f0.fld.f20r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB17"); 
state->u.f0.fld.f20r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB18"); 
state->u.f0.fld.f20r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB19"); 
state->u.f0.fld.f20r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB20"); 
state->u.f0.fld.f20r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB21"); 
state->u.f0.fld.f20r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB22"); 
state->u.f0.fld.f20r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB23"); 
state->u.f0.fld.f20r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB24"); 
state->u.f0.fld.f20r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB25"); 
state->u.f0.fld.f20r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB26"); 
state->u.f0.fld.f20r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB27"); 
state->u.f0.fld.f20r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB28"); 
state->u.f0.fld.f20r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB29"); 
state->u.f0.fld.f20r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB30"); 
state->u.f0.fld.f20r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f20r1, "FB31"); 
// F20R2bitfields.
state->u.f0.fld.f20r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB0"); 
state->u.f0.fld.f20r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB1"); 
state->u.f0.fld.f20r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB2"); 
state->u.f0.fld.f20r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB3"); 
state->u.f0.fld.f20r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB4"); 
state->u.f0.fld.f20r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB5"); 
state->u.f0.fld.f20r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB6"); 
state->u.f0.fld.f20r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB7"); 
state->u.f0.fld.f20r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB8"); 
state->u.f0.fld.f20r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB9"); 
state->u.f0.fld.f20r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB10"); 
state->u.f0.fld.f20r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB11"); 
state->u.f0.fld.f20r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB12"); 
state->u.f0.fld.f20r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB13"); 
state->u.f0.fld.f20r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB14"); 
state->u.f0.fld.f20r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB15"); 
state->u.f0.fld.f20r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB16"); 
state->u.f0.fld.f20r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB17"); 
state->u.f0.fld.f20r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB18"); 
state->u.f0.fld.f20r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB19"); 
state->u.f0.fld.f20r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB20"); 
state->u.f0.fld.f20r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB21"); 
state->u.f0.fld.f20r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB22"); 
state->u.f0.fld.f20r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB23"); 
state->u.f0.fld.f20r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB24"); 
state->u.f0.fld.f20r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB25"); 
state->u.f0.fld.f20r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB26"); 
state->u.f0.fld.f20r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB27"); 
state->u.f0.fld.f20r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB28"); 
state->u.f0.fld.f20r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB29"); 
state->u.f0.fld.f20r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB30"); 
state->u.f0.fld.f20r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f20r2, "FB31"); 
// F21R1bitfields.
state->u.f0.fld.f21r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB0"); 
state->u.f0.fld.f21r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB1"); 
state->u.f0.fld.f21r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB2"); 
state->u.f0.fld.f21r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB3"); 
state->u.f0.fld.f21r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB4"); 
state->u.f0.fld.f21r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB5"); 
state->u.f0.fld.f21r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB6"); 
state->u.f0.fld.f21r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB7"); 
state->u.f0.fld.f21r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB8"); 
state->u.f0.fld.f21r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB9"); 
state->u.f0.fld.f21r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB10"); 
state->u.f0.fld.f21r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB11"); 
state->u.f0.fld.f21r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB12"); 
state->u.f0.fld.f21r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB13"); 
state->u.f0.fld.f21r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB14"); 
state->u.f0.fld.f21r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB15"); 
state->u.f0.fld.f21r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB16"); 
state->u.f0.fld.f21r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB17"); 
state->u.f0.fld.f21r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB18"); 
state->u.f0.fld.f21r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB19"); 
state->u.f0.fld.f21r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB20"); 
state->u.f0.fld.f21r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB21"); 
state->u.f0.fld.f21r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB22"); 
state->u.f0.fld.f21r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB23"); 
state->u.f0.fld.f21r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB24"); 
state->u.f0.fld.f21r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB25"); 
state->u.f0.fld.f21r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB26"); 
state->u.f0.fld.f21r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB27"); 
state->u.f0.fld.f21r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB28"); 
state->u.f0.fld.f21r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB29"); 
state->u.f0.fld.f21r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB30"); 
state->u.f0.fld.f21r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f21r1, "FB31"); 
// F21R2bitfields.
state->u.f0.fld.f21r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB0"); 
state->u.f0.fld.f21r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB1"); 
state->u.f0.fld.f21r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB2"); 
state->u.f0.fld.f21r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB3"); 
state->u.f0.fld.f21r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB4"); 
state->u.f0.fld.f21r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB5"); 
state->u.f0.fld.f21r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB6"); 
state->u.f0.fld.f21r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB7"); 
state->u.f0.fld.f21r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB8"); 
state->u.f0.fld.f21r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB9"); 
state->u.f0.fld.f21r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB10"); 
state->u.f0.fld.f21r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB11"); 
state->u.f0.fld.f21r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB12"); 
state->u.f0.fld.f21r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB13"); 
state->u.f0.fld.f21r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB14"); 
state->u.f0.fld.f21r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB15"); 
state->u.f0.fld.f21r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB16"); 
state->u.f0.fld.f21r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB17"); 
state->u.f0.fld.f21r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB18"); 
state->u.f0.fld.f21r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB19"); 
state->u.f0.fld.f21r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB20"); 
state->u.f0.fld.f21r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB21"); 
state->u.f0.fld.f21r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB22"); 
state->u.f0.fld.f21r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB23"); 
state->u.f0.fld.f21r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB24"); 
state->u.f0.fld.f21r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB25"); 
state->u.f0.fld.f21r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB26"); 
state->u.f0.fld.f21r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB27"); 
state->u.f0.fld.f21r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB28"); 
state->u.f0.fld.f21r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB29"); 
state->u.f0.fld.f21r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB30"); 
state->u.f0.fld.f21r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f21r2, "FB31"); 
// F22R1bitfields.
state->u.f0.fld.f22r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB0"); 
state->u.f0.fld.f22r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB1"); 
state->u.f0.fld.f22r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB2"); 
state->u.f0.fld.f22r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB3"); 
state->u.f0.fld.f22r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB4"); 
state->u.f0.fld.f22r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB5"); 
state->u.f0.fld.f22r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB6"); 
state->u.f0.fld.f22r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB7"); 
state->u.f0.fld.f22r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB8"); 
state->u.f0.fld.f22r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB9"); 
state->u.f0.fld.f22r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB10"); 
state->u.f0.fld.f22r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB11"); 
state->u.f0.fld.f22r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB12"); 
state->u.f0.fld.f22r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB13"); 
state->u.f0.fld.f22r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB14"); 
state->u.f0.fld.f22r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB15"); 
state->u.f0.fld.f22r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB16"); 
state->u.f0.fld.f22r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB17"); 
state->u.f0.fld.f22r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB18"); 
state->u.f0.fld.f22r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB19"); 
state->u.f0.fld.f22r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB20"); 
state->u.f0.fld.f22r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB21"); 
state->u.f0.fld.f22r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB22"); 
state->u.f0.fld.f22r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB23"); 
state->u.f0.fld.f22r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB24"); 
state->u.f0.fld.f22r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB25"); 
state->u.f0.fld.f22r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB26"); 
state->u.f0.fld.f22r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB27"); 
state->u.f0.fld.f22r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB28"); 
state->u.f0.fld.f22r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB29"); 
state->u.f0.fld.f22r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB30"); 
state->u.f0.fld.f22r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f22r1, "FB31"); 
// F22R2bitfields.
state->u.f0.fld.f22r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB0"); 
state->u.f0.fld.f22r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB1"); 
state->u.f0.fld.f22r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB2"); 
state->u.f0.fld.f22r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB3"); 
state->u.f0.fld.f22r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB4"); 
state->u.f0.fld.f22r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB5"); 
state->u.f0.fld.f22r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB6"); 
state->u.f0.fld.f22r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB7"); 
state->u.f0.fld.f22r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB8"); 
state->u.f0.fld.f22r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB9"); 
state->u.f0.fld.f22r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB10"); 
state->u.f0.fld.f22r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB11"); 
state->u.f0.fld.f22r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB12"); 
state->u.f0.fld.f22r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB13"); 
state->u.f0.fld.f22r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB14"); 
state->u.f0.fld.f22r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB15"); 
state->u.f0.fld.f22r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB16"); 
state->u.f0.fld.f22r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB17"); 
state->u.f0.fld.f22r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB18"); 
state->u.f0.fld.f22r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB19"); 
state->u.f0.fld.f22r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB20"); 
state->u.f0.fld.f22r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB21"); 
state->u.f0.fld.f22r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB22"); 
state->u.f0.fld.f22r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB23"); 
state->u.f0.fld.f22r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB24"); 
state->u.f0.fld.f22r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB25"); 
state->u.f0.fld.f22r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB26"); 
state->u.f0.fld.f22r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB27"); 
state->u.f0.fld.f22r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB28"); 
state->u.f0.fld.f22r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB29"); 
state->u.f0.fld.f22r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB30"); 
state->u.f0.fld.f22r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f22r2, "FB31"); 
// F23R1bitfields.
state->u.f0.fld.f23r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB0"); 
state->u.f0.fld.f23r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB1"); 
state->u.f0.fld.f23r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB2"); 
state->u.f0.fld.f23r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB3"); 
state->u.f0.fld.f23r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB4"); 
state->u.f0.fld.f23r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB5"); 
state->u.f0.fld.f23r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB6"); 
state->u.f0.fld.f23r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB7"); 
state->u.f0.fld.f23r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB8"); 
state->u.f0.fld.f23r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB9"); 
state->u.f0.fld.f23r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB10"); 
state->u.f0.fld.f23r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB11"); 
state->u.f0.fld.f23r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB12"); 
state->u.f0.fld.f23r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB13"); 
state->u.f0.fld.f23r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB14"); 
state->u.f0.fld.f23r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB15"); 
state->u.f0.fld.f23r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB16"); 
state->u.f0.fld.f23r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB17"); 
state->u.f0.fld.f23r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB18"); 
state->u.f0.fld.f23r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB19"); 
state->u.f0.fld.f23r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB20"); 
state->u.f0.fld.f23r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB21"); 
state->u.f0.fld.f23r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB22"); 
state->u.f0.fld.f23r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB23"); 
state->u.f0.fld.f23r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB24"); 
state->u.f0.fld.f23r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB25"); 
state->u.f0.fld.f23r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB26"); 
state->u.f0.fld.f23r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB27"); 
state->u.f0.fld.f23r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB28"); 
state->u.f0.fld.f23r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB29"); 
state->u.f0.fld.f23r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB30"); 
state->u.f0.fld.f23r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f23r1, "FB31"); 
// F23R2bitfields.
state->u.f0.fld.f23r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB0"); 
state->u.f0.fld.f23r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB1"); 
state->u.f0.fld.f23r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB2"); 
state->u.f0.fld.f23r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB3"); 
state->u.f0.fld.f23r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB4"); 
state->u.f0.fld.f23r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB5"); 
state->u.f0.fld.f23r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB6"); 
state->u.f0.fld.f23r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB7"); 
state->u.f0.fld.f23r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB8"); 
state->u.f0.fld.f23r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB9"); 
state->u.f0.fld.f23r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB10"); 
state->u.f0.fld.f23r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB11"); 
state->u.f0.fld.f23r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB12"); 
state->u.f0.fld.f23r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB13"); 
state->u.f0.fld.f23r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB14"); 
state->u.f0.fld.f23r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB15"); 
state->u.f0.fld.f23r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB16"); 
state->u.f0.fld.f23r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB17"); 
state->u.f0.fld.f23r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB18"); 
state->u.f0.fld.f23r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB19"); 
state->u.f0.fld.f23r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB20"); 
state->u.f0.fld.f23r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB21"); 
state->u.f0.fld.f23r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB22"); 
state->u.f0.fld.f23r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB23"); 
state->u.f0.fld.f23r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB24"); 
state->u.f0.fld.f23r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB25"); 
state->u.f0.fld.f23r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB26"); 
state->u.f0.fld.f23r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB27"); 
state->u.f0.fld.f23r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB28"); 
state->u.f0.fld.f23r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB29"); 
state->u.f0.fld.f23r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB30"); 
state->u.f0.fld.f23r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f23r2, "FB31"); 
// F24R1bitfields.
state->u.f0.fld.f24r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB0"); 
state->u.f0.fld.f24r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB1"); 
state->u.f0.fld.f24r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB2"); 
state->u.f0.fld.f24r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB3"); 
state->u.f0.fld.f24r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB4"); 
state->u.f0.fld.f24r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB5"); 
state->u.f0.fld.f24r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB6"); 
state->u.f0.fld.f24r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB7"); 
state->u.f0.fld.f24r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB8"); 
state->u.f0.fld.f24r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB9"); 
state->u.f0.fld.f24r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB10"); 
state->u.f0.fld.f24r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB11"); 
state->u.f0.fld.f24r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB12"); 
state->u.f0.fld.f24r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB13"); 
state->u.f0.fld.f24r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB14"); 
state->u.f0.fld.f24r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB15"); 
state->u.f0.fld.f24r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB16"); 
state->u.f0.fld.f24r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB17"); 
state->u.f0.fld.f24r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB18"); 
state->u.f0.fld.f24r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB19"); 
state->u.f0.fld.f24r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB20"); 
state->u.f0.fld.f24r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB21"); 
state->u.f0.fld.f24r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB22"); 
state->u.f0.fld.f24r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB23"); 
state->u.f0.fld.f24r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB24"); 
state->u.f0.fld.f24r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB25"); 
state->u.f0.fld.f24r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB26"); 
state->u.f0.fld.f24r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB27"); 
state->u.f0.fld.f24r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB28"); 
state->u.f0.fld.f24r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB29"); 
state->u.f0.fld.f24r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB30"); 
state->u.f0.fld.f24r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f24r1, "FB31"); 
// F24R2bitfields.
state->u.f0.fld.f24r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB0"); 
state->u.f0.fld.f24r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB1"); 
state->u.f0.fld.f24r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB2"); 
state->u.f0.fld.f24r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB3"); 
state->u.f0.fld.f24r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB4"); 
state->u.f0.fld.f24r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB5"); 
state->u.f0.fld.f24r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB6"); 
state->u.f0.fld.f24r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB7"); 
state->u.f0.fld.f24r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB8"); 
state->u.f0.fld.f24r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB9"); 
state->u.f0.fld.f24r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB10"); 
state->u.f0.fld.f24r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB11"); 
state->u.f0.fld.f24r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB12"); 
state->u.f0.fld.f24r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB13"); 
state->u.f0.fld.f24r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB14"); 
state->u.f0.fld.f24r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB15"); 
state->u.f0.fld.f24r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB16"); 
state->u.f0.fld.f24r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB17"); 
state->u.f0.fld.f24r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB18"); 
state->u.f0.fld.f24r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB19"); 
state->u.f0.fld.f24r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB20"); 
state->u.f0.fld.f24r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB21"); 
state->u.f0.fld.f24r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB22"); 
state->u.f0.fld.f24r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB23"); 
state->u.f0.fld.f24r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB24"); 
state->u.f0.fld.f24r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB25"); 
state->u.f0.fld.f24r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB26"); 
state->u.f0.fld.f24r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB27"); 
state->u.f0.fld.f24r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB28"); 
state->u.f0.fld.f24r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB29"); 
state->u.f0.fld.f24r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB30"); 
state->u.f0.fld.f24r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f24r2, "FB31"); 
// F25R1bitfields.
state->u.f0.fld.f25r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB0"); 
state->u.f0.fld.f25r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB1"); 
state->u.f0.fld.f25r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB2"); 
state->u.f0.fld.f25r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB3"); 
state->u.f0.fld.f25r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB4"); 
state->u.f0.fld.f25r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB5"); 
state->u.f0.fld.f25r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB6"); 
state->u.f0.fld.f25r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB7"); 
state->u.f0.fld.f25r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB8"); 
state->u.f0.fld.f25r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB9"); 
state->u.f0.fld.f25r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB10"); 
state->u.f0.fld.f25r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB11"); 
state->u.f0.fld.f25r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB12"); 
state->u.f0.fld.f25r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB13"); 
state->u.f0.fld.f25r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB14"); 
state->u.f0.fld.f25r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB15"); 
state->u.f0.fld.f25r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB16"); 
state->u.f0.fld.f25r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB17"); 
state->u.f0.fld.f25r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB18"); 
state->u.f0.fld.f25r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB19"); 
state->u.f0.fld.f25r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB20"); 
state->u.f0.fld.f25r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB21"); 
state->u.f0.fld.f25r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB22"); 
state->u.f0.fld.f25r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB23"); 
state->u.f0.fld.f25r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB24"); 
state->u.f0.fld.f25r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB25"); 
state->u.f0.fld.f25r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB26"); 
state->u.f0.fld.f25r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB27"); 
state->u.f0.fld.f25r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB28"); 
state->u.f0.fld.f25r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB29"); 
state->u.f0.fld.f25r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB30"); 
state->u.f0.fld.f25r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f25r1, "FB31"); 
// F25R2bitfields.
state->u.f0.fld.f25r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB0"); 
state->u.f0.fld.f25r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB1"); 
state->u.f0.fld.f25r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB2"); 
state->u.f0.fld.f25r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB3"); 
state->u.f0.fld.f25r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB4"); 
state->u.f0.fld.f25r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB5"); 
state->u.f0.fld.f25r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB6"); 
state->u.f0.fld.f25r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB7"); 
state->u.f0.fld.f25r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB8"); 
state->u.f0.fld.f25r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB9"); 
state->u.f0.fld.f25r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB10"); 
state->u.f0.fld.f25r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB11"); 
state->u.f0.fld.f25r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB12"); 
state->u.f0.fld.f25r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB13"); 
state->u.f0.fld.f25r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB14"); 
state->u.f0.fld.f25r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB15"); 
state->u.f0.fld.f25r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB16"); 
state->u.f0.fld.f25r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB17"); 
state->u.f0.fld.f25r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB18"); 
state->u.f0.fld.f25r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB19"); 
state->u.f0.fld.f25r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB20"); 
state->u.f0.fld.f25r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB21"); 
state->u.f0.fld.f25r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB22"); 
state->u.f0.fld.f25r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB23"); 
state->u.f0.fld.f25r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB24"); 
state->u.f0.fld.f25r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB25"); 
state->u.f0.fld.f25r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB26"); 
state->u.f0.fld.f25r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB27"); 
state->u.f0.fld.f25r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB28"); 
state->u.f0.fld.f25r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB29"); 
state->u.f0.fld.f25r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB30"); 
state->u.f0.fld.f25r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f25r2, "FB31"); 
// F26R1bitfields.
state->u.f0.fld.f26r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB0"); 
state->u.f0.fld.f26r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB1"); 
state->u.f0.fld.f26r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB2"); 
state->u.f0.fld.f26r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB3"); 
state->u.f0.fld.f26r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB4"); 
state->u.f0.fld.f26r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB5"); 
state->u.f0.fld.f26r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB6"); 
state->u.f0.fld.f26r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB7"); 
state->u.f0.fld.f26r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB8"); 
state->u.f0.fld.f26r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB9"); 
state->u.f0.fld.f26r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB10"); 
state->u.f0.fld.f26r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB11"); 
state->u.f0.fld.f26r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB12"); 
state->u.f0.fld.f26r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB13"); 
state->u.f0.fld.f26r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB14"); 
state->u.f0.fld.f26r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB15"); 
state->u.f0.fld.f26r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB16"); 
state->u.f0.fld.f26r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB17"); 
state->u.f0.fld.f26r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB18"); 
state->u.f0.fld.f26r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB19"); 
state->u.f0.fld.f26r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB20"); 
state->u.f0.fld.f26r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB21"); 
state->u.f0.fld.f26r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB22"); 
state->u.f0.fld.f26r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB23"); 
state->u.f0.fld.f26r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB24"); 
state->u.f0.fld.f26r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB25"); 
state->u.f0.fld.f26r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB26"); 
state->u.f0.fld.f26r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB27"); 
state->u.f0.fld.f26r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB28"); 
state->u.f0.fld.f26r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB29"); 
state->u.f0.fld.f26r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB30"); 
state->u.f0.fld.f26r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f26r1, "FB31"); 
// F26R2bitfields.
state->u.f0.fld.f26r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB0"); 
state->u.f0.fld.f26r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB1"); 
state->u.f0.fld.f26r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB2"); 
state->u.f0.fld.f26r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB3"); 
state->u.f0.fld.f26r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB4"); 
state->u.f0.fld.f26r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB5"); 
state->u.f0.fld.f26r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB6"); 
state->u.f0.fld.f26r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB7"); 
state->u.f0.fld.f26r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB8"); 
state->u.f0.fld.f26r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB9"); 
state->u.f0.fld.f26r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB10"); 
state->u.f0.fld.f26r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB11"); 
state->u.f0.fld.f26r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB12"); 
state->u.f0.fld.f26r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB13"); 
state->u.f0.fld.f26r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB14"); 
state->u.f0.fld.f26r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB15"); 
state->u.f0.fld.f26r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB16"); 
state->u.f0.fld.f26r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB17"); 
state->u.f0.fld.f26r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB18"); 
state->u.f0.fld.f26r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB19"); 
state->u.f0.fld.f26r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB20"); 
state->u.f0.fld.f26r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB21"); 
state->u.f0.fld.f26r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB22"); 
state->u.f0.fld.f26r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB23"); 
state->u.f0.fld.f26r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB24"); 
state->u.f0.fld.f26r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB25"); 
state->u.f0.fld.f26r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB26"); 
state->u.f0.fld.f26r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB27"); 
state->u.f0.fld.f26r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB28"); 
state->u.f0.fld.f26r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB29"); 
state->u.f0.fld.f26r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB30"); 
state->u.f0.fld.f26r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f26r2, "FB31"); 
// F27R1bitfields.
state->u.f0.fld.f27r1.fb0= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB0"); 
state->u.f0.fld.f27r1.fb1= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB1"); 
state->u.f0.fld.f27r1.fb2= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB2"); 
state->u.f0.fld.f27r1.fb3= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB3"); 
state->u.f0.fld.f27r1.fb4= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB4"); 
state->u.f0.fld.f27r1.fb5= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB5"); 
state->u.f0.fld.f27r1.fb6= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB6"); 
state->u.f0.fld.f27r1.fb7= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB7"); 
state->u.f0.fld.f27r1.fb8= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB8"); 
state->u.f0.fld.f27r1.fb9= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB9"); 
state->u.f0.fld.f27r1.fb10= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB10"); 
state->u.f0.fld.f27r1.fb11= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB11"); 
state->u.f0.fld.f27r1.fb12= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB12"); 
state->u.f0.fld.f27r1.fb13= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB13"); 
state->u.f0.fld.f27r1.fb14= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB14"); 
state->u.f0.fld.f27r1.fb15= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB15"); 
state->u.f0.fld.f27r1.fb16= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB16"); 
state->u.f0.fld.f27r1.fb17= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB17"); 
state->u.f0.fld.f27r1.fb18= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB18"); 
state->u.f0.fld.f27r1.fb19= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB19"); 
state->u.f0.fld.f27r1.fb20= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB20"); 
state->u.f0.fld.f27r1.fb21= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB21"); 
state->u.f0.fld.f27r1.fb22= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB22"); 
state->u.f0.fld.f27r1.fb23= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB23"); 
state->u.f0.fld.f27r1.fb24= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB24"); 
state->u.f0.fld.f27r1.fb25= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB25"); 
state->u.f0.fld.f27r1.fb26= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB26"); 
state->u.f0.fld.f27r1.fb27= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB27"); 
state->u.f0.fld.f27r1.fb28= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB28"); 
state->u.f0.fld.f27r1.fb29= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB29"); 
state->u.f0.fld.f27r1.fb30= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB30"); 
state->u.f0.fld.f27r1.fb31= cm_object_get_child_by_name(state->u.f0.reg.f27r1, "FB31"); 
// F27R2bitfields.
state->u.f0.fld.f27r2.fb0= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB0"); 
state->u.f0.fld.f27r2.fb1= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB1"); 
state->u.f0.fld.f27r2.fb2= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB2"); 
state->u.f0.fld.f27r2.fb3= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB3"); 
state->u.f0.fld.f27r2.fb4= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB4"); 
state->u.f0.fld.f27r2.fb5= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB5"); 
state->u.f0.fld.f27r2.fb6= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB6"); 
state->u.f0.fld.f27r2.fb7= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB7"); 
state->u.f0.fld.f27r2.fb8= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB8"); 
state->u.f0.fld.f27r2.fb9= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB9"); 
state->u.f0.fld.f27r2.fb10= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB10"); 
state->u.f0.fld.f27r2.fb11= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB11"); 
state->u.f0.fld.f27r2.fb12= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB12"); 
state->u.f0.fld.f27r2.fb13= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB13"); 
state->u.f0.fld.f27r2.fb14= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB14"); 
state->u.f0.fld.f27r2.fb15= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB15"); 
state->u.f0.fld.f27r2.fb16= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB16"); 
state->u.f0.fld.f27r2.fb17= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB17"); 
state->u.f0.fld.f27r2.fb18= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB18"); 
state->u.f0.fld.f27r2.fb19= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB19"); 
state->u.f0.fld.f27r2.fb20= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB20"); 
state->u.f0.fld.f27r2.fb21= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB21"); 
state->u.f0.fld.f27r2.fb22= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB22"); 
state->u.f0.fld.f27r2.fb23= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB23"); 
state->u.f0.fld.f27r2.fb24= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB24"); 
state->u.f0.fld.f27r2.fb25= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB25"); 
state->u.f0.fld.f27r2.fb26= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB26"); 
state->u.f0.fld.f27r2.fb27= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB27"); 
state->u.f0.fld.f27r2.fb28= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB28"); 
state->u.f0.fld.f27r2.fb29= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB29"); 
state->u.f0.fld.f27r2.fb30= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB30"); 
state->u.f0.fld.f27r2.fb31= cm_object_get_child_by_name(state->u.f0.reg.f27r2, "FB31"); 
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
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x2) {

            stm32f0x2_can_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_can_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f0.reg.xxx, &stm32_can_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_can_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f0.reg.xxx, &stm32_can_xxx_post_write_callback);

            // TODO: add interrupts.

// TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/CANEN");
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
