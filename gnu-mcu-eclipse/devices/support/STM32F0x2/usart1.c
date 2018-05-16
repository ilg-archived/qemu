/*
 * STM32- USART(Universal synchronous asynchronous receiver transmitter) emulation.
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

#include <hw/cortexm/stm32/usart.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x2_usart_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32USARTState *state = STM32_USART_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
state->u.f0.reg.cr1= cm_object_get_child_by_name(obj, "CR1");
state->u.f0.reg.cr2= cm_object_get_child_by_name(obj, "CR2");
state->u.f0.reg.cr3= cm_object_get_child_by_name(obj, "CR3");
state->u.f0.reg.brr= cm_object_get_child_by_name(obj, "BRR");
state->u.f0.reg.gtpr= cm_object_get_child_by_name(obj, "GTPR");
state->u.f0.reg.rtor= cm_object_get_child_by_name(obj, "RTOR");
state->u.f0.reg.rqr= cm_object_get_child_by_name(obj, "RQR");
state->u.f0.reg.isr= cm_object_get_child_by_name(obj, "ISR");
state->u.f0.reg.icr= cm_object_get_child_by_name(obj, "ICR");
state->u.f0.reg.rdr= cm_object_get_child_by_name(obj, "RDR");
state->u.f0.reg.tdr= cm_object_get_child_by_name(obj, "TDR");
// CR1bitfields.
state->u.f0.fld.cr1.ue= cm_object_get_child_by_name(state->u.f0.reg.cr1, "UE"); 
state->u.f0.fld.cr1.uesm= cm_object_get_child_by_name(state->u.f0.reg.cr1, "UESM"); 
state->u.f0.fld.cr1.re= cm_object_get_child_by_name(state->u.f0.reg.cr1, "RE"); 
state->u.f0.fld.cr1.te= cm_object_get_child_by_name(state->u.f0.reg.cr1, "TE"); 
state->u.f0.fld.cr1.idleie= cm_object_get_child_by_name(state->u.f0.reg.cr1, "IDLEIE"); 
state->u.f0.fld.cr1.rxneie= cm_object_get_child_by_name(state->u.f0.reg.cr1, "RXNEIE"); 
state->u.f0.fld.cr1.tcie= cm_object_get_child_by_name(state->u.f0.reg.cr1, "TCIE"); 
state->u.f0.fld.cr1.txeie= cm_object_get_child_by_name(state->u.f0.reg.cr1, "TXEIE"); 
state->u.f0.fld.cr1.peie= cm_object_get_child_by_name(state->u.f0.reg.cr1, "PEIE"); 
state->u.f0.fld.cr1.ps= cm_object_get_child_by_name(state->u.f0.reg.cr1, "PS"); 
state->u.f0.fld.cr1.pce= cm_object_get_child_by_name(state->u.f0.reg.cr1, "PCE"); 
state->u.f0.fld.cr1.wake= cm_object_get_child_by_name(state->u.f0.reg.cr1, "WAKE"); 
state->u.f0.fld.cr1.m= cm_object_get_child_by_name(state->u.f0.reg.cr1, "M"); 
state->u.f0.fld.cr1.mme= cm_object_get_child_by_name(state->u.f0.reg.cr1, "MME"); 
state->u.f0.fld.cr1.cmie= cm_object_get_child_by_name(state->u.f0.reg.cr1, "CMIE"); 
state->u.f0.fld.cr1.over8= cm_object_get_child_by_name(state->u.f0.reg.cr1, "OVER8"); 
state->u.f0.fld.cr1.dedt= cm_object_get_child_by_name(state->u.f0.reg.cr1, "DEDT"); 
state->u.f0.fld.cr1.deat= cm_object_get_child_by_name(state->u.f0.reg.cr1, "DEAT"); 
state->u.f0.fld.cr1.rtoie= cm_object_get_child_by_name(state->u.f0.reg.cr1, "RTOIE"); 
state->u.f0.fld.cr1.eobie= cm_object_get_child_by_name(state->u.f0.reg.cr1, "EOBIE"); 
state->u.f0.fld.cr1.m1= cm_object_get_child_by_name(state->u.f0.reg.cr1, "M1"); 
// CR2bitfields.
state->u.f0.fld.cr2.addm7= cm_object_get_child_by_name(state->u.f0.reg.cr2, "ADDM7"); 
state->u.f0.fld.cr2.lbdl= cm_object_get_child_by_name(state->u.f0.reg.cr2, "LBDL"); 
state->u.f0.fld.cr2.lbdie= cm_object_get_child_by_name(state->u.f0.reg.cr2, "LBDIE"); 
state->u.f0.fld.cr2.lbcl= cm_object_get_child_by_name(state->u.f0.reg.cr2, "LBCL"); 
state->u.f0.fld.cr2.cpha= cm_object_get_child_by_name(state->u.f0.reg.cr2, "CPHA"); 
state->u.f0.fld.cr2.cpol= cm_object_get_child_by_name(state->u.f0.reg.cr2, "CPOL"); 
state->u.f0.fld.cr2.clken= cm_object_get_child_by_name(state->u.f0.reg.cr2, "CLKEN"); 
state->u.f0.fld.cr2.stop= cm_object_get_child_by_name(state->u.f0.reg.cr2, "STOP"); 
state->u.f0.fld.cr2.linen= cm_object_get_child_by_name(state->u.f0.reg.cr2, "LINEN"); 
state->u.f0.fld.cr2.swap= cm_object_get_child_by_name(state->u.f0.reg.cr2, "SWAP"); 
state->u.f0.fld.cr2.rxinv= cm_object_get_child_by_name(state->u.f0.reg.cr2, "RXINV"); 
state->u.f0.fld.cr2.txinv= cm_object_get_child_by_name(state->u.f0.reg.cr2, "TXINV"); 
state->u.f0.fld.cr2.datainv= cm_object_get_child_by_name(state->u.f0.reg.cr2, "DATAINV"); 
state->u.f0.fld.cr2.msbfirst= cm_object_get_child_by_name(state->u.f0.reg.cr2, "MSBFIRST"); 
state->u.f0.fld.cr2.abren= cm_object_get_child_by_name(state->u.f0.reg.cr2, "ABREN"); 
state->u.f0.fld.cr2.abrmod= cm_object_get_child_by_name(state->u.f0.reg.cr2, "ABRMOD"); 
state->u.f0.fld.cr2.rtoen= cm_object_get_child_by_name(state->u.f0.reg.cr2, "RTOEN"); 
state->u.f0.fld.cr2.add0= cm_object_get_child_by_name(state->u.f0.reg.cr2, "ADD0"); 
state->u.f0.fld.cr2.add4= cm_object_get_child_by_name(state->u.f0.reg.cr2, "ADD4"); 
// CR3bitfields.
state->u.f0.fld.cr3.eie= cm_object_get_child_by_name(state->u.f0.reg.cr3, "EIE"); 
state->u.f0.fld.cr3.iren= cm_object_get_child_by_name(state->u.f0.reg.cr3, "IREN"); 
state->u.f0.fld.cr3.irlp= cm_object_get_child_by_name(state->u.f0.reg.cr3, "IRLP"); 
state->u.f0.fld.cr3.hdsel= cm_object_get_child_by_name(state->u.f0.reg.cr3, "HDSEL"); 
state->u.f0.fld.cr3.nack= cm_object_get_child_by_name(state->u.f0.reg.cr3, "NACK"); 
state->u.f0.fld.cr3.scen= cm_object_get_child_by_name(state->u.f0.reg.cr3, "SCEN"); 
state->u.f0.fld.cr3.dmar= cm_object_get_child_by_name(state->u.f0.reg.cr3, "DMAR"); 
state->u.f0.fld.cr3.dmat= cm_object_get_child_by_name(state->u.f0.reg.cr3, "DMAT"); 
state->u.f0.fld.cr3.rtse= cm_object_get_child_by_name(state->u.f0.reg.cr3, "RTSE"); 
state->u.f0.fld.cr3.ctse= cm_object_get_child_by_name(state->u.f0.reg.cr3, "CTSE"); 
state->u.f0.fld.cr3.ctsie= cm_object_get_child_by_name(state->u.f0.reg.cr3, "CTSIE"); 
state->u.f0.fld.cr3.onebit= cm_object_get_child_by_name(state->u.f0.reg.cr3, "ONEBIT"); 
state->u.f0.fld.cr3.ovrdis= cm_object_get_child_by_name(state->u.f0.reg.cr3, "OVRDIS"); 
state->u.f0.fld.cr3.ddre= cm_object_get_child_by_name(state->u.f0.reg.cr3, "DDRE"); 
state->u.f0.fld.cr3.dem= cm_object_get_child_by_name(state->u.f0.reg.cr3, "DEM"); 
state->u.f0.fld.cr3.dep= cm_object_get_child_by_name(state->u.f0.reg.cr3, "DEP"); 
state->u.f0.fld.cr3.scarcnt= cm_object_get_child_by_name(state->u.f0.reg.cr3, "SCARCNT"); 
state->u.f0.fld.cr3.wus= cm_object_get_child_by_name(state->u.f0.reg.cr3, "WUS"); 
state->u.f0.fld.cr3.wufie= cm_object_get_child_by_name(state->u.f0.reg.cr3, "WUFIE"); 
// BRRbitfields.
state->u.f0.fld.brr.div_fraction= cm_object_get_child_by_name(state->u.f0.reg.brr, "DIV_Fraction"); 
state->u.f0.fld.brr.div_mantissa= cm_object_get_child_by_name(state->u.f0.reg.brr, "DIV_Mantissa"); 
// GTPRbitfields.
state->u.f0.fld.gtpr.psc= cm_object_get_child_by_name(state->u.f0.reg.gtpr, "PSC"); 
state->u.f0.fld.gtpr.gt= cm_object_get_child_by_name(state->u.f0.reg.gtpr, "GT"); 
// RTORbitfields.
state->u.f0.fld.rtor.rto= cm_object_get_child_by_name(state->u.f0.reg.rtor, "RTO"); 
state->u.f0.fld.rtor.blen= cm_object_get_child_by_name(state->u.f0.reg.rtor, "BLEN"); 
// RQRbitfields.
state->u.f0.fld.rqr.abrrq= cm_object_get_child_by_name(state->u.f0.reg.rqr, "ABRRQ"); 
state->u.f0.fld.rqr.sbkrq= cm_object_get_child_by_name(state->u.f0.reg.rqr, "SBKRQ"); 
state->u.f0.fld.rqr.mmrq= cm_object_get_child_by_name(state->u.f0.reg.rqr, "MMRQ"); 
state->u.f0.fld.rqr.rxfrq= cm_object_get_child_by_name(state->u.f0.reg.rqr, "RXFRQ"); 
state->u.f0.fld.rqr.txfrq= cm_object_get_child_by_name(state->u.f0.reg.rqr, "TXFRQ"); 
// ISRbitfields.
state->u.f0.fld.isr.pe= cm_object_get_child_by_name(state->u.f0.reg.isr, "PE"); 
state->u.f0.fld.isr.fe= cm_object_get_child_by_name(state->u.f0.reg.isr, "FE"); 
state->u.f0.fld.isr.nf= cm_object_get_child_by_name(state->u.f0.reg.isr, "NF"); 
state->u.f0.fld.isr.ore= cm_object_get_child_by_name(state->u.f0.reg.isr, "ORE"); 
state->u.f0.fld.isr.idle= cm_object_get_child_by_name(state->u.f0.reg.isr, "IDLE"); 
state->u.f0.fld.isr.rxne= cm_object_get_child_by_name(state->u.f0.reg.isr, "RXNE"); 
state->u.f0.fld.isr.tc= cm_object_get_child_by_name(state->u.f0.reg.isr, "TC"); 
state->u.f0.fld.isr.txe= cm_object_get_child_by_name(state->u.f0.reg.isr, "TXE"); 
state->u.f0.fld.isr.lbdf= cm_object_get_child_by_name(state->u.f0.reg.isr, "LBDF"); 
state->u.f0.fld.isr.ctsif= cm_object_get_child_by_name(state->u.f0.reg.isr, "CTSIF"); 
state->u.f0.fld.isr.cts= cm_object_get_child_by_name(state->u.f0.reg.isr, "CTS"); 
state->u.f0.fld.isr.rtof= cm_object_get_child_by_name(state->u.f0.reg.isr, "RTOF"); 
state->u.f0.fld.isr.eobf= cm_object_get_child_by_name(state->u.f0.reg.isr, "EOBF"); 
state->u.f0.fld.isr.abre= cm_object_get_child_by_name(state->u.f0.reg.isr, "ABRE"); 
state->u.f0.fld.isr.abrf= cm_object_get_child_by_name(state->u.f0.reg.isr, "ABRF"); 
state->u.f0.fld.isr.busy= cm_object_get_child_by_name(state->u.f0.reg.isr, "BUSY"); 
state->u.f0.fld.isr.cmf= cm_object_get_child_by_name(state->u.f0.reg.isr, "CMF"); 
state->u.f0.fld.isr.sbkf= cm_object_get_child_by_name(state->u.f0.reg.isr, "SBKF"); 
state->u.f0.fld.isr.rwu= cm_object_get_child_by_name(state->u.f0.reg.isr, "RWU"); 
state->u.f0.fld.isr.wuf= cm_object_get_child_by_name(state->u.f0.reg.isr, "WUF"); 
state->u.f0.fld.isr.teack= cm_object_get_child_by_name(state->u.f0.reg.isr, "TEACK"); 
state->u.f0.fld.isr.reack= cm_object_get_child_by_name(state->u.f0.reg.isr, "REACK"); 
// ICRbitfields.
state->u.f0.fld.icr.pecf= cm_object_get_child_by_name(state->u.f0.reg.icr, "PECF"); 
state->u.f0.fld.icr.fecf= cm_object_get_child_by_name(state->u.f0.reg.icr, "FECF"); 
state->u.f0.fld.icr.ncf= cm_object_get_child_by_name(state->u.f0.reg.icr, "NCF"); 
state->u.f0.fld.icr.orecf= cm_object_get_child_by_name(state->u.f0.reg.icr, "ORECF"); 
state->u.f0.fld.icr.idlecf= cm_object_get_child_by_name(state->u.f0.reg.icr, "IDLECF"); 
state->u.f0.fld.icr.tccf= cm_object_get_child_by_name(state->u.f0.reg.icr, "TCCF"); 
state->u.f0.fld.icr.lbdcf= cm_object_get_child_by_name(state->u.f0.reg.icr, "LBDCF"); 
state->u.f0.fld.icr.ctscf= cm_object_get_child_by_name(state->u.f0.reg.icr, "CTSCF"); 
state->u.f0.fld.icr.rtocf= cm_object_get_child_by_name(state->u.f0.reg.icr, "RTOCF"); 
state->u.f0.fld.icr.eobcf= cm_object_get_child_by_name(state->u.f0.reg.icr, "EOBCF"); 
state->u.f0.fld.icr.cmcf= cm_object_get_child_by_name(state->u.f0.reg.icr, "CMCF"); 
state->u.f0.fld.icr.wucf= cm_object_get_child_by_name(state->u.f0.reg.icr, "WUCF"); 
// RDRbitfields.
state->u.f0.fld.rdr.rdr= cm_object_get_child_by_name(state->u.f0.reg.rdr, "RDR"); 
// TDRbitfields.
state->u.f0.fld.tdr.tdr= cm_object_get_child_by_name(state->u.f0.reg.tdr, "TDR"); 
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_usart_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32USARTState *state = STM32_USART_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_usart_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32USARTState *state = STM32_USART_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_usart_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32USARTState *state = STM32_USART_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_usart_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32USARTState *state = STM32_USART_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_usart_is_enabled(Object *obj)
{
    STM32USARTState *state = STM32_USART_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_usart_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32USARTState *state = STM32_USART_STATE(obj);

    // Capabilities are not yet available.

cm_object_property_add_int(obj, "port-index",
            (const int *) &state->port_index);
    state->port_index = STM32_PORT_USART_UNDEFINED;
// TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_usart_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_USART)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32USARTState *state = STM32_USART_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "USART";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x2) {

            stm32f0x2_usart_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_usart_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f0.reg.xxx, &stm32_usart_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_usart_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f0.reg.xxx, &stm32_usart_xxx_post_write_callback);

            // TODO: add interrupts.

// TODO: remove this if the peripheral is always enabled.
           snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/USART%dEN",
                1 + state->port_index - STM32_PORT_USART1);
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

static void stm32_usart_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_USART);
}

static void stm32_usart_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_usart_reset_callback;
    dc->realize = stm32_usart_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_usart_is_enabled;
}

static const TypeInfo stm32_usart_type_info = {
    .name = TYPE_STM32_USART,
    .parent = TYPE_STM32_USART_PARENT,
    .instance_init = stm32_usart_instance_init_callback,
    .instance_size = sizeof(STM32USARTState),
    .class_init = stm32_usart_class_init_callback,
    .class_size = sizeof(STM32USARTClass) };

static void stm32_usart_register_types(void)
{
    type_register_static(&stm32_usart_type_info);
}

type_init(stm32_usart_register_types);

// ----------------------------------------------------------------------------
