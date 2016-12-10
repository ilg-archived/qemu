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

#include <hw/cortexm/stm32/flash.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

/*
 * This file implements the STM32 flash control.
 *
 * The initial implementation is intended only to pass CMSIS initialisations.
 * The written values can be read back, but no other actions are supported.
 */

/* ------------------------------------------------------------------------- */

static void stm32f0x1_flash_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    // DO NOT EDIT! Automatically generated!
    STM32FLASHState *state = STM32_FLASH_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->f0.reg.acr = cm_object_get_child_by_name(obj, "ACR");
    state->f0.reg.keyr = cm_object_get_child_by_name(obj, "KEYR");
    state->f0.reg.optkeyr = cm_object_get_child_by_name(obj, "OPTKEYR");
    state->f0.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->f0.reg.ar = cm_object_get_child_by_name(obj, "AR");
    state->f0.reg.obr = cm_object_get_child_by_name(obj, "OBR");
    state->f0.reg.wrpr = cm_object_get_child_by_name(obj, "WRPR");

    // ACR bitfields.
    state->f0.fld.acr.latency = cm_object_get_child_by_name(state->f0.reg.acr,
            "LATENCY");
    state->f0.fld.acr.prftbe = cm_object_get_child_by_name(state->f0.reg.acr,
            "PRFTBE");
    state->f0.fld.acr.prftbs = cm_object_get_child_by_name(state->f0.reg.acr,
            "PRFTBS");

    // KEYR bitfields.
    state->f0.fld.keyr.fkeyr = cm_object_get_child_by_name(state->f0.reg.keyr,
            "FKEYR");

    // OPTKEYR bitfields.
    state->f0.fld.optkeyr.optkeyr = cm_object_get_child_by_name(
            state->f0.reg.optkeyr, "OPTKEYR");

    // SR bitfields.
    state->f0.fld.sr.bsy = cm_object_get_child_by_name(state->f0.reg.sr, "BSY");
    state->f0.fld.sr.pgerr = cm_object_get_child_by_name(state->f0.reg.sr,
            "PGERR");
    state->f0.fld.sr.wrprt = cm_object_get_child_by_name(state->f0.reg.sr,
            "WRPRT");
    state->f0.fld.sr.eop = cm_object_get_child_by_name(state->f0.reg.sr, "EOP");

    // CR bitfields.
    state->f0.fld.cr.pg = cm_object_get_child_by_name(state->f0.reg.cr, "PG");
    state->f0.fld.cr.per = cm_object_get_child_by_name(state->f0.reg.cr, "PER");
    state->f0.fld.cr.mer = cm_object_get_child_by_name(state->f0.reg.cr, "MER");
    state->f0.fld.cr.optpg = cm_object_get_child_by_name(state->f0.reg.cr,
            "OPTPG");
    state->f0.fld.cr.opter = cm_object_get_child_by_name(state->f0.reg.cr,
            "OPTER");
    state->f0.fld.cr.strt = cm_object_get_child_by_name(state->f0.reg.cr,
            "STRT");
    state->f0.fld.cr.lock = cm_object_get_child_by_name(state->f0.reg.cr,
            "LOCK");
    state->f0.fld.cr.optwre = cm_object_get_child_by_name(state->f0.reg.cr,
            "OPTWRE");
    state->f0.fld.cr.errie = cm_object_get_child_by_name(state->f0.reg.cr,
            "ERRIE");
    state->f0.fld.cr.eopie = cm_object_get_child_by_name(state->f0.reg.cr,
            "EOPIE");
    state->f0.fld.cr.force_optload = cm_object_get_child_by_name(
            state->f0.reg.cr, "FORCE_OPTLOAD");

    // AR bitfields.
    state->f0.fld.ar.far = cm_object_get_child_by_name(state->f0.reg.ar, "FAR");

    // OBR bitfields.
    state->f0.fld.obr.opterr = cm_object_get_child_by_name(state->f0.reg.obr,
            "OPTERR");
    state->f0.fld.obr.level1_prot = cm_object_get_child_by_name(
            state->f0.reg.obr, "LEVEL1_PROT");
    state->f0.fld.obr.level2_prot = cm_object_get_child_by_name(
            state->f0.reg.obr, "LEVEL2_PROT");
    state->f0.fld.obr.wdg_sw = cm_object_get_child_by_name(state->f0.reg.obr,
            "WDG_SW");
    state->f0.fld.obr.nrst_stop = cm_object_get_child_by_name(state->f0.reg.obr,
            "nRST_STOP");
    state->f0.fld.obr.nrst_stdby = cm_object_get_child_by_name(
            state->f0.reg.obr, "nRST_STDBY");
    state->f0.fld.obr.boot1 = cm_object_get_child_by_name(state->f0.reg.obr,
            "BOOT1");
    state->f0.fld.obr.vdda_monitor = cm_object_get_child_by_name(
            state->f0.reg.obr, "VDDA_MONITOR");
    state->f0.fld.obr.data0 = cm_object_get_child_by_name(state->f0.reg.obr,
            "Data0");
    state->f0.fld.obr.data1 = cm_object_get_child_by_name(state->f0.reg.obr,
            "Data1");

    // WRPR bitfields.
    state->f0.fld.wrpr.wrp = cm_object_get_child_by_name(state->f0.reg.wrpr,
            "WRP");
}

