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

#include "hw/misc/bitfield.h"
#include "hw/misc/register.h"
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

uint64_t bitfield_get_value(Object* obj)
{

    RegisterState *reg_state = REGISTER_STATE(obj->parent);
    BitfieldState *state = BITFIELD_STATE(obj);

    return (reg_state->value >> state->shift) & state->mask;
}

bool bitfield_is_zero(Object* obj)
{

    RegisterState *reg_state = REGISTER_STATE(obj->parent);
    BitfieldState *state = BITFIELD_STATE(obj);

    return (reg_state->value & state->mask) == 0;
}

/* ----- Private ----------------------------------------------------------- */

#if 0
static void bitfield_instance_init(Object *obj)
{
    qemu_log_function_name();

    BitfieldState *state = BITFIELD_STATE(obj);

    /* ... */
}
#endif

static void bitfield_realize(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /* Call parent realize(). */
    if (!cm_device_parent_realize(dev, errp, TYPE_BITFIELD)) {
        return;
    }

    Object *parent = OBJECT(dev)->parent;
    assert(parent);

    if (strcmp(TYPE_REGISTER, object_get_typename(parent)) != 0) {
        if (errp) {
            error_setg(errp, "Bitfield not a child of register\n.");
            return;
        }
    }
    RegisterState *reg_state = REGISTER_STATE(parent);

    BitfieldState *state = BITFIELD_STATE(dev);
    assert(state->register_size_bits);
    assert(state->register_size_bits <= 64);

    if (state->first_bit != 0 && state->last_bit == 0) {
        /* Single bit field. */
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

    state->shift = state->first_bit;

    /* Compute a mask that covers all bitfield bits. */
    uint64_t mask = -1;
    mask >>= (64 - 1 - (state->last_bit - state->first_bit));
    mask <<= state->shift;
    state->mask = mask;

    if ((!state->is_readable) && (!state->is_writable)) {
        /* Bitfield mode bits not defined, get from register. */

        if (!state->is_readable) {
            if (reg_state->readable_bits != 0) {
                if (reg_state->readable_bits & mask) {
                    state->is_readable = true;
                }
            } else {
                /* Both register and field are not defined. Default is readable */
                state->is_readable = true;
            }
        }

        if (!state->is_writable) {
            if (reg_state->writable_bits == 0) {
                if (reg_state->writable_bits & mask) {
                    state->is_writable = true;
                }
            } else {
                /* Both register and field are not defined. Default is writable */
                state->is_writable = true;
            }
        }
    }

    /* Update back the register readable & writable bits */
    if (state->is_readable) {
        reg_state->readable_bits |= mask;
    }

    if (state->is_writable) {
        reg_state->writable_bits |= mask;
    }

    if (state->reset_value == 0) {
        /* Bitfield reset value not defined (or 0), get from register */
        if (reg_state->reset_value & mask) {
            state->reset_value = (reg_state->reset_value & mask)
                    >> state->shift;
        }
    }

    /* Update back the register reset value. */
    reg_state->reset_value &= (~mask);
    reg_state->reset_value |= (state->reset_value << state->shift);
}

static Property bitfield_properties[] = {

        DEFINE_PROP_UINT32("register-size-bits", BitfieldState,
                register_size_bits, 32),
        DEFINE_PROP_UINT32("first-bit", BitfieldState, first_bit, 0),
        DEFINE_PROP_UINT32("last-bit", BitfieldState, last_bit, 0),
        DEFINE_PROP_UINT64("reset-value", BitfieldState, reset_value, 0x0),
        DEFINE_PROP_BOOL("is-readable", BitfieldState, is_readable,
                false),
        DEFINE_PROP_BOOL("is-writable", BitfieldState, is_writable,
                false),
        DEFINE_PROP_CONST_STRING("follows", BitfieldState, follows),

    DEFINE_PROP_END_OF_LIST(), };

static void bitfield_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->realize = bitfield_realize;
    dc->props = bitfield_properties;
}

static const TypeInfo bitfield_type_info = {
    .name = TYPE_BITFIELD,
    .parent = TYPE_BITFIELD_PARENT,
    //.instance_init = bitfield_instance_init,
    .instance_size = sizeof(BitfieldState),
    .class_init = bitfield_class_init,
    .class_size = sizeof(BitfieldClass) };

static void bitfield_register_types(void)
{
    type_register_static(&bitfield_type_info);
}

type_init(bitfield_register_types);

/* ------------------------------------------------------------------------- */

