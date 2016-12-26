/*
 * STM32 Olimex boards emulation.
 *
 * Copyright (c) 2014 Liviu Ionescu.
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

#include <hw/cortexm/board.h>
#include <hw/cortexm/stm32/mcus.h>
#include <hw/cortexm/gpio-led.h>
#include <hw/cortexm/button-gpio.h>
#include <hw/cortexm/button-reset.h>
#include <hw/cortexm/helper.h>

/*
 * This file defines several Olimex STM32 boards.
 */

// ----- Olimex STM32-H103 ----------------------------------------------------
static GPIOLEDInfo stm32_h103_leds_info[] = {
    {
        .name = "led:green",
        .active_low = true,
        .colour_name = "green",
        .x = 97,
        .y = 243,
        .w = 14,
        .h = 12,
        .gpio_path = DEVICE_PATH_STM32_GPIO_C,
        .irq_name = STM32_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 12,
    /**/
    },
    { },
/**/
};

static ButtonGPIOInfo stm32_h103_buttons_user_info[] = {
    {
        .name = "button:user",
        .x = 178,
        .y = 172,
        .w = 20,
        .h = 20,

        .active_low = false,
        .gpio_path = DEVICE_PATH_STM32_GPIO_A,
        .irq_name = STM32_IRQ_GPIO_IDR_IN,
        .gpio_bit = 0,
    /**/
    },
    { }, /**/
};

static ButtonResetInfo stm32_h103_button_reset_info = {
    .x = 176,
    .y = 112,
    .w = 20,
    .h = 10,
/**/
};

static void stm32_h103_board_init_callback(MachineState *machine)
{
    CortexMBoardState *board = CORTEXM_BOARD_STATE(machine);

    cortexm_board_greeting(board);
    BoardGraphicContext *board_graphic_context =
            cortexm_board_init_graphic_image(board, "STM32-H103.jpg");

    {
        // Create the MCU
        Object *mcu = cm_object_new_mcu(machine, TYPE_STM32F103RB);

        // Set the board specific oscillator frequencies.
        cm_object_property_set_int(mcu, 8000000, "hse-freq-hz"); // 8.0 MHz
        cm_object_property_set_int(mcu, 32768, "lse-freq-hz"); // 32 kHz

        cm_object_realize(mcu);
    }

    Object *peripheral = cm_container_get_peripheral();
    // Create board LEDs.
    gpio_led_create_from_info(peripheral, stm32_h103_leds_info,
            board_graphic_context);

    if (board_graphic_context != NULL) {
        // Create board buttons.
        button_reset_create_from_info(peripheral, &stm32_h103_button_reset_info,
                board_graphic_context);
        button_gpio_create_from_info(peripheral, stm32_h103_buttons_user_info,
                board_graphic_context);
    }
}

static void stm32_h103_board_class_init_callback(ObjectClass *oc, void *data)
{
    MachineClass *mc = MACHINE_CLASS(oc);

    mc->desc = "Olimex Header Board for STM32F103RBT6";
    mc->init = stm32_h103_board_init_callback;
}

static const TypeInfo stm32_h103_machine = {
    .name = BOARD_TYPE_NAME("STM32-H103"),
    .parent = TYPE_CORTEXM_BOARD,
    .class_init = stm32_h103_board_class_init_callback
/**/
};

// ----- Olimex STM32-P103 ----------------------------------------------------

static GPIOLEDInfo stm32_p103_leds_info[] = {
    {
        .name = "led:red",
        .active_low = true,
        .colour_name = "red",
        .x = 331,
        .y = 362,
        .w = 12,
        .h = 10,
        .gpio_path = DEVICE_PATH_STM32_GPIO_C,
        .irq_name = STM32_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 12,
    /**/
    },
    { },
/**/
};

static ButtonGPIOInfo stm32_p103_buttons_user_info[] = {
    {
        .name = "button:wkup",
        .x = 278,
        .y = 438,
        .w = 36,
        .h = 36,

        .active_low = false,
        .gpio_path = DEVICE_PATH_STM32_GPIO_A,
        .irq_name = STM32_IRQ_GPIO_IDR_IN,
        .gpio_bit = 0,
    /**/
    },
    { },
/**/
};

