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
        val32 = svd_parse_uint(str);
        cm_object_property_set_int(obj, val32, "offset-bytes");
    } else {
        error_printf("Missing register offset_bytes.\n");
        exit(1);
    }

    svd_set_register_properties_group(svd, obj);

    str = cm_object_property_get_str_with_parent(obj, "svd-reset-value", NULL);
    if (str != NULL) {
        val32 = svd_parse_uint(str);
        cm_object_property_set_int(obj, val32, "reset-value");
    }

    str = cm_object_property_get_str_with_parent(obj, "svd-reset-mask", NULL);
    if (str != NULL) {
        val32 = svd_parse_uint(str);
        cm_object_property_set_int(obj, val32, "reset-mask");
    }

    int size_bits = 0;
    str = cm_object_property_get_str_with_parent(obj, "svd-size", NULL);
    if (str != NULL) {
        size_bits = svd_parse_uint(str);
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

            // Should we delay until the register is realized()?
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
        val32 = svd_parse_uint(str);
        assert(val32 < PERIPHERAL_REGISTER_MAX_SIZE_BITS);
        cm_object_property_set_int(obj, val32, "first-bit");
    }

    str = json_object_get_string(svd, "bitWidth");
    if (str != NULL) {
        val32 = svd_parse_uint(str);
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

void svd_set_peripheral_address_block(JSON_Object *svd, const char* name,
        Object *obj)
{
    const char *str;

    uint32_t size = 0;
    hwaddr addr = 0;

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);

    str = json_object_get_string(periph, "baseAddress");
    if (str == NULL) {
        error_printf("Missing baseAddress array.\n");
        exit(1);
    }
    addr = svd_parse_uint(str);

    JSON_Array *address_blocks = json_object_get_array(periph, "addressBlocks");
    if (address_blocks == NULL) {
        str = json_object_get_string(periph, "derivedFrom");
        if (str == NULL) {
            error_printf("Missing derivedFrom for addressBlocks.\n");
            exit(1);
        }
        JSON_Object *peripheral = svd_get_peripheral_by_name(svd, str);
        if (peripheral == NULL) {
            error_printf("Missing derivedFrom %s.\n", str);
            exit(1);
        }
        address_blocks = json_object_get_array(peripheral, "addressBlocks");
        if (address_blocks == NULL) {
            error_printf("Missing addressBlocks array.\n");
            exit(1);
        }
    }

    size_t count = json_array_get_count(address_blocks);
    int i;

    for (i = 0; i < count; ++i) {
        JSON_Object *address_block = json_array_get_object(address_blocks, i);

        str = json_object_get_string(address_block, "usage");
        if (strcmp(str, "registers") == 0) {
            str = json_object_get_string(address_block, "offset");
            if (str == NULL) {
                error_printf("Missing addressBlock.offset.\n");
                exit(1);
            }
            addr += svd_parse_uint(str);

            str = json_object_get_string(address_block, "size");
            if (str == NULL) {
                error_printf("Missing addressBlock.size.\n");
                exit(1);
            }
            size = svd_parse_uint(str);

            assert(addr != 0);
            assert(size != 0);

            cm_object_property_set_int(obj, addr, "mmio-address");
            cm_object_property_set_int(obj, size, "mmio-size-bytes");

            return;
        }
    }

    error_printf("Missing addressBlock.usage=registers.\n");
    exit(1);
}

uint64_t svd_parse_uint(const char *str)
{
    assert(str != NULL);
    assert(strlen(str) > 0);

    uint64_t ret;
    int cnt;
    if (strncmp(str, "0x", 2) == 0) {
        cnt = sscanf(str, "0x%" PRIX64, &ret);
    } else if (strncmp(str, "0X", 2) == 0) {
        cnt = sscanf(str, "0X%" PRIX64, &ret);
    } else {
        cnt = sscanf(str, "%" PRIu64, &ret);
    }
    if (cnt != 1) {
        error_printf(
                "Cannot parse unsigned int from %s (must be 0x, 0X, nnn).\n",
                str);
        exit(1);
    }
    return ret;
}

