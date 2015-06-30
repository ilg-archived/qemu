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

#include "hw/misc/peripheral-register.h"
#include "hw/misc/register-bitfield.h"
#include "hw/arm/cortexm-helper.h"

/**
 * This file implements a register bitfield.
 * Up to 64-bits registers are supported.
 * Bitfield objects are always children of register objects.
 *
 * To simplify handling, it is possible to explicitly mark status or ready
 * bits to follow the value of other enable bits, present in the same
 * register.
 */

/* ----- Public ------------------------------------------------------------ */

/**
 * Get the value of a bitfield, shifted to the right.
 */
uint64_t register_bitfield_get_value(Object* obj)
{

    PeripheralRegisterState *reg_state = PERIPHERAL_REGISTER_STATE(obj->parent);
    RegisterBitfieldState *state = REGISTER_BITFIELD_STATE(obj);

    return (reg_state->value >> state->shift) & state->mask;
}

/**
 * Return true if a bitfield is zero.
 */
bool register_bitfield_is_zero(Object* obj)
{

    PeripheralRegisterState *reg_state = PERIPHERAL_REGISTER_STATE(obj->parent);
    RegisterBitfieldState *state = REGISTER_BITFIELD_STATE(obj);

    return (reg_state->value & state->mask) == 0;
}

/* ----- Private ----------------------------------------------------------- */

static void register_bitfield_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    RegisterBitfieldState *state = REGISTER_BITFIELD_STATE(obj);

    /*
     * Add properties and set the default values.
     */
    cm_object_property_add_const_str(obj, "name", &state->name);
    state->name = NULL;

    cm_object_property_add_uint32(obj, "register-size-bits",
            &state->register_size_bits);
    state->register_size_bits = 0;

    cm_object_property_add_uint32(obj, "first-bit", &state->first_bit);
    state->first_bit = 0;

    cm_object_property_add_uint32(obj, "last-bit", &state->last_bit);
    state->last_bit = 0;

    cm_object_property_add_uint64(obj, "reset-value", &state->reset_value);
    state->reset_value = 0;

    cm_object_property_add_bool(obj, "is-readable", &state->is_readable);
    state->is_readable = false; /* Computed in realize() */

    cm_object_property_add_bool(obj, "is-writable", &state->is_writable);
    state->is_writable = false; /* Computed in realize() */

    cm_object_property_add_const_str(obj, "follows", &state->follows);
    state->follows = NULL;
}

static void register_bitfield_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /* Call parent realize(). */
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
    assert(state->register_size_bits <= 64);

    if (state->first_bit != 0 && state->last_bit == 0) {
        /* Implicit single bit field. */
        state->last_bit = state->first_bit;
    }

    /*
     * First bit must be the lowest bit in the register.
     * If not, switch values.
     */
    if (state->first_bit > state->last_bit) {
        uint32_t tmp = state->first_bit;
        state->first_bit = state->last_bit;
        state->last_bit = tmp;
    }

    assert(state->first_bit < state->register_size_bits);
    assert(state->last_bit < state->register_size_bits);

    state->shift = state->first_bit;

    /*
     * Compute a mask that covers all bitfield bits.
     */
    uint64_t mask = -1;
    mask >>= (64 - 1 - (state->last_bit - state->first_bit));
    mask <<= state->shift;
    /* The mask is shifted to the bitfield real position. */
    state->mask = mask;

    /*
     * Compute if readable/writable, based on bitfield and parent register.
     */
    if ((!state->is_readable) && (!state->is_writable)) {
        /* Bitfield mode bits not defined, get from register. */

        if (!state->is_readable) {
            if (reg->readable_bits != 0) {
                /*
                 * The register has some bits set, check the one specified
                 * in the bitfield mask.
                 */
                if (reg->readable_bits & mask) {
                    state->is_readable = true;
                }
            } else {
                /*
                 * Both register and field are not defined.
                 * Default is readable.
                 */
                state->is_readable = true;
            }
        }

        if (!state->is_writable) {
            if (reg->writable_bits != 0) {
                /*
                 * The register has some bits set, check the one specified
                 * in the bitfield mask.
                 */
                if (reg->writable_bits & mask) {
                    state->is_writable = true;
                }
            } else {
                /*
                 * Both register and field are not defined.
                 * Default is writable.
                 */
                state->is_writable = true;
            }
        }
    }

    /* Update back the register readable & writable bits */
    if (state->is_readable) {
        if (!reg->is_readable) {
            error_setg(errp,
                    "Parent register of bitfield %s is not readable.\n",
                    state->name);
            return;
        }
        reg->readable_bits |= mask;
    } else {
        reg->readable_bits &= (~mask);
    }

    if (state->is_writable) {
        if (!reg->is_writable) {
            error_setg(errp,
                    "Parent register of bitfield %s is not writable.\n",
                    state->name);
            return;
        }
        reg->writable_bits |= mask;
    } else {
        reg->writable_bits &= (~mask);
    }

    /*
     * Compute bitfield reset value, possibly using parent.
     * The reset value is right aligned.
     */
    if (state->reset_value == 0) {
        /* Bitfield reset value not defined (or 0), get from register */
        if (reg->reset_value & mask) {
            state->reset_value = (reg->reset_value & mask) >> state->shift;
        }
    }

    /* Update back the register reset value. */
    reg->reset_value &= (~mask);
    reg->reset_value |= ((state->reset_value << state->shift) & mask);
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
    .class_size = sizeof(RegisterBitfieldClass) };

static void register_bitfield_register_types(void)
{
    type_register_static(&register_bitfield_type_info);
}

type_init(register_bitfield_register_types);

/* ------------------------------------------------------------------------- */

