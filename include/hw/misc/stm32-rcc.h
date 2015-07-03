/*
 * STM32 MCU - RCC (Reset and Clock Control).
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

#ifndef STM32_RCC_H_
#define STM32_RCC_H_

#include "hw/misc/peripheral.h"
#include "hw/arm/stm32-capabilities.h"

/* ------------------------------------------------------------------------- */

/* The high speed internal clock frequency. */
#define HSI_FREQ_HZ (8000000)
/* The low speed internal clock frequency. */
#define LSI_FREQ_HZ (40000)

/* No external oscillator */
#define DEFAULT_HSE_FREQ_HZ (0)
/* No RTC */
#define DEFAULT_RTC_FREQ_HZ (0)

/* ------------------------------------------------------------------------- */

#define TYPE_STM32_RCC TYPE_STM32_PREFIX "rcc" TYPE_PERIPHERAL_SUFFIX

#define TYPE_STM32F1_RCC_CR TYPE_STM32F1_PREFIX "rcc-cr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1_RCC_CFGR TYPE_STM32F1_PREFIX "rcc-cfgr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1_RCC_CIR TYPE_STM32F1_PREFIX "rcc-cir" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1_RCC_APB2RSTR TYPE_STM32F1_PREFIX "rcc-apb2rstr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1_RCC_APB1RSTR TYPE_STM32F1_PREFIX "rcc-apb1rstr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1_RCC_AHBENR TYPE_STM32F1_PREFIX "rcc-ahbenr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1_RCC_APB2ENR TYPE_STM32F1_PREFIX "rcc-apb2enr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1_RCC_APB1ENR TYPE_STM32F1_PREFIX "rcc-apb1enr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1_RCC_BDCR TYPE_STM32F1_PREFIX "rcc-bdcr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1_RCC_CSR TYPE_STM32F1_PREFIX "rcc-csr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX

#define TYPE_STM32F1CL_RCC_CR TYPE_STM32F1CL_PREFIX "rcc-cr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1CL_RCC_CFGR TYPE_STM32F1CL_PREFIX "rcc-cfgr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1CL_RCC_CIR TYPE_STM32F1CL_PREFIX "rcc-cir" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1CL_RCC_APB2RSTR TYPE_STM32F1CL_PREFIX "rcc-apb2rstr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1CL_RCC_APB1RSTR TYPE_STM32F1CL_PREFIX "rcc-apb1rstr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1CL_RCC_AHBENR TYPE_STM32F1CL_PREFIX "rcc-ahbenr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1CL_RCC_APB2ENR TYPE_STM32F1CL_PREFIX "rcc-apb2enr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1CL_RCC_APB1ENR TYPE_STM32F1CL_PREFIX "rcc-apb1enr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1CL_RCC_BDCR TYPE_STM32F1CL_PREFIX "rcc-bdcr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1CL_RCC_CSR TYPE_STM32F1CL_PREFIX "rcc-csr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1CL_RCC_AHBRSTR TYPE_STM32F1CL_PREFIX "rcc-ahbrstr" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX
#define TYPE_STM32F1CL_RCC_CFGR2 TYPE_STM32F1CL_PREFIX "rcc-cfgr2" \
    TYPE_PERIPHERAL_REGISTER_SUFFIX

/* ------------------------------------------------------------------------- */

/* Parent definitions. */
#define TYPE_STM32_RCC_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32RCCParentClass;
typedef PeripheralState STM32RCCParentState;

/* ------------------------------------------------------------------------- */

/* Class definitions. */
#define STM32_RCC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32RCCClass, (obj), TYPE_STM32_RCC)
#define STM32_RCC_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32RCCClass, (klass), TYPE_STM32_RCC)

typedef struct {
    /*< private >*/
    STM32RCCParentClass parent_class;
    /*< public >*/

    /* None, so far. */
} STM32RCCClass;

/* ------------------------------------------------------------------------- */

/* Instance definitions. */
#define STM32_RCC_STATE(obj) \
    OBJECT_CHECK(STM32RCCState, (obj), TYPE_STM32_RCC)

typedef struct {
    /*< private >*/
    STM32RCCParentState parent_obj;
    /*< public >*/

    /* Properties */
    uint32_t cpu_freq_hz;
    uint32_t hse_freq_hz;
    uint32_t lse_freq_hz;
    uint32_t hsi_freq_hz;
    uint32_t lsi_freq_hz;

    MemoryRegion mmio;
    // qemu_irq irq;

    union {
        struct {
            /* F1 specific registers */
            /* 0x28 most, 0x30 for CL */
            struct {
                Object *cr; /* 0x00 */
                Object *cfgr; /* 0x04 */
                Object *cir; /* 0x08 */
                Object *apb2rstr; /* 0x0C */
                Object *apb1rstr; /* 0x10 */
                Object *ahbenr; /* 0x14 */
                Object *apb2enr; /* 0x18 */
                Object *apb1enr; /* 0x1C */
                Object *bdcr; /* 0x20 */
                Object *csr; /* 0x24 */

                /* Connectivity line devices */
                Object *ahbrstr; /* 0x28 */
                Object *cfgr2; /* 0x2C */
            } reg;
        } f1;
        struct {
            /* F4 specific registers */
            struct {
                // TODO: add them
            } reg;
        } f4;
    } u;

    const STM32Capabilities *capabilities;
} STM32RCCState;

/* ------------------------------------------------------------------------- */

#endif /* STM32_RCC_H_ */
