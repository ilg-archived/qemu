/*
 * STM32 MCU - GPIO emulation.
 *
 * Copyright (c) 2015 Liviu Ionescu.
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

#include <hw/cortexm/stm32/gpio.h>
#include <hw/cortexm/stm32/exti.h>
#include <hw/cortexm/stm32/syscfg.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

#include "qemu/bitops.h"

/*
 * This file implements the STM32 GPIO device.
 *
 * The implementation is more or less complete, with interrupts ready to
 * be used by LEDs & buttons.
 *
 * A read access to the Output Data register gets the last written value
 * while in output mode (not only in Push-Pull mode as specified in the
 * ST manual.
 *
 * TODO: add a separate mask to know when in push-pull output mode.
 *
 */

// ----- Generated code -------------------------------------------------------
//
// STM32F051R8
// DO NOT EDIT! Automatically generated!
static void stm32f0x1_gpio_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f0.reg.moder = cm_object_get_child_by_name(obj, "MODER");
    state->u.f0.reg.otyper = cm_object_get_child_by_name(obj, "OTYPER");
    state->u.f0.reg.ospeedr = cm_object_get_child_by_name(obj, "OSPEEDR");
    state->u.f0.reg.pupdr = cm_object_get_child_by_name(obj, "PUPDR");
    state->u.f0.reg.idr = cm_object_get_child_by_name(obj, "IDR");
    state->u.f0.reg.odr = cm_object_get_child_by_name(obj, "ODR");
    state->u.f0.reg.bsrr = cm_object_get_child_by_name(obj, "BSRR");
    state->u.f0.reg.lckr = cm_object_get_child_by_name(obj, "LCKR");
    state->u.f0.reg.afrl = cm_object_get_child_by_name(obj, "AFRL");
    state->u.f0.reg.afrh = cm_object_get_child_by_name(obj, "AFRH");
    state->u.f0.reg.brr = cm_object_get_child_by_name(obj, "BRR");

    // MODER bitfields.
    state->u.f0.fld.moder.moder0 = cm_object_get_child_by_name(
            state->u.f0.reg.moder, "MODER0");
    state->u.f0.fld.moder.moder1 = cm_object_get_child_by_name(
            state->u.f0.reg.moder, "MODER1");
    state->u.f0.fld.moder.moder2 = cm_object_get_child_by_name(
            state->u.f0.reg.moder, "MODER2");
    state->u.f0.fld.moder.moder3 = cm_object_get_child_by_name(
            state->u.f0.reg.moder, "MODER3");
    state->u.f0.fld.moder.moder4 = cm_object_get_child_by_name(
            state->u.f0.reg.moder, "MODER4");
    state->u.f0.fld.moder.moder5 = cm_object_get_child_by_name(
            state->u.f0.reg.moder, "MODER5");
    state->u.f0.fld.moder.moder6 = cm_object_get_child_by_name(
            state->u.f0.reg.moder, "MODER6");
    state->u.f0.fld.moder.moder7 = cm_object_get_child_by_name(
            state->u.f0.reg.moder, "MODER7");
    state->u.f0.fld.moder.moder8 = cm_object_get_child_by_name(
            state->u.f0.reg.moder, "MODER8");
    state->u.f0.fld.moder.moder9 = cm_object_get_child_by_name(
            state->u.f0.reg.moder, "MODER9");
    state->u.f0.fld.moder.moder10 = cm_object_get_child_by_name(
            state->u.f0.reg.moder, "MODER10");
    state->u.f0.fld.moder.moder11 = cm_object_get_child_by_name(
            state->u.f0.reg.moder, "MODER11");
    state->u.f0.fld.moder.moder12 = cm_object_get_child_by_name(
            state->u.f0.reg.moder, "MODER12");
    state->u.f0.fld.moder.moder13 = cm_object_get_child_by_name(
            state->u.f0.reg.moder, "MODER13");
    state->u.f0.fld.moder.moder14 = cm_object_get_child_by_name(
            state->u.f0.reg.moder, "MODER14");
    state->u.f0.fld.moder.moder15 = cm_object_get_child_by_name(
            state->u.f0.reg.moder, "MODER15");

    // OTYPER bitfields.
    state->u.f0.fld.otyper.ot0 = cm_object_get_child_by_name(
            state->u.f0.reg.otyper, "OT0");
    state->u.f0.fld.otyper.ot1 = cm_object_get_child_by_name(
            state->u.f0.reg.otyper, "OT1");
    state->u.f0.fld.otyper.ot2 = cm_object_get_child_by_name(
            state->u.f0.reg.otyper, "OT2");
    state->u.f0.fld.otyper.ot3 = cm_object_get_child_by_name(
            state->u.f0.reg.otyper, "OT3");
    state->u.f0.fld.otyper.ot4 = cm_object_get_child_by_name(
            state->u.f0.reg.otyper, "OT4");
    state->u.f0.fld.otyper.ot5 = cm_object_get_child_by_name(
            state->u.f0.reg.otyper, "OT5");
    state->u.f0.fld.otyper.ot6 = cm_object_get_child_by_name(
            state->u.f0.reg.otyper, "OT6");
    state->u.f0.fld.otyper.ot7 = cm_object_get_child_by_name(
            state->u.f0.reg.otyper, "OT7");
    state->u.f0.fld.otyper.ot8 = cm_object_get_child_by_name(
            state->u.f0.reg.otyper, "OT8");
    state->u.f0.fld.otyper.ot9 = cm_object_get_child_by_name(
            state->u.f0.reg.otyper, "OT9");
    state->u.f0.fld.otyper.ot10 = cm_object_get_child_by_name(
            state->u.f0.reg.otyper, "OT10");
    state->u.f0.fld.otyper.ot11 = cm_object_get_child_by_name(
            state->u.f0.reg.otyper, "OT11");
    state->u.f0.fld.otyper.ot12 = cm_object_get_child_by_name(
            state->u.f0.reg.otyper, "OT12");
    state->u.f0.fld.otyper.ot13 = cm_object_get_child_by_name(
            state->u.f0.reg.otyper, "OT13");
    state->u.f0.fld.otyper.ot14 = cm_object_get_child_by_name(
            state->u.f0.reg.otyper, "OT14");
    state->u.f0.fld.otyper.ot15 = cm_object_get_child_by_name(
            state->u.f0.reg.otyper, "OT15");

    // OSPEEDR bitfields.
    state->u.f0.fld.ospeedr.ospeedr0 = cm_object_get_child_by_name(
            state->u.f0.reg.ospeedr, "OSPEEDR0");
    state->u.f0.fld.ospeedr.ospeedr1 = cm_object_get_child_by_name(
            state->u.f0.reg.ospeedr, "OSPEEDR1");
    state->u.f0.fld.ospeedr.ospeedr2 = cm_object_get_child_by_name(
            state->u.f0.reg.ospeedr, "OSPEEDR2");
    state->u.f0.fld.ospeedr.ospeedr3 = cm_object_get_child_by_name(
            state->u.f0.reg.ospeedr, "OSPEEDR3");
    state->u.f0.fld.ospeedr.ospeedr4 = cm_object_get_child_by_name(
            state->u.f0.reg.ospeedr, "OSPEEDR4");
    state->u.f0.fld.ospeedr.ospeedr5 = cm_object_get_child_by_name(
            state->u.f0.reg.ospeedr, "OSPEEDR5");
    state->u.f0.fld.ospeedr.ospeedr6 = cm_object_get_child_by_name(
            state->u.f0.reg.ospeedr, "OSPEEDR6");
    state->u.f0.fld.ospeedr.ospeedr7 = cm_object_get_child_by_name(
            state->u.f0.reg.ospeedr, "OSPEEDR7");
    state->u.f0.fld.ospeedr.ospeedr8 = cm_object_get_child_by_name(
            state->u.f0.reg.ospeedr, "OSPEEDR8");
    state->u.f0.fld.ospeedr.ospeedr9 = cm_object_get_child_by_name(
            state->u.f0.reg.ospeedr, "OSPEEDR9");
    state->u.f0.fld.ospeedr.ospeedr10 = cm_object_get_child_by_name(
            state->u.f0.reg.ospeedr, "OSPEEDR10");
    state->u.f0.fld.ospeedr.ospeedr11 = cm_object_get_child_by_name(
            state->u.f0.reg.ospeedr, "OSPEEDR11");
    state->u.f0.fld.ospeedr.ospeedr12 = cm_object_get_child_by_name(
            state->u.f0.reg.ospeedr, "OSPEEDR12");
    state->u.f0.fld.ospeedr.ospeedr13 = cm_object_get_child_by_name(
            state->u.f0.reg.ospeedr, "OSPEEDR13");
    state->u.f0.fld.ospeedr.ospeedr14 = cm_object_get_child_by_name(
            state->u.f0.reg.ospeedr, "OSPEEDR14");
    state->u.f0.fld.ospeedr.ospeedr15 = cm_object_get_child_by_name(
            state->u.f0.reg.ospeedr, "OSPEEDR15");

    // PUPDR bitfields.
    state->u.f0.fld.pupdr.pupdr0 = cm_object_get_child_by_name(
            state->u.f0.reg.pupdr, "PUPDR0");
    state->u.f0.fld.pupdr.pupdr1 = cm_object_get_child_by_name(
            state->u.f0.reg.pupdr, "PUPDR1");
    state->u.f0.fld.pupdr.pupdr2 = cm_object_get_child_by_name(
            state->u.f0.reg.pupdr, "PUPDR2");
    state->u.f0.fld.pupdr.pupdr3 = cm_object_get_child_by_name(
            state->u.f0.reg.pupdr, "PUPDR3");
    state->u.f0.fld.pupdr.pupdr4 = cm_object_get_child_by_name(
            state->u.f0.reg.pupdr, "PUPDR4");
    state->u.f0.fld.pupdr.pupdr5 = cm_object_get_child_by_name(
            state->u.f0.reg.pupdr, "PUPDR5");
    state->u.f0.fld.pupdr.pupdr6 = cm_object_get_child_by_name(
            state->u.f0.reg.pupdr, "PUPDR6");
    state->u.f0.fld.pupdr.pupdr7 = cm_object_get_child_by_name(
            state->u.f0.reg.pupdr, "PUPDR7");
    state->u.f0.fld.pupdr.pupdr8 = cm_object_get_child_by_name(
            state->u.f0.reg.pupdr, "PUPDR8");
    state->u.f0.fld.pupdr.pupdr9 = cm_object_get_child_by_name(
            state->u.f0.reg.pupdr, "PUPDR9");
    state->u.f0.fld.pupdr.pupdr10 = cm_object_get_child_by_name(
            state->u.f0.reg.pupdr, "PUPDR10");
    state->u.f0.fld.pupdr.pupdr11 = cm_object_get_child_by_name(
            state->u.f0.reg.pupdr, "PUPDR11");
    state->u.f0.fld.pupdr.pupdr12 = cm_object_get_child_by_name(
            state->u.f0.reg.pupdr, "PUPDR12");
    state->u.f0.fld.pupdr.pupdr13 = cm_object_get_child_by_name(
            state->u.f0.reg.pupdr, "PUPDR13");
    state->u.f0.fld.pupdr.pupdr14 = cm_object_get_child_by_name(
            state->u.f0.reg.pupdr, "PUPDR14");
    state->u.f0.fld.pupdr.pupdr15 = cm_object_get_child_by_name(
            state->u.f0.reg.pupdr, "PUPDR15");

    // IDR bitfields.
    state->u.f0.fld.idr.idr0 = cm_object_get_child_by_name(state->u.f0.reg.idr,
            "IDR0");
    state->u.f0.fld.idr.idr1 = cm_object_get_child_by_name(state->u.f0.reg.idr,
            "IDR1");
    state->u.f0.fld.idr.idr2 = cm_object_get_child_by_name(state->u.f0.reg.idr,
            "IDR2");
    state->u.f0.fld.idr.idr3 = cm_object_get_child_by_name(state->u.f0.reg.idr,
            "IDR3");
    state->u.f0.fld.idr.idr4 = cm_object_get_child_by_name(state->u.f0.reg.idr,
            "IDR4");
    state->u.f0.fld.idr.idr5 = cm_object_get_child_by_name(state->u.f0.reg.idr,
            "IDR5");
    state->u.f0.fld.idr.idr6 = cm_object_get_child_by_name(state->u.f0.reg.idr,
            "IDR6");
    state->u.f0.fld.idr.idr7 = cm_object_get_child_by_name(state->u.f0.reg.idr,
            "IDR7");
    state->u.f0.fld.idr.idr8 = cm_object_get_child_by_name(state->u.f0.reg.idr,
            "IDR8");
    state->u.f0.fld.idr.idr9 = cm_object_get_child_by_name(state->u.f0.reg.idr,
            "IDR9");
    state->u.f0.fld.idr.idr10 = cm_object_get_child_by_name(state->u.f0.reg.idr,
            "IDR10");
    state->u.f0.fld.idr.idr11 = cm_object_get_child_by_name(state->u.f0.reg.idr,
            "IDR11");
    state->u.f0.fld.idr.idr12 = cm_object_get_child_by_name(state->u.f0.reg.idr,
            "IDR12");
    state->u.f0.fld.idr.idr13 = cm_object_get_child_by_name(state->u.f0.reg.idr,
            "IDR13");
    state->u.f0.fld.idr.idr14 = cm_object_get_child_by_name(state->u.f0.reg.idr,
            "IDR14");
    state->u.f0.fld.idr.idr15 = cm_object_get_child_by_name(state->u.f0.reg.idr,
            "IDR15");

    // ODR bitfields.
    state->u.f0.fld.odr.odr0 = cm_object_get_child_by_name(state->u.f0.reg.odr,
            "ODR0");
    state->u.f0.fld.odr.odr1 = cm_object_get_child_by_name(state->u.f0.reg.odr,
            "ODR1");
    state->u.f0.fld.odr.odr2 = cm_object_get_child_by_name(state->u.f0.reg.odr,
            "ODR2");
    state->u.f0.fld.odr.odr3 = cm_object_get_child_by_name(state->u.f0.reg.odr,
            "ODR3");
    state->u.f0.fld.odr.odr4 = cm_object_get_child_by_name(state->u.f0.reg.odr,
            "ODR4");
    state->u.f0.fld.odr.odr5 = cm_object_get_child_by_name(state->u.f0.reg.odr,
            "ODR5");
    state->u.f0.fld.odr.odr6 = cm_object_get_child_by_name(state->u.f0.reg.odr,
            "ODR6");
    state->u.f0.fld.odr.odr7 = cm_object_get_child_by_name(state->u.f0.reg.odr,
            "ODR7");
    state->u.f0.fld.odr.odr8 = cm_object_get_child_by_name(state->u.f0.reg.odr,
            "ODR8");
    state->u.f0.fld.odr.odr9 = cm_object_get_child_by_name(state->u.f0.reg.odr,
            "ODR9");
    state->u.f0.fld.odr.odr10 = cm_object_get_child_by_name(state->u.f0.reg.odr,
            "ODR10");
    state->u.f0.fld.odr.odr11 = cm_object_get_child_by_name(state->u.f0.reg.odr,
            "ODR11");
    state->u.f0.fld.odr.odr12 = cm_object_get_child_by_name(state->u.f0.reg.odr,
            "ODR12");
    state->u.f0.fld.odr.odr13 = cm_object_get_child_by_name(state->u.f0.reg.odr,
            "ODR13");
    state->u.f0.fld.odr.odr14 = cm_object_get_child_by_name(state->u.f0.reg.odr,
            "ODR14");
    state->u.f0.fld.odr.odr15 = cm_object_get_child_by_name(state->u.f0.reg.odr,
            "ODR15");

    // BSRR bitfields.
    state->u.f0.fld.bsrr.bs0 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BS0");
    state->u.f0.fld.bsrr.bs1 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BS1");
    state->u.f0.fld.bsrr.bs2 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BS2");
    state->u.f0.fld.bsrr.bs3 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BS3");
    state->u.f0.fld.bsrr.bs4 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BS4");
    state->u.f0.fld.bsrr.bs5 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BS5");
    state->u.f0.fld.bsrr.bs6 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BS6");
    state->u.f0.fld.bsrr.bs7 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BS7");
    state->u.f0.fld.bsrr.bs8 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BS8");
    state->u.f0.fld.bsrr.bs9 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BS9");
    state->u.f0.fld.bsrr.bs10 = cm_object_get_child_by_name(
            state->u.f0.reg.bsrr, "BS10");
    state->u.f0.fld.bsrr.bs11 = cm_object_get_child_by_name(
            state->u.f0.reg.bsrr, "BS11");
    state->u.f0.fld.bsrr.bs12 = cm_object_get_child_by_name(
            state->u.f0.reg.bsrr, "BS12");
    state->u.f0.fld.bsrr.bs13 = cm_object_get_child_by_name(
            state->u.f0.reg.bsrr, "BS13");
    state->u.f0.fld.bsrr.bs14 = cm_object_get_child_by_name(
            state->u.f0.reg.bsrr, "BS14");
    state->u.f0.fld.bsrr.bs15 = cm_object_get_child_by_name(
            state->u.f0.reg.bsrr, "BS15");
    state->u.f0.fld.bsrr.br0 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BR0");
    state->u.f0.fld.bsrr.br1 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BR1");
    state->u.f0.fld.bsrr.br2 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BR2");
    state->u.f0.fld.bsrr.br3 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BR3");
    state->u.f0.fld.bsrr.br4 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BR4");
    state->u.f0.fld.bsrr.br5 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BR5");
    state->u.f0.fld.bsrr.br6 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BR6");
    state->u.f0.fld.bsrr.br7 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BR7");
    state->u.f0.fld.bsrr.br8 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BR8");
    state->u.f0.fld.bsrr.br9 = cm_object_get_child_by_name(state->u.f0.reg.bsrr,
            "BR9");
    state->u.f0.fld.bsrr.br10 = cm_object_get_child_by_name(
            state->u.f0.reg.bsrr, "BR10");
    state->u.f0.fld.bsrr.br11 = cm_object_get_child_by_name(
            state->u.f0.reg.bsrr, "BR11");
    state->u.f0.fld.bsrr.br12 = cm_object_get_child_by_name(
            state->u.f0.reg.bsrr, "BR12");
    state->u.f0.fld.bsrr.br13 = cm_object_get_child_by_name(
            state->u.f0.reg.bsrr, "BR13");
    state->u.f0.fld.bsrr.br14 = cm_object_get_child_by_name(
            state->u.f0.reg.bsrr, "BR14");
    state->u.f0.fld.bsrr.br15 = cm_object_get_child_by_name(
            state->u.f0.reg.bsrr, "BR15");

    // LCKR bitfields.
    state->u.f0.fld.lckr.lck0 = cm_object_get_child_by_name(
            state->u.f0.reg.lckr, "LCK0");
    state->u.f0.fld.lckr.lck1 = cm_object_get_child_by_name(
            state->u.f0.reg.lckr, "LCK1");
    state->u.f0.fld.lckr.lck2 = cm_object_get_child_by_name(
            state->u.f0.reg.lckr, "LCK2");
    state->u.f0.fld.lckr.lck3 = cm_object_get_child_by_name(
            state->u.f0.reg.lckr, "LCK3");
    state->u.f0.fld.lckr.lck4 = cm_object_get_child_by_name(
            state->u.f0.reg.lckr, "LCK4");
    state->u.f0.fld.lckr.lck5 = cm_object_get_child_by_name(
            state->u.f0.reg.lckr, "LCK5");
    state->u.f0.fld.lckr.lck6 = cm_object_get_child_by_name(
            state->u.f0.reg.lckr, "LCK6");
    state->u.f0.fld.lckr.lck7 = cm_object_get_child_by_name(
            state->u.f0.reg.lckr, "LCK7");
    state->u.f0.fld.lckr.lck8 = cm_object_get_child_by_name(
            state->u.f0.reg.lckr, "LCK8");
    state->u.f0.fld.lckr.lck9 = cm_object_get_child_by_name(
            state->u.f0.reg.lckr, "LCK9");
    state->u.f0.fld.lckr.lck10 = cm_object_get_child_by_name(
            state->u.f0.reg.lckr, "LCK10");
    state->u.f0.fld.lckr.lck11 = cm_object_get_child_by_name(
            state->u.f0.reg.lckr, "LCK11");
    state->u.f0.fld.lckr.lck12 = cm_object_get_child_by_name(
            state->u.f0.reg.lckr, "LCK12");
    state->u.f0.fld.lckr.lck13 = cm_object_get_child_by_name(
            state->u.f0.reg.lckr, "LCK13");
    state->u.f0.fld.lckr.lck14 = cm_object_get_child_by_name(
            state->u.f0.reg.lckr, "LCK14");
    state->u.f0.fld.lckr.lck15 = cm_object_get_child_by_name(
            state->u.f0.reg.lckr, "LCK15");
    state->u.f0.fld.lckr.lckk = cm_object_get_child_by_name(
            state->u.f0.reg.lckr, "LCKK");

    // AFRL bitfields.
    state->u.f0.fld.afrl.afrl0 = cm_object_get_child_by_name(
            state->u.f0.reg.afrl, "AFRL0");
    state->u.f0.fld.afrl.afrl1 = cm_object_get_child_by_name(
            state->u.f0.reg.afrl, "AFRL1");
    state->u.f0.fld.afrl.afrl2 = cm_object_get_child_by_name(
            state->u.f0.reg.afrl, "AFRL2");
    state->u.f0.fld.afrl.afrl3 = cm_object_get_child_by_name(
            state->u.f0.reg.afrl, "AFRL3");
    state->u.f0.fld.afrl.afrl4 = cm_object_get_child_by_name(
            state->u.f0.reg.afrl, "AFRL4");
    state->u.f0.fld.afrl.afrl5 = cm_object_get_child_by_name(
            state->u.f0.reg.afrl, "AFRL5");
    state->u.f0.fld.afrl.afrl6 = cm_object_get_child_by_name(
            state->u.f0.reg.afrl, "AFRL6");
    state->u.f0.fld.afrl.afrl7 = cm_object_get_child_by_name(
            state->u.f0.reg.afrl, "AFRL7");

    // AFRH bitfields.
    state->u.f0.fld.afrh.afrh8 = cm_object_get_child_by_name(
            state->u.f0.reg.afrh, "AFRH8");
    state->u.f0.fld.afrh.afrh9 = cm_object_get_child_by_name(
            state->u.f0.reg.afrh, "AFRH9");
    state->u.f0.fld.afrh.afrh10 = cm_object_get_child_by_name(
            state->u.f0.reg.afrh, "AFRH10");
    state->u.f0.fld.afrh.afrh11 = cm_object_get_child_by_name(
            state->u.f0.reg.afrh, "AFRH11");
    state->u.f0.fld.afrh.afrh12 = cm_object_get_child_by_name(
            state->u.f0.reg.afrh, "AFRH12");
    state->u.f0.fld.afrh.afrh13 = cm_object_get_child_by_name(
            state->u.f0.reg.afrh, "AFRH13");
    state->u.f0.fld.afrh.afrh14 = cm_object_get_child_by_name(
            state->u.f0.reg.afrh, "AFRH14");
    state->u.f0.fld.afrh.afrh15 = cm_object_get_child_by_name(
            state->u.f0.reg.afrh, "AFRH15");

    // BRR bitfields.
    state->u.f0.fld.brr.br0 = cm_object_get_child_by_name(state->u.f0.reg.brr,
            "BR0");
    state->u.f0.fld.brr.br1 = cm_object_get_child_by_name(state->u.f0.reg.brr,
            "BR1");
    state->u.f0.fld.brr.br2 = cm_object_get_child_by_name(state->u.f0.reg.brr,
            "BR2");
    state->u.f0.fld.brr.br3 = cm_object_get_child_by_name(state->u.f0.reg.brr,
            "BR3");
    state->u.f0.fld.brr.br4 = cm_object_get_child_by_name(state->u.f0.reg.brr,
            "BR4");
    state->u.f0.fld.brr.br5 = cm_object_get_child_by_name(state->u.f0.reg.brr,
            "BR5");
    state->u.f0.fld.brr.br6 = cm_object_get_child_by_name(state->u.f0.reg.brr,
            "BR6");
    state->u.f0.fld.brr.br7 = cm_object_get_child_by_name(state->u.f0.reg.brr,
            "BR7");
    state->u.f0.fld.brr.br8 = cm_object_get_child_by_name(state->u.f0.reg.brr,
            "BR8");
    state->u.f0.fld.brr.br9 = cm_object_get_child_by_name(state->u.f0.reg.brr,
            "BR9");
    state->u.f0.fld.brr.br10 = cm_object_get_child_by_name(state->u.f0.reg.brr,
            "BR10");
    state->u.f0.fld.brr.br11 = cm_object_get_child_by_name(state->u.f0.reg.brr,
            "BR11");
    state->u.f0.fld.brr.br12 = cm_object_get_child_by_name(state->u.f0.reg.brr,
            "BR12");
    state->u.f0.fld.brr.br13 = cm_object_get_child_by_name(state->u.f0.reg.brr,
            "BR13");
    state->u.f0.fld.brr.br14 = cm_object_get_child_by_name(state->u.f0.reg.brr,
            "BR14");
    state->u.f0.fld.brr.br15 = cm_object_get_child_by_name(state->u.f0.reg.brr,
            "BR15");
}

