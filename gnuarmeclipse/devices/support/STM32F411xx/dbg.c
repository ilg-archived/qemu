/*
 * STM32 - DBG (Debug support) emulation.
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

#include <hw/cortexm/stm32/dbg.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f411xx_dbg_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32DBGState *state = STM32_DBG_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.dbgmcu_idcode = cm_object_get_child_by_name(obj, "DBGMCU_IDCODE");
    state->u.f4.reg.dbgmcu_cr = cm_object_get_child_by_name(obj, "DBGMCU_CR");
    state->u.f4.reg.dbgmcu_apb1_fz = cm_object_get_child_by_name(obj, "DBGMCU_APB1_FZ");
    state->u.f4.reg.dbgmcu_apb2_fz = cm_object_get_child_by_name(obj, "DBGMCU_APB2_FZ");
    
    
    // DBGMCU_IDCODE bitfields.
    state->u.f4.fld.dbgmcu_idcode.dev_id = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_idcode, "DEV_ID"); 
    state->u.f4.fld.dbgmcu_idcode.rev_id = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_idcode, "REV_ID");  
    
    // DBGMCU_CR bitfields.
    state->u.f4.fld.dbgmcu_cr.dbg_sleep = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_cr, "DBG_SLEEP"); 
    state->u.f4.fld.dbgmcu_cr.dbg_stop = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_cr, "DBG_STOP"); 
    state->u.f4.fld.dbgmcu_cr.dbg_standby = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_cr, "DBG_STANDBY"); 
    state->u.f4.fld.dbgmcu_cr.trace_ioen = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_cr, "TRACE_IOEN"); 
    state->u.f4.fld.dbgmcu_cr.trace_mode = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_cr, "TRACE_MODE");  
    
    // DBGMCU_APB1_FZ bitfields.
    state->u.f4.fld.dbgmcu_apb1_fz.dbg_tim2_stop = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_apb1_fz, "DBG_TIM2_STOP"); 
    state->u.f4.fld.dbgmcu_apb1_fz.dbg_tim3_stop = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_apb1_fz, "DBG_TIM3_STOP"); 
    state->u.f4.fld.dbgmcu_apb1_fz.dbg_tim4_stop = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_apb1_fz, "DBG_TIM4_STOP"); 
    state->u.f4.fld.dbgmcu_apb1_fz.dbg_tim5_stop = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_apb1_fz, "DBG_TIM5_STOP"); 
    state->u.f4.fld.dbgmcu_apb1_fz.dbg_rtc_stop = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_apb1_fz, "DBG_RTC_Stop"); 
    state->u.f4.fld.dbgmcu_apb1_fz.dbg_wwdg_stop = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_apb1_fz, "DBG_WWDG_STOP"); 
    state->u.f4.fld.dbgmcu_apb1_fz.dbg_iwdeg_stop = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_apb1_fz, "DBG_IWDEG_STOP"); 
    state->u.f4.fld.dbgmcu_apb1_fz.dbg_i2c1_smbus_timeout = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_apb1_fz, "DBG_I2C1_SMBUS_TIMEOUT"); 
    state->u.f4.fld.dbgmcu_apb1_fz.dbg_i2c2_smbus_timeout = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_apb1_fz, "DBG_I2C2_SMBUS_TIMEOUT"); 
    state->u.f4.fld.dbgmcu_apb1_fz.dbg_i2c3smbus_timeout = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_apb1_fz, "DBG_I2C3SMBUS_TIMEOUT");  
    
    // DBGMCU_APB2_FZ bitfields.
    state->u.f4.fld.dbgmcu_apb2_fz.dbg_tim1_stop = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_apb2_fz, "DBG_TIM1_STOP"); 
    state->u.f4.fld.dbgmcu_apb2_fz.dbg_tim9_stop = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_apb2_fz, "DBG_TIM9_STOP"); 
    state->u.f4.fld.dbgmcu_apb2_fz.dbg_tim10_stop = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_apb2_fz, "DBG_TIM10_STOP"); 
    state->u.f4.fld.dbgmcu_apb2_fz.dbg_tim11_stop = cm_object_get_child_by_name(state->u.f4.reg.dbgmcu_apb2_fz, "DBG_TIM11_STOP");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_dbg_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32DBGState *state = STM32_DBG_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_dbg_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32DBGState *state = STM32_DBG_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_dbg_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32DBGState *state = STM32_DBG_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_dbg_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32DBGState *state = STM32_DBG_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_dbg_is_enabled(Object *obj)
{
    STM32DBGState *state = STM32_DBG_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_dbg_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32DBGState *state = STM32_DBG_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_dbg_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_DBG)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32DBGState *state = STM32_DBG_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "DBG";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_411xx ) {

            stm32f411xx_dbg_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_dbg_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_dbg_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_dbg_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_dbg_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/DBGEN");


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

static void stm32_dbg_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_DBG);
}

static void stm32_dbg_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_dbg_reset_callback;
    dc->realize = stm32_dbg_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_dbg_is_enabled;
}

static const TypeInfo stm32_dbg_type_info = {
    .name = TYPE_STM32_DBG,
    .parent = TYPE_STM32_DBG_PARENT,
    .instance_init = stm32_dbg_instance_init_callback,
    .instance_size = sizeof(STM32DBGState),
    .class_init = stm32_dbg_class_init_callback,
    .class_size = sizeof(STM32DBGClass) };

static void stm32_dbg_register_types(void)
{
    type_register_static(&stm32_dbg_type_info);
}

type_init(stm32_dbg_register_types);

// ----------------------------------------------------------------------------
