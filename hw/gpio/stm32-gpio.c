/*
 * STM32 MCU - GPIO.
 *
 * Copyright (c) 2015 Liviu Ionescu
 * Copyright (c) 2010 Andre Beckus
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

#include "hw/gpio/stm32-gpio.h"
#include "qemu/bitops.h"

/**
 * This file implements the STM32 GPIO device.
 *
 * The implementation is more or less complete, with interrupts ready to
 * be used by LEDs & buttons.
 *
 * A read access to the Output Data register gets the last written value
 * while in output mode (not only in Push-Pull mode as specified in the
 * ST manual.
 *
 * TODO: add a separate mask to know when in push-pull output mode.
 *
 * TODO: consider using virtual functions to avoid if's in register access.
 *
 * References:
 * - ST CD00171190.pdf, Doc ID 13902 Rev 15, "RM0008 Reference Manual,
 * STM32F101xx, STM32F102xx, STM32F103xx, STM32F105xx and STM32F107xx
 * advanced ARM®-based 32-bit MCUs"
 *
 * All STM32 reference manuals available from:
 * http://www.st.com/stonline/stappl/resourceSelector/\
 * app?page=fullResourceSelector&doctype=reference_manual&FamilyID=141
 */

/* ------------------------------------------------------------------------- */

/* STM32F1[LMHX]D, STM32F1CL */

static bool stm32f1_rcc_is_gpio_enabled(STM32RCCState *dev, int port_index)
{
    assert(dev);
    /* GPIO clock enable bits are in apb2enr for families. */
    if ((dev->u.f1.reg.apb2enr & (0x4 << port_index)) != 0) {
        return true;
    }
    return false;
}

/**
 * STM32F1 read 32-bits.
 */
static uint32_t stm32f1_gpio_read32(STM32GPIOState *state, uint32_t offset,
        unsigned size)
{
    if (!stm32f1_rcc_is_gpio_enabled(state->rcc, state->port_index)) {
        return 0; /* Not enabled */
    }

    uint32_t value;

    switch (offset) {
    case 0x00:
        value = state->u.f1.reg.crl;
        return value;

    case 0x04:
        value = state->u.f1.reg.crh;
        return value;

    case 0x08:
        value = state->u.f1.reg.idr & 0x0000FFFF;
        return value;

    case 0x0C:
        value = state->u.f1.reg.odr & 0x0000FFFF;
        return value;

    case 0x18:
        value = state->u.f1.reg.lckr & 0x0001FFFF;
        return value;

    default:
        qemu_log_mask(LOG_UNIMP,
                "GPIO: Read of size %d at offset 0x%x not implemented\n", size,
                offset);
        break;
    }

    return 0;
}

/**
 * Gets the four configuration bits for the pin from the CRL or CRH
 * register.
 */
static uint32_t stm32f1_gpio_get_pin_config(STM32GPIOState *state, unsigned pin)
{
    /*
     * Simplify extract logic by combining both 32 bit registers into
     * one 64 bit value.
     */
    uint64_t cr_64 = ((uint64_t) state->u.f1.reg.crh << 32)
            | state->u.f1.reg.crl;
    return extract64(cr_64, pin * 4, 4);
}

/**
 * Configuration bits:
 * - in input mode:
 *   00: analog mode
 *   01: floating input (reset)
 *   10: Input with pull-up/pull-down
 *   11: Reserved
 * - in output mode:
 *   00: general purpose output push-pull
 *   01: general purpose output open-drain
 *   10: alternate function output push-pull
 *   11: alternate function output open-drain
 */
static uint32_t __attribute__ ((unused)) stm32f1_gpio_get_config_bits(
        STM32GPIOState *state, unsigned pin)
{
    return (stm32f1_gpio_get_pin_config(state, pin) >> 2) & 0x3;
}

/**
 * Modes are:
 * 00: input (reset)
 * 01: output, 10 MHz
 * 10: output, 2 MHz
 * 11: output, 50 MHz
 */
static uint32_t stm32f1_gpio_get_mode_bits(STM32GPIOState *state, unsigned pin)
{
    return stm32f1_gpio_get_pin_config(state, pin) & 0x3;
}

