/*
 * STM32 Cortex-M devices emulation.
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

#ifndef STM32_MCUS_H_
#define STM32_MCUS_H_

#include "qemu/osdep.h"

#include <hw/cortexm/stm32/mcu.h>

/* ------------------------------------------------------------------------- */

// For compatibility with some development tools, it is
// strongly recommended to use the CMSIS names.
#define TYPE_STM32F051R8 "STM32F051R8"
#define TYPE_STM32F100RB "STM32F100RB"

// Medium density
#define TYPE_STM32F103RB "STM32F103RB"

// Connectivity line
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

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_DEVICE_PARENT TYPE_STM32_MCU
typedef STM32MCUClass STM32DeviceParentClass;
typedef STM32MCUState STM32DeviceParentState;

// ----------------------------------------------------------------------------

// Class definitions.
// Warning, this cast must not check the type!
#define STM32_DEVICE_GET_CLASS(obj) \
    ((STM32DeviceClass *)object_get_class(OBJECT(obj)))

// Structure to define the specifics of each MCU. Capabilities are
// split between core & stm32; they care processed by parent class
// constructors.
typedef struct {

    const char *name; // CMSIS device name

    const CortexMCapabilities cortexm;
    const STM32Capabilities *stm32;

} STM32PartInfo;

typedef struct {
    // private:
    STM32DeviceParentClass parent_class;
    // public:

    STM32PartInfo *part_info;
} STM32DeviceClass;

// ----------------------------------------------------------------------------

// Instance definitions.
typedef struct {
    // private:
    STM32DeviceParentState parent_class;
    // public:

} STM32DeviceState;

// ----------------------------------------------------------------------------

#endif /* STM32_MCUS_H_ */
