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

#include <hw/cortexm/peripheral-register.h>
#include <hw/cortexm/register-bitfield.h>
#include <hw/cortexm/svd.h>
#include <hw/cortexm/helper.h>

/*
 * This file implements a register bitfield.
 * Up to 64-bits registers are supported.
 * Bitfield objects are always children of register objects.
 * Bitfields do not keep a separate value, but get it from the
 * parent register, by masking and shifting
 *
 * To simplify handling, it is possible to explicitly mark status or ready
 * bits to follow the value of other enable bits, present in the same
 * register.
 */

// ----- Public ---------------------------------------------------------------
// Set register bitfield properties from the info structure.
Object *register_bitfield_add_properties_and_children(Object *obj,
        RegisterBitfieldInfo *info)
{
    assert(info->first_bit < PERIPHERAL_REGISTER_MAX_SIZE_BITS);
    cm_object_property_set_int(obj, info->first_bit, "first-bit");

    assert(info->width_bits < PERIPHERAL_REGISTER_MAX_SIZE_BITS);
    if (info->width_bits) {
        cm_object_property_set_int(obj, info->width_bits, "width-bits");
    }

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
        // Leave both false, as set by the option defaults,
        // in bitfield realize() this dual condition is tested to
        // compute the actual values using parent values.
    }

    int size_bits = 0;
    PeripheralRegisterState *reg_state = PERIPHERAL_REGISTER_STATE(
            cm_object_get_parent(obj));
    size_bits = reg_state->size_bits;

    cm_object_property_set_int(obj, size_bits, "register-size-bits");

    return obj;
}

// Get the value of a bitfield. Bitfields do not keep a separate value,
// but get it from the parent register, by masking and shifting.
peripheral_register_t register_bitfield_read_value(Object* obj)
{
    assert(obj);

    PeripheralRegisterState *reg = PERIPHERAL_REGISTER_STATE(obj->parent);
    assert(reg);

    RegisterBitfieldState *state = REGISTER_BITFIELD_STATE(obj);

    return (reg->value & state->mask) >> state->shift;
}

// Return true if a bitfield is zero.
bool register_bitfield_is_zero(Object* obj)
{
    assert(obj);

    PeripheralRegisterState *reg = PERIPHERAL_REGISTER_STATE(obj->parent);
    assert(reg);

    RegisterBitfieldState *state = REGISTER_BITFIELD_STATE(obj);

    return (reg->value & state->mask) == 0;
}

// Return true if a bitfield is non-zero.
bool register_bitfield_is_non_zero(Object* obj)
{
    assert(obj);

    PeripheralRegisterState *reg = PERIPHERAL_REGISTER_STATE(obj->parent);
    assert(reg);

    RegisterBitfieldState *state = REGISTER_BITFIELD_STATE(obj);

    return (reg->value & state->mask) != 0;
}

// ----- Private --------------------------------------------------------------

static void register_bitfield_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    RegisterBitfieldState *state = REGISTER_BITFIELD_STATE(obj);

    // Add properties and set the default values.
    cm_object_property_add_const_str(obj, "name", &state->name);
    state->name = NULL;

    cm_object_property_add_uint32(obj, "register-size-bits",
            &state->register_size_bits);
    state->register_size_bits = 0;

    cm_object_property_add_uint32(obj, "first-bit", &state->first_bit);
    state->first_bit = 0;

    cm_object_property_add_uint32(obj, "width-bits", &state->width_bits);
    state->width_bits = 1;

    cm_object_property_add_bool(obj, "is-readable", &state->is_readable);
    state->is_readable = false; /* Computed in realize() */

    cm_object_property_add_bool(obj, "is-writable", &state->is_writable);
    state->is_writable = false; /* Computed in realize() */

    cm_object_property_add_const_str(obj, "follows", &state->follows);
    state->follows = NULL;

    cm_object_property_add_const_str(obj, "cleared-by", &state->cleared_by);
    state->cleared_by = NULL;

    cm_object_property_add_const_str(obj, "set-by", &state->set_by);
    state->set_by = NULL;

    cm_object_property_add_const_str(obj, "svd-access", &state->svd.access);
    state->svd.access = NULL;
}

