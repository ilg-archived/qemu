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

#define USART_SR_TXE        (1 << 7)
#define USART_SR_TC         (1 << 6)
#define USART_SR_RXNE       (1 << 5)

#define USART_CR1_UE        (1 << 13)
#define USART_CR1_TXEIE     (1 << 7)
#define USART_CR1_TCIE      (1 << 6)
#define USART_CR1_RXNEIE    (1 << 5)
#define USART_CR1_TE        (1 << 3)
#define USART_CR1_RE        (1 << 2)

/* ------------------------------------------------------------------------- */

// TODO: rework reference to RCC to use links.
static bool stm32_usart_is_enabled(Object *obj)
{
    STM32USARTState *state = STM32_USART_STATE(obj);

    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    switch (capabilities->family) {

    case STM32_FAMILY_F4:
        if (state->port_index == STM32_USART_1) {
            if ((peripheral_register_read_value(state->rcc->f4.reg.apb2enr)
                    & 0x10) != 0) {
                return true;
            }
        } else if (state->port_index == STM32_USART_6) {
            if ((peripheral_register_read_value(state->rcc->f4.reg.apb2enr)
                    & 0x20) != 0) {
                return true;
            }
        } else {
            if ((peripheral_register_read_value(state->rcc->f4.reg.apb1enr)
                    & (0x20000 << (state->port_index - STM32_USART_2))) != 0) {
                return true;
            }
            break;
        }
        break;

    default:
        break;
    }

    return false;
}

/* ------------------------------------------------------------------------- */

