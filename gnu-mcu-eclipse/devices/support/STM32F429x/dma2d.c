/*
 * STM32 - DMA2D (DMA2D controller) emulation.
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

#include <hw/cortexm/stm32/dma2d.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f429x_dma2d_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32DMA2DState *state = STM32_DMA2D_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->u.f4.reg.isr = cm_object_get_child_by_name(obj, "ISR");
    state->u.f4.reg.ifcr = cm_object_get_child_by_name(obj, "IFCR");
    state->u.f4.reg.fgmar = cm_object_get_child_by_name(obj, "FGMAR");
    state->u.f4.reg.fgor = cm_object_get_child_by_name(obj, "FGOR");
    state->u.f4.reg.bgmar = cm_object_get_child_by_name(obj, "BGMAR");
    state->u.f4.reg.bgor = cm_object_get_child_by_name(obj, "BGOR");
    state->u.f4.reg.fgpfccr = cm_object_get_child_by_name(obj, "FGPFCCR");
    state->u.f4.reg.fgcolr = cm_object_get_child_by_name(obj, "FGCOLR");
    state->u.f4.reg.bgpfccr = cm_object_get_child_by_name(obj, "BGPFCCR");
    state->u.f4.reg.bgcolr = cm_object_get_child_by_name(obj, "BGCOLR");
    state->u.f4.reg.fgcmar = cm_object_get_child_by_name(obj, "FGCMAR");
    state->u.f4.reg.bgcmar = cm_object_get_child_by_name(obj, "BGCMAR");
    state->u.f4.reg.opfccr = cm_object_get_child_by_name(obj, "OPFCCR");
    state->u.f4.reg.ocolr = cm_object_get_child_by_name(obj, "OCOLR");
    state->u.f4.reg.omar = cm_object_get_child_by_name(obj, "OMAR");
    state->u.f4.reg.oor = cm_object_get_child_by_name(obj, "OOR");
    state->u.f4.reg.nlr = cm_object_get_child_by_name(obj, "NLR");
    state->u.f4.reg.lwr = cm_object_get_child_by_name(obj, "LWR");
    state->u.f4.reg.amtcr = cm_object_get_child_by_name(obj, "AMTCR");
    state->u.f4.reg.fgclut = cm_object_get_child_by_name(obj, "FGCLUT");
    state->u.f4.reg.bgclut = cm_object_get_child_by_name(obj, "BGCLUT");
    
    
    // CR bitfields.
    state->u.f4.fld.cr.start = cm_object_get_child_by_name(state->u.f4.reg.cr, "START"); 
    state->u.f4.fld.cr.susp = cm_object_get_child_by_name(state->u.f4.reg.cr, "SUSP"); 
    state->u.f4.fld.cr.abort = cm_object_get_child_by_name(state->u.f4.reg.cr, "ABORT"); 
    state->u.f4.fld.cr.teie = cm_object_get_child_by_name(state->u.f4.reg.cr, "TEIE"); 
    state->u.f4.fld.cr.tcie = cm_object_get_child_by_name(state->u.f4.reg.cr, "TCIE"); 
    state->u.f4.fld.cr.twie = cm_object_get_child_by_name(state->u.f4.reg.cr, "TWIE"); 
    state->u.f4.fld.cr.caeie = cm_object_get_child_by_name(state->u.f4.reg.cr, "CAEIE"); 
    state->u.f4.fld.cr.ctcie = cm_object_get_child_by_name(state->u.f4.reg.cr, "CTCIE"); 
    state->u.f4.fld.cr.ceie = cm_object_get_child_by_name(state->u.f4.reg.cr, "CEIE"); 
    state->u.f4.fld.cr.mode = cm_object_get_child_by_name(state->u.f4.reg.cr, "MODE");  
    
    // ISR bitfields.
    state->u.f4.fld.isr.teif = cm_object_get_child_by_name(state->u.f4.reg.isr, "TEIF"); 
    state->u.f4.fld.isr.tcif = cm_object_get_child_by_name(state->u.f4.reg.isr, "TCIF"); 
    state->u.f4.fld.isr.twif = cm_object_get_child_by_name(state->u.f4.reg.isr, "TWIF"); 
    state->u.f4.fld.isr.caeif = cm_object_get_child_by_name(state->u.f4.reg.isr, "CAEIF"); 
    state->u.f4.fld.isr.ctcif = cm_object_get_child_by_name(state->u.f4.reg.isr, "CTCIF"); 
    state->u.f4.fld.isr.ceif = cm_object_get_child_by_name(state->u.f4.reg.isr, "CEIF");  
    
    // IFCR bitfields.
    state->u.f4.fld.ifcr.cteif = cm_object_get_child_by_name(state->u.f4.reg.ifcr, "CTEIF"); 
    state->u.f4.fld.ifcr.ctcif = cm_object_get_child_by_name(state->u.f4.reg.ifcr, "CTCIF"); 
    state->u.f4.fld.ifcr.ctwif = cm_object_get_child_by_name(state->u.f4.reg.ifcr, "CTWIF"); 
    state->u.f4.fld.ifcr.caecif = cm_object_get_child_by_name(state->u.f4.reg.ifcr, "CAECIF"); 
    state->u.f4.fld.ifcr.cctcif = cm_object_get_child_by_name(state->u.f4.reg.ifcr, "CCTCIF"); 
    state->u.f4.fld.ifcr.cceif = cm_object_get_child_by_name(state->u.f4.reg.ifcr, "CCEIF");  
    
    // FGMAR bitfields.
    state->u.f4.fld.fgmar.ma = cm_object_get_child_by_name(state->u.f4.reg.fgmar, "MA");  
    
    // FGOR bitfields.
    state->u.f4.fld.fgor.lo = cm_object_get_child_by_name(state->u.f4.reg.fgor, "LO");  
    
    // BGMAR bitfields.
    state->u.f4.fld.bgmar.ma = cm_object_get_child_by_name(state->u.f4.reg.bgmar, "MA");  
    
    // BGOR bitfields.
    state->u.f4.fld.bgor.lo = cm_object_get_child_by_name(state->u.f4.reg.bgor, "LO");  
    
    // FGPFCCR bitfields.
    state->u.f4.fld.fgpfccr.cm = cm_object_get_child_by_name(state->u.f4.reg.fgpfccr, "CM"); 
    state->u.f4.fld.fgpfccr.ccm = cm_object_get_child_by_name(state->u.f4.reg.fgpfccr, "CCM"); 
    state->u.f4.fld.fgpfccr.start = cm_object_get_child_by_name(state->u.f4.reg.fgpfccr, "START"); 
    state->u.f4.fld.fgpfccr.cs = cm_object_get_child_by_name(state->u.f4.reg.fgpfccr, "CS"); 
    state->u.f4.fld.fgpfccr.am = cm_object_get_child_by_name(state->u.f4.reg.fgpfccr, "AM"); 
    state->u.f4.fld.fgpfccr.alpha = cm_object_get_child_by_name(state->u.f4.reg.fgpfccr, "ALPHA");  
    
    // FGCOLR bitfields.
    state->u.f4.fld.fgcolr.blue = cm_object_get_child_by_name(state->u.f4.reg.fgcolr, "BLUE"); 
    state->u.f4.fld.fgcolr.green = cm_object_get_child_by_name(state->u.f4.reg.fgcolr, "GREEN"); 
    state->u.f4.fld.fgcolr.red = cm_object_get_child_by_name(state->u.f4.reg.fgcolr, "RED");  
    
    // BGPFCCR bitfields.
    state->u.f4.fld.bgpfccr.cm = cm_object_get_child_by_name(state->u.f4.reg.bgpfccr, "CM"); 
    state->u.f4.fld.bgpfccr.ccm = cm_object_get_child_by_name(state->u.f4.reg.bgpfccr, "CCM"); 
    state->u.f4.fld.bgpfccr.start = cm_object_get_child_by_name(state->u.f4.reg.bgpfccr, "START"); 
    state->u.f4.fld.bgpfccr.cs = cm_object_get_child_by_name(state->u.f4.reg.bgpfccr, "CS"); 
    state->u.f4.fld.bgpfccr.am = cm_object_get_child_by_name(state->u.f4.reg.bgpfccr, "AM"); 
    state->u.f4.fld.bgpfccr.alpha = cm_object_get_child_by_name(state->u.f4.reg.bgpfccr, "ALPHA");  
    
    // BGCOLR bitfields.
    state->u.f4.fld.bgcolr.blue = cm_object_get_child_by_name(state->u.f4.reg.bgcolr, "BLUE"); 
    state->u.f4.fld.bgcolr.green = cm_object_get_child_by_name(state->u.f4.reg.bgcolr, "GREEN"); 
    state->u.f4.fld.bgcolr.red = cm_object_get_child_by_name(state->u.f4.reg.bgcolr, "RED");  
    
    // FGCMAR bitfields.
    state->u.f4.fld.fgcmar.ma = cm_object_get_child_by_name(state->u.f4.reg.fgcmar, "MA");  
    
    // BGCMAR bitfields.
    state->u.f4.fld.bgcmar.ma = cm_object_get_child_by_name(state->u.f4.reg.bgcmar, "MA");  
    
    // OPFCCR bitfields.
    state->u.f4.fld.opfccr.cm = cm_object_get_child_by_name(state->u.f4.reg.opfccr, "CM");  
    
    // OCOLR bitfields.
    state->u.f4.fld.ocolr.blue = cm_object_get_child_by_name(state->u.f4.reg.ocolr, "BLUE"); 
    state->u.f4.fld.ocolr.green = cm_object_get_child_by_name(state->u.f4.reg.ocolr, "GREEN"); 
    state->u.f4.fld.ocolr.red = cm_object_get_child_by_name(state->u.f4.reg.ocolr, "RED"); 
    state->u.f4.fld.ocolr.aplha = cm_object_get_child_by_name(state->u.f4.reg.ocolr, "APLHA");  
    
    // OMAR bitfields.
    state->u.f4.fld.omar.ma = cm_object_get_child_by_name(state->u.f4.reg.omar, "MA");  
    
    // OOR bitfields.
    state->u.f4.fld.oor.lo = cm_object_get_child_by_name(state->u.f4.reg.oor, "LO");  
    
    // NLR bitfields.
    state->u.f4.fld.nlr.nl = cm_object_get_child_by_name(state->u.f4.reg.nlr, "NL"); 
    state->u.f4.fld.nlr.pl = cm_object_get_child_by_name(state->u.f4.reg.nlr, "PL");  
    
    // LWR bitfields.
    state->u.f4.fld.lwr.lw = cm_object_get_child_by_name(state->u.f4.reg.lwr, "LW");  
    
    // AMTCR bitfields.
    state->u.f4.fld.amtcr.en = cm_object_get_child_by_name(state->u.f4.reg.amtcr, "EN"); 
    state->u.f4.fld.amtcr.dt = cm_object_get_child_by_name(state->u.f4.reg.amtcr, "DT");  
    
    // FGCLUT bitfields.
    state->u.f4.fld.fgclut.blue = cm_object_get_child_by_name(state->u.f4.reg.fgclut, "BLUE"); 
    state->u.f4.fld.fgclut.green = cm_object_get_child_by_name(state->u.f4.reg.fgclut, "GREEN"); 
    state->u.f4.fld.fgclut.red = cm_object_get_child_by_name(state->u.f4.reg.fgclut, "RED"); 
    state->u.f4.fld.fgclut.aplha = cm_object_get_child_by_name(state->u.f4.reg.fgclut, "APLHA");  
    
    // BGCLUT bitfields.
    state->u.f4.fld.bgclut.blue = cm_object_get_child_by_name(state->u.f4.reg.bgclut, "BLUE"); 
    state->u.f4.fld.bgclut.green = cm_object_get_child_by_name(state->u.f4.reg.bgclut, "GREEN"); 
    state->u.f4.fld.bgclut.red = cm_object_get_child_by_name(state->u.f4.reg.bgclut, "RED"); 
    state->u.f4.fld.bgclut.aplha = cm_object_get_child_by_name(state->u.f4.reg.bgclut, "APLHA");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_dma2d_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32DMA2DState *state = STM32_DMA2D_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_dma2d_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32DMA2DState *state = STM32_DMA2D_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_dma2d_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32DMA2DState *state = STM32_DMA2D_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_dma2d_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32DMA2DState *state = STM32_DMA2D_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_dma2d_is_enabled(Object *obj)
{
    STM32DMA2DState *state = STM32_DMA2D_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_dma2d_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32DMA2DState *state = STM32_DMA2D_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_dma2d_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_DMA2D)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32DMA2DState *state = STM32_DMA2D_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "DMA2D";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_429x ) {

            stm32f429x_dma2d_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_dma2d_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_dma2d_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_dma2d_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_dma2d_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/DMA2DEN");


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

static void stm32_dma2d_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_DMA2D);
}

static void stm32_dma2d_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_dma2d_reset_callback;
    dc->realize = stm32_dma2d_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_dma2d_is_enabled;
}

static const TypeInfo stm32_dma2d_type_info = {
    .name = TYPE_STM32_DMA2D,
    .parent = TYPE_STM32_DMA2D_PARENT,
    .instance_init = stm32_dma2d_instance_init_callback,
    .instance_size = sizeof(STM32DMA2DState),
    .class_init = stm32_dma2d_class_init_callback,
    .class_size = sizeof(STM32DMA2DClass) };

static void stm32_dma2d_register_types(void)
{
    type_register_static(&stm32_dma2d_type_info);
}

type_init(stm32_dma2d_register_types);

// ----------------------------------------------------------------------------
