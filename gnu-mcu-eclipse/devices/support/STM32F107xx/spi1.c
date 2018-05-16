/*
 * STM32 - SPI (Serial peripheral interface) emulation.
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

#include <hw/cortexm/stm32/spi.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f107xx_spi_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32SPIState *state = STM32_SPI_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f1.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
    state->u.f1.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
    state->u.f1.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->u.f1.reg.dr = cm_object_get_child_by_name(obj, "DR");
    state->u.f1.reg.crcpr = cm_object_get_child_by_name(obj, "CRCPR");
    state->u.f1.reg.rxcrcr = cm_object_get_child_by_name(obj, "RXCRCR");
    state->u.f1.reg.txcrcr = cm_object_get_child_by_name(obj, "TXCRCR");
    state->u.f1.reg.i2scfgr = cm_object_get_child_by_name(obj, "I2SCFGR");
    state->u.f1.reg.i2spr = cm_object_get_child_by_name(obj, "I2SPR");
    
    
    // CR1 bitfields.
    state->u.f1.fld.cr1.cpha = cm_object_get_child_by_name(state->u.f1.reg.cr1, "CPHA"); 
    state->u.f1.fld.cr1.cpol = cm_object_get_child_by_name(state->u.f1.reg.cr1, "CPOL"); 
    state->u.f1.fld.cr1.mstr = cm_object_get_child_by_name(state->u.f1.reg.cr1, "MSTR"); 
    state->u.f1.fld.cr1.br = cm_object_get_child_by_name(state->u.f1.reg.cr1, "BR"); 
    state->u.f1.fld.cr1.spe = cm_object_get_child_by_name(state->u.f1.reg.cr1, "SPE"); 
    state->u.f1.fld.cr1.lsbfirst = cm_object_get_child_by_name(state->u.f1.reg.cr1, "LSBFIRST"); 
    state->u.f1.fld.cr1.ssi = cm_object_get_child_by_name(state->u.f1.reg.cr1, "SSI"); 
    state->u.f1.fld.cr1.ssm = cm_object_get_child_by_name(state->u.f1.reg.cr1, "SSM"); 
    state->u.f1.fld.cr1.rxonly = cm_object_get_child_by_name(state->u.f1.reg.cr1, "RXONLY"); 
    state->u.f1.fld.cr1.dff = cm_object_get_child_by_name(state->u.f1.reg.cr1, "DFF"); 
    state->u.f1.fld.cr1.crcnext = cm_object_get_child_by_name(state->u.f1.reg.cr1, "CRCNEXT"); 
    state->u.f1.fld.cr1.crcen = cm_object_get_child_by_name(state->u.f1.reg.cr1, "CRCEN"); 
    state->u.f1.fld.cr1.bidioe = cm_object_get_child_by_name(state->u.f1.reg.cr1, "BIDIOE"); 
    state->u.f1.fld.cr1.bidimode = cm_object_get_child_by_name(state->u.f1.reg.cr1, "BIDIMODE");  
    
    // CR2 bitfields.
    state->u.f1.fld.cr2.rxdmaen = cm_object_get_child_by_name(state->u.f1.reg.cr2, "RXDMAEN"); 
    state->u.f1.fld.cr2.txdmaen = cm_object_get_child_by_name(state->u.f1.reg.cr2, "TXDMAEN"); 
    state->u.f1.fld.cr2.ssoe = cm_object_get_child_by_name(state->u.f1.reg.cr2, "SSOE"); 
    state->u.f1.fld.cr2.errie = cm_object_get_child_by_name(state->u.f1.reg.cr2, "ERRIE"); 
    state->u.f1.fld.cr2.rxneie = cm_object_get_child_by_name(state->u.f1.reg.cr2, "RXNEIE"); 
    state->u.f1.fld.cr2.txeie = cm_object_get_child_by_name(state->u.f1.reg.cr2, "TXEIE");  
    
    // SR bitfields.
    state->u.f1.fld.sr.rxne = cm_object_get_child_by_name(state->u.f1.reg.sr, "RXNE"); 
    state->u.f1.fld.sr.txe = cm_object_get_child_by_name(state->u.f1.reg.sr, "TXE"); 
    state->u.f1.fld.sr.chside = cm_object_get_child_by_name(state->u.f1.reg.sr, "CHSIDE"); 
    state->u.f1.fld.sr.udr = cm_object_get_child_by_name(state->u.f1.reg.sr, "UDR"); 
    state->u.f1.fld.sr.crcerr = cm_object_get_child_by_name(state->u.f1.reg.sr, "CRCERR"); 
    state->u.f1.fld.sr.modf = cm_object_get_child_by_name(state->u.f1.reg.sr, "MODF"); 
    state->u.f1.fld.sr.ovr = cm_object_get_child_by_name(state->u.f1.reg.sr, "OVR"); 
    state->u.f1.fld.sr.bsy = cm_object_get_child_by_name(state->u.f1.reg.sr, "BSY");  
    
    // DR bitfields.
    state->u.f1.fld.dr.dr = cm_object_get_child_by_name(state->u.f1.reg.dr, "DR");  
    
    // CRCPR bitfields.
    state->u.f1.fld.crcpr.crcpoly = cm_object_get_child_by_name(state->u.f1.reg.crcpr, "CRCPOLY");  
    
    // RXCRCR bitfields.
    state->u.f1.fld.rxcrcr.rxcrc = cm_object_get_child_by_name(state->u.f1.reg.rxcrcr, "RxCRC");  
    
    // TXCRCR bitfields.
    state->u.f1.fld.txcrcr.txcrc = cm_object_get_child_by_name(state->u.f1.reg.txcrcr, "TxCRC");  
    
    // I2SCFGR bitfields.
    state->u.f1.fld.i2scfgr.chlen = cm_object_get_child_by_name(state->u.f1.reg.i2scfgr, "CHLEN"); 
    state->u.f1.fld.i2scfgr.datlen = cm_object_get_child_by_name(state->u.f1.reg.i2scfgr, "DATLEN"); 
    state->u.f1.fld.i2scfgr.ckpol = cm_object_get_child_by_name(state->u.f1.reg.i2scfgr, "CKPOL"); 
    state->u.f1.fld.i2scfgr.i2sstd = cm_object_get_child_by_name(state->u.f1.reg.i2scfgr, "I2SSTD"); 
    state->u.f1.fld.i2scfgr.pcmsync = cm_object_get_child_by_name(state->u.f1.reg.i2scfgr, "PCMSYNC"); 
    state->u.f1.fld.i2scfgr.i2scfg = cm_object_get_child_by_name(state->u.f1.reg.i2scfgr, "I2SCFG"); 
    state->u.f1.fld.i2scfgr.i2se = cm_object_get_child_by_name(state->u.f1.reg.i2scfgr, "I2SE"); 
    state->u.f1.fld.i2scfgr.i2smod = cm_object_get_child_by_name(state->u.f1.reg.i2scfgr, "I2SMOD");  
    
    // I2SPR bitfields.
    state->u.f1.fld.i2spr.i2sdiv = cm_object_get_child_by_name(state->u.f1.reg.i2spr, "I2SDIV"); 
    state->u.f1.fld.i2spr.odd = cm_object_get_child_by_name(state->u.f1.reg.i2spr, "ODD"); 
    state->u.f1.fld.i2spr.mckoe = cm_object_get_child_by_name(state->u.f1.reg.i2spr, "MCKOE");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_spi_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32SPIState *state = STM32_SPI_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_spi_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32SPIState *state = STM32_SPI_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_spi_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32SPIState *state = STM32_SPI_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_spi_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32SPIState *state = STM32_SPI_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_spi_is_enabled(Object *obj)
{
    STM32SPIState *state = STM32_SPI_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_spi_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32SPIState *state = STM32_SPI_STATE(obj);

    // Capabilities are not yet available.

    cm_object_property_add_int(obj, "port-index",
            (const int *) &state->port_index);
    state->port_index = STM32_PORT_SPI_UNDEFINED;

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_spi_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_SPI)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32SPIState *state = STM32_SPI_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "SPI";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F1:

        if (capabilities->f1.is_107xx ) {

            stm32f107xx_spi_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f1.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f1.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f1.reg.xxx, &stm32_spi_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f1.reg.xxx, &stm32_spi_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f1.reg.xxx, &stm32_spi_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f1.reg.xxx, &stm32_spi_xxx_post_write_callback);

            // TODO: add interrupts.

           // TODO: remove this if the peripheral is always enabled.
           snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/SPI%dEN",
                1 + state->port_index - STM32_PORT_SPI1);


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

static void stm32_spi_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_SPI);
}

static void stm32_spi_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_spi_reset_callback;
    dc->realize = stm32_spi_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_spi_is_enabled;
}

static const TypeInfo stm32_spi_type_info = {
    .name = TYPE_STM32_SPI,
    .parent = TYPE_STM32_SPI_PARENT,
    .instance_init = stm32_spi_instance_init_callback,
    .instance_size = sizeof(STM32SPIState),
    .class_init = stm32_spi_class_init_callback,
    .class_size = sizeof(STM32SPIClass) };

static void stm32_spi_register_types(void)
{
    type_register_static(&stm32_spi_type_info);
}

type_init(stm32_spi_register_types);

// ----------------------------------------------------------------------------