// ----------------------------------------------------------------------------

// STM32F103RB
// DO NOT EDIT! Automatically generated!
static void stm32f103xx_gpio_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f1.reg.crl = cm_object_get_child_by_name(obj, "CRL");
    state->u.f1.reg.crh = cm_object_get_child_by_name(obj, "CRH");
    state->u.f1.reg.idr = cm_object_get_child_by_name(obj, "IDR");
    state->u.f1.reg.odr = cm_object_get_child_by_name(obj, "ODR");
    state->u.f1.reg.bsrr = cm_object_get_child_by_name(obj, "BSRR");
    state->u.f1.reg.brr = cm_object_get_child_by_name(obj, "BRR");
    state->u.f1.reg.lckr = cm_object_get_child_by_name(obj, "LCKR");

    // CRL bitfields.
    state->u.f1.fld.crl.mode0 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "MODE0");
    state->u.f1.fld.crl.cnf0 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "CNF0");
    state->u.f1.fld.crl.mode1 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "MODE1");
    state->u.f1.fld.crl.cnf1 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "CNF1");
    state->u.f1.fld.crl.mode2 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "MODE2");
    state->u.f1.fld.crl.cnf2 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "CNF2");
    state->u.f1.fld.crl.mode3 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "MODE3");
    state->u.f1.fld.crl.cnf3 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "CNF3");
    state->u.f1.fld.crl.mode4 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "MODE4");
    state->u.f1.fld.crl.cnf4 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "CNF4");
    state->u.f1.fld.crl.mode5 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "MODE5");
    state->u.f1.fld.crl.cnf5 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "CNF5");
    state->u.f1.fld.crl.mode6 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "MODE6");
    state->u.f1.fld.crl.cnf6 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "CNF6");
    state->u.f1.fld.crl.mode7 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "MODE7");
    state->u.f1.fld.crl.cnf7 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "CNF7");

    // CRH bitfields.
    state->u.f1.fld.crh.mode8 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "MODE8");
    state->u.f1.fld.crh.cnf8 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "CNF8");
    state->u.f1.fld.crh.mode9 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "MODE9");
    state->u.f1.fld.crh.cnf9 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "CNF9");
    state->u.f1.fld.crh.mode10 = cm_object_get_child_by_name(
            state->u.f1.reg.crh, "MODE10");
    state->u.f1.fld.crh.cnf10 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "CNF10");
    state->u.f1.fld.crh.mode11 = cm_object_get_child_by_name(
            state->u.f1.reg.crh, "MODE11");
    state->u.f1.fld.crh.cnf11 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "CNF11");
    state->u.f1.fld.crh.mode12 = cm_object_get_child_by_name(
            state->u.f1.reg.crh, "MODE12");
    state->u.f1.fld.crh.cnf12 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "CNF12");
    state->u.f1.fld.crh.mode13 = cm_object_get_child_by_name(
            state->u.f1.reg.crh, "MODE13");
    state->u.f1.fld.crh.cnf13 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "CNF13");
    state->u.f1.fld.crh.mode14 = cm_object_get_child_by_name(
            state->u.f1.reg.crh, "MODE14");
    state->u.f1.fld.crh.cnf14 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "CNF14");
    state->u.f1.fld.crh.mode15 = cm_object_get_child_by_name(
            state->u.f1.reg.crh, "MODE15");
    state->u.f1.fld.crh.cnf15 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "CNF15");

    // IDR bitfields.
    state->u.f1.fld.idr.idr0 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR0");
    state->u.f1.fld.idr.idr1 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR1");
    state->u.f1.fld.idr.idr2 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR2");
    state->u.f1.fld.idr.idr3 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR3");
    state->u.f1.fld.idr.idr4 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR4");
    state->u.f1.fld.idr.idr5 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR5");
    state->u.f1.fld.idr.idr6 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR6");
    state->u.f1.fld.idr.idr7 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR7");
    state->u.f1.fld.idr.idr8 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR8");
    state->u.f1.fld.idr.idr9 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR9");
    state->u.f1.fld.idr.idr10 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR10");
    state->u.f1.fld.idr.idr11 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR11");
    state->u.f1.fld.idr.idr12 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR12");
    state->u.f1.fld.idr.idr13 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR13");
    state->u.f1.fld.idr.idr14 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR14");
    state->u.f1.fld.idr.idr15 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR15");

    // ODR bitfields.
    state->u.f1.fld.odr.odr0 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR0");
    state->u.f1.fld.odr.odr1 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR1");
    state->u.f1.fld.odr.odr2 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR2");
    state->u.f1.fld.odr.odr3 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR3");
    state->u.f1.fld.odr.odr4 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR4");
    state->u.f1.fld.odr.odr5 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR5");
    state->u.f1.fld.odr.odr6 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR6");
    state->u.f1.fld.odr.odr7 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR7");
    state->u.f1.fld.odr.odr8 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR8");
    state->u.f1.fld.odr.odr9 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR9");
    state->u.f1.fld.odr.odr10 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR10");
    state->u.f1.fld.odr.odr11 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR11");
    state->u.f1.fld.odr.odr12 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR12");
    state->u.f1.fld.odr.odr13 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR13");
    state->u.f1.fld.odr.odr14 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR14");
    state->u.f1.fld.odr.odr15 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR15");

    // BSRR bitfields.
    state->u.f1.fld.bsrr.bs0 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS0");
    state->u.f1.fld.bsrr.bs1 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS1");
    state->u.f1.fld.bsrr.bs2 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS2");
    state->u.f1.fld.bsrr.bs3 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS3");
    state->u.f1.fld.bsrr.bs4 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS4");
    state->u.f1.fld.bsrr.bs5 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS5");
    state->u.f1.fld.bsrr.bs6 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS6");
    state->u.f1.fld.bsrr.bs7 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS7");
    state->u.f1.fld.bsrr.bs8 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS8");
    state->u.f1.fld.bsrr.bs9 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS9");
    state->u.f1.fld.bsrr.bs10 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BS10");
    state->u.f1.fld.bsrr.bs11 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BS11");
    state->u.f1.fld.bsrr.bs12 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BS12");
    state->u.f1.fld.bsrr.bs13 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BS13");
    state->u.f1.fld.bsrr.bs14 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BS14");
    state->u.f1.fld.bsrr.bs15 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BS15");
    state->u.f1.fld.bsrr.br0 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR0");
    state->u.f1.fld.bsrr.br1 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR1");
    state->u.f1.fld.bsrr.br2 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR2");
    state->u.f1.fld.bsrr.br3 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR3");
    state->u.f1.fld.bsrr.br4 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR4");
    state->u.f1.fld.bsrr.br5 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR5");
    state->u.f1.fld.bsrr.br6 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR6");
    state->u.f1.fld.bsrr.br7 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR7");
    state->u.f1.fld.bsrr.br8 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR8");
    state->u.f1.fld.bsrr.br9 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR9");
    state->u.f1.fld.bsrr.br10 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BR10");
    state->u.f1.fld.bsrr.br11 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BR11");
    state->u.f1.fld.bsrr.br12 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BR12");
    state->u.f1.fld.bsrr.br13 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BR13");
    state->u.f1.fld.bsrr.br14 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BR14");
    state->u.f1.fld.bsrr.br15 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BR15");

    // BRR bitfields.
    state->u.f1.fld.brr.br0 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR0");
    state->u.f1.fld.brr.br1 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR1");
    state->u.f1.fld.brr.br2 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR2");
    state->u.f1.fld.brr.br3 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR3");
    state->u.f1.fld.brr.br4 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR4");
    state->u.f1.fld.brr.br5 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR5");
    state->u.f1.fld.brr.br6 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR6");
    state->u.f1.fld.brr.br7 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR7");
    state->u.f1.fld.brr.br8 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR8");
    state->u.f1.fld.brr.br9 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR9");
    state->u.f1.fld.brr.br10 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR10");
    state->u.f1.fld.brr.br11 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR11");
    state->u.f1.fld.brr.br12 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR12");
    state->u.f1.fld.brr.br13 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR13");
    state->u.f1.fld.brr.br14 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR14");
    state->u.f1.fld.brr.br15 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR15");

    // LCKR bitfields.
    state->u.f1.fld.lckr.lck0 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK0");
    state->u.f1.fld.lckr.lck1 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK1");
    state->u.f1.fld.lckr.lck2 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK2");
    state->u.f1.fld.lckr.lck3 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK3");
    state->u.f1.fld.lckr.lck4 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK4");
    state->u.f1.fld.lckr.lck5 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK5");
    state->u.f1.fld.lckr.lck6 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK6");
    state->u.f1.fld.lckr.lck7 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK7");
    state->u.f1.fld.lckr.lck8 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK8");
    state->u.f1.fld.lckr.lck9 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK9");
    state->u.f1.fld.lckr.lck10 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK10");
    state->u.f1.fld.lckr.lck11 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK11");
    state->u.f1.fld.lckr.lck12 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK12");
    state->u.f1.fld.lckr.lck13 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK13");
    state->u.f1.fld.lckr.lck14 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK14");
    state->u.f1.fld.lckr.lck15 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK15");
    state->u.f1.fld.lckr.lckk = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCKK");
}

