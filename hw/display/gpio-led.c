/*
 * GPIO connected LED device emulation.
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

#include "hw/display/gpio-led.h"

/**
 * This class implements a LED connected to a GPIO device.
 */

static void gpio_led_irq_handler(void *opaque, int n, int level)
{
    GPIOLEDInfo *info = GPIO_LED_STATE(opaque)->info;

    /* There should be only one IRQ for the LED */
    assert(n == 0);

    FILE *file = stderr;
    /*
     * Assume that the IRQ is only triggered if the LED has changed state.
     * If this is not correct, we may get multiple LED Offs or Ons in a row.
     */
    switch (level) {
    case 0:
        fprintf(file, "%s",
                info->active_low ? info->on_message : info->off_message);
        break;

    case 1:
        fprintf(file, "%s",
                info->active_low ? info->off_message : info->on_message);
        break;
    }
}

static void gpio_led_construct_callback(Object *obj,
        GPIOLEDInfo* info /*, DeviceState *mcu */)
{
    qemu_log_function_name();

    GPIOLEDState *state = GPIO_LED_STATE(obj);

    state->info = info;

    /*
     * Allocate 1 single incoming irq, and attach handler, this device
     * and n=0. (n==0 is checked in the handler by an assert)
     */
    state->irq = qemu_allocate_irq(gpio_led_irq_handler, obj, 0);
    // qdev_init_gpio_in(DEVICE(obj), gpio_led_irq_handler, 1);

    /* The connection will be done by the machine */
}

#define DEFINE_PROP_DEVICE_STATE_PTR(_n, _s, _f) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_ptr, DeviceState*)

static Property gpio_led_properties[] = {
        DEFINE_PROP_GPIO_LED_PTR("info", GPIOLEDState, info),
    DEFINE_PROP_END_OF_LIST() };

static void gpio_led_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->props = gpio_led_properties;

    GPIOLEDClass *gl_class = GPIO_LED_CLASS(klass);
    gl_class->construct = gpio_led_construct_callback;
}

static const TypeInfo gpio_led_type_info = {
    .name = TYPE_GPIO_LED,
    .parent = TYPE_GPIO_LED_PARENT,
    .instance_size = sizeof(GPIOLEDState),
    .class_init = gpio_led_class_init_callback,
    .class_size = sizeof(GPIOLEDClass) };

static void gpio_led_type_init()
{
    type_register_static(&gpio_led_type_info);
}

type_init(gpio_led_type_init);
