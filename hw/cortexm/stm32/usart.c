/*
 * STM32 USART
 *
 * Copyright (c) 2015 Dimitri L. <dimdimdimdim at gmx dot fr>
 * Includes substantial work from:
 * 	Copyright (c) 2015 Liviu Ionescu (stm32-gpio.c)
 * 	Copyright (c) 2014 Alistair Francis (stm32f2xx_usart.c)
 * 	Copyright (c) 2010 Andre Beckus (stm32-gpio.c)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <hw/cortexm/stm32/usart.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/svd.h>

#include "sysemu/sysemu.h"

#define USART_SR_TXE        (1 << 7)
#define USART_SR_TC         (1 << 6)
#define USART_SR_RXNE       (1 << 5)

#define USART_CR1_UE        (1 << 13)
#define USART_CR1_TXEIE     (1 << 7)
#define USART_CR1_TCIE      (1 << 6)
#define USART_CR1_RXNEIE    (1 << 5)
#define USART_CR1_TE        (1 << 3)
#define USART_CR1_RE        (1 << 2)

// ----- Generated code -------------------------------------------------------

// STM32F051R8
// DO NOT EDIT! Automatically generated!
static void stm32f0x1_usart_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32USARTState *state = STM32_USART_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f0.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
    state->u.f0.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
    state->u.f0.reg.cr3 = cm_object_get_child_by_name(obj, "CR3");
    state->u.f0.reg.brr = cm_object_get_child_by_name(obj, "BRR");
    state->u.f0.reg.gtpr = cm_object_get_child_by_name(obj, "GTPR");
    state->u.f0.reg.rtor = cm_object_get_child_by_name(obj, "RTOR");
    state->u.f0.reg.rqr = cm_object_get_child_by_name(obj, "RQR");
    state->u.f0.reg.isr = cm_object_get_child_by_name(obj, "ISR");
    state->u.f0.reg.icr = cm_object_get_child_by_name(obj, "ICR");
    state->u.f0.reg.rdr = cm_object_get_child_by_name(obj, "RDR");
    state->u.f0.reg.tdr = cm_object_get_child_by_name(obj, "TDR");

    // CR1 bitfields.
    state->u.f0.fld.cr1.ue = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "UE");
    state->u.f0.fld.cr1.uesm = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "UESM");
    state->u.f0.fld.cr1.re = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "RE");
    state->u.f0.fld.cr1.te = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "TE");
    state->u.f0.fld.cr1.idleie = cm_object_get_child_by_name(
            state->u.f0.reg.cr1, "IDLEIE");
    state->u.f0.fld.cr1.rxneie = cm_object_get_child_by_name(
            state->u.f0.reg.cr1, "RXNEIE");
    state->u.f0.fld.cr1.tcie = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "TCIE");
    state->u.f0.fld.cr1.txeie = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "TXEIE");
    state->u.f0.fld.cr1.peie = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "PEIE");
    state->u.f0.fld.cr1.ps = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "PS");
    state->u.f0.fld.cr1.pce = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "PCE");
    state->u.f0.fld.cr1.wake = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "WAKE");
    state->u.f0.fld.cr1.m = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "M");
    state->u.f0.fld.cr1.mme = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "MME");
    state->u.f0.fld.cr1.cmie = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "CMIE");
    state->u.f0.fld.cr1.over8 = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "OVER8");
    state->u.f0.fld.cr1.dedt = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "DEDT");
    state->u.f0.fld.cr1.deat = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "DEAT");
    state->u.f0.fld.cr1.rtoie = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "RTOIE");
    state->u.f0.fld.cr1.eobie = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "EOBIE");
    state->u.f0.fld.cr1.m1 = cm_object_get_child_by_name(state->u.f0.reg.cr1,
            "M1");

    // CR2 bitfields.
    state->u.f0.fld.cr2.addm7 = cm_object_get_child_by_name(state->u.f0.reg.cr2,
            "ADDM7");
    state->u.f0.fld.cr2.lbdl = cm_object_get_child_by_name(state->u.f0.reg.cr2,
            "LBDL");
    state->u.f0.fld.cr2.lbdie = cm_object_get_child_by_name(state->u.f0.reg.cr2,
            "LBDIE");
    state->u.f0.fld.cr2.lbcl = cm_object_get_child_by_name(state->u.f0.reg.cr2,
            "LBCL");
    state->u.f0.fld.cr2.cpha = cm_object_get_child_by_name(state->u.f0.reg.cr2,
            "CPHA");
    state->u.f0.fld.cr2.cpol = cm_object_get_child_by_name(state->u.f0.reg.cr2,
            "CPOL");
    state->u.f0.fld.cr2.clken = cm_object_get_child_by_name(state->u.f0.reg.cr2,
            "CLKEN");
    state->u.f0.fld.cr2.stop = cm_object_get_child_by_name(state->u.f0.reg.cr2,
            "STOP");
    state->u.f0.fld.cr2.linen = cm_object_get_child_by_name(state->u.f0.reg.cr2,
            "LINEN");
    state->u.f0.fld.cr2.swap = cm_object_get_child_by_name(state->u.f0.reg.cr2,
            "SWAP");
    state->u.f0.fld.cr2.rxinv = cm_object_get_child_by_name(state->u.f0.reg.cr2,
            "RXINV");
    state->u.f0.fld.cr2.txinv = cm_object_get_child_by_name(state->u.f0.reg.cr2,
            "TXINV");
    state->u.f0.fld.cr2.datainv = cm_object_get_child_by_name(
            state->u.f0.reg.cr2, "DATAINV");
    state->u.f0.fld.cr2.msbfirst = cm_object_get_child_by_name(
            state->u.f0.reg.cr2, "MSBFIRST");
    state->u.f0.fld.cr2.abren = cm_object_get_child_by_name(state->u.f0.reg.cr2,
            "ABREN");
    state->u.f0.fld.cr2.abrmod = cm_object_get_child_by_name(
            state->u.f0.reg.cr2, "ABRMOD");
    state->u.f0.fld.cr2.rtoen = cm_object_get_child_by_name(state->u.f0.reg.cr2,
            "RTOEN");
    state->u.f0.fld.cr2.add0 = cm_object_get_child_by_name(state->u.f0.reg.cr2,
            "ADD0");
    state->u.f0.fld.cr2.add4 = cm_object_get_child_by_name(state->u.f0.reg.cr2,
            "ADD4");

    // CR3 bitfields.
    state->u.f0.fld.cr3.eie = cm_object_get_child_by_name(state->u.f0.reg.cr3,
            "EIE");
    state->u.f0.fld.cr3.iren = cm_object_get_child_by_name(state->u.f0.reg.cr3,
            "IREN");
    state->u.f0.fld.cr3.irlp = cm_object_get_child_by_name(state->u.f0.reg.cr3,
            "IRLP");
    state->u.f0.fld.cr3.hdsel = cm_object_get_child_by_name(state->u.f0.reg.cr3,
            "HDSEL");
    state->u.f0.fld.cr3.nack = cm_object_get_child_by_name(state->u.f0.reg.cr3,
            "NACK");
    state->u.f0.fld.cr3.scen = cm_object_get_child_by_name(state->u.f0.reg.cr3,
            "SCEN");
    state->u.f0.fld.cr3.dmar = cm_object_get_child_by_name(state->u.f0.reg.cr3,
            "DMAR");
    state->u.f0.fld.cr3.dmat = cm_object_get_child_by_name(state->u.f0.reg.cr3,
            "DMAT");
    state->u.f0.fld.cr3.rtse = cm_object_get_child_by_name(state->u.f0.reg.cr3,
            "RTSE");
    state->u.f0.fld.cr3.ctse = cm_object_get_child_by_name(state->u.f0.reg.cr3,
            "CTSE");
    state->u.f0.fld.cr3.ctsie = cm_object_get_child_by_name(state->u.f0.reg.cr3,
            "CTSIE");
    state->u.f0.fld.cr3.onebit = cm_object_get_child_by_name(
            state->u.f0.reg.cr3, "ONEBIT");
    state->u.f0.fld.cr3.ovrdis = cm_object_get_child_by_name(
            state->u.f0.reg.cr3, "OVRDIS");
    state->u.f0.fld.cr3.ddre = cm_object_get_child_by_name(state->u.f0.reg.cr3,
            "DDRE");
    state->u.f0.fld.cr3.dem = cm_object_get_child_by_name(state->u.f0.reg.cr3,
            "DEM");
    state->u.f0.fld.cr3.dep = cm_object_get_child_by_name(state->u.f0.reg.cr3,
            "DEP");
    state->u.f0.fld.cr3.scarcnt = cm_object_get_child_by_name(
            state->u.f0.reg.cr3, "SCARCNT");
    state->u.f0.fld.cr3.wus = cm_object_get_child_by_name(state->u.f0.reg.cr3,
            "WUS");
    state->u.f0.fld.cr3.wufie = cm_object_get_child_by_name(state->u.f0.reg.cr3,
            "WUFIE");

    // BRR bitfields.
    state->u.f0.fld.brr.div_fraction = cm_object_get_child_by_name(
            state->u.f0.reg.brr, "DIV_Fraction");
    state->u.f0.fld.brr.div_mantissa = cm_object_get_child_by_name(
            state->u.f0.reg.brr, "DIV_Mantissa");

    // GTPR bitfields.
    state->u.f0.fld.gtpr.psc = cm_object_get_child_by_name(state->u.f0.reg.gtpr,
            "PSC");
    state->u.f0.fld.gtpr.gt = cm_object_get_child_by_name(state->u.f0.reg.gtpr,
            "GT");

    // RTOR bitfields.
    state->u.f0.fld.rtor.rto = cm_object_get_child_by_name(state->u.f0.reg.rtor,
            "RTO");
    state->u.f0.fld.rtor.blen = cm_object_get_child_by_name(
            state->u.f0.reg.rtor, "BLEN");

    // RQR bitfields.
    state->u.f0.fld.rqr.abrrq = cm_object_get_child_by_name(state->u.f0.reg.rqr,
            "ABRRQ");
    state->u.f0.fld.rqr.sbkrq = cm_object_get_child_by_name(state->u.f0.reg.rqr,
            "SBKRQ");
    state->u.f0.fld.rqr.mmrq = cm_object_get_child_by_name(state->u.f0.reg.rqr,
            "MMRQ");
    state->u.f0.fld.rqr.rxfrq = cm_object_get_child_by_name(state->u.f0.reg.rqr,
            "RXFRQ");
    state->u.f0.fld.rqr.txfrq = cm_object_get_child_by_name(state->u.f0.reg.rqr,
            "TXFRQ");

    // ISR bitfields.
    state->u.f0.fld.isr.pe = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "PE");
    state->u.f0.fld.isr.fe = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "FE");
    state->u.f0.fld.isr.nf = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "NF");
    state->u.f0.fld.isr.ore = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "ORE");
    state->u.f0.fld.isr.idle = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "IDLE");
    state->u.f0.fld.isr.rxne = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "RXNE");
    state->u.f0.fld.isr.tc = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "TC");
    state->u.f0.fld.isr.txe = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "TXE");
    state->u.f0.fld.isr.lbdf = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "LBDF");
    state->u.f0.fld.isr.ctsif = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "CTSIF");
    state->u.f0.fld.isr.cts = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "CTS");
    state->u.f0.fld.isr.rtof = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "RTOF");
    state->u.f0.fld.isr.eobf = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "EOBF");
    state->u.f0.fld.isr.abre = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "ABRE");
    state->u.f0.fld.isr.abrf = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "ABRF");
    state->u.f0.fld.isr.busy = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "BUSY");
    state->u.f0.fld.isr.cmf = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "CMF");
    state->u.f0.fld.isr.sbkf = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "SBKF");
    state->u.f0.fld.isr.rwu = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "RWU");
    state->u.f0.fld.isr.wuf = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "WUF");
    state->u.f0.fld.isr.teack = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "TEACK");
    state->u.f0.fld.isr.reack = cm_object_get_child_by_name(state->u.f0.reg.isr,
            "REACK");

    // ICR bitfields.
    state->u.f0.fld.icr.pecf = cm_object_get_child_by_name(state->u.f0.reg.icr,
            "PECF");
    state->u.f0.fld.icr.fecf = cm_object_get_child_by_name(state->u.f0.reg.icr,
            "FECF");
    state->u.f0.fld.icr.ncf = cm_object_get_child_by_name(state->u.f0.reg.icr,
            "NCF");
    state->u.f0.fld.icr.orecf = cm_object_get_child_by_name(state->u.f0.reg.icr,
            "ORECF");
    state->u.f0.fld.icr.idlecf = cm_object_get_child_by_name(
            state->u.f0.reg.icr, "IDLECF");
    state->u.f0.fld.icr.tccf = cm_object_get_child_by_name(state->u.f0.reg.icr,
            "TCCF");
    state->u.f0.fld.icr.lbdcf = cm_object_get_child_by_name(state->u.f0.reg.icr,
            "LBDCF");
    state->u.f0.fld.icr.ctscf = cm_object_get_child_by_name(state->u.f0.reg.icr,
            "CTSCF");
    state->u.f0.fld.icr.rtocf = cm_object_get_child_by_name(state->u.f0.reg.icr,
            "RTOCF");
    state->u.f0.fld.icr.eobcf = cm_object_get_child_by_name(state->u.f0.reg.icr,
            "EOBCF");
    state->u.f0.fld.icr.cmcf = cm_object_get_child_by_name(state->u.f0.reg.icr,
            "CMCF");
    state->u.f0.fld.icr.wucf = cm_object_get_child_by_name(state->u.f0.reg.icr,
            "WUCF");

    // RDR bitfields.
    state->u.f0.fld.rdr.rdr = cm_object_get_child_by_name(state->u.f0.reg.rdr,
            "RDR");

    // TDR bitfields.
    state->u.f0.fld.tdr.tdr = cm_object_get_child_by_name(state->u.f0.reg.tdr,
            "TDR");
}

// ----------------------------------------------------------------------------

// STM32F103RB
// DO NOT EDIT! Automatically generated!
static void stm32f103xx_usart_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32USARTState *state = STM32_USART_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f1.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->u.f1.reg.dr = cm_object_get_child_by_name(obj, "DR");
    state->u.f1.reg.brr = cm_object_get_child_by_name(obj, "BRR");
    state->u.f1.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
    state->u.f1.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
    state->u.f1.reg.cr3 = cm_object_get_child_by_name(obj, "CR3");
    state->u.f1.reg.gtpr = cm_object_get_child_by_name(obj, "GTPR");

    // SR bitfields.
    state->u.f1.fld.sr.pe = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "PE");
    state->u.f1.fld.sr.fe = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "FE");
    state->u.f1.fld.sr.ne = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "NE");
    state->u.f1.fld.sr.ore = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "ORE");
    state->u.f1.fld.sr.idle = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "IDLE");
    state->u.f1.fld.sr.rxne = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "RXNE");
    state->u.f1.fld.sr.tc = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "TC");
    state->u.f1.fld.sr.txe = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "TXE");
    state->u.f1.fld.sr.lbd = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "LBD");
    state->u.f1.fld.sr.cts = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "CTS");

    // DR bitfields.
    state->u.f1.fld.dr.dr = cm_object_get_child_by_name(state->u.f1.reg.dr,
            "DR");

    // BRR bitfields.
    state->u.f1.fld.brr.div_fraction = cm_object_get_child_by_name(
            state->u.f1.reg.brr, "DIV_Fraction");
    state->u.f1.fld.brr.div_mantissa = cm_object_get_child_by_name(
            state->u.f1.reg.brr, "DIV_Mantissa");

    // CR1 bitfields.
    state->u.f1.fld.cr1.sbk = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "SBK");
    state->u.f1.fld.cr1.rwu = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "RWU");
    state->u.f1.fld.cr1.re = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "RE");
    state->u.f1.fld.cr1.te = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "TE");
    state->u.f1.fld.cr1.idleie = cm_object_get_child_by_name(
            state->u.f1.reg.cr1, "IDLEIE");
    state->u.f1.fld.cr1.rxneie = cm_object_get_child_by_name(
            state->u.f1.reg.cr1, "RXNEIE");
    state->u.f1.fld.cr1.tcie = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "TCIE");
    state->u.f1.fld.cr1.txeie = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "TXEIE");
    state->u.f1.fld.cr1.peie = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "PEIE");
    state->u.f1.fld.cr1.ps = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "PS");
    state->u.f1.fld.cr1.pce = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "PCE");
    state->u.f1.fld.cr1.wake = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "WAKE");
    state->u.f1.fld.cr1.m = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "M");
    state->u.f1.fld.cr1.ue = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "UE");

    // CR2 bitfields.
    state->u.f1.fld.cr2.add = cm_object_get_child_by_name(state->u.f1.reg.cr2,
            "ADD");
    state->u.f1.fld.cr2.lbdl = cm_object_get_child_by_name(state->u.f1.reg.cr2,
            "LBDL");
    state->u.f1.fld.cr2.lbdie = cm_object_get_child_by_name(state->u.f1.reg.cr2,
            "LBDIE");
    state->u.f1.fld.cr2.lbcl = cm_object_get_child_by_name(state->u.f1.reg.cr2,
            "LBCL");
    state->u.f1.fld.cr2.cpha = cm_object_get_child_by_name(state->u.f1.reg.cr2,
            "CPHA");
    state->u.f1.fld.cr2.cpol = cm_object_get_child_by_name(state->u.f1.reg.cr2,
            "CPOL");
    state->u.f1.fld.cr2.clken = cm_object_get_child_by_name(state->u.f1.reg.cr2,
            "CLKEN");
    state->u.f1.fld.cr2.stop = cm_object_get_child_by_name(state->u.f1.reg.cr2,
            "STOP");
    state->u.f1.fld.cr2.linen = cm_object_get_child_by_name(state->u.f1.reg.cr2,
            "LINEN");

    // CR3 bitfields.
    state->u.f1.fld.cr3.eie = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "EIE");
    state->u.f1.fld.cr3.iren = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "IREN");
    state->u.f1.fld.cr3.irlp = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "IRLP");
    state->u.f1.fld.cr3.hdsel = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "HDSEL");
    state->u.f1.fld.cr3.nack = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "NACK");
    state->u.f1.fld.cr3.scen = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "SCEN");
    state->u.f1.fld.cr3.dmar = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "DMAR");
    state->u.f1.fld.cr3.dmat = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "DMAT");
    state->u.f1.fld.cr3.rtse = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "RTSE");
    state->u.f1.fld.cr3.ctse = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "CTSE");
    state->u.f1.fld.cr3.ctsie = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "CTSIE");

    // GTPR bitfields.
    state->u.f1.fld.gtpr.psc = cm_object_get_child_by_name(state->u.f1.reg.gtpr,
            "PSC");
    state->u.f1.fld.gtpr.gt = cm_object_get_child_by_name(state->u.f1.reg.gtpr,
            "GT");
}

// ----------------------------------------------------------------------------

// STM32F107VC
// DO NOT EDIT! Automatically generated!
static void stm32f107xx_usart_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32USARTState *state = STM32_USART_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f1.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->u.f1.reg.dr = cm_object_get_child_by_name(obj, "DR");
    state->u.f1.reg.brr = cm_object_get_child_by_name(obj, "BRR");
    state->u.f1.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
    state->u.f1.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
    state->u.f1.reg.cr3 = cm_object_get_child_by_name(obj, "CR3");
    state->u.f1.reg.gtpr = cm_object_get_child_by_name(obj, "GTPR");

    // SR bitfields.
    state->u.f1.fld.sr.pe = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "PE");
    state->u.f1.fld.sr.fe = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "FE");
    state->u.f1.fld.sr.ne = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "NE");
    state->u.f1.fld.sr.ore = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "ORE");
    state->u.f1.fld.sr.idle = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "IDLE");
    state->u.f1.fld.sr.rxne = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "RXNE");
    state->u.f1.fld.sr.tc = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "TC");
    state->u.f1.fld.sr.txe = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "TXE");
    state->u.f1.fld.sr.lbd = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "LBD");
    state->u.f1.fld.sr.cts = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "CTS");

    // DR bitfields.
    state->u.f1.fld.dr.dr = cm_object_get_child_by_name(state->u.f1.reg.dr,
            "DR");

    // BRR bitfields.
    state->u.f1.fld.brr.div_fraction = cm_object_get_child_by_name(
            state->u.f1.reg.brr, "DIV_Fraction");
    state->u.f1.fld.brr.div_mantissa = cm_object_get_child_by_name(
            state->u.f1.reg.brr, "DIV_Mantissa");

    // CR1 bitfields.
    state->u.f1.fld.cr1.sbk = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "SBK");
    state->u.f1.fld.cr1.rwu = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "RWU");
    state->u.f1.fld.cr1.re = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "RE");
    state->u.f1.fld.cr1.te = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "TE");
    state->u.f1.fld.cr1.idleie = cm_object_get_child_by_name(
            state->u.f1.reg.cr1, "IDLEIE");
    state->u.f1.fld.cr1.rxneie = cm_object_get_child_by_name(
            state->u.f1.reg.cr1, "RXNEIE");
    state->u.f1.fld.cr1.tcie = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "TCIE");
    state->u.f1.fld.cr1.txeie = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "TXEIE");
    state->u.f1.fld.cr1.peie = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "PEIE");
    state->u.f1.fld.cr1.ps = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "PS");
    state->u.f1.fld.cr1.pce = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "PCE");
    state->u.f1.fld.cr1.wake = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "WAKE");
    state->u.f1.fld.cr1.m = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "M");
    state->u.f1.fld.cr1.ue = cm_object_get_child_by_name(state->u.f1.reg.cr1,
            "UE");

    // CR2 bitfields.
    state->u.f1.fld.cr2.add = cm_object_get_child_by_name(state->u.f1.reg.cr2,
            "ADD");
    state->u.f1.fld.cr2.lbdl = cm_object_get_child_by_name(state->u.f1.reg.cr2,
            "LBDL");
    state->u.f1.fld.cr2.lbdie = cm_object_get_child_by_name(state->u.f1.reg.cr2,
            "LBDIE");
    state->u.f1.fld.cr2.lbcl = cm_object_get_child_by_name(state->u.f1.reg.cr2,
            "LBCL");
    state->u.f1.fld.cr2.cpha = cm_object_get_child_by_name(state->u.f1.reg.cr2,
            "CPHA");
    state->u.f1.fld.cr2.cpol = cm_object_get_child_by_name(state->u.f1.reg.cr2,
            "CPOL");
    state->u.f1.fld.cr2.clken = cm_object_get_child_by_name(state->u.f1.reg.cr2,
            "CLKEN");
    state->u.f1.fld.cr2.stop = cm_object_get_child_by_name(state->u.f1.reg.cr2,
            "STOP");
    state->u.f1.fld.cr2.linen = cm_object_get_child_by_name(state->u.f1.reg.cr2,
            "LINEN");

    // CR3 bitfields.
    state->u.f1.fld.cr3.eie = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "EIE");
    state->u.f1.fld.cr3.iren = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "IREN");
    state->u.f1.fld.cr3.irlp = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "IRLP");
    state->u.f1.fld.cr3.hdsel = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "HDSEL");
    state->u.f1.fld.cr3.nack = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "NACK");
    state->u.f1.fld.cr3.scen = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "SCEN");
    state->u.f1.fld.cr3.dmar = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "DMAR");
    state->u.f1.fld.cr3.dmat = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "DMAT");
    state->u.f1.fld.cr3.rtse = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "RTSE");
    state->u.f1.fld.cr3.ctse = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "CTSE");
    state->u.f1.fld.cr3.ctsie = cm_object_get_child_by_name(state->u.f1.reg.cr3,
            "CTSIE");

    // GTPR bitfields.
    state->u.f1.fld.gtpr.psc = cm_object_get_child_by_name(state->u.f1.reg.gtpr,
            "PSC");
    state->u.f1.fld.gtpr.gt = cm_object_get_child_by_name(state->u.f1.reg.gtpr,
            "GT");
}

// ----------------------------------------------------------------------------

// STM32F407VG, STM32F407ZG, STM32F405RG
// DO NOT EDIT! Automatically generated!
static void stm32f40x_usart_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32USARTState *state = STM32_USART_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f4.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->u.f4.reg.dr = cm_object_get_child_by_name(obj, "DR");
    state->u.f4.reg.brr = cm_object_get_child_by_name(obj, "BRR");
    state->u.f4.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
    state->u.f4.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
    state->u.f4.reg.cr3 = cm_object_get_child_by_name(obj, "CR3");
    state->u.f4.reg.gtpr = cm_object_get_child_by_name(obj, "GTPR");

    // SR bitfields.
    state->u.f4.fld.sr.pe = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "PE");
    state->u.f4.fld.sr.fe = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "FE");
    state->u.f4.fld.sr.nf = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "NF");
    state->u.f4.fld.sr.ore = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "ORE");
    state->u.f4.fld.sr.idle = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "IDLE");
    state->u.f4.fld.sr.rxne = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "RXNE");
    state->u.f4.fld.sr.tc = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "TC");
    state->u.f4.fld.sr.txe = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "TXE");
    state->u.f4.fld.sr.lbd = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "LBD");
    state->u.f4.fld.sr.cts = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "CTS");

    // DR bitfields.
    state->u.f4.fld.dr.dr = cm_object_get_child_by_name(state->u.f4.reg.dr,
            "DR");

    // BRR bitfields.
    state->u.f4.fld.brr.div_fraction = cm_object_get_child_by_name(
            state->u.f4.reg.brr, "DIV_Fraction");
    state->u.f4.fld.brr.div_mantissa = cm_object_get_child_by_name(
            state->u.f4.reg.brr, "DIV_Mantissa");

    // CR1 bitfields.
    state->u.f4.fld.cr1.sbk = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "SBK");
    state->u.f4.fld.cr1.rwu = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "RWU");
    state->u.f4.fld.cr1.re = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "RE");
    state->u.f4.fld.cr1.te = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "TE");
    state->u.f4.fld.cr1.idleie = cm_object_get_child_by_name(
            state->u.f4.reg.cr1, "IDLEIE");
    state->u.f4.fld.cr1.rxneie = cm_object_get_child_by_name(
            state->u.f4.reg.cr1, "RXNEIE");
    state->u.f4.fld.cr1.tcie = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "TCIE");
    state->u.f4.fld.cr1.txeie = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "TXEIE");
    state->u.f4.fld.cr1.peie = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "PEIE");
    state->u.f4.fld.cr1.ps = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "PS");
    state->u.f4.fld.cr1.pce = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "PCE");
    state->u.f4.fld.cr1.wake = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "WAKE");
    state->u.f4.fld.cr1.m = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "M");
    state->u.f4.fld.cr1.ue = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "UE");
    state->u.f4.fld.cr1.over8 = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "OVER8");

    // CR2 bitfields.
    state->u.f4.fld.cr2.add = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "ADD");
    state->u.f4.fld.cr2.lbdl = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "LBDL");
    state->u.f4.fld.cr2.lbdie = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "LBDIE");
    state->u.f4.fld.cr2.lbcl = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "LBCL");
    state->u.f4.fld.cr2.cpha = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "CPHA");
    state->u.f4.fld.cr2.cpol = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "CPOL");
    state->u.f4.fld.cr2.clken = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "CLKEN");
    state->u.f4.fld.cr2.stop = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "STOP");
    state->u.f4.fld.cr2.linen = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "LINEN");

    // CR3 bitfields.
    state->u.f4.fld.cr3.eie = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "EIE");
    state->u.f4.fld.cr3.iren = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "IREN");
    state->u.f4.fld.cr3.irlp = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "IRLP");
    state->u.f4.fld.cr3.hdsel = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "HDSEL");
    state->u.f4.fld.cr3.nack = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "NACK");
    state->u.f4.fld.cr3.scen = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "SCEN");
    state->u.f4.fld.cr3.dmar = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "DMAR");
    state->u.f4.fld.cr3.dmat = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "DMAT");
    state->u.f4.fld.cr3.rtse = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "RTSE");
    state->u.f4.fld.cr3.ctse = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "CTSE");
    state->u.f4.fld.cr3.ctsie = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "CTSIE");
    state->u.f4.fld.cr3.onebit = cm_object_get_child_by_name(
            state->u.f4.reg.cr3, "ONEBIT");

    // GTPR bitfields.
    state->u.f4.fld.gtpr.psc = cm_object_get_child_by_name(state->u.f4.reg.gtpr,
            "PSC");
    state->u.f4.fld.gtpr.gt = cm_object_get_child_by_name(state->u.f4.reg.gtpr,
            "GT");
}

// ----------------------------------------------------------------------------

// STM32F411RE
// DO NOT EDIT! Automatically generated!
static void stm32f411xx_usart_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32USARTState *state = STM32_USART_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f4.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->u.f4.reg.dr = cm_object_get_child_by_name(obj, "DR");
    state->u.f4.reg.brr = cm_object_get_child_by_name(obj, "BRR");
    state->u.f4.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
    state->u.f4.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
    state->u.f4.reg.cr3 = cm_object_get_child_by_name(obj, "CR3");
    state->u.f4.reg.gtpr = cm_object_get_child_by_name(obj, "GTPR");

    // SR bitfields.
    state->u.f4.fld.sr.pe = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "PE");
    state->u.f4.fld.sr.fe = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "FE");
    state->u.f4.fld.sr.nf = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "NF");
    state->u.f4.fld.sr.ore = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "ORE");
    state->u.f4.fld.sr.idle = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "IDLE");
    state->u.f4.fld.sr.rxne = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "RXNE");
    state->u.f4.fld.sr.tc = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "TC");
    state->u.f4.fld.sr.txe = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "TXE");
    state->u.f4.fld.sr.lbd = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "LBD");
    state->u.f4.fld.sr.cts = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "CTS");

    // DR bitfields.
    state->u.f4.fld.dr.dr = cm_object_get_child_by_name(state->u.f4.reg.dr,
            "DR");

    // BRR bitfields.
    state->u.f4.fld.brr.div_fraction = cm_object_get_child_by_name(
            state->u.f4.reg.brr, "DIV_Fraction");
    state->u.f4.fld.brr.div_mantissa = cm_object_get_child_by_name(
            state->u.f4.reg.brr, "DIV_Mantissa");

    // CR1 bitfields.
    state->u.f4.fld.cr1.sbk = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "SBK");
    state->u.f4.fld.cr1.rwu = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "RWU");
    state->u.f4.fld.cr1.re = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "RE");
    state->u.f4.fld.cr1.te = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "TE");
    state->u.f4.fld.cr1.idleie = cm_object_get_child_by_name(
            state->u.f4.reg.cr1, "IDLEIE");
    state->u.f4.fld.cr1.rxneie = cm_object_get_child_by_name(
            state->u.f4.reg.cr1, "RXNEIE");
    state->u.f4.fld.cr1.tcie = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "TCIE");
    state->u.f4.fld.cr1.txeie = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "TXEIE");
    state->u.f4.fld.cr1.peie = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "PEIE");
    state->u.f4.fld.cr1.ps = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "PS");
    state->u.f4.fld.cr1.pce = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "PCE");
    state->u.f4.fld.cr1.wake = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "WAKE");
    state->u.f4.fld.cr1.m = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "M");
    state->u.f4.fld.cr1.ue = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "UE");
    state->u.f4.fld.cr1.over8 = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "OVER8");

    // CR2 bitfields.
    state->u.f4.fld.cr2.add = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "ADD");
    state->u.f4.fld.cr2.lbdl = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "LBDL");
    state->u.f4.fld.cr2.lbdie = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "LBDIE");
    state->u.f4.fld.cr2.lbcl = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "LBCL");
    state->u.f4.fld.cr2.cpha = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "CPHA");
    state->u.f4.fld.cr2.cpol = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "CPOL");
    state->u.f4.fld.cr2.clken = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "CLKEN");
    state->u.f4.fld.cr2.stop = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "STOP");
    state->u.f4.fld.cr2.linen = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "LINEN");

    // CR3 bitfields.
    state->u.f4.fld.cr3.eie = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "EIE");
    state->u.f4.fld.cr3.iren = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "IREN");
    state->u.f4.fld.cr3.irlp = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "IRLP");
    state->u.f4.fld.cr3.hdsel = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "HDSEL");
    state->u.f4.fld.cr3.nack = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "NACK");
    state->u.f4.fld.cr3.scen = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "SCEN");
    state->u.f4.fld.cr3.dmar = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "DMAR");
    state->u.f4.fld.cr3.dmat = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "DMAT");
    state->u.f4.fld.cr3.rtse = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "RTSE");
    state->u.f4.fld.cr3.ctse = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "CTSE");
    state->u.f4.fld.cr3.ctsie = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "CTSIE");
    state->u.f4.fld.cr3.onebit = cm_object_get_child_by_name(
            state->u.f4.reg.cr3, "ONEBIT");

    // GTPR bitfields.
    state->u.f4.fld.gtpr.psc = cm_object_get_child_by_name(state->u.f4.reg.gtpr,
            "PSC");
    state->u.f4.fld.gtpr.gt = cm_object_get_child_by_name(state->u.f4.reg.gtpr,
            "GT");
}

// ----------------------------------------------------------------------------

// STM32F429ZI
// DO NOT EDIT! Automatically generated!
static void stm32f429x_usart_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32USARTState *state = STM32_USART_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f4.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->u.f4.reg.dr = cm_object_get_child_by_name(obj, "DR");
    state->u.f4.reg.brr = cm_object_get_child_by_name(obj, "BRR");
    state->u.f4.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
    state->u.f4.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
    state->u.f4.reg.cr3 = cm_object_get_child_by_name(obj, "CR3");
    state->u.f4.reg.gtpr = cm_object_get_child_by_name(obj, "GTPR");

    // SR bitfields.
    state->u.f4.fld.sr.pe = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "PE");
    state->u.f4.fld.sr.fe = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "FE");
    state->u.f4.fld.sr.nf = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "NF");
    state->u.f4.fld.sr.ore = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "ORE");
    state->u.f4.fld.sr.idle = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "IDLE");
    state->u.f4.fld.sr.rxne = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "RXNE");
    state->u.f4.fld.sr.tc = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "TC");
    state->u.f4.fld.sr.txe = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "TXE");
    state->u.f4.fld.sr.lbd = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "LBD");
    state->u.f4.fld.sr.cts = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "CTS");

    // DR bitfields.
    state->u.f4.fld.dr.dr = cm_object_get_child_by_name(state->u.f4.reg.dr,
            "DR");

    // BRR bitfields.
    state->u.f4.fld.brr.div_fraction = cm_object_get_child_by_name(
            state->u.f4.reg.brr, "DIV_Fraction");
    state->u.f4.fld.brr.div_mantissa = cm_object_get_child_by_name(
            state->u.f4.reg.brr, "DIV_Mantissa");

    // CR1 bitfields.
    state->u.f4.fld.cr1.sbk = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "SBK");
    state->u.f4.fld.cr1.rwu = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "RWU");
    state->u.f4.fld.cr1.re = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "RE");
    state->u.f4.fld.cr1.te = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "TE");
    state->u.f4.fld.cr1.idleie = cm_object_get_child_by_name(
            state->u.f4.reg.cr1, "IDLEIE");
    state->u.f4.fld.cr1.rxneie = cm_object_get_child_by_name(
            state->u.f4.reg.cr1, "RXNEIE");
    state->u.f4.fld.cr1.tcie = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "TCIE");
    state->u.f4.fld.cr1.txeie = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "TXEIE");
    state->u.f4.fld.cr1.peie = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "PEIE");
    state->u.f4.fld.cr1.ps = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "PS");
    state->u.f4.fld.cr1.pce = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "PCE");
    state->u.f4.fld.cr1.wake = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "WAKE");
    state->u.f4.fld.cr1.m = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "M");
    state->u.f4.fld.cr1.ue = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "UE");
    state->u.f4.fld.cr1.over8 = cm_object_get_child_by_name(state->u.f4.reg.cr1,
            "OVER8");

    // CR2 bitfields.
    state->u.f4.fld.cr2.add = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "ADD");
    state->u.f4.fld.cr2.lbdl = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "LBDL");
    state->u.f4.fld.cr2.lbdie = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "LBDIE");
    state->u.f4.fld.cr2.lbcl = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "LBCL");
    state->u.f4.fld.cr2.cpha = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "CPHA");
    state->u.f4.fld.cr2.cpol = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "CPOL");
    state->u.f4.fld.cr2.clken = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "CLKEN");
    state->u.f4.fld.cr2.stop = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "STOP");
    state->u.f4.fld.cr2.linen = cm_object_get_child_by_name(state->u.f4.reg.cr2,
            "LINEN");

    // CR3 bitfields.
    state->u.f4.fld.cr3.eie = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "EIE");
    state->u.f4.fld.cr3.iren = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "IREN");
    state->u.f4.fld.cr3.irlp = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "IRLP");
    state->u.f4.fld.cr3.hdsel = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "HDSEL");
    state->u.f4.fld.cr3.nack = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "NACK");
    state->u.f4.fld.cr3.scen = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "SCEN");
    state->u.f4.fld.cr3.dmar = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "DMAR");
    state->u.f4.fld.cr3.dmat = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "DMAT");
    state->u.f4.fld.cr3.rtse = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "RTSE");
    state->u.f4.fld.cr3.ctse = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "CTSE");
    state->u.f4.fld.cr3.ctsie = cm_object_get_child_by_name(state->u.f4.reg.cr3,
            "CTSIE");
    state->u.f4.fld.cr3.onebit = cm_object_get_child_by_name(
            state->u.f4.reg.cr3, "ONEBIT");

    // GTPR bitfields.
    state->u.f4.fld.gtpr.psc = cm_object_get_child_by_name(state->u.f4.reg.gtpr,
            "PSC");
    state->u.f4.fld.gtpr.gt = cm_object_get_child_by_name(state->u.f4.reg.gtpr,
            "GT");
}

// ----- Public ---------------------------------------------------------------

// Create GPIO%c and return it.
Object* stm32_usart_create(Object *parent, stm32_usart_index_t index)
{
    if ((int) index >= STM32_PORT_USART_UNDEFINED) {
        hw_error("Cannot assign USART %d: QEMU supports only %d ports\n",
                1 + index - STM32_PORT_USART1, STM32_PORT_USART_UNDEFINED);
    }

    char child_name[10];
    snprintf(child_name, sizeof(child_name) - 1, "USART%d",
            1 + index - STM32_PORT_USART1);
    // Passing a local string is ok.
    Object *usart = cm_object_new(parent, child_name,
    TYPE_STM32_USART);

    object_property_set_int(usart, index, "port-index", NULL);

    cm_object_realize(usart);

    return usart;
}

// ----- Private --------------------------------------------------------------

static bool stm32_usart_is_enabled(Object *obj)
{
    STM32USARTState *state = STM32_USART_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

// ----------------------------------------------------------------------------

static int smt32f4_usart_get_irq_vector(STM32USARTState *state)
{
    // TODO: use capabilities to select interrupt numbers
    // for different variants.

    switch (state->port_index) {
    case STM32_PORT_USART1:
        return STM32F4_01_57_XX_USART1_IRQn;
    case STM32_PORT_USART2:
        return STM32F4_01_57_XX_USART2_IRQn;
    case STM32_PORT_USART3:
        return STM32F4_01_57_XX_USART3_IRQn;
    case STM32_PORT_USART4:
        return STM32F4_01_57_XX_UART4_IRQn;
    case STM32_PORT_USART5:
        return STM32F4_01_57_XX_UART5_IRQn;
    case STM32_PORT_USART6:
        return STM32F4_01_57_XX_USART6_IRQn;
    default:
        return 1023; // Whatever...
    }
}

#if 0
static int stm32f4_usart_can_receive(void *obj)
{
    STM32USARTState *state = STM32_USART_STATE((Object * )obj);

    int32_t sr = peripheral_register_get_raw_value(state->reg.sr);
    if (!(sr & USART_SR_RXNE)) {
        return 1;
    }

    return 0;
}

static void stm32f4_usart_receive(void *obj, const uint8_t *buf, int size)
{
    STM32USARTState *state = STM32_USART_STATE((Object * )obj);

    int32_t cr1 = peripheral_register_get_raw_value(state->reg.cr1);

    if (!stm32_usart_is_enabled(obj) || !(cr1 & USART_CR1_UE)
            || !(cr1 & USART_CR1_RE)) {
        // USART not enabled - drop the chars
        return;
    }

    peripheral_register_set_raw_value(state->reg.dr, *buf);
    peripheral_register_or_raw_value(state->reg.sr, USART_SR_RXNE);

    if (cr1 & USART_CR1_RXNEIE) {
        cortexm_nvic_set_pending_interrupt(state->nvic,
                smt32f4_usart_get_irq_vector(state));
    }
}
#endif

static void stm32f4_usart_dr_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32USARTState *state = STM32_USART_STATE(periph);

    peripheral_register_and_raw_value(state->reg.sr, ~USART_SR_RXNE);
    if (state->chr) {
#if 0
        qemu_chr_accept_input(state->chr);
#endif
    }
}

static void stm32f4_usart_dr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32USARTState *state = STM32_USART_STATE(periph);
    unsigned char ch;

    int32_t cr1 = peripheral_register_get_raw_value(state->reg.cr1);

    // 'value' may be half-word, use full_word.
    if ((cr1 & USART_CR1_UE) && (cr1 & USART_CR1_TE)) {
        if (state->chr) {
            ch = full_value; /* Use only the lower 8 bits */
