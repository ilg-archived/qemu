/*
 * STM32 - GPIO (General purpose I/O) emulation.
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

#include <hw/cortexm/stm32/gpio.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_gpio_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f1.reg.crl = cm_object_get_child_by_name(obj, "CRL");
    state->u.f1.reg.crh = cm_object_get_child_by_name(obj, "CRH");
    state->u.f1.reg.idr = cm_object_get_child_by_name(obj, "IDR");
    state->u.f1.reg.odr = cm_object_get_child_by_name(obj, "ODR");
    state->u.f1.reg.bsrr = cm_object_get_child_by_name(obj, "BSRR");
    state->u.f1.reg.brr = cm_object_get_child_by_name(obj, "BRR");
    state->u.f1.reg.lckr = cm_object_get_child_by_name(obj, "LCKR");
    
    
    // CRL bitfields.
    state->u.f1.fld.crl.mode0 = cm_object_get_child_by_name(state->u.f1.reg.crl, "MODE0"); 
    state->u.f1.fld.crl.cnf0 = cm_object_get_child_by_name(state->u.f1.reg.crl, "CNF0"); 
    state->u.f1.fld.crl.mode1 = cm_object_get_child_by_name(state->u.f1.reg.crl, "MODE1"); 
    state->u.f1.fld.crl.cnf1 = cm_object_get_child_by_name(state->u.f1.reg.crl, "CNF1"); 
    state->u.f1.fld.crl.mode2 = cm_object_get_child_by_name(state->u.f1.reg.crl, "MODE2"); 
    state->u.f1.fld.crl.cnf2 = cm_object_get_child_by_name(state->u.f1.reg.crl, "CNF2"); 
    state->u.f1.fld.crl.mode3 = cm_object_get_child_by_name(state->u.f1.reg.crl, "MODE3"); 
    state->u.f1.fld.crl.cnf3 = cm_object_get_child_by_name(state->u.f1.reg.crl, "CNF3"); 
    state->u.f1.fld.crl.mode4 = cm_object_get_child_by_name(state->u.f1.reg.crl, "MODE4"); 
    state->u.f1.fld.crl.cnf4 = cm_object_get_child_by_name(state->u.f1.reg.crl, "CNF4"); 
    state->u.f1.fld.crl.mode5 = cm_object_get_child_by_name(state->u.f1.reg.crl, "MODE5"); 
    state->u.f1.fld.crl.cnf5 = cm_object_get_child_by_name(state->u.f1.reg.crl, "CNF5"); 
    state->u.f1.fld.crl.mode6 = cm_object_get_child_by_name(state->u.f1.reg.crl, "MODE6"); 
    state->u.f1.fld.crl.cnf6 = cm_object_get_child_by_name(state->u.f1.reg.crl, "CNF6"); 
    state->u.f1.fld.crl.mode7 = cm_object_get_child_by_name(state->u.f1.reg.crl, "MODE7"); 
    state->u.f1.fld.crl.cnf7 = cm_object_get_child_by_name(state->u.f1.reg.crl, "CNF7");  
    
    // CRH bitfields.
    state->u.f1.fld.crh.mode8 = cm_object_get_child_by_name(state->u.f1.reg.crh, "MODE8"); 
    state->u.f1.fld.crh.cnf8 = cm_object_get_child_by_name(state->u.f1.reg.crh, "CNF8"); 
    state->u.f1.fld.crh.mode9 = cm_object_get_child_by_name(state->u.f1.reg.crh, "MODE9"); 
    state->u.f1.fld.crh.cnf9 = cm_object_get_child_by_name(state->u.f1.reg.crh, "CNF9"); 
    state->u.f1.fld.crh.mode10 = cm_object_get_child_by_name(state->u.f1.reg.crh, "MODE10"); 
    state->u.f1.fld.crh.cnf10 = cm_object_get_child_by_name(state->u.f1.reg.crh, "CNF10"); 
    state->u.f1.fld.crh.mode11 = cm_object_get_child_by_name(state->u.f1.reg.crh, "MODE11"); 
    state->u.f1.fld.crh.cnf11 = cm_object_get_child_by_name(state->u.f1.reg.crh, "CNF11"); 
    state->u.f1.fld.crh.mode12 = cm_object_get_child_by_name(state->u.f1.reg.crh, "MODE12"); 
    state->u.f1.fld.crh.cnf12 = cm_object_get_child_by_name(state->u.f1.reg.crh, "CNF12"); 
    state->u.f1.fld.crh.mode13 = cm_object_get_child_by_name(state->u.f1.reg.crh, "MODE13"); 
    state->u.f1.fld.crh.cnf13 = cm_object_get_child_by_name(state->u.f1.reg.crh, "CNF13"); 
    state->u.f1.fld.crh.mode14 = cm_object_get_child_by_name(state->u.f1.reg.crh, "MODE14"); 
    state->u.f1.fld.crh.cnf14 = cm_object_get_child_by_name(state->u.f1.reg.crh, "CNF14"); 
    state->u.f1.fld.crh.mode15 = cm_object_get_child_by_name(state->u.f1.reg.crh, "MODE15"); 
    state->u.f1.fld.crh.cnf15 = cm_object_get_child_by_name(state->u.f1.reg.crh, "CNF15");  
    
    // IDR bitfields.
    state->u.f1.fld.idr.idr0 = cm_object_get_child_by_name(state->u.f1.reg.idr, "IDR0"); 
    state->u.f1.fld.idr.idr1 = cm_object_get_child_by_name(state->u.f1.reg.idr, "IDR1"); 
    state->u.f1.fld.idr.idr2 = cm_object_get_child_by_name(state->u.f1.reg.idr, "IDR2"); 
    state->u.f1.fld.idr.idr3 = cm_object_get_child_by_name(state->u.f1.reg.idr, "IDR3"); 
    state->u.f1.fld.idr.idr4 = cm_object_get_child_by_name(state->u.f1.reg.idr, "IDR4"); 
    state->u.f1.fld.idr.idr5 = cm_object_get_child_by_name(state->u.f1.reg.idr, "IDR5"); 
    state->u.f1.fld.idr.idr6 = cm_object_get_child_by_name(state->u.f1.reg.idr, "IDR6"); 
    state->u.f1.fld.idr.idr7 = cm_object_get_child_by_name(state->u.f1.reg.idr, "IDR7"); 
    state->u.f1.fld.idr.idr8 = cm_object_get_child_by_name(state->u.f1.reg.idr, "IDR8"); 
    state->u.f1.fld.idr.idr9 = cm_object_get_child_by_name(state->u.f1.reg.idr, "IDR9"); 
    state->u.f1.fld.idr.idr10 = cm_object_get_child_by_name(state->u.f1.reg.idr, "IDR10"); 
    state->u.f1.fld.idr.idr11 = cm_object_get_child_by_name(state->u.f1.reg.idr, "IDR11"); 
    state->u.f1.fld.idr.idr12 = cm_object_get_child_by_name(state->u.f1.reg.idr, "IDR12"); 
    state->u.f1.fld.idr.idr13 = cm_object_get_child_by_name(state->u.f1.reg.idr, "IDR13"); 
    state->u.f1.fld.idr.idr14 = cm_object_get_child_by_name(state->u.f1.reg.idr, "IDR14"); 
    state->u.f1.fld.idr.idr15 = cm_object_get_child_by_name(state->u.f1.reg.idr, "IDR15");  
    
    // ODR bitfields.
    state->u.f1.fld.odr.odr0 = cm_object_get_child_by_name(state->u.f1.reg.odr, "ODR0"); 
    state->u.f1.fld.odr.odr1 = cm_object_get_child_by_name(state->u.f1.reg.odr, "ODR1"); 
    state->u.f1.fld.odr.odr2 = cm_object_get_child_by_name(state->u.f1.reg.odr, "ODR2"); 
    state->u.f1.fld.odr.odr3 = cm_object_get_child_by_name(state->u.f1.reg.odr, "ODR3"); 
    state->u.f1.fld.odr.odr4 = cm_object_get_child_by_name(state->u.f1.reg.odr, "ODR4"); 
    state->u.f1.fld.odr.odr5 = cm_object_get_child_by_name(state->u.f1.reg.odr, "ODR5"); 
    state->u.f1.fld.odr.odr6 = cm_object_get_child_by_name(state->u.f1.reg.odr, "ODR6"); 
    state->u.f1.fld.odr.odr7 = cm_object_get_child_by_name(state->u.f1.reg.odr, "ODR7"); 
    state->u.f1.fld.odr.odr8 = cm_object_get_child_by_name(state->u.f1.reg.odr, "ODR8"); 
    state->u.f1.fld.odr.odr9 = cm_object_get_child_by_name(state->u.f1.reg.odr, "ODR9"); 
    state->u.f1.fld.odr.odr10 = cm_object_get_child_by_name(state->u.f1.reg.odr, "ODR10"); 
    state->u.f1.fld.odr.odr11 = cm_object_get_child_by_name(state->u.f1.reg.odr, "ODR11"); 
    state->u.f1.fld.odr.odr12 = cm_object_get_child_by_name(state->u.f1.reg.odr, "ODR12"); 
    state->u.f1.fld.odr.odr13 = cm_object_get_child_by_name(state->u.f1.reg.odr, "ODR13"); 
    state->u.f1.fld.odr.odr14 = cm_object_get_child_by_name(state->u.f1.reg.odr, "ODR14"); 
    state->u.f1.fld.odr.odr15 = cm_object_get_child_by_name(state->u.f1.reg.odr, "ODR15");  
    
    // BSRR bitfields.
    state->u.f1.fld.bsrr.bs0 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BS0"); 
    state->u.f1.fld.bsrr.bs1 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BS1"); 
    state->u.f1.fld.bsrr.bs2 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BS2"); 
    state->u.f1.fld.bsrr.bs3 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BS3"); 
    state->u.f1.fld.bsrr.bs4 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BS4"); 
    state->u.f1.fld.bsrr.bs5 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BS5"); 
    state->u.f1.fld.bsrr.bs6 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BS6"); 
    state->u.f1.fld.bsrr.bs7 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BS7"); 
    state->u.f1.fld.bsrr.bs8 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BS8"); 
    state->u.f1.fld.bsrr.bs9 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BS9"); 
    state->u.f1.fld.bsrr.bs10 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BS10"); 
    state->u.f1.fld.bsrr.bs11 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BS11"); 
    state->u.f1.fld.bsrr.bs12 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BS12"); 
    state->u.f1.fld.bsrr.bs13 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BS13"); 
    state->u.f1.fld.bsrr.bs14 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BS14"); 
    state->u.f1.fld.bsrr.bs15 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BS15"); 
    state->u.f1.fld.bsrr.br0 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BR0"); 
    state->u.f1.fld.bsrr.br1 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BR1"); 
    state->u.f1.fld.bsrr.br2 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BR2"); 
    state->u.f1.fld.bsrr.br3 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BR3"); 
    state->u.f1.fld.bsrr.br4 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BR4"); 
    state->u.f1.fld.bsrr.br5 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BR5"); 
    state->u.f1.fld.bsrr.br6 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BR6"); 
    state->u.f1.fld.bsrr.br7 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BR7"); 
    state->u.f1.fld.bsrr.br8 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BR8"); 
    state->u.f1.fld.bsrr.br9 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BR9"); 
    state->u.f1.fld.bsrr.br10 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BR10"); 
    state->u.f1.fld.bsrr.br11 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BR11"); 
    state->u.f1.fld.bsrr.br12 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BR12"); 
    state->u.f1.fld.bsrr.br13 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BR13"); 
    state->u.f1.fld.bsrr.br14 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BR14"); 
    state->u.f1.fld.bsrr.br15 = cm_object_get_child_by_name(state->u.f1.reg.bsrr, "BR15");  
    
    // BRR bitfields.
    state->u.f1.fld.brr.br0 = cm_object_get_child_by_name(state->u.f1.reg.brr, "BR0"); 
    state->u.f1.fld.brr.br1 = cm_object_get_child_by_name(state->u.f1.reg.brr, "BR1"); 
    state->u.f1.fld.brr.br2 = cm_object_get_child_by_name(state->u.f1.reg.brr, "BR2"); 
    state->u.f1.fld.brr.br3 = cm_object_get_child_by_name(state->u.f1.reg.brr, "BR3"); 
    state->u.f1.fld.brr.br4 = cm_object_get_child_by_name(state->u.f1.reg.brr, "BR4"); 
    state->u.f1.fld.brr.br5 = cm_object_get_child_by_name(state->u.f1.reg.brr, "BR5"); 
    state->u.f1.fld.brr.br6 = cm_object_get_child_by_name(state->u.f1.reg.brr, "BR6"); 
    state->u.f1.fld.brr.br7 = cm_object_get_child_by_name(state->u.f1.reg.brr, "BR7"); 
    state->u.f1.fld.brr.br8 = cm_object_get_child_by_name(state->u.f1.reg.brr, "BR8"); 
    state->u.f1.fld.brr.br9 = cm_object_get_child_by_name(state->u.f1.reg.brr, "BR9"); 
    state->u.f1.fld.brr.br10 = cm_object_get_child_by_name(state->u.f1.reg.brr, "BR10"); 
    state->u.f1.fld.brr.br11 = cm_object_get_child_by_name(state->u.f1.reg.brr, "BR11"); 
    state->u.f1.fld.brr.br12 = cm_object_get_child_by_name(state->u.f1.reg.brr, "BR12"); 
    state->u.f1.fld.brr.br13 = cm_object_get_child_by_name(state->u.f1.reg.brr, "BR13"); 
    state->u.f1.fld.brr.br14 = cm_object_get_child_by_name(state->u.f1.reg.brr, "BR14"); 
    state->u.f1.fld.brr.br15 = cm_object_get_child_by_name(state->u.f1.reg.brr, "BR15");  
    
    // LCKR bitfields.
    state->u.f1.fld.lckr.lck0 = cm_object_get_child_by_name(state->u.f1.reg.lckr, "LCK0"); 
    state->u.f1.fld.lckr.lck1 = cm_object_get_child_by_name(state->u.f1.reg.lckr, "LCK1"); 
    state->u.f1.fld.lckr.lck2 = cm_object_get_child_by_name(state->u.f1.reg.lckr, "LCK2"); 
    state->u.f1.fld.lckr.lck3 = cm_object_get_child_by_name(state->u.f1.reg.lckr, "LCK3"); 
    state->u.f1.fld.lckr.lck4 = cm_object_get_child_by_name(state->u.f1.reg.lckr, "LCK4"); 
    state->u.f1.fld.lckr.lck5 = cm_object_get_child_by_name(state->u.f1.reg.lckr, "LCK5"); 
    state->u.f1.fld.lckr.lck6 = cm_object_get_child_by_name(state->u.f1.reg.lckr, "LCK6"); 
    state->u.f1.fld.lckr.lck7 = cm_object_get_child_by_name(state->u.f1.reg.lckr, "LCK7"); 
    state->u.f1.fld.lckr.lck8 = cm_object_get_child_by_name(state->u.f1.reg.lckr, "LCK8"); 
    state->u.f1.fld.lckr.lck9 = cm_object_get_child_by_name(state->u.f1.reg.lckr, "LCK9"); 
    state->u.f1.fld.lckr.lck10 = cm_object_get_child_by_name(state->u.f1.reg.lckr, "LCK10"); 
    state->u.f1.fld.lckr.lck11 = cm_object_get_child_by_name(state->u.f1.reg.lckr, "LCK11"); 
    state->u.f1.fld.lckr.lck12 = cm_object_get_child_by_name(state->u.f1.reg.lckr, "LCK12"); 
    state->u.f1.fld.lckr.lck13 = cm_object_get_child_by_name(state->u.f1.reg.lckr, "LCK13"); 
    state->u.f1.fld.lckr.lck14 = cm_object_get_child_by_name(state->u.f1.reg.lckr, "LCK14"); 
    state->u.f1.fld.lckr.lck15 = cm_object_get_child_by_name(state->u.f1.reg.lckr, "LCK15"); 
    state->u.f1.fld.lckr.lckk = cm_object_get_child_by_name(state->u.f1.reg.lckr, "LCKK");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_gpio_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_gpio_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_gpio_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_gpio_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_gpio_is_enabled(Object *obj)
{
    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_gpio_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    // Capabilities are not yet available.

    cm_object_property_add_int(obj, "port-index",
            (const int *) &state->port_index);
    state->port_index = STM32_PORT_GPIO_UNDEFINED;

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_gpio_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_GPIO)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32GPIOState *state = STM32_GPIO_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "GPIO";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F1:

        if (capabilities->f1.is_103xx ) {

            stm32f103xx_gpio_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f1.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f1.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f1.reg.xxx, &stm32_gpio_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f1.reg.xxx, &stm32_gpio_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f1.reg.xxx, &stm32_gpio_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f1.reg.xxx, &stm32_gpio_xxx_post_write_callback);

            // TODO: add interrupts.

           // TODO: remove this if the peripheral is always enabled.
           snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/GPIO%dEN",
                1 + state->port_index - STM32_PORT_GPIO1);


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

static void stm32_gpio_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_GPIO);
}

static void stm32_gpio_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_gpio_reset_callback;
    dc->realize = stm32_gpio_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_gpio_is_enabled;
}

static const TypeInfo stm32_gpio_type_info = {
    .name = TYPE_STM32_GPIO,
    .parent = TYPE_STM32_GPIO_PARENT,
    .instance_init = stm32_gpio_instance_init_callback,
    .instance_size = sizeof(STM32GPIOState),
    .class_init = stm32_gpio_class_init_callback,
    .class_size = sizeof(STM32GPIOClass) };

static void stm32_gpio_register_types(void)
{
    type_register_static(&stm32_gpio_type_info);
}

type_init(stm32_gpio_register_types);

// ----------------------------------------------------------------------------
