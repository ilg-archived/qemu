/*
 * Register bitfield emulation.
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

#ifndef BITFIELD_H_
#define BITFIELD_H_

#include "config.h"
#include "qemu/typedefs.h"
#include "hw/sysbus.h"

/**
 * Emulates the behaviour of a register bitfield.
 */

/* ------------------------------------------------------------------------- */

#define BITFIELD_MODE_READ          (0x01)
#define BITFIELD_MODE_WRITE         (0x02)
#define BITFIELD_MODE_READ_WRITE    (BITFIELD_MODE_READ | BITFIELD_MODE_WRITE)

typedef struct {
    const char *name;
    const char *desc;
    uint32_t first_bit;
    uint32_t last_bit;
    uint64_t reset_value;
    uint32_t mode;
    const char *follows;
} BitfieldInfo;

/* ------------------------------------------------------------------------- */

#define TYPE_BITFIELD "bitfield"

/* ------------------------------------------------------------------------- */

/* Parent definitions. */
#define TYPE_BITFIELD_PARENT TYPE_DEVICE
typedef DeviceClass BitfieldParentClass;
typedef DeviceState BitfieldParentState;

/* ------------------------------------------------------------------------- */

#define BITFIELD_GET_CLASS(obj) \
    OBJECT_GET_CLASS(BitfieldClass, (obj), TYPE_BITFIELD)
#define BITFIELD_CLASS(klass) \
    OBJECT_CLASS_CHECK(BitfieldClass, (klass), TYPE_BITFIELD)

typedef struct {
    /*< private >*/
    BitfieldParentClass parent_class;
    /*< public >*/

} BitfieldClass;

/* ------------------------------------------------------------------------- */

#define BITFIELD_STATE(obj) \
    OBJECT_CHECK(BitfieldState, (obj), TYPE_BITFIELD)

typedef struct {
    /*< private >*/
    BitfieldParentState parent_obj;
    /*< public >*/

    uint32_t register_size_bits;

    uint32_t first_bit;
    uint32_t last_bit;
    uint64_t reset_value;bool is_readable;bool is_writable;
    const char *follows;

    /* The field value is ((parent->value & mask) >> shift) */
    uint64_t mask;
    uint32_t shift;

} BitfieldState;

/* ----- Public ------------------------------------------------------------ */

bool bitfield_is_zero(Object* obj);
uint64_t bitfield_get_value(Object* obj);

/* ------------------------------------------------------------------------- */

#endif /* BITFIELD_H_ */
