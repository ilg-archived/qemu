/*
 * Infineon XMC boards emulation.
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

#include <hw/cortexm/xmc.h>
#include "qemu/module.h"
#include <hw/cortexm/helper.h>

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/*
 * This file defines several Infineon boards.
 * Where available, the board names follow the CMSIS Packs names.
 */

/* ----- XMC4500 Enterprise Kit ----- */
static void xmc4500_enterprise_kit_board_init(MachineState *machine);

static QEMUMachine xmc4500_enterprise_kit_machine = {
    .name = "XMC4500 Enterprise Kit",
    .desc = "Infineon CPU Board XMC4500 General Purpose "
            "(Experimental)",
    .init = xmc4500_enterprise_kit_board_init };

static void xmc4500_enterprise_kit_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    xmc4500_f144k1024_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- XMC4400 Enterprise Kit ----- */
static void xmc4400_enterprise_kit_board_init(MachineState *machine);

static QEMUMachine xmc4400_enterprise_kit_machine = {
    .name = "XMC4400 Enterprise Kit",
    .desc = "Infineon CPU Board XMC4400 General Purpose "
            "(Experimental)",
    .init = xmc4400_enterprise_kit_board_init };

static void xmc4400_enterprise_kit_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    xmc4400_f100k512_mcu_init(machine);

    /* TODO: Add board inits */
}

/* ----- XMC4200 Enterprise Kit ----- */
static void xmc4200_enterprise_kit_board_init(MachineState *machine);

static QEMUMachine xmc4200_enterprise_kit_machine = {
    .name = "XMC4200 Enterprise Kit",
    .desc = "Infineon CPU Board XMC4200 Actuator "
            "(Experimental)",
    .init = xmc4200_enterprise_kit_board_init };

static void xmc4200_enterprise_kit_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    xmc4200_q48k256_mcu_init(machine);

    /* TODO: Add board inits */
}

/* ----- XMC4500 Relax Kit ----- */
static void xmc4500_relax_kit_board_init(MachineState *machine);

static QEMUMachine xmc4500_relax_kit_machine = {
    .name = "XMC4500 Relax Kit",
    .desc = "Infineon CPU Board XMC4500 Relax Kit "
            "(Experimental)",
    .init = xmc4500_relax_kit_board_init };

static void xmc4500_relax_kit_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    xmc4500_f100k1024_mcu_init(machine);

    /* TODO: Add board inits */
}

/* ----- XMC4500 Relax Lite Kit ----- */
static void xmc4500_relax_lite_kit_board_init(MachineState *machine);

static QEMUMachine xmc4500_relax_lite_kit_machine = {
    .name = "XMC4500 Relax Lite Kit",
    .desc = "Infineon CPU Board XMC4500 Relax Lite Kit "
            "(Experimental)",
    .init = xmc4500_relax_lite_kit_board_init, };

static void xmc4500_relax_lite_kit_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    xmc4500_f100f1024_mcu_init(machine);

    /* TODO: Add board inits */
}

/* ----- XMC1300 Boot Kit ----- */
static void xmc1300_boot_kit_board_init(MachineState *machine);

static QEMUMachine xmc1300_boot_kit_machine = {
    .name = "XMC1300 Boot Kit",
    .desc = "Infineon CPU Card XMC1300 Boot Kit Control Series "
            "(Experimental)",
    .init = xmc1300_boot_kit_board_init, };

static void xmc1300_boot_kit_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    xmc1302_t038x200_mcu_init(machine);

    /* TODO: Add board inits */
}

/* ----- XMC1200 Boot Kit ----- */
static void xmc1200_boot_kit_board_init(MachineState *machine);

static QEMUMachine xmc1200_boot_kit_machine = {
    .name = "XMC1200 Boot Kit",
    .desc = "Infineon CPU Card XMC1200 Boot Kit Feature Series "
            "(Experimental)",
    .init = xmc1200_boot_kit_board_init };

static void xmc1200_boot_kit_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    xmc1201_t038x200_mcu_init(machine);

    /* TODO: Add board inits */
}

/* ----- XMC1100 Boot Kit ----- */
static void xmc1100_boot_kit_board_init(MachineState *machine);

static QEMUMachine xmc1100_boot_kit_machine = {
    .name = "XMC1100 Boot Kit",
    .desc = "Infineon CPU Card XMC1100 Boot Kit Entry Series "
            "(Experimental)",
    .init = xmc1100_boot_kit_board_init };

static void xmc1100_boot_kit_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    xmc1100_t038x064_mcu_init(machine);

    /* TODO: Add board inits */
}

/* ----- XMC 2Go ----- */
static void xmc2go_board_init(MachineState *machine);

static QEMUMachine xmc2go_machine = {
    .name = "XMC 2Go",
    .desc = "Infineon XMC 2Go Kit with XMC1100 "
            "(Experimental)",
    .init = xmc2go_board_init };

static void xmc2go_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    xmc1100_q024f0064_mcu_init(machine);

    /* TODO: Add board inits */
}

/* ----- Boards inits ----- */
static void xmc_machine_init(void)
{
    qemu_register_machine(&xmc4500_enterprise_kit_machine);
    qemu_register_machine(&xmc4400_enterprise_kit_machine);
    qemu_register_machine(&xmc4200_enterprise_kit_machine);
    qemu_register_machine(&xmc4500_relax_kit_machine);
    qemu_register_machine(&xmc4500_relax_lite_kit_machine);
    qemu_register_machine(&xmc1300_boot_kit_machine);
    qemu_register_machine(&xmc1200_boot_kit_machine);
    qemu_register_machine(&xmc1100_boot_kit_machine);
    qemu_register_machine(&xmc2go_machine);
}

machine_init( xmc_machine_init);