bool svd_parse_bool(const char *str)
{
    assert(str != NULL);
    assert(strlen(str) > 0);

    if (strcmp(str, "true") == 0 || strcmp(str, "1") == 0) {
        return true;
    } else if (strcmp(str, "false") == 0 || strcmp(str, "0") == 0) {
        return false;
    } else {
        error_printf("Cannot parse bool from %s (must be true/false, 1/0).\n",
                str);
        exit(1);
    }
}

void svd_process_cpu(JSON_Object *svd, CortexMCoreCapabilities *core)
{
    assert(svd != NULL);
    assert(core != NULL);

    JSON_Object *device = json_object_get_object(svd, "device");
    assert(device != NULL);

    JSON_Object *cpu = json_object_get_object(device, "cpu");
    if (cpu == NULL) {
        error_printf("SVD device has no mandatory \"cpu\".\n");
        exit(1);
    }

    const char *str;

    str = json_object_get_string(cpu, "name");
    if (str == NULL) {
        error_printf("SVD device.cpu has no mandatory \"name\".\n");
        exit(1);
    }

    if (strcmp(str, "CM0") == 0) {
        core->cpu_model = "cortex-m0";
    } else if (strcmp(str, "CM0PLUS") == 0 || strcmp(str, "CM0+") == 0) {
        core->cpu_model = "cortex-m0p";
    } else if (strcmp(str, "CM1") == 0) {
        core->cpu_model = "cortex-m1";
    } else if (strcmp(str, "CM3") == 0) {
        core->cpu_model = "cortex-m3";
    } else if (strcmp(str, "CM4") == 0) {
        core->cpu_model = "cortex-m4";
    } else if (strcmp(str, "CM7") == 0) {
        core->cpu_model = "cortex-m7";
    } else {
        error_printf("SVD device.cpu unsupported \"name\"=%s.\n", str);
        exit(1);
    }

    str = json_object_get_string(cpu, "revision");
    if (str != NULL) {
        int major = 0;
        int minor = 0;
        if (sscanf(str, "r%dp%d", &major, &minor) != 2) {
            error_printf("SVD device.cpu unsupported \"revision\"=%s.\n", str);
            exit(1);
        }
        core->major = major;
        core->minor = minor;
    } else {
        core->major = 0;
        core->minor = 0;
    }

    // TODO: process endian

    str = json_object_get_string(cpu, "mpuPresent");
    if (str != NULL) {
        core->has_mpu = svd_parse_bool(str);
    } else {
        core->has_mpu = false;
    }

    str = json_object_get_string(cpu, "fpuPresent");
    if (str != NULL) {
        core->has_fpu = svd_parse_bool(str);
    } else {
        core->has_fpu = false;
    }

    str = json_object_get_string(cpu, "qemuItmPresent");
    if (str != NULL) {
        core->has_etm = svd_parse_bool(str);
    } else {
        core->has_etm = false;
    }

    str = json_object_get_string(cpu, "qemuEtmPresent");
    if (str != NULL) {
        core->has_itm = svd_parse_bool(str);
    } else {
        core->has_itm = false;
    }

    // TODO parse fpuDP

    str = json_object_get_string(cpu, "deviceNumInterrupts");
    if (str != NULL) {
        core->num_irq = svd_parse_uint(str);
    } else {
        error_printf(
                "SVD device.cpu has no mandatory \"deviceNumInterrupts\".\n");
        exit(1);
    }

    str = json_object_get_string(cpu, "nvicPrioBits");
    if (str != NULL) {
        core->nvic_bits = svd_parse_uint(str);
    } else {
        error_printf("SVD device.cpu has no mandatory \"nvicPrioBits\".\n");
        exit(1);
    }

    // TODO: parse vendorSystickConfig
}

// ----------------------------------------------------------------------------

