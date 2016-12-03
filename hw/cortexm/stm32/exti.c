/*
 * STM32 MCU - EXTI (external interrupts controller) emulation.
 *
 * Copyright (c) 2016 Liviu Ionescu.
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

#include <hw/cortexm/stm32/exti.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>

/*
 * This file implements the STM32 EXTI.
 *
 * Not yet implemented:
 * - event mode; EMR ignored, no events are generated.
 */

/* ----- Private ----------------------------------------------------------- */

/*
 * Called for each pin changed in the board (like buttons)
 * and for GPIO output changes.
 */
static void stm32f_exti_in_irq_handler(void *opaque, int index, int level)
{
    qemu_log_mask(LOG_FUNC, "%s(%d,%d) \n", __FUNCTION__, index, level);

    STM32EXTIState *state = STM32_EXTI_STATE(opaque);
    assert(index < STM32_EXTI_MAX_NUM);
    uint32_t mask = (1 << index);

    if ((peripheral_register_read_value(state->reg.imr) & mask) != 0) {
        if (((level
                && ((peripheral_register_read_value(state->reg.rtsr) & mask)
                        != 0))
                || (!level
                        && ((peripheral_register_read_value(state->reg.ftsr)
                                & mask) != 0)))) {

            /* Set the corresponding bit in the pending register.
             * Must be cleared by the application when the interrupt
             * is acknowledged. */
            peripheral_register_or_raw_value(state->reg.pr, mask);

#if 0
            qemu_log_mask(LOG_FUNC, "%s(%d,%d) nvic\n", __FUNCTION__,
                    index, level);
#endif

            // Raise the outgoing interrupt, connected to NVIC.
            cm_irq_raise(state->irq_out[index]);
        }
    }
}

/*
 * Pass only bits corresponding to enabled interrupts.
 */
static peripheral_register_t stm32f_exti_swier_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32EXTIState *state = STM32_EXTI_STATE(periph);
    peripheral_register_t imr_value = peripheral_register_read_value(
            state->reg.imr);

    return (full_value & imr_value);
}

/*
 * Set pending bits programmatically. Raising bits pend interrupts.
 * Lowering bits does nothing.
 */
static void stm32f_exti_swier_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32EXTIState *state = STM32_EXTI_STATE(periph);
    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(
            reg);
    /* Bits that were 0 and now are 1. */
    uint32_t raised = (~prev_value) & full_value;

    uint32_t mask = 1;
    int i;
    for (i = 0; i < state->num_exti; ++i, mask <<= 1) {
        if ((raised & mask) != 0) {
            stm32f_exti_in_irq_handler(reg, i, 1);
        }
    }
}

/*
 * Implement 'rc_w1', clear bits by writing 1.
 */
static peripheral_register_t stm32f_exti_pr_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32EXTIState *state = STM32_EXTI_STATE(periph);
    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(
            state->reg.pr);

    peripheral_register_t imr_value = peripheral_register_read_value(
            state->reg.imr);

    /* Compute enabled bits that were 1 and were requested to clear. */
    uint32_t acknowledged = (imr_value & prev_value & full_value);

    uint32_t mask = 1;
    int i;
    for (i = 0; i < state->num_exti; ++i, mask <<= 1) {
        if ((acknowledged & mask) != 0) {
            /* Notify NVIC that the interrupt was acknowledged. */
            cm_irq_lower(state->irq_out[i]);
        }
    }

    /* Clear bits. */
    return (prev_value & (~full_value));
}

/* ------------------------------------------------------------------------- */

/* STM32F051XX */

