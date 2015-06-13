/*
 * STM32 Arduino-like boards emulation.
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
#include "qemu/module.h"
#include "sysemu/sysemu.h"

/*
 * This file defines several Arduino-like STM32 boards.
 */

/* ----- Netduino 2 ----- */
static void
netduino2_board_init_callback(MachineState *machine);

static QEMUMachine netduino2_machine = {
    .name = "Netduino2",
    .desc = "Netduino Development Board with STM32F2 (Experimental)",
    .init = netduino2_board_init_callback };

static void netduino2_board_init_callback(MachineState *machine)
{
    cortexm_board_greeting(machine);
    cortexm_mcu_create(machine, TYPE_STM32F205RF);

    /* TODO: Add board inits */
}

/* ----- Netduino Plus 2 ----- */
static void
netduinoplus2_board_init_callback(MachineState *machine);

static QEMUMachine netduinoplus2_machine = {
    .name = "NetduinoPlus2",
    .desc = "Netduino Development Board with STM32F4 (Experimental)",
    .init = netduinoplus2_board_init_callback };

static void netduinoplus2_board_init_callback(MachineState *machine)
{
    cortexm_board_greeting(machine);
    cortexm_mcu_create(machine, TYPE_STM32F405RG);

    /* TODO: Add board inits */
}

/* ----- Netduino Go ----- */
static void
netduinogo_board_init_callback(MachineState *machine);

static QEMUMachine netduinogo_machine = {
    .name = "NetduinoGo",
    .desc = "Netduino GoBus Development Board with STM32F4 (Experimental)",
    .init = netduinogo_board_init_callback };

static void netduinogo_board_init_callback(MachineState *machine)
{
    cortexm_board_greeting(machine);
    cortexm_mcu_create(machine, TYPE_STM32F405RG);

    /* TODO: Add board inits */
}

/* ----- Mapple ----- */
static void
mapple_board_init_callback(MachineState *machine);

static QEMUMachine mapple_machine = {
    .name = "Mapple",
    .desc = "LeafLab Arduino-style STM32 microcontroller board (Experimental)",
    .init = mapple_board_init_callback };

static void mapple_board_init_callback(MachineState *machine)
{
    cortexm_board_greeting(machine);
    cortexm_mcu_create(machine, TYPE_STM32F103RB);

    /* TODO: Add board inits */
}

/* ----- Boards inits ----- */
static void stm32_duino_machines_init(void)
{
    qemu_register_machine(&netduino2_machine);
    qemu_register_machine(&netduinoplus2_machine);
    qemu_register_machine(&netduinogo_machine);
    qemu_register_machine(&mapple_machine);
}

machine_init(stm32_duino_machines_init);
