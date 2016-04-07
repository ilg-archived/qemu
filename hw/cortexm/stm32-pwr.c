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

#include <hw/misc/stm32-pwr.h>
#include "hw/arm/cortexm-helper.h"

/**
 * This file implements the STM32 PWR.
 *
 * The initial implementation is intended only to pass CMSIS initialisations.
 *
 * References:
 * - ST CD00171190.pdf, Doc ID 13902 Rev 15, "RM0008 Reference Manual,
 * STM32F101xx, STM32F102xx, STM32F103xx, STM32F105xx and STM32F107xx
 * advanced ARM®-based 32-bit MCUs"
 *
 * - Doc ID 018909 Rev 6, "ST RM0090 Reference manual,
 * STM32F405xx/07xx, STM32F415xx/17xx, STM32F42xxx and STM32F43xxx
 * advanced ARM-based 32-bit MCUs"
 *
 * - Doc ID 026448 Rev 1, "ST RM0383 Reference manual,
 * STM32F411xC/E advanced ARM-based 32-bit MCUs"
 *
 * All STM32 reference manuals available from:
 * http://www.st.com/stonline/stappl/resourceSelector/\
 * app?page=fullResourceSelector&doctype=reference_manual&FamilyID=141
 */

/* ----- Private ----------------------------------------------------------- */

/* ------------------------------------------------------------------------- */

/* STM32F10xx */

static PeripheralInfo stm32f1_pwr_info =
        {
            .desc = "Power controller (PWR)",

            .registers =
                    (PeripheralRegisterInfo[] ) {
                                {
                                    .desc =
                                            "PWR power control register (PWR_CR)",
                                    .name = "cr",
                                    .offset_bytes = 0x00,
                                    .reset_value = 0x00004000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lpds",
                                                            .desc =
                                                                    "Low-power deep sleep",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "pdds",
                                                            .desc =
                                                                    "Power-down deepsleep",
                                                            .first_bit = 1, },
                                                        {
                                                            .name = "cwuf",
                                                            .desc =
                                                                    "Clear wakeup flag",
                                                            .first_bit = 2,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "csbf",
                                                            .desc =
                                                                    "Clear standby flag",
                                                            .first_bit = 3,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "pvde",
                                                            .desc =
                                                                    "Power voltage detector enable",
                                                            .first_bit = 4, },
                                                        {
                                                            .name = "pls",
                                                            .desc =
                                                                    "PVD level selection",
                                                            .first_bit = 5,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "dbp",
                                                            .desc =
                                                                    "Disable backup domain write protection",
                                                            .first_bit = 8, },
                                                        { }, /**/
                                                    } , /**/},
                                {
                                    .desc =
                                            "PWR power control/status register (PWR_CSR)",
                                    .name = "csr",
                                    .offset_bytes = 0x04,
                                    .reset_value = 0x00000000,
                                    .bitfields = (RegisterBitfieldInfo[] ) {
                                                {
                                                    .name = "wuf",
                                                    .desc = "Wakeup flag",
                                                    .first_bit = 0,
                                                    .rw_mode =
                                                    REGISTER_RW_MODE_READ, },
                                                {
                                                    .name = "sbf",
                                                    .desc = "Standby flag",
                                                    .first_bit = 1,
                                                    .rw_mode =
                                                    REGISTER_RW_MODE_READ, },
                                                {
                                                    .name = "pvdo",
                                                    .desc = "PVD output",
                                                    .first_bit = 2,
                                                    .rw_mode =
                                                    REGISTER_RW_MODE_READ, },
                                                {
                                                    .name = "ewup",
                                                    .desc = "Enable WKUP pin",
                                                    .first_bit = 8, },
                                                { }, /**/
                                            } , /**/},
                                { }, /**/
                            } , /**/
        };

