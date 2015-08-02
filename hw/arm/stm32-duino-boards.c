/*
 * STM32 Arduino-like boards emulation.
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
 * This file defines several Arduino-like STM32 boards.
 */

#if 0
/* ----- Netduino 2 ----- */
static void
netduino2_board_init_callback(MachineState *machine);

static QEMUMachine netduino2_machine = {
    .name = "Netduino2",
    .desc = "Netduino Development Board with STM32F2 (Experimental)",
    .init = netduino2_board_init_callback};

static void netduino2_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);
    //cortexm_mcu_alloc(machine, TYPE_STM32F205RF);

    /* TODO: Add board inits */
}
#endif

/* ----- Netduino Plus 2 ----- */

static GPIOLEDInfo netduinoplus2_leds_info[] = {
    {
        .name = "blue-led",
        .active_low = false,
        .colour_message = "Blue",
        .x = 507,
        .y = 183,
        .w = 12,
        .h = 14,
        .gpio_path = "/machine/mcu/stm32/gpio[a]",
        .port_bit = 10, },
    { }, /**/
};

static void netduinoplus2_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);

    {
        /* Create the MCU */
        Object *mcu = cm_object_new_mcu(machine, TYPE_STM32F405RG);

        /* Set the board specific oscillator frequencies. */
        cm_object_property_set_int(mcu, 25000000, "hse-freq-hz"); /* 25.0 MHz */
        cm_object_property_set_int(mcu, 0, "lse-freq-hz"); /* N/A */

        cm_object_realize(mcu);
    }

    void *board_surface = cm_board_init_image("NetduinoPlus2.jpg",
            "NetduinoPlus2");

    Object *peripheral = cm_container_get_peripheral();
    gpio_led_create_from_info(peripheral, netduinoplus2_leds_info, board_surface);
}

static QEMUMachine netduinoplus2_machine = {
    .name = "NetduinoPlus2",
    .desc = "Netduino Development Board with STM32F4",
    .init = netduinoplus2_board_init_callback };

/* ----- Netduino Go ----- */

static GPIOLEDInfo netduinogo_leds_info[] = {
    {
        .name = "white-led1",
        .active_low = false,
        .colour_message = "White",
        .x = 140,
        .y = 457,
        .w = 8,
        .h = 12,
        .on_message = "[White LED1 On]\n",
        .on_message = "[White LED1 Off]\n",
        .gpio_path = "/machine/mcu/stm32/gpio[b]",
        .port_bit = 6, },
    {
        .name = "white-led2",
        .active_low = false,
        .colour_message = "White",
        .x = 286,
        .y = 457,
        .w = 8,
        .h = 12,
        .on_message = "[White LED2 On]\n",
        .on_message = "[White LED2 Off]\n",
        .gpio_path = "/machine/mcu/stm32/gpio[b]",
        .port_bit = 7, },
    {
        .name = "white-led3",
        .active_low = false,
        .colour_message = "White",
        .x = 432,
        .y = 457,
        .w = 8,
        .h = 12,
        .on_message = "[White LED3 On]\n",
        .on_message = "[White LED3 Off]\n",
        .gpio_path = "/machine/mcu/stm32/gpio[b]",
        .port_bit = 8, },
    {
        .name = "white-led4",
        .active_low = false,
        .colour_message = "White",
        .x = 614,
        .y = 405,
        .w = 12,
        .h = 8,
        .on_message = "[White LED4 On]\n",
        .on_message = "[White LED4 Off]\n",
        .gpio_path = "/machine/mcu/stm32/gpio[b]",
        .port_bit = 9, },
    {
        .name = "white-led5",
        .active_low = false,
        .colour_message = "White",
        .x = 614,
        .y = 259,
        .w = 12,
        .h = 8,
        .on_message = "[White LED5 On]\n",
        .on_message = "[White LED5 Off]\n",
        .gpio_path = "/machine/mcu/stm32/gpio[c]",
        .port_bit = 6, },
    {
        .name = "white-led6",
        .active_low = false,
        .colour_message = "White",
        .x = 564,
        .y = 70,
        .w = 8,
        .h = 12,
        .on_message = "[White LED6 On]\n",
        .on_message = "[White LED6 Off]\n",
        .gpio_path = "/machine/mcu/stm32/gpio[c]",
        .port_bit = 7, },
    {
        .name = "white-led7",
        .colour_message = "White",
        .x = 419,
        .y = 70,
        .w = 8,
        .h = 12,
        .active_low = false,
        .on_message = "[White LED7 On]\n",
        .on_message = "[White LED7 Off]\n",
        .gpio_path = "/machine/mcu/stm32/gpio[c]",
        .port_bit = 8, },
    {
        .name = "white-led8",
        .active_low = false,
        .colour_message = "White",
        .x = 274,
        .y = 70,
        .w = 8,
        .h = 12,
        .on_message = "[White LED8 On]\n",
        .on_message = "[White LED8 Off]\n",
        .gpio_path = "/machine/mcu/stm32/gpio[c]",
        .port_bit = 9, },
    { }, /**/
};

static void netduinogo_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);

    {
        /* Create the MCU */
        Object *mcu = cm_object_new_mcu(machine, TYPE_STM32F405RG);

        /* Set the board specific oscillator frequencies. */
        cm_object_property_set_int(mcu, 25000000, "hse-freq-hz"); /* 25.0 MHz */
        cm_object_property_set_int(mcu, 0, "lse-freq-hz"); /* N/A */

        cm_object_realize(mcu);
    }

    void *board_surface = cm_board_init_image("NetduinoGo.jpg",
            cm_board_get_desc(machine));

    Object *peripheral = cm_container_get_peripheral();
    gpio_led_create_from_info(peripheral, netduinogo_leds_info, board_surface);
}

static QEMUMachine netduinogo_machine = {
    .name = "NetduinoGo",
    .desc = "Netduino GoBus Development Board with STM32F4",
    .init = netduinogo_board_init_callback };

/* ----- Mapple r5 ----- */

static GPIOLEDInfo mapple_leds_info[] = {
    {
        .name = "blue-led",
        .active_low = false,
        .colour_message = "Blue",
        .x = 215,
        .y = 161,
        .w = 10,
        .h = 8,
        .gpio_path = "/machine/mcu/stm32/gpio[a]",
        .port_bit = 5, },
    { }, /**/
};

static void mapple_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);

    {
        /* Create the MCU */
        Object *mcu = cm_object_new_mcu(machine, TYPE_STM32F103RB);

        /* Set the board specific oscillator frequencies. */
        cm_object_property_set_int(mcu, 8000000, "hse-freq-hz"); /* 8.0 MHz */
        cm_object_property_set_int(mcu, 0, "lse-freq-hz"); /* N/A */

        cm_object_realize(mcu);
    }

    void *board_surface = cm_board_init_image("Mapple.jpg",
            cm_board_get_desc(machine));

    Object *peripheral = cm_container_get_peripheral();
    gpio_led_create_from_info(peripheral, mapple_leds_info, board_surface);
}

static QEMUMachine mapple_machine = {
    .name = "Mapple",
    .desc = "LeafLab Arduino-style STM32 microcontroller board (r5)",
    .init = mapple_board_init_callback };

/* ----- Boards inits ----- */
static void stm32_duino_machines_init(void)
{
#if 0
    qemu_register_machine(&netduino2_machine);
#endif
    qemu_register_machine(&netduinoplus2_machine);
    qemu_register_machine(&netduinogo_machine);
    qemu_register_machine(&mapple_machine);
}

machine_init(stm32_duino_machines_init);
