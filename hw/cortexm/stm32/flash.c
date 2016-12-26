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

// ----- Generated code -------------------------------------------------------
//
// STM32F051R8
// DO NOT EDIT! Automatically generated!
static void stm32f0x1_flash_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32FLASHState *state = STM32_FLASH_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f0.reg.acr = cm_object_get_child_by_name(obj, "ACR");
    state->u.f0.reg.keyr = cm_object_get_child_by_name(obj, "KEYR");
    state->u.f0.reg.optkeyr = cm_object_get_child_by_name(obj, "OPTKEYR");
    state->u.f0.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->u.f0.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->u.f0.reg.ar = cm_object_get_child_by_name(obj, "AR");
    state->u.f0.reg.obr = cm_object_get_child_by_name(obj, "OBR");
    state->u.f0.reg.wrpr = cm_object_get_child_by_name(obj, "WRPR");

    // ACR bitfields.
    state->u.f0.fld.acr.latency = cm_object_get_child_by_name(
            state->u.f0.reg.acr, "LATENCY");
    state->u.f0.fld.acr.prftbe = cm_object_get_child_by_name(
            state->u.f0.reg.acr, "PRFTBE");
    state->u.f0.fld.acr.prftbs = cm_object_get_child_by_name(
            state->u.f0.reg.acr, "PRFTBS");

    // KEYR bitfields.
    state->u.f0.fld.keyr.fkeyr = cm_object_get_child_by_name(
            state->u.f0.reg.keyr, "FKEYR");

    // OPTKEYR bitfields.
    state->u.f0.fld.optkeyr.optkeyr = cm_object_get_child_by_name(
            state->u.f0.reg.optkeyr, "OPTKEYR");

    // SR bitfields.
    state->u.f0.fld.sr.bsy = cm_object_get_child_by_name(state->u.f0.reg.sr,
            "BSY");
    state->u.f0.fld.sr.pgerr = cm_object_get_child_by_name(state->u.f0.reg.sr,
            "PGERR");
    state->u.f0.fld.sr.wrprt = cm_object_get_child_by_name(state->u.f0.reg.sr,
            "WRPRT");
    state->u.f0.fld.sr.eop = cm_object_get_child_by_name(state->u.f0.reg.sr,
            "EOP");

    // CR bitfields.
    state->u.f0.fld.cr.pg = cm_object_get_child_by_name(state->u.f0.reg.cr,
            "PG");
    state->u.f0.fld.cr.per = cm_object_get_child_by_name(state->u.f0.reg.cr,
            "PER");
    state->u.f0.fld.cr.mer = cm_object_get_child_by_name(state->u.f0.reg.cr,
            "MER");
    state->u.f0.fld.cr.optpg = cm_object_get_child_by_name(state->u.f0.reg.cr,
            "OPTPG");
    state->u.f0.fld.cr.opter = cm_object_get_child_by_name(state->u.f0.reg.cr,
            "OPTER");
    state->u.f0.fld.cr.strt = cm_object_get_child_by_name(state->u.f0.reg.cr,
            "STRT");
    state->u.f0.fld.cr.lock = cm_object_get_child_by_name(state->u.f0.reg.cr,
            "LOCK");
    state->u.f0.fld.cr.optwre = cm_object_get_child_by_name(state->u.f0.reg.cr,
            "OPTWRE");
    state->u.f0.fld.cr.errie = cm_object_get_child_by_name(state->u.f0.reg.cr,
            "ERRIE");
    state->u.f0.fld.cr.eopie = cm_object_get_child_by_name(state->u.f0.reg.cr,
            "EOPIE");
    state->u.f0.fld.cr.force_optload = cm_object_get_child_by_name(
            state->u.f0.reg.cr, "FORCE_OPTLOAD");

    // AR bitfields.
    state->u.f0.fld.ar.far_ = cm_object_get_child_by_name(state->u.f0.reg.ar,
            "FAR");

    // OBR bitfields.
    state->u.f0.fld.obr.opterr = cm_object_get_child_by_name(
            state->u.f0.reg.obr, "OPTERR");
    state->u.f0.fld.obr.level1_prot = cm_object_get_child_by_name(
            state->u.f0.reg.obr, "LEVEL1_PROT");
    state->u.f0.fld.obr.level2_prot = cm_object_get_child_by_name(
            state->u.f0.reg.obr, "LEVEL2_PROT");
    state->u.f0.fld.obr.wdg_sw = cm_object_get_child_by_name(
            state->u.f0.reg.obr, "WDG_SW");
    state->u.f0.fld.obr.nrst_stop = cm_object_get_child_by_name(
            state->u.f0.reg.obr, "nRST_STOP");
    state->u.f0.fld.obr.nrst_stdby = cm_object_get_child_by_name(
            state->u.f0.reg.obr, "nRST_STDBY");
    state->u.f0.fld.obr.boot1 = cm_object_get_child_by_name(state->u.f0.reg.obr,
            "BOOT1");
    state->u.f0.fld.obr.vdda_monitor = cm_object_get_child_by_name(
            state->u.f0.reg.obr, "VDDA_MONITOR");
    state->u.f0.fld.obr.data0 = cm_object_get_child_by_name(state->u.f0.reg.obr,
            "Data0");
    state->u.f0.fld.obr.data1 = cm_object_get_child_by_name(state->u.f0.reg.obr,
            "Data1");

    // WRPR bitfields.
    state->u.f0.fld.wrpr.wrp = cm_object_get_child_by_name(state->u.f0.reg.wrpr,
            "WRP");
}

