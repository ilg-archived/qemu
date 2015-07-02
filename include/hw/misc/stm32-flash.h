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

#include "hw/misc/peripheral.h"
#include "hw/arm/stm32-capabilities.h"

/* ------------------------------------------------------------------------- */

#define TYPE_STM32_FLASH TYPE_STM32_PREFIX "flash" TYPE_PERIPHERAL_SUFFIX

#define TYPE_STM32_FLASH_ACR \
       TYPE_STM32_PREFIX "flash-acr" TYPE_PERIPHERAL_REGISTER_SUFFIX

/* ------------------------------------------------------------------------- */

/* Parent definitions. */
#define TYPE_STM32_FLASH_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32FlashParentClass;
typedef PeripheralState STM32FlashParentState;

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

    /* None, so far. */
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
            struct {
                DeviceState *acr; /* 0x00 */
#if 0
                DeviceState *keyr; /* 0x04 */
                DeviceState *optkeyr; /* 0x08 */
                DeviceState *sr; /* 0x0C */
                DeviceState *cr; /* 0x10 */
                DeviceState *ar; /* 0x14 */
                DeviceState *obr; /* 0x1C */
                DeviceState *wrpr; /* 0x20 */

                /* XL only */
                DeviceState *keyr2; /* 0x44 */
                DeviceState *sr2; /* 0x4C */
                DeviceState *cr2; /* 0x50 */
                DeviceState *ar2; /* 0x54 */
#endif
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
