/*
 * STM32 Arduino-like boards emulation.
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
 * This file defines several Arduino-like STM32 boards.
 */

#if 0
/* ----- Netduino 2 ----- */
static void
netduino2_board_init_callback(MachineState *machine);

static QEMUMachine netduino2_machine = {
    .name = "Netduino2",
    .desc = "Netduino Development Board with STM32F2 (Experimental)",
    .init = netduino2_board_init_callback};

static void netduino2_board_init_callback(MachineState *machine)
{
    cm_board_greeting(machine);
    //cortexm_mcu_alloc(machine, TYPE_STM32F205RF);

    /* TODO: Add board inits */
}
#endif

// ----- Netduino Plus 2 ------------------------------------------------------

static GPIOLEDInfo netduinoplus2_leds_info[] = {
    {
        .name = "led:blue",
        .active_low = false,
        .colour_name = "blue",
        .x = 507,
        .y = 183,
        .w = 12,
        .h = 14,

        .gpio_path = DEVICE_PATH_STM32_GPIO_A,
        .irq_name = STM32_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 10,
    /**/
    },
    { },
/**/
};

static ButtonGPIOInfo netduinoplus2_buttons_user_info[] = {
    {
        .name = "button:user",
        .x = 477,
        .y = 299,
        .w = 28,
        .h = 28,

        .active_low = false,
        .gpio_path = DEVICE_PATH_STM32_GPIO_C,
        .irq_name = STM32_IRQ_GPIO_IDR_IN,
        .gpio_bit = 14,
    /**/
    },
    { },
/**/
};

// Button not physically present, only as a pin in a connector.
static ButtonResetInfo netduinoplus2_button_reset_info = {
    .x = 305,
    .y = 452,
    .w = 15,
    .h = 45,
/**/
};

static void netduinoplus2_board_init_callback(MachineState *machine)
{
    CortexMBoardState *board = CORTEXM_BOARD_STATE(machine);

    cortexm_board_greeting(board);
    BoardGraphicContext *board_graphic_context =
            cortexm_board_init_graphic_image(board, "NetduinoPlus2.jpg");

    {
        // Create the MCU
        Object *mcu = cm_object_new_mcu(machine, TYPE_STM32F405RG);

        // Set the board specific oscillator frequencies.
        cm_object_property_set_int(mcu, 25000000, "hse-freq-hz"); // 25.0 MHz
        cm_object_property_set_int(mcu, 0, "lse-freq-hz"); // N/A

        cm_object_realize(mcu);
    }

    Object *peripheral = cm_container_get_peripheral();
    // Create board LEDs.
    gpio_led_create_from_info(peripheral, netduinoplus2_leds_info,
            board_graphic_context);

    if (board_graphic_context != NULL) {
        // Create board buttons.
        button_reset_create_from_info(peripheral,
                &netduinoplus2_button_reset_info, board_graphic_context);
        button_gpio_create_from_info(peripheral,
                netduinoplus2_buttons_user_info, board_graphic_context);
    }
}

static void netduinoplus2_board_class_init_callback(ObjectClass *oc, void *data)
{
    MachineClass *mc = MACHINE_CLASS(oc);

    mc->desc = "Netduino Development Board with STM32F4";
    mc->init = netduinoplus2_board_init_callback;
}

static const TypeInfo netduinoplus2_machine = {
    .name = BOARD_TYPE_NAME("NetduinoPlus2"),
    .parent = TYPE_CORTEXM_BOARD,
    .class_init = netduinoplus2_board_class_init_callback
/**/
};

// ----- Netduino Go ----------------------------------------------------------

