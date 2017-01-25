/*
 * STM32 - Ethernet_MAC (Ethernet: media access control (MAC)) emulation.
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

#include <hw/cortexm/stm32/ethernet_mac.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f40x_ethernet_mac_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32Ethernet_MACState *state = STM32_Ethernet_MAC_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.maccr = cm_object_get_child_by_name(obj, "MACCR");
    state->u.f4.reg.macffr = cm_object_get_child_by_name(obj, "MACFFR");
    state->u.f4.reg.machthr = cm_object_get_child_by_name(obj, "MACHTHR");
    state->u.f4.reg.machtlr = cm_object_get_child_by_name(obj, "MACHTLR");
    state->u.f4.reg.macmiiar = cm_object_get_child_by_name(obj, "MACMIIAR");
    state->u.f4.reg.macmiidr = cm_object_get_child_by_name(obj, "MACMIIDR");
    state->u.f4.reg.macfcr = cm_object_get_child_by_name(obj, "MACFCR");
    state->u.f4.reg.macvlantr = cm_object_get_child_by_name(obj, "MACVLANTR");
    state->u.f4.reg.macpmtcsr = cm_object_get_child_by_name(obj, "MACPMTCSR");
    state->u.f4.reg.macdbgr = cm_object_get_child_by_name(obj, "MACDBGR");
    state->u.f4.reg.macsr = cm_object_get_child_by_name(obj, "MACSR");
    state->u.f4.reg.macimr = cm_object_get_child_by_name(obj, "MACIMR");
    state->u.f4.reg.maca0hr = cm_object_get_child_by_name(obj, "MACA0HR");
    state->u.f4.reg.maca0lr = cm_object_get_child_by_name(obj, "MACA0LR");
    state->u.f4.reg.maca1hr = cm_object_get_child_by_name(obj, "MACA1HR");
    state->u.f4.reg.maca1lr = cm_object_get_child_by_name(obj, "MACA1LR");
    state->u.f4.reg.maca2hr = cm_object_get_child_by_name(obj, "MACA2HR");
    state->u.f4.reg.maca2lr = cm_object_get_child_by_name(obj, "MACA2LR");
    state->u.f4.reg.maca3hr = cm_object_get_child_by_name(obj, "MACA3HR");
    state->u.f4.reg.maca3lr = cm_object_get_child_by_name(obj, "MACA3LR");
    
    
    // MACCR bitfields.
    state->u.f4.fld.maccr.re = cm_object_get_child_by_name(state->u.f4.reg.maccr, "RE"); 
    state->u.f4.fld.maccr.te = cm_object_get_child_by_name(state->u.f4.reg.maccr, "TE"); 
    state->u.f4.fld.maccr.dc = cm_object_get_child_by_name(state->u.f4.reg.maccr, "DC"); 
    state->u.f4.fld.maccr.bl = cm_object_get_child_by_name(state->u.f4.reg.maccr, "BL"); 
    state->u.f4.fld.maccr.apcs = cm_object_get_child_by_name(state->u.f4.reg.maccr, "APCS"); 
    state->u.f4.fld.maccr.rd = cm_object_get_child_by_name(state->u.f4.reg.maccr, "RD"); 
    state->u.f4.fld.maccr.ipco = cm_object_get_child_by_name(state->u.f4.reg.maccr, "IPCO"); 
    state->u.f4.fld.maccr.dm = cm_object_get_child_by_name(state->u.f4.reg.maccr, "DM"); 
    state->u.f4.fld.maccr.lm = cm_object_get_child_by_name(state->u.f4.reg.maccr, "LM"); 
    state->u.f4.fld.maccr.rod = cm_object_get_child_by_name(state->u.f4.reg.maccr, "ROD"); 
    state->u.f4.fld.maccr.fes = cm_object_get_child_by_name(state->u.f4.reg.maccr, "FES"); 
    state->u.f4.fld.maccr.csd = cm_object_get_child_by_name(state->u.f4.reg.maccr, "CSD"); 
    state->u.f4.fld.maccr.ifg = cm_object_get_child_by_name(state->u.f4.reg.maccr, "IFG"); 
    state->u.f4.fld.maccr.jd = cm_object_get_child_by_name(state->u.f4.reg.maccr, "JD"); 
    state->u.f4.fld.maccr.wd = cm_object_get_child_by_name(state->u.f4.reg.maccr, "WD"); 
    state->u.f4.fld.maccr.cstf = cm_object_get_child_by_name(state->u.f4.reg.maccr, "CSTF");  
    
    // MACFFR bitfields.
    state->u.f4.fld.macffr.pm = cm_object_get_child_by_name(state->u.f4.reg.macffr, "PM"); 
    state->u.f4.fld.macffr.hu = cm_object_get_child_by_name(state->u.f4.reg.macffr, "HU"); 
    state->u.f4.fld.macffr.hm = cm_object_get_child_by_name(state->u.f4.reg.macffr, "HM"); 
    state->u.f4.fld.macffr.daif = cm_object_get_child_by_name(state->u.f4.reg.macffr, "DAIF"); 
    state->u.f4.fld.macffr.ram = cm_object_get_child_by_name(state->u.f4.reg.macffr, "RAM"); 
    state->u.f4.fld.macffr.bfd = cm_object_get_child_by_name(state->u.f4.reg.macffr, "BFD"); 
    state->u.f4.fld.macffr.pcf = cm_object_get_child_by_name(state->u.f4.reg.macffr, "PCF"); 
    state->u.f4.fld.macffr.saif = cm_object_get_child_by_name(state->u.f4.reg.macffr, "SAIF"); 
    state->u.f4.fld.macffr.saf = cm_object_get_child_by_name(state->u.f4.reg.macffr, "SAF"); 
    state->u.f4.fld.macffr.hpf = cm_object_get_child_by_name(state->u.f4.reg.macffr, "HPF"); 
    state->u.f4.fld.macffr.ra = cm_object_get_child_by_name(state->u.f4.reg.macffr, "RA");  
    
    // MACHTHR bitfields.
    state->u.f4.fld.machthr.hth = cm_object_get_child_by_name(state->u.f4.reg.machthr, "HTH");  
    
    // MACHTLR bitfields.
    state->u.f4.fld.machtlr.htl = cm_object_get_child_by_name(state->u.f4.reg.machtlr, "HTL");  
    
    // MACMIIAR bitfields.
    state->u.f4.fld.macmiiar.mb = cm_object_get_child_by_name(state->u.f4.reg.macmiiar, "MB"); 
    state->u.f4.fld.macmiiar.mw = cm_object_get_child_by_name(state->u.f4.reg.macmiiar, "MW"); 
    state->u.f4.fld.macmiiar.cr = cm_object_get_child_by_name(state->u.f4.reg.macmiiar, "CR"); 
    state->u.f4.fld.macmiiar.mr = cm_object_get_child_by_name(state->u.f4.reg.macmiiar, "MR"); 
    state->u.f4.fld.macmiiar.pa = cm_object_get_child_by_name(state->u.f4.reg.macmiiar, "PA");  
    
    // MACMIIDR bitfields.
    state->u.f4.fld.macmiidr.td = cm_object_get_child_by_name(state->u.f4.reg.macmiidr, "TD");  
    
    // MACFCR bitfields.
    state->u.f4.fld.macfcr.fcb = cm_object_get_child_by_name(state->u.f4.reg.macfcr, "FCB"); 
    state->u.f4.fld.macfcr.tfce = cm_object_get_child_by_name(state->u.f4.reg.macfcr, "TFCE"); 
    state->u.f4.fld.macfcr.rfce = cm_object_get_child_by_name(state->u.f4.reg.macfcr, "RFCE"); 
    state->u.f4.fld.macfcr.upfd = cm_object_get_child_by_name(state->u.f4.reg.macfcr, "UPFD"); 
    state->u.f4.fld.macfcr.plt = cm_object_get_child_by_name(state->u.f4.reg.macfcr, "PLT"); 
    state->u.f4.fld.macfcr.zqpd = cm_object_get_child_by_name(state->u.f4.reg.macfcr, "ZQPD"); 
    state->u.f4.fld.macfcr.pt = cm_object_get_child_by_name(state->u.f4.reg.macfcr, "PT");  
    
    // MACVLANTR bitfields.
    state->u.f4.fld.macvlantr.vlanti = cm_object_get_child_by_name(state->u.f4.reg.macvlantr, "VLANTI"); 
    state->u.f4.fld.macvlantr.vlantc = cm_object_get_child_by_name(state->u.f4.reg.macvlantr, "VLANTC");  
    
    // MACPMTCSR bitfields.
    state->u.f4.fld.macpmtcsr.pd = cm_object_get_child_by_name(state->u.f4.reg.macpmtcsr, "PD"); 
    state->u.f4.fld.macpmtcsr.mpe = cm_object_get_child_by_name(state->u.f4.reg.macpmtcsr, "MPE"); 
    state->u.f4.fld.macpmtcsr.wfe = cm_object_get_child_by_name(state->u.f4.reg.macpmtcsr, "WFE"); 
    state->u.f4.fld.macpmtcsr.mpr = cm_object_get_child_by_name(state->u.f4.reg.macpmtcsr, "MPR"); 
    state->u.f4.fld.macpmtcsr.wfr = cm_object_get_child_by_name(state->u.f4.reg.macpmtcsr, "WFR"); 
    state->u.f4.fld.macpmtcsr.gu = cm_object_get_child_by_name(state->u.f4.reg.macpmtcsr, "GU"); 
    state->u.f4.fld.macpmtcsr.wffrpr = cm_object_get_child_by_name(state->u.f4.reg.macpmtcsr, "WFFRPR");  
    
    // MACDBGR bitfields.
    state->u.f4.fld.macdbgr.cr = cm_object_get_child_by_name(state->u.f4.reg.macdbgr, "CR"); 
    state->u.f4.fld.macdbgr.csr = cm_object_get_child_by_name(state->u.f4.reg.macdbgr, "CSR"); 
    state->u.f4.fld.macdbgr.ror = cm_object_get_child_by_name(state->u.f4.reg.macdbgr, "ROR"); 
    state->u.f4.fld.macdbgr.mcf = cm_object_get_child_by_name(state->u.f4.reg.macdbgr, "MCF"); 
    state->u.f4.fld.macdbgr.mcp = cm_object_get_child_by_name(state->u.f4.reg.macdbgr, "MCP"); 
    state->u.f4.fld.macdbgr.mcfhp = cm_object_get_child_by_name(state->u.f4.reg.macdbgr, "MCFHP");  
    
    // MACSR bitfields.
    state->u.f4.fld.macsr.pmts = cm_object_get_child_by_name(state->u.f4.reg.macsr, "PMTS"); 
    state->u.f4.fld.macsr.mmcs = cm_object_get_child_by_name(state->u.f4.reg.macsr, "MMCS"); 
    state->u.f4.fld.macsr.mmcrs = cm_object_get_child_by_name(state->u.f4.reg.macsr, "MMCRS"); 
    state->u.f4.fld.macsr.mmcts = cm_object_get_child_by_name(state->u.f4.reg.macsr, "MMCTS"); 
    state->u.f4.fld.macsr.tsts = cm_object_get_child_by_name(state->u.f4.reg.macsr, "TSTS");  
    
    // MACIMR bitfields.
    state->u.f4.fld.macimr.pmtim = cm_object_get_child_by_name(state->u.f4.reg.macimr, "PMTIM"); 
    state->u.f4.fld.macimr.tstim = cm_object_get_child_by_name(state->u.f4.reg.macimr, "TSTIM");  
    
    // MACA0HR bitfields.
    state->u.f4.fld.maca0hr.maca0h = cm_object_get_child_by_name(state->u.f4.reg.maca0hr, "MACA0H"); 
    state->u.f4.fld.maca0hr.mo = cm_object_get_child_by_name(state->u.f4.reg.maca0hr, "MO");  
    
    // MACA0LR bitfields.
    state->u.f4.fld.maca0lr.maca0l = cm_object_get_child_by_name(state->u.f4.reg.maca0lr, "MACA0L");  
    
    // MACA1HR bitfields.
    state->u.f4.fld.maca1hr.maca1h = cm_object_get_child_by_name(state->u.f4.reg.maca1hr, "MACA1H"); 
    state->u.f4.fld.maca1hr.mbc = cm_object_get_child_by_name(state->u.f4.reg.maca1hr, "MBC"); 
    state->u.f4.fld.maca1hr.sa = cm_object_get_child_by_name(state->u.f4.reg.maca1hr, "SA"); 
    state->u.f4.fld.maca1hr.ae = cm_object_get_child_by_name(state->u.f4.reg.maca1hr, "AE");  
    
    // MACA1LR bitfields.
    state->u.f4.fld.maca1lr.maca1lr = cm_object_get_child_by_name(state->u.f4.reg.maca1lr, "MACA1LR");  
    
    // MACA2HR bitfields.
    state->u.f4.fld.maca2hr.mac2ah = cm_object_get_child_by_name(state->u.f4.reg.maca2hr, "MAC2AH"); 
    state->u.f4.fld.maca2hr.mbc = cm_object_get_child_by_name(state->u.f4.reg.maca2hr, "MBC"); 
    state->u.f4.fld.maca2hr.sa = cm_object_get_child_by_name(state->u.f4.reg.maca2hr, "SA"); 
    state->u.f4.fld.maca2hr.ae = cm_object_get_child_by_name(state->u.f4.reg.maca2hr, "AE");  
    
    // MACA2LR bitfields.
    state->u.f4.fld.maca2lr.maca2l = cm_object_get_child_by_name(state->u.f4.reg.maca2lr, "MACA2L");  
    
    // MACA3HR bitfields.
    state->u.f4.fld.maca3hr.maca3h = cm_object_get_child_by_name(state->u.f4.reg.maca3hr, "MACA3H"); 
    state->u.f4.fld.maca3hr.mbc = cm_object_get_child_by_name(state->u.f4.reg.maca3hr, "MBC"); 
    state->u.f4.fld.maca3hr.sa = cm_object_get_child_by_name(state->u.f4.reg.maca3hr, "SA"); 
    state->u.f4.fld.maca3hr.ae = cm_object_get_child_by_name(state->u.f4.reg.maca3hr, "AE");  
    
    // MACA3LR bitfields.
    state->u.f4.fld.maca3lr.mbca3l = cm_object_get_child_by_name(state->u.f4.reg.maca3lr, "MBCA3L");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_ethernet_mac_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32Ethernet_MACState *state = STM32_Ethernet_MAC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_ethernet_mac_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32Ethernet_MACState *state = STM32_Ethernet_MAC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_ethernet_mac_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32Ethernet_MACState *state = STM32_Ethernet_MAC_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_ethernet_mac_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32Ethernet_MACState *state = STM32_Ethernet_MAC_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_ethernet_mac_is_enabled(Object *obj)
{
    STM32Ethernet_MACState *state = STM32_Ethernet_MAC_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_ethernet_mac_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32Ethernet_MACState *state = STM32_Ethernet_MAC_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_ethernet_mac_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_Ethernet_MAC)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32Ethernet_MACState *state = STM32_Ethernet_MAC_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "Ethernet_MAC";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_40x ) {

            stm32f40x_ethernet_mac_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_ethernet_mac_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_ethernet_mac_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_ethernet_mac_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_ethernet_mac_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/Ethernet_MACEN");


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

static void stm32_ethernet_mac_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_Ethernet_MAC);
}

static void stm32_ethernet_mac_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_ethernet_mac_reset_callback;
    dc->realize = stm32_ethernet_mac_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_ethernet_mac_is_enabled;
}

static const TypeInfo stm32_ethernet_mac_type_info = {
    .name = TYPE_STM32_Ethernet_MAC,
    .parent = TYPE_STM32_Ethernet_MAC_PARENT,
    .instance_init = stm32_ethernet_mac_instance_init_callback,
    .instance_size = sizeof(STM32Ethernet_MACState),
    .class_init = stm32_ethernet_mac_class_init_callback,
    .class_size = sizeof(STM32Ethernet_MACClass) };

static void stm32_ethernet_mac_register_types(void)
{
    type_register_static(&stm32_ethernet_mac_type_info);
}

type_init(stm32_ethernet_mac_register_types);

// ----------------------------------------------------------------------------
