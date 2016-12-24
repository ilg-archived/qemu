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

#include <hw/cortexm/peripheral-register.h>
#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

#include "qemu/error-report.h"

/*
 * This file implements a peripheral register. It extends all shorter accesses
 * to register size and uses the defined masks to write/read the register.
 *
 * Pre-read and post-write actions can be defined, to fetch data or to
 * cross update registers.
 *
 * This mechanism should cover most of the cases, but if it does not and
 * custom read/write actions are needed, it is possible to define new
 * types that redefine the main read/write methods.
 */

static int peripheral_register_create_auto_array(Object *obj, void *opaque);
static int peripheral_register_check_access(unsigned size, unsigned offset,
        uint64_t access);

// ----- Public ---------------------------------------------------------------

// Set the register properties and add children bitfields from the
// info structure.
Object *peripheral_register_add_properties_and_children(Object *obj,
        PeripheralRegisterInfo *info)
{
    // After properties are set to default values by .instance_init,
    // copy actual values from info.

    PeripheralState *parent = PERIPHERAL_STATE(cm_object_get_parent(obj));

    cm_object_property_set_int(obj, info->offset_bytes, "offset-bytes");

    if (info->reset_value != 0) {
        cm_object_property_set_int(obj, info->reset_value, "reset-value");
    }
    if (info->reset_mask != 0) {
        cm_object_property_set_int(obj, info->reset_mask, "reset-mask");
    }
    if (info->readable_bits != 0) {
        cm_object_property_set_int(obj, info->readable_bits, "readable-bits");
    }
    if (info->writable_bits != 0) {
        cm_object_property_set_int(obj, info->writable_bits, "writable-bits");
    }
    uint64_t access_flags = 0;
    if (info->access_flags != 0) {
        access_flags = info->access_flags;
    } else {
        if (parent->default_access_flags != 0) {
            access_flags = parent->default_access_flags;
        } else {
            access_flags = PERIPHERAL_REGISTER_DEFAULT_ACCESS_FLAGS;
        }
    }
    cm_object_property_set_int(obj, access_flags, "access-flags");

    int size_bits = 0;
    if (info->size_bits != 0) {
        size_bits = info->size_bits;
    } else {
        if (parent->register_size_bytes != 0) {
            size_bits = parent->register_size_bytes * 8;
        } else {
            size_bits = PERIPHERAL_REGISTER_DEFAULT_SIZE_BYTES;
        }
    }
    cm_object_property_set_int(obj, size_bits, "size-bits");

    if (info->rw_mode != 0) {
        if (info->rw_mode & REGISTER_RW_MODE_READ) {
            cm_object_property_set_bool(obj, true, "is-readable");
        } else {
            cm_object_property_set_bool(obj, false, "is-readable");
        }
        if (info->rw_mode & REGISTER_RW_MODE_WRITE) {
            cm_object_property_set_bool(obj, true, "is-writable");
        } else {
            cm_object_property_set_bool(obj, false, "is-writable");
        }
    } else {
        cm_object_property_set_bool(obj, true, "is-readable");
        cm_object_property_set_bool(obj, true, "is-writable");
    }

    if (info->bitfields) {
        RegisterBitfieldInfo *bifi_info;
        for (bifi_info = info->bitfields; bifi_info->name; ++bifi_info) {

            Object *bifi = cm_object_new(obj, bifi_info->name,
            TYPE_REGISTER_BITFIELD);

            cm_object_property_set_str(bifi, bifi_info->name, "name");

            register_bitfield_add_properties_and_children(bifi, bifi_info);

            // Should we delay until the register is realized()?
            cm_object_realize(bifi);
        }
    }

    return obj;
}

// Internal structure with temporary storage,
// used to compute the auto_bits array.
typedef struct {
    peripheral_register_t left_shift_follows_masks[sizeof(peripheral_register_t)
            * 8];
    peripheral_register_t right_shift_follows_masks[sizeof(peripheral_register_t)
            * 8];

    peripheral_register_t left_shift_cleared_by_masks[sizeof(peripheral_register_t)
            * 8];
    peripheral_register_t right_shift_cleared_by_masks[sizeof(peripheral_register_t)
            * 8];

    peripheral_register_t left_shift_set_by_masks[sizeof(peripheral_register_t)
            * 8];
    peripheral_register_t right_shift_set_by_masks[sizeof(peripheral_register_t)
            * 8];

    const char *to_find_bifi;
    RegisterBitfieldState *found_bifi;

    PeripheralRegisterState *reg;
    Error *local_err;
} PeripheralRegisterAutoTmp;

