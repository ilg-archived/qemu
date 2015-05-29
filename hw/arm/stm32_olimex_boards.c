/*
 * STM32 Olimex boards emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#include "hw/arm/stm32.h"
#include "qemu/module.h"
#include "sysemu/sysemu.h"

/*
 * This file defines several Olimex STM32 boards.
 */

/* ----- Olimex STM32-H103 ----- */
static void
stm32_h103_board_init (MachineState *machine);

static QEMUMachine stm32_h103_machine =
  { //
    .name = "STM32-H103", //
	.desc = "Olimex Header Board for STM32F103RBT6 (Experimental)", //
	.init = stm32_h103_board_init, //
    };

static void
stm32_h103_board_init (MachineState *machine)
{
  stm32_board_init (machine, &stm32_h103_machine);
  stm32_mcu_init (machine, TYPE_STM32F103RB);

  /* TODO: Add board inits */
}

/* ----- Olimex STM32-P103 ----- */
static void
stm32_p103_board_init (MachineState *machine);

static QEMUMachine stm32_p103_machine =
  { .name = "STM32-P103", .desc =
      "Olimex Prototype Board for STM32F103RBT6 (Experimental)", .init =
      stm32_p103_board_init, };

static void
stm32_p103_board_init (MachineState *machine)
{
  stm32_board_init (machine, &stm32_p103_machine);
  stm32f103rb_mcu_init (machine);
  /* TODO: Add board inits */
}

/* ----- Olimex OLIMEXINO-STM32 ----- */
static void
olimexino_stm32_board_init (MachineState *machine);

static QEMUMachine olimexino_stm32_machine =
  { .name = "OLIMEXINO-STM32", .desc =
      "Olimex Mapple (Arduino-like) Development Board (Experimental)", .init =
      olimexino_stm32_board_init, };

static void
olimexino_stm32_board_init (MachineState *machine)
{
  stm32_board_init (machine, &olimexino_stm32_machine);
  stm32f103rb_mcu_init (machine);
  /* TODO: Add board inits */
}

/* ----- Olimex STM32-P107 ----- */
static void
stm32_p107_board_init (MachineState *machine);

static QEMUMachine stm32_p107_machine =
  { .name = "STM32-P107", .desc =
      "Olimex Prototype Board for STM32F107VCT6 (Experimental)", .init =
      stm32_p107_board_init, };

static void
stm32_p107_board_init (MachineState *machine)
{
  stm32_board_init (machine, &stm32_p107_machine);
  stm32f107vc_mcu_init (machine);
  /* TODO: Add board inits */
}

/* ----- Olimex STM32-P407 ----- */
static void
stm32_e407_board_init (MachineState *machine);

static QEMUMachine stm32_e407_machine =
  { .name = "STM32-E407", .desc =
      "Olimex Development Board for STM32F407ZGT6 (Experimental)", .init =
      stm32_e407_board_init, };

static void
stm32_e407_board_init (MachineState *machine)
{
  stm32_board_init (machine, &stm32_e407_machine);
  stm32f407zg_mcu_init (machine);
  /* TODO: Add board inits */
}

/* ----- Boards inits ----- */
static void
stm32_olimex_machines_init (void)
{
  qemu_register_machine (&stm32_e407_machine);
  qemu_register_machine (&stm32_p107_machine);
  qemu_register_machine (&stm32_p103_machine);
  qemu_register_machine (&stm32_h103_machine);
  qemu_register_machine (&olimexino_stm32_machine);
}

machine_init(stm32_olimex_machines_init);