static ButtonResetInfo stm32_p103_button_reset_info = {
    .x = 167,
    .y = 210,
    .w = 10,
    .h = 18,
/**/
};

static void stm32_p103_board_init_callback(MachineState *machine)
{
    CortexMBoardState *board = CORTEXM_BOARD_STATE(machine);

    cortexm_board_greeting(board);
    BoardGraphicContext *board_graphic_context =
            cortexm_board_init_graphic_image(board, "STM32-P103.jpg");

    {
        // Create the MCU
        Object *mcu = cm_object_new_mcu(machine, TYPE_STM32F103RB);

        // Set the board specific oscillator frequencies.
        cm_object_property_set_int(mcu, 8000000, "hse-freq-hz"); // 8.0 MHz
        cm_object_property_set_int(mcu, 32768, "lse-freq-hz"); // 32 kHz

        cm_object_realize(mcu);
    }

    Object *peripheral = cm_container_get_peripheral();
    // Create board LEDs.
    gpio_led_create_from_info(peripheral, stm32_p103_leds_info,
            board_graphic_context);

    if (board_graphic_context != NULL) {
        // Create board buttons.
        button_reset_create_from_info(peripheral, &stm32_p103_button_reset_info,
                board_graphic_context);
        button_gpio_create_from_info(peripheral, stm32_p103_buttons_user_info,
                board_graphic_context);
    }
}

static void stm32_p103_board_class_init_callback(ObjectClass *oc, void *data)
{
    MachineClass *mc = MACHINE_CLASS(oc);

    mc->desc = "Olimex Prototype Board for STM32F103RBT6";
    mc->init = stm32_p103_board_init_callback;
}

static const TypeInfo stm32_p103_machine = {
    .name = BOARD_TYPE_NAME("STM32-P103"),
    .parent = TYPE_CORTEXM_BOARD,
    .class_init = stm32_p103_board_class_init_callback
/**/
};

// ----- Olimex OLIMEXINO-STM32 -----------------------------------------------

static GPIOLEDInfo olimexino_stm32_leds_info[] = {
    {
        .name = "led:green",
        .active_low = false,
        .colour_name = "green",
        .x = 137,
        .y = 40,
        .w = 10,
        .h = 10,
        .gpio_path = DEVICE_PATH_STM32_GPIO_A,
        .irq_name = STM32_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 5,
    /**/
    },
    {
        .name = "led:yellow",
        .active_low = false,
        .colour_name = "yellow",
        .x = 168,
        .y = 40,
        .w = 10,
        .h = 10,
        .gpio_path = DEVICE_PATH_STM32_GPIO_A,
        .irq_name = STM32_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 1,
    /**/
    },
    { },
/**/
};

// The button is also connected to BOOT0. Not implemented.
static ButtonGPIOInfo olimexino_stm32_buttons_user_info[] = {
    {
        .name = "button:user",
        .x = 95,
        .y = 44,
        .w = 40,
        .h = 40,

        .active_low = false,
        .gpio_path = DEVICE_PATH_STM32_GPIO_C,
        .irq_name = STM32_IRQ_GPIO_IDR_IN,
        .gpio_bit = 9,
    /**/
    },
    { },
/**/
};

static ButtonResetInfo olimexino_stm32_button_reset_info = {
    .x = 136,
    .y = 416,
    .w = 40,
    .h = 40,
/**/
};