#if 0
static PeripheralInfo stm32f051xx_flash_info = {
    .desc = "Reset and clock control (RCC)",

    .default_access_flags = PERIPHERAL_REGISTER_32BITS_WORD,

    .registers = (PeripheralRegisterInfo[] ) {
        {
            .desc = "Flash access control register (FLASH_ACR)",
            .name = "acr",
            .offset_bytes = 0x00,
            .reset_value = 0x00000000,
            .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "latency",
                    .first_bit = 0,
                    .width_bits = 3,},
                {
                    .name = "prftbe",
                    .desc = "Prefetch buffer enable",
                    .first_bit = 4,},
                {
                    .name = "prftbs",
                    .desc = "Prefetch buffer status",
                    .first_bit = 5,
                    .rw_mode = REGISTER_RW_MODE_READ,},
                {}, /**/
            }, /**/
        },
        /* Very schematic, functional read after write only. */
        {
            .name = "keyr",
            .offset_bytes = 0x04,},
        {
            .name = "optkeyr",
            .offset_bytes = 0x08,},
        {
            .name = "sr",
            .offset_bytes = 0x0C,},
        {
            .name = "cr",
            .offset_bytes = 0x10,},
        {
            .name = "ar",
            .offset_bytes = 0x14,},
        /* 0x18 is reserved */
        {
            .name = "obr",
            .offset_bytes = 0x1C,},
        {
            .name = "wrpr",
            .offset_bytes = 0x20,},
        {}, /**/
    }, /**/
};
#endif

#if 0
static void stm32f051_flash_create_objects(Object *obj, JSON_Value *family)
{
    STM32FLASHState *state = STM32_FLASH_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family,
            "stm32f051:flash");

    peripheral_add_properties_and_children2(obj, info);

    state->f0.reg.acr = cm_object_get_child_by_name(obj, "acr");
    state->f0.reg.keyr = cm_object_get_child_by_name(obj, "keyr");
    state->f0.reg.optkeyr = cm_object_get_child_by_name(obj, "optkeyr");
    state->f0.reg.sr = cm_object_get_child_by_name(obj, "sr");
    state->f0.reg.cr = cm_object_get_child_by_name(obj, "cr");
    state->f0.reg.ar = cm_object_get_child_by_name(obj, "ar");
    state->f0.reg.obr = cm_object_get_child_by_name(obj, "obr");
    state->f0.reg.wrpr = cm_object_get_child_by_name(obj, "wrpr");

    /* ACR bitfields. */
    state->f0.acr.prftbs = cm_object_get_child_by_name(
            OBJECT(state->f0.reg.acr), "prftbs");
}
#endif

/* ------------------------------------------------------------------------- */