// ----------------------------------------------------------------------------

// STM32F107VC
// DO NOT EDIT! Automatically generated!
static void stm32f107xx_gpio_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f1.reg.crl = cm_object_get_child_by_name(obj, "CRL");
    state->u.f1.reg.crh = cm_object_get_child_by_name(obj, "CRH");
    state->u.f1.reg.idr = cm_object_get_child_by_name(obj, "IDR");
    state->u.f1.reg.odr = cm_object_get_child_by_name(obj, "ODR");
    state->u.f1.reg.bsrr = cm_object_get_child_by_name(obj, "BSRR");
    state->u.f1.reg.brr = cm_object_get_child_by_name(obj, "BRR");
    state->u.f1.reg.lckr = cm_object_get_child_by_name(obj, "LCKR");

    // CRL bitfields.
    state->u.f1.fld.crl.mode0 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "MODE0");
    state->u.f1.fld.crl.cnf0 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "CNF0");
    state->u.f1.fld.crl.mode1 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "MODE1");
    state->u.f1.fld.crl.cnf1 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "CNF1");
    state->u.f1.fld.crl.mode2 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "MODE2");
    state->u.f1.fld.crl.cnf2 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "CNF2");
    state->u.f1.fld.crl.mode3 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "MODE3");
    state->u.f1.fld.crl.cnf3 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "CNF3");
    state->u.f1.fld.crl.mode4 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "MODE4");
    state->u.f1.fld.crl.cnf4 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "CNF4");
    state->u.f1.fld.crl.mode5 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "MODE5");
    state->u.f1.fld.crl.cnf5 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "CNF5");
    state->u.f1.fld.crl.mode6 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "MODE6");
    state->u.f1.fld.crl.cnf6 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "CNF6");
    state->u.f1.fld.crl.mode7 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "MODE7");
    state->u.f1.fld.crl.cnf7 = cm_object_get_child_by_name(state->u.f1.reg.crl,
            "CNF7");

    // CRH bitfields.
    state->u.f1.fld.crh.mode8 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "MODE8");
    state->u.f1.fld.crh.cnf8 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "CNF8");
    state->u.f1.fld.crh.mode9 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "MODE9");
    state->u.f1.fld.crh.cnf9 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "CNF9");
    state->u.f1.fld.crh.mode10 = cm_object_get_child_by_name(
            state->u.f1.reg.crh, "MODE10");
    state->u.f1.fld.crh.cnf10 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "CNF10");
    state->u.f1.fld.crh.mode11 = cm_object_get_child_by_name(
            state->u.f1.reg.crh, "MODE11");
    state->u.f1.fld.crh.cnf11 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "CNF11");
    state->u.f1.fld.crh.mode12 = cm_object_get_child_by_name(
            state->u.f1.reg.crh, "MODE12");
    state->u.f1.fld.crh.cnf12 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "CNF12");
    state->u.f1.fld.crh.mode13 = cm_object_get_child_by_name(
            state->u.f1.reg.crh, "MODE13");
    state->u.f1.fld.crh.cnf13 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "CNF13");
    state->u.f1.fld.crh.mode14 = cm_object_get_child_by_name(
            state->u.f1.reg.crh, "MODE14");
    state->u.f1.fld.crh.cnf14 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "CNF14");
    state->u.f1.fld.crh.mode15 = cm_object_get_child_by_name(
            state->u.f1.reg.crh, "MODE15");
    state->u.f1.fld.crh.cnf15 = cm_object_get_child_by_name(state->u.f1.reg.crh,
            "CNF15");

    // IDR bitfields.
    state->u.f1.fld.idr.idr0 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR0");
    state->u.f1.fld.idr.idr1 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR1");
    state->u.f1.fld.idr.idr2 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR2");
    state->u.f1.fld.idr.idr3 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR3");
    state->u.f1.fld.idr.idr4 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR4");
    state->u.f1.fld.idr.idr5 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR5");
    state->u.f1.fld.idr.idr6 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR6");
    state->u.f1.fld.idr.idr7 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR7");
    state->u.f1.fld.idr.idr8 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR8");
    state->u.f1.fld.idr.idr9 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR9");
    state->u.f1.fld.idr.idr10 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR10");
    state->u.f1.fld.idr.idr11 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR11");
    state->u.f1.fld.idr.idr12 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR12");
    state->u.f1.fld.idr.idr13 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR13");
    state->u.f1.fld.idr.idr14 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR14");
    state->u.f1.fld.idr.idr15 = cm_object_get_child_by_name(state->u.f1.reg.idr,
            "IDR15");

    // ODR bitfields.
    state->u.f1.fld.odr.odr0 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR0");
    state->u.f1.fld.odr.odr1 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR1");
    state->u.f1.fld.odr.odr2 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR2");
    state->u.f1.fld.odr.odr3 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR3");
    state->u.f1.fld.odr.odr4 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR4");
    state->u.f1.fld.odr.odr5 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR5");
    state->u.f1.fld.odr.odr6 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR6");
    state->u.f1.fld.odr.odr7 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR7");
    state->u.f1.fld.odr.odr8 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR8");
    state->u.f1.fld.odr.odr9 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR9");
    state->u.f1.fld.odr.odr10 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR10");
    state->u.f1.fld.odr.odr11 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR11");
    state->u.f1.fld.odr.odr12 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR12");
    state->u.f1.fld.odr.odr13 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR13");
    state->u.f1.fld.odr.odr14 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR14");
    state->u.f1.fld.odr.odr15 = cm_object_get_child_by_name(state->u.f1.reg.odr,
            "ODR15");

    // BSRR bitfields.
    state->u.f1.fld.bsrr.bs0 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS0");
    state->u.f1.fld.bsrr.bs1 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS1");
    state->u.f1.fld.bsrr.bs2 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS2");
    state->u.f1.fld.bsrr.bs3 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS3");
    state->u.f1.fld.bsrr.bs4 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS4");
    state->u.f1.fld.bsrr.bs5 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS5");
    state->u.f1.fld.bsrr.bs6 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS6");
    state->u.f1.fld.bsrr.bs7 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS7");
    state->u.f1.fld.bsrr.bs8 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS8");
    state->u.f1.fld.bsrr.bs9 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BS9");
    state->u.f1.fld.bsrr.bs10 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BS10");
    state->u.f1.fld.bsrr.bs11 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BS11");
    state->u.f1.fld.bsrr.bs12 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BS12");
    state->u.f1.fld.bsrr.bs13 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BS13");
    state->u.f1.fld.bsrr.bs14 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BS14");
    state->u.f1.fld.bsrr.bs15 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BS15");
    state->u.f1.fld.bsrr.br0 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR0");
    state->u.f1.fld.bsrr.br1 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR1");
    state->u.f1.fld.bsrr.br2 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR2");
    state->u.f1.fld.bsrr.br3 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR3");
    state->u.f1.fld.bsrr.br4 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR4");
    state->u.f1.fld.bsrr.br5 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR5");
    state->u.f1.fld.bsrr.br6 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR6");
    state->u.f1.fld.bsrr.br7 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR7");
    state->u.f1.fld.bsrr.br8 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR8");
    state->u.f1.fld.bsrr.br9 = cm_object_get_child_by_name(state->u.f1.reg.bsrr,
            "BR9");
    state->u.f1.fld.bsrr.br10 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BR10");
    state->u.f1.fld.bsrr.br11 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BR11");
    state->u.f1.fld.bsrr.br12 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BR12");
    state->u.f1.fld.bsrr.br13 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BR13");
    state->u.f1.fld.bsrr.br14 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BR14");
    state->u.f1.fld.bsrr.br15 = cm_object_get_child_by_name(
            state->u.f1.reg.bsrr, "BR15");

    // BRR bitfields.
    state->u.f1.fld.brr.br0 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR0");
    state->u.f1.fld.brr.br1 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR1");
    state->u.f1.fld.brr.br2 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR2");
    state->u.f1.fld.brr.br3 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR3");
    state->u.f1.fld.brr.br4 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR4");
    state->u.f1.fld.brr.br5 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR5");
    state->u.f1.fld.brr.br6 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR6");
    state->u.f1.fld.brr.br7 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR7");
    state->u.f1.fld.brr.br8 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR8");
    state->u.f1.fld.brr.br9 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR9");
    state->u.f1.fld.brr.br10 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR10");
    state->u.f1.fld.brr.br11 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR11");
    state->u.f1.fld.brr.br12 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR12");
    state->u.f1.fld.brr.br13 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR13");
    state->u.f1.fld.brr.br14 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR14");
    state->u.f1.fld.brr.br15 = cm_object_get_child_by_name(state->u.f1.reg.brr,
            "BR15");

    // LCKR bitfields.
    state->u.f1.fld.lckr.lck0 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK0");
    state->u.f1.fld.lckr.lck1 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK1");
    state->u.f1.fld.lckr.lck2 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK2");
    state->u.f1.fld.lckr.lck3 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK3");
    state->u.f1.fld.lckr.lck4 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK4");
    state->u.f1.fld.lckr.lck5 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK5");
    state->u.f1.fld.lckr.lck6 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK6");
    state->u.f1.fld.lckr.lck7 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK7");
    state->u.f1.fld.lckr.lck8 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK8");
    state->u.f1.fld.lckr.lck9 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK9");
    state->u.f1.fld.lckr.lck10 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK10");
    state->u.f1.fld.lckr.lck11 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK11");
    state->u.f1.fld.lckr.lck12 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK12");
    state->u.f1.fld.lckr.lck13 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK13");
    state->u.f1.fld.lckr.lck14 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK14");
    state->u.f1.fld.lckr.lck15 = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCK15");
    state->u.f1.fld.lckr.lckk = cm_object_get_child_by_name(
            state->u.f1.reg.lckr, "LCKK");
}

