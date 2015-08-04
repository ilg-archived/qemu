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

#define TYPE_STM32_RCC TYPE_STM32_PREFIX "rcc" TYPE_PERIPHERAL_SUFFIX

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

        /* Bitfields. */
        struct {
            Object *hsirdy;
            Object *hserdy;
            Object *pllrdy;
            Object *pll2rdy; /* CL */
            Object *pll3rdy; /* CL */
        } cr;
        struct {
            Object *sws;
            Object *pllmul;
            Object *pllsrc;
            Object *pllxtpre;
            Object *hpre;
        } cfgr;
        struct {
            Object *lsirdyf;
            Object *lserdyf;
            Object *hsirdyf;
            Object *hserdyf;
            Object *pllrdyf;
            Object *pll2rdyf;
            Object *pll3rdyf;
            Object *cssf;
        } cir;
        struct {
            Object *lserdy;
        } bdcr;
        struct {
            Object *lsirdy;
            Object *pinrstf;
            Object *porrstf;
            Object *stfrstf;
            Object *iwdgrstf;
            Object *wwdgrstf;
            Object *lrwrrstf;
        } csr;
        struct {
            Object *prediv1;
            Object *prediv2;
            Object *pll2mul;
            Object *prediv1src;
        } cfgr2;

    } f1;
    struct {
        /* F4 specific registers */
        struct {
            Object *cr; /* 0x00 */
            Object *pllcfgr; /* 0x04 */
            Object *cfgr; /* 0x08 */
            Object *cir; /* 0x0C */
            Object *ahb1rstr; /* 0x10 */
            Object *ahb2rstr; /* 0x14 */
            Object *ahb3rstr; /* 0x18 */
            Object *apb1rstr; /* 0x20 */
            Object *apb2rstr; /* 0x24 */
            Object *ahb1enr; /* 0x30 */
            Object *ahb2enr; /* 0x34 */
            Object *ahb3enr; /* 0x38 */
            Object *apb1enr; /* 0x40 */
            Object *apb2enr; /* 0x44 */
            Object *ahb1lpenr; /* 0x50 */
            Object *ahb2lpenr; /* 0x54 */
            Object *ahb3lpenr; /* 0x58 */
            Object *apb1lpenr; /* 0x60 */
            Object *apb2lpenr; /* 0x64 */
            Object *bdcr; /* 0x70 */
            Object *csr; /* 0x74 */
            Object *sscgr; /* 0x80 */
            Object *plli2scfgr; /* 0x84 */
            Object *pllsaicfgr; /* 0x84 */
            Object *plldckcfgr; /* 0x84 */
        } reg;
        struct {
            struct {
                Object *hsion;
                Object *hsirdy;
                Object *hsitrim;
                Object *hsical;
                Object *hseon;
                Object *hserdy;
                Object *hsebyp;
                Object *csson;
                Object *pllon;
                Object *pllrdy;
                Object *plli2son;
                Object *plli2srdy;
                Object *pllsaion;
                Object *pllsairdy;
            } cr;
            struct {
                Object *pllm;
                Object *plln;
                Object *pllp;
                Object *pllsrc;
                Object *pllq;
            } pllcfgr;
            struct {
                Object *sw;
                Object *sws;
                Object *hpre;
                Object *ppre1;
                Object *ppre2;
                Object *rtcpre;
                Object *mco1;
                Object *i2ssrc;
                Object *mco1pre;
                Object *mco2pre;
                Object *mco2;
            } cfgr;
            struct {
                Object *lsirdyf;
                Object *lserdyf;
                Object *hsirdyf;
                Object *hserdyf;
                Object *pllrdyf;
                Object *plli2srdyf;
                Object *pllsairdyf;
                Object *cssf;
            } cir;
            struct {
                Object *lserdy;
            } bdcr;
            struct {
                Object *lsirdy;
                Object *borrstf;
                Object *pinrstf;
                Object *porrstf;
                Object *stfrstf;
                Object *iwdgrstf;
                Object *wwdgrstf;
                Object *lpwrrstf;
            } csr;

        } fld;
    } f4;

    const STM32Capabilities *capabilities;
} STM32RCCState;

/* ------------------------------------------------------------------------- */

#endif /* STM32_RCC_H_ */
