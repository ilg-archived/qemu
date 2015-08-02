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

/**
 * Emulates the behaviour of a peripheral register.
 * Up to 64-bits are supported.
 *
 * Register are defined in terms of offset inside the MMIO area,
 * read/write masks, reset value.
 *
 * Registers may have bitfields as direct children.
 *
 * A special feature is the possibility to define status bitfields
 * that follow enable/disable bitfields.
 */

/* ------------------------------------------------------------------------- */

/* Allow all accesses, of all sizes. */
#define PERIPHERAL_REGISTER_DEFAULT_ACCESS_FLAGS    (0xFFFFFFFFFFFFFFFF)
#define PERIPHERAL_REGISTER_64BITS_ALL                  (0xFFFFFFFFFFFFFFFF)
#define PERIPHERAL_REGISTER_32BITS_ALL                  (0x0F0F0F0F)
#define PERIPHERAL_REGISTER_32BITS_WORD                 (0x01000000)

#define PERIPHERAL_REGISTER_DEFAULT_SIZE_BYTES      (4)
#define PERIPHERAL_REGISTER_MAX_SIZE_BITS           (64)

#define REGISTER_RW_MODE_READ          (0x01)
#define REGISTER_RW_MODE_WRITE         (0x02)
#define REGISTER_RW_MODE_READ_WRITE    \
    (REGISTER_RW_MODE_READ | REGISTER_RW_MODE_WRITE)

/* ------------------------------------------------------------------------- */

/*
 * Pass both the register and the peripheral, to allow
 * inter-registers settings.
 */
typedef peripheral_register_t (*register_read_callback_t)(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size);

typedef void (*register_write_callback_t)(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value);

/**
 * Info structure used to create new register types.
 */
typedef struct {
    const char *desc;
    const char *name;

    uint32_t offset_bytes;
    peripheral_register_t reset_value;
    peripheral_register_t reset_mask;
    peripheral_register_t readable_bits;
    peripheral_register_t writable_bits;
    uint64_t access_flags;
    uint32_t size_bits;
    uint32_t rw_mode;

    RegisterBitfieldInfo *bitfields;

    /* Copied to instance. */
    //register_read_callback_t pre_read;
    //register_write_callback_t post_write;
} PeripheralRegisterInfo;

typedef enum {
    PERIPHERAL_REGISTER_AUTO_BITS_TYPE_FOLLOWS = 1,
    PERIPHERAL_REGISTER_AUTO_BITS_TYPE_CLEARED_BY,
    PERIPHERAL_REGISTER_AUTO_BITS_TYPE_SET_BY,
} peripheral_register_auto_bits_type_t;

/*
 * Automatically reflected bits (like ENABLE) into status bits
 * (like READY). The mask defines which bits should be reflected and
 * the shift how many positions should be shifted (+ <<, - >>).
 *
 * The operations are:
 *      value &= ~(mask << shift);
 *      value |= ((value & mask) << shift);
 *
 * The array is terminated by a zero mask.
 */
typedef struct {
    peripheral_register_t mask;
    int shift;
    peripheral_register_auto_bits_type_t type;
} PeripheralRegisterAutoBits;

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

    register_read_callback_t pre_read;
    register_read_callback_t read;
    register_write_callback_t write;
    register_write_callback_t post_write;
} PeripheralRegisterClass;

/* ------------------------------------------------------------------------- */

/* Instance definitions. */
#define PERIPHERAL_REGISTER_STATE(obj) \
    OBJECT_CHECK(PeripheralRegisterState, (obj), TYPE_PERIPHERAL_REGISTER)

typedef struct {
    /*< private >*/
    PeripheralRegisterParentState parent_obj;
    /*< public >*/

    const char *name;

    uint32_t offset_bytes;
    peripheral_register_t reset_value;
    peripheral_register_t reset_mask;
    peripheral_register_t readable_bits;
    peripheral_register_t writable_bits;
    uint64_t access_flags;

    uint32_t size_bits;

    bool is_readable; /**/
    bool is_writable;

    PeripheralRegisterAutoBits *auto_bits;

    /* Current register value; returned (masked) by reads. */
    peripheral_register_t value;

    /* Previous value, used to compute changes. */
    peripheral_register_t prev_value;

    /*
     * Placing pointers to functions in the instance data is not very
     * nice, but the alternative to create new times and make these
     * functions virtuals is not very practical, since there are
     * hundreds of such objects, mostly used only once.
     */
    register_read_callback_t pre_read;
    register_write_callback_t post_write;
} PeripheralRegisterState;

/* ----- Public ------------------------------------------------------------ */

Object *peripheral_register_new_with_info(Object *parent_obj,
        const char *node_name, PeripheralRegisterInfo *info);

void peripheral_register_compute_auto_bits(Object *obj);

peripheral_register_t peripheral_register_read_value(Object* obj);

void peripheral_register_write_value(Object* obj, peripheral_register_t value);

peripheral_register_t peripheral_register_get_raw_value(Object* obj);

void peripheral_register_set_raw_value(Object* obj,
        peripheral_register_t value);

void peripheral_register_or_raw_value(Object* obj, peripheral_register_t value);

void peripheral_register_and_raw_value(Object* obj,
        peripheral_register_t value);

peripheral_register_t peripheral_register_get_raw_prev_value(Object* obj);

peripheral_register_t peripheral_register_shorten(peripheral_register_t value,
        uint32_t offset, unsigned size, bool is_little_endian);

peripheral_register_t peripheral_register_widen(peripheral_register_t old_value,
        peripheral_register_t value, uint32_t offset, unsigned size,
        bool is_little_endian);

void peripheral_register_set_post_write(Object* obj,
        register_write_callback_t ptr);

void peripheral_register_set_pre_read(Object* obj,
        register_read_callback_t ptr);

/* ------------------------------------------------------------------------- */

#endif /* PERIPHERAL_REGISTER_H_ */