// ----------------------------------------------------------------------------

// STM32F103RB
// DO NOT EDIT! Automatically generated!
static void stm32f103xx_flash_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32FLASHState *state = STM32_FLASH_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f1.reg.acr = cm_object_get_child_by_name(obj, "ACR");
    state->u.f1.reg.keyr = cm_object_get_child_by_name(obj, "KEYR");
    state->u.f1.reg.optkeyr = cm_object_get_child_by_name(obj, "OPTKEYR");
    state->u.f1.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->u.f1.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->u.f1.reg.ar = cm_object_get_child_by_name(obj, "AR");
    state->u.f1.reg.obr = cm_object_get_child_by_name(obj, "OBR");
    state->u.f1.reg.wrpr = cm_object_get_child_by_name(obj, "WRPR");

    // ACR bitfields.
    state->u.f1.fld.acr.latency = cm_object_get_child_by_name(
            state->u.f1.reg.acr, "LATENCY");
    state->u.f1.fld.acr.hlfcya = cm_object_get_child_by_name(
            state->u.f1.reg.acr, "HLFCYA");
    state->u.f1.fld.acr.prftbe = cm_object_get_child_by_name(
            state->u.f1.reg.acr, "PRFTBE");
    state->u.f1.fld.acr.prftbs = cm_object_get_child_by_name(
            state->u.f1.reg.acr, "PRFTBS");

    // KEYR bitfields.
    state->u.f1.fld.keyr.key = cm_object_get_child_by_name(state->u.f1.reg.keyr,
            "KEY");

    // OPTKEYR bitfields.
    state->u.f1.fld.optkeyr.optkey = cm_object_get_child_by_name(
            state->u.f1.reg.optkeyr, "OPTKEY");

    // SR bitfields.
    state->u.f1.fld.sr.bsy = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "BSY");
    state->u.f1.fld.sr.pgerr = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "PGERR");
    state->u.f1.fld.sr.wrprterr = cm_object_get_child_by_name(
            state->u.f1.reg.sr, "WRPRTERR");
    state->u.f1.fld.sr.eop = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "EOP");

    // CR bitfields.
    state->u.f1.fld.cr.pg = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "PG");
    state->u.f1.fld.cr.per = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "PER");
    state->u.f1.fld.cr.mer = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "MER");
    state->u.f1.fld.cr.optpg = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "OPTPG");
    state->u.f1.fld.cr.opter = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "OPTER");
    state->u.f1.fld.cr.strt = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "STRT");
    state->u.f1.fld.cr.lock = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "LOCK");
    state->u.f1.fld.cr.optwre = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "OPTWRE");
    state->u.f1.fld.cr.errie = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "ERRIE");
    state->u.f1.fld.cr.eopie = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "EOPIE");

    // AR bitfields.
    state->u.f1.fld.ar.far_ = cm_object_get_child_by_name(state->u.f1.reg.ar,
            "FAR");

    // OBR bitfields.
    state->u.f1.fld.obr.opterr = cm_object_get_child_by_name(
            state->u.f1.reg.obr, "OPTERR");
    state->u.f1.fld.obr.rdprt = cm_object_get_child_by_name(state->u.f1.reg.obr,
            "RDPRT");
    state->u.f1.fld.obr.wdg_sw = cm_object_get_child_by_name(
            state->u.f1.reg.obr, "WDG_SW");
    state->u.f1.fld.obr.nrst_stop = cm_object_get_child_by_name(
            state->u.f1.reg.obr, "nRST_STOP");
    state->u.f1.fld.obr.nrst_stdby = cm_object_get_child_by_name(
            state->u.f1.reg.obr, "nRST_STDBY");
    state->u.f1.fld.obr.data0 = cm_object_get_child_by_name(state->u.f1.reg.obr,
            "Data0");
    state->u.f1.fld.obr.data1 = cm_object_get_child_by_name(state->u.f1.reg.obr,
            "Data1");

    // WRPR bitfields.
    state->u.f1.fld.wrpr.wrp = cm_object_get_child_by_name(state->u.f1.reg.wrpr,
            "WRP");
}

