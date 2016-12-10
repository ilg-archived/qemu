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

#include <hw/cortexm/stm32/pwr.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

/*
 * This file implements the STM32 PWR.
 *
 * The initial implementation is intended only to pass CMSIS initialisations.
 */

/* ----- Private ----------------------------------------------------------- */

/* ------------------------------------------------------------------------- */

/* STM32F051R8 */

static void stm32f0x1_pwr_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    // DO NOT EDIT! Automatically generated!
    STM32PWRState *state = STM32_PWR_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->f0.reg.csr = cm_object_get_child_by_name(obj, "CSR");

    // CR bitfields.
    state->f0.fld.cr.lpds = cm_object_get_child_by_name(state->f0.reg.cr,
            "LPDS");
    state->f0.fld.cr.pdds = cm_object_get_child_by_name(state->f0.reg.cr,
            "PDDS");
    state->f0.fld.cr.cwuf = cm_object_get_child_by_name(state->f0.reg.cr,
            "CWUF");
    state->f0.fld.cr.csbf = cm_object_get_child_by_name(state->f0.reg.cr,
            "CSBF");
    state->f0.fld.cr.pvde = cm_object_get_child_by_name(state->f0.reg.cr,
            "PVDE");
    state->f0.fld.cr.pls = cm_object_get_child_by_name(state->f0.reg.cr, "PLS");
    state->f0.fld.cr.dbp = cm_object_get_child_by_name(state->f0.reg.cr, "DBP");

    // CSR bitfields.
    state->f0.fld.csr.wuf = cm_object_get_child_by_name(state->f0.reg.csr,
            "WUF");
    state->f0.fld.csr.sbf = cm_object_get_child_by_name(state->f0.reg.csr,
            "SBF");
    state->f0.fld.csr.pvdo = cm_object_get_child_by_name(state->f0.reg.csr,
            "PVDO");
    state->f0.fld.csr.vrefintrdy = cm_object_get_child_by_name(
            state->f0.reg.csr, "VREFINTRDY");
    state->f0.fld.csr.ewup1 = cm_object_get_child_by_name(state->f0.reg.csr,
            "EWUP1");
    state->f0.fld.csr.ewup2 = cm_object_get_child_by_name(state->f0.reg.csr,
            "EWUP2");
    state->f0.fld.csr.ewup3 = cm_object_get_child_by_name(state->f0.reg.csr,
            "EWUP3");
    state->f0.fld.csr.ewup4 = cm_object_get_child_by_name(state->f0.reg.csr,
            "EWUP4");
    state->f0.fld.csr.ewup5 = cm_object_get_child_by_name(state->f0.reg.csr,
            "EWUP5");
    state->f0.fld.csr.ewup6 = cm_object_get_child_by_name(state->f0.reg.csr,
            "EWUP6");
    state->f0.fld.csr.ewup7 = cm_object_get_child_by_name(state->f0.reg.csr,
            "EWUP7");
    state->f0.fld.csr.ewup8 = cm_object_get_child_by_name(state->f0.reg.csr,
            "EWUP8");
}

