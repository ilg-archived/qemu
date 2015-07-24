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

#include "hw/qdev.h"
#include "qemu/typedefs.h"
#include "hw/sysbus.h"

#if defined(CONFIG_SDL)
#include "SDL/SDL.h"
#endif

/* ------------------------------------------------------------------------- */

#define DEFINE_PROP_GPIO_LED_PTR(_n, _s, _f) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_ptr, GPIOLEDInfo*)

/* ------------------------------------------------------------------------- */

typedef struct {

    const char *name; /* NULL for table end. */

    bool active_low;
    const char *colour_message;
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
    int port_bit;

} GPIOLEDInfo;

/* ------------------------------------------------------------------------- */

#define TYPE_GPIO_LED "gpio-led"

// TODO: Change this to TYPE_DEVICE
#define TYPE_GPIO_LED_PARENT TYPE_SYS_BUS_DEVICE
typedef SysBusDeviceClass GPIOLEDParentClass;
typedef SysBusDevice GPIOLEDParentState;

#define GPIO_LED_GET_CLASS(obj) \
    OBJECT_GET_CLASS(GPIOLEDClass, (obj), TYPE_GPIO_LED)
#define GPIO_LED_CLASS(klass) \
    OBJECT_CLASS_CHECK(GPIOLEDClass, (klass), TYPE_GPIO_LED)

/* ------------------------------------------------------------------------- */

typedef struct {
    /*< private >*/
    GPIOLEDParentClass parent_class;
    /*< public >*/

} GPIOLEDClass;

/* ------------------------------------------------------------------------- */

#define GPIO_LED_STATE(obj) \
    OBJECT_CHECK(GPIOLEDState, (obj), TYPE_GPIO_LED)

typedef struct {
    /*< private >*/
    GPIOLEDParentState parent_obj;
    /*< public >*/

    bool active_low;
    const char *on_message;
    const char *off_message;

#if defined(CONFIG_SDL)
    SDL_Rect rectangle;
    struct {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    } colour;
    SDL_Surface *crop_off;
    SDL_Surface *crop_on;
    SDL_Surface *board_surface;
#endif

    /**
     * The actual irq used to blink the LED. It works connected to
     * a GPIO device outgoing irq.
     */
    qemu_irq irq;

} GPIOLEDState;

Object **gpio_led_create_from_info(Object *parent, GPIOLEDInfo *info_array,
        void* board_surface);
void gpio_led_connect(Object *obj, const char *port_name, int port_bit);

/* ------------------------------------------------------------------------- */

#endif /* GPIO_LED_H_ */
