/*
 * STM32 - USB (Universal serial bus full-speed device interface) emulation.
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

#include <hw/cortexm/stm32/usb.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_usb_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32USBState *state = STM32_USB_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f0.reg.ep0r = cm_object_get_child_by_name(obj, "EP0R");
    state->u.f0.reg.ep1r = cm_object_get_child_by_name(obj, "EP1R");
    state->u.f0.reg.ep2r = cm_object_get_child_by_name(obj, "EP2R");
    state->u.f0.reg.ep3r = cm_object_get_child_by_name(obj, "EP3R");
    state->u.f0.reg.ep4r = cm_object_get_child_by_name(obj, "EP4R");
    state->u.f0.reg.ep5r = cm_object_get_child_by_name(obj, "EP5R");
    state->u.f0.reg.ep6r = cm_object_get_child_by_name(obj, "EP6R");
    state->u.f0.reg.ep7r = cm_object_get_child_by_name(obj, "EP7R");
    state->u.f0.reg.cntr = cm_object_get_child_by_name(obj, "CNTR");
    state->u.f0.reg.istr = cm_object_get_child_by_name(obj, "ISTR");
    state->u.f0.reg.fnr = cm_object_get_child_by_name(obj, "FNR");
    state->u.f0.reg.daddr = cm_object_get_child_by_name(obj, "DADDR");
    state->u.f0.reg.btable = cm_object_get_child_by_name(obj, "BTABLE");
    state->u.f0.reg.lpmcsr = cm_object_get_child_by_name(obj, "LPMCSR");
    state->u.f0.reg.bcdr = cm_object_get_child_by_name(obj, "BCDR");
    
    
    // EP0R bitfields.
    state->u.f0.fld.ep0r.ea = cm_object_get_child_by_name(state->u.f0.reg.ep0r, "EA"); 
    state->u.f0.fld.ep0r.stat_tx = cm_object_get_child_by_name(state->u.f0.reg.ep0r, "STAT_TX"); 
    state->u.f0.fld.ep0r.dtog_tx = cm_object_get_child_by_name(state->u.f0.reg.ep0r, "DTOG_TX"); 
    state->u.f0.fld.ep0r.ctr_tx = cm_object_get_child_by_name(state->u.f0.reg.ep0r, "CTR_TX"); 
    state->u.f0.fld.ep0r.ep_kind = cm_object_get_child_by_name(state->u.f0.reg.ep0r, "EP_KIND"); 
    state->u.f0.fld.ep0r.ep_type = cm_object_get_child_by_name(state->u.f0.reg.ep0r, "EP_TYPE"); 
    state->u.f0.fld.ep0r.setup = cm_object_get_child_by_name(state->u.f0.reg.ep0r, "SETUP"); 
    state->u.f0.fld.ep0r.stat_rx = cm_object_get_child_by_name(state->u.f0.reg.ep0r, "STAT_RX"); 
    state->u.f0.fld.ep0r.dtog_rx = cm_object_get_child_by_name(state->u.f0.reg.ep0r, "DTOG_RX"); 
    state->u.f0.fld.ep0r.ctr_rx = cm_object_get_child_by_name(state->u.f0.reg.ep0r, "CTR_RX");  
    
    // EP1R bitfields.
    state->u.f0.fld.ep1r.ea = cm_object_get_child_by_name(state->u.f0.reg.ep1r, "EA"); 
    state->u.f0.fld.ep1r.stat_tx = cm_object_get_child_by_name(state->u.f0.reg.ep1r, "STAT_TX"); 
    state->u.f0.fld.ep1r.dtog_tx = cm_object_get_child_by_name(state->u.f0.reg.ep1r, "DTOG_TX"); 
    state->u.f0.fld.ep1r.ctr_tx = cm_object_get_child_by_name(state->u.f0.reg.ep1r, "CTR_TX"); 
    state->u.f0.fld.ep1r.ep_kind = cm_object_get_child_by_name(state->u.f0.reg.ep1r, "EP_KIND"); 
    state->u.f0.fld.ep1r.ep_type = cm_object_get_child_by_name(state->u.f0.reg.ep1r, "EP_TYPE"); 
    state->u.f0.fld.ep1r.setup = cm_object_get_child_by_name(state->u.f0.reg.ep1r, "SETUP"); 
    state->u.f0.fld.ep1r.stat_rx = cm_object_get_child_by_name(state->u.f0.reg.ep1r, "STAT_RX"); 
    state->u.f0.fld.ep1r.dtog_rx = cm_object_get_child_by_name(state->u.f0.reg.ep1r, "DTOG_RX"); 
    state->u.f0.fld.ep1r.ctr_rx = cm_object_get_child_by_name(state->u.f0.reg.ep1r, "CTR_RX");  
    
    // EP2R bitfields.
    state->u.f0.fld.ep2r.ea = cm_object_get_child_by_name(state->u.f0.reg.ep2r, "EA"); 
    state->u.f0.fld.ep2r.stat_tx = cm_object_get_child_by_name(state->u.f0.reg.ep2r, "STAT_TX"); 
    state->u.f0.fld.ep2r.dtog_tx = cm_object_get_child_by_name(state->u.f0.reg.ep2r, "DTOG_TX"); 
    state->u.f0.fld.ep2r.ctr_tx = cm_object_get_child_by_name(state->u.f0.reg.ep2r, "CTR_TX"); 
    state->u.f0.fld.ep2r.ep_kind = cm_object_get_child_by_name(state->u.f0.reg.ep2r, "EP_KIND"); 
    state->u.f0.fld.ep2r.ep_type = cm_object_get_child_by_name(state->u.f0.reg.ep2r, "EP_TYPE"); 
    state->u.f0.fld.ep2r.setup = cm_object_get_child_by_name(state->u.f0.reg.ep2r, "SETUP"); 
    state->u.f0.fld.ep2r.stat_rx = cm_object_get_child_by_name(state->u.f0.reg.ep2r, "STAT_RX"); 
    state->u.f0.fld.ep2r.dtog_rx = cm_object_get_child_by_name(state->u.f0.reg.ep2r, "DTOG_RX"); 
    state->u.f0.fld.ep2r.ctr_rx = cm_object_get_child_by_name(state->u.f0.reg.ep2r, "CTR_RX");  
    
    // EP3R bitfields.
    state->u.f0.fld.ep3r.ea = cm_object_get_child_by_name(state->u.f0.reg.ep3r, "EA"); 
    state->u.f0.fld.ep3r.stat_tx = cm_object_get_child_by_name(state->u.f0.reg.ep3r, "STAT_TX"); 
    state->u.f0.fld.ep3r.dtog_tx = cm_object_get_child_by_name(state->u.f0.reg.ep3r, "DTOG_TX"); 
    state->u.f0.fld.ep3r.ctr_tx = cm_object_get_child_by_name(state->u.f0.reg.ep3r, "CTR_TX"); 
    state->u.f0.fld.ep3r.ep_kind = cm_object_get_child_by_name(state->u.f0.reg.ep3r, "EP_KIND"); 
    state->u.f0.fld.ep3r.ep_type = cm_object_get_child_by_name(state->u.f0.reg.ep3r, "EP_TYPE"); 
    state->u.f0.fld.ep3r.setup = cm_object_get_child_by_name(state->u.f0.reg.ep3r, "SETUP"); 
    state->u.f0.fld.ep3r.stat_rx = cm_object_get_child_by_name(state->u.f0.reg.ep3r, "STAT_RX"); 
    state->u.f0.fld.ep3r.dtog_rx = cm_object_get_child_by_name(state->u.f0.reg.ep3r, "DTOG_RX"); 
    state->u.f0.fld.ep3r.ctr_rx = cm_object_get_child_by_name(state->u.f0.reg.ep3r, "CTR_RX");  
    
    // EP4R bitfields.
    state->u.f0.fld.ep4r.ea = cm_object_get_child_by_name(state->u.f0.reg.ep4r, "EA"); 
    state->u.f0.fld.ep4r.stat_tx = cm_object_get_child_by_name(state->u.f0.reg.ep4r, "STAT_TX"); 
    state->u.f0.fld.ep4r.dtog_tx = cm_object_get_child_by_name(state->u.f0.reg.ep4r, "DTOG_TX"); 
    state->u.f0.fld.ep4r.ctr_tx = cm_object_get_child_by_name(state->u.f0.reg.ep4r, "CTR_TX"); 
    state->u.f0.fld.ep4r.ep_kind = cm_object_get_child_by_name(state->u.f0.reg.ep4r, "EP_KIND"); 
    state->u.f0.fld.ep4r.ep_type = cm_object_get_child_by_name(state->u.f0.reg.ep4r, "EP_TYPE"); 
    state->u.f0.fld.ep4r.setup = cm_object_get_child_by_name(state->u.f0.reg.ep4r, "SETUP"); 
    state->u.f0.fld.ep4r.stat_rx = cm_object_get_child_by_name(state->u.f0.reg.ep4r, "STAT_RX"); 
    state->u.f0.fld.ep4r.dtog_rx = cm_object_get_child_by_name(state->u.f0.reg.ep4r, "DTOG_RX"); 
    state->u.f0.fld.ep4r.ctr_rx = cm_object_get_child_by_name(state->u.f0.reg.ep4r, "CTR_RX");  
    
    // EP5R bitfields.
    state->u.f0.fld.ep5r.ea = cm_object_get_child_by_name(state->u.f0.reg.ep5r, "EA"); 
    state->u.f0.fld.ep5r.stat_tx = cm_object_get_child_by_name(state->u.f0.reg.ep5r, "STAT_TX"); 
    state->u.f0.fld.ep5r.dtog_tx = cm_object_get_child_by_name(state->u.f0.reg.ep5r, "DTOG_TX"); 
    state->u.f0.fld.ep5r.ctr_tx = cm_object_get_child_by_name(state->u.f0.reg.ep5r, "CTR_TX"); 
    state->u.f0.fld.ep5r.ep_kind = cm_object_get_child_by_name(state->u.f0.reg.ep5r, "EP_KIND"); 
    state->u.f0.fld.ep5r.ep_type = cm_object_get_child_by_name(state->u.f0.reg.ep5r, "EP_TYPE"); 
    state->u.f0.fld.ep5r.setup = cm_object_get_child_by_name(state->u.f0.reg.ep5r, "SETUP"); 
    state->u.f0.fld.ep5r.stat_rx = cm_object_get_child_by_name(state->u.f0.reg.ep5r, "STAT_RX"); 
    state->u.f0.fld.ep5r.dtog_rx = cm_object_get_child_by_name(state->u.f0.reg.ep5r, "DTOG_RX"); 
    state->u.f0.fld.ep5r.ctr_rx = cm_object_get_child_by_name(state->u.f0.reg.ep5r, "CTR_RX");  
    
    // EP6R bitfields.
    state->u.f0.fld.ep6r.ea = cm_object_get_child_by_name(state->u.f0.reg.ep6r, "EA"); 
    state->u.f0.fld.ep6r.stat_tx = cm_object_get_child_by_name(state->u.f0.reg.ep6r, "STAT_TX"); 
    state->u.f0.fld.ep6r.dtog_tx = cm_object_get_child_by_name(state->u.f0.reg.ep6r, "DTOG_TX"); 
    state->u.f0.fld.ep6r.ctr_tx = cm_object_get_child_by_name(state->u.f0.reg.ep6r, "CTR_TX"); 
    state->u.f0.fld.ep6r.ep_kind = cm_object_get_child_by_name(state->u.f0.reg.ep6r, "EP_KIND"); 
    state->u.f0.fld.ep6r.ep_type = cm_object_get_child_by_name(state->u.f0.reg.ep6r, "EP_TYPE"); 
    state->u.f0.fld.ep6r.setup = cm_object_get_child_by_name(state->u.f0.reg.ep6r, "SETUP"); 
    state->u.f0.fld.ep6r.stat_rx = cm_object_get_child_by_name(state->u.f0.reg.ep6r, "STAT_RX"); 
    state->u.f0.fld.ep6r.dtog_rx = cm_object_get_child_by_name(state->u.f0.reg.ep6r, "DTOG_RX"); 
    state->u.f0.fld.ep6r.ctr_rx = cm_object_get_child_by_name(state->u.f0.reg.ep6r, "CTR_RX");  
    
    // EP7R bitfields.
    state->u.f0.fld.ep7r.ea = cm_object_get_child_by_name(state->u.f0.reg.ep7r, "EA"); 
    state->u.f0.fld.ep7r.stat_tx = cm_object_get_child_by_name(state->u.f0.reg.ep7r, "STAT_TX"); 
    state->u.f0.fld.ep7r.dtog_tx = cm_object_get_child_by_name(state->u.f0.reg.ep7r, "DTOG_TX"); 
    state->u.f0.fld.ep7r.ctr_tx = cm_object_get_child_by_name(state->u.f0.reg.ep7r, "CTR_TX"); 
    state->u.f0.fld.ep7r.ep_kind = cm_object_get_child_by_name(state->u.f0.reg.ep7r, "EP_KIND"); 
    state->u.f0.fld.ep7r.ep_type = cm_object_get_child_by_name(state->u.f0.reg.ep7r, "EP_TYPE"); 
    state->u.f0.fld.ep7r.setup = cm_object_get_child_by_name(state->u.f0.reg.ep7r, "SETUP"); 
    state->u.f0.fld.ep7r.stat_rx = cm_object_get_child_by_name(state->u.f0.reg.ep7r, "STAT_RX"); 
    state->u.f0.fld.ep7r.dtog_rx = cm_object_get_child_by_name(state->u.f0.reg.ep7r, "DTOG_RX"); 
    state->u.f0.fld.ep7r.ctr_rx = cm_object_get_child_by_name(state->u.f0.reg.ep7r, "CTR_RX");  
    
    // CNTR bitfields.
    state->u.f0.fld.cntr.fres = cm_object_get_child_by_name(state->u.f0.reg.cntr, "FRES"); 
    state->u.f0.fld.cntr.pdwn = cm_object_get_child_by_name(state->u.f0.reg.cntr, "PDWN"); 
    state->u.f0.fld.cntr.lpmode = cm_object_get_child_by_name(state->u.f0.reg.cntr, "LPMODE"); 
    state->u.f0.fld.cntr.fsusp = cm_object_get_child_by_name(state->u.f0.reg.cntr, "FSUSP"); 
    state->u.f0.fld.cntr.resume = cm_object_get_child_by_name(state->u.f0.reg.cntr, "RESUME"); 
    state->u.f0.fld.cntr.l1resume = cm_object_get_child_by_name(state->u.f0.reg.cntr, "L1RESUME"); 
    state->u.f0.fld.cntr.l1reqm = cm_object_get_child_by_name(state->u.f0.reg.cntr, "L1REQM"); 
    state->u.f0.fld.cntr.esofm = cm_object_get_child_by_name(state->u.f0.reg.cntr, "ESOFM"); 
    state->u.f0.fld.cntr.sofm = cm_object_get_child_by_name(state->u.f0.reg.cntr, "SOFM"); 
    state->u.f0.fld.cntr.resetm = cm_object_get_child_by_name(state->u.f0.reg.cntr, "RESETM"); 
    state->u.f0.fld.cntr.suspm = cm_object_get_child_by_name(state->u.f0.reg.cntr, "SUSPM"); 
    state->u.f0.fld.cntr.wkupm = cm_object_get_child_by_name(state->u.f0.reg.cntr, "WKUPM"); 
    state->u.f0.fld.cntr.errm = cm_object_get_child_by_name(state->u.f0.reg.cntr, "ERRM"); 
    state->u.f0.fld.cntr.pmaovrm = cm_object_get_child_by_name(state->u.f0.reg.cntr, "PMAOVRM"); 
    state->u.f0.fld.cntr.ctrm = cm_object_get_child_by_name(state->u.f0.reg.cntr, "CTRM");  
    
    // ISTR bitfields.
    state->u.f0.fld.istr.ep_id = cm_object_get_child_by_name(state->u.f0.reg.istr, "EP_ID"); 
    state->u.f0.fld.istr.dir = cm_object_get_child_by_name(state->u.f0.reg.istr, "DIR"); 
    state->u.f0.fld.istr.l1req = cm_object_get_child_by_name(state->u.f0.reg.istr, "L1REQ"); 
    state->u.f0.fld.istr.esof = cm_object_get_child_by_name(state->u.f0.reg.istr, "ESOF"); 
    state->u.f0.fld.istr.sof = cm_object_get_child_by_name(state->u.f0.reg.istr, "SOF"); 
    state->u.f0.fld.istr.reset = cm_object_get_child_by_name(state->u.f0.reg.istr, "RESET"); 
    state->u.f0.fld.istr.susp = cm_object_get_child_by_name(state->u.f0.reg.istr, "SUSP"); 
    state->u.f0.fld.istr.wkup = cm_object_get_child_by_name(state->u.f0.reg.istr, "WKUP"); 
    state->u.f0.fld.istr.err = cm_object_get_child_by_name(state->u.f0.reg.istr, "ERR"); 
    state->u.f0.fld.istr.pmaovr = cm_object_get_child_by_name(state->u.f0.reg.istr, "PMAOVR"); 
    state->u.f0.fld.istr.ctr = cm_object_get_child_by_name(state->u.f0.reg.istr, "CTR");  
    
    // FNR bitfields.
    state->u.f0.fld.fnr.fn = cm_object_get_child_by_name(state->u.f0.reg.fnr, "FN"); 
    state->u.f0.fld.fnr.lsof = cm_object_get_child_by_name(state->u.f0.reg.fnr, "LSOF"); 
    state->u.f0.fld.fnr.lck = cm_object_get_child_by_name(state->u.f0.reg.fnr, "LCK"); 
    state->u.f0.fld.fnr.rxdm = cm_object_get_child_by_name(state->u.f0.reg.fnr, "RXDM"); 
    state->u.f0.fld.fnr.rxdp = cm_object_get_child_by_name(state->u.f0.reg.fnr, "RXDP");  
    
    // DADDR bitfields.
    state->u.f0.fld.daddr.add = cm_object_get_child_by_name(state->u.f0.reg.daddr, "ADD"); 
    state->u.f0.fld.daddr.ef = cm_object_get_child_by_name(state->u.f0.reg.daddr, "EF");  
    
    // BTABLE bitfields.
    state->u.f0.fld.btable.btable = cm_object_get_child_by_name(state->u.f0.reg.btable, "BTABLE");  
    
    // LPMCSR bitfields.
    state->u.f0.fld.lpmcsr.lpmen = cm_object_get_child_by_name(state->u.f0.reg.lpmcsr, "LPMEN"); 
    state->u.f0.fld.lpmcsr.lpmack = cm_object_get_child_by_name(state->u.f0.reg.lpmcsr, "LPMACK"); 
    state->u.f0.fld.lpmcsr.remwake = cm_object_get_child_by_name(state->u.f0.reg.lpmcsr, "REMWAKE"); 
    state->u.f0.fld.lpmcsr.besl = cm_object_get_child_by_name(state->u.f0.reg.lpmcsr, "BESL");  
    
    // BCDR bitfields.
    state->u.f0.fld.bcdr.bcden = cm_object_get_child_by_name(state->u.f0.reg.bcdr, "BCDEN"); 
    state->u.f0.fld.bcdr.dcden = cm_object_get_child_by_name(state->u.f0.reg.bcdr, "DCDEN"); 
    state->u.f0.fld.bcdr.pden = cm_object_get_child_by_name(state->u.f0.reg.bcdr, "PDEN"); 
    state->u.f0.fld.bcdr.sden = cm_object_get_child_by_name(state->u.f0.reg.bcdr, "SDEN"); 
    state->u.f0.fld.bcdr.dcdet = cm_object_get_child_by_name(state->u.f0.reg.bcdr, "DCDET"); 
    state->u.f0.fld.bcdr.pdet = cm_object_get_child_by_name(state->u.f0.reg.bcdr, "PDET"); 
    state->u.f0.fld.bcdr.sdet = cm_object_get_child_by_name(state->u.f0.reg.bcdr, "SDET"); 
    state->u.f0.fld.bcdr.ps2det = cm_object_get_child_by_name(state->u.f0.reg.bcdr, "PS2DET"); 
    state->u.f0.fld.bcdr.dppu = cm_object_get_child_by_name(state->u.f0.reg.bcdr, "DPPU");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_usb_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32USBState *state = STM32_USB_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_usb_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32USBState *state = STM32_USB_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_usb_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32USBState *state = STM32_USB_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_usb_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32USBState *state = STM32_USB_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_usb_is_enabled(Object *obj)
{
    STM32USBState *state = STM32_USB_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_usb_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32USBState *state = STM32_USB_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_usb_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_USB)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32USBState *state = STM32_USB_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "USB";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x1 ) {

            stm32f0x1_usb_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_usb_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f0.reg.xxx, &stm32_usb_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_usb_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f0.reg.xxx, &stm32_usb_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/USBEN");


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

static void stm32_usb_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_USB);
}

static void stm32_usb_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_usb_reset_callback;
    dc->realize = stm32_usb_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_usb_is_enabled;
}

static const TypeInfo stm32_usb_type_info = {
    .name = TYPE_STM32_USB,
    .parent = TYPE_STM32_USB_PARENT,
    .instance_init = stm32_usb_instance_init_callback,
    .instance_size = sizeof(STM32USBState),
    .class_init = stm32_usb_class_init_callback,
    .class_size = sizeof(STM32USBClass) };

static void stm32_usb_register_types(void)
{
    type_register_static(&stm32_usb_type_info);
}

type_init(stm32_usb_register_types);

// ----------------------------------------------------------------------------
