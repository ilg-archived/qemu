/*
 * TI Tiva boards emulation.
 *
 * Copyright (c) 2014 Liviu Ionescu.
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

#include "qemu/osdep.h"

#include <hw/cortexm/tiva.h>
#include "qemu/module.h"
#include <hw/cortexm/helper.h>

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/*
 * This file defines several TI boards.
 * Where available, the board names follow the CMSIS Packs names.
 */

/* ----- EK-TM4C123GXL ----- */
static void ek_tm4c123gxl_board_init(MachineState *machine);

static QEMUMachine ek_tm4c123gxl_machine = {
    .name = "EK-TM4C123GXL",
    .desc = "TI Tiva C Series TM4C123GXL LaunchPad Evaluation Kit "
            "(Experimental)",
    .init = ek_tm4c123gxl_board_init };

static void ek_tm4c123gxl_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    tm4c123gh6pm_mcu_init(machine);

    /* TODO: Add board inits */
}

/* ----- Boards inits ----- */
static void lpc_machine_init(void)
{
    qemu_register_machine(&ek_tm4c123gxl_machine);
}

machine_init( lpc_machine_init);

