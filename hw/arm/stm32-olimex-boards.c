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
#include "hw/arm/stm32-mcu.h"
#include "qemu/module.h"
#include "sysemu/sysemu.h"
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
        DeviceState *mcu = cm_create(TYPE_STM32F103RB);

        qdev_prop_set_ptr(mcu, "machine", machine);

        /* Set the board specific oscillator frequencies. */
        qdev_prop_set_uint32(mcu, "hse-freq-hz", 8000000); /* 8.0 MHz */
        qdev_prop_set_uint32(mcu, "lse-freq-hz", 32768); /* 32 kHz */

        cm_realize(mcu);
    }

    {
        /* Create the board LED */
        DeviceState *led = cm_create(TYPE_GPIO_LED);

        /* STM32-H103 Green LED, GPIOC[12], active low */
        qdev_prop_set_bit(led, "active-low", true);
        qdev_prop_set_string(led, "on-message", "[Green LED On]\n");
        qdev_prop_set_string(led, "off-message", "[Green LED Off]\n");

        gpio_led_connect(led, "/machine/stm32/gpio[c]", 12);

        cm_realize(led);
    }
}

static QEMUMachine stm32_h103_machine = {
    .name = "STM32-H103",
    .desc = "Olimex Header Board for STM32F103RBT6",
    .init = stm32_h103_board_init_callback };

/* ----- Olimex STM32-P103 ----- */
static void
stm32_p103_board_init_callback(MachineState *machine);

static QEMUMachine stm32_p103_machine = {
    .name = "STM32-P103",
    .desc = "Olimex Prototype Board for STM32F103RBT6 (Experimental)",
    .init = stm32_p103_board_init_callback };

static void stm32_p103_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);
//cortexm_mcu_alloc(machine, TYPE_STM32F103RB);

    /* TODO: Add board inits */
}

/* ----- Olimex OLIMEXINO-STM32 ----- */
static void
olimexino_stm32_board_init_callback(MachineState *machine);

static QEMUMachine olimexino_stm32_machine = {
    .name = "OLIMEXINO-STM32",
    .desc = "Olimex Mapple (Arduino-like) Development Board (Experimental)",
    .init = olimexino_stm32_board_init_callback };

static void olimexino_stm32_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);
//cortexm_mcu_alloc(machine, TYPE_STM32F103RB);

    /* TODO: Add board inits */
}

/* ----- Olimex STM32-P107 ----- */
static void
stm32_p107_board_init_callback(MachineState *machine);

static QEMUMachine stm32_p107_machine = {
    .name = "STM32-P107",
    .desc = "Olimex Prototype Board for STM32F107VCT6 (Experimental)",
    .init = stm32_p107_board_init_callback };

static void stm32_p107_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);
//cortexm_mcu_alloc(machine, TYPE_STM32F107VC);

    /* TODO: Add board inits */
}

/* ----- Olimex STM32-P407 ----- */
static void
stm32_e407_board_init_callback(MachineState *machine);

static QEMUMachine stm32_e407_machine = {
    .name = "STM32-E407",
    .desc = "Olimex Development Board for STM32F407ZGT6 (Experimental)",
    .init = stm32_e407_board_init_callback };

static void stm32_e407_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);
//cortexm_mcu_alloc(machine, TYPE_STM32F407ZG);

    /* TODO: Add board inits */
}

/* ----- Boards inits ----- */
static void stm32_olimex_machines_init(void)
{
    qemu_register_machine(&stm32_e407_machine);
    qemu_register_machine(&stm32_p107_machine);
    qemu_register_machine(&stm32_p103_machine);
    qemu_register_machine(&stm32_h103_machine);
    qemu_register_machine(&olimexino_stm32_machine);
}

#if defined(CONFIG_GNU_ARM_ECLIPSE)
machine_init(stm32_olimex_machines_init);
#endif
