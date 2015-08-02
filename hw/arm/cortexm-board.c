/*
 * Default Cortex-M board.
 *
 * Copyright (c) 2015 Liviu Ionescu.
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

#include "hw/arm/stm32-mcus.h"
#include "hw/arm/cortexm-helper.h"
#include "sysemu/sysemu.h"

static void cortexm_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);

    {
        /* Create the MCU */
        Object *mcu = cm_object_new_mcu(machine, NULL);

        cm_object_realize(mcu);
    }
}

static QEMUMachine machine_none = {
    .name = "generic",
    .desc = "Generic Cortex-M board; use -mcu to define the device",
    .init = cortexm_board_init_callback, };

static void cortexm_board_init(void)
{
    qemu_register_machine(&machine_none);
}

machine_init(cortexm_board_init);

