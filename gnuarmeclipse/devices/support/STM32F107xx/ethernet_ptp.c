/*
 * STM32 - ETHERNET_PTP (Ethernet: Precision time protocol) emulation.
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

#include <hw/cortexm/stm32/ethernet_ptp.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f107xx_ethernet_ptp_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32ETHERNET_PTPState *state = STM32_ETHERNET_PTP_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f1.reg.ptptscr = cm_object_get_child_by_name(obj, "PTPTSCR");
    state->u.f1.reg.ptpssir = cm_object_get_child_by_name(obj, "PTPSSIR");
    state->u.f1.reg.ptptshr = cm_object_get_child_by_name(obj, "PTPTSHR");
    state->u.f1.reg.ptptslr = cm_object_get_child_by_name(obj, "PTPTSLR");
    state->u.f1.reg.ptptshur = cm_object_get_child_by_name(obj, "PTPTSHUR");
    state->u.f1.reg.ptptslur = cm_object_get_child_by_name(obj, "PTPTSLUR");
    state->u.f1.reg.ptptsar = cm_object_get_child_by_name(obj, "PTPTSAR");
    state->u.f1.reg.ptptthr = cm_object_get_child_by_name(obj, "PTPTTHR");
    state->u.f1.reg.ptpttlr = cm_object_get_child_by_name(obj, "PTPTTLR");
    
    
    // PTPTSCR bitfields.
    state->u.f1.fld.ptptscr.tse = cm_object_get_child_by_name(state->u.f1.reg.ptptscr, "TSE"); 
    state->u.f1.fld.ptptscr.tsfcu = cm_object_get_child_by_name(state->u.f1.reg.ptptscr, "TSFCU"); 
    state->u.f1.fld.ptptscr.tssti = cm_object_get_child_by_name(state->u.f1.reg.ptptscr, "TSSTI"); 
    state->u.f1.fld.ptptscr.tsstu = cm_object_get_child_by_name(state->u.f1.reg.ptptscr, "TSSTU"); 
    state->u.f1.fld.ptptscr.tsite = cm_object_get_child_by_name(state->u.f1.reg.ptptscr, "TSITE"); 
    state->u.f1.fld.ptptscr.tsaru = cm_object_get_child_by_name(state->u.f1.reg.ptptscr, "TSARU");  
    
    // PTPSSIR bitfields.
    state->u.f1.fld.ptpssir.stssi = cm_object_get_child_by_name(state->u.f1.reg.ptpssir, "STSSI");  
    
    // PTPTSHR bitfields.
    state->u.f1.fld.ptptshr.sts = cm_object_get_child_by_name(state->u.f1.reg.ptptshr, "STS");  
    
    // PTPTSLR bitfields.
    state->u.f1.fld.ptptslr.stss = cm_object_get_child_by_name(state->u.f1.reg.ptptslr, "STSS"); 
    state->u.f1.fld.ptptslr.stpns = cm_object_get_child_by_name(state->u.f1.reg.ptptslr, "STPNS");  
    
    // PTPTSHUR bitfields.
    state->u.f1.fld.ptptshur.tsus = cm_object_get_child_by_name(state->u.f1.reg.ptptshur, "TSUS");  
    
    // PTPTSLUR bitfields.
    state->u.f1.fld.ptptslur.tsuss = cm_object_get_child_by_name(state->u.f1.reg.ptptslur, "TSUSS"); 
    state->u.f1.fld.ptptslur.tsupns = cm_object_get_child_by_name(state->u.f1.reg.ptptslur, "TSUPNS");  
    
    // PTPTSAR bitfields.
    state->u.f1.fld.ptptsar.tsa = cm_object_get_child_by_name(state->u.f1.reg.ptptsar, "TSA");  
    
    // PTPTTHR bitfields.
    state->u.f1.fld.ptptthr.ttsh = cm_object_get_child_by_name(state->u.f1.reg.ptptthr, "TTSH");  
    
    // PTPTTLR bitfields.
    state->u.f1.fld.ptpttlr.ttsl = cm_object_get_child_by_name(state->u.f1.reg.ptpttlr, "TTSL");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_ethernet_ptp_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32ETHERNET_PTPState *state = STM32_ETHERNET_PTP_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_ethernet_ptp_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32ETHERNET_PTPState *state = STM32_ETHERNET_PTP_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_ethernet_ptp_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32ETHERNET_PTPState *state = STM32_ETHERNET_PTP_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_ethernet_ptp_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32ETHERNET_PTPState *state = STM32_ETHERNET_PTP_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_ethernet_ptp_is_enabled(Object *obj)
{
    STM32ETHERNET_PTPState *state = STM32_ETHERNET_PTP_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_ethernet_ptp_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32ETHERNET_PTPState *state = STM32_ETHERNET_PTP_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_ethernet_ptp_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_ETHERNET_PTP)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32ETHERNET_PTPState *state = STM32_ETHERNET_PTP_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "ETHERNET_PTP";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F1:

        if (capabilities->f1.is_107xx ) {

            stm32f107xx_ethernet_ptp_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f1.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f1.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f1.reg.xxx, &stm32_ethernet_ptp_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f1.reg.xxx, &stm32_ethernet_ptp_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f1.reg.xxx, &stm32_ethernet_ptp_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f1.reg.xxx, &stm32_ethernet_ptp_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/ETHERNET_PTPEN");


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

static void stm32_ethernet_ptp_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_ETHERNET_PTP);
}

static void stm32_ethernet_ptp_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_ethernet_ptp_reset_callback;
    dc->realize = stm32_ethernet_ptp_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_ethernet_ptp_is_enabled;
}

static const TypeInfo stm32_ethernet_ptp_type_info = {
    .name = TYPE_STM32_ETHERNET_PTP,
    .parent = TYPE_STM32_ETHERNET_PTP_PARENT,
    .instance_init = stm32_ethernet_ptp_instance_init_callback,
    .instance_size = sizeof(STM32ETHERNET_PTPState),
    .class_init = stm32_ethernet_ptp_class_init_callback,
    .class_size = sizeof(STM32ETHERNET_PTPClass) };

static void stm32_ethernet_ptp_register_types(void)
{
    type_register_static(&stm32_ethernet_ptp_type_info);
}

type_init(stm32_ethernet_ptp_register_types);

// ----------------------------------------------------------------------------