/**
 * Update the direction mask, cached for performance reasons.
 *
 * Must be called after each CR[LH] changes.
 *
 * index == 0 - CRL
 * index == 1 - CRH
 */
static void stm32f1_gpio_update_dir_mask(STM32GPIOState *s, int index)
{
    assert((index == 0) || (index == 1));

    unsigned start_pin = index * 8;
    unsigned pin_dir;

    for (int pin = start_pin; pin < start_pin + 8; pin++) {
        pin_dir = stm32f1_gpio_get_mode_bits(s, pin);
        /*
         * If the mode is 0, the pin is input.  Otherwise, it
         * is output.
         */
        if (pin_dir == 0) {
            s->dir_mask &= ~(1 << pin); /* Input pin */
        } else {
            s->dir_mask |= (1 << pin); /* Output pin */
        }
    }
}

/**
 * Write the ODR register and trigger interrupts for changed pins
 * (output only).
 *
 * The odr pointer is passed to make the function useful for other
 * families too.
 */
static void stm32_gpio_write_odr(STM32GPIOState *state, uint32_t *odr,
        uint32_t *idr, uint32_t new_value)
{
    assert(odr != NULL);

    /* Preserve old value, to compute changed bits */
    uint32_t old_value = *odr;

    /*
     * Update register value. Per documentation, the upper 16 bits
     * always read as 0.
     */
    *odr = new_value & 0x0000FFFF;

    /* Compute pins that changed value. */
    uint32_t changed = old_value ^ new_value;

    /* Filter changed pins that are outputs - do not touch input pins. */
    uint32_t changed_out = changed & state->dir_mask;

    if (changed_out) {
        for (int pin = 0; pin < STM32_GPIO_PIN_COUNT; pin++) {
            /*
             * If the value of this pin has changed, then update
             * the output IRQ.
             */
            if (changed_out & BIT(pin)) {
                qemu_set_irq(state->out_irq[pin], (*odr & BIT(pin)) ? 1 : 0);

                /*
                 * Andre Beckus used:
                 * state->busdev.parent_obj.gpios.lh_first->out[pin]
                 *
                 * The "irq_intercept_out" command in the qtest
                 * framework overwrites the out IRQ array in the
                 * NamedGPIOList structure (via the
                 * qemu_irq_intercept_out procedure).  So we need
                 * to reference this structure directly (rather than
                 * use our local state->out_irq array) in order for
                 * the unit tests to work. This is something of a hack,
                 * but I don't have a solution yet.
                 */
            }
        }
    }

    /*
     * For output pins, make them read the written value.
     *
     * TODO: check if there is anything special for open-drain pins.
     */
    uint32_t tmp = (*idr) & (~state->dir_mask);
    *idr = (tmp | (new_value & state->dir_mask)) & 0x0000FFFF;
}

/**
 * STM32F1 write 32-bits.
 */
static void stm32f1_gpio_write32(STM32GPIOState *state, uint32_t offset,
        uint32_t value, unsigned size)
{

    if (!stm32f1_rcc_is_gpio_enabled(state->rcc, state->port_index)) {
        return; /* Not enabled */
    }

    uint32_t tmp;
    uint32_t set_bits;
    uint32_t reset_bits;

    switch (offset) {
    case 0x00:
        state->u.f1.reg.crl = value;
        stm32f1_gpio_update_dir_mask(state, 0);
        break;

    case 0x04:
        state->u.f1.reg.crh = value;
        stm32f1_gpio_update_dir_mask(state, 1);
        break;

    case 0x0C:
        stm32_gpio_write_odr(state, &state->u.f1.reg.odr, &state->u.f1.reg.idr,
                value);
        break;

    case 0x10:
        set_bits = (value & 0x0000FFFF);
        reset_bits = ((value >> 16) & 0x0000FFFF);

        /* Clear the BR bits and set the BS bits. */
        tmp = (state->u.f1.reg.odr & (~reset_bits)) | set_bits;
        stm32_gpio_write_odr(state, &state->u.f1.reg.odr, &state->u.f1.reg.idr,
                tmp);
        break;

    case 0x14:
        reset_bits = (value & 0x0000FFFF);

        /* Clear the BR bits. */
        tmp = state->u.f1.reg.odr & ~reset_bits;
        stm32_gpio_write_odr(state, &state->u.f1.reg.odr, &state->u.f1.reg.idr,
                tmp);
        break;

    case 0x18:
        // TODO: implement it fully
        state->u.f1.reg.lckr = value & 0x0001FFFF;
        break;

    default:
        qemu_log_mask(LOG_UNIMP,
                "GPIO: Write of size %d at offset 0x%x not implemented\n", size,
                offset);
    }
}

