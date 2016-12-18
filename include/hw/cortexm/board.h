/*
 * Cortex-M Board (machine) emulation.
 * 
 * Copyright (c) 2016 Liviu Ionescu.
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

#ifndef CORTEXM_BOARD_H_
#define CORTEXM_BOARD_H_

#include "qemu/osdep.h"

#include <hw/cortexm/graphic.h>
#include <hw/cortexm/helper.h>
#include "hw/boards.h"

// ----------------------------------------------------------------------------

#define TYPE_CORTEXM_BOARD TYPE_CORTEXM_PREFIX "machine"

#define BOARD_TYPE_NAME(board_name) (board_name TYPE_MACHINE_SUFFIX)

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_CORTEXM_BOARD_PARENT TYPE_MACHINE
typedef MachineClass CortexMBoardParentClass;
typedef MachineState CortexMBoardParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define CORTEXM_BOARD_GET_CLASS(obj) \
    OBJECT_GET_CLASS(CortexMBoardClass, (obj), TYPE_CORTEXM_BOARD)
#define CORTEXM_BOARD_CLASS(klass) \
    OBJECT_CLASS_CHECK(CortexMBoardClass, (klass), TYPE_CORTEXM_BOARD)

typedef struct {
    // private:
    CortexMBoardParentClass parent_class;
    // public:

} CortexMBoardClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define CORTEXM_BOARD_STATE(obj) \
    OBJECT_CHECK(CortexMBoardState, (obj), TYPE_CORTEXM_BOARD)

typedef struct {
    // private:
    CortexMBoardParentState parent_obj;
    // public:

    BoardGraphicContext graphic_context;

} CortexMBoardState;

// ----------------------------------------------------------------------------

bool cortexm_board_is_initialized(void);

void cortexm_board_clear(void);

CortexMBoardState *cortexm_board_get(void);

const char *cortexm_board_get_name(CortexMBoardState *board);

const char *cortexm_board_get_desc(CortexMBoardState *board);

void cortexm_board_greeting(CortexMBoardState *board);

BoardGraphicContext * cortexm_board_init_graphic_image(CortexMBoardState *board,
        const char *file_name);

// ----------------------------------------------------------------------------

#endif /* CORTEXM_BOARD_H_ */
