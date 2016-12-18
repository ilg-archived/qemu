/*
 * Cortex-M BitBand emulation.
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

#ifndef CORTEXM_BITBAND_H_
#define CORTEXM_BITBAND_H_

#include "qemu/osdep.h"

#include <hw/cortexm/helper.h>

#include "hw/sysbus.h"

// ----------------------------------------------------------------------------

#define CORTEXM_BITBAND_OFFSET (0x02000000)

// ----------------------------------------------------------------------------

#define TYPE_CORTEXM_BITBAND TYPE_CORTEXM_PREFIX "bitband-memory"

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_CORTEXM_BITBAND_PARENT TYPE_SYS_BUS_DEVICE
typedef SysBusDeviceClass CortexMBitBandParentClass;
typedef SysBusDevice CortexMBitBandParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define CORTEXM_BITBAND_GET_CLASS(obj) \
    OBJECT_GET_CLASS(CortexMBitBandClass, (obj), TYPE_CORTEXM_BITBAND)
#define CORTEXM_BITBAND_CLASS(klass) \
    OBJECT_CLASS_CHECK(CortexMBitBandClass, (klass), TYPE_CORTEXM_BITBAND)

typedef struct {
    // private:
    CortexMBitBandParentClass parent_class;
    // public:

} CortexMBitBandClass;

// ----------------------------------------------------------------------------

#define CORTEXM_BITBAND_STATE(obj) \
    OBJECT_CHECK(CortexMBitBandState, (obj), TYPE_CORTEXM_BITBAND)

typedef struct {
    // private:
    CortexMBitBandParentState parent_obj;
    // public:

    MemoryRegion iomem;
    uint32_t base;
} CortexMBitBandState;

// ----------------------------------------------------------------------------

void cortexm_bitband_init(Object *parent, const char *node_name,
        uint32_t address);

// ----------------------------------------------------------------------------

#endif /* CORTEXM_BITBAND_H_ */
