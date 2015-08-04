/*
 * STM32 MCU - GPIO emulation.
 *
 * Copyright (c) 2015 Liviu Ionescu.
 * Copyright (c) 2010 Andre Beckus.
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
#include "hw/arm/cortexm-helper.h"

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
 * References:
 * - ST CD00171190.pdf, Doc ID 13902 Rev 15, "RM0008 Reference Manual,
 * STM32F101xx, STM32F102xx, STM32F103xx, STM32F105xx and STM32F107xx
 * advanced ARM®-based 32-bit MCUs"
 *
 * - Doc ID 018909 Rev 6, "ST RM0090 Reference manual,
 * STM32F405xx/07xx, STM32F415xx/17xx, STM32F42xxx and STM32F43xxx
 * advanced ARM-based 32-bit MCUs"
 *
 * - Doc ID 026448 Rev 1, "ST RM0383 Reference manual,
 * STM32F411xC/E advanced ARM-based 32-bit MCUs"
 *
 * All STM32 reference manuals available from:
 * http://www.st.com/stonline/stappl/resourceSelector/\
 * app?page=fullResourceSelector&doctype=reference_manual&FamilyID=141
 */

/* ------------------------------------------------------------------------- */

static void stm32_gpio_update_idr(STM32GPIOState *state, Object *idr,
        uint16_t new_odr);

static void stm32_gpio_set_odr_irqs(STM32GPIOState *state, uint16_t old_odr,
        uint16_t new_odr);

static void stm32_gpio_update_odr_and_idr(STM32GPIOState *state, Object *odr,
        Object *idr, uint16_t new_value);

/* ------------------------------------------------------------------------- */

// TODO: rework reference to RCC to use links.
static bool stm32_gpio_is_enabled(Object *obj)
{
#if 1
    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    switch (capabilities->family) {
    case STM32_FAMILY_F1:

        if ((peripheral_register_read_value(state->rcc->f1.reg.apb2enr)
                & (0x4 << state->port_index)) != 0) {
            return true;
        }
        break;

    case STM32_FAMILY_F4:

        if ((peripheral_register_read_value(state->rcc->f4.reg.ahb1enr)
                & (0x1 << state->port_index)) != 0) {
            return true;
        }
        break;

    default:
        break;
    }

    return false;
#else
    return true;
#endif
}

/* ===== F1 ================================================================ */

/* STM32F1[LMHX]D, STM32F1CL */

static void stm32f1_gpio_update_dir_mask(STM32GPIOState *state, int index);

/* ------------------------------------------------------------------------- */

/* The peripheral registers have to be accessed only by words (32-bit). */

static void stm32f1_gpio_crl_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    stm32f1_gpio_update_dir_mask(state, 0);
}

static void stm32f1_gpio_crh_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    stm32f1_gpio_update_dir_mask(state, 1);
}

static void stm32f1_gpio_odr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    Object *odr = state->f1.reg.odr;
    assert(odr);

    uint16_t prev_value = peripheral_register_get_raw_prev_value(odr);
    uint16_t new_value = peripheral_register_get_raw_value(odr);

    stm32_gpio_set_odr_irqs(state, prev_value, new_value);
    stm32_gpio_update_idr(state, state->f1.reg.idr, new_value);
}

static void stm32f1_gpio_bsrr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    Object *odr = state->f1.reg.odr;
    assert(odr);

    uint32_t new_value;
    uint32_t bits_to_set;
    uint32_t bits_to_reset;

    /* Value is word (32-bits) and can be used directly. */
    bits_to_set = (value & 0x0000FFFF);
    bits_to_reset = ((value >> 16) & 0x0000FFFF);

    /* Clear the BR bits and set the BS bits. */
    new_value = (peripheral_register_get_raw_value(odr) & (~bits_to_reset))
            | bits_to_set;
    stm32_gpio_update_odr_and_idr(state, odr, state->f1.reg.idr, new_value);
}

