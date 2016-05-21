/*
 * Freescale Kinetis boards emulation.
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

#include "hw/cortexm/kinetis.h"
#include "qemu/module.h"
#include "hw/cortexm/cortexm-helper.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/*
 * This file defines several Kinetis boards.
 * Where available, the board names follow the CMSIS Packs names.
 */

/* ----- FRDM-K20D50M ----- */
static void frdm_k20d50m_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    mk20dx128vlh5_mcu_init(machine);
    /* TODO: Add board inits */
}

static void frdm_k20d50m_machine_init(MachineClass *mc) {
    mc->desc = "Freescale Freedom Development Platform for "
               "Kinetis K20 USB MCUs (Experimental)";
    mc->init = frdm_k20d50m_board_init;
}
DEFINE_MACHINE("FRDM-K20D50M", frdm_k20d50m_machine_init)

/* ----- FRDM-K22F ----- */
static void frdm_k22f_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    mk22fn512vlh12_mcu_init(machine);
    /* TODO: Add board inits */
}

static void frdm_k22f_machine_init(MachineClass *mc) {
    mc->desc = "Freescale Freedom Development Platform for "
               "Kinetis K22 MCUs (Experimental)";
    mc->init = frdm_k22f_board_init;
}

DEFINE_MACHINE("FRDM-K22F", frdm_k22f_machine_init)

/* ----- FRDM-K64F ----- */
static void frdm_k64f_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    mk64fn1m0vll12_mcu_init(machine);
    /* TODO: Add board inits */
}

static void frdm_k64f_machine_init(MachineClass *mc) {
    mc->desc = "Freescale Freedom Development Platform for "
               "Kinetis K6[34] and K24 MCUs (Experimental)";
    mc->init = frdm_k64f_board_init;
}

DEFINE_MACHINE("FRDM-K64F", frdm_k64f_machine_init)

/* ----- TWR-K60F120M ----- */
static void twr_k60f120m_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    mk64fn1m0vll12_mcu_init(machine);
    /* TODO: Add board inits */
}

static void twr_k60f120m_machine_init(MachineClass *mc) {
    mc->desc = "Freescale Kinetis K60 120 MHz Tower System Module (Experimental)";
    mc->init = twr_k60f120m_board_init;
}
DEFINE_MACHINE("TWR-K60F120M", twr_k60f120m_machine_init)

/* ----- FRDM-KL25Z ----- */
static void frdm_kl25z_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    mkl25z128vlk4_mcu_init(machine);
    /* TODO: Add board inits */
}

static void frdm_kl25z_machine_init(MachineClass *mc) {
    mc->desc = "Freescale Freedom Development Platform for "
               "Kinetis KL[12][45] MCUs (Experimental)";
    mc->init = frdm_kl25z_board_init;
}
DEFINE_MACHINE("FRDM-KL25Z", frdm_kl25z_machine_init)

/* ----- FRDM-KL26Z ----- */
static void frdm_kl26z_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    mkl26z128vlh4_mcu_init(machine);

    /* TODO: Add board inits */
}

static void frdm_kl26z_machine_init(MachineClass *mc) {
    mc->desc = "Freescale Freedom Development Platform for "
               "Kinetis KL[12]6 MCUs (Experimental)";
    mc->init = frdm_kl26z_board_init;
}
DEFINE_MACHINE("FRDM-KL26Z", frdm_kl26z_machine_init)

/* ----- FRDM-KL43Z ----- */
static void frdm_kl43z_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    mkl43z256vlh4_mcu_init(machine);

    /* TODO: Add board inits */
}

static void frdm_kl43z_machine_init(MachineClass *mc) {
    mc->desc = "Freescale Freedom Development Platform for "
               "Kinetis KL[34]3, KL[12]7 MCUs (Experimental)";
    mc->init = frdm_kl43z_board_init;
}
DEFINE_MACHINE("FRDM-KL43Z", frdm_kl43z_machine_init)

/* ----- FRDM-KL46Z ----- */
static void frdm_kl46z_board_init(MachineState *machine)
{
    cm_board_greeting(machine);
    mkl46z256vll4_mcu_init(machine);

    /* TODO: Add board inits */
}

static void frdm_kl46z_machine_init(MachineClass *mc) {
    mc->desc = "Freescale Freedom Development Platform for "
               "Kinetis KL[34]x MCUs (Experimental)";
    mc->init = frdm_kl46z_board_init;
}

DEFINE_MACHINE("FRDM-KL46Z", frdm_kl46z_machine_init)