static void stm32f0x1_usart_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    // DO NOT EDIT! Automatically generated!
    STM32USARTState *state = STM32_USART_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->f0.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
    state->f0.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
    state->f0.reg.cr3 = cm_object_get_child_by_name(obj, "CR3");
    state->f0.reg.brr = cm_object_get_child_by_name(obj, "BRR");
    state->f0.reg.gtpr = cm_object_get_child_by_name(obj, "GTPR");
    state->f0.reg.rtor = cm_object_get_child_by_name(obj, "RTOR");
    state->f0.reg.rqr = cm_object_get_child_by_name(obj, "RQR");
    state->f0.reg.isr = cm_object_get_child_by_name(obj, "ISR");
    state->f0.reg.icr = cm_object_get_child_by_name(obj, "ICR");
    state->f0.reg.rdr = cm_object_get_child_by_name(obj, "RDR");
    state->f0.reg.tdr = cm_object_get_child_by_name(obj, "TDR");

    // CR1 bitfields.
    state->f0.fld.cr1.ue = cm_object_get_child_by_name(state->f0.reg.cr1, "UE");
    state->f0.fld.cr1.uesm = cm_object_get_child_by_name(state->f0.reg.cr1,
            "UESM");
    state->f0.fld.cr1.re = cm_object_get_child_by_name(state->f0.reg.cr1, "RE");
    state->f0.fld.cr1.te = cm_object_get_child_by_name(state->f0.reg.cr1, "TE");
    state->f0.fld.cr1.idleie = cm_object_get_child_by_name(state->f0.reg.cr1,
            "IDLEIE");
    state->f0.fld.cr1.rxneie = cm_object_get_child_by_name(state->f0.reg.cr1,
            "RXNEIE");
    state->f0.fld.cr1.tcie = cm_object_get_child_by_name(state->f0.reg.cr1,
            "TCIE");
    state->f0.fld.cr1.txeie = cm_object_get_child_by_name(state->f0.reg.cr1,
            "TXEIE");
    state->f0.fld.cr1.peie = cm_object_get_child_by_name(state->f0.reg.cr1,
            "PEIE");
    state->f0.fld.cr1.ps = cm_object_get_child_by_name(state->f0.reg.cr1, "PS");
    state->f0.fld.cr1.pce = cm_object_get_child_by_name(state->f0.reg.cr1,
            "PCE");
    state->f0.fld.cr1.wake = cm_object_get_child_by_name(state->f0.reg.cr1,
            "WAKE");
    state->f0.fld.cr1.m = cm_object_get_child_by_name(state->f0.reg.cr1, "M");
    state->f0.fld.cr1.mme = cm_object_get_child_by_name(state->f0.reg.cr1,
            "MME");
    state->f0.fld.cr1.cmie = cm_object_get_child_by_name(state->f0.reg.cr1,
            "CMIE");
    state->f0.fld.cr1.over8 = cm_object_get_child_by_name(state->f0.reg.cr1,
            "OVER8");
    state->f0.fld.cr1.dedt = cm_object_get_child_by_name(state->f0.reg.cr1,
            "DEDT");
    state->f0.fld.cr1.deat = cm_object_get_child_by_name(state->f0.reg.cr1,
            "DEAT");
    state->f0.fld.cr1.rtoie = cm_object_get_child_by_name(state->f0.reg.cr1,
            "RTOIE");
    state->f0.fld.cr1.eobie = cm_object_get_child_by_name(state->f0.reg.cr1,
            "EOBIE");
    state->f0.fld.cr1.m1 = cm_object_get_child_by_name(state->f0.reg.cr1, "M1");

    // CR2 bitfields.
    state->f0.fld.cr2.addm7 = cm_object_get_child_by_name(state->f0.reg.cr2,
            "ADDM7");
    state->f0.fld.cr2.lbdl = cm_object_get_child_by_name(state->f0.reg.cr2,
            "LBDL");
    state->f0.fld.cr2.lbdie = cm_object_get_child_by_name(state->f0.reg.cr2,
            "LBDIE");
    state->f0.fld.cr2.lbcl = cm_object_get_child_by_name(state->f0.reg.cr2,
            "LBCL");
    state->f0.fld.cr2.cpha = cm_object_get_child_by_name(state->f0.reg.cr2,
            "CPHA");
    state->f0.fld.cr2.cpol = cm_object_get_child_by_name(state->f0.reg.cr2,
            "CPOL");
    state->f0.fld.cr2.clken = cm_object_get_child_by_name(state->f0.reg.cr2,
            "CLKEN");
    state->f0.fld.cr2.stop = cm_object_get_child_by_name(state->f0.reg.cr2,
            "STOP");
    state->f0.fld.cr2.linen = cm_object_get_child_by_name(state->f0.reg.cr2,
            "LINEN");
    state->f0.fld.cr2.swap = cm_object_get_child_by_name(state->f0.reg.cr2,
            "SWAP");
    state->f0.fld.cr2.rxinv = cm_object_get_child_by_name(state->f0.reg.cr2,
            "RXINV");
    state->f0.fld.cr2.txinv = cm_object_get_child_by_name(state->f0.reg.cr2,
            "TXINV");
    state->f0.fld.cr2.datainv = cm_object_get_child_by_name(state->f0.reg.cr2,
            "DATAINV");
    state->f0.fld.cr2.msbfirst = cm_object_get_child_by_name(state->f0.reg.cr2,
            "MSBFIRST");
    state->f0.fld.cr2.abren = cm_object_get_child_by_name(state->f0.reg.cr2,
            "ABREN");
    state->f0.fld.cr2.abrmod = cm_object_get_child_by_name(state->f0.reg.cr2,
            "ABRMOD");
    state->f0.fld.cr2.rtoen = cm_object_get_child_by_name(state->f0.reg.cr2,
            "RTOEN");
    state->f0.fld.cr2.add0 = cm_object_get_child_by_name(state->f0.reg.cr2,
            "ADD0");
    state->f0.fld.cr2.add4 = cm_object_get_child_by_name(state->f0.reg.cr2,
            "ADD4");

    // CR3 bitfields.
    state->f0.fld.cr3.eie = cm_object_get_child_by_name(state->f0.reg.cr3,
            "EIE");
    state->f0.fld.cr3.iren = cm_object_get_child_by_name(state->f0.reg.cr3,
            "IREN");
    state->f0.fld.cr3.irlp = cm_object_get_child_by_name(state->f0.reg.cr3,
            "IRLP");
    state->f0.fld.cr3.hdsel = cm_object_get_child_by_name(state->f0.reg.cr3,
            "HDSEL");
    state->f0.fld.cr3.nack = cm_object_get_child_by_name(state->f0.reg.cr3,
            "NACK");
    state->f0.fld.cr3.scen = cm_object_get_child_by_name(state->f0.reg.cr3,
            "SCEN");
    state->f0.fld.cr3.dmar = cm_object_get_child_by_name(state->f0.reg.cr3,
            "DMAR");
    state->f0.fld.cr3.dmat = cm_object_get_child_by_name(state->f0.reg.cr3,
            "DMAT");
    state->f0.fld.cr3.rtse = cm_object_get_child_by_name(state->f0.reg.cr3,
            "RTSE");
    state->f0.fld.cr3.ctse = cm_object_get_child_by_name(state->f0.reg.cr3,
            "CTSE");
    state->f0.fld.cr3.ctsie = cm_object_get_child_by_name(state->f0.reg.cr3,
            "CTSIE");
    state->f0.fld.cr3.onebit = cm_object_get_child_by_name(state->f0.reg.cr3,
            "ONEBIT");
    state->f0.fld.cr3.ovrdis = cm_object_get_child_by_name(state->f0.reg.cr3,
            "OVRDIS");
    state->f0.fld.cr3.ddre = cm_object_get_child_by_name(state->f0.reg.cr3,
            "DDRE");
    state->f0.fld.cr3.dem = cm_object_get_child_by_name(state->f0.reg.cr3,
            "DEM");
    state->f0.fld.cr3.dep = cm_object_get_child_by_name(state->f0.reg.cr3,
            "DEP");
    state->f0.fld.cr3.scarcnt = cm_object_get_child_by_name(state->f0.reg.cr3,
            "SCARCNT");
    state->f0.fld.cr3.wus = cm_object_get_child_by_name(state->f0.reg.cr3,
            "WUS");
    state->f0.fld.cr3.wufie = cm_object_get_child_by_name(state->f0.reg.cr3,
            "WUFIE");

    // BRR bitfields.
    state->f0.fld.brr.div_fraction = cm_object_get_child_by_name(
            state->f0.reg.brr, "DIV_Fraction");
    state->f0.fld.brr.div_mantissa = cm_object_get_child_by_name(
            state->f0.reg.brr, "DIV_Mantissa");

    // GTPR bitfields.
    state->f0.fld.gtpr.psc = cm_object_get_child_by_name(state->f0.reg.gtpr,
            "PSC");
    state->f0.fld.gtpr.gt = cm_object_get_child_by_name(state->f0.reg.gtpr,
            "GT");

    // RTOR bitfields.
    state->f0.fld.rtor.rto = cm_object_get_child_by_name(state->f0.reg.rtor,
            "RTO");
    state->f0.fld.rtor.blen = cm_object_get_child_by_name(state->f0.reg.rtor,
            "BLEN");

    // RQR bitfields.
    state->f0.fld.rqr.abrrq = cm_object_get_child_by_name(state->f0.reg.rqr,
            "ABRRQ");
    state->f0.fld.rqr.sbkrq = cm_object_get_child_by_name(state->f0.reg.rqr,
            "SBKRQ");
    state->f0.fld.rqr.mmrq = cm_object_get_child_by_name(state->f0.reg.rqr,
            "MMRQ");
    state->f0.fld.rqr.rxfrq = cm_object_get_child_by_name(state->f0.reg.rqr,
            "RXFRQ");
    state->f0.fld.rqr.txfrq = cm_object_get_child_by_name(state->f0.reg.rqr,
            "TXFRQ");

    // ISR bitfields.
    state->f0.fld.isr.pe = cm_object_get_child_by_name(state->f0.reg.isr, "PE");
    state->f0.fld.isr.fe = cm_object_get_child_by_name(state->f0.reg.isr, "FE");
    state->f0.fld.isr.nf = cm_object_get_child_by_name(state->f0.reg.isr, "NF");
    state->f0.fld.isr.ore = cm_object_get_child_by_name(state->f0.reg.isr,
            "ORE");
    state->f0.fld.isr.idle = cm_object_get_child_by_name(state->f0.reg.isr,
            "IDLE");
    state->f0.fld.isr.rxne = cm_object_get_child_by_name(state->f0.reg.isr,
            "RXNE");
    state->f0.fld.isr.tc = cm_object_get_child_by_name(state->f0.reg.isr, "TC");
    state->f0.fld.isr.txe = cm_object_get_child_by_name(state->f0.reg.isr,
            "TXE");
    state->f0.fld.isr.lbdf = cm_object_get_child_by_name(state->f0.reg.isr,
            "LBDF");
    state->f0.fld.isr.ctsif = cm_object_get_child_by_name(state->f0.reg.isr,
            "CTSIF");
    state->f0.fld.isr.cts = cm_object_get_child_by_name(state->f0.reg.isr,
            "CTS");
    state->f0.fld.isr.rtof = cm_object_get_child_by_name(state->f0.reg.isr,
            "RTOF");
    state->f0.fld.isr.eobf = cm_object_get_child_by_name(state->f0.reg.isr,
            "EOBF");
    state->f0.fld.isr.abre = cm_object_get_child_by_name(state->f0.reg.isr,
            "ABRE");
    state->f0.fld.isr.abrf = cm_object_get_child_by_name(state->f0.reg.isr,
            "ABRF");
    state->f0.fld.isr.busy = cm_object_get_child_by_name(state->f0.reg.isr,
            "BUSY");
    state->f0.fld.isr.cmf = cm_object_get_child_by_name(state->f0.reg.isr,
            "CMF");
    state->f0.fld.isr.sbkf = cm_object_get_child_by_name(state->f0.reg.isr,
            "SBKF");
    state->f0.fld.isr.rwu = cm_object_get_child_by_name(state->f0.reg.isr,
            "RWU");
    state->f0.fld.isr.wuf = cm_object_get_child_by_name(state->f0.reg.isr,
            "WUF");
    state->f0.fld.isr.teack = cm_object_get_child_by_name(state->f0.reg.isr,
            "TEACK");
    state->f0.fld.isr.reack = cm_object_get_child_by_name(state->f0.reg.isr,
            "REACK");

    // ICR bitfields.
    state->f0.fld.icr.pecf = cm_object_get_child_by_name(state->f0.reg.icr,
            "PECF");
    state->f0.fld.icr.fecf = cm_object_get_child_by_name(state->f0.reg.icr,
            "FECF");
    state->f0.fld.icr.ncf = cm_object_get_child_by_name(state->f0.reg.icr,
            "NCF");
    state->f0.fld.icr.orecf = cm_object_get_child_by_name(state->f0.reg.icr,
            "ORECF");
    state->f0.fld.icr.idlecf = cm_object_get_child_by_name(state->f0.reg.icr,
            "IDLECF");
    state->f0.fld.icr.tccf = cm_object_get_child_by_name(state->f0.reg.icr,
            "TCCF");
    state->f0.fld.icr.lbdcf = cm_object_get_child_by_name(state->f0.reg.icr,
            "LBDCF");
    state->f0.fld.icr.ctscf = cm_object_get_child_by_name(state->f0.reg.icr,
            "CTSCF");
    state->f0.fld.icr.rtocf = cm_object_get_child_by_name(state->f0.reg.icr,
            "RTOCF");
    state->f0.fld.icr.eobcf = cm_object_get_child_by_name(state->f0.reg.icr,
            "EOBCF");
    state->f0.fld.icr.cmcf = cm_object_get_child_by_name(state->f0.reg.icr,
            "CMCF");
    state->f0.fld.icr.wucf = cm_object_get_child_by_name(state->f0.reg.icr,
            "WUCF");

    // RDR bitfields.
    state->f0.fld.rdr.rdr = cm_object_get_child_by_name(state->f0.reg.rdr,
            "RDR");

    // TDR bitfields.
    state->f0.fld.tdr.tdr = cm_object_get_child_by_name(state->f0.reg.tdr,
            "TDR");
}

