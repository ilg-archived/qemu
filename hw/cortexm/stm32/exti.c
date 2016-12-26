/*
 * STM32 MCU - EXTI (external interrupts controller) emulation.
 *
 * Copyright (c) 2016 Liviu Ionescu.
 * Copyright (c) 2010 Andre Beckus.
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

#include <hw/cortexm/stm32/exti.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

/*
 * This file implements the STM32 EXTI.
 *
 * Not yet implemented:
 * - event mode; EMR ignored, no events are generated.
 */

// ----- Generated code -------------------------------------------------------
//
// STM32F051R8
// DO NOT EDIT! Automatically generated!
static void stm32f0x1_exti_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32EXTIState *state = STM32_EXTI_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f0.reg.imr = cm_object_get_child_by_name(obj, "IMR");
    state->u.f0.reg.emr = cm_object_get_child_by_name(obj, "EMR");
    state->u.f0.reg.rtsr = cm_object_get_child_by_name(obj, "RTSR");
    state->u.f0.reg.ftsr = cm_object_get_child_by_name(obj, "FTSR");
    state->u.f0.reg.swier = cm_object_get_child_by_name(obj, "SWIER");
    state->u.f0.reg.pr = cm_object_get_child_by_name(obj, "PR");

    // IMR bitfields.
    state->u.f0.fld.imr.mr0 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR0");
    state->u.f0.fld.imr.mr1 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR1");
    state->u.f0.fld.imr.mr2 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR2");
    state->u.f0.fld.imr.mr3 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR3");
    state->u.f0.fld.imr.mr4 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR4");
    state->u.f0.fld.imr.mr5 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR5");
    state->u.f0.fld.imr.mr6 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR6");
    state->u.f0.fld.imr.mr7 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR7");
    state->u.f0.fld.imr.mr8 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR8");
    state->u.f0.fld.imr.mr9 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR9");
    state->u.f0.fld.imr.mr10 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR10");
    state->u.f0.fld.imr.mr11 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR11");
    state->u.f0.fld.imr.mr12 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR12");
    state->u.f0.fld.imr.mr13 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR13");
    state->u.f0.fld.imr.mr14 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR14");
    state->u.f0.fld.imr.mr15 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR15");
    state->u.f0.fld.imr.mr16 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR16");
    state->u.f0.fld.imr.mr17 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR17");
    state->u.f0.fld.imr.mr18 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR18");
    state->u.f0.fld.imr.mr19 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR19");
    state->u.f0.fld.imr.mr20 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR20");
    state->u.f0.fld.imr.mr21 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR21");
    state->u.f0.fld.imr.mr22 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR22");
    state->u.f0.fld.imr.mr23 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR23");
    state->u.f0.fld.imr.mr24 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR24");
    state->u.f0.fld.imr.mr25 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR25");
    state->u.f0.fld.imr.mr26 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR26");
    state->u.f0.fld.imr.mr27 = cm_object_get_child_by_name(state->u.f0.reg.imr,
            "MR27");

    // EMR bitfields.
    state->u.f0.fld.emr.mr0 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR0");
    state->u.f0.fld.emr.mr1 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR1");
    state->u.f0.fld.emr.mr2 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR2");
    state->u.f0.fld.emr.mr3 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR3");
    state->u.f0.fld.emr.mr4 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR4");
    state->u.f0.fld.emr.mr5 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR5");
    state->u.f0.fld.emr.mr6 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR6");
    state->u.f0.fld.emr.mr7 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR7");
    state->u.f0.fld.emr.mr8 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR8");
    state->u.f0.fld.emr.mr9 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR9");
    state->u.f0.fld.emr.mr10 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR10");
    state->u.f0.fld.emr.mr11 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR11");
    state->u.f0.fld.emr.mr12 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR12");
    state->u.f0.fld.emr.mr13 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR13");
    state->u.f0.fld.emr.mr14 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR14");
    state->u.f0.fld.emr.mr15 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR15");
    state->u.f0.fld.emr.mr16 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR16");
    state->u.f0.fld.emr.mr17 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR17");
    state->u.f0.fld.emr.mr18 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR18");
    state->u.f0.fld.emr.mr19 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR19");
    state->u.f0.fld.emr.mr20 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR20");
    state->u.f0.fld.emr.mr21 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR21");
    state->u.f0.fld.emr.mr22 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR22");
    state->u.f0.fld.emr.mr23 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR23");
    state->u.f0.fld.emr.mr24 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR24");
    state->u.f0.fld.emr.mr25 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR25");
    state->u.f0.fld.emr.mr26 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR26");
    state->u.f0.fld.emr.mr27 = cm_object_get_child_by_name(state->u.f0.reg.emr,
            "MR27");

    // RTSR bitfields.
    state->u.f0.fld.rtsr.tr0 = cm_object_get_child_by_name(state->u.f0.reg.rtsr,
            "TR0");
    state->u.f0.fld.rtsr.tr1 = cm_object_get_child_by_name(state->u.f0.reg.rtsr,
            "TR1");
    state->u.f0.fld.rtsr.tr2 = cm_object_get_child_by_name(state->u.f0.reg.rtsr,
            "TR2");
    state->u.f0.fld.rtsr.tr3 = cm_object_get_child_by_name(state->u.f0.reg.rtsr,
            "TR3");
    state->u.f0.fld.rtsr.tr4 = cm_object_get_child_by_name(state->u.f0.reg.rtsr,
            "TR4");
    state->u.f0.fld.rtsr.tr5 = cm_object_get_child_by_name(state->u.f0.reg.rtsr,
            "TR5");
    state->u.f0.fld.rtsr.tr6 = cm_object_get_child_by_name(state->u.f0.reg.rtsr,
            "TR6");
    state->u.f0.fld.rtsr.tr7 = cm_object_get_child_by_name(state->u.f0.reg.rtsr,
            "TR7");
    state->u.f0.fld.rtsr.tr8 = cm_object_get_child_by_name(state->u.f0.reg.rtsr,
            "TR8");
    state->u.f0.fld.rtsr.tr9 = cm_object_get_child_by_name(state->u.f0.reg.rtsr,
            "TR9");
    state->u.f0.fld.rtsr.tr10 = cm_object_get_child_by_name(
            state->u.f0.reg.rtsr, "TR10");
    state->u.f0.fld.rtsr.tr11 = cm_object_get_child_by_name(
            state->u.f0.reg.rtsr, "TR11");
    state->u.f0.fld.rtsr.tr12 = cm_object_get_child_by_name(
            state->u.f0.reg.rtsr, "TR12");
    state->u.f0.fld.rtsr.tr13 = cm_object_get_child_by_name(
            state->u.f0.reg.rtsr, "TR13");
    state->u.f0.fld.rtsr.tr14 = cm_object_get_child_by_name(
            state->u.f0.reg.rtsr, "TR14");
    state->u.f0.fld.rtsr.tr15 = cm_object_get_child_by_name(
            state->u.f0.reg.rtsr, "TR15");
    state->u.f0.fld.rtsr.tr16 = cm_object_get_child_by_name(
            state->u.f0.reg.rtsr, "TR16");
    state->u.f0.fld.rtsr.tr17 = cm_object_get_child_by_name(
            state->u.f0.reg.rtsr, "TR17");
    state->u.f0.fld.rtsr.tr19 = cm_object_get_child_by_name(
            state->u.f0.reg.rtsr, "TR19");

    // FTSR bitfields.
    state->u.f0.fld.ftsr.tr0 = cm_object_get_child_by_name(state->u.f0.reg.ftsr,
            "TR0");
    state->u.f0.fld.ftsr.tr1 = cm_object_get_child_by_name(state->u.f0.reg.ftsr,
            "TR1");
    state->u.f0.fld.ftsr.tr2 = cm_object_get_child_by_name(state->u.f0.reg.ftsr,
            "TR2");
    state->u.f0.fld.ftsr.tr3 = cm_object_get_child_by_name(state->u.f0.reg.ftsr,
            "TR3");
    state->u.f0.fld.ftsr.tr4 = cm_object_get_child_by_name(state->u.f0.reg.ftsr,
            "TR4");
    state->u.f0.fld.ftsr.tr5 = cm_object_get_child_by_name(state->u.f0.reg.ftsr,
            "TR5");
    state->u.f0.fld.ftsr.tr6 = cm_object_get_child_by_name(state->u.f0.reg.ftsr,
            "TR6");
    state->u.f0.fld.ftsr.tr7 = cm_object_get_child_by_name(state->u.f0.reg.ftsr,
            "TR7");
    state->u.f0.fld.ftsr.tr8 = cm_object_get_child_by_name(state->u.f0.reg.ftsr,
            "TR8");
    state->u.f0.fld.ftsr.tr9 = cm_object_get_child_by_name(state->u.f0.reg.ftsr,
            "TR9");
    state->u.f0.fld.ftsr.tr10 = cm_object_get_child_by_name(
            state->u.f0.reg.ftsr, "TR10");
    state->u.f0.fld.ftsr.tr11 = cm_object_get_child_by_name(
            state->u.f0.reg.ftsr, "TR11");
    state->u.f0.fld.ftsr.tr12 = cm_object_get_child_by_name(
            state->u.f0.reg.ftsr, "TR12");
    state->u.f0.fld.ftsr.tr13 = cm_object_get_child_by_name(
            state->u.f0.reg.ftsr, "TR13");
    state->u.f0.fld.ftsr.tr14 = cm_object_get_child_by_name(
            state->u.f0.reg.ftsr, "TR14");
    state->u.f0.fld.ftsr.tr15 = cm_object_get_child_by_name(
            state->u.f0.reg.ftsr, "TR15");
    state->u.f0.fld.ftsr.tr16 = cm_object_get_child_by_name(
            state->u.f0.reg.ftsr, "TR16");
    state->u.f0.fld.ftsr.tr17 = cm_object_get_child_by_name(
            state->u.f0.reg.ftsr, "TR17");
    state->u.f0.fld.ftsr.tr19 = cm_object_get_child_by_name(
            state->u.f0.reg.ftsr, "TR19");

    // SWIER bitfields.
    state->u.f0.fld.swier.swier0 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER0");
    state->u.f0.fld.swier.swier1 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER1");
    state->u.f0.fld.swier.swier2 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER2");
    state->u.f0.fld.swier.swier3 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER3");
    state->u.f0.fld.swier.swier4 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER4");
    state->u.f0.fld.swier.swier5 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER5");
    state->u.f0.fld.swier.swier6 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER6");
    state->u.f0.fld.swier.swier7 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER7");
    state->u.f0.fld.swier.swier8 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER8");
    state->u.f0.fld.swier.swier9 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER9");
    state->u.f0.fld.swier.swier10 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER10");
    state->u.f0.fld.swier.swier11 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER11");
    state->u.f0.fld.swier.swier12 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER12");
    state->u.f0.fld.swier.swier13 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER13");
    state->u.f0.fld.swier.swier14 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER14");
    state->u.f0.fld.swier.swier15 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER15");
    state->u.f0.fld.swier.swier16 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER16");
    state->u.f0.fld.swier.swier17 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER17");
    state->u.f0.fld.swier.swier19 = cm_object_get_child_by_name(
            state->u.f0.reg.swier, "SWIER19");

    // PR bitfields.
    state->u.f0.fld.pr.pr0 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR0");
    state->u.f0.fld.pr.pr1 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR1");
    state->u.f0.fld.pr.pr2 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR2");
    state->u.f0.fld.pr.pr3 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR3");
    state->u.f0.fld.pr.pr4 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR4");
    state->u.f0.fld.pr.pr5 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR5");
    state->u.f0.fld.pr.pr6 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR6");
    state->u.f0.fld.pr.pr7 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR7");
    state->u.f0.fld.pr.pr8 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR8");
    state->u.f0.fld.pr.pr9 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR9");
    state->u.f0.fld.pr.pr10 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR10");
    state->u.f0.fld.pr.pr11 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR11");
    state->u.f0.fld.pr.pr12 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR12");
    state->u.f0.fld.pr.pr13 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR13");
    state->u.f0.fld.pr.pr14 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR14");
    state->u.f0.fld.pr.pr15 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR15");
    state->u.f0.fld.pr.pr16 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR16");
    state->u.f0.fld.pr.pr17 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR17");
    state->u.f0.fld.pr.pr19 = cm_object_get_child_by_name(state->u.f0.reg.pr,
            "PR19");
}

