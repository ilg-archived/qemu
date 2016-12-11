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
    state->f0.reg.moder = cm_object_get_child_by_name(obj, "MODER");
    state->f0.reg.otyper = cm_object_get_child_by_name(obj, "OTYPER");
    state->f0.reg.ospeedr = cm_object_get_child_by_name(obj, "OSPEEDR");
    state->f0.reg.pupdr = cm_object_get_child_by_name(obj, "PUPDR");
    state->f0.reg.idr = cm_object_get_child_by_name(obj, "IDR");
    state->f0.reg.odr = cm_object_get_child_by_name(obj, "ODR");
    state->f0.reg.bsrr = cm_object_get_child_by_name(obj, "BSRR");
    state->f0.reg.lckr = cm_object_get_child_by_name(obj, "LCKR");
    state->f0.reg.afrl = cm_object_get_child_by_name(obj, "AFRL");
    state->f0.reg.afrh = cm_object_get_child_by_name(obj, "AFRH");
    state->f0.reg.brr = cm_object_get_child_by_name(obj, "BRR");

    // MODER bitfields.
    state->f0.fld.moder.moder0 = cm_object_get_child_by_name(
            state->f0.reg.moder, "MODER0");
    state->f0.fld.moder.moder1 = cm_object_get_child_by_name(
            state->f0.reg.moder, "MODER1");
    state->f0.fld.moder.moder2 = cm_object_get_child_by_name(
            state->f0.reg.moder, "MODER2");
    state->f0.fld.moder.moder3 = cm_object_get_child_by_name(
            state->f0.reg.moder, "MODER3");
    state->f0.fld.moder.moder4 = cm_object_get_child_by_name(
            state->f0.reg.moder, "MODER4");
    state->f0.fld.moder.moder5 = cm_object_get_child_by_name(
            state->f0.reg.moder, "MODER5");
    state->f0.fld.moder.moder6 = cm_object_get_child_by_name(
            state->f0.reg.moder, "MODER6");
    state->f0.fld.moder.moder7 = cm_object_get_child_by_name(
            state->f0.reg.moder, "MODER7");
    state->f0.fld.moder.moder8 = cm_object_get_child_by_name(
            state->f0.reg.moder, "MODER8");
    state->f0.fld.moder.moder9 = cm_object_get_child_by_name(
            state->f0.reg.moder, "MODER9");
    state->f0.fld.moder.moder10 = cm_object_get_child_by_name(
            state->f0.reg.moder, "MODER10");
    state->f0.fld.moder.moder11 = cm_object_get_child_by_name(
            state->f0.reg.moder, "MODER11");
    state->f0.fld.moder.moder12 = cm_object_get_child_by_name(
            state->f0.reg.moder, "MODER12");
    state->f0.fld.moder.moder13 = cm_object_get_child_by_name(
            state->f0.reg.moder, "MODER13");
    state->f0.fld.moder.moder14 = cm_object_get_child_by_name(
            state->f0.reg.moder, "MODER14");
    state->f0.fld.moder.moder15 = cm_object_get_child_by_name(
            state->f0.reg.moder, "MODER15");

    // OTYPER bitfields.
    state->f0.fld.otyper.ot0 = cm_object_get_child_by_name(state->f0.reg.otyper,
            "OT0");
    state->f0.fld.otyper.ot1 = cm_object_get_child_by_name(state->f0.reg.otyper,
            "OT1");
    state->f0.fld.otyper.ot2 = cm_object_get_child_by_name(state->f0.reg.otyper,
            "OT2");
    state->f0.fld.otyper.ot3 = cm_object_get_child_by_name(state->f0.reg.otyper,
            "OT3");
    state->f0.fld.otyper.ot4 = cm_object_get_child_by_name(state->f0.reg.otyper,
            "OT4");
    state->f0.fld.otyper.ot5 = cm_object_get_child_by_name(state->f0.reg.otyper,
            "OT5");
    state->f0.fld.otyper.ot6 = cm_object_get_child_by_name(state->f0.reg.otyper,
            "OT6");
    state->f0.fld.otyper.ot7 = cm_object_get_child_by_name(state->f0.reg.otyper,
            "OT7");
    state->f0.fld.otyper.ot8 = cm_object_get_child_by_name(state->f0.reg.otyper,
            "OT8");
    state->f0.fld.otyper.ot9 = cm_object_get_child_by_name(state->f0.reg.otyper,
            "OT9");
    state->f0.fld.otyper.ot10 = cm_object_get_child_by_name(
            state->f0.reg.otyper, "OT10");
    state->f0.fld.otyper.ot11 = cm_object_get_child_by_name(
            state->f0.reg.otyper, "OT11");
    state->f0.fld.otyper.ot12 = cm_object_get_child_by_name(
            state->f0.reg.otyper, "OT12");
    state->f0.fld.otyper.ot13 = cm_object_get_child_by_name(
            state->f0.reg.otyper, "OT13");
    state->f0.fld.otyper.ot14 = cm_object_get_child_by_name(
            state->f0.reg.otyper, "OT14");
    state->f0.fld.otyper.ot15 = cm_object_get_child_by_name(
            state->f0.reg.otyper, "OT15");

    // OSPEEDR bitfields.
    state->f0.fld.ospeedr.ospeedr0 = cm_object_get_child_by_name(
            state->f0.reg.ospeedr, "OSPEEDR0");
    state->f0.fld.ospeedr.ospeedr1 = cm_object_get_child_by_name(
            state->f0.reg.ospeedr, "OSPEEDR1");
    state->f0.fld.ospeedr.ospeedr2 = cm_object_get_child_by_name(
            state->f0.reg.ospeedr, "OSPEEDR2");
    state->f0.fld.ospeedr.ospeedr3 = cm_object_get_child_by_name(
            state->f0.reg.ospeedr, "OSPEEDR3");
    state->f0.fld.ospeedr.ospeedr4 = cm_object_get_child_by_name(
            state->f0.reg.ospeedr, "OSPEEDR4");
    state->f0.fld.ospeedr.ospeedr5 = cm_object_get_child_by_name(
            state->f0.reg.ospeedr, "OSPEEDR5");
    state->f0.fld.ospeedr.ospeedr6 = cm_object_get_child_by_name(
            state->f0.reg.ospeedr, "OSPEEDR6");
    state->f0.fld.ospeedr.ospeedr7 = cm_object_get_child_by_name(
            state->f0.reg.ospeedr, "OSPEEDR7");
    state->f0.fld.ospeedr.ospeedr8 = cm_object_get_child_by_name(
            state->f0.reg.ospeedr, "OSPEEDR8");
    state->f0.fld.ospeedr.ospeedr9 = cm_object_get_child_by_name(
            state->f0.reg.ospeedr, "OSPEEDR9");
    state->f0.fld.ospeedr.ospeedr10 = cm_object_get_child_by_name(
            state->f0.reg.ospeedr, "OSPEEDR10");
    state->f0.fld.ospeedr.ospeedr11 = cm_object_get_child_by_name(
            state->f0.reg.ospeedr, "OSPEEDR11");
    state->f0.fld.ospeedr.ospeedr12 = cm_object_get_child_by_name(
            state->f0.reg.ospeedr, "OSPEEDR12");
    state->f0.fld.ospeedr.ospeedr13 = cm_object_get_child_by_name(
            state->f0.reg.ospeedr, "OSPEEDR13");
    state->f0.fld.ospeedr.ospeedr14 = cm_object_get_child_by_name(
            state->f0.reg.ospeedr, "OSPEEDR14");
    state->f0.fld.ospeedr.ospeedr15 = cm_object_get_child_by_name(
            state->f0.reg.ospeedr, "OSPEEDR15");

    // PUPDR bitfields.
    state->f0.fld.pupdr.pupdr0 = cm_object_get_child_by_name(
            state->f0.reg.pupdr, "PUPDR0");
    state->f0.fld.pupdr.pupdr1 = cm_object_get_child_by_name(
            state->f0.reg.pupdr, "PUPDR1");
    state->f0.fld.pupdr.pupdr2 = cm_object_get_child_by_name(
            state->f0.reg.pupdr, "PUPDR2");
    state->f0.fld.pupdr.pupdr3 = cm_object_get_child_by_name(
            state->f0.reg.pupdr, "PUPDR3");
    state->f0.fld.pupdr.pupdr4 = cm_object_get_child_by_name(
            state->f0.reg.pupdr, "PUPDR4");
    state->f0.fld.pupdr.pupdr5 = cm_object_get_child_by_name(
            state->f0.reg.pupdr, "PUPDR5");
    state->f0.fld.pupdr.pupdr6 = cm_object_get_child_by_name(
            state->f0.reg.pupdr, "PUPDR6");
    state->f0.fld.pupdr.pupdr7 = cm_object_get_child_by_name(
            state->f0.reg.pupdr, "PUPDR7");
    state->f0.fld.pupdr.pupdr8 = cm_object_get_child_by_name(
            state->f0.reg.pupdr, "PUPDR8");
    state->f0.fld.pupdr.pupdr9 = cm_object_get_child_by_name(
            state->f0.reg.pupdr, "PUPDR9");
    state->f0.fld.pupdr.pupdr10 = cm_object_get_child_by_name(
            state->f0.reg.pupdr, "PUPDR10");
    state->f0.fld.pupdr.pupdr11 = cm_object_get_child_by_name(
            state->f0.reg.pupdr, "PUPDR11");
    state->f0.fld.pupdr.pupdr12 = cm_object_get_child_by_name(
            state->f0.reg.pupdr, "PUPDR12");
    state->f0.fld.pupdr.pupdr13 = cm_object_get_child_by_name(
            state->f0.reg.pupdr, "PUPDR13");
    state->f0.fld.pupdr.pupdr14 = cm_object_get_child_by_name(
            state->f0.reg.pupdr, "PUPDR14");
    state->f0.fld.pupdr.pupdr15 = cm_object_get_child_by_name(
            state->f0.reg.pupdr, "PUPDR15");

    // IDR bitfields.
    state->f0.fld.idr.idr0 = cm_object_get_child_by_name(state->f0.reg.idr,
            "IDR0");
    state->f0.fld.idr.idr1 = cm_object_get_child_by_name(state->f0.reg.idr,
            "IDR1");
    state->f0.fld.idr.idr2 = cm_object_get_child_by_name(state->f0.reg.idr,
            "IDR2");
    state->f0.fld.idr.idr3 = cm_object_get_child_by_name(state->f0.reg.idr,
            "IDR3");
    state->f0.fld.idr.idr4 = cm_object_get_child_by_name(state->f0.reg.idr,
            "IDR4");
    state->f0.fld.idr.idr5 = cm_object_get_child_by_name(state->f0.reg.idr,
            "IDR5");
    state->f0.fld.idr.idr6 = cm_object_get_child_by_name(state->f0.reg.idr,
            "IDR6");
    state->f0.fld.idr.idr7 = cm_object_get_child_by_name(state->f0.reg.idr,
            "IDR7");
    state->f0.fld.idr.idr8 = cm_object_get_child_by_name(state->f0.reg.idr,
            "IDR8");
    state->f0.fld.idr.idr9 = cm_object_get_child_by_name(state->f0.reg.idr,
            "IDR9");
    state->f0.fld.idr.idr10 = cm_object_get_child_by_name(state->f0.reg.idr,
            "IDR10");
    state->f0.fld.idr.idr11 = cm_object_get_child_by_name(state->f0.reg.idr,
            "IDR11");
    state->f0.fld.idr.idr12 = cm_object_get_child_by_name(state->f0.reg.idr,
            "IDR12");
    state->f0.fld.idr.idr13 = cm_object_get_child_by_name(state->f0.reg.idr,
            "IDR13");
    state->f0.fld.idr.idr14 = cm_object_get_child_by_name(state->f0.reg.idr,
            "IDR14");
    state->f0.fld.idr.idr15 = cm_object_get_child_by_name(state->f0.reg.idr,
            "IDR15");

    // ODR bitfields.
    state->f0.fld.odr.odr0 = cm_object_get_child_by_name(state->f0.reg.odr,
            "ODR0");
    state->f0.fld.odr.odr1 = cm_object_get_child_by_name(state->f0.reg.odr,
            "ODR1");
    state->f0.fld.odr.odr2 = cm_object_get_child_by_name(state->f0.reg.odr,
            "ODR2");
    state->f0.fld.odr.odr3 = cm_object_get_child_by_name(state->f0.reg.odr,
            "ODR3");
    state->f0.fld.odr.odr4 = cm_object_get_child_by_name(state->f0.reg.odr,
            "ODR4");
    state->f0.fld.odr.odr5 = cm_object_get_child_by_name(state->f0.reg.odr,
            "ODR5");
    state->f0.fld.odr.odr6 = cm_object_get_child_by_name(state->f0.reg.odr,
            "ODR6");
    state->f0.fld.odr.odr7 = cm_object_get_child_by_name(state->f0.reg.odr,
            "ODR7");
    state->f0.fld.odr.odr8 = cm_object_get_child_by_name(state->f0.reg.odr,
            "ODR8");
    state->f0.fld.odr.odr9 = cm_object_get_child_by_name(state->f0.reg.odr,
            "ODR9");
    state->f0.fld.odr.odr10 = cm_object_get_child_by_name(state->f0.reg.odr,
            "ODR10");
    state->f0.fld.odr.odr11 = cm_object_get_child_by_name(state->f0.reg.odr,
            "ODR11");
    state->f0.fld.odr.odr12 = cm_object_get_child_by_name(state->f0.reg.odr,
            "ODR12");
    state->f0.fld.odr.odr13 = cm_object_get_child_by_name(state->f0.reg.odr,
            "ODR13");
    state->f0.fld.odr.odr14 = cm_object_get_child_by_name(state->f0.reg.odr,
            "ODR14");
    state->f0.fld.odr.odr15 = cm_object_get_child_by_name(state->f0.reg.odr,
            "ODR15");

    // BSRR bitfields.
    state->f0.fld.bsrr.bs0 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BS0");
    state->f0.fld.bsrr.bs1 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BS1");
    state->f0.fld.bsrr.bs2 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BS2");
    state->f0.fld.bsrr.bs3 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BS3");
    state->f0.fld.bsrr.bs4 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BS4");
    state->f0.fld.bsrr.bs5 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BS5");
    state->f0.fld.bsrr.bs6 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BS6");
    state->f0.fld.bsrr.bs7 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BS7");
    state->f0.fld.bsrr.bs8 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BS8");
    state->f0.fld.bsrr.bs9 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BS9");
    state->f0.fld.bsrr.bs10 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BS10");
    state->f0.fld.bsrr.bs11 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BS11");
    state->f0.fld.bsrr.bs12 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BS12");
    state->f0.fld.bsrr.bs13 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BS13");
    state->f0.fld.bsrr.bs14 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BS14");
    state->f0.fld.bsrr.bs15 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BS15");
    state->f0.fld.bsrr.br0 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BR0");
    state->f0.fld.bsrr.br1 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BR1");
    state->f0.fld.bsrr.br2 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BR2");
    state->f0.fld.bsrr.br3 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BR3");
    state->f0.fld.bsrr.br4 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BR4");
    state->f0.fld.bsrr.br5 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BR5");
    state->f0.fld.bsrr.br6 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BR6");
    state->f0.fld.bsrr.br7 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BR7");
    state->f0.fld.bsrr.br8 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BR8");
    state->f0.fld.bsrr.br9 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BR9");
    state->f0.fld.bsrr.br10 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BR10");
    state->f0.fld.bsrr.br11 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BR11");
    state->f0.fld.bsrr.br12 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BR12");
    state->f0.fld.bsrr.br13 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BR13");
    state->f0.fld.bsrr.br14 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BR14");
    state->f0.fld.bsrr.br15 = cm_object_get_child_by_name(state->f0.reg.bsrr,
            "BR15");

    // LCKR bitfields.
    state->f0.fld.lckr.lck0 = cm_object_get_child_by_name(state->f0.reg.lckr,
            "LCK0");
    state->f0.fld.lckr.lck1 = cm_object_get_child_by_name(state->f0.reg.lckr,
            "LCK1");
    state->f0.fld.lckr.lck2 = cm_object_get_child_by_name(state->f0.reg.lckr,
            "LCK2");
    state->f0.fld.lckr.lck3 = cm_object_get_child_by_name(state->f0.reg.lckr,
            "LCK3");
    state->f0.fld.lckr.lck4 = cm_object_get_child_by_name(state->f0.reg.lckr,
            "LCK4");
    state->f0.fld.lckr.lck5 = cm_object_get_child_by_name(state->f0.reg.lckr,
            "LCK5");
    state->f0.fld.lckr.lck6 = cm_object_get_child_by_name(state->f0.reg.lckr,
            "LCK6");
    state->f0.fld.lckr.lck7 = cm_object_get_child_by_name(state->f0.reg.lckr,
            "LCK7");
    state->f0.fld.lckr.lck8 = cm_object_get_child_by_name(state->f0.reg.lckr,
            "LCK8");
    state->f0.fld.lckr.lck9 = cm_object_get_child_by_name(state->f0.reg.lckr,
            "LCK9");
    state->f0.fld.lckr.lck10 = cm_object_get_child_by_name(state->f0.reg.lckr,
            "LCK10");
    state->f0.fld.lckr.lck11 = cm_object_get_child_by_name(state->f0.reg.lckr,
            "LCK11");
    state->f0.fld.lckr.lck12 = cm_object_get_child_by_name(state->f0.reg.lckr,
            "LCK12");
    state->f0.fld.lckr.lck13 = cm_object_get_child_by_name(state->f0.reg.lckr,
            "LCK13");
    state->f0.fld.lckr.lck14 = cm_object_get_child_by_name(state->f0.reg.lckr,
            "LCK14");
    state->f0.fld.lckr.lck15 = cm_object_get_child_by_name(state->f0.reg.lckr,
            "LCK15");
    state->f0.fld.lckr.lckk = cm_object_get_child_by_name(state->f0.reg.lckr,
            "LCKK");

    // AFRL bitfields.
    state->f0.fld.afrl.afrl0 = cm_object_get_child_by_name(state->f0.reg.afrl,
            "AFRL0");
    state->f0.fld.afrl.afrl1 = cm_object_get_child_by_name(state->f0.reg.afrl,
            "AFRL1");
    state->f0.fld.afrl.afrl2 = cm_object_get_child_by_name(state->f0.reg.afrl,
            "AFRL2");
    state->f0.fld.afrl.afrl3 = cm_object_get_child_by_name(state->f0.reg.afrl,
            "AFRL3");
    state->f0.fld.afrl.afrl4 = cm_object_get_child_by_name(state->f0.reg.afrl,
            "AFRL4");
    state->f0.fld.afrl.afrl5 = cm_object_get_child_by_name(state->f0.reg.afrl,
            "AFRL5");
    state->f0.fld.afrl.afrl6 = cm_object_get_child_by_name(state->f0.reg.afrl,
            "AFRL6");
    state->f0.fld.afrl.afrl7 = cm_object_get_child_by_name(state->f0.reg.afrl,
            "AFRL7");

    // AFRH bitfields.
    state->f0.fld.afrh.afrh8 = cm_object_get_child_by_name(state->f0.reg.afrh,
            "AFRH8");
    state->f0.fld.afrh.afrh9 = cm_object_get_child_by_name(state->f0.reg.afrh,
            "AFRH9");
    state->f0.fld.afrh.afrh10 = cm_object_get_child_by_name(state->f0.reg.afrh,
            "AFRH10");
    state->f0.fld.afrh.afrh11 = cm_object_get_child_by_name(state->f0.reg.afrh,
            "AFRH11");
    state->f0.fld.afrh.afrh12 = cm_object_get_child_by_name(state->f0.reg.afrh,
            "AFRH12");
    state->f0.fld.afrh.afrh13 = cm_object_get_child_by_name(state->f0.reg.afrh,
            "AFRH13");
    state->f0.fld.afrh.afrh14 = cm_object_get_child_by_name(state->f0.reg.afrh,
            "AFRH14");
    state->f0.fld.afrh.afrh15 = cm_object_get_child_by_name(state->f0.reg.afrh,
            "AFRH15");

    // BRR bitfields.
    state->f0.fld.brr.br0 = cm_object_get_child_by_name(state->f0.reg.brr,
            "BR0");
    state->f0.fld.brr.br1 = cm_object_get_child_by_name(state->f0.reg.brr,
            "BR1");
    state->f0.fld.brr.br2 = cm_object_get_child_by_name(state->f0.reg.brr,
            "BR2");
    state->f0.fld.brr.br3 = cm_object_get_child_by_name(state->f0.reg.brr,
            "BR3");
    state->f0.fld.brr.br4 = cm_object_get_child_by_name(state->f0.reg.brr,
            "BR4");
    state->f0.fld.brr.br5 = cm_object_get_child_by_name(state->f0.reg.brr,
            "BR5");
    state->f0.fld.brr.br6 = cm_object_get_child_by_name(state->f0.reg.brr,
            "BR6");
    state->f0.fld.brr.br7 = cm_object_get_child_by_name(state->f0.reg.brr,
            "BR7");
    state->f0.fld.brr.br8 = cm_object_get_child_by_name(state->f0.reg.brr,
            "BR8");
    state->f0.fld.brr.br9 = cm_object_get_child_by_name(state->f0.reg.brr,
            "BR9");
    state->f0.fld.brr.br10 = cm_object_get_child_by_name(state->f0.reg.brr,
            "BR10");
    state->f0.fld.brr.br11 = cm_object_get_child_by_name(state->f0.reg.brr,
            "BR11");
    state->f0.fld.brr.br12 = cm_object_get_child_by_name(state->f0.reg.brr,
            "BR12");
    state->f0.fld.brr.br13 = cm_object_get_child_by_name(state->f0.reg.brr,
            "BR13");
    state->f0.fld.brr.br14 = cm_object_get_child_by_name(state->f0.reg.brr,
            "BR14");
    state->f0.fld.brr.br15 = cm_object_get_child_by_name(state->f0.reg.brr,
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
    state->f1.reg.crl = cm_object_get_child_by_name(obj, "CRL");
    state->f1.reg.crh = cm_object_get_child_by_name(obj, "CRH");
    state->f1.reg.idr = cm_object_get_child_by_name(obj, "IDR");
    state->f1.reg.odr = cm_object_get_child_by_name(obj, "ODR");
    state->f1.reg.bsrr = cm_object_get_child_by_name(obj, "BSRR");
    state->f1.reg.brr = cm_object_get_child_by_name(obj, "BRR");
    state->f1.reg.lckr = cm_object_get_child_by_name(obj, "LCKR");

    // CRL bitfields.
    state->f1.fld.crl.mode0 = cm_object_get_child_by_name(state->f1.reg.crl,
            "MODE0");
    state->f1.fld.crl.cnf0 = cm_object_get_child_by_name(state->f1.reg.crl,
            "CNF0");
    state->f1.fld.crl.mode1 = cm_object_get_child_by_name(state->f1.reg.crl,
            "MODE1");
    state->f1.fld.crl.cnf1 = cm_object_get_child_by_name(state->f1.reg.crl,
            "CNF1");
    state->f1.fld.crl.mode2 = cm_object_get_child_by_name(state->f1.reg.crl,
            "MODE2");
    state->f1.fld.crl.cnf2 = cm_object_get_child_by_name(state->f1.reg.crl,
            "CNF2");
    state->f1.fld.crl.mode3 = cm_object_get_child_by_name(state->f1.reg.crl,
            "MODE3");
    state->f1.fld.crl.cnf3 = cm_object_get_child_by_name(state->f1.reg.crl,
            "CNF3");
    state->f1.fld.crl.mode4 = cm_object_get_child_by_name(state->f1.reg.crl,
            "MODE4");
    state->f1.fld.crl.cnf4 = cm_object_get_child_by_name(state->f1.reg.crl,
            "CNF4");
    state->f1.fld.crl.mode5 = cm_object_get_child_by_name(state->f1.reg.crl,
            "MODE5");
    state->f1.fld.crl.cnf5 = cm_object_get_child_by_name(state->f1.reg.crl,
            "CNF5");
    state->f1.fld.crl.mode6 = cm_object_get_child_by_name(state->f1.reg.crl,
            "MODE6");
    state->f1.fld.crl.cnf6 = cm_object_get_child_by_name(state->f1.reg.crl,
            "CNF6");
    state->f1.fld.crl.mode7 = cm_object_get_child_by_name(state->f1.reg.crl,
            "MODE7");
    state->f1.fld.crl.cnf7 = cm_object_get_child_by_name(state->f1.reg.crl,
            "CNF7");

    // CRH bitfields.
    state->f1.fld.crh.mode8 = cm_object_get_child_by_name(state->f1.reg.crh,
            "MODE8");
    state->f1.fld.crh.cnf8 = cm_object_get_child_by_name(state->f1.reg.crh,
            "CNF8");
    state->f1.fld.crh.mode9 = cm_object_get_child_by_name(state->f1.reg.crh,
            "MODE9");
    state->f1.fld.crh.cnf9 = cm_object_get_child_by_name(state->f1.reg.crh,
            "CNF9");
    state->f1.fld.crh.mode10 = cm_object_get_child_by_name(state->f1.reg.crh,
            "MODE10");
    state->f1.fld.crh.cnf10 = cm_object_get_child_by_name(state->f1.reg.crh,
            "CNF10");
    state->f1.fld.crh.mode11 = cm_object_get_child_by_name(state->f1.reg.crh,
            "MODE11");
    state->f1.fld.crh.cnf11 = cm_object_get_child_by_name(state->f1.reg.crh,
            "CNF11");
    state->f1.fld.crh.mode12 = cm_object_get_child_by_name(state->f1.reg.crh,
            "MODE12");
    state->f1.fld.crh.cnf12 = cm_object_get_child_by_name(state->f1.reg.crh,
            "CNF12");
    state->f1.fld.crh.mode13 = cm_object_get_child_by_name(state->f1.reg.crh,
            "MODE13");
    state->f1.fld.crh.cnf13 = cm_object_get_child_by_name(state->f1.reg.crh,
            "CNF13");
    state->f1.fld.crh.mode14 = cm_object_get_child_by_name(state->f1.reg.crh,
            "MODE14");
    state->f1.fld.crh.cnf14 = cm_object_get_child_by_name(state->f1.reg.crh,
            "CNF14");
    state->f1.fld.crh.mode15 = cm_object_get_child_by_name(state->f1.reg.crh,
            "MODE15");
    state->f1.fld.crh.cnf15 = cm_object_get_child_by_name(state->f1.reg.crh,
            "CNF15");

    // IDR bitfields.
    state->f1.fld.idr.idr0 = cm_object_get_child_by_name(state->f1.reg.idr,
            "IDR0");
    state->f1.fld.idr.idr1 = cm_object_get_child_by_name(state->f1.reg.idr,
            "IDR1");
    state->f1.fld.idr.idr2 = cm_object_get_child_by_name(state->f1.reg.idr,
            "IDR2");
    state->f1.fld.idr.idr3 = cm_object_get_child_by_name(state->f1.reg.idr,
            "IDR3");
    state->f1.fld.idr.idr4 = cm_object_get_child_by_name(state->f1.reg.idr,
            "IDR4");
    state->f1.fld.idr.idr5 = cm_object_get_child_by_name(state->f1.reg.idr,
            "IDR5");
    state->f1.fld.idr.idr6 = cm_object_get_child_by_name(state->f1.reg.idr,
            "IDR6");
    state->f1.fld.idr.idr7 = cm_object_get_child_by_name(state->f1.reg.idr,
            "IDR7");
    state->f1.fld.idr.idr8 = cm_object_get_child_by_name(state->f1.reg.idr,
            "IDR8");
    state->f1.fld.idr.idr9 = cm_object_get_child_by_name(state->f1.reg.idr,
            "IDR9");
    state->f1.fld.idr.idr10 = cm_object_get_child_by_name(state->f1.reg.idr,
            "IDR10");
    state->f1.fld.idr.idr11 = cm_object_get_child_by_name(state->f1.reg.idr,
            "IDR11");
    state->f1.fld.idr.idr12 = cm_object_get_child_by_name(state->f1.reg.idr,
            "IDR12");
    state->f1.fld.idr.idr13 = cm_object_get_child_by_name(state->f1.reg.idr,
            "IDR13");
    state->f1.fld.idr.idr14 = cm_object_get_child_by_name(state->f1.reg.idr,
            "IDR14");
    state->f1.fld.idr.idr15 = cm_object_get_child_by_name(state->f1.reg.idr,
            "IDR15");

    // ODR bitfields.
    state->f1.fld.odr.odr0 = cm_object_get_child_by_name(state->f1.reg.odr,
            "ODR0");
    state->f1.fld.odr.odr1 = cm_object_get_child_by_name(state->f1.reg.odr,
            "ODR1");
    state->f1.fld.odr.odr2 = cm_object_get_child_by_name(state->f1.reg.odr,
            "ODR2");
    state->f1.fld.odr.odr3 = cm_object_get_child_by_name(state->f1.reg.odr,
            "ODR3");
    state->f1.fld.odr.odr4 = cm_object_get_child_by_name(state->f1.reg.odr,
            "ODR4");
    state->f1.fld.odr.odr5 = cm_object_get_child_by_name(state->f1.reg.odr,
            "ODR5");
    state->f1.fld.odr.odr6 = cm_object_get_child_by_name(state->f1.reg.odr,
            "ODR6");
    state->f1.fld.odr.odr7 = cm_object_get_child_by_name(state->f1.reg.odr,
            "ODR7");
    state->f1.fld.odr.odr8 = cm_object_get_child_by_name(state->f1.reg.odr,
            "ODR8");
    state->f1.fld.odr.odr9 = cm_object_get_child_by_name(state->f1.reg.odr,
            "ODR9");
    state->f1.fld.odr.odr10 = cm_object_get_child_by_name(state->f1.reg.odr,
            "ODR10");
    state->f1.fld.odr.odr11 = cm_object_get_child_by_name(state->f1.reg.odr,
            "ODR11");
    state->f1.fld.odr.odr12 = cm_object_get_child_by_name(state->f1.reg.odr,
            "ODR12");
    state->f1.fld.odr.odr13 = cm_object_get_child_by_name(state->f1.reg.odr,
            "ODR13");
    state->f1.fld.odr.odr14 = cm_object_get_child_by_name(state->f1.reg.odr,
            "ODR14");
    state->f1.fld.odr.odr15 = cm_object_get_child_by_name(state->f1.reg.odr,
            "ODR15");

    // BSRR bitfields.
    state->f1.fld.bsrr.bs0 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BS0");
    state->f1.fld.bsrr.bs1 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BS1");
    state->f1.fld.bsrr.bs2 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BS2");
    state->f1.fld.bsrr.bs3 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BS3");
    state->f1.fld.bsrr.bs4 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BS4");
    state->f1.fld.bsrr.bs5 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BS5");
    state->f1.fld.bsrr.bs6 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BS6");
    state->f1.fld.bsrr.bs7 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BS7");
    state->f1.fld.bsrr.bs8 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BS8");
    state->f1.fld.bsrr.bs9 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BS9");
    state->f1.fld.bsrr.bs10 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BS10");
    state->f1.fld.bsrr.bs11 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BS11");
    state->f1.fld.bsrr.bs12 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BS12");
    state->f1.fld.bsrr.bs13 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BS13");
    state->f1.fld.bsrr.bs14 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BS14");
    state->f1.fld.bsrr.bs15 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BS15");
    state->f1.fld.bsrr.br0 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BR0");
    state->f1.fld.bsrr.br1 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BR1");
    state->f1.fld.bsrr.br2 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BR2");
    state->f1.fld.bsrr.br3 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BR3");
    state->f1.fld.bsrr.br4 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BR4");
    state->f1.fld.bsrr.br5 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BR5");
    state->f1.fld.bsrr.br6 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BR6");
    state->f1.fld.bsrr.br7 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BR7");
    state->f1.fld.bsrr.br8 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BR8");
    state->f1.fld.bsrr.br9 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BR9");
    state->f1.fld.bsrr.br10 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BR10");
    state->f1.fld.bsrr.br11 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BR11");
    state->f1.fld.bsrr.br12 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BR12");
    state->f1.fld.bsrr.br13 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BR13");
    state->f1.fld.bsrr.br14 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BR14");
    state->f1.fld.bsrr.br15 = cm_object_get_child_by_name(state->f1.reg.bsrr,
            "BR15");

    // BRR bitfields.
    state->f1.fld.brr.br0 = cm_object_get_child_by_name(state->f1.reg.brr,
            "BR0");
    state->f1.fld.brr.br1 = cm_object_get_child_by_name(state->f1.reg.brr,
            "BR1");
    state->f1.fld.brr.br2 = cm_object_get_child_by_name(state->f1.reg.brr,
            "BR2");
    state->f1.fld.brr.br3 = cm_object_get_child_by_name(state->f1.reg.brr,
            "BR3");
    state->f1.fld.brr.br4 = cm_object_get_child_by_name(state->f1.reg.brr,
            "BR4");
    state->f1.fld.brr.br5 = cm_object_get_child_by_name(state->f1.reg.brr,
            "BR5");
    state->f1.fld.brr.br6 = cm_object_get_child_by_name(state->f1.reg.brr,
            "BR6");
    state->f1.fld.brr.br7 = cm_object_get_child_by_name(state->f1.reg.brr,
            "BR7");
    state->f1.fld.brr.br8 = cm_object_get_child_by_name(state->f1.reg.brr,
            "BR8");
    state->f1.fld.brr.br9 = cm_object_get_child_by_name(state->f1.reg.brr,
            "BR9");
    state->f1.fld.brr.br10 = cm_object_get_child_by_name(state->f1.reg.brr,
            "BR10");
    state->f1.fld.brr.br11 = cm_object_get_child_by_name(state->f1.reg.brr,
            "BR11");
    state->f1.fld.brr.br12 = cm_object_get_child_by_name(state->f1.reg.brr,
            "BR12");
    state->f1.fld.brr.br13 = cm_object_get_child_by_name(state->f1.reg.brr,
            "BR13");
    state->f1.fld.brr.br14 = cm_object_get_child_by_name(state->f1.reg.brr,
            "BR14");
    state->f1.fld.brr.br15 = cm_object_get_child_by_name(state->f1.reg.brr,
            "BR15");

    // LCKR bitfields.
    state->f1.fld.lckr.lck0 = cm_object_get_child_by_name(state->f1.reg.lckr,
            "LCK0");
    state->f1.fld.lckr.lck1 = cm_object_get_child_by_name(state->f1.reg.lckr,
            "LCK1");
    state->f1.fld.lckr.lck2 = cm_object_get_child_by_name(state->f1.reg.lckr,
            "LCK2");
    state->f1.fld.lckr.lck3 = cm_object_get_child_by_name(state->f1.reg.lckr,
            "LCK3");
    state->f1.fld.lckr.lck4 = cm_object_get_child_by_name(state->f1.reg.lckr,
            "LCK4");
    state->f1.fld.lckr.lck5 = cm_object_get_child_by_name(state->f1.reg.lckr,
            "LCK5");
    state->f1.fld.lckr.lck6 = cm_object_get_child_by_name(state->f1.reg.lckr,
            "LCK6");
    state->f1.fld.lckr.lck7 = cm_object_get_child_by_name(state->f1.reg.lckr,
            "LCK7");
    state->f1.fld.lckr.lck8 = cm_object_get_child_by_name(state->f1.reg.lckr,
            "LCK8");
    state->f1.fld.lckr.lck9 = cm_object_get_child_by_name(state->f1.reg.lckr,
            "LCK9");
    state->f1.fld.lckr.lck10 = cm_object_get_child_by_name(state->f1.reg.lckr,
            "LCK10");
    state->f1.fld.lckr.lck11 = cm_object_get_child_by_name(state->f1.reg.lckr,
            "LCK11");
    state->f1.fld.lckr.lck12 = cm_object_get_child_by_name(state->f1.reg.lckr,
            "LCK12");
    state->f1.fld.lckr.lck13 = cm_object_get_child_by_name(state->f1.reg.lckr,
            "LCK13");
    state->f1.fld.lckr.lck14 = cm_object_get_child_by_name(state->f1.reg.lckr,
            "LCK14");
    state->f1.fld.lckr.lck15 = cm_object_get_child_by_name(state->f1.reg.lckr,
            "LCK15");
    state->f1.fld.lckr.lckk = cm_object_get_child_by_name(state->f1.reg.lckr,
            "LCKK");
}

