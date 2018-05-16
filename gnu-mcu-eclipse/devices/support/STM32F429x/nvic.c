/*
 * STM32 - NVIC (Nested Vectored Interrupt Controller) emulation.
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

#include <hw/cortexm/stm32/nvic.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f429x_nvic_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32NVICState *state = STM32_NVIC_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.ictr = cm_object_get_child_by_name(obj, "ICTR");
    state->u.f4.reg.stir = cm_object_get_child_by_name(obj, "STIR");
    state->u.f4.reg.iser0 = cm_object_get_child_by_name(obj, "ISER0");
    state->u.f4.reg.iser1 = cm_object_get_child_by_name(obj, "ISER1");
    state->u.f4.reg.iser2 = cm_object_get_child_by_name(obj, "ISER2");
    state->u.f4.reg.icer0 = cm_object_get_child_by_name(obj, "ICER0");
    state->u.f4.reg.icer1 = cm_object_get_child_by_name(obj, "ICER1");
    state->u.f4.reg.icer2 = cm_object_get_child_by_name(obj, "ICER2");
    state->u.f4.reg.ispr0 = cm_object_get_child_by_name(obj, "ISPR0");
    state->u.f4.reg.ispr1 = cm_object_get_child_by_name(obj, "ISPR1");
    state->u.f4.reg.ispr2 = cm_object_get_child_by_name(obj, "ISPR2");
    state->u.f4.reg.icpr0 = cm_object_get_child_by_name(obj, "ICPR0");
    state->u.f4.reg.icpr1 = cm_object_get_child_by_name(obj, "ICPR1");
    state->u.f4.reg.icpr2 = cm_object_get_child_by_name(obj, "ICPR2");
    state->u.f4.reg.iabr0 = cm_object_get_child_by_name(obj, "IABR0");
    state->u.f4.reg.iabr1 = cm_object_get_child_by_name(obj, "IABR1");
    state->u.f4.reg.iabr2 = cm_object_get_child_by_name(obj, "IABR2");
    state->u.f4.reg.ipr0 = cm_object_get_child_by_name(obj, "IPR0");
    state->u.f4.reg.ipr1 = cm_object_get_child_by_name(obj, "IPR1");
    state->u.f4.reg.ipr2 = cm_object_get_child_by_name(obj, "IPR2");
    state->u.f4.reg.ipr3 = cm_object_get_child_by_name(obj, "IPR3");
    state->u.f4.reg.ipr4 = cm_object_get_child_by_name(obj, "IPR4");
    state->u.f4.reg.ipr5 = cm_object_get_child_by_name(obj, "IPR5");
    state->u.f4.reg.ipr6 = cm_object_get_child_by_name(obj, "IPR6");
    state->u.f4.reg.ipr7 = cm_object_get_child_by_name(obj, "IPR7");
    state->u.f4.reg.ipr8 = cm_object_get_child_by_name(obj, "IPR8");
    state->u.f4.reg.ipr9 = cm_object_get_child_by_name(obj, "IPR9");
    state->u.f4.reg.ipr10 = cm_object_get_child_by_name(obj, "IPR10");
    state->u.f4.reg.ipr11 = cm_object_get_child_by_name(obj, "IPR11");
    state->u.f4.reg.ipr12 = cm_object_get_child_by_name(obj, "IPR12");
    state->u.f4.reg.ipr13 = cm_object_get_child_by_name(obj, "IPR13");
    state->u.f4.reg.ipr14 = cm_object_get_child_by_name(obj, "IPR14");
    state->u.f4.reg.ipr15 = cm_object_get_child_by_name(obj, "IPR15");
    state->u.f4.reg.ipr16 = cm_object_get_child_by_name(obj, "IPR16");
    state->u.f4.reg.ipr17 = cm_object_get_child_by_name(obj, "IPR17");
    state->u.f4.reg.ipr18 = cm_object_get_child_by_name(obj, "IPR18");
    state->u.f4.reg.ipr19 = cm_object_get_child_by_name(obj, "IPR19");
    state->u.f4.reg.ipr20 = cm_object_get_child_by_name(obj, "IPR20");
    
    
    // ICTR bitfields.
    state->u.f4.fld.ictr.intlinesnum = cm_object_get_child_by_name(state->u.f4.reg.ictr, "INTLINESNUM");  
    
    // STIR bitfields.
    state->u.f4.fld.stir.intid = cm_object_get_child_by_name(state->u.f4.reg.stir, "INTID");  
    
    // ISER0 bitfields.
    state->u.f4.fld.iser0.setena = cm_object_get_child_by_name(state->u.f4.reg.iser0, "SETENA");  
    
    // ISER1 bitfields.
    state->u.f4.fld.iser1.setena = cm_object_get_child_by_name(state->u.f4.reg.iser1, "SETENA");  
    
    // ISER2 bitfields.
    state->u.f4.fld.iser2.setena = cm_object_get_child_by_name(state->u.f4.reg.iser2, "SETENA");  
    
    // ICER0 bitfields.
    state->u.f4.fld.icer0.clrena = cm_object_get_child_by_name(state->u.f4.reg.icer0, "CLRENA");  
    
    // ICER1 bitfields.
    state->u.f4.fld.icer1.clrena = cm_object_get_child_by_name(state->u.f4.reg.icer1, "CLRENA");  
    
    // ICER2 bitfields.
    state->u.f4.fld.icer2.clrena = cm_object_get_child_by_name(state->u.f4.reg.icer2, "CLRENA");  
    
    // ISPR0 bitfields.
    state->u.f4.fld.ispr0.setpend = cm_object_get_child_by_name(state->u.f4.reg.ispr0, "SETPEND");  
    
    // ISPR1 bitfields.
    state->u.f4.fld.ispr1.setpend = cm_object_get_child_by_name(state->u.f4.reg.ispr1, "SETPEND");  
    
    // ISPR2 bitfields.
    state->u.f4.fld.ispr2.setpend = cm_object_get_child_by_name(state->u.f4.reg.ispr2, "SETPEND");  
    
    // ICPR0 bitfields.
    state->u.f4.fld.icpr0.clrpend = cm_object_get_child_by_name(state->u.f4.reg.icpr0, "CLRPEND");  
    
    // ICPR1 bitfields.
    state->u.f4.fld.icpr1.clrpend = cm_object_get_child_by_name(state->u.f4.reg.icpr1, "CLRPEND");  
    
    // ICPR2 bitfields.
    state->u.f4.fld.icpr2.clrpend = cm_object_get_child_by_name(state->u.f4.reg.icpr2, "CLRPEND");  
    
    // IABR0 bitfields.
    state->u.f4.fld.iabr0.active = cm_object_get_child_by_name(state->u.f4.reg.iabr0, "ACTIVE");  
    
    // IABR1 bitfields.
    state->u.f4.fld.iabr1.active = cm_object_get_child_by_name(state->u.f4.reg.iabr1, "ACTIVE");  
    
    // IABR2 bitfields.
    state->u.f4.fld.iabr2.active = cm_object_get_child_by_name(state->u.f4.reg.iabr2, "ACTIVE");  
    
    // IPR0 bitfields.
    state->u.f4.fld.ipr0.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr0, "IPR_N0"); 
    state->u.f4.fld.ipr0.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr0, "IPR_N1"); 
    state->u.f4.fld.ipr0.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr0, "IPR_N2"); 
    state->u.f4.fld.ipr0.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr0, "IPR_N3");  
    
    // IPR1 bitfields.
    state->u.f4.fld.ipr1.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr1, "IPR_N0"); 
    state->u.f4.fld.ipr1.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr1, "IPR_N1"); 
    state->u.f4.fld.ipr1.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr1, "IPR_N2"); 
    state->u.f4.fld.ipr1.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr1, "IPR_N3");  
    
    // IPR2 bitfields.
    state->u.f4.fld.ipr2.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr2, "IPR_N0"); 
    state->u.f4.fld.ipr2.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr2, "IPR_N1"); 
    state->u.f4.fld.ipr2.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr2, "IPR_N2"); 
    state->u.f4.fld.ipr2.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr2, "IPR_N3");  
    
    // IPR3 bitfields.
    state->u.f4.fld.ipr3.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr3, "IPR_N0"); 
    state->u.f4.fld.ipr3.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr3, "IPR_N1"); 
    state->u.f4.fld.ipr3.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr3, "IPR_N2"); 
    state->u.f4.fld.ipr3.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr3, "IPR_N3");  
    
    // IPR4 bitfields.
    state->u.f4.fld.ipr4.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr4, "IPR_N0"); 
    state->u.f4.fld.ipr4.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr4, "IPR_N1"); 
    state->u.f4.fld.ipr4.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr4, "IPR_N2"); 
    state->u.f4.fld.ipr4.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr4, "IPR_N3");  
    
    // IPR5 bitfields.
    state->u.f4.fld.ipr5.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr5, "IPR_N0"); 
    state->u.f4.fld.ipr5.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr5, "IPR_N1"); 
    state->u.f4.fld.ipr5.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr5, "IPR_N2"); 
    state->u.f4.fld.ipr5.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr5, "IPR_N3");  
    
    // IPR6 bitfields.
    state->u.f4.fld.ipr6.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr6, "IPR_N0"); 
    state->u.f4.fld.ipr6.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr6, "IPR_N1"); 
    state->u.f4.fld.ipr6.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr6, "IPR_N2"); 
    state->u.f4.fld.ipr6.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr6, "IPR_N3");  
    
    // IPR7 bitfields.
    state->u.f4.fld.ipr7.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr7, "IPR_N0"); 
    state->u.f4.fld.ipr7.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr7, "IPR_N1"); 
    state->u.f4.fld.ipr7.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr7, "IPR_N2"); 
    state->u.f4.fld.ipr7.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr7, "IPR_N3");  
    
    // IPR8 bitfields.
    state->u.f4.fld.ipr8.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr8, "IPR_N0"); 
    state->u.f4.fld.ipr8.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr8, "IPR_N1"); 
    state->u.f4.fld.ipr8.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr8, "IPR_N2"); 
    state->u.f4.fld.ipr8.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr8, "IPR_N3");  
    
    // IPR9 bitfields.
    state->u.f4.fld.ipr9.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr9, "IPR_N0"); 
    state->u.f4.fld.ipr9.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr9, "IPR_N1"); 
    state->u.f4.fld.ipr9.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr9, "IPR_N2"); 
    state->u.f4.fld.ipr9.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr9, "IPR_N3");  
    
    // IPR10 bitfields.
    state->u.f4.fld.ipr10.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr10, "IPR_N0"); 
    state->u.f4.fld.ipr10.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr10, "IPR_N1"); 
    state->u.f4.fld.ipr10.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr10, "IPR_N2"); 
    state->u.f4.fld.ipr10.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr10, "IPR_N3");  
    
    // IPR11 bitfields.
    state->u.f4.fld.ipr11.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr11, "IPR_N0"); 
    state->u.f4.fld.ipr11.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr11, "IPR_N1"); 
    state->u.f4.fld.ipr11.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr11, "IPR_N2"); 
    state->u.f4.fld.ipr11.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr11, "IPR_N3");  
    
    // IPR12 bitfields.
    state->u.f4.fld.ipr12.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr12, "IPR_N0"); 
    state->u.f4.fld.ipr12.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr12, "IPR_N1"); 
    state->u.f4.fld.ipr12.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr12, "IPR_N2"); 
    state->u.f4.fld.ipr12.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr12, "IPR_N3");  
    
    // IPR13 bitfields.
    state->u.f4.fld.ipr13.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr13, "IPR_N0"); 
    state->u.f4.fld.ipr13.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr13, "IPR_N1"); 
    state->u.f4.fld.ipr13.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr13, "IPR_N2"); 
    state->u.f4.fld.ipr13.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr13, "IPR_N3");  
    
    // IPR14 bitfields.
    state->u.f4.fld.ipr14.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr14, "IPR_N0"); 
    state->u.f4.fld.ipr14.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr14, "IPR_N1"); 
    state->u.f4.fld.ipr14.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr14, "IPR_N2"); 
    state->u.f4.fld.ipr14.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr14, "IPR_N3");  
    
    // IPR15 bitfields.
    state->u.f4.fld.ipr15.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr15, "IPR_N0"); 
    state->u.f4.fld.ipr15.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr15, "IPR_N1"); 
    state->u.f4.fld.ipr15.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr15, "IPR_N2"); 
    state->u.f4.fld.ipr15.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr15, "IPR_N3");  
    
    // IPR16 bitfields.
    state->u.f4.fld.ipr16.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr16, "IPR_N0"); 
    state->u.f4.fld.ipr16.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr16, "IPR_N1"); 
    state->u.f4.fld.ipr16.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr16, "IPR_N2"); 
    state->u.f4.fld.ipr16.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr16, "IPR_N3");  
    
    // IPR17 bitfields.
    state->u.f4.fld.ipr17.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr17, "IPR_N0"); 
    state->u.f4.fld.ipr17.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr17, "IPR_N1"); 
    state->u.f4.fld.ipr17.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr17, "IPR_N2"); 
    state->u.f4.fld.ipr17.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr17, "IPR_N3");  
    
    // IPR18 bitfields.
    state->u.f4.fld.ipr18.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr18, "IPR_N0"); 
    state->u.f4.fld.ipr18.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr18, "IPR_N1"); 
    state->u.f4.fld.ipr18.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr18, "IPR_N2"); 
    state->u.f4.fld.ipr18.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr18, "IPR_N3");  
    
    // IPR19 bitfields.
    state->u.f4.fld.ipr19.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr19, "IPR_N0"); 
    state->u.f4.fld.ipr19.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr19, "IPR_N1"); 
    state->u.f4.fld.ipr19.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr19, "IPR_N2"); 
    state->u.f4.fld.ipr19.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr19, "IPR_N3");  
    
    // IPR20 bitfields.
    state->u.f4.fld.ipr20.ipr_n0 = cm_object_get_child_by_name(state->u.f4.reg.ipr20, "IPR_N0"); 
    state->u.f4.fld.ipr20.ipr_n1 = cm_object_get_child_by_name(state->u.f4.reg.ipr20, "IPR_N1"); 
    state->u.f4.fld.ipr20.ipr_n2 = cm_object_get_child_by_name(state->u.f4.reg.ipr20, "IPR_N2"); 
    state->u.f4.fld.ipr20.ipr_n3 = cm_object_get_child_by_name(state->u.f4.reg.ipr20, "IPR_N3");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_nvic_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32NVICState *state = STM32_NVIC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_nvic_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32NVICState *state = STM32_NVIC_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_nvic_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32NVICState *state = STM32_NVIC_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_nvic_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32NVICState *state = STM32_NVIC_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_nvic_is_enabled(Object *obj)
{
    STM32NVICState *state = STM32_NVIC_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_nvic_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32NVICState *state = STM32_NVIC_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_nvic_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_NVIC)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32NVICState *state = STM32_NVIC_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "NVIC";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_429x ) {

            stm32f429x_nvic_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_nvic_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_nvic_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_nvic_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_nvic_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/NVICEN");


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

static void stm32_nvic_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_NVIC);
}

static void stm32_nvic_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_nvic_reset_callback;
    dc->realize = stm32_nvic_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_nvic_is_enabled;
}

static const TypeInfo stm32_nvic_type_info = {
    .name = TYPE_STM32_NVIC,
    .parent = TYPE_STM32_NVIC_PARENT,
    .instance_init = stm32_nvic_instance_init_callback,
    .instance_size = sizeof(STM32NVICState),
    .class_init = stm32_nvic_class_init_callback,
    .class_size = sizeof(STM32NVICClass) };

static void stm32_nvic_register_types(void)
{
    type_register_static(&stm32_nvic_type_info);
}

type_init(stm32_nvic_register_types);

// ----------------------------------------------------------------------------
