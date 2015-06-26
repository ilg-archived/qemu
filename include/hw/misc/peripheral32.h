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

#ifndef PERIPHERAL32_H_
#define PERIPHERAL32_H_

#include "hw/misc/register32.h"

//#include "exec/address-spaces.h"

/**
 * Parent type for 32-bits peripherals.
 * It builds an array of 32-bits registers and forwards read/writes to them.
 */

/* ------------------------------------------------------------------------- */

#define TYPE_PERIPHERAL32 "peripheral32"

/* ------------------------------------------------------------------------- */

/* Parent definitions. */
#define TYPE_PERIPHERAL32_PARENT TYPE_SYS_BUS_DEVICE
typedef SysBusDeviceClass Peripheral32ParentClass;
typedef SysBusDevice Peripheral32ParentState;

/* ------------------------------------------------------------------------- */

#define PERIPHERAL32_GET_CLASS(obj) \
    OBJECT_GET_CLASS(Peripheral32Class, (obj), TYPE_PERIPHERAL32)
#define PERIPHERAL32_CLASS(klass) \
    OBJECT_CLASS_CHECK(Peripheral32Class, (klass), TYPE_PERIPHERAL32)

typedef struct {
    /*< private >*/
    Peripheral32ParentClass parent_class;
    /*< public >*/

} Peripheral32Class;

/* ------------------------------------------------------------------------- */

#define PERIPHERAL32_STATE(obj) \
    OBJECT_CHECK(Peripheral32State, (obj), TYPE_PERIPHERAL32)

typedef struct {
    /*< private >*/
    Peripheral32ParentState parent_obj;
    /*< public >*/

    /* Memory region name */
    const char *mmio_name;

    /* Memory region address, relative to system area */
    hwaddr mmio_address;

    /* Memory region size, including reservation at the end */
    uint32_t mmio_size;

    MemoryRegion mmio;

    /* Default access flags, when registers do not define them. */
    uint32_t default_access_flags;

} Peripheral32State;

/* ------------------------------------------------------------------------- */

void peripheral32_add_registers(DeviceState *dev, RegisterInfo *regs);

/* ------------------------------------------------------------------------- */

#endif /* PERIPHERAL32_H_ */
