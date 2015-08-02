/*
 * STM32 Olimex boards emulation.
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
 * This file defines several Olimex STM32 boards.
 */

/* ----- Olimex STM32-H103 ----- */

static GPIOLEDInfo stm32_h103_leds_info[] = {
    {
        .name = "green-led",
        .active_low = true,
        .colour_message = "Green",
        .x = 97,
        .y = 243,
        .w = 14,
        .h = 12,
        .gpio_path = "/machine/mcu/stm32/gpio[c]",
        .port_bit = 12, },
    { }, /**/
};

static void stm32_h103_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);

    {
        /* Create the MCU */
        Object *mcu = cm_object_new_mcu(machine, TYPE_STM32F103RB);

        /* Set the board specific oscillator frequencies. */
        cm_object_property_set_int(mcu, 8000000, "hse-freq-hz"); /* 8.0 MHz */
        cm_object_property_set_int(mcu, 32768, "lse-freq-hz"); /* 32 kHz */

        cm_object_realize(mcu);
    }

    void *board_surface = cm_board_init_image("STM32-H103.jpg",
            cm_board_get_desc(machine));

    Object *peripheral = cm_container_get_peripheral();
    gpio_led_create_from_info(peripheral, stm32_h103_leds_info, board_surface);
}

static QEMUMachine stm32_h103_machine = {
    .name = "STM32-H103",
    .desc = "Olimex Header Board for STM32F103RBT6",
    .init = stm32_h103_board_init_callback };

/* ----- Olimex STM32-P103 ----- */

static GPIOLEDInfo stm32_p103_leds_info[] = {
    {
        .name = "red-led",
        .active_low = true,
        .colour_message = "Red",
        .x = 331,
        .y = 362,
        .w = 12,
        .h = 10,
        .gpio_path = "/machine/mcu/stm32/gpio[c]",
        .port_bit = 12, },
    { }, /**/
};

static void stm32_p103_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);

    {
        /* Create the MCU */
        Object *mcu = cm_object_new_mcu(machine, TYPE_STM32F103RB);

        /* Set the board specific oscillator frequencies. */
        cm_object_property_set_int(mcu, 8000000, "hse-freq-hz"); /* 8.0 MHz */
        cm_object_property_set_int(mcu, 32768, "lse-freq-hz"); /* 32 kHz */

        cm_object_realize(mcu);
    }

    void *board_surface = cm_board_init_image("STM32-P103.jpg",
            cm_board_get_desc(machine));

    Object *peripheral = cm_container_get_peripheral();
    gpio_led_create_from_info(peripheral, stm32_p103_leds_info, board_surface);
}

static QEMUMachine stm32_p103_machine = {
    .name = "STM32-P103",
    .desc = "Olimex Prototype Board for STM32F103RBT6",
    .init = stm32_p103_board_init_callback };

/* ----- Olimex OLIMEXINO-STM32 ----- */

static GPIOLEDInfo olimexino_stm32_leds_info[] = {
    {
        .name = "green-led",
        .active_low = false,
        .colour_message = "Green",
        .x = 137,
        .y = 40,
        .w = 10,
        .h = 10,
        .gpio_path = "/machine/mcu/stm32/gpio[a]",
        .port_bit = 5, },
    {
        .name = "yellow-led",
        .active_low = false,
        .colour_message = "Yellow",
        .x = 168,
        .y = 40,
        .w = 10,
        .h = 10,
        .gpio_path = "/machine/mcu/stm32/gpio[a]",
        .port_bit = 1, },
    { }, /**/
};

static void olimexino_stm32_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);

    {
        /* Create the MCU */
        Object *mcu = cm_object_new_mcu(machine, TYPE_STM32F103RB);

        /* Set the board specific oscillator frequencies. */
        cm_object_property_set_int(mcu, 8000000, "hse-freq-hz"); /* 8.0 MHz */
        cm_object_property_set_int(mcu, 32768, "lse-freq-hz"); /* 32 kHz */

        cm_object_realize(mcu);
    }

    void *board_surface = cm_board_init_image("OLIMEXINO-STM32.jpg",
            cm_board_get_desc(machine));

    Object *peripheral = cm_container_get_peripheral();
    gpio_led_create_from_info(peripheral, olimexino_stm32_leds_info,
            board_surface);
}

