/*
 * Cortex-M MCU emulation.
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

#include <hw/cortexm/cortexm-board.h>
#include "qemu/error-report.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/* ----- Public ------------------------------------------------------------ */

const char *cortexm_board_get_name(CortexMBoardState *board)
{
    return object_class_get_name(OBJECT_CLASS(board));
}

const char *cortexm_board_get_desc(CortexMBoardState *board)
{
    return MACHINE_GET_CLASS(board)->desc;
}

/**
 * When verbose, display a line to identify the board (name, description).
 */
void cortexm_board_greeting(CortexMBoardState *board)
{
#if defined(CONFIG_VERBOSE)
    if (verbosity_level >= VERBOSITY_COMMON) {
        MachineClass *mc = MACHINE_GET_CLASS(board);
        printf("Board: '%s' (%s).\n", mc->name, mc->desc);
    }
#endif
}

void cortexm_board_init_graphic_image(CortexMBoardState *board,
        const char *file_name)
{
#if defined(CONFIG_SDL)

    const char *caption = cortexm_board_get_desc(board);
    MachineState *machine = MACHINE(board);

    cortexm_graphic_board_init_graphic_context(&(board->graphic_context),
            machine->enable_graphics ? file_name : NULL, caption);

    cortexm_graphic_init_timer();

#endif /* defined(CONFIG_SDL) */
}

/* ===== Private class implementation ====================================== */

static void cortexm_board_class_init_callback(ObjectClass *klass, void *data)
{
    qemu_log_function_name();
}

static const TypeInfo cortexm_board_type_init = {
    .abstract = true,
    .name = TYPE_CORTEXM_BOARD,
    .parent = TYPE_CORTEXM_BOARD_PARENT,
    .instance_size = sizeof(CortexMBoardState),
    .class_init = cortexm_board_class_init_callback,
    .class_size = sizeof(CortexMBoardClass) };

/* ===== Private class implementation ====================================== */

static void cortexm_generic_board_init_callback(MachineState *machine)
{
    CortexMBoardState *board = CORTEXM_BOARD_STATE(machine);

    cortexm_board_greeting(board);

    {
        /* Create the MCU */
        Object *mcu = cm_object_new_mcu(machine, NULL);

        cm_object_realize(mcu);
    }
}

static void cortexm_generic_board_class_init_callback(ObjectClass *oc,
        void *data)
{
    MachineClass *mc = MACHINE_CLASS(oc);

    mc->desc = "Generic Cortex-M board; use -mcu to define the device";
    mc->init = cortexm_generic_board_init_callback;
}

static const TypeInfo cortexm_generic_board_type_init = {
    .name = BOARD_TYPE_NAME("generic"),
    .parent = TYPE_CORTEXM_BOARD,
    .class_init = cortexm_generic_board_class_init_callback, };

/* -------------------------------------------------------------------------- */

static void cortexm_board_types_init(void)
{
    type_register_static(&cortexm_board_type_init);
    type_register_static(&cortexm_generic_board_type_init);
}

type_init(cortexm_board_types_init);

/* -------------------------------------------------------------------------- */
