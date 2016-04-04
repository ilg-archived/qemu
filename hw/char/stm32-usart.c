/*
 * STM32 USART
 *
 * Copyright (c) 2015 Dimitri L. <dimdimdimdim at gmx dot fr>
 * Includes substantial work from:
 * 	Copyright (c) 2015 Liviu Ionescu (stm32-gpio.c)
 * 	Copyright (c) 2014 Alistair Francis (stm32f2xx_usart.c)
 * 	Copyright (c) 2010 Andre Beckus (stm32-gpio.c)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "hw/char/stm32-usart.h"

#define USART_SR_TXE        (1 << 7)
#define USART_SR_TC         (1 << 6)
#define USART_SR_RXNE       (1 << 5)

#define USART_CR1_UE        (1 << 13)
#define USART_CR1_TXEIE     (1 << 7)
#define USART_CR1_TCIE      (1 << 6)
#define USART_CR1_RXNEIE    (1 << 5)
#define USART_CR1_TE        (1 << 3)
#define USART_CR1_RE        (1 << 2)

/* ------------------------------------------------------------------------- */

// TODO: rework reference to RCC to use links.
static bool stm32_usart_is_enabled(Object *obj)
{
    STM32USARTState *state = STM32_USART_STATE(obj);

    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    switch (capabilities->family) {

    case STM32_FAMILY_F4:
        if (state->port_index == STM32_USART_1) {
            if ((peripheral_register_read_value(state->rcc->f4.reg.apb2enr)
                    & 0x10) != 0) {
                return true;
            }
        }
        else if (state->port_index == STM32_USART_6) {
            if ((peripheral_register_read_value(state->rcc->f4.reg.apb2enr)
                    & 0x20) != 0) {
                return true;
            }
        }
        else {
            if ((peripheral_register_read_value(state->rcc->f4.reg.apb1enr)
                    & (0x20000 << (state->port_index - STM32_USART_2))) != 0) {
                return true;
            }
            break;
        }
        break;

    default:
        break;
    }

    return false;
}

/* ------------------------------------------------------------------------- */

static PeripheralInfo stm32_usart_info =
{
    .desc = "Universal synch asynch receiver transmitter (USART)",
    .registers =
        (PeripheralRegisterInfo[] ) {
            {
                .desc =
                        "USART status register (USART_SR)",
                .name = "sr",
                .offset_bytes = 0x00,
                /* datasheet indicates 0x00C00000, but I think it's wrong */
                .reset_value = 0x000000C0,
                .access_flags =
                PERIPHERAL_REGISTER_32BITS_ALL,
                .readable_bits = 0x000003FF,
                .writable_bits = 0x000003FF, },
            {
                .desc =
                        "USART data register (USART_DR)",
                .name = "dr",
                .offset_bytes = 0x04,
                .reset_value = 0x00000000,
                .access_flags =
                PERIPHERAL_REGISTER_32BITS_ALL,
                .readable_bits = 0x000001FF,
                .writable_bits = 0x000001FF, },
            {
                .desc =
                        "USART baud rate register (USART_BRR)",
                .name = "brr",
                .offset_bytes = 0x08,
                .reset_value = 0x00000000,
                .access_flags =
                PERIPHERAL_REGISTER_32BITS_ALL,
                .readable_bits = 0x0000FFFF,
                .writable_bits = 0x0000FFFF, },
            {
                .desc =
                        "USART control register 1 (USART_CR1)",
                .name = "cr1",
                .offset_bytes = 0x0C,
                .reset_value = 0x00000000,
                .access_flags =
                PERIPHERAL_REGISTER_32BITS_ALL,
                .readable_bits = 0x0000BFFF,
                .writable_bits = 0x0000BFFF, },
            {
                .desc =
                        "USART control register 2 (USART_CR2)",
                .name = "cr2",
                .offset_bytes = 0x10,
                .reset_value = 0x00000000,
                .access_flags =
                PERIPHERAL_REGISTER_32BITS_ALL,
                .readable_bits = 0x00007F6F,
                .writable_bits = 0x00007F6F, },
            {
                .desc =
                        "USART control register 3 (USART_CR3)",
                .name = "cr3",
                .offset_bytes = 0x14,
                .reset_value = 0x00000000,
                .access_flags =
                PERIPHERAL_REGISTER_32BITS_ALL,
                .writable_bits = 0x00000FFF,
                .readable_bits = 0x00000FFF, },
            {
                .desc =
                        "USART guard time and prescaler register (USART_GTPR)",
                .name = "gtpr",
                .offset_bytes = 0x18,
                .reset_value = 0x00000000,
                .access_flags =
                PERIPHERAL_REGISTER_32BITS_ALL,
                .writable_bits = 0x0000FFFF,
                .readable_bits = 0x0000FFFF, },
            { }, /**/
        } , /**/
};