// ----------------------------------------------------------------------------

// STM32F407VG, STM32F407ZG, STM32F405RG
// DO NOT EDIT! Automatically generated!
static void stm32f40x_gpio_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f4.reg.moder = cm_object_get_child_by_name(obj, "MODER");
    state->u.f4.reg.otyper = cm_object_get_child_by_name(obj, "OTYPER");
    state->u.f4.reg.ospeedr = cm_object_get_child_by_name(obj, "OSPEEDR");
    state->u.f4.reg.pupdr = cm_object_get_child_by_name(obj, "PUPDR");
    state->u.f4.reg.idr = cm_object_get_child_by_name(obj, "IDR");
    state->u.f4.reg.odr = cm_object_get_child_by_name(obj, "ODR");
    state->u.f4.reg.bsrr = cm_object_get_child_by_name(obj, "BSRR");
    state->u.f4.reg.lckr = cm_object_get_child_by_name(obj, "LCKR");
    state->u.f4.reg.afrl = cm_object_get_child_by_name(obj, "AFRL");
    state->u.f4.reg.afrh = cm_object_get_child_by_name(obj, "AFRH");

    // MODER bitfields.
    state->u.f4.fld.moder.moder0 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER0");
    state->u.f4.fld.moder.moder1 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER1");
    state->u.f4.fld.moder.moder2 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER2");
    state->u.f4.fld.moder.moder3 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER3");
    state->u.f4.fld.moder.moder4 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER4");
    state->u.f4.fld.moder.moder5 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER5");
    state->u.f4.fld.moder.moder6 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER6");
    state->u.f4.fld.moder.moder7 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER7");
    state->u.f4.fld.moder.moder8 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER8");
    state->u.f4.fld.moder.moder9 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER9");
    state->u.f4.fld.moder.moder10 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER10");
    state->u.f4.fld.moder.moder11 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER11");
    state->u.f4.fld.moder.moder12 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER12");
    state->u.f4.fld.moder.moder13 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER13");
    state->u.f4.fld.moder.moder14 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER14");
    state->u.f4.fld.moder.moder15 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER15");

    // OTYPER bitfields.
    state->u.f4.fld.otyper.ot0 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT0");
    state->u.f4.fld.otyper.ot1 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT1");
    state->u.f4.fld.otyper.ot2 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT2");
    state->u.f4.fld.otyper.ot3 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT3");
    state->u.f4.fld.otyper.ot4 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT4");
    state->u.f4.fld.otyper.ot5 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT5");
    state->u.f4.fld.otyper.ot6 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT6");
    state->u.f4.fld.otyper.ot7 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT7");
    state->u.f4.fld.otyper.ot8 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT8");
    state->u.f4.fld.otyper.ot9 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT9");
    state->u.f4.fld.otyper.ot10 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT10");
    state->u.f4.fld.otyper.ot11 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT11");
    state->u.f4.fld.otyper.ot12 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT12");
    state->u.f4.fld.otyper.ot13 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT13");
    state->u.f4.fld.otyper.ot14 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT14");
    state->u.f4.fld.otyper.ot15 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT15");

    // OSPEEDR bitfields.
    state->u.f4.fld.ospeedr.ospeedr0 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR0");
    state->u.f4.fld.ospeedr.ospeedr1 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR1");
    state->u.f4.fld.ospeedr.ospeedr2 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR2");
    state->u.f4.fld.ospeedr.ospeedr3 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR3");
    state->u.f4.fld.ospeedr.ospeedr4 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR4");
    state->u.f4.fld.ospeedr.ospeedr5 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR5");
    state->u.f4.fld.ospeedr.ospeedr6 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR6");
    state->u.f4.fld.ospeedr.ospeedr7 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR7");
    state->u.f4.fld.ospeedr.ospeedr8 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR8");
    state->u.f4.fld.ospeedr.ospeedr9 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR9");
    state->u.f4.fld.ospeedr.ospeedr10 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR10");
    state->u.f4.fld.ospeedr.ospeedr11 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR11");
    state->u.f4.fld.ospeedr.ospeedr12 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR12");
    state->u.f4.fld.ospeedr.ospeedr13 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR13");
    state->u.f4.fld.ospeedr.ospeedr14 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR14");
    state->u.f4.fld.ospeedr.ospeedr15 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR15");

    // PUPDR bitfields.
    state->u.f4.fld.pupdr.pupdr0 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR0");
    state->u.f4.fld.pupdr.pupdr1 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR1");
    state->u.f4.fld.pupdr.pupdr2 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR2");
    state->u.f4.fld.pupdr.pupdr3 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR3");
    state->u.f4.fld.pupdr.pupdr4 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR4");
    state->u.f4.fld.pupdr.pupdr5 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR5");
    state->u.f4.fld.pupdr.pupdr6 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR6");
    state->u.f4.fld.pupdr.pupdr7 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR7");
    state->u.f4.fld.pupdr.pupdr8 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR8");
    state->u.f4.fld.pupdr.pupdr9 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR9");
    state->u.f4.fld.pupdr.pupdr10 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR10");
    state->u.f4.fld.pupdr.pupdr11 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR11");
    state->u.f4.fld.pupdr.pupdr12 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR12");
    state->u.f4.fld.pupdr.pupdr13 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR13");
    state->u.f4.fld.pupdr.pupdr14 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR14");
    state->u.f4.fld.pupdr.pupdr15 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR15");

    // IDR bitfields.
    state->u.f4.fld.idr.idr0 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR0");
    state->u.f4.fld.idr.idr1 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR1");
    state->u.f4.fld.idr.idr2 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR2");
    state->u.f4.fld.idr.idr3 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR3");
    state->u.f4.fld.idr.idr4 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR4");
    state->u.f4.fld.idr.idr5 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR5");
    state->u.f4.fld.idr.idr6 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR6");
    state->u.f4.fld.idr.idr7 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR7");
    state->u.f4.fld.idr.idr8 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR8");
    state->u.f4.fld.idr.idr9 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR9");
    state->u.f4.fld.idr.idr10 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR10");
    state->u.f4.fld.idr.idr11 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR11");
    state->u.f4.fld.idr.idr12 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR12");
    state->u.f4.fld.idr.idr13 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR13");
    state->u.f4.fld.idr.idr14 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR14");
    state->u.f4.fld.idr.idr15 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR15");

    // ODR bitfields.
    state->u.f4.fld.odr.odr0 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR0");
    state->u.f4.fld.odr.odr1 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR1");
    state->u.f4.fld.odr.odr2 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR2");
    state->u.f4.fld.odr.odr3 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR3");
    state->u.f4.fld.odr.odr4 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR4");
    state->u.f4.fld.odr.odr5 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR5");
    state->u.f4.fld.odr.odr6 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR6");
    state->u.f4.fld.odr.odr7 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR7");
    state->u.f4.fld.odr.odr8 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR8");
    state->u.f4.fld.odr.odr9 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR9");
    state->u.f4.fld.odr.odr10 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR10");
    state->u.f4.fld.odr.odr11 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR11");
    state->u.f4.fld.odr.odr12 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR12");
    state->u.f4.fld.odr.odr13 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR13");
    state->u.f4.fld.odr.odr14 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR14");
    state->u.f4.fld.odr.odr15 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR15");

    // BSRR bitfields.
    state->u.f4.fld.bsrr.bs0 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS0");
    state->u.f4.fld.bsrr.bs1 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS1");
    state->u.f4.fld.bsrr.bs2 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS2");
    state->u.f4.fld.bsrr.bs3 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS3");
    state->u.f4.fld.bsrr.bs4 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS4");
    state->u.f4.fld.bsrr.bs5 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS5");
    state->u.f4.fld.bsrr.bs6 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS6");
    state->u.f4.fld.bsrr.bs7 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS7");
    state->u.f4.fld.bsrr.bs8 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS8");
    state->u.f4.fld.bsrr.bs9 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS9");
    state->u.f4.fld.bsrr.bs10 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BS10");
    state->u.f4.fld.bsrr.bs11 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BS11");
    state->u.f4.fld.bsrr.bs12 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BS12");
    state->u.f4.fld.bsrr.bs13 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BS13");
    state->u.f4.fld.bsrr.bs14 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BS14");
    state->u.f4.fld.bsrr.bs15 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BS15");
    state->u.f4.fld.bsrr.br0 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR0");
    state->u.f4.fld.bsrr.br1 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR1");
    state->u.f4.fld.bsrr.br2 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR2");
    state->u.f4.fld.bsrr.br3 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR3");
    state->u.f4.fld.bsrr.br4 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR4");
    state->u.f4.fld.bsrr.br5 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR5");
    state->u.f4.fld.bsrr.br6 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR6");
    state->u.f4.fld.bsrr.br7 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR7");
    state->u.f4.fld.bsrr.br8 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR8");
    state->u.f4.fld.bsrr.br9 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR9");
    state->u.f4.fld.bsrr.br10 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BR10");
    state->u.f4.fld.bsrr.br11 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BR11");
    state->u.f4.fld.bsrr.br12 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BR12");
    state->u.f4.fld.bsrr.br13 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BR13");
    state->u.f4.fld.bsrr.br14 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BR14");
    state->u.f4.fld.bsrr.br15 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BR15");

    // LCKR bitfields.
    state->u.f4.fld.lckr.lck0 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK0");
    state->u.f4.fld.lckr.lck1 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK1");
    state->u.f4.fld.lckr.lck2 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK2");
    state->u.f4.fld.lckr.lck3 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK3");
    state->u.f4.fld.lckr.lck4 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK4");
    state->u.f4.fld.lckr.lck5 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK5");
    state->u.f4.fld.lckr.lck6 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK6");
    state->u.f4.fld.lckr.lck7 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK7");
    state->u.f4.fld.lckr.lck8 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK8");
    state->u.f4.fld.lckr.lck9 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK9");
    state->u.f4.fld.lckr.lck10 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK10");
    state->u.f4.fld.lckr.lck11 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK11");
    state->u.f4.fld.lckr.lck12 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK12");
    state->u.f4.fld.lckr.lck13 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK13");
    state->u.f4.fld.lckr.lck14 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK14");
    state->u.f4.fld.lckr.lck15 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK15");
    state->u.f4.fld.lckr.lckk = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCKK");

    // AFRL bitfields.
    state->u.f4.fld.afrl.afrl0 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL0");
    state->u.f4.fld.afrl.afrl1 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL1");
    state->u.f4.fld.afrl.afrl2 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL2");
    state->u.f4.fld.afrl.afrl3 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL3");
    state->u.f4.fld.afrl.afrl4 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL4");
    state->u.f4.fld.afrl.afrl5 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL5");
    state->u.f4.fld.afrl.afrl6 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL6");
    state->u.f4.fld.afrl.afrl7 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL7");

    // AFRH bitfields.
    state->u.f4.fld.afrh.afrh8 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH8");
    state->u.f4.fld.afrh.afrh9 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH9");
    state->u.f4.fld.afrh.afrh10 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH10");
    state->u.f4.fld.afrh.afrh11 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH11");
    state->u.f4.fld.afrh.afrh12 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH12");
    state->u.f4.fld.afrh.afrh13 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH13");
    state->u.f4.fld.afrh.afrh14 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH14");
    state->u.f4.fld.afrh.afrh15 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH15");
}