#if 0
static PeripheralInfo stm32f051xx_pwr_info =
{
    .desc = "Power controller (PWR)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_WORD_HALFWORD,

    .registers =
    (PeripheralRegisterInfo[] ) {
        {
            .desc =
            "PWR power control register (PWR_CR)",
            .name = "cr",
            .offset_bytes = 0x00,
            .reset_value = 0x00000000,
            .bitfields =
            (RegisterBitfieldInfo[] ) {
                {
                    .name = "lpds",
                    .desc =
                    "Low-power deep sleep",
                    .first_bit = 0,},
                {
                    .name = "pdds",
                    .desc =
                    "Power-down deepsleep",
                    .first_bit = 1,},
                {
                    /* rc_w1, read as 0, cleared by 1 */
                    .name = "cwuf",
                    .desc =
                    "Clear wakeup flag",
                    .first_bit = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    /* rc_w1, read as 0, cleared by 1 */
                    .name = "csbf",
                    .desc =
                    "Clear standby flag",
                    .first_bit = 3,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "pvde",
                    .desc =
                    "Power voltage detector enable",
                    .first_bit = 4,},
                {
                    .name = "pls",
                    .desc =
                    "PVD level selection",
                    .first_bit = 5,
                    .width_bits = 3,},
                {
                    .name = "dbp",
                    .desc =
                    "Disable backup domain write protection",
                    .first_bit = 8,},
                {}, /**/
            }, /**/},
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
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "sbf",
                    .desc = "Standby flag",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "pvdo",
                    .desc = "PVD output",
                    .first_bit = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "ewup1",
                    .desc = "Enable WKUP1 pin",
                    .first_bit = 8,},
                {
                    .name = "ewup2",
                    .desc = "Enable WKUP2 pin",
                    .first_bit = 9,},
                {
                    .name = "ewup3",
                    .desc = "Enable WKUP3 pin",
                    .first_bit = 10,},
                {
                    .name = "ewup4",
                    .desc = "Enable WKUP4 pin",
                    .first_bit = 11,},
                {
                    .name = "ewup5",
                    .desc = "Enable WKUP5 pin",
                    .first_bit = 12,},
                {
                    .name = "ewup6",
                    .desc = "Enable WKUP6 pin",
                    .first_bit = 13,},
                {
                    .name = "ewup7",
                    .desc = "Enable WKUP7 pin",
                    .first_bit = 14,},
                {
                    .name = "ewup8",
                    .desc = "Enable WKUP8 pin",
                    .first_bit = 15,},
                {}, /**/
            }, /**/},
        {}, /**/
    }, /**/
};
#endif

#if 0
static void stm32f051_pwr_create_objects(Object *obj, JSON_Value *family)
{
    STM32PWRState *state = STM32_PWR_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family, "stm32f051:pwr");

    peripheral_add_properties_and_children2(obj, info);

    state->f0.reg.cr = cm_object_get_child_by_name(obj, "cr");
    state->f0.reg.csr = cm_object_get_child_by_name(obj, "csr");

    /* CR bitfields. */
    state->f0.fld.cr.lpds = cm_object_get_child_by_name(state->f0.reg.cr,
            "lpds");
    state->f0.fld.cr.pdds = cm_object_get_child_by_name(state->f0.reg.cr,
            "pdds");
    state->f0.fld.cr.cwuf = cm_object_get_child_by_name(state->f0.reg.cr,
            "cwuf");
    state->f0.fld.cr.csbf = cm_object_get_child_by_name(state->f0.reg.cr,
            "csbf");
    state->f0.fld.cr.pvde = cm_object_get_child_by_name(state->f0.reg.cr,
            "pvde");
    state->f0.fld.cr.pls = cm_object_get_child_by_name(state->f0.reg.cr, "pls");
    state->f0.fld.cr.dbp = cm_object_get_child_by_name(state->f0.reg.cr, "dbp");

    /* CSR bitfields. */
    state->f0.fld.csr.wuf = cm_object_get_child_by_name(state->f0.reg.csr,
            "wuf");
    state->f0.fld.csr.sbf = cm_object_get_child_by_name(state->f0.reg.csr,
            "sbf");
    state->f0.fld.csr.pvdo = cm_object_get_child_by_name(state->f0.reg.csr,
            "pvdo");
    // state->f0.fld.csr.ewup = cm_object_get_child_by_name(state->f0.reg.csr,
    //        "ewup");
}
#endif

/* ------------------------------------------------------------------------- */