// ----------------------------------------------------------------------------

// STM32F407VG
// DO NOT EDIT! Automatically generated!
static void stm32f40x_gpio_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->f4.reg.moder = cm_object_get_child_by_name(obj, "MODER");
    state->f4.reg.otyper = cm_object_get_child_by_name(obj, "OTYPER");
    state->f4.reg.ospeedr = cm_object_get_child_by_name(obj, "OSPEEDR");
    state->f4.reg.pupdr = cm_object_get_child_by_name(obj, "PUPDR");
    state->f4.reg.idr = cm_object_get_child_by_name(obj, "IDR");
    state->f4.reg.odr = cm_object_get_child_by_name(obj, "ODR");
    state->f4.reg.bsrr = cm_object_get_child_by_name(obj, "BSRR");
    state->f4.reg.lckr = cm_object_get_child_by_name(obj, "LCKR");
    state->f4.reg.afrl = cm_object_get_child_by_name(obj, "AFRL");
    state->f4.reg.afrh = cm_object_get_child_by_name(obj, "AFRH");

    // MODER bitfields.
    state->f4.fld.moder.moder0 = cm_object_get_child_by_name(
            state->f4.reg.moder, "MODER0");
    state->f4.fld.moder.moder1 = cm_object_get_child_by_name(
            state->f4.reg.moder, "MODER1");
    state->f4.fld.moder.moder2 = cm_object_get_child_by_name(
            state->f4.reg.moder, "MODER2");
    state->f4.fld.moder.moder3 = cm_object_get_child_by_name(
            state->f4.reg.moder, "MODER3");
    state->f4.fld.moder.moder4 = cm_object_get_child_by_name(
            state->f4.reg.moder, "MODER4");
    state->f4.fld.moder.moder5 = cm_object_get_child_by_name(
            state->f4.reg.moder, "MODER5");
    state->f4.fld.moder.moder6 = cm_object_get_child_by_name(
            state->f4.reg.moder, "MODER6");
    state->f4.fld.moder.moder7 = cm_object_get_child_by_name(
            state->f4.reg.moder, "MODER7");
    state->f4.fld.moder.moder8 = cm_object_get_child_by_name(
            state->f4.reg.moder, "MODER8");
    state->f4.fld.moder.moder9 = cm_object_get_child_by_name(
            state->f4.reg.moder, "MODER9");
    state->f4.fld.moder.moder10 = cm_object_get_child_by_name(
            state->f4.reg.moder, "MODER10");
    state->f4.fld.moder.moder11 = cm_object_get_child_by_name(
            state->f4.reg.moder, "MODER11");
    state->f4.fld.moder.moder12 = cm_object_get_child_by_name(
            state->f4.reg.moder, "MODER12");
    state->f4.fld.moder.moder13 = cm_object_get_child_by_name(
            state->f4.reg.moder, "MODER13");
    state->f4.fld.moder.moder14 = cm_object_get_child_by_name(
            state->f4.reg.moder, "MODER14");
    state->f4.fld.moder.moder15 = cm_object_get_child_by_name(
            state->f4.reg.moder, "MODER15");

    // OTYPER bitfields.
    state->f4.fld.otyper.ot0 = cm_object_get_child_by_name(state->f4.reg.otyper,
            "OT0");
    state->f4.fld.otyper.ot1 = cm_object_get_child_by_name(state->f4.reg.otyper,
            "OT1");
    state->f4.fld.otyper.ot2 = cm_object_get_child_by_name(state->f4.reg.otyper,
            "OT2");
    state->f4.fld.otyper.ot3 = cm_object_get_child_by_name(state->f4.reg.otyper,
            "OT3");
    state->f4.fld.otyper.ot4 = cm_object_get_child_by_name(state->f4.reg.otyper,
            "OT4");
    state->f4.fld.otyper.ot5 = cm_object_get_child_by_name(state->f4.reg.otyper,
            "OT5");
    state->f4.fld.otyper.ot6 = cm_object_get_child_by_name(state->f4.reg.otyper,
            "OT6");
    state->f4.fld.otyper.ot7 = cm_object_get_child_by_name(state->f4.reg.otyper,
            "OT7");
    state->f4.fld.otyper.ot8 = cm_object_get_child_by_name(state->f4.reg.otyper,
            "OT8");
    state->f4.fld.otyper.ot9 = cm_object_get_child_by_name(state->f4.reg.otyper,
            "OT9");
    state->f4.fld.otyper.ot10 = cm_object_get_child_by_name(
            state->f4.reg.otyper, "OT10");
    state->f4.fld.otyper.ot11 = cm_object_get_child_by_name(
            state->f4.reg.otyper, "OT11");
    state->f4.fld.otyper.ot12 = cm_object_get_child_by_name(
            state->f4.reg.otyper, "OT12");
    state->f4.fld.otyper.ot13 = cm_object_get_child_by_name(
            state->f4.reg.otyper, "OT13");
    state->f4.fld.otyper.ot14 = cm_object_get_child_by_name(
            state->f4.reg.otyper, "OT14");
    state->f4.fld.otyper.ot15 = cm_object_get_child_by_name(
            state->f4.reg.otyper, "OT15");

    // OSPEEDR bitfields.
    state->f4.fld.ospeedr.ospeedr0 = cm_object_get_child_by_name(
            state->f4.reg.ospeedr, "OSPEEDR0");
    state->f4.fld.ospeedr.ospeedr1 = cm_object_get_child_by_name(
            state->f4.reg.ospeedr, "OSPEEDR1");
    state->f4.fld.ospeedr.ospeedr2 = cm_object_get_child_by_name(
            state->f4.reg.ospeedr, "OSPEEDR2");
    state->f4.fld.ospeedr.ospeedr3 = cm_object_get_child_by_name(
            state->f4.reg.ospeedr, "OSPEEDR3");
    state->f4.fld.ospeedr.ospeedr4 = cm_object_get_child_by_name(
            state->f4.reg.ospeedr, "OSPEEDR4");
    state->f4.fld.ospeedr.ospeedr5 = cm_object_get_child_by_name(
            state->f4.reg.ospeedr, "OSPEEDR5");
    state->f4.fld.ospeedr.ospeedr6 = cm_object_get_child_by_name(
            state->f4.reg.ospeedr, "OSPEEDR6");
    state->f4.fld.ospeedr.ospeedr7 = cm_object_get_child_by_name(
            state->f4.reg.ospeedr, "OSPEEDR7");
    state->f4.fld.ospeedr.ospeedr8 = cm_object_get_child_by_name(
            state->f4.reg.ospeedr, "OSPEEDR8");
    state->f4.fld.ospeedr.ospeedr9 = cm_object_get_child_by_name(
            state->f4.reg.ospeedr, "OSPEEDR9");
    state->f4.fld.ospeedr.ospeedr10 = cm_object_get_child_by_name(
            state->f4.reg.ospeedr, "OSPEEDR10");
    state->f4.fld.ospeedr.ospeedr11 = cm_object_get_child_by_name(
            state->f4.reg.ospeedr, "OSPEEDR11");
    state->f4.fld.ospeedr.ospeedr12 = cm_object_get_child_by_name(
            state->f4.reg.ospeedr, "OSPEEDR12");
    state->f4.fld.ospeedr.ospeedr13 = cm_object_get_child_by_name(
            state->f4.reg.ospeedr, "OSPEEDR13");
    state->f4.fld.ospeedr.ospeedr14 = cm_object_get_child_by_name(
            state->f4.reg.ospeedr, "OSPEEDR14");
    state->f4.fld.ospeedr.ospeedr15 = cm_object_get_child_by_name(
            state->f4.reg.ospeedr, "OSPEEDR15");

    // PUPDR bitfields.
    state->f4.fld.pupdr.pupdr0 = cm_object_get_child_by_name(
            state->f4.reg.pupdr, "PUPDR0");
    state->f4.fld.pupdr.pupdr1 = cm_object_get_child_by_name(
            state->f4.reg.pupdr, "PUPDR1");
    state->f4.fld.pupdr.pupdr2 = cm_object_get_child_by_name(
            state->f4.reg.pupdr, "PUPDR2");
    state->f4.fld.pupdr.pupdr3 = cm_object_get_child_by_name(
            state->f4.reg.pupdr, "PUPDR3");
    state->f4.fld.pupdr.pupdr4 = cm_object_get_child_by_name(
            state->f4.reg.pupdr, "PUPDR4");
    state->f4.fld.pupdr.pupdr5 = cm_object_get_child_by_name(
            state->f4.reg.pupdr, "PUPDR5");
    state->f4.fld.pupdr.pupdr6 = cm_object_get_child_by_name(
            state->f4.reg.pupdr, "PUPDR6");
    state->f4.fld.pupdr.pupdr7 = cm_object_get_child_by_name(
            state->f4.reg.pupdr, "PUPDR7");
    state->f4.fld.pupdr.pupdr8 = cm_object_get_child_by_name(
            state->f4.reg.pupdr, "PUPDR8");
    state->f4.fld.pupdr.pupdr9 = cm_object_get_child_by_name(
            state->f4.reg.pupdr, "PUPDR9");
    state->f4.fld.pupdr.pupdr10 = cm_object_get_child_by_name(
            state->f4.reg.pupdr, "PUPDR10");
    state->f4.fld.pupdr.pupdr11 = cm_object_get_child_by_name(
            state->f4.reg.pupdr, "PUPDR11");
    state->f4.fld.pupdr.pupdr12 = cm_object_get_child_by_name(
            state->f4.reg.pupdr, "PUPDR12");
    state->f4.fld.pupdr.pupdr13 = cm_object_get_child_by_name(
            state->f4.reg.pupdr, "PUPDR13");
    state->f4.fld.pupdr.pupdr14 = cm_object_get_child_by_name(
            state->f4.reg.pupdr, "PUPDR14");
    state->f4.fld.pupdr.pupdr15 = cm_object_get_child_by_name(
            state->f4.reg.pupdr, "PUPDR15");

    // IDR bitfields.
    state->f4.fld.idr.idr0 = cm_object_get_child_by_name(state->f4.reg.idr,
            "IDR0");
    state->f4.fld.idr.idr1 = cm_object_get_child_by_name(state->f4.reg.idr,
            "IDR1");
    state->f4.fld.idr.idr2 = cm_object_get_child_by_name(state->f4.reg.idr,
            "IDR2");
    state->f4.fld.idr.idr3 = cm_object_get_child_by_name(state->f4.reg.idr,
            "IDR3");
    state->f4.fld.idr.idr4 = cm_object_get_child_by_name(state->f4.reg.idr,
            "IDR4");
    state->f4.fld.idr.idr5 = cm_object_get_child_by_name(state->f4.reg.idr,
            "IDR5");
    state->f4.fld.idr.idr6 = cm_object_get_child_by_name(state->f4.reg.idr,
            "IDR6");
    state->f4.fld.idr.idr7 = cm_object_get_child_by_name(state->f4.reg.idr,
            "IDR7");
    state->f4.fld.idr.idr8 = cm_object_get_child_by_name(state->f4.reg.idr,
            "IDR8");
    state->f4.fld.idr.idr9 = cm_object_get_child_by_name(state->f4.reg.idr,
            "IDR9");
    state->f4.fld.idr.idr10 = cm_object_get_child_by_name(state->f4.reg.idr,
            "IDR10");
    state->f4.fld.idr.idr11 = cm_object_get_child_by_name(state->f4.reg.idr,
            "IDR11");
    state->f4.fld.idr.idr12 = cm_object_get_child_by_name(state->f4.reg.idr,
            "IDR12");
    state->f4.fld.idr.idr13 = cm_object_get_child_by_name(state->f4.reg.idr,
            "IDR13");
    state->f4.fld.idr.idr14 = cm_object_get_child_by_name(state->f4.reg.idr,
            "IDR14");
    state->f4.fld.idr.idr15 = cm_object_get_child_by_name(state->f4.reg.idr,
            "IDR15");

    // ODR bitfields.
    state->f4.fld.odr.odr0 = cm_object_get_child_by_name(state->f4.reg.odr,
            "ODR0");
    state->f4.fld.odr.odr1 = cm_object_get_child_by_name(state->f4.reg.odr,
            "ODR1");
    state->f4.fld.odr.odr2 = cm_object_get_child_by_name(state->f4.reg.odr,
            "ODR2");
    state->f4.fld.odr.odr3 = cm_object_get_child_by_name(state->f4.reg.odr,
            "ODR3");
    state->f4.fld.odr.odr4 = cm_object_get_child_by_name(state->f4.reg.odr,
            "ODR4");
    state->f4.fld.odr.odr5 = cm_object_get_child_by_name(state->f4.reg.odr,
            "ODR5");
    state->f4.fld.odr.odr6 = cm_object_get_child_by_name(state->f4.reg.odr,
            "ODR6");
    state->f4.fld.odr.odr7 = cm_object_get_child_by_name(state->f4.reg.odr,
            "ODR7");
    state->f4.fld.odr.odr8 = cm_object_get_child_by_name(state->f4.reg.odr,
            "ODR8");
    state->f4.fld.odr.odr9 = cm_object_get_child_by_name(state->f4.reg.odr,
            "ODR9");
    state->f4.fld.odr.odr10 = cm_object_get_child_by_name(state->f4.reg.odr,
            "ODR10");
    state->f4.fld.odr.odr11 = cm_object_get_child_by_name(state->f4.reg.odr,
            "ODR11");
    state->f4.fld.odr.odr12 = cm_object_get_child_by_name(state->f4.reg.odr,
            "ODR12");
    state->f4.fld.odr.odr13 = cm_object_get_child_by_name(state->f4.reg.odr,
            "ODR13");
    state->f4.fld.odr.odr14 = cm_object_get_child_by_name(state->f4.reg.odr,
            "ODR14");
    state->f4.fld.odr.odr15 = cm_object_get_child_by_name(state->f4.reg.odr,
            "ODR15");

    // BSRR bitfields.
    state->f4.fld.bsrr.bs0 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BS0");
    state->f4.fld.bsrr.bs1 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BS1");
    state->f4.fld.bsrr.bs2 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BS2");
    state->f4.fld.bsrr.bs3 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BS3");
    state->f4.fld.bsrr.bs4 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BS4");
    state->f4.fld.bsrr.bs5 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BS5");
    state->f4.fld.bsrr.bs6 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BS6");
    state->f4.fld.bsrr.bs7 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BS7");
    state->f4.fld.bsrr.bs8 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BS8");
    state->f4.fld.bsrr.bs9 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BS9");
    state->f4.fld.bsrr.bs10 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BS10");
    state->f4.fld.bsrr.bs11 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BS11");
    state->f4.fld.bsrr.bs12 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BS12");
    state->f4.fld.bsrr.bs13 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BS13");
    state->f4.fld.bsrr.bs14 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BS14");
    state->f4.fld.bsrr.bs15 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BS15");
    state->f4.fld.bsrr.br0 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BR0");
    state->f4.fld.bsrr.br1 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BR1");
    state->f4.fld.bsrr.br2 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BR2");
    state->f4.fld.bsrr.br3 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BR3");
    state->f4.fld.bsrr.br4 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BR4");
    state->f4.fld.bsrr.br5 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BR5");
    state->f4.fld.bsrr.br6 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BR6");
    state->f4.fld.bsrr.br7 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BR7");
    state->f4.fld.bsrr.br8 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BR8");
    state->f4.fld.bsrr.br9 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BR9");
    state->f4.fld.bsrr.br10 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BR10");
    state->f4.fld.bsrr.br11 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BR11");
    state->f4.fld.bsrr.br12 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BR12");
    state->f4.fld.bsrr.br13 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BR13");
    state->f4.fld.bsrr.br14 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BR14");
    state->f4.fld.bsrr.br15 = cm_object_get_child_by_name(state->f4.reg.bsrr,
            "BR15");

    // LCKR bitfields.
    state->f4.fld.lckr.lck0 = cm_object_get_child_by_name(state->f4.reg.lckr,
            "LCK0");
    state->f4.fld.lckr.lck1 = cm_object_get_child_by_name(state->f4.reg.lckr,
            "LCK1");
    state->f4.fld.lckr.lck2 = cm_object_get_child_by_name(state->f4.reg.lckr,
            "LCK2");
    state->f4.fld.lckr.lck3 = cm_object_get_child_by_name(state->f4.reg.lckr,
            "LCK3");
    state->f4.fld.lckr.lck4 = cm_object_get_child_by_name(state->f4.reg.lckr,
            "LCK4");
    state->f4.fld.lckr.lck5 = cm_object_get_child_by_name(state->f4.reg.lckr,
            "LCK5");
    state->f4.fld.lckr.lck6 = cm_object_get_child_by_name(state->f4.reg.lckr,
            "LCK6");
    state->f4.fld.lckr.lck7 = cm_object_get_child_by_name(state->f4.reg.lckr,
            "LCK7");
    state->f4.fld.lckr.lck8 = cm_object_get_child_by_name(state->f4.reg.lckr,
            "LCK8");
    state->f4.fld.lckr.lck9 = cm_object_get_child_by_name(state->f4.reg.lckr,
            "LCK9");
    state->f4.fld.lckr.lck10 = cm_object_get_child_by_name(state->f4.reg.lckr,
            "LCK10");
    state->f4.fld.lckr.lck11 = cm_object_get_child_by_name(state->f4.reg.lckr,
            "LCK11");
    state->f4.fld.lckr.lck12 = cm_object_get_child_by_name(state->f4.reg.lckr,
            "LCK12");
    state->f4.fld.lckr.lck13 = cm_object_get_child_by_name(state->f4.reg.lckr,
            "LCK13");
    state->f4.fld.lckr.lck14 = cm_object_get_child_by_name(state->f4.reg.lckr,
            "LCK14");
    state->f4.fld.lckr.lck15 = cm_object_get_child_by_name(state->f4.reg.lckr,
            "LCK15");
    state->f4.fld.lckr.lckk = cm_object_get_child_by_name(state->f4.reg.lckr,
            "LCKK");

    // AFRL bitfields.
    state->f4.fld.afrl.afrl0 = cm_object_get_child_by_name(state->f4.reg.afrl,
            "AFRL0");
    state->f4.fld.afrl.afrl1 = cm_object_get_child_by_name(state->f4.reg.afrl,
            "AFRL1");
    state->f4.fld.afrl.afrl2 = cm_object_get_child_by_name(state->f4.reg.afrl,
            "AFRL2");
    state->f4.fld.afrl.afrl3 = cm_object_get_child_by_name(state->f4.reg.afrl,
            "AFRL3");
    state->f4.fld.afrl.afrl4 = cm_object_get_child_by_name(state->f4.reg.afrl,
            "AFRL4");
    state->f4.fld.afrl.afrl5 = cm_object_get_child_by_name(state->f4.reg.afrl,
            "AFRL5");
    state->f4.fld.afrl.afrl6 = cm_object_get_child_by_name(state->f4.reg.afrl,
            "AFRL6");
    state->f4.fld.afrl.afrl7 = cm_object_get_child_by_name(state->f4.reg.afrl,
            "AFRL7");

    // AFRH bitfields.
    state->f4.fld.afrh.afrh8 = cm_object_get_child_by_name(state->f4.reg.afrh,
            "AFRH8");
    state->f4.fld.afrh.afrh9 = cm_object_get_child_by_name(state->f4.reg.afrh,
            "AFRH9");
    state->f4.fld.afrh.afrh10 = cm_object_get_child_by_name(state->f4.reg.afrh,
            "AFRH10");
    state->f4.fld.afrh.afrh11 = cm_object_get_child_by_name(state->f4.reg.afrh,
            "AFRH11");
    state->f4.fld.afrh.afrh12 = cm_object_get_child_by_name(state->f4.reg.afrh,
            "AFRH12");
    state->f4.fld.afrh.afrh13 = cm_object_get_child_by_name(state->f4.reg.afrh,
            "AFRH13");
    state->f4.fld.afrh.afrh14 = cm_object_get_child_by_name(state->f4.reg.afrh,
            "AFRH14");
    state->f4.fld.afrh.afrh15 = cm_object_get_child_by_name(state->f4.reg.afrh,
            "AFRH15");
}

