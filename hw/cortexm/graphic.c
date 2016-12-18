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

#include <hw/cortexm/graphic.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/board.h>

#include <hw/cortexm/gpio-led.h>
#include <hw/cortexm/button.h>

#include "qemu/timer.h"
#include "qemu/error-report.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

// ----------------------------------------------------------------------------

static void cortexm_graphic_board_init_graphic_context(
        BoardGraphicContext *board_graphic_context);

static void cortexm_graphic_led_init_graphic_context(
        BoardGraphicContext *board_graphic_context,
        LEDGraphicContext *led_graphic_context, uint8_t red, uint8_t green,
        uint8_t blue);

static void cortexm_graphic_led_turn(BoardGraphicContext *board_graphic_context,
        LEDGraphicContext *led_graphic_context, bool is_on);

static void cortexm_graphic_process_mouse_motion(void);

static void cortexm_graphic_process_mouse_button_down(void);

static void cortexm_graphic_process_mouse_button_up(void);

// ----------------------------------------------------------------------------

static bool is_not_nographic = false;
static bool is_terminated = false;
static SDL_Cursor *saved_cursor = NULL;
static SDL_Cursor *button_cursor = NULL;
static ButtonState *current_button = NULL;
static ButtonState *pushed_button = NULL;

// ----------------------------------------------------------------------------

typedef struct {
    int x;
    int y;
} MousePosition;

static BoardGraphicContext *board_graphic_context;

static void cortexm_graphic_process_event(SDL_Event* event)
{
    GPIOLEDState *state;
    bool is_on;
    int exit_code;

    switch (event->type) {

#if defined(CONFIG_SDLABI_2_0)

    case SDL_FIRSTEVENT:
        break;

    case SDL_WINDOWEVENT:
        // Window state change
        break;
#elif defined(CONFIG_SDLABI_1_2)

#endif

    case SDL_KEYDOWN:
    case SDL_KEYUP:
        // Nothing for now
        break;

    case SDL_MOUSEMOTION:
        if (board_graphic_context != NULL) {
            cortexm_graphic_process_mouse_motion();
        }
        break;

    case SDL_MOUSEBUTTONDOWN:
        if (board_graphic_context != NULL) {
            cortexm_graphic_process_mouse_button_down();
        }
        break;

    case SDL_MOUSEBUTTONUP:
        if (board_graphic_context != NULL) {
            cortexm_graphic_process_mouse_button_up();
        }
        break;

    case SDL_FINGERDOWN:
    case SDL_FINGERUP:
    case SDL_FINGERMOTION:
        // case SDL_DOLLARGESTURE:
        // case SDL_DOLLARRECORD:
        // case SDL_MULTIGESTURE:
        // Nothing for now
        break;

    case SDL_QUIT:
        // Quit the program
#if defined(CONFIG_VERBOSE)
        if (verbosity_level >= VERBOSITY_COMMON) {
            printf("Graphic window closed. Quit.\n");
        }
#endif /* defined(CONFIG_VERBOSE) */
        cortexm_graphic_quit();
        exit(1);

    case SDL_USEREVENT:

        // User events, enqueued with SDL_PushEvent().
        switch (event->user.code) {

        case GRAPHIC_EVENT_BOARD_INIT:
            board_graphic_context = (BoardGraphicContext *) event->user.data1;

            if (!cortexm_graphic_board_is_graphic_context_initialised(
                    board_graphic_context)) {
                cortexm_graphic_board_init_graphic_context(
                        board_graphic_context);
            }
            break;

        case GRAPHIC_EVENT_LED_INIT:
            state = (GPIOLEDState *) event->user.data1;

            if (!cortexm_graphic_led_is_graphic_context_initialised(
                    &(state->led_graphic_context))) {
                cortexm_graphic_led_init_graphic_context(
                        state->board_graphic_context,
                        &(state->led_graphic_context), state->colour.red,
                        state->colour.green, state->colour.blue);
            }
            break;

        case GRAPHIC_EVENT_LED_TURN:
            state = (GPIOLEDState *) event->user.data1;
            is_on = (bool) event->user.data2;

            cortexm_graphic_led_turn(state->board_graphic_context,
                    &(state->led_graphic_context), is_on);
            break;

        case GRAPHIC_EVENT_QUIT:
            cortexm_graphic_quit();
            break;

        case GRAPHIC_EVENT_EXIT:
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
            exit_code = (int) event->user.data1;
#pragma GCC diagnostic pop
            cortexm_graphic_quit();
            exit(exit_code);

        default:
            qemu_log_mask(LOG_UNIMP, "Unimplemented user event %d\n",
                    event->user.code);
        }
        break;

    default:
        qemu_log_mask(LOG_UNIMP, "Other event 0x%X\n", event->type);
        break;
    }
}