// DO NOT EDIT! Automatically generated!
static void stm32f103xx_flash_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32FLASHState *state = STM32_FLASH_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->f1.reg.acr = cm_object_get_child_by_name(obj, "ACR");
    state->f1.reg.keyr = cm_object_get_child_by_name(obj, "KEYR");
    state->f1.reg.optkeyr = cm_object_get_child_by_name(obj, "OPTKEYR");
    state->f1.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->f1.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->f1.reg.ar = cm_object_get_child_by_name(obj, "AR");
    state->f1.reg.obr = cm_object_get_child_by_name(obj, "OBR");
    state->f1.reg.wrpr = cm_object_get_child_by_name(obj, "WRPR");

    // ACR bitfields.
    state->f1.fld.acr.latency = cm_object_get_child_by_name(state->f1.reg.acr,
            "LATENCY");
    state->f1.fld.acr.hlfcya = cm_object_get_child_by_name(state->f1.reg.acr,
            "HLFCYA");
    state->f1.fld.acr.prftbe = cm_object_get_child_by_name(state->f1.reg.acr,
            "PRFTBE");
    state->f1.fld.acr.prftbs = cm_object_get_child_by_name(state->f1.reg.acr,
            "PRFTBS");

    // KEYR bitfields.
    state->f1.fld.keyr.key = cm_object_get_child_by_name(state->f1.reg.keyr,
            "KEY");

    // OPTKEYR bitfields.
    state->f1.fld.optkeyr.optkey = cm_object_get_child_by_name(
            state->f1.reg.optkeyr, "OPTKEY");

    // SR bitfields.
    state->f1.fld.sr.bsy = cm_object_get_child_by_name(state->f1.reg.sr, "BSY");
    state->f1.fld.sr.pgerr = cm_object_get_child_by_name(state->f1.reg.sr,
            "PGERR");
    state->f1.fld.sr.wrprterr = cm_object_get_child_by_name(state->f1.reg.sr,
            "WRPRTERR");
    state->f1.fld.sr.eop = cm_object_get_child_by_name(state->f1.reg.sr, "EOP");

    // CR bitfields.
    state->f1.fld.cr.pg = cm_object_get_child_by_name(state->f1.reg.cr, "PG");
    state->f1.fld.cr.per = cm_object_get_child_by_name(state->f1.reg.cr, "PER");
    state->f1.fld.cr.mer = cm_object_get_child_by_name(state->f1.reg.cr, "MER");
    state->f1.fld.cr.optpg = cm_object_get_child_by_name(state->f1.reg.cr,
            "OPTPG");
    state->f1.fld.cr.opter = cm_object_get_child_by_name(state->f1.reg.cr,
            "OPTER");
    state->f1.fld.cr.strt = cm_object_get_child_by_name(state->f1.reg.cr,
            "STRT");
    state->f1.fld.cr.lock = cm_object_get_child_by_name(state->f1.reg.cr,
            "LOCK");
    state->f1.fld.cr.optwre = cm_object_get_child_by_name(state->f1.reg.cr,
            "OPTWRE");
    state->f1.fld.cr.errie = cm_object_get_child_by_name(state->f1.reg.cr,
            "ERRIE");
    state->f1.fld.cr.eopie = cm_object_get_child_by_name(state->f1.reg.cr,
            "EOPIE");

    // AR bitfields.
    state->f1.fld.ar.far = cm_object_get_child_by_name(state->f1.reg.ar, "FAR");

    // OBR bitfields.
    state->f1.fld.obr.opterr = cm_object_get_child_by_name(state->f1.reg.obr,
            "OPTERR");
    state->f1.fld.obr.rdprt = cm_object_get_child_by_name(state->f1.reg.obr,
            "RDPRT");
    state->f1.fld.obr.wdg_sw = cm_object_get_child_by_name(state->f1.reg.obr,
            "WDG_SW");
    state->f1.fld.obr.nrst_stop = cm_object_get_child_by_name(state->f1.reg.obr,
            "nRST_STOP");
    state->f1.fld.obr.nrst_stdby = cm_object_get_child_by_name(
            state->f1.reg.obr, "nRST_STDBY");
    state->f1.fld.obr.data0 = cm_object_get_child_by_name(state->f1.reg.obr,
            "Data0");
    state->f1.fld.obr.data1 = cm_object_get_child_by_name(state->f1.reg.obr,
            "Data1");

    // WRPR bitfields.
    state->f1.fld.wrpr.wrp = cm_object_get_child_by_name(state->f1.reg.wrpr,
            "WRP");
}