// ----------------------------------------------------------------------------

// STM32F411RE
// DO NOT EDIT! Automatically generated!
static void stm32f411xx_gpio_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f4.reg.moder = cm_object_get_child_by_name(obj, "MODER");
    state->u.f4.reg.otyper = cm_object_get_child_by_name(obj, "OTYPER");
    state->u.f4.reg.ospeedr = cm_object_get_child_by_name(obj, "OSPEEDR");
    state->u.f4.reg.pupdr = cm_object_get_child_by_name(obj, "PUPDR");
    state->u.f4.reg.idr = cm_object_get_child_by_name(obj, "IDR");
    state->u.f4.reg.odr = cm_object_get_child_by_name(obj, "ODR");
    state->u.f4.reg.bsrr = cm_object_get_child_by_name(obj, "BSRR");
    state->u.f4.reg.lckr = cm_object_get_child_by_name(obj, "LCKR");
    state->u.f4.reg.afrl = cm_object_get_child_by_name(obj, "AFRL");
    state->u.f4.reg.afrh = cm_object_get_child_by_name(obj, "AFRH");

    // MODER bitfields.
    state->u.f4.fld.moder.moder0 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER0");
    state->u.f4.fld.moder.moder1 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER1");
    state->u.f4.fld.moder.moder2 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER2");
    state->u.f4.fld.moder.moder3 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER3");
    state->u.f4.fld.moder.moder4 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER4");
    state->u.f4.fld.moder.moder5 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER5");
    state->u.f4.fld.moder.moder6 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER6");
    state->u.f4.fld.moder.moder7 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER7");
    state->u.f4.fld.moder.moder8 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER8");
    state->u.f4.fld.moder.moder9 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER9");
    state->u.f4.fld.moder.moder10 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER10");
    state->u.f4.fld.moder.moder11 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER11");
    state->u.f4.fld.moder.moder12 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER12");
    state->u.f4.fld.moder.moder13 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER13");
    state->u.f4.fld.moder.moder14 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER14");
    state->u.f4.fld.moder.moder15 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER15");

    // OTYPER bitfields.
    state->u.f4.fld.otyper.ot0 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT0");
    state->u.f4.fld.otyper.ot1 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT1");
    state->u.f4.fld.otyper.ot2 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT2");
    state->u.f4.fld.otyper.ot3 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT3");
    state->u.f4.fld.otyper.ot4 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT4");
    state->u.f4.fld.otyper.ot5 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT5");
    state->u.f4.fld.otyper.ot6 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT6");
    state->u.f4.fld.otyper.ot7 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT7");
    state->u.f4.fld.otyper.ot8 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT8");
    state->u.f4.fld.otyper.ot9 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT9");
    state->u.f4.fld.otyper.ot10 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT10");
    state->u.f4.fld.otyper.ot11 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT11");
    state->u.f4.fld.otyper.ot12 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT12");
    state->u.f4.fld.otyper.ot13 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT13");
    state->u.f4.fld.otyper.ot14 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT14");
    state->u.f4.fld.otyper.ot15 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT15");

    // OSPEEDR bitfields.
    state->u.f4.fld.ospeedr.ospeedr0 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR0");
    state->u.f4.fld.ospeedr.ospeedr1 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR1");
    state->u.f4.fld.ospeedr.ospeedr2 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR2");
    state->u.f4.fld.ospeedr.ospeedr3 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR3");
    state->u.f4.fld.ospeedr.ospeedr4 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR4");
    state->u.f4.fld.ospeedr.ospeedr5 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR5");
    state->u.f4.fld.ospeedr.ospeedr6 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR6");
    state->u.f4.fld.ospeedr.ospeedr7 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR7");
    state->u.f4.fld.ospeedr.ospeedr8 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR8");
    state->u.f4.fld.ospeedr.ospeedr9 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR9");
    state->u.f4.fld.ospeedr.ospeedr10 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR10");
    state->u.f4.fld.ospeedr.ospeedr11 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR11");
    state->u.f4.fld.ospeedr.ospeedr12 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR12");
    state->u.f4.fld.ospeedr.ospeedr13 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR13");
    state->u.f4.fld.ospeedr.ospeedr14 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR14");
    state->u.f4.fld.ospeedr.ospeedr15 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR15");

    // PUPDR bitfields.
    state->u.f4.fld.pupdr.pupdr0 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR0");
    state->u.f4.fld.pupdr.pupdr1 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR1");
    state->u.f4.fld.pupdr.pupdr2 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR2");
    state->u.f4.fld.pupdr.pupdr3 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR3");
    state->u.f4.fld.pupdr.pupdr4 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR4");
    state->u.f4.fld.pupdr.pupdr5 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR5");
    state->u.f4.fld.pupdr.pupdr6 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR6");
    state->u.f4.fld.pupdr.pupdr7 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR7");
    state->u.f4.fld.pupdr.pupdr8 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR8");
    state->u.f4.fld.pupdr.pupdr9 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR9");
    state->u.f4.fld.pupdr.pupdr10 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR10");
    state->u.f4.fld.pupdr.pupdr11 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR11");
    state->u.f4.fld.pupdr.pupdr12 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR12");
    state->u.f4.fld.pupdr.pupdr13 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR13");
    state->u.f4.fld.pupdr.pupdr14 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR14");
    state->u.f4.fld.pupdr.pupdr15 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR15");

    // IDR bitfields.
    state->u.f4.fld.idr.idr0 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR0");
    state->u.f4.fld.idr.idr1 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR1");
    state->u.f4.fld.idr.idr2 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR2");
    state->u.f4.fld.idr.idr3 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR3");
    state->u.f4.fld.idr.idr4 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR4");
    state->u.f4.fld.idr.idr5 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR5");
    state->u.f4.fld.idr.idr6 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR6");
    state->u.f4.fld.idr.idr7 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR7");
    state->u.f4.fld.idr.idr8 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR8");
    state->u.f4.fld.idr.idr9 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR9");
    state->u.f4.fld.idr.idr10 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR10");
    state->u.f4.fld.idr.idr11 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR11");
    state->u.f4.fld.idr.idr12 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR12");
    state->u.f4.fld.idr.idr13 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR13");
    state->u.f4.fld.idr.idr14 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR14");
    state->u.f4.fld.idr.idr15 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR15");

    // ODR bitfields.
    state->u.f4.fld.odr.odr0 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR0");
    state->u.f4.fld.odr.odr1 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR1");
    state->u.f4.fld.odr.odr2 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR2");
    state->u.f4.fld.odr.odr3 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR3");
    state->u.f4.fld.odr.odr4 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR4");
    state->u.f4.fld.odr.odr5 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR5");
    state->u.f4.fld.odr.odr6 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR6");
    state->u.f4.fld.odr.odr7 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR7");
    state->u.f4.fld.odr.odr8 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR8");
    state->u.f4.fld.odr.odr9 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR9");
    state->u.f4.fld.odr.odr10 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR10");
    state->u.f4.fld.odr.odr11 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR11");
    state->u.f4.fld.odr.odr12 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR12");
    state->u.f4.fld.odr.odr13 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR13");
    state->u.f4.fld.odr.odr14 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR14");
    state->u.f4.fld.odr.odr15 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR15");

    // BSRR bitfields.
    state->u.f4.fld.bsrr.bs0 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS0");
    state->u.f4.fld.bsrr.bs1 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS1");
    state->u.f4.fld.bsrr.bs2 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS2");
    state->u.f4.fld.bsrr.bs3 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS3");
    state->u.f4.fld.bsrr.bs4 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS4");
    state->u.f4.fld.bsrr.bs5 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS5");
    state->u.f4.fld.bsrr.bs6 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS6");
    state->u.f4.fld.bsrr.bs7 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS7");
    state->u.f4.fld.bsrr.bs8 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS8");
    state->u.f4.fld.bsrr.bs9 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS9");
    state->u.f4.fld.bsrr.bs10 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BS10");
    state->u.f4.fld.bsrr.bs11 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BS11");
    state->u.f4.fld.bsrr.bs12 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BS12");
    state->u.f4.fld.bsrr.bs13 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BS13");
    state->u.f4.fld.bsrr.bs14 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BS14");
    state->u.f4.fld.bsrr.bs15 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BS15");
    state->u.f4.fld.bsrr.br0 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR0");
    state->u.f4.fld.bsrr.br1 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR1");
    state->u.f4.fld.bsrr.br2 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR2");
    state->u.f4.fld.bsrr.br3 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR3");
    state->u.f4.fld.bsrr.br4 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR4");
    state->u.f4.fld.bsrr.br5 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR5");
    state->u.f4.fld.bsrr.br6 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR6");
    state->u.f4.fld.bsrr.br7 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR7");
    state->u.f4.fld.bsrr.br8 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR8");
    state->u.f4.fld.bsrr.br9 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR9");
    state->u.f4.fld.bsrr.br10 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BR10");
    state->u.f4.fld.bsrr.br11 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BR11");
    state->u.f4.fld.bsrr.br12 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BR12");
    state->u.f4.fld.bsrr.br13 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BR13");
    state->u.f4.fld.bsrr.br14 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BR14");
    state->u.f4.fld.bsrr.br15 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BR15");

    // LCKR bitfields.
    state->u.f4.fld.lckr.lck0 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK0");
    state->u.f4.fld.lckr.lck1 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK1");
    state->u.f4.fld.lckr.lck2 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK2");
    state->u.f4.fld.lckr.lck3 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK3");
    state->u.f4.fld.lckr.lck4 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK4");
    state->u.f4.fld.lckr.lck5 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK5");
    state->u.f4.fld.lckr.lck6 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK6");
    state->u.f4.fld.lckr.lck7 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK7");
    state->u.f4.fld.lckr.lck8 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK8");
    state->u.f4.fld.lckr.lck9 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK9");
    state->u.f4.fld.lckr.lck10 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK10");
    state->u.f4.fld.lckr.lck11 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK11");
    state->u.f4.fld.lckr.lck12 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK12");
    state->u.f4.fld.lckr.lck13 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK13");
    state->u.f4.fld.lckr.lck14 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK14");
    state->u.f4.fld.lckr.lck15 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK15");
    state->u.f4.fld.lckr.lckk = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCKK");

    // AFRL bitfields.
    state->u.f4.fld.afrl.afrl0 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL0");
    state->u.f4.fld.afrl.afrl1 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL1");
    state->u.f4.fld.afrl.afrl2 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL2");
    state->u.f4.fld.afrl.afrl3 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL3");
    state->u.f4.fld.afrl.afrl4 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL4");
    state->u.f4.fld.afrl.afrl5 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL5");
    state->u.f4.fld.afrl.afrl6 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL6");
    state->u.f4.fld.afrl.afrl7 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL7");

    // AFRH bitfields.
    state->u.f4.fld.afrh.afrh8 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH8");
    state->u.f4.fld.afrh.afrh9 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH9");
    state->u.f4.fld.afrh.afrh10 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH10");
    state->u.f4.fld.afrh.afrh11 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH11");
    state->u.f4.fld.afrh.afrh12 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH12");
    state->u.f4.fld.afrh.afrh13 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH13");
    state->u.f4.fld.afrh.afrh14 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH14");
    state->u.f4.fld.afrh.afrh15 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH15");
}