// ----------------------------------------------------------------------------

// STM32F103RB
// DO NOT EDIT! Automatically generated!
static void stm32f103xx_exti_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32EXTIState *state = STM32_EXTI_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f1.reg.imr = cm_object_get_child_by_name(obj, "IMR");
    state->u.f1.reg.emr = cm_object_get_child_by_name(obj, "EMR");
    state->u.f1.reg.rtsr = cm_object_get_child_by_name(obj, "RTSR");
    state->u.f1.reg.ftsr = cm_object_get_child_by_name(obj, "FTSR");
    state->u.f1.reg.swier = cm_object_get_child_by_name(obj, "SWIER");
    state->u.f1.reg.pr = cm_object_get_child_by_name(obj, "PR");

    // IMR bitfields.
    state->u.f1.fld.imr.mr0 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR0");
    state->u.f1.fld.imr.mr1 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR1");
    state->u.f1.fld.imr.mr2 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR2");
    state->u.f1.fld.imr.mr3 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR3");
    state->u.f1.fld.imr.mr4 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR4");
    state->u.f1.fld.imr.mr5 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR5");
    state->u.f1.fld.imr.mr6 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR6");
    state->u.f1.fld.imr.mr7 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR7");
    state->u.f1.fld.imr.mr8 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR8");
    state->u.f1.fld.imr.mr9 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR9");
    state->u.f1.fld.imr.mr10 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR10");
    state->u.f1.fld.imr.mr11 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR11");
    state->u.f1.fld.imr.mr12 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR12");
    state->u.f1.fld.imr.mr13 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR13");
    state->u.f1.fld.imr.mr14 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR14");
    state->u.f1.fld.imr.mr15 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR15");
    state->u.f1.fld.imr.mr16 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR16");
    state->u.f1.fld.imr.mr17 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR17");
    state->u.f1.fld.imr.mr18 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR18");

    // EMR bitfields.
    state->u.f1.fld.emr.mr0 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR0");
    state->u.f1.fld.emr.mr1 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR1");
    state->u.f1.fld.emr.mr2 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR2");
    state->u.f1.fld.emr.mr3 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR3");
    state->u.f1.fld.emr.mr4 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR4");
    state->u.f1.fld.emr.mr5 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR5");
    state->u.f1.fld.emr.mr6 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR6");
    state->u.f1.fld.emr.mr7 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR7");
    state->u.f1.fld.emr.mr8 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR8");
    state->u.f1.fld.emr.mr9 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR9");
    state->u.f1.fld.emr.mr10 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR10");
    state->u.f1.fld.emr.mr11 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR11");
    state->u.f1.fld.emr.mr12 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR12");
    state->u.f1.fld.emr.mr13 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR13");
    state->u.f1.fld.emr.mr14 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR14");
    state->u.f1.fld.emr.mr15 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR15");
    state->u.f1.fld.emr.mr16 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR16");
    state->u.f1.fld.emr.mr17 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR17");
    state->u.f1.fld.emr.mr18 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR18");

    // RTSR bitfields.
    state->u.f1.fld.rtsr.tr0 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR0");
    state->u.f1.fld.rtsr.tr1 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR1");
    state->u.f1.fld.rtsr.tr2 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR2");
    state->u.f1.fld.rtsr.tr3 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR3");
    state->u.f1.fld.rtsr.tr4 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR4");
    state->u.f1.fld.rtsr.tr5 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR5");
    state->u.f1.fld.rtsr.tr6 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR6");
    state->u.f1.fld.rtsr.tr7 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR7");
    state->u.f1.fld.rtsr.tr8 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR8");
    state->u.f1.fld.rtsr.tr9 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR9");
    state->u.f1.fld.rtsr.tr10 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR10");
    state->u.f1.fld.rtsr.tr11 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR11");
    state->u.f1.fld.rtsr.tr12 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR12");
    state->u.f1.fld.rtsr.tr13 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR13");
    state->u.f1.fld.rtsr.tr14 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR14");
    state->u.f1.fld.rtsr.tr15 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR15");
    state->u.f1.fld.rtsr.tr16 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR16");
    state->u.f1.fld.rtsr.tr17 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR17");
    state->u.f1.fld.rtsr.tr18 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR18");

    // FTSR bitfields.
    state->u.f1.fld.ftsr.tr0 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR0");
    state->u.f1.fld.ftsr.tr1 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR1");
    state->u.f1.fld.ftsr.tr2 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR2");
    state->u.f1.fld.ftsr.tr3 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR3");
    state->u.f1.fld.ftsr.tr4 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR4");
    state->u.f1.fld.ftsr.tr5 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR5");
    state->u.f1.fld.ftsr.tr6 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR6");
    state->u.f1.fld.ftsr.tr7 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR7");
    state->u.f1.fld.ftsr.tr8 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR8");
    state->u.f1.fld.ftsr.tr9 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR9");
    state->u.f1.fld.ftsr.tr10 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR10");
    state->u.f1.fld.ftsr.tr11 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR11");
    state->u.f1.fld.ftsr.tr12 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR12");
    state->u.f1.fld.ftsr.tr13 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR13");
    state->u.f1.fld.ftsr.tr14 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR14");
    state->u.f1.fld.ftsr.tr15 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR15");
    state->u.f1.fld.ftsr.tr16 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR16");
    state->u.f1.fld.ftsr.tr17 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR17");
    state->u.f1.fld.ftsr.tr18 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR18");

    // SWIER bitfields.
    state->u.f1.fld.swier.swier0 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER0");
    state->u.f1.fld.swier.swier1 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER1");
    state->u.f1.fld.swier.swier2 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER2");
    state->u.f1.fld.swier.swier3 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER3");
    state->u.f1.fld.swier.swier4 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER4");
    state->u.f1.fld.swier.swier5 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER5");
    state->u.f1.fld.swier.swier6 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER6");
    state->u.f1.fld.swier.swier7 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER7");
    state->u.f1.fld.swier.swier8 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER8");
    state->u.f1.fld.swier.swier9 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER9");
    state->u.f1.fld.swier.swier10 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER10");
    state->u.f1.fld.swier.swier11 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER11");
    state->u.f1.fld.swier.swier12 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER12");
    state->u.f1.fld.swier.swier13 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER13");
    state->u.f1.fld.swier.swier14 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER14");
    state->u.f1.fld.swier.swier15 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER15");
    state->u.f1.fld.swier.swier16 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER16");
    state->u.f1.fld.swier.swier17 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER17");
    state->u.f1.fld.swier.swier18 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER18");

    // PR bitfields.
    state->u.f1.fld.pr.pr0 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR0");
    state->u.f1.fld.pr.pr1 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR1");
    state->u.f1.fld.pr.pr2 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR2");
    state->u.f1.fld.pr.pr3 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR3");
    state->u.f1.fld.pr.pr4 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR4");
    state->u.f1.fld.pr.pr5 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR5");
    state->u.f1.fld.pr.pr6 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR6");
    state->u.f1.fld.pr.pr7 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR7");
    state->u.f1.fld.pr.pr8 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR8");
    state->u.f1.fld.pr.pr9 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR9");
    state->u.f1.fld.pr.pr10 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR10");
    state->u.f1.fld.pr.pr11 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR11");
    state->u.f1.fld.pr.pr12 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR12");
    state->u.f1.fld.pr.pr13 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR13");
    state->u.f1.fld.pr.pr14 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR14");
    state->u.f1.fld.pr.pr15 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR15");
    state->u.f1.fld.pr.pr16 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR16");
    state->u.f1.fld.pr.pr17 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR17");
    state->u.f1.fld.pr.pr18 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR18");
}

