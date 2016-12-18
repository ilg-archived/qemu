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

#ifndef CORTEXM_JSON_PARSER_H_
#define CORTEXM_JSON_PARSER_H_

#include "qemu/osdep.h"
#include <hw/cortexm/parson.h>

// ----------------------------------------------------------------------------

JSON_Object *cm_json_parser_get_peripheral(JSON_Value *family,
        const char *name);
uint64_t cm_json_parser_parse_access_flags(const char *str);

uint64_t cm_json_parser_parse_hex(const char *str);

// ----------------------------------------------------------------------------

#endif /* CORTEXM_JSON_PARSER_H_ */