#if 0
static PeripheralInfo stm32f051xx_exti_info = {
    .desc = "External interrupt/event controller (PWR)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_WORD,

    .registers = (PeripheralRegisterInfo[] ) {
        {
            .desc = "Interrupt mask register (EXTI_IMR)",
            .name = "imr",
            .offset_bytes = 0x00,
            /*
             * Reset value:
             * - 0x0FF4 0000 (STM32F03x devices)
             * - 0x7FF4 0000 (STM32F04x devices)
             * - 0x0F94 0000 (STM32F05x devices)
             * - 0x7F84 0000 (STM32F07x and STM32F09x devices)
             */
            .reset_value = 0x0F940000,
            .readable_bits = 0xFFFFFFFF,
            .writable_bits = 0xFFFFFFFF,
            /**/
        },
        {
            .desc = "Event mask register (EXTI_EMR)",
            .name = "emr",
            .offset_bytes = 0x04,
            .reset_value = 0x00000000,
            .readable_bits = 0x007BFFFF,
            .writable_bits = 0x007BFFFF,
            /**/
        },
        {
            .desc = "Rising trigger selection register (EXTI_RTSR)",
            .name = "rtsr",
            .offset_bytes = 0x08,
            .reset_value = 0x00000000,
            .readable_bits = 0x007BFFFF,
            .writable_bits = 0x007BFFFF,
            /**/
        },
        {
            .desc = "Falling trigger selection register (EXTI_FTSR)",
            .name = "ftsr",
            .offset_bytes = 0x0C,
            .reset_value = 0x00000000,
            .readable_bits = 0x007BFFFF,
            .writable_bits = 0x007BFFFF,
            /**/
        },
        {
            .desc = "Software interrupt event register (EXTI_SWIER)",
            .name = "swier",
            .offset_bytes = 0x10,
            .reset_value = 0x00000000,
            .readable_bits = 0x007BFFFF,
            .writable_bits = 0x007BFFFF,
            /**/
        },
        {
            .desc = "Pending register (EXTI_PR)",
            .name = "pr",
            .offset_bytes = 0x14,
            .reset_value = 0x00000000,
            // The manual states 'Reset value is undefined',
            // but SVD gives the 0x0 value.
            // .reset_mask = 0x00000000,
            .readable_bits = 0x007BFFFF,
            .writable_bits = 0x007BFFFF,
            /* rc_w1 - Software can read as well as clear this bit
             * by writing 1. Writing ‘0’ has no effect on the bit
             * value. */
        },
        {}, /**/
    }, /**/
};
#endif

/* ------------------------------------------------------------------------- */

/* STM32F10xx */

#if 0
static PeripheralInfo stm32f1_exti_info = {
    .desc = "External interrupt/event controller (PWR)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_WORD,

    .registers = (PeripheralRegisterInfo[] ) {
        {
            .desc = "Interrupt mask register (EXTI_IMR)",
            .name = "imr",
            .offset_bytes = 0x00,
            .reset_value = 0x00000000,
            .readable_bits = 0x000FFFFF,
            .writable_bits = 0x000FFFFF,
            /**/
        },
        {
            .desc = "Event mask register (EXTI_EMR)",
            .name = "emr",
            .offset_bytes = 0x04,
            .reset_value = 0x00000000,
            .readable_bits = 0x000FFFFF,
            .writable_bits = 0x000FFFFF,
            /**/
        },
        {
            .desc = "Rising trigger selection register (EXTI_RTSR)",
            .name = "rtsr",
            .offset_bytes = 0x08,
            .reset_value = 0x00000000,
            .readable_bits = 0x000FFFFF,
            .writable_bits = 0x000FFFFF,
            /**/
        },
        {
            .desc = "Falling trigger selection register (EXTI_FTSR)",
            .name = "ftsr",
            .offset_bytes = 0x0C,
            .reset_value = 0x00000000,
            .readable_bits = 0x000FFFFF,
            .writable_bits = 0x000FFFFF,
            /**/
        },
        {
            .desc = "Software interrupt event register (EXTI_SWIER)",
            .name = "swier",
            .offset_bytes = 0x10,
            .reset_value = 0x00000000,
            .readable_bits = 0x000FFFFF,
            .writable_bits = 0x000FFFFF,
            /**/
        },
        {
            .desc = "Pending register (EXTI_PR)",
            .name = "pr",
            .offset_bytes = 0x14,
            .reset_value = 0x00000000,
            // The manual states 'Reset value is undefined',
            // but SVD gives the 0x0 value.
            // .reset_mask = 0x00000000,
            .readable_bits = 0x000FFFFF,
            .writable_bits = 0x000FFFFF,
            /* rc_w1 - Software can read as well as clear this bit
             * by writing 1. Writing ‘0’ has no effect on the bit
             * value. */
        },
        {}, /**/
    }, /**/
};
#endif

/* ------------------------------------------------------------------------- */

/* STM32F401x_BC does not have EXTI19 and EXTI20,
 * will probably use the 411xx definitions. */

/* ------------------------------------------------------------------------- */

/* STM32F4_01_57_XX, STM32F4_23_XX_ */