// ----------------------------------------------------------------------------

// STM32F429ZI
// DO NOT EDIT! Automatically generated!
static void stm32f429x_gpio_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f4.reg.moder = cm_object_get_child_by_name(obj, "MODER");
    state->u.f4.reg.otyper = cm_object_get_child_by_name(obj, "OTYPER");
    state->u.f4.reg.ospeedr = cm_object_get_child_by_name(obj, "OSPEEDR");
    state->u.f4.reg.pupdr = cm_object_get_child_by_name(obj, "PUPDR");
    state->u.f4.reg.idr = cm_object_get_child_by_name(obj, "IDR");
    state->u.f4.reg.odr = cm_object_get_child_by_name(obj, "ODR");
    state->u.f4.reg.bsrr = cm_object_get_child_by_name(obj, "BSRR");
    state->u.f4.reg.lckr = cm_object_get_child_by_name(obj, "LCKR");
    state->u.f4.reg.afrl = cm_object_get_child_by_name(obj, "AFRL");
    state->u.f4.reg.afrh = cm_object_get_child_by_name(obj, "AFRH");

    // MODER bitfields.
    state->u.f4.fld.moder.moder0 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER0");
    state->u.f4.fld.moder.moder1 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER1");
    state->u.f4.fld.moder.moder2 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER2");
    state->u.f4.fld.moder.moder3 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER3");
    state->u.f4.fld.moder.moder4 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER4");
    state->u.f4.fld.moder.moder5 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER5");
    state->u.f4.fld.moder.moder6 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER6");
    state->u.f4.fld.moder.moder7 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER7");
    state->u.f4.fld.moder.moder8 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER8");
    state->u.f4.fld.moder.moder9 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER9");
    state->u.f4.fld.moder.moder10 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER10");
    state->u.f4.fld.moder.moder11 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER11");
    state->u.f4.fld.moder.moder12 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER12");
    state->u.f4.fld.moder.moder13 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER13");
    state->u.f4.fld.moder.moder14 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER14");
    state->u.f4.fld.moder.moder15 = cm_object_get_child_by_name(
            state->u.f4.reg.moder, "MODER15");

    // OTYPER bitfields.
    state->u.f4.fld.otyper.ot0 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT0");
    state->u.f4.fld.otyper.ot1 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT1");
    state->u.f4.fld.otyper.ot2 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT2");
    state->u.f4.fld.otyper.ot3 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT3");
    state->u.f4.fld.otyper.ot4 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT4");
    state->u.f4.fld.otyper.ot5 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT5");
    state->u.f4.fld.otyper.ot6 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT6");
    state->u.f4.fld.otyper.ot7 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT7");
    state->u.f4.fld.otyper.ot8 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT8");
    state->u.f4.fld.otyper.ot9 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT9");
    state->u.f4.fld.otyper.ot10 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT10");
    state->u.f4.fld.otyper.ot11 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT11");
    state->u.f4.fld.otyper.ot12 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT12");
    state->u.f4.fld.otyper.ot13 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT13");
    state->u.f4.fld.otyper.ot14 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT14");
    state->u.f4.fld.otyper.ot15 = cm_object_get_child_by_name(
            state->u.f4.reg.otyper, "OT15");

    // OSPEEDR bitfields.
    state->u.f4.fld.ospeedr.ospeedr0 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR0");
    state->u.f4.fld.ospeedr.ospeedr1 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR1");
    state->u.f4.fld.ospeedr.ospeedr2 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR2");
    state->u.f4.fld.ospeedr.ospeedr3 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR3");
    state->u.f4.fld.ospeedr.ospeedr4 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR4");
    state->u.f4.fld.ospeedr.ospeedr5 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR5");
    state->u.f4.fld.ospeedr.ospeedr6 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR6");
    state->u.f4.fld.ospeedr.ospeedr7 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR7");
    state->u.f4.fld.ospeedr.ospeedr8 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR8");
    state->u.f4.fld.ospeedr.ospeedr9 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR9");
    state->u.f4.fld.ospeedr.ospeedr10 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR10");
    state->u.f4.fld.ospeedr.ospeedr11 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR11");
    state->u.f4.fld.ospeedr.ospeedr12 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR12");
    state->u.f4.fld.ospeedr.ospeedr13 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR13");
    state->u.f4.fld.ospeedr.ospeedr14 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR14");
    state->u.f4.fld.ospeedr.ospeedr15 = cm_object_get_child_by_name(
            state->u.f4.reg.ospeedr, "OSPEEDR15");

    // PUPDR bitfields.
    state->u.f4.fld.pupdr.pupdr0 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR0");
    state->u.f4.fld.pupdr.pupdr1 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR1");
    state->u.f4.fld.pupdr.pupdr2 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR2");
    state->u.f4.fld.pupdr.pupdr3 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR3");
    state->u.f4.fld.pupdr.pupdr4 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR4");
    state->u.f4.fld.pupdr.pupdr5 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR5");
    state->u.f4.fld.pupdr.pupdr6 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR6");
    state->u.f4.fld.pupdr.pupdr7 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR7");
    state->u.f4.fld.pupdr.pupdr8 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR8");
    state->u.f4.fld.pupdr.pupdr9 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR9");
    state->u.f4.fld.pupdr.pupdr10 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR10");
    state->u.f4.fld.pupdr.pupdr11 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR11");
    state->u.f4.fld.pupdr.pupdr12 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR12");
    state->u.f4.fld.pupdr.pupdr13 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR13");
    state->u.f4.fld.pupdr.pupdr14 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR14");
    state->u.f4.fld.pupdr.pupdr15 = cm_object_get_child_by_name(
            state->u.f4.reg.pupdr, "PUPDR15");

    // IDR bitfields.
    state->u.f4.fld.idr.idr0 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR0");
    state->u.f4.fld.idr.idr1 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR1");
    state->u.f4.fld.idr.idr2 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR2");
    state->u.f4.fld.idr.idr3 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR3");
    state->u.f4.fld.idr.idr4 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR4");
    state->u.f4.fld.idr.idr5 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR5");
    state->u.f4.fld.idr.idr6 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR6");
    state->u.f4.fld.idr.idr7 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR7");
    state->u.f4.fld.idr.idr8 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR8");
    state->u.f4.fld.idr.idr9 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR9");
    state->u.f4.fld.idr.idr10 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR10");
    state->u.f4.fld.idr.idr11 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR11");
    state->u.f4.fld.idr.idr12 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR12");
    state->u.f4.fld.idr.idr13 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR13");
    state->u.f4.fld.idr.idr14 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR14");
    state->u.f4.fld.idr.idr15 = cm_object_get_child_by_name(state->u.f4.reg.idr,
            "IDR15");

    // ODR bitfields.
    state->u.f4.fld.odr.odr0 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR0");
    state->u.f4.fld.odr.odr1 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR1");
    state->u.f4.fld.odr.odr2 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR2");
    state->u.f4.fld.odr.odr3 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR3");
    state->u.f4.fld.odr.odr4 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR4");
    state->u.f4.fld.odr.odr5 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR5");
    state->u.f4.fld.odr.odr6 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR6");
    state->u.f4.fld.odr.odr7 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR7");
    state->u.f4.fld.odr.odr8 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR8");
    state->u.f4.fld.odr.odr9 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR9");
    state->u.f4.fld.odr.odr10 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR10");
    state->u.f4.fld.odr.odr11 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR11");
    state->u.f4.fld.odr.odr12 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR12");
    state->u.f4.fld.odr.odr13 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR13");
    state->u.f4.fld.odr.odr14 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR14");
    state->u.f4.fld.odr.odr15 = cm_object_get_child_by_name(state->u.f4.reg.odr,
            "ODR15");

    // BSRR bitfields.
    state->u.f4.fld.bsrr.bs0 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS0");
    state->u.f4.fld.bsrr.bs1 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS1");
    state->u.f4.fld.bsrr.bs2 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS2");
    state->u.f4.fld.bsrr.bs3 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS3");
    state->u.f4.fld.bsrr.bs4 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS4");
    state->u.f4.fld.bsrr.bs5 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS5");
    state->u.f4.fld.bsrr.bs6 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS6");
    state->u.f4.fld.bsrr.bs7 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS7");
    state->u.f4.fld.bsrr.bs8 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS8");
    state->u.f4.fld.bsrr.bs9 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BS9");
    state->u.f4.fld.bsrr.bs10 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BS10");
    state->u.f4.fld.bsrr.bs11 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BS11");
    state->u.f4.fld.bsrr.bs12 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BS12");
    state->u.f4.fld.bsrr.bs13 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BS13");
    state->u.f4.fld.bsrr.bs14 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BS14");
    state->u.f4.fld.bsrr.bs15 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BS15");
    state->u.f4.fld.bsrr.br0 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR0");
    state->u.f4.fld.bsrr.br1 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR1");
    state->u.f4.fld.bsrr.br2 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR2");
    state->u.f4.fld.bsrr.br3 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR3");
    state->u.f4.fld.bsrr.br4 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR4");
    state->u.f4.fld.bsrr.br5 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR5");
    state->u.f4.fld.bsrr.br6 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR6");
    state->u.f4.fld.bsrr.br7 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR7");
    state->u.f4.fld.bsrr.br8 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR8");
    state->u.f4.fld.bsrr.br9 = cm_object_get_child_by_name(state->u.f4.reg.bsrr,
            "BR9");
    state->u.f4.fld.bsrr.br10 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BR10");
    state->u.f4.fld.bsrr.br11 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BR11");
    state->u.f4.fld.bsrr.br12 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BR12");
    state->u.f4.fld.bsrr.br13 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BR13");
    state->u.f4.fld.bsrr.br14 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BR14");
    state->u.f4.fld.bsrr.br15 = cm_object_get_child_by_name(
            state->u.f4.reg.bsrr, "BR15");

    // LCKR bitfields.
    state->u.f4.fld.lckr.lck0 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK0");
    state->u.f4.fld.lckr.lck1 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK1");
    state->u.f4.fld.lckr.lck2 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK2");
    state->u.f4.fld.lckr.lck3 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK3");
    state->u.f4.fld.lckr.lck4 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK4");
    state->u.f4.fld.lckr.lck5 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK5");
    state->u.f4.fld.lckr.lck6 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK6");
    state->u.f4.fld.lckr.lck7 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK7");
    state->u.f4.fld.lckr.lck8 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK8");
    state->u.f4.fld.lckr.lck9 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK9");
    state->u.f4.fld.lckr.lck10 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK10");
    state->u.f4.fld.lckr.lck11 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK11");
    state->u.f4.fld.lckr.lck12 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK12");
    state->u.f4.fld.lckr.lck13 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK13");
    state->u.f4.fld.lckr.lck14 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK14");
    state->u.f4.fld.lckr.lck15 = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCK15");
    state->u.f4.fld.lckr.lckk = cm_object_get_child_by_name(
            state->u.f4.reg.lckr, "LCKK");

    // AFRL bitfields.
    state->u.f4.fld.afrl.afrl0 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL0");
    state->u.f4.fld.afrl.afrl1 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL1");
    state->u.f4.fld.afrl.afrl2 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL2");
    state->u.f4.fld.afrl.afrl3 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL3");
    state->u.f4.fld.afrl.afrl4 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL4");
    state->u.f4.fld.afrl.afrl5 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL5");
    state->u.f4.fld.afrl.afrl6 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL6");
    state->u.f4.fld.afrl.afrl7 = cm_object_get_child_by_name(
            state->u.f4.reg.afrl, "AFRL7");

    // AFRH bitfields.
    state->u.f4.fld.afrh.afrh8 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH8");
    state->u.f4.fld.afrh.afrh9 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH9");
    state->u.f4.fld.afrh.afrh10 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH10");
    state->u.f4.fld.afrh.afrh11 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH11");
    state->u.f4.fld.afrh.afrh12 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH12");
    state->u.f4.fld.afrh.afrh13 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH13");
    state->u.f4.fld.afrh.afrh14 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH14");
    state->u.f4.fld.afrh.afrh15 = cm_object_get_child_by_name(
            state->u.f4.reg.afrh, "AFRH15");
}