// ----------------------------------------------------------------------------

// STM32F107VC
// DO NOT EDIT! Automatically generated!
static void stm32f107xx_flash_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32FLASHState *state = STM32_FLASH_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f1.reg.acr = cm_object_get_child_by_name(obj, "ACR");
    state->u.f1.reg.keyr = cm_object_get_child_by_name(obj, "KEYR");
    state->u.f1.reg.optkeyr = cm_object_get_child_by_name(obj, "OPTKEYR");
    state->u.f1.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->u.f1.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->u.f1.reg.ar = cm_object_get_child_by_name(obj, "AR");
    state->u.f1.reg.obr = cm_object_get_child_by_name(obj, "OBR");
    state->u.f1.reg.wrpr = cm_object_get_child_by_name(obj, "WRPR");

    // ACR bitfields.
    state->u.f1.fld.acr.latency = cm_object_get_child_by_name(
            state->u.f1.reg.acr, "LATENCY");
    state->u.f1.fld.acr.hlfcya = cm_object_get_child_by_name(
            state->u.f1.reg.acr, "HLFCYA");
    state->u.f1.fld.acr.prftbe = cm_object_get_child_by_name(
            state->u.f1.reg.acr, "PRFTBE");
    state->u.f1.fld.acr.prftbs = cm_object_get_child_by_name(
            state->u.f1.reg.acr, "PRFTBS");

    // KEYR bitfields.
    state->u.f1.fld.keyr.key = cm_object_get_child_by_name(state->u.f1.reg.keyr,
            "KEY");

    // OPTKEYR bitfields.
    state->u.f1.fld.optkeyr.optkey = cm_object_get_child_by_name(
            state->u.f1.reg.optkeyr, "OPTKEY");

    // SR bitfields.
    state->u.f1.fld.sr.bsy = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "BSY");
    state->u.f1.fld.sr.pgerr = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "PGERR");
    state->u.f1.fld.sr.wrprterr = cm_object_get_child_by_name(
            state->u.f1.reg.sr, "WRPRTERR");
    state->u.f1.fld.sr.eop = cm_object_get_child_by_name(state->u.f1.reg.sr,
            "EOP");

    // CR bitfields.
    state->u.f1.fld.cr.pg = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "PG");
    state->u.f1.fld.cr.per = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "PER");
    state->u.f1.fld.cr.mer = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "MER");
    state->u.f1.fld.cr.optpg = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "OPTPG");
    state->u.f1.fld.cr.opter = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "OPTER");
    state->u.f1.fld.cr.strt = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "STRT");
    state->u.f1.fld.cr.lock = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "LOCK");
    state->u.f1.fld.cr.optwre = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "OPTWRE");
    state->u.f1.fld.cr.errie = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "ERRIE");
    state->u.f1.fld.cr.eopie = cm_object_get_child_by_name(state->u.f1.reg.cr,
            "EOPIE");

    // AR bitfields.
    state->u.f1.fld.ar.far_ = cm_object_get_child_by_name(state->u.f1.reg.ar,
            "FAR");

    // OBR bitfields.
    state->u.f1.fld.obr.opterr = cm_object_get_child_by_name(
            state->u.f1.reg.obr, "OPTERR");
    state->u.f1.fld.obr.rdprt = cm_object_get_child_by_name(state->u.f1.reg.obr,
            "RDPRT");
    state->u.f1.fld.obr.wdg_sw = cm_object_get_child_by_name(
            state->u.f1.reg.obr, "WDG_SW");
    state->u.f1.fld.obr.nrst_stop = cm_object_get_child_by_name(
            state->u.f1.reg.obr, "nRST_STOP");
    state->u.f1.fld.obr.nrst_stdby = cm_object_get_child_by_name(
            state->u.f1.reg.obr, "nRST_STDBY");
    state->u.f1.fld.obr.data0 = cm_object_get_child_by_name(state->u.f1.reg.obr,
            "Data0");
    state->u.f1.fld.obr.data1 = cm_object_get_child_by_name(state->u.f1.reg.obr,
            "Data1");

    // WRPR bitfields.
    state->u.f1.fld.wrpr.wrp = cm_object_get_child_by_name(state->u.f1.reg.wrpr,
            "WRP");
}