static GPIOLEDInfo netduinogo_leds_info[] = {
    {
        .name = "led:white1",
        .active_low = false,
        .colour_name = "white",
        .x = 140,
        .y = 457,
        .w = 8,
        .h = 12,

//        .on_message = "[White LED1 On]\n",
//        .on_message = "[White LED1 Off]\n",
        .gpio_path = DEVICE_PATH_STM32_GPIO_B,
        .irq_name = STM32_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 6,
    /**/
    },
    {
        .name = "led:white2",
        .active_low = false,
        .colour_name = "white",
        .x = 286,
        .y = 457,
        .w = 8,
        .h = 12,

//        .on_message = "[White LED2 On]\n",
//        .on_message = "[White LED2 Off]\n",
        .gpio_path = DEVICE_PATH_STM32_GPIO_B,
        .irq_name = STM32_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 7,
    /**/
    },
    {
        .name = "led:white3",
        .active_low = false,
        .colour_name = "white",
        .x = 432,
        .y = 457,
        .w = 8,
        .h = 12,

//        .on_message = "[White LED3 On]\n",
//        .on_message = "[White LED3 Off]\n",
        .gpio_path = DEVICE_PATH_STM32_GPIO_B,
        .irq_name = STM32_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 8,
    /**/
    },
    {
        .name = "led:white4",
        .active_low = false,
        .colour_name = "white",
        .x = 614,
        .y = 405,
        .w = 12,
        .h = 8,

//        .on_message = "[White LED4 On]\n",
//        .on_message = "[White LED4 Off]\n",
        .gpio_path = DEVICE_PATH_STM32_GPIO_B,
        .irq_name = STM32_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 9,
    /**/
    },
    {
        .name = "led:white5",
        .active_low = false,
        .colour_name = "white",
        .x = 614,
        .y = 259,
        .w = 12,
        .h = 8,

//        .on_message = "[White LED5 On]\n",
//        .on_message = "[White LED5 Off]\n",
        .gpio_path = DEVICE_PATH_STM32_GPIO_C,
        .irq_name = STM32_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 6,
    /**/
    },
    {
        .name = "led:white6",
        .active_low = false,
        .colour_name = "white",
        .x = 564,
        .y = 70,
        .w = 8,
        .h = 12,

//        .on_message = "[White LED6 On]\n",
//        .on_message = "[White LED6 Off]\n",
        .gpio_path = DEVICE_PATH_STM32_GPIO_C,
        .irq_name = STM32_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 7,
    /**/
    },
    {
        .name = "led:white7",
        .active_low = false,
        .colour_name = "white",
        .x = 419,
        .y = 70,
        .w = 8,
        .h = 12,

//        .on_message = "[White LED7 On]\n",
//        .on_message = "[White LED7 Off]\n",
        .gpio_path = DEVICE_PATH_STM32_GPIO_C,
        .irq_name = STM32_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 8,
    /**/
    },
    {
        .name = "led:white8",
        .active_low = false,
        .colour_name = "white",
        .x = 274,
        .y = 70,
        .w = 8,
        .h = 12,

//        .on_message = "[White LED8 On]\n",
//        .on_message = "[White LED8 Off]\n",
        .gpio_path = DEVICE_PATH_STM32_GPIO_C,
        .irq_name = STM32_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 9,
    /**/
    },
    { },
/**/
};

static ButtonGPIOInfo netduinogo_buttons_user_info[] = {
    {
        .name = "button:user",
        .x = 428,
        .y = 261,
        .w = 30,
        .h = 30,

        .active_low = false,
        .gpio_path = DEVICE_PATH_STM32_GPIO_C,
        .irq_name = STM32_IRQ_GPIO_IDR_IN,
        .gpio_bit = 14,
    /**/
    },
    { },
/**/
};

// Button not physically present, the action associated to the PWR label.
static ButtonResetInfo netduinogo_button_reset_info = {
    .x = 84,
    .y = 193,
    .w = 12,
    .h = 28,
/**/
};

static void netduinogo_board_init_callback(MachineState *machine)
{
    CortexMBoardState *board = CORTEXM_BOARD_STATE(machine);

    cortexm_board_greeting(board);
    BoardGraphicContext *board_graphic_context =
            cortexm_board_init_graphic_image(board, "NetduinoGo.jpg");

    {
        // Create the MCU
        Object *mcu = cm_object_new_mcu(machine, TYPE_STM32F405RG);

        // Set the board specific oscillator frequencies.
        cm_object_property_set_int(mcu, 25000000, "hse-freq-hz"); // 25.0 MHz
        cm_object_property_set_int(mcu, 0, "lse-freq-hz"); // N/A

        cm_object_realize(mcu);
    }

    Object *peripheral = cm_container_get_peripheral();
    // Create board LEDs.
    gpio_led_create_from_info(peripheral, netduinogo_leds_info,
            board_graphic_context);

    if (board_graphic_context != NULL) {
        // Create board buttons.
        button_reset_create_from_info(peripheral, &netduinogo_button_reset_info,
                board_graphic_context);
        button_gpio_create_from_info(peripheral, netduinogo_buttons_user_info,
                board_graphic_context);
    }
}

