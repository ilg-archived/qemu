/*
 * Abstract graphic button.
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

#ifndef CORTEXM_BUTTON_H_
#define CORTEXM_BUTTON_H_

#include "qemu/osdep.h"

#include "hw/sysbus.h"

// ----------------------------------------------------------------------------

#define TYPE_BUTTON "button"

// Parent definitions.
#define TYPE_BUTTON_PARENT TYPE_SYS_BUS_DEVICE
typedef SysBusDeviceClass ButtonParentClass;
typedef SysBusDevice ButtonParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define BUTTON_GET_CLASS(obj) \
    OBJECT_GET_CLASS(ButtonClass, (obj), TYPE_BUTTON)
#define BUTTON_CLASS(klass) \
    OBJECT_CLASS_CHECK(ButtonClass, (klass), TYPE_BUTTON)

typedef struct ButtonState ButtonState;

typedef struct ButtonClass {
    // private:
    ButtonParentClass parent_class;
    // public:

    // Action when the button is pushed down.
    void (*down)(ButtonState *dev);
    // Action when the button is released.
    void (*up)(ButtonState *dev);

} ButtonClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define BUTTON_STATE(obj) \
    OBJECT_CHECK(ButtonState, (obj), TYPE_BUTTON)

typedef struct ButtonState {
    // private:
    ButtonParentState parent_obj;
    // public:

    unsigned int value;

#if defined(CONFIG_SDL)

    struct rectangle_s {
        int x_left;
        int x_right;
        int y_top;
        int y_bottom;
    } position;

#endif /* defined(CONFIG_SDL) */

} ButtonState;

// ----------------------------------------------------------------------------

#endif /* CORTEXM_BUTTON_H_ */
