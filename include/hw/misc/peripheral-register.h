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

#ifndef PERIPHERAL_REGISTER_H_
#define PERIPHERAL_REGISTER_H_

#include "config.h"
#include "qemu/typedefs.h"
#include "hw/misc/register-bitfield.h"

//#include "exec/address-spaces.h"

/**
 * Emulates the behaviour of a peripheral register.
 * Up to 64-bits are supported.
 */

/* ------------------------------------------------------------------------- */

/* Allow all accesses, of all sizes. */
#define PERIPHERAL_REGISTER_DEFAULT_ACCESS_FLAGS     (0xFFFFFFFF)

typedef struct {
    const char *desc;

    hwaddr offset;
    uint64_t reset_value;
    uint64_t readable_bits;
    uint64_t writable_bits;
    uint32_t access_flags;
    // uint32_t array_size; /* For multiple identical registers, name[0]... */
    RegisterBitfieldInfo *bitfields;
} PeripheralRegisterInfo;

typedef struct {
    const char *name; /* Type name, like gpio-bssr */
    const char *desc;

    hwaddr offset;
    uint64_t reset_value;
    uint64_t readable_bits;
    uint64_t writable_bits;
    uint32_t access_flags;
    // uint32_t array_size; /* For multiple identical registers, name[0]... */
    uint64_t (*read)(Object *obj, hwaddr addr, unsigned size);
    void (*write)(Object *obj, hwaddr addr, unsigned size, uint64_t value);
    RegisterBitfieldInfo *bitfields;
} PeripheralRegisterTypeInfo;

/* ------------------------------------------------------------------------- */

#define TYPE_PERIPHERAL_REGISTER "peripheral-register"

#define TYPE_PERIPHERAL_REGISTER_SUFFIX "-register"

/* ------------------------------------------------------------------------- */

/* Parent definitions. */
#define TYPE_PERIPHERAL_REGISTER_PARENT TYPE_DEVICE
typedef DeviceClass PeripheralRegisterParentClass;
typedef DeviceState PeripheralRegisterParentState;

/* ------------------------------------------------------------------------- */

/* Class definitions. */
#define PERIPHERAL_REGISTER_GET_CLASS(obj) \
    OBJECT_GET_CLASS(PeripheralRegisterClass, (obj), TYPE_PERIPHERAL_REGISTER)
#define PERIPHERAL_REGISTER_CLASS(klass) \
    OBJECT_CLASS_CHECK(PeripheralRegisterClass, (klass), TYPE_PERIPHERAL_REGISTER)

typedef struct {
    /*< private >*/
    PeripheralRegisterParentClass parent_class;
    /*< public >*/

    uint64_t (*read)(Object *obj, hwaddr addr, unsigned size);
    void (*write)(Object *obj, hwaddr addr, unsigned size, uint64_t value);

} PeripheralRegisterClass;

/* ------------------------------------------------------------------------- */

/* Instance definitions. */
#define PERIPHERAL_REGISTER_STATE(obj) \
    OBJECT_CHECK(PeripheralRegisterState, (obj), TYPE_PERIPHERAL_REGISTER)

typedef struct {
    /*< private >*/
    PeripheralRegisterParentState parent_obj;
    /*< public >*/

    hwaddr offset;
    uint64_t reset_value;
    uint64_t readable_bits;
    uint64_t writable_bits;
    uint32_t access_flags;
    //uint32_t array_size; /* For multiple identical registers, name[0]... */

    uint64_t value;
} PeripheralRegisterState;

/* ------------------------------------------------------------------------- */

/* Derived class definitions. */
#define PERIPHERAL_REGISTER_DERIVED_GET_CLASS(obj, _t) \
    OBJECT_GET_CLASS(PeripheralRegisterDerivedClass, (obj), _t)
#define PERIPHERAL_REGISTER_DERIVED_CLASS(klass, _t) \
    OBJECT_CLASS_CHECK(PeripheralRegisterDerivedClass, (klass), _t)

typedef struct {
    /*< private >*/
    PeripheralRegisterParentClass parent_class;
    /*< public >*/

    const char *name;
    const char *desc;

    hwaddr offset;

    uint64_t reset_value;
    uint64_t readable_bits;
    uint64_t writable_bits;
    uint32_t access_flags;

    RegisterBitfieldInfo *bitfields;

} PeripheralRegisterDerivedClass;

/* ------------------------------------------------------------------------- */

/* Derived instance definitions. */
#define PERIPHERAL_REGISTER_DERIVED_STATE(obj, _t) \
    OBJECT_CHECK(PeripheralRegisterDerivedState, (obj), _t)

typedef struct {
    /*< private >*/
    PeripheralRegisterState parent_obj;
    /*< public >*/

} PeripheralRegisterDerivedState;

/* ----- Public ------------------------------------------------------------ */

uint64_t peripheral_register_get_value(Object* obj);
Object *peripheral_register_new(Object *parent, const char *node_name,
        PeripheralRegisterInfo *info);
Object *derived_peripheral_register_new(Object *parent, const char *node_name,
        const char *type_name);

void derived_peripheral_register_type_register(PeripheralRegisterTypeInfo *reg);

/* ------------------------------------------------------------------------- */

#endif /* PERIPHERAL_REGISTER_H_ */