static void stm32f1_gpio_brr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    Object *odr = state->f1.reg.odr;
    assert(odr);

    /* Value is word (32-bits) and can be used directly. */
    uint32_t new_value;
    uint32_t bits_to_reset;
    bits_to_reset = (value & 0x0000FFFF);

    /* Clear the BR bits. */
    new_value = peripheral_register_get_raw_value(odr) & ~bits_to_reset;
    stm32_gpio_update_odr_and_idr(state, odr, state->f1.reg.idr, new_value);
}

static PeripheralInfo stm32f1_gpio_info = {
    .desc = "General-purpose I/Os (GPIO)",

    .registers = (PeripheralRegisterInfo[] ) {
                {
                    .desc = "Port configuration register low (GPIOx_CRL)",
                    .name = "crl",
                    .offset_bytes = 0x00,
                    .reset_value = 0x44444444,
                    .access_flags = PERIPHERAL_REGISTER_32BITS_WORD, },
                {
                    .desc = "Port configuration register low (GPIOx_CRH)",
                    .name = "crh",
                    .offset_bytes = 0x04,
                    .reset_value = 0x44444444,
                    .access_flags = PERIPHERAL_REGISTER_32BITS_WORD, },
                {
                    .desc = "Port input data register (GPIOx_IDR)",
                    .name = "idr",
                    .offset_bytes = 0x08,
                    .reset_value = 0x00000000,
                    .reset_mask = 0xFFFF0000,
                    .access_flags = PERIPHERAL_REGISTER_32BITS_WORD,
                    .readable_bits = 0x0000FFFF,
                    .rw_mode = REGISTER_RW_MODE_READ, },
                {
                    .desc = "Port output data register (GPIOx_ODR)",
                    .name = "odr",
                    .offset_bytes = 0x0C,
                    .reset_value = 0x00000000,
                    .access_flags = PERIPHERAL_REGISTER_32BITS_WORD,
                    .writable_bits = 0x0000FFFF,
                    .rw_mode = REGISTER_RW_MODE_WRITE, },
                {
                    .desc = "Port bit set/reset register (GPIOx_BSRR)",
                    .name = "bsrr",
                    .offset_bytes = 0x10,
                    .reset_value = 0x00000000,
                    .access_flags = PERIPHERAL_REGISTER_32BITS_WORD,
                    .writable_bits = 0xFFFFFFFF,
                    .rw_mode = REGISTER_RW_MODE_WRITE, },
                {
                    .desc = "Port bit reset register (GPIOx_BRR) ",
                    .name = "brr",
                    .offset_bytes = 0x14,
                    .reset_value = 0x00000000,
                    .access_flags = PERIPHERAL_REGISTER_32BITS_WORD,
                    .writable_bits = 0x0000FFFF,
                    .rw_mode = REGISTER_RW_MODE_WRITE, },
                {
                    .desc = "Port configuration lock register (GPIOx_LCKR)",
                    .name = "lckr",
                    .offset_bytes = 0x18,
                    .reset_value = 0x0001FFFF,
                    .access_flags = PERIPHERAL_REGISTER_32BITS_WORD,
                    .readable_bits = 0x0001FFFF,
                    .writable_bits = 0x0001FFFF, },
                { }, /**/
            } , /**/
};

static void stm32f1_gpio_create_objects(Object *obj)
{
    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    peripheral_new_with_info(obj, NULL, &stm32f1_gpio_info);

    state->f1.reg.crl = cm_object_get_child_by_name(obj, "crl");
    state->f1.reg.crh = cm_object_get_child_by_name(obj, "crh");
    state->f1.reg.idr = cm_object_get_child_by_name(obj, "idr");
    state->f1.reg.odr = cm_object_get_child_by_name(obj, "odr");
    state->f1.reg.bsrr = cm_object_get_child_by_name(obj, "bsrr");
    state->f1.reg.brr = cm_object_get_child_by_name(obj, "brr");
    state->f1.reg.lckr = cm_object_get_child_by_name(obj, "lckr");
}
/* ------------------------------------------------------------------------- */

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
    uint64_t cr_64 =
            ((uint64_t) peripheral_register_get_raw_value(state->f1.reg.crh)
                    << 32)
                    | (peripheral_register_get_raw_value(state->f1.reg.crl)
                            & 0xFFFFFFFF);
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
static void stm32f1_gpio_update_dir_mask(STM32GPIOState *state, int index)
{
    assert((index == 0) || (index == 1));

    unsigned start_pin = index * 8;
    unsigned pin_dir;
    int pin;

    for (pin = start_pin; pin < start_pin + 8; pin++) {
        pin_dir = stm32f1_gpio_get_mode_bits(state, pin);
        /*
         * If the mode is 0, the pin is input.  Otherwise, it
         * is output.
         */
        if (pin_dir == 0) {
            state->dir_mask &= ~(1 << pin); /* Input pin */
        } else {
            state->dir_mask |= (1 << pin); /* Output pin */
        }
    }
}

