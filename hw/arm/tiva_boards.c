/*
 * TI Tiva boards emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#include "hw/arm/tiva.h"
#include "qemu/module.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/*
 * This file defines several TI boards.
 * Where available, the board names follow the CMSIS Packs names.
 */

/* Common inits for all LPC boards */
void tiva_board_init(MachineState *machine, QEMUMachine *qm)
{
#if defined(CONFIG_VERBOSE)
    if (verbosity_level >= VERBOSITY_COMMON) {
        printf("Board: '%s' (%s).\n", qm->name, qm->desc);
    }
#endif
}

/* ----- EK-TM4C123GXL ----- */
static void ek_tm4c123gxl_board_init(MachineState *machine);

static QEMUMachine ek_tm4c123gxl_machine = {
    .name = "EK-TM4C123GXL",
    .desc = "TI Tiva C Series TM4C123GXL LaunchPad Evaluation Kit "
    "(Experimental)",
    .init = ek_tm4c123gxl_board_init,
};

static void ek_tm4c123gxl_board_init(MachineState *machine)
{
    tiva_board_init(machine, &ek_tm4c123gxl_machine);
    tm4c123gh6pm_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- Boards inits ----- */
static void lpc_machine_init(void)
{
    qemu_register_machine(&ek_tm4c123gxl_machine);
}

machine_init(lpc_machine_init);

