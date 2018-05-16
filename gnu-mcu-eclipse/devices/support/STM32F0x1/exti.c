/*
 * STM32 - EXTI (External interrupt/event controller) emulation.
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

#include <hw/cortexm/stm32/exti.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_exti_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32EXTIState *state = STM32_EXTI_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f0.reg.imr = cm_object_get_child_by_name(obj, "IMR");
    state->u.f0.reg.emr = cm_object_get_child_by_name(obj, "EMR");
    state->u.f0.reg.rtsr = cm_object_get_child_by_name(obj, "RTSR");
    state->u.f0.reg.ftsr = cm_object_get_child_by_name(obj, "FTSR");
    state->u.f0.reg.swier = cm_object_get_child_by_name(obj, "SWIER");
    state->u.f0.reg.pr = cm_object_get_child_by_name(obj, "PR");
    
    
    // IMR bitfields.
    state->u.f0.fld.imr.mr0 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR0"); 
    state->u.f0.fld.imr.mr1 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR1"); 
    state->u.f0.fld.imr.mr2 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR2"); 
    state->u.f0.fld.imr.mr3 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR3"); 
    state->u.f0.fld.imr.mr4 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR4"); 
    state->u.f0.fld.imr.mr5 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR5"); 
    state->u.f0.fld.imr.mr6 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR6"); 
    state->u.f0.fld.imr.mr7 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR7"); 
    state->u.f0.fld.imr.mr8 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR8"); 
    state->u.f0.fld.imr.mr9 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR9"); 
    state->u.f0.fld.imr.mr10 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR10"); 
    state->u.f0.fld.imr.mr11 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR11"); 
    state->u.f0.fld.imr.mr12 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR12"); 
    state->u.f0.fld.imr.mr13 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR13"); 
    state->u.f0.fld.imr.mr14 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR14"); 
    state->u.f0.fld.imr.mr15 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR15"); 
    state->u.f0.fld.imr.mr16 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR16"); 
    state->u.f0.fld.imr.mr17 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR17"); 
    state->u.f0.fld.imr.mr18 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR18"); 
    state->u.f0.fld.imr.mr19 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR19"); 
    state->u.f0.fld.imr.mr20 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR20"); 
    state->u.f0.fld.imr.mr21 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR21"); 
    state->u.f0.fld.imr.mr22 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR22"); 
    state->u.f0.fld.imr.mr23 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR23"); 
    state->u.f0.fld.imr.mr24 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR24"); 
    state->u.f0.fld.imr.mr25 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR25"); 
    state->u.f0.fld.imr.mr26 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR26"); 
    state->u.f0.fld.imr.mr27 = cm_object_get_child_by_name(state->u.f0.reg.imr, "MR27");  
    
    // EMR bitfields.
    state->u.f0.fld.emr.mr0 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR0"); 
    state->u.f0.fld.emr.mr1 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR1"); 
    state->u.f0.fld.emr.mr2 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR2"); 
    state->u.f0.fld.emr.mr3 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR3"); 
    state->u.f0.fld.emr.mr4 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR4"); 
    state->u.f0.fld.emr.mr5 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR5"); 
    state->u.f0.fld.emr.mr6 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR6"); 
    state->u.f0.fld.emr.mr7 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR7"); 
    state->u.f0.fld.emr.mr8 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR8"); 
    state->u.f0.fld.emr.mr9 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR9"); 
    state->u.f0.fld.emr.mr10 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR10"); 
    state->u.f0.fld.emr.mr11 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR11"); 
    state->u.f0.fld.emr.mr12 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR12"); 
    state->u.f0.fld.emr.mr13 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR13"); 
    state->u.f0.fld.emr.mr14 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR14"); 
    state->u.f0.fld.emr.mr15 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR15"); 
    state->u.f0.fld.emr.mr16 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR16"); 
    state->u.f0.fld.emr.mr17 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR17"); 
    state->u.f0.fld.emr.mr18 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR18"); 
    state->u.f0.fld.emr.mr19 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR19"); 
    state->u.f0.fld.emr.mr20 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR20"); 
    state->u.f0.fld.emr.mr21 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR21"); 
    state->u.f0.fld.emr.mr22 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR22"); 
    state->u.f0.fld.emr.mr23 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR23"); 
    state->u.f0.fld.emr.mr24 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR24"); 
    state->u.f0.fld.emr.mr25 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR25"); 
    state->u.f0.fld.emr.mr26 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR26"); 
    state->u.f0.fld.emr.mr27 = cm_object_get_child_by_name(state->u.f0.reg.emr, "MR27");  
    
    // RTSR bitfields.
    state->u.f0.fld.rtsr.tr0 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR0"); 
    state->u.f0.fld.rtsr.tr1 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR1"); 
    state->u.f0.fld.rtsr.tr2 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR2"); 
    state->u.f0.fld.rtsr.tr3 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR3"); 
    state->u.f0.fld.rtsr.tr4 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR4"); 
    state->u.f0.fld.rtsr.tr5 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR5"); 
    state->u.f0.fld.rtsr.tr6 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR6"); 
    state->u.f0.fld.rtsr.tr7 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR7"); 
    state->u.f0.fld.rtsr.tr8 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR8"); 
    state->u.f0.fld.rtsr.tr9 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR9"); 
    state->u.f0.fld.rtsr.tr10 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR10"); 
    state->u.f0.fld.rtsr.tr11 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR11"); 
    state->u.f0.fld.rtsr.tr12 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR12"); 
    state->u.f0.fld.rtsr.tr13 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR13"); 
    state->u.f0.fld.rtsr.tr14 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR14"); 
    state->u.f0.fld.rtsr.tr15 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR15"); 
    state->u.f0.fld.rtsr.tr16 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR16"); 
    state->u.f0.fld.rtsr.tr17 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR17"); 
    state->u.f0.fld.rtsr.tr19 = cm_object_get_child_by_name(state->u.f0.reg.rtsr, "TR19");  
    
    // FTSR bitfields.
    state->u.f0.fld.ftsr.tr0 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR0"); 
    state->u.f0.fld.ftsr.tr1 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR1"); 
    state->u.f0.fld.ftsr.tr2 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR2"); 
    state->u.f0.fld.ftsr.tr3 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR3"); 
    state->u.f0.fld.ftsr.tr4 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR4"); 
    state->u.f0.fld.ftsr.tr5 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR5"); 
    state->u.f0.fld.ftsr.tr6 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR6"); 
    state->u.f0.fld.ftsr.tr7 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR7"); 
    state->u.f0.fld.ftsr.tr8 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR8"); 
    state->u.f0.fld.ftsr.tr9 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR9"); 
    state->u.f0.fld.ftsr.tr10 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR10"); 
    state->u.f0.fld.ftsr.tr11 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR11"); 
    state->u.f0.fld.ftsr.tr12 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR12"); 
    state->u.f0.fld.ftsr.tr13 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR13"); 
    state->u.f0.fld.ftsr.tr14 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR14"); 
    state->u.f0.fld.ftsr.tr15 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR15"); 
    state->u.f0.fld.ftsr.tr16 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR16"); 
    state->u.f0.fld.ftsr.tr17 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR17"); 
    state->u.f0.fld.ftsr.tr19 = cm_object_get_child_by_name(state->u.f0.reg.ftsr, "TR19");  
    
    // SWIER bitfields.
    state->u.f0.fld.swier.swier0 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER0"); 
    state->u.f0.fld.swier.swier1 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER1"); 
    state->u.f0.fld.swier.swier2 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER2"); 
    state->u.f0.fld.swier.swier3 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER3"); 
    state->u.f0.fld.swier.swier4 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER4"); 
    state->u.f0.fld.swier.swier5 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER5"); 
    state->u.f0.fld.swier.swier6 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER6"); 
    state->u.f0.fld.swier.swier7 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER7"); 
    state->u.f0.fld.swier.swier8 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER8"); 
    state->u.f0.fld.swier.swier9 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER9"); 
    state->u.f0.fld.swier.swier10 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER10"); 
    state->u.f0.fld.swier.swier11 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER11"); 
    state->u.f0.fld.swier.swier12 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER12"); 
    state->u.f0.fld.swier.swier13 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER13"); 
    state->u.f0.fld.swier.swier14 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER14"); 
    state->u.f0.fld.swier.swier15 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER15"); 
    state->u.f0.fld.swier.swier16 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER16"); 
    state->u.f0.fld.swier.swier17 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER17"); 
    state->u.f0.fld.swier.swier19 = cm_object_get_child_by_name(state->u.f0.reg.swier, "SWIER19");  
    
    // PR bitfields.
    state->u.f0.fld.pr.pr0 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR0"); 
    state->u.f0.fld.pr.pr1 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR1"); 
    state->u.f0.fld.pr.pr2 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR2"); 
    state->u.f0.fld.pr.pr3 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR3"); 
    state->u.f0.fld.pr.pr4 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR4"); 
    state->u.f0.fld.pr.pr5 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR5"); 
    state->u.f0.fld.pr.pr6 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR6"); 
    state->u.f0.fld.pr.pr7 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR7"); 
    state->u.f0.fld.pr.pr8 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR8"); 
    state->u.f0.fld.pr.pr9 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR9"); 
    state->u.f0.fld.pr.pr10 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR10"); 
    state->u.f0.fld.pr.pr11 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR11"); 
    state->u.f0.fld.pr.pr12 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR12"); 
    state->u.f0.fld.pr.pr13 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR13"); 
    state->u.f0.fld.pr.pr14 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR14"); 
    state->u.f0.fld.pr.pr15 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR15"); 
    state->u.f0.fld.pr.pr16 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR16"); 
    state->u.f0.fld.pr.pr17 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR17"); 
    state->u.f0.fld.pr.pr19 = cm_object_get_child_by_name(state->u.f0.reg.pr, "PR19");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_exti_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32EXTIState *state = STM32_EXTI_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_exti_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32EXTIState *state = STM32_EXTI_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_exti_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32EXTIState *state = STM32_EXTI_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_exti_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32EXTIState *state = STM32_EXTI_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_exti_is_enabled(Object *obj)
{
    STM32EXTIState *state = STM32_EXTI_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_exti_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32EXTIState *state = STM32_EXTI_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_exti_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_EXTI)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32EXTIState *state = STM32_EXTI_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "EXTI";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x1 ) {

            stm32f0x1_exti_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_exti_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f0.reg.xxx, &stm32_exti_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_exti_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f0.reg.xxx, &stm32_exti_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/EXTIEN");


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

static void stm32_exti_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_EXTI);
}

static void stm32_exti_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_exti_reset_callback;
    dc->realize = stm32_exti_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_exti_is_enabled;
}

static const TypeInfo stm32_exti_type_info = {
    .name = TYPE_STM32_EXTI,
    .parent = TYPE_STM32_EXTI_PARENT,
    .instance_init = stm32_exti_instance_init_callback,
    .instance_size = sizeof(STM32EXTIState),
    .class_init = stm32_exti_class_init_callback,
    .class_size = sizeof(STM32EXTIClass) };

static void stm32_exti_register_types(void)
{
    type_register_static(&stm32_exti_type_info);
}

type_init(stm32_exti_register_types);

// ----------------------------------------------------------------------------
