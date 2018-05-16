/*
 * STM32 - TIM14 (General-purpose-timers) emulation.
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

#include <hw/cortexm/stm32/tim14.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_tim14_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32TIM14State *state = STM32_TIM14_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f0.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
    state->u.f0.reg.dier = cm_object_get_child_by_name(obj, "DIER");
    state->u.f0.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->u.f0.reg.egr = cm_object_get_child_by_name(obj, "EGR");
    state->u.f0.reg.ccmr1_output = cm_object_get_child_by_name(obj, "CCMR1_Output");
    state->u.f0.reg.ccmr1_input = cm_object_get_child_by_name(obj, "CCMR1_Input");
    state->u.f0.reg.ccer = cm_object_get_child_by_name(obj, "CCER");
    state->u.f0.reg.cnt = cm_object_get_child_by_name(obj, "CNT");
    state->u.f0.reg.psc = cm_object_get_child_by_name(obj, "PSC");
    state->u.f0.reg.arr = cm_object_get_child_by_name(obj, "ARR");
    state->u.f0.reg.ccr1 = cm_object_get_child_by_name(obj, "CCR1");
    state->u.f0.reg.or_ = cm_object_get_child_by_name(obj, "OR");
    
    
    // CR1 bitfields.
    state->u.f0.fld.cr1.cen = cm_object_get_child_by_name(state->u.f0.reg.cr1, "CEN"); 
    state->u.f0.fld.cr1.udis = cm_object_get_child_by_name(state->u.f0.reg.cr1, "UDIS"); 
    state->u.f0.fld.cr1.urs = cm_object_get_child_by_name(state->u.f0.reg.cr1, "URS"); 
    state->u.f0.fld.cr1.arpe = cm_object_get_child_by_name(state->u.f0.reg.cr1, "ARPE"); 
    state->u.f0.fld.cr1.ckd = cm_object_get_child_by_name(state->u.f0.reg.cr1, "CKD");  
    
    // DIER bitfields.
    state->u.f0.fld.dier.uie = cm_object_get_child_by_name(state->u.f0.reg.dier, "UIE"); 
    state->u.f0.fld.dier.cc1ie = cm_object_get_child_by_name(state->u.f0.reg.dier, "CC1IE");  
    
    // SR bitfields.
    state->u.f0.fld.sr.uif = cm_object_get_child_by_name(state->u.f0.reg.sr, "UIF"); 
    state->u.f0.fld.sr.cc1if = cm_object_get_child_by_name(state->u.f0.reg.sr, "CC1IF"); 
    state->u.f0.fld.sr.cc1of = cm_object_get_child_by_name(state->u.f0.reg.sr, "CC1OF");  
    
    // EGR bitfields.
    state->u.f0.fld.egr.ug = cm_object_get_child_by_name(state->u.f0.reg.egr, "UG"); 
    state->u.f0.fld.egr.cc1g = cm_object_get_child_by_name(state->u.f0.reg.egr, "CC1G");  
    
    // CCMR1_Output bitfields.
    state->u.f0.fld.ccmr1_output.cc1s = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_output, "CC1S"); 
    state->u.f0.fld.ccmr1_output.oc1fe = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_output, "OC1FE"); 
    state->u.f0.fld.ccmr1_output.oc1pe = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_output, "OC1PE"); 
    state->u.f0.fld.ccmr1_output.oc1m = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_output, "OC1M");  
    
    // CCMR1_Input bitfields.
    state->u.f0.fld.ccmr1_input.cc1s = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_input, "CC1S"); 
    state->u.f0.fld.ccmr1_input.ic1psc = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_input, "IC1PSC"); 
    state->u.f0.fld.ccmr1_input.ic1f = cm_object_get_child_by_name(state->u.f0.reg.ccmr1_input, "IC1F");  
    
    // CCER bitfields.
    state->u.f0.fld.ccer.cc1e = cm_object_get_child_by_name(state->u.f0.reg.ccer, "CC1E"); 
    state->u.f0.fld.ccer.cc1p = cm_object_get_child_by_name(state->u.f0.reg.ccer, "CC1P"); 
    state->u.f0.fld.ccer.cc1np = cm_object_get_child_by_name(state->u.f0.reg.ccer, "CC1NP");  
    
    // CNT bitfields.
    state->u.f0.fld.cnt.cnt = cm_object_get_child_by_name(state->u.f0.reg.cnt, "CNT");  
    
    // PSC bitfields.
    state->u.f0.fld.psc.psc = cm_object_get_child_by_name(state->u.f0.reg.psc, "PSC");  
    
    // ARR bitfields.
    state->u.f0.fld.arr.arr = cm_object_get_child_by_name(state->u.f0.reg.arr, "ARR");  
    
    // CCR1 bitfields.
    state->u.f0.fld.ccr1.ccr1 = cm_object_get_child_by_name(state->u.f0.reg.ccr1, "CCR1");  
    
    // OR bitfields.
    state->u.f0.fld.or_.rmp = cm_object_get_child_by_name(state->u.f0.reg.or_, "RMP");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_tim14_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32TIM14State *state = STM32_TIM14_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_tim14_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32TIM14State *state = STM32_TIM14_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_tim14_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32TIM14State *state = STM32_TIM14_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_tim14_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32TIM14State *state = STM32_TIM14_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_tim14_is_enabled(Object *obj)
{
    STM32TIM14State *state = STM32_TIM14_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_tim14_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32TIM14State *state = STM32_TIM14_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_tim14_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_TIM14)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32TIM14State *state = STM32_TIM14_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "TIM14";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x1 ) {

            stm32f0x1_tim14_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_tim14_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f0.reg.xxx, &stm32_tim14_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_tim14_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f0.reg.xxx, &stm32_tim14_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/TIM14EN");


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

static void stm32_tim14_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_TIM14);
}

static void stm32_tim14_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_tim14_reset_callback;
    dc->realize = stm32_tim14_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_tim14_is_enabled;
}

static const TypeInfo stm32_tim14_type_info = {
    .name = TYPE_STM32_TIM14,
    .parent = TYPE_STM32_TIM14_PARENT,
    .instance_init = stm32_tim14_instance_init_callback,
    .instance_size = sizeof(STM32TIM14State),
    .class_init = stm32_tim14_class_init_callback,
    .class_size = sizeof(STM32TIM14Class) };

static void stm32_tim14_register_types(void)
{
    type_register_static(&stm32_tim14_type_info);
}

type_init(stm32_tim14_register_types);

// ----------------------------------------------------------------------------