/* ------------------------------------------------------------------------- */

static uint64_t stm32_gpio_read_callback(void *opaque, hwaddr addr,
        unsigned size)
{
    STM32GPIOState *state = (STM32GPIOState *) opaque;
    uint32_t offset = addr;

    if (size != 4) {
        qemu_log_mask(LOG_UNIMP,
                "GPIO: Read of size %d at offset 0x%x not implemented\n", size,
                offset);
        return 0;
    }

    const STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;

    switch (capabilities->family) {
    case STM32_FAMILY_F1:
        return stm32f1_gpio_read32(state, offset, size);
        break;

    default:
        qemu_log_mask(LOG_GUEST_ERROR,
                "GPIO: Read of size %d at offset 0x%x for unknown family %d\n",
                size, offset, capabilities->family);
    }

    return 0;
}

static void stm32_gpio_write_callback(void *opaque, hwaddr addr, uint64_t value,
        unsigned size)
{
    STM32GPIOState *state = (STM32GPIOState *) opaque;
    uint32_t offset = addr;

    if (size != 4) {
        qemu_log_mask(LOG_UNIMP,
                "GPIO: Write of size %d at offset 0x%x not implemented\n", size,
                offset);
        return;
    }

    const STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;

    switch (capabilities->family) {
    case STM32_FAMILY_F1:

        // TODO: check in RCC if GPIO is enabled.

        stm32f1_gpio_write32(state, offset, value, size);
        break;

    default:
        qemu_log_mask(LOG_GUEST_ERROR,
                "GPIO: Write of size %d at offset 0x%x for unknown family %d\n",
                size, offset, capabilities->family);
    }
}

static const MemoryRegionOps stm32_gpio_ops = {
    .read = stm32_gpio_read_callback,
    .write = stm32_gpio_write_callback,
    .valid.min_access_size = 4,
    .valid.max_access_size = 4,
    .endianness = DEVICE_NATIVE_ENDIAN, };

static void stm32_gpio_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    STM32GPIOState *state = STM32_GPIO_STATE(dev);

    const STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;

    state->dir_mask = 0;

    switch (capabilities->family) {
    case STM32_FAMILY_F1:
        state->u.f1.reg.crl = 0x44444444;
        state->u.f1.reg.crh = 0x44444444;
        state->u.f1.reg.idr = 0x00000000;
        state->u.f1.reg.odr = 0x00000000;
        state->u.f1.reg.lckr = 0x00000000;

        stm32f1_gpio_update_dir_mask(state, 0);
        stm32f1_gpio_update_dir_mask(state, 1);
        break;

    default:
        break;
    }

    // Disabled because it triggers false LED irqs at reset.
#if 0
    /* Clear all outgoing interrupts. */
    for (int pin = 0; pin < STM32_GPIO_PIN_COUNT; pin++) {
        qemu_irq_lower(state->out_irq[pin]);
    }
#endif

    // TODO: check if incoming interrupts need to be cleared too.
}

