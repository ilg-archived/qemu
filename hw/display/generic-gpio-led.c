/*
 * Generic LED device emulation.
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

//#include "qom/object.h"
#include "hw/display/generic-gpio-led.h"
//#include "hw/qdev.h"

static void generic_gpio_led_irq_handler(void *opaque, int n, int level)
{
    GenericGPIOLEDInfo *info = GENERIC_GPIO_LED_STATE(opaque)->info;

    /* There should be only one IRQ for the LED */
    assert(n == 0);

    FILE *file;
    if (info->use_stderr) {
        file = stderr;
    } else {
        file = stdout;
    }
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

static void generic_gpio_led_construct_callback(Object *obj,
        GenericGPIOLEDInfo* info, DeviceState *mcu)
{
    qemu_log_function_name();

    GenericGPIOLEDState *state = GENERIC_GPIO_LED_STATE(obj);

    state->info = info;
    state->mcu = mcu;
}

static void generic_gpio_led_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    GenericGPIOLEDState *state = GENERIC_GPIO_LED_STATE(dev);
    GenericGPIOLEDClass *klass = GENERIC_GPIO_LED_GET_CLASS(state);

    GenericGPIOLEDInfo *info = state->info;

    DeviceState *gpio = klass->get_gpio_dev(dev, info->port_index);
    assert(gpio);

    /* Connect LED interrupt to GPIO pin  */
    qemu_irq *led_irq = qemu_allocate_irqs(generic_gpio_led_irq_handler, dev,
            1);
    qdev_connect_gpio_out(gpio, info->port_bit, led_irq[0]);
}

#define DEFINE_PROP_DEVICE_STATE_PTR(_n, _s, _f) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_ptr, DeviceState*)

static Property generic_gpio_led_properties[] = {
        DEFINE_PROP_GENERIC_GPIO_LED_PTR("info", GenericGPIOLEDState, info),
        DEFINE_PROP_DEVICE_STATE_PTR("mcu", GenericGPIOLEDState, mcu),
    DEFINE_PROP_END_OF_LIST() };

static void generic_gpio_led_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->props = generic_gpio_led_properties;
    dc->realize = generic_gpio_led_realize_callback;

    GenericGPIOLEDClass *gl_class = GENERIC_GPIO_LED_CLASS(klass);
    gl_class->construct = generic_gpio_led_construct_callback;
}

static const TypeInfo generic_gpio_led_type_info = {
    .abstract = true,
    .name = TYPE_GENERIC_GPIO_LED,
    .parent = TYPE_DEVICE,
    .instance_size = sizeof(GenericGPIOLEDState),
    .class_init = generic_gpio_led_class_init_callback,
    .class_size = sizeof(GenericGPIOLEDClass) };

static void generic_gpio_led_type_init()
{
    type_register_static(&generic_gpio_led_type_info);
}

type_init(generic_gpio_led_type_init);