static void olimexino_stm32_board_init_callback(MachineState *machine)
{
    CortexMBoardState *board = CORTEXM_BOARD_STATE(machine);

    cortexm_board_greeting(board);
    BoardGraphicContext *board_graphic_context =
            cortexm_board_init_graphic_image(board, "OLIMEXINO-STM32.jpg");

    {
        // Create the MCU
        Object *mcu = cm_object_new_mcu(machine, TYPE_STM32F103RB);

        // Set the board specific oscillator frequencies.
        cm_object_property_set_int(mcu, 8000000, "hse-freq-hz"); // 8.0 MHz
        cm_object_property_set_int(mcu, 32768, "lse-freq-hz"); // 32 kHz

        cm_object_realize(mcu);
    }

    Object *peripheral = cm_container_get_peripheral();
    // Create board LEDs.
    gpio_led_create_from_info(peripheral, olimexino_stm32_leds_info,
            board_graphic_context);

    if (board_graphic_context != NULL) {
        // Create board buttons.
        button_reset_create_from_info(peripheral,
                &olimexino_stm32_button_reset_info, board_graphic_context);
        button_gpio_create_from_info(peripheral,
                olimexino_stm32_buttons_user_info, board_graphic_context);
    }
}

static void olimexino_stm32_board_class_init_callback(ObjectClass *oc,
        void *data)
{
    MachineClass *mc = MACHINE_CLASS(oc);

    mc->desc = "Olimex Maple (Arduino-like) Development Board";
    mc->init = olimexino_stm32_board_init_callback;
}

static const TypeInfo olimexino_stm32_machine = {
    .name = BOARD_TYPE_NAME("OLIMEXINO-STM32"),
    .parent = TYPE_CORTEXM_BOARD,
    .class_init = olimexino_stm32_board_class_init_callback
/**/
};

// ----- Olimex STM32-P107 ----------------------------------------------------

static GPIOLEDInfo stm32_p107_leds_info[] = {
    {
        .name = "led:green",
        .active_low = false,
        .colour_name = "green",
        .x = 227,
        .y = 354,
        .w = 6,
        .h = 8,
        .gpio_path = DEVICE_PATH_STM32_GPIO_C,
        .irq_name = STM32_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 6,
    /**/
    },
    {
        .name = "led:yellow",
        .active_low = false,
        .colour_name = "yellow",
        .x = 171,
        .y = 354,
        .w = 6,
        .h = 8,
        .gpio_path = DEVICE_PATH_STM32_GPIO_C,
        .irq_name = STM32_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 7,
    /**/
    },
    { },
/**/
};

static ButtonGPIOInfo stm32_p107_buttons_user_info[] = {
    {
        .name = "button:wkup",
        .x = 198,
        .y = 353,
        .w = 30,
        .h = 30,

        .active_low = false,
        .gpio_path = DEVICE_PATH_STM32_GPIO_A,
        .irq_name = STM32_IRQ_GPIO_IDR_IN,
        .gpio_bit = 0,
    /**/
    },
    {
        .name = "button:tamper",
        .x = 254,
        .y = 353,
        .w = 30,
        .h = 30,

        .active_low = true,
        .gpio_path = DEVICE_PATH_STM32_GPIO_C,
        .irq_name = STM32_IRQ_GPIO_IDR_IN,
        .gpio_bit = 13,
    /**/
    },
    { },
/**/
};

static ButtonResetInfo stm32_p107_button_reset_info = {
    .x = 302,
    .y = 84,
    .w = 16,
    .h = 8,
/**/
};

static void stm32_p107_board_init_callback(MachineState *machine)
{
    CortexMBoardState *board = CORTEXM_BOARD_STATE(machine);

    cortexm_board_greeting(board);
    BoardGraphicContext *board_graphic_context =
            cortexm_board_init_graphic_image(board, "STM32-P107.jpg");

    {
        // Create the MCU
        Object *mcu = cm_object_new_mcu(machine, TYPE_STM32F107VC);

        // Set the board specific oscillator frequencies.
        cm_object_property_set_int(mcu, 25000000, "hse-freq-hz"); // 25.0 MHz
        cm_object_property_set_int(mcu, 32768, "lse-freq-hz"); // 32 kHz

        cm_object_realize(mcu);
    }

    Object *peripheral = cm_container_get_peripheral();
    // Create board LEDs.
    gpio_led_create_from_info(peripheral, stm32_p107_leds_info,
            board_graphic_context);

    if (board_graphic_context != NULL) {
        // Create board buttons.
        button_reset_create_from_info(peripheral, &stm32_p107_button_reset_info,
                board_graphic_context);
        button_gpio_create_from_info(peripheral, stm32_p107_buttons_user_info,
                board_graphic_context);
    }
}