void peripheral_register_compute_auto_bits(Object *obj)
{
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(obj);

    // Scan children bitfields to identify those that follow other
    // bitfields. Compute the signed distance between bitfields
    // and for each distance accumulate a bitmask.

    PeripheralRegisterAutoTmp *auto_tmp = g_malloc0(
            sizeof(PeripheralRegisterAutoTmp));
    auto_tmp->reg = state;

    state->auto_bits = NULL;

    int ret;
    ret = object_child_foreach(obj, peripheral_register_create_auto_array,
            (void *) auto_tmp);

    if (ret) {
        if (auto_tmp->local_err) {
            error_report_err(auto_tmp->local_err);
            exit(1);
        }
    } else {
        int count = 0;
        int i;
        for (i = 0; i < sizeof(peripheral_register_t) * 8; ++i) {
            if (auto_tmp->left_shift_follows_masks[i] != 0) {
                count++;
            }
            if (auto_tmp->right_shift_follows_masks[i] != 0) {
                count++;
            }
            if (auto_tmp->left_shift_cleared_by_masks[i] != 0) {
                count++;
            }
            if (auto_tmp->right_shift_cleared_by_masks[i] != 0) {
                count++;
            }
            if (auto_tmp->left_shift_set_by_masks[i] != 0) {
                count++;
            }
            if (auto_tmp->right_shift_set_by_masks[i] != 0) {
                count++;
            }
        }

        if (count) {
            count++; // One more for the terminator.
            PeripheralRegisterAutoBits *auto_bits = g_malloc_n(count,
                    sizeof(PeripheralRegisterAutoBits));

            PeripheralRegisterAutoBits *p = auto_bits;

            for (i = 0; i < sizeof(peripheral_register_t) * 8; ++i) {
                if (auto_tmp->left_shift_follows_masks[i] != 0) {
                    p->mask = auto_tmp->left_shift_follows_masks[i];
                    p->shift = i;
                    p->type = PERIPHERAL_REGISTER_AUTO_BITS_TYPE_FOLLOWS;
                    ++p;
                }
                if (auto_tmp->right_shift_follows_masks[i] != 0) {
                    p->mask = auto_tmp->right_shift_follows_masks[i];
                    p->shift = -i;
                    p->type = PERIPHERAL_REGISTER_AUTO_BITS_TYPE_FOLLOWS;
                    ++p;
                }
                if (auto_tmp->left_shift_cleared_by_masks[i] != 0) {
                    p->mask = auto_tmp->left_shift_cleared_by_masks[i];
                    p->shift = i;
                    p->type = PERIPHERAL_REGISTER_AUTO_BITS_TYPE_CLEARED_BY;
                    ++p;
                }
                if (auto_tmp->right_shift_cleared_by_masks[i] != 0) {
                    p->mask = auto_tmp->right_shift_cleared_by_masks[i];
                    p->shift = -i;
                    p->type = PERIPHERAL_REGISTER_AUTO_BITS_TYPE_CLEARED_BY;
                    ++p;
                }
                if (auto_tmp->left_shift_set_by_masks[i] != 0) {
                    p->mask = auto_tmp->left_shift_set_by_masks[i];
                    p->shift = i;
                    p->type = PERIPHERAL_REGISTER_AUTO_BITS_TYPE_SET_BY;
                    ++p;
                }
                if (auto_tmp->right_shift_set_by_masks[i] != 0) {
                    p->mask = auto_tmp->right_shift_set_by_masks[i];
                    p->shift = -i;
                    p->type = PERIPHERAL_REGISTER_AUTO_BITS_TYPE_SET_BY;
                    ++p;
                }
            }

            // End of array.
            p->mask = 0;
            p->shift = 0;

            state->auto_bits = auto_bits;
        }
    }
    g_free(auto_tmp);
}

// ----------------------------------------------------------------------------

// Return the readable bits of the register.
peripheral_register_t peripheral_register_read_value(Object* obj)
{
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(obj);

    return (state->value & state->readable_bits);
}

void peripheral_register_write_value(Object* obj, peripheral_register_t value)
{
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(obj);

    state->value = value & state->writable_bits;
}

// Return the full register, as is.
peripheral_register_t peripheral_register_get_raw_value(Object* obj)
{
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(obj);

    return state->value;
}

