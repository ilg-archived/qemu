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

#include "hw/arm/cortexm-helper.h"

#include "hw/boards.h"
#include "cpu-qom.h"
#include "qemu/error-report.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/* ------------------------------------------------------------------------- */

/**
 * When verbose, display a line to identify the board (name, description).
 *
 * Does not really depend on Cortex-M, but I could not find a better place.
 */
void cm_board_greeting(MachineState *machine)
{
#if defined(CONFIG_VERBOSE)
    if (verbosity_level >= VERBOSITY_COMMON) {
        MachineClass *mc = MACHINE_GET_CLASS(machine);
        printf("Board: '%s' (%s).\n", mc->name, mc->desc);
    }
#endif
}

/* ------------------------------------------------------------------------- */

/**
 * A version of cpu_generic_init() that does only the object creation and
 * initialisation, without calling realize().
 */
static CPUState *cm_cpu_generic_create(const char *typename,
        const char *cpu_model)
{
    char *str, *name, *featurestr;
    CPUState *cpu;
    ObjectClass *oc;
    CPUClass *cc;
    Error *err = NULL;

    str = g_strdup(cpu_model);
    name = strtok(str, ",");

    oc = cpu_class_by_name(typename, name);
    if (oc == NULL) {
        g_free(str);
        return NULL;
    }

    cpu = CPU(object_new(object_class_get_name(oc)));
    cc = CPU_GET_CLASS(cpu);

    featurestr = strtok(NULL, ",");
    cc->parse_features(cpu, featurestr, &err);
    g_free(str);
    if (err != NULL) {
        error_report_err(err);
        object_unref(OBJECT(cpu));
        return NULL;
    }

    return cpu;
}

/**
 * A version of cpu_arm_init() that does only the object creation and
 * initialisation, without calling realize().
 */
ARMCPU *cm_cpu_arm_create(Object *parent, const char *cpu_model)
{
    ARMCPU *cpu;
    cpu = ARM_CPU(cm_cpu_generic_create(TYPE_ARM_CPU, cpu_model));
    if (!cpu) {
        error_report("Unable to find CPU definition %s", cpu_model);
        exit(1);
    }
    cm_object_property_add_child(parent, "core", OBJECT(cpu));

    return cpu;
}

/**
 *  Realize object. Errors are fatal.
 *  Similar to qdev_init_nofail(), but with a less-confusing name, since
 *  qdev_init_nofail not only that it does not call init(), but realize(),
 *  and it may fail, and when it does it exits.
 */
void cm_object_realize(Object *obj)
{
    Error *err = NULL;

    object_property_set_bool(obj, true, "realized", &err);
    if (err) {
        error_report("Realization of object %s failed: %s",
                object_get_typename(obj), error_get_pretty(err));
        exit(1);
    }
}

Object *cm_object_new(Object *parent, const char* node_name,
        const char *type_name)
{
    if (object_class_by_name(type_name) == NULL) {
        error_report("Creating object of type %s failed; no such type.",
                type_name);
        exit(1);
    }

    Object *obj = object_new(type_name);
    if (!obj) {
        error_report("Creating object of type %s failed.", type_name);
        exit(1);
    }

    cm_object_property_add_child(parent, node_name, obj);
    return obj;
}

Object *cm_object_new_mcu(const char *type_name)
{
    return cm_object_new(cm_object_get_machine(), "mcu", type_name);
}

/**
 *  Call the parent realize() of a given type.
 */
bool cm_device_parent_realize(DeviceState *dev, Error **errp,
        const char *type_name)
{
    /* Identify parent class. */
    DeviceClass *klass = DEVICE_CLASS(
            object_class_get_parent(object_class_by_name(type_name)));

    if (klass->realize) {
        Error *local_err = NULL;
        klass->realize(dev, &local_err);
        if (local_err) {
            error_propagate(errp, local_err);
            return false;
        }
    }
    return true;
}

/**
 *  Call the realize() of a given type.
 */
bool cm_device_by_name_realize(DeviceState *dev, Error **errp,
        const char *type_name)
{
    /* Identify class. */
    DeviceClass *klass = DEVICE_CLASS(object_class_by_name(type_name));

    if (klass->realize) {
        Error *local_err = NULL;
        klass->realize(dev, &local_err);
        if (local_err) {
            error_propagate(errp, local_err);
            return false;
        }
    }
    return true;
}

/**
 * Call the parent reset() of a given type.
 */
void cm_device_parent_reset(DeviceState *dev, const char *type_name)
{
    /* Identify parent class. */
    DeviceClass *klass = DEVICE_CLASS(
            object_class_get_parent(object_class_by_name(type_name)));

    if (klass->reset) {
        klass->reset(dev);
    }
}

/**
 * Call the reset() of a given type.
 */
void cm_device_by_name_reset(DeviceState *dev, const char *type_name)
{
    /* Identify class. */
    DeviceClass *klass = DEVICE_CLASS(object_class_by_name(type_name));

    if (klass->reset) {
        klass->reset(dev);
    }
}

Object *cm_object_get_machine(void)
{
    static Object *obj;

    if (obj == NULL) {
        obj = container_get(object_get_root(), "/machine");
    }

    return obj;
}

void cm_object_property_set_int(Object *obj, int64_t value, const char *name)
{
    Error *err = NULL;
    object_property_set_int(obj, value, name, &err);
    if (err) {
        error_report("Setting int property %s for %s failed: %s.", name,
                object_get_typename(obj), error_get_pretty(err));
        exit(1);
    }
}

void cm_object_property_set_bool(Object *obj, bool value, const char *name)
{
    Error *err = NULL;
    object_property_set_bool(obj, value, name, &err);
    if (err) {
        error_report("Setting bool property %s for %s failed: %s.", name,
                object_get_typename(obj), error_get_pretty(err));
        exit(1);
    }
}

void cm_object_property_set_str(Object *obj, const char *value,
        const char *name)
{
    Error *err = NULL;
    object_property_set_str(obj, value, name, &err);
    if (err) {
        error_report("Setting string property %s for %s failed: %s.", name,
                object_get_typename(obj), error_get_pretty(err));
        exit(1);
    }
}

void cm_object_property_add_child(Object *obj, const char *node_name,
        Object *child)
{
    Error *err = NULL;
    object_property_add_child(obj, node_name, child, &err);
    if (err) {
        error_report("Adding child %s for %s failed: %s.", node_name,
                object_get_typename(obj), error_get_pretty(err));
        exit(1);
    }
}

Object *cm_container_get_peripheral(void)
{
    return container_get(object_get_root(), "/peripheral");
}

/* ------------------------------------------------------------------------- */