// ----------------------------------------------------------------------------

// STM32F107VC
// DO NOT EDIT! Automatically generated!
static void stm32f107xx_exti_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32EXTIState *state = STM32_EXTI_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f1.reg.imr = cm_object_get_child_by_name(obj, "IMR");
    state->u.f1.reg.emr = cm_object_get_child_by_name(obj, "EMR");
    state->u.f1.reg.rtsr = cm_object_get_child_by_name(obj, "RTSR");
    state->u.f1.reg.ftsr = cm_object_get_child_by_name(obj, "FTSR");
    state->u.f1.reg.swier = cm_object_get_child_by_name(obj, "SWIER");
    state->u.f1.reg.pr = cm_object_get_child_by_name(obj, "PR");

    // IMR bitfields.
    state->u.f1.fld.imr.mr0 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR0");
    state->u.f1.fld.imr.mr1 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR1");
    state->u.f1.fld.imr.mr2 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR2");
    state->u.f1.fld.imr.mr3 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR3");
    state->u.f1.fld.imr.mr4 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR4");
    state->u.f1.fld.imr.mr5 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR5");
    state->u.f1.fld.imr.mr6 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR6");
    state->u.f1.fld.imr.mr7 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR7");
    state->u.f1.fld.imr.mr8 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR8");
    state->u.f1.fld.imr.mr9 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR9");
    state->u.f1.fld.imr.mr10 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR10");
    state->u.f1.fld.imr.mr11 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR11");
    state->u.f1.fld.imr.mr12 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR12");
    state->u.f1.fld.imr.mr13 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR13");
    state->u.f1.fld.imr.mr14 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR14");
    state->u.f1.fld.imr.mr15 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR15");
    state->u.f1.fld.imr.mr16 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR16");
    state->u.f1.fld.imr.mr17 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR17");
    state->u.f1.fld.imr.mr18 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR18");
    state->u.f1.fld.imr.mr19 = cm_object_get_child_by_name(state->u.f1.reg.imr,
            "MR19");

    // EMR bitfields.
    state->u.f1.fld.emr.mr0 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR0");
    state->u.f1.fld.emr.mr1 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR1");
    state->u.f1.fld.emr.mr2 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR2");
    state->u.f1.fld.emr.mr3 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR3");
    state->u.f1.fld.emr.mr4 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR4");
    state->u.f1.fld.emr.mr5 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR5");
    state->u.f1.fld.emr.mr6 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR6");
    state->u.f1.fld.emr.mr7 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR7");
    state->u.f1.fld.emr.mr8 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR8");
    state->u.f1.fld.emr.mr9 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR9");
    state->u.f1.fld.emr.mr10 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR10");
    state->u.f1.fld.emr.mr11 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR11");
    state->u.f1.fld.emr.mr12 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR12");
    state->u.f1.fld.emr.mr13 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR13");
    state->u.f1.fld.emr.mr14 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR14");
    state->u.f1.fld.emr.mr15 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR15");
    state->u.f1.fld.emr.mr16 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR16");
    state->u.f1.fld.emr.mr17 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR17");
    state->u.f1.fld.emr.mr18 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR18");
    state->u.f1.fld.emr.mr19 = cm_object_get_child_by_name(state->u.f1.reg.emr,
            "MR19");

    // RTSR bitfields.
    state->u.f1.fld.rtsr.tr0 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR0");
    state->u.f1.fld.rtsr.tr1 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR1");
    state->u.f1.fld.rtsr.tr2 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR2");
    state->u.f1.fld.rtsr.tr3 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR3");
    state->u.f1.fld.rtsr.tr4 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR4");
    state->u.f1.fld.rtsr.tr5 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR5");
    state->u.f1.fld.rtsr.tr6 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR6");
    state->u.f1.fld.rtsr.tr7 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR7");
    state->u.f1.fld.rtsr.tr8 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR8");
    state->u.f1.fld.rtsr.tr9 = cm_object_get_child_by_name(state->u.f1.reg.rtsr,
            "TR9");
    state->u.f1.fld.rtsr.tr10 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR10");
    state->u.f1.fld.rtsr.tr11 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR11");
    state->u.f1.fld.rtsr.tr12 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR12");
    state->u.f1.fld.rtsr.tr13 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR13");
    state->u.f1.fld.rtsr.tr14 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR14");
    state->u.f1.fld.rtsr.tr15 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR15");
    state->u.f1.fld.rtsr.tr16 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR16");
    state->u.f1.fld.rtsr.tr17 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR17");
    state->u.f1.fld.rtsr.tr18 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR18");
    state->u.f1.fld.rtsr.tr19 = cm_object_get_child_by_name(
            state->u.f1.reg.rtsr, "TR19");

    // FTSR bitfields.
    state->u.f1.fld.ftsr.tr0 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR0");
    state->u.f1.fld.ftsr.tr1 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR1");
    state->u.f1.fld.ftsr.tr2 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR2");
    state->u.f1.fld.ftsr.tr3 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR3");
    state->u.f1.fld.ftsr.tr4 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR4");
    state->u.f1.fld.ftsr.tr5 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR5");
    state->u.f1.fld.ftsr.tr6 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR6");
    state->u.f1.fld.ftsr.tr7 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR7");
    state->u.f1.fld.ftsr.tr8 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR8");
    state->u.f1.fld.ftsr.tr9 = cm_object_get_child_by_name(state->u.f1.reg.ftsr,
            "TR9");
    state->u.f1.fld.ftsr.tr10 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR10");
    state->u.f1.fld.ftsr.tr11 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR11");
    state->u.f1.fld.ftsr.tr12 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR12");
    state->u.f1.fld.ftsr.tr13 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR13");
    state->u.f1.fld.ftsr.tr14 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR14");
    state->u.f1.fld.ftsr.tr15 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR15");
    state->u.f1.fld.ftsr.tr16 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR16");
    state->u.f1.fld.ftsr.tr17 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR17");
    state->u.f1.fld.ftsr.tr18 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR18");
    state->u.f1.fld.ftsr.tr19 = cm_object_get_child_by_name(
            state->u.f1.reg.ftsr, "TR19");

    // SWIER bitfields.
    state->u.f1.fld.swier.swier0 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER0");
    state->u.f1.fld.swier.swier1 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER1");
    state->u.f1.fld.swier.swier2 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER2");
    state->u.f1.fld.swier.swier3 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER3");
    state->u.f1.fld.swier.swier4 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER4");
    state->u.f1.fld.swier.swier5 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER5");
    state->u.f1.fld.swier.swier6 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER6");
    state->u.f1.fld.swier.swier7 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER7");
    state->u.f1.fld.swier.swier8 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER8");
    state->u.f1.fld.swier.swier9 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER9");
    state->u.f1.fld.swier.swier10 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER10");
    state->u.f1.fld.swier.swier11 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER11");
    state->u.f1.fld.swier.swier12 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER12");
    state->u.f1.fld.swier.swier13 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER13");
    state->u.f1.fld.swier.swier14 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER14");
    state->u.f1.fld.swier.swier15 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER15");
    state->u.f1.fld.swier.swier16 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER16");
    state->u.f1.fld.swier.swier17 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER17");
    state->u.f1.fld.swier.swier18 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER18");
    state->u.f1.fld.swier.swier19 = cm_object_get_child_by_name(
            state->u.f1.reg.swier, "SWIER19");

    // PR bitfields.
    state->u.f1.fld.pr.pr0 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR0");
    state->u.f1.fld.pr.pr1 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR1");
    state->u.f1.fld.pr.pr2 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR2");
    state->u.f1.fld.pr.pr3 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR3");
    state->u.f1.fld.pr.pr4 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR4");
    state->u.f1.fld.pr.pr5 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR5");
    state->u.f1.fld.pr.pr6 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR6");
    state->u.f1.fld.pr.pr7 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR7");
    state->u.f1.fld.pr.pr8 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR8");
    state->u.f1.fld.pr.pr9 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR9");
    state->u.f1.fld.pr.pr10 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR10");
    state->u.f1.fld.pr.pr11 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR11");
    state->u.f1.fld.pr.pr12 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR12");
    state->u.f1.fld.pr.pr13 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR13");
    state->u.f1.fld.pr.pr14 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR14");
    state->u.f1.fld.pr.pr15 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR15");
    state->u.f1.fld.pr.pr16 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR16");
    state->u.f1.fld.pr.pr17 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR17");
    state->u.f1.fld.pr.pr18 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR18");
    state->u.f1.fld.pr.pr19 = cm_object_get_child_by_name(state->u.f1.reg.pr,
            "PR19");
}