/* ------------------------------------------------------------------------- */

static void stm32f40x_usart_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    // DO NOT EDIT! Automatically generated!
    STM32USARTState *state = STM32_USART_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->f4.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->f4.reg.dr = cm_object_get_child_by_name(obj, "DR");
    state->f4.reg.brr = cm_object_get_child_by_name(obj, "BRR");
    state->f4.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
    state->f4.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
    state->f4.reg.cr3 = cm_object_get_child_by_name(obj, "CR3");
    state->f4.reg.gtpr = cm_object_get_child_by_name(obj, "GTPR");

    // SR bitfields.
    state->f4.fld.sr.pe = cm_object_get_child_by_name(state->f4.reg.sr, "PE");
    state->f4.fld.sr.fe = cm_object_get_child_by_name(state->f4.reg.sr, "FE");
    state->f4.fld.sr.nf = cm_object_get_child_by_name(state->f4.reg.sr, "NF");
    state->f4.fld.sr.ore = cm_object_get_child_by_name(state->f4.reg.sr, "ORE");
    state->f4.fld.sr.idle = cm_object_get_child_by_name(state->f4.reg.sr,
            "IDLE");
    state->f4.fld.sr.rxne = cm_object_get_child_by_name(state->f4.reg.sr,
            "RXNE");
    state->f4.fld.sr.tc = cm_object_get_child_by_name(state->f4.reg.sr, "TC");
    state->f4.fld.sr.txe = cm_object_get_child_by_name(state->f4.reg.sr, "TXE");
    state->f4.fld.sr.lbd = cm_object_get_child_by_name(state->f4.reg.sr, "LBD");
    state->f4.fld.sr.cts = cm_object_get_child_by_name(state->f4.reg.sr, "CTS");

    // DR bitfields.
    state->f4.fld.dr.dr = cm_object_get_child_by_name(state->f4.reg.dr, "DR");

    // BRR bitfields.
    state->f4.fld.brr.div_fraction = cm_object_get_child_by_name(
            state->f4.reg.brr, "DIV_Fraction");
    state->f4.fld.brr.div_mantissa = cm_object_get_child_by_name(
            state->f4.reg.brr, "DIV_Mantissa");

    // CR1 bitfields.
    state->f4.fld.cr1.sbk = cm_object_get_child_by_name(state->f4.reg.cr1,
            "SBK");
    state->f4.fld.cr1.rwu = cm_object_get_child_by_name(state->f4.reg.cr1,
            "RWU");
    state->f4.fld.cr1.re = cm_object_get_child_by_name(state->f4.reg.cr1, "RE");
    state->f4.fld.cr1.te = cm_object_get_child_by_name(state->f4.reg.cr1, "TE");
    state->f4.fld.cr1.idleie = cm_object_get_child_by_name(state->f4.reg.cr1,
            "IDLEIE");
    state->f4.fld.cr1.rxneie = cm_object_get_child_by_name(state->f4.reg.cr1,
            "RXNEIE");
    state->f4.fld.cr1.tcie = cm_object_get_child_by_name(state->f4.reg.cr1,
            "TCIE");
    state->f4.fld.cr1.txeie = cm_object_get_child_by_name(state->f4.reg.cr1,
            "TXEIE");
    state->f4.fld.cr1.peie = cm_object_get_child_by_name(state->f4.reg.cr1,
            "PEIE");
    state->f4.fld.cr1.ps = cm_object_get_child_by_name(state->f4.reg.cr1, "PS");
    state->f4.fld.cr1.pce = cm_object_get_child_by_name(state->f4.reg.cr1,
            "PCE");
    state->f4.fld.cr1.wake = cm_object_get_child_by_name(state->f4.reg.cr1,
            "WAKE");
    state->f4.fld.cr1.m = cm_object_get_child_by_name(state->f4.reg.cr1, "M");
    state->f4.fld.cr1.ue = cm_object_get_child_by_name(state->f4.reg.cr1, "UE");
    state->f4.fld.cr1.over8 = cm_object_get_child_by_name(state->f4.reg.cr1,
            "OVER8");

    // CR2 bitfields.
    state->f4.fld.cr2.add = cm_object_get_child_by_name(state->f4.reg.cr2,
            "ADD");
    state->f4.fld.cr2.lbdl = cm_object_get_child_by_name(state->f4.reg.cr2,
            "LBDL");
    state->f4.fld.cr2.lbdie = cm_object_get_child_by_name(state->f4.reg.cr2,
            "LBDIE");
    state->f4.fld.cr2.lbcl = cm_object_get_child_by_name(state->f4.reg.cr2,
            "LBCL");
    state->f4.fld.cr2.cpha = cm_object_get_child_by_name(state->f4.reg.cr2,
            "CPHA");
    state->f4.fld.cr2.cpol = cm_object_get_child_by_name(state->f4.reg.cr2,
            "CPOL");
    state->f4.fld.cr2.clken = cm_object_get_child_by_name(state->f4.reg.cr2,
            "CLKEN");
    state->f4.fld.cr2.stop = cm_object_get_child_by_name(state->f4.reg.cr2,
            "STOP");
    state->f4.fld.cr2.linen = cm_object_get_child_by_name(state->f4.reg.cr2,
            "LINEN");

    // CR3 bitfields.
    state->f4.fld.cr3.eie = cm_object_get_child_by_name(state->f4.reg.cr3,
            "EIE");
    state->f4.fld.cr3.iren = cm_object_get_child_by_name(state->f4.reg.cr3,
            "IREN");
    state->f4.fld.cr3.irlp = cm_object_get_child_by_name(state->f4.reg.cr3,
            "IRLP");
    state->f4.fld.cr3.hdsel = cm_object_get_child_by_name(state->f4.reg.cr3,
            "HDSEL");
    state->f4.fld.cr3.nack = cm_object_get_child_by_name(state->f4.reg.cr3,
            "NACK");
    state->f4.fld.cr3.scen = cm_object_get_child_by_name(state->f4.reg.cr3,
            "SCEN");
    state->f4.fld.cr3.dmar = cm_object_get_child_by_name(state->f4.reg.cr3,
            "DMAR");
    state->f4.fld.cr3.dmat = cm_object_get_child_by_name(state->f4.reg.cr3,
            "DMAT");
    state->f4.fld.cr3.rtse = cm_object_get_child_by_name(state->f4.reg.cr3,
            "RTSE");
    state->f4.fld.cr3.ctse = cm_object_get_child_by_name(state->f4.reg.cr3,
            "CTSE");
    state->f4.fld.cr3.ctsie = cm_object_get_child_by_name(state->f4.reg.cr3,
            "CTSIE");
    state->f4.fld.cr3.onebit = cm_object_get_child_by_name(state->f4.reg.cr3,
            "ONEBIT");

    // GTPR bitfields.
    state->f4.fld.gtpr.psc = cm_object_get_child_by_name(state->f4.reg.gtpr,
            "PSC");
    state->f4.fld.gtpr.gt = cm_object_get_child_by_name(state->f4.reg.gtpr,
            "GT");
}

