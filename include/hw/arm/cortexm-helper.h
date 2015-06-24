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

#ifndef CORTEXM_HELPER_H_
#define CORTEXM_HELPER_H_

#include "qemu-common.h"

/* ------------------------------------------------------------------------- */

#define DEFINE_PROP_CONST_STRING(_n, _s, _f) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_string, const char*)

#define DEFINE_PROP_NON_VOID_PTR(_n, _s, _f, _t) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_ptr, _t)

#define DEFINE_PROP_INT32_TYPE(_n, _s, _f, _d, _t) \
    DEFINE_PROP_DEFAULT(_n, _s, _f, _d, qdev_prop_int32, _t)

/* ------------------------------------------------------------------------- */

void cm_board_greeting(MachineState *machine);

/* ------------------------------------------------------------------------- */

ARMCPU *cm_cpu_arm_create(const char *cpu_model);

DeviceState *cm_create(const char *name);
void cm_realize(DeviceState *dev);

bool cm_parent_realize(DeviceState *dev, Error **errp, const char *typename);
bool cm_class_realize(DeviceState *dev, Error **errp, const char *typename);
void cm_parent_reset(DeviceState *dev, const char *typename);

/* ------------------------------------------------------------------------- */

#endif /* CORTEXM_HELPER_H_ */