#if defined(USE_GRAPHIC_POLL_EVENT)
static QEMUTimer *event_loop_timer;
#endif /* defined(USE_GRAPHIC_POLL_EVENT) */

#if defined(USE_GRAPHIC_POLL_EVENT)
void cortexm_graphic_init_timer(void)
{
    if (is_not_nographic) {
        return;
    }

    // The event loop will be processed from time to time.
    event_loop_timer = timer_new_ms(QEMU_CLOCK_REALTIME,
            (void (*)(void *)) cortexm_graphic_event_loop, &event_loop_timer);
    timer_mod(event_loop_timer, qemu_clock_get_ms(QEMU_CLOCK_REALTIME));
}
#endif /* defined(USE_GRAPHIC_POLL_EVENT) */

void cortexm_graphic_event_loop(void)
{
#if !defined(USE_GRAPHIC_POLL_EVENT)
    qemu_log_function_name();
#endif

#if defined(CONFIG_SDL)

    SDL_Event event;

#if !defined(USE_GRAPHIC_POLL_EVENT)

#if defined(CONFIG_SDLABI_2_0)
    // Raise graphic responsiveness.
    SDL_SetThreadPriority(SDL_THREAD_PRIORITY_HIGH);
#endif

    while (SDL_WaitEvent(&event)) {
        cortexm_graphic_process_event(&event);
    }

#else

    while (SDL_PollEvent(&event)) {
        cortexm_graphic_process_event(&event);
    }

    timer_mod(event_loop_timer, qemu_clock_get_ms(QEMU_CLOCK_REALTIME) + 10);

#endif /* !defined(defined(USE_GRAPHIC_POLL_EVENT)) */

#endif /* defined(CONFIG_SDL) */
}

// Called from different threads to enqueue jobs via the event loop.
// This ensures all graphic primitives are executed on the allowed thread.
int cortexm_graphic_enqueue_event(int code, void *data1, void *data2)
{
    qemu_log_mask(LOG_FUNC, "%s(%d)\n", __FUNCTION__, code);

#if defined(CONFIG_SDL)

    SDL_Event event;

    event.type = SDL_USEREVENT;
    event.user.code = code;
    event.user.data1 = data1;
    event.user.data2 = data2;

    // TODO: if multi-thread access is needed, add a mutex.
    int ret = SDL_PushEvent(&event);

#if defined(CONFIG_SDLABI_2_0)
    // Used to give the scheduler a chance to yield.
    SDL_Delay(1);
#endif

    return ret;

#else

    return 0;

#endif /* defined(CONFIG_SDL) */
}

// ----------------------------------------------------------------------------

static inline bool cortexm_graphic_mouse_is_in_button(MousePosition *mp,
        ButtonState *button_state)
{
    if ((mp->x >= button_state->position.x_left)
            && (mp->x <= button_state->position.x_right)
            && (mp->y >= button_state->position.y_top)
            && (mp->y <= button_state->position.y_bottom)) {
        return true;
    } else {
        return false;
    }
}