// ----------------------------------------------------------------------------

// STM32F407VG, STM32F407ZG, STM32F405RG
// DO NOT EDIT! Automatically generated!
static void stm32f40x_flash_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32FLASHState *state = STM32_FLASH_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f4.reg.acr = cm_object_get_child_by_name(obj, "ACR");
    state->u.f4.reg.keyr = cm_object_get_child_by_name(obj, "KEYR");
    state->u.f4.reg.optkeyr = cm_object_get_child_by_name(obj, "OPTKEYR");
    state->u.f4.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->u.f4.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->u.f4.reg.optcr = cm_object_get_child_by_name(obj, "OPTCR");

    // ACR bitfields.
    state->u.f4.fld.acr.latency = cm_object_get_child_by_name(
            state->u.f4.reg.acr, "LATENCY");
    state->u.f4.fld.acr.prften = cm_object_get_child_by_name(
            state->u.f4.reg.acr, "PRFTEN");
    state->u.f4.fld.acr.icen = cm_object_get_child_by_name(state->u.f4.reg.acr,
            "ICEN");
    state->u.f4.fld.acr.dcen = cm_object_get_child_by_name(state->u.f4.reg.acr,
            "DCEN");
    state->u.f4.fld.acr.icrst = cm_object_get_child_by_name(state->u.f4.reg.acr,
            "ICRST");
    state->u.f4.fld.acr.dcrst = cm_object_get_child_by_name(state->u.f4.reg.acr,
            "DCRST");

    // KEYR bitfields.
    state->u.f4.fld.keyr.key = cm_object_get_child_by_name(state->u.f4.reg.keyr,
            "KEY");

    // OPTKEYR bitfields.
    state->u.f4.fld.optkeyr.optkey = cm_object_get_child_by_name(
            state->u.f4.reg.optkeyr, "OPTKEY");

    // SR bitfields.
    state->u.f4.fld.sr.eop = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "EOP");
    state->u.f4.fld.sr.operr = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "OPERR");
    state->u.f4.fld.sr.wrperr = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "WRPERR");
    state->u.f4.fld.sr.pgaerr = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "PGAERR");
    state->u.f4.fld.sr.pgperr = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "PGPERR");
    state->u.f4.fld.sr.pgserr = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "PGSERR");
    state->u.f4.fld.sr.bsy = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "BSY");

    // CR bitfields.
    state->u.f4.fld.cr.pg = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "PG");
    state->u.f4.fld.cr.ser = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "SER");
    state->u.f4.fld.cr.mer = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "MER");
    state->u.f4.fld.cr.snb = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "SNB");
    state->u.f4.fld.cr.psize = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "PSIZE");
    state->u.f4.fld.cr.strt = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "STRT");
    state->u.f4.fld.cr.eopie = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "EOPIE");
    state->u.f4.fld.cr.errie = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "ERRIE");
    state->u.f4.fld.cr.lock = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "LOCK");

    // OPTCR bitfields.
    state->u.f4.fld.optcr.optlock = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "OPTLOCK");
    state->u.f4.fld.optcr.optstrt = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "OPTSTRT");
    state->u.f4.fld.optcr.bor_lev = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "BOR_LEV");
    state->u.f4.fld.optcr.wdg_sw = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "WDG_SW");
    state->u.f4.fld.optcr.nrst_stop = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "nRST_STOP");
    state->u.f4.fld.optcr.nrst_stdby = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "nRST_STDBY");
    state->u.f4.fld.optcr.rdp = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "RDP");
    state->u.f4.fld.optcr.nwrp = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "nWRP");
}

