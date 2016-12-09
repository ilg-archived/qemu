/*
 * STM32 MCU - EXTI (external interrupts controller) emulation.
 *
 * Copyright (c) 2016 Liviu Ionescu.
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

#ifndef STM32_EXTI_H_
#define STM32_EXTI_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

/* ------------------------------------------------------------------------- */

#define DEVICE_PATH_STM32_EXTI DEVICE_PATH_STM32 "EXTI"

/*
 * The maximum number of EXTIs for all families.
 * Used to statically allocate the irqs.
 */
#define STM32_EXTI_MAX_NUM  (23)

#define IRQ_EXTI_IN     "exti-in"
#define IRQ_EXTI_OUT    "nvic-out"

/* ------------------------------------------------------------------------- */

#define TYPE_STM32_EXTI TYPE_STM32_PREFIX "exti" TYPE_PERIPHERAL_SUFFIX

/* ------------------------------------------------------------------------- */

/* Parent definitions. */
#define TYPE_STM32_EXTI_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32EXTIParentClass;
typedef PeripheralState STM32EXTIParentState;

/* ------------------------------------------------------------------------- */

/* Class definitions. */
#define STM32_EXTI_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32EXTIClass, (obj), TYPE_STM32_EXTI)
#define STM32_EXTI_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32EXTIClass, (klass), TYPE_STM32_EXTI)

typedef struct {
    /*< private >*/
    STM32EXTIParentClass parent_class;
    /*< public >*/

    /* None, so far. */
} STM32EXTIClass;

/* ------------------------------------------------------------------------- */

/* Instance definitions. */
#define STM32_EXTI_STATE(obj) \
    OBJECT_CHECK(STM32EXTIState, (obj), TYPE_STM32_EXTI)

typedef struct {
    /*< private >*/
    STM32EXTIParentState parent_obj;
    /*< public >*/

    MemoryRegion mmio;
    uint32_t num_exti;

    /* Output IRQs, connected to NVIC interrupts. */
    qemu_irq irq_out[STM32_EXTI_MAX_NUM];

    struct {
        Object *imr;
        Object *emr;
        Object *rtsr;
        Object *ftsr;
        Object *swier;
        Object *pr; /* rc_w1 */
    } reg;

    struct {
        /* F1 specific registers */
    } f1;

    struct {
        // F4 EXTI (External interrupt/event controller) registers.
        struct {
            Object *imr; // 0x0 Interrupt mask register (EXTI_IMR)
            Object *emr; // 0x4 Event mask register (EXTI_EMR)
            Object *rtsr; // 0x8 Rising Trigger selection register (EXTI_RTSR)
            Object *ftsr; // 0xC Falling Trigger selection register (EXTI_FTSR)
            Object *swier; // 0x10 Software interrupt event register (EXTI_SWIER)
            Object *pr; // 0x14 Pending register (EXTI_PR)
        } reg;
    } f4;

    const STM32Capabilities *capabilities;
} STM32EXTIState;

/* ------------------------------------------------------------------------- */

#endif /* STM32_EXTI_H_ */
