/*
 * STM32 Cortex-M devices emulation.
 *
 * Copyright (c) 2014 Liviu Ionescu.
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

#ifndef STM32_MCU_H_
#define STM32_MCU_H_

#include "qemu/osdep.h"

#include "hw/boards.h"
#include <hw/cortexm/mcu.h>
#include <hw/cortexm/stm32/rcc.h>
#include <hw/cortexm/stm32/flash.h>
#include <hw/cortexm/stm32/pwr.h>
#include <hw/cortexm/stm32/gpio.h>
#include <hw/cortexm/stm32/usart.h>
#include <hw/cortexm/stm32/exti.h>
#include <hw/cortexm/stm32/syscfg.h>
#include <hw/cortexm/stm32/afio.h>
#include <hw/cortexm/parson.h>

// ----------------------------------------------------------------------------

#define TYPE_STM32_MCU "stm32-mcu"

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_MCU_PARENT TYPE_CORTEXM_MCU
typedef CortexMClass STM32MCUParentClass;
typedef CortexMState STM32MCUParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_MCU_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32MCUClass, (obj), TYPE_STM32_MCU)
#define STM32_MCU_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32MCUClass, (klass), TYPE_STM32_MCU)

typedef struct STM32MCUClass {
    // private:
    STM32MCUParentClass parent_class;
    // public:

} STM32MCUClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_MCU_STATE(obj) \
    OBJECT_CHECK(STM32MCUState, (obj), TYPE_STM32_MCU)

typedef struct STM32MCUState {
    // private:
    STM32MCUParentState parent_obj;
    // public:

    // Constructor parameters.
    const STM32Capabilities *param_capabilities;

    // Specific STM32 capabilities; Cortex-M capabilities are separate.
    const STM32Capabilities *capabilities;

    Object *container;

    DeviceState *rcc;

    // These two properties are duplicated from RCC, to allow
    // setting them before the object exist.
    uint32_t hse_freq_hz;
    uint32_t lse_freq_hz;

    DeviceState *flash;
    DeviceState *pwr;
    DeviceState *exti;

    DeviceState *syscfg;
    DeviceState *afio; // For STM32F1 only.

    DeviceState *gpio[STM32_MAX_GPIO];
    int num_gpio;
    DeviceState *usart[STM32_MAX_USART];

} STM32MCUState;

// ------ Public --------------------------------------------------------------

/*
 * Might be deprecated in the future; peripherals are named and can be
 * obtained by name.
 */

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

G_INLINE_FUNC STM32MCUState *stm32_mcu_get(void)
{
    return STM32_MCU_STATE(object_resolve_path("/machine/mcu", NULL));
}

// ----------------------------------------------------------------------------

#endif /* STM32_MCU_H_ */
