/*
 * Reset graphic button.
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

#ifndef CORTEXM_BUTTON_RESET_H_
#define CORTEXM_BUTTON_RESET_H_

#include "qemu/osdep.h"

#include <hw/cortexm/button.h>
#include <hw/cortexm/graphic.h>

// ----------------------------------------------------------------------------

typedef struct {

    // Centre coordinates of the button.
    uint32_t x;
    uint32_t y;
    // Size of the rectangle where the button is active.
    uint32_t w;
    uint32_t h;

} ButtonResetInfo;

// ----------------------------------------------------------------------------

#define TYPE_BUTTON_RESET "button-reset"

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_BUTTON_RESET_PARENT TYPE_BUTTON
typedef ButtonClass ButtonResetParentClass;
typedef ButtonState ButtonResetParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define BUTTON_RESET_GET_CLASS(obj) \
    OBJECT_GET_CLASS(ButtonResetClass, (obj), TYPE_BUTTON_RESET)
#define BUTTON_RESET_CLASS(klass) \
    OBJECT_CLASS_CHECK(ButtonResetClass, (klass), TYPE_BUTTON_RESET)

typedef struct ButtonResetClass {
    // private:
    ButtonResetParentClass parent_class;
    // public:

} ButtonResetClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define BUTTON_RESET_STATE(obj) \
    OBJECT_CHECK(ButtonResetState, (obj), TYPE_BUTTON_RESET)

typedef struct ButtonResetState {
    // private:
    ButtonResetParentState parent_obj;
    // public:

} ButtonResetState;

// ----------------------------------------------------------------------------

void button_reset_create_from_info(Object *parent, ButtonResetInfo *info,
        BoardGraphicContext *graphic_context);

// ----------------------------------------------------------------------------

#endif /* CORTEXM_BUTTON_RESET_H_ */