// ----- Public ---------------------------------------------------------------

// Create GPIO%c and return it.

Object* stm32_gpio_create(Object *parent, stm32_gpio_index_t index)
{
    if ((int) index >= STM32_PORT_GPIO_UNDEFINED) {
        hw_error("Cannot assign GPIO%c: QEMU supports only %d ports\n",
                'A' + index, STM32_PORT_GPIO_UNDEFINED);
    }

    char child_name[10];
    snprintf(child_name, sizeof(child_name) - 1, "GPIO%c",
            'A' + index - STM32_PORT_GPIOA);
    // Passing a local string is ok.
    Object *gpio = cm_object_new(parent, child_name, TYPE_STM32_GPIO);
    int i;

    object_property_set_int(gpio, index, "port-index", NULL);

    cm_object_realize(gpio);

    for (i = 0; i < STM32_GPIO_PIN_COUNT; ++i) {
        /* Connect GPIO outgoing to EXTI incoming. */
        cm_irq_connect(DEVICE(gpio), STM32_IRQ_GPIO_EXTI_OUT, i,
                cm_device_by_name(DEVICE_PATH_STM32_EXTI), STM32_IRQ_EXTI_IN,
                i);
    }

    return gpio;
}

// Return a pointer to the GPIO%c object, or null if not found.

Object* stm32_gpio_get(int index)
{
    char gpio_name[40];
    snprintf(gpio_name, sizeof(gpio_name), DEVICE_PATH_STM32 "GPIO%c",
            'A' + index - STM32_PORT_GPIOA);
    return object_resolve_path(gpio_name, NULL);
}

// ----- Private --------------------------------------------------------------

static void stm32_gpio_update_idr(STM32GPIOState *state, Object *idr,
        uint16_t new_odr);

static void stm32_gpio_set_odr_irqs(STM32GPIOState *state, uint16_t old_odr,
        uint16_t new_odr);

static void stm32_gpio_update_odr_and_idr(STM32GPIOState *state, Object *odr,
        Object *idr, uint16_t new_value);

// ----------------------------------------------------------------------------

static bool stm32_gpio_is_enabled(Object *obj)
{
    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32f0_gpio_brr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    Object *odr = state->reg.odr;
    assert(odr);

    // 'value' may be have any size, use full_word.
    uint32_t bits_to_reset = (full_value & 0x0000FFFF);

    // Clear the BR bits.
    uint32_t new_value = (peripheral_register_get_raw_value(odr)
            & (~bits_to_reset));
    stm32_gpio_update_odr_and_idr(state, odr, state->reg.idr, new_value);
}

// ----------------------------------------------------------------------------

// STM32F1[LMHX]D, STM32F1CL

//  The F1 peripheral registers must be accessed only as words (32-bit).

static void stm32f1_gpio_update_dir_mask(STM32GPIOState *state, int index);

static void stm32f1_gpio_crl_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    stm32f1_gpio_update_dir_mask(state, 0);
}

static void stm32f1_gpio_crh_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    stm32f1_gpio_update_dir_mask(state, 1);
}

static void stm32f1_gpio_odr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    Object *odr = state->u.f1.reg.odr;
    assert(odr);

    uint16_t prev_value = peripheral_register_get_raw_prev_value(odr);

    stm32_gpio_set_odr_irqs(state, prev_value, full_value);
    stm32_gpio_update_idr(state, state->u.f1.reg.idr, full_value);
}

static void stm32f1_gpio_bsrr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    Object *odr = state->u.f1.reg.odr;
    assert(odr);

    // Although 'value' is known to be 32-bits, for consistency use full_value
    uint32_t bits_to_set = (full_value & 0x0000FFFF);
    uint32_t bits_to_reset = ((full_value >> 16) & 0x0000FFFF);

    // Clear the BR bits and set the BS bits.
    uint32_t new_value = (peripheral_register_get_raw_value(odr)
            & (~bits_to_reset)) | bits_to_set;
    stm32_gpio_update_odr_and_idr(state, odr, state->u.f1.reg.idr, new_value);
}

static void stm32f1_gpio_brr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    Object *odr = state->u.f1.reg.odr;
    assert(odr);

    // Although 'value' is known to be 32-bits, for consistency use full_value
    uint32_t bits_to_reset = (full_value & 0x0000FFFF);

    // Clear the BR bits.
    uint32_t new_value = peripheral_register_get_raw_value(odr)
            & ~bits_to_reset;
    stm32_gpio_update_odr_and_idr(state, odr, state->u.f1.reg.idr, new_value);
}

// ----------------------------------------------------------------------------

// Gets the four configuration bits for the pin from the CRL or CRH
// register.

static uint32_t stm32f1_gpio_get_pin_config(STM32GPIOState *state, unsigned pin)
{
    // Simplify extract logic by combining both 32 bit registers into
    // one 64 bit value.

    uint64_t cr_64 = ((uint64_t) peripheral_register_get_raw_value(
            state->u.f1.reg.crh) << 32)
            | (peripheral_register_get_raw_value(state->u.f1.reg.crl)
                    & 0xFFFFFFFF);
    return extract64(cr_64, pin * 4, 4);
}

/*
 * Configuration bits:
 * - in input mode:
 *   00: analog mode
 *   01: floating input (reset)
 *   10: Input with pull-up/pull-down
 *   11: Reserved
 * - in output mode:
 *   00: general purpose output push-pull
 *   01: general purpose output open-drain
 *   10: alternate function output push-pull
 *   11: alternate function output open-drain
 */
static uint32_t __attribute__ ((unused)) stm32f1_gpio_get_config_bits(
        STM32GPIOState *state, unsigned pin)
{
    return (stm32f1_gpio_get_pin_config(state, pin) >> 2) & 0x3;
}

/*
 * Modes are:
 * 00: input (reset)
 * 01: output, 10 MHz
 * 10: output, 2 MHz
 * 11: output, 50 MHz
 */
static uint32_t stm32f1_gpio_get_mode_bits(STM32GPIOState *state, unsigned pin)
{
    return stm32f1_gpio_get_pin_config(state, pin) & 0x3;
}

/*
 * Update the direction mask, cached for performance reasons.
 *
 * Must be called after each CR[LH] changes.
 *
 * index == 0 - CRL
 * index == 1 - CRH
 */
static void stm32f1_gpio_update_dir_mask(STM32GPIOState *state, int index)
{
    assert((index == 0) || (index == 1));

    unsigned start_pin = index * 8;
    unsigned pin_dir;
    int pin;

    for (pin = start_pin; pin < start_pin + 8; pin++) {
        pin_dir = stm32f1_gpio_get_mode_bits(state, pin);
        // If the mode is 0, the pin is input.  Otherwise, it
        // is output.
        if (pin_dir == 0) {
            state->dir_mask &= ~(1 << pin); // Input pin
        } else {
            state->dir_mask |= (1 << pin); // Output pin
        }
    }
}

// ----------------------------------------------------------------------------

// STM32F4[01][57]xx, STM32F4[23]xxx, STM32F411xx

static uint32_t stm32f4_gpio_get_config_bits(uint32_t value, uint32_t bit);
static void stm32f4_gpio_update_dir_mask(STM32GPIOState *state);

static void stm32f4_gpio_moder_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    stm32f4_gpio_update_dir_mask(state);
}

static void stm32f4_gpio_odr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    Object *odr = state->reg.odr;
    assert(odr);

    uint16_t prev_value = peripheral_register_get_raw_prev_value(odr);

    // 'value' may be have any size, use full_word.
    stm32_gpio_set_odr_irqs(state, prev_value, full_value);
    stm32_gpio_update_idr(state, state->reg.idr, full_value);
}

static void stm32f4_gpio_bsrr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    Object *odr = state->reg.odr;
    assert(odr);

    // 'value' may be have any size, use full_word.
    uint32_t bits_to_set = (full_value & 0x0000FFFF);
    uint32_t bits_to_reset = ((full_value >> 16) & 0x0000FFFF);

    // Clear the BR bits and set the BS bits.
    uint32_t new_value = (peripheral_register_get_raw_value(odr)
            & (~bits_to_reset)) | bits_to_set;
    stm32_gpio_update_odr_and_idr(state, odr, state->reg.idr, new_value);
}

// ----------------------------------------------------------------------------

// The F4 family has more uniform configuration registers, each
// register bit has a 2-bits slice in a register.
static uint32_t stm32f4_gpio_get_config_bits(uint32_t value, uint32_t bit)
{
    assert(bit < 16);
    return (value >> (bit * 2)) & 0x3;
}

// Update the cached direction mask on MODER changes.

static void stm32f4_gpio_update_dir_mask(STM32GPIOState *state)
{
    uint32_t moder = peripheral_register_get_raw_value(state->reg.moder);

    // Fully recompute the direction mask.
    int bit;
    uint32_t mode;
    for (bit = 0; bit < 16; bit++) {
        mode = stm32f4_gpio_get_config_bits(moder, bit);
        // If the mode is 1, the bit is output. Otherwise, it
        // is input or has alternate functions.

        if (mode == 1) {
            state->dir_mask |= (1 << bit); // Output pin
        } else {
            state->dir_mask &= ~(1 << bit); // Input pin
        }
    }
}

// ----------------------------------------------------------------------------

// Write the ODR register and trigger interrupts for changed pins
// (output only).
//
// The odr pointer is passed to make the function useful for other
// families too.

static void stm32_gpio_update_odr_and_idr(STM32GPIOState *state, Object *odr,
        Object *idr, uint16_t new_value)
{
    assert(odr);

    // Preserve old value, to compute changed bits
    uint16_t old_value = peripheral_register_get_raw_value(odr);

    // Update register value. Per documentation, the upper 16 bits
    // always read as 0, so write is used, to apply the mask.
    peripheral_register_write_value(odr, new_value);

    stm32_gpio_set_odr_irqs(state, old_value, new_value);
    stm32_gpio_update_idr(state, idr, new_value);
}