void peripheral_register_set_raw_value(Object* obj, peripheral_register_t value)
{
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(obj);

    state->value = value;
}

void peripheral_register_or_raw_value(Object* obj, peripheral_register_t value)
{
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(obj);

    state->value |= value;
}

void peripheral_register_and_raw_value(Object* obj, peripheral_register_t value)
{
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(obj);

    state->value &= value;
}

peripheral_register_t peripheral_register_get_raw_prev_value(Object* obj)
{
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(obj);

    return state->prev_value;
}

void peripheral_register_set_pre_write(Object* obj,
        register_pre_write_callback_t ptr)
{
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(obj);

    state->pre_write = ptr;
}

void peripheral_register_set_post_write(Object* obj,
        register_post_write_callback_t ptr)
{
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(obj);

    state->post_write = ptr;
}

void peripheral_register_set_pre_read(Object* obj, register_read_callback_t ptr)
{
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(obj);

    state->pre_read = ptr;
}

void peripheral_register_set_post_read(Object* obj,
        register_post_read_callback_t ptr)
{
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(obj);

    state->post_read = ptr;
}

// ----- Private --------------------------------------------------------------

// Validate the access, using the bits defined for each register.
// Each byte encodes one size and inside the byte each bit encodes
// one unaligned offset.
static int peripheral_register_check_access(unsigned size, unsigned offset,
        uint64_t access)
{
    if ((access >> (8 * ((size - 1) & 7))) & (1 << (offset & 7))) {
        return true;
    }

    return false;
}

// Structure used to process endianness.
// It overlaps a long long with an array of bytes.
typedef union {
    peripheral_register_t ll;
    uint8_t b[sizeof(peripheral_register_t)];
} EndiannessUnion;

peripheral_register_t peripheral_register_shorten(peripheral_register_t value,
        uint32_t offset, unsigned size, bool is_little_endian)
{
    EndiannessUnion tmp;
    tmp.ll = value;

    EndiannessUnion result;
    result.ll = 0; /* Start with a zero value. */

    // Copy 'size' bytes from register to response.
    // The other bytes remain zero.
    // Working at byte level, it copes well with any alignment.

    int i;
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    if (is_little_endian) {
        for (i = 0; i < size; ++i) {
            // Source: little-endian (guest register)
            // Destination: little-endian (host result)
            result.b[i] = tmp.b[i + offset];
        }
    } else {
        // Source: big-endian (guest register)
        // Destination: little-endian (host result)
        for (i = 0; i < size; ++i) {
            result.b[i] = tmp.b[8 - (i + offset)];
        }
    }
#else
    // Warning: Not tested!
    if (periph_state->is_little_endian) {
        for (i = 0; i < size; ++i) {
            // Source: little-endian (guest register)
            // Destination: big-endian (host result)
            result.b[8 - i] = tmp.b[i + offset];
        }
    } else {
        for (i = 0; i < size; ++i) {
            // Source: big-endian (guest register)
            // Destination: big-endian (host result)
            result.b[8 - i] = tmp.b[8 - (i + offset)];
        }
    }
#endif
    return result.ll;
}

peripheral_register_t peripheral_register_widen(peripheral_register_t old_value,
        peripheral_register_t value, uint32_t offset, unsigned size,
        bool is_little_endian)
{
    EndiannessUnion in_value;
    in_value.ll = value;

    EndiannessUnion new_value;
    new_value.ll = old_value; /* Start with the original value. */

    // Overwrite 'size' bytes in new_value with bytes from in_value.
    // The other bytes remain with their original values.
    // Working at byte level, it copes well with any alignment.
    int i;
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    if (is_little_endian) {
        for (i = 0; i < size; ++i) {
            // Source: little-endian (host in value)
            // Destination: little-endian (guest register)
            new_value.b[i + offset] = in_value.b[i];
        }
    } else {
        for (i = 0; i < size; ++i) {
            // Source: little-endian (host in value)
            // Destination: big-endian (guest register)
            new_value.b[8 - (i + offset)] = in_value.b[i];
        }
    }
#else
    // Warning: Not tested!
    if (periph_state->is_little_endian) {
        for (i = 0; i < size; ++i) {
            // Source: big-endian (host in value)
            // Destination: little-endian (guest register)
            new_value.b[i + offset] = in_value.b[8 - i];
        }
    } else {
        for (i = 0; i < size; ++i) {
            // Source: big-endian (host in value)
            // Destination: big-endian (guest register)
            new_value.b[8 - (i + offset)] = in_value.b[8 - i];
        }
    }
#endif
    return new_value.ll;
}

