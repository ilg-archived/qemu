/*
 * STM32 - I2C (Inter-integrated circuit) emulation.
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

#include <hw/cortexm/stm32/i2c.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x1_i2c_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32I2CState *state = STM32_I2C_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f0.reg.cr1 = cm_object_get_child_by_name(obj, "CR1");
    state->u.f0.reg.cr2 = cm_object_get_child_by_name(obj, "CR2");
    state->u.f0.reg.oar1 = cm_object_get_child_by_name(obj, "OAR1");
    state->u.f0.reg.oar2 = cm_object_get_child_by_name(obj, "OAR2");
    state->u.f0.reg.timingr = cm_object_get_child_by_name(obj, "TIMINGR");
    state->u.f0.reg.timeoutr = cm_object_get_child_by_name(obj, "TIMEOUTR");
    state->u.f0.reg.isr = cm_object_get_child_by_name(obj, "ISR");
    state->u.f0.reg.icr = cm_object_get_child_by_name(obj, "ICR");
    state->u.f0.reg.pecr = cm_object_get_child_by_name(obj, "PECR");
    state->u.f0.reg.rxdr = cm_object_get_child_by_name(obj, "RXDR");
    state->u.f0.reg.txdr = cm_object_get_child_by_name(obj, "TXDR");
    
    
    // CR1 bitfields.
    state->u.f0.fld.cr1.pe = cm_object_get_child_by_name(state->u.f0.reg.cr1, "PE"); 
    state->u.f0.fld.cr1.txie = cm_object_get_child_by_name(state->u.f0.reg.cr1, "TXIE"); 
    state->u.f0.fld.cr1.rxie = cm_object_get_child_by_name(state->u.f0.reg.cr1, "RXIE"); 
    state->u.f0.fld.cr1.addrie = cm_object_get_child_by_name(state->u.f0.reg.cr1, "ADDRIE"); 
    state->u.f0.fld.cr1.nackie = cm_object_get_child_by_name(state->u.f0.reg.cr1, "NACKIE"); 
    state->u.f0.fld.cr1.stopie = cm_object_get_child_by_name(state->u.f0.reg.cr1, "STOPIE"); 
    state->u.f0.fld.cr1.tcie = cm_object_get_child_by_name(state->u.f0.reg.cr1, "TCIE"); 
    state->u.f0.fld.cr1.errie = cm_object_get_child_by_name(state->u.f0.reg.cr1, "ERRIE"); 
    state->u.f0.fld.cr1.dnf = cm_object_get_child_by_name(state->u.f0.reg.cr1, "DNF"); 
    state->u.f0.fld.cr1.anfoff = cm_object_get_child_by_name(state->u.f0.reg.cr1, "ANFOFF"); 
    state->u.f0.fld.cr1.swrst = cm_object_get_child_by_name(state->u.f0.reg.cr1, "SWRST"); 
    state->u.f0.fld.cr1.txdmaen = cm_object_get_child_by_name(state->u.f0.reg.cr1, "TXDMAEN"); 
    state->u.f0.fld.cr1.rxdmaen = cm_object_get_child_by_name(state->u.f0.reg.cr1, "RXDMAEN"); 
    state->u.f0.fld.cr1.sbc = cm_object_get_child_by_name(state->u.f0.reg.cr1, "SBC"); 
    state->u.f0.fld.cr1.nostretch = cm_object_get_child_by_name(state->u.f0.reg.cr1, "NOSTRETCH"); 
    state->u.f0.fld.cr1.wupen = cm_object_get_child_by_name(state->u.f0.reg.cr1, "WUPEN"); 
    state->u.f0.fld.cr1.gcen = cm_object_get_child_by_name(state->u.f0.reg.cr1, "GCEN"); 
    state->u.f0.fld.cr1.smbhen = cm_object_get_child_by_name(state->u.f0.reg.cr1, "SMBHEN"); 
    state->u.f0.fld.cr1.smbden = cm_object_get_child_by_name(state->u.f0.reg.cr1, "SMBDEN"); 
    state->u.f0.fld.cr1.alerten = cm_object_get_child_by_name(state->u.f0.reg.cr1, "ALERTEN"); 
    state->u.f0.fld.cr1.pecen = cm_object_get_child_by_name(state->u.f0.reg.cr1, "PECEN");  
    
    // CR2 bitfields.
    state->u.f0.fld.cr2.sadd0 = cm_object_get_child_by_name(state->u.f0.reg.cr2, "SADD0"); 
    state->u.f0.fld.cr2.sadd1 = cm_object_get_child_by_name(state->u.f0.reg.cr2, "SADD1"); 
    state->u.f0.fld.cr2.sadd8 = cm_object_get_child_by_name(state->u.f0.reg.cr2, "SADD8"); 
    state->u.f0.fld.cr2.rd_wrn = cm_object_get_child_by_name(state->u.f0.reg.cr2, "RD_WRN"); 
    state->u.f0.fld.cr2.add10 = cm_object_get_child_by_name(state->u.f0.reg.cr2, "ADD10"); 
    state->u.f0.fld.cr2.head10r = cm_object_get_child_by_name(state->u.f0.reg.cr2, "HEAD10R"); 
    state->u.f0.fld.cr2.start = cm_object_get_child_by_name(state->u.f0.reg.cr2, "START"); 
    state->u.f0.fld.cr2.stop = cm_object_get_child_by_name(state->u.f0.reg.cr2, "STOP"); 
    state->u.f0.fld.cr2.nack = cm_object_get_child_by_name(state->u.f0.reg.cr2, "NACK"); 
    state->u.f0.fld.cr2.nbytes = cm_object_get_child_by_name(state->u.f0.reg.cr2, "NBYTES"); 
    state->u.f0.fld.cr2.reload = cm_object_get_child_by_name(state->u.f0.reg.cr2, "RELOAD"); 
    state->u.f0.fld.cr2.autoend = cm_object_get_child_by_name(state->u.f0.reg.cr2, "AUTOEND"); 
    state->u.f0.fld.cr2.pecbyte = cm_object_get_child_by_name(state->u.f0.reg.cr2, "PECBYTE");  
    
    // OAR1 bitfields.
    state->u.f0.fld.oar1.oa1_0 = cm_object_get_child_by_name(state->u.f0.reg.oar1, "OA1_0"); 
    state->u.f0.fld.oar1.oa1_1 = cm_object_get_child_by_name(state->u.f0.reg.oar1, "OA1_1"); 
    state->u.f0.fld.oar1.oa1_8 = cm_object_get_child_by_name(state->u.f0.reg.oar1, "OA1_8"); 
    state->u.f0.fld.oar1.oa1mode = cm_object_get_child_by_name(state->u.f0.reg.oar1, "OA1MODE"); 
    state->u.f0.fld.oar1.oa1en = cm_object_get_child_by_name(state->u.f0.reg.oar1, "OA1EN");  
    
    // OAR2 bitfields.
    state->u.f0.fld.oar2.oa2 = cm_object_get_child_by_name(state->u.f0.reg.oar2, "OA2"); 
    state->u.f0.fld.oar2.oa2msk = cm_object_get_child_by_name(state->u.f0.reg.oar2, "OA2MSK"); 
    state->u.f0.fld.oar2.oa2en = cm_object_get_child_by_name(state->u.f0.reg.oar2, "OA2EN");  
    
    // TIMINGR bitfields.
    state->u.f0.fld.timingr.scll = cm_object_get_child_by_name(state->u.f0.reg.timingr, "SCLL"); 
    state->u.f0.fld.timingr.sclh = cm_object_get_child_by_name(state->u.f0.reg.timingr, "SCLH"); 
    state->u.f0.fld.timingr.sdadel = cm_object_get_child_by_name(state->u.f0.reg.timingr, "SDADEL"); 
    state->u.f0.fld.timingr.scldel = cm_object_get_child_by_name(state->u.f0.reg.timingr, "SCLDEL"); 
    state->u.f0.fld.timingr.presc = cm_object_get_child_by_name(state->u.f0.reg.timingr, "PRESC");  
    
    // TIMEOUTR bitfields.
    state->u.f0.fld.timeoutr.timeouta = cm_object_get_child_by_name(state->u.f0.reg.timeoutr, "TIMEOUTA"); 
    state->u.f0.fld.timeoutr.tidle = cm_object_get_child_by_name(state->u.f0.reg.timeoutr, "TIDLE"); 
    state->u.f0.fld.timeoutr.timouten = cm_object_get_child_by_name(state->u.f0.reg.timeoutr, "TIMOUTEN"); 
    state->u.f0.fld.timeoutr.timeoutb = cm_object_get_child_by_name(state->u.f0.reg.timeoutr, "TIMEOUTB"); 
    state->u.f0.fld.timeoutr.texten = cm_object_get_child_by_name(state->u.f0.reg.timeoutr, "TEXTEN");  
    
    // ISR bitfields.
    state->u.f0.fld.isr.txe = cm_object_get_child_by_name(state->u.f0.reg.isr, "TXE"); 
    state->u.f0.fld.isr.txis = cm_object_get_child_by_name(state->u.f0.reg.isr, "TXIS"); 
    state->u.f0.fld.isr.rxne = cm_object_get_child_by_name(state->u.f0.reg.isr, "RXNE"); 
    state->u.f0.fld.isr.addr = cm_object_get_child_by_name(state->u.f0.reg.isr, "ADDR"); 
    state->u.f0.fld.isr.nackf = cm_object_get_child_by_name(state->u.f0.reg.isr, "NACKF"); 
    state->u.f0.fld.isr.stopf = cm_object_get_child_by_name(state->u.f0.reg.isr, "STOPF"); 
    state->u.f0.fld.isr.tc = cm_object_get_child_by_name(state->u.f0.reg.isr, "TC"); 
    state->u.f0.fld.isr.tcr = cm_object_get_child_by_name(state->u.f0.reg.isr, "TCR"); 
    state->u.f0.fld.isr.berr = cm_object_get_child_by_name(state->u.f0.reg.isr, "BERR"); 
    state->u.f0.fld.isr.arlo = cm_object_get_child_by_name(state->u.f0.reg.isr, "ARLO"); 
    state->u.f0.fld.isr.ovr = cm_object_get_child_by_name(state->u.f0.reg.isr, "OVR"); 
    state->u.f0.fld.isr.pecerr = cm_object_get_child_by_name(state->u.f0.reg.isr, "PECERR"); 
    state->u.f0.fld.isr.timeout = cm_object_get_child_by_name(state->u.f0.reg.isr, "TIMEOUT"); 
    state->u.f0.fld.isr.alert = cm_object_get_child_by_name(state->u.f0.reg.isr, "ALERT"); 
    state->u.f0.fld.isr.busy = cm_object_get_child_by_name(state->u.f0.reg.isr, "BUSY"); 
    state->u.f0.fld.isr.dir = cm_object_get_child_by_name(state->u.f0.reg.isr, "DIR"); 
    state->u.f0.fld.isr.addcode = cm_object_get_child_by_name(state->u.f0.reg.isr, "ADDCODE");  
    
    // ICR bitfields.
    state->u.f0.fld.icr.addrcf = cm_object_get_child_by_name(state->u.f0.reg.icr, "ADDRCF"); 
    state->u.f0.fld.icr.nackcf = cm_object_get_child_by_name(state->u.f0.reg.icr, "NACKCF"); 
    state->u.f0.fld.icr.stopcf = cm_object_get_child_by_name(state->u.f0.reg.icr, "STOPCF"); 
    state->u.f0.fld.icr.berrcf = cm_object_get_child_by_name(state->u.f0.reg.icr, "BERRCF"); 
    state->u.f0.fld.icr.arlocf = cm_object_get_child_by_name(state->u.f0.reg.icr, "ARLOCF"); 
    state->u.f0.fld.icr.ovrcf = cm_object_get_child_by_name(state->u.f0.reg.icr, "OVRCF"); 
    state->u.f0.fld.icr.peccf = cm_object_get_child_by_name(state->u.f0.reg.icr, "PECCF"); 
    state->u.f0.fld.icr.timoutcf = cm_object_get_child_by_name(state->u.f0.reg.icr, "TIMOUTCF"); 
    state->u.f0.fld.icr.alertcf = cm_object_get_child_by_name(state->u.f0.reg.icr, "ALERTCF");  
    
    // PECR bitfields.
    state->u.f0.fld.pecr.pec = cm_object_get_child_by_name(state->u.f0.reg.pecr, "PEC");  
    
    // RXDR bitfields.
    state->u.f0.fld.rxdr.rxdata = cm_object_get_child_by_name(state->u.f0.reg.rxdr, "RXDATA");  
    
    // TXDR bitfields.
    state->u.f0.fld.txdr.txdata = cm_object_get_child_by_name(state->u.f0.reg.txdr, "TXDATA");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_i2c_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32I2CState *state = STM32_I2C_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_i2c_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32I2CState *state = STM32_I2C_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_i2c_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32I2CState *state = STM32_I2C_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_i2c_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32I2CState *state = STM32_I2C_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_i2c_is_enabled(Object *obj)
{
    STM32I2CState *state = STM32_I2C_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_i2c_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32I2CState *state = STM32_I2C_STATE(obj);

    // Capabilities are not yet available.

    cm_object_property_add_int(obj, "port-index",
            (const int *) &state->port_index);
    state->port_index = STM32_PORT_I2C_UNDEFINED;

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_i2c_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_I2C)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32I2CState *state = STM32_I2C_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "I2C";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x1 ) {

            stm32f0x1_i2c_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_i2c_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f0.reg.xxx, &stm32_i2c_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_i2c_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f0.reg.xxx, &stm32_i2c_xxx_post_write_callback);

            // TODO: add interrupts.

           // TODO: remove this if the peripheral is always enabled.
           snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/I2C%dEN",
                1 + state->port_index - STM32_PORT_I2C1);


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

static void stm32_i2c_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_I2C);
}

static void stm32_i2c_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_i2c_reset_callback;
    dc->realize = stm32_i2c_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_i2c_is_enabled;
}

static const TypeInfo stm32_i2c_type_info = {
    .name = TYPE_STM32_I2C,
    .parent = TYPE_STM32_I2C_PARENT,
    .instance_init = stm32_i2c_instance_init_callback,
    .instance_size = sizeof(STM32I2CState),
    .class_init = stm32_i2c_class_init_callback,
    .class_size = sizeof(STM32I2CClass) };

static void stm32_i2c_register_types(void)
{
    type_register_static(&stm32_i2c_type_info);
}

type_init(stm32_i2c_register_types);

// ----------------------------------------------------------------------------