// ----------------------------------------------------------------------------

// STM32F407VG, STM32F407ZG, STM32F405RG
// DO NOT EDIT! Automatically generated!
static void stm32f40x_exti_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32EXTIState *state = STM32_EXTI_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f4.reg.imr = cm_object_get_child_by_name(obj, "IMR");
    state->u.f4.reg.emr = cm_object_get_child_by_name(obj, "EMR");
    state->u.f4.reg.rtsr = cm_object_get_child_by_name(obj, "RTSR");
    state->u.f4.reg.ftsr = cm_object_get_child_by_name(obj, "FTSR");
    state->u.f4.reg.swier = cm_object_get_child_by_name(obj, "SWIER");
    state->u.f4.reg.pr = cm_object_get_child_by_name(obj, "PR");

    // IMR bitfields.
    state->u.f4.fld.imr.mr0 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR0");
    state->u.f4.fld.imr.mr1 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR1");
    state->u.f4.fld.imr.mr2 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR2");
    state->u.f4.fld.imr.mr3 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR3");
    state->u.f4.fld.imr.mr4 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR4");
    state->u.f4.fld.imr.mr5 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR5");
    state->u.f4.fld.imr.mr6 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR6");
    state->u.f4.fld.imr.mr7 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR7");
    state->u.f4.fld.imr.mr8 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR8");
    state->u.f4.fld.imr.mr9 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR9");
    state->u.f4.fld.imr.mr10 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR10");
    state->u.f4.fld.imr.mr11 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR11");
    state->u.f4.fld.imr.mr12 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR12");
    state->u.f4.fld.imr.mr13 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR13");
    state->u.f4.fld.imr.mr14 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR14");
    state->u.f4.fld.imr.mr15 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR15");
    state->u.f4.fld.imr.mr16 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR16");
    state->u.f4.fld.imr.mr17 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR17");
    state->u.f4.fld.imr.mr18 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR18");
    state->u.f4.fld.imr.mr19 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR19");
    state->u.f4.fld.imr.mr20 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR20");
    state->u.f4.fld.imr.mr21 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR21");
    state->u.f4.fld.imr.mr22 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR22");

    // EMR bitfields.
    state->u.f4.fld.emr.mr0 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR0");
    state->u.f4.fld.emr.mr1 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR1");
    state->u.f4.fld.emr.mr2 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR2");
    state->u.f4.fld.emr.mr3 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR3");
    state->u.f4.fld.emr.mr4 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR4");
    state->u.f4.fld.emr.mr5 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR5");
    state->u.f4.fld.emr.mr6 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR6");
    state->u.f4.fld.emr.mr7 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR7");
    state->u.f4.fld.emr.mr8 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR8");
    state->u.f4.fld.emr.mr9 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR9");
    state->u.f4.fld.emr.mr10 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR10");
    state->u.f4.fld.emr.mr11 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR11");
    state->u.f4.fld.emr.mr12 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR12");
    state->u.f4.fld.emr.mr13 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR13");
    state->u.f4.fld.emr.mr14 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR14");
    state->u.f4.fld.emr.mr15 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR15");
    state->u.f4.fld.emr.mr16 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR16");
    state->u.f4.fld.emr.mr17 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR17");
    state->u.f4.fld.emr.mr18 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR18");
    state->u.f4.fld.emr.mr19 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR19");
    state->u.f4.fld.emr.mr20 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR20");
    state->u.f4.fld.emr.mr21 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR21");
    state->u.f4.fld.emr.mr22 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR22");

    // RTSR bitfields.
    state->u.f4.fld.rtsr.tr0 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR0");
    state->u.f4.fld.rtsr.tr1 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR1");
    state->u.f4.fld.rtsr.tr2 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR2");
    state->u.f4.fld.rtsr.tr3 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR3");
    state->u.f4.fld.rtsr.tr4 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR4");
    state->u.f4.fld.rtsr.tr5 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR5");
    state->u.f4.fld.rtsr.tr6 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR6");
    state->u.f4.fld.rtsr.tr7 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR7");
    state->u.f4.fld.rtsr.tr8 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR8");
    state->u.f4.fld.rtsr.tr9 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR9");
    state->u.f4.fld.rtsr.tr10 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR10");
    state->u.f4.fld.rtsr.tr11 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR11");
    state->u.f4.fld.rtsr.tr12 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR12");
    state->u.f4.fld.rtsr.tr13 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR13");
    state->u.f4.fld.rtsr.tr14 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR14");
    state->u.f4.fld.rtsr.tr15 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR15");
    state->u.f4.fld.rtsr.tr16 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR16");
    state->u.f4.fld.rtsr.tr17 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR17");
    state->u.f4.fld.rtsr.tr18 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR18");
    state->u.f4.fld.rtsr.tr19 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR19");
    state->u.f4.fld.rtsr.tr20 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR20");
    state->u.f4.fld.rtsr.tr21 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR21");
    state->u.f4.fld.rtsr.tr22 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR22");

    // FTSR bitfields.
    state->u.f4.fld.ftsr.tr0 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR0");
    state->u.f4.fld.ftsr.tr1 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR1");
    state->u.f4.fld.ftsr.tr2 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR2");
    state->u.f4.fld.ftsr.tr3 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR3");
    state->u.f4.fld.ftsr.tr4 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR4");
    state->u.f4.fld.ftsr.tr5 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR5");
    state->u.f4.fld.ftsr.tr6 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR6");
    state->u.f4.fld.ftsr.tr7 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR7");
    state->u.f4.fld.ftsr.tr8 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR8");
    state->u.f4.fld.ftsr.tr9 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR9");
    state->u.f4.fld.ftsr.tr10 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR10");
    state->u.f4.fld.ftsr.tr11 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR11");
    state->u.f4.fld.ftsr.tr12 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR12");
    state->u.f4.fld.ftsr.tr13 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR13");
    state->u.f4.fld.ftsr.tr14 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR14");
    state->u.f4.fld.ftsr.tr15 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR15");
    state->u.f4.fld.ftsr.tr16 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR16");
    state->u.f4.fld.ftsr.tr17 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR17");
    state->u.f4.fld.ftsr.tr18 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR18");
    state->u.f4.fld.ftsr.tr19 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR19");
    state->u.f4.fld.ftsr.tr20 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR20");
    state->u.f4.fld.ftsr.tr21 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR21");
    state->u.f4.fld.ftsr.tr22 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR22");

    // SWIER bitfields.
    state->u.f4.fld.swier.swier0 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER0");
    state->u.f4.fld.swier.swier1 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER1");
    state->u.f4.fld.swier.swier2 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER2");
    state->u.f4.fld.swier.swier3 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER3");
    state->u.f4.fld.swier.swier4 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER4");
    state->u.f4.fld.swier.swier5 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER5");
    state->u.f4.fld.swier.swier6 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER6");
    state->u.f4.fld.swier.swier7 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER7");
    state->u.f4.fld.swier.swier8 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER8");
    state->u.f4.fld.swier.swier9 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER9");
    state->u.f4.fld.swier.swier10 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER10");
    state->u.f4.fld.swier.swier11 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER11");
    state->u.f4.fld.swier.swier12 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER12");
    state->u.f4.fld.swier.swier13 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER13");
    state->u.f4.fld.swier.swier14 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER14");
    state->u.f4.fld.swier.swier15 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER15");
    state->u.f4.fld.swier.swier16 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER16");
    state->u.f4.fld.swier.swier17 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER17");
    state->u.f4.fld.swier.swier18 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER18");
    state->u.f4.fld.swier.swier19 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER19");
    state->u.f4.fld.swier.swier20 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER20");
    state->u.f4.fld.swier.swier21 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER21");
    state->u.f4.fld.swier.swier22 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER22");

    // PR bitfields.
    state->u.f4.fld.pr.pr0 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR0");
    state->u.f4.fld.pr.pr1 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR1");
    state->u.f4.fld.pr.pr2 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR2");
    state->u.f4.fld.pr.pr3 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR3");
    state->u.f4.fld.pr.pr4 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR4");
    state->u.f4.fld.pr.pr5 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR5");
    state->u.f4.fld.pr.pr6 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR6");
    state->u.f4.fld.pr.pr7 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR7");
    state->u.f4.fld.pr.pr8 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR8");
    state->u.f4.fld.pr.pr9 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR9");
    state->u.f4.fld.pr.pr10 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR10");
    state->u.f4.fld.pr.pr11 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR11");
    state->u.f4.fld.pr.pr12 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR12");
    state->u.f4.fld.pr.pr13 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR13");
    state->u.f4.fld.pr.pr14 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR14");
    state->u.f4.fld.pr.pr15 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR15");
    state->u.f4.fld.pr.pr16 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR16");
    state->u.f4.fld.pr.pr17 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR17");
    state->u.f4.fld.pr.pr18 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR18");
    state->u.f4.fld.pr.pr19 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR19");
    state->u.f4.fld.pr.pr20 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR20");
    state->u.f4.fld.pr.pr21 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR21");
    state->u.f4.fld.pr.pr22 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR22");
}