// ----------------------------------------------------------------------------

// STM32F411RE
// DO NOT EDIT! Automatically generated!
static void stm32f411xx_flash_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32FLASHState *state = STM32_FLASH_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f4.reg.acr = cm_object_get_child_by_name(obj, "ACR");
    state->u.f4.reg.keyr = cm_object_get_child_by_name(obj, "KEYR");
    state->u.f4.reg.optkeyr = cm_object_get_child_by_name(obj, "OPTKEYR");
    state->u.f4.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->u.f4.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->u.f4.reg.optcr = cm_object_get_child_by_name(obj, "OPTCR");

    // ACR bitfields.
    state->u.f4.fld.acr.latency = cm_object_get_child_by_name(
            state->u.f4.reg.acr, "LATENCY");
    state->u.f4.fld.acr.prften = cm_object_get_child_by_name(
            state->u.f4.reg.acr, "PRFTEN");
    state->u.f4.fld.acr.icen = cm_object_get_child_by_name(state->u.f4.reg.acr,
            "ICEN");
    state->u.f4.fld.acr.dcen = cm_object_get_child_by_name(state->u.f4.reg.acr,
            "DCEN");
    state->u.f4.fld.acr.icrst = cm_object_get_child_by_name(state->u.f4.reg.acr,
            "ICRST");
    state->u.f4.fld.acr.dcrst = cm_object_get_child_by_name(state->u.f4.reg.acr,
            "DCRST");

    // KEYR bitfields.
    state->u.f4.fld.keyr.key = cm_object_get_child_by_name(state->u.f4.reg.keyr,
            "KEY");

    // OPTKEYR bitfields.
    state->u.f4.fld.optkeyr.optkey = cm_object_get_child_by_name(
            state->u.f4.reg.optkeyr, "OPTKEY");

    // SR bitfields.
    state->u.f4.fld.sr.eop = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "EOP");
    state->u.f4.fld.sr.operr = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "OPERR");
    state->u.f4.fld.sr.wrperr = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "WRPERR");
    state->u.f4.fld.sr.pgaerr = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "PGAERR");
    state->u.f4.fld.sr.pgperr = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "PGPERR");
    state->u.f4.fld.sr.pgserr = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "PGSERR");
    state->u.f4.fld.sr.bsy = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "BSY");

    // CR bitfields.
    state->u.f4.fld.cr.pg = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "PG");
    state->u.f4.fld.cr.ser = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "SER");
    state->u.f4.fld.cr.mer = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "MER");
    state->u.f4.fld.cr.snb = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "SNB");
    state->u.f4.fld.cr.psize = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "PSIZE");
    state->u.f4.fld.cr.strt = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "STRT");
    state->u.f4.fld.cr.eopie = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "EOPIE");
    state->u.f4.fld.cr.errie = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "ERRIE");
    state->u.f4.fld.cr.lock = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "LOCK");

    // OPTCR bitfields.
    state->u.f4.fld.optcr.optlock = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "OPTLOCK");
    state->u.f4.fld.optcr.optstrt = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "OPTSTRT");
    state->u.f4.fld.optcr.bor_lev = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "BOR_LEV");
    state->u.f4.fld.optcr.wdg_sw = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "WDG_SW");
    state->u.f4.fld.optcr.nrst_stop = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "nRST_STOP");
    state->u.f4.fld.optcr.nrst_stdby = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "nRST_STDBY");
    state->u.f4.fld.optcr.rdp = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "RDP");
    state->u.f4.fld.optcr.nwrp = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "nWRP");
}

