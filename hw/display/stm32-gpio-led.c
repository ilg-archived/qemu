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

static DeviceState *stm32_gpio_led_get_gpio_dev(DeviceState *dev,
        int port_index)
{
    GenericGPIOLEDState *gl_state = GENERIC_GPIO_LED_STATE(dev);

    return stm32_mcu_get_gpio_dev(gl_state->mcu, port_index);
}

static void stm32_gpio_led_class_init_callback(ObjectClass *klass, void *data)
{
    GenericGPIOLEDClass *gl_klass = GENERIC_GPIO_LED_CLASS(klass);

    gl_klass->get_gpio_dev = stm32_gpio_led_get_gpio_dev;
}

static const TypeInfo stm32_gpio_led_type_info = {
    .name = TYPE_STM32_GPIO_LED,
    .parent = TYPE_GENERIC_GPIO_LED,
    .instance_size = sizeof(STM32GPIOLEDState),
    .class_init = stm32_gpio_led_class_init_callback,
    .class_size = sizeof(STM32GPIOLEDClass) };

static void stm32_gpio_led_type_init()
{
    type_register_static(&stm32_gpio_led_type_info);
}

type_init(stm32_gpio_led_type_init);