static QEMUMachine olimexino_stm32_machine = {
    .name = "OLIMEXINO-STM32",
    .desc = "Olimex Mapple (Arduino-like) Development Board",
    .init = olimexino_stm32_board_init_callback };

/* ----- Olimex STM32-P107 ----- */

static GPIOLEDInfo stm32_p107_leds_info[] = {
    {
        .name = "green-led",
        .active_low = false,
        .colour_message = "Green",
        .x = 171,
        .y = 354,
        .w = 6,
        .h = 8,
        .gpio_path = "/machine/mcu/stm32/gpio[c]",
        .port_bit = 6, },
    {
        .name = "yellow-led",
        .active_low = false,
        .colour_message = "Yellow",
        .x = 227,
        .y = 354,
        .w = 6,
        .h = 8,
        .gpio_path = "/machine/mcu/stm32/gpio[c]",
        .port_bit = 7, },
    { }, /**/
};

static void stm32_p107_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);

    {
        /* Create the MCU */
        Object *mcu = cm_object_new_mcu(machine, TYPE_STM32F107VC);

        /* Set the board specific oscillator frequencies. */
        cm_object_property_set_int(mcu, 25000000, "hse-freq-hz"); /* 25.0 MHz */
        cm_object_property_set_int(mcu, 32768, "lse-freq-hz"); /* 32 kHz */

        cm_object_realize(mcu);
    }

    void *board_surface = cm_board_init_image("STM32-P107.jpg",
            cm_board_get_desc(machine));

    Object *peripheral = cm_container_get_peripheral();
    gpio_led_create_from_info(peripheral, stm32_p107_leds_info, board_surface);
}

static QEMUMachine stm32_p107_machine = {
    .name = "STM32-P107",
    .desc = "Olimex Prototype Board for STM32F107VCT6",
    .init = stm32_p107_board_init_callback };

/* ----- Olimex STM32-P407 ----- */

static GPIOLEDInfo stm32_e407_leds_info[] = {
    {
        .name = "green-led",
        .active_low = true,
        .colour_message = "Green",
        .x = 73,
        .y = 408,
        .w = 8,
        .h = 6,
        .gpio_path = "/machine/mcu/stm32/gpio[c]",
        .port_bit = 13, },
    { }, /**/
};

static void stm32_e407_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);
    {
        /* Create the MCU */
        Object *mcu = cm_object_new_mcu(machine, TYPE_STM32F407ZG);

        /* Set the board specific oscillator frequencies. */
        cm_object_property_set_int(mcu, 12000000, "hse-freq-hz"); /* 12.0 MHz */
        cm_object_property_set_int(mcu, 32768, "lse-freq-hz"); /* 32 kHz */

        cm_object_realize(mcu);
    }

    void *board_surface = cm_board_init_image("STM32-E407.jpg",
            cm_board_get_desc(machine));

    Object *peripheral = cm_container_get_peripheral();
    gpio_led_create_from_info(peripheral, stm32_e407_leds_info, board_surface);
}

static QEMUMachine stm32_e407_machine = {
    .name = "STM32-E407",
    .desc = "Olimex Development Board for STM32F407ZGT6",
    .init = stm32_e407_board_init_callback };

/* ----- Boards inits ----- */
static void stm32_olimex_machines_init(void)
{
    qemu_register_machine(&stm32_e407_machine);
    qemu_register_machine(&stm32_p107_machine);
    qemu_register_machine(&stm32_p103_machine);
    qemu_register_machine(&stm32_h103_machine);
    qemu_register_machine(&olimexino_stm32_machine);
}

machine_init(stm32_olimex_machines_init);
