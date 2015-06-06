/*
 * STM32 MCU - flash control.
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

#include "hw/misc/stm32_flash.h"

/**
 * This file implements the STM32 flash control.
 *
 * The initial implementation is intended only to pass CMSIS initialisations.
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

/* STM32F1[LMH]D, STM32F1CL */

#define STM32F1_FLASH_ACR_READ_MASK             (0x0000003F)
#define STM32F1_FLASH_ACR_WRITE_MASK            (0x0000001F)

/**
 * STM32F1 flash memory interface, read 32-bits.
 */
static uint32_t stm32f1_flash_read32(STM32FlashState *state, uint32_t offset,
        unsigned size)
{
    uint32_t value;

    switch (offset) {
    case 0x00:
        value = (state->u.f1.reg.acr & STM32F1_FLASH_ACR_READ_MASK);
        value &= ~0x00000020; /* Clear PRFTBS Prefetch buffer status bit */
        /* PRFTBS follows PRFTBE */
        value |= ((state->u.f1.reg.acr & 0x00000010) << 1);
        return value;

    default:
        qemu_log_mask(LOG_UNIMP,
                "FLASH: Read of size %d at offset 0x%x not implemented\n", size,
                offset);
        break;
    }

    return 0;
}

/**
 * STM32F1 flash memory interface, write 32-bits.
 */
static void stm32f1_flash_write32(STM32FlashState *state, uint32_t offset,
        uint32_t value, unsigned size)
{
    // uint32_t tmp;

    switch (offset) {
    case 0x00:
        state->u.f1.reg.acr = (value & STM32F1_FLASH_ACR_WRITE_MASK);
        break;

    default:
        qemu_log_mask(LOG_UNIMP,
                "FLASH: Write of size %d at offset 0x%x not implemented\n",
                size, offset);
    }
}

/* ------------------------------------------------------------------------- */

static uint64_t stm32_flash_read(void *opaque, hwaddr addr, unsigned size)
{
    STM32FlashState *state = (STM32FlashState *) opaque;
    uint32_t offset = addr;

    if (size != 4) {
        qemu_log_mask(LOG_UNIMP,
                "FLASH: Read of size %d at offset 0x%x not implemented\n", size,
                offset);
        return 0;
    }

    STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;

    switch (capabilities->stm32.family) {
    case STM32_FAMILY_F1:
        return stm32f1_flash_read32(state, offset, size);
        break;

    default:
        qemu_log_mask(LOG_GUEST_ERROR,
                "FLASH: Read of size %d at offset 0x%x for unknown family %d\n",
                size, offset, capabilities->stm32.family);
    }

    return 0;
}

static void stm32_flash_write(void *opaque, hwaddr addr, uint64_t value,
        unsigned size)
{
    STM32FlashState *state = (STM32FlashState *) opaque;
    uint32_t offset = addr;

    if (size != 4) {
        qemu_log_mask(LOG_UNIMP,
                "FLASH: Write of size %d at offset 0x%x not implemented\n",
                size, offset);
        return;
    }

    STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;

    switch (capabilities->stm32.family) {
    case STM32_FAMILY_F1:
        stm32f1_flash_write32(state, offset, value, size);
        break;

    default:
        qemu_log_mask(LOG_GUEST_ERROR,
                "FLASH: Write of size %d at offset 0x%x for unknown family %d\n",
                size, offset, capabilities->stm32.family);
    }
}

static const MemoryRegionOps stm32_flash_ops = {
    .read = stm32_flash_read,
    .write = stm32_flash_write,
    .endianness = DEVICE_NATIVE_ENDIAN, };

/* ------------------------------------------------------------------------- */

static void stm32_flash_reset(DeviceState *dev)
{
    qemu_log_function_name();

    STM32FlashState *state = STM32_FLASH_STATE(dev);

    STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;

    switch (capabilities->stm32.family) {
    case STM32_FAMILY_F1:

        break;
    default:
        break;
    }
}

static void stm32_flash_realize(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32FlashState *state = STM32_FLASH_STATE(dev);

    STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;
    assert(capabilities != NULL);

    uint64_t size;
    switch (capabilities->stm32.family) {
    case STM32_FAMILY_F1:
        if (capabilities->stm32.f1.is_xd) {
            size = 0x57;
        } else {
            size = 0x24;
        }
        break;
    default:
        size = 0; /* This will trigger an assertion to fail */
    }

    memory_region_init_io(&state->mmio, OBJECT(dev), &stm32_flash_ops, state,
            TYPE_STM32_FLASH, size);

    sysbus_init_mmio(SYS_BUS_DEVICE(dev), &state->mmio);
    sysbus_mmio_map(SYS_BUS_DEVICE(dev), 0, 0x40022000);
}

static void stm32_flash_instance_init(Object *obj)
{
    qemu_log_function_name();

    // STM32FlashState *state = STM32_FLASH_STATE(obj);

}

static void stm32_flash_class_init(ObjectClass *klass, void *data)
{
    STM32FlashClass *nc = STM32_FLASH_CLASS(klass);
    DeviceClass *dc = DEVICE_CLASS(klass);

    nc->parent_realize = dc->realize;

    dc->reset = stm32_flash_reset;
    dc->realize = stm32_flash_realize;
}

static const TypeInfo stm32_flash_type_info = {
    .name = TYPE_STM32_FLASH,
    .parent = TYPE_STM32_SYS_BUS_DEVICE,
    .instance_init = stm32_flash_instance_init,
    .instance_size = sizeof(STM32FlashState),
    .class_init = stm32_flash_class_init };

static void stm32_flash_register_types(void)
{
    type_register_static(&stm32_flash_type_info);
}

#if defined(CONFIG_GNU_ARM_ECLIPSE)
type_init(stm32_flash_register_types)
#endif

/* ------------------------------------------------------------------------- */