#if 0
static PeripheralInfo stm32f4_usart_info =
{
    .desc = "Universal synch asynch receiver transmitter (USART)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_WORD_HALFWORD,

    .registers =
    (PeripheralRegisterInfo[] ) {
        {
            .desc = "USART status register (USART_SR)",
            .name = "sr",
            .offset_bytes = 0x00,
            /* datasheet indicates 0x00C00000, but I think it's wrong */
            .reset_value = 0x000000C0,
            .readable_bits = 0x000003FF,
            .writable_bits = 0x00000360,
            /**/
        },
        {
            .desc = "USART data register (USART_DR)",
            .name = "dr",
            .offset_bytes = 0x04,
            .reset_value = 0x00000000,
            .readable_bits = 0x000001FF,
            .writable_bits = 0x000001FF,
            /**/
        },
        {
            .desc =
            "USART baud rate register (USART_BRR)",
            .name = "brr",
            .offset_bytes = 0x08,
            .reset_value = 0x00000000,
            .readable_bits = 0x0000FFFF,
            .writable_bits = 0x0000FFFF,
            /**/
        },
        {
            .desc =
            "USART control register 1 (USART_CR1)",
            .name = "cr1",
            .offset_bytes = 0x0C,
            .reset_value = 0x00000000,
            .readable_bits = 0x0000BFFF,
            .writable_bits = 0x0000BFFF,
            /**/
        },
        {
            .desc =
            "USART control register 2 (USART_CR2)",
            .name = "cr2",
            .offset_bytes = 0x10,
            .reset_value = 0x00000000,
            .readable_bits = 0x00007F7F,
            .writable_bits = 0x00007F7F,
            /**/
        },
        {
            .desc =
            "USART control register 3 (USART_CR3)",
            .name = "cr3",
            .offset_bytes = 0x14,
            .reset_value = 0x00000000,
            .writable_bits = 0x00000FFF,
            .readable_bits = 0x00000FFF,
            /**/
        },
        {
            .desc =
            "USART guard time and prescaler register (USART_GTPR)",
            .name = "gtpr",
            .offset_bytes = 0x18,
            .reset_value = 0x00000000,
            .writable_bits = 0x0000FFFF,
            .readable_bits = 0x0000FFFF,
            /**/
        },
        {}, /**/
    },
    /**/
};
#endif

