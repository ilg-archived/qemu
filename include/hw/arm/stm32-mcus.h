/*
 * STM32 Cortex-M devices emulation.
 *
 * Copyright (c) 2014 Liviu Ionescu
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

#ifndef HW_ARM_STM32_H
#define HW_ARM_STM32_H 1

#include "hw/arm/stm32-mcu.h"

/* ----- Devices ----- */

#define TYPE_STM32F051R8 "STM32F051R8"
#define TYPE_STM32F100RB "STM32F100RB"
#define TYPE_STM32F103RB "STM32F103RB"
#define TYPE_STM32F107VC "STM32F107VC"
#define TYPE_STM32L152RE "STM32L152RE"
#define TYPE_STM32F205RF "STM32F205RF"
#define TYPE_STM32F303VC "STM32F303VC"
#define TYPE_STM32F334R8 "STM32F334R8"
#define TYPE_STM32F405RG "STM32F405RG"
#define TYPE_STM32F407VG "STM32F407VG"
#define TYPE_STM32F407ZG "STM32F407ZG"
#define TYPE_STM32F411RE "STM32F411RE"
#define TYPE_STM32F429ZI "STM32F429ZI"

#define STM32_DEVICE_GET_CLASS(obj) \
    ((STM32DeviceClass*)object_get_class(OBJECT(obj)))

typedef struct {
    const char *name;
    CortexMCapabilities core;
    STM32Capabilities stm32;
} STM32PartInfo;

typedef struct {
    /*< private >*/
    STM32MCUClass parent_class;
    /*< public >*/

    void (*construct)(Object *obj, MachineState *machine);
    STM32PartInfo *part_info;
} STM32DeviceClass;

typedef struct {
    /*< private >*/
    STM32MCUState parent_class;
    /*< public >*/

} STM32DeviceState;

#endif /* HW_ARM_STM32_H */