static void cortexm_graphic_process_mouse_motion(void)
{
    MousePosition mp;
    int i;

    SDL_GetMouseState(&mp.x, &mp.y);

    if (current_button == NULL) {
        // Previously not in a button, enumerate all, maybe one matches.
        for (i = 0; i < board_graphic_context->buttons_array_length; ++i) {
            if (cortexm_graphic_mouse_is_in_button(&mp,
                    board_graphic_context->buttons[i])) {
                // Mouse entered the button.
                current_button = board_graphic_context->buttons[i];

                saved_cursor = SDL_GetCursor();
                SDL_SetCursor(button_cursor);

                break;
            }
        }
    } else {
        // Previously in a button, check if still in.
        if (!cortexm_graphic_mouse_is_in_button(&mp, current_button)) {
            // Mouse exited the button.
            current_button = NULL;

            SDL_SetCursor(saved_cursor);
            saved_cursor = NULL;
        }
    }
}

static void cortexm_graphic_process_mouse_button_down(void)
{
#if 1
    MousePosition mp;
    SDL_GetMouseState(&mp.x, &mp.y);
    qemu_log_mask(LOG_FUNC, "%s() %d,%d\n", __FUNCTION__, mp.x, mp.y);
#endif

    if (current_button != NULL) {

        ButtonClass *klass = BUTTON_GET_CLASS(current_button);

        // Perform the down() action associated with the current button.
        klass->down(current_button);
        pushed_button = current_button;
    }
}

static void cortexm_graphic_process_mouse_button_up(void)
{
    if (pushed_button != NULL) {

        ButtonClass *klass = BUTTON_GET_CLASS(pushed_button);

        // Perform the up() action associated with the previously pushed button.
        klass->up(pushed_button);
        pushed_button = NULL;
    }
}

// ----------------------------------------------------------------------------

// Called indirectly via the event loop, to clean the board graphic context.
void cortexm_graphic_quit(void)
{
    qemu_log_function_name();

    if (is_not_nographic || is_terminated) {
        return;
    }

#if defined(CONFIG_SDL)

    if (cortexm_board_is_initialized()) {
        CortexMBoardState *board = cortexm_board_get();
        if (board != NULL) {
            BoardGraphicContext *board_graphic_context =
                    &(board->graphic_context);

            if (cortexm_graphic_board_is_graphic_context_initialised(
                    board_graphic_context)) {

#if defined(CONFIG_SDLABI_2_0)

                // Destroy in reverse order of creation
                if (board_graphic_context->texture != NULL) {
                    qemu_log_mask(LOG_FUNC, "%s() SDL_DestroyTexture()\n",
                            __FUNCTION__);
                    SDL_DestroyTexture(board_graphic_context->texture);
                }

                if (board_graphic_context->renderer != NULL) {
                    qemu_log_mask(LOG_FUNC, "%s() SDL_DestroyRenderer()\n",
                            __FUNCTION__);
                    SDL_DestroyRenderer(board_graphic_context->renderer);
                }

                if (board_graphic_context->window != NULL) {
                    qemu_log_mask(LOG_FUNC, "%s() SDL_DestroyWindow()\n",
                            __FUNCTION__);
                    SDL_DestroyWindow(board_graphic_context->window);
                }

#elif defined(CONFIG_SDLABI_1_2)

#endif /* defined(CONFIG_SDLABI_) */

            }
        }
        // Prevent subsequent destroys.
        cortexm_board_clear();
    }

    qemu_log_mask(LOG_FUNC, "%s() SDL_Quit()\n", __FUNCTION__);
    SDL_Quit();

    is_terminated = true;

#endif /* defined(CONFIG_SDL) */
}

// ----------------------------------------------------------------------------

static QemuThread start_thread;

// Called via the atexit() mechanism, to clean the board graphic context.
static void cortexm_graphic_atexit(void)
{
    if (qemu_thread_is_self(&start_thread)) {
        // If running on the main thread, directly quit.
        cortexm_graphic_quit();
    } else {
        // If on another thread, defer to main thread and wait.
        cortexm_graphic_enqueue_event(GRAPHIC_EVENT_QUIT, NULL, NULL);

        while (!is_terminated) {
            qemu_log_mask(LOG_FUNC, "%s() wait\n", __FUNCTION__);
            SDL_Delay(100);
        }
    }
}