// ----- Public ---------------------------------------------------------------

/*
 * Create GPIO[i] and return it.
 */
Object* stm32_gpio_create(Object *parent, stm32_gpio_index_t index)
{
    char child_name[10];
    snprintf(child_name, sizeof(child_name), "GPIO%c", 'A' + index);
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

/*
 * Return a pointer to the gpio[n] object, or null if not found.
 */
Object* stm32_gpio_get(int index)
{
    char gpio_name[40];
    snprintf(gpio_name, sizeof(gpio_name), "/machine/mcu/stm32/gpio[%c]",
            'a' + index);
    return object_resolve_path(gpio_name, NULL);
}

// ----- Private --------------------------------------------------------------

static void stm32_gpio_update_idr(STM32GPIOState *state, Object *idr,
        uint16_t new_odr);

static void stm32_gpio_set_odr_irqs(STM32GPIOState *state, uint16_t old_odr,
        uint16_t new_odr);

static void stm32_gpio_update_odr_and_idr(STM32GPIOState *state, Object *odr,
        Object *idr, uint16_t new_value);

/* ------------------------------------------------------------------------- */

static bool stm32_gpio_is_enabled(Object *obj)
{
#if 1
    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if ((peripheral_register_read_value(state->rcc->f0.reg.ahbenr)
                & (0x20000 << state->port_index)) != 0) {
            return true;
        }
        break;

    case STM32_FAMILY_F1:

        if ((peripheral_register_read_value(state->rcc->f1.reg.apb2enr)
                & (0x4 << state->port_index)) != 0) {
            return true;
        }
        break;

    case STM32_FAMILY_F4:

        if ((peripheral_register_read_value(state->rcc->f4.reg.ahb1enr)
                & (0x1 << state->port_index)) != 0) {
            return true;
        }
        break;

    default:
        break;
    }

    return false;
#else
    /* Always enabled. Used during tests. */
    return true;
#endif
}

