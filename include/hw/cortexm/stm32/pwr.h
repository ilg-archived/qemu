/*
 * STM32 MCU - PWR (power controller) emulation.
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

#ifndef STM32_PWR_H_
#define STM32_PWR_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_PWR DEVICE_PATH_STM32 "PWR"

// ----------------------------------------------------------------------------

#define TYPE_STM32_PWR TYPE_STM32_PREFIX "pwr" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_PWR_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32PWRParentClass;
typedef PeripheralState STM32PWRParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_PWR_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32PWRClass, (obj), TYPE_STM32_PWR)
#define STM32_PWR_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32PWRClass, (klass), TYPE_STM32_PWR)

typedef struct {
    // private:
    STM32PWRParentClass parent_class;
    // public:

    // None, so far.
} STM32PWRClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_PWR_STATE(obj) \
    OBJECT_CHECK(STM32PWRState, (obj), TYPE_STM32_PWR)

typedef struct {
    // private:
    STM32PWRParentState parent_obj;
    // public:

    const STM32Capabilities *capabilities;

    union {
        // DO NOT EDIT! Automatically generated!
        struct {
            // F0 PWR (Power control) registers.
            struct {
                Object *cr; // 0x0 Power control register
                Object *csr; // 0x4 Power control/status register
            } reg;

            struct {

                // CR (Power control register) bitfields.
                struct {
                    Object *lpds; // [0:0] Low-power deep sleep
                    Object *pdds; // [1:1] Power down deepsleep
                    Object *cwuf; // [2:2] Clear wakeup flag
                    Object *csbf; // [3:3] Clear standby flag
                    Object *pvde; // [4:4] Power voltage detector enable
                    Object *pls; // [5:7] PVD level selection
                    Object *dbp; // [8:8] Disable backup domain write protection
                } cr;

                // CSR (Power control/status register) bitfields.
                struct {
                    Object *wuf; // [0:0] Wakeup flag
                    Object *sbf; // [1:1] Standby flag
                    Object *pvdo; // [2:2] PVD output
                    Object *vrefintrdy; // [3:3] VREFINT reference voltage ready
                    Object *ewup1; // [8:8] Enable WKUP pin 1
                    Object *ewup2; // [9:9] Enable WKUP pin 2
                    Object *ewup3; // [10:10] Enable WKUP pin 3
                    Object *ewup4; // [11:11] Enable WKUP pin 4
                    Object *ewup5; // [12:12] Enable WKUP pin 5
                    Object *ewup6; // [13:13] Enable WKUP pin 6
                    Object *ewup7; // [14:14] Enable WKUP pin 7
                    Object *ewup8; // [15:15] Enable WKUP pin 8
                } csr;
            } fld;
        } f0;

        // DO NOT EDIT! Automatically generated!
        struct {
            // F1 PWR (Power control) registers.
            struct {
                Object *cr; // 0x0 Power control register (PWR_CR)
                Object *csr; // 0x4 Power control register (PWR_CR)
            } reg;

            struct {

                // CR (Power control register (PWR_CR)) bitfields.
                struct {
                    Object *lpds; // [0:0] Low Power Deep Sleep
                    Object *pdds; // [1:1] Power Down Deep Sleep
                    Object *cwuf; // [2:2] Clear Wake-up Flag
                    Object *csbf; // [3:3] Clear STANDBY Flag
                    Object *pvde; // [4:4] Power Voltage Detector Enable
                    Object *pls; // [5:7] PVD Level Selection
                    Object *dbp; // [8:8] Disable Backup Domain write protection
                } cr;

                // CSR (Power control register (PWR_CR)) bitfields.
                struct {
                    Object *wuf; // [0:0] Wake-Up Flag
                    Object *sbf; // [1:1] STANDBY Flag
                    Object *pvdo; // [2:2] PVD Output
                    Object *ewup; // [8:8] Enable WKUP pin
                } csr;
            } fld;
        } f1;

#if 0
        struct {
            /* F4 specific registers */
            struct {
                Object *cr;
                Object *csr;
            }reg;
            struct {
                struct {
                    Object *lpds;
                    Object *pdds;
                    Object *cwuf;
                    Object *csbf;
                    Object *pvde;
                    Object *pls;
                    Object *dbp;
                    Object *fpds;

                    Object *lpuds; /* [23]xxx */
                    Object *mruds; /* [23]xxx */
                    Object *adcdc1; /* [23]xxx */

                    Object *vos;

                    /* [23]xxx */
                    Object *oden;
                    Object *odswen;
                    Object *uden;
                }cr;
                struct {
                    Object *wuf;
                    Object *sbf;
                    Object *pvdo;
                    Object *brr;
                    Object *ewup;
                    Object *bre;
                    Object *vosrdy;
                    /* [23]xxx */
                    Object *odrdy;
                    Object *odswrdy;
                    Object *udrdy;
                }csr;
            }fld;
        }f4;
#endif

        // DO NOT EDIT! Automatically generated!
        struct {
            // F4 PWR (Power control) registers.
            struct {
                Object *cr; // 0x0 Power control register
                Object *csr; // 0x4 Power control/status register
            } reg;

            struct {

                // CR (Power control register) bitfields.
                struct {
                    Object *lpds; // [0:0] Low-power deep sleep
                    Object *pdds; // [1:1] Power down deepsleep
                    Object *cwuf; // [2:2] Clear wakeup flag
                    Object *csbf; // [3:3] Clear standby flag
                    Object *pvde; // [4:4] Power voltage detector enable
                    Object *pls; // [5:7] PVD level selection
                    Object *dbp; // [8:8] Disable backup domain write protection
                    Object *fpds; // [9:9] Flash power down in Stop mode

                    // F429
                    Object *lpuds; // [10:10] Low-Power Regulator Low Voltage in deepsleep
                    Object *mruds; // [11:11] Main regulator low voltage in deepsleep mode
                    Object *adcdc1; // [13:13] ADCDC1
                    Object *vos; // [14:15] Regulator voltage scaling output selection
                    Object *oden; // [16:16] Over-drive enable
                    Object *odswen; // [17:17] Over-drive switching enabled
                    Object *uden; // [18:19] Under-drive enable in stop mode

                } cr;

                // CSR (Power control/status register) bitfields.
                struct {
                    Object *wuf; // [0:0] Wakeup flag
                    Object *sbf; // [1:1] Standby flag
                    Object *pvdo; // [2:2] PVD output
                    Object *brr; // [3:3] Backup regulator ready
                    Object *ewup; // [8:8] Enable WKUP pin
                    Object *bre; // [9:9] Backup regulator enable
                    Object *vosrdy; // [14:14] Regulator voltage scaling output selection ready bit

                    // F429
                    Object *odrdy; // [16:16] Over-drive mode ready
                    Object *odswrdy; // [17:17] Over-drive mode switching ready
                    Object *udrdy; // [18:19] Under-drive ready flag

                } csr;
            } fld;
        } f4;
    } u;

} STM32PWRState;

// ----------------------------------------------------------------------------

#endif /* STM32_PWR_H_ */