// ----------------------------------------------------------------------------

// STM32F429ZI
// DO NOT EDIT! Automatically generated!
static void stm32f429x_flash_create_objects(Object *obj, JSON_Object *svd,
        const char *name)
{
    STM32FLASHState *state = STM32_FLASH_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers.
    state->u.f4.reg.acr = cm_object_get_child_by_name(obj, "ACR");
    state->u.f4.reg.keyr = cm_object_get_child_by_name(obj, "KEYR");
    state->u.f4.reg.optkeyr = cm_object_get_child_by_name(obj, "OPTKEYR");
    state->u.f4.reg.sr = cm_object_get_child_by_name(obj, "SR");
    state->u.f4.reg.cr = cm_object_get_child_by_name(obj, "CR");
    state->u.f4.reg.optcr = cm_object_get_child_by_name(obj, "OPTCR");
    state->u.f4.reg.optcr1 = cm_object_get_child_by_name(obj, "OPTCR1");

    // ACR bitfields.
    state->u.f4.fld.acr.latency = cm_object_get_child_by_name(
            state->u.f4.reg.acr, "LATENCY");
    state->u.f4.fld.acr.prften = cm_object_get_child_by_name(
            state->u.f4.reg.acr, "PRFTEN");
    state->u.f4.fld.acr.icen = cm_object_get_child_by_name(state->u.f4.reg.acr,
            "ICEN");
    state->u.f4.fld.acr.dcen = cm_object_get_child_by_name(state->u.f4.reg.acr,
            "DCEN");
    state->u.f4.fld.acr.icrst = cm_object_get_child_by_name(state->u.f4.reg.acr,
            "ICRST");
    state->u.f4.fld.acr.dcrst = cm_object_get_child_by_name(state->u.f4.reg.acr,
            "DCRST");

    // KEYR bitfields.
    state->u.f4.fld.keyr.key = cm_object_get_child_by_name(state->u.f4.reg.keyr,
            "KEY");

    // OPTKEYR bitfields.
    state->u.f4.fld.optkeyr.optkey = cm_object_get_child_by_name(
            state->u.f4.reg.optkeyr, "OPTKEY");

    // SR bitfields.
    state->u.f4.fld.sr.eop = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "EOP");
    state->u.f4.fld.sr.operr = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "OPERR");
    state->u.f4.fld.sr.wrperr = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "WRPERR");
    state->u.f4.fld.sr.pgaerr = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "PGAERR");
    state->u.f4.fld.sr.pgperr = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "PGPERR");
    state->u.f4.fld.sr.pgserr = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "PGSERR");
    state->u.f4.fld.sr.bsy = cm_object_get_child_by_name(state->u.f4.reg.sr,
            "BSY");

    // CR bitfields.
    state->u.f4.fld.cr.pg = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "PG");
    state->u.f4.fld.cr.ser = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "SER");
    state->u.f4.fld.cr.mer = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "MER");
    state->u.f4.fld.cr.snb = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "SNB");
    state->u.f4.fld.cr.psize = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "PSIZE");
    state->u.f4.fld.cr.mer1 = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "MER1");
    state->u.f4.fld.cr.strt = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "STRT");
    state->u.f4.fld.cr.eopie = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "EOPIE");
    state->u.f4.fld.cr.errie = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "ERRIE");
    state->u.f4.fld.cr.lock = cm_object_get_child_by_name(state->u.f4.reg.cr,
            "LOCK");

    // OPTCR bitfields.
    state->u.f4.fld.optcr.optlock = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "OPTLOCK");
    state->u.f4.fld.optcr.optstrt = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "OPTSTRT");
    state->u.f4.fld.optcr.bor_lev = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "BOR_LEV");
    state->u.f4.fld.optcr.wdg_sw = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "WDG_SW");
    state->u.f4.fld.optcr.nrst_stop = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "nRST_STOP");
    state->u.f4.fld.optcr.nrst_stdby = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "nRST_STDBY");
    state->u.f4.fld.optcr.rdp = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "RDP");
    state->u.f4.fld.optcr.nwrp = cm_object_get_child_by_name(
            state->u.f4.reg.optcr, "nWRP");

    // OPTCR1 bitfields.
    state->u.f4.fld.optcr1.nwrp = cm_object_get_child_by_name(
            state->u.f4.reg.optcr1, "nWRP");
}

