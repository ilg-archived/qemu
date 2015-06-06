/*
 * STM32 - Common code for all sys bus devices.
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

#include "hw/misc/stm32_sys_bus_device.h"

static void stm32_sys_bus_device_instance_init(Object *obj)
{
    qemu_log_function_name();

//    STM32SysBusDevice *state = STM32_SYS_BUS_DEVICE_STATE(obj);
}

static const TypeInfo stm32_sys_bus_device_type_info = {
    .abstract = true,
    .name = TYPE_STM32_SYS_BUS_DEVICE,
    .parent = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(STM32SysBusDevice),
    .instance_init = stm32_sys_bus_device_instance_init };

static void stm32_types_init()
{
    type_register_static(&stm32_sys_bus_device_type_info);
}

#if defined(CONFIG_GNU_ARM_ECLIPSE)
type_init(stm32_types_init);
#endif
