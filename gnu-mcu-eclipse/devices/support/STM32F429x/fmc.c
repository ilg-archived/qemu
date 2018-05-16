/*
 * STM32 - FMC (Flexible memory controller) emulation.
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

#include <hw/cortexm/stm32/fmc.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f429x_fmc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32FMCState *state = STM32_FMC_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.bcr1 = cm_object_get_child_by_name(obj, "BCR1");
    state->u.f4.reg.btr1 = cm_object_get_child_by_name(obj, "BTR1");
    state->u.f4.reg.bcr2 = cm_object_get_child_by_name(obj, "BCR2");
    state->u.f4.reg.btr2 = cm_object_get_child_by_name(obj, "BTR2");
    state->u.f4.reg.bcr3 = cm_object_get_child_by_name(obj, "BCR3");
    state->u.f4.reg.btr3 = cm_object_get_child_by_name(obj, "BTR3");
    state->u.f4.reg.bcr4 = cm_object_get_child_by_name(obj, "BCR4");
    state->u.f4.reg.btr4 = cm_object_get_child_by_name(obj, "BTR4");
    state->u.f4.reg.pcr2 = cm_object_get_child_by_name(obj, "PCR2");
    state->u.f4.reg.sr2 = cm_object_get_child_by_name(obj, "SR2");
    state->u.f4.reg.pmem2 = cm_object_get_child_by_name(obj, "PMEM2");
    state->u.f4.reg.patt2 = cm_object_get_child_by_name(obj, "PATT2");
    state->u.f4.reg.eccr2 = cm_object_get_child_by_name(obj, "ECCR2");
    state->u.f4.reg.pcr3 = cm_object_get_child_by_name(obj, "PCR3");
    state->u.f4.reg.sr3 = cm_object_get_child_by_name(obj, "SR3");
    state->u.f4.reg.pmem3 = cm_object_get_child_by_name(obj, "PMEM3");
    state->u.f4.reg.patt3 = cm_object_get_child_by_name(obj, "PATT3");
    state->u.f4.reg.eccr3 = cm_object_get_child_by_name(obj, "ECCR3");
    state->u.f4.reg.pcr4 = cm_object_get_child_by_name(obj, "PCR4");
    state->u.f4.reg.sr4 = cm_object_get_child_by_name(obj, "SR4");
    state->u.f4.reg.pmem4 = cm_object_get_child_by_name(obj, "PMEM4");
    state->u.f4.reg.patt4 = cm_object_get_child_by_name(obj, "PATT4");
    state->u.f4.reg.pio4 = cm_object_get_child_by_name(obj, "PIO4");
    state->u.f4.reg.bwtr1 = cm_object_get_child_by_name(obj, "BWTR1");
    state->u.f4.reg.bwtr2 = cm_object_get_child_by_name(obj, "BWTR2");
    state->u.f4.reg.bwtr3 = cm_object_get_child_by_name(obj, "BWTR3");
    state->u.f4.reg.bwtr4 = cm_object_get_child_by_name(obj, "BWTR4");
    state->u.f4.reg.sdcr1 = cm_object_get_child_by_name(obj, "SDCR1");
    state->u.f4.reg.sdcr2 = cm_object_get_child_by_name(obj, "SDCR2");
    state->u.f4.reg.sdtr1 = cm_object_get_child_by_name(obj, "SDTR1");
    state->u.f4.reg.sdtr2 = cm_object_get_child_by_name(obj, "SDTR2");
    state->u.f4.reg.sdcmr = cm_object_get_child_by_name(obj, "SDCMR");
    state->u.f4.reg.sdrtr = cm_object_get_child_by_name(obj, "SDRTR");
    state->u.f4.reg.sdsr = cm_object_get_child_by_name(obj, "SDSR");
    
    
    // BCR1 bitfields.
    state->u.f4.fld.bcr1.mbken = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "MBKEN"); 
    state->u.f4.fld.bcr1.muxen = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "MUXEN"); 
    state->u.f4.fld.bcr1.mtyp = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "MTYP"); 
    state->u.f4.fld.bcr1.mwid = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "MWID"); 
    state->u.f4.fld.bcr1.faccen = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "FACCEN"); 
    state->u.f4.fld.bcr1.bursten = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "BURSTEN"); 
    state->u.f4.fld.bcr1.waitpol = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "WAITPOL"); 
    state->u.f4.fld.bcr1.waitcfg = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "WAITCFG"); 
    state->u.f4.fld.bcr1.wren = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "WREN"); 
    state->u.f4.fld.bcr1.waiten = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "WAITEN"); 
    state->u.f4.fld.bcr1.extmod = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "EXTMOD"); 
    state->u.f4.fld.bcr1.asyncwait = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "ASYNCWAIT"); 
    state->u.f4.fld.bcr1.cburstrw = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "CBURSTRW"); 
    state->u.f4.fld.bcr1.cclken = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "CCLKEN");  
    
    // BTR1 bitfields.
    state->u.f4.fld.btr1.addset = cm_object_get_child_by_name(state->u.f4.reg.btr1, "ADDSET"); 
    state->u.f4.fld.btr1.addhld = cm_object_get_child_by_name(state->u.f4.reg.btr1, "ADDHLD"); 
    state->u.f4.fld.btr1.datast = cm_object_get_child_by_name(state->u.f4.reg.btr1, "DATAST"); 
    state->u.f4.fld.btr1.busturn = cm_object_get_child_by_name(state->u.f4.reg.btr1, "BUSTURN"); 
    state->u.f4.fld.btr1.clkdiv = cm_object_get_child_by_name(state->u.f4.reg.btr1, "CLKDIV"); 
    state->u.f4.fld.btr1.datlat = cm_object_get_child_by_name(state->u.f4.reg.btr1, "DATLAT"); 
    state->u.f4.fld.btr1.accmod = cm_object_get_child_by_name(state->u.f4.reg.btr1, "ACCMOD");  
    
    // BCR2 bitfields.
    state->u.f4.fld.bcr2.mbken = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "MBKEN"); 
    state->u.f4.fld.bcr2.muxen = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "MUXEN"); 
    state->u.f4.fld.bcr2.mtyp = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "MTYP"); 
    state->u.f4.fld.bcr2.mwid = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "MWID"); 
    state->u.f4.fld.bcr2.faccen = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "FACCEN"); 
    state->u.f4.fld.bcr2.bursten = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "BURSTEN"); 
    state->u.f4.fld.bcr2.waitpol = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "WAITPOL"); 
    state->u.f4.fld.bcr2.wrapmod = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "WRAPMOD"); 
    state->u.f4.fld.bcr2.waitcfg = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "WAITCFG"); 
    state->u.f4.fld.bcr2.wren = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "WREN"); 
    state->u.f4.fld.bcr2.waiten = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "WAITEN"); 
    state->u.f4.fld.bcr2.extmod = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "EXTMOD"); 
    state->u.f4.fld.bcr2.asyncwait = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "ASYNCWAIT"); 
    state->u.f4.fld.bcr2.cburstrw = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "CBURSTRW");  
    
    // BTR2 bitfields.
    state->u.f4.fld.btr2.addset = cm_object_get_child_by_name(state->u.f4.reg.btr2, "ADDSET"); 
    state->u.f4.fld.btr2.addhld = cm_object_get_child_by_name(state->u.f4.reg.btr2, "ADDHLD"); 
    state->u.f4.fld.btr2.datast = cm_object_get_child_by_name(state->u.f4.reg.btr2, "DATAST"); 
    state->u.f4.fld.btr2.busturn = cm_object_get_child_by_name(state->u.f4.reg.btr2, "BUSTURN"); 
    state->u.f4.fld.btr2.clkdiv = cm_object_get_child_by_name(state->u.f4.reg.btr2, "CLKDIV"); 
    state->u.f4.fld.btr2.datlat = cm_object_get_child_by_name(state->u.f4.reg.btr2, "DATLAT"); 
    state->u.f4.fld.btr2.accmod = cm_object_get_child_by_name(state->u.f4.reg.btr2, "ACCMOD");  
    
    // BCR3 bitfields.
    state->u.f4.fld.bcr3.mbken = cm_object_get_child_by_name(state->u.f4.reg.bcr3, "MBKEN"); 
    state->u.f4.fld.bcr3.muxen = cm_object_get_child_by_name(state->u.f4.reg.bcr3, "MUXEN"); 
    state->u.f4.fld.bcr3.mtyp = cm_object_get_child_by_name(state->u.f4.reg.bcr3, "MTYP"); 
    state->u.f4.fld.bcr3.mwid = cm_object_get_child_by_name(state->u.f4.reg.bcr3, "MWID"); 
    state->u.f4.fld.bcr3.faccen = cm_object_get_child_by_name(state->u.f4.reg.bcr3, "FACCEN"); 
    state->u.f4.fld.bcr3.bursten = cm_object_get_child_by_name(state->u.f4.reg.bcr3, "BURSTEN"); 
    state->u.f4.fld.bcr3.waitpol = cm_object_get_child_by_name(state->u.f4.reg.bcr3, "WAITPOL"); 
    state->u.f4.fld.bcr3.wrapmod = cm_object_get_child_by_name(state->u.f4.reg.bcr3, "WRAPMOD"); 
    state->u.f4.fld.bcr3.waitcfg = cm_object_get_child_by_name(state->u.f4.reg.bcr3, "WAITCFG"); 
    state->u.f4.fld.bcr3.wren = cm_object_get_child_by_name(state->u.f4.reg.bcr3, "WREN"); 
    state->u.f4.fld.bcr3.waiten = cm_object_get_child_by_name(state->u.f4.reg.bcr3, "WAITEN"); 
    state->u.f4.fld.bcr3.extmod = cm_object_get_child_by_name(state->u.f4.reg.bcr3, "EXTMOD"); 
    state->u.f4.fld.bcr3.asyncwait = cm_object_get_child_by_name(state->u.f4.reg.bcr3, "ASYNCWAIT"); 
    state->u.f4.fld.bcr3.cburstrw = cm_object_get_child_by_name(state->u.f4.reg.bcr3, "CBURSTRW");  
    
    // BTR3 bitfields.
    state->u.f4.fld.btr3.addset = cm_object_get_child_by_name(state->u.f4.reg.btr3, "ADDSET"); 
    state->u.f4.fld.btr3.addhld = cm_object_get_child_by_name(state->u.f4.reg.btr3, "ADDHLD"); 
    state->u.f4.fld.btr3.datast = cm_object_get_child_by_name(state->u.f4.reg.btr3, "DATAST"); 
    state->u.f4.fld.btr3.busturn = cm_object_get_child_by_name(state->u.f4.reg.btr3, "BUSTURN"); 
    state->u.f4.fld.btr3.clkdiv = cm_object_get_child_by_name(state->u.f4.reg.btr3, "CLKDIV"); 
    state->u.f4.fld.btr3.datlat = cm_object_get_child_by_name(state->u.f4.reg.btr3, "DATLAT"); 
    state->u.f4.fld.btr3.accmod = cm_object_get_child_by_name(state->u.f4.reg.btr3, "ACCMOD");  
    
    // BCR4 bitfields.
    state->u.f4.fld.bcr4.mbken = cm_object_get_child_by_name(state->u.f4.reg.bcr4, "MBKEN"); 
    state->u.f4.fld.bcr4.muxen = cm_object_get_child_by_name(state->u.f4.reg.bcr4, "MUXEN"); 
    state->u.f4.fld.bcr4.mtyp = cm_object_get_child_by_name(state->u.f4.reg.bcr4, "MTYP"); 
    state->u.f4.fld.bcr4.mwid = cm_object_get_child_by_name(state->u.f4.reg.bcr4, "MWID"); 
    state->u.f4.fld.bcr4.faccen = cm_object_get_child_by_name(state->u.f4.reg.bcr4, "FACCEN"); 
    state->u.f4.fld.bcr4.bursten = cm_object_get_child_by_name(state->u.f4.reg.bcr4, "BURSTEN"); 
    state->u.f4.fld.bcr4.waitpol = cm_object_get_child_by_name(state->u.f4.reg.bcr4, "WAITPOL"); 
    state->u.f4.fld.bcr4.wrapmod = cm_object_get_child_by_name(state->u.f4.reg.bcr4, "WRAPMOD"); 
    state->u.f4.fld.bcr4.waitcfg = cm_object_get_child_by_name(state->u.f4.reg.bcr4, "WAITCFG"); 
    state->u.f4.fld.bcr4.wren = cm_object_get_child_by_name(state->u.f4.reg.bcr4, "WREN"); 
    state->u.f4.fld.bcr4.waiten = cm_object_get_child_by_name(state->u.f4.reg.bcr4, "WAITEN"); 
    state->u.f4.fld.bcr4.extmod = cm_object_get_child_by_name(state->u.f4.reg.bcr4, "EXTMOD"); 
    state->u.f4.fld.bcr4.asyncwait = cm_object_get_child_by_name(state->u.f4.reg.bcr4, "ASYNCWAIT"); 
    state->u.f4.fld.bcr4.cburstrw = cm_object_get_child_by_name(state->u.f4.reg.bcr4, "CBURSTRW");  
    
    // BTR4 bitfields.
    state->u.f4.fld.btr4.addset = cm_object_get_child_by_name(state->u.f4.reg.btr4, "ADDSET"); 
    state->u.f4.fld.btr4.addhld = cm_object_get_child_by_name(state->u.f4.reg.btr4, "ADDHLD"); 
    state->u.f4.fld.btr4.datast = cm_object_get_child_by_name(state->u.f4.reg.btr4, "DATAST"); 
    state->u.f4.fld.btr4.busturn = cm_object_get_child_by_name(state->u.f4.reg.btr4, "BUSTURN"); 
    state->u.f4.fld.btr4.clkdiv = cm_object_get_child_by_name(state->u.f4.reg.btr4, "CLKDIV"); 
    state->u.f4.fld.btr4.datlat = cm_object_get_child_by_name(state->u.f4.reg.btr4, "DATLAT"); 
    state->u.f4.fld.btr4.accmod = cm_object_get_child_by_name(state->u.f4.reg.btr4, "ACCMOD");  
    
    // PCR2 bitfields.
    state->u.f4.fld.pcr2.pwaiten = cm_object_get_child_by_name(state->u.f4.reg.pcr2, "PWAITEN"); 
    state->u.f4.fld.pcr2.pbken = cm_object_get_child_by_name(state->u.f4.reg.pcr2, "PBKEN"); 
    state->u.f4.fld.pcr2.ptyp = cm_object_get_child_by_name(state->u.f4.reg.pcr2, "PTYP"); 
    state->u.f4.fld.pcr2.pwid = cm_object_get_child_by_name(state->u.f4.reg.pcr2, "PWID"); 
    state->u.f4.fld.pcr2.eccen = cm_object_get_child_by_name(state->u.f4.reg.pcr2, "ECCEN"); 
    state->u.f4.fld.pcr2.tclr = cm_object_get_child_by_name(state->u.f4.reg.pcr2, "TCLR"); 
    state->u.f4.fld.pcr2.tar = cm_object_get_child_by_name(state->u.f4.reg.pcr2, "TAR"); 
    state->u.f4.fld.pcr2.eccps = cm_object_get_child_by_name(state->u.f4.reg.pcr2, "ECCPS");  
    
    // SR2 bitfields.
    state->u.f4.fld.sr2.irs = cm_object_get_child_by_name(state->u.f4.reg.sr2, "IRS"); 
    state->u.f4.fld.sr2.ils = cm_object_get_child_by_name(state->u.f4.reg.sr2, "ILS"); 
    state->u.f4.fld.sr2.ifs = cm_object_get_child_by_name(state->u.f4.reg.sr2, "IFS"); 
    state->u.f4.fld.sr2.iren = cm_object_get_child_by_name(state->u.f4.reg.sr2, "IREN"); 
    state->u.f4.fld.sr2.ilen = cm_object_get_child_by_name(state->u.f4.reg.sr2, "ILEN"); 
    state->u.f4.fld.sr2.ifen = cm_object_get_child_by_name(state->u.f4.reg.sr2, "IFEN"); 
    state->u.f4.fld.sr2.fempt = cm_object_get_child_by_name(state->u.f4.reg.sr2, "FEMPT");  
    
    // PMEM2 bitfields.
    state->u.f4.fld.pmem2.memsetx = cm_object_get_child_by_name(state->u.f4.reg.pmem2, "MEMSETx"); 
    state->u.f4.fld.pmem2.memwaitx = cm_object_get_child_by_name(state->u.f4.reg.pmem2, "MEMWAITx"); 
    state->u.f4.fld.pmem2.memholdx = cm_object_get_child_by_name(state->u.f4.reg.pmem2, "MEMHOLDx"); 
    state->u.f4.fld.pmem2.memhizx = cm_object_get_child_by_name(state->u.f4.reg.pmem2, "MEMHIZx");  
    
    // PATT2 bitfields.
    state->u.f4.fld.patt2.attsetx = cm_object_get_child_by_name(state->u.f4.reg.patt2, "ATTSETx"); 
    state->u.f4.fld.patt2.attwaitx = cm_object_get_child_by_name(state->u.f4.reg.patt2, "ATTWAITx"); 
    state->u.f4.fld.patt2.attholdx = cm_object_get_child_by_name(state->u.f4.reg.patt2, "ATTHOLDx"); 
    state->u.f4.fld.patt2.atthizx = cm_object_get_child_by_name(state->u.f4.reg.patt2, "ATTHIZx");  
    
    // ECCR2 bitfields.
    state->u.f4.fld.eccr2.eccx = cm_object_get_child_by_name(state->u.f4.reg.eccr2, "ECCx");  
    
    // PCR3 bitfields.
    state->u.f4.fld.pcr3.pwaiten = cm_object_get_child_by_name(state->u.f4.reg.pcr3, "PWAITEN"); 
    state->u.f4.fld.pcr3.pbken = cm_object_get_child_by_name(state->u.f4.reg.pcr3, "PBKEN"); 
    state->u.f4.fld.pcr3.ptyp = cm_object_get_child_by_name(state->u.f4.reg.pcr3, "PTYP"); 
    state->u.f4.fld.pcr3.pwid = cm_object_get_child_by_name(state->u.f4.reg.pcr3, "PWID"); 
    state->u.f4.fld.pcr3.eccen = cm_object_get_child_by_name(state->u.f4.reg.pcr3, "ECCEN"); 
    state->u.f4.fld.pcr3.tclr = cm_object_get_child_by_name(state->u.f4.reg.pcr3, "TCLR"); 
    state->u.f4.fld.pcr3.tar = cm_object_get_child_by_name(state->u.f4.reg.pcr3, "TAR"); 
    state->u.f4.fld.pcr3.eccps = cm_object_get_child_by_name(state->u.f4.reg.pcr3, "ECCPS");  
    
    // SR3 bitfields.
    state->u.f4.fld.sr3.irs = cm_object_get_child_by_name(state->u.f4.reg.sr3, "IRS"); 
    state->u.f4.fld.sr3.ils = cm_object_get_child_by_name(state->u.f4.reg.sr3, "ILS"); 
    state->u.f4.fld.sr3.ifs = cm_object_get_child_by_name(state->u.f4.reg.sr3, "IFS"); 
    state->u.f4.fld.sr3.iren = cm_object_get_child_by_name(state->u.f4.reg.sr3, "IREN"); 
    state->u.f4.fld.sr3.ilen = cm_object_get_child_by_name(state->u.f4.reg.sr3, "ILEN"); 
    state->u.f4.fld.sr3.ifen = cm_object_get_child_by_name(state->u.f4.reg.sr3, "IFEN"); 
    state->u.f4.fld.sr3.fempt = cm_object_get_child_by_name(state->u.f4.reg.sr3, "FEMPT");  
    
    // PMEM3 bitfields.
    state->u.f4.fld.pmem3.memsetx = cm_object_get_child_by_name(state->u.f4.reg.pmem3, "MEMSETx"); 
    state->u.f4.fld.pmem3.memwaitx = cm_object_get_child_by_name(state->u.f4.reg.pmem3, "MEMWAITx"); 
    state->u.f4.fld.pmem3.memholdx = cm_object_get_child_by_name(state->u.f4.reg.pmem3, "MEMHOLDx"); 
    state->u.f4.fld.pmem3.memhizx = cm_object_get_child_by_name(state->u.f4.reg.pmem3, "MEMHIZx");  
    
    // PATT3 bitfields.
    state->u.f4.fld.patt3.attsetx = cm_object_get_child_by_name(state->u.f4.reg.patt3, "ATTSETx"); 
    state->u.f4.fld.patt3.attwaitx = cm_object_get_child_by_name(state->u.f4.reg.patt3, "ATTWAITx"); 
    state->u.f4.fld.patt3.attholdx = cm_object_get_child_by_name(state->u.f4.reg.patt3, "ATTHOLDx"); 
    state->u.f4.fld.patt3.atthizx = cm_object_get_child_by_name(state->u.f4.reg.patt3, "ATTHIZx");  
    
    // ECCR3 bitfields.
    state->u.f4.fld.eccr3.eccx = cm_object_get_child_by_name(state->u.f4.reg.eccr3, "ECCx");  
    
    // PCR4 bitfields.
    state->u.f4.fld.pcr4.pwaiten = cm_object_get_child_by_name(state->u.f4.reg.pcr4, "PWAITEN"); 
    state->u.f4.fld.pcr4.pbken = cm_object_get_child_by_name(state->u.f4.reg.pcr4, "PBKEN"); 
    state->u.f4.fld.pcr4.ptyp = cm_object_get_child_by_name(state->u.f4.reg.pcr4, "PTYP"); 
    state->u.f4.fld.pcr4.pwid = cm_object_get_child_by_name(state->u.f4.reg.pcr4, "PWID"); 
    state->u.f4.fld.pcr4.eccen = cm_object_get_child_by_name(state->u.f4.reg.pcr4, "ECCEN"); 
    state->u.f4.fld.pcr4.tclr = cm_object_get_child_by_name(state->u.f4.reg.pcr4, "TCLR"); 
    state->u.f4.fld.pcr4.tar = cm_object_get_child_by_name(state->u.f4.reg.pcr4, "TAR"); 
    state->u.f4.fld.pcr4.eccps = cm_object_get_child_by_name(state->u.f4.reg.pcr4, "ECCPS");  
    
    // SR4 bitfields.
    state->u.f4.fld.sr4.irs = cm_object_get_child_by_name(state->u.f4.reg.sr4, "IRS"); 
    state->u.f4.fld.sr4.ils = cm_object_get_child_by_name(state->u.f4.reg.sr4, "ILS"); 
    state->u.f4.fld.sr4.ifs = cm_object_get_child_by_name(state->u.f4.reg.sr4, "IFS"); 
    state->u.f4.fld.sr4.iren = cm_object_get_child_by_name(state->u.f4.reg.sr4, "IREN"); 
    state->u.f4.fld.sr4.ilen = cm_object_get_child_by_name(state->u.f4.reg.sr4, "ILEN"); 
    state->u.f4.fld.sr4.ifen = cm_object_get_child_by_name(state->u.f4.reg.sr4, "IFEN"); 
    state->u.f4.fld.sr4.fempt = cm_object_get_child_by_name(state->u.f4.reg.sr4, "FEMPT");  
    
    // PMEM4 bitfields.
    state->u.f4.fld.pmem4.memsetx = cm_object_get_child_by_name(state->u.f4.reg.pmem4, "MEMSETx"); 
    state->u.f4.fld.pmem4.memwaitx = cm_object_get_child_by_name(state->u.f4.reg.pmem4, "MEMWAITx"); 
    state->u.f4.fld.pmem4.memholdx = cm_object_get_child_by_name(state->u.f4.reg.pmem4, "MEMHOLDx"); 
    state->u.f4.fld.pmem4.memhizx = cm_object_get_child_by_name(state->u.f4.reg.pmem4, "MEMHIZx");  
    
    // PATT4 bitfields.
    state->u.f4.fld.patt4.attsetx = cm_object_get_child_by_name(state->u.f4.reg.patt4, "ATTSETx"); 
    state->u.f4.fld.patt4.attwaitx = cm_object_get_child_by_name(state->u.f4.reg.patt4, "ATTWAITx"); 
    state->u.f4.fld.patt4.attholdx = cm_object_get_child_by_name(state->u.f4.reg.patt4, "ATTHOLDx"); 
    state->u.f4.fld.patt4.atthizx = cm_object_get_child_by_name(state->u.f4.reg.patt4, "ATTHIZx");  
    
    // PIO4 bitfields.
    state->u.f4.fld.pio4.iosetx = cm_object_get_child_by_name(state->u.f4.reg.pio4, "IOSETx"); 
    state->u.f4.fld.pio4.iowaitx = cm_object_get_child_by_name(state->u.f4.reg.pio4, "IOWAITx"); 
    state->u.f4.fld.pio4.ioholdx = cm_object_get_child_by_name(state->u.f4.reg.pio4, "IOHOLDx"); 
    state->u.f4.fld.pio4.iohizx = cm_object_get_child_by_name(state->u.f4.reg.pio4, "IOHIZx");  
    
    // BWTR1 bitfields.
    state->u.f4.fld.bwtr1.addset = cm_object_get_child_by_name(state->u.f4.reg.bwtr1, "ADDSET"); 
    state->u.f4.fld.bwtr1.addhld = cm_object_get_child_by_name(state->u.f4.reg.bwtr1, "ADDHLD"); 
    state->u.f4.fld.bwtr1.datast = cm_object_get_child_by_name(state->u.f4.reg.bwtr1, "DATAST"); 
    state->u.f4.fld.bwtr1.clkdiv = cm_object_get_child_by_name(state->u.f4.reg.bwtr1, "CLKDIV"); 
    state->u.f4.fld.bwtr1.datlat = cm_object_get_child_by_name(state->u.f4.reg.bwtr1, "DATLAT"); 
    state->u.f4.fld.bwtr1.accmod = cm_object_get_child_by_name(state->u.f4.reg.bwtr1, "ACCMOD");  
    
    // BWTR2 bitfields.
    state->u.f4.fld.bwtr2.addset = cm_object_get_child_by_name(state->u.f4.reg.bwtr2, "ADDSET"); 
    state->u.f4.fld.bwtr2.addhld = cm_object_get_child_by_name(state->u.f4.reg.bwtr2, "ADDHLD"); 
    state->u.f4.fld.bwtr2.datast = cm_object_get_child_by_name(state->u.f4.reg.bwtr2, "DATAST"); 
    state->u.f4.fld.bwtr2.clkdiv = cm_object_get_child_by_name(state->u.f4.reg.bwtr2, "CLKDIV"); 
    state->u.f4.fld.bwtr2.datlat = cm_object_get_child_by_name(state->u.f4.reg.bwtr2, "DATLAT"); 
    state->u.f4.fld.bwtr2.accmod = cm_object_get_child_by_name(state->u.f4.reg.bwtr2, "ACCMOD");  
    
    // BWTR3 bitfields.
    state->u.f4.fld.bwtr3.addset = cm_object_get_child_by_name(state->u.f4.reg.bwtr3, "ADDSET"); 
    state->u.f4.fld.bwtr3.addhld = cm_object_get_child_by_name(state->u.f4.reg.bwtr3, "ADDHLD"); 
    state->u.f4.fld.bwtr3.datast = cm_object_get_child_by_name(state->u.f4.reg.bwtr3, "DATAST"); 
    state->u.f4.fld.bwtr3.clkdiv = cm_object_get_child_by_name(state->u.f4.reg.bwtr3, "CLKDIV"); 
    state->u.f4.fld.bwtr3.datlat = cm_object_get_child_by_name(state->u.f4.reg.bwtr3, "DATLAT"); 
    state->u.f4.fld.bwtr3.accmod = cm_object_get_child_by_name(state->u.f4.reg.bwtr3, "ACCMOD");  
    
    // BWTR4 bitfields.
    state->u.f4.fld.bwtr4.addset = cm_object_get_child_by_name(state->u.f4.reg.bwtr4, "ADDSET"); 
    state->u.f4.fld.bwtr4.addhld = cm_object_get_child_by_name(state->u.f4.reg.bwtr4, "ADDHLD"); 
    state->u.f4.fld.bwtr4.datast = cm_object_get_child_by_name(state->u.f4.reg.bwtr4, "DATAST"); 
    state->u.f4.fld.bwtr4.clkdiv = cm_object_get_child_by_name(state->u.f4.reg.bwtr4, "CLKDIV"); 
    state->u.f4.fld.bwtr4.datlat = cm_object_get_child_by_name(state->u.f4.reg.bwtr4, "DATLAT"); 
    state->u.f4.fld.bwtr4.accmod = cm_object_get_child_by_name(state->u.f4.reg.bwtr4, "ACCMOD");  
    
    // SDCR1 bitfields.
    state->u.f4.fld.sdcr1.nc = cm_object_get_child_by_name(state->u.f4.reg.sdcr1, "NC"); 
    state->u.f4.fld.sdcr1.nr = cm_object_get_child_by_name(state->u.f4.reg.sdcr1, "NR"); 
    state->u.f4.fld.sdcr1.mwid = cm_object_get_child_by_name(state->u.f4.reg.sdcr1, "MWID"); 
    state->u.f4.fld.sdcr1.nb = cm_object_get_child_by_name(state->u.f4.reg.sdcr1, "NB"); 
    state->u.f4.fld.sdcr1.cas = cm_object_get_child_by_name(state->u.f4.reg.sdcr1, "CAS"); 
    state->u.f4.fld.sdcr1.wp = cm_object_get_child_by_name(state->u.f4.reg.sdcr1, "WP"); 
    state->u.f4.fld.sdcr1.sdclk = cm_object_get_child_by_name(state->u.f4.reg.sdcr1, "SDCLK"); 
    state->u.f4.fld.sdcr1.rburst = cm_object_get_child_by_name(state->u.f4.reg.sdcr1, "RBURST"); 
    state->u.f4.fld.sdcr1.rpipe = cm_object_get_child_by_name(state->u.f4.reg.sdcr1, "RPIPE");  
    
    // SDCR2 bitfields.
    state->u.f4.fld.sdcr2.nc = cm_object_get_child_by_name(state->u.f4.reg.sdcr2, "NC"); 
    state->u.f4.fld.sdcr2.nr = cm_object_get_child_by_name(state->u.f4.reg.sdcr2, "NR"); 
    state->u.f4.fld.sdcr2.mwid = cm_object_get_child_by_name(state->u.f4.reg.sdcr2, "MWID"); 
    state->u.f4.fld.sdcr2.nb = cm_object_get_child_by_name(state->u.f4.reg.sdcr2, "NB"); 
    state->u.f4.fld.sdcr2.cas = cm_object_get_child_by_name(state->u.f4.reg.sdcr2, "CAS"); 
    state->u.f4.fld.sdcr2.wp = cm_object_get_child_by_name(state->u.f4.reg.sdcr2, "WP"); 
    state->u.f4.fld.sdcr2.sdclk = cm_object_get_child_by_name(state->u.f4.reg.sdcr2, "SDCLK"); 
    state->u.f4.fld.sdcr2.rburst = cm_object_get_child_by_name(state->u.f4.reg.sdcr2, "RBURST"); 
    state->u.f4.fld.sdcr2.rpipe = cm_object_get_child_by_name(state->u.f4.reg.sdcr2, "RPIPE");  
    
    // SDTR1 bitfields.
    state->u.f4.fld.sdtr1.tmrd = cm_object_get_child_by_name(state->u.f4.reg.sdtr1, "TMRD"); 
    state->u.f4.fld.sdtr1.txsr = cm_object_get_child_by_name(state->u.f4.reg.sdtr1, "TXSR"); 
    state->u.f4.fld.sdtr1.tras = cm_object_get_child_by_name(state->u.f4.reg.sdtr1, "TRAS"); 
    state->u.f4.fld.sdtr1.trc = cm_object_get_child_by_name(state->u.f4.reg.sdtr1, "TRC"); 
    state->u.f4.fld.sdtr1.twr = cm_object_get_child_by_name(state->u.f4.reg.sdtr1, "TWR"); 
    state->u.f4.fld.sdtr1.trp = cm_object_get_child_by_name(state->u.f4.reg.sdtr1, "TRP"); 
    state->u.f4.fld.sdtr1.trcd = cm_object_get_child_by_name(state->u.f4.reg.sdtr1, "TRCD");  
    
    // SDTR2 bitfields.
    state->u.f4.fld.sdtr2.tmrd = cm_object_get_child_by_name(state->u.f4.reg.sdtr2, "TMRD"); 
    state->u.f4.fld.sdtr2.txsr = cm_object_get_child_by_name(state->u.f4.reg.sdtr2, "TXSR"); 
    state->u.f4.fld.sdtr2.tras = cm_object_get_child_by_name(state->u.f4.reg.sdtr2, "TRAS"); 
    state->u.f4.fld.sdtr2.trc = cm_object_get_child_by_name(state->u.f4.reg.sdtr2, "TRC"); 
    state->u.f4.fld.sdtr2.twr = cm_object_get_child_by_name(state->u.f4.reg.sdtr2, "TWR"); 
    state->u.f4.fld.sdtr2.trp = cm_object_get_child_by_name(state->u.f4.reg.sdtr2, "TRP"); 
    state->u.f4.fld.sdtr2.trcd = cm_object_get_child_by_name(state->u.f4.reg.sdtr2, "TRCD");  
    
    // SDCMR bitfields.
    state->u.f4.fld.sdcmr.mode = cm_object_get_child_by_name(state->u.f4.reg.sdcmr, "MODE"); 
    state->u.f4.fld.sdcmr.ctb2 = cm_object_get_child_by_name(state->u.f4.reg.sdcmr, "CTB2"); 
    state->u.f4.fld.sdcmr.ctb1 = cm_object_get_child_by_name(state->u.f4.reg.sdcmr, "CTB1"); 
    state->u.f4.fld.sdcmr.nrfs = cm_object_get_child_by_name(state->u.f4.reg.sdcmr, "NRFS"); 
    state->u.f4.fld.sdcmr.mrd = cm_object_get_child_by_name(state->u.f4.reg.sdcmr, "MRD");  
    
    // SDRTR bitfields.
    state->u.f4.fld.sdrtr.cre = cm_object_get_child_by_name(state->u.f4.reg.sdrtr, "CRE"); 
    state->u.f4.fld.sdrtr.count = cm_object_get_child_by_name(state->u.f4.reg.sdrtr, "COUNT"); 
    state->u.f4.fld.sdrtr.reie = cm_object_get_child_by_name(state->u.f4.reg.sdrtr, "REIE");  
    
    // SDSR bitfields.
    state->u.f4.fld.sdsr.re = cm_object_get_child_by_name(state->u.f4.reg.sdsr, "RE"); 
    state->u.f4.fld.sdsr.modes1 = cm_object_get_child_by_name(state->u.f4.reg.sdsr, "MODES1"); 
    state->u.f4.fld.sdsr.modes2 = cm_object_get_child_by_name(state->u.f4.reg.sdsr, "MODES2"); 
    state->u.f4.fld.sdsr.busy = cm_object_get_child_by_name(state->u.f4.reg.sdsr, "BUSY");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_fmc_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32FMCState *state = STM32_FMC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_fmc_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32FMCState *state = STM32_FMC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_fmc_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32FMCState *state = STM32_FMC_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_fmc_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32FMCState *state = STM32_FMC_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_fmc_is_enabled(Object *obj)
{
    STM32FMCState *state = STM32_FMC_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_fmc_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32FMCState *state = STM32_FMC_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_fmc_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_FMC)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32FMCState *state = STM32_FMC_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "FMC";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_429x ) {

            stm32f429x_fmc_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_fmc_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_fmc_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_fmc_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_fmc_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/FMCEN");


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

static void stm32_fmc_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_FMC);
}

static void stm32_fmc_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_fmc_reset_callback;
    dc->realize = stm32_fmc_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_fmc_is_enabled;
}

static const TypeInfo stm32_fmc_type_info = {
    .name = TYPE_STM32_FMC,
    .parent = TYPE_STM32_FMC_PARENT,
    .instance_init = stm32_fmc_instance_init_callback,
    .instance_size = sizeof(STM32FMCState),
    .class_init = stm32_fmc_class_init_callback,
    .class_size = sizeof(STM32FMCClass) };

static void stm32_fmc_register_types(void)
{
    type_register_static(&stm32_fmc_type_info);
}

type_init(stm32_fmc_register_types);

// ----------------------------------------------------------------------------