#if 0
            qemu_chr_fe_write_all(state->chr, &ch, 1);
#endif
        }
        // transmission is immediately complete
        peripheral_register_or_raw_value(state->reg.sr,
        USART_SR_TC | USART_SR_TXE);
        if ((cr1 & USART_CR1_TXEIE) || (cr1 & USART_CR1_TCIE)) {
            cortexm_nvic_set_pending_interrupt(state->nvic,
                    smt32f4_usart_get_irq_vector(state));
        }
    }
}

static void stm32f4_usart_cr1_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32USARTState *state = STM32_USART_STATE(periph);

    int32_t sr = peripheral_register_get_raw_value(state->reg.sr);

    // 'value' may be half-word, use full_word.
    if (((full_value & USART_CR1_RXNEIE) && (sr & USART_SR_RXNE))
            || ((full_value & USART_CR1_TXEIE) && (sr & USART_SR_TXE))
            || ((full_value & USART_CR1_TCIE) && (sr & USART_SR_TC))) {
        cortexm_nvic_set_pending_interrupt(state->nvic,
                smt32f4_usart_get_irq_vector(state));
    }
}

// ----------------------------------------------------------------------------

static void stm32_usart_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32USARTState *state = STM32_USART_STATE(obj);

    // FIXME use a qdev char-device prop instead of qemu_char_get_next_serial()
    // state->chr = qemu_char_get_next_serial();

    cm_object_property_add_int(obj, "port-index",
            (const int *) &state->port_index);
    state->port_index = STM32_PORT_USART_UNDEFINED;

}

