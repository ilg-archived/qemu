/*
 * STM32- RTC(Real-time clock) emulation.
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

#include <hw/cortexm/stm32/rtc.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f0x2_rtc_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32RTCState *state = STM32_RTC_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
state->u.f0.reg.tr= cm_object_get_child_by_name(obj, "TR");
state->u.f0.reg.dr= cm_object_get_child_by_name(obj, "DR");
state->u.f0.reg.cr= cm_object_get_child_by_name(obj, "CR");
state->u.f0.reg.isr= cm_object_get_child_by_name(obj, "ISR");
state->u.f0.reg.prer= cm_object_get_child_by_name(obj, "PRER");
state->u.f0.reg.alrmar= cm_object_get_child_by_name(obj, "ALRMAR");
state->u.f0.reg.wpr= cm_object_get_child_by_name(obj, "WPR");
state->u.f0.reg.ssr= cm_object_get_child_by_name(obj, "SSR");
state->u.f0.reg.shiftr= cm_object_get_child_by_name(obj, "SHIFTR");
state->u.f0.reg.tstr= cm_object_get_child_by_name(obj, "TSTR");
state->u.f0.reg.tsdr= cm_object_get_child_by_name(obj, "TSDR");
state->u.f0.reg.tsssr= cm_object_get_child_by_name(obj, "TSSSR");
state->u.f0.reg.calr= cm_object_get_child_by_name(obj, "CALR");
state->u.f0.reg.tafcr= cm_object_get_child_by_name(obj, "TAFCR");
state->u.f0.reg.alrmassr= cm_object_get_child_by_name(obj, "ALRMASSR");
state->u.f0.reg.bkp0r= cm_object_get_child_by_name(obj, "BKP0R");
state->u.f0.reg.bkp1r= cm_object_get_child_by_name(obj, "BKP1R");
state->u.f0.reg.bkp2r= cm_object_get_child_by_name(obj, "BKP2R");
state->u.f0.reg.bkp3r= cm_object_get_child_by_name(obj, "BKP3R");
state->u.f0.reg.bkp4r= cm_object_get_child_by_name(obj, "BKP4R");
// TRbitfields.
state->u.f0.fld.tr.su= cm_object_get_child_by_name(state->u.f0.reg.tr, "SU"); 
state->u.f0.fld.tr.st= cm_object_get_child_by_name(state->u.f0.reg.tr, "ST"); 
state->u.f0.fld.tr.mnu= cm_object_get_child_by_name(state->u.f0.reg.tr, "MNU"); 
state->u.f0.fld.tr.mnt= cm_object_get_child_by_name(state->u.f0.reg.tr, "MNT"); 
state->u.f0.fld.tr.hu= cm_object_get_child_by_name(state->u.f0.reg.tr, "HU"); 
state->u.f0.fld.tr.ht= cm_object_get_child_by_name(state->u.f0.reg.tr, "HT"); 
state->u.f0.fld.tr.pm= cm_object_get_child_by_name(state->u.f0.reg.tr, "PM"); 
// DRbitfields.
state->u.f0.fld.dr.du= cm_object_get_child_by_name(state->u.f0.reg.dr, "DU"); 
state->u.f0.fld.dr.dt= cm_object_get_child_by_name(state->u.f0.reg.dr, "DT"); 
state->u.f0.fld.dr.mu= cm_object_get_child_by_name(state->u.f0.reg.dr, "MU"); 
state->u.f0.fld.dr.mt= cm_object_get_child_by_name(state->u.f0.reg.dr, "MT"); 
state->u.f0.fld.dr.wdu= cm_object_get_child_by_name(state->u.f0.reg.dr, "WDU"); 
state->u.f0.fld.dr.yu= cm_object_get_child_by_name(state->u.f0.reg.dr, "YU"); 
state->u.f0.fld.dr.yt= cm_object_get_child_by_name(state->u.f0.reg.dr, "YT"); 
// CRbitfields.
state->u.f0.fld.cr.tsedge= cm_object_get_child_by_name(state->u.f0.reg.cr, "TSEDGE"); 
state->u.f0.fld.cr.refckon= cm_object_get_child_by_name(state->u.f0.reg.cr, "REFCKON"); 
state->u.f0.fld.cr.bypshad= cm_object_get_child_by_name(state->u.f0.reg.cr, "BYPSHAD"); 
state->u.f0.fld.cr.fmt= cm_object_get_child_by_name(state->u.f0.reg.cr, "FMT"); 
state->u.f0.fld.cr.alrae= cm_object_get_child_by_name(state->u.f0.reg.cr, "ALRAE"); 
state->u.f0.fld.cr.tse= cm_object_get_child_by_name(state->u.f0.reg.cr, "TSE"); 
state->u.f0.fld.cr.alraie= cm_object_get_child_by_name(state->u.f0.reg.cr, "ALRAIE"); 
state->u.f0.fld.cr.tsie= cm_object_get_child_by_name(state->u.f0.reg.cr, "TSIE"); 
state->u.f0.fld.cr.add1h= cm_object_get_child_by_name(state->u.f0.reg.cr, "ADD1H"); 
state->u.f0.fld.cr.sub1h= cm_object_get_child_by_name(state->u.f0.reg.cr, "SUB1H"); 
state->u.f0.fld.cr.bkp= cm_object_get_child_by_name(state->u.f0.reg.cr, "BKP"); 
state->u.f0.fld.cr.cosel= cm_object_get_child_by_name(state->u.f0.reg.cr, "COSEL"); 
state->u.f0.fld.cr.pol= cm_object_get_child_by_name(state->u.f0.reg.cr, "POL"); 
state->u.f0.fld.cr.osel= cm_object_get_child_by_name(state->u.f0.reg.cr, "OSEL"); 
state->u.f0.fld.cr.coe= cm_object_get_child_by_name(state->u.f0.reg.cr, "COE"); 
// ISRbitfields.
state->u.f0.fld.isr.alrawf= cm_object_get_child_by_name(state->u.f0.reg.isr, "ALRAWF"); 
state->u.f0.fld.isr.shpf= cm_object_get_child_by_name(state->u.f0.reg.isr, "SHPF"); 
state->u.f0.fld.isr.inits= cm_object_get_child_by_name(state->u.f0.reg.isr, "INITS"); 
state->u.f0.fld.isr.rsf= cm_object_get_child_by_name(state->u.f0.reg.isr, "RSF"); 
state->u.f0.fld.isr.initf= cm_object_get_child_by_name(state->u.f0.reg.isr, "INITF"); 
state->u.f0.fld.isr.init= cm_object_get_child_by_name(state->u.f0.reg.isr, "INIT"); 
state->u.f0.fld.isr.alraf= cm_object_get_child_by_name(state->u.f0.reg.isr, "ALRAF"); 
state->u.f0.fld.isr.tsf= cm_object_get_child_by_name(state->u.f0.reg.isr, "TSF"); 
state->u.f0.fld.isr.tsovf= cm_object_get_child_by_name(state->u.f0.reg.isr, "TSOVF"); 
state->u.f0.fld.isr.tamp1f= cm_object_get_child_by_name(state->u.f0.reg.isr, "TAMP1F"); 
state->u.f0.fld.isr.tamp2f= cm_object_get_child_by_name(state->u.f0.reg.isr, "TAMP2F"); 
state->u.f0.fld.isr.recalpf= cm_object_get_child_by_name(state->u.f0.reg.isr, "RECALPF"); 
// PRERbitfields.
state->u.f0.fld.prer.prediv_s= cm_object_get_child_by_name(state->u.f0.reg.prer, "PREDIV_S"); 
state->u.f0.fld.prer.prediv_a= cm_object_get_child_by_name(state->u.f0.reg.prer, "PREDIV_A"); 
// ALRMARbitfields.
state->u.f0.fld.alrmar.su= cm_object_get_child_by_name(state->u.f0.reg.alrmar, "SU"); 
state->u.f0.fld.alrmar.st= cm_object_get_child_by_name(state->u.f0.reg.alrmar, "ST"); 
state->u.f0.fld.alrmar.msk1= cm_object_get_child_by_name(state->u.f0.reg.alrmar, "MSK1"); 
state->u.f0.fld.alrmar.mnu= cm_object_get_child_by_name(state->u.f0.reg.alrmar, "MNU"); 
state->u.f0.fld.alrmar.mnt= cm_object_get_child_by_name(state->u.f0.reg.alrmar, "MNT"); 
state->u.f0.fld.alrmar.msk2= cm_object_get_child_by_name(state->u.f0.reg.alrmar, "MSK2"); 
state->u.f0.fld.alrmar.hu= cm_object_get_child_by_name(state->u.f0.reg.alrmar, "HU"); 
state->u.f0.fld.alrmar.ht= cm_object_get_child_by_name(state->u.f0.reg.alrmar, "HT"); 
state->u.f0.fld.alrmar.pm= cm_object_get_child_by_name(state->u.f0.reg.alrmar, "PM"); 
state->u.f0.fld.alrmar.msk3= cm_object_get_child_by_name(state->u.f0.reg.alrmar, "MSK3"); 
state->u.f0.fld.alrmar.du= cm_object_get_child_by_name(state->u.f0.reg.alrmar, "DU"); 
state->u.f0.fld.alrmar.dt= cm_object_get_child_by_name(state->u.f0.reg.alrmar, "DT"); 
state->u.f0.fld.alrmar.wdsel= cm_object_get_child_by_name(state->u.f0.reg.alrmar, "WDSEL"); 
state->u.f0.fld.alrmar.msk4= cm_object_get_child_by_name(state->u.f0.reg.alrmar, "MSK4"); 
// WPRbitfields.
state->u.f0.fld.wpr.key= cm_object_get_child_by_name(state->u.f0.reg.wpr, "KEY"); 
// SSRbitfields.
state->u.f0.fld.ssr.ss= cm_object_get_child_by_name(state->u.f0.reg.ssr, "SS"); 
// SHIFTRbitfields.
state->u.f0.fld.shiftr.subfs= cm_object_get_child_by_name(state->u.f0.reg.shiftr, "SUBFS"); 
state->u.f0.fld.shiftr.add1s= cm_object_get_child_by_name(state->u.f0.reg.shiftr, "ADD1S"); 
// TSTRbitfields.
state->u.f0.fld.tstr.su= cm_object_get_child_by_name(state->u.f0.reg.tstr, "SU"); 
state->u.f0.fld.tstr.st= cm_object_get_child_by_name(state->u.f0.reg.tstr, "ST"); 
state->u.f0.fld.tstr.mnu= cm_object_get_child_by_name(state->u.f0.reg.tstr, "MNU"); 
state->u.f0.fld.tstr.mnt= cm_object_get_child_by_name(state->u.f0.reg.tstr, "MNT"); 
state->u.f0.fld.tstr.hu= cm_object_get_child_by_name(state->u.f0.reg.tstr, "HU"); 
state->u.f0.fld.tstr.ht= cm_object_get_child_by_name(state->u.f0.reg.tstr, "HT"); 
state->u.f0.fld.tstr.pm= cm_object_get_child_by_name(state->u.f0.reg.tstr, "PM"); 
// TSDRbitfields.
state->u.f0.fld.tsdr.du= cm_object_get_child_by_name(state->u.f0.reg.tsdr, "DU"); 
state->u.f0.fld.tsdr.dt= cm_object_get_child_by_name(state->u.f0.reg.tsdr, "DT"); 
state->u.f0.fld.tsdr.mu= cm_object_get_child_by_name(state->u.f0.reg.tsdr, "MU"); 
state->u.f0.fld.tsdr.mt= cm_object_get_child_by_name(state->u.f0.reg.tsdr, "MT"); 
state->u.f0.fld.tsdr.wdu= cm_object_get_child_by_name(state->u.f0.reg.tsdr, "WDU"); 
// TSSSRbitfields.
state->u.f0.fld.tsssr.ss= cm_object_get_child_by_name(state->u.f0.reg.tsssr, "SS"); 
// CALRbitfields.
state->u.f0.fld.calr.calm= cm_object_get_child_by_name(state->u.f0.reg.calr, "CALM"); 
state->u.f0.fld.calr.calw16= cm_object_get_child_by_name(state->u.f0.reg.calr, "CALW16"); 
state->u.f0.fld.calr.calw8= cm_object_get_child_by_name(state->u.f0.reg.calr, "CALW8"); 
state->u.f0.fld.calr.calp= cm_object_get_child_by_name(state->u.f0.reg.calr, "CALP"); 
// TAFCRbitfields.
state->u.f0.fld.tafcr.tamp1e= cm_object_get_child_by_name(state->u.f0.reg.tafcr, "TAMP1E"); 
state->u.f0.fld.tafcr.tamp1trg= cm_object_get_child_by_name(state->u.f0.reg.tafcr, "TAMP1TRG"); 
state->u.f0.fld.tafcr.tampie= cm_object_get_child_by_name(state->u.f0.reg.tafcr, "TAMPIE"); 
state->u.f0.fld.tafcr.tamp2e= cm_object_get_child_by_name(state->u.f0.reg.tafcr, "TAMP2E"); 
state->u.f0.fld.tafcr.tamp2_trg= cm_object_get_child_by_name(state->u.f0.reg.tafcr, "TAMP2_TRG"); 
state->u.f0.fld.tafcr.tampts= cm_object_get_child_by_name(state->u.f0.reg.tafcr, "TAMPTS"); 
state->u.f0.fld.tafcr.tampfreq= cm_object_get_child_by_name(state->u.f0.reg.tafcr, "TAMPFREQ"); 
state->u.f0.fld.tafcr.tampflt= cm_object_get_child_by_name(state->u.f0.reg.tafcr, "TAMPFLT"); 
state->u.f0.fld.tafcr.tamp_prch= cm_object_get_child_by_name(state->u.f0.reg.tafcr, "TAMP_PRCH"); 
state->u.f0.fld.tafcr.tamp_pudis= cm_object_get_child_by_name(state->u.f0.reg.tafcr, "TAMP_PUDIS"); 
state->u.f0.fld.tafcr.pc13value= cm_object_get_child_by_name(state->u.f0.reg.tafcr, "PC13VALUE"); 
state->u.f0.fld.tafcr.pc13mode= cm_object_get_child_by_name(state->u.f0.reg.tafcr, "PC13MODE"); 
state->u.f0.fld.tafcr.pc14value= cm_object_get_child_by_name(state->u.f0.reg.tafcr, "PC14VALUE"); 
state->u.f0.fld.tafcr.pc14mode= cm_object_get_child_by_name(state->u.f0.reg.tafcr, "PC14MODE"); 
state->u.f0.fld.tafcr.pc15value= cm_object_get_child_by_name(state->u.f0.reg.tafcr, "PC15VALUE"); 
state->u.f0.fld.tafcr.pc15mode= cm_object_get_child_by_name(state->u.f0.reg.tafcr, "PC15MODE"); 
// ALRMASSRbitfields.
state->u.f0.fld.alrmassr.ss= cm_object_get_child_by_name(state->u.f0.reg.alrmassr, "SS"); 
state->u.f0.fld.alrmassr.maskss= cm_object_get_child_by_name(state->u.f0.reg.alrmassr, "MASKSS"); 
// BKP0Rbitfields.
state->u.f0.fld.bkp0r.bkp= cm_object_get_child_by_name(state->u.f0.reg.bkp0r, "BKP"); 
// BKP1Rbitfields.
state->u.f0.fld.bkp1r.bkp= cm_object_get_child_by_name(state->u.f0.reg.bkp1r, "BKP"); 
// BKP2Rbitfields.
state->u.f0.fld.bkp2r.bkp= cm_object_get_child_by_name(state->u.f0.reg.bkp2r, "BKP"); 
// BKP3Rbitfields.
state->u.f0.fld.bkp3r.bkp= cm_object_get_child_by_name(state->u.f0.reg.bkp3r, "BKP"); 
// BKP4Rbitfields.
state->u.f0.fld.bkp4r.bkp= cm_object_get_child_by_name(state->u.f0.reg.bkp4r, "BKP"); 
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_rtc_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32RTCState *state = STM32_RTC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_rtc_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32RTCState *state = STM32_RTC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_rtc_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32RTCState *state = STM32_RTC_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_rtc_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32RTCState *state = STM32_RTC_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_rtc_is_enabled(Object *obj)
{
    STM32RTCState *state = STM32_RTC_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_rtc_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32RTCState *state = STM32_RTC_STATE(obj);

    // Capabilities are not yet available.

// TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_rtc_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_RTC)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32RTCState *state = STM32_RTC_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "RTC";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x2) {

            stm32f0x2_rtc_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f0.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_rtc_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f0.reg.xxx, &stm32_rtc_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f0.reg.xxx, &stm32_rtc_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f0.reg.xxx, &stm32_rtc_xxx_post_write_callback);

            // TODO: add interrupts.

// TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/RTCEN");
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

static void stm32_rtc_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_RTC);
}

static void stm32_rtc_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_rtc_reset_callback;
    dc->realize = stm32_rtc_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_rtc_is_enabled;
}

static const TypeInfo stm32_rtc_type_info = {
    .name = TYPE_STM32_RTC,
    .parent = TYPE_STM32_RTC_PARENT,
    .instance_init = stm32_rtc_instance_init_callback,
    .instance_size = sizeof(STM32RTCState),
    .class_init = stm32_rtc_class_init_callback,
    .class_size = sizeof(STM32RTCClass) };

static void stm32_rtc_register_types(void)
{
    type_register_static(&stm32_rtc_type_info);
}

type_init(stm32_rtc_register_types);

// ----------------------------------------------------------------------------
