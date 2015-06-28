/*
 * Peripheral register emulation.
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

#ifndef REGISTER_H_
#define REGISTER_H_

#include "config.h"
#include "qemu/typedefs.h"
#include "hw/misc/bitfield.h"

//#include "exec/address-spaces.h"

/**
 * Emulates the behaviour of a peripheral register.
 * Up to 64-bits are supported.
 */

/* ------------------------------------------------------------------------- */

/* Allow all accesses, of all sizes. */
#define REGISTER_DEFAULT_ACCESS_FLAGS     (0x0FFF)

typedef struct {
    const char *name;
    const char *desc;
    hwaddr offset;
    uint64_t reset_value;
    uint64_t readable_bits;
    uint64_t writable_bits;
    uint32_t access_flags;
    uint32_t array_size; /* For multiple identical registers, name[0]... */
    uint64_t (*read)(hwaddr addr, unsigned size);
    void (*write)(hwaddr addr, unsigned size, uint64_t value);
    BitfieldInfo *bitfields;
} RegisterInfo;

/* ------------------------------------------------------------------------- */

#define TYPE_REGISTER "register"

/* ------------------------------------------------------------------------- */

/* Parent definitions. */
#define TYPE_REGISTER_PARENT TYPE_DEVICE
typedef DeviceClass RegisterParentClass;
typedef DeviceState RegisterParentState;

/* ------------------------------------------------------------------------- */

#define REGISTER_GET_CLASS(obj) \
    OBJECT_GET_CLASS(RegisterClass, (obj), TYPE_REGISTER)
#define REGISTER_CLASS(klass) \
    OBJECT_CLASS_CHECK(RegisterClass, (klass), TYPE_REGISTER)

typedef struct {
    /*< private >*/
    RegisterParentClass parent_class;
    /*< public >*/

} RegisterClass;

/* ------------------------------------------------------------------------- */

#define REGISTER_STATE(obj) \
    OBJECT_CHECK(RegisterState, (obj), TYPE_REGISTER)

typedef struct {
    /*< private >*/
    RegisterParentState parent_obj;
    /*< public >*/

    //MemoryRegion mmio;
    hwaddr offset;
    uint64_t reset_value;
    uint64_t readable_bits;
    uint64_t writable_bits;
    uint32_t access_flags;
    uint32_t array_size; /* For multiple identical registers, name[0]... */

    uint64_t value;
} RegisterState;

/* ----- Public ------------------------------------------------------------ */

uint64_t register_get_value(Object* obj);

/* ------------------------------------------------------------------------- */

#endif /* REGISTER_H_ */