// If EXTI is sensitive to this GPIO pin, set interrupt.
static void stm32_gpio_set_exti_irq(STM32GPIOState *state, int pin, int level)
{
    assert(pin < 16);

    const STM32Capabilities *capabilities = state->capabilities;

    // Implement the SYSCFG/AFIO multiplexers at origin, in GPIO,
    // instead of forwarding all interrupts to EXTI to be rejected there.

    peripheral_register_t exti = 0;
    if (capabilities->family == STM32_FAMILY_F1) {
        exti = register_bitfield_read_value(state->afio->exticr.exti[pin]);
    } else {
        exti = register_bitfield_read_value(state->syscfg->exticr.exti[pin]);
    }
    if (exti == (state->port_index - STM32_PORT_GPIOA)) {
        cm_irq_set(state->exti_irq[pin], level);
    }
}

// Identify ODR bits that changed, then notify listeners (like LEDs)
// and trigger interrupts.
static void stm32_gpio_set_odr_irqs(STM32GPIOState *state, uint16_t old_odr,
        uint16_t new_odr)
{
    // Compute pins that changed value.
    uint16_t changed = old_odr ^ new_odr;

    // Filter changed pins that are outputs - do not touch input pins.
    uint16_t changed_out = changed & state->dir_mask;

    uint16_t mask = 1;
    if (changed_out) {
        int pin;
        for (pin = 0; pin < STM32_GPIO_PIN_COUNT; pin++, mask <<= 1) {
            // If the value of this pin has changed, then update
            // the output IRQ.
            if ((changed_out & mask) != 0) {
                int level = (new_odr & mask) ? 1 : 0;

                cm_irq_set(state->odr_irq[pin], level);

                stm32_gpio_set_exti_irq(state, pin, level);
            }
        }
    }
}

// For output pins, make them read back the written value.
//
// TODO: check if there is anything special for open-drain pins.

static void stm32_gpio_update_idr(STM32GPIOState *state, Object *idr,
        uint16_t new_odr)
{
    assert(idr);

    // Clear output bits.
    peripheral_register_and_raw_value(idr, ~state->dir_mask);
    // Copy output bits from ODR.
    peripheral_register_or_raw_value(idr, (new_odr & state->dir_mask));
}

// Callback fired when a GPIO input pin changes state (based
// on an external stimulus from the machine).
static void stm32_gpio_in_irq_handler(void *opaque, int n, int level)
{
    qemu_log_mask(LOG_FUNC, "%s(%d,%d) \n", __FUNCTION__, n, level);

    assert(n < 16);

    STM32GPIOState *state = STM32_GPIO_STATE(opaque);
    unsigned pin = n;

    assert(pin < STM32_GPIO_PIN_COUNT);

    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *idr;
    // Update internal pin state.
    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        idr = state->u.f0.reg.idr;
        break;

    case STM32_FAMILY_F1:

        idr = state->u.f1.reg.idr;
        break;

    case STM32_FAMILY_F4:

        idr = state->u.f4.reg.idr;
        break;

    default:
        assert(false);
        return;
    }

    // TODO: check if a mutex is needed,
    // this can be called from the graphic thread.
    if (level == 0) {
        // Clear the IDR bit.
        peripheral_register_and_raw_value(idr, ~(1 << pin));
    } else {
        // Set the IDR bit.
        peripheral_register_or_raw_value(idr, (1 << pin));
    }

    stm32_gpio_set_exti_irq(state, pin, level);
}

// ----------------------------------------------------------------------------

static void stm32_gpio_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    cm_object_property_add_int(obj, "port-index",
            (const int *) &state->port_index);
    state->port_index = STM32_PORT_GPIO_UNDEFINED;

    cm_irq_init_in(DEVICE(obj), stm32_gpio_in_irq_handler,
    STM32_IRQ_GPIO_IDR_IN, STM32_GPIO_PIN_COUNT);

    // Outgoing interrupts, will be later connected to EXTI.
    cm_irq_init_out(DEVICE(obj), state->exti_irq, STM32_IRQ_GPIO_EXTI_OUT,
    STM32_GPIO_PIN_COUNT);

    // Outgoing interrupts, machine devices like LEDs might
    // be connected here.
    cm_irq_init_out(DEVICE(obj), state->odr_irq, STM32_IRQ_GPIO_ODR_OUT,
    STM32_GPIO_PIN_COUNT);

    state->enabling_bit = NULL;

    state->syscfg = NULL;
    state->afio = NULL;

    state->dir_mask = 0;

    state->reg.moder = NULL;
    state->reg.otyper = NULL;
    state->reg.ospeeder = NULL;
    state->reg.pupdr = NULL;
    state->reg.idr = NULL;
    state->reg.odr = NULL;
    state->reg.bsrr = NULL;
    state->reg.lckr = NULL;
    state->reg.afrl = NULL;
    state->reg.afrh = NULL;
    state->reg.brr = NULL;
}

static void stm32_gpio_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_GPIO)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32GPIOState *state = STM32_GPIO_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    char periph_name[10];
    snprintf(periph_name, sizeof(periph_name) - 1, "GPIO%c",
            'A' + state->port_index);

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // Must be defined before creating registers.
    cm_object_property_set_int(obj, 4, "register-size-bytes");

    // TODO: get it from MCU
    cm_object_property_set_bool(obj, true, "is-little-endian");

    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x1) {

            stm32f0x1_gpio_create_objects(obj, cm_state->svd_json, periph_name);

            state->reg.moder = state->u.f0.reg.moder;
            state->reg.otyper = state->u.f0.reg.otyper;
            state->reg.ospeeder = state->u.f0.reg.ospeedr;
            state->reg.pupdr = state->u.f0.reg.pupdr;
            state->reg.idr = state->u.f0.reg.idr;
            state->reg.odr = state->u.f0.reg.odr;
            state->reg.bsrr = state->u.f0.reg.bsrr;
            state->reg.lckr = state->u.f0.reg.lckr;
            state->reg.afrl = state->u.f0.reg.afrl;
            state->reg.afrh = state->u.f0.reg.afrh;
            state->reg.brr = state->u.f0.reg.brr;

            // Add callbacks. Use some of the F4 callbacks.
            peripheral_register_set_post_write(state->reg.moder,
                    &stm32f4_gpio_moder_post_write_callback);
            peripheral_register_set_post_write(state->reg.odr,
                    &stm32f4_gpio_odr_post_write_callback);
            peripheral_register_set_post_write(state->reg.bsrr,
                    &stm32f4_gpio_bsrr_post_write_callback);

            // F0 specific.
            peripheral_register_set_post_write(state->reg.brr,
                    &stm32f0_gpio_brr_post_write_callback);

        } else {
            assert(false);
        }

        state->syscfg = STM32_SYSCFG_STATE(
                cm_device_by_name(DEVICE_PATH_STM32_SYSCFG));

        snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHBENR/IOP%cEN",
                'A' + state->port_index - STM32_PORT_GPIOA);

        break;

    case STM32_FAMILY_F1:

        if (capabilities->f1.is_103xx) {

            stm32f103xx_gpio_create_objects(obj, cm_state->svd_json,
                    periph_name);

        } else if (capabilities->f1.is_107xx) {

            stm32f107xx_gpio_create_objects(obj, cm_state->svd_json,
                    periph_name);

        } else {
            assert(false);
        }

        // Add callbacks.
        peripheral_register_set_post_write(state->u.f1.reg.crl,
                &stm32f1_gpio_crl_post_write_callback);
        peripheral_register_set_post_write(state->u.f1.reg.crh,
                &stm32f1_gpio_crh_post_write_callback);
        peripheral_register_set_post_write(state->u.f1.reg.odr,
                &stm32f1_gpio_odr_post_write_callback);
        peripheral_register_set_post_write(state->u.f1.reg.bsrr,
                &stm32f1_gpio_bsrr_post_write_callback);
        peripheral_register_set_post_write(state->u.f1.reg.brr,
                &stm32f1_gpio_brr_post_write_callback);

        state->afio = STM32_AFIO_STATE(
                cm_device_by_name(DEVICE_PATH_STM32_AFIO));

        snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/APB2ENR/IOP%cEN",
                'A' + state->port_index - STM32_PORT_GPIOA);

        break;

    case STM32_FAMILY_F4:

        if (capabilities->f4.is_40x) {

            stm32f40x_gpio_create_objects(obj, cm_state->svd_json, periph_name);

        } else if (capabilities->f4.is_411xx) {

            stm32f411xx_gpio_create_objects(obj, cm_state->svd_json,
                    periph_name);

        } else if (capabilities->f4.is_429x) {

            stm32f429x_gpio_create_objects(obj, cm_state->svd_json,
                    periph_name);

        } else {
            assert(false);
        }

        state->reg.moder = state->u.f4.reg.moder;
        state->reg.otyper = state->u.f4.reg.otyper;
        state->reg.ospeeder = state->u.f4.reg.ospeedr;
        state->reg.pupdr = state->u.f4.reg.pupdr;
        state->reg.idr = state->u.f4.reg.idr;
        state->reg.odr = state->u.f4.reg.odr;
        state->reg.bsrr = state->u.f4.reg.bsrr;
        state->reg.lckr = state->u.f4.reg.lckr;
        state->reg.afrl = state->u.f4.reg.afrl;
        state->reg.afrh = state->u.f4.reg.afrh;

        // Add callbacks.
        peripheral_register_set_post_write(state->reg.moder,
                &stm32f4_gpio_moder_post_write_callback);
        peripheral_register_set_post_write(state->reg.odr,
                &stm32f4_gpio_odr_post_write_callback);
        peripheral_register_set_post_write(state->reg.bsrr,
                &stm32f4_gpio_bsrr_post_write_callback);

        state->syscfg = STM32_SYSCFG_STATE(
                cm_device_by_name(DEVICE_PATH_STM32_SYSCFG));

        snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/GPIO%cEN",
                'A' + state->port_index - STM32_PORT_GPIOA);

        break;

    default:
        assert(false);
        break;
    }

    state->enabling_bit = OBJECT(cm_device_by_name(enabling_bit_name));

    peripheral_prepare_registers(obj);
}

static void stm32_gpio_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Defer parent reset to read the previous value.

    STM32GPIOState *state = STM32_GPIO_STATE(dev);

    const STM32Capabilities *capabilities =
    STM32_GPIO_STATE(state)->capabilities;

    Object *odr = NULL;
    switch (capabilities->family) {
    case STM32_FAMILY_F0:
        odr = state->u.f0.reg.odr;
        break;

    case STM32_FAMILY_F1:
        odr = state->u.f1.reg.odr;
        break;

    case STM32_FAMILY_F4:
        odr = state->u.f4.reg.odr;
        break;

    default:
        assert(false);
        break;
    }

    assert(odr);
    uint16_t prev_odr = peripheral_register_get_raw_value(odr);

    // Call parent reset().
    // Must be exactly here, between reading the old and the new values.
    cm_device_parent_reset(dev, TYPE_STM32_GPIO);

    uint16_t new_odr = peripheral_register_get_raw_value(odr);

    // Update connected devices, like LEDs, to new ODR.
    stm32_gpio_set_odr_irqs(state, prev_odr, new_odr);

    // ------------------------------------------------------------------------

    state->dir_mask = 0;

    switch (capabilities->family) {
    case STM32_FAMILY_F0:
        // Use the F4 code
        stm32f4_gpio_update_dir_mask(state);
        break;

    case STM32_FAMILY_F1:
        stm32f1_gpio_update_dir_mask(state, 0);
        stm32f1_gpio_update_dir_mask(state, 1);
        break;

    case STM32_FAMILY_F4:
        stm32f4_gpio_update_dir_mask(state);
        break;

    default:
        assert(false);
        break;
    }
}

static void stm32_gpio_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_gpio_reset_callback;
    dc->realize = stm32_gpio_realize_callback;

    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_gpio_is_enabled;
}

static const TypeInfo stm32_gpio_type_info = {
    .name = TYPE_STM32_GPIO,
    .parent = TYPE_STM32_GPIO_PARENT,
    .instance_init = stm32_gpio_instance_init_callback,
    .instance_size = sizeof(STM32GPIOState),
    .class_init = stm32_gpio_class_init_callback,
    .class_size = sizeof(STM32GPIOClass)
/**/
};

static void stm32_gpio_register_types(void)
{
    type_register_static(&stm32_gpio_type_info);
}

type_init(stm32_gpio_register_types);

// ----------------------------------------------------------------------------
