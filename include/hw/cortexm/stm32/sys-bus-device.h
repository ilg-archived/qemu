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

#ifndef STM32_SYS_BUS_DEVICE_H_
#define STM32_SYS_BUS_DEVICE_H_

#include "qemu/osdep.h"

#include <hw/cortexm/stm32/capabilities.h>
#include "hw/sysbus.h"

/*
 *  Parent type for all STM32 peripherals.
 *
 * Define a field to differentiate between different STM32 families.
 */

// ----------------------------------------------------------------------------
#define TYPE_STM32_SYS_BUS_DEVICE "stm32-sys-bus-device"

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_SYS_BUS_DEVICE_PARENT TYPE_SYS_BUS_DEVICE
typedef SysBusDeviceClass STM32SysBusDeviceParentClass;
typedef SysBusDevice STM32SysBusDeviceParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_SYS_BUS_DEVICE_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32SysBusDeviceClass, (obj), TYPE_STM32_SYS_BUS_DEVICE)
#define STM32_SYS_BUS_DEVICE_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32SysBusDeviceClass, (klass), TYPE_STM32_SYS_BUS_DEVICE)

typedef struct {
    // private:
    STM32SysBusDeviceParentClass parent_class;
    // public:
} STM32SysBusDeviceClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_SYS_BUS_DEVICE_STATE(obj) \
    OBJECT_CHECK(STM32SysBusDeviceState, (obj), TYPE_STM32_SYS_BUS_DEVICE)

typedef struct {
    // private:
    STM32SysBusDeviceParentState parent_obj;
    // public:

    const STM32Capabilities *capabilities;
} STM32SysBusDeviceState;

// ----------------------------------------------------------------------------

#endif /* STM32_SYS_BUS_DEVICE_H_ */