/* STM32F103RB */

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_pwr_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32PWRState *state = STM32_PWR_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->f1.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->f1.reg.csr = cm_object_get_child_by_name(obj, "CSR");

    // CR bitfields.
    state->f1.fld.cr.lpds = cm_object_get_child_by_name(state->f1.reg.cr,
            "LPDS");
    state->f1.fld.cr.pdds = cm_object_get_child_by_name(state->f1.reg.cr,
            "PDDS");
    state->f1.fld.cr.cwuf = cm_object_get_child_by_name(state->f1.reg.cr,
            "CWUF");
    state->f1.fld.cr.csbf = cm_object_get_child_by_name(state->f1.reg.cr,
            "CSBF");
    state->f1.fld.cr.pvde = cm_object_get_child_by_name(state->f1.reg.cr,
            "PVDE");
    state->f1.fld.cr.pls = cm_object_get_child_by_name(state->f1.reg.cr, "PLS");
    state->f1.fld.cr.dbp = cm_object_get_child_by_name(state->f1.reg.cr, "DBP");

    // CSR bitfields.
    state->f1.fld.csr.wuf = cm_object_get_child_by_name(state->f1.reg.csr,
            "WUF");
    state->f1.fld.csr.sbf = cm_object_get_child_by_name(state->f1.reg.csr,
            "SBF");
    state->f1.fld.csr.pvdo = cm_object_get_child_by_name(state->f1.reg.csr,
            "PVDO");
    state->f1.fld.csr.ewup = cm_object_get_child_by_name(state->f1.reg.csr,
            "EWUP");
}

#if 0
static PeripheralInfo stm32f1_pwr_info =
{
    .desc = "Power controller (PWR)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_WORD_HALFWORD,

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
                    .first_bit = 0,},
                {
                    .name = "pdds",
                    .desc =
                    "Power-down deepsleep",
                    .first_bit = 1,},
                {
                    .name = "cwuf",
                    .desc =
                    "Clear wakeup flag",
                    .first_bit = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "csbf",
                    .desc =
                    "Clear standby flag",
                    .first_bit = 3,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "pvde",
                    .desc =
                    "Power voltage detector enable",
                    .first_bit = 4,},
                {
                    .name = "pls",
                    .desc =
                    "PVD level selection",
                    .first_bit = 5,
                    .width_bits = 3,},
                {
                    .name = "dbp",
                    .desc =
                    "Disable backup domain write protection",
                    .first_bit = 8,},
                {}, /**/
            }, /**/},
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
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "sbf",
                    .desc = "Standby flag",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "pvdo",
                    .desc = "PVD output",
                    .first_bit = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "ewup",
                    .desc = "Enable WKUP pin",
                    .first_bit = 8,},
                {}, /**/
            }, /**/},
        {}, /**/
    }, /**/
};
#endif

#if 0
static void stm32f1xx_pwr_create_objects(Object *obj, JSON_Value *family)
{
    STM32PWRState *state = STM32_PWR_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family, "stm32f1xx:pwr");

    peripheral_add_properties_and_children2(obj, info);

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
#endif

/* ------------------------------------------------------------------------- */

static void stm32f40x_pwr_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    // DO NOT EDIT! Automatically generated!
    STM32PWRState *state = STM32_PWR_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->f4.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->f4.reg.csr = cm_object_get_child_by_name(obj, "CSR");

    // CR bitfields.
    state->f4.fld.cr.lpds = cm_object_get_child_by_name(state->f4.reg.cr,
            "LPDS");
    state->f4.fld.cr.pdds = cm_object_get_child_by_name(state->f4.reg.cr,
            "PDDS");
    state->f4.fld.cr.cwuf = cm_object_get_child_by_name(state->f4.reg.cr,
            "CWUF");
    state->f4.fld.cr.csbf = cm_object_get_child_by_name(state->f4.reg.cr,
            "CSBF");
    state->f4.fld.cr.pvde = cm_object_get_child_by_name(state->f4.reg.cr,
            "PVDE");
    state->f4.fld.cr.pls = cm_object_get_child_by_name(state->f4.reg.cr, "PLS");
    state->f4.fld.cr.dbp = cm_object_get_child_by_name(state->f4.reg.cr, "DBP");
    state->f4.fld.cr.fpds = cm_object_get_child_by_name(state->f4.reg.cr,
            "FPDS");

    // CSR bitfields.
    state->f4.fld.csr.wuf = cm_object_get_child_by_name(state->f4.reg.csr,
            "WUF");
    state->f4.fld.csr.sbf = cm_object_get_child_by_name(state->f4.reg.csr,
            "SBF");
    state->f4.fld.csr.pvdo = cm_object_get_child_by_name(state->f4.reg.csr,
            "PVDO");
    state->f4.fld.csr.brr = cm_object_get_child_by_name(state->f4.reg.csr,
            "BRR");
    state->f4.fld.csr.ewup = cm_object_get_child_by_name(state->f4.reg.csr,
            "EWUP");
    state->f4.fld.csr.bre = cm_object_get_child_by_name(state->f4.reg.csr,
            "BRE");
    state->f4.fld.csr.vosrdy = cm_object_get_child_by_name(state->f4.reg.csr,
            "VOSRDY");
}
/* STM32F4_01_57_xx */