static void stm32f1_pwr_create_objects(Object *obj)
{
    STM32PWRState *state = STM32_PWR_STATE(obj);

    peripheral_new_with_info(obj, NULL, &stm32f1_pwr_info);

    state->f1.reg.cr = cm_object_get_child_by_name(obj, "cr");
    state->f1.reg.csr = cm_object_get_child_by_name(obj, "csr");

    /* CR bitfields. */
    state->f1.fld.cr.lpds = cm_object_get_child_by_name(state->f1.reg.cr,
            "lpds");
    state->f1.fld.cr.pdds = cm_object_get_child_by_name(state->f1.reg.cr,
            "pdds");
    state->f1.fld.cr.cwuf = cm_object_get_child_by_name(state->f1.reg.cr,
            "cwuf");
    state->f1.fld.cr.csbf = cm_object_get_child_by_name(state->f1.reg.cr,
            "csbf");
    state->f1.fld.cr.pvde = cm_object_get_child_by_name(state->f1.reg.cr,
            "pvde");
    state->f1.fld.cr.pls = cm_object_get_child_by_name(state->f1.reg.cr, "pls");
    state->f1.fld.cr.dbp = cm_object_get_child_by_name(state->f1.reg.cr, "dbp");

    /* CSR bitfields. */
    state->f1.fld.csr.wuf = cm_object_get_child_by_name(state->f1.reg.csr,
            "wuf");
    state->f1.fld.csr.sbf = cm_object_get_child_by_name(state->f1.reg.csr,
            "sbf");
    state->f1.fld.csr.pvdo = cm_object_get_child_by_name(state->f1.reg.csr,
            "pvdo");
    state->f1.fld.csr.ewup = cm_object_get_child_by_name(state->f1.reg.csr,
            "ewup");
}

/* ------------------------------------------------------------------------- */

/* STM32F4_01_57_xx */

static PeripheralInfo stm32f4_01_57_xx_pwr_info =
        {
            .desc = "Power controller (PWR)",

            .registers =
                    (PeripheralRegisterInfo[] ) {
                                {
                                    .desc =
                                            "PWR power control register (PWR_CR)",
                                    .name = "cr",
                                    .offset_bytes = 0x00,
                                    .reset_value = 0x00004000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lpds",
                                                            .desc =
                                                                    "Low-power deep sleep",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "pdds",
                                                            .desc =
                                                                    "Power-down deepsleep",
                                                            .first_bit = 1, },
                                                        {
                                                            .name = "cwuf",
                                                            .desc =
                                                                    "Clear wakeup flag",
                                                            .first_bit = 2,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "csbf",
                                                            .desc =
                                                                    "Clear standby flag",
                                                            .first_bit = 3,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "pvde",
                                                            .desc =
                                                                    "Power voltage detector enable",
                                                            .first_bit = 4, },
                                                        {
                                                            .name = "pls",
                                                            .desc =
                                                                    "PVD level selection",
                                                            .first_bit = 5,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "dbp",
                                                            .desc =
                                                                    "Disable backup domain write protection",
                                                            .first_bit = 8, },
                                                        {
                                                            .name = "fpds",
                                                            .desc =
                                                                    "Flash power-down in Stop mode",
                                                            .first_bit = 9, },
                                                        {
                                                            .name = "vos",
                                                            .desc =
                                                                    "Regulator voltages caling output selection",
                                                            .first_bit = 14, },
                                                        { }, /**/
                                                    } , /**/},
                                {
                                    .desc =
                                            "PWR power control/status register (PWR_CSR)",
                                    .name = "csr",
                                    .offset_bytes = 0x04,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "wuf",
                                                            .desc =
                                                                    "Wakeup flag",
                                                            .first_bit = 0,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "sbf",
                                                            .desc =
                                                                    "Standby flag",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "pvdo",
                                                            .desc = "PVD output",
                                                            .first_bit = 2,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "brr",
                                                            .desc =
                                                                    "CBackup regulator ready",
                                                            .first_bit = 3,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "ewup",
                                                            .desc =
                                                                    "Enable WKUP pin",
                                                            .first_bit = 8, },
                                                        {
                                                            .name = "bre",
                                                            .desc =
                                                                    "Backup regulator enable",
                                                            .first_bit = 9, },
                                                        {
                                                            .name = "vosrdy",
                                                            .desc =
                                                                    "Regulator voltage scaling output selection ready bit",
                                                            .first_bit = 14,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        { }, /**/
                                                    } , /**/},
                                { }, /**/
                            } , /**/
        };