// ----------------------------------------------------------------------------

// STM32F411RE
// DO NOT EDIT! Automatically generated!
static void stm32f411xx_exti_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32EXTIState *state = STM32_EXTI_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f4.reg.imr = cm_object_get_child_by_name(obj, "IMR");
    state->u.f4.reg.emr = cm_object_get_child_by_name(obj, "EMR");
    state->u.f4.reg.rtsr = cm_object_get_child_by_name(obj, "RTSR");
    state->u.f4.reg.ftsr = cm_object_get_child_by_name(obj, "FTSR");
    state->u.f4.reg.swier = cm_object_get_child_by_name(obj, "SWIER");
    state->u.f4.reg.pr = cm_object_get_child_by_name(obj, "PR");

    // IMR bitfields.
    state->u.f4.fld.imr.mr0 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR0");
    state->u.f4.fld.imr.mr1 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR1");
    state->u.f4.fld.imr.mr2 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR2");
    state->u.f4.fld.imr.mr3 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR3");
    state->u.f4.fld.imr.mr4 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR4");
    state->u.f4.fld.imr.mr5 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR5");
    state->u.f4.fld.imr.mr6 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR6");
    state->u.f4.fld.imr.mr7 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR7");
    state->u.f4.fld.imr.mr8 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR8");
    state->u.f4.fld.imr.mr9 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR9");
    state->u.f4.fld.imr.mr10 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR10");
    state->u.f4.fld.imr.mr11 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR11");
    state->u.f4.fld.imr.mr12 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR12");
    state->u.f4.fld.imr.mr13 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR13");
    state->u.f4.fld.imr.mr14 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR14");
    state->u.f4.fld.imr.mr15 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR15");
    state->u.f4.fld.imr.mr16 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR16");
    state->u.f4.fld.imr.mr17 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR17");
    state->u.f4.fld.imr.mr18 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR18");
    state->u.f4.fld.imr.mr19 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR19");
    state->u.f4.fld.imr.mr20 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR20");
    state->u.f4.fld.imr.mr21 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR21");
    state->u.f4.fld.imr.mr22 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR22");

    // EMR bitfields.
    state->u.f4.fld.emr.mr0 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR0");
    state->u.f4.fld.emr.mr1 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR1");
    state->u.f4.fld.emr.mr2 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR2");
    state->u.f4.fld.emr.mr3 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR3");
    state->u.f4.fld.emr.mr4 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR4");
    state->u.f4.fld.emr.mr5 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR5");
    state->u.f4.fld.emr.mr6 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR6");
    state->u.f4.fld.emr.mr7 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR7");
    state->u.f4.fld.emr.mr8 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR8");
    state->u.f4.fld.emr.mr9 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR9");
    state->u.f4.fld.emr.mr10 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR10");
    state->u.f4.fld.emr.mr11 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR11");
    state->u.f4.fld.emr.mr12 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR12");
    state->u.f4.fld.emr.mr13 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR13");
    state->u.f4.fld.emr.mr14 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR14");
    state->u.f4.fld.emr.mr15 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR15");
    state->u.f4.fld.emr.mr16 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR16");
    state->u.f4.fld.emr.mr17 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR17");
    state->u.f4.fld.emr.mr18 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR18");
    state->u.f4.fld.emr.mr19 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR19");
    state->u.f4.fld.emr.mr20 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR20");
    state->u.f4.fld.emr.mr21 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR21");
    state->u.f4.fld.emr.mr22 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR22");

    // RTSR bitfields.
    state->u.f4.fld.rtsr.tr0 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR0");
    state->u.f4.fld.rtsr.tr1 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR1");
    state->u.f4.fld.rtsr.tr2 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR2");
    state->u.f4.fld.rtsr.tr3 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR3");
    state->u.f4.fld.rtsr.tr4 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR4");
    state->u.f4.fld.rtsr.tr5 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR5");
    state->u.f4.fld.rtsr.tr6 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR6");
    state->u.f4.fld.rtsr.tr7 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR7");
    state->u.f4.fld.rtsr.tr8 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR8");
    state->u.f4.fld.rtsr.tr9 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR9");
    state->u.f4.fld.rtsr.tr10 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR10");
    state->u.f4.fld.rtsr.tr11 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR11");
    state->u.f4.fld.rtsr.tr12 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR12");
    state->u.f4.fld.rtsr.tr13 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR13");
    state->u.f4.fld.rtsr.tr14 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR14");
    state->u.f4.fld.rtsr.tr15 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR15");
    state->u.f4.fld.rtsr.tr16 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR16");
    state->u.f4.fld.rtsr.tr17 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR17");
    state->u.f4.fld.rtsr.tr18 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR18");
    state->u.f4.fld.rtsr.tr19 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR19");
    state->u.f4.fld.rtsr.tr20 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR20");
    state->u.f4.fld.rtsr.tr21 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR21");
    state->u.f4.fld.rtsr.tr22 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR22");

    // FTSR bitfields.
    state->u.f4.fld.ftsr.tr0 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR0");
    state->u.f4.fld.ftsr.tr1 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR1");
    state->u.f4.fld.ftsr.tr2 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR2");
    state->u.f4.fld.ftsr.tr3 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR3");
    state->u.f4.fld.ftsr.tr4 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR4");
    state->u.f4.fld.ftsr.tr5 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR5");
    state->u.f4.fld.ftsr.tr6 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR6");
    state->u.f4.fld.ftsr.tr7 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR7");
    state->u.f4.fld.ftsr.tr8 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR8");
    state->u.f4.fld.ftsr.tr9 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR9");
    state->u.f4.fld.ftsr.tr10 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR10");
    state->u.f4.fld.ftsr.tr11 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR11");
    state->u.f4.fld.ftsr.tr12 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR12");
    state->u.f4.fld.ftsr.tr13 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR13");
    state->u.f4.fld.ftsr.tr14 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR14");
    state->u.f4.fld.ftsr.tr15 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR15");
    state->u.f4.fld.ftsr.tr16 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR16");
    state->u.f4.fld.ftsr.tr17 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR17");
    state->u.f4.fld.ftsr.tr18 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR18");
    state->u.f4.fld.ftsr.tr19 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR19");
    state->u.f4.fld.ftsr.tr20 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR20");
    state->u.f4.fld.ftsr.tr21 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR21");
    state->u.f4.fld.ftsr.tr22 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR22");

    // SWIER bitfields.
    state->u.f4.fld.swier.swier0 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER0");
    state->u.f4.fld.swier.swier1 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER1");
    state->u.f4.fld.swier.swier2 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER2");
    state->u.f4.fld.swier.swier3 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER3");
    state->u.f4.fld.swier.swier4 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER4");
    state->u.f4.fld.swier.swier5 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER5");
    state->u.f4.fld.swier.swier6 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER6");
    state->u.f4.fld.swier.swier7 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER7");
    state->u.f4.fld.swier.swier8 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER8");
    state->u.f4.fld.swier.swier9 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER9");
    state->u.f4.fld.swier.swier10 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER10");
    state->u.f4.fld.swier.swier11 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER11");
    state->u.f4.fld.swier.swier12 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER12");
    state->u.f4.fld.swier.swier13 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER13");
    state->u.f4.fld.swier.swier14 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER14");
    state->u.f4.fld.swier.swier15 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER15");
    state->u.f4.fld.swier.swier16 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER16");
    state->u.f4.fld.swier.swier17 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER17");
    state->u.f4.fld.swier.swier18 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER18");
    state->u.f4.fld.swier.swier19 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER19");
    state->u.f4.fld.swier.swier20 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER20");
    state->u.f4.fld.swier.swier21 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER21");
    state->u.f4.fld.swier.swier22 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER22");

    // PR bitfields.
    state->u.f4.fld.pr.pr0 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR0");
    state->u.f4.fld.pr.pr1 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR1");
    state->u.f4.fld.pr.pr2 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR2");
    state->u.f4.fld.pr.pr3 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR3");
    state->u.f4.fld.pr.pr4 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR4");
    state->u.f4.fld.pr.pr5 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR5");
    state->u.f4.fld.pr.pr6 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR6");
    state->u.f4.fld.pr.pr7 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR7");
    state->u.f4.fld.pr.pr8 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR8");
    state->u.f4.fld.pr.pr9 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR9");
    state->u.f4.fld.pr.pr10 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR10");
    state->u.f4.fld.pr.pr11 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR11");
    state->u.f4.fld.pr.pr12 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR12");
    state->u.f4.fld.pr.pr13 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR13");
    state->u.f4.fld.pr.pr14 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR14");
    state->u.f4.fld.pr.pr15 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR15");
    state->u.f4.fld.pr.pr16 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR16");
    state->u.f4.fld.pr.pr17 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR17");
    state->u.f4.fld.pr.pr18 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR18");
    state->u.f4.fld.pr.pr19 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR19");
    state->u.f4.fld.pr.pr20 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR20");
    state->u.f4.fld.pr.pr21 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR21");
    state->u.f4.fld.pr.pr22 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR22");
}

