/*
 * STM32 MCU - XXX emulation.
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

#include "hw/misc/stm32-xxx.h"

/**
 * This file implements the STM32 XXX.
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


/* ----- Private ----------------------------------------------------------- */


/* STM32F1[LMHX]D, STM32F1CL */

/**
 * STM32F1 read 32-bits.
 */
static uint32_t stm32f1_xxx_read32(STM32XxxState *state, uint32_t offset,
        unsigned size)
{
    uint32_t value;

    switch (offset) {
    case 0x00:
      value = state->u.f1.reg.cr;
      return value;
      
    default:
        qemu_log_mask(LOG_UNIMP,
                "XXX: Read of size %d at offset 0x%x not implemented\n", size,
                offset);
        break;
    }

    return 0;
}

/**
 * STM32F1 write 32-bits.
 */
static void stm32f1_xxx_write32(STM32XxxState *state, uint32_t offset,
        uint32_t value, unsigned size)
{
    uint32_t tmp;

    switch (offset) {
    case 0x00:
        state->u.f1.reg.cr = (value & 0xFFFFFFFF);
        break;

    default:
        qemu_log_mask(LOG_UNIMP,
                "XXX: Write of size %d at offset 0x%x not implemented\n", size,
                offset);
    }
}

/* ------------------------------------------------------------------------- */

static uint64_t stm32_xxx_read(void *opaque, hwaddr addr, unsigned size)
{
    STM32XxxState *state = (STM32XxxState *) opaque;
    uint32_t offset = addr;

    if (size != 4) {
        qemu_log_mask(LOG_UNIMP,
                "XXX: Read of size %d at offset 0x%x not implemented\n", size,
                offset);
        return 0;
    }

    STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;

    switch (capabilities->stm32.family) {
    case STM32_FAMILY_F1:
        return stm32f1_xxx_read32(state, offset, size);
        break;

    default:
        qemu_log_mask(LOG_GUEST_ERROR,
                "XXX: Read of size %d at offset 0x%x for unknown family %d\n",
                size, offset, capabilities->stm32.family);
    }

    return 0;
}

static void stm32_xxx_write(void *opaque, hwaddr addr, uint64_t value,
        unsigned size)
{
    STM32XxxState *state = (STM32XxxState *) opaque;
    uint32_t offset = addr;

    if (size != 4) {
        qemu_log_mask(LOG_UNIMP,
                "XXX: Write of size %d at offset 0x%x not implemented\n", size,
                offset);
        return;
    }

    STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;

    switch (capabilities->stm32.family) {
    case STM32_FAMILY_F1:
        stm32f1_xxx_write32(state, offset, value, size);
        break;

    default:
        qemu_log_mask(LOG_GUEST_ERROR,
                "RCC: Write of size %d at offset 0x%x for unknown family %d\n",
                size, offset, capabilities->stm32.family);
    }
}

static const MemoryRegionOps stm32_xxx_ops = {
    .read = stm32_xxx_read,
    .write = stm32_xxx_write,
    .endianness = DEVICE_NATIVE_ENDIAN, };

/* ------------------------------------------------------------------------- */


static void stm32_xxx_instance_init(Object *obj)
{
    qemu_log_function_name();

    STM32XxxState *state = STM32_XXX_STATE(obj);

    /* ... */
}

static void stm32_xxx_realize(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /* Call parent realize(). */
    if (!cm_parent_realize(dev, errp, TYPE_STM32_XXX)) {
        return;
    }

    STM32XxxState *state = STM32_XXX_STATE(dev);

    STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;
    assert(capabilities != NULL);

    uint64_t size;
    hwaddr addr;
    switch (capabilities->stm32.family) {
    case STM32_FAMILY_F1:
        size = 0x3FF;
        addr = 0xE0000000;
        break;
    default:
        size = 0; /* This will trigger an assertion to fail */
    }

    memory_region_init_io(&state->mmio, OBJECT(dev), &stm32_gpio_ops, state, TYPE_STM32_XXX,
            size);

    sysbus_init_mmio(SYS_BUS_DEVICE(dev), &state->mmio);
    sysbus_mmio_map(SYS_BUS_DEVICE(dev), 0, addr);
  
    /* ... */
}

static void stm32_xxx_reset(DeviceState *dev)
{
    qemu_log_function_name();

    /* Call parent reset(). */
    cm_parent_reset(dev, TYPE_STM32_XXX);
  
    STM32XxxState *state = STM32_XXX_STATE(dev);
    /* ... */
}

static void stm32_xxx_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_xxx_reset;
    dc->realize = stm32_xxx_realize;
}

static const TypeInfo stm32_xxx_type_info = {
    .name = TYPE_STM32_XXX,
    .parent = TYPE_STM32_XXX_PARENT,
    .instance_init = stm32_xxx_instance_init,
    .instance_size = sizeof(STM32XxxState),
    .class_init = stm32_xxx_class_init,
    .class_size = sizeof(STM32XxxClass) };

static void stm32_xxx_register_type(void)
{
    type_register_static(&stm32_xxx_type_info);
}

#if defined(CONFIG_GNU_ARM_ECLIPSE)
type_init(stm32_xxx_register_types)
#endif

/* ------------------------------------------------------------------------- */

