/*
 * STM32 Nucleo boards emulation.
 *
 * Copyright (c) 2014 Liviu Ionescu.
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

#include "hw/arm/stm32-mcus.h"
#include "hw/display/gpio-led.h"
#include "hw/arm/cortexm-helper.h"

/*
 * This file defines several STM32 Nucleo boards.
 */

/* ----- ST NUCLEO-F103RB ----- */

static GPIOLEDInfo nucleo_f103rb_leds_info[] = {
    {
        .name = "green-led",
        .active_low = false,
        .colour_message = "Green",
        .x = 277,
        .y = 271,
        .w = 8,
        .h = 6,
        .gpio_path = "/machine/mcu/stm32/gpio[a]",
        .port_bit = 5, },
    { }, /**/
};

static void nucleo_f103rb_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);

    {
        /* Create the MCU */
        Object *mcu = cm_object_new_mcu(machine, TYPE_STM32F103RB);

        /* The board has no oscillators. */
        cm_object_property_set_int(mcu, 0, "hse-freq-hz"); /* N/A */
        cm_object_property_set_int(mcu, 0, "lse-freq-hz"); /* N/A */

        cm_object_realize(mcu);
    }

    void *board_surface = cm_board_init_image("NUCLEO-F103RB.jpg",
            cm_board_get_desc(machine));

    Object *peripheral = cm_container_get_peripheral();
    gpio_led_create_from_info(peripheral, nucleo_f103rb_leds_info,
            board_surface);
}

static QEMUMachine nucleo_f103rb_machine = {
    .name = "NUCLEO-F103RB",
    .desc = "ST Nucleo Development Board for STM32 F1 series",
    .init = nucleo_f103rb_board_init_callback };

#if 0
/* ----- ST NUCLEO-L152RE ----- */
static void nucleo_l152re_board_init_callback(MachineState *machine);

static QEMUMachine nucleo_l152re_machine = {
    .name = "NUCLEO-L152RE",
    .desc = "ST Nucleo Development Board with STM32L152RET6 (Experimental)",
    .init = nucleo_l152re_board_init_callback};

static void nucleo_l152re_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);
    //cortexm_mcu_alloc(machine, TYPE_STM32L152RE);

    /* TODO: Add board inits */
}
#endif

#if 0
// Disabled due to HAL clock init problems when no clock is defined.
/* ----- ST NUCLEO-F411RE ----- */
static void nucleo_f411re_board_init_callback(MachineState *machine);

static QEMUMachine nucleo_f411re_machine = {
    .name = "NUCLEO-F411RE",
    .desc = "ST Nucleo Development Board for STM32 F4 series (Experimental)",
    .init = nucleo_f411re_board_init_callback};

static void nucleo_f411re_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);
    //cortexm_mcu_alloc(machine, TYPE_STM32F411RE);

    /* TODO: Add board inits */
}
#endif

#if 0
/* ----- ST NUCLEO-F334R8 ----- */
static void nucleo_f334r8_board_init_callback(MachineState *machine);

static QEMUMachine nucleo_f334r8_machine = {
    .name = "NUCLEO-F334R8",
    .desc = "ST Nucleo Development Board for STM32 F3 series (Experimental)",
    .init = nucleo_f334r8_board_init_callback};

static void nucleo_f334r8_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);
    //cortexm_mcu_alloc(machine, TYPE_STM32F334R8);

    /* TODO: Add board inits */
}
#endif

/* ----- Boards inits ----- */
static void stm32_machines_init(void)
{
    qemu_register_machine(&nucleo_f103rb_machine);
#if 0
    qemu_register_machine(&nucleo_l152re_machine);
    qemu_register_machine(&nucleo_f411re_machine);
    qemu_register_machine(&nucleo_f334r8_machine);
#endif
}

machine_init(stm32_machines_init);