// Start the graphic subsystem. From this moment on, the event queue
// must be available to enqueue requests, even if the requests will
// be processed when the event loop is entered (at the end of main()).
void cortexm_graphic_start(bool nographic)
{
    qemu_log_function_name();

    is_not_nographic = nographic;

    if (is_not_nographic) {
        return;
    }

#if defined(CONFIG_SDL)

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        error_printf("Unable to initialize SDL:  %s\n", SDL_GetError());
        exit(1);
    }

    atexit(cortexm_graphic_atexit);

#endif /* defined(CONFIG_SDL) */

    qemu_thread_get_self(&start_thread);
}

// ----------------------------------------------------------------------------

void cortexm_graphic_board_clear_graphic_context(
        BoardGraphicContext *board_graphic_context)
{
    qemu_log_function_name();

    board_graphic_context->picture_file_name = NULL;
    board_graphic_context->picture_file_absolute_path = NULL;
    board_graphic_context->window_caption = NULL;

    board_graphic_context->buttons = NULL;
    board_graphic_context->buttons_array_capacity = 0;
    board_graphic_context->buttons_array_length = 0;

#if defined(CONFIG_SDL)

#if defined(CONFIG_SDLABI_2_0)
    board_graphic_context->window = NULL;
    board_graphic_context->renderer = NULL;
    board_graphic_context->texture = NULL;
    board_graphic_context->surface = NULL;
#elif defined(CONFIG_SDLABI_1_2)
    board_graphic_context->surface = NULL;
#endif

#endif /* defined(CONFIG_SDL) */
}

bool cortexm_graphic_board_is_graphic_context_initialised(
        BoardGraphicContext *board_graphic_context)
{
    return (board_graphic_context->surface != NULL);
}

static void cortexm_graphic_board_init_graphic_context(
        BoardGraphicContext *board_graphic_context)
{
    qemu_log_function_name();

#if defined(CONFIG_SDL)

#if 0
    const char *fullname = qemu_find_file(QEMU_FILE_TYPE_GRAPHICS,
            board_graphic_context->picture_file_name);
    if (fullname == NULL) {
        error_printf("Image file '%s' not found.\n",
                board_graphic_context->picture_file_name);
        exit(1);
    }
#endif

    int res = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    if ((res & (IMG_INIT_JPG | IMG_INIT_PNG))
            != (IMG_INIT_JPG | IMG_INIT_PNG)) {
        error_printf("IMG_init failed (%s).\n", IMG_GetError());
        exit(1);
    }
    // A better SDL_LoadBMP().
    SDL_Surface* board_bitmap = IMG_Load(
            board_graphic_context->picture_file_absolute_path);
    if (board_bitmap == NULL) {
        error_printf("Cannot load image file '%s' (%s).\n",
                board_graphic_context->picture_file_absolute_path,
                IMG_GetError());
        exit(1);
    }

#if defined(CONFIG_SDLABI_2_0)

    SDL_Window* win = SDL_CreateWindow(board_graphic_context->window_caption,
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, board_bitmap->w,
            board_bitmap->h, 0);
    if (win == NULL) {
        error_printf("Could not create window: %s\n", SDL_GetError());
        exit(1);
    }
    board_graphic_context->window = win;

    SDL_Renderer* renderer = SDL_CreateRenderer(win, -1,
            SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        error_printf("Could not create renderer: %s\n", SDL_GetError());
        exit(1);
    }
    board_graphic_context->renderer = renderer;

    SDL_Surface* board_bitmap_rgb = SDL_ConvertSurfaceFormat(board_bitmap,
            SDL_PIXELFORMAT_RGB888, 0);
    if (board_bitmap_rgb == 0) {
        error_printf("Could not create surface: %s\n", SDL_GetError());
        exit(1);
    }
    board_graphic_context->surface = board_bitmap_rgb;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,
            board_bitmap_rgb);
    if (texture == NULL) {
        error_printf("Could not create texture: %s\n", SDL_GetError());
        exit(1);
    }
    board_graphic_context->texture = texture;

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

#elif defined(CONFIG_SDLABI_1_2)

    SDL_WM_SetCaption(board_graphic_context->window_caption, NULL);
    SDL_Surface* screen = SDL_SetVideoMode(board_bitmap->w, board_bitmap->h, 32,
            SDL_DOUBLEBUF);
    SDL_Surface* board_surface = SDL_DisplayFormat(board_bitmap);

    /* Apply image to screen */
    SDL_BlitSurface(board_surface, NULL, screen, NULL);
    /* Update screen */
    SDL_Flip(screen);

    board_graphic_context->surface = screen;