#if 0
static PeripheralInfo stm32f1_flash_info = {
    .desc = "Reset and clock control (RCC)",

    /* Assumed, not found in the reference manual. */
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_ALL,

    .registers = (PeripheralRegisterInfo[] ) {
        {
            .desc = "Flash access control register (FLASH_ACR)",
            .name = "acr",
            .offset_bytes = 0x00,
            .reset_value = 0x00000030,
            .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "latency",
                    .first_bit = 0,
                    .width_bits = 3,},
                {
                    .name = "hlfcya",
                    .desc = "Flash half cycle access enable",
                    .first_bit = 3,},
                {
                    .name = "prftbe",
                    .desc = "Prefetch buffer enable",
                    .first_bit = 4,},
                {
                    .name = "prftbs",
                    .desc = "Prefetch buffer status",
                    .first_bit = 5,
                    .rw_mode = REGISTER_RW_MODE_READ,},
                {}, /**/
            }, /**/
        },
        /* Very schematic, functional read after write only. */
        {
            .name = "keyr",
            .offset_bytes = 0x04,},
        {
            .name = "optkeyr",
            .offset_bytes = 0x08,},
        {
            .name = "sr",
            .offset_bytes = 0x0C,},
        {
            .name = "cr",
            .offset_bytes = 0x10,},
        {
            .name = "ar",
            .offset_bytes = 0x14,},
        /* 0x18 is reserved */
        {
            .name = "obr",
            .offset_bytes = 0x1C,},
        {
            .name = "wrpr",
            .offset_bytes = 0x20,},
        {}, /**/
    }, /**/
};
#endif

#if 0
static void stm32f1xx_flash_create_objects(Object *obj, JSON_Value *family)
{
    STM32FLASHState *state = STM32_FLASH_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family,
            "stm32f1xx:flash");

    peripheral_add_properties_and_children2(obj, info);

    state->f1.reg.acr = cm_object_get_child_by_name(obj, "acr");
    state->f1.reg.keyr = cm_object_get_child_by_name(obj, "keyr");
    state->f1.reg.optkeyr = cm_object_get_child_by_name(obj, "optkeyr");
    state->f1.reg.sr = cm_object_get_child_by_name(obj, "sr");
    state->f1.reg.cr = cm_object_get_child_by_name(obj, "cr");
    state->f1.reg.ar = cm_object_get_child_by_name(obj, "ar");
    state->f1.reg.obr = cm_object_get_child_by_name(obj, "obr");
    state->f1.reg.wrpr = cm_object_get_child_by_name(obj, "wrpr");

    /* ACR bitfields. */
    state->f1.acr.prftbs = cm_object_get_child_by_name(
            OBJECT(state->f1.reg.acr), "prftbs");
}
#endif

/* ------------------------------------------------------------------------- */

#if 0
static PeripheralInfo stm32f1xd_flash_info = {
    .desc = "Reset and clock control (RCC)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_ALL,

    .registers = (PeripheralRegisterInfo[] ) {
        {
            .desc = "Flash access control register (FLASH_ACR)",
            .name = "acr",
            .offset_bytes = 0x00,
            .reset_value = 0x00000030,
            .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "latency",
                    .first_bit = 0,
                    .width_bits = 3,},
                {
                    .name = "hlfcya",
                    .desc = "Flash half cycle access enable",
                    .first_bit = 3,},
                {
                    .name = "prftbe",
                    .desc = "Prefetch buffer enable",
                    .first_bit = 4,},
                {
                    .name = "prftbs",
                    .desc = "Prefetch buffer status",
                    .first_bit = 5,
                    .rw_mode = REGISTER_RW_MODE_READ,},
                {}, /**/
            }, /**/
        },
        /* Very schematic, functional read after write only. */
        {
            .name = "keyr",
            .offset_bytes = 0x04,},
        {
            .name = "optkeyr",
            .offset_bytes = 0x08,},
        {
            .name = "sr",
            .offset_bytes = 0x0C,},
        {
            .name = "cr",
            .offset_bytes = 0x10,},
        {
            .name = "ar",
            .offset_bytes = 0x14,},
        /* 0x18 is reserved */
        {
            .name = "obr",
            .offset_bytes = 0x1C,},
        {
            .name = "wrpr",
            .offset_bytes = 0x20,},

        /*
         * XL density devices specific.
         */
        {
            .name = "keyr2",
            .offset_bytes = 0x44,},
        {
            .name = "sr2",
            .offset_bytes = 0x4C,},
        {
            .name = "cr2",
            .offset_bytes = 0x50,},
        {
            .name = "ar2",
            .offset_bytes = 0x54,},

        {}, /**/
    }, /**/
};
#endif