// ----- Private --------------------------------------------------------------

static peripheral_register_t peripheral_register_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(reg);
    PeripheralState *periph_state = PERIPHERAL_STATE(periph);

    // Validate alignment
    if (!peripheral_register_check_access(size, offset, state->access_flags)) {
        qemu_log_mask(LOG_GUEST_ERROR,
                "%s: Peripheral register read of size %d at offset " "0x%"PRIX32" not aligned.\n",
                object_get_typename(OBJECT(state)), size, addr);
        return 0;
    }

    // Specific actions required to get the actual values are implemented
    // with pre read callbacks. These should prepare the value in the
    // register.

    if (state->pre_read) {
        peripheral_register_t new_value;
        new_value = state->pre_read(reg, periph, addr, offset, size);

#if 0
        // This complicated thing is most probably an error.
        state->value &= (new_value & state->readable_bits);
        state->value |= (new_value & state->readable_bits);
#else
        state->value = (new_value & state->readable_bits);
#endif
    }

    peripheral_register_t ret = peripheral_register_shorten(
            state->value & state->readable_bits, offset, size,
            periph_state->is_little_endian);

    if (state->post_read) {
        state->post_read(reg, periph, addr, offset, size);
    }

#if 1
    qemu_log_mask(LOG_FUNC, "%s('%s','%s',0x%04X,%u,%u)=0x%"PRIX64"\n",
            __func__, state->name, periph_state->mmio_node_name, addr, offset,
            size, ret);
#endif

    return ret;
}

static void peripheral_register_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value)
{
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(reg);
    PeripheralState *periph_state = PERIPHERAL_STATE(periph);

    qemu_log_mask(LOG_FUNC, "%s('%s','%s',0x%04X,%u,%u,0x%"PRIX64")\n",
            __func__, state->name, periph_state->mmio_node_name, addr, offset,
            size, value);

    // Validate alignment
    if (!peripheral_register_check_access(size, offset, state->access_flags)) {
        qemu_log_mask(LOG_GUEST_ERROR,
                "%s: Peripheral register write of size %d at offset " "0x%"PRIX32" not aligned.\n",
                object_get_typename(OBJECT(state)), size, addr);
        return;
    }

    peripheral_register_t new_value = peripheral_register_widen(state->value,
            value, offset, size, periph_state->is_little_endian);

    peripheral_register_t full_value;
    // Clear all writable bits, preserve the rest.
    full_value = state->value & (~state->writable_bits);
    // Set all writable bits with the new values.
    full_value |= (new_value & state->writable_bits);

    PeripheralRegisterAutoBits *auto_bits;
    for (auto_bits = state->auto_bits; auto_bits && auto_bits->mask;
            auto_bits++) {
        if (auto_bits->type == PERIPHERAL_REGISTER_AUTO_BITS_TYPE_FOLLOWS) {
            // Clear the linked bits and copy those from the referred bits.
            if (auto_bits->shift > 0) {
                full_value &= ~(auto_bits->mask << auto_bits->shift);
                full_value |= ((full_value & auto_bits->mask)
                        << auto_bits->shift);
            } else if (auto_bits->shift < 0) {
                full_value &= ~(auto_bits->mask >> auto_bits->shift);
                full_value |= ((full_value & auto_bits->mask)
                        >> auto_bits->shift);
            }
        } else if (auto_bits->type
                == PERIPHERAL_REGISTER_AUTO_BITS_TYPE_CLEARED_BY) {
            // If the referred bits are set, clear the linked bits.
            if (auto_bits->shift > 0) {
                full_value &= ~((full_value & auto_bits->mask)
                        << auto_bits->shift);
            } else if (auto_bits->shift < 0) {
                full_value &= ~((full_value & auto_bits->mask)
                        >> auto_bits->shift);
            }
        } else if (auto_bits->type
                == PERIPHERAL_REGISTER_AUTO_BITS_TYPE_SET_BY) {
            // If the referred bits are set, set the linked bits.
            if (auto_bits->shift > 0) {
                full_value |= ((full_value & auto_bits->mask)
                        << auto_bits->shift);
            } else if (auto_bits->shift < 0) {
                full_value |= ((full_value & auto_bits->mask)
                        >> auto_bits->shift);
            }
        }
    }

    state->prev_value = state->value;

    if (state->pre_write) {
        state->value = state->pre_write(reg, periph, addr, offset, size, value,
                full_value);
    } else {
        state->value = full_value;
    }

    // Actions associated with registers are implemented with post write
    // callbacks. The original value, possibly short and unaligned, is
    // passed first, then the full register value.

    if (state->post_write) {
        state->post_write(reg, periph, addr, offset, size, value, full_value);
    }
}