static void stm32f4_01_57_xx_pwr_create_objects(Object *obj)
{
    STM32PWRState *state = STM32_PWR_STATE(obj);

    peripheral_new_with_info(obj, NULL, &stm32f4_01_57_xx_pwr_info);

    state->f4.reg.cr = cm_object_get_child_by_name(obj, "cr");
    state->f4.reg.csr = cm_object_get_child_by_name(obj, "csr");

    /* CR bitfields. */
    state->f4.fld.cr.lpds = cm_object_get_child_by_name(state->f4.reg.cr,
            "lpds");
    state->f4.fld.cr.pdds = cm_object_get_child_by_name(state->f4.reg.cr,
            "pdds");
    state->f4.fld.cr.cwuf = cm_object_get_child_by_name(state->f4.reg.cr,
            "cwuf");
    state->f4.fld.cr.csbf = cm_object_get_child_by_name(state->f4.reg.cr,
            "csbf");
    state->f4.fld.cr.pvde = cm_object_get_child_by_name(state->f4.reg.cr,
            "pvde");
    state->f4.fld.cr.pls = cm_object_get_child_by_name(state->f4.reg.cr, "pls");
    state->f4.fld.cr.dbp = cm_object_get_child_by_name(state->f4.reg.cr, "dbp");
    state->f4.fld.cr.fpds = cm_object_get_child_by_name(state->f4.reg.cr,
            "fpds");
    state->f4.fld.cr.vos = cm_object_get_child_by_name(state->f4.reg.cr, "vos");

    /* CSR bitfields. */
    state->f4.fld.csr.wuf = cm_object_get_child_by_name(state->f4.reg.csr,
            "wuf");
    state->f4.fld.csr.sbf = cm_object_get_child_by_name(state->f4.reg.csr,
            "sbf");
    state->f4.fld.csr.pvdo = cm_object_get_child_by_name(state->f4.reg.csr,
            "pvdo");
    state->f4.fld.csr.brr = cm_object_get_child_by_name(state->f4.reg.csr,
            "brr");
    state->f4.fld.csr.ewup = cm_object_get_child_by_name(state->f4.reg.csr,
            "ewup");
    state->f4.fld.csr.bre = cm_object_get_child_by_name(state->f4.reg.csr,
            "bre");
    state->f4.fld.csr.vosrdy = cm_object_get_child_by_name(state->f4.reg.csr,
            "vosrdy");

}

/* ------------------------------------------------------------------------- */

/* STM32F411_xx */

static PeripheralInfo stm32f411xx_pwr_info =
        {
            .desc = "Power controller (PWR)",

            .registers =
                    (PeripheralRegisterInfo[] ) {
                                {
                                    .desc =
                                            "PWR power control register (PWR_CR)",
                                    .name = "cr",
                                    .offset_bytes = 0x00,
                                    .reset_value = 0x00008000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lpds",
                                                            .desc =
                                                                    "Low-power deep sleep",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "pdds",
                                                            .desc =
                                                                    "Power-down deepsleep",
                                                            .first_bit = 1, },
                                                        {
                                                            .name = "cwuf",
                                                            .desc =
                                                                    "Clear wakeup flag",
                                                            .first_bit = 2,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "csbf",
                                                            .desc =
                                                                    "Clear standby flag",
                                                            .first_bit = 3,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "pvde",
                                                            .desc =
                                                                    "Power voltage detector enable",
                                                            .first_bit = 4, },
                                                        {
                                                            .name = "pls",
                                                            .desc =
                                                                    "PVD level selection",
                                                            .first_bit = 5,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "dbp",
                                                            .desc =
                                                                    "Disable backup domain write protection",
                                                            .first_bit = 8, },
                                                        {
                                                            .name = "fpds",
                                                            .desc =
                                                                    "Flash power-down in Stop mode",
                                                            .first_bit = 9, },
                                                        {
                                                            .name = "vos",
                                                            .desc =
                                                                    "Regulator voltages caling output selection",
                                                            .first_bit = 14, },
                                                        {
                                                            .name = "fmssr",
                                                            .desc =
                                                                    "Flash Memory Sleep System Run",
                                                            .first_bit = 20, },
                                                        {
                                                            .name = "fissr",
                                                            .desc =
                                                                    "Flash Interface Stop while System Run",
                                                            .first_bit = 21, },
                                                        { }, /**/
                                                    } , /**/},
                                {
                                    .desc =
                                            "PWR power control/status register (PWR_CSR)",
                                    .name = "csr",
                                    .offset_bytes = 0x04,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "wuf",
                                                            .desc =
                                                                    "Wakeup flag",
                                                            .first_bit = 0,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "sbf",
                                                            .desc =
                                                                    "Standby flag",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "pvdo",
                                                            .desc = "PVD output",
                                                            .first_bit = 2,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "brr",
                                                            .desc =
                                                                    "CBackup regulator ready",
                                                            .first_bit = 3,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "ewup",
                                                            .desc =
                                                                    "Enable WKUP pin",
                                                            .first_bit = 8, },
                                                        {
                                                            .name = "bre",
                                                            .desc =
                                                                    "Backup regulator enable",
                                                            .first_bit = 9, },
                                                        {
                                                            .name = "vosrdy",
                                                            .desc =
                                                                    "Regulator voltage scaling output selection ready bit",
                                                            .first_bit = 14,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        { }, /**/
                                                    } , /**/},
                                { }, /**/
                            } , /**/
        };