#if 0
static void stm32f1xd_flash_create_objects(Object *obj, JSON_Value *family)
{
    STM32FLASHState *state = STM32_FLASH_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family,
            "stm32f1xd:flash");

    peripheral_add_properties_and_children2(obj, info);

    state->f1.reg.acr = cm_object_get_child_by_name(obj, "acr");
    state->f1.reg.keyr = cm_object_get_child_by_name(obj, "keyr");
    state->f1.reg.optkeyr = cm_object_get_child_by_name(obj, "optkeyr");
    state->f1.reg.sr = cm_object_get_child_by_name(obj, "sr");
    state->f1.reg.cr = cm_object_get_child_by_name(obj, "cr");
    state->f1.reg.ar = cm_object_get_child_by_name(obj, "ar");
    state->f1.reg.obr = cm_object_get_child_by_name(obj, "obr");
    state->f1.reg.wrpr = cm_object_get_child_by_name(obj, "wrpr");

    state->f1.reg.keyr2 = cm_object_get_child_by_name(obj, "keyr2");
    state->f1.reg.sr2 = cm_object_get_child_by_name(obj, "sr2");
    state->f1.reg.cr2 = cm_object_get_child_by_name(obj, "cr2");
    state->f1.reg.ar2 = cm_object_get_child_by_name(obj, "ar2");

    /* ACR bitfields. */
    state->f1.acr.prftbs = cm_object_get_child_by_name(
            OBJECT(state->f1.reg.acr), "prftbs");
}
#endif

/* ------------------------------------------------------------------------- */

static void stm32f40x_flash_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    // DO NOT EDIT! Automatically generated!
    STM32FLASHState *state = STM32_FLASH_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->f4.reg.acr = cm_object_get_child_by_name(obj, "ACR");
    state->f4.reg.keyr = cm_object_get_child_by_name(obj, "KEYR");
    state->f4.reg.optkeyr = cm_object_get_child_by_name(obj, "OPTKEYR");
    state->f4.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->f4.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->f4.reg.optcr = cm_object_get_child_by_name(obj, "OPTCR");

    // ACR bitfields.
    state->f4.fld.acr.latency = cm_object_get_child_by_name(state->f4.reg.acr,
            "LATENCY");
    state->f4.fld.acr.prften = cm_object_get_child_by_name(state->f4.reg.acr,
            "PRFTEN");
    state->f4.fld.acr.icen = cm_object_get_child_by_name(state->f4.reg.acr,
            "ICEN");
    state->f4.fld.acr.dcen = cm_object_get_child_by_name(state->f4.reg.acr,
            "DCEN");
    state->f4.fld.acr.icrst = cm_object_get_child_by_name(state->f4.reg.acr,
            "ICRST");
    state->f4.fld.acr.dcrst = cm_object_get_child_by_name(state->f4.reg.acr,
            "DCRST");

    // KEYR bitfields.
    state->f4.fld.keyr.key = cm_object_get_child_by_name(state->f4.reg.keyr,
            "KEY");

    // OPTKEYR bitfields.
    state->f4.fld.optkeyr.optkey = cm_object_get_child_by_name(
            state->f4.reg.optkeyr, "OPTKEY");

    // SR bitfields.
    state->f4.fld.sr.eop = cm_object_get_child_by_name(state->f4.reg.sr, "EOP");
    state->f4.fld.sr.operr = cm_object_get_child_by_name(state->f4.reg.sr,
            "OPERR");
    state->f4.fld.sr.wrperr = cm_object_get_child_by_name(state->f4.reg.sr,
            "WRPERR");
    state->f4.fld.sr.pgaerr = cm_object_get_child_by_name(state->f4.reg.sr,
            "PGAERR");
    state->f4.fld.sr.pgperr = cm_object_get_child_by_name(state->f4.reg.sr,
            "PGPERR");
    state->f4.fld.sr.pgserr = cm_object_get_child_by_name(state->f4.reg.sr,
            "PGSERR");
    state->f4.fld.sr.bsy = cm_object_get_child_by_name(state->f4.reg.sr, "BSY");

    // CR bitfields.
    state->f4.fld.cr.pg = cm_object_get_child_by_name(state->f4.reg.cr, "PG");
    state->f4.fld.cr.ser = cm_object_get_child_by_name(state->f4.reg.cr, "SER");
    state->f4.fld.cr.mer = cm_object_get_child_by_name(state->f4.reg.cr, "MER");
    state->f4.fld.cr.snb = cm_object_get_child_by_name(state->f4.reg.cr, "SNB");
    state->f4.fld.cr.psize = cm_object_get_child_by_name(state->f4.reg.cr,
            "PSIZE");
    state->f4.fld.cr.strt = cm_object_get_child_by_name(state->f4.reg.cr,
            "STRT");
    state->f4.fld.cr.eopie = cm_object_get_child_by_name(state->f4.reg.cr,
            "EOPIE");
    state->f4.fld.cr.errie = cm_object_get_child_by_name(state->f4.reg.cr,
            "ERRIE");
    state->f4.fld.cr.lock = cm_object_get_child_by_name(state->f4.reg.cr,
            "LOCK");

    // OPTCR bitfields.
    state->f4.fld.optcr.optlock = cm_object_get_child_by_name(
            state->f4.reg.optcr, "OPTLOCK");
    state->f4.fld.optcr.optstrt = cm_object_get_child_by_name(
            state->f4.reg.optcr, "OPTSTRT");
    state->f4.fld.optcr.bor_lev = cm_object_get_child_by_name(
            state->f4.reg.optcr, "BOR_LEV");
    state->f4.fld.optcr.wdg_sw = cm_object_get_child_by_name(
            state->f4.reg.optcr, "WDG_SW");
    state->f4.fld.optcr.nrst_stop = cm_object_get_child_by_name(
            state->f4.reg.optcr, "nRST_STOP");
    state->f4.fld.optcr.nrst_stdby = cm_object_get_child_by_name(
            state->f4.reg.optcr, "nRST_STDBY");
    state->f4.fld.optcr.rdp = cm_object_get_child_by_name(state->f4.reg.optcr,
            "RDP");
    state->f4.fld.optcr.nwrp = cm_object_get_child_by_name(state->f4.reg.optcr,
            "nWRP");
}