#if 0
static void stm32f4xx_usart_create_objects(Object *obj, JSON_Value *family)
{
    STM32USARTState *state = STM32_USART_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family,
            "stm32f4xx:usart");

    peripheral_add_properties_and_children2(obj, info);

    state->reg.sr = cm_object_get_child_by_name(obj, "sr");
    state->reg.dr = cm_object_get_child_by_name(obj, "dr");
    state->reg.brr = cm_object_get_child_by_name(obj, "brr");
    state->reg.cr1 = cm_object_get_child_by_name(obj, "cr1");
    state->reg.cr2 = cm_object_get_child_by_name(obj, "cr2");
    state->reg.cr3 = cm_object_get_child_by_name(obj, "cr3");
    state->reg.gtpr = cm_object_get_child_by_name(obj, "gtpr");
}
#endif

/* ------------------------------------------------------------------------- */

static int smt32f4_usart_get_irq_vector(STM32USARTState *state)
{
    /* TODO: use capabilities to select interrupt numbers
     * for different variants.
     */
    switch (state->port_index) {
    case STM32_USART_1:
        return STM32F4_01_57_XX_USART1_IRQn;
    case STM32_USART_2:
        return STM32F4_01_57_XX_USART2_IRQn;
    case STM32_USART_3:
        return STM32F4_01_57_XX_USART3_IRQn;
    case STM32_UART_4:
        return STM32F4_01_57_XX_UART4_IRQn;
    case STM32_UART_5:
        return STM32F4_01_57_XX_UART5_IRQn;
    case STM32_USART_6:
        return STM32F4_01_57_XX_USART6_IRQn;
    default:
        return 1023; /* Whatever... */
    }
}

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
        /* USART not enabled - drop the chars */
        return;
    }

    peripheral_register_set_raw_value(state->reg.dr, *buf);
    peripheral_register_or_raw_value(state->reg.sr, USART_SR_RXNE);

    if (cr1 & USART_CR1_RXNEIE) {
        cortexm_nvic_set_pending_interrupt(state->nvic,
                smt32f4_usart_get_irq_vector(state));
    }
}

