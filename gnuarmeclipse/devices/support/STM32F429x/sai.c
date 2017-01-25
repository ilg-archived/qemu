/*
 * STM32 - SAI (Serial audio interface) emulation.
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

#include <hw/cortexm/stm32/sai.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f429x_sai_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32SAIState *state = STM32_SAI_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.bcr1 = cm_object_get_child_by_name(obj, "BCR1");
    state->u.f4.reg.bcr2 = cm_object_get_child_by_name(obj, "BCR2");
    state->u.f4.reg.bfrcr = cm_object_get_child_by_name(obj, "BFRCR");
    state->u.f4.reg.bslotr = cm_object_get_child_by_name(obj, "BSLOTR");
    state->u.f4.reg.bim = cm_object_get_child_by_name(obj, "BIM");
    state->u.f4.reg.bsr = cm_object_get_child_by_name(obj, "BSR");
    state->u.f4.reg.bclrfr = cm_object_get_child_by_name(obj, "BCLRFR");
    state->u.f4.reg.bdr = cm_object_get_child_by_name(obj, "BDR");
    state->u.f4.reg.acr1 = cm_object_get_child_by_name(obj, "ACR1");
    state->u.f4.reg.acr2 = cm_object_get_child_by_name(obj, "ACR2");
    state->u.f4.reg.afrcr = cm_object_get_child_by_name(obj, "AFRCR");
    state->u.f4.reg.aslotr = cm_object_get_child_by_name(obj, "ASLOTR");
    state->u.f4.reg.aim = cm_object_get_child_by_name(obj, "AIM");
    state->u.f4.reg.asr = cm_object_get_child_by_name(obj, "ASR");
    state->u.f4.reg.aclrfr = cm_object_get_child_by_name(obj, "ACLRFR");
    state->u.f4.reg.adr = cm_object_get_child_by_name(obj, "ADR");
    
    
    // BCR1 bitfields.
    state->u.f4.fld.bcr1.mode = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "MODE"); 
    state->u.f4.fld.bcr1.prtcfg = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "PRTCFG"); 
    state->u.f4.fld.bcr1.ds = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "DS"); 
    state->u.f4.fld.bcr1.lsbfirst = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "LSBFIRST"); 
    state->u.f4.fld.bcr1.ckstr = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "CKSTR"); 
    state->u.f4.fld.bcr1.syncen = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "SYNCEN"); 
    state->u.f4.fld.bcr1.mono = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "MONO"); 
    state->u.f4.fld.bcr1.outdri = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "OutDri"); 
    state->u.f4.fld.bcr1.saiben = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "SAIBEN"); 
    state->u.f4.fld.bcr1.dmaen = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "DMAEN"); 
    state->u.f4.fld.bcr1.nodiv = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "NODIV"); 
    state->u.f4.fld.bcr1.mcjdiv = cm_object_get_child_by_name(state->u.f4.reg.bcr1, "MCJDIV");  
    
    // BCR2 bitfields.
    state->u.f4.fld.bcr2.fth = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "FTH"); 
    state->u.f4.fld.bcr2.fflus = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "FFLUS"); 
    state->u.f4.fld.bcr2.tris = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "TRIS"); 
    state->u.f4.fld.bcr2.mute = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "MUTE"); 
    state->u.f4.fld.bcr2.muteval = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "MUTEVAL"); 
    state->u.f4.fld.bcr2.mutecn = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "MUTECN"); 
    state->u.f4.fld.bcr2.cpl = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "CPL"); 
    state->u.f4.fld.bcr2.comp = cm_object_get_child_by_name(state->u.f4.reg.bcr2, "COMP");  
    
    // BFRCR bitfields.
    state->u.f4.fld.bfrcr.frl = cm_object_get_child_by_name(state->u.f4.reg.bfrcr, "FRL"); 
    state->u.f4.fld.bfrcr.fsall = cm_object_get_child_by_name(state->u.f4.reg.bfrcr, "FSALL"); 
    state->u.f4.fld.bfrcr.fsdef = cm_object_get_child_by_name(state->u.f4.reg.bfrcr, "FSDEF"); 
    state->u.f4.fld.bfrcr.fspol = cm_object_get_child_by_name(state->u.f4.reg.bfrcr, "FSPOL"); 
    state->u.f4.fld.bfrcr.fsoff = cm_object_get_child_by_name(state->u.f4.reg.bfrcr, "FSOFF");  
    
    // BSLOTR bitfields.
    state->u.f4.fld.bslotr.fboff = cm_object_get_child_by_name(state->u.f4.reg.bslotr, "FBOFF"); 
    state->u.f4.fld.bslotr.slotsz = cm_object_get_child_by_name(state->u.f4.reg.bslotr, "SLOTSZ"); 
    state->u.f4.fld.bslotr.nbslot = cm_object_get_child_by_name(state->u.f4.reg.bslotr, "NBSLOT"); 
    state->u.f4.fld.bslotr.sloten = cm_object_get_child_by_name(state->u.f4.reg.bslotr, "SLOTEN");  
    
    // BIM bitfields.
    state->u.f4.fld.bim.ovrudrie = cm_object_get_child_by_name(state->u.f4.reg.bim, "OVRUDRIE"); 
    state->u.f4.fld.bim.mutedet = cm_object_get_child_by_name(state->u.f4.reg.bim, "MUTEDET"); 
    state->u.f4.fld.bim.wckcfg = cm_object_get_child_by_name(state->u.f4.reg.bim, "WCKCFG"); 
    state->u.f4.fld.bim.freqie = cm_object_get_child_by_name(state->u.f4.reg.bim, "FREQIE"); 
    state->u.f4.fld.bim.cnrdyie = cm_object_get_child_by_name(state->u.f4.reg.bim, "CNRDYIE"); 
    state->u.f4.fld.bim.afsdetie = cm_object_get_child_by_name(state->u.f4.reg.bim, "AFSDETIE"); 
    state->u.f4.fld.bim.lfsdetie = cm_object_get_child_by_name(state->u.f4.reg.bim, "LFSDETIE");  
    
    // BSR bitfields.
    state->u.f4.fld.bsr.ovrudr = cm_object_get_child_by_name(state->u.f4.reg.bsr, "OVRUDR"); 
    state->u.f4.fld.bsr.mutedet = cm_object_get_child_by_name(state->u.f4.reg.bsr, "MUTEDET"); 
    state->u.f4.fld.bsr.wckcfg = cm_object_get_child_by_name(state->u.f4.reg.bsr, "WCKCFG"); 
    state->u.f4.fld.bsr.freq = cm_object_get_child_by_name(state->u.f4.reg.bsr, "FREQ"); 
    state->u.f4.fld.bsr.cnrdy = cm_object_get_child_by_name(state->u.f4.reg.bsr, "CNRDY"); 
    state->u.f4.fld.bsr.afsdet = cm_object_get_child_by_name(state->u.f4.reg.bsr, "AFSDET"); 
    state->u.f4.fld.bsr.lfsdet = cm_object_get_child_by_name(state->u.f4.reg.bsr, "LFSDET"); 
    state->u.f4.fld.bsr.flvl = cm_object_get_child_by_name(state->u.f4.reg.bsr, "FLVL");  
    
    // BCLRFR bitfields.
    state->u.f4.fld.bclrfr.ovrudr = cm_object_get_child_by_name(state->u.f4.reg.bclrfr, "OVRUDR"); 
    state->u.f4.fld.bclrfr.mutedet = cm_object_get_child_by_name(state->u.f4.reg.bclrfr, "MUTEDET"); 
    state->u.f4.fld.bclrfr.wckcfg = cm_object_get_child_by_name(state->u.f4.reg.bclrfr, "WCKCFG"); 
    state->u.f4.fld.bclrfr.cnrdy = cm_object_get_child_by_name(state->u.f4.reg.bclrfr, "CNRDY"); 
    state->u.f4.fld.bclrfr.cafsdet = cm_object_get_child_by_name(state->u.f4.reg.bclrfr, "CAFSDET"); 
    state->u.f4.fld.bclrfr.lfsdet = cm_object_get_child_by_name(state->u.f4.reg.bclrfr, "LFSDET");  
    
    // BDR bitfields.
    state->u.f4.fld.bdr.data = cm_object_get_child_by_name(state->u.f4.reg.bdr, "DATA");  
    
    // ACR1 bitfields.
    state->u.f4.fld.acr1.mode = cm_object_get_child_by_name(state->u.f4.reg.acr1, "MODE"); 
    state->u.f4.fld.acr1.prtcfg = cm_object_get_child_by_name(state->u.f4.reg.acr1, "PRTCFG"); 
    state->u.f4.fld.acr1.ds = cm_object_get_child_by_name(state->u.f4.reg.acr1, "DS"); 
    state->u.f4.fld.acr1.lsbfirst = cm_object_get_child_by_name(state->u.f4.reg.acr1, "LSBFIRST"); 
    state->u.f4.fld.acr1.ckstr = cm_object_get_child_by_name(state->u.f4.reg.acr1, "CKSTR"); 
    state->u.f4.fld.acr1.syncen = cm_object_get_child_by_name(state->u.f4.reg.acr1, "SYNCEN"); 
    state->u.f4.fld.acr1.mono = cm_object_get_child_by_name(state->u.f4.reg.acr1, "MONO"); 
    state->u.f4.fld.acr1.outdri = cm_object_get_child_by_name(state->u.f4.reg.acr1, "OutDri"); 
    state->u.f4.fld.acr1.saiaen = cm_object_get_child_by_name(state->u.f4.reg.acr1, "SAIAEN"); 
    state->u.f4.fld.acr1.dmaen = cm_object_get_child_by_name(state->u.f4.reg.acr1, "DMAEN"); 
    state->u.f4.fld.acr1.nodiv = cm_object_get_child_by_name(state->u.f4.reg.acr1, "NODIV"); 
    state->u.f4.fld.acr1.mcjdiv = cm_object_get_child_by_name(state->u.f4.reg.acr1, "MCJDIV");  
    
    // ACR2 bitfields.
    state->u.f4.fld.acr2.fth = cm_object_get_child_by_name(state->u.f4.reg.acr2, "FTH"); 
    state->u.f4.fld.acr2.fflus = cm_object_get_child_by_name(state->u.f4.reg.acr2, "FFLUS"); 
    state->u.f4.fld.acr2.tris = cm_object_get_child_by_name(state->u.f4.reg.acr2, "TRIS"); 
    state->u.f4.fld.acr2.mute = cm_object_get_child_by_name(state->u.f4.reg.acr2, "MUTE"); 
    state->u.f4.fld.acr2.muteval = cm_object_get_child_by_name(state->u.f4.reg.acr2, "MUTEVAL"); 
    state->u.f4.fld.acr2.mutecn = cm_object_get_child_by_name(state->u.f4.reg.acr2, "MUTECN"); 
    state->u.f4.fld.acr2.cpl = cm_object_get_child_by_name(state->u.f4.reg.acr2, "CPL"); 
    state->u.f4.fld.acr2.comp = cm_object_get_child_by_name(state->u.f4.reg.acr2, "COMP");  
    
    // AFRCR bitfields.
    state->u.f4.fld.afrcr.frl = cm_object_get_child_by_name(state->u.f4.reg.afrcr, "FRL"); 
    state->u.f4.fld.afrcr.fsall = cm_object_get_child_by_name(state->u.f4.reg.afrcr, "FSALL"); 
    state->u.f4.fld.afrcr.fsdef = cm_object_get_child_by_name(state->u.f4.reg.afrcr, "FSDEF"); 
    state->u.f4.fld.afrcr.fspol = cm_object_get_child_by_name(state->u.f4.reg.afrcr, "FSPOL"); 
    state->u.f4.fld.afrcr.fsoff = cm_object_get_child_by_name(state->u.f4.reg.afrcr, "FSOFF");  
    
    // ASLOTR bitfields.
    state->u.f4.fld.aslotr.fboff = cm_object_get_child_by_name(state->u.f4.reg.aslotr, "FBOFF"); 
    state->u.f4.fld.aslotr.slotsz = cm_object_get_child_by_name(state->u.f4.reg.aslotr, "SLOTSZ"); 
    state->u.f4.fld.aslotr.nbslot = cm_object_get_child_by_name(state->u.f4.reg.aslotr, "NBSLOT"); 
    state->u.f4.fld.aslotr.sloten = cm_object_get_child_by_name(state->u.f4.reg.aslotr, "SLOTEN");  
    
    // AIM bitfields.
    state->u.f4.fld.aim.ovrudrie = cm_object_get_child_by_name(state->u.f4.reg.aim, "OVRUDRIE"); 
    state->u.f4.fld.aim.mutedet = cm_object_get_child_by_name(state->u.f4.reg.aim, "MUTEDET"); 
    state->u.f4.fld.aim.wckcfg = cm_object_get_child_by_name(state->u.f4.reg.aim, "WCKCFG"); 
    state->u.f4.fld.aim.freqie = cm_object_get_child_by_name(state->u.f4.reg.aim, "FREQIE"); 
    state->u.f4.fld.aim.cnrdyie = cm_object_get_child_by_name(state->u.f4.reg.aim, "CNRDYIE"); 
    state->u.f4.fld.aim.afsdetie = cm_object_get_child_by_name(state->u.f4.reg.aim, "AFSDETIE"); 
    state->u.f4.fld.aim.lfsdet = cm_object_get_child_by_name(state->u.f4.reg.aim, "LFSDET");  
    
    // ASR bitfields.
    state->u.f4.fld.asr.ovrudr = cm_object_get_child_by_name(state->u.f4.reg.asr, "OVRUDR"); 
    state->u.f4.fld.asr.mutedet = cm_object_get_child_by_name(state->u.f4.reg.asr, "MUTEDET"); 
    state->u.f4.fld.asr.wckcfg = cm_object_get_child_by_name(state->u.f4.reg.asr, "WCKCFG"); 
    state->u.f4.fld.asr.freq = cm_object_get_child_by_name(state->u.f4.reg.asr, "FREQ"); 
    state->u.f4.fld.asr.cnrdy = cm_object_get_child_by_name(state->u.f4.reg.asr, "CNRDY"); 
    state->u.f4.fld.asr.afsdet = cm_object_get_child_by_name(state->u.f4.reg.asr, "AFSDET"); 
    state->u.f4.fld.asr.lfsdet = cm_object_get_child_by_name(state->u.f4.reg.asr, "LFSDET"); 
    state->u.f4.fld.asr.flvl = cm_object_get_child_by_name(state->u.f4.reg.asr, "FLVL");  
    
    // ACLRFR bitfields.
    state->u.f4.fld.aclrfr.ovrudr = cm_object_get_child_by_name(state->u.f4.reg.aclrfr, "OVRUDR"); 
    state->u.f4.fld.aclrfr.mutedet = cm_object_get_child_by_name(state->u.f4.reg.aclrfr, "MUTEDET"); 
    state->u.f4.fld.aclrfr.wckcfg = cm_object_get_child_by_name(state->u.f4.reg.aclrfr, "WCKCFG"); 
    state->u.f4.fld.aclrfr.cnrdy = cm_object_get_child_by_name(state->u.f4.reg.aclrfr, "CNRDY"); 
    state->u.f4.fld.aclrfr.cafsdet = cm_object_get_child_by_name(state->u.f4.reg.aclrfr, "CAFSDET"); 
    state->u.f4.fld.aclrfr.lfsdet = cm_object_get_child_by_name(state->u.f4.reg.aclrfr, "LFSDET");  
    
    // ADR bitfields.
    state->u.f4.fld.adr.data = cm_object_get_child_by_name(state->u.f4.reg.adr, "DATA");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_sai_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32SAIState *state = STM32_SAI_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_sai_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32SAIState *state = STM32_SAI_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_sai_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32SAIState *state = STM32_SAI_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_sai_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32SAIState *state = STM32_SAI_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_sai_is_enabled(Object *obj)
{
    STM32SAIState *state = STM32_SAI_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_sai_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32SAIState *state = STM32_SAI_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_sai_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_SAI)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32SAIState *state = STM32_SAI_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "SAI";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_429x ) {

            stm32f429x_sai_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_sai_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_sai_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_sai_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_sai_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/SAIEN");


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

static void stm32_sai_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_SAI);
}

static void stm32_sai_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_sai_reset_callback;
    dc->realize = stm32_sai_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_sai_is_enabled;
}

static const TypeInfo stm32_sai_type_info = {
    .name = TYPE_STM32_SAI,
    .parent = TYPE_STM32_SAI_PARENT,
    .instance_init = stm32_sai_instance_init_callback,
    .instance_size = sizeof(STM32SAIState),
    .class_init = stm32_sai_class_init_callback,
    .class_size = sizeof(STM32SAIClass) };

static void stm32_sai_register_types(void)
{
    type_register_static(&stm32_sai_type_info);
}

type_init(stm32_sai_register_types);

// ----------------------------------------------------------------------------
