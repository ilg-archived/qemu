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

#include <hw/cortexm/board.h>

#include "qemu/error-report.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

// ----- Public ---------------------------------------------------------------

static Object *board;

bool cortexm_board_is_initialized(void)
{
    return (board != NULL);
}

void cortexm_board_clear(void)
{
    board = NULL;
}

// Return a pointer to the current board.
CortexMBoardState *cortexm_board_get(void)
{
    if (board == NULL) {
        board = container_get(object_get_root(), "/machine");
    }

    if (board == NULL) {
        return NULL;
    }

    return CORTEXM_BOARD_STATE(board);
}

// Return the board name.
const char *cortexm_board_get_name(CortexMBoardState *board)
{
    return object_class_get_name(OBJECT_CLASS(board));
}

// Return the board description.
const char *cortexm_board_get_desc(CortexMBoardState *board)
{
    return MACHINE_GET_CLASS(board)->desc;
}

// When verbose, display a line to identify the board (name, description).
void cortexm_board_greeting(CortexMBoardState *board)
{
#if defined(CONFIG_VERBOSE)
    if (verbosity_level >= VERBOSITY_COMMON) {
        MachineClass *mc = MACHINE_GET_CLASS(board);
        printf("Board: '%s' (%s).\n", mc->name, mc->desc);
    }
#endif
}

BoardGraphicContext *cortexm_board_init_graphic_image(CortexMBoardState *board,
        const char *file_name)
{
#if defined(CONFIG_SDL)

    const char *caption = cortexm_board_get_desc(board);
    MachineState *machine = MACHINE(board);

    // Always clear, even if graphic mode is not enabled.
    cortexm_graphic_board_clear_graphic_context(&(board->graphic_context));

    if (!machine->enable_graphics || file_name == NULL) {
        return NULL;
    }

    board->graphic_context.picture_file_name = file_name;
    board->graphic_context.window_caption = caption;

    const char *fullname = qemu_find_file(QEMU_FILE_TYPE_GRAPHICS, file_name);
    if (fullname == NULL) {
        error_printf("Picture file '%s' not found.\n", file_name);
        exit(1);
    }

    board->graphic_context.picture_file_absolute_path = fullname;

#if defined(CONFIG_VERBOSE)
    if (verbosity_level >= VERBOSITY_DETAILED) {
        printf("Board picture: '%s'.\n", fullname);
    }
#endif

#if defined(USE_GRAPHIC_POLL_EVENT)
    // The timer must be active before the first push.
    cortexm_graphic_init_timer();
#endif

    cortexm_graphic_enqueue_event(GRAPHIC_EVENT_BOARD_INIT,
            &(board->graphic_context),
            NULL);

    return &(board->graphic_context);

#else

    return NULL;

#endif /* defined(CONFIG_SDL) */
}

// ----- Private --------------------------------------------------------------

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

static void cortexm_generic_board_init_callback(MachineState *machine)
{
    CortexMBoardState *board = CORTEXM_BOARD_STATE(machine);

    cortexm_board_greeting(board);

    {
        // Create the MCU
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
    .class_init = cortexm_generic_board_class_init_callback,
/**/
};

// ----------------------------------------------------------------------------

static void cortexm_board_types_init(void)
{
    type_register_static(&cortexm_board_type_init);
    type_register_static(&cortexm_generic_board_type_init);
}

type_init(cortexm_board_types_init);

// ----------------------------------------------------------------------------
