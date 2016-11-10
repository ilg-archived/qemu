/*
 * Atmel SAM boards emulation.
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

#include <hw/cortexm/sam.h>
#include "qemu/module.h"
#include <hw/cortexm/helper.h>

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/*
 * This file defines several SAM boards.
 * Where available, the board names follow the CMSIS Packs names.
 */

/* ----- SAM3-H256 ----- */
static void sam3_h256_board_init(MachineState *machine);

static QEMUMachine sam3_h256_machine = {
    .name = "SAM3-H256",
    .desc = "Olimex Header Board for ATSAM3S4BA "
            "(Experimental)",
    .init = sam3_h256_board_init };

static void sam3_h256_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    sam3s4b_mcu_init(machine);

    /* TODO: Add board inits */
}

/* ----- Boards inits ----- */
static void sam_machine_init(void)
{
    qemu_register_machine(&sam3_h256_machine);
}

machine_init( sam_machine_init);

