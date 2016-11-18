/*
 * NXP LPC boards emulation.
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

#include "hw/arm/lpc.h"
#include "qemu/module.h"
#include <hw/cortexm/helper.h>

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/*
 * This file defines several LPC boards.
 * Where available, the board names follow the CMSIS Packs names.
 */

/* ----- LPCXpresso-LPC1769 ----- */
static void lpcxpresso_lpc1769_board_init(MachineState *machine);

static QEMUMachine lpcxpresso_lpc1769_machine = {
    .name = "LPCXpresso-LPC1769",
    .desc = "Embedded Artists LPCXpresso LPC1769 Development Board "
            "(Experimental)",
    .init = lpcxpresso_lpc1769_board_init };

static void lpcxpresso_lpc1769_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    lpc1769fbd100_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- Boards inits ----- */
static void lpc_machine_init(void)
{
    qemu_register_machine(&lpcxpresso_lpc1769_machine);
}

machine_init( lpc_machine_init);

