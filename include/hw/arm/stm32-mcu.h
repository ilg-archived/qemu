/*
 * STM32 Cortex-M devices emulation.
 *
 * Copyright (c) 2014 Liviu Ionescu
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

#ifndef STM32_MCU_H
#define STM32_MCU_H

#include "hw/boards.h"
#include "hw/arm/cortexm-mcu.h"
//#include "hw/sysbus.h"
#include "hw/misc/stm32-rcc.h"
#include "hw/misc/stm32-flash.h"
#include "hw/gpio/stm32-gpio.h"

/* ---- Common STM32 ----- */
#define TYPE_STM32_MCU "stm32-mcu"

#define STM32_MCU_STATE(obj) \
    OBJECT_CHECK(STM32MCUState, (obj), TYPE_STM32_MCU)

typedef struct STM32MCUState {
    /*< private >*/
    CortexMState parent_obj;
    /*< public >*/

    /* Specific STM32 capabilities; Cortex-M capabilities are separate. */
    STM32Capabilities *capabilities;

    DeviceState *rcc;
    DeviceState *flash;
    DeviceState *gpio[STM32_MAX_GPIO];
} STM32MCUState;

#define STM32_MCU_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32MCUClass, (obj), TYPE_STM32_MCU)
#define STM32_MCU_CLASS(obj) \
    OBJECT_CLASS_CHECK(STM32MCUClass, (obj), TYPE_STM32_MCU)

typedef struct STM32MCUClass {
    /*< private >*/
    CortexMClass parent_class;
    /*< public >*/

    DeviceRealize parent_realize;
    void (*construct)(Object *obj, STM32Capabilities* capabilities,
            CortexMCapabilities* core_capabilities, MachineState *machine);

    void (*parent_memory_regions_create)(DeviceState *dev);
    // void (*parent_reset)(DeviceState *dev);
} STM32MCUClass;

G_INLINE_FUNC DeviceState *stm32_mcu_get_rcc_dev(DeviceState *dev)
{
    return DEVICE((STM32_MCU_STATE(dev)->rcc));
}

G_INLINE_FUNC DeviceState *stm32_mcu_get_gpio_dev(DeviceState *dev,
        int port_index)
{
    assert(port_index < STM32_MAX_GPIO);
    return DEVICE((STM32_MCU_STATE(dev)->gpio[port_index]));
}

#endif /* STM32_MCU_H */
