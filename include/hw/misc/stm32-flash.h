/*
 * STM32 MCU - flash control.
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

#ifndef STM32_FLASH_H_
#define STM32_FLASH_H_

#include "hw/misc/peripheral32.h"
#include "hw/arm/stm32-capabilities.h"

#if 0
#include "config.h"
#include "hw/sysbus.h"
#include "hw/misc/stm32-sys-bus-device.h"
#endif

/* ------------------------------------------------------------------------- */

#define TYPE_STM32_FLASH "stm32-flash"

/* ------------------------------------------------------------------------- */

/* Parent definitions. */
#if 0
#define TYPE_STM32_FLASH_PARENT TYPE_STM32_SYS_BUS_DEVICE
typedef STM32SysBusDeviceClass STM32FlashParentClass;
typedef STM32SysBusDeviceState STM32FlashParentState;
#else
#define TYPE_STM32_FLASH_PARENT TYPE_PERIPHERAL32
typedef Peripheral32Class STM32FlashParentClass;
typedef Peripheral32State STM32FlashParentState;
#endif

/* ------------------------------------------------------------------------- */

/* Class definitions. */
#define STM32_FLASH_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32FlashClass, (obj), TYPE_STM32_FLASH)
#define STM32_FLASH_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32FlashClass, (klass), TYPE_STM32_FLASH)

typedef struct {
    /*< private >*/
    STM32FlashParentClass parent_class;
    /*< public >*/

} STM32FlashClass;

/* ------------------------------------------------------------------------- */

/* Instance definitions. */
#define STM32_FLASH_STATE(obj) \
    OBJECT_CHECK(STM32FlashState, (obj), TYPE_STM32_FLASH)

typedef struct {
    /*< private >*/
    STM32FlashParentState parent_obj;
    /*< public >*/

    const STM32Capabilities *capabilities;

    union {
        struct {
            /* F1 specific registers */
            /* 0x28 most, 0x30 for CL */
            struct {
                uint32_t acr; /* 0x00 */
                uint32_t keyr; /* 0x04 */
                uint32_t optkeyr; /* 0x08 */
                uint32_t sr; /* 0x0C */
                uint32_t cr; /* 0x10 */
                uint32_t ar; /* 0x14 */
                uint32_t obr; /* 0x1C */
                uint32_t wrpr; /* 0x20 */

                /* XL only */
                uint32_t keyr2; /* 0x44 */
                uint32_t sr2; /* 0x4C */
                uint32_t cr2; /* 0x50 */
                uint32_t ar2; /* 0x54 */
            } reg;
        } f1;
        struct {
            /* F4 specific registers */
            struct {
                // TODO: add them
            } reg;
        } f4;
    } u;
} STM32FlashState;

/* ------------------------------------------------------------------------- */

#endif /* STM32_FLASH_H_ */