/* ===== F4 ================================================================ */

/* STM32F4[01][57]xx, STM32F4[23]xxx, STM32F411xx */

uint32_t stm32f4_gpio_get_config_bits(uint32_t value, uint32_t bit);
static void stm32f4_gpio_update_dir_mask(STM32GPIOState *state);

/* ------------------------------------------------------------------------- */

static void stm32f4_gpio_moder_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    stm32f4_gpio_update_dir_mask(state);
}

static void stm32f4_gpio_odr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    Object *odr = state->f4.reg.odr;
    assert(odr);

    uint16_t prev_value = peripheral_register_get_raw_prev_value(odr);
    uint16_t new_value = peripheral_register_get_raw_value(odr);

    stm32_gpio_set_odr_irqs(state, prev_value, new_value);
    stm32_gpio_update_idr(state, state->f4.reg.idr, new_value);
}

static void stm32f4_gpio_bsrr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value)
{
    STM32GPIOState *state = STM32_GPIO_STATE(periph);

    Object *odr = state->f4.reg.odr;
    assert(odr);

    uint32_t new_value;
    uint32_t bits_to_set;
    uint32_t bits_to_reset;

    /* Value is word (32-bits). */
    bits_to_set = (value & 0x0000FFFF);
    bits_to_reset = ((value >> 16) & 0x0000FFFF);

    /* Clear the BR bits and set the BS bits. */
    new_value = (peripheral_register_get_raw_value(odr) & (~bits_to_reset))
            | bits_to_set;
    stm32_gpio_update_odr_and_idr(state, odr, state->f4.reg.idr, new_value);
}