#endif /* defined(CONFIG_SDLABI_*) */

    SDL_FreeSurface(board_bitmap);

    button_cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
    if (button_cursor == NULL) {
        error_printf("Could not create cursor: %s\n", SDL_GetError());
        exit(1);
    }
#endif /* defined(CONFIG_SDL) */
}

#define DEFAULT_BUTTONS_CAPACITY (2)

void cortexm_graphic_board_add_button(
        BoardGraphicContext *board_graphic_context, ButtonState *button_state)
{
    if (board_graphic_context->buttons_array_length
            >= board_graphic_context->buttons_array_capacity) {
        if (board_graphic_context->buttons_array_capacity == 0) {
            // Allocate initial array of pointers to buttons.
            board_graphic_context->buttons = g_malloc0_n(
            DEFAULT_BUTTONS_CAPACITY, sizeof(Object*));
            board_graphic_context->buttons_array_capacity =
            DEFAULT_BUTTONS_CAPACITY;
        } else {
            // Double the size of the array of pointers to buttons.
            board_graphic_context->buttons = g_realloc_n(
                    board_graphic_context->buttons,
                    2 * board_graphic_context->buttons_array_capacity,
                    sizeof(Object*));
            board_graphic_context->buttons_array_capacity *= 2;
        }
    }

    assert(
            board_graphic_context->buttons_array_length
                    < board_graphic_context->buttons_array_capacity);

    board_graphic_context->buttons[board_graphic_context->buttons_array_length++] =
            button_state;
}

// ----------------------------------------------------------------------------

void cortexm_graphic_led_clear_graphic_context(
        LEDGraphicContext *led_graphic_context)
{
    qemu_log_function_name();

    led_graphic_context->crop_on = NULL;
    led_graphic_context->crop_off = NULL;
}

bool cortexm_graphic_led_is_graphic_context_initialised(
        LEDGraphicContext *led_graphic_context)
{
    return (led_graphic_context->crop_on != NULL);
}

static void cortexm_graphic_led_init_graphic_context(
        BoardGraphicContext *board_graphic_context,
        LEDGraphicContext *led_graphic_context, uint8_t red, uint8_t green,
        uint8_t blue)
{
    qemu_log_function_name();

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

    // Copy bitmap from original picture.
    SDL_BlitSurface(board_graphic_context->surface, rectangle,
            led_graphic_context->crop_off, 0);

    Uint32 colour = SDL_MapRGB(led_graphic_context->crop_on->format, red, green,
            blue);

    // Fill with uniform colour.
    SDL_FillRect(led_graphic_context->crop_on, NULL, colour);

#endif /* defined(CONFIG_SDL) */
}

static void cortexm_graphic_led_turn(BoardGraphicContext *board_graphic_context,
        LEDGraphicContext *led_graphic_context, bool is_on)
{
    qemu_log_mask(LOG_FUNC, "%s(%s)\n", __FUNCTION__, is_on ? "on" : "off");

#if defined(CONFIG_SDL)

    SDL_Surface *crop =
            is_on ?
                    led_graphic_context->crop_on :
                    led_graphic_context->crop_off;

#if defined(CONFIG_SDLABI_2_0)
    SDL_UpdateTexture(board_graphic_context->texture,
            &(led_graphic_context->rectangle), crop->pixels, crop->pitch);
    SDL_RenderCopy(board_graphic_context->renderer,
            board_graphic_context->texture,
            NULL, NULL);
    SDL_RenderPresent(board_graphic_context->renderer);
#elif defined(CONFIG_SDLABI_1_2)
    SDL_BlitSurface(crop, NULL, board_graphic_context->surface,
            &(led_graphic_context->rectangle));
    SDL_Flip(board_graphic_context->surface);
#endif

#endif /* defined(CONFIG_SDL) */
}

// ----------------------------------------------------------------------------