static void stm32_usart_create_objects(Object *obj)
{
    STM32USARTState *state = STM32_USART_STATE(obj);

    peripheral_new_with_info(obj, NULL, &stm32_usart_info);

    state->reg.sr = cm_object_get_child_by_name(obj, "sr");
    state->reg.dr = cm_object_get_child_by_name(obj, "dr");
    state->reg.brr = cm_object_get_child_by_name(obj, "brr");
    state->reg.cr1 = cm_object_get_child_by_name(obj, "cr1");
    state->reg.cr2 = cm_object_get_child_by_name(obj, "cr2");
    state->reg.cr3 = cm_object_get_child_by_name(obj, "cr3");
    state->reg.gtpr = cm_object_get_child_by_name(obj, "gtpr");
}

/* ------------------------------------------------------------------------- */

static int smt32_usart_get_irq_vector(STM32USARTState *state)
{
    switch (state->port_index) {
    case STM32_USART_1:
        return STM32_EXCP_USART_1;
    case STM32_USART_2:
        return STM32_EXCP_USART_2;
    case STM32_USART_3:
        return STM32_EXCP_USART_3;
    case STM32_UART_4:
        return STM32_EXCP_UART_4;
    case STM32_UART_5:
        return STM32_EXCP_UART_5;
    case STM32_USART_6:
        return STM32_EXCP_USART_6;
    default:
        return 1023; /* Whatever... */
    }
}

static int stm32_usart_can_receive(void *obj)
{
    STM32USARTState *state = STM32_USART_STATE((Object *)obj);

    int32_t sr = peripheral_register_get_raw_value(state->reg.sr);
    if (!(sr & USART_SR_RXNE)) {
        return 1;
    }

    return 0;
}

static void stm32_usart_receive(void *obj, const uint8_t *buf, int size)
{
    STM32USARTState *state = STM32_USART_STATE((Object *)obj);

    int32_t cr1 = peripheral_register_get_raw_value(state->reg.cr1);

    if (!stm32_usart_is_enabled(obj)
            || !(cr1 & USART_CR1_UE) || !(cr1 & USART_CR1_RE)) {
        /* USART not enabled - drop the chars */
        return;
    }

    peripheral_register_set_raw_value(state->reg.dr, *buf);
    peripheral_register_or_raw_value(state->reg.sr, USART_SR_RXNE);

    if (cr1 & USART_CR1_RXNEIE) {
        cortexm_nvic_set_pending(state->nvic,
                smt32_usart_get_irq_vector(state));
    }
}

static void stm32_usart_dr_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value)
{
    STM32USARTState *state = STM32_USART_STATE(periph);
    unsigned char ch;
    
    int32_t cr1 = peripheral_register_get_raw_value(state->reg.cr1);

    if ((cr1 & USART_CR1_UE) && (cr1 & USART_CR1_TE)) {
        if (state->chr) {
            ch = value;
            qemu_chr_fe_write_all(state->chr, &ch, 1);
        }
        /* transmission is immediately complete */
        peripheral_register_or_raw_value(state->reg.sr,
                USART_SR_TC | USART_SR_TXE);
        if ((cr1 & USART_CR1_TXEIE) || (cr1 & USART_CR1_TCIE)) {
            cortexm_nvic_set_pending(state->nvic,
                    smt32_usart_get_irq_vector(state));
        }
    }
}

static peripheral_register_t stm32_usart_dr_pre_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32USARTState *state = STM32_USART_STATE(periph);

    peripheral_register_and_raw_value(state->reg.sr, ~USART_SR_RXNE);
//    if (state->chr) {
//        qemu_chr_accept_input(state->chr);
//    }

    // TODO: return the value to be returned by read
    return '?';
}

static void stm32_usart_cr1_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value)
{
    STM32USARTState *state = STM32_USART_STATE(periph);

    int32_t sr = peripheral_register_get_raw_value(state->reg.sr);

    if (((value & USART_CR1_RXNEIE) && (sr & USART_SR_RXNE)) ||
            ((value & USART_CR1_TXEIE) && (sr & USART_SR_TXE))  ||
            ((value & USART_CR1_TCIE) && (sr & USART_SR_TC))) {
        cortexm_nvic_set_pending(state->nvic,
                smt32_usart_get_irq_vector(state));
    }
}

