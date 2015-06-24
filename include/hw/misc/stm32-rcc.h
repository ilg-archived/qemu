/*
 * STM32 MCU - RCC (Reset and Clock Control).
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

#ifndef STM32_RCC_H_
#define STM32_RCC_H_

#include "config.h"
#include "hw/sysbus.h"
#include "hw/misc/stm32-sys-bus-device.h"

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

#define TYPE_STM32_RCC "stm32-rcc"

/* ------------------------------------------------------------------------- */

/* Parent definitions. */
#define TYPE_STM32_RCC_PARENT TYPE_STM32_SYS_BUS_DEVICE
typedef STM32SysBusDeviceClass STM32RCCParentClass;
typedef STM32SysBusDeviceState STM32RCCParentState;

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
                uint32_t cr; /* 0x00 */
                uint32_t cfgr; /* 0x04 */
                uint32_t cir; /* 0x08 */
                uint32_t apb2rstr; /* 0x0C */
                uint32_t apb1rstr; /* 0x10 */
                uint32_t ahbenr; /* 0x14 */
                uint32_t apb2enr; /* 0x18 */
                uint32_t apb1enr; /* 0x1C */
                uint32_t bdcr; /* 0x20 */
                uint32_t csr; /* 0x24 */

                /* Connectivity line devices */
                uint32_t ahbrstr; /* 0x28 */
                uint32_t cfgr2; /* 0x2C */

            } reg;
        } f1;
        struct {
            /* F4 specific registers */
            struct {
                // TODO: add them
            } reg;
        } f4;
    } u;
} STM32RCCState;

/* ------------------------------------------------------------------------- */

#endif /* STM32_RCC_H_ */
