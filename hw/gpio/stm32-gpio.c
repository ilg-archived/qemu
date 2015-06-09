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

/**
 * This file implements the STM32 GPIO.
 *
 * The initial implementation is intended only to blink a LED.
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

/**
 * STM32F1 read 32-bits.
 */
static uint32_t stm32f1_gpio_read32(STM32GPIOState *state, uint32_t offset,
        unsigned size)
{
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
 * STM32F1 write 32-bits.
 */
static void stm32f1_gpio_write32(STM32GPIOState *state, uint32_t offset,
        uint32_t value, unsigned size)
{
    uint32_t tmp;
    uint32_t set_bits;
    uint32_t reset_bits;

    switch (offset) {
    case 0x00:
        state->u.f1.reg.crl = value;
        break;
    case 0x04:
        state->u.f1.reg.crh = value;
        break;
    case 0x0C:
        state->u.f1.reg.odr = value & 0x0000FFFF;
        break;
    case 0x10:
        set_bits = (value & 0x0000FFFF);
        reset_bits = ((value >> 16) & 0x0000FFFF);

        /* Clear the BR bits and set the BS bits. */
        tmp = (state->u.f1.reg.odr & (~reset_bits)) | set_bits;
        state->u.f1.reg.odr = tmp & 0x0000FFFF;
        break;

    case 0x14:
        reset_bits = (value & 0x0000FFFF);

        /* Clear the BR bits. */
        tmp = state->u.f1.reg.odr & ~reset_bits;
        state->u.f1.reg.odr = tmp & 0x0000FFFF;
        break;

    case 0x18:
        state->u.f1.reg.lckr = value & 0x0001FFFF;
        break;

    default:
        qemu_log_mask(LOG_UNIMP,
                "GPIO: Write of size %d at offset 0x%x not implemented\n", size,
                offset);
    }
}

/* ------------------------------------------------------------------------- */

static uint64_t stm32_gpio_read(void *opaque, hwaddr addr, unsigned size)
{
    STM32GPIOState *state = (STM32GPIOState *) opaque;
    uint32_t offset = addr;

    if (size != 4) {
        qemu_log_mask(LOG_UNIMP,
                "GPIO: Read of size %d at offset 0x%x not implemented\n", size,
                offset);
        return 0;
    }

    STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;

    switch (capabilities->stm32.family) {
    case STM32_FAMILY_F1:
        return stm32f1_gpio_read32(state, offset, size);
        break;

    default:
        qemu_log_mask(LOG_GUEST_ERROR,
                "GPIO: Read of size %d at offset 0x%x for unknown family %d\n",
                size, offset, capabilities->stm32.family);
    }

    return 0;
}

static void stm32_gpio_write(void *opaque, hwaddr addr, uint64_t value,
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

    STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;

    switch (capabilities->stm32.family) {
    case STM32_FAMILY_F1:
        stm32f1_gpio_write32(state, offset, value, size);
        break;

    default:
        qemu_log_mask(LOG_GUEST_ERROR,
                "GPIO: Write of size %d at offset 0x%x for unknown family %d\n",
                size, offset, capabilities->stm32.family);
    }
}

static const MemoryRegionOps stm32_gpio_ops = {
    .read = stm32_gpio_read,
    .write = stm32_gpio_write,
    .endianness = DEVICE_NATIVE_ENDIAN, };

static void stm32_gpio_reset(DeviceState *dev)
{
    qemu_log_function_name();

    STM32GPIOState *state = STM32_GPIO_STATE(dev);

    STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;

    switch (capabilities->stm32.family) {
    case STM32_FAMILY_F1:
        state->u.f1.reg.crl = 0x44444444;
        state->u.f1.reg.crh = 0x44444444;
        state->u.f1.reg.idr = 0x00000000;
        state->u.f1.reg.odr = 0x00000000;
        state->u.f1.reg.lckr = 0x00000000;
        break;
    default:
        break;
    }
}

static void stm32_gpio_realize(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32GPIOState *state = STM32_GPIO_STATE(dev);

    STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;
    assert(capabilities != NULL);

    uint64_t size;
    hwaddr addr;
    const char *port_name;
    switch (capabilities->stm32.family) {
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

static void stm32_gpio_instance_init(Object *obj)
{
    qemu_log_function_name();

    // STM32GPIOState *state = STM32_GPIO_STATE(obj);

}

static Property stm32_gpio_properties[] = {
        DEFINE_PROP_STM32_GPIO_PORT_INDEX("port-index", STM32GPIOState,
                port_index, STM32_GPIO_PORT_UNDEFINED),
    DEFINE_PROP_END_OF_LIST() };

static void stm32_gpio_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_gpio_reset;
    dc->realize = stm32_gpio_realize;

    dc->props = stm32_gpio_properties;
}

static const TypeInfo stm32_gpio_type_info = {
    .name = TYPE_STM32_GPIO,
    .parent = TYPE_STM32_SYS_BUS_DEVICE,
    .instance_init = stm32_gpio_instance_init,
    .instance_size = sizeof(STM32GPIOState),
    .class_init = stm32_gpio_class_init,
    .class_size = sizeof(STM32GPIOClass) };

static void stm32_gpio_register_types(void)
{
    type_register_static(&stm32_gpio_type_info);
}

#if defined(CONFIG_GNU_ARM_ECLIPSE)
type_init(stm32_gpio_register_types)
#endif
