/*
 * NXP LPC boards emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#include "hw/arm/lpc.h"
#include "qemu/module.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/*
 * This file defines several LPC boards.
 * Where available, the board names follow the CMSIS Packs names.
 */

/* Common inits for all LPC boards */
void lpc_board_init(MachineState *machine, QEMUMachine *qm)
{
#if defined(CONFIG_VERBOSE)
    if (verbosity_level > VERBOSITY_COMMON) {
        printf("Board: '%s' (%s).\n", qm->name, qm->desc);
    }
#endif
}

/* ----- LPCXpresso-LPC1769 ----- */
static void lpcxpresso_lpc1769_board_init(MachineState *machine);

static QEMUMachine lpcxpresso_lpc1769_machine = {
    .name = "LPCXpresso-LPC1769",
    .desc = "Embedded Artists LPCXpresso LPC1769 Development Board "
            "(Experimental)",
    .init = lpcxpresso_lpc1769_board_init,
};

static void lpcxpresso_lpc1769_board_init(MachineState *machine)
{
    lpc_board_init(machine, &lpcxpresso_lpc1769_machine);
    lpc1769fbd100_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- Boards inits ----- */
static void lpc_machine_init(void)
{
    qemu_register_machine(&lpcxpresso_lpc1769_machine);
}

machine_init(lpc_machine_init);