#if 0
static PeripheralInfo stm32f0_gpio_info =
{
    .desc = "General-purpose I/Os (GPIO)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_ALL,

    .registers =
    (PeripheralRegisterInfo[] ) {
        {
            .desc =
            "GPIO port mode register (GPIOx_MODER)",
            .name = "moder",
            .offset_bytes = 0x00,
            /* 0xA8000000 for port A, 0x00000280 for port B */
            .reset_value = 0x00000000,
            /**/
        },
        {
            .desc =
            "GPIO port output type register (GPIOx_OTYPER)",
            .name = "otyper",
            .offset_bytes = 0x04,
            .reset_value = 0x00000000,
            .readable_bits = 0x0000FFFF,
            .writable_bits = 0x0000FFFF,
            /**/
        },
        {
            .desc =
            "GPIO port output speed register (GPIOx_OSPEEDR)",
            .name = "ospeeder",
            .offset_bytes = 0x08,
            .reset_value = 0x00000000, /* 0x0000 00C0 for port B */
            /**/
        },
        {
            .desc =
            "GPIO port pull-up/pull-down register (GPIOx_PUPDR)",
            .name = "pupdr",
            .offset_bytes = 0x0C,
            /* 0x640000C0 for port A, 0x00000100 for port B */
            .reset_value = 0x00000000,
            /**/
        },
        {
            .desc =
            "GPIO Port input data register (GPIOx_IDR)",
            .name = "idr",
            .offset_bytes = 0x10,
            .reset_value = 0x00000000,
            .reset_mask = 0xFFFF0000,
            .readable_bits = 0x0000FFFF,
            .rw_mode = REGISTER_RW_MODE_READ,
            /**/
        },
        {
            .desc =
            "GPIO Port output data register (GPIOx_ODR)",
            .name = "odr",
            .offset_bytes = 0x14,
            .reset_value = 0x00000000,
            .writable_bits = 0x0000FFFF,
            .readable_bits = 0x0000FFFF,
            /**/
        },
        {
            .desc =
            "GPIO Port bit set/reset register (GPIOx_BSRR) ",
            .name = "bsrr",
            .offset_bytes = 0x18,
            .reset_value = 0x00000000,
            .rw_mode = REGISTER_RW_MODE_WRITE,
            /**/
        },
        {
            .desc =
            "GPIO Port configuration lock register (GPIOx_LCKR)",
            .name = "lckr",
            .offset_bytes = 0x1C,
            .reset_value = 0x00000000,
            .readable_bits = 0x0001FFFF,
            .writable_bits = 0x0001FFFF,
            /**/
        },
        {
            .desc =
            "GPIO alternate function low register (GPIOx_AFRL)",
            .name = "afrl",
            .offset_bytes = 0x20,
            .reset_value = 0x00000000,
            /**/
        },
        {
            .desc =
            "GPIO alternate function low register (GPIOx_AFRH)",
            .name = "afrh",
            .offset_bytes = 0x24,
            .reset_value = 0x00000000,
            /**/
        },
        {
            .desc =
            "GPIO Port bit reset register (GPIOx_BRR) ",
            .name = "brr",
            .offset_bytes = 0x28,
            .reset_value = 0x00000000,
            .rw_mode = REGISTER_RW_MODE_WRITE,
            /**/
        },
        {}, /**/
    }, /**/
};
#endif

