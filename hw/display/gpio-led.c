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

#include "hw/display/gpio-led.h"
#include "hw/arm/cortexm-helper.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/**
 * This class implements a LED connected to a GPIO device.
 */

/* ----- Public ------------------------------------------------------------ */

/**
 * Create a number of LEDs, using details from an array of Info structures.
 */
Object **gpio_led_create_from_info(Object *parent, GPIOLEDInfo *info_array,
        void* board_surface)
{
    GPIOLEDInfo *info;

    int count = 0;
    for (info = info_array; info->name; info++) {
        count++;
    }

    Object **arr;
    arr = g_malloc0_n(count + 1, sizeof(Object*));

    Object **p = arr;

    for (info = info_array; info->name; info++) {
        /* Create the board LED1 */
        Object *led = cm_object_new(parent, info->name, TYPE_GPIO_LED);

        cm_object_property_set_bool(led, info->active_low, "active-low");
        const char *msg = NULL;
        size_t len;
        if (info->on_message) {
            msg = info->on_message;
        } else if (info->colour_message) {
            len = strlen(info->colour_message) + 16;
            msg = g_malloc(len);
            snprintf((char * )msg, len, "[%s LED On]\n", info->colour_message);
        }
        if (msg) {
            cm_object_property_set_str(led, msg, "on-message");
        } else {
            cm_object_property_set_str(led, "[Green LED On]\n", "on-message");
        }

        msg = NULL;
        if (info->off_message) {
            msg = info->off_message;
        } else if (info->colour_message) {
            len = strlen(info->colour_message) + 16;
            msg = g_malloc(len);
            snprintf((char * )msg, len, "[%s LED Off]\n", info->colour_message);
        }
        if (msg) {
            cm_object_property_set_str(led, msg, "off-message");
        } else {
            cm_object_property_set_str(led, "[Green LED Off]\n", "off-message");
        }

        if (info->gpio_path) {
            gpio_led_connect(led, info->gpio_path, info->port_bit);
        }

        if (info->w && info->h) {
            /* Compute corner coordinate from centre coordinate. */
            cm_object_property_set_int(led, info->x - (info->w / 2), "x");
            cm_object_property_set_int(led, info->y - (info->h / 2), "y");
            cm_object_property_set_int(led, info->w, "w");
            cm_object_property_set_int(led, info->h, "h");
        }

        if (info->colour.red == 0 && info->colour.green == 0
                && info->colour.blue == 0) {

            if (strcasecmp(info->colour_message, "red") == 0) {
                cm_object_property_set_int(led, 255, "colour.red");
            } else if (strcasecmp(info->colour_message, "green") == 0) {
                cm_object_property_set_int(led, 255, "colour.green");
            } else if (strcasecmp(info->colour_message, "blue") == 0) {
                cm_object_property_set_int(led, 255, "colour.blue");
                cm_object_property_set_int(led, 128, "colour.green");
            } else if (strcasecmp(info->colour_message, "yellow") == 0) {
                cm_object_property_set_int(led, 255, "colour.red");
                cm_object_property_set_int(led, 255, "colour.green");
            } else if (strcasecmp(info->colour_message, "orange") == 0) {
                cm_object_property_set_int(led, 255, "colour.red");
                cm_object_property_set_int(led, 153, "colour.green");
                cm_object_property_set_int(led, 51, "colour.blue");
            } else {
                /* White LED */
                cm_object_property_set_int(led, 255, "colour.red");
                cm_object_property_set_int(led, 255, "colour.green");
                cm_object_property_set_int(led, 255, "colour.blue");
            }

        }

        GPIO_LED_STATE(led)->board_surface = (SDL_Surface *) board_surface;

        cm_object_realize(led);

#if defined(CONFIG_VERBOSE)
        if (verbosity_level >= VERBOSITY_DETAILED) {
            printf("LED:");
            if (info->colour_message) {
                printf(" %s", info->colour_message);
            }
            printf(" active %s", info->active_low ? "low" : "high");
            if (info->w && info->h) {
                printf(" %d*%d @(%d,%d)", info->w, info->h, info->x, info->y);
            }
            if (info->gpio_path) {
                printf(" %s,%d", info->gpio_path, info->port_bit);
            }
            printf("\n");
        }
#endif /* defined(CONFIG_VERBOSE) */

        *p++ = led;
    }

    return arr;
}

/**
 * Connect this LED to the named GPIO port pin.
 * The port name is the full path to the GPIO port,
 * something like "/machine/stm32/gpio[c]"; the first
 * port bit has index 0.
 */
void gpio_led_connect(Object *obj, const char *port_name, int port_bit)
{
    GPIOLEDState *state = GPIO_LED_STATE(obj);

    /**
     * Connect the outgoing port pin irq (the GPIO port has outgoing
     * irq's for all bits) to this local incoming irq.
     */
    qdev_connect_gpio_out(DEVICE(object_resolve_path(port_name, NULL)),
            port_bit, state->irq);
}