#if 0
static PeripheralInfo stm32f4_01_57_xx_flash_info = {
    .desc = "Reset and clock control (RCC)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_ALL,

    .registers = (PeripheralRegisterInfo[] ) {
        {
            .desc = "Flash access control register (FLASH_ACR)",
            .name = "acr",
            .offset_bytes = 0x00,
            .reset_value = 0x00000030,
            .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "latency",
                    .first_bit = 0,
                    .width_bits = 3,},
                {
                    .name = "prften",
                    .desc = "Prefetch enable",
                    .first_bit = 8,},
                {
                    .name = "icen",
                    .desc = "Prefetch enable",
                    .first_bit = 9,},
                {
                    .name = "dcen",
                    .desc = "Data cache enable",
                    .first_bit = 10,},
                {
                    .name = "icrst",
                    .desc = "Instruction cache reset",
                    .first_bit = 11,
                    .rw_mode = REGISTER_RW_MODE_READ,},
                {
                    .name = "dcrst",
                    .desc = "Data cache reset",
                    .first_bit = 12,},
                {}, /**/
            }, /**/
        },
        /* Very schematic, functional read after write only. */
        {
            .name = "keyr",
            .offset_bytes = 0x04,},
        {
            .name = "optkeyr",
            .offset_bytes = 0x08,},
        {
            .name = "sr",
            .offset_bytes = 0x0C,},
        {
            .name = "cr",
            .offset_bytes = 0x10,},
        {
            .name = "optcr",
            .offset_bytes = 0x14,},
        {}, /**/
    }, /**/
};
#endif

#if 0
static void stm32f4_01_57_flash_create_objects(Object *obj, JSON_Value *family)
{
    //STM32FLASHState *state = STM32_FLASH_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family,
            "stm32f4_01_57:flash");

    peripheral_add_properties_and_children2(obj, info);
}
#endif

/* ------------------------------------------------------------------------- */