#if 0
static void stm32f051_gpio_create_objects(Object *obj, JSON_Value *family)
{
    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family, "stm32f051:gpio");

    peripheral_add_properties_and_children2(obj, info);

    state->reg.moder = cm_object_get_child_by_name(obj, "moder");
    state->reg.otyper = cm_object_get_child_by_name(obj, "otyper");
    state->reg.ospeeder = cm_object_get_child_by_name(obj, "ospeeder");
    state->reg.pupdr = cm_object_get_child_by_name(obj, "pupdr");
    state->reg.idr = cm_object_get_child_by_name(obj, "idr");
    state->reg.odr = cm_object_get_child_by_name(obj, "odr");
    state->reg.bsrr = cm_object_get_child_by_name(obj, "bsrr");
    state->reg.lckr = cm_object_get_child_by_name(obj, "lckr");
    state->reg.afrl = cm_object_get_child_by_name(obj, "afrl");
    state->reg.afrh = cm_object_get_child_by_name(obj, "afrh");
    state->reg.brr = cm_object_get_child_by_name(obj, "brr");
}
#endif

static void stm32f0_gpio_brr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    Object *odr = state->reg.odr;
    assert(odr);

    /* 'value' may be have any size, use full_word. */
    uint32_t bits_to_reset = (full_value & 0x0000FFFF);

    /* Clear the BR bits. */
    uint32_t new_value = (peripheral_register_get_raw_value(odr)
            & (~bits_to_reset));
    stm32_gpio_update_odr_and_idr(state, odr, state->reg.idr, new_value);
}

