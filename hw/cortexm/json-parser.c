/*
 * Cortex-M JSON parser.
 *
 * Copyright (c) 2014 Liviu Ionescu.
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

#include <hw/cortexm/json-parser.h>
#include <hw/cortexm/peripheral.h>

#include "qemu/error-report.h"

// ----- Public ---------------------------------------------------------------

JSON_Object *cm_json_parser_get_peripheral(JSON_Value *family, const char *name)
{
    JSON_Object *object = json_value_get_object(family);
    JSON_Array *peripherals = json_object_get_array(object, "peripherals");
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

uint64_t cm_json_parser_parse_access_flags(const char *str)
{
    if (strcmp(str, "32_all") == 0) {
        return PERIPHERAL_REGISTER_32BITS_ALL;
    } else if (strcmp(str, "32_word") == 0) {
        return PERIPHERAL_REGISTER_32BITS_WORD;
    } else if (strcmp(str, "32_word_halfword") == 0) {
        return PERIPHERAL_REGISTER_32BITS_WORD_HALFWORD;
    } else if (strncmp(str, "0x", 2) == 0) {
        uint64_t ret;
        sscanf(str, "0x%" PRIX64, &ret);
        return ret;
    }
    error_printf("Unsupported value '%s' for access flags.\n", str);
    exit(1);
}

uint64_t cm_json_parser_parse_hex(const char *str)
{
    if (strncmp(str, "0x", 2) == 0) {
        uint64_t ret;
        sscanf(str, "0x%" PRIX64, &ret);
        return ret;
    }
    error_printf("Unsupported value '%s' for a hex field.\n", str);
    exit(1);
}

// ----------------------------------------------------------------------------
