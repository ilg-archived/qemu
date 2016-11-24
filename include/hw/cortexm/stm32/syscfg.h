/*
 * STM32 MCU - SYSCFG (system configuration controller) emulation.
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

#ifndef STM32_SYSCFG_H_
#define STM32_SYSCFG_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

/* ------------------------------------------------------------------------- */

#define DEVICE_PATH_STM32_SYSCFG "/machine/mcu/stm32/syscfg"

/* ------------------------------------------------------------------------- */

#define TYPE_STM32_SYSCFG TYPE_STM32_PREFIX "syscfg" TYPE_PERIPHERAL_SUFFIX

/* ------------------------------------------------------------------------- */

/* Parent definitions. */
#define TYPE_STM32_SYSCFG_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32SYSCFGParentClass;
typedef PeripheralState STM32SYSCFGParentState;

/* ------------------------------------------------------------------------- */

/* Class definitions. */
#define STM32_SYSCFG_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32SYSCFGClass, (obj), TYPE_STM32_SYSCFG)
#define STM32_SYSCFG_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32SYSCFGClass, (klass), TYPE_STM32_SYSCFG)

typedef struct {
    /*< private >*/
    STM32SYSCFGParentClass parent_class;
    /*< public >*/

    /* None, so far. */
} STM32SYSCFGClass;

/* ------------------------------------------------------------------------- */

/* Instance definitions. */
#define STM32_SYSCFG_STATE(obj) \
    OBJECT_CHECK(STM32SYSCFGState, (obj), TYPE_STM32_SYSCFG)

typedef struct {
    /*< private >*/
    STM32SYSCFGParentState parent_obj;
    /*< public >*/

    struct {
        Object *memrmp;
        Object *pmc;
        Object *exticr1;
        Object *exticr2;
        Object *exticr3;
        Object *exticr4;
        Object *cmpcr; /* rc_w1 */
    } reg;

    struct {
        Object *mem_mode;
    } memrmp;

    struct {
        Object *exti[16];
    } exticr;

    struct {
        Object *cmp_pd;
        Object *ready;
    } cmpcr;

    const STM32Capabilities *capabilities;
} STM32SYSCFGState;

/* ------------------------------------------------------------------------- */

#endif /* STM32_SYSCFG_H_ */
