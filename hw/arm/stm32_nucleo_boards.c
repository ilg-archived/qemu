/*
 * STM32 Nucleo boards emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#include "hw/arm/stm32.h"
#include "qemu/module.h"
#include "sysemu/sysemu.h"

/*
 * This file defines several STM32 Nucleo boards.
 */

/* ----- ST NUCLEO-F411RE ----- */
static void nucleo_f411re_board_init(MachineState *machine);

static QEMUMachine nucleo_f411re_machine =
{ .name = "NUCLEO-F411RE", .desc =
		"ST Nucleo Development Board for STM32 F4 series (Experimental)",
		.init = nucleo_f411re_board_init, };

static void nucleo_f411re_board_init(MachineState *machine)
{
	cortexm_board_greeting(machine, &nucleo_f411re_machine);
	stm32f411re_mcu_init(machine);
	/* TODO: Add board inits */
}

/* ----- ST NUCLEO-F334R8 ----- */
static void nucleo_f334r8_board_init(MachineState *machine);

static QEMUMachine nucleo_f334r8_machine =
{ .name = "NUCLEO-F334R8", .desc =
		"ST Nucleo Development Board for STM32 F3 series (Experimental)",
		.init = nucleo_f334r8_board_init, };

static void nucleo_f334r8_board_init(MachineState *machine)
{
	cortexm_board_greeting(machine, &nucleo_f334r8_machine);
	stm32f334r8_mcu_init(machine);
	/* TODO: Add board inits */
}

/* ----- ST NUCLEO-F103RB ----- */
static void nucleo_f103rb_board_init(MachineState *machine);

static QEMUMachine nucleo_f103rb_machine =
{ .name = "NUCLEO-F103RB", .desc =
		"ST Nucleo Development Board for STM32 F1 series (Experimental)",
		.init = nucleo_f103rb_board_init, };

static void nucleo_f103rb_board_init(MachineState *machine)
{
	cortexm_board_greeting(machine, &nucleo_f103rb_machine);
	stm32f103rb_mcu_init(machine);
	/* TODO: Add board inits */
}

/* ----- ST NUCLEO-L152RE ----- */
static void nucleo_l152re_board_init(MachineState *machine);

static QEMUMachine nucleo_l152re_machine =
{ .name = "NUCLEO-L152RE", .desc =
		"ST Nucleo Development Board with STM32L152RET6 (Experimental)", .init =
		nucleo_l152re_board_init, };

static void nucleo_l152re_board_init(MachineState *machine)
{
	cortexm_board_greeting(machine, &nucleo_l152re_machine);
	stm32l152re_mcu_init(machine);
	/* TODO: Add board inits */
}

/* ----- Boards inits ----- */
static void stm32_machines_init(void)
{
	qemu_register_machine(&nucleo_f411re_machine);
	qemu_register_machine(&nucleo_f334r8_machine);
	qemu_register_machine(&nucleo_f103rb_machine);
	qemu_register_machine(&nucleo_l152re_machine);
}

machine_init(stm32_machines_init);
