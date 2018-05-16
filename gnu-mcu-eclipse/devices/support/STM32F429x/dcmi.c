/*
 * STM32 - DCMI (Digital camera interface) emulation.
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

#include <hw/cortexm/stm32/dcmi.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f429x_dcmi_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32DCMIState *state = STM32_DCMI_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->u.f4.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->u.f4.reg.ris = cm_object_get_child_by_name(obj, "RIS");
    state->u.f4.reg.ier = cm_object_get_child_by_name(obj, "IER");
    state->u.f4.reg.mis = cm_object_get_child_by_name(obj, "MIS");
    state->u.f4.reg.icr = cm_object_get_child_by_name(obj, "ICR");
    state->u.f4.reg.escr = cm_object_get_child_by_name(obj, "ESCR");
    state->u.f4.reg.esur = cm_object_get_child_by_name(obj, "ESUR");
    state->u.f4.reg.cwstrt = cm_object_get_child_by_name(obj, "CWSTRT");
    state->u.f4.reg.cwsize = cm_object_get_child_by_name(obj, "CWSIZE");
    state->u.f4.reg.dr = cm_object_get_child_by_name(obj, "DR");
    
    
    // CR bitfields.
    state->u.f4.fld.cr.capture = cm_object_get_child_by_name(state->u.f4.reg.cr, "CAPTURE"); 
    state->u.f4.fld.cr.cm = cm_object_get_child_by_name(state->u.f4.reg.cr, "CM"); 
    state->u.f4.fld.cr.crop = cm_object_get_child_by_name(state->u.f4.reg.cr, "CROP"); 
    state->u.f4.fld.cr.jpeg = cm_object_get_child_by_name(state->u.f4.reg.cr, "JPEG"); 
    state->u.f4.fld.cr.ess = cm_object_get_child_by_name(state->u.f4.reg.cr, "ESS"); 
    state->u.f4.fld.cr.pckpol = cm_object_get_child_by_name(state->u.f4.reg.cr, "PCKPOL"); 
    state->u.f4.fld.cr.hspol = cm_object_get_child_by_name(state->u.f4.reg.cr, "HSPOL"); 
    state->u.f4.fld.cr.vspol = cm_object_get_child_by_name(state->u.f4.reg.cr, "VSPOL"); 
    state->u.f4.fld.cr.fcrc = cm_object_get_child_by_name(state->u.f4.reg.cr, "FCRC"); 
    state->u.f4.fld.cr.edm = cm_object_get_child_by_name(state->u.f4.reg.cr, "EDM"); 
    state->u.f4.fld.cr.enable = cm_object_get_child_by_name(state->u.f4.reg.cr, "ENABLE");  
    
    // SR bitfields.
    state->u.f4.fld.sr.hsync = cm_object_get_child_by_name(state->u.f4.reg.sr, "HSYNC"); 
    state->u.f4.fld.sr.vsync = cm_object_get_child_by_name(state->u.f4.reg.sr, "VSYNC"); 
    state->u.f4.fld.sr.fne = cm_object_get_child_by_name(state->u.f4.reg.sr, "FNE");  
    
    // RIS bitfields.
    state->u.f4.fld.ris.frame_ris = cm_object_get_child_by_name(state->u.f4.reg.ris, "FRAME_RIS"); 
    state->u.f4.fld.ris.ovr_ris = cm_object_get_child_by_name(state->u.f4.reg.ris, "OVR_RIS"); 
    state->u.f4.fld.ris.err_ris = cm_object_get_child_by_name(state->u.f4.reg.ris, "ERR_RIS"); 
    state->u.f4.fld.ris.vsync_ris = cm_object_get_child_by_name(state->u.f4.reg.ris, "VSYNC_RIS"); 
    state->u.f4.fld.ris.line_ris = cm_object_get_child_by_name(state->u.f4.reg.ris, "LINE_RIS");  
    
    // IER bitfields.
    state->u.f4.fld.ier.frame_ie = cm_object_get_child_by_name(state->u.f4.reg.ier, "FRAME_IE"); 
    state->u.f4.fld.ier.ovr_ie = cm_object_get_child_by_name(state->u.f4.reg.ier, "OVR_IE"); 
    state->u.f4.fld.ier.err_ie = cm_object_get_child_by_name(state->u.f4.reg.ier, "ERR_IE"); 
    state->u.f4.fld.ier.vsync_ie = cm_object_get_child_by_name(state->u.f4.reg.ier, "VSYNC_IE"); 
    state->u.f4.fld.ier.line_ie = cm_object_get_child_by_name(state->u.f4.reg.ier, "LINE_IE");  
    
    // MIS bitfields.
    state->u.f4.fld.mis.frame_mis = cm_object_get_child_by_name(state->u.f4.reg.mis, "FRAME_MIS"); 
    state->u.f4.fld.mis.ovr_mis = cm_object_get_child_by_name(state->u.f4.reg.mis, "OVR_MIS"); 
    state->u.f4.fld.mis.err_mis = cm_object_get_child_by_name(state->u.f4.reg.mis, "ERR_MIS"); 
    state->u.f4.fld.mis.vsync_mis = cm_object_get_child_by_name(state->u.f4.reg.mis, "VSYNC_MIS"); 
    state->u.f4.fld.mis.line_mis = cm_object_get_child_by_name(state->u.f4.reg.mis, "LINE_MIS");  
    
    // ICR bitfields.
    state->u.f4.fld.icr.frame_isc = cm_object_get_child_by_name(state->u.f4.reg.icr, "FRAME_ISC"); 
    state->u.f4.fld.icr.ovr_isc = cm_object_get_child_by_name(state->u.f4.reg.icr, "OVR_ISC"); 
    state->u.f4.fld.icr.err_isc = cm_object_get_child_by_name(state->u.f4.reg.icr, "ERR_ISC"); 
    state->u.f4.fld.icr.vsync_isc = cm_object_get_child_by_name(state->u.f4.reg.icr, "VSYNC_ISC"); 
    state->u.f4.fld.icr.line_isc = cm_object_get_child_by_name(state->u.f4.reg.icr, "LINE_ISC");  
    
    // ESCR bitfields.
    state->u.f4.fld.escr.fsc = cm_object_get_child_by_name(state->u.f4.reg.escr, "FSC"); 
    state->u.f4.fld.escr.lsc = cm_object_get_child_by_name(state->u.f4.reg.escr, "LSC"); 
    state->u.f4.fld.escr.lec = cm_object_get_child_by_name(state->u.f4.reg.escr, "LEC"); 
    state->u.f4.fld.escr.fec = cm_object_get_child_by_name(state->u.f4.reg.escr, "FEC");  
    
    // ESUR bitfields.
    state->u.f4.fld.esur.fsu = cm_object_get_child_by_name(state->u.f4.reg.esur, "FSU"); 
    state->u.f4.fld.esur.lsu = cm_object_get_child_by_name(state->u.f4.reg.esur, "LSU"); 
    state->u.f4.fld.esur.leu = cm_object_get_child_by_name(state->u.f4.reg.esur, "LEU"); 
    state->u.f4.fld.esur.feu = cm_object_get_child_by_name(state->u.f4.reg.esur, "FEU");  
    
    // CWSTRT bitfields.
    state->u.f4.fld.cwstrt.hoffcnt = cm_object_get_child_by_name(state->u.f4.reg.cwstrt, "HOFFCNT"); 
    state->u.f4.fld.cwstrt.vst = cm_object_get_child_by_name(state->u.f4.reg.cwstrt, "VST");  
    
    // CWSIZE bitfields.
    state->u.f4.fld.cwsize.capcnt = cm_object_get_child_by_name(state->u.f4.reg.cwsize, "CAPCNT"); 
    state->u.f4.fld.cwsize.vline = cm_object_get_child_by_name(state->u.f4.reg.cwsize, "VLINE");  
    
    // DR bitfields.
    state->u.f4.fld.dr.byte0 = cm_object_get_child_by_name(state->u.f4.reg.dr, "Byte0"); 
    state->u.f4.fld.dr.byte1 = cm_object_get_child_by_name(state->u.f4.reg.dr, "Byte1"); 
    state->u.f4.fld.dr.byte2 = cm_object_get_child_by_name(state->u.f4.reg.dr, "Byte2"); 
    state->u.f4.fld.dr.byte3 = cm_object_get_child_by_name(state->u.f4.reg.dr, "Byte3");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_dcmi_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32DCMIState *state = STM32_DCMI_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_dcmi_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32DCMIState *state = STM32_DCMI_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_dcmi_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32DCMIState *state = STM32_DCMI_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_dcmi_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32DCMIState *state = STM32_DCMI_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_dcmi_is_enabled(Object *obj)
{
    STM32DCMIState *state = STM32_DCMI_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_dcmi_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32DCMIState *state = STM32_DCMI_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_dcmi_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_DCMI)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32DCMIState *state = STM32_DCMI_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "DCMI";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_429x ) {

            stm32f429x_dcmi_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_dcmi_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_dcmi_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_dcmi_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_dcmi_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/DCMIEN");


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

static void stm32_dcmi_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_DCMI);
}

static void stm32_dcmi_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_dcmi_reset_callback;
    dc->realize = stm32_dcmi_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_dcmi_is_enabled;
}

static const TypeInfo stm32_dcmi_type_info = {
    .name = TYPE_STM32_DCMI,
    .parent = TYPE_STM32_DCMI_PARENT,
    .instance_init = stm32_dcmi_instance_init_callback,
    .instance_size = sizeof(STM32DCMIState),
    .class_init = stm32_dcmi_class_init_callback,
    .class_size = sizeof(STM32DCMIClass) };

static void stm32_dcmi_register_types(void)
{
    type_register_static(&stm32_dcmi_type_info);
}

type_init(stm32_dcmi_register_types);

// ----------------------------------------------------------------------------
