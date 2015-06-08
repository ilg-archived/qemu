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
#define STM32F051R8_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DeviceClass, (obj), TYPE_STM32F051R8)
#define STM32F051R8_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32DeviceClass, (klass), TYPE_STM32F051R8)
#define STM32F051R8_STATE(obj) \
    OBJECT_CHECK(STM32MCUState, (obj), TYPE_STM32F051R8)

#define TYPE_STM32F100RB "STM32F100RB"
#define STM32F100RB_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DeviceClass, (obj), TYPE_STM32F100RB)
#define STM32F100RB_CLASS(obj) \
    OBJECT_CLASS_CHECK(STM32DeviceClass, (obj), TYPE_STM32F100RB)
#define STM32F100RB_STATE(obj) \
    OBJECT_CHECK(STM32MCUState, (obj), TYPE_STM32F100RB)

#define TYPE_STM32F103RB "STM32F103RB"
#define STM32F103RB_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DeviceClass, (obj), TYPE_STM32F103RB)
#define STM32F103RB_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32DeviceClass, (klass), TYPE_STM32F103RB)
#define STM32F103RB_STATE(obj) \
    OBJECT_CHECK(STM32MCUState, (obj), TYPE_STM32F103RB)

#define TYPE_STM32F107VC "STM32F107VC"
#define STM32F107VC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DeviceClass, (obj), TYPE_STM32F107VC)
#define STM32F107VC_CLASS(obj) \
    OBJECT_CLASS_CHECK(STM32DeviceClass, (obj), TYPE_STM32F107VC)
#define STM32F107VC_STATE(obj) \
    OBJECT_CHECK(STM32MCUState, (obj), TYPE_STM32F107VC)

#define TYPE_STM32L152RE "STM32L152RE"
#define STM32L152RE_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DeviceClass, (obj), TYPE_STM32L152RE)
#define STM32L152RE_CLASS(obj) \
    OBJECT_CLASS_CHECK(STM32DeviceClass, (obj), TYPE_STM32L152RE)
#define STM32L152RE_STATE(obj) \
    OBJECT_CHECK(STM32MCUState, (obj), TYPE_STM32L152RE)

#define TYPE_STM32F205RF "STM32F205RF"
#define STM32F205RF_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DeviceClass, (obj), TYPE_STM32F205RF)
#define STM32F205RF_CLASS(obj) \
    OBJECT_CLASS_CHECK(STM32DeviceClass, (obj), TYPE_STM32F205RF)
#define STM32F205RF_STATE(obj) \
    OBJECT_CHECK(STM32MCUState, (obj), TYPE_STM32F205RF)

#define TYPE_STM32F303VC "STM32F303VC"
#define STM32F303VC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DeviceClass, (obj), TYPE_STM32F303VC)
#define STM32F303VC_CLASS(obj) \
    OBJECT_CLASS_CHECK(STM32DeviceClass, (obj), TYPE_STM32F303VC)
#define STM32F303VC_STATE(obj) \
    OBJECT_CHECK(STM32MCUState, (obj), TYPE_STM32F303VC)

#define TYPE_STM32F334R8 "STM32F334R8"
#define STM32F334R8_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DeviceClass, (obj), TYPE_STM32F334R8)
#define STM32F334R8_CLASS(obj) \
    OBJECT_CLASS_CHECK(STM32DeviceClass, (obj), TYPE_STM32F334R8)
#define STM32F334R8_STATE(obj) \
    OBJECT_CHECK(STM32MCUState, (obj), TYPE_STM32F334R8)

#define TYPE_STM32F405RG "STM32F405RG"
#define STM32F405RG_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DeviceClass, (obj), TYPE_STM32F405RG)
#define STM32F405RG_CLASS(obj) \
    OBJECT_CLASS_CHECK(STM32DeviceClass, (obj), TYPE_STM32F405RG)
#define STM32F405RG_STATE(obj) \
    OBJECT_CHECK(STM32MCUState, (obj), TYPE_STM32F405RG)

#define TYPE_STM32F407VG "STM32F407VG"
#define STM32F407VG_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DeviceClass, (obj), TYPE_STM32F407VG)
#define STM32F407VG_CLASS(obj) \
    OBJECT_CLASS_CHECK(STM32DeviceClass, (obj), TYPE_STM32F407VG)
#define STM32F407VG_STATE(obj) \
    OBJECT_CHECK(STM32MCUState, (obj), TYPE_STM32F407VG)

#define TYPE_STM32F407ZG "STM32F407ZG"
#define STM32F407ZG_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DeviceClass, (obj), TYPE_STM32F407ZG)
#define STM32F407ZG_CLASS(obj) \
    OBJECT_CLASS_CHECK(STM32DeviceClass, (obj), TYPE_STM32F407ZG)
#define STM32F407ZG_STATE(obj) \
    OBJECT_CHECK(STM32MCUState, (obj), TYPE_STM32F407ZG)

#define TYPE_STM32F411RE "STM32F411RE"
#define STM32F411RE_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DeviceClass, (obj), TYPE_STM32F411RE)
#define STM32F411RE_CLASS(obj) \
    OBJECT_CLASS_CHECK(STM32DeviceClass, (obj), TYPE_STM32F411RE)
#define STM32F411RE_STATE(obj) \
    OBJECT_CHECK(STM32MCUState, (obj), TYPE_STM32F411RE)

#define TYPE_STM32F429ZI "STM32F429ZI"
#define STM32F429ZI_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DeviceClass, (obj), TYPE_STM32F429ZI)
#define STM32F429ZI_CLASS(obj) \
    OBJECT_CLASS_CHECK(STM32DeviceClass, (obj), TYPE_STM32F429ZI)
#define STM32F429ZI_STATE(obj) \
    OBJECT_CHECK(STM32MCUState, (obj), TYPE_STM32F429ZI)

typedef struct STM32DeviceClass {
    /*< private >*/
    STM32MCUClass parent_class;
    /*< public >*/

    DeviceRealize parent_realize;
    // void (*parent_reset)(DeviceState *dev);
} STM32DeviceClass;

#endif /* HW_ARM_STM32_H */
