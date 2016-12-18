/*
 * Cortex-M MCU emulation.
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

#ifndef CORTEXM_SVD_H_
#define CORTEXM_SVD_H_

#include "qemu/osdep.h"

#include <hw/cortexm/parson.h>
#include <hw/cortexm/mcu.h>

#include "qom/object.h"

// ----------------------------------------------------------------------------

void svd_validate_device_name(JSON_Object *svd, const char *name);
bool svd_has_named_peripheral(JSON_Object *svd, const char *name);
JSON_Object *svd_get_peripheral_by_name(JSON_Object *svd, const char *name);
void svd_set_rw_mode(Object *obj, const char *str);
void svd_set_register_properties_group(JSON_Object *svd, Object *obj);

Object *svd_add_peripheral_properties_and_children(Object *obj,
        JSON_Object *svd, JSON_Object *root);
Object *svd_add_peripheral_register_properties_and_children(Object *obj,
        JSON_Object *svd);
Object *svd_add_register_bitfield_properties_and_children(Object *obj,
        JSON_Object *svd);

void svd_set_peripheral_address_block(JSON_Object *svd, const char* name,
        Object *obj);

uint64_t svd_parse_uint(const char *str);
bool svd_parse_bool(const char *str);

void svd_process_cpu(JSON_Object *svd, CortexMCoreCapabilities *core);

// ----------------------------------------------------------------------------

#endif /* CORTEXM_SVD_H_ */

