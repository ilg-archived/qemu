/*
 * STM32 LED device emulation.
 *
 * Copyright (c) 2015 Liviu Ionescu
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

#include "hw/display/stm32-gpio-led.h"
#include "hw/arm/stm32-mcu.h"

/**
 * Implementation of the "generic-gpio-led" base class for the STM32 family.
 */

/**
 * Implementation of the parent class virtual function.
 * It mainly returns a pointer to the device GPIO[i].
 */
static DeviceState *stm32_gpio_led_get_gpio_dev(DeviceState *dev,
        int port_index)
{
    GPIOLEDState *gl_state = GPIO_LED_STATE(dev);

    /**
     * Ask the MCU for the i-th (port_index) GPIO device.
     */
    return NULL; //stm32_mcu_get_gpio_dev(gl_state->mcu, port_index);
}

static void stm_gpio_led_construct_callback(Object *obj,
        GPIOLEDInfo* info, DeviceState *mcu)
{
    qemu_log_function_name();

    /* Explicitly call the parent constructor. */
    GPIO_LED_GET_CLASS(obj)->construct(obj, info /*, mcu */);
}

static void stm32_gpio_led_class_init_callback(ObjectClass *klass, void *data)
{
    STM32GPIOLEDClass *st_class = STM32_GPIO_LED_CLASS(klass);
    st_class->construct = stm_gpio_led_construct_callback;

    /* Set virtual in parent class */
    GPIOLEDClass *gl_class = GPIO_LED_CLASS(klass);
    //gl_class->get_gpio_dev = stm32_gpio_led_get_gpio_dev;
}

/*
 * The realize() would be empty here, and its pointer is not initialised.
 */
static const TypeInfo stm32_gpio_led_type_info = {
    .name = TYPE_STM32_GPIO_LED,
    .parent = TYPE_GPIO_LED,
    .instance_size = sizeof(STM32GPIOLEDState),
    .class_init = stm32_gpio_led_class_init_callback,
    .class_size = sizeof(STM32GPIOLEDClass) };

static void stm32_gpio_led_type_init()
{
    type_register_static(&stm32_gpio_led_type_info);
}

type_init(stm32_gpio_led_type_init);
