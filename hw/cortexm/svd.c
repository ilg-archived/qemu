/*
 * Cortex-M SVD processing.
 *
 * Copyright (c) 2016 Liviu Ionescu.
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

#include <hw/cortexm/svd.h>
#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/helper.h>

#include "qemu/error-report.h"

void svd_validate_device_name(JSON_Object *svd, const char *name)
{
    assert(svd != NULL);
    assert(name != NULL);

    JSON_Object *device = json_object_get_object(svd, "device");
    if (device == NULL) {
        error_printf("SVD has no mandatory \"device\".\n");
        exit(1);
    }

    const char *svd_name = json_object_get_string(device, "name");
    if (svd_name == NULL) {
        error_printf("SVD device has no \"name\".\n");
        exit(1);
    }
    if (strcmp(svd_name, name) != 0) {
        error_printf("SVD device name \"%s\" != \"%s\".\n", svd_name, name);
        exit(1);
    }
}

JSON_Object *svd_get_peripheral_by_name(JSON_Object *svd, const char *name)
{
    JSON_Object *device = json_object_get_object(svd, "device");
    assert(device != NULL);

    JSON_Array *peripherals = json_object_get_array(device, "peripherals");
    size_t count = json_array_get_count(peripherals);
    int i;

    for (i = 0; i < count; ++i) {
        JSON_Object *peripheral = json_array_get_object(peripherals, i);
        const char *periph_name = json_object_get_string(peripheral, "name");
        if (strcmp(periph_name, name) == 0) {
            return peripheral;
        }
    }
    error_printf("Peripheral '%s' not found in JSON.\n", name);
    exit(1);
}

bool svd_has_named_peripheral(JSON_Object *svd, const char *name)
{
    JSON_Object *device = json_object_get_object(svd, "device");
    assert(device != NULL);

    JSON_Array *peripherals = json_object_get_array(device, "peripherals");
    size_t count = json_array_get_count(peripherals);
    int i;

    for (i = 0; i < count; ++i) {
        JSON_Object *peripheral = json_array_get_object(peripherals, i);
        const char *periph_name = json_object_get_string(peripheral, "name");
        if (strcmp(periph_name, name) == 0) {
            return true;
        }
    }
    return false;
}

void svd_set_rw_mode(Object *obj, const char *str)
{
    if (str != NULL) {
        if (strcmp(str, "read-only") == 0) {
            cm_object_property_set_bool(obj, true, "is-readable");
            cm_object_property_set_bool(obj, false, "is-writable");
        } else if (strcmp(str, "write-only") == 0) {
            cm_object_property_set_bool(obj, false, "is-readable");
            cm_object_property_set_bool(obj, true, "is-writable");
        } else if (strcmp(str, "read-write") == 0) {
            cm_object_property_set_bool(obj, true, "is-readable");
            cm_object_property_set_bool(obj, true, "is-writable");
        } else if (strcmp(str, "writeOnce") == 0) {
            // TODO: implement Once
            cm_object_property_set_bool(obj, false, "is-readable");
            cm_object_property_set_bool(obj, true, "is-writable");
        } else if (strcmp(str, "read-writeOnce") == 0) {
            // TODO: implement Once
            cm_object_property_set_bool(obj, true, "is-readable");
            cm_object_property_set_bool(obj, true, "is-writable");
        }
    }
}

void svd_set_register_properties_group(JSON_Object *svd, Object *obj)
{
    assert(svd != NULL);
    assert(obj != NULL);

    const char *str;

    // If NULL, the *_set_str() does nothing.
    str = json_object_get_string(svd, "size");
    cm_object_property_set_str(obj, str, "svd-size");

    str = json_object_get_string(svd, "access");
    cm_object_property_set_str(obj, str, "svd-access");

    str = json_object_get_string(svd, "protection");
    cm_object_property_set_str(obj, str, "svd-protection");

    str = json_object_get_string(svd, "resetValue");
    cm_object_property_set_str(obj, str, "svd-reset-value");

    str = json_object_get_string(svd, "resetMask");
    cm_object_property_set_str(obj, str, "svd-reset-mask");
}

Object *svd_add_peripheral_properties_and_children(Object *obj,
        JSON_Object *svd, JSON_Object *root)
{
    const char *str;

    str = json_object_get_string(svd, "name");
    // Store a local copy of the node name, for easier access.
    // Passing a parsed string is ok, it is copied.
    cm_object_property_set_str(obj, str, "name");

#if 0
    if (json_object_has_value_of_type(info, "default_access_flags",
                    JSONString)) {
        str = json_object_get_string(info, "default_access_flags");
        uint64_t access_flags = cm_json_parser_parse_access_flags(str);
        cm_object_property_set_int(obj, access_flags, "default-access-flags");
    }
#endif

#if 0
    if (json_object_has_value_of_type(info, "register_size_bytes",
                    JSONNumber)) {
        number = json_object_get_number(info, "register_size_bytes");
        cm_object_property_set_int(obj, (uint32_t) number,
                "register-size-bytes");
    }
#endif

    svd_set_register_properties_group(svd, obj);

    JSON_Array *clusters = json_object_get_array(svd, "clusters");
    if (clusters != NULL) {
        error_printf("clusters are not yet implemented.\n");
        exit(1);
    }

    JSON_Array *registers = json_object_get_array(svd, "registers");
    if (registers == NULL) {
        str = json_object_get_string(svd, "derivedFrom");
        if (str == NULL) {
            error_printf("Missing registers array.\n");
            exit(1);
        }
        JSON_Object *peripheral = svd_get_peripheral_by_name(root, str);
        if (peripheral == NULL) {
            error_printf("Missing derivedFrom %s.\n", str);
            exit(1);
        }
        registers = json_object_get_array(peripheral, "registers");
        if (registers == NULL) {
            error_printf("Missing registers array.\n");
            exit(1);
        }
    }

    size_t count = json_array_get_count(registers);
    int i;

    for (i = 0; i < count; ++i) {
        JSON_Object *regi = json_array_get_object(registers, i);

        const char *regi_name = json_object_get_string(regi, "name");

        // Create the register with exactly the SVD name
        // (usually uppercase).
        Object *reg = cm_object_new(obj, regi_name,
        TYPE_PERIPHERAL_REGISTER);

        // Store a local copy of the node name, for easier access.
        // Passing a parsed string is ok, it is copied.
        cm_object_property_set_str(reg, regi_name, "name");

        svd_add_peripheral_register_properties_and_children(reg, regi);

        cm_object_realize(reg);
    }

    return obj;
}

Object *svd_add_peripheral_register_properties_and_children(Object *obj,
        JSON_Object *svd)
{
    const char *str;
    uint32_t val32;

    str = json_object_get_string(svd, "addressOffset");
    if (str != NULL) {
        val32 = cm_json_parser_parse_uint(str);
        cm_object_property_set_int(obj, val32, "offset-bytes");
    } else {
        error_printf("Missing register offset_bytes.\n");
        exit(1);
    }

    svd_set_register_properties_group(svd, obj);

    str = cm_object_property_get_str_with_parent(obj, "svd-reset-value", NULL);
    if (str != NULL) {
        val32 = cm_json_parser_parse_uint(str);
        cm_object_property_set_int(obj, val32, "reset-value");
    }

    str = cm_object_property_get_str_with_parent(obj, "svd-reset-mask", NULL);
    if (str != NULL) {
        val32 = cm_json_parser_parse_uint(str);
        cm_object_property_set_int(obj, val32, "reset-mask");
    }

    int size_bits = 0;
    str = cm_object_property_get_str_with_parent(obj, "svd-size", NULL);
    if (str != NULL) {
        size_bits = cm_json_parser_parse_uint(str);
        cm_object_property_set_int(obj, size_bits, "size-bits");
    }

    str = cm_object_property_get_str_with_parent(obj, "svd-access", NULL);
    if (str != NULL) {
        svd_set_rw_mode(obj, str);
    }

    JSON_Array *bitfields = json_object_get_array(svd, "fields");
    if (bitfields != NULL) {
        size_t count = json_array_get_count(bitfields);
        int i;

        for (i = 0; i < count; ++i) {
            JSON_Object *bitfield = json_array_get_object(bitfields, i);

            const char *bifi_name = json_object_get_string(bitfield, "name");

            // Passing a parsed string is ok, it is used to as an
            // index in a table.
            Object *obifi = cm_object_new(obj, bifi_name,
            TYPE_REGISTER_BITFIELD);

            // Passing a parsed string is ok, it is copied.
            cm_object_property_set_str(obifi, bifi_name, "name");

            svd_add_register_bitfield_properties_and_children(obifi, bitfield);

            /* Should we delay until the register is realized()? */
            cm_object_realize(obifi);
        }
    } else {
#if 0
        if (json_object_has_value_of_type(svd, "readable_bits", JSONString)) {
            str = json_object_get_string(svd, "readable_bits");
            val32 = cm_json_parser_parse_hex(str);
            cm_object_property_set_int(obj, val32, "readable-bits");
        }

        if (json_object_has_value_of_type(svd, "writable_bits", JSONString)) {
            str = json_object_get_string(svd, "writable_bits");
            val32 = cm_json_parser_parse_hex(str);
            cm_object_property_set_int(obj, val32, "writable-bits");
        }
#endif

#if 0
        uint64_t access_flags = 0;
        if (json_object_has_value_of_type(svd, "access_flags", JSONString)) {
            str = json_object_get_string(svd, "access_flags");
            access_flags = cm_json_parser_parse_access_flags(str);
        } else {
            if (parent->default_access_flags != 0) {
                access_flags = parent->default_access_flags;
            } else {
                access_flags = PERIPHERAL_REGISTER_DEFAULT_ACCESS_FLAGS;
            }
        }
        cm_object_property_set_int(obj, access_flags, "access-flags");
#endif

    }

    return obj;
}