#if 0
static PeripheralInfo stm32f411xx_flash_info = {
    .desc = "Reset and clock control (RCC)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_ALL,

    .registers = (PeripheralRegisterInfo[] ) {
        {
            .desc = "Flash access control register (FLASH_ACR)",
            .name = "acr",
            .offset_bytes = 0x00,
            .reset_value = 0x00000030,
            .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "latency",
                    .first_bit = 0,
                    .width_bits = 4,},
                {
                    .name = "prften",
                    .desc = "Prefetch enable",
                    .first_bit = 8,},
                {
                    .name = "icen",
                    .desc = "Prefetch enable",
                    .first_bit = 9,},
                {
                    .name = "dcen",
                    .desc = "Data cache enable",
                    .first_bit = 10,},
                {
                    .name = "icrst",
                    .desc = "Instruction cache reset",
                    .first_bit = 11,
                    .rw_mode = REGISTER_RW_MODE_READ,},
                {
                    .name = "dcrst",
                    .desc = "Data cache reset",
                    .first_bit = 12,},
                {}, /**/
            }, /**/
        },
        /* Very schematic, functional read after write only. */
        {
            .name = "keyr",
            .offset_bytes = 0x04,},
        {
            .name = "optkeyr",
            .offset_bytes = 0x08,},
        {
            .name = "sr",
            .offset_bytes = 0x0C,},
        {
            .name = "cr",
            .offset_bytes = 0x10,},
        {
            .name = "optcr",
            .offset_bytes = 0x14,},
        {}, /**/
    }, /**/
};
#endif

#if 0
static void stm32f411_flash_create_objects(Object *obj, JSON_Value *family)
{
    //STM32FLASHState *state = STM32_FLASH_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family,
            "stm32f411:flash");

    peripheral_add_properties_and_children2(obj, info);
}
#endif

/* ------------------------------------------------------------------------- */

#if 0
static PeripheralInfo stm32f4_23_xxx_flash_info = {
    .desc = "Reset and clock control (RCC)",
    .default_access_flags = PERIPHERAL_REGISTER_32BITS_ALL,

    .registers = (PeripheralRegisterInfo[] ) {
        {
            .desc = "Flash access control register (FLASH_ACR)",
            .name = "acr",
            .offset_bytes = 0x00,
            .reset_value = 0x00000030,
            .bitfields = (RegisterBitfieldInfo[] ) {
                {
                    .name = "latency",
                    .first_bit = 0,
                    .width_bits = 4,},
                {
                    .name = "prften",
                    .desc = "Prefetch enable",
                    .first_bit = 8,},
                {
                    .name = "icen",
                    .desc = "Prefetch enable",
                    .first_bit = 9,},
                {
                    .name = "dcen",
                    .desc = "Data cache enable",
                    .first_bit = 10,},
                {
                    .name = "icrst",
                    .desc = "Instruction cache reset",
                    .first_bit = 11,
                    .rw_mode = REGISTER_RW_MODE_READ,},
                {
                    .name = "dcrst",
                    .desc = "Data cache reset",
                    .first_bit = 12,},
                {}, /**/
            }, /**/
        },
        /* Very schematic, functional read after write only. */
        {
            .name = "keyr",
            .offset_bytes = 0x04,},
        {
            .name = "optkeyr",
            .offset_bytes = 0x08,},
        {
            .name = "sr",
            .offset_bytes = 0x0C,},
        {
            .name = "cr",
            .offset_bytes = 0x10,},
        {
            .name = "optcr",
            .offset_bytes = 0x14,},
        {
            .name = "optcr1",
            .offset_bytes = 0x18,},

        {}, /**/
    }, /**/
};
#endif

#if 0
static void stm32f4_23_x_flash_create_objects(Object *obj, JSON_Value *family)
{
    //STM32FLASHState *state = STM32_FLASH_STATE(obj);

    JSON_Object *info = cm_json_parser_get_peripheral(family,
            "stm32f4_23_x:flash");

    peripheral_add_properties_and_children2(obj, info);
}
#endif

/* ------------------------------------------------------------------------- */

static void stm32_flash_instance_init_callback(Object *obj)
{
    qemu_log_function_name();
}

