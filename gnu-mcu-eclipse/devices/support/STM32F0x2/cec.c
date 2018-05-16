/*
 * STM32- CEC(HDMI-CEC controller) emulation.
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

#include <hw/cortexm/stm32/cec.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x2_cec_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32CECState *state = STM32_CEC_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
state->u.f0.reg.cr= cm_object_get_child_by_name(obj, "CR");
state->u.f0.reg.cfgr= cm_object_get_child_by_name(obj, "CFGR");
state->u.f0.reg.txdr= cm_object_get_child_by_name(obj, "TXDR");
state->u.f0.reg.rxdr= cm_object_get_child_by_name(obj, "RXDR");
state->u.f0.reg.isr= cm_object_get_child_by_name(obj, "ISR");
state->u.f0.reg.ier= cm_object_get_child_by_name(obj, "IER");
// CRbitfields.
state->u.f0.fld.cr.cecen= cm_object_get_child_by_name(state->u.f0.reg.cr, "CECEN"); 
state->u.f0.fld.cr.txsom= cm_object_get_child_by_name(state->u.f0.reg.cr, "TXSOM"); 
state->u.f0.fld.cr.txeom= cm_object_get_child_by_name(state->u.f0.reg.cr, "TXEOM"); 
// CFGRbitfields.
state->u.f0.fld.cfgr.oar= cm_object_get_child_by_name(state->u.f0.reg.cfgr, "OAR"); 
state->u.f0.fld.cfgr.lstn= cm_object_get_child_by_name(state->u.f0.reg.cfgr, "LSTN"); 
state->u.f0.fld.cfgr.sft= cm_object_get_child_by_name(state->u.f0.reg.cfgr, "SFT"); 
state->u.f0.fld.cfgr.rxtol= cm_object_get_child_by_name(state->u.f0.reg.cfgr, "RXTOL"); 
state->u.f0.fld.cfgr.brestp= cm_object_get_child_by_name(state->u.f0.reg.cfgr, "BRESTP"); 
state->u.f0.fld.cfgr.bregen= cm_object_get_child_by_name(state->u.f0.reg.cfgr, "BREGEN"); 
state->u.f0.fld.cfgr.lbpegen= cm_object_get_child_by_name(state->u.f0.reg.cfgr, "LBPEGEN"); 
// TXDRbitfields.
state->u.f0.fld.txdr.txd= cm_object_get_child_by_name(state->u.f0.reg.txdr, "TXD"); 
// RXDRbitfields.
state->u.f0.fld.rxdr.rxdr= cm_object_get_child_by_name(state->u.f0.reg.rxdr, "RXDR"); 
// ISRbitfields.
state->u.f0.fld.isr.rxbr= cm_object_get_child_by_name(state->u.f0.reg.isr, "RXBR"); 
state->u.f0.fld.isr.rxend= cm_object_get_child_by_name(state->u.f0.reg.isr, "RXEND"); 
state->u.f0.fld.isr.rxovr= cm_object_get_child_by_name(state->u.f0.reg.isr, "RXOVR"); 
state->u.f0.fld.isr.bre= cm_object_get_child_by_name(state->u.f0.reg.isr, "BRE"); 
state->u.f0.fld.isr.sbpe= cm_object_get_child_by_name(state->u.f0.reg.isr, "SBPE"); 
state->u.f0.fld.isr.lbpe= cm_object_get_child_by_name(state->u.f0.reg.isr, "LBPE"); 
state->u.f0.fld.isr.rxacke= cm_object_get_child_by_name(state->u.f0.reg.isr, "RXACKE"); 
state->u.f0.fld.isr.arblst= cm_object_get_child_by_name(state->u.f0.reg.isr, "ARBLST"); 
state->u.f0.fld.isr.txbr= cm_object_get_child_by_name(state->u.f0.reg.isr, "TXBR"); 
state->u.f0.fld.isr.txend= cm_object_get_child_by_name(state->u.f0.reg.isr, "TXEND"); 
state->u.f0.fld.isr.txudr= cm_object_get_child_by_name(state->u.f0.reg.isr, "TXUDR"); 
state->u.f0.fld.isr.txerr= cm_object_get_child_by_name(state->u.f0.reg.isr, "TXERR"); 
state->u.f0.fld.isr.txacke= cm_object_get_child_by_name(state->u.f0.reg.isr, "TXACKE"); 
// IERbitfields.
state->u.f0.fld.ier.rxbrie= cm_object_get_child_by_name(state->u.f0.reg.ier, "RXBRIE"); 
state->u.f0.fld.ier.rxendie= cm_object_get_child_by_name(state->u.f0.reg.ier, "RXENDIE"); 
state->u.f0.fld.ier.rxovrie= cm_object_get_child_by_name(state->u.f0.reg.ier, "RXOVRIE"); 
state->u.f0.fld.ier.breie= cm_object_get_child_by_name(state->u.f0.reg.ier, "BREIE"); 
state->u.f0.fld.ier.sbpeie= cm_object_get_child_by_name(state->u.f0.reg.ier, "SBPEIE"); 
state->u.f0.fld.ier.lbpeie= cm_object_get_child_by_name(state->u.f0.reg.ier, "LBPEIE"); 
state->u.f0.fld.ier.rxackie= cm_object_get_child_by_name(state->u.f0.reg.ier, "RXACKIE"); 
state->u.f0.fld.ier.arblstie= cm_object_get_child_by_name(state->u.f0.reg.ier, "ARBLSTIE"); 
state->u.f0.fld.ier.txbrie= cm_object_get_child_by_name(state->u.f0.reg.ier, "TXBRIE"); 
state->u.f0.fld.ier.txendie= cm_object_get_child_by_name(state->u.f0.reg.ier, "TXENDIE"); 
state->u.f0.fld.ier.txudrie= cm_object_get_child_by_name(state->u.f0.reg.ier, "TXUDRIE"); 
state->u.f0.fld.ier.txerrie= cm_object_get_child_by_name(state->u.f0.reg.ier, "TXERRIE"); 
state->u.f0.fld.ier.txackie= cm_object_get_child_by_name(state->u.f0.reg.ier, "TXACKIE"); 
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_cec_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32CECState *state = STM32_CEC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_cec_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32CECState *state = STM32_CEC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_cec_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32CECState *state = STM32_CEC_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_cec_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32CECState *state = STM32_CEC_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_cec_is_enabled(Object *obj)
{
    STM32CECState *state = STM32_CEC_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_cec_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32CECState *state = STM32_CEC_STATE(obj);

    // Capabilities are not yet available.

// TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_cec_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_CEC)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32CECState *state = STM32_CEC_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "CEC";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x2) {

            stm32f0x2_cec_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_cec_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f0.reg.xxx, &stm32_cec_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_cec_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f0.reg.xxx, &stm32_cec_xxx_post_write_callback);

            // TODO: add interrupts.

// TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/CECEN");
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

static void stm32_cec_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_CEC);
}

static void stm32_cec_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_cec_reset_callback;
    dc->realize = stm32_cec_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_cec_is_enabled;
}

static const TypeInfo stm32_cec_type_info = {
    .name = TYPE_STM32_CEC,
    .parent = TYPE_STM32_CEC_PARENT,
    .instance_init = stm32_cec_instance_init_callback,
    .instance_size = sizeof(STM32CECState),
    .class_init = stm32_cec_class_init_callback,
    .class_size = sizeof(STM32CECClass) };

static void stm32_cec_register_types(void)
{
    type_register_static(&stm32_cec_type_info);
}

type_init(stm32_cec_register_types);

// ----------------------------------------------------------------------------