static void stm32_usart_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_USART)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32USARTState *state = STM32_USART_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    Object *obj = OBJECT(dev);

    state->nvic = CORTEXM_NVIC_STATE(cm_state->nvic);

    char periph_name[10];
    snprintf(periph_name, sizeof(periph_name) - 1, "USART%d",
            1 + state->port_index - STM32_PORT_USART1);

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // Must be defined before creating registers.
    cm_object_property_set_int(obj, 4, "register-size-bytes");

    // TODO: get it from MCU
    cm_object_property_set_bool(obj, true, "is-little-endian");

    const STM32Capabilities *capabilities =
    STM32_USART_STATE(state)->capabilities;
    assert(capabilities != NULL);

    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {

    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x1) {

            stm32f0x1_usart_create_objects(obj, cm_state->svd_json,
                    periph_name);

            // TODO: add callbacks
        } else {
            assert(false);
        }

        switch (state->port_index) {

        case STM32_PORT_USART1:
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                    DEVICE_PATH_STM32_RCC "/APB2ENR/USART%dEN",
                    1 + state->port_index - STM32_PORT_USART1);
            break;

        case STM32_PORT_USART2:
        case STM32_PORT_USART3:
        case STM32_PORT_USART4:
        case STM32_PORT_USART5:
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                    DEVICE_PATH_STM32_RCC "/APB1ENR/USART%dEN",
                    1 + state->port_index - STM32_PORT_USART1);
            break;

        default:
            assert(false);
            break;
        }

        break;

    case STM32_FAMILY_F1:

        if (capabilities->f1.is_103xx) {

            stm32f103xx_usart_create_objects(obj, cm_state->svd_json,
                    periph_name);

        } else if (capabilities->f1.is_107xx) {

            stm32f107xx_usart_create_objects(obj, cm_state->svd_json,
                    periph_name);

        } else {
            assert(false);
        }

        // TODO: add callbacks

        state->reg.sr = state->u.f1.reg.sr;
        state->reg.dr = state->u.f1.reg.dr;
        state->reg.brr = state->u.f1.reg.brr;
        state->reg.cr1 = state->u.f1.reg.cr1;
        state->reg.cr2 = state->u.f1.reg.cr2;
        state->reg.cr3 = state->u.f1.reg.cr3;
        state->reg.gtpr = state->u.f1.reg.gtpr;

        switch (state->port_index) {

        case STM32_PORT_USART1:
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                    DEVICE_PATH_STM32_RCC "/APB2ENR/USART%dEN",
                    1 + state->port_index - STM32_PORT_USART1);
            break;

        case STM32_PORT_USART2:
        case STM32_PORT_USART3:
            // UART_4, UART_5:
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                    DEVICE_PATH_STM32_RCC "/APB1ENR/USART%dEN",
                    1 + state->port_index - STM32_PORT_USART1);
            break;

        default:
            assert(false);
            break;
        }

        break;

    case STM32_FAMILY_F4:

        if (capabilities->f4.is_40x) {

            stm32f40x_usart_create_objects(obj, cm_state->svd_json,
                    periph_name);

        } else if (capabilities->f4.is_411xx) {

            stm32f411xx_usart_create_objects(obj, cm_state->svd_json,
                    periph_name);

        } else if (capabilities->f4.is_429x) {

            stm32f429x_usart_create_objects(obj, cm_state->svd_json,
                    periph_name);

        } else {
            assert(false);
        }

        state->reg.sr = state->u.f4.reg.sr;
        state->reg.dr = state->u.f4.reg.dr;
        state->reg.brr = state->u.f4.reg.brr;
        state->reg.cr1 = state->u.f4.reg.cr1;
        state->reg.cr2 = state->u.f4.reg.cr2;
        state->reg.cr3 = state->u.f4.reg.cr3;
        state->reg.gtpr = state->u.f4.reg.gtpr;

        // Register callbacks.
        peripheral_register_set_post_read(state->reg.dr,
                &stm32f4_usart_dr_post_read_callback);
        peripheral_register_set_post_write(state->reg.dr,
                &stm32f4_usart_dr_post_write_callback);
        peripheral_register_set_post_write(state->reg.cr1,
                &stm32f4_usart_cr1_post_write_callback);

        // char-device callbacks.
        if (state->chr) {
#if 0
            qemu_chr_add_handlers(state->chr, stm32f4_usart_can_receive,
                    stm32f4_usart_receive, NULL, obj);
#endif
        }

        switch (state->port_index) {

        case STM32_PORT_USART1:
        case STM32_PORT_USART6:
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                    DEVICE_PATH_STM32_RCC "/APB2ENR/USART%dEN",
                    1 + state->port_index - STM32_PORT_USART1);
            break;

        case STM32_PORT_USART2:
        case STM32_PORT_USART3:

            // UART_4, UART_5:
            // F429 UART_7, UART_8
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                    DEVICE_PATH_STM32_RCC "/APB1ENR/USART%dEN",
                    1 + state->port_index - STM32_PORT_USART1);
            break;

        default:
            assert(false);
            break;
        }

        break;

    default:
        assert(false);
        break;
    }

    state->enabling_bit = OBJECT(cm_device_by_name(enabling_bit_name));

    peripheral_prepare_registers(obj);

    // ------------------------------------------------------------------------

    CharDriverState *chr = serial_hds[state->port_index];
    if (!chr) {
        char chardev_name[10];

        snprintf(chardev_name, ARRAY_SIZE(chardev_name)-1, "serial%d",
                0 + state->port_index - STM32_PORT_USART1);
        chr = qemu_chr_new(chardev_name, "null");
        if (!(chr)) {
            hw_error("Can't assign serial port to %s.\n", periph_name);
        }
    }
    state->chr = chr;
}