static PeripheralInfo stm32f4_gpio_info =
        {
            .desc = "General-purpose I/Os (GPIO)",

            .registers =
                    (PeripheralRegisterInfo[] ) {
                                {
                                    .desc =
                                            "GPIO port mode register (GPIOx_MODER)",
                                    .name = "moder",
                                    .offset_bytes = 0x00,
                                    /* 0xA8000000 for port A, 0x00000280 for port B */
                                    .reset_value = 0x00000000,
                                    .access_flags =
                                    PERIPHERAL_REGISTER_32BITS_ALL, },
                                {
                                    .desc =
                                            "GPIO port output type register (GPIOx_OTYPER)",
                                    .name = "otyper",
                                    .offset_bytes = 0x04,
                                    .reset_value = 0x00000000,
                                    .access_flags =
                                    PERIPHERAL_REGISTER_32BITS_ALL,
                                    .readable_bits = 0x0000FFFF,
                                    .writable_bits = 0x0000FFFF, },
                                {
                                    .desc =
                                            "GPIO port output speed register (GPIOx_OSPEEDR)",
                                    .name = "ospeeder",
                                    .offset_bytes = 0x08,
                                    .reset_value = 0x00000000, /* 0x0000 00C0 for port B */
                                    .access_flags =
                                    PERIPHERAL_REGISTER_32BITS_ALL, },
                                {
                                    .desc =
                                            "GPIO port pull-up/pull-down register (GPIOx_PUPDR)",
                                    .name = "pupdr",
                                    .offset_bytes = 0x0C,
                                    /* 0x640000C0 for port A, 0x00000100 for port B */
                                    .reset_value = 0x00000000,
                                    .access_flags =
                                    PERIPHERAL_REGISTER_32BITS_ALL, },
                                {
                                    .desc =
                                            "GPIO Port input data register (GPIOx_IDR)",
                                    .name = "idr",
                                    .offset_bytes = 0x10,
                                    .reset_value = 0x00000000,
                                    .reset_mask = 0xFFFF0000,
                                    .access_flags =
                                    PERIPHERAL_REGISTER_32BITS_ALL,
                                    .readable_bits = 0x0000FFFF,
                                    .rw_mode = REGISTER_RW_MODE_READ, },
                                {
                                    .desc =
                                            "GPIO Port output data register (GPIOx_ODR)",
                                    .name = "odr",
                                    .offset_bytes = 0x14,
                                    .reset_value = 0x00000000,
                                    .access_flags =
                                    PERIPHERAL_REGISTER_32BITS_ALL,
                                    .writable_bits = 0x0000FFFF,
                                    .readable_bits = 0x0000FFFF, },
                                {
                                    .desc =
                                            "GPIO Port bit set/reset register (GPIOx_BSRR) ",
                                    .name = "bsrr",
                                    .offset_bytes = 0x18,
                                    .reset_value = 0x00000000,
                                    .access_flags =
                                    PERIPHERAL_REGISTER_32BITS_ALL,
                                    .rw_mode = REGISTER_RW_MODE_WRITE, },
                                {
                                    .desc =
                                            "GPIO alternate function low register (GPIOx_AFRL)",
                                    .name = "afrl",
                                    .offset_bytes = 0x20,
                                    .reset_value = 0x00000000,
                                    .access_flags =
                                    PERIPHERAL_REGISTER_32BITS_ALL, },
                                {
                                    .desc =
                                            "GPIO alternate function low register (GPIOx_AFRH)",
                                    .name = "afrh",
                                    .offset_bytes = 0x24,
                                    .reset_value = 0x00000000,
                                    .access_flags =
                                    PERIPHERAL_REGISTER_32BITS_ALL, },
                                {
                                    .desc =
                                            "GPIO Port configuration lock register (GPIOx_LCKR)",
                                    .name = "lckr",
                                    .offset_bytes = 0x1C,
                                    .reset_value = 0x00000000,
                                    .access_flags =
                                    PERIPHERAL_REGISTER_32BITS_WORD,
                                    .readable_bits = 0x0001FFFF,
                                    .writable_bits = 0x0001FFFF, },
                                { }, /**/
                            } , /**/
        };

static void stm32f4_gpio_create_objects(Object *obj)
{
    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    peripheral_new_with_info(obj, NULL, &stm32f4_gpio_info);

    state->f4.reg.moder = cm_object_get_child_by_name(obj, "moder");
    state->f4.reg.otyper = cm_object_get_child_by_name(obj, "otyper");
    state->f4.reg.ospeeder = cm_object_get_child_by_name(obj, "ospeeder");
    state->f4.reg.pupdr = cm_object_get_child_by_name(obj, "pupdr");
    state->f4.reg.idr = cm_object_get_child_by_name(obj, "idr");
    state->f4.reg.odr = cm_object_get_child_by_name(obj, "odr");
    state->f4.reg.bsrr = cm_object_get_child_by_name(obj, "bsrr");
    state->f4.reg.afrl = cm_object_get_child_by_name(obj, "afrl");
    state->f4.reg.afrh = cm_object_get_child_by_name(obj, "afrh");
    state->f4.reg.lckr = cm_object_get_child_by_name(obj, "lckr");
}

/* ------------------------------------------------------------------------- */

/**
 * The F4 family has more uniform configuration registers, each
 * register bit has a 2-bits slice in a register.
 */
uint32_t stm32f4_gpio_get_config_bits(uint32_t value, uint32_t bit)
{
    assert(bit < 16);
    return (value >> (bit * 2)) & 0x3;
}

static void stm32f4_gpio_update_dir_mask(STM32GPIOState *state)
{
    uint32_t moder = peripheral_register_get_raw_value(state->f4.reg.moder);

    /* Fully recompute the direction mask. */
    int bit;
    uint32_t mode;
    for (bit = 0; bit < 16; bit++) {
        mode = stm32f4_gpio_get_config_bits(moder, bit);
        /*
         * If the mode is 1, the bit is output. Otherwise, it
         * is input or has alternate functions.
         */
        if (mode == 1) {
            state->dir_mask |= (1 << bit); /* Output pin */
        } else {
            state->dir_mask &= ~(1 << bit); /* Input pin */
        }
    }
}