/* ----- Private ----------------------------------------------------------- */

static void gpio_led_turn_on(GPIOLEDState *state)
{
    fprintf(stderr, "%s", state->on_message);

#if defined(CONFIG_SDL)
    if (state->board_surface) {
        SDL_BlitSurface(state->crop_on, NULL, state->board_surface,
                &state->rectangle);
        SDL_Flip(state->board_surface);
    }
#endif
}

static void gpio_led_turn_off(GPIOLEDState *state)
{
    fprintf(stderr, "%s", state->off_message);

#if defined(CONFIG_SDL)
    if (state->board_surface) {
        SDL_BlitSurface(state->crop_off, NULL, state->board_surface,
                &state->rectangle);
        SDL_Flip(state->board_surface);
    }
#endif
}

/**
 * Callback used to notify the LED status change.
 */
static void gpio_led_irq_handler(void *opaque, int n, int level)
{
    GPIOLEDState *state = GPIO_LED_STATE(opaque);

    /* There should be only one IRQ for the LED */
    assert(n == 0);

    /*
     * Assume that the IRQ is only triggered if the LED has changed state.
     * If this is not correct, we may get multiple LED Offs or Ons in a row.
     */
    switch (level) {
    case 0:

        if (state->active_low) {
            gpio_led_turn_on(state);
        } else {
            gpio_led_turn_off(state);
        }
        break;

    case 1:
        if (state->active_low) {
            gpio_led_turn_off(state);
        } else {
            gpio_led_turn_on(state);
        }
        break;
    }
}

static void gpio_led_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    GPIOLEDState *state = GPIO_LED_STATE(obj);

    cm_object_property_add_bool(obj, "active-low", &state->active_low);
    cm_object_property_add_const_str(obj, "on-message", &state->on_message);
    cm_object_property_add_const_str(obj, "off-message", &state->off_message);

    cm_object_property_set_str(obj, "[LED On]\n", "on-message");
    cm_object_property_set_str(obj, "[LED Off]\n", "off-message");

#if defined(CONFIG_SDL)
    cm_object_property_add_int16(obj, "x", &state->rectangle.x);
    cm_object_property_add_int16(obj, "y", &state->rectangle.y);
    cm_object_property_add_uint16(obj, "w", &state->rectangle.w);
    cm_object_property_add_uint16(obj, "h", &state->rectangle.h);

    cm_object_property_add_uint8(obj, "colour.red", &state->colour.red);
    cm_object_property_add_uint8(obj, "colour.green", &state->colour.green);
    cm_object_property_add_uint8(obj, "colour.blue", &state->colour.blue);
#endif

    /*
     * Allocate 1 single incoming irq, and fill it with
     * [handler, this device, n=0]. (n==0 is checked in the
     * handler by an assert).
     */
    state->irq = qemu_allocate_irq(gpio_led_irq_handler, obj, 0);
    // qdev_init_gpio_in(DEVICE(obj), gpio_led_irq_handler, 1);

    /*
     * The connection will be done by the machine.
     * A helper class is gpio_led_connect().
     */
}

static SDL_Surface* crop_surface(SDL_Surface* sprite_sheet, SDL_Rect *rectangle)
{
    SDL_Surface* surface = SDL_CreateRGBSurface(sprite_sheet->flags,
            rectangle->w, rectangle->h, sprite_sheet->format->BitsPerPixel,
            sprite_sheet->format->Rmask, sprite_sheet->format->Gmask,
            sprite_sheet->format->Bmask, sprite_sheet->format->Amask);
    SDL_BlitSurface(sprite_sheet, rectangle, surface, 0);
    return surface;
}

static void gpio_led_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    GPIOLEDState *state = GPIO_LED_STATE(dev);

    if (state->board_surface) {

        state->crop_off = crop_surface(state->board_surface, &state->rectangle);
        state->crop_on = crop_surface(state->board_surface, &state->rectangle);

        Uint32 colour = SDL_MapRGB(state->crop_off->format, state->colour.red,
                state->colour.green, state->colour.blue);
        SDL_FillRect(state->crop_on, NULL, colour);
    }
}

static void gpio_led_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->realize = gpio_led_realize_callback;
}

static const TypeInfo gpio_led_type_info = {
    .name = TYPE_GPIO_LED,
    .parent = TYPE_GPIO_LED_PARENT,
    .instance_size = sizeof(GPIOLEDState),
    .instance_init = gpio_led_instance_init_callback,
    .class_init = gpio_led_class_init_callback,
    .class_size = sizeof(GPIOLEDClass) };

static void gpio_led_type_init(void)
{
    type_register_static(&gpio_led_type_info);
}

type_init(gpio_led_type_init);

/* ------------------------------------------------------------------------- */
