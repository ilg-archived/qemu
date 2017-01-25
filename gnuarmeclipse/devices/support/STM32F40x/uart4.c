/*
 * STM32 - UART (Universal synchronous asynchronous receiver transmitter) emulation.
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

#include <hw/cortexm/stm32/uart.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f40x_uart_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32UARTState *state = STM32_UART_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->u.f4.reg.dr = cm_object_get_child_by_name(obj, "DR");
    state->u.f4.reg.brr = cm_object_get_child_by_name(obj, "BRR");
    state->u.f4.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
    state->u.f4.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
    state->u.f4.reg.cr3 = cm_object_get_child_by_name(obj, "CR3");
    
    
    // SR bitfields.
    state->u.f4.fld.sr.pe = cm_object_get_child_by_name(state->u.f4.reg.sr, "PE"); 
    state->u.f4.fld.sr.fe = cm_object_get_child_by_name(state->u.f4.reg.sr, "FE"); 
    state->u.f4.fld.sr.nf = cm_object_get_child_by_name(state->u.f4.reg.sr, "NF"); 
    state->u.f4.fld.sr.ore = cm_object_get_child_by_name(state->u.f4.reg.sr, "ORE"); 
    state->u.f4.fld.sr.idle = cm_object_get_child_by_name(state->u.f4.reg.sr, "IDLE"); 
    state->u.f4.fld.sr.rxne = cm_object_get_child_by_name(state->u.f4.reg.sr, "RXNE"); 
    state->u.f4.fld.sr.tc = cm_object_get_child_by_name(state->u.f4.reg.sr, "TC"); 
    state->u.f4.fld.sr.txe = cm_object_get_child_by_name(state->u.f4.reg.sr, "TXE"); 
    state->u.f4.fld.sr.lbd = cm_object_get_child_by_name(state->u.f4.reg.sr, "LBD");  
    
    // DR bitfields.
    state->u.f4.fld.dr.dr = cm_object_get_child_by_name(state->u.f4.reg.dr, "DR");  
    
    // BRR bitfields.
    state->u.f4.fld.brr.div_fraction = cm_object_get_child_by_name(state->u.f4.reg.brr, "DIV_Fraction"); 
    state->u.f4.fld.brr.div_mantissa = cm_object_get_child_by_name(state->u.f4.reg.brr, "DIV_Mantissa");  
    
    // CR1 bitfields.
    state->u.f4.fld.cr1.sbk = cm_object_get_child_by_name(state->u.f4.reg.cr1, "SBK"); 
    state->u.f4.fld.cr1.rwu = cm_object_get_child_by_name(state->u.f4.reg.cr1, "RWU"); 
    state->u.f4.fld.cr1.re = cm_object_get_child_by_name(state->u.f4.reg.cr1, "RE"); 
    state->u.f4.fld.cr1.te = cm_object_get_child_by_name(state->u.f4.reg.cr1, "TE"); 
    state->u.f4.fld.cr1.idleie = cm_object_get_child_by_name(state->u.f4.reg.cr1, "IDLEIE"); 
    state->u.f4.fld.cr1.rxneie = cm_object_get_child_by_name(state->u.f4.reg.cr1, "RXNEIE"); 
    state->u.f4.fld.cr1.tcie = cm_object_get_child_by_name(state->u.f4.reg.cr1, "TCIE"); 
    state->u.f4.fld.cr1.txeie = cm_object_get_child_by_name(state->u.f4.reg.cr1, "TXEIE"); 
    state->u.f4.fld.cr1.peie = cm_object_get_child_by_name(state->u.f4.reg.cr1, "PEIE"); 
    state->u.f4.fld.cr1.ps = cm_object_get_child_by_name(state->u.f4.reg.cr1, "PS"); 
    state->u.f4.fld.cr1.pce = cm_object_get_child_by_name(state->u.f4.reg.cr1, "PCE"); 
    state->u.f4.fld.cr1.wake = cm_object_get_child_by_name(state->u.f4.reg.cr1, "WAKE"); 
    state->u.f4.fld.cr1.m = cm_object_get_child_by_name(state->u.f4.reg.cr1, "M"); 
    state->u.f4.fld.cr1.ue = cm_object_get_child_by_name(state->u.f4.reg.cr1, "UE"); 
    state->u.f4.fld.cr1.over8 = cm_object_get_child_by_name(state->u.f4.reg.cr1, "OVER8");  
    
    // CR2 bitfields.
    state->u.f4.fld.cr2.add = cm_object_get_child_by_name(state->u.f4.reg.cr2, "ADD"); 
    state->u.f4.fld.cr2.lbdl = cm_object_get_child_by_name(state->u.f4.reg.cr2, "LBDL"); 
    state->u.f4.fld.cr2.lbdie = cm_object_get_child_by_name(state->u.f4.reg.cr2, "LBDIE"); 
    state->u.f4.fld.cr2.stop = cm_object_get_child_by_name(state->u.f4.reg.cr2, "STOP"); 
    state->u.f4.fld.cr2.linen = cm_object_get_child_by_name(state->u.f4.reg.cr2, "LINEN");  
    
    // CR3 bitfields.
    state->u.f4.fld.cr3.eie = cm_object_get_child_by_name(state->u.f4.reg.cr3, "EIE"); 
    state->u.f4.fld.cr3.iren = cm_object_get_child_by_name(state->u.f4.reg.cr3, "IREN"); 
    state->u.f4.fld.cr3.irlp = cm_object_get_child_by_name(state->u.f4.reg.cr3, "IRLP"); 
    state->u.f4.fld.cr3.hdsel = cm_object_get_child_by_name(state->u.f4.reg.cr3, "HDSEL"); 
    state->u.f4.fld.cr3.dmar = cm_object_get_child_by_name(state->u.f4.reg.cr3, "DMAR"); 
    state->u.f4.fld.cr3.dmat = cm_object_get_child_by_name(state->u.f4.reg.cr3, "DMAT"); 
    state->u.f4.fld.cr3.onebit = cm_object_get_child_by_name(state->u.f4.reg.cr3, "ONEBIT");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_uart_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32UARTState *state = STM32_UART_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_uart_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32UARTState *state = STM32_UART_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_uart_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32UARTState *state = STM32_UART_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_uart_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32UARTState *state = STM32_UART_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_uart_is_enabled(Object *obj)
{
    STM32UARTState *state = STM32_UART_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_uart_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32UARTState *state = STM32_UART_STATE(obj);

    // Capabilities are not yet available.

    cm_object_property_add_int(obj, "port-index",
            (const int *) &state->port_index);
    state->port_index = STM32_PORT_UART_UNDEFINED;

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_uart_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_UART)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32UARTState *state = STM32_UART_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "UART";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_40x ) {

            stm32f40x_uart_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_uart_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_uart_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_uart_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_uart_xxx_post_write_callback);

            // TODO: add interrupts.

           // TODO: remove this if the peripheral is always enabled.
           snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/UART%dEN",
                1 + state->port_index - STM32_PORT_UART1);


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

static void stm32_uart_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_UART);
}

static void stm32_uart_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_uart_reset_callback;
    dc->realize = stm32_uart_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_uart_is_enabled;
}

static const TypeInfo stm32_uart_type_info = {
    .name = TYPE_STM32_UART,
    .parent = TYPE_STM32_UART_PARENT,
    .instance_init = stm32_uart_instance_init_callback,
    .instance_size = sizeof(STM32UARTState),
    .class_init = stm32_uart_class_init_callback,
    .class_size = sizeof(STM32UARTClass) };

static void stm32_uart_register_types(void)
{
    type_register_static(&stm32_uart_type_info);
}

type_init(stm32_uart_register_types);

// ----------------------------------------------------------------------------
