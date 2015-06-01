/*
 * Atmel SAM boards emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#include "hw/arm/sam.h"
#include "qemu/module.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/*
 * This file defines several SAM boards.
 * Where available, the board names follow the CMSIS Packs names.
 */

/* Common inits for all SAM boards */
void sam_board_init(MachineState *machine, QEMUMachine *qm)
{
#if defined(CONFIG_VERBOSE)
    if (verbosity_level > VERBOSITY_COMMON) {
        printf("Board: '%s' (%s).\n", qm->name, qm->desc);
    }
#endif
}

/* ----- SAM3-H256 ----- */
static void sam3_h256_board_init(MachineState *machine);

static QEMUMachine sam3_h256_machine = {
    .name = "SAM3-H256",
    .desc = "Olimex Header Board for ATSAM3S4BA "
    "(Experimental)",
    .init = sam3_h256_board_init,
};

static void sam3_h256_board_init(MachineState *machine)
{
    sam_board_init(machine, &sam3_h256_machine);
    sam3s4b_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- Boards inits ----- */
static void sam_machine_init(void)
{
    qemu_register_machine(&sam3_h256_machine);
}

machine_init(sam_machine_init);