// ----------------------------------------------------------------------------

// STM32F429ZI
// DO NOT EDIT! Automatically generated!
static void stm32f429x_exti_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32EXTIState *state = STM32_EXTI_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f4.reg.imr = cm_object_get_child_by_name(obj, "IMR");
    state->u.f4.reg.emr = cm_object_get_child_by_name(obj, "EMR");
    state->u.f4.reg.rtsr = cm_object_get_child_by_name(obj, "RTSR");
    state->u.f4.reg.ftsr = cm_object_get_child_by_name(obj, "FTSR");
    state->u.f4.reg.swier = cm_object_get_child_by_name(obj, "SWIER");
    state->u.f4.reg.pr = cm_object_get_child_by_name(obj, "PR");

    // IMR bitfields.
    state->u.f4.fld.imr.mr0 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR0");
    state->u.f4.fld.imr.mr1 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR1");
    state->u.f4.fld.imr.mr2 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR2");
    state->u.f4.fld.imr.mr3 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR3");
    state->u.f4.fld.imr.mr4 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR4");
    state->u.f4.fld.imr.mr5 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR5");
    state->u.f4.fld.imr.mr6 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR6");
    state->u.f4.fld.imr.mr7 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR7");
    state->u.f4.fld.imr.mr8 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR8");
    state->u.f4.fld.imr.mr9 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR9");
    state->u.f4.fld.imr.mr10 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR10");
    state->u.f4.fld.imr.mr11 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR11");
    state->u.f4.fld.imr.mr12 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR12");
    state->u.f4.fld.imr.mr13 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR13");
    state->u.f4.fld.imr.mr14 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR14");
    state->u.f4.fld.imr.mr15 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR15");
    state->u.f4.fld.imr.mr16 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR16");
    state->u.f4.fld.imr.mr17 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR17");
    state->u.f4.fld.imr.mr18 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR18");
    state->u.f4.fld.imr.mr19 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR19");
    state->u.f4.fld.imr.mr20 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR20");
    state->u.f4.fld.imr.mr21 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR21");
    state->u.f4.fld.imr.mr22 = cm_object_get_child_by_name(state->u.f4.reg.imr,
            "MR22");

    // EMR bitfields.
    state->u.f4.fld.emr.mr0 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR0");
    state->u.f4.fld.emr.mr1 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR1");
    state->u.f4.fld.emr.mr2 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR2");
    state->u.f4.fld.emr.mr3 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR3");
    state->u.f4.fld.emr.mr4 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR4");
    state->u.f4.fld.emr.mr5 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR5");
    state->u.f4.fld.emr.mr6 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR6");
    state->u.f4.fld.emr.mr7 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR7");
    state->u.f4.fld.emr.mr8 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR8");
    state->u.f4.fld.emr.mr9 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR9");
    state->u.f4.fld.emr.mr10 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR10");
    state->u.f4.fld.emr.mr11 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR11");
    state->u.f4.fld.emr.mr12 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR12");
    state->u.f4.fld.emr.mr13 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR13");
    state->u.f4.fld.emr.mr14 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR14");
    state->u.f4.fld.emr.mr15 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR15");
    state->u.f4.fld.emr.mr16 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR16");
    state->u.f4.fld.emr.mr17 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR17");
    state->u.f4.fld.emr.mr18 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR18");
    state->u.f4.fld.emr.mr19 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR19");
    state->u.f4.fld.emr.mr20 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR20");
    state->u.f4.fld.emr.mr21 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR21");
    state->u.f4.fld.emr.mr22 = cm_object_get_child_by_name(state->u.f4.reg.emr,
            "MR22");

    // RTSR bitfields.
    state->u.f4.fld.rtsr.tr0 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR0");
    state->u.f4.fld.rtsr.tr1 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR1");
    state->u.f4.fld.rtsr.tr2 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR2");
    state->u.f4.fld.rtsr.tr3 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR3");
    state->u.f4.fld.rtsr.tr4 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR4");
    state->u.f4.fld.rtsr.tr5 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR5");
    state->u.f4.fld.rtsr.tr6 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR6");
    state->u.f4.fld.rtsr.tr7 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR7");
    state->u.f4.fld.rtsr.tr8 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR8");
    state->u.f4.fld.rtsr.tr9 = cm_object_get_child_by_name(state->u.f4.reg.rtsr,
            "TR9");
    state->u.f4.fld.rtsr.tr10 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR10");
    state->u.f4.fld.rtsr.tr11 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR11");
    state->u.f4.fld.rtsr.tr12 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR12");
    state->u.f4.fld.rtsr.tr13 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR13");
    state->u.f4.fld.rtsr.tr14 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR14");
    state->u.f4.fld.rtsr.tr15 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR15");
    state->u.f4.fld.rtsr.tr16 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR16");
    state->u.f4.fld.rtsr.tr17 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR17");
    state->u.f4.fld.rtsr.tr18 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR18");
    state->u.f4.fld.rtsr.tr19 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR19");
    state->u.f4.fld.rtsr.tr20 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR20");
    state->u.f4.fld.rtsr.tr21 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR21");
    state->u.f4.fld.rtsr.tr22 = cm_object_get_child_by_name(
            state->u.f4.reg.rtsr, "TR22");

    // FTSR bitfields.
    state->u.f4.fld.ftsr.tr0 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR0");
    state->u.f4.fld.ftsr.tr1 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR1");
    state->u.f4.fld.ftsr.tr2 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR2");
    state->u.f4.fld.ftsr.tr3 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR3");
    state->u.f4.fld.ftsr.tr4 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR4");
    state->u.f4.fld.ftsr.tr5 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR5");
    state->u.f4.fld.ftsr.tr6 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR6");
    state->u.f4.fld.ftsr.tr7 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR7");
    state->u.f4.fld.ftsr.tr8 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR8");
    state->u.f4.fld.ftsr.tr9 = cm_object_get_child_by_name(state->u.f4.reg.ftsr,
            "TR9");
    state->u.f4.fld.ftsr.tr10 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR10");
    state->u.f4.fld.ftsr.tr11 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR11");
    state->u.f4.fld.ftsr.tr12 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR12");
    state->u.f4.fld.ftsr.tr13 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR13");
    state->u.f4.fld.ftsr.tr14 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR14");
    state->u.f4.fld.ftsr.tr15 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR15");
    state->u.f4.fld.ftsr.tr16 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR16");
    state->u.f4.fld.ftsr.tr17 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR17");
    state->u.f4.fld.ftsr.tr18 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR18");
    state->u.f4.fld.ftsr.tr19 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR19");
    state->u.f4.fld.ftsr.tr20 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR20");
    state->u.f4.fld.ftsr.tr21 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR21");
    state->u.f4.fld.ftsr.tr22 = cm_object_get_child_by_name(
            state->u.f4.reg.ftsr, "TR22");

    // SWIER bitfields.
    state->u.f4.fld.swier.swier0 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER0");
    state->u.f4.fld.swier.swier1 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER1");
    state->u.f4.fld.swier.swier2 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER2");
    state->u.f4.fld.swier.swier3 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER3");
    state->u.f4.fld.swier.swier4 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER4");
    state->u.f4.fld.swier.swier5 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER5");
    state->u.f4.fld.swier.swier6 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER6");
    state->u.f4.fld.swier.swier7 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER7");
    state->u.f4.fld.swier.swier8 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER8");
    state->u.f4.fld.swier.swier9 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER9");
    state->u.f4.fld.swier.swier10 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER10");
    state->u.f4.fld.swier.swier11 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER11");
    state->u.f4.fld.swier.swier12 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER12");
    state->u.f4.fld.swier.swier13 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER13");
    state->u.f4.fld.swier.swier14 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER14");
    state->u.f4.fld.swier.swier15 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER15");
    state->u.f4.fld.swier.swier16 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER16");
    state->u.f4.fld.swier.swier17 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER17");
    state->u.f4.fld.swier.swier18 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER18");
    state->u.f4.fld.swier.swier19 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER19");
    state->u.f4.fld.swier.swier20 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER20");
    state->u.f4.fld.swier.swier21 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER21");
    state->u.f4.fld.swier.swier22 = cm_object_get_child_by_name(
            state->u.f4.reg.swier, "SWIER22");

    // PR bitfields.
    state->u.f4.fld.pr.pr0 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR0");
    state->u.f4.fld.pr.pr1 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR1");
    state->u.f4.fld.pr.pr2 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR2");
    state->u.f4.fld.pr.pr3 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR3");
    state->u.f4.fld.pr.pr4 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR4");
    state->u.f4.fld.pr.pr5 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR5");
    state->u.f4.fld.pr.pr6 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR6");
    state->u.f4.fld.pr.pr7 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR7");
    state->u.f4.fld.pr.pr8 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR8");
    state->u.f4.fld.pr.pr9 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR9");
    state->u.f4.fld.pr.pr10 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR10");
    state->u.f4.fld.pr.pr11 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR11");
    state->u.f4.fld.pr.pr12 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR12");
    state->u.f4.fld.pr.pr13 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR13");
    state->u.f4.fld.pr.pr14 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR14");
    state->u.f4.fld.pr.pr15 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR15");
    state->u.f4.fld.pr.pr16 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR16");
    state->u.f4.fld.pr.pr17 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR17");
    state->u.f4.fld.pr.pr18 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR18");
    state->u.f4.fld.pr.pr19 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR19");
    state->u.f4.fld.pr.pr20 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR20");
    state->u.f4.fld.pr.pr21 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR21");
    state->u.f4.fld.pr.pr22 = cm_object_get_child_by_name(state->u.f4.reg.pr,
            "PR22");
}