static void stm32_p107_board_class_init_callback(ObjectClass *oc, void *data)
{
    MachineClass *mc = MACHINE_CLASS(oc);

    mc->desc = "Olimex Prototype Board for STM32F107VCT6";
    mc->init = stm32_p107_board_init_callback;
}

static const TypeInfo stm32_p107_machine = {
    .name = BOARD_TYPE_NAME("STM32-P107"),
    .parent = TYPE_CORTEXM_BOARD,
    .class_init = stm32_p107_board_class_init_callback
/**/
};

// ----- Olimex STM32-P407 ----------------------------------------------------

static GPIOLEDInfo stm32_e407_leds_info[] = {
    {
        .name = "led:green",
        .active_low = true,
        .colour_name = "green",
        .x = 73,
        .y = 408,
        .w = 8,
        .h = 6,
        .gpio_path = DEVICE_PATH_STM32_GPIO_C,
        .irq_name = STM32_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 13,
    /**/
    },
    { },
/**/
};

static ButtonGPIOInfo stm32_e407_buttons_user_info[] = {
    {
        .name = "button:wkup",
        .x = 103,
        .y = 25,
        .w = 18,
        .h = 10,

        .active_low = false,
        .gpio_path = DEVICE_PATH_STM32_GPIO_A,
        .irq_name = STM32_IRQ_GPIO_IDR_IN,
        .gpio_bit = 0,
    /**/
    },
    { },
/**/
};

static ButtonResetInfo stm32_e407_button_reset_info = {
    .x = 91,
    .y = 425,
    .w = 18,
    .h = 10,
/**/
};

static void stm32_e407_board_init_callback(MachineState *machine)
{
    CortexMBoardState *board = CORTEXM_BOARD_STATE(machine);

    cortexm_board_greeting(board);
    BoardGraphicContext *board_graphic_context =
            cortexm_board_init_graphic_image(board, "STM32-E407.jpg");

    {
        // Create the MCU
        Object *mcu = cm_object_new_mcu(machine, TYPE_STM32F407ZG);

        // Set the board specific oscillator frequencies.
        cm_object_property_set_int(mcu, 12000000, "hse-freq-hz"); // 12.0 MHz
        cm_object_property_set_int(mcu, 32768, "lse-freq-hz"); // 32 kHz

        cm_object_realize(mcu);
    }

    Object *peripheral = cm_container_get_peripheral();
    // Create board LEDs.
    gpio_led_create_from_info(peripheral, stm32_e407_leds_info,
            board_graphic_context);

    if (board_graphic_context != NULL) {
        // Create board buttons.
        button_reset_create_from_info(peripheral, &stm32_e407_button_reset_info,
                board_graphic_context);
        button_gpio_create_from_info(peripheral, stm32_e407_buttons_user_info,
                board_graphic_context);
    }
}

static void stm32_e407_board_class_init_callback(ObjectClass *oc, void *data)
{
    MachineClass *mc = MACHINE_CLASS(oc);

    mc->desc = "Olimex Development Board for STM32F407ZGT6";
    mc->init = stm32_e407_board_init_callback;
}

static const TypeInfo stm32_e407_machine = {
    .name = BOARD_TYPE_NAME("STM32-E407"),
    .parent = TYPE_CORTEXM_BOARD,
    .class_init = stm32_e407_board_class_init_callback
/**/
};

// ----- Boards inits ---------------------------------------------------------

static void stm32_olimex_machines_init(void)
{
    type_register_static(&stm32_e407_machine);
    type_register_static(&stm32_p107_machine);
    type_register_static(&stm32_p103_machine);
    type_register_static(&stm32_h103_machine);
    type_register_static(&olimexino_stm32_machine);
}

#if 1
type_init(stm32_olimex_machines_init);
#endif
