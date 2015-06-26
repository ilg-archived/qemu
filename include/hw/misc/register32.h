/*
 * 32-bits register emulation.
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

#ifndef REGISTER32_H_
#define REGISTER32_H_

#include "config.h"
#include "qemu/typedefs.h"
#include "hw/sysbus.h"

//#include "exec/address-spaces.h"

/**
 * Emulates the behaviour of a 32-bits register.
 */

/* ------------------------------------------------------------------------- */

/*
 * Automatically reflected bits, like ENABLE, into status bits,
 * like READY. The mask defines which bits should be reflected and
 * the shift how many positions should be shifted (+ <<, - >>).
 *
 * The array is terminated by a zero mask.
 */
typedef struct {
    uint32_t mask;
    int shift;
} RegisterAutoBits;

typedef struct {
    const char *name;
    const char *desc;
    hwaddr offset;
    uint32_t reset_value;
    uint32_t read_mask;
    uint32_t write_mask;
    uint32_t access_flags;
    uint32_t array_size; /* For multiple identical registers, name[0]... */
    uint32_t (*read)(hwaddr addr, unsigned size);
    void (*write)(hwaddr addr, unsigned size, uint32_t value);
    RegisterAutoBits *auto_bits;
} RegisterInfo;

/* ------------------------------------------------------------------------- */

#define TYPE_REGISTER32 "register32"

/* ------------------------------------------------------------------------- */

/* Parent definitions. */
#define TYPE_REGISTER32_PARENT TYPE_SYS_BUS_DEVICE
typedef SysBusDeviceClass Register32ParentClass;
typedef SysBusDevice Register32ParentState;

/* ------------------------------------------------------------------------- */

#define REGISTER32_GET_CLASS(obj) \
    OBJECT_GET_CLASS(Register32Class, (obj), TYPE_REGISTER32)
#define REGISTER32_CLASS(klass) \
    OBJECT_CLASS_CHECK(Register32Class, (klass), TYPE_REGISTER32)

typedef struct {
    /*< private >*/
    Register32ParentClass parent_class;
    /*< public >*/

} Register32Class;

/* ------------------------------------------------------------------------- */

#define REGISTER32_STATE(obj) \
    OBJECT_CHECK(Register32State, (obj), TYPE_REGISTER32)

typedef struct {
    /*< private >*/
    Register32ParentState parent_obj;
    /*< public >*/

    //MemoryRegion mmio;
} Register32State;

/* ------------------------------------------------------------------------- */

#endif /* REGISTER32_H_ */