Object *svd_add_register_bitfield_properties_and_children(Object *obj,
        JSON_Object *svd)
{
    const char *str;
    uint32_t val32;

    str = json_object_get_string(svd, "bitOffset");
    if (str != NULL) {
        val32 = cm_json_parser_parse_uint(str);
        assert(val32 < PERIPHERAL_REGISTER_MAX_SIZE_BITS);
        cm_object_property_set_int(obj, val32, "first-bit");
    }

    str = json_object_get_string(svd, "bitWidth");
    if (str != NULL) {
        val32 = cm_json_parser_parse_uint(str);
        assert(val32 < PERIPHERAL_REGISTER_MAX_SIZE_BITS);
        cm_object_property_set_int(obj, val32, "width-bits");
    }

    str = json_object_get_string(svd, "access");
    // Passing a parsed string is ok, it is copied.
    cm_object_property_set_str(obj, str, "svd-access");

    str = cm_object_property_get_str_with_parent(obj, "svd-access", NULL);
    if (str != NULL) {
        svd_set_rw_mode(obj, str);
    }

    int size_bits = 0;
    PeripheralRegisterState *reg_state = PERIPHERAL_REGISTER_STATE(
            cm_object_get_parent(obj));
    size_bits = reg_state->size_bits;

    cm_object_property_set_int(obj, size_bits, "register-size-bits");

    return obj;
}

