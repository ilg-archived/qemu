/*
 * Cortex-M graphics definitions.
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

#ifndef CORTEXM_GRAPHIC_H_
#define CORTEXM_GRAPHIC_H_

#include "qemu/osdep.h"

#if defined(CONFIG_SDL)
#if defined(CONFIG_SDLABI_2_0)
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#elif defined(CONFIG_SDLABI_1_2)
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#endif
#endif /* defined(CONFIG_SDL) */

// ----------------------------------------------------------------------------

// Use polling on the QEMU I/O thread instead of a separate thread.
#define USE_GRAPHIC_POLL_EVENT
// On windows always use polling.
#if !defined(USE_GRAPHIC_POLL_EVENT) && defined(WIN32)
#define USE_GRAPHIC_POLL_EVENT
#endif

// ----------------------------------------------------------------------------

typedef struct ButtonState ButtonState;

// Storage for board graphic context, stored in CortexMBoardState
typedef struct BoardGraphicContext {

    const char *picture_file_name;
    const char *picture_file_absolute_path;
    const char *window_caption;

    // Array of pointers to button states.
    ButtonState **buttons;
    size_t buttons_array_capacity;
    size_t buttons_array_length;

#if defined(CONFIG_SDL)
#if defined(CONFIG_SDLABI_2_0)
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Surface *surface;
#elif defined(CONFIG_SDLABI_1_2)
    SDL_Surface *surface;
#endif
#endif /* defined(CONFIG_SDL) */

} BoardGraphicContext;

// ----------------------------------------------------------------------------

typedef struct {

    const char *name; // NULL for table end.

    bool active_low;

    // Centre coordinates of the button.
    uint32_t x;
    uint32_t y;
    // Size of the rectangle where the button is active.
    uint32_t w;
    uint32_t h;

    const char *gpio_path;
    int port_bit;

} GraphicButtonInfo;

// ----------------------------------------------------------------------------

// Storage for LED graphic context, stored in GPIOLEDState
typedef struct {
    SDL_Rect rectangle;
    SDL_Surface *crop_off;
    SDL_Surface *crop_on;
} LEDGraphicContext;

// ----------------------------------------------------------------------------

enum {
    GRAPHIC_EVENT_NONE = 0,
    GRAPHIC_EVENT_QUIT,
    GRAPHIC_EVENT_EXIT,
    GRAPHIC_EVENT_BOARD_INIT,
    GRAPHIC_EVENT_LED_INIT,
    GRAPHIC_EVENT_LED_TURN,
};

// ----------------------------------------------------------------------------

void cortexm_graphic_start(bool nographic);

#if defined(USE_GRAPHIC_POLL_EVENT)
void cortexm_graphic_init_timer(void);
#endif

void cortexm_graphic_quit(void);

int cortexm_graphic_enqueue_event(int code, void *data1, void *data2);

void cortexm_graphic_event_loop(void);

//void cortexm_graphic_init_timer(void);

// ----- Board graphic functions -----
void cortexm_graphic_board_clear_graphic_context(
        BoardGraphicContext *board_graphic_context);

bool cortexm_graphic_board_is_graphic_context_initialised(
        BoardGraphicContext *board_graphic_context);

void cortexm_graphic_board_add_button(
        BoardGraphicContext *board_graphic_context, ButtonState *button_state);

// ----- LED graphic function -----
void cortexm_graphic_led_clear_graphic_context(
        LEDGraphicContext *led_graphic_context);

bool cortexm_graphic_led_is_graphic_context_initialised(
        LEDGraphicContext *led_graphic_context);

// ----------------------------------------------------------------------------

#endif /* CORTEXM_GRAPHIC_H_ */

