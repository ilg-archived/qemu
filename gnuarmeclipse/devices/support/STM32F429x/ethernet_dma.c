/*
 * STM32 - Ethernet_DMA (Ethernet: DMA controller operation) emulation.
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

#include <hw/cortexm/stm32/ethernet_dma.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f429x_ethernet_dma_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32Ethernet_DMAState *state = STM32_Ethernet_DMA_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.dmabmr = cm_object_get_child_by_name(obj, "DMABMR");
    state->u.f4.reg.dmatpdr = cm_object_get_child_by_name(obj, "DMATPDR");
    state->u.f4.reg.dmarpdr = cm_object_get_child_by_name(obj, "DMARPDR");
    state->u.f4.reg.dmardlar = cm_object_get_child_by_name(obj, "DMARDLAR");
    state->u.f4.reg.dmatdlar = cm_object_get_child_by_name(obj, "DMATDLAR");
    state->u.f4.reg.dmasr = cm_object_get_child_by_name(obj, "DMASR");
    state->u.f4.reg.dmaomr = cm_object_get_child_by_name(obj, "DMAOMR");
    state->u.f4.reg.dmaier = cm_object_get_child_by_name(obj, "DMAIER");
    state->u.f4.reg.dmamfbocr = cm_object_get_child_by_name(obj, "DMAMFBOCR");
    state->u.f4.reg.dmarswtr = cm_object_get_child_by_name(obj, "DMARSWTR");
    state->u.f4.reg.dmachtdr = cm_object_get_child_by_name(obj, "DMACHTDR");
    state->u.f4.reg.dmachrdr = cm_object_get_child_by_name(obj, "DMACHRDR");
    state->u.f4.reg.dmachtbar = cm_object_get_child_by_name(obj, "DMACHTBAR");
    state->u.f4.reg.dmachrbar = cm_object_get_child_by_name(obj, "DMACHRBAR");
    
    
    // DMABMR bitfields.
    state->u.f4.fld.dmabmr.sr = cm_object_get_child_by_name(state->u.f4.reg.dmabmr, "SR"); 
    state->u.f4.fld.dmabmr.da = cm_object_get_child_by_name(state->u.f4.reg.dmabmr, "DA"); 
    state->u.f4.fld.dmabmr.dsl = cm_object_get_child_by_name(state->u.f4.reg.dmabmr, "DSL"); 
    state->u.f4.fld.dmabmr.edfe = cm_object_get_child_by_name(state->u.f4.reg.dmabmr, "EDFE"); 
    state->u.f4.fld.dmabmr.pbl = cm_object_get_child_by_name(state->u.f4.reg.dmabmr, "PBL"); 
    state->u.f4.fld.dmabmr.rtpr = cm_object_get_child_by_name(state->u.f4.reg.dmabmr, "RTPR"); 
    state->u.f4.fld.dmabmr.fb = cm_object_get_child_by_name(state->u.f4.reg.dmabmr, "FB"); 
    state->u.f4.fld.dmabmr.rdp = cm_object_get_child_by_name(state->u.f4.reg.dmabmr, "RDP"); 
    state->u.f4.fld.dmabmr.usp = cm_object_get_child_by_name(state->u.f4.reg.dmabmr, "USP"); 
    state->u.f4.fld.dmabmr.fpm = cm_object_get_child_by_name(state->u.f4.reg.dmabmr, "FPM"); 
    state->u.f4.fld.dmabmr.aab = cm_object_get_child_by_name(state->u.f4.reg.dmabmr, "AAB"); 
    state->u.f4.fld.dmabmr.mb = cm_object_get_child_by_name(state->u.f4.reg.dmabmr, "MB");  
    
    // DMATPDR bitfields.
    state->u.f4.fld.dmatpdr.tpd = cm_object_get_child_by_name(state->u.f4.reg.dmatpdr, "TPD");  
    
    // DMARPDR bitfields.
    state->u.f4.fld.dmarpdr.rpd = cm_object_get_child_by_name(state->u.f4.reg.dmarpdr, "RPD");  
    
    // DMARDLAR bitfields.
    state->u.f4.fld.dmardlar.srl = cm_object_get_child_by_name(state->u.f4.reg.dmardlar, "SRL");  
    
    // DMATDLAR bitfields.
    state->u.f4.fld.dmatdlar.stl = cm_object_get_child_by_name(state->u.f4.reg.dmatdlar, "STL");  
    
    // DMASR bitfields.
    state->u.f4.fld.dmasr.ts = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "TS"); 
    state->u.f4.fld.dmasr.tpss = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "TPSS"); 
    state->u.f4.fld.dmasr.tbus = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "TBUS"); 
    state->u.f4.fld.dmasr.tjts = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "TJTS"); 
    state->u.f4.fld.dmasr.ros = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "ROS"); 
    state->u.f4.fld.dmasr.tus = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "TUS"); 
    state->u.f4.fld.dmasr.rs = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "RS"); 
    state->u.f4.fld.dmasr.rbus = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "RBUS"); 
    state->u.f4.fld.dmasr.rpss = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "RPSS"); 
    state->u.f4.fld.dmasr.pwts = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "PWTS"); 
    state->u.f4.fld.dmasr.ets = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "ETS"); 
    state->u.f4.fld.dmasr.fbes = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "FBES"); 
    state->u.f4.fld.dmasr.ers = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "ERS"); 
    state->u.f4.fld.dmasr.ais = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "AIS"); 
    state->u.f4.fld.dmasr.nis = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "NIS"); 
    state->u.f4.fld.dmasr.rps = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "RPS"); 
    state->u.f4.fld.dmasr.tps = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "TPS"); 
    state->u.f4.fld.dmasr.ebs = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "EBS"); 
    state->u.f4.fld.dmasr.mmcs = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "MMCS"); 
    state->u.f4.fld.dmasr.pmts = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "PMTS"); 
    state->u.f4.fld.dmasr.tsts = cm_object_get_child_by_name(state->u.f4.reg.dmasr, "TSTS");  
    
    // DMAOMR bitfields.
    state->u.f4.fld.dmaomr.sr = cm_object_get_child_by_name(state->u.f4.reg.dmaomr, "SR"); 
    state->u.f4.fld.dmaomr.osf = cm_object_get_child_by_name(state->u.f4.reg.dmaomr, "OSF"); 
    state->u.f4.fld.dmaomr.rtc = cm_object_get_child_by_name(state->u.f4.reg.dmaomr, "RTC"); 
    state->u.f4.fld.dmaomr.fugf = cm_object_get_child_by_name(state->u.f4.reg.dmaomr, "FUGF"); 
    state->u.f4.fld.dmaomr.fef = cm_object_get_child_by_name(state->u.f4.reg.dmaomr, "FEF"); 
    state->u.f4.fld.dmaomr.st = cm_object_get_child_by_name(state->u.f4.reg.dmaomr, "ST"); 
    state->u.f4.fld.dmaomr.ttc = cm_object_get_child_by_name(state->u.f4.reg.dmaomr, "TTC"); 
    state->u.f4.fld.dmaomr.ftf = cm_object_get_child_by_name(state->u.f4.reg.dmaomr, "FTF"); 
    state->u.f4.fld.dmaomr.tsf = cm_object_get_child_by_name(state->u.f4.reg.dmaomr, "TSF"); 
    state->u.f4.fld.dmaomr.dfrf = cm_object_get_child_by_name(state->u.f4.reg.dmaomr, "DFRF"); 
    state->u.f4.fld.dmaomr.rsf = cm_object_get_child_by_name(state->u.f4.reg.dmaomr, "RSF"); 
    state->u.f4.fld.dmaomr.dtcefd = cm_object_get_child_by_name(state->u.f4.reg.dmaomr, "DTCEFD");  
    
    // DMAIER bitfields.
    state->u.f4.fld.dmaier.tie = cm_object_get_child_by_name(state->u.f4.reg.dmaier, "TIE"); 
    state->u.f4.fld.dmaier.tpsie = cm_object_get_child_by_name(state->u.f4.reg.dmaier, "TPSIE"); 
    state->u.f4.fld.dmaier.tbuie = cm_object_get_child_by_name(state->u.f4.reg.dmaier, "TBUIE"); 
    state->u.f4.fld.dmaier.tjtie = cm_object_get_child_by_name(state->u.f4.reg.dmaier, "TJTIE"); 
    state->u.f4.fld.dmaier.roie = cm_object_get_child_by_name(state->u.f4.reg.dmaier, "ROIE"); 
    state->u.f4.fld.dmaier.tuie = cm_object_get_child_by_name(state->u.f4.reg.dmaier, "TUIE"); 
    state->u.f4.fld.dmaier.rie = cm_object_get_child_by_name(state->u.f4.reg.dmaier, "RIE"); 
    state->u.f4.fld.dmaier.rbuie = cm_object_get_child_by_name(state->u.f4.reg.dmaier, "RBUIE"); 
    state->u.f4.fld.dmaier.rpsie = cm_object_get_child_by_name(state->u.f4.reg.dmaier, "RPSIE"); 
    state->u.f4.fld.dmaier.rwtie = cm_object_get_child_by_name(state->u.f4.reg.dmaier, "RWTIE"); 
    state->u.f4.fld.dmaier.etie = cm_object_get_child_by_name(state->u.f4.reg.dmaier, "ETIE"); 
    state->u.f4.fld.dmaier.fbeie = cm_object_get_child_by_name(state->u.f4.reg.dmaier, "FBEIE"); 
    state->u.f4.fld.dmaier.erie = cm_object_get_child_by_name(state->u.f4.reg.dmaier, "ERIE"); 
    state->u.f4.fld.dmaier.aise = cm_object_get_child_by_name(state->u.f4.reg.dmaier, "AISE"); 
    state->u.f4.fld.dmaier.nise = cm_object_get_child_by_name(state->u.f4.reg.dmaier, "NISE");  
    
    // DMAMFBOCR bitfields.
    state->u.f4.fld.dmamfbocr.mfc = cm_object_get_child_by_name(state->u.f4.reg.dmamfbocr, "MFC"); 
    state->u.f4.fld.dmamfbocr.omfc = cm_object_get_child_by_name(state->u.f4.reg.dmamfbocr, "OMFC"); 
    state->u.f4.fld.dmamfbocr.mfa = cm_object_get_child_by_name(state->u.f4.reg.dmamfbocr, "MFA"); 
    state->u.f4.fld.dmamfbocr.ofoc = cm_object_get_child_by_name(state->u.f4.reg.dmamfbocr, "OFOC");  
    
    // DMARSWTR bitfields.
    state->u.f4.fld.dmarswtr.rswtc = cm_object_get_child_by_name(state->u.f4.reg.dmarswtr, "RSWTC");  
    
    // DMACHTDR bitfields.
    state->u.f4.fld.dmachtdr.htdap = cm_object_get_child_by_name(state->u.f4.reg.dmachtdr, "HTDAP");  
    
    // DMACHRDR bitfields.
    state->u.f4.fld.dmachrdr.hrdap = cm_object_get_child_by_name(state->u.f4.reg.dmachrdr, "HRDAP");  
    
    // DMACHTBAR bitfields.
    state->u.f4.fld.dmachtbar.htbap = cm_object_get_child_by_name(state->u.f4.reg.dmachtbar, "HTBAP");  
    
    // DMACHRBAR bitfields.
    state->u.f4.fld.dmachrbar.hrbap = cm_object_get_child_by_name(state->u.f4.reg.dmachrbar, "HRBAP");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_ethernet_dma_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32Ethernet_DMAState *state = STM32_Ethernet_DMA_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_ethernet_dma_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32Ethernet_DMAState *state = STM32_Ethernet_DMA_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_ethernet_dma_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32Ethernet_DMAState *state = STM32_Ethernet_DMA_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_ethernet_dma_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32Ethernet_DMAState *state = STM32_Ethernet_DMA_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_ethernet_dma_is_enabled(Object *obj)
{
    STM32Ethernet_DMAState *state = STM32_Ethernet_DMA_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_ethernet_dma_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32Ethernet_DMAState *state = STM32_Ethernet_DMA_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_ethernet_dma_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_Ethernet_DMA)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32Ethernet_DMAState *state = STM32_Ethernet_DMA_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "Ethernet_DMA";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_429x ) {

            stm32f429x_ethernet_dma_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_ethernet_dma_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_ethernet_dma_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_ethernet_dma_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_ethernet_dma_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/Ethernet_DMAEN");


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

static void stm32_ethernet_dma_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_Ethernet_DMA);
}

static void stm32_ethernet_dma_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_ethernet_dma_reset_callback;
    dc->realize = stm32_ethernet_dma_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_ethernet_dma_is_enabled;
}

static const TypeInfo stm32_ethernet_dma_type_info = {
    .name = TYPE_STM32_Ethernet_DMA,
    .parent = TYPE_STM32_Ethernet_DMA_PARENT,
    .instance_init = stm32_ethernet_dma_instance_init_callback,
    .instance_size = sizeof(STM32Ethernet_DMAState),
    .class_init = stm32_ethernet_dma_class_init_callback,
    .class_size = sizeof(STM32Ethernet_DMAClass) };

static void stm32_ethernet_dma_register_types(void)
{
    type_register_static(&stm32_ethernet_dma_type_info);
}

type_init(stm32_ethernet_dma_register_types);

// ----------------------------------------------------------------------------