static void stm32_usart_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    STM32USARTState *state = STM32_USART_STATE(dev);

    // Call parent reset().
    cm_device_parent_reset(dev, TYPE_STM32_USART);

    if (state->chr) {
#if 0
        qemu_chr_accept_input(state->chr);
#endif
    }

    const STM32Capabilities *capabilities =
    STM32_USART_STATE(state)->capabilities;
    assert(capabilities != NULL);

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        // TODO:
        // FIXME: We should certainly clear the interrupt state.
        // Don't know how to do that: implement cortexm_nvic_clear_pending ???
        break;

    default:
        break;
    }

}

#if 0
static Property stm32_usart_properties[] = {
    DEFINE_PROP_CHR("chardev", STM32USARTState, chr),
    DEFINE_PROP_END_OF_LIST()};
#endif

static void stm32_usart_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_usart_reset_callback;
    dc->realize = stm32_usart_realize_callback;

    // dc->props = stm32_usart_properties;

    // Reason: instance_init() method uses qemu_char_get_next_serial()
    // dc->cannot_instantiate_with_device_add_yet = true;

    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_usart_is_enabled;
}

static const TypeInfo stm32_usart_type_info = {
    .name = TYPE_STM32_USART,
    .parent = TYPE_STM32_USART_PARENT,
    .instance_init = stm32_usart_instance_init_callback,
    .instance_size = sizeof(STM32USARTState),
    .class_init = stm32_usart_class_init_callback,
    .class_size = sizeof(STM32USARTClass)
/**/
};

static void stm32_usart_register_types(void)
{
    type_register_static(&stm32_usart_type_info);
}

type_init(stm32_usart_register_types);

