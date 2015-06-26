/*
 * STM32 Olimex boards emulation.
 *
 * Copyright (c) 2014 Liviu Ionescu
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

static void stm32_h103_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);
    {
        /* Create the MCU */
        Object *mcu = cm_object_new(TYPE_STM32F103RB);

        qdev_prop_set_ptr(DEVICE(mcu), "machine", machine);

        /* Set the board specific oscillator frequencies. */
        object_property_set_int(mcu, 8000000, "hse-freq-hz", NULL); /* 8.0 MHz */
        object_property_set_int(mcu, 32768, "lse-freq-hz", NULL); /* 32 kHz */

        cm_object_realize(mcu);
    }

    {
        /* Create the board LED */
        Object *led = cm_object_new(TYPE_GPIO_LED);

        /* STM32-H103 Green LED, GPIOC[12], active low */
        object_property_set_bool(led, true, "active-low", NULL);
        object_property_set_str(led, "[Green LED On]\n", "on-message", NULL);
        object_property_set_str(led, "[Green LED Off]\n", "off-message", NULL);

        gpio_led_connect(led, "/machine/stm32/gpio[c]", 12);

        cm_object_realize(led);
    }
}

static QEMUMachine stm32_h103_machine = {
    .name = "STM32-H103",
    .desc = "Olimex Header Board for STM32F103RBT6",
    .init = stm32_h103_board_init_callback };

/* ----- Olimex STM32-P103 ----- */

static void stm32_p103_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);

    {
        /* Create the MCU */
        Object *mcu = cm_object_new(TYPE_STM32F103RB);

        qdev_prop_set_ptr(DEVICE(mcu), "machine", machine);

        /* Set the board specific oscillator frequencies. */
        object_property_set_int(mcu, 8000000, "hse-freq-hz", NULL); /* 8.0 MHz */
        object_property_set_int(mcu, 32768, "lse-freq-hz", NULL); /* 32 kHz */

        cm_object_realize(mcu);
    }

    {
        /* Create the board LED */
        Object *led = cm_object_new(TYPE_GPIO_LED);

        /* STM32-P103 Green LED, GPIOC[12], active low */
        object_property_set_bool(led, true, "active-low", NULL);
        object_property_set_str(led, "[Red LED On]\n", "on-message", NULL);
        object_property_set_str(led, "[Red LED Off]\n", "off-message", NULL);

        gpio_led_connect(led, "/machine/stm32/gpio[c]", 12);

        cm_object_realize(led);
    }
}

static QEMUMachine stm32_p103_machine = {
    .name = "STM32-P103",
    .desc = "Olimex Prototype Board for STM32F103RBT6",
    .init = stm32_p103_board_init_callback };

/* ----- Olimex OLIMEXINO-STM32 ----- */

static void olimexino_stm32_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);

    {
        /* Create the MCU */
        Object *mcu = cm_object_new(TYPE_STM32F103RB);

        qdev_prop_set_ptr(DEVICE(mcu), "machine", machine);

        /* Set the board specific oscillator frequencies. */
        object_property_set_int(mcu, 8000000, "hse-freq-hz", NULL); /* 8.0 MHz */
        object_property_set_int(mcu, 32768, "lse-freq-hz", NULL); /* 32 kHz */

        cm_object_realize(mcu);
    }

    {
        /* Create the board LED1 */
        Object *led = cm_object_new(TYPE_GPIO_LED);

        /* OLIMEXINO-STM32 Green LED1, PA5, active high */
        object_property_set_bool(led, false, "active-low", NULL);
        object_property_set_str(led, "[Green LED On]\n", "on-message", NULL);
        object_property_set_str(led, "[Green LED Off]\n", "off-message", NULL);

        gpio_led_connect(led, "/machine/stm32/gpio[a]", 5);

        cm_object_realize(led);
    }

    {
        /* Create the board LED2 */
        Object *led = cm_object_new(TYPE_GPIO_LED);

        /* OLIMEXINO-STM32 Yellow LED2, PA1, active high */
        object_property_set_bool(led, false, "active-low", NULL);
        object_property_set_str(led, "[Yellow LED On]\n", "on-message", NULL);
        object_property_set_str(led, "[Yellow LED Off]\n", "off-message", NULL);

        gpio_led_connect(led, "/machine/stm32/gpio[a]", 1);

        cm_object_realize(led);
    }
}

static QEMUMachine olimexino_stm32_machine = {
    .name = "OLIMEXINO-STM32",
    .desc = "Olimex Mapple (Arduino-like) Development Board",
    .init = olimexino_stm32_board_init_callback };

/* ----- Olimex STM32-P107 ----- */

static void stm32_p107_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);

    {
        /* Create the MCU */
        Object *mcu = cm_object_new(TYPE_STM32F107VC);

        qdev_prop_set_ptr(DEVICE(mcu), "machine", machine);

        /* Set the board specific oscillator frequencies. */
        object_property_set_int(mcu, 25000000, "hse-freq-hz", NULL); /* 25.0 MHz */
        object_property_set_int(mcu, 32768, "lse-freq-hz", NULL); /* 32 kHz */

        cm_object_realize(mcu);
    }

    {
        /* Create the board LED1 STAT1 */
        Object *led = cm_object_new(TYPE_GPIO_LED);

        /* STM32-P107 Green LED1, PC6, active high */
        object_property_set_bool(led, false, "active-low", NULL);
        object_property_set_str(led, "[Green LED On]\n", "on-message", NULL);
        object_property_set_str(led, "[Green LED Off]\n", "off-message", NULL);

        gpio_led_connect(led, "/machine/stm32/gpio[c]", 6);

        cm_object_realize(led);
    }

    {
        /* Create the board LED2 STAT2 */
        Object *led = cm_object_new(TYPE_GPIO_LED);

        /* STM32-P107 Yellow LED2, PC7, active high */
        object_property_set_bool(led, false, "active-low", NULL);
        object_property_set_str(led, "[Yellow LED On]\n", "on-message", NULL);
        object_property_set_str(led, "[Yellow LED Off]\n", "off-message", NULL);

        gpio_led_connect(led, "/machine/stm32/gpio[c]", 7);

        cm_object_realize(led);
    }
}

static QEMUMachine stm32_p107_machine = {
    .name = "STM32-P107",
    .desc = "Olimex Prototype Board for STM32F107VCT6",
    .init = stm32_p107_board_init_callback };

/* ----- Olimex STM32-P407 ----- */

static void stm32_e407_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);
    {
        /* Create the MCU */
        Object *mcu = cm_object_new(TYPE_STM32F407ZG);

        qdev_prop_set_ptr(DEVICE(mcu), "machine", machine);

        /* Set the board specific oscillator frequencies. */
        object_property_set_int(mcu, 12000000, "hse-freq-hz", NULL); /* 12.0 MHz */
        object_property_set_int(mcu, 32768, "lse-freq-hz", NULL); /* 32 kHz */

        cm_object_realize(mcu);
    }

    {
        /* Create the board LED */
        Object *led = cm_object_new(TYPE_GPIO_LED);

        /* STM32-P107 Green LED1, PC13, active low */
        object_property_set_bool(led, true, "active-low", NULL);
        object_property_set_str(led, "[Green LED On]\n", "on-message", NULL);
        object_property_set_str(led, "[Green LED Off]\n", "off-message", NULL);

        gpio_led_connect(led, "/machine/stm32/gpio[c]", 13);

        cm_object_realize(led);
    }
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
