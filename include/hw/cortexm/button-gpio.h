/*
 * GPIO connected graphic button.
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

#ifndef CORTEXM_BUTTON_GPIO_H_
#define CORTEXM_BUTTON_GPIO_H_

#include "qemu/osdep.h"

#include <hw/cortexm/button.h>
#include <hw/cortexm/graphic.h>

// ----------------------------------------------------------------------------

#define IRQ_BUTTON_GPIO_OUT     "button-out"

// ----------------------------------------------------------------------------

typedef struct {

    const char *name; // NULL for table end.

    // Centre coordinates of the button.
    uint32_t x;
    uint32_t y;
    // Size of the rectangle where the button is active.
    uint32_t w;
    uint32_t h;

    bool active_low;

    const char *gpio_path;
    const char *irq_name;
    int gpio_bit;

} ButtonGPIOInfo;

// ----------------------------------------------------------------------------

#define TYPE_BUTTON_GPIO "button-gpio"

// Parent definitions.
#define TYPE_BUTTON_GPIO_PARENT TYPE_BUTTON
typedef ButtonClass ButtonGPIOParentClass;
typedef ButtonState ButtonGPIOParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define BUTTON_GPIO_GET_CLASS(obj) \
    OBJECT_GET_CLASS(ButtonGPIOClass, (obj), TYPE_BUTTON_GPIO)
#define BUTTON_GPIO_CLASS(klass) \
    OBJECT_CLASS_CHECK(ButtonGPIOClass, (klass), TYPE_BUTTON_GPIO)

typedef struct ButtonGPIOClass {
    // private:
    ButtonGPIOParentClass parent_class;
    // public:

} ButtonGPIOClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define BUTTON_GPIO_STATE(obj) \
    OBJECT_CHECK(ButtonGPIOState, (obj), TYPE_BUTTON_GPIO)

typedef struct ButtonGPIOState {
    // private:
    ButtonGPIOParentState parent_obj;
    // public:

    bool active_low;
    qemu_irq irq_out;

} ButtonGPIOState;

// ----------------------------------------------------------------------------

void button_gpio_create_from_info(Object *parent, ButtonGPIOInfo *info_array,
        BoardGraphicContext *graphic_context);

// ----------------------------------------------------------------------------

#endif /* CORTEXM_BUTTON_GPIO_H_ */
