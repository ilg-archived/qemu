/*
 * Cortex-M devices emulation helper.
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

#ifndef CORTEXM_HELPER_H_
#define CORTEXM_HELPER_H_

#include "qemu/osdep.h"

#include "hw/boards.h"
#include "hw/qdev-properties.h"
#include "qemu/log.h"

// ----------------------------------------------------------------------------

#define TYPE_CORTEXM_PREFIX     "cortexm:"

// ----------------------------------------------------------------------------

#define DEFINE_PROP_CONST_STRING(_n, _s, _f) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_string, const char*)

#define DEFINE_PROP_NON_VOID_PTR(_n, _s, _f, _t) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_ptr, _t)

#define DEFINE_PROP_INT32_TYPE(_n, _s, _f, _d, _t) \
    DEFINE_PROP_DEFAULT(_n, _s, _f, _d, qdev_prop_int32, _t)

// ----------------------------------------------------------------------------

#define CORTEXM_IRQ_IN      "irq-in"
#define CORTEXM_IRQ_OUT     "irq-out"

// ----------------------------------------------------------------------------

typedef uint64_t peripheral_register_t;

// ----------------------------------------------------------------------------

bool cm_mcu_help_func(const char *mcu_device);
bool cm_board_help_func(const char *name);

// ----------------------------------------------------------------------------

void *cm_cpu_arm_create(Object *parent, const char *cpu_model);

Object *cm_object_new(Object *parent, const char *name, const char *type_name);
Object *cm_object_new_mcu(MachineState *machine, const char *board_device_name);

Object *cm_object_get_parent(Object *obj);
bool cm_object_is_instance_of_typename(Object *obj, const char *type_name);
Object *cm_object_get_child_by_name(Object *obj, const char *name);

void cm_object_realize(Object *dev);

DeviceState *cm_device_by_name(const char *path);

void cm_device_reset(DeviceState *dev);

bool cm_device_parent_realize(DeviceState *dev, Error **errp,
        const char *type_name);
bool cm_device_by_name_realize(DeviceState *dev, Error **errp,
        const char *type_name);
void cm_device_parent_reset(DeviceState *dev, const char *type_name);
void cm_device_by_name_reset(DeviceState *dev, const char *type_name);

void cm_object_property_set_int(Object *obj, int64_t value, const char *name);
void cm_object_property_set_bool(Object *obj, bool value, const char *name);
void cm_object_property_set_str(Object *obj, const char *value,
        const char *name);

char *cm_object_property_get_str(Object *obj, const char *name, Error **errp);
char *cm_object_property_get_str_with_parent(Object *obj, const char *name,
        Error **errp);

Object *cm_container_get_peripheral(void);

void cm_object_property_add_child(Object *parent, const char *node_name,
        Object *child);

ObjectProperty *
cm_object_property_add(Object *obj, const char *name, const char *type,
        ObjectPropertyAccessor *get, ObjectPropertyAccessor *set,
        ObjectPropertyRelease *release, void *opaque);

void cm_object_property_add_str(Object *obj, const char *name, char **v);

void cm_object_property_add_const_str(Object *obj, const char *name,
        const char **v);

void cm_object_property_add_bool(Object *obj, const char *name, const bool *v);

void cm_object_property_add_uint64_callback(Object *obj, const char *name,
        const uint64_t *v);

void cm_object_property_add_uint32(Object *obj, const char *name,
        const uint32_t *v);

void cm_object_property_add_uint16(Object *obj, const char *name,
        const uint16_t *v);

void cm_object_property_add_uint8(Object *obj, const char *name,
        const uint8_t *v);

void cm_object_property_add_int16(Object *obj, const char *name,
        const int16_t *v);

void cm_object_property_add_int(Object *obj, const char *name, const int *v);

void cm_irq_init_in(DeviceState *dev, qemu_irq_handler handler,
        const char *name, int num);

qemu_irq cm_irq_get_in(DeviceState *dev, const char *name, int index);

void cm_irq_init_out(DeviceState *dev, qemu_irq *pins, const char *name,
        int num);

void cm_irq_connect(DeviceState *dev_out, const char *name_out, int index_out,
        DeviceState *dev_in, const char *name_in, int index_in);

void cm_irq_connect_out(DeviceState *dev, const char *name, int index,
        qemu_irq in_irq);

qemu_irq cm_irq_create_in(qemu_irq_handler handler, void *opaque, int index);

void cm_irq_set(qemu_irq irq, int level);

void cm_irq_raise(qemu_irq irq);
void cm_irq_lower(qemu_irq irq);

// ----------------------------------------------------------------------------

#endif /* CORTEXM_HELPER_H_ */
