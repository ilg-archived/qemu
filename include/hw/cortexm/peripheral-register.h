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

#include "qemu/osdep.h"

#include "qemu/typedefs.h"
#include "qapi/error.h"

#include <hw/cortexm/register-bitfield.h>
#include <hw/cortexm/json-parser.h>

/*
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

// ----------------------------------------------------------------------------
/*
 * Access bits are grouped by size and offset.
 *
 * The byte position encodes the size (4321, or 87654321).
 * The bit position encodes the offset (3210, or 76543210)
 * - 01 - offset = 0, word aligned
 * - 04 - offset = 2, half-word aligned
 * - 08 - offset = 3, byte aligned
 *
 * Checked by peripheral_register_check_access().
 */

// Allow all unaligned accesses, of all sizes.
#define PERIPHERAL_REGISTER_DEFAULT_ACCESS_FLAGS        (0xFFFFFFFFFFFFFFFF)
#define PERIPHERAL_REGISTER_64BITS_ALL                  (0xFFFFFFFFFFFFFFFF)
#define PERIPHERAL_REGISTER_32BITS_ALL                  (0x0F0F0F0F)

// ----------------------------------------------------------------------------

// Allow word access aligned at 4 byte margin (reg-offset 0)
#define PERIPHERAL_REGISTER_32BITS_WORD                 (0x01000000)
// Allow word access aligned at 4 byte margin and half word access
// aligned at 2 and 4 byte margin  (reg-offset 0 or 2)
#define PERIPHERAL_REGISTER_32BITS_WORD_HALFWORD        (0x01000500)

// ----------------------------------------------------------------------------

#define PERIPHERAL_REGISTER_DEFAULT_SIZE_BYTES          (4)
#define PERIPHERAL_REGISTER_MAX_SIZE_BITS               (64)

// ----------------------------------------------------------------------------

#define REGISTER_RW_MODE_READ          (0x01)
#define REGISTER_RW_MODE_WRITE         (0x02)
#define REGISTER_RW_MODE_READ_WRITE    \
    (REGISTER_RW_MODE_READ | REGISTER_RW_MODE_WRITE)

// ----------------------------------------------------------------------------

// Pass both the register and the peripheral, to allow
// inter-registers settings.
typedef peripheral_register_t (*register_read_callback_t)(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size);

typedef void (*register_write_callback_t)(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value);

typedef peripheral_register_t (*register_pre_read_callback_t)(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size);

typedef void (*register_post_read_callback_t)(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size);

typedef peripheral_register_t (*register_pre_write_callback_t)(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value);

typedef void (*register_post_write_callback_t)(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value);

// Info structure used to create new register types.
typedef struct {
    // Register description; copied from reference manual.
    const char *desc;

    // Register abbreviation; lower case, short word.
    const char *name;

    // Register offset inside peripheral, in bytes.
    uint32_t offset_bytes;

    // Register value at reset.
    peripheral_register_t reset_value;
    // Mask with the bits affected by reset; default all.
    peripheral_register_t reset_mask;
    // Mask with the bits that can be read; the other return 0.
    peripheral_register_t readable_bits;
    // mask with the bits that can be written; the other are unchanged.
    peripheral_register_t writable_bits;

    // Each byte encodes which accesses are allowed, for different alignments.
    uint64_t access_flags;

    // Register size in bits; default is inherited from peripheral.
    uint32_t size_bits;

    // Read, write or read & write; default both.
    uint32_t rw_mode;

    // Pointer to array of bitfields.
    RegisterBitfieldInfo *bitfields;

    // Copied to instance.
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
    // follows, cleared by, set by
    peripheral_register_auto_bits_type_t type;
} PeripheralRegisterAutoBits;

// ----------------------------------------------------------------------------

#define TYPE_PERIPHERAL_REGISTER "peripheral-register"

#define TYPE_PERIPHERAL_REGISTER_SUFFIX "-register"

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_PERIPHERAL_REGISTER_PARENT TYPE_DEVICE
typedef DeviceClass PeripheralRegisterParentClass;
typedef DeviceState PeripheralRegisterParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define PERIPHERAL_REGISTER_GET_CLASS(obj) \
    OBJECT_GET_CLASS(PeripheralRegisterClass, (obj), TYPE_PERIPHERAL_REGISTER)
#define PERIPHERAL_REGISTER_CLASS(klass) \
    OBJECT_CLASS_CHECK(PeripheralRegisterClass, (klass), TYPE_PERIPHERAL_REGISTER)

typedef struct {
    // private:
    PeripheralRegisterParentClass parent_class;
    // public:

    register_read_callback_t read;
    register_write_callback_t write;

} PeripheralRegisterClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define PERIPHERAL_REGISTER_STATE(obj) \
    OBJECT_CHECK(PeripheralRegisterState, (obj), TYPE_PERIPHERAL_REGISTER)

typedef struct {
    // private:
    PeripheralRegisterParentState parent_obj;
    // public:

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

    // Current register value; returned (masked) by reads.
    peripheral_register_t value;

    // Previous value, used to compute changes.
    peripheral_register_t prev_value;

    /*
     * Placing pointers to functions in the instance data is not very
     * nice, but the alternative to create new classes and make these
     * functions virtuals is not very practical, since there are
     * hundreds of such objects, mostly used only once.
     */

    // Called to retrieve the value before read.
    // Name the function xxx_pre_read_callback().
    register_pre_read_callback_t pre_read;
    // Called for further processing after read.
    // Name the function xxx_post_read_callback().
    register_post_read_callback_t post_read;

    // Called for further processing before write.
    register_pre_write_callback_t pre_write;
    // Called after storing the new value in the write callback.
    // Name the function xxx_post_write_callback().
    register_post_write_callback_t post_write;

    struct {
        const char *size;
        const char *access;
        const char *protection;
        const char *reset_value;
        const char *reset_mask;
    } svd;

} PeripheralRegisterState;

// ----- Public ---------------------------------------------------------------

Object *peripheral_register_add_properties_and_children(Object *obj,
        PeripheralRegisterInfo *info);

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

void peripheral_register_set_pre_write(Object* obj,
        register_pre_write_callback_t ptr);

void peripheral_register_set_post_write(Object* obj,
        register_post_write_callback_t ptr);

void peripheral_register_set_pre_read(Object* obj,
        register_read_callback_t ptr);

void peripheral_register_set_post_read(Object* obj,
        register_post_read_callback_t ptr);

// ----------------------------------------------------------------------------

#endif /* PERIPHERAL_REGISTER_H_ */
