/*
 * Cortex-M Graphic support.
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

#include <hw/cortexm/cortexm-graphic.h>
#include "qemu/osdep.h"
#include "qemu/timer.h"
#include "qemu/error-report.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/* ------------------------------------------------------------------------- */

#if defined(CONFIG_SDL)
static QEMUTimer *timer;

/**
 * SDL event loop, called every 10 ms by the timer.
 */
static void sdl_event_loop(void *p)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        //If the user has Xed out the window
        if (event.type == SDL_QUIT) {
            //Quit the program
            fprintf(stderr, "Quit.\n");
            exit(1);
        }
    }

    timer_mod(timer, qemu_clock_get_ms(QEMU_CLOCK_REALTIME) + 10);
}
#endif /* defined(CONFIG_SDL) */

void cortexm_graphic_init_timer(void)
{
#if defined(CONFIG_SDL)
    /* The event loop will be processed from time to time. */
    timer = timer_new_ms(QEMU_CLOCK_REALTIME, sdl_event_loop, &timer);
    timer_mod(timer, qemu_clock_get_ms(QEMU_CLOCK_REALTIME));
#endif /* defined(CONFIG_SDL) */
}

void cortexm_graphic_board_init_graphic_context(
        BoardGraphicContext *board_graphic_context, const char *file_name,
        const char *caption)
{
#if defined(CONFIG_SDL)

#if defined(CONFIG_SDLABI_2_0)
    board_graphic_context->renderer = NULL;
    board_graphic_context->texture = NULL;
    board_graphic_context->surface = NULL;
#elif defined(CONFIG_SDLABI_1_2)
    board_graphic_context->surface = NULL;
#endif

    if (file_name) {
        // Start SDL, if needed.
        if (SDL_WasInit(SDL_INIT_VIDEO) == 0) {
            SDL_Init(SDL_INIT_VIDEO);
        }

        const char *fullname = qemu_find_file(QEMU_FILE_TYPE_IMAGES, file_name);
        if (fullname == NULL) {
            error_printf("Image file '%s' not found.\n", file_name);
            exit(1);
        }

        int res = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
        if ((res & (IMG_INIT_JPG | IMG_INIT_PNG))
                != (IMG_INIT_JPG | IMG_INIT_PNG)) {
            error_printf("IMG_init failed (%s).\n", IMG_GetError());
            exit(1);
        }
        /* A better SDL_LoadBMP(). */
        SDL_Surface* board_bitmap = IMG_Load(fullname);
        if (board_bitmap == NULL) {
            error_printf("Cannot load image file '%s' (%s).\n", fullname,
                    IMG_GetError());
            exit(1);
        }

#if defined(CONFIG_VERBOSE)
        if (verbosity_level >= VERBOSITY_DETAILED) {
            printf("Board picture: '%s'.\n", fullname);
        }
#endif

#if defined(CONFIG_SDLABI_2_0)

        SDL_Window* win = SDL_CreateWindow(caption, SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED, board_bitmap->w, board_bitmap->h,
                SDL_WINDOW_MOUSE_CAPTURE);
        SDL_Renderer* renderer = SDL_CreateRenderer(win, -1,
                SDL_RENDERER_ACCELERATED);

        SDL_Surface* board_bitmap_rgb = SDL_ConvertSurfaceFormat(board_bitmap,
                SDL_PIXELFORMAT_RGB888, 0);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,
                board_bitmap_rgb);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);

        board_graphic_context->renderer = renderer;
        board_graphic_context->surface = board_bitmap_rgb;
        board_graphic_context->texture = texture;
        board_graphic_context->window = win;

#elif defined(CONFIG_SDLABI_1_2)

        SDL_WM_SetCaption(caption, NULL);
        SDL_Surface* screen = SDL_SetVideoMode(board_bitmap->w, board_bitmap->h,
                32, SDL_DOUBLEBUF);
        SDL_Surface* board_surface = SDL_DisplayFormat(board_bitmap);

        /* Apply image to screen */
        SDL_BlitSurface(board_surface, NULL, screen, NULL);
        /* Update screen */
        SDL_Flip(screen);

        board_graphic_context->surface = screen;

#endif

        SDL_FreeSurface(board_bitmap);
    }
#endif /* defined(CONFIG_SDL) */
}

void cortexm_graphic_led_init_context(
        BoardGraphicContext *board_graphic_context,
        LEDGraphicContext *led_graphic_context, uint8_t red, uint8_t green,
        uint8_t blue)
{
#if defined(CONFIG_SDL)

    SDL_Surface *surface = board_graphic_context->surface;
    SDL_Rect *rectangle = &(led_graphic_context->rectangle);

#if defined(CONFIG_SDLABI_2_0)

    led_graphic_context->crop_off = SDL_ConvertSurfaceFormat(surface,
            SDL_PIXELFORMAT_RGB888, 0);

    led_graphic_context->crop_on = SDL_ConvertSurfaceFormat(surface,
            SDL_PIXELFORMAT_RGB888, 0);

#elif defined(CONFIG_SDLABI_1_2)

    led_graphic_context->crop_off = SDL_CreateRGBSurface(surface->flags,
            rectangle->w, rectangle->h, surface->format->BitsPerPixel,
            surface->format->Rmask, surface->format->Gmask,
            surface->format->Bmask, surface->format->Amask);

    led_graphic_context->crop_on = SDL_CreateRGBSurface(surface->flags,
            rectangle->w, rectangle->h, surface->format->BitsPerPixel,
            surface->format->Rmask, surface->format->Gmask,
            surface->format->Bmask, surface->format->Amask);

#endif

    /* Copy bitmap from original picture. */
    SDL_BlitSurface(board_graphic_context->surface, rectangle,
            led_graphic_context->crop_off, 0);

    Uint32 colour = SDL_MapRGB(led_graphic_context->crop_on->format, red, green,
            blue);

    /* Fill with uniform colour. */
    SDL_FillRect(led_graphic_context->crop_on, NULL, colour);

#endif /* defined(CONFIG_SDL) */
}

void cortexm_graphic_led_turn(BoardGraphicContext *board_graphic_context,
        LEDGraphicContext *led_graphic_context, bool is_on)
{
#if defined(CONFIG_SDL)

    SDL_Surface *crop =
            is_on ?
                    led_graphic_context->crop_on :
                    led_graphic_context->crop_off;

#if defined(CONFIG_SDLABI_2_0)
    SDL_UpdateTexture(board_graphic_context->texture,
            &(led_graphic_context->rectangle), crop->pixels, crop->pitch);
    SDL_RenderCopy(board_graphic_context->renderer,
            board_graphic_context->texture, NULL, NULL);
    SDL_RenderPresent(board_graphic_context->renderer);
#elif defined(CONFIG_SDLABI_1_2)
    SDL_BlitSurface(crop, NULL, board_graphic_context->surface,
            &(led_graphic_context->rectangle));
    SDL_Flip(board_graphic_context->surface);
#endif

#endif /* defined(CONFIG_SDL) */
}

/* ------------------------------------------------------------------------- */