static void stm32f411xx_pwr_create_objects(Object *obj)
{
    STM32PWRState *state = STM32_PWR_STATE(obj);

    peripheral_new_with_info(obj, NULL, &stm32f411xx_pwr_info);

    state->f4.reg.cr = cm_object_get_child_by_name(obj, "cr");
    state->f4.reg.csr = cm_object_get_child_by_name(obj, "csr");

    /* CR bitfields. */
    state->f4.fld.cr.lpds = cm_object_get_child_by_name(state->f4.reg.cr,
            "lpds");
    state->f4.fld.cr.pdds = cm_object_get_child_by_name(state->f4.reg.cr,
            "pdds");
    state->f4.fld.cr.cwuf = cm_object_get_child_by_name(state->f4.reg.cr,
            "cwuf");
    state->f4.fld.cr.csbf = cm_object_get_child_by_name(state->f4.reg.cr,
            "csbf");
    state->f4.fld.cr.pvde = cm_object_get_child_by_name(state->f4.reg.cr,
            "pvde");
    state->f4.fld.cr.pls = cm_object_get_child_by_name(state->f4.reg.cr, "pls");
    state->f4.fld.cr.dbp = cm_object_get_child_by_name(state->f4.reg.cr, "dbp");
    state->f4.fld.cr.fpds = cm_object_get_child_by_name(state->f4.reg.cr,
            "fpds");
    state->f4.fld.cr.vos = cm_object_get_child_by_name(state->f4.reg.cr, "vos");

    /* CSR bitfields. */
    state->f4.fld.csr.wuf = cm_object_get_child_by_name(state->f4.reg.csr,
            "wuf");
    state->f4.fld.csr.sbf = cm_object_get_child_by_name(state->f4.reg.csr,
            "sbf");
    state->f4.fld.csr.pvdo = cm_object_get_child_by_name(state->f4.reg.csr,
            "pvdo");
    state->f4.fld.csr.brr = cm_object_get_child_by_name(state->f4.reg.csr,
            "brr");
    state->f4.fld.csr.ewup = cm_object_get_child_by_name(state->f4.reg.csr,
            "ewup");
    state->f4.fld.csr.bre = cm_object_get_child_by_name(state->f4.reg.csr,
            "bre");
    state->f4.fld.csr.vosrdy = cm_object_get_child_by_name(state->f4.reg.csr,
            "vosrdy");

}
/* ------------------------------------------------------------------------- */

/* STM32F4_23_xxx */

