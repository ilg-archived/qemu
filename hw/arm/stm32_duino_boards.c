/*
 * STM32 Arduino-like boards emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#include "hw/arm/stm32.h"
#include "qemu/module.h"
#include "sysemu/sysemu.h"

/*
 * This file defines several Arduino-like STM32 boards.
 */

/* ----- Netduino 2 ----- */
static void
netduino2_board_init(MachineState *machine);

static QEMUMachine netduino2_machine =
{ .name = "Netduino2", .desc =
		"Netduino Development Board with STM32F2 (Experimental)", .init =
		netduino2_board_init, };

static void netduino2_board_init(MachineState *machine)
{
	cortexm_board_greeting(machine, &netduino2_machine);
	stm32f205rf_mcu_init(machine);
	/* TODO: Add board inits */
}

/* ----- Netduino Plus 2 ----- */
static void
netduinoplus2_board_init(MachineState *machine);

static QEMUMachine netduinoplus2_machine =
{ .name = "NetduinoPlus2", .desc =
		"Netduino Development Board with STM32F4 (Experimental)", .init =
		netduinoplus2_board_init, };

static void netduinoplus2_board_init(MachineState *machine)
{
	cortexm_board_greeting(machine, &netduinoplus2_machine);
	stm32f405rg_mcu_init(machine);
	/* TODO: Add board inits */
}

/* ----- Netduino Go ----- */
static void
netduinogo_board_init(MachineState *machine);

static QEMUMachine netduinogo_machine =
{ .name = "NetduinoGo", .desc =
		"Netduino GoBus Development Board with STM32F4 (Experimental)", .init =
		netduinogo_board_init, };

static void netduinogo_board_init(MachineState *machine)
{
	cortexm_board_greeting(machine, &netduinogo_machine);
	stm32f405rg_mcu_init(machine);
	/* TODO: Add board inits */
}

/* ----- Mapple ----- */
static void
mapple_board_init(MachineState *machine);

static QEMUMachine mapple_machine =
{ .name = "Mapple", .desc =
		"LeafLab Arduino-style STM32 microcontroller board (Experimental)",
		.init = mapple_board_init, };

static void mapple_board_init(MachineState *machine)
{
	cortexm_board_greeting(machine, &mapple_machine);
	stm32f103rb_mcu_init(machine);
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