#if 0
static PeripheralInfo stm32f4_01_57_xx_pwr_info =
{
    .desc = "Power controller (PWR)",

    /* Assumed. */
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_ALL,

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
                    .first_bit = 0,},
                {
                    .name = "pdds",
                    .desc =
                    "Power-down deepsleep",
                    .first_bit = 1,},
                {
                    .name = "cwuf",
                    .desc =
                    "Clear wakeup flag",
                    .first_bit = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "csbf",
                    .desc =
                    "Clear standby flag",
                    .first_bit = 3,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "pvde",
                    .desc =
                    "Power voltage detector enable",
                    .first_bit = 4,},
                {
                    .name = "pls",
                    .desc =
                    "PVD level selection",
                    .first_bit = 5,
                    .width_bits = 3,},
                {
                    .name = "dbp",
                    .desc =
                    "Disable backup domain write protection",
                    .first_bit = 8,},
                {
                    .name = "fpds",
                    .desc =
                    "Flash power-down in Stop mode",
                    .first_bit = 9,},
                {
                    .name = "vos",
                    .desc =
                    "Regulator voltages caling output selection",
                    .first_bit = 14,},
                {}, /**/
            }, /**/},
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
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "sbf",
                    .desc =
                    "Standby flag",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "pvdo",
                    .desc = "PVD output",
                    .first_bit = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "brr",
                    .desc =
                    "CBackup regulator ready",
                    .first_bit = 3,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "ewup",
                    .desc =
                    "Enable WKUP pin",
                    .first_bit = 8,},
                {
                    .name = "bre",
                    .desc =
                    "Backup regulator enable",
                    .first_bit = 9,},
                {
                    .name = "vosrdy",
                    .desc =
                    "Regulator voltage scaling output selection ready bit",
                    .first_bit = 14,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {}, /**/
            }, /**/},
        {}, /**/
    }, /**/
};
#endif

#if 0
static void stm32f4_01_57_pwr_create_objects(Object *obj, JSON_Value *family)
{
    STM32PWRState *state = STM32_PWR_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family,
            "stm32f4_01_57:pwr");

    peripheral_add_properties_and_children2(obj, info);

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
#if 0
    state->f4.fld.cr.vos = cm_object_get_child_by_name(state->f4.reg.cr, "vos");
#endif
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
#endif

/* ------------------------------------------------------------------------- */

/* STM32F411_xx */

#if 0
static PeripheralInfo stm32f411xx_pwr_info =
{
    .desc = "Power controller (PWR)",

    /* Assumed. */
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_ALL,

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
                    .first_bit = 0,},
                {
                    .name = "pdds",
                    .desc =
                    "Power-down deepsleep",
                    .first_bit = 1,},
                {
                    .name = "cwuf",
                    .desc =
                    "Clear wakeup flag",
                    .first_bit = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "csbf",
                    .desc =
                    "Clear standby flag",
                    .first_bit = 3,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "pvde",
                    .desc =
                    "Power voltage detector enable",
                    .first_bit = 4,},
                {
                    .name = "pls",
                    .desc =
                    "PVD level selection",
                    .first_bit = 5,
                    .width_bits = 3,},
                {
                    .name = "dbp",
                    .desc =
                    "Disable backup domain write protection",
                    .first_bit = 8,},
                {
                    .name = "fpds",
                    .desc =
                    "Flash power-down in Stop mode",
                    .first_bit = 9,},
                {
                    .name = "vos",
                    .desc =
                    "Regulator voltages caling output selection",
                    .first_bit = 14,},
                {
                    .name = "fmssr",
                    .desc =
                    "Flash Memory Sleep System Run",
                    .first_bit = 20,},
                {
                    .name = "fissr",
                    .desc =
                    "Flash Interface Stop while System Run",
                    .first_bit = 21,},
                {}, /**/
            }, /**/},
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
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "sbf",
                    .desc =
                    "Standby flag",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "pvdo",
                    .desc = "PVD output",
                    .first_bit = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "brr",
                    .desc =
                    "CBackup regulator ready",
                    .first_bit = 3,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "ewup",
                    .desc =
                    "Enable WKUP pin",
                    .first_bit = 8,},
                {
                    .name = "bre",
                    .desc =
                    "Backup regulator enable",
                    .first_bit = 9,},
                {
                    .name = "vosrdy",
                    .desc =
                    "Regulator voltage scaling output selection ready bit",
                    .first_bit = 14,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {}, /**/
            }, /**/},
        {}, /**/
    }, /**/
};
#endif

