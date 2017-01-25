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
static void stm32f103xx_sdio_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32SDIOState *state = STM32_SDIO_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f1.reg.power = cm_object_get_child_by_name(obj, "POWER");
    state->u.f1.reg.clkcr = cm_object_get_child_by_name(obj, "CLKCR");
    state->u.f1.reg.arg = cm_object_get_child_by_name(obj, "ARG");
    state->u.f1.reg.cmd = cm_object_get_child_by_name(obj, "CMD");
    state->u.f1.reg.respcmd = cm_object_get_child_by_name(obj, "RESPCMD");
    state->u.f1.reg.respi1 = cm_object_get_child_by_name(obj, "RESPI1");
    state->u.f1.reg.resp2 = cm_object_get_child_by_name(obj, "RESP2");
    state->u.f1.reg.resp3 = cm_object_get_child_by_name(obj, "RESP3");
    state->u.f1.reg.resp4 = cm_object_get_child_by_name(obj, "RESP4");
    state->u.f1.reg.dtimer = cm_object_get_child_by_name(obj, "DTIMER");
    state->u.f1.reg.dlen = cm_object_get_child_by_name(obj, "DLEN");
    state->u.f1.reg.dctrl = cm_object_get_child_by_name(obj, "DCTRL");
    state->u.f1.reg.dcount = cm_object_get_child_by_name(obj, "DCOUNT");
    state->u.f1.reg.sta = cm_object_get_child_by_name(obj, "STA");
    state->u.f1.reg.icr = cm_object_get_child_by_name(obj, "ICR");
    state->u.f1.reg.mask = cm_object_get_child_by_name(obj, "MASK");
    state->u.f1.reg.fifocnt = cm_object_get_child_by_name(obj, "FIFOCNT");
    state->u.f1.reg.fifo = cm_object_get_child_by_name(obj, "FIFO");
    
    
    // POWER bitfields.
    state->u.f1.fld.power.pwrctrl = cm_object_get_child_by_name(state->u.f1.reg.power, "PWRCTRL");  
    
    // CLKCR bitfields.
    state->u.f1.fld.clkcr.clkdiv = cm_object_get_child_by_name(state->u.f1.reg.clkcr, "CLKDIV"); 
    state->u.f1.fld.clkcr.clken = cm_object_get_child_by_name(state->u.f1.reg.clkcr, "CLKEN"); 
    state->u.f1.fld.clkcr.pwrsav = cm_object_get_child_by_name(state->u.f1.reg.clkcr, "PWRSAV"); 
    state->u.f1.fld.clkcr.bypass = cm_object_get_child_by_name(state->u.f1.reg.clkcr, "BYPASS"); 
    state->u.f1.fld.clkcr.widbus = cm_object_get_child_by_name(state->u.f1.reg.clkcr, "WIDBUS"); 
    state->u.f1.fld.clkcr.negedge = cm_object_get_child_by_name(state->u.f1.reg.clkcr, "NEGEDGE"); 
    state->u.f1.fld.clkcr.hwfc_en = cm_object_get_child_by_name(state->u.f1.reg.clkcr, "HWFC_EN");  
    
    // ARG bitfields.
    state->u.f1.fld.arg.cmdarg = cm_object_get_child_by_name(state->u.f1.reg.arg, "CMDARG");  
    
    // CMD bitfields.
    state->u.f1.fld.cmd.cmdindex = cm_object_get_child_by_name(state->u.f1.reg.cmd, "CMDINDEX"); 
    state->u.f1.fld.cmd.waitresp = cm_object_get_child_by_name(state->u.f1.reg.cmd, "WAITRESP"); 
    state->u.f1.fld.cmd.waitint = cm_object_get_child_by_name(state->u.f1.reg.cmd, "WAITINT"); 
    state->u.f1.fld.cmd.waitpend = cm_object_get_child_by_name(state->u.f1.reg.cmd, "WAITPEND"); 
    state->u.f1.fld.cmd.cpsmen = cm_object_get_child_by_name(state->u.f1.reg.cmd, "CPSMEN"); 
    state->u.f1.fld.cmd.sdiosuspend = cm_object_get_child_by_name(state->u.f1.reg.cmd, "SDIOSuspend"); 
    state->u.f1.fld.cmd.encmdcompl = cm_object_get_child_by_name(state->u.f1.reg.cmd, "ENCMDcompl"); 
    state->u.f1.fld.cmd.nien = cm_object_get_child_by_name(state->u.f1.reg.cmd, "nIEN"); 
    state->u.f1.fld.cmd.ce_atacmd = cm_object_get_child_by_name(state->u.f1.reg.cmd, "CE_ATACMD");  
    
    // RESPCMD bitfields.
    state->u.f1.fld.respcmd.respcmd = cm_object_get_child_by_name(state->u.f1.reg.respcmd, "RESPCMD");  
    
    // RESPI1 bitfields.
    state->u.f1.fld.respi1.cardstatus1 = cm_object_get_child_by_name(state->u.f1.reg.respi1, "CARDSTATUS1");  
    
    // RESP2 bitfields.
    state->u.f1.fld.resp2.cardstatus2 = cm_object_get_child_by_name(state->u.f1.reg.resp2, "CARDSTATUS2");  
    
    // RESP3 bitfields.
    state->u.f1.fld.resp3.cardstatus3 = cm_object_get_child_by_name(state->u.f1.reg.resp3, "CARDSTATUS3");  
    
    // RESP4 bitfields.
    state->u.f1.fld.resp4.cardstatus4 = cm_object_get_child_by_name(state->u.f1.reg.resp4, "CARDSTATUS4");  
    
    // DTIMER bitfields.
    state->u.f1.fld.dtimer.datatime = cm_object_get_child_by_name(state->u.f1.reg.dtimer, "DATATIME");  
    
    // DLEN bitfields.
    state->u.f1.fld.dlen.datalength = cm_object_get_child_by_name(state->u.f1.reg.dlen, "DATALENGTH");  
    
    // DCTRL bitfields.
    state->u.f1.fld.dctrl.dten = cm_object_get_child_by_name(state->u.f1.reg.dctrl, "DTEN"); 
    state->u.f1.fld.dctrl.dtdir = cm_object_get_child_by_name(state->u.f1.reg.dctrl, "DTDIR"); 
    state->u.f1.fld.dctrl.dtmode = cm_object_get_child_by_name(state->u.f1.reg.dctrl, "DTMODE"); 
    state->u.f1.fld.dctrl.dmaen = cm_object_get_child_by_name(state->u.f1.reg.dctrl, "DMAEN"); 
    state->u.f1.fld.dctrl.dblocksize = cm_object_get_child_by_name(state->u.f1.reg.dctrl, "DBLOCKSIZE"); 
    state->u.f1.fld.dctrl.pwstart = cm_object_get_child_by_name(state->u.f1.reg.dctrl, "PWSTART"); 
    state->u.f1.fld.dctrl.pwstop = cm_object_get_child_by_name(state->u.f1.reg.dctrl, "PWSTOP"); 
    state->u.f1.fld.dctrl.rwmod = cm_object_get_child_by_name(state->u.f1.reg.dctrl, "RWMOD"); 
    state->u.f1.fld.dctrl.sdioen = cm_object_get_child_by_name(state->u.f1.reg.dctrl, "SDIOEN");  
    
    // DCOUNT bitfields.
    state->u.f1.fld.dcount.datacount = cm_object_get_child_by_name(state->u.f1.reg.dcount, "DATACOUNT");  
    
    // STA bitfields.
    state->u.f1.fld.sta.ccrcfail = cm_object_get_child_by_name(state->u.f1.reg.sta, "CCRCFAIL"); 
    state->u.f1.fld.sta.dcrcfail = cm_object_get_child_by_name(state->u.f1.reg.sta, "DCRCFAIL"); 
    state->u.f1.fld.sta.ctimeout = cm_object_get_child_by_name(state->u.f1.reg.sta, "CTIMEOUT"); 
    state->u.f1.fld.sta.dtimeout = cm_object_get_child_by_name(state->u.f1.reg.sta, "DTIMEOUT"); 
    state->u.f1.fld.sta.txunderr = cm_object_get_child_by_name(state->u.f1.reg.sta, "TXUNDERR"); 
    state->u.f1.fld.sta.rxoverr = cm_object_get_child_by_name(state->u.f1.reg.sta, "RXOVERR"); 
    state->u.f1.fld.sta.cmdrend = cm_object_get_child_by_name(state->u.f1.reg.sta, "CMDREND"); 
    state->u.f1.fld.sta.cmdsent = cm_object_get_child_by_name(state->u.f1.reg.sta, "CMDSENT"); 
    state->u.f1.fld.sta.dataend = cm_object_get_child_by_name(state->u.f1.reg.sta, "DATAEND"); 
    state->u.f1.fld.sta.stbiterr = cm_object_get_child_by_name(state->u.f1.reg.sta, "STBITERR"); 
    state->u.f1.fld.sta.dbckend = cm_object_get_child_by_name(state->u.f1.reg.sta, "DBCKEND"); 
    state->u.f1.fld.sta.cmdact = cm_object_get_child_by_name(state->u.f1.reg.sta, "CMDACT"); 
    state->u.f1.fld.sta.txact = cm_object_get_child_by_name(state->u.f1.reg.sta, "TXACT"); 
    state->u.f1.fld.sta.rxact = cm_object_get_child_by_name(state->u.f1.reg.sta, "RXACT"); 
    state->u.f1.fld.sta.txfifohe = cm_object_get_child_by_name(state->u.f1.reg.sta, "TXFIFOHE"); 
    state->u.f1.fld.sta.rxfifohf = cm_object_get_child_by_name(state->u.f1.reg.sta, "RXFIFOHF"); 
    state->u.f1.fld.sta.txfifof = cm_object_get_child_by_name(state->u.f1.reg.sta, "TXFIFOF"); 
    state->u.f1.fld.sta.rxfifof = cm_object_get_child_by_name(state->u.f1.reg.sta, "RXFIFOF"); 
    state->u.f1.fld.sta.txfifoe = cm_object_get_child_by_name(state->u.f1.reg.sta, "TXFIFOE"); 
    state->u.f1.fld.sta.rxfifoe = cm_object_get_child_by_name(state->u.f1.reg.sta, "RXFIFOE"); 
    state->u.f1.fld.sta.txdavl = cm_object_get_child_by_name(state->u.f1.reg.sta, "TXDAVL"); 
    state->u.f1.fld.sta.rxdavl = cm_object_get_child_by_name(state->u.f1.reg.sta, "RXDAVL"); 
    state->u.f1.fld.sta.sdioit = cm_object_get_child_by_name(state->u.f1.reg.sta, "SDIOIT"); 
    state->u.f1.fld.sta.ceataend = cm_object_get_child_by_name(state->u.f1.reg.sta, "CEATAEND");  
    
    // ICR bitfields.
    state->u.f1.fld.icr.ccrcfailc = cm_object_get_child_by_name(state->u.f1.reg.icr, "CCRCFAILC"); 
    state->u.f1.fld.icr.dcrcfailc = cm_object_get_child_by_name(state->u.f1.reg.icr, "DCRCFAILC"); 
    state->u.f1.fld.icr.ctimeoutc = cm_object_get_child_by_name(state->u.f1.reg.icr, "CTIMEOUTC"); 
    state->u.f1.fld.icr.dtimeoutc = cm_object_get_child_by_name(state->u.f1.reg.icr, "DTIMEOUTC"); 
    state->u.f1.fld.icr.txunderrc = cm_object_get_child_by_name(state->u.f1.reg.icr, "TXUNDERRC"); 
    state->u.f1.fld.icr.rxoverrc = cm_object_get_child_by_name(state->u.f1.reg.icr, "RXOVERRC"); 
    state->u.f1.fld.icr.cmdrendc = cm_object_get_child_by_name(state->u.f1.reg.icr, "CMDRENDC"); 
    state->u.f1.fld.icr.cmdsentc = cm_object_get_child_by_name(state->u.f1.reg.icr, "CMDSENTC"); 
    state->u.f1.fld.icr.dataendc = cm_object_get_child_by_name(state->u.f1.reg.icr, "DATAENDC"); 
    state->u.f1.fld.icr.stbiterrc = cm_object_get_child_by_name(state->u.f1.reg.icr, "STBITERRC"); 
    state->u.f1.fld.icr.dbckendc = cm_object_get_child_by_name(state->u.f1.reg.icr, "DBCKENDC"); 
    state->u.f1.fld.icr.sdioitc = cm_object_get_child_by_name(state->u.f1.reg.icr, "SDIOITC"); 
    state->u.f1.fld.icr.ceataendc = cm_object_get_child_by_name(state->u.f1.reg.icr, "CEATAENDC");  
    
    // MASK bitfields.
    state->u.f1.fld.mask.ccrcfailie = cm_object_get_child_by_name(state->u.f1.reg.mask, "CCRCFAILIE"); 
    state->u.f1.fld.mask.dcrcfailie = cm_object_get_child_by_name(state->u.f1.reg.mask, "DCRCFAILIE"); 
    state->u.f1.fld.mask.ctimeoutie = cm_object_get_child_by_name(state->u.f1.reg.mask, "CTIMEOUTIE"); 
    state->u.f1.fld.mask.dtimeoutie = cm_object_get_child_by_name(state->u.f1.reg.mask, "DTIMEOUTIE"); 
    state->u.f1.fld.mask.txunderrie = cm_object_get_child_by_name(state->u.f1.reg.mask, "TXUNDERRIE"); 
    state->u.f1.fld.mask.rxoverrie = cm_object_get_child_by_name(state->u.f1.reg.mask, "RXOVERRIE"); 
    state->u.f1.fld.mask.cmdrendie = cm_object_get_child_by_name(state->u.f1.reg.mask, "CMDRENDIE"); 
    state->u.f1.fld.mask.cmdsentie = cm_object_get_child_by_name(state->u.f1.reg.mask, "CMDSENTIE"); 
    state->u.f1.fld.mask.dataendie = cm_object_get_child_by_name(state->u.f1.reg.mask, "DATAENDIE"); 
    state->u.f1.fld.mask.stbiterrie = cm_object_get_child_by_name(state->u.f1.reg.mask, "STBITERRIE"); 
    state->u.f1.fld.mask.dbackendie = cm_object_get_child_by_name(state->u.f1.reg.mask, "DBACKENDIE"); 
    state->u.f1.fld.mask.cmdactie = cm_object_get_child_by_name(state->u.f1.reg.mask, "CMDACTIE"); 
    state->u.f1.fld.mask.txactie = cm_object_get_child_by_name(state->u.f1.reg.mask, "TXACTIE"); 
    state->u.f1.fld.mask.rxactie = cm_object_get_child_by_name(state->u.f1.reg.mask, "RXACTIE"); 
    state->u.f1.fld.mask.txfifoheie = cm_object_get_child_by_name(state->u.f1.reg.mask, "TXFIFOHEIE"); 
    state->u.f1.fld.mask.rxfifohfie = cm_object_get_child_by_name(state->u.f1.reg.mask, "RXFIFOHFIE"); 
    state->u.f1.fld.mask.txfifofie = cm_object_get_child_by_name(state->u.f1.reg.mask, "TXFIFOFIE"); 
    state->u.f1.fld.mask.rxfifofie = cm_object_get_child_by_name(state->u.f1.reg.mask, "RXFIFOFIE"); 
    state->u.f1.fld.mask.txfifoeie = cm_object_get_child_by_name(state->u.f1.reg.mask, "TXFIFOEIE"); 
    state->u.f1.fld.mask.rxfifoeie = cm_object_get_child_by_name(state->u.f1.reg.mask, "RXFIFOEIE"); 
    state->u.f1.fld.mask.txdavlie = cm_object_get_child_by_name(state->u.f1.reg.mask, "TXDAVLIE"); 
    state->u.f1.fld.mask.rxdavlie = cm_object_get_child_by_name(state->u.f1.reg.mask, "RXDAVLIE"); 
    state->u.f1.fld.mask.sdioitie = cm_object_get_child_by_name(state->u.f1.reg.mask, "SDIOITIE"); 
    state->u.f1.fld.mask.ceatendie = cm_object_get_child_by_name(state->u.f1.reg.mask, "CEATENDIE");  
    
    // FIFOCNT bitfields.
    state->u.f1.fld.fifocnt.fif0count = cm_object_get_child_by_name(state->u.f1.reg.fifocnt, "FIF0COUNT");  
    
    // FIFO bitfields.
    state->u.f1.fld.fifo.fifodata = cm_object_get_child_by_name(state->u.f1.reg.fifo, "FIFOData");  
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
    case STM32_FAMILY_F1:

        if (capabilities->f1.is_103xx ) {

            stm32f103xx_sdio_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f1.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f1.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f1.reg.xxx, &stm32_sdio_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f1.reg.xxx, &stm32_sdio_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f1.reg.xxx, &stm32_sdio_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f1.reg.xxx, &stm32_sdio_xxx_post_write_callback);

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