static void register_bitfield_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_REGISTER_BITFIELD)) {
        return;
    }

    Object *parent = cm_object_get_parent(OBJECT(dev));
    assert(parent);

    RegisterBitfieldState *state = REGISTER_BITFIELD_STATE(dev);
    PeripheralRegisterState *reg = PERIPHERAL_REGISTER_STATE(parent);

    if (!cm_object_is_instance_of_typename(parent, TYPE_PERIPHERAL_REGISTER)) {
        if (errp) {
            error_setg(errp, "Bitfield %s not a child of register %s.\n",
                    state->name, reg->name);
            return;
        }
    }

    if (state->register_size_bits == 0) {
        state->register_size_bits = reg->size_bits;
    }

    assert(state->register_size_bits);
    assert(state->register_size_bits <= PERIPHERAL_REGISTER_MAX_SIZE_BITS);

    assert(state->first_bit < state->register_size_bits);
    assert(
            state->first_bit + state->width_bits - 1
                    < state->register_size_bits);

    state->shift = state->first_bit;

    // Compute a mask that covers all bitfield bits.
    // The mask is shifted to the bitfield real position and can be
    // used on the register value.
    peripheral_register_t mask = -1;
    mask >>= ((sizeof(peripheral_register_t) * 8) - state->width_bits);
    mask <<= state->shift;
    state->mask = mask;

    // Compute if readable/writable, based on bitfield and parent register.
    // The parent register was not realized yet.
    if ((!state->is_readable) && (!state->is_writable)) {
        // Bitfield mode bits not defined, get from register.

        if (!state->is_readable) {
            if (reg->readable_bits != 0) {
                // The register has some bits set, check the one specified
                // in the bitfield mask.
                if (reg->readable_bits & mask) {
                    state->is_readable = true;
                }
            } else {
                // Both register and field are not defined.
                // Default is readable.
                state->is_readable = true;
            }
        }

        if (!state->is_writable) {
            if (reg->writable_bits != 0) {
                // The register has some bits set, check the one specified
                // in the bitfield mask.
                if (reg->writable_bits & mask) {
                    state->is_writable = true;
                }
            } else {
                // Both register and field are not defined.
                // Default is writable.
                state->is_writable = true;
            }
        }
    }

    // Update back the register readable & writable bits
    if (state->is_readable) {
        if (!reg->is_readable) {
            error_setg(errp,
                    "Parent register of bitfield %s is not readable.\n",
                    state->name);
            return;
        }
    }

    if (state->is_writable) {
        if (!reg->is_writable) {
            error_setg(errp,
                    "Parent register of bitfield %s is not writable.\n",
                    state->name);
            return;
        }
    }

    qemu_log_mask(LOG_FUNC,
            "%s() '%s[%d:%d]', mask: 0x%"PRIX64", shift: %d, mode: %s%s\n",
            __FUNCTION__, state->name, state->first_bit + state->width_bits + 1,
            state->first_bit, state->mask, state->shift,
            state->is_readable ? "r" : "", state->is_writable ? "w" : "");
}

static void register_bitfield_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->realize = register_bitfield_realize_callback;
}

static const TypeInfo register_bitfield_type_info = {
    .name = TYPE_REGISTER_BITFIELD,
    .parent = TYPE_REGISTER_BITFIELD_PARENT,
    .instance_init = register_bitfield_instance_init_callback,
    .instance_size = sizeof(RegisterBitfieldState),
    .class_init = register_bitfield_class_init,
    .class_size = sizeof(RegisterBitfieldClass)
/**/
};

static void register_bitfield_register_types(void)
{
    type_register_static(&register_bitfield_type_info);
}

type_init(register_bitfield_register_types);

// ----------------------------------------------------------------------------

