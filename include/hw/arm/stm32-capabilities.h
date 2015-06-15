/*
 * STM32 capabilities definitions.
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

#ifndef STM32_CAPABILITIES_H_
#define STM32_CAPABILITIES_H_

#include <stdint.h>

typedef enum {
    STM32_FAMILY_UNKNOWN,
    STM32_FAMILY_F1,
    STM32_FAMILY_F4
} stm32_family_t;

#define STM32_MAX_GPIO  (8)

typedef struct {

    stm32_family_t family;

    /*
     * Properties common to all families
     */
    uint32_t hsi_freq_hz;
    uint32_t lsi_freq_hz;

    /*
     * Peripherals common to all families.
     */
    unsigned int has_gpioa :1;
    unsigned int has_gpiob :1;
    unsigned int has_gpioc :1;
    unsigned int has_gpiod :1;
    unsigned int has_gpioe :1;
    unsigned int has_gpiof :1;
    unsigned int has_gpiog :1;

    /*
     * Note: the family definitions are mutual exclusive, and could
     * be packed in a union, but this makes writing the definitions
     * more complicated and was discarded.
     */
    struct {
        unsigned int is_ld :1; /* is low density */
        unsigned int is_md :1; /* is medium density */
        unsigned int is_hd :1; /* is high density */
        unsigned int is_xd :1; /* is extra density */
        unsigned int is_cl :1; /* is Connectivity Line */
        unsigned int is_ldvl :1; /* is low density */
        unsigned int is_mdvl :1; /* is medium density */
        unsigned int is_hdvl :1; /* is high density */

    } f1;
} STM32Capabilities;

#endif /* STM32_CAPABILITIES_H_ */