/* ========================================================================= */

/**
 * Write the ODR register and trigger interrupts for changed pins
 * (output only).
 *
 * The odr pointer is passed to make the function useful for other
 * families too.
 */
static void stm32_gpio_update_odr_and_idr(STM32GPIOState *state, Object *odr,
        Object *idr, uint16_t new_value)
{
    assert(odr);

    /* Preserve old value, to compute changed bits */
    uint16_t old_value = peripheral_register_get_raw_value(odr);

    /*
     * Update register value. Per documentation, the upper 16 bits
     * always read as 0, so write is used, to apply the mask.
     */
    peripheral_register_write_value(odr, new_value);

    stm32_gpio_set_odr_irqs(state, old_value, new_value);
    stm32_gpio_update_idr(state, idr, new_value);
}

static void stm32_gpio_set_odr_irqs(STM32GPIOState *state, uint16_t old_odr,
        uint16_t new_odr)
{
    /* Compute pins that changed value. */
    uint16_t changed = old_odr ^ new_odr;

    /* Filter changed pins that are outputs - do not touch input pins. */
    uint16_t changed_out = changed & state->dir_mask;

    uint16_t mask = 1;
    if (changed_out) {
        int pin;
        for (pin = 0; pin < STM32_GPIO_PIN_COUNT; pin++, mask <<= 1) {
            /*
             * If the value of this pin has changed, then update
             * the output IRQ.
             */
            if (changed_out & mask) {
                qemu_set_irq(state->out_irq[pin], (new_odr & mask) ? 1 : 0);

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
}

/**
 * For output pins, make them read back the written value.
 *
 * TODO: check if there is anything special for open-drain pins.
 */
static void stm32_gpio_update_idr(STM32GPIOState *state, Object *idr,
        uint16_t new_odr)
{
    assert(idr);

    /* Clear output bits. */
    peripheral_register_and_raw_value(idr, ~state->dir_mask);
    /* Copy output bits from ODR. */
    peripheral_register_or_raw_value(idr, (new_odr & state->dir_mask));
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

    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *idr;
    /* Update internal pin state. */
    switch (capabilities->family) {
    case STM32_FAMILY_F1:

        idr = state->f1.reg.idr;
        break;

    case STM32_FAMILY_F4:

        idr = state->f4.reg.idr;
        break;

    default:
        break;
    }

    if (level == 0) {
        /* Clear the IDR bit. */
        peripheral_register_and_raw_value(idr, ~(1 << pin));
    } else {
        /* Set the IDR bit. */
        peripheral_register_or_raw_value(idr, (1 << pin));
    }

    /* Propagate the pin level to the input IRQs. */
    qemu_set_irq(state->in_irq[pin], level);
}

/* ------------------------------------------------------------------------- */

static void stm32_gpio_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32GPIOState *state = STM32_GPIO_STATE(obj);

    /*
     * Initialise incoming interrupts, received from machine
     * devices, like buttons.
     */
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);
    int pin;
    for (pin = 0; pin < STM32_GPIO_PIN_COUNT; pin++) {
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

static void stm32_gpio_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /* No need to call parent realize(). */

    STM32GPIOState *state = STM32_GPIO_STATE(dev);

    const STM32Capabilities *capabilities =
    STM32_GPIO_STATE(state)->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    /* Must be defined before creating registers. */
    cm_object_property_set_int(obj, 4, "register-size-bytes");

    /* TODO: get it from MCU */
    cm_object_property_set_bool(obj, true, "is-little-endian");

    uint32_t size;
    hwaddr addr;

    switch (capabilities->family) {
    case STM32_FAMILY_F1:

        if (state->port_index > STM32_GPIO_PORT_G) {
            qemu_log_mask(LOG_GUEST_ERROR, "GPIO: Illegal GPIO port %d\n",
                    state->port_index);
            return;
        }

        size = 0x400;
        addr = 0x40010800 + (state->port_index - STM32_GPIO_PORT_A) * size;

        break;

    case STM32_FAMILY_F4:

        if (state->port_index > STM32_GPIO_PORT_K) {
            qemu_log_mask(LOG_GUEST_ERROR, "GPIO: Illegal GPIO port %d\n",
                    state->port_index);
            return;
        }

        size = 0x400;
        addr = 0x40020000 + (state->port_index - STM32_GPIO_PORT_A) * size;

        break;

    default:

        size = 0; /* This will trigger an assertion to fail. */
        addr = 0;

        break;
    }

    cm_object_property_set_int(obj, addr, "mmio-address");
    cm_object_property_set_int(obj, size, "mmio-size-bytes");

    switch (capabilities->family) {
    case STM32_FAMILY_F1:
        stm32f1_gpio_create_objects(obj);

        /* Add callbacks. */
        peripheral_register_set_post_write(state->f1.reg.crl,
                &stm32f1_gpio_crl_post_write_callback);
        peripheral_register_set_post_write(state->f1.reg.crh,
                &stm32f1_gpio_crh_post_write_callback);
        peripheral_register_set_post_write(state->f1.reg.odr,
                &stm32f1_gpio_odr_post_write_callback);
        peripheral_register_set_post_write(state->f1.reg.bsrr,
                &stm32f1_gpio_bsrr_post_write_callback);
        peripheral_register_set_post_write(state->f1.reg.brr,
                &stm32f1_gpio_brr_post_write_callback);

        break;

    case STM32_FAMILY_F4:
        stm32f4_gpio_create_objects(obj);

        /* Add callbacks. */
        peripheral_register_set_post_write(state->f4.reg.moder,
                &stm32f4_gpio_moder_post_write_callback);
        peripheral_register_set_post_write(state->f4.reg.odr,
                &stm32f4_gpio_odr_post_write_callback);
        peripheral_register_set_post_write(state->f4.reg.bsrr,
                &stm32f4_gpio_bsrr_post_write_callback);

        break;

    default:
        break;
    }

    /* Call parent realize(). */
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_GPIO)) {
        return;
    }
}