static void stm32f4_usart_dr_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32USARTState *state = STM32_USART_STATE(periph);

    peripheral_register_and_raw_value(state->reg.sr, ~USART_SR_RXNE);
    if (state->chr) {
        qemu_chr_accept_input(state->chr);
    }
}

static void stm32f4_usart_dr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32USARTState *state = STM32_USART_STATE(periph);
    unsigned char ch;

    int32_t cr1 = peripheral_register_get_raw_value(state->reg.cr1);

    /* 'value' may be half-word, use full_word. */
    if ((cr1 & USART_CR1_UE) && (cr1 & USART_CR1_TE)) {
        if (state->chr) {
            ch = full_value; /* Use only the lower 8 bits */
            qemu_chr_fe_write_all(state->chr, &ch, 1);
        }
        /* transmission is immediately complete */
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

    /* 'value' may be half-word, use full_word. */
    if (((full_value & USART_CR1_RXNEIE) && (sr & USART_SR_RXNE))
            || ((full_value & USART_CR1_TXEIE) && (sr & USART_SR_TXE))
            || ((full_value & USART_CR1_TCIE) && (sr & USART_SR_TC))) {
        cortexm_nvic_set_pending_interrupt(state->nvic,
                smt32f4_usart_get_irq_vector(state));
    }
}

