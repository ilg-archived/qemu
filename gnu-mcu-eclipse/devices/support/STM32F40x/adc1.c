/*
 * STM32 - ADC (Analog-to-digital converter) emulation.
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

#include <hw/cortexm/stm32/adc.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f40x_adc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32ADCState *state = STM32_ADC_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->u.f4.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
    state->u.f4.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
    state->u.f4.reg.smpr1 = cm_object_get_child_by_name(obj, "SMPR1");
    state->u.f4.reg.smpr2 = cm_object_get_child_by_name(obj, "SMPR2");
    state->u.f4.reg.jofr1 = cm_object_get_child_by_name(obj, "JOFR1");
    state->u.f4.reg.jofr2 = cm_object_get_child_by_name(obj, "JOFR2");
    state->u.f4.reg.jofr3 = cm_object_get_child_by_name(obj, "JOFR3");
    state->u.f4.reg.jofr4 = cm_object_get_child_by_name(obj, "JOFR4");
    state->u.f4.reg.htr = cm_object_get_child_by_name(obj, "HTR");
    state->u.f4.reg.ltr = cm_object_get_child_by_name(obj, "LTR");
    state->u.f4.reg.sqr1 = cm_object_get_child_by_name(obj, "SQR1");
    state->u.f4.reg.sqr2 = cm_object_get_child_by_name(obj, "SQR2");
    state->u.f4.reg.sqr3 = cm_object_get_child_by_name(obj, "SQR3");
    state->u.f4.reg.jsqr = cm_object_get_child_by_name(obj, "JSQR");
    state->u.f4.reg.jdr1 = cm_object_get_child_by_name(obj, "JDR1");
    state->u.f4.reg.jdr2 = cm_object_get_child_by_name(obj, "JDR2");
    state->u.f4.reg.jdr3 = cm_object_get_child_by_name(obj, "JDR3");
    state->u.f4.reg.jdr4 = cm_object_get_child_by_name(obj, "JDR4");
    state->u.f4.reg.dr = cm_object_get_child_by_name(obj, "DR");
    
    
    // SR bitfields.
    state->u.f4.fld.sr.awd = cm_object_get_child_by_name(state->u.f4.reg.sr, "AWD"); 
    state->u.f4.fld.sr.eoc = cm_object_get_child_by_name(state->u.f4.reg.sr, "EOC"); 
    state->u.f4.fld.sr.jeoc = cm_object_get_child_by_name(state->u.f4.reg.sr, "JEOC"); 
    state->u.f4.fld.sr.jstrt = cm_object_get_child_by_name(state->u.f4.reg.sr, "JSTRT"); 
    state->u.f4.fld.sr.strt = cm_object_get_child_by_name(state->u.f4.reg.sr, "STRT"); 
    state->u.f4.fld.sr.ovr = cm_object_get_child_by_name(state->u.f4.reg.sr, "OVR");  
    
    // CR1 bitfields.
    state->u.f4.fld.cr1.awdch = cm_object_get_child_by_name(state->u.f4.reg.cr1, "AWDCH"); 
    state->u.f4.fld.cr1.eocie = cm_object_get_child_by_name(state->u.f4.reg.cr1, "EOCIE"); 
    state->u.f4.fld.cr1.awdie = cm_object_get_child_by_name(state->u.f4.reg.cr1, "AWDIE"); 
    state->u.f4.fld.cr1.jeocie = cm_object_get_child_by_name(state->u.f4.reg.cr1, "JEOCIE"); 
    state->u.f4.fld.cr1.scan = cm_object_get_child_by_name(state->u.f4.reg.cr1, "SCAN"); 
    state->u.f4.fld.cr1.awdsgl = cm_object_get_child_by_name(state->u.f4.reg.cr1, "AWDSGL"); 
    state->u.f4.fld.cr1.jauto = cm_object_get_child_by_name(state->u.f4.reg.cr1, "JAUTO"); 
    state->u.f4.fld.cr1.discen = cm_object_get_child_by_name(state->u.f4.reg.cr1, "DISCEN"); 
    state->u.f4.fld.cr1.jdiscen = cm_object_get_child_by_name(state->u.f4.reg.cr1, "JDISCEN"); 
    state->u.f4.fld.cr1.discnum = cm_object_get_child_by_name(state->u.f4.reg.cr1, "DISCNUM"); 
    state->u.f4.fld.cr1.jawden = cm_object_get_child_by_name(state->u.f4.reg.cr1, "JAWDEN"); 
    state->u.f4.fld.cr1.awden = cm_object_get_child_by_name(state->u.f4.reg.cr1, "AWDEN"); 
    state->u.f4.fld.cr1.res = cm_object_get_child_by_name(state->u.f4.reg.cr1, "RES"); 
    state->u.f4.fld.cr1.ovrie = cm_object_get_child_by_name(state->u.f4.reg.cr1, "OVRIE");  
    
    // CR2 bitfields.
    state->u.f4.fld.cr2.adon = cm_object_get_child_by_name(state->u.f4.reg.cr2, "ADON"); 
    state->u.f4.fld.cr2.cont = cm_object_get_child_by_name(state->u.f4.reg.cr2, "CONT"); 
    state->u.f4.fld.cr2.dma = cm_object_get_child_by_name(state->u.f4.reg.cr2, "DMA"); 
    state->u.f4.fld.cr2.dds = cm_object_get_child_by_name(state->u.f4.reg.cr2, "DDS"); 
    state->u.f4.fld.cr2.eocs = cm_object_get_child_by_name(state->u.f4.reg.cr2, "EOCS"); 
    state->u.f4.fld.cr2.align = cm_object_get_child_by_name(state->u.f4.reg.cr2, "ALIGN"); 
    state->u.f4.fld.cr2.jextsel = cm_object_get_child_by_name(state->u.f4.reg.cr2, "JEXTSEL"); 
    state->u.f4.fld.cr2.jexten = cm_object_get_child_by_name(state->u.f4.reg.cr2, "JEXTEN"); 
    state->u.f4.fld.cr2.jswstart = cm_object_get_child_by_name(state->u.f4.reg.cr2, "JSWSTART"); 
    state->u.f4.fld.cr2.extsel = cm_object_get_child_by_name(state->u.f4.reg.cr2, "EXTSEL"); 
    state->u.f4.fld.cr2.exten = cm_object_get_child_by_name(state->u.f4.reg.cr2, "EXTEN"); 
    state->u.f4.fld.cr2.swstart = cm_object_get_child_by_name(state->u.f4.reg.cr2, "SWSTART");  
    
    // SMPR1 bitfields.
    state->u.f4.fld.smpr1.smpx_x = cm_object_get_child_by_name(state->u.f4.reg.smpr1, "SMPx_x");  
    
    // SMPR2 bitfields.
    state->u.f4.fld.smpr2.smpx_x = cm_object_get_child_by_name(state->u.f4.reg.smpr2, "SMPx_x");  
    
    // JOFR1 bitfields.
    state->u.f4.fld.jofr1.joffset1 = cm_object_get_child_by_name(state->u.f4.reg.jofr1, "JOFFSET1");  
    
    // JOFR2 bitfields.
    state->u.f4.fld.jofr2.joffset2 = cm_object_get_child_by_name(state->u.f4.reg.jofr2, "JOFFSET2");  
    
    // JOFR3 bitfields.
    state->u.f4.fld.jofr3.joffset3 = cm_object_get_child_by_name(state->u.f4.reg.jofr3, "JOFFSET3");  
    
    // JOFR4 bitfields.
    state->u.f4.fld.jofr4.joffset4 = cm_object_get_child_by_name(state->u.f4.reg.jofr4, "JOFFSET4");  
    
    // HTR bitfields.
    state->u.f4.fld.htr.ht = cm_object_get_child_by_name(state->u.f4.reg.htr, "HT");  
    
    // LTR bitfields.
    state->u.f4.fld.ltr.lt = cm_object_get_child_by_name(state->u.f4.reg.ltr, "LT");  
    
    // SQR1 bitfields.
    state->u.f4.fld.sqr1.sq13 = cm_object_get_child_by_name(state->u.f4.reg.sqr1, "SQ13"); 
    state->u.f4.fld.sqr1.sq14 = cm_object_get_child_by_name(state->u.f4.reg.sqr1, "SQ14"); 
    state->u.f4.fld.sqr1.sq15 = cm_object_get_child_by_name(state->u.f4.reg.sqr1, "SQ15"); 
    state->u.f4.fld.sqr1.sq16 = cm_object_get_child_by_name(state->u.f4.reg.sqr1, "SQ16"); 
    state->u.f4.fld.sqr1.l = cm_object_get_child_by_name(state->u.f4.reg.sqr1, "L");  
    
    // SQR2 bitfields.
    state->u.f4.fld.sqr2.sq7 = cm_object_get_child_by_name(state->u.f4.reg.sqr2, "SQ7"); 
    state->u.f4.fld.sqr2.sq8 = cm_object_get_child_by_name(state->u.f4.reg.sqr2, "SQ8"); 
    state->u.f4.fld.sqr2.sq9 = cm_object_get_child_by_name(state->u.f4.reg.sqr2, "SQ9"); 
    state->u.f4.fld.sqr2.sq10 = cm_object_get_child_by_name(state->u.f4.reg.sqr2, "SQ10"); 
    state->u.f4.fld.sqr2.sq11 = cm_object_get_child_by_name(state->u.f4.reg.sqr2, "SQ11"); 
    state->u.f4.fld.sqr2.sq12 = cm_object_get_child_by_name(state->u.f4.reg.sqr2, "SQ12");  
    
    // SQR3 bitfields.
    state->u.f4.fld.sqr3.sq1 = cm_object_get_child_by_name(state->u.f4.reg.sqr3, "SQ1"); 
    state->u.f4.fld.sqr3.sq2 = cm_object_get_child_by_name(state->u.f4.reg.sqr3, "SQ2"); 
    state->u.f4.fld.sqr3.sq3 = cm_object_get_child_by_name(state->u.f4.reg.sqr3, "SQ3"); 
    state->u.f4.fld.sqr3.sq4 = cm_object_get_child_by_name(state->u.f4.reg.sqr3, "SQ4"); 
    state->u.f4.fld.sqr3.sq5 = cm_object_get_child_by_name(state->u.f4.reg.sqr3, "SQ5"); 
    state->u.f4.fld.sqr3.sq6 = cm_object_get_child_by_name(state->u.f4.reg.sqr3, "SQ6");  
    
    // JSQR bitfields.
    state->u.f4.fld.jsqr.jsq1 = cm_object_get_child_by_name(state->u.f4.reg.jsqr, "JSQ1"); 
    state->u.f4.fld.jsqr.jsq2 = cm_object_get_child_by_name(state->u.f4.reg.jsqr, "JSQ2"); 
    state->u.f4.fld.jsqr.jsq3 = cm_object_get_child_by_name(state->u.f4.reg.jsqr, "JSQ3"); 
    state->u.f4.fld.jsqr.jsq4 = cm_object_get_child_by_name(state->u.f4.reg.jsqr, "JSQ4"); 
    state->u.f4.fld.jsqr.jl = cm_object_get_child_by_name(state->u.f4.reg.jsqr, "JL");  
    
    // JDR1 bitfields.
    state->u.f4.fld.jdr1.jdata = cm_object_get_child_by_name(state->u.f4.reg.jdr1, "JDATA");  
    
    // JDR2 bitfields.
    state->u.f4.fld.jdr2.jdata = cm_object_get_child_by_name(state->u.f4.reg.jdr2, "JDATA");  
    
    // JDR3 bitfields.
    state->u.f4.fld.jdr3.jdata = cm_object_get_child_by_name(state->u.f4.reg.jdr3, "JDATA");  
    
    // JDR4 bitfields.
    state->u.f4.fld.jdr4.jdata = cm_object_get_child_by_name(state->u.f4.reg.jdr4, "JDATA");  
    
    // DR bitfields.
    state->u.f4.fld.dr.data = cm_object_get_child_by_name(state->u.f4.reg.dr, "DATA");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_adc_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32ADCState *state = STM32_ADC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_adc_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32ADCState *state = STM32_ADC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_adc_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32ADCState *state = STM32_ADC_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_adc_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32ADCState *state = STM32_ADC_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_adc_is_enabled(Object *obj)
{
    STM32ADCState *state = STM32_ADC_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_adc_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32ADCState *state = STM32_ADC_STATE(obj);

    // Capabilities are not yet available.

    cm_object_property_add_int(obj, "port-index",
            (const int *) &state->port_index);
    state->port_index = STM32_PORT_ADC_UNDEFINED;

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_adc_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_ADC)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32ADCState *state = STM32_ADC_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "ADC";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_40x ) {

            stm32f40x_adc_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_adc_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_adc_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_adc_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_adc_xxx_post_write_callback);

            // TODO: add interrupts.

           // TODO: remove this if the peripheral is always enabled.
           snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/ADC%dEN",
                1 + state->port_index - STM32_PORT_ADC1);


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

static void stm32_adc_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_ADC);
}

static void stm32_adc_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_adc_reset_callback;
    dc->realize = stm32_adc_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_adc_is_enabled;
}

static const TypeInfo stm32_adc_type_info = {
    .name = TYPE_STM32_ADC,
    .parent = TYPE_STM32_ADC_PARENT,
    .instance_init = stm32_adc_instance_init_callback,
    .instance_size = sizeof(STM32ADCState),
    .class_init = stm32_adc_class_init_callback,
    .class_size = sizeof(STM32ADCClass) };

static void stm32_adc_register_types(void)
{
    type_register_static(&stm32_adc_type_info);
}

type_init(stm32_adc_register_types);

// ----------------------------------------------------------------------------