#if 0
static PeripheralInfo stm32f4xxxx_exti_info = {
    .desc = "External interrupt/event controller (PWR)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_ALL,

    .registers = (PeripheralRegisterInfo[] ) {
        {
            .desc = "Interrupt mask register (EXTI_IMR)",
            .name = "imr",
            .offset_bytes = 0x00,
            .reset_value = 0x00000000,
            .readable_bits = 0x007FFFFF,
            .writable_bits = 0x007FFFFF,
            /**/
        },
        {
            .desc = "Event mask register (EXTI_EMR)",
            .name = "emr",
            .offset_bytes = 0x04,
            .reset_value = 0x00000000,
            .readable_bits = 0x007FFFFF,
            .writable_bits = 0x007FFFFF,
            /**/
        },
        {
            .desc = "Rising trigger selection register (EXTI_RTSR)",
            .name = "rtsr",
            .offset_bytes = 0x08,
            .reset_value = 0x00000000,
            .readable_bits = 0x007FFFFF,
            .writable_bits = 0x007FFFFF,
            /**/
        },
        {
            .desc = "Falling trigger selection register (EXTI_FTSR)",
            .name = "ftsr",
            .offset_bytes = 0x0C,
            .reset_value = 0x00000000,
            .readable_bits = 0x007FFFFF,
            .writable_bits = 0x007FFFFF,
            /**/
        },
        {
            .desc = "Software interrupt event register (EXTI_SWIER)",
            .name = "swier",
            .offset_bytes = 0x10,
            .reset_value = 0x00000000,
            .readable_bits = 0x007FFFFF,
            .writable_bits = 0x007FFFFF,
            /**/
        },
        {
            .desc = "Pending register (EXTI_PR)",
            .name = "pr",
            .offset_bytes = 0x14,
            .reset_value = 0x00000000,
            // The manual states 'Reset value is undefined',
            // but SVD gives the 0x0 value.
            // .reset_mask = 0x00000000,
            .readable_bits = 0x007FFFFF,
            .writable_bits = 0x007FFFFF,
            /* rc_w1 - Software can read as well as clear this bit
             * by writing 1. Writing ‘0’ has no effect on the bit
             * value. */
        },
        {}, /**/
    }, /**/
};
#endif

/* ------------------------------------------------------------------------- */

/* STM32F411_xx */

#if 0
static PeripheralInfo stm32f411xx_exti_info = {
    .desc = "External interrupt/event controller (PWR)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_ALL,

    .registers = (PeripheralRegisterInfo[] ) {
        {
            .desc = "Interrupt mask register (EXTI_IMR)",
            .name = "imr",
            .offset_bytes = 0x00,
            .reset_value = 0x00000000,
            .readable_bits = 0x0067FFFF,
            .writable_bits = 0x0067FFFF,
            /**/
        },
        {
            .desc = "Event mask register (EXTI_EMR)",
            .name = "emr",
            .offset_bytes = 0x04,
            .reset_value = 0x00000000,
            .readable_bits = 0x0067FFFF,
            .writable_bits = 0x0067FFFF,
            /**/
        },
        {
            .desc = "Rising trigger selection register (EXTI_RTSR)",
            .name = "rtsr",
            .offset_bytes = 0x08,
            .reset_value = 0x00000000,
            .readable_bits = 0x0067FFFF,
            .writable_bits = 0x0067FFFF,
            /**/
        },
        {
            .desc = "Falling trigger selection register (EXTI_FTSR)",
            .name = "ftsr",
            .offset_bytes = 0x0C,
            .reset_value = 0x00000000,
            .readable_bits = 0x0067FFFF,
            .writable_bits = 0x0067FFFF,
            /**/
        },
        {
            .desc = "Software interrupt event register (EXTI_SWIER)",
            .name = "swier",
            .offset_bytes = 0x10,
            .reset_value = 0x00000000,
            .readable_bits = 0x0067FFFF,
            .writable_bits = 0x0067FFFF,
            /**/
        },
        {
            .desc = "Pending register (EXTI_PR)",
            .name = "pr",
            .offset_bytes = 0x14,
            .reset_value = 0x00000000,
            // The manual states 'Reset value is undefined',
            // but SVD gives the 0x0 value.
            // .reset_mask = 0x00000000,
            .readable_bits = 0x0067FFFF,
            .writable_bits = 0x0067FFFF,
            /* rc_w1 - Software can read as well as clear this bit
             * by writing 1. Writing ‘0’ has no effect on the bit
             * value. */
        },
        {}, /**/
    }, /**/
};
#endif

/* ------------------------------------------------------------------------- */

