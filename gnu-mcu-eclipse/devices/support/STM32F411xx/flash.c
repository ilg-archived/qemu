/*
 * STM32 - FLASH (FLASH) emulation.
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

#include <hw/cortexm/stm32/flash.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f411xx_flash_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32FLASHState *state = STM32_FLASH_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.acr = cm_object_get_child_by_name(obj, "ACR");
    state->u.f4.reg.keyr = cm_object_get_child_by_name(obj, "KEYR");
    state->u.f4.reg.optkeyr = cm_object_get_child_by_name(obj, "OPTKEYR");
    state->u.f4.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->u.f4.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->u.f4.reg.optcr = cm_object_get_child_by_name(obj, "OPTCR");
    
    
    // ACR bitfields.
    state->u.f4.fld.acr.latency = cm_object_get_child_by_name(state->u.f4.reg.acr, "LATENCY"); 
    state->u.f4.fld.acr.prften = cm_object_get_child_by_name(state->u.f4.reg.acr, "PRFTEN"); 
    state->u.f4.fld.acr.icen = cm_object_get_child_by_name(state->u.f4.reg.acr, "ICEN"); 
    state->u.f4.fld.acr.dcen = cm_object_get_child_by_name(state->u.f4.reg.acr, "DCEN"); 
    state->u.f4.fld.acr.icrst = cm_object_get_child_by_name(state->u.f4.reg.acr, "ICRST"); 
    state->u.f4.fld.acr.dcrst = cm_object_get_child_by_name(state->u.f4.reg.acr, "DCRST");  
    
    // KEYR bitfields.
    state->u.f4.fld.keyr.key = cm_object_get_child_by_name(state->u.f4.reg.keyr, "KEY");  
    
    // OPTKEYR bitfields.
    state->u.f4.fld.optkeyr.optkey = cm_object_get_child_by_name(state->u.f4.reg.optkeyr, "OPTKEY");  
    
    // SR bitfields.
    state->u.f4.fld.sr.eop = cm_object_get_child_by_name(state->u.f4.reg.sr, "EOP"); 
    state->u.f4.fld.sr.operr = cm_object_get_child_by_name(state->u.f4.reg.sr, "OPERR"); 
    state->u.f4.fld.sr.wrperr = cm_object_get_child_by_name(state->u.f4.reg.sr, "WRPERR"); 
    state->u.f4.fld.sr.pgaerr = cm_object_get_child_by_name(state->u.f4.reg.sr, "PGAERR"); 
    state->u.f4.fld.sr.pgperr = cm_object_get_child_by_name(state->u.f4.reg.sr, "PGPERR"); 
    state->u.f4.fld.sr.pgserr = cm_object_get_child_by_name(state->u.f4.reg.sr, "PGSERR"); 
    state->u.f4.fld.sr.bsy = cm_object_get_child_by_name(state->u.f4.reg.sr, "BSY");  
    
    // CR bitfields.
    state->u.f4.fld.cr.pg = cm_object_get_child_by_name(state->u.f4.reg.cr, "PG"); 
    state->u.f4.fld.cr.ser = cm_object_get_child_by_name(state->u.f4.reg.cr, "SER"); 
    state->u.f4.fld.cr.mer = cm_object_get_child_by_name(state->u.f4.reg.cr, "MER"); 
    state->u.f4.fld.cr.snb = cm_object_get_child_by_name(state->u.f4.reg.cr, "SNB"); 
    state->u.f4.fld.cr.psize = cm_object_get_child_by_name(state->u.f4.reg.cr, "PSIZE"); 
    state->u.f4.fld.cr.strt = cm_object_get_child_by_name(state->u.f4.reg.cr, "STRT"); 
    state->u.f4.fld.cr.eopie = cm_object_get_child_by_name(state->u.f4.reg.cr, "EOPIE"); 
    state->u.f4.fld.cr.errie = cm_object_get_child_by_name(state->u.f4.reg.cr, "ERRIE"); 
    state->u.f4.fld.cr.lock = cm_object_get_child_by_name(state->u.f4.reg.cr, "LOCK");  
    
    // OPTCR bitfields.
    state->u.f4.fld.optcr.optlock = cm_object_get_child_by_name(state->u.f4.reg.optcr, "OPTLOCK"); 
    state->u.f4.fld.optcr.optstrt = cm_object_get_child_by_name(state->u.f4.reg.optcr, "OPTSTRT"); 
    state->u.f4.fld.optcr.bor_lev = cm_object_get_child_by_name(state->u.f4.reg.optcr, "BOR_LEV"); 
    state->u.f4.fld.optcr.wdg_sw = cm_object_get_child_by_name(state->u.f4.reg.optcr, "WDG_SW"); 
    state->u.f4.fld.optcr.nrst_stop = cm_object_get_child_by_name(state->u.f4.reg.optcr, "nRST_STOP"); 
    state->u.f4.fld.optcr.nrst_stdby = cm_object_get_child_by_name(state->u.f4.reg.optcr, "nRST_STDBY"); 
    state->u.f4.fld.optcr.rdp = cm_object_get_child_by_name(state->u.f4.reg.optcr, "RDP"); 
    state->u.f4.fld.optcr.nwrp = cm_object_get_child_by_name(state->u.f4.reg.optcr, "nWRP");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_flash_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32FLASHState *state = STM32_FLASH_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_flash_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32FLASHState *state = STM32_FLASH_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_flash_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32FLASHState *state = STM32_FLASH_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_flash_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32FLASHState *state = STM32_FLASH_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_flash_is_enabled(Object *obj)
{
    STM32FLASHState *state = STM32_FLASH_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_flash_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32FLASHState *state = STM32_FLASH_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_flash_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_FLASH)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32FLASHState *state = STM32_FLASH_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "FLASH";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_411xx ) {

            stm32f411xx_flash_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_flash_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_flash_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_flash_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_flash_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/FLASHEN");


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

static void stm32_flash_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_FLASH);
}

static void stm32_flash_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_flash_reset_callback;
    dc->realize = stm32_flash_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_flash_is_enabled;
}

static const TypeInfo stm32_flash_type_info = {
    .name = TYPE_STM32_FLASH,
    .parent = TYPE_STM32_FLASH_PARENT,
    .instance_init = stm32_flash_instance_init_callback,
    .instance_size = sizeof(STM32FLASHState),
    .class_init = stm32_flash_class_init_callback,
    .class_size = sizeof(STM32FLASHClass) };

static void stm32_flash_register_types(void)
{
    type_register_static(&stm32_flash_type_info);
}

type_init(stm32_flash_register_types);

// ----------------------------------------------------------------------------
