/*
 * STM32 MCU - XXX.
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

#include "hw/misc/stm32_xxx.h"

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

static uint64_t stm32_xxx_read(void *opaque, hwaddr addr, unsigned size)
{
    STM32XxxState *state = (STM32XxxState *) opaque;
    uint32_t offset = addr;

    return 0;
}

static void stm32_xxx_write(void *opaque, hwaddr addr, uint64_t value,
        unsigned size)
{
    STM32XxxState *state = (STM32XxxState *) opaque;
    uint32_t offset = addr;

}

static const MemoryRegionOps stm32_xxx_ops = {
    .read = stm32_xxx_read,
    .write = stm32_xxx_write,
    .endianness = DEVICE_NATIVE_ENDIAN, };

static void stm32_xxx_reset(DeviceState *dev)
{
    qemu_log_function_name();

    STM32XxxState *state = STM32_XXX_STATE(dev);
}

static void stm32_xxx_realize(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32XxxState *state = STM32_XXX_STATE(dev);

//    memory_region_init_io(&state->mmio, OBJECT(dev), &stm32_xxx_ops, state, "xxx",
//            0x1000);
//
//    sysbus_init_mmio(SYS_BUS_DEVICE(dev), &state->mmio);
//    sysbus_mmio_map(SYS_BUS_DEVICE(dev), 0, 0xE0000000);
}

static void stm32_xxx_instance_init(Object *obj)
{
    qemu_log_function_name();

    STM32XxxState *state = STM32_XXX_STATE(obj);

    // state->num_ports = DEFAULT_ITM_NUM_PORTS;
}

static void stm32_xxx_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_xxx_reset;
    dc->realize = stm32_xxx_realize;
}

static const TypeInfo stm32_xxx_type_info = {
    .name = TYPE_STM32_XXX,
    .parent = TYPE_STM32_SYS_BUS_DEVICE,
    .instance_init = stm32_xxx_instance_init,
    .instance_size = sizeof(STM32XxxState),
    .class_init = stm32_xxx_class_init,
    .class_size = sizeof(STM32XxxClass) };

static void stm32_xxx_register_types(void)
{
    type_register_static(&stm32_xxx_type_info);
}

#if defined(CONFIG_GNU_ARM_ECLIPSE)
type_init(stm32_xxx_register_types)
#endif
