/*
 * 32-bits peripheral emulation.
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

#ifndef PERIPHERAL_H_
#define PERIPHERAL_H_

#include "hw/misc/peripheral-register.h"

/**
 * Parent type for peripherals.
 * It builds an array of registers and forwards read/writes to them.
 */

/* ------------------------------------------------------------------------- */

#define TYPE_PERIPHERAL "peripheral"

#define TYPE_PERIPHERAL_SUFFIX "-peripheral"

/* ------------------------------------------------------------------------- */

/**
 * Parent definitions.
 *
 * Must be a descendant of SYS_BUS_DEVICE since here are stored the
 * MMIO settings by sysbus_init_mmio() and sysbus_mmio_map().
 */
#define TYPE_PERIPHERAL_PARENT TYPE_SYS_BUS_DEVICE
typedef SysBusDeviceClass PeripheralParentClass;
typedef SysBusDevice PeripheralParentState;

/* ------------------------------------------------------------------------- */

/* Class definitions. */
#define PERIPHERAL_GET_CLASS(obj) \
    OBJECT_GET_CLASS(PeripheralClass, (obj), TYPE_PERIPHERAL)
#define PERIPHERAL_CLASS(klass) \
    OBJECT_CLASS_CHECK(PeripheralClass, (klass), TYPE_PERIPHERAL)

typedef struct {
    /*< private >*/
    PeripheralParentClass parent_class;
    /*< public >*/

    /* None, so far. */
} PeripheralClass;

/* ------------------------------------------------------------------------- */

/* Instance definitions. */
#define PERIPHERAL_STATE(obj) \
    OBJECT_CHECK(PeripheralState, (obj), TYPE_PERIPHERAL)

typedef struct {
    /*< private >*/
    PeripheralParentState parent_obj;
    /*< public >*/

    /* Memory region node name, as seen in qom-tree */
    const char *mmio_node_name;

    /* Memory region address, relative to system area */
    hwaddr mmio_address;

    /* Memory region size, including reservation at the end */
    uint32_t mmio_size_bytes;

    MemoryRegion mmio;

    /* Default access flags, when registers do not define them. */
    uint32_t default_access_flags;

    /* All peripheral registers have the same size. (1-8) */
    uint32_t register_size_bytes;

    uint32_t max_offset_bytes;
    uint32_t num_registers;

    uint32_t registers_size_ptrs;
    Object **registers;

    bool is_little_endian;
} PeripheralState;

/* ------------------------------------------------------------------------- */

#endif /* PERIPHERAL_H_ */
