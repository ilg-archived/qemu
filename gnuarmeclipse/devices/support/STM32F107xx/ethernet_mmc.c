/*
 * STM32 - ETHERNET_MMC (Ethernet: MAC management counters) emulation.
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

#include <hw/cortexm/stm32/ethernet_mmc.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f107xx_ethernet_mmc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32ETHERNET_MMCState *state = STM32_ETHERNET_MMC_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f1.reg.mmccr = cm_object_get_child_by_name(obj, "MMCCR");
    state->u.f1.reg.mmcrir = cm_object_get_child_by_name(obj, "MMCRIR");
    state->u.f1.reg.mmctir = cm_object_get_child_by_name(obj, "MMCTIR");
    state->u.f1.reg.mmcrimr = cm_object_get_child_by_name(obj, "MMCRIMR");
    state->u.f1.reg.mmctimr = cm_object_get_child_by_name(obj, "MMCTIMR");
    state->u.f1.reg.mmctgfsccr = cm_object_get_child_by_name(obj, "MMCTGFSCCR");
    state->u.f1.reg.mmctgfmsccr = cm_object_get_child_by_name(obj, "MMCTGFMSCCR");
    state->u.f1.reg.mmctgfcr = cm_object_get_child_by_name(obj, "MMCTGFCR");
    state->u.f1.reg.mmcrfcecr = cm_object_get_child_by_name(obj, "MMCRFCECR");
    state->u.f1.reg.mmcrfaecr = cm_object_get_child_by_name(obj, "MMCRFAECR");
    state->u.f1.reg.mmcrgufcr = cm_object_get_child_by_name(obj, "MMCRGUFCR");
    
    
    // MMCCR bitfields.
    state->u.f1.fld.mmccr.cr = cm_object_get_child_by_name(state->u.f1.reg.mmccr, "CR"); 
    state->u.f1.fld.mmccr.csr = cm_object_get_child_by_name(state->u.f1.reg.mmccr, "CSR"); 
    state->u.f1.fld.mmccr.ror = cm_object_get_child_by_name(state->u.f1.reg.mmccr, "ROR"); 
    state->u.f1.fld.mmccr.mcf = cm_object_get_child_by_name(state->u.f1.reg.mmccr, "MCF");  
    
    // MMCRIR bitfields.
    state->u.f1.fld.mmcrir.rfces = cm_object_get_child_by_name(state->u.f1.reg.mmcrir, "RFCES"); 
    state->u.f1.fld.mmcrir.rfaes = cm_object_get_child_by_name(state->u.f1.reg.mmcrir, "RFAES"); 
    state->u.f1.fld.mmcrir.rgufs = cm_object_get_child_by_name(state->u.f1.reg.mmcrir, "RGUFS");  
    
    // MMCTIR bitfields.
    state->u.f1.fld.mmctir.tgfscs = cm_object_get_child_by_name(state->u.f1.reg.mmctir, "TGFSCS"); 
    state->u.f1.fld.mmctir.tgfmscs = cm_object_get_child_by_name(state->u.f1.reg.mmctir, "TGFMSCS"); 
    state->u.f1.fld.mmctir.tgfs = cm_object_get_child_by_name(state->u.f1.reg.mmctir, "TGFS");  
    
    // MMCRIMR bitfields.
    state->u.f1.fld.mmcrimr.rfcem = cm_object_get_child_by_name(state->u.f1.reg.mmcrimr, "RFCEM"); 
    state->u.f1.fld.mmcrimr.rfaem = cm_object_get_child_by_name(state->u.f1.reg.mmcrimr, "RFAEM"); 
    state->u.f1.fld.mmcrimr.rgufm = cm_object_get_child_by_name(state->u.f1.reg.mmcrimr, "RGUFM");  
    
    // MMCTIMR bitfields.
    state->u.f1.fld.mmctimr.tgfscm = cm_object_get_child_by_name(state->u.f1.reg.mmctimr, "TGFSCM"); 
    state->u.f1.fld.mmctimr.tgfmscm = cm_object_get_child_by_name(state->u.f1.reg.mmctimr, "TGFMSCM"); 
    state->u.f1.fld.mmctimr.tgfm = cm_object_get_child_by_name(state->u.f1.reg.mmctimr, "TGFM");  
    
    // MMCTGFSCCR bitfields.
    state->u.f1.fld.mmctgfsccr.tgfscc = cm_object_get_child_by_name(state->u.f1.reg.mmctgfsccr, "TGFSCC");  
    
    // MMCTGFMSCCR bitfields.
    state->u.f1.fld.mmctgfmsccr.tgfmscc = cm_object_get_child_by_name(state->u.f1.reg.mmctgfmsccr, "TGFMSCC");  
    
    // MMCTGFCR bitfields.
    state->u.f1.fld.mmctgfcr.tgfc = cm_object_get_child_by_name(state->u.f1.reg.mmctgfcr, "TGFC");  
    
    // MMCRFCECR bitfields.
    state->u.f1.fld.mmcrfcecr.rfcfc = cm_object_get_child_by_name(state->u.f1.reg.mmcrfcecr, "RFCFC");  
    
    // MMCRFAECR bitfields.
    state->u.f1.fld.mmcrfaecr.rfaec = cm_object_get_child_by_name(state->u.f1.reg.mmcrfaecr, "RFAEC");  
    
    // MMCRGUFCR bitfields.
    state->u.f1.fld.mmcrgufcr.rgufc = cm_object_get_child_by_name(state->u.f1.reg.mmcrgufcr, "RGUFC");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_ethernet_mmc_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32ETHERNET_MMCState *state = STM32_ETHERNET_MMC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_ethernet_mmc_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32ETHERNET_MMCState *state = STM32_ETHERNET_MMC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_ethernet_mmc_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32ETHERNET_MMCState *state = STM32_ETHERNET_MMC_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_ethernet_mmc_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32ETHERNET_MMCState *state = STM32_ETHERNET_MMC_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_ethernet_mmc_is_enabled(Object *obj)
{
    STM32ETHERNET_MMCState *state = STM32_ETHERNET_MMC_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_ethernet_mmc_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32ETHERNET_MMCState *state = STM32_ETHERNET_MMC_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_ethernet_mmc_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_ETHERNET_MMC)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32ETHERNET_MMCState *state = STM32_ETHERNET_MMC_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "ETHERNET_MMC";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F1:

        if (capabilities->f1.is_107xx ) {

            stm32f107xx_ethernet_mmc_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f1.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f1.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f1.reg.xxx, &stm32_ethernet_mmc_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f1.reg.xxx, &stm32_ethernet_mmc_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f1.reg.xxx, &stm32_ethernet_mmc_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f1.reg.xxx, &stm32_ethernet_mmc_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/ETHERNET_MMCEN");


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

static void stm32_ethernet_mmc_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_ETHERNET_MMC);
}

static void stm32_ethernet_mmc_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_ethernet_mmc_reset_callback;
    dc->realize = stm32_ethernet_mmc_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_ethernet_mmc_is_enabled;
}

static const TypeInfo stm32_ethernet_mmc_type_info = {
    .name = TYPE_STM32_ETHERNET_MMC,
    .parent = TYPE_STM32_ETHERNET_MMC_PARENT,
    .instance_init = stm32_ethernet_mmc_instance_init_callback,
    .instance_size = sizeof(STM32ETHERNET_MMCState),
    .class_init = stm32_ethernet_mmc_class_init_callback,
    .class_size = sizeof(STM32ETHERNET_MMCClass) };

static void stm32_ethernet_mmc_register_types(void)
{
    type_register_static(&stm32_ethernet_mmc_type_info);
}

type_init(stm32_ethernet_mmc_register_types);

// ----------------------------------------------------------------------------