// ----- Private --------------------------------------------------------------

// Called for each pin changed in the board (like buttons)
// and for GPIO output changes.

static void stm32_exti_in_irq_handler(void *opaque, int index, int level)
{
    qemu_log_mask(LOG_FUNC, "%s(%d,%d) \n", __FUNCTION__, index, level);

    STM32EXTIState *state = STM32_EXTI_STATE(opaque);
    assert(index < STM32_EXTI_MAX_NUM);
    uint32_t mask = (1 << index);

    if ((peripheral_register_read_value(state->reg.imr) & mask) != 0) {
        if (((level
                && ((peripheral_register_read_value(state->reg.rtsr) & mask)
                        != 0))
                || (!level
                        && ((peripheral_register_read_value(state->reg.ftsr)
                                & mask) != 0)))) {

            // Set the corresponding bit in the pending register.
            // Must be cleared by the application when the interrupt
            // is acknowledged.
            peripheral_register_or_raw_value(state->reg.pr, mask);

#if 0
            qemu_log_mask(LOG_FUNC, "%s(%d,%d) nvic\n", __FUNCTION__,
                    index, level);
#endif

            // Raise the outgoing interrupt, connected to NVIC.
            cm_irq_raise(state->irq_out[index]);
        }
    }
}

// Pass only bits corresponding to enabled interrupts.
static peripheral_register_t stm32_exti_swier_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32EXTIState *state = STM32_EXTI_STATE(periph);
    peripheral_register_t imr_value = peripheral_register_read_value(
            state->reg.imr);

    return (full_value & imr_value);
}

// Set pending bits programmatically. Raising bits pend interrupts.
// Lowering bits does nothing.

static void stm32_exti_swier_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32EXTIState *state = STM32_EXTI_STATE(periph);
    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(
            reg);
    // Bits that were 0 and now are 1.
    uint32_t raised = (~prev_value) & full_value;

    uint32_t mask = 1;
    int i;
    for (i = 0; i < state->num_exti; ++i, mask <<= 1) {
        if ((raised & mask) != 0) {
            stm32_exti_in_irq_handler(reg, i, 1);
        }
    }
}

// Implement 'rc_w1', clear bits by writing 1.

static peripheral_register_t stm32_exti_pr_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32EXTIState *state = STM32_EXTI_STATE(periph);
    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(
            state->reg.pr);

    peripheral_register_t imr_value = peripheral_register_read_value(
            state->reg.imr);

    // Compute enabled bits that were 1 and were requested to clear.
    uint32_t acknowledged = (imr_value & prev_value & full_value);

    uint32_t mask = 1;
    int i;
    for (i = 0; i < state->num_exti; ++i, mask <<= 1) {
        if ((acknowledged & mask) != 0) {
#if 0
            qemu_log_mask(LOG_FUNC, "%s() %d exti ack\n", __FUNCTION__, i);
#endif
            // Notify NVIC that the interrupt was acknowledged.
            cm_irq_lower(state->irq_out[i]);
        }
    }

    // Clear bits.
    return (prev_value & (~full_value));
}