/* ===== F1 ================================================================ */

/* STM32F1[LMHX]D, STM32F1CL */

static void stm32f1_gpio_update_dir_mask(STM32GPIOState *state, int index);

/* ------------------------------------------------------------------------- */

/* The peripheral registers have to be accessed only by words (32-bit). */

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

    Object *odr = state->f1.reg.odr;
    assert(odr);

    uint16_t prev_value = peripheral_register_get_raw_prev_value(odr);

    stm32_gpio_set_odr_irqs(state, prev_value, full_value);
    stm32_gpio_update_idr(state, state->f1.reg.idr, full_value);
}

static void stm32f1_gpio_bsrr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    Object *odr = state->f1.reg.odr;
    assert(odr);

    /* Although 'value' is known to be 32-bits, for consistency use full_value */
    uint32_t bits_to_set = (full_value & 0x0000FFFF);
    uint32_t bits_to_reset = ((full_value >> 16) & 0x0000FFFF);

    /* Clear the BR bits and set the BS bits. */
    uint32_t new_value = (peripheral_register_get_raw_value(odr)
            & (~bits_to_reset)) | bits_to_set;
    stm32_gpio_update_odr_and_idr(state, odr, state->f1.reg.idr, new_value);
}

static void stm32f1_gpio_brr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    Object *odr = state->f1.reg.odr;
    assert(odr);

    /* Although 'value' is known to be 32-bits, for consistency use full_value */
    uint32_t bits_to_reset = (full_value & 0x0000FFFF);

    /* Clear the BR bits. */
    uint32_t new_value = peripheral_register_get_raw_value(odr)
            & ~bits_to_reset;
    stm32_gpio_update_odr_and_idr(state, odr, state->f1.reg.idr, new_value);
}

