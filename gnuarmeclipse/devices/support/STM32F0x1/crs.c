/*
 * STM32 - CRS (Clock recovery system) emulation.
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

#include <hw/cortexm/stm32/crs.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_crs_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32CRSState *state = STM32_CRS_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->u.f0.reg.cfgr = cm_object_get_child_by_name(obj, "CFGR");
    state->u.f0.reg.isr = cm_object_get_child_by_name(obj, "ISR");
    state->u.f0.reg.icr = cm_object_get_child_by_name(obj, "ICR");
    
    
    // CR bitfields.
    state->u.f0.fld.cr.syncokie = cm_object_get_child_by_name(state->u.f0.reg.cr, "SYNCOKIE"); 
    state->u.f0.fld.cr.syncwarnie = cm_object_get_child_by_name(state->u.f0.reg.cr, "SYNCWARNIE"); 
    state->u.f0.fld.cr.errie = cm_object_get_child_by_name(state->u.f0.reg.cr, "ERRIE"); 
    state->u.f0.fld.cr.esyncie = cm_object_get_child_by_name(state->u.f0.reg.cr, "ESYNCIE"); 
    state->u.f0.fld.cr.cen = cm_object_get_child_by_name(state->u.f0.reg.cr, "CEN"); 
    state->u.f0.fld.cr.autotrimen = cm_object_get_child_by_name(state->u.f0.reg.cr, "AUTOTRIMEN"); 
    state->u.f0.fld.cr.swsync = cm_object_get_child_by_name(state->u.f0.reg.cr, "SWSYNC"); 
    state->u.f0.fld.cr.trim = cm_object_get_child_by_name(state->u.f0.reg.cr, "TRIM");  
    
    // CFGR bitfields.
    state->u.f0.fld.cfgr.reload = cm_object_get_child_by_name(state->u.f0.reg.cfgr, "RELOAD"); 
    state->u.f0.fld.cfgr.felim = cm_object_get_child_by_name(state->u.f0.reg.cfgr, "FELIM"); 
    state->u.f0.fld.cfgr.syncdiv = cm_object_get_child_by_name(state->u.f0.reg.cfgr, "SYNCDIV"); 
    state->u.f0.fld.cfgr.syncsrc = cm_object_get_child_by_name(state->u.f0.reg.cfgr, "SYNCSRC"); 
    state->u.f0.fld.cfgr.syncpol = cm_object_get_child_by_name(state->u.f0.reg.cfgr, "SYNCPOL");  
    
    // ISR bitfields.
    state->u.f0.fld.isr.syncokf = cm_object_get_child_by_name(state->u.f0.reg.isr, "SYNCOKF"); 
    state->u.f0.fld.isr.syncwarnf = cm_object_get_child_by_name(state->u.f0.reg.isr, "SYNCWARNF"); 
    state->u.f0.fld.isr.errf = cm_object_get_child_by_name(state->u.f0.reg.isr, "ERRF"); 
    state->u.f0.fld.isr.esyncf = cm_object_get_child_by_name(state->u.f0.reg.isr, "ESYNCF"); 
    state->u.f0.fld.isr.syncerr = cm_object_get_child_by_name(state->u.f0.reg.isr, "SYNCERR"); 
    state->u.f0.fld.isr.syncmiss = cm_object_get_child_by_name(state->u.f0.reg.isr, "SYNCMISS"); 
    state->u.f0.fld.isr.trimovf = cm_object_get_child_by_name(state->u.f0.reg.isr, "TRIMOVF"); 
    state->u.f0.fld.isr.fedir = cm_object_get_child_by_name(state->u.f0.reg.isr, "FEDIR"); 
    state->u.f0.fld.isr.fecap = cm_object_get_child_by_name(state->u.f0.reg.isr, "FECAP");  
    
    // ICR bitfields.
    state->u.f0.fld.icr.syncokc = cm_object_get_child_by_name(state->u.f0.reg.icr, "SYNCOKC"); 
    state->u.f0.fld.icr.syncwarnc = cm_object_get_child_by_name(state->u.f0.reg.icr, "SYNCWARNC"); 
    state->u.f0.fld.icr.errc = cm_object_get_child_by_name(state->u.f0.reg.icr, "ERRC"); 
    state->u.f0.fld.icr.esyncc = cm_object_get_child_by_name(state->u.f0.reg.icr, "ESYNCC");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_crs_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32CRSState *state = STM32_CRS_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_crs_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32CRSState *state = STM32_CRS_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_crs_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32CRSState *state = STM32_CRS_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_crs_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32CRSState *state = STM32_CRS_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_crs_is_enabled(Object *obj)
{
    STM32CRSState *state = STM32_CRS_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_crs_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32CRSState *state = STM32_CRS_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_crs_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_CRS)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32CRSState *state = STM32_CRS_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "CRS";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x1 ) {

            stm32f0x1_crs_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_crs_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f0.reg.xxx, &stm32_crs_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_crs_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f0.reg.xxx, &stm32_crs_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/CRSEN");


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

static void stm32_crs_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_CRS);
}

static void stm32_crs_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_crs_reset_callback;
    dc->realize = stm32_crs_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_crs_is_enabled;
}

static const TypeInfo stm32_crs_type_info = {
    .name = TYPE_STM32_CRS,
    .parent = TYPE_STM32_CRS_PARENT,
    .instance_init = stm32_crs_instance_init_callback,
    .instance_size = sizeof(STM32CRSState),
    .class_init = stm32_crs_class_init_callback,
    .class_size = sizeof(STM32CRSClass) };

static void stm32_crs_register_types(void)
{
    type_register_static(&stm32_crs_type_info);
}

type_init(stm32_crs_register_types);

// ----------------------------------------------------------------------------
