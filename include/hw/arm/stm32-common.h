/*
 * STM32 common definitions.
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

#ifndef STM32_COMMON_H_
#define STM32_COMMON_H_

#include "hw/arm/cortexm.h"

typedef enum {
    STM32_FAMILY_UNKNOWN,
    STM32_FAMILY_F1,
    STM32_FAMILY_F4
} stm32_family_t;

typedef struct {
    /* Parent, it must be the first one. */
    CortexMCapabilities cortexm;

    struct {
        stm32_family_t family;
        /* Note: the family definitions are mutual exclusive, and could
         * be packed in a union, but this makes writing the definitions
         * more complicated and was discarded.
         */
        struct {
            unsigned int is_ld :1; /* is low density */
            unsigned int is_md :1; /* is medium density */
            unsigned int is_hd :1; /* is high density */
            unsigned int is_xd :1; /* is extra density */
            unsigned int is_cl :1; /* is Connectivity Line */
        } f1;
    } stm32;
} STM32Capabilities;

#endif /* STM32_COMMON_H_ */