/* ------------------------------------------------------------------------- */

static void stm32_usart_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    /* STM32USARTState *state = STM32_USART_STATE(obj); */

    /* FIXME use a qdev char-device prop instead of qemu_char_get_next_serial() */
    /* state->chr = qemu_char_get_next_serial(); */
}

static void stm32_usart_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /* No need to call parent realize(). */

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32USARTState *state = STM32_USART_STATE(dev);
    /* First thing first: get capabilities from MCU, needed everywhere. */
    state->capabilities = mcu->capabilities;

    Object *obj = OBJECT(dev);

    /* Must be defined before creating registers. */
    cm_object_property_set_int(obj, 4, "register-size-bytes");

    /* TODO: get it from MCU */
    cm_object_property_set_bool(obj, true, "is-little-endian");

    /*
     * Creating the memory region in the parent class will trigger
     * an assertion if zro address or size.
     */
    uint32_t size = 0;
    hwaddr addr = 0;

    const STM32Capabilities *capabilities =
    STM32_USART_STATE(state)->capabilities;
    assert(capabilities != NULL);

    char usart_name[10];
    snprintf(usart_name, sizeof(usart_name) - 1, "USART%d",
            state->port_index - STM32_USART_1 + 1);

    switch (capabilities->family) {
    case STM32_FAMILY_F0:
        if (state->port_index > STM32_USART_8) {
            qemu_log_mask(LOG_GUEST_ERROR, "USART: Illegal USART port %d\n",
                    state->port_index);
            return;
        }
        size = 0x400;
        if (state->port_index == STM32_USART_1) {
            addr = 0x40013800;
        } else if (state->port_index == STM32_USART_2) {
            addr = 0x40004400;
        } else if (state->port_index == STM32_USART_3) {
            addr = 0x40004800;
        } else if (state->port_index == STM32_USART_4) {
            addr = 0x40004C00;
        } else if (state->port_index == STM32_USART_5) {
            addr = 0x40005000;
        } else if (state->port_index == STM32_USART_6) {
            addr = 0x40011400;
        } else if (state->port_index == STM32_USART_7) {
            addr = 0x40011800;
        } else if (state->port_index == STM32_USART_8) {
            addr = 0x40011C00;
        } else {
            assert(false);
        }

        break;

    case STM32_FAMILY_F4:

        if (state->port_index > STM32_USART_6) {
            qemu_log_mask(LOG_GUEST_ERROR, "USART: Illegal USART port %d\n",
                    state->port_index);
            return;
        }

        size = 0x400;
        if (state->port_index == STM32_USART_1) {
            addr = 0x40011000;
        } else if (state->port_index == STM32_USART_6) {
            addr = 0x40011400;
        } else {
            addr = 0x40004400 + (state->port_index - STM32_USART_2) * size;
        }

        break;

    default:

        assert(false);
        break;
    }

    cm_object_property_set_int(obj, addr, "mmio-address");
    cm_object_property_set_int(obj, size, "mmio-size-bytes");

    switch (capabilities->family) {
    case STM32_FAMILY_F0:
        stm32f0x1_usart_create_objects(obj, cm_state->svd_json, usart_name);

        // TODO: add callbacks
        break;

    case STM32_FAMILY_F4:

        // stm32f4xx_usart_create_objects(obj, mcu->family_json);
        stm32f40x_usart_create_objects(obj, cm_state->svd_json, usart_name);

        state->reg.sr = state->f4.reg.sr;
        state->reg.dr = state->f4.reg.dr;
        state->reg.brr = state->f4.reg.brr;
        state->reg.cr1 = state->f4.reg.cr1;
        state->reg.cr2 = state->f4.reg.cr2;
        state->reg.cr3 = state->f4.reg.cr3;
        state->reg.gtpr = state->f4.reg.gtpr;

        /* Register callbacks. */
        peripheral_register_set_post_read(state->reg.dr,
                &stm32f4_usart_dr_post_read_callback);
        peripheral_register_set_post_write(state->reg.dr,
                &stm32f4_usart_dr_post_write_callback);
        peripheral_register_set_post_write(state->reg.cr1,
                &stm32f4_usart_cr1_post_write_callback);

        /* char-device callbacks. */
        if (state->chr) {
            qemu_chr_add_handlers(state->chr, stm32f4_usart_can_receive,
                    stm32f4_usart_receive, NULL, obj);
        }

        break;

    default:
        assert(false);
        break;
    }

    /* Call parent realize(). */
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_USART)) {
        return;
    }
}