static void stm32_exti_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32EXTIState *state = STM32_EXTI_STATE(obj);

    cm_object_property_add_uint32(obj, "num_exti", &state->num_exti);
    state->num_exti = 0;

    /* capabilities are not yet available. */

    /*
     * Incoming interrupts. There is only one set of incoming,
     * all GPIOs are connected here, but each pin can have only
     * one source. To simplify things (hopefully), the multiplexer
     * is implemented in each GPIO.
     */
    cm_irq_init_in(DEVICE(obj), stm32f_exti_in_irq_handler, IRQ_EXTI_IN,
    STM32_EXTI_MAX_NUM);

    /*
     * Outgoing interrupts, will be later connected to NVIC.
     */
    cm_irq_init_out(DEVICE(obj), state->irq_out, IRQ_EXTI_OUT,
    STM32_EXTI_MAX_NUM);

}

static void stm32_exti_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /*
     * Parent realize() is called after setting properties and creating
     * registers.
     */

    STM32MCUState *mcu = stm32_mcu_get();

    STM32EXTIState *state = STM32_EXTI_STATE(dev);
    /* First thing first: get capabilities from MCU, needed everywhere. */
    state->capabilities = mcu->capabilities;

    /* Also keep a local pointer, to access them easier. */
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    /*
     * Creating the memory region in the parent class will trigger
     * an assertion if zro address or size.
     */
    uint32_t size = 0;
    hwaddr addr = 0;
    switch (capabilities->family) {
    case STM32_FAMILY_F0:
        addr = 0x40010400;
        size = 0x400;
        break;

    case STM32_FAMILY_F1:
    case STM32_FAMILY_F4:
        addr = 0x40013C00;
        size = 0x400;
        break;

    default:
        assert(false);
        break;
    }

    cm_object_property_set_int(obj, addr, "mmio-address");
    cm_object_property_set_int(obj, size, "mmio-size-bytes");

    assert(capabilities->num_exti <= STM32_EXTI_MAX_NUM);
    cm_object_property_set_int(obj, capabilities->num_exti, "num_exti");

    JSON_Object *info;

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        assert(capabilities->num_exti == 23);
        if (capabilities->f0.is_51xx) {
            info = cm_json_parser_get_peripheral(mcu->family_json,
                    "stm32f051:exti");
            peripheral_add_properties_and_children2(obj, info);
        } else {
            assert(false);
        }
        break;

    case STM32_FAMILY_F1:

        assert(capabilities->num_exti == 20);
        info = cm_json_parser_get_peripheral(mcu->family_json,
                "stm32f1xx:exti");
        peripheral_add_properties_and_children2(obj, info);
        break;

    case STM32_FAMILY_F4:

        assert(capabilities->num_exti == 23);
        if (capabilities->f4.is_01_57_xx || capabilities->f4.is_23_xxx) {

            info = cm_json_parser_get_peripheral(mcu->family_json,
                    "stm32f4xx:exti");
            peripheral_add_properties_and_children2(obj, info);

        } else if (capabilities->f4.is11xx) {

            info = cm_json_parser_get_peripheral(mcu->family_json,
                    "stm32f411:exti");
            peripheral_add_properties_and_children2(obj, info);

        } else {
            assert(false);
        }
        break;

    default:
        break;
    }

    state->reg.imr = cm_object_get_child_by_name(obj, "imr");
    state->reg.emr = cm_object_get_child_by_name(obj, "emr");
    state->reg.rtsr = cm_object_get_child_by_name(obj, "rtsr");
    state->reg.ftsr = cm_object_get_child_by_name(obj, "ftsr");
    state->reg.swier = cm_object_get_child_by_name(obj, "swier");
    state->reg.pr = cm_object_get_child_by_name(obj, "pr");

    peripheral_register_set_pre_write(state->reg.swier,
            stm32f_exti_swier_pre_write_callback);
    peripheral_register_set_post_write(state->reg.swier,
            stm32f_exti_swier_post_write_callback);

    peripheral_register_set_pre_write(state->reg.pr,
            stm32f_exti_pr_pre_write_callback);

    DeviceState *nvic = DEVICE(cm_device_by_name(DEVICE_PATH_CORTEXM_NVIC));

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_51xx) {
            cm_irq_connect(dev, IRQ_EXTI_OUT, 0, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI0_1_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 1, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI0_1_IRQn);

            cm_irq_connect(dev, IRQ_EXTI_OUT, 2, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI2_3_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 3, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI2_3_IRQn);

            cm_irq_connect(dev, IRQ_EXTI_OUT, 4, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 5, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 6, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 7, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 8, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 9, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 10, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 11, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 12, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 13, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 14, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 15, nvic, IRQ_NVIC_IN,
                    STM32F051XX_EXTI4_15_IRQn);

            // TODO add 16 - 23;

        }
        break;

    case STM32_FAMILY_F1:

        if (capabilities->f1.is_md || capabilities->f1.is_cl) {

            cm_irq_connect(dev, IRQ_EXTI_OUT, 0, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI0_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 1, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI1_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 2, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI2_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 3, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI3_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 4, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI4_IRQn);

            cm_irq_connect(dev, IRQ_EXTI_OUT, 5, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI9_5_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 6, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI9_5_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 7, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI9_5_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 8, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI9_5_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 9, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI9_5_IRQn);

            cm_irq_connect(dev, IRQ_EXTI_OUT, 10, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI15_10_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 11, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI15_10_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 12, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI15_10_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 13, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI15_10_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 14, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI15_10_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 15, nvic, IRQ_NVIC_IN,
                    STM32F10X_MD_EXTI15_10_IRQn);

            // TODO add 16 - 20; if different for STM32F10X_CL, extend if
        }

        break;

    case STM32_FAMILY_F4:

        if (capabilities->f4.is_01_57_xx || capabilities->f4.is_23_xxx) {

            cm_irq_connect(dev, IRQ_EXTI_OUT, 0, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI0_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 1, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI1_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 2, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI2_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 3, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI3_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 4, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI4_IRQn);

            cm_irq_connect(dev, IRQ_EXTI_OUT, 5, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI9_5_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 6, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI9_5_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 7, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI9_5_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 8, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI9_5_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 9, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI9_5_IRQn);

            cm_irq_connect(dev, IRQ_EXTI_OUT, 10, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 11, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 12, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 13, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 14, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 15, nvic, IRQ_NVIC_IN,
                    STM32F4_01_57_XX_EXTI15_10_IRQn);

            // TODO add 16 - 22; if different for STM32F4_23_XX, extend if

        } else if (capabilities->f4.is11xx) {

            cm_irq_connect(dev, IRQ_EXTI_OUT, 0, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI0_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 1, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI1_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 2, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI2_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 3, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI3_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 4, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI4_IRQn);

            cm_irq_connect(dev, IRQ_EXTI_OUT, 5, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI9_5_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 6, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI9_5_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 7, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI9_5_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 8, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI9_5_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 9, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI9_5_IRQn);

            cm_irq_connect(dev, IRQ_EXTI_OUT, 10, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 11, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 12, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 13, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 14, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI15_10_IRQn);
            cm_irq_connect(dev, IRQ_EXTI_OUT, 15, nvic, IRQ_NVIC_IN,
                    STM32F411XX_EXTI15_10_IRQn);

            // TODO add 16,17,18,21,22
        }

        break;

    default:
        break;
    }

    cm_object_property_set_str(obj, "exti", "name");

    /* Call parent realize(). */
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_EXTI)) {
        return;
    }
}

