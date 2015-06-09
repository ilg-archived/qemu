/*
 * STM32 MCU - XXX.
 *
 * Copyright (c) 2015 Liviu Ionescu
 * Copyright (c) 2010 Andre Beckus
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


#ifndef STM32_XXX_H_
#define STM32_XXX_H_

#include "config.h"
#include "hw/sysbus.h"
#include "hw/misc/stm32-sys-busdevice.h"

#include "exec/address-spaces.h"

#define TYPE_STM32_XXX "stm32-xxx"

#define STM32_XXX_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32XxxClass, (obj), TYPE_STM32_XXX)
#define STM32_XXX_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32XxxClass, (klass), TYPE_STM32_XXX)
#define STM32_XXX_STATE(obj) \
    OBJECT_CHECK(STM32XxxState, (obj), TYPE_STM32_XXX)

typedef struct {
    /*< private >*/
    SysBusDeviceClass parent_class;
    /*< public >*/

    /* No local virtual functions */
} STM32XxxClass;

typedef struct {
    /*< private >*/
    STM32SysBusDevice parent_obj;
    /*< public >*/

    MemoryRegion mmio;

    union {
        struct {
            /* F1 specific registers */
            struct {
                uint32_t cr;
            } reg;
        } f1;
        struct {
            /* F4 specific registers */
            struct {

            } reg;
        } f4;
    } u;
} STM32XxxState;

#endif /* STM32_XXX_H_ */