static PeripheralInfo stm32f4_23_xxx_pwr_info =
        {
            .desc = "Power controller (PWR)",

            .registers =
                    (PeripheralRegisterInfo[] ) {
                                {
                                    .desc =
                                            "PWR power control register (PWR_CR)",
                                    .name = "cr",
                                    .offset_bytes = 0x00,
                                    .reset_value = 0x00004000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "lpds",
                                                            .desc =
                                                                    "Low-power deep sleep",
                                                            .first_bit = 0, },
                                                        {
                                                            .name = "pdds",
                                                            .desc =
                                                                    "Power-down deepsleep",
                                                            .first_bit = 1, },
                                                        {
                                                            .name = "cwuf",
                                                            .desc =
                                                                    "Clear wakeup flag",
                                                            .first_bit = 2,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "csbf",
                                                            .desc =
                                                                    "Clear standby flag",
                                                            .first_bit = 3,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_WRITE, },
                                                        {
                                                            .name = "pvde",
                                                            .desc =
                                                                    "Power voltage detector enable",
                                                            .first_bit = 4, },
                                                        {
                                                            .name = "pls",
                                                            .desc =
                                                                    "PVD level selection",
                                                            .first_bit = 5,
                                                            .width_bits = 3, },
                                                        {
                                                            .name = "dbp",
                                                            .desc =
                                                                    "Disable backup domain write protection",
                                                            .first_bit = 8, },
                                                        {
                                                            .name = "fpds",
                                                            .desc =
                                                                    "Flash power-down in Stop mode",
                                                            .first_bit = 9, },
                                                        {
                                                            .name = "lpuds",
                                                            .desc =
                                                                    "Low-power regulator",
                                                            .first_bit = 10, },
                                                        {
                                                            .name = "mruds",
                                                            .desc =
                                                                    "Main regulator in deeppsleep",
                                                            .first_bit = 11, },
                                                        {
                                                            .name = "adcdc1",
                                                            .desc = " ",
                                                            .first_bit = 13, },
                                                        {
                                                            .name = "vos",
                                                            .desc =
                                                                    "Regulator voltages caling output selection",
                                                            .first_bit = 14,
                                                            .width_bits = 2, },
                                                        {
                                                            .name = "oden",
                                                            .desc = " ",
                                                            .first_bit = 16, },
                                                        {
                                                            .name = "odswen",
                                                            .desc = " ",
                                                            .first_bit = 17, },
                                                        {
                                                            .name = "uden",
                                                            .desc = " ",
                                                            .first_bit = 18,
                                                            .width_bits = 2, },
                                                        { }, /**/
                                                    } , /**/},
                                {
                                    .desc =
                                            "PWR power control/status register (PWR_CSR)",
                                    .name = "csr",
                                    .offset_bytes = 0x04,
                                    .reset_value = 0x00000000,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .name = "wuf",
                                                            .desc =
                                                                    "Wakeup flag",
                                                            .first_bit = 0,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "sbf",
                                                            .desc =
                                                                    "Standby flag",
                                                            .first_bit = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "pvdo",
                                                            .desc = "PVD output",
                                                            .first_bit = 2,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "brr",
                                                            .desc =
                                                                    "CBackup regulator ready",
                                                            .first_bit = 3,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "ewup",
                                                            .desc =
                                                                    "Enable WKUP pin",
                                                            .first_bit = 8, },
                                                        {
                                                            .name = "bre",
                                                            .desc =
                                                                    "Backup regulator enable",
                                                            .first_bit = 9, },
                                                        {
                                                            .name = "vosrdy",
                                                            .desc =
                                                                    "Regulator voltage scaling output selection ready bit",
                                                            .first_bit = 14,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "odrdy",
                                                            .desc =
                                                                    "Over-drive ready",
                                                            .first_bit = 16,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "odswrdy",
                                                            .desc =
                                                                    "Over-drive mode switching ready",
                                                            .first_bit = 17,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ, },
                                                        {
                                                            .name = "udrdy",
                                                            .desc =
                                                                    "Unedr-drive ready",
                                                            .first_bit = 18,
                                                            .width_bits = 2, },
                                                        { }, /**/
                                                    } , /**/},
                                { }, /**/
                            } , /**/
        };

static void stm32f4_23_xxx_pwr_create_objects(Object *obj)
{
    STM32PWRState *state = STM32_PWR_STATE(obj);

    peripheral_new_with_info(obj, NULL, &stm32f4_23_xxx_pwr_info);

    state->f4.reg.cr = cm_object_get_child_by_name(obj, "cr");
    state->f4.reg.csr = cm_object_get_child_by_name(obj, "csr");

    /* CR bitfields. */
    state->f4.fld.cr.lpds = cm_object_get_child_by_name(state->f4.reg.cr,
            "lpds");
    state->f4.fld.cr.pdds = cm_object_get_child_by_name(state->f4.reg.cr,
            "pdds");
    state->f4.fld.cr.cwuf = cm_object_get_child_by_name(state->f4.reg.cr,
            "cwuf");
    state->f4.fld.cr.csbf = cm_object_get_child_by_name(state->f4.reg.cr,
            "csbf");
    state->f4.fld.cr.pvde = cm_object_get_child_by_name(state->f4.reg.cr,
            "pvde");
    state->f4.fld.cr.pls = cm_object_get_child_by_name(state->f4.reg.cr, "pls");
    state->f4.fld.cr.dbp = cm_object_get_child_by_name(state->f4.reg.cr, "dbp");
    state->f4.fld.cr.fpds = cm_object_get_child_by_name(state->f4.reg.cr,
            "fpds");
    state->f4.fld.cr.lpuds = cm_object_get_child_by_name(state->f4.reg.cr,
            "lpuds");
    state->f4.fld.cr.mruds = cm_object_get_child_by_name(state->f4.reg.cr,
            "mruds");
    state->f4.fld.cr.adcdc1 = cm_object_get_child_by_name(state->f4.reg.cr,
            "adcdc1");
    state->f4.fld.cr.vos = cm_object_get_child_by_name(state->f4.reg.cr, "vos");
    state->f4.fld.cr.oden = cm_object_get_child_by_name(state->f4.reg.cr,
            "oden");
    state->f4.fld.cr.odswen = cm_object_get_child_by_name(state->f4.reg.cr,
            "odswen");
    state->f4.fld.cr.uden = cm_object_get_child_by_name(state->f4.reg.cr,
            "uden");

    /* CSR bitfields. */
    state->f4.fld.csr.wuf = cm_object_get_child_by_name(state->f4.reg.csr,
            "wuf");
    state->f4.fld.csr.sbf = cm_object_get_child_by_name(state->f4.reg.csr,
            "sbf");
    state->f4.fld.csr.pvdo = cm_object_get_child_by_name(state->f4.reg.csr,
            "pvdo");
    state->f4.fld.csr.brr = cm_object_get_child_by_name(state->f4.reg.csr,
            "brr");
    state->f4.fld.csr.ewup = cm_object_get_child_by_name(state->f4.reg.csr,
            "ewup");
    state->f4.fld.csr.bre = cm_object_get_child_by_name(state->f4.reg.csr,
            "bre");
    state->f4.fld.csr.vosrdy = cm_object_get_child_by_name(state->f4.reg.csr,
            "vosrdy");
    state->f4.fld.csr.odrdy = cm_object_get_child_by_name(state->f4.reg.csr,
            "odrdy");
    state->f4.fld.csr.odswrdy = cm_object_get_child_by_name(state->f4.reg.csr,
            "odswrdy");
    state->f4.fld.csr.udrdy = cm_object_get_child_by_name(state->f4.reg.csr,
            "udrdy");

}