static void stm32_exti_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    /* Call parent reset(). */
    cm_device_parent_reset(dev, TYPE_STM32_EXTI);
}

static void stm32_exti_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_exti_reset_callback;
    dc->realize = stm32_exti_realize_callback;
}

static const TypeInfo stm32_exti_type_info = {
    .name = TYPE_STM32_EXTI,
    .parent = TYPE_STM32_EXTI_PARENT,
    .instance_init = stm32_exti_instance_init_callback,
    .instance_size = sizeof(STM32EXTIState),
    .class_init = stm32_exti_class_init_callback,
    .class_size = sizeof(STM32EXTIClass) };

static void stm32_exti_register_types(void)
{
    type_register_static(&stm32_exti_type_info);

#if 0
    peripheral_serialize_info("f051-exti.json", "stm32f051:exti", &stm32f051xx_exti_info);
    peripheral_serialize_info("f1xx-exti.json", "stm32f1xx:exti", &stm32f1_exti_info);
    peripheral_serialize_info("f4xx-exti.json", "stm32f4xx:exti", &stm32f4xxxx_exti_info);
    peripheral_serialize_info("f411-exti.json", "stm32f411:exti", &stm32f411xx_exti_info);
#endif
}

type_init(stm32_exti_register_types);

/* ------------------------------------------------------------------------- */