// ----------------------------------------------------------------------------

static void peripheral_register_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(obj);

    // Add properties and set the default values.

    cm_object_property_add_const_str(obj, "name", &state->name);
    state->name = NULL;

    cm_object_property_add_uint32(obj, "offset-bytes", &state->offset_bytes);
    state->offset_bytes = 0x00000000;

    cm_object_property_add_uint64_callback(obj, "reset-value",
            &state->reset_value);
    state->reset_value = 0x0000000000000000;

    cm_object_property_add_uint64_callback(obj, "reset-mask",
            &state->reset_mask);
    state->reset_mask = 0xFFFFFFFFFFFFFFFF;

    cm_object_property_add_uint64_callback(obj, "readable-bits",
            &state->readable_bits);
    state->readable_bits = 0x0000000000000000;

    cm_object_property_add_uint64_callback(obj, "writable-bits",
            &state->writable_bits);
    state->writable_bits = 0x0000000000000000;

    cm_object_property_add_uint64_callback(obj, "access-flags",
            &state->access_flags);
    state->access_flags = PERIPHERAL_REGISTER_DEFAULT_ACCESS_FLAGS;

    cm_object_property_add_uint32(obj, "size-bits", &state->size_bits);
    /* Intentional 0. Default set again in realize(), possibly from parent. */
    state->size_bits = 0;

    cm_object_property_add_bool(obj, "is-readable", &state->is_readable);
    state->is_readable = true;

    cm_object_property_add_bool(obj, "is-writable", &state->is_writable);
    state->is_writable = true;

    cm_object_property_add_const_str(obj, "svd-size", &state->svd.size);
    state->svd.size = NULL;

    cm_object_property_add_const_str(obj, "svd-access", &state->svd.access);
    state->svd.access = NULL;

    cm_object_property_add_const_str(obj, "svd-protection",
            &state->svd.protection);
    state->svd.protection = NULL;

    cm_object_property_add_const_str(obj, "svd-reset-value",
            &state->svd.reset_value);
    state->svd.reset_value = NULL;

    cm_object_property_add_const_str(obj, "svd-reset-mask",
            &state->svd.reset_mask);
    state->svd.reset_mask = NULL;

    /* Reset value. */
    state->value = state->reset_value;

    state->auto_bits = NULL;

    state->pre_read = NULL;
    state->post_read = NULL;
    state->pre_write = NULL;
    state->post_write = NULL;
}

typedef struct {
    peripheral_register_t mask;
    peripheral_register_t readable_bits;
    peripheral_register_t writable_bits;
    PeripheralRegisterState *reg;
    Error *local_err;
} PeripheralRegisterValidateTmp;

// Create the auto_bits array, by concatenating masks of
// followed bitfields and grouping based on shift steps.

static int peripheral_register_validate_bitfields(Object *obj, void *opaque)
{
    PeripheralRegisterValidateTmp *validate_tmp =
            (PeripheralRegisterValidateTmp *) opaque;
    PeripheralRegisterState *reg = validate_tmp->reg;

    // Process only children that descend from a bitfield.
    if (cm_object_is_instance_of_typename(obj, TYPE_REGISTER_BITFIELD)) {
        RegisterBitfieldState *bifi = REGISTER_BITFIELD_STATE(obj);

        if (bifi->mask & validate_tmp->mask) {
            error_setg(&validate_tmp->local_err, "Bitfield %s of register %s  "
                    "overlaps with other bitfield.\n", bifi->name, reg->name);
            return 1;
        }

        // Collect more bits in the mask.
        validate_tmp->mask |= bifi->mask;

        // Collect readable bits.
        if (bifi->is_readable) {
            validate_tmp->readable_bits |= bifi->mask;
        }
        // Collect writable bits.
        if (bifi->is_writable) {
            validate_tmp->writable_bits |= bifi->mask;
        }

    }
    return 0; // Continue iterations.
}

