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

#if 0
typedef const struct {
    
} stm32_board_info;
#endif

/* Common inits for all boards */
static void stm32_board_init(MachineState *machine, QEMUMachine *qm)
{
#if defined(CONFIG_VERBOSE)
    if (verbosity_level > 0) {
        printf("Board: '%s' (%s).\n", qm->name, qm->desc);
    }
#endif
}

/* TODO: add NUCLEO boards */

/* ----- ST STM32F4-Discovery ----- */
static void stm32f4_discovery_init(MachineState *machine);

static QEMUMachine stm32f4_discovery_machine = {
    .name = "STM32F4-Discovery",
    .desc = "Discovery kit for STM32F407/417 line",
    .init = stm32f4_discovery_init,
};

static void stm32f4_discovery_init(MachineState *machine)
{
    stm32_board_init(machine, &stm32f4_discovery_machine);
    /* qemu_irq *irqs = */ stm32f407vg_init(machine);
    /* TODO: Add board inits */
}

/* ----- Olimex STM32-H103 ----- */
static void stm32_h103_init(MachineState *machine);

static QEMUMachine stm32_h103_machine = {
    .name = "STM32-H103",
    .desc = "Olimex STM32-H103 Dev Board",
    .init = stm32_h103_init,
};

static void stm32_h103_init(MachineState *machine)
{
    stm32_board_init(machine, &stm32_h103_machine);
    stm32f103rb_init(machine);
    /* TODO: Add board inits */
}

/* ----- Olimex STM32-P103 ----- */
static void stm32_p103_init(MachineState *machine);

static QEMUMachine stm32_p103_machine = {
    .name = "STM32-P103",
    .desc = "Olimex STM32-P103 Dev Board",
    .init = stm32_p103_init,
};

static void stm32_p103_init(MachineState *machine)
{
    stm32_board_init(machine, &stm32_p103_machine);
    stm32f103rb_init(machine);
    /* TODO: Add board inits */
}

/* ----- Olimex STM32-P107 ----- */
static void stm32_p107_init(MachineState *machine);

static QEMUMachine stm32_p107_machine = {
    .name = "STM32-P107",
    .desc = "Olimex STM32-P107 Dev Board",
    .init = stm32_p107_init,
};

static void stm32_p107_init(MachineState *machine)
{
    stm32_board_init(machine, &stm32_p107_machine);
    stm32f107vc_init(machine);
    /* TODO: Add board inits */
}

/* ----- Olimex STM32-P407 ----- */
static void stm32_p407_init(MachineState *machine);

static QEMUMachine stm32_p407_machine = {
    .name = "STM32-P407",
    .desc = "Olimex STM32-P407 Dev Board",
    .init = stm32_p407_init,
};

static void stm32_p407_init(MachineState *machine)
{
    stm32_board_init(machine, &stm32_p407_machine);
    stm32f407zg_init(machine);
    /* TODO: Add board inits */
}

/* ----- Boards inits ----- */
static void stm32_machine_init(void)
{
    qemu_register_machine(&stm32_h103_machine);
    qemu_register_machine(&stm32_p103_machine);
    qemu_register_machine(&stm32_p107_machine);
    qemu_register_machine(&stm32_p407_machine);
    qemu_register_machine(&stm32f4_discovery_machine);
}

machine_init(stm32_machine_init);