/* ------------------------------------------------------------------------- */

static void stm32_usart_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    /* STM32USARTState *state = STM32_USART_STATE(obj); */

    /* FIXME use a qdev chardev prop instead of qemu_char_get_next_serial() */
    /* state->chr = qemu_char_get_next_serial(); */
}

static void stm32_usart_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /* No need to call parent realize(). */

    STM32USARTState *state = STM32_USART_STATE(dev);

    const STM32Capabilities *capabilities =
    STM32_USART_STATE(state)->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    /* Must be defined before creating registers. */
    cm_object_property_set_int(obj, 4, "register-size-bytes");

    /* TODO: get it from MCU */
    cm_object_property_set_bool(obj, true, "is-little-endian");

    uint32_t size;
    hwaddr addr;

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (state->port_index > STM32_USART_6) {
            qemu_log_mask(LOG_GUEST_ERROR, "USART: Illegal USART port %d\n",
                    state->port_index);
            return;
        }

        size = 0x400;
        if (state->port_index == STM32_USART_1) {
            addr = 0x40011000;
        }
        else if (state->port_index == STM32_USART_6) {
            addr = 0x40011400;
        }
        else {
            addr = 0x40004400 + (state->port_index - STM32_USART_2) * size;
        }

        break;

    default:

        size = 0; /* This will trigger an assertion to fail. */
        addr = 0;

        break;
    }

    cm_object_property_set_int(obj, addr, "mmio-address");
    cm_object_property_set_int(obj, size, "mmio-size-bytes");

    stm32_usart_create_objects(obj);
    
    /* Register callbacks. */
    peripheral_register_set_pre_read(state->reg.dr,
            &stm32_usart_dr_pre_read_callback);
    peripheral_register_set_post_write(state->reg.dr,
            &stm32_usart_dr_post_write_callback);
    peripheral_register_set_post_write(state->reg.cr1,
            &stm32_usart_cr1_post_write_callback);

    /* Chardev callbacks. */
    if (state->chr) {
        qemu_chr_add_handlers(state->chr, stm32_usart_can_receive,
                              stm32_usart_receive, NULL, obj);
    }
    
    /* Call parent realize(). */
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_USART)) {
        return;
    }
}

static void stm32_usart_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    /* No need to call parent reset(). */

    STM32USARTState *state = STM32_USART_STATE(dev);

    /* Call parent reset(). */
    cm_device_parent_reset(dev, TYPE_STM32_USART);

    /* FIXME: We should certainly clear the interrupt state.
     * Don't know how to do that: implement cortexm_nvic_clear_pending ??? */

    if (state->chr) {
        qemu_chr_accept_input(state->chr);
    }
}

static Property stm32_usart_properties[] = {
        DEFINE_PROP_CHR("chardev", STM32USARTState, chr),
        DEFINE_PROP_INT32_TYPE("port-index", STM32USARTState, port_index,
                STM32_USART_PORT_UNDEFINED, stm32_usart_index_t),
        DEFINE_PROP_NON_VOID_PTR("rcc", STM32USARTState, rcc, STM32RCCState *),
        DEFINE_PROP_NON_VOID_PTR("nvic", STM32USARTState,
                nvic, CortexMNVICState *),
        DEFINE_PROP_NON_VOID_PTR("capabilities", STM32USARTState,
                capabilities, const STM32Capabilities *),
    DEFINE_PROP_END_OF_LIST() };

static void stm32_usart_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_usart_reset_callback;
    dc->realize = stm32_usart_realize_callback;

    dc->props = stm32_usart_properties;

    /* Reason: instance_init() method uses qemu_char_get_next_serial()
    dc->cannot_instantiate_with_device_add_yet = true;*/

    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_usart_is_enabled;
}

static const TypeInfo stm32_usart_type_info = {
    .name = TYPE_STM32_USART,
    .parent = TYPE_STM32_USART_PARENT,
    .instance_init = stm32_usart_instance_init_callback,
    .instance_size = sizeof(STM32USARTState),
    .class_init = stm32_usart_class_init_callback,
    .class_size = sizeof(STM32USARTClass) /**/
};

static void stm32_usart_register_types(void)
{
    type_register_static(&stm32_usart_type_info);
}

type_init(stm32_usart_register_types);