static void stm32_gpio_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32GPIOState *state = STM32_GPIO_STATE(dev);

    const STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;
    assert(capabilities != NULL);

    uint64_t size;
    hwaddr addr;
    const char *port_name;
    switch (capabilities->family) {
    case STM32_FAMILY_F1:
        size = 0x400;

        switch (state->port_index) {
        case STM32_GPIO_PORT_A:
            addr = 0x40010800;
            port_name = TYPE_STM32_GPIO "a";
            break;
        case STM32_GPIO_PORT_B:
            addr = 0x40010C00;
            port_name = TYPE_STM32_GPIO "b";
            break;
        case STM32_GPIO_PORT_C:
            addr = 0x40011000;
            port_name = TYPE_STM32_GPIO "c";
            break;
        case STM32_GPIO_PORT_D:
            addr = 0x40011400;
            port_name = TYPE_STM32_GPIO "d";
            break;
        case STM32_GPIO_PORT_E:
            addr = 0x40011800;
            port_name = TYPE_STM32_GPIO "e";
            break;
        case STM32_GPIO_PORT_F:
            addr = 0x40011C00;
            port_name = TYPE_STM32_GPIO "f";
            break;
        case STM32_GPIO_PORT_G:
            addr = 0x40012000;
            port_name = TYPE_STM32_GPIO "g";
            break;
        default:
            qemu_log_mask(LOG_GUEST_ERROR, "GPIO: Illegal GPIO port %d\n",
                    state->port_index);
            return;
        }
        break;

    default:
        size = 0; /* This will trigger an assertion to fail */
        addr = 0;
        port_name = TYPE_STM32_GPIO "?";
        break;
    }

    memory_region_init_io(&state->mmio, OBJECT(dev), &stm32_gpio_ops, state,
            port_name, size);
    sysbus_init_mmio(SYS_BUS_DEVICE(dev), &state->mmio);
    sysbus_mmio_map(SYS_BUS_DEVICE(dev), 0, addr);
}

/**
 * Callback fired when a GPIO input pin changes state (based
 * on an external stimulus from the machine).
 */
static void stm32_gpio_in_irq_handler(void *opaque, int n, int level)
{
    qemu_log_function_name();

    STM32GPIOState *state = STM32_GPIO_STATE(opaque);
    unsigned pin = n;

    assert(pin < STM32_GPIO_PIN_COUNT);

    const STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;
    assert(capabilities != NULL);

    /* Update internal pin state. */
    switch (capabilities->family) {
    case STM32_FAMILY_F1:
        if (level == 0) {
            state->u.f1.reg.idr &= ~(1 << pin); /* Clear IDR bit. */
        } else {
            state->u.f1.reg.idr |= (1 << pin); /* Set IDR bit. */
        }
        break;

    default:
        break;
    }

    /* Propagate the pin level to the input IRQs. */
    qemu_set_irq(state->in_irq[pin], level);
}

static void stm32_gpio_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    /*
     * Initialise incoming interrupts, received from machine
     * devices, like buttons.
     */
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);
    for (int pin = 0; pin < STM32_GPIO_PIN_COUNT; pin++) {
        sysbus_init_irq(sbd, &state->in_irq[pin]);
    }
    /* Handler for incoming interrupts */
    qdev_init_gpio_in(DEVICE(obj), stm32_gpio_in_irq_handler,
    STM32_GPIO_PIN_COUNT);

    /*
     * Initialise outgoing interrupts, propagated to exceptions
     * or machine devices like LEDs
     */
    qdev_init_gpio_out(DEVICE(obj), state->out_irq, STM32_GPIO_PIN_COUNT);

}

static Property stm32_gpio_properties[] = {
        DEFINE_PROP_STM32_GPIO_PORT_INDEX("port-index", STM32GPIOState,
                port_index, STM32_GPIO_PORT_UNDEFINED),
    DEFINE_PROP_END_OF_LIST() };

static void stm32_gpio_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_gpio_reset_callback;
    dc->realize = stm32_gpio_realize_callback;

    dc->props = stm32_gpio_properties;
}

static const TypeInfo stm32_gpio_type_info = {
    .name = TYPE_STM32_GPIO,
    .parent = TYPE_STM32_SYS_BUS_DEVICE,
    .instance_init = stm32_gpio_instance_init_callback,
    .instance_size = sizeof(STM32GPIOState),
    .class_init = stm32_gpio_class_init_callback,
    .class_size = sizeof(STM32GPIOClass) };

static void stm32_gpio_register_types(void)
{
    type_register_static(&stm32_gpio_type_info);
}

#if defined(CONFIG_GNU_ARM_ECLIPSE)
type_init(stm32_gpio_register_types);
#endif