#if 0
static void stm32f411_pwr_create_objects(Object *obj, JSON_Value *family)
{
    STM32PWRState *state = STM32_PWR_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family, "stm32f411:pwr");

    peripheral_add_properties_and_children2(obj, info);

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
#if 0
    state->f4.fld.cr.vos = cm_object_get_child_by_name(state->f4.reg.cr, "vos");
#endif
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
#endif

/* ------------------------------------------------------------------------- */

/* STM32F4_23_xxx */

#if 0
static PeripheralInfo stm32f4_23_xxx_pwr_info =
{
    .desc = "Power controller (PWR)",

    /* Assumed. */
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_ALL,

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
                    .first_bit = 0,},
                {
                    .name = "pdds",
                    .desc =
                    "Power-down deepsleep",
                    .first_bit = 1,},
                {
                    .name = "cwuf",
                    .desc =
                    "Clear wakeup flag",
                    .first_bit = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "csbf",
                    .desc =
                    "Clear standby flag",
                    .first_bit = 3,
                    .rw_mode =
                    REGISTER_RW_MODE_WRITE,},
                {
                    .name = "pvde",
                    .desc =
                    "Power voltage detector enable",
                    .first_bit = 4,},
                {
                    .name = "pls",
                    .desc =
                    "PVD level selection",
                    .first_bit = 5,
                    .width_bits = 3,},
                {
                    .name = "dbp",
                    .desc =
                    "Disable backup domain write protection",
                    .first_bit = 8,},
                {
                    .name = "fpds",
                    .desc =
                    "Flash power-down in Stop mode",
                    .first_bit = 9,},
                {
                    .name = "lpuds",
                    .desc =
                    "Low-power regulator",
                    .first_bit = 10,},
                {
                    .name = "mruds",
                    .desc =
                    "Main regulator in deeppsleep",
                    .first_bit = 11,},
                {
                    .name = "adcdc1",
                    .desc = " ",
                    .first_bit = 13,},
                {
                    .name = "vos",
                    .desc =
                    "Regulator voltages caling output selection",
                    .first_bit = 14,
                    .width_bits = 2,},
                {
                    .name = "oden",
                    .desc = " ",
                    .first_bit = 16,},
                {
                    .name = "odswen",
                    .desc = " ",
                    .first_bit = 17,},
                {
                    .name = "uden",
                    .desc = " ",
                    .first_bit = 18,
                    .width_bits = 2,},
                {}, /**/
            }, /**/},
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
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "sbf",
                    .desc =
                    "Standby flag",
                    .first_bit = 1,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "pvdo",
                    .desc = "PVD output",
                    .first_bit = 2,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "brr",
                    .desc =
                    "CBackup regulator ready",
                    .first_bit = 3,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "ewup",
                    .desc =
                    "Enable WKUP pin",
                    .first_bit = 8,},
                {
                    .name = "bre",
                    .desc =
                    "Backup regulator enable",
                    .first_bit = 9,},
                {
                    .name = "vosrdy",
                    .desc =
                    "Regulator voltage scaling output selection ready bit",
                    .first_bit = 14,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "odrdy",
                    .desc =
                    "Over-drive ready",
                    .first_bit = 16,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "odswrdy",
                    .desc =
                    "Over-drive mode switching ready",
                    .first_bit = 17,
                    .rw_mode =
                    REGISTER_RW_MODE_READ,},
                {
                    .name = "udrdy",
                    .desc =
                    "Unedr-drive ready",
                    .first_bit = 18,
                    .width_bits = 2,},
                {}, /**/
            }, /**/},
        {}, /**/
    }, /**/
};
#endif

