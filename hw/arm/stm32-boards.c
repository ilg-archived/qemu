/*
 * STM32 boards emulation.
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

#include "hw/arm/stm32.h"
#include "qemu/module.h"
#include "sysemu/sysemu.h"
#include "qom/object.h"

/*
 * This file defines several STM32 boards.
 * Where available, the board names follow the CMSIS Packs names.
 */

/* ----- ST STM32F4-Discovery ----- */
static void
stm32f4_discovery_board_init_callback(MachineState *machine);

static QEMUMachine stm32f4_discovery_machine = {
    .name = "STM32F4-Discovery",
    .desc = "ST Discovery kit for STM32F407/417 lines (Experimental)",
    .init = stm32f4_discovery_board_init_callback };

static void stm32f4_discovery_board_init_callback(MachineState *machine)
{
    cortexm_board_greeting(machine);
    cortexm_mcu_init(machine, TYPE_STM32F407VG);

    /* TODO: Add board inits */
}

/* ----- ST STM32F429I-Discovery ----- */
static void
stm32f429i_discovery_board_init_callback(MachineState *machine);

static QEMUMachine stm32f429i_discovery_machine = {
    .name = "STM32F429I-Discovery",
    .desc = "ST Discovery kit for STM32F429/439 lines (Experimental)",
    .init = stm32f429i_discovery_board_init_callback };

static void stm32f429i_discovery_board_init_callback(MachineState *machine)
{
    cortexm_board_greeting(machine);
    cortexm_mcu_init(machine, TYPE_STM32F429ZI);

    /* TODO: Add board inits */
}

/* ----- ST STM32F3-Discovery ----- */
static void
stm32f3_discovery_board_init_callback(MachineState *machine);

static QEMUMachine stm32f3_discovery_machine = {
    .name = "STM32F3-Discovery",
    .desc = "ST Discovery kit for STM32F303 line (Experimental)",
    .init = stm32f3_discovery_board_init_callback };

static void stm32f3_discovery_board_init_callback(MachineState *machine)
{
    cortexm_board_greeting(machine);
    cortexm_mcu_init(machine, TYPE_STM32F303VC);

    /* TODO: Add board inits */
}

/* ----- ST STM32F0-Discovery ----- */
static void
stm32f0_discovery_board_init_callback(MachineState *machine);

static QEMUMachine stm32f0_discovery_machine = {
    .name = "STM32F0-Discovery",
    .desc = "ST Discovery kit for STM32F051 line (Experimental)",
    .init = stm32f0_discovery_board_init_callback };

static void stm32f0_discovery_board_init_callback(MachineState *machine)
{
    cortexm_board_greeting(machine);
    cortexm_mcu_init(machine, TYPE_STM32F051R8);

    /* TODO: Add board inits */
}

/* ----- ST STM32VL-Discovery ----- */
static void
stm32vl_discovery_init_callback(MachineState *machine);

static QEMUMachine stm32vl_discovery_machine = {
    .name = "STM32VL-Discovery",
    .desc = "ST Discovery kit for STM32F100 Value Line (Experimental)",
    .init = stm32vl_discovery_init_callback };

static void stm32vl_discovery_init_callback(MachineState *machine)
{
    cortexm_board_greeting(machine);
    cortexm_mcu_init(machine, TYPE_STM32F100RB);

    /* TODO: Add board inits */
}

/* ----- Boards inits ----- */
static void stm32_machines_init(void)
{
    qemu_register_machine(&stm32f429i_discovery_machine);
    qemu_register_machine(&stm32f4_discovery_machine);
    qemu_register_machine(&stm32f3_discovery_machine);
    qemu_register_machine(&stm32f0_discovery_machine);
    qemu_register_machine(&stm32vl_discovery_machine);
}

machine_init(stm32_machines_init);
