/*
 * GPIO connected LED device emulation.
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

#ifndef GPIO_LED_H_
#define GPIO_LED_H_

#include "qemu/osdep.h"

#include "hw/qdev.h"
#include "qemu/typedefs.h"
#include "hw/sysbus.h"

#include <hw/cortexm/graphic.h>

// ----------------------------------------------------------------------------

#define IRQ_GPIO_LED_IN     "led-in"

// ----------------------------------------------------------------------------

#define DEFINE_PROP_GPIO_LED_PTR(_n, _s, _f) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_ptr, GPIOLEDInfo*)

// ----------------------------------------------------------------------------

typedef struct {

    const char *name; /* NULL for table end. */

    bool active_low;
    const char *colour_name;
    const char *on_message;
    const char *off_message;

    /* Centre of the LED. */
    uint32_t x;
    uint32_t y;
    /* Size of the rectangle to lit. */
    uint32_t w;
    uint32_t h;

    struct {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    } colour;

    const char *gpio_path;
    const char *irq_name;
    int gpio_bit;

} GPIOLEDInfo;

// ----------------------------------------------------------------------------

#define TYPE_GPIO_LED "gpio-led"

// Parent definitions.
// TODO: Change this to TYPE_DEVICE
#define TYPE_GPIO_LED_PARENT TYPE_SYS_BUS_DEVICE
typedef SysBusDeviceClass GPIOLEDParentClass;
typedef SysBusDevice GPIOLEDParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define GPIO_LED_GET_CLASS(obj) \
    OBJECT_GET_CLASS(GPIOLEDClass, (obj), TYPE_GPIO_LED)
#define GPIO_LED_CLASS(klass) \
    OBJECT_CLASS_CHECK(GPIOLEDClass, (klass), TYPE_GPIO_LED)

typedef struct {
    // private:
    GPIOLEDParentClass parent_class;
    // public:

} GPIOLEDClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define GPIO_LED_STATE(obj) \
    OBJECT_CHECK(GPIOLEDState, (obj), TYPE_GPIO_LED)

/*
 * The LED has a single incoming interrupt; connect the source,
 * usually a GPIO outgoing interrupt, to it.
 *
 * Properties:
 * - active-low (bool)
 * - on-message (string)
 * - off-message (string)
 * - x,y,w,h (int)
 * - colour.red, colour.green, colour.blue (int)
 */
typedef struct {
    // private:
    GPIOLEDParentState parent_obj;
    // public:

    bool active_low;
    const char *on_message;
    const char *off_message;

#if defined(CONFIG_SDL)
    struct {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    } colour;
    LEDGraphicContext led_graphic_context;
    BoardGraphicContext *board_graphic_context;
#endif /* defined(CONFIG_SDL) */

} GPIOLEDState;

Object **gpio_led_create_from_info(Object *parent, GPIOLEDInfo *info_array,
        BoardGraphicContext *graphic_context);

// ----------------------------------------------------------------------------

#endif /* GPIO_LED_H_ */