#if 0
static void stm32f4_23_x_pwr_create_objects(Object *obj, JSON_Value *family)
{
    STM32PWRState *state = STM32_PWR_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family,
            "stm32f4_23_x:pwr");

    peripheral_add_properties_and_children2(obj, info);

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
#if 0
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
#endif

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
#if 0
    state->f4.fld.csr.odrdy = cm_object_get_child_by_name(state->f4.reg.csr,
            "odrdy");
    state->f4.fld.csr.odswrdy = cm_object_get_child_by_name(state->f4.reg.csr,
            "odswrdy");
    state->f4.fld.csr.udrdy = cm_object_get_child_by_name(state->f4.reg.csr,
            "udrdy");
#endif
}
#endif

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

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32PWRState *state = STM32_PWR_STATE(dev);
    /* First thing first: get capabilities from MCU, needed everywhere. */
    state->capabilities = mcu->capabilities;

    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    /*
     * Creating the memory region in the parent class will trigger
     * an assertion if zro address or size.
     */
    uint32_t size = 0;
    hwaddr addr = 0;

    switch (capabilities->family) {
    case STM32_FAMILY_F0:
    case STM32_FAMILY_F1:
    case STM32_FAMILY_F4:
        addr = 0x40007000;
        size = 0x400;
        break;

    default:
        assert(false);
        break;
    }

    cm_object_property_set_int(obj, addr, "mmio-address");
    cm_object_property_set_int(obj, size, "mmio-size-bytes");

    switch (capabilities->family) {
    case STM32_FAMILY_F0:
        stm32f0x1_pwr_create_objects(obj, cm_state->svd_json, "PWR");

        // stm32f051_pwr_create_objects(obj, mcu->family_json);
        break;

    case STM32_FAMILY_F1:

        stm32f103xx_pwr_create_objects(obj, cm_state->svd_json, "PWR");

        // stm32f1xx_pwr_create_objects(obj, mcu->family_json);
        break;

    case STM32_FAMILY_F4:
        if (capabilities->f4.is_40x) {
            stm32f40x_pwr_create_objects(obj, cm_state->svd_json, "PWR");
            /* Auto bits. */
            cm_object_property_set_str(state->f4.fld.csr.brr, "BRE", "follows");
#if 0
        } else if (capabilities->f4.is_01_57_xx) {
            stm32f4_01_57_pwr_create_objects(obj, mcu->family_json);
            /* Auto bits. */
            cm_object_property_set_str(state->f4.fld.csr.brr, "bre", "follows");
        } else if (capabilities->f4.is_23_xxx) {
            stm32f4_23_x_pwr_create_objects(obj, mcu->family_json);
            /* Auto bits. */
            cm_object_property_set_str(state->f4.fld.csr.brr, "bre", "follows");
        } else if (capabilities->f4.is11xx) {
            stm32f411_pwr_create_objects(obj, mcu->family_json);
            /* Auto bits. */
            cm_object_property_set_str(state->f4.fld.csr.brr, "bre", "follows");
#endif
        }

        break;

    default:
        assert(false);
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

#if 0
    peripheral_serialize_info("f051-pwr.json", "stm32f051:pwr", &stm32f051xx_pwr_info);
    peripheral_serialize_info("f1xx-pwr.json", "stm32f1xx:pwr", &stm32f1_pwr_info);
    peripheral_serialize_info("f4_01_57-pwr.json", "stm32f4_01_57:pwr", &stm32f4_01_57_xx_pwr_info);
    peripheral_serialize_info("f4_23_x-pwr.json", "stm32f4_23_x:pwr", &stm32f4_23_xxx_pwr_info);
    peripheral_serialize_info("f411-pwr.json", "stm32f411:pwr", &stm32f411xx_pwr_info);
#endif
}

type_init(stm32_pwr_register_types);

/* ------------------------------------------------------------------------- */