/* ------------------------------------------------------------------------- */

static void stm32_pwr_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

}

static void stm32_pwr_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /*
     * Parent realize() is called after setting properties and creating
     * registers.
     */
    STM32PWRState *state = STM32_PWR_STATE(dev);

    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    uint32_t size;
    hwaddr addr;
    switch (capabilities->family) {
    case STM32_FAMILY_F1:
    case STM32_FAMILY_F4:
        addr = 0x40007000;
        size = 0x400;
        break;

    default:
        /*
         * This will trigger an assertion to fail when creating the
         * memory region in the parent class.
         */
        size = 0;
        addr = 0;
        break;
    }

    cm_object_property_set_int(obj, addr, "mmio-address");
    cm_object_property_set_int(obj, size, "mmio-size-bytes");

    switch (capabilities->family) {
    case STM32_FAMILY_F1:

        stm32f1_pwr_create_objects(obj);
        break;

    case STM32_FAMILY_F4:

        if (capabilities->f4.is_01_57_xx) {

            stm32f4_01_57_xx_pwr_create_objects(obj);

            /* Auto bits. */
            cm_object_property_set_str(state->f4.fld.csr.brr, "bre", "follows");
        } else if (capabilities->f4.is_23_xxx) {

            stm32f4_23_xxx_pwr_create_objects(obj);

            /* Auto bits. */
            cm_object_property_set_str(state->f4.fld.csr.brr, "bre", "follows");
        } else if (capabilities->f4.is11xx) {

            stm32f411xx_pwr_create_objects(obj);

            /* Auto bits. */
            cm_object_property_set_str(state->f4.fld.csr.brr, "bre", "follows");
        }

        break;

    default:
        break;
    }

    /* Call parent realize(). */
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_PWR)) {
        return;
    }
}

static void stm32_pwr_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    /* Call parent reset(). */
    cm_device_parent_reset(dev, TYPE_STM32_PWR);
}

static Property stm32_pwr_properties[] = {
        DEFINE_PROP_NON_VOID_PTR("capabilities", STM32PWRState,
                capabilities, const STM32Capabilities *),
    DEFINE_PROP_END_OF_LIST(), };

static void stm32_pwr_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_pwr_reset_callback;
    dc->realize = stm32_pwr_realize_callback;

    dc->props = stm32_pwr_properties;
}

static const TypeInfo stm32_pwr_type_info = {
    .name = TYPE_STM32_PWR,
    .parent = TYPE_STM32_PWR_PARENT,
    .instance_init = stm32_pwr_instance_init_callback,
    .instance_size = sizeof(STM32PWRState),
    .class_init = stm32_pwr_class_init_callback,
    .class_size = sizeof(STM32PWRClass) };

static void stm32_pwr_register_types(void)
{
    type_register_static(&stm32_pwr_type_info);
}

type_init(stm32_pwr_register_types);

/* ------------------------------------------------------------------------- */