static void stm32_usart_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    /* No need to call parent reset(). */

    STM32USARTState *state = STM32_USART_STATE(dev);

    /* Call parent reset(). */
    cm_device_parent_reset(dev, TYPE_STM32_USART);

    if (state->chr) {
        qemu_chr_accept_input(state->chr);
    }

    const STM32Capabilities *capabilities =
    STM32_USART_STATE(state)->capabilities;
    assert(capabilities != NULL);

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        // TODO:
        /* FIXME: We should certainly clear the interrupt state.
         * Don't know how to do that: implement cortexm_nvic_clear_pending ??? */
        break;

    default:
        break;
    }

}

static Property stm32_usart_properties[] = {
        DEFINE_PROP_CHR("chardev", STM32USARTState, chr),
        DEFINE_PROP_INT32_TYPE("port-index", STM32USARTState, port_index,
                STM32_USART_PORT_UNDEFINED, stm32_usart_index_t),
        DEFINE_PROP_NON_VOID_PTR("rcc", STM32USARTState, rcc, STM32RCCState *),
        DEFINE_PROP_NON_VOID_PTR("nvic", STM32USARTState,
                nvic, CortexMNVICState *),
        DEFINE_PROP_NON_VOID_PTR("capabilities", STM32USARTState,
                capabilities, const STM32Capabilities *),
    DEFINE_PROP_END_OF_LIST() };

static void stm32_usart_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_usart_reset_callback;
    dc->realize = stm32_usart_realize_callback;

    dc->props = stm32_usart_properties;

    /* Reason: instance_init() method uses qemu_char_get_next_serial()
     dc->cannot_instantiate_with_device_add_yet = true;*/

    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_usart_is_enabled;
}

static const TypeInfo stm32_usart_type_info = {
    .name = TYPE_STM32_USART,
    .parent = TYPE_STM32_USART_PARENT,
    .instance_init = stm32_usart_instance_init_callback,
    .instance_size = sizeof(STM32USARTState),
    .class_init = stm32_usart_class_init_callback,
    .class_size = sizeof(STM32USARTClass) /**/
};

static void stm32_usart_register_types(void)
{
    type_register_static(&stm32_usart_type_info);

#if 0
    peripheral_serialize_info("f4xx-usart.json", "stm32f4xx:usart", &stm32f4_usart_info);
#endif
}

type_init(stm32_usart_register_types);