static void stm32_gpio_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    /* No need to call parent reset(). */

    STM32GPIOState *state = STM32_GPIO_STATE(dev);

    const STM32Capabilities *capabilities =
    STM32_GPIO_STATE(state)->capabilities;

    state->dir_mask = 0;

    /* Call parent reset(). */
    cm_device_parent_reset(dev, TYPE_STM32_RCC);

    switch (capabilities->family) {
    case STM32_FAMILY_F1:

        stm32f1_gpio_update_dir_mask(state, 0);
        stm32f1_gpio_update_dir_mask(state, 1);
        break;

    case STM32_FAMILY_F4:

        stm32f4_gpio_update_dir_mask(state);
        break;

    default:
        break;
    }
}

static Property stm32_gpio_properties[] = {
        DEFINE_PROP_INT32_TYPE("port-index", STM32GPIOState, port_index,
                STM32_GPIO_PORT_UNDEFINED, stm32_gpio_index_t),
        DEFINE_PROP_NON_VOID_PTR("rcc", STM32GPIOState, rcc, STM32RCCState *),
        DEFINE_PROP_NON_VOID_PTR("capabilities", STM32GPIOState,
                capabilities, const STM32Capabilities *),
    DEFINE_PROP_END_OF_LIST() };

static void stm32_gpio_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_gpio_reset_callback;
    dc->realize = stm32_gpio_realize_callback;

    dc->props = stm32_gpio_properties;

    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_gpio_is_enabled;
}

static const TypeInfo stm32_gpio_type_info = {
    .name = TYPE_STM32_GPIO,
    .parent = TYPE_STM32_GPIO_PARENT,
    .instance_init = stm32_gpio_instance_init_callback,
    .instance_size = sizeof(STM32GPIOState),
    .class_init = stm32_gpio_class_init_callback,
    .class_size = sizeof(STM32GPIOClass) /**/
};

static void stm32_gpio_register_types(void)
{
    type_register_static(&stm32_gpio_type_info);
}

type_init(stm32_gpio_register_types);

/* ------------------------------------------------------------------------- */