static void netduinogo_board_class_init_callback(ObjectClass *oc, void *data)
{
    MachineClass *mc = MACHINE_CLASS(oc);

    mc->desc = "Netduino GoBus Development Board with STM32F4";
    mc->init = netduinogo_board_init_callback;
}

static const TypeInfo netduinogo_machine = {
    .name = BOARD_TYPE_NAME("NetduinoGo"),
    .parent = TYPE_CORTEXM_BOARD,
    .class_init = netduinogo_board_class_init_callback
/**/
};

// ----- Maple r5 -------------------------------------------------------------

static GPIOLEDInfo maple_leds_info[] = {
    {
        .name = "led:blue",
        .active_low = false,
        .colour_name = "blue",
        .x = 215,
        .y = 161,
        .w = 10,
        .h = 8,

        .gpio_path = DEVICE_PATH_STM32_GPIO_A,
        .irq_name = STM32_IRQ_GPIO_ODR_OUT,
        .gpio_bit = 5,
    /**/
    },
    { },
/**/
};

static ButtonGPIOInfo maple_buttons_user_info[] = {
    {
        .name = "button:user",
        .x = 499,
        .y = 178,
        .w = 30,
        .h = 36,

        .active_low = false,
        .gpio_path = DEVICE_PATH_STM32_GPIO_C,
        .irq_name = STM32_IRQ_GPIO_IDR_IN,
        .gpio_bit = 9,
    /**/
    },
    { },
/**/
};

static ButtonResetInfo maple_button_reset_info = {
    .x = 166,
    .y = 538,
    .w = 30,
    .h = 36,
/**/
};

static void maple_board_init_callback(MachineState *machine)
{
    CortexMBoardState *board = CORTEXM_BOARD_STATE(machine);

    cortexm_board_greeting(board);
    BoardGraphicContext *board_graphic_context =
            cortexm_board_init_graphic_image(board, "Maple.jpg");

    {
        // Create the MCU
        Object *mcu = cm_object_new_mcu(machine, TYPE_STM32F103RB);

        // Set the board specific oscillator frequencies.
        cm_object_property_set_int(mcu, 8000000, "hse-freq-hz"); // 8.0 MHz
        cm_object_property_set_int(mcu, 0, "lse-freq-hz"); // N/A

        cm_object_realize(mcu);
    }

    cortexm_board_init_graphic_image(board, "Maple.jpg");

    Object *peripheral = cm_container_get_peripheral();
    // Create board LEDs.
    gpio_led_create_from_info(peripheral, maple_leds_info,
            board_graphic_context);

    if (board_graphic_context != NULL) {
        // Create board buttons.
        button_reset_create_from_info(peripheral, &maple_button_reset_info,
                board_graphic_context);
        button_gpio_create_from_info(peripheral, maple_buttons_user_info,
                board_graphic_context);
    }
}

static void maple_board_class_init_callback(ObjectClass *oc, void *data)
{
    MachineClass *mc = MACHINE_CLASS(oc);

    mc->desc = "LeafLab Arduino-style STM32 microcontroller board (r5)";
    mc->init = maple_board_init_callback;
}

static const TypeInfo maple_machine = {
    .name = BOARD_TYPE_NAME("Maple"),
    .parent = TYPE_CORTEXM_BOARD,
    .class_init = maple_board_class_init_callback
/**/
};

// ----- Boards inits ---------------------------------------------------------

static void stm32_duino_machines_init(void)
{
#if 0
    qemu_register_machine(&netduino2_machine);
#endif
    type_register_static(&netduinoplus2_machine);
    type_register_static(&netduinogo_machine);
    type_register_static(&maple_machine);
}

#if 1
type_init(stm32_duino_machines_init);
#endif

