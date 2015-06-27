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
#include "hw/arm/cortexm-helper.h"

/**
 * This class implements a LED connected to a GPIO device.
 */

/* ----- Public ------------------------------------------------------------ */

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

/**
 * Callback used to notify the LED status change.
 */
static void gpio_led_irq_handler(void *opaque, int n, int level)
{
    GPIOLEDState *state = GPIO_LED_STATE(opaque);

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
                state->active_low ? state->on_message : state->off_message);
        break;

    case 1:
        fprintf(file, "%s",
                state->active_low ? state->off_message : state->on_message);
        break;
    }
}

static void gpio_led_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    GPIOLEDState *state = GPIO_LED_STATE(obj);

    qdev_prop_set_string(DEVICE(obj), "on-message", "[LED On]\n");
    qdev_prop_set_string(DEVICE(obj), "off-message", "[LED Off]\n");

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

static Property gpio_led_properties[] = {
        DEFINE_PROP_BOOL("active-low", GPIOLEDState, active_low, false),
        DEFINE_PROP_CONST_STRING("on-message", GPIOLEDState, on_message),
        DEFINE_PROP_CONST_STRING("off-message", GPIOLEDState, off_message),
    DEFINE_PROP_END_OF_LIST() };

static void gpio_led_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->props = gpio_led_properties;
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
