/*
 * STM32 - Common code for all sys bus devices.
 *
 * Copyright (c) 2015 Liviu Ionescu.
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

#include <hw/cortexm/stm32/sys-bus-device.h>
#include <hw/cortexm/helper.h>

/* ------------------------------------------------------------------------- */

static Property stm32_sys_bus_device_properties[] = {
        DEFINE_PROP_NON_VOID_PTR("capabilities", STM32SysBusDeviceState,
                capabilities, const STM32Capabilities *),
    DEFINE_PROP_END_OF_LIST() };

static void stm32_sys_bus_device_class_init_callback(ObjectClass *klass,
        void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->props = stm32_sys_bus_device_properties;
}

static const TypeInfo stm32_sys_bus_device_type_info = {
    .abstract = true,
    .name = TYPE_STM32_SYS_BUS_DEVICE,
    .parent = TYPE_STM32_SYS_BUS_DEVICE_PARENT,
    .instance_size = sizeof(STM32SysBusDeviceState),
    .class_init = stm32_sys_bus_device_class_init_callback,
    .class_size = sizeof(STM32SysBusDeviceClass)
/**/
};

static void stm32_types_init(void)
{
    type_register_static(&stm32_sys_bus_device_type_info);
}

type_init(stm32_types_init);

// ----------------------------------------------------------------------------
