/*
 * STM32 - BKP (Backup registers) emulation.
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

#include <hw/cortexm/stm32/bkp.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_bkp_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32BKPState *state = STM32_BKP_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f1.reg.dr1 = cm_object_get_child_by_name(obj, "DR1");
    state->u.f1.reg.dr2 = cm_object_get_child_by_name(obj, "DR2");
    state->u.f1.reg.dr3 = cm_object_get_child_by_name(obj, "DR3");
    state->u.f1.reg.dr4 = cm_object_get_child_by_name(obj, "DR4");
    state->u.f1.reg.dr5 = cm_object_get_child_by_name(obj, "DR5");
    state->u.f1.reg.dr6 = cm_object_get_child_by_name(obj, "DR6");
    state->u.f1.reg.dr7 = cm_object_get_child_by_name(obj, "DR7");
    state->u.f1.reg.dr8 = cm_object_get_child_by_name(obj, "DR8");
    state->u.f1.reg.dr9 = cm_object_get_child_by_name(obj, "DR9");
    state->u.f1.reg.dr10 = cm_object_get_child_by_name(obj, "DR10");
    state->u.f1.reg.dr11 = cm_object_get_child_by_name(obj, "DR11");
    state->u.f1.reg.dr12 = cm_object_get_child_by_name(obj, "DR12");
    state->u.f1.reg.dr13 = cm_object_get_child_by_name(obj, "DR13");
    state->u.f1.reg.dr14 = cm_object_get_child_by_name(obj, "DR14");
    state->u.f1.reg.dr15 = cm_object_get_child_by_name(obj, "DR15");
    state->u.f1.reg.dr16 = cm_object_get_child_by_name(obj, "DR16");
    state->u.f1.reg.dr17 = cm_object_get_child_by_name(obj, "DR17");
    state->u.f1.reg.dr18 = cm_object_get_child_by_name(obj, "DR18");
    state->u.f1.reg.dr19 = cm_object_get_child_by_name(obj, "DR19");
    state->u.f1.reg.dr20 = cm_object_get_child_by_name(obj, "DR20");
    state->u.f1.reg.dr21 = cm_object_get_child_by_name(obj, "DR21");
    state->u.f1.reg.dr22 = cm_object_get_child_by_name(obj, "DR22");
    state->u.f1.reg.dr23 = cm_object_get_child_by_name(obj, "DR23");
    state->u.f1.reg.dr24 = cm_object_get_child_by_name(obj, "DR24");
    state->u.f1.reg.dr25 = cm_object_get_child_by_name(obj, "DR25");
    state->u.f1.reg.dr26 = cm_object_get_child_by_name(obj, "DR26");
    state->u.f1.reg.dr27 = cm_object_get_child_by_name(obj, "DR27");
    state->u.f1.reg.dr28 = cm_object_get_child_by_name(obj, "DR28");
    state->u.f1.reg.dr29 = cm_object_get_child_by_name(obj, "DR29");
    state->u.f1.reg.dr30 = cm_object_get_child_by_name(obj, "DR30");
    state->u.f1.reg.dr31 = cm_object_get_child_by_name(obj, "DR31");
    state->u.f1.reg.dr32 = cm_object_get_child_by_name(obj, "DR32");
    state->u.f1.reg.dr33 = cm_object_get_child_by_name(obj, "DR33");
    state->u.f1.reg.dr34 = cm_object_get_child_by_name(obj, "DR34");
    state->u.f1.reg.dr35 = cm_object_get_child_by_name(obj, "DR35");
    state->u.f1.reg.dr36 = cm_object_get_child_by_name(obj, "DR36");
    state->u.f1.reg.dr37 = cm_object_get_child_by_name(obj, "DR37");
    state->u.f1.reg.dr38 = cm_object_get_child_by_name(obj, "DR38");
    state->u.f1.reg.dr39 = cm_object_get_child_by_name(obj, "DR39");
    state->u.f1.reg.dr40 = cm_object_get_child_by_name(obj, "DR40");
    state->u.f1.reg.dr41 = cm_object_get_child_by_name(obj, "DR41");
    state->u.f1.reg.dr42 = cm_object_get_child_by_name(obj, "DR42");
    state->u.f1.reg.rtccr = cm_object_get_child_by_name(obj, "RTCCR");
    state->u.f1.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->u.f1.reg.csr = cm_object_get_child_by_name(obj, "CSR");
    
    
    // DR1 bitfields.
    state->u.f1.fld.dr1.d1 = cm_object_get_child_by_name(state->u.f1.reg.dr1, "D1");  
    
    // DR2 bitfields.
    state->u.f1.fld.dr2.d2 = cm_object_get_child_by_name(state->u.f1.reg.dr2, "D2");  
    
    // DR3 bitfields.
    state->u.f1.fld.dr3.d3 = cm_object_get_child_by_name(state->u.f1.reg.dr3, "D3");  
    
    // DR4 bitfields.
    state->u.f1.fld.dr4.d4 = cm_object_get_child_by_name(state->u.f1.reg.dr4, "D4");  
    
    // DR5 bitfields.
    state->u.f1.fld.dr5.d5 = cm_object_get_child_by_name(state->u.f1.reg.dr5, "D5");  
    
    // DR6 bitfields.
    state->u.f1.fld.dr6.d6 = cm_object_get_child_by_name(state->u.f1.reg.dr6, "D6");  
    
    // DR7 bitfields.
    state->u.f1.fld.dr7.d7 = cm_object_get_child_by_name(state->u.f1.reg.dr7, "D7");  
    
    // DR8 bitfields.
    state->u.f1.fld.dr8.d8 = cm_object_get_child_by_name(state->u.f1.reg.dr8, "D8");  
    
    // DR9 bitfields.
    state->u.f1.fld.dr9.d9 = cm_object_get_child_by_name(state->u.f1.reg.dr9, "D9");  
    
    // DR10 bitfields.
    state->u.f1.fld.dr10.d10 = cm_object_get_child_by_name(state->u.f1.reg.dr10, "D10");  
    
    // DR11 bitfields.
    state->u.f1.fld.dr11.dr11 = cm_object_get_child_by_name(state->u.f1.reg.dr11, "DR11");  
    
    // DR12 bitfields.
    state->u.f1.fld.dr12.dr12 = cm_object_get_child_by_name(state->u.f1.reg.dr12, "DR12");  
    
    // DR13 bitfields.
    state->u.f1.fld.dr13.dr13 = cm_object_get_child_by_name(state->u.f1.reg.dr13, "DR13");  
    
    // DR14 bitfields.
    state->u.f1.fld.dr14.d14 = cm_object_get_child_by_name(state->u.f1.reg.dr14, "D14");  
    
    // DR15 bitfields.
    state->u.f1.fld.dr15.d15 = cm_object_get_child_by_name(state->u.f1.reg.dr15, "D15");  
    
    // DR16 bitfields.
    state->u.f1.fld.dr16.d16 = cm_object_get_child_by_name(state->u.f1.reg.dr16, "D16");  
    
    // DR17 bitfields.
    state->u.f1.fld.dr17.d17 = cm_object_get_child_by_name(state->u.f1.reg.dr17, "D17");  
    
    // DR18 bitfields.
    state->u.f1.fld.dr18.d18 = cm_object_get_child_by_name(state->u.f1.reg.dr18, "D18");  
    
    // DR19 bitfields.
    state->u.f1.fld.dr19.d19 = cm_object_get_child_by_name(state->u.f1.reg.dr19, "D19");  
    
    // DR20 bitfields.
    state->u.f1.fld.dr20.d20 = cm_object_get_child_by_name(state->u.f1.reg.dr20, "D20");  
    
    // DR21 bitfields.
    state->u.f1.fld.dr21.d21 = cm_object_get_child_by_name(state->u.f1.reg.dr21, "D21");  
    
    // DR22 bitfields.
    state->u.f1.fld.dr22.d22 = cm_object_get_child_by_name(state->u.f1.reg.dr22, "D22");  
    
    // DR23 bitfields.
    state->u.f1.fld.dr23.d23 = cm_object_get_child_by_name(state->u.f1.reg.dr23, "D23");  
    
    // DR24 bitfields.
    state->u.f1.fld.dr24.d24 = cm_object_get_child_by_name(state->u.f1.reg.dr24, "D24");  
    
    // DR25 bitfields.
    state->u.f1.fld.dr25.d25 = cm_object_get_child_by_name(state->u.f1.reg.dr25, "D25");  
    
    // DR26 bitfields.
    state->u.f1.fld.dr26.d26 = cm_object_get_child_by_name(state->u.f1.reg.dr26, "D26");  
    
    // DR27 bitfields.
    state->u.f1.fld.dr27.d27 = cm_object_get_child_by_name(state->u.f1.reg.dr27, "D27");  
    
    // DR28 bitfields.
    state->u.f1.fld.dr28.d28 = cm_object_get_child_by_name(state->u.f1.reg.dr28, "D28");  
    
    // DR29 bitfields.
    state->u.f1.fld.dr29.d29 = cm_object_get_child_by_name(state->u.f1.reg.dr29, "D29");  
    
    // DR30 bitfields.
    state->u.f1.fld.dr30.d30 = cm_object_get_child_by_name(state->u.f1.reg.dr30, "D30");  
    
    // DR31 bitfields.
    state->u.f1.fld.dr31.d31 = cm_object_get_child_by_name(state->u.f1.reg.dr31, "D31");  
    
    // DR32 bitfields.
    state->u.f1.fld.dr32.d32 = cm_object_get_child_by_name(state->u.f1.reg.dr32, "D32");  
    
    // DR33 bitfields.
    state->u.f1.fld.dr33.d33 = cm_object_get_child_by_name(state->u.f1.reg.dr33, "D33");  
    
    // DR34 bitfields.
    state->u.f1.fld.dr34.d34 = cm_object_get_child_by_name(state->u.f1.reg.dr34, "D34");  
    
    // DR35 bitfields.
    state->u.f1.fld.dr35.d35 = cm_object_get_child_by_name(state->u.f1.reg.dr35, "D35");  
    
    // DR36 bitfields.
    state->u.f1.fld.dr36.d36 = cm_object_get_child_by_name(state->u.f1.reg.dr36, "D36");  
    
    // DR37 bitfields.
    state->u.f1.fld.dr37.d37 = cm_object_get_child_by_name(state->u.f1.reg.dr37, "D37");  
    
    // DR38 bitfields.
    state->u.f1.fld.dr38.d38 = cm_object_get_child_by_name(state->u.f1.reg.dr38, "D38");  
    
    // DR39 bitfields.
    state->u.f1.fld.dr39.d39 = cm_object_get_child_by_name(state->u.f1.reg.dr39, "D39");  
    
    // DR40 bitfields.
    state->u.f1.fld.dr40.d40 = cm_object_get_child_by_name(state->u.f1.reg.dr40, "D40");  
    
    // DR41 bitfields.
    state->u.f1.fld.dr41.d41 = cm_object_get_child_by_name(state->u.f1.reg.dr41, "D41");  
    
    // DR42 bitfields.
    state->u.f1.fld.dr42.d42 = cm_object_get_child_by_name(state->u.f1.reg.dr42, "D42");  
    
    // RTCCR bitfields.
    state->u.f1.fld.rtccr.cal = cm_object_get_child_by_name(state->u.f1.reg.rtccr, "CAL"); 
    state->u.f1.fld.rtccr.cco = cm_object_get_child_by_name(state->u.f1.reg.rtccr, "CCO"); 
    state->u.f1.fld.rtccr.asoe = cm_object_get_child_by_name(state->u.f1.reg.rtccr, "ASOE"); 
    state->u.f1.fld.rtccr.asos = cm_object_get_child_by_name(state->u.f1.reg.rtccr, "ASOS");  
    
    // CR bitfields.
    state->u.f1.fld.cr.tpe = cm_object_get_child_by_name(state->u.f1.reg.cr, "TPE"); 
    state->u.f1.fld.cr.tpal = cm_object_get_child_by_name(state->u.f1.reg.cr, "TPAL");  
    
    // CSR bitfields.
    state->u.f1.fld.csr.cte = cm_object_get_child_by_name(state->u.f1.reg.csr, "CTE"); 
    state->u.f1.fld.csr.cti = cm_object_get_child_by_name(state->u.f1.reg.csr, "CTI"); 
    state->u.f1.fld.csr.tpie = cm_object_get_child_by_name(state->u.f1.reg.csr, "TPIE"); 
    state->u.f1.fld.csr.tef = cm_object_get_child_by_name(state->u.f1.reg.csr, "TEF"); 
    state->u.f1.fld.csr.tif = cm_object_get_child_by_name(state->u.f1.reg.csr, "TIF");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_bkp_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32BKPState *state = STM32_BKP_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_bkp_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32BKPState *state = STM32_BKP_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_bkp_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32BKPState *state = STM32_BKP_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_bkp_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32BKPState *state = STM32_BKP_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_bkp_is_enabled(Object *obj)
{
    STM32BKPState *state = STM32_BKP_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_bkp_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32BKPState *state = STM32_BKP_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_bkp_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_BKP)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32BKPState *state = STM32_BKP_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "BKP";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F1:

        if (capabilities->f1.is_103xx ) {

            stm32f103xx_bkp_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f1.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f1.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f1.reg.xxx, &stm32_bkp_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f1.reg.xxx, &stm32_bkp_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f1.reg.xxx, &stm32_bkp_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f1.reg.xxx, &stm32_bkp_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/BKPEN");


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

static void stm32_bkp_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_BKP);
}

static void stm32_bkp_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_bkp_reset_callback;
    dc->realize = stm32_bkp_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_bkp_is_enabled;
}

static const TypeInfo stm32_bkp_type_info = {
    .name = TYPE_STM32_BKP,
    .parent = TYPE_STM32_BKP_PARENT,
    .instance_init = stm32_bkp_instance_init_callback,
    .instance_size = sizeof(STM32BKPState),
    .class_init = stm32_bkp_class_init_callback,
    .class_size = sizeof(STM32BKPClass) };

static void stm32_bkp_register_types(void)
{
    type_register_static(&stm32_bkp_type_info);
}

type_init(stm32_bkp_register_types);

// ----------------------------------------------------------------------------
