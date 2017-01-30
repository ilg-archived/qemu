/*
 * STM32- ADC(Analog-to-digital converter) emulation.
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
static void stm32f0x2_adc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32ADCState *state = STM32_ADC_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
state->u.f0.reg.isr= cm_object_get_child_by_name(obj, "ISR");
state->u.f0.reg.ier= cm_object_get_child_by_name(obj, "IER");
state->u.f0.reg.cr= cm_object_get_child_by_name(obj, "CR");
state->u.f0.reg.cfgr1= cm_object_get_child_by_name(obj, "CFGR1");
state->u.f0.reg.cfgr2= cm_object_get_child_by_name(obj, "CFGR2");
state->u.f0.reg.smpr= cm_object_get_child_by_name(obj, "SMPR");
state->u.f0.reg.tr= cm_object_get_child_by_name(obj, "TR");
state->u.f0.reg.chselr= cm_object_get_child_by_name(obj, "CHSELR");
state->u.f0.reg.dr= cm_object_get_child_by_name(obj, "DR");
state->u.f0.reg.ccr= cm_object_get_child_by_name(obj, "CCR");
// ISRbitfields.
state->u.f0.fld.isr.adrdy= cm_object_get_child_by_name(state->u.f0.reg.isr, "ADRDY"); 
state->u.f0.fld.isr.eosmp= cm_object_get_child_by_name(state->u.f0.reg.isr, "EOSMP"); 
state->u.f0.fld.isr.eoc= cm_object_get_child_by_name(state->u.f0.reg.isr, "EOC"); 
state->u.f0.fld.isr.eos= cm_object_get_child_by_name(state->u.f0.reg.isr, "EOS"); 
state->u.f0.fld.isr.ovr= cm_object_get_child_by_name(state->u.f0.reg.isr, "OVR"); 
state->u.f0.fld.isr.awd= cm_object_get_child_by_name(state->u.f0.reg.isr, "AWD"); 
// IERbitfields.
state->u.f0.fld.ier.adrdyie= cm_object_get_child_by_name(state->u.f0.reg.ier, "ADRDYIE"); 
state->u.f0.fld.ier.eosmpie= cm_object_get_child_by_name(state->u.f0.reg.ier, "EOSMPIE"); 
state->u.f0.fld.ier.eocie= cm_object_get_child_by_name(state->u.f0.reg.ier, "EOCIE"); 
state->u.f0.fld.ier.eosie= cm_object_get_child_by_name(state->u.f0.reg.ier, "EOSIE"); 
state->u.f0.fld.ier.ovrie= cm_object_get_child_by_name(state->u.f0.reg.ier, "OVRIE"); 
state->u.f0.fld.ier.awdie= cm_object_get_child_by_name(state->u.f0.reg.ier, "AWDIE"); 
// CRbitfields.
state->u.f0.fld.cr.aden= cm_object_get_child_by_name(state->u.f0.reg.cr, "ADEN"); 
state->u.f0.fld.cr.addis= cm_object_get_child_by_name(state->u.f0.reg.cr, "ADDIS"); 
state->u.f0.fld.cr.adstart= cm_object_get_child_by_name(state->u.f0.reg.cr, "ADSTART"); 
state->u.f0.fld.cr.adstp= cm_object_get_child_by_name(state->u.f0.reg.cr, "ADSTP"); 
state->u.f0.fld.cr.adcal= cm_object_get_child_by_name(state->u.f0.reg.cr, "ADCAL"); 
// CFGR1bitfields.
state->u.f0.fld.cfgr1.dmaen= cm_object_get_child_by_name(state->u.f0.reg.cfgr1, "DMAEN"); 
state->u.f0.fld.cfgr1.dmacfg= cm_object_get_child_by_name(state->u.f0.reg.cfgr1, "DMACFG"); 
state->u.f0.fld.cfgr1.scandir= cm_object_get_child_by_name(state->u.f0.reg.cfgr1, "SCANDIR"); 
state->u.f0.fld.cfgr1.res= cm_object_get_child_by_name(state->u.f0.reg.cfgr1, "RES"); 
state->u.f0.fld.cfgr1.align= cm_object_get_child_by_name(state->u.f0.reg.cfgr1, "ALIGN"); 
state->u.f0.fld.cfgr1.extsel= cm_object_get_child_by_name(state->u.f0.reg.cfgr1, "EXTSEL"); 
state->u.f0.fld.cfgr1.exten= cm_object_get_child_by_name(state->u.f0.reg.cfgr1, "EXTEN"); 
state->u.f0.fld.cfgr1.ovrmod= cm_object_get_child_by_name(state->u.f0.reg.cfgr1, "OVRMOD"); 
state->u.f0.fld.cfgr1.cont= cm_object_get_child_by_name(state->u.f0.reg.cfgr1, "CONT"); 
state->u.f0.fld.cfgr1.autdly= cm_object_get_child_by_name(state->u.f0.reg.cfgr1, "AUTDLY"); 
state->u.f0.fld.cfgr1.autoff= cm_object_get_child_by_name(state->u.f0.reg.cfgr1, "AUTOFF"); 
state->u.f0.fld.cfgr1.discen= cm_object_get_child_by_name(state->u.f0.reg.cfgr1, "DISCEN"); 
state->u.f0.fld.cfgr1.awdsgl= cm_object_get_child_by_name(state->u.f0.reg.cfgr1, "AWDSGL"); 
state->u.f0.fld.cfgr1.awden= cm_object_get_child_by_name(state->u.f0.reg.cfgr1, "AWDEN"); 
state->u.f0.fld.cfgr1.awdch= cm_object_get_child_by_name(state->u.f0.reg.cfgr1, "AWDCH"); 
// CFGR2bitfields.
state->u.f0.fld.cfgr2.jitoff_d2= cm_object_get_child_by_name(state->u.f0.reg.cfgr2, "JITOFF_D2"); 
state->u.f0.fld.cfgr2.jitoff_d4= cm_object_get_child_by_name(state->u.f0.reg.cfgr2, "JITOFF_D4"); 
// SMPRbitfields.
state->u.f0.fld.smpr.smpr= cm_object_get_child_by_name(state->u.f0.reg.smpr, "SMPR"); 
// TRbitfields.
state->u.f0.fld.tr.lt= cm_object_get_child_by_name(state->u.f0.reg.tr, "LT"); 
state->u.f0.fld.tr.ht= cm_object_get_child_by_name(state->u.f0.reg.tr, "HT"); 
// CHSELRbitfields.
state->u.f0.fld.chselr.chsel0= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL0"); 
state->u.f0.fld.chselr.chsel1= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL1"); 
state->u.f0.fld.chselr.chsel2= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL2"); 
state->u.f0.fld.chselr.chsel3= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL3"); 
state->u.f0.fld.chselr.chsel4= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL4"); 
state->u.f0.fld.chselr.chsel5= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL5"); 
state->u.f0.fld.chselr.chsel6= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL6"); 
state->u.f0.fld.chselr.chsel7= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL7"); 
state->u.f0.fld.chselr.chsel8= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL8"); 
state->u.f0.fld.chselr.chsel9= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL9"); 
state->u.f0.fld.chselr.chsel10= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL10"); 
state->u.f0.fld.chselr.chsel11= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL11"); 
state->u.f0.fld.chselr.chsel12= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL12"); 
state->u.f0.fld.chselr.chsel13= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL13"); 
state->u.f0.fld.chselr.chsel14= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL14"); 
state->u.f0.fld.chselr.chsel15= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL15"); 
state->u.f0.fld.chselr.chsel16= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL16"); 
state->u.f0.fld.chselr.chsel17= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL17"); 
state->u.f0.fld.chselr.chsel18= cm_object_get_child_by_name(state->u.f0.reg.chselr, "CHSEL18"); 
// DRbitfields.
state->u.f0.fld.dr.data= cm_object_get_child_by_name(state->u.f0.reg.dr, "DATA"); 
// CCRbitfields.
state->u.f0.fld.ccr.vrefen= cm_object_get_child_by_name(state->u.f0.reg.ccr, "VREFEN"); 
state->u.f0.fld.ccr.tsen= cm_object_get_child_by_name(state->u.f0.reg.ccr, "TSEN"); 
state->u.f0.fld.ccr.vbaten= cm_object_get_child_by_name(state->u.f0.reg.ccr, "VBATEN"); 
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
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x2) {

            stm32f0x2_adc_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_adc_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f0.reg.xxx, &stm32_adc_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_adc_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f0.reg.xxx, &stm32_adc_xxx_post_write_callback);

            // TODO: add interrupts.

// TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/ADCEN");
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
