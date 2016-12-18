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

#ifndef REGISTER_BITFIELD_H_
#define REGISTER_BITFIELD_H_

#include "qemu/osdep.h"
#include "qemu/typedefs.h"
#include "qapi/error.h"

#include "hw/sysbus.h"
#include <hw/cortexm/helper.h>
#include <hw/cortexm/json-parser.h>

/*
 * Emulates the behaviour of a register bitfield.
 *
 * Each bitfield should be the child of a peripheral register.
 *
 * Bitfields are automatically created when creating registers.
 */

// ----------------------------------------------------------------------------
// Info structure used to define the bitfield when creating
// registers.
typedef struct {
    const char *name;
    const char *desc;
    uint32_t first_bit;
    uint32_t width_bits;
    uint32_t rw_mode;
} RegisterBitfieldInfo;

// ----------------------------------------------------------------------------

#define TYPE_REGISTER_BITFIELD "register-bitfield"

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_REGISTER_BITFIELD_PARENT TYPE_DEVICE
typedef DeviceClass RegisterBitfieldParentClass;
typedef DeviceState RegisterBitfieldParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define REGISTER_BITFIELD_GET_CLASS(obj) \
    OBJECT_GET_CLASS(RegisterBitfieldClass, (obj), TYPE_REGISTER_BITFIELD)
#define REGISTER_BITFIELD_CLASS(klass) \
    OBJECT_CLASS_CHECK(RegisterBitfieldClass, (klass), TYPE_REGISTER_BITFIELD)

typedef struct {
    // private:
    RegisterBitfieldParentClass parent_class;
    // public:

    // None, so far.
} RegisterBitfieldClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define REGISTER_BITFIELD_STATE(obj) \
    OBJECT_CHECK(RegisterBitfieldState, (obj), TYPE_REGISTER_BITFIELD)

typedef struct {
    // private:
    RegisterBitfieldParentState parent_obj;
    // public:

    const char *name;

    uint32_t register_size_bits;

    uint32_t first_bit;
    uint32_t width_bits; /**/
    bool is_readable; /**/
    bool is_writable; /**/
    const char *follows;
    const char *cleared_by;
    const char *set_by;

    // The field value is ((parent->value & mask) >> shift)
    peripheral_register_t mask;
    uint32_t shift;

    struct {
        const char *access;
    } svd;

} RegisterBitfieldState;

// ----- Public ---------------------------------------------------------------

Object *register_bitfield_add_properties_and_children(Object *obj,
        RegisterBitfieldInfo *bifi_info);

bool register_bitfield_is_zero(Object* obj);
bool register_bitfield_is_non_zero(Object* obj);

peripheral_register_t register_bitfield_read_value(Object* obj);

// ----------------------------------------------------------------------------

#endif /* REGISTER_BITFIELD_H_ */
