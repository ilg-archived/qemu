/*
 * Cortex-M NVIC emulation.
 *
 * Copyright (c) 2015 Liviu Ionescu.
 * Copyright (c) 2006-2007 CodeSourcery.
 * Written by Paul Brook.
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

#ifndef CORTEXM_NVIC_H
#define CORTEXM_NVIC_H

#include "hw/intc/gic_internal.h"
#include "hw/misc/peripheral.h"

/* ------------------------------------------------------------------------- */

#define TYPE_CORTEXM_NVIC TYPE_CORTEXM_PREFIX "nvic" TYPE_PERIPHERAL_SUFFIX

/* ------------------------------------------------------------------------- */

/* Parent definitions. */
#define TYPE_CORTEXM_NVIC_PARENT TYPE_ARM_GIC_COMMON
typedef ARMGICClass CortexMNVICParentClass;
typedef GICState CortexMNVICParentState;

/* ------------------------------------------------------------------------- */

typedef struct {

} CortexMNVICConstruct;

/* Class definitions. */
#define CORTEXM_NVIC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(CortexMNVICClass, (obj), TYPE_CORTEXM_NVIC)
#define CORTEXM_NVIC_CLASS(klass) \
    OBJECT_CLASS_CHECK(CortexMNVICClass, (klass), TYPE_CORTEXM_NVIC)

typedef struct {
    /*< private >*/
    CortexMNVICParentClass parent_class;
    /*< public >*/

} CortexMNVICClass;

/* ------------------------------------------------------------------------- */

/* Instance definitions. */
#define CORTEXM_NVIC_STATE(obj) \
    OBJECT_CHECK(CortexMNVICState, (obj), TYPE_CORTEXM_NVIC)

typedef struct {
    /*< private >*/
    CortexMNVICParentState gic;
    /*< public >*/

    struct {
        uint32_t control;
        uint32_t reload;
        int64_t tick;
        QEMUTimer *timer;
    } systick;
    MemoryRegion sysregmem;
    MemoryRegion gic_iomem_alias;
    MemoryRegion container;
    uint32_t num_irq;
} CortexMNVICState;

/* ------------------------------------------------------------------------- */

void cortexm_nvic_set_pending(void *opaque, int irq);
int cortexm_nvic_acknowledge_irq(void *opaque);
void cortexm_nvic_complete_irq(void *opaque, int irq);

/* ------------------------------------------------------------------------- */

#endif /* CORTEXM_NVIC_H */