// ----------------------------------------------------------------------------

static void stm32_exti_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32EXTIState *state = STM32_EXTI_STATE(obj);

    cm_object_property_add_uint32(obj, "num_exti", &state->num_exti);
    state->num_exti = 0;

    // capabilities are not yet available.

    // Incoming interrupts. There is only one set of incoming,
    // all GPIOs are connected here, but each pin can have only
    // one source. To simplify things (hopefully), the multiplexer
    // is implemented in each GPIO.

    cm_irq_init_in(DEVICE(obj), stm32_exti_in_irq_handler, STM32_IRQ_EXTI_IN,
    STM32_EXTI_MAX_NUM);

    // Outgoing interrupts, will be later connected to NVIC.

    cm_irq_init_out(DEVICE(obj), state->irq_out, STM32_IRQ_EXTI_OUT,
    STM32_EXTI_MAX_NUM);

    state->reg.imr = NULL;
    state->reg.emr = NULL;
    state->reg.rtsr = NULL;
    state->reg.ftsr = NULL;
    state->reg.swier = NULL;
    state->reg.pr = NULL;
}

static void stm32_exti_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_EXTI)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32EXTIState *state = STM32_EXTI_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "EXTI";
    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    assert(
            capabilities->num_exti > 0 && capabilities->num_exti <= STM32_EXTI_MAX_NUM);
    cm_object_property_set_int(obj, capabilities->num_exti, "num_exti");

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x1) {

            stm32f0x1_exti_create_objects(obj, cm_state->svd_json, periph_name);

            state->reg.imr = state->u.f0.reg.imr;
            state->reg.emr = state->u.f0.reg.emr;
            state->reg.rtsr = state->u.f0.reg.rtsr;
            state->reg.ftsr = state->u.f0.reg.ftsr;
            state->reg.swier = state->u.f0.reg.swier;
            state->reg.pr = state->u.f0.reg.pr;

        } else {
            assert(false);
        }
        break;

    case STM32_FAMILY_F1:

        if (capabilities->f1.is_103xx) {

            stm32f103xx_exti_create_objects(obj, cm_state->svd_json,
                    periph_name);

        } else if (capabilities->f1.is_107xx) {

            stm32f107xx_exti_create_objects(obj, cm_state->svd_json,
                    periph_name);

        } else {
            assert(false);
        }

        state->reg.imr = state->u.f1.reg.imr;
        state->reg.emr = state->u.f1.reg.emr;
        state->reg.rtsr = state->u.f1.reg.rtsr;
        state->reg.ftsr = state->u.f1.reg.ftsr;
        state->reg.swier = state->u.f1.reg.swier;
        state->reg.pr = state->u.f1.reg.pr;

        break;

    case STM32_FAMILY_F4:

        if (capabilities->f4.is_40x) {

            stm32f40x_exti_create_objects(obj, cm_state->svd_json, periph_name);

        } else if (capabilities->f4.is_411xx) {

            stm32f411xx_exti_create_objects(obj, cm_state->svd_json,
                    periph_name);

        } else if (capabilities->f4.is_429x) {

            stm32f429x_exti_create_objects(obj, cm_state->svd_json,
                    periph_name);

        } else {
            assert(false);
        }

        state->reg.imr = state->u.f4.reg.imr;
        state->reg.emr = state->u.f4.reg.emr;
        state->reg.rtsr = state->u.f4.reg.rtsr;
        state->reg.ftsr = state->u.f4.reg.ftsr;
        state->reg.swier = state->u.f4.reg.swier;
        state->reg.pr = state->u.f4.reg.pr;

        break;

    default:
        break;
    }

    peripheral_register_set_pre_write(state->reg.swier,
            stm32_exti_swier_pre_write_callback);
    peripheral_register_set_post_write(state->reg.swier,
            stm32_exti_swier_post_write_callback);

    peripheral_register_set_pre_write(state->reg.pr,
            stm32_exti_pr_pre_write_callback);

    DeviceState *nvic = DEVICE(cm_device_by_name(DEVICE_PATH_CORTEXM_NVIC));

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x1) {
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 0, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI0_1_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 1, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI0_1_IRQn);

            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 2, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI2_3_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 3, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI2_3_IRQn);

            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 4, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 5, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 6, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 7, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 8, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 9, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 10, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 11, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 12, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 13, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 14, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 15, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);

            // TODO add 16 - 23;

        }
        break;

    case STM32_FAMILY_F1:

        if (capabilities->f1.is_md || capabilities->f1.is_cl) {

            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 0, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI0_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 1, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI1_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 2, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI2_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 3, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI3_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 4, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI4_IRQn);

            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 5, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI9_5_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 6, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI9_5_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 7, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI9_5_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 8, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI9_5_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 9, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI9_5_IRQn);

            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 10, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 11, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 12, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 13, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 14, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 15, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI15_10_IRQn);

            // TODO add 16 - 20; if different for STM32F10X_CL, extend if
        }

        break;

    case STM32_FAMILY_F4:

        if (capabilities->f4.is_40x) {

            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 0, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI0_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 1, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI1_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 2, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI2_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 3, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI3_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 4, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI4_IRQn);

            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 5, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI9_5_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 6, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI9_5_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 7, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI9_5_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 8, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI9_5_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 9, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI9_5_IRQn);

            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 10, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 11, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 12, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 13, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 14, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 15, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI15_10_IRQn);

            // TODO add 16 - 22; if different for STM32F4_23_XX, extend if

        } else if (capabilities->f4.is_429x) {

            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 0, nvic, IRQ_NVIC_IN,
                    STM32F429X_EXTI0_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 1, nvic, IRQ_NVIC_IN,
                    STM32F429X_EXTI1_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 2, nvic, IRQ_NVIC_IN,
                    STM32F429X_EXTI2_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 3, nvic, IRQ_NVIC_IN,
                    STM32F429X_EXTI3_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 4, nvic, IRQ_NVIC_IN,
                    STM32F429X_EXTI4_IRQn);

            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 5, nvic, IRQ_NVIC_IN,
                    STM32F429X_EXTI9_5_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 6, nvic, IRQ_NVIC_IN,
                    STM32F429X_EXTI9_5_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 7, nvic, IRQ_NVIC_IN,
                    STM32F429X_EXTI9_5_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 8, nvic, IRQ_NVIC_IN,
                    STM32F429X_EXTI9_5_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 9, nvic, IRQ_NVIC_IN,
                    STM32F429X_EXTI9_5_IRQn);

            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 10, nvic, IRQ_NVIC_IN,
                    STM32F429X_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 11, nvic, IRQ_NVIC_IN,
                    STM32F429X_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 12, nvic, IRQ_NVIC_IN,
                    STM32F429X_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 13, nvic, IRQ_NVIC_IN,
                    STM32F429X_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 14, nvic, IRQ_NVIC_IN,
                    STM32F429X_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 15, nvic, IRQ_NVIC_IN,
                    STM32F429X_EXTI15_10_IRQn);

            // TODO add 16 - 22; if different for STM32F4_23_XX, extend if

        } else if (capabilities->f4.is_411xx) {

            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 0, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI0_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 1, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI1_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 2, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI2_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 3, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI3_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 4, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI4_IRQn);

            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 5, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI9_5_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 6, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI9_5_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 7, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI9_5_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 8, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI9_5_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 9, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI9_5_IRQn);

            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 10, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 11, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 12, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 13, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 14, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, STM32_IRQ_EXTI_OUT, 15, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI15_10_IRQn);

            // TODO add 16,17,18,21,22
        }

        break;

    default:
        break;
    }

    peripheral_prepare_registers(obj);
}

static void stm32_exti_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset().
    cm_device_parent_reset(dev, TYPE_STM32_EXTI);
}

static void stm32_exti_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_exti_reset_callback;
    dc->realize = stm32_exti_realize_callback;
}

static const TypeInfo stm32_exti_type_info = {
    .name = TYPE_STM32_EXTI,
    .parent = TYPE_STM32_EXTI_PARENT,
    .instance_init = stm32_exti_instance_init_callback,
    .instance_size = sizeof(STM32EXTIState),
    .class_init = stm32_exti_class_init_callback,
    .class_size = sizeof(STM32EXTIClass)
/**/
};

static void stm32_exti_register_types(void)
{
    type_register_static(&stm32_exti_type_info);
}

type_init(stm32_exti_register_types);

/* ------------------------------------------------------------------------- */

