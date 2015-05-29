/*
 * STM32 boards emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#include "hw/arm/stm32.h"
#include "qemu/module.h"
#include "sysemu/sysemu.h"
#include "qom/object.h"

/*
 * This file defines several STM32 boards.
 * Where available, the board names follow the CMSIS Packs names.
 */

/* Common inits for all STM32 boards */
void stm32_board_init(MachineState *machine, QEMUMachine *qm)
{
#if defined(CONFIG_VERBOSE)
	if (verbosity_level > 0) {
		printf("Board: '%s' (%s).\n", qm->name, qm->desc);
	}
#endif
}

/* ----- ST STM32F4-Discovery ----- */
static void
stm32f4_discovery_board_init(MachineState *machine);

static QEMUMachine stm32f4_discovery_machine =
{ .name = "STM32F4-Discovery", .desc =
		"ST Discovery kit for STM32F407/417 lines (Experimental)", .init =
		stm32f4_discovery_board_init, };

static void stm32f4_discovery_board_init(MachineState *machine)
{
	stm32_board_init(machine, &stm32f4_discovery_machine);
	stm32f407vg_mcu_init(machine);
	/* TODO: Add board inits */
}

/* ----- ST STM32F429I-Discovery ----- */
static void
stm32f429i_discovery_board_init(MachineState *machine);

static QEMUMachine stm32f429i_discovery_machine =
{ .name = "STM32F429I-Discovery", .desc =
		"ST Discovery kit for STM32F429/439 lines (Experimental)", .init =
		stm32f429i_discovery_board_init, };

static void stm32f429i_discovery_board_init(MachineState *machine)
{
	stm32_board_init(machine, &stm32f429i_discovery_machine);
	stm32f429zi_mcu_init(machine);
	/* TODO: Add board inits */
}

/* ----- ST STM32F3-Discovery ----- */
static void
stm32f3_discovery_board_init(MachineState *machine);

static QEMUMachine stm32f3_discovery_machine =
{ .name = "STM32F3-Discovery", .desc =
		"ST Discovery kit for STM32F303 line (Experimental)", .init =
		stm32f3_discovery_board_init, };

static void stm32f3_discovery_board_init(MachineState *machine)
{
	stm32_board_init(machine, &stm32f3_discovery_machine);
	stm32f303vc_mcu_init(machine);
	/* TODO: Add board inits */
}

/* ----- ST STM32F0-Discovery ----- */
static void
stm32f0_discovery_board_init(MachineState *machine);

static QEMUMachine stm32f0_discovery_machine =
{ .name = "STM32F0-Discovery", .desc =
		"ST Discovery kit for STM32F051 line (Experimental)", .init =
		stm32f0_discovery_board_init, };

static void stm32f0_discovery_board_init(MachineState *machine)
{
	stm32_board_init(machine, &stm32f0_discovery_machine);
	stm32f051r8_mcu_init(machine);
	/* TODO: Add board inits */
}

/* ----- ST STM32VL-Discovery ----- */
static void
stm32vl_discovery_init(MachineState *machine);

static QEMUMachine stm32vl_discovery_machine =
{ .name = "STM32VL-Discovery", .desc =
		"ST Discovery kit for STM32F100 Value Line (Experimental)", .init =
		stm32vl_discovery_init, };

static void stm32vl_discovery_init(MachineState *machine)
{
	stm32_board_init(machine, &stm32vl_discovery_machine);
	stm32f100rb_mcu_init(machine);
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