// Find the followed bitfield among its siblings.
// Use the temporary structure to pass input/output values.
// When found, break the iteration.

static int peripheral_register_find_bifi(Object *obj, void *opaque)
{
    PeripheralRegisterAutoTmp *auto_tmp = (PeripheralRegisterAutoTmp *) opaque;

    // Process only children that descend from a bitfield.
    if (cm_object_is_instance_of_typename(obj, TYPE_REGISTER_BITFIELD)) {
        RegisterBitfieldState *bifi = REGISTER_BITFIELD_STATE(obj);

        if (strcmp(auto_tmp->to_find_bifi, bifi->name) == 0) {
            auto_tmp->found_bifi = bifi;
            return 1; // Break iterations.
        }
    }

    return 0; // Continue iterations.
}

// Create the auto_bits array, by concatenating masks of
// followed bitfields and grouping based on shift steps.
static int peripheral_register_create_auto_array(Object *obj, void *opaque)
{
    PeripheralRegisterAutoTmp *auto_tmp = (PeripheralRegisterAutoTmp *) opaque;
    PeripheralRegisterState *reg = auto_tmp->reg;

    // Process only children that descend from a bitfield.
    if (cm_object_is_instance_of_typename(obj, TYPE_REGISTER_BITFIELD)) {
        RegisterBitfieldState *bifi = REGISTER_BITFIELD_STATE(obj);

        if (bifi->follows) {
            // Find the followed bitfield.
            auto_tmp->to_find_bifi = bifi->follows;
            auto_tmp->found_bifi = NULL;

            // Try to find the followed bitfield among its siblings.
            object_child_foreach(OBJECT(reg), peripheral_register_find_bifi,
                    (void *) auto_tmp);

            if (auto_tmp->found_bifi == NULL) {
                error_setg(&auto_tmp->local_err,
                        "Bitfield %s of register %s follows "
                                "missing %s bitfield.\n", bifi->name, reg->name,
                        auto_tmp->to_find_bifi);
                return 1;
            }

            // Positive values means shift left, negative shift right.
            int delta_shift = bifi->first_bit - auto_tmp->found_bifi->first_bit;
            if (delta_shift > 0) {
                auto_tmp->left_shift_follows_masks[delta_shift] |=
                        auto_tmp->found_bifi->mask;
            } else if (delta_shift < 0) {
                auto_tmp->right_shift_follows_masks[-delta_shift] |=
                        auto_tmp->found_bifi->mask;
            }
        } else if (bifi->cleared_by) {
            // Find the .cleared_by bitfield.
            auto_tmp->to_find_bifi = bifi->cleared_by;
            auto_tmp->found_bifi = NULL;

            // Try to find the followed bitfield among its siblings.
            object_child_foreach(OBJECT(reg), peripheral_register_find_bifi,
                    (void *) auto_tmp);

            if (auto_tmp->found_bifi == NULL) {
                error_setg(&auto_tmp->local_err,
                        "Bitfield %s of register %s cleared by "
                                "missing %s bitfield.\n", bifi->name, reg->name,
                        auto_tmp->to_find_bifi);
                return 1;
            }

            // Positive values means shift left, negative shift right.
            int delta_shift = bifi->first_bit - auto_tmp->found_bifi->first_bit;
            if (delta_shift > 0) {
                auto_tmp->left_shift_cleared_by_masks[delta_shift] |=
                        auto_tmp->found_bifi->mask;
            } else if (delta_shift < 0) {
                auto_tmp->right_shift_cleared_by_masks[-delta_shift] |=
                        auto_tmp->found_bifi->mask;
            }
        } else if (bifi->set_by) {
            // Find the .set_by bitfield.
            auto_tmp->to_find_bifi = bifi->cleared_by;
            auto_tmp->found_bifi = NULL;

            // Try to find the followed bitfield among its siblings.
            object_child_foreach(OBJECT(reg), peripheral_register_find_bifi,
                    (void *) auto_tmp);

            if (auto_tmp->found_bifi == NULL) {
                error_setg(&auto_tmp->local_err,
                        "Bitfield %s of register %s set by "
                                "missing %s bitfield.\n", bifi->name, reg->name,
                        auto_tmp->to_find_bifi);
                return 1;
            }

            // Positive values means shift left, negative shift right.
            int delta_shift = bifi->first_bit - auto_tmp->found_bifi->first_bit;
            if (delta_shift > 0) {
                auto_tmp->left_shift_set_by_masks[delta_shift] |=
                        auto_tmp->found_bifi->mask;
            } else if (delta_shift < 0) {
                auto_tmp->right_shift_set_by_masks[-delta_shift] |=
                        auto_tmp->found_bifi->mask;
            }
        }
    }

    return 0; // Continue iterations.
}

