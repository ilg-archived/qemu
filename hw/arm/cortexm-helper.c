/*
 * Cortex-M devices emulation helper.
 *
 * Copyright (c) 2015 Liviu Ionescu
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
ARMCPU *cm_cpu_arm_create(const char *cpu_model)
{
    return ARM_CPU(cm_cpu_generic_create(TYPE_ARM_CPU, cpu_model));
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
        error_report("Initialization of device %s failed: %s",
                object_get_typename(obj), error_get_pretty(err));
        exit(1);
    }
}

Object *cm_object_new(const char *name)
{
    // TODO: migrate to QOM
    return OBJECT(qdev_create(NULL, name));
    // return DEVICE(object_new(name));
}

/**
 *  Call the parent realize() of a given type.
 */
bool cm_object_parent_realize(DeviceState *dev, Error **errp,
        const char *typename)
{
    /* Identify parent class. */
    DeviceClass *parent_class = DEVICE_CLASS(
            object_class_get_parent(object_class_by_name(typename)));

    if (parent_class->realize) {
        Error *local_err = NULL;
        parent_class->realize(dev, &local_err);
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
bool cm_object_by_name_realize(DeviceState *dev, Error **errp,
        const char *typename)
{
    /* Identify parent class. */
    DeviceClass *parent_class = DEVICE_CLASS(object_class_by_name(typename));

    if (parent_class->realize) {
        Error *local_err = NULL;
        parent_class->realize(dev, &local_err);
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
void cm_object_parent_reset(DeviceState *dev, const char *typename)
{
    /* Identify parent class. */
    DeviceClass *parent_class = DEVICE_CLASS(
            object_class_get_parent(object_class_by_name(typename)));

    if (parent_class->reset) {
        parent_class->reset(dev);
    }
}

/* ------------------------------------------------------------------------- */