#if 0
static PeripheralInfo stm32f1_gpio_info = {
    .desc = "General-purpose I/Os (GPIO)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_WORD,

    .registers = (PeripheralRegisterInfo[] ) {
        {
            .desc = "Port configuration register low (GPIOx_CRL)",
            .name = "crl",
            .offset_bytes = 0x00,
            .reset_value = 0x44444444,
            /**/
        },
        {
            .desc = "Port configuration register low (GPIOx_CRH)",
            .name = "crh",
            .offset_bytes = 0x04,
            .reset_value = 0x44444444,
            /**/
        },

        {
            .desc = "Port input data register (GPIOx_IDR)",
            .name = "idr",
            .offset_bytes = 0x08,
            .reset_value = 0x00000000,
            .reset_mask = 0xFFFF0000,
            .readable_bits = 0x0000FFFF,
            .rw_mode = REGISTER_RW_MODE_READ,
            /**/
        },
        {
            .desc = "Port output data register (GPIOx_ODR)",
            .name = "odr",
            .offset_bytes = 0x0C,
            .reset_value = 0x00000000,
            .writable_bits = 0x0000FFFF,
            .rw_mode = REGISTER_RW_MODE_WRITE,
            /**/
        },
        {
            .desc = "Port bit set/reset register (GPIOx_BSRR)",
            .name = "bsrr",
            .offset_bytes = 0x10,
            .reset_value = 0x00000000,
            .writable_bits = 0xFFFFFFFF,
            .rw_mode = REGISTER_RW_MODE_WRITE,
            /**/
        },
        {
            .desc = "Port bit reset register (GPIOx_BRR) ",
            .name = "brr",
            .offset_bytes = 0x14,
            .reset_value = 0x00000000,
            .writable_bits = 0x0000FFFF,
            .rw_mode = REGISTER_RW_MODE_WRITE,
            /**/
        },
        {
            .desc = "Port configuration lock register (GPIOx_LCKR)",
            .name = "lckr",
            .offset_bytes = 0x18,
            .reset_value = 0x0001FFFF,
            .readable_bits = 0x0001FFFF,
            .writable_bits = 0x0001FFFF,
            /**/
        },
        {}, /**/
    }, /**/
};
#endif

#if 0
static void stm32f1xx_gpio_create_objects(Object *obj, JSON_Value *family)
{
    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family, "stm32f1xx:gpio");

    peripheral_add_properties_and_children2(obj, info);

    state->f1.reg.crl = cm_object_get_child_by_name(obj, "crl");
    state->f1.reg.crh = cm_object_get_child_by_name(obj, "crh");
    state->f1.reg.idr = cm_object_get_child_by_name(obj, "idr");
    state->f1.reg.odr = cm_object_get_child_by_name(obj, "odr");
    state->f1.reg.bsrr = cm_object_get_child_by_name(obj, "bsrr");
    state->f1.reg.brr = cm_object_get_child_by_name(obj, "brr");
    state->f1.reg.lckr = cm_object_get_child_by_name(obj, "lckr");
}
#endif

/* ------------------------------------------------------------------------- */

/*
 * Gets the four configuration bits for the pin from the CRL or CRH
 * register.
 */
static uint32_t stm32f1_gpio_get_pin_config(STM32GPIOState *state, unsigned pin)
{
    /*
     * Simplify extract logic by combining both 32 bit registers into
     * one 64 bit value.
     */
    uint64_t cr_64 =
            ((uint64_t) peripheral_register_get_raw_value(state->f1.reg.crh)
                    << 32)
                    | (peripheral_register_get_raw_value(state->f1.reg.crl)
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
        /*
         * If the mode is 0, the pin is input.  Otherwise, it
         * is output.
         */
        if (pin_dir == 0) {
            state->dir_mask &= ~(1 << pin); /* Input pin */
        } else {
            state->dir_mask |= (1 << pin); /* Output pin */
        }
    }
}

/* ===== F4 ================================================================ */

/* STM32F4[01][57]xx, STM32F4[23]xxx, STM32F411xx */

uint32_t stm32f4_gpio_get_config_bits(uint32_t value, uint32_t bit);
static void stm32f4_gpio_update_dir_mask(STM32GPIOState *state);

/* ------------------------------------------------------------------------- */

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

    /* 'value' may be have any size, use full_word. */
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

    /* 'value' may be have any size, use full_word. */
    uint32_t bits_to_set = (full_value & 0x0000FFFF);
    uint32_t bits_to_reset = ((full_value >> 16) & 0x0000FFFF);

    /* Clear the BR bits and set the BS bits. */
    uint32_t new_value = (peripheral_register_get_raw_value(odr)
            & (~bits_to_reset)) | bits_to_set;
    stm32_gpio_update_odr_and_idr(state, odr, state->reg.idr, new_value);
}

#if 0
static PeripheralInfo stm32f4_gpio_info =
{
    .desc = "General-purpose I/Os (GPIO)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_ALL,

    .registers =
    (PeripheralRegisterInfo[] ) {
        {
            .desc =
            "GPIO port mode register (GPIOx_MODER)",
            .name = "moder",
            .offset_bytes = 0x00,
            /* 0xA8000000 for port A, 0x00000280 for port B */
            .reset_value = 0x00000000,
            /**/
        },
        {
            .desc =
            "GPIO port output type register (GPIOx_OTYPER)",
            .name = "otyper",
            .offset_bytes = 0x04,
            .reset_value = 0x00000000,
            .readable_bits = 0x0000FFFF,
            .writable_bits = 0x0000FFFF,
            /**/
        },
        {
            .desc =
            "GPIO port output speed register (GPIOx_OSPEEDR)",
            .name = "ospeeder",
            .offset_bytes = 0x08,
            .reset_value = 0x00000000, /* 0x0000 00C0 for port B */
            /**/
        },
        {
            .desc =
            "GPIO port pull-up/pull-down register (GPIOx_PUPDR)",
            .name = "pupdr",
            .offset_bytes = 0x0C,
            /* 0x640000C0 for port A, 0x00000100 for port B */
            .reset_value = 0x00000000,
            /**/
        },
        {
            .desc =
            "GPIO Port input data register (GPIOx_IDR)",
            .name = "idr",
            .offset_bytes = 0x10,
            .reset_value = 0x00000000,
            .reset_mask = 0xFFFF0000,
            .readable_bits = 0x0000FFFF,
            .rw_mode = REGISTER_RW_MODE_READ,
            /**/
        },
        {
            .desc =
            "GPIO Port output data register (GPIOx_ODR)",
            .name = "odr",
            .offset_bytes = 0x14,
            .reset_value = 0x00000000,
            .writable_bits = 0x0000FFFF,
            .readable_bits = 0x0000FFFF,
            /**/
        },
        {
            .desc =
            "GPIO Port bit set/reset register (GPIOx_BSRR) ",
            .name = "bsrr",
            .offset_bytes = 0x18,
            .reset_value = 0x00000000,
            .rw_mode = REGISTER_RW_MODE_WRITE,
            /**/
        },
        {
            .desc =
            "GPIO Port configuration lock register (GPIOx_LCKR)",
            .name = "lckr",
            .offset_bytes = 0x1C,
            .reset_value = 0x00000000,
            .readable_bits = 0x0001FFFF,
            .writable_bits = 0x0001FFFF,
            /**/
        },
        {
            .desc =
            "GPIO alternate function low register (GPIOx_AFRL)",
            .name = "afrl",
            .offset_bytes = 0x20,
            .reset_value = 0x00000000,
            /**/
        },
        {
            .desc =
            "GPIO alternate function low register (GPIOx_AFRH)",
            .name = "afrh",
            .offset_bytes = 0x24,
            .reset_value = 0x00000000,
            /**/
        },
        {}, /**/
    }, /**/
};
#endif

#if 0
static void stm32f4xx_gpio_create_objects(Object *obj, JSON_Value *family)
{
    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family, "stm32f4xx:gpio");

    peripheral_add_properties_and_children2(obj, info);

    state->reg.moder = cm_object_get_child_by_name(obj, "moder");
    state->reg.otyper = cm_object_get_child_by_name(obj, "otyper");
    state->reg.ospeeder = cm_object_get_child_by_name(obj, "ospeeder");
    state->reg.pupdr = cm_object_get_child_by_name(obj, "pupdr");
    state->reg.idr = cm_object_get_child_by_name(obj, "idr");
    state->reg.odr = cm_object_get_child_by_name(obj, "odr");
    state->reg.bsrr = cm_object_get_child_by_name(obj, "bsrr");
    state->reg.lckr = cm_object_get_child_by_name(obj, "lckr");
    state->reg.afrl = cm_object_get_child_by_name(obj, "afrl");
    state->reg.afrh = cm_object_get_child_by_name(obj, "afrh");
}
#endif

/* ------------------------------------------------------------------------- */

/*
 * The F4 family has more uniform configuration registers, each
 * register bit has a 2-bits slice in a register.
 */
uint32_t stm32f4_gpio_get_config_bits(uint32_t value, uint32_t bit)
{
    assert(bit < 16);
    return (value >> (bit * 2)) & 0x3;
}

static void stm32f4_gpio_update_dir_mask(STM32GPIOState *state)
{
    uint32_t moder = peripheral_register_get_raw_value(state->reg.moder);

    /* Fully recompute the direction mask. */
    int bit;
    uint32_t mode;
    for (bit = 0; bit < 16; bit++) {
        mode = stm32f4_gpio_get_config_bits(moder, bit);
        /*
         * If the mode is 1, the bit is output. Otherwise, it
         * is input or has alternate functions.
         */
        if (mode == 1) {
            state->dir_mask |= (1 << bit); /* Output pin */
        } else {
            state->dir_mask &= ~(1 << bit); /* Input pin */
        }
    }
}

/* ========================================================================= */

/*
 * Write the ODR register and trigger interrupts for changed pins
 * (output only).
 *
 * The odr pointer is passed to make the function useful for other
 * families too.
 */
static void stm32_gpio_update_odr_and_idr(STM32GPIOState *state, Object *odr,
        Object *idr, uint16_t new_value)
{
    assert(odr);

    /* Preserve old value, to compute changed bits */
    uint16_t old_value = peripheral_register_get_raw_value(odr);

    /*
     * Update register value. Per documentation, the upper 16 bits
     * always read as 0, so write is used, to apply the mask.
     */
    peripheral_register_write_value(odr, new_value);

    stm32_gpio_set_odr_irqs(state, old_value, new_value);
    stm32_gpio_update_idr(state, idr, new_value);
}

static void stm32_gpio_set_irq(STM32GPIOState *state, int pin, int level)
{
    assert(pin < 16);

    const STM32Capabilities *capabilities = state->capabilities;

    /*
     * Implement the SYSCFG/AFIO multiplexers at origin, in GPIO,
     * instead of forwarding all interrupts to EXTI to be rejected there.
     */

    if (capabilities->family == STM32_FAMILY_F1) {
        // TODO: on F1, use AFIO.
        cm_irq_set(state->exti_irq[pin], level);
    } else {
        if (register_bitfield_read_value(state->syscfg->exticr.exti[pin])
                == pin) {
            cm_irq_set(state->exti_irq[pin], level);
        }
    }
}

