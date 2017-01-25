/*
 * STM32 - SDIO (Secure digital input/output interface) emulation.
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

#include <hw/cortexm/stm32/sdio.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f429x_sdio_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32SDIOState *state = STM32_SDIO_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.power = cm_object_get_child_by_name(obj, "POWER");
    state->u.f4.reg.clkcr = cm_object_get_child_by_name(obj, "CLKCR");
    state->u.f4.reg.arg = cm_object_get_child_by_name(obj, "ARG");
    state->u.f4.reg.cmd = cm_object_get_child_by_name(obj, "CMD");
    state->u.f4.reg.respcmd = cm_object_get_child_by_name(obj, "RESPCMD");
    state->u.f4.reg.resp1 = cm_object_get_child_by_name(obj, "RESP1");
    state->u.f4.reg.resp2 = cm_object_get_child_by_name(obj, "RESP2");
    state->u.f4.reg.resp3 = cm_object_get_child_by_name(obj, "RESP3");
    state->u.f4.reg.resp4 = cm_object_get_child_by_name(obj, "RESP4");
    state->u.f4.reg.dtimer = cm_object_get_child_by_name(obj, "DTIMER");
    state->u.f4.reg.dlen = cm_object_get_child_by_name(obj, "DLEN");
    state->u.f4.reg.dctrl = cm_object_get_child_by_name(obj, "DCTRL");
    state->u.f4.reg.dcount = cm_object_get_child_by_name(obj, "DCOUNT");
    state->u.f4.reg.sta = cm_object_get_child_by_name(obj, "STA");
    state->u.f4.reg.icr = cm_object_get_child_by_name(obj, "ICR");
    state->u.f4.reg.mask = cm_object_get_child_by_name(obj, "MASK");
    state->u.f4.reg.fifocnt = cm_object_get_child_by_name(obj, "FIFOCNT");
    state->u.f4.reg.fifo = cm_object_get_child_by_name(obj, "FIFO");
    
    
    // POWER bitfields.
    state->u.f4.fld.power.pwrctrl = cm_object_get_child_by_name(state->u.f4.reg.power, "PWRCTRL");  
    
    // CLKCR bitfields.
    state->u.f4.fld.clkcr.clkdiv = cm_object_get_child_by_name(state->u.f4.reg.clkcr, "CLKDIV"); 
    state->u.f4.fld.clkcr.clken = cm_object_get_child_by_name(state->u.f4.reg.clkcr, "CLKEN"); 
    state->u.f4.fld.clkcr.pwrsav = cm_object_get_child_by_name(state->u.f4.reg.clkcr, "PWRSAV"); 
    state->u.f4.fld.clkcr.bypass = cm_object_get_child_by_name(state->u.f4.reg.clkcr, "BYPASS"); 
    state->u.f4.fld.clkcr.widbus = cm_object_get_child_by_name(state->u.f4.reg.clkcr, "WIDBUS"); 
    state->u.f4.fld.clkcr.negedge = cm_object_get_child_by_name(state->u.f4.reg.clkcr, "NEGEDGE"); 
    state->u.f4.fld.clkcr.hwfc_en = cm_object_get_child_by_name(state->u.f4.reg.clkcr, "HWFC_EN");  
    
    // ARG bitfields.
    state->u.f4.fld.arg.cmdarg = cm_object_get_child_by_name(state->u.f4.reg.arg, "CMDARG");  
    
    // CMD bitfields.
    state->u.f4.fld.cmd.cmdindex = cm_object_get_child_by_name(state->u.f4.reg.cmd, "CMDINDEX"); 
    state->u.f4.fld.cmd.waitresp = cm_object_get_child_by_name(state->u.f4.reg.cmd, "WAITRESP"); 
    state->u.f4.fld.cmd.waitint = cm_object_get_child_by_name(state->u.f4.reg.cmd, "WAITINT"); 
    state->u.f4.fld.cmd.waitpend = cm_object_get_child_by_name(state->u.f4.reg.cmd, "WAITPEND"); 
    state->u.f4.fld.cmd.cpsmen = cm_object_get_child_by_name(state->u.f4.reg.cmd, "CPSMEN"); 
    state->u.f4.fld.cmd.sdiosuspend = cm_object_get_child_by_name(state->u.f4.reg.cmd, "SDIOSuspend"); 
    state->u.f4.fld.cmd.encmdcompl = cm_object_get_child_by_name(state->u.f4.reg.cmd, "ENCMDcompl"); 
    state->u.f4.fld.cmd.nien = cm_object_get_child_by_name(state->u.f4.reg.cmd, "nIEN"); 
    state->u.f4.fld.cmd.ce_atacmd = cm_object_get_child_by_name(state->u.f4.reg.cmd, "CE_ATACMD");  
    
    // RESPCMD bitfields.
    state->u.f4.fld.respcmd.respcmd = cm_object_get_child_by_name(state->u.f4.reg.respcmd, "RESPCMD");  
    
    // RESP1 bitfields.
    state->u.f4.fld.resp1.cardstatus1 = cm_object_get_child_by_name(state->u.f4.reg.resp1, "CARDSTATUS1");  
    
    // RESP2 bitfields.
    state->u.f4.fld.resp2.cardstatus2 = cm_object_get_child_by_name(state->u.f4.reg.resp2, "CARDSTATUS2");  
    
    // RESP3 bitfields.
    state->u.f4.fld.resp3.cardstatus3 = cm_object_get_child_by_name(state->u.f4.reg.resp3, "CARDSTATUS3");  
    
    // RESP4 bitfields.
    state->u.f4.fld.resp4.cardstatus4 = cm_object_get_child_by_name(state->u.f4.reg.resp4, "CARDSTATUS4");  
    
    // DTIMER bitfields.
    state->u.f4.fld.dtimer.datatime = cm_object_get_child_by_name(state->u.f4.reg.dtimer, "DATATIME");  
    
    // DLEN bitfields.
    state->u.f4.fld.dlen.datalength = cm_object_get_child_by_name(state->u.f4.reg.dlen, "DATALENGTH");  
    
    // DCTRL bitfields.
    state->u.f4.fld.dctrl.dten = cm_object_get_child_by_name(state->u.f4.reg.dctrl, "DTEN"); 
    state->u.f4.fld.dctrl.dtdir = cm_object_get_child_by_name(state->u.f4.reg.dctrl, "DTDIR"); 
    state->u.f4.fld.dctrl.dtmode = cm_object_get_child_by_name(state->u.f4.reg.dctrl, "DTMODE"); 
    state->u.f4.fld.dctrl.dmaen = cm_object_get_child_by_name(state->u.f4.reg.dctrl, "DMAEN"); 
    state->u.f4.fld.dctrl.dblocksize = cm_object_get_child_by_name(state->u.f4.reg.dctrl, "DBLOCKSIZE"); 
    state->u.f4.fld.dctrl.rwstart = cm_object_get_child_by_name(state->u.f4.reg.dctrl, "RWSTART"); 
    state->u.f4.fld.dctrl.rwstop = cm_object_get_child_by_name(state->u.f4.reg.dctrl, "RWSTOP"); 
    state->u.f4.fld.dctrl.rwmod = cm_object_get_child_by_name(state->u.f4.reg.dctrl, "RWMOD"); 
    state->u.f4.fld.dctrl.sdioen = cm_object_get_child_by_name(state->u.f4.reg.dctrl, "SDIOEN");  
    
    // DCOUNT bitfields.
    state->u.f4.fld.dcount.datacount = cm_object_get_child_by_name(state->u.f4.reg.dcount, "DATACOUNT");  
    
    // STA bitfields.
    state->u.f4.fld.sta.ccrcfail = cm_object_get_child_by_name(state->u.f4.reg.sta, "CCRCFAIL"); 
    state->u.f4.fld.sta.dcrcfail = cm_object_get_child_by_name(state->u.f4.reg.sta, "DCRCFAIL"); 
    state->u.f4.fld.sta.ctimeout = cm_object_get_child_by_name(state->u.f4.reg.sta, "CTIMEOUT"); 
    state->u.f4.fld.sta.dtimeout = cm_object_get_child_by_name(state->u.f4.reg.sta, "DTIMEOUT"); 
    state->u.f4.fld.sta.txunderr = cm_object_get_child_by_name(state->u.f4.reg.sta, "TXUNDERR"); 
    state->u.f4.fld.sta.rxoverr = cm_object_get_child_by_name(state->u.f4.reg.sta, "RXOVERR"); 
    state->u.f4.fld.sta.cmdrend = cm_object_get_child_by_name(state->u.f4.reg.sta, "CMDREND"); 
    state->u.f4.fld.sta.cmdsent = cm_object_get_child_by_name(state->u.f4.reg.sta, "CMDSENT"); 
    state->u.f4.fld.sta.dataend = cm_object_get_child_by_name(state->u.f4.reg.sta, "DATAEND"); 
    state->u.f4.fld.sta.stbiterr = cm_object_get_child_by_name(state->u.f4.reg.sta, "STBITERR"); 
    state->u.f4.fld.sta.dbckend = cm_object_get_child_by_name(state->u.f4.reg.sta, "DBCKEND"); 
    state->u.f4.fld.sta.cmdact = cm_object_get_child_by_name(state->u.f4.reg.sta, "CMDACT"); 
    state->u.f4.fld.sta.txact = cm_object_get_child_by_name(state->u.f4.reg.sta, "TXACT"); 
    state->u.f4.fld.sta.rxact = cm_object_get_child_by_name(state->u.f4.reg.sta, "RXACT"); 
    state->u.f4.fld.sta.txfifohe = cm_object_get_child_by_name(state->u.f4.reg.sta, "TXFIFOHE"); 
    state->u.f4.fld.sta.rxfifohf = cm_object_get_child_by_name(state->u.f4.reg.sta, "RXFIFOHF"); 
    state->u.f4.fld.sta.txfifof = cm_object_get_child_by_name(state->u.f4.reg.sta, "TXFIFOF"); 
    state->u.f4.fld.sta.rxfifof = cm_object_get_child_by_name(state->u.f4.reg.sta, "RXFIFOF"); 
    state->u.f4.fld.sta.txfifoe = cm_object_get_child_by_name(state->u.f4.reg.sta, "TXFIFOE"); 
    state->u.f4.fld.sta.rxfifoe = cm_object_get_child_by_name(state->u.f4.reg.sta, "RXFIFOE"); 
    state->u.f4.fld.sta.txdavl = cm_object_get_child_by_name(state->u.f4.reg.sta, "TXDAVL"); 
    state->u.f4.fld.sta.rxdavl = cm_object_get_child_by_name(state->u.f4.reg.sta, "RXDAVL"); 
    state->u.f4.fld.sta.sdioit = cm_object_get_child_by_name(state->u.f4.reg.sta, "SDIOIT"); 
    state->u.f4.fld.sta.ceataend = cm_object_get_child_by_name(state->u.f4.reg.sta, "CEATAEND");  
    
    // ICR bitfields.
    state->u.f4.fld.icr.ccrcfailc = cm_object_get_child_by_name(state->u.f4.reg.icr, "CCRCFAILC"); 
    state->u.f4.fld.icr.dcrcfailc = cm_object_get_child_by_name(state->u.f4.reg.icr, "DCRCFAILC"); 
    state->u.f4.fld.icr.ctimeoutc = cm_object_get_child_by_name(state->u.f4.reg.icr, "CTIMEOUTC"); 
    state->u.f4.fld.icr.dtimeoutc = cm_object_get_child_by_name(state->u.f4.reg.icr, "DTIMEOUTC"); 
    state->u.f4.fld.icr.txunderrc = cm_object_get_child_by_name(state->u.f4.reg.icr, "TXUNDERRC"); 
    state->u.f4.fld.icr.rxoverrc = cm_object_get_child_by_name(state->u.f4.reg.icr, "RXOVERRC"); 
    state->u.f4.fld.icr.cmdrendc = cm_object_get_child_by_name(state->u.f4.reg.icr, "CMDRENDC"); 
    state->u.f4.fld.icr.cmdsentc = cm_object_get_child_by_name(state->u.f4.reg.icr, "CMDSENTC"); 
    state->u.f4.fld.icr.dataendc = cm_object_get_child_by_name(state->u.f4.reg.icr, "DATAENDC"); 
    state->u.f4.fld.icr.stbiterrc = cm_object_get_child_by_name(state->u.f4.reg.icr, "STBITERRC"); 
    state->u.f4.fld.icr.dbckendc = cm_object_get_child_by_name(state->u.f4.reg.icr, "DBCKENDC"); 
    state->u.f4.fld.icr.sdioitc = cm_object_get_child_by_name(state->u.f4.reg.icr, "SDIOITC"); 
    state->u.f4.fld.icr.ceataendc = cm_object_get_child_by_name(state->u.f4.reg.icr, "CEATAENDC");  
    
    // MASK bitfields.
    state->u.f4.fld.mask.ccrcfailie = cm_object_get_child_by_name(state->u.f4.reg.mask, "CCRCFAILIE"); 
    state->u.f4.fld.mask.dcrcfailie = cm_object_get_child_by_name(state->u.f4.reg.mask, "DCRCFAILIE"); 
    state->u.f4.fld.mask.ctimeoutie = cm_object_get_child_by_name(state->u.f4.reg.mask, "CTIMEOUTIE"); 
    state->u.f4.fld.mask.dtimeoutie = cm_object_get_child_by_name(state->u.f4.reg.mask, "DTIMEOUTIE"); 
    state->u.f4.fld.mask.txunderrie = cm_object_get_child_by_name(state->u.f4.reg.mask, "TXUNDERRIE"); 
    state->u.f4.fld.mask.rxoverrie = cm_object_get_child_by_name(state->u.f4.reg.mask, "RXOVERRIE"); 
    state->u.f4.fld.mask.cmdrendie = cm_object_get_child_by_name(state->u.f4.reg.mask, "CMDRENDIE"); 
    state->u.f4.fld.mask.cmdsentie = cm_object_get_child_by_name(state->u.f4.reg.mask, "CMDSENTIE"); 
    state->u.f4.fld.mask.dataendie = cm_object_get_child_by_name(state->u.f4.reg.mask, "DATAENDIE"); 
    state->u.f4.fld.mask.stbiterrie = cm_object_get_child_by_name(state->u.f4.reg.mask, "STBITERRIE"); 
    state->u.f4.fld.mask.dbckendie = cm_object_get_child_by_name(state->u.f4.reg.mask, "DBCKENDIE"); 
    state->u.f4.fld.mask.cmdactie = cm_object_get_child_by_name(state->u.f4.reg.mask, "CMDACTIE"); 
    state->u.f4.fld.mask.txactie = cm_object_get_child_by_name(state->u.f4.reg.mask, "TXACTIE"); 
    state->u.f4.fld.mask.rxactie = cm_object_get_child_by_name(state->u.f4.reg.mask, "RXACTIE"); 
    state->u.f4.fld.mask.txfifoheie = cm_object_get_child_by_name(state->u.f4.reg.mask, "TXFIFOHEIE"); 
    state->u.f4.fld.mask.rxfifohfie = cm_object_get_child_by_name(state->u.f4.reg.mask, "RXFIFOHFIE"); 
    state->u.f4.fld.mask.txfifofie = cm_object_get_child_by_name(state->u.f4.reg.mask, "TXFIFOFIE"); 
    state->u.f4.fld.mask.rxfifofie = cm_object_get_child_by_name(state->u.f4.reg.mask, "RXFIFOFIE"); 
    state->u.f4.fld.mask.txfifoeie = cm_object_get_child_by_name(state->u.f4.reg.mask, "TXFIFOEIE"); 
    state->u.f4.fld.mask.rxfifoeie = cm_object_get_child_by_name(state->u.f4.reg.mask, "RXFIFOEIE"); 
    state->u.f4.fld.mask.txdavlie = cm_object_get_child_by_name(state->u.f4.reg.mask, "TXDAVLIE"); 
    state->u.f4.fld.mask.rxdavlie = cm_object_get_child_by_name(state->u.f4.reg.mask, "RXDAVLIE"); 
    state->u.f4.fld.mask.sdioitie = cm_object_get_child_by_name(state->u.f4.reg.mask, "SDIOITIE"); 
    state->u.f4.fld.mask.ceataendie = cm_object_get_child_by_name(state->u.f4.reg.mask, "CEATAENDIE");  
    
    // FIFOCNT bitfields.
    state->u.f4.fld.fifocnt.fifocount = cm_object_get_child_by_name(state->u.f4.reg.fifocnt, "FIFOCOUNT");  
    
    // FIFO bitfields.
    state->u.f4.fld.fifo.fifodata = cm_object_get_child_by_name(state->u.f4.reg.fifo, "FIFOData");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_sdio_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32SDIOState *state = STM32_SDIO_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_sdio_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32SDIOState *state = STM32_SDIO_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_sdio_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32SDIOState *state = STM32_SDIO_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_sdio_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32SDIOState *state = STM32_SDIO_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_sdio_is_enabled(Object *obj)
{
    STM32SDIOState *state = STM32_SDIO_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_sdio_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32SDIOState *state = STM32_SDIO_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_sdio_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_SDIO)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32SDIOState *state = STM32_SDIO_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "SDIO";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_429x ) {

            stm32f429x_sdio_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_sdio_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_sdio_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_sdio_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_sdio_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/SDIOEN");


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

static void stm32_sdio_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_SDIO);
}

static void stm32_sdio_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_sdio_reset_callback;
    dc->realize = stm32_sdio_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_sdio_is_enabled;
}

static const TypeInfo stm32_sdio_type_info = {
    .name = TYPE_STM32_SDIO,
    .parent = TYPE_STM32_SDIO_PARENT,
    .instance_init = stm32_sdio_instance_init_callback,
    .instance_size = sizeof(STM32SDIOState),
    .class_init = stm32_sdio_class_init_callback,
    .class_size = sizeof(STM32SDIOClass) };

static void stm32_sdio_register_types(void)
{
    type_register_static(&stm32_sdio_type_info);
}

type_init(stm32_sdio_register_types);

// ----------------------------------------------------------------------------
