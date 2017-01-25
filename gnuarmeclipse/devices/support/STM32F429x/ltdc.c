/*
 * STM32 - LTDC (LCD-TFT Controller) emulation.
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

#include <hw/cortexm/stm32/ltdc.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f429x_ltdc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32LTDCState *state = STM32_LTDC_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.sscr = cm_object_get_child_by_name(obj, "SSCR");
    state->u.f4.reg.bpcr = cm_object_get_child_by_name(obj, "BPCR");
    state->u.f4.reg.awcr = cm_object_get_child_by_name(obj, "AWCR");
    state->u.f4.reg.twcr = cm_object_get_child_by_name(obj, "TWCR");
    state->u.f4.reg.gcr = cm_object_get_child_by_name(obj, "GCR");
    state->u.f4.reg.srcr = cm_object_get_child_by_name(obj, "SRCR");
    state->u.f4.reg.bccr = cm_object_get_child_by_name(obj, "BCCR");
    state->u.f4.reg.ier = cm_object_get_child_by_name(obj, "IER");
    state->u.f4.reg.isr = cm_object_get_child_by_name(obj, "ISR");
    state->u.f4.reg.icr = cm_object_get_child_by_name(obj, "ICR");
    state->u.f4.reg.lipcr = cm_object_get_child_by_name(obj, "LIPCR");
    state->u.f4.reg.cpsr = cm_object_get_child_by_name(obj, "CPSR");
    state->u.f4.reg.cdsr = cm_object_get_child_by_name(obj, "CDSR");
    state->u.f4.reg.l1cr = cm_object_get_child_by_name(obj, "L1CR");
    state->u.f4.reg.l1whpcr = cm_object_get_child_by_name(obj, "L1WHPCR");
    state->u.f4.reg.l1wvpcr = cm_object_get_child_by_name(obj, "L1WVPCR");
    state->u.f4.reg.l1ckcr = cm_object_get_child_by_name(obj, "L1CKCR");
    state->u.f4.reg.l1pfcr = cm_object_get_child_by_name(obj, "L1PFCR");
    state->u.f4.reg.l1cacr = cm_object_get_child_by_name(obj, "L1CACR");
    state->u.f4.reg.l1dccr = cm_object_get_child_by_name(obj, "L1DCCR");
    state->u.f4.reg.l1bfcr = cm_object_get_child_by_name(obj, "L1BFCR");
    state->u.f4.reg.l1cfbar = cm_object_get_child_by_name(obj, "L1CFBAR");
    state->u.f4.reg.l1cfblr = cm_object_get_child_by_name(obj, "L1CFBLR");
    state->u.f4.reg.l1cfblnr = cm_object_get_child_by_name(obj, "L1CFBLNR");
    state->u.f4.reg.l1clutwr = cm_object_get_child_by_name(obj, "L1CLUTWR");
    state->u.f4.reg.l2cr = cm_object_get_child_by_name(obj, "L2CR");
    state->u.f4.reg.l2whpcr = cm_object_get_child_by_name(obj, "L2WHPCR");
    state->u.f4.reg.l2wvpcr = cm_object_get_child_by_name(obj, "L2WVPCR");
    state->u.f4.reg.l2ckcr = cm_object_get_child_by_name(obj, "L2CKCR");
    state->u.f4.reg.l2pfcr = cm_object_get_child_by_name(obj, "L2PFCR");
    state->u.f4.reg.l2cacr = cm_object_get_child_by_name(obj, "L2CACR");
    state->u.f4.reg.l2dccr = cm_object_get_child_by_name(obj, "L2DCCR");
    state->u.f4.reg.l2bfcr = cm_object_get_child_by_name(obj, "L2BFCR");
    state->u.f4.reg.l2cfbar = cm_object_get_child_by_name(obj, "L2CFBAR");
    state->u.f4.reg.l2cfblr = cm_object_get_child_by_name(obj, "L2CFBLR");
    state->u.f4.reg.l2cfblnr = cm_object_get_child_by_name(obj, "L2CFBLNR");
    state->u.f4.reg.l2clutwr = cm_object_get_child_by_name(obj, "L2CLUTWR");
    
    
    // SSCR bitfields.
    state->u.f4.fld.sscr.vsh = cm_object_get_child_by_name(state->u.f4.reg.sscr, "VSH"); 
    state->u.f4.fld.sscr.hsw = cm_object_get_child_by_name(state->u.f4.reg.sscr, "HSW");  
    
    // BPCR bitfields.
    state->u.f4.fld.bpcr.avbp = cm_object_get_child_by_name(state->u.f4.reg.bpcr, "AVBP"); 
    state->u.f4.fld.bpcr.ahbp = cm_object_get_child_by_name(state->u.f4.reg.bpcr, "AHBP");  
    
    // AWCR bitfields.
    state->u.f4.fld.awcr.aah = cm_object_get_child_by_name(state->u.f4.reg.awcr, "AAH"); 
    state->u.f4.fld.awcr.aaw = cm_object_get_child_by_name(state->u.f4.reg.awcr, "AAW");  
    
    // TWCR bitfields.
    state->u.f4.fld.twcr.totalh = cm_object_get_child_by_name(state->u.f4.reg.twcr, "TOTALH"); 
    state->u.f4.fld.twcr.totalw = cm_object_get_child_by_name(state->u.f4.reg.twcr, "TOTALW");  
    
    // GCR bitfields.
    state->u.f4.fld.gcr.ltdcen = cm_object_get_child_by_name(state->u.f4.reg.gcr, "LTDCEN"); 
    state->u.f4.fld.gcr.dbw = cm_object_get_child_by_name(state->u.f4.reg.gcr, "DBW"); 
    state->u.f4.fld.gcr.dgw = cm_object_get_child_by_name(state->u.f4.reg.gcr, "DGW"); 
    state->u.f4.fld.gcr.drw = cm_object_get_child_by_name(state->u.f4.reg.gcr, "DRW"); 
    state->u.f4.fld.gcr.den = cm_object_get_child_by_name(state->u.f4.reg.gcr, "DEN"); 
    state->u.f4.fld.gcr.pcpol = cm_object_get_child_by_name(state->u.f4.reg.gcr, "PCPOL"); 
    state->u.f4.fld.gcr.depol = cm_object_get_child_by_name(state->u.f4.reg.gcr, "DEPOL"); 
    state->u.f4.fld.gcr.vspol = cm_object_get_child_by_name(state->u.f4.reg.gcr, "VSPOL"); 
    state->u.f4.fld.gcr.hspol = cm_object_get_child_by_name(state->u.f4.reg.gcr, "HSPOL");  
    
    // SRCR bitfields.
    state->u.f4.fld.srcr.imr = cm_object_get_child_by_name(state->u.f4.reg.srcr, "IMR"); 
    state->u.f4.fld.srcr.vbr = cm_object_get_child_by_name(state->u.f4.reg.srcr, "VBR");  
    
    // BCCR bitfields.
    state->u.f4.fld.bccr.bc = cm_object_get_child_by_name(state->u.f4.reg.bccr, "BC");  
    
    // IER bitfields.
    state->u.f4.fld.ier.lie = cm_object_get_child_by_name(state->u.f4.reg.ier, "LIE"); 
    state->u.f4.fld.ier.fuie = cm_object_get_child_by_name(state->u.f4.reg.ier, "FUIE"); 
    state->u.f4.fld.ier.terrie = cm_object_get_child_by_name(state->u.f4.reg.ier, "TERRIE"); 
    state->u.f4.fld.ier.rrie = cm_object_get_child_by_name(state->u.f4.reg.ier, "RRIE");  
    
    // ISR bitfields.
    state->u.f4.fld.isr.lif = cm_object_get_child_by_name(state->u.f4.reg.isr, "LIF"); 
    state->u.f4.fld.isr.fuif = cm_object_get_child_by_name(state->u.f4.reg.isr, "FUIF"); 
    state->u.f4.fld.isr.terrif = cm_object_get_child_by_name(state->u.f4.reg.isr, "TERRIF"); 
    state->u.f4.fld.isr.rrif = cm_object_get_child_by_name(state->u.f4.reg.isr, "RRIF");  
    
    // ICR bitfields.
    state->u.f4.fld.icr.clif = cm_object_get_child_by_name(state->u.f4.reg.icr, "CLIF"); 
    state->u.f4.fld.icr.cfuif = cm_object_get_child_by_name(state->u.f4.reg.icr, "CFUIF"); 
    state->u.f4.fld.icr.cterrif = cm_object_get_child_by_name(state->u.f4.reg.icr, "CTERRIF"); 
    state->u.f4.fld.icr.crrif = cm_object_get_child_by_name(state->u.f4.reg.icr, "CRRIF");  
    
    // LIPCR bitfields.
    state->u.f4.fld.lipcr.lipos = cm_object_get_child_by_name(state->u.f4.reg.lipcr, "LIPOS");  
    
    // CPSR bitfields.
    state->u.f4.fld.cpsr.cypos = cm_object_get_child_by_name(state->u.f4.reg.cpsr, "CYPOS"); 
    state->u.f4.fld.cpsr.cxpos = cm_object_get_child_by_name(state->u.f4.reg.cpsr, "CXPOS");  
    
    // CDSR bitfields.
    state->u.f4.fld.cdsr.vdes = cm_object_get_child_by_name(state->u.f4.reg.cdsr, "VDES"); 
    state->u.f4.fld.cdsr.hdes = cm_object_get_child_by_name(state->u.f4.reg.cdsr, "HDES"); 
    state->u.f4.fld.cdsr.vsyncs = cm_object_get_child_by_name(state->u.f4.reg.cdsr, "VSYNCS"); 
    state->u.f4.fld.cdsr.hsyncs = cm_object_get_child_by_name(state->u.f4.reg.cdsr, "HSYNCS");  
    
    // L1CR bitfields.
    state->u.f4.fld.l1cr.len = cm_object_get_child_by_name(state->u.f4.reg.l1cr, "LEN"); 
    state->u.f4.fld.l1cr.colken = cm_object_get_child_by_name(state->u.f4.reg.l1cr, "COLKEN"); 
    state->u.f4.fld.l1cr.cluten = cm_object_get_child_by_name(state->u.f4.reg.l1cr, "CLUTEN");  
    
    // L1WHPCR bitfields.
    state->u.f4.fld.l1whpcr.whstpos = cm_object_get_child_by_name(state->u.f4.reg.l1whpcr, "WHSTPOS"); 
    state->u.f4.fld.l1whpcr.whsppos = cm_object_get_child_by_name(state->u.f4.reg.l1whpcr, "WHSPPOS");  
    
    // L1WVPCR bitfields.
    state->u.f4.fld.l1wvpcr.wvstpos = cm_object_get_child_by_name(state->u.f4.reg.l1wvpcr, "WVSTPOS"); 
    state->u.f4.fld.l1wvpcr.wvsppos = cm_object_get_child_by_name(state->u.f4.reg.l1wvpcr, "WVSPPOS");  
    
    // L1CKCR bitfields.
    state->u.f4.fld.l1ckcr.ckblue = cm_object_get_child_by_name(state->u.f4.reg.l1ckcr, "CKBLUE"); 
    state->u.f4.fld.l1ckcr.ckgreen = cm_object_get_child_by_name(state->u.f4.reg.l1ckcr, "CKGREEN"); 
    state->u.f4.fld.l1ckcr.ckred = cm_object_get_child_by_name(state->u.f4.reg.l1ckcr, "CKRED");  
    
    // L1PFCR bitfields.
    state->u.f4.fld.l1pfcr.pf = cm_object_get_child_by_name(state->u.f4.reg.l1pfcr, "PF");  
    
    // L1CACR bitfields.
    state->u.f4.fld.l1cacr.consta = cm_object_get_child_by_name(state->u.f4.reg.l1cacr, "CONSTA");  
    
    // L1DCCR bitfields.
    state->u.f4.fld.l1dccr.dcblue = cm_object_get_child_by_name(state->u.f4.reg.l1dccr, "DCBLUE"); 
    state->u.f4.fld.l1dccr.dcgreen = cm_object_get_child_by_name(state->u.f4.reg.l1dccr, "DCGREEN"); 
    state->u.f4.fld.l1dccr.dcred = cm_object_get_child_by_name(state->u.f4.reg.l1dccr, "DCRED"); 
    state->u.f4.fld.l1dccr.dcalpha = cm_object_get_child_by_name(state->u.f4.reg.l1dccr, "DCALPHA");  
    
    // L1BFCR bitfields.
    state->u.f4.fld.l1bfcr.bf2 = cm_object_get_child_by_name(state->u.f4.reg.l1bfcr, "BF2"); 
    state->u.f4.fld.l1bfcr.bf1 = cm_object_get_child_by_name(state->u.f4.reg.l1bfcr, "BF1");  
    
    // L1CFBAR bitfields.
    state->u.f4.fld.l1cfbar.cfbadd = cm_object_get_child_by_name(state->u.f4.reg.l1cfbar, "CFBADD");  
    
    // L1CFBLR bitfields.
    state->u.f4.fld.l1cfblr.cfbll = cm_object_get_child_by_name(state->u.f4.reg.l1cfblr, "CFBLL"); 
    state->u.f4.fld.l1cfblr.cfbp = cm_object_get_child_by_name(state->u.f4.reg.l1cfblr, "CFBP");  
    
    // L1CFBLNR bitfields.
    state->u.f4.fld.l1cfblnr.cfblnbr = cm_object_get_child_by_name(state->u.f4.reg.l1cfblnr, "CFBLNBR");  
    
    // L1CLUTWR bitfields.
    state->u.f4.fld.l1clutwr.blue = cm_object_get_child_by_name(state->u.f4.reg.l1clutwr, "BLUE"); 
    state->u.f4.fld.l1clutwr.green = cm_object_get_child_by_name(state->u.f4.reg.l1clutwr, "GREEN"); 
    state->u.f4.fld.l1clutwr.red = cm_object_get_child_by_name(state->u.f4.reg.l1clutwr, "RED"); 
    state->u.f4.fld.l1clutwr.clutadd = cm_object_get_child_by_name(state->u.f4.reg.l1clutwr, "CLUTADD");  
    
    // L2CR bitfields.
    state->u.f4.fld.l2cr.len = cm_object_get_child_by_name(state->u.f4.reg.l2cr, "LEN"); 
    state->u.f4.fld.l2cr.colken = cm_object_get_child_by_name(state->u.f4.reg.l2cr, "COLKEN"); 
    state->u.f4.fld.l2cr.cluten = cm_object_get_child_by_name(state->u.f4.reg.l2cr, "CLUTEN");  
    
    // L2WHPCR bitfields.
    state->u.f4.fld.l2whpcr.whstpos = cm_object_get_child_by_name(state->u.f4.reg.l2whpcr, "WHSTPOS"); 
    state->u.f4.fld.l2whpcr.whsppos = cm_object_get_child_by_name(state->u.f4.reg.l2whpcr, "WHSPPOS");  
    
    // L2WVPCR bitfields.
    state->u.f4.fld.l2wvpcr.wvstpos = cm_object_get_child_by_name(state->u.f4.reg.l2wvpcr, "WVSTPOS"); 
    state->u.f4.fld.l2wvpcr.wvsppos = cm_object_get_child_by_name(state->u.f4.reg.l2wvpcr, "WVSPPOS");  
    
    // L2CKCR bitfields.
    state->u.f4.fld.l2ckcr.ckblue = cm_object_get_child_by_name(state->u.f4.reg.l2ckcr, "CKBLUE"); 
    state->u.f4.fld.l2ckcr.ckgreen = cm_object_get_child_by_name(state->u.f4.reg.l2ckcr, "CKGREEN"); 
    state->u.f4.fld.l2ckcr.ckred = cm_object_get_child_by_name(state->u.f4.reg.l2ckcr, "CKRED");  
    
    // L2PFCR bitfields.
    state->u.f4.fld.l2pfcr.pf = cm_object_get_child_by_name(state->u.f4.reg.l2pfcr, "PF");  
    
    // L2CACR bitfields.
    state->u.f4.fld.l2cacr.consta = cm_object_get_child_by_name(state->u.f4.reg.l2cacr, "CONSTA");  
    
    // L2DCCR bitfields.
    state->u.f4.fld.l2dccr.dcblue = cm_object_get_child_by_name(state->u.f4.reg.l2dccr, "DCBLUE"); 
    state->u.f4.fld.l2dccr.dcgreen = cm_object_get_child_by_name(state->u.f4.reg.l2dccr, "DCGREEN"); 
    state->u.f4.fld.l2dccr.dcred = cm_object_get_child_by_name(state->u.f4.reg.l2dccr, "DCRED"); 
    state->u.f4.fld.l2dccr.dcalpha = cm_object_get_child_by_name(state->u.f4.reg.l2dccr, "DCALPHA");  
    
    // L2BFCR bitfields.
    state->u.f4.fld.l2bfcr.bf2 = cm_object_get_child_by_name(state->u.f4.reg.l2bfcr, "BF2"); 
    state->u.f4.fld.l2bfcr.bf1 = cm_object_get_child_by_name(state->u.f4.reg.l2bfcr, "BF1");  
    
    // L2CFBAR bitfields.
    state->u.f4.fld.l2cfbar.cfbadd = cm_object_get_child_by_name(state->u.f4.reg.l2cfbar, "CFBADD");  
    
    // L2CFBLR bitfields.
    state->u.f4.fld.l2cfblr.cfbll = cm_object_get_child_by_name(state->u.f4.reg.l2cfblr, "CFBLL"); 
    state->u.f4.fld.l2cfblr.cfbp = cm_object_get_child_by_name(state->u.f4.reg.l2cfblr, "CFBP");  
    
    // L2CFBLNR bitfields.
    state->u.f4.fld.l2cfblnr.cfblnbr = cm_object_get_child_by_name(state->u.f4.reg.l2cfblnr, "CFBLNBR");  
    
    // L2CLUTWR bitfields.
    state->u.f4.fld.l2clutwr.blue = cm_object_get_child_by_name(state->u.f4.reg.l2clutwr, "BLUE"); 
    state->u.f4.fld.l2clutwr.green = cm_object_get_child_by_name(state->u.f4.reg.l2clutwr, "GREEN"); 
    state->u.f4.fld.l2clutwr.red = cm_object_get_child_by_name(state->u.f4.reg.l2clutwr, "RED"); 
    state->u.f4.fld.l2clutwr.clutadd = cm_object_get_child_by_name(state->u.f4.reg.l2clutwr, "CLUTADD");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_ltdc_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32LTDCState *state = STM32_LTDC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_ltdc_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32LTDCState *state = STM32_LTDC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_ltdc_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32LTDCState *state = STM32_LTDC_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_ltdc_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32LTDCState *state = STM32_LTDC_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_ltdc_is_enabled(Object *obj)
{
    STM32LTDCState *state = STM32_LTDC_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_ltdc_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32LTDCState *state = STM32_LTDC_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_ltdc_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_LTDC)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32LTDCState *state = STM32_LTDC_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "LTDC";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_429x ) {

            stm32f429x_ltdc_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_ltdc_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_ltdc_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_ltdc_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_ltdc_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/LTDCEN");


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

static void stm32_ltdc_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_LTDC);
}

static void stm32_ltdc_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_ltdc_reset_callback;
    dc->realize = stm32_ltdc_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_ltdc_is_enabled;
}

static const TypeInfo stm32_ltdc_type_info = {
    .name = TYPE_STM32_LTDC,
    .parent = TYPE_STM32_LTDC_PARENT,
    .instance_init = stm32_ltdc_instance_init_callback,
    .instance_size = sizeof(STM32LTDCState),
    .class_init = stm32_ltdc_class_init_callback,
    .class_size = sizeof(STM32LTDCClass) };

static void stm32_ltdc_register_types(void)
{
    type_register_static(&stm32_ltdc_type_info);
}

type_init(stm32_ltdc_register_types);

// ----------------------------------------------------------------------------