// ----- Private --------------------------------------------------------------

static void stm32_flash_instance_init_callback(Object *obj)
{
    qemu_log_function_name();
}

static void stm32_flash_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_FLASH)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32FLASHState *state = STM32_FLASH_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "FLASH";
    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // Must be defined before creating registers.
    cm_object_property_set_int(obj, 4, "register-size-bytes");

    // TODO: get it from MCU
    cm_object_property_set_bool(obj, true, "is-little-endian");

    switch (capabilities->family) {
    case STM32_FAMILY_F0:

        if (capabilities->f0.is_0x1) {
            stm32f0x1_flash_create_objects(obj, cm_state->svd_json,
                    periph_name);
        } else {
            assert(false);
        }
        break;

    case STM32_FAMILY_F1:

        if (capabilities->f1.is_103xx) {

            stm32f103xx_flash_create_objects(obj, cm_state->svd_json,
                    periph_name);

        } else if (capabilities->f1.is_107xx) {

            stm32f107xx_flash_create_objects(obj, cm_state->svd_json,
                    periph_name);

        } else {
            assert(false);
        }

        // Auto bits.
        cm_object_property_set_str(state->u.f1.fld.acr.prftbs, "PRFTBE",
                "follows");

        break;

    case STM32_FAMILY_F4:

        if (capabilities->f4.is_40x) {

            stm32f40x_flash_create_objects(obj, cm_state->svd_json,
                    periph_name);

        } else if (capabilities->f4.is_411xx) {

            stm32f411xx_flash_create_objects(obj, cm_state->svd_json,
                    periph_name);

        } else if (capabilities->f4.is_429x) {

            stm32f429x_flash_create_objects(obj, cm_state->svd_json,
                    periph_name);

        } else {
            assert(false);
        }
        break;

    default:
        break;
    }

    peripheral_prepare_registers(obj);
}

static void stm32_flash_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset().
    cm_device_parent_reset(dev, TYPE_STM32_FLASH);
}

static void stm32_flash_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    dc->reset = stm32_flash_reset_callback;
    dc->realize = stm32_flash_realize_callback;
}

static const TypeInfo stm32_flash_type_info = {
    .name = TYPE_STM32_FLASH,
    .parent = TYPE_STM32_FLASH_PARENT,
    .instance_init = stm32_flash_instance_init_callback,
    .instance_size = sizeof(STM32FLASHState),
    .class_init = stm32_flash_class_init_callback,
    .class_size = sizeof(STM32FLASHClass)
/**/
};

static void stm32_flash_register_types(void)
{
    type_register_static(&stm32_flash_type_info);
}

type_init(stm32_flash_register_types);

/* ------------------------------------------------------------------------- */