static void stm32_flash_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /*
     * Parent realize() is called after setting properties and creating
     * registers.
     */

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32FLASHState *state = STM32_FLASH_STATE(dev);
    /* First thing first: get capabilities from MCU, needed everywhere. */
    state->capabilities = mcu->capabilities;

    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    /* Must be defined before creating registers. */
    cm_object_property_set_int(obj, 4, "register-size-bytes");

    /* TODO: get it from MCU */
    cm_object_property_set_bool(obj, true, "is-little-endian");

    /*
     * Creating the memory region in the parent class will trigger
     * an assertion if zro address or size.
     */
    uint32_t size = 0;
    hwaddr addr = 0;

    switch (capabilities->family) {
    case STM32_FAMILY_F0:
    case STM32_FAMILY_F1:
        addr = 0x40022000;
        size = 0x400;
        break;

    case STM32_FAMILY_F4:
        addr = 0x40023C00;
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

        if (capabilities->f0.is_0x1) {
            stm32f0x1_flash_create_objects(obj, cm_state->svd_json, "FLASH");
#if 0
        } else if (capabilities->f0.is_51xx) {
            stm32f051_flash_create_objects(obj, mcu->family_json);
#endif
        }
        break;

    case STM32_FAMILY_F1:

        if (capabilities->f1.is_103xx) {
            stm32f103xx_flash_create_objects(obj, cm_state->svd_json, "FLASH");

            /* Auto bits. */
            cm_object_property_set_str(state->f1.fld.acr.prftbs, "PRFTBE",
                    "follows");
#if 0
        } else if (capabilities->f1.is_cl || capabilities->f1.is_hd
                || capabilities->f1.is_hdvl || capabilities->f1.is_ld
                || capabilities->f1.is_ldvl || capabilities->f1.is_md
                || capabilities->f1.is_mdvl) {
            stm32f1xx_flash_create_objects(obj, mcu->family_json);

            /* Auto bits. */
            cm_object_property_set_str(state->f1.acr.prftbs, "prftbe",
                    "follows");
        } else if (capabilities->f1.is_xd) {
            stm32f1xd_flash_create_objects(obj, mcu->family_json);

            /* Auto bits. */
            cm_object_property_set_str(state->f1.acr.prftbs, "prftbe",
                    "follows");
#endif
        }

        break;

    case STM32_FAMILY_F4:

        if (capabilities->f4.is_40x) {
            stm32f40x_flash_create_objects(obj, cm_state->svd_json, "FLASH");
#if 0
        } else if (capabilities->f4.is_01_57_xx) {
            stm32f4_01_57_flash_create_objects(obj, mcu->family_json);
        } else if (capabilities->f4.is11xx) {
            stm32f411_flash_create_objects(obj, mcu->family_json);
        } else if (capabilities->f4.is_23_xxx) {
            stm32f4_23_x_flash_create_objects(obj, mcu->family_json);
#endif
        }
        break;

    default:
        break;
    }

    /* Call parent realize(). */
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_FLASH)) {
        return;
    }
}

static void stm32_flash_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    /* Call parent reset(). */
    cm_device_parent_reset(dev, TYPE_STM32_FLASH);
}

static Property stm32_flash_properties[] = {
        DEFINE_PROP_NON_VOID_PTR("capabilities", STM32FLASHState,
                capabilities, const STM32Capabilities *),
    DEFINE_PROP_END_OF_LIST() };

static void stm32_flash_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    dc->reset = stm32_flash_reset_callback;
    dc->realize = stm32_flash_realize_callback;
    dc->props = stm32_flash_properties;
}

static const TypeInfo stm32_flash_type_info = {
    .name = TYPE_STM32_FLASH,
    .parent = TYPE_STM32_FLASH_PARENT,
    .instance_init = stm32_flash_instance_init_callback,
    .instance_size = sizeof(STM32FLASHState),
    .class_init = stm32_flash_class_init_callback,
    .class_size = sizeof(STM32FLASHClass) /**/
};

static void stm32_flash_register_types(void)
{
    type_register_static(&stm32_flash_type_info);

#if 0
    peripheral_serialize_info("f051-flash.json", "stm32f051:flash",
            &stm32f051xx_flash_info);
    peripheral_serialize_info("f1xx-flash.json", "stm32f1xx:flash",
            &stm32f1_flash_info);
    peripheral_serialize_info("f1xd-flash.json", "stm32f1xd:flash",
            &stm32f1xd_flash_info);

    peripheral_serialize_info("f4_01_57-flash.json", "stm32f4_01_57:flash",
            &stm32f4_01_57_xx_flash_info);
    peripheral_serialize_info("f4_23_x-flash.json", "stm32f4_23_x:flash",
            &stm32f4_23_xxx_flash_info);
    peripheral_serialize_info("f411-flash.json", "stm32f411:flash",
            &stm32f411xx_flash_info);
#endif
}

type_init(stm32_flash_register_types);

/* ------------------------------------------------------------------------- */