static void stm32_gpio_set_odr_irqs(STM32GPIOState *state, uint16_t old_odr,
        uint16_t new_odr)
{
    // const STM32Capabilities *capabilities = state->capabilities;

    /* Compute pins that changed value. */
    uint16_t changed = old_odr ^ new_odr;

    /* Filter changed pins that are outputs - do not touch input pins. */
    uint16_t changed_out = changed & state->dir_mask;

    uint16_t mask = 1;
    if (changed_out) {
        int pin;
        for (pin = 0; pin < STM32_GPIO_PIN_COUNT; pin++, mask <<= 1) {
            /*
             * If the value of this pin has changed, then update
             * the output IRQ.
             */
            if ((changed_out & mask) != 0) {
                int level = (new_odr & mask) ? 1 : 0;

                cm_irq_set(state->odr_irq[pin], level);

                stm32_gpio_set_irq(state, pin, level);
            }
        }
    }
}

/*
 * For output pins, make them read back the written value.
 *
 * TODO: check if there is anything special for open-drain pins.
 */
static void stm32_gpio_update_idr(STM32GPIOState *state, Object *idr,
        uint16_t new_odr)
{
    assert(idr);

    /* Clear output bits. */
    peripheral_register_and_raw_value(idr, ~state->dir_mask);
    /* Copy output bits from ODR. */
    peripheral_register_or_raw_value(idr, (new_odr & state->dir_mask));
}

/*
 * Callback fired when a GPIO input pin changes state (based
 * on an external stimulus from the machine).
 */
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
    /* Update internal pin state. */
    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        idr = state->reg.idr;
        break;

    case STM32_FAMILY_F1:

        idr = state->f1.reg.idr;
        break;

    case STM32_FAMILY_F4:

        idr = state->reg.idr;
        break;

    default:
        assert(false);
        return;
    }

    // TODO: check if a mutex is needed,
    // this can be called from the graphic thread.
    if (level == 0) {
        /* Clear the IDR bit. */
        peripheral_register_and_raw_value(idr, ~(1 << pin));
    } else {
        /* Set the IDR bit. */
        peripheral_register_or_raw_value(idr, (1 << pin));
    }

    stm32_gpio_set_irq(state, pin, level);
}

/* ------------------------------------------------------------------------- */

static void stm32_gpio_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    cm_object_property_add_int(obj, "port-index",
            (const int *) &state->port_index);
    state->port_index = STM32_GPIO_PORT_UNDEFINED;

    cm_irq_init_in(DEVICE(obj), stm32_gpio_in_irq_handler,
    STM32_IRQ_GPIO_IDR_IN, STM32_GPIO_PIN_COUNT);

    /*
     * Outgoing interrupts, will be later connected to EXTI.
     */
    cm_irq_init_out(DEVICE(obj), state->exti_irq, STM32_IRQ_GPIO_EXTI_OUT,
    STM32_GPIO_PIN_COUNT);

    /*
     * Outgoing interrupts, machine devices like LEDs might
     * be connected here.
     */
    cm_irq_init_out(DEVICE(obj), state->odr_irq, STM32_IRQ_GPIO_ODR_OUT,
    STM32_GPIO_PIN_COUNT);

}

static void stm32_gpio_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /*
     * Parent realize() is called after setting properties and creating
     * registers.
     */

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32GPIOState *state = STM32_GPIO_STATE(dev);
    /* First thing first: get capabilities from MCU, needed everywhere. */
    state->capabilities = mcu->capabilities;

    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    char periph_name[10];
    snprintf(periph_name, sizeof(periph_name) - 1, "GPIO%c",
            'A' + state->port_index);

    // TODO: use links
    state->rcc = STM32_RCC_STATE(cm_device_by_name(DEVICE_PATH_STM32_RCC));

    /* Must be defined before creating registers. */
    cm_object_property_set_int(obj, 4, "register-size-bytes");

    /* TODO: get it from MCU */
    cm_object_property_set_bool(obj, true, "is-little-endian");

    /*
     * Creating the memory region in the parent class will trigger
     * an assertion if zro address or size.
     */
    uint32_t size = 0;
    hwaddr addr = 0;

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if (state->port_index > STM32_GPIO_PORT_F) {
            qemu_log_mask(LOG_GUEST_ERROR, "GPIO: Illegal GPIO port %d\n",
                    state->port_index);
            return;
        }

        size = 0x400;
        addr = 0x48000000 + (state->port_index - STM32_GPIO_PORT_A) * size;

        state->syscfg = STM32_SYSCFG_STATE(
                cm_device_by_name(DEVICE_PATH_STM32_SYSCFG));

        break;

    case STM32_FAMILY_F1:

        if (state->port_index > STM32_GPIO_PORT_G) {
            qemu_log_mask(LOG_GUEST_ERROR, "GPIO: Illegal GPIO port %d\n",
                    state->port_index);
            return;
        }

        size = 0x400;
        addr = 0x40010800 + (state->port_index - STM32_GPIO_PORT_A) * size;

        break;

    case STM32_FAMILY_F4:

        if (state->port_index > STM32_GPIO_PORT_K) {
            qemu_log_mask(LOG_GUEST_ERROR, "GPIO: Illegal GPIO port %d\n",
                    state->port_index);
            return;
        }

        size = 0x400;
        addr = 0x40020000 + (state->port_index - STM32_GPIO_PORT_A) * size;

        state->syscfg = STM32_SYSCFG_STATE(
                cm_device_by_name(DEVICE_PATH_STM32_SYSCFG));

        break;

    default:

        assert(false);
        break;
    }

    cm_object_property_set_int(obj, addr, "mmio-address");
    cm_object_property_set_int(obj, size, "mmio-size-bytes");

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x1) {

            stm32f0x1_gpio_create_objects(obj, cm_state->svd_json, periph_name);
            // stm32f051_gpio_create_objects(obj, mcu->family_json);

            state->reg.moder = state->f0.reg.moder;
            state->reg.otyper = state->f0.reg.otyper;
            state->reg.ospeeder = state->f0.reg.ospeedr;
            state->reg.pupdr = state->f0.reg.pupdr;
            state->reg.idr = state->f0.reg.idr;
            state->reg.odr = state->f0.reg.odr;
            state->reg.bsrr = state->f0.reg.bsrr;
            state->reg.lckr = state->f0.reg.lckr;
            state->reg.afrl = state->f0.reg.afrl;
            state->reg.afrh = state->f0.reg.afrh;
            state->reg.brr = state->f0.reg.brr;

            /* Add callbacks. Use some of the F4 callbacks.*/
            peripheral_register_set_post_write(state->reg.moder,
                    &stm32f4_gpio_moder_post_write_callback);
            peripheral_register_set_post_write(state->reg.odr,
                    &stm32f4_gpio_odr_post_write_callback);
            peripheral_register_set_post_write(state->reg.bsrr,
                    &stm32f4_gpio_bsrr_post_write_callback);

            /* F0 specific. */
            peripheral_register_set_post_write(state->reg.brr,
                    &stm32f0_gpio_brr_post_write_callback);

        } else {
            assert(false);
        }

        break;

    case STM32_FAMILY_F1:

        if (capabilities->f1.is_103xx) {
            // stm32f1xx_gpio_create_objects(obj, mcu->family_json);
            stm32f103xx_gpio_create_objects(obj, cm_state->svd_json,
                    periph_name);

            /* Add callbacks. */
            peripheral_register_set_post_write(state->f1.reg.crl,
                    &stm32f1_gpio_crl_post_write_callback);
            peripheral_register_set_post_write(state->f1.reg.crh,
                    &stm32f1_gpio_crh_post_write_callback);
            peripheral_register_set_post_write(state->f1.reg.odr,
                    &stm32f1_gpio_odr_post_write_callback);
            peripheral_register_set_post_write(state->f1.reg.bsrr,
                    &stm32f1_gpio_bsrr_post_write_callback);
            peripheral_register_set_post_write(state->f1.reg.brr,
                    &stm32f1_gpio_brr_post_write_callback);
        } else {
            assert(false);
        }

        break;

    case STM32_FAMILY_F4:

        if (capabilities->f4.is_40x) {

            stm32f40x_gpio_create_objects(obj, cm_state->svd_json, periph_name);
            // stm32f4xx_gpio_create_objects(obj, mcu->family_json);

            state->reg.moder = state->f4.reg.moder;
            state->reg.otyper = state->f4.reg.otyper;
            state->reg.ospeeder = state->f4.reg.ospeedr;
            state->reg.pupdr = state->f4.reg.pupdr;
            state->reg.idr = state->f4.reg.idr;
            state->reg.odr = state->f4.reg.odr;
            state->reg.bsrr = state->f4.reg.bsrr;
            state->reg.lckr = state->f4.reg.lckr;
            state->reg.afrl = state->f4.reg.afrl;
            state->reg.afrh = state->f4.reg.afrh;

            /* Add callbacks. */
            peripheral_register_set_post_write(state->reg.moder,
                    &stm32f4_gpio_moder_post_write_callback);
            peripheral_register_set_post_write(state->reg.odr,
                    &stm32f4_gpio_odr_post_write_callback);
            peripheral_register_set_post_write(state->reg.bsrr,
                    &stm32f4_gpio_bsrr_post_write_callback);

        } else {
            assert(false);
        }

        break;

    default:
        assert(false);
        break;
    }

#if 0
    char name[10];
    snprintf(name, sizeof(name), "gpio[%c]", 'a' + state->port_index);
    cm_object_property_set_str(obj, name, "name");
#endif

    /* Call parent realize(). */
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_GPIO)) {
        return;
    }
}

static void stm32_gpio_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    /* No need to call parent reset(). */

    STM32GPIOState *state = STM32_GPIO_STATE(dev);

    const STM32Capabilities *capabilities =
    STM32_GPIO_STATE(state)->capabilities;

    Object *odr = NULL;
    switch (capabilities->family) {
    case STM32_FAMILY_F0:
        odr = state->reg.odr;
        break;

    case STM32_FAMILY_F1:
        odr = state->f1.reg.odr;
        break;

    case STM32_FAMILY_F4:
        odr = state->reg.odr;
        break;

    default:
        assert(false);
        break;
    }

    assert(odr);
    uint16_t prev_odr = peripheral_register_get_raw_value(odr);

    /* Call parent reset(). */
    cm_device_parent_reset(dev, TYPE_STM32_GPIO);

    uint16_t new_odr = peripheral_register_get_raw_value(odr);

    /* Update connected devices, like LEDs, to new ODR. */
    stm32_gpio_set_odr_irqs(state, prev_odr, new_odr);

    state->dir_mask = 0;

    switch (capabilities->family) {
    case STM32_FAMILY_F0:
        /* Use the F4 code */
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
    .class_size = sizeof(STM32GPIOClass) /**/
};

static void stm32_gpio_register_types(void)
{
    type_register_static(&stm32_gpio_type_info);

#if 0
    peripheral_serialize_info("f051-gpio.json", "stm32f051:gpio", &stm32f0_gpio_info);
    peripheral_serialize_info("f1xx-gpio.json", "stm32f1xx:gpio", &stm32f1_gpio_info);
    peripheral_serialize_info("f4xx-gpio.json", "stm32f4xx:gpio", &stm32f4_gpio_info);
#endif
}

type_init(stm32_gpio_register_types);

/* ------------------------------------------------------------------------- */