static void peripheral_register_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_PERIPHERAL_REGISTER)) {
        return;
    }

    // By the time we reach here, the bitfields were already realized().
    // This also means the readable/writable masks might have been
    // updated.
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(dev);

    // The size should have been already computed by derived_realize(),
    // which is executed before this function.
    assert(state->size_bits != 0);

    int ret;
    // Scan bitfields and validate by checking if masks do not overlap.
    PeripheralRegisterValidateTmp *validate_tmp = g_malloc0(
            sizeof(PeripheralRegisterValidateTmp));
    validate_tmp->reg = state;
    validate_tmp->mask = 0;

    ret = object_child_foreach(OBJECT(dev),
            peripheral_register_validate_bitfields, (void *) validate_tmp);

    if (ret) {
        if (validate_tmp->local_err) {
            error_propagate(errp, validate_tmp->local_err);
        }
    }
    int has_bitfields = (validate_tmp->mask != 0);
    peripheral_register_t bitfields_readable_bits = validate_tmp->readable_bits;
    peripheral_register_t bitfields_writable_bits = validate_tmp->writable_bits;

    g_free(validate_tmp);

    if (ret) {
        return;
    }

    if (has_bitfields) {
        // If it has bitfields, to the defined readable/writable masks
        // the bitfields will contribute more bits.
        state->readable_bits |= bitfields_readable_bits;
        state->writable_bits |= bitfields_writable_bits;
    } else {
        // It has no bitfields, we might need to do our best to
        // determine if there are some bitmasks, otherwise set
        // them to allow all bits.
        if (state->readable_bits == 0 && state->is_readable) {
            // Default all bits readable.
            state->readable_bits = 0xFFFFFFFFFFFFFFFF;
        }

        if (state->writable_bits == 0 && state->is_writable) {
            // Default all bits writable.
            state->writable_bits = 0xFFFFFFFFFFFFFFFF;
        }
    }

    // Clear readable bits if entire register is non-readable.
    if (!state->is_readable) {
        state->readable_bits = 0;
    }

    // Clear writable bits if entire register is non-writable.
    if (!state->is_writable) {
        state->writable_bits = 0;
    }

    qemu_log_mask(LOG_FUNC,
            "%s() '%s', readable: 0x%08"PRIX64", writable: 0x%08"PRIX64", " "reset: 0x%08"PRIX64", mode: %s%s\n",
            __FUNCTION__, state->name, state->readable_bits,
            state->writable_bits, state->reset_value,
            state->is_readable ? "r" : "", state->is_writable ? "w" : "");
}

static void peripheral_register_reset_callback(DeviceState *dev)
{
    PeripheralRegisterState *state = PERIPHERAL_REGISTER_STATE(dev);

    qemu_log_mask(LOG_FUNC, "%s() '%s', reset: 0x%08"PRIX64"\n", __FUNCTION__,
            state->name, state->reset_value);

    // Call parent reset().
    cm_device_parent_reset(dev, TYPE_PERIPHERAL_REGISTER);

    // Clear the value according to the reset mask.
    state->value &= ~(state->reset_mask);

    // Copy bits from reset value.
    state->value |= (state->reset_value & state->reset_mask);
}

static void peripheral_register_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = peripheral_register_reset_callback;
    dc->realize = peripheral_register_realize_callback;

    PeripheralRegisterClass *pr_class = PERIPHERAL_REGISTER_CLASS(klass);
    pr_class->read = peripheral_register_read_callback;
    pr_class->write = peripheral_register_write_callback;
}

static const TypeInfo peripheral_register_type_info = {
    .name = TYPE_PERIPHERAL_REGISTER,
    .parent = TYPE_PERIPHERAL_REGISTER_PARENT,
    .instance_init = peripheral_register_instance_init_callback,
    .instance_size = sizeof(PeripheralRegisterState),
    .class_init = peripheral_register_class_init,
    .class_size = sizeof(PeripheralRegisterClass)
/**/
};

static void register_peripheral_register_types(void)
{
    type_register_static(&peripheral_register_type_info);
}

type_init(register_peripheral_register_types);

// ----------------------------------------------------------------------------

