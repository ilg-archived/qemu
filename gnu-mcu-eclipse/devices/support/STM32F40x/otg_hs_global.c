/*
 * STM32 - OTG_HS_GLOBAL (USB on the go high speed) emulation.
 *
 * Copyright (c) 2016 Liviu Ionescu.
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

#include <hw/cortexm/stm32/otg_hs_global.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f40x_otg_hs_global_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32OTG_HS_GLOBALState *state = STM32_OTG_HS_GLOBAL_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.otg_hs_gotgctl = cm_object_get_child_by_name(obj, "OTG_HS_GOTGCTL");
    state->u.f4.reg.otg_hs_gotgint = cm_object_get_child_by_name(obj, "OTG_HS_GOTGINT");
    state->u.f4.reg.otg_hs_gahbcfg = cm_object_get_child_by_name(obj, "OTG_HS_GAHBCFG");
    state->u.f4.reg.otg_hs_gusbcfg = cm_object_get_child_by_name(obj, "OTG_HS_GUSBCFG");
    state->u.f4.reg.otg_hs_grstctl = cm_object_get_child_by_name(obj, "OTG_HS_GRSTCTL");
    state->u.f4.reg.otg_hs_gintsts = cm_object_get_child_by_name(obj, "OTG_HS_GINTSTS");
    state->u.f4.reg.otg_hs_gintmsk = cm_object_get_child_by_name(obj, "OTG_HS_GINTMSK");
    state->u.f4.reg.otg_hs_grxstsr_host = cm_object_get_child_by_name(obj, "OTG_HS_GRXSTSR_Host");
    state->u.f4.reg.otg_hs_grxstsp_host = cm_object_get_child_by_name(obj, "OTG_HS_GRXSTSP_Host");
    state->u.f4.reg.otg_hs_grxfsiz = cm_object_get_child_by_name(obj, "OTG_HS_GRXFSIZ");
    state->u.f4.reg.otg_hs_gnptxfsiz_host = cm_object_get_child_by_name(obj, "OTG_HS_GNPTXFSIZ_Host");
    state->u.f4.reg.otg_hs_tx0fsiz_peripheral = cm_object_get_child_by_name(obj, "OTG_HS_TX0FSIZ_Peripheral");
    state->u.f4.reg.otg_hs_gnptxsts = cm_object_get_child_by_name(obj, "OTG_HS_GNPTXSTS");
    state->u.f4.reg.otg_hs_gccfg = cm_object_get_child_by_name(obj, "OTG_HS_GCCFG");
    state->u.f4.reg.otg_hs_cid = cm_object_get_child_by_name(obj, "OTG_HS_CID");
    state->u.f4.reg.otg_hs_hptxfsiz = cm_object_get_child_by_name(obj, "OTG_HS_HPTXFSIZ");
    state->u.f4.reg.otg_hs_dieptxf1 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPTXF1");
    state->u.f4.reg.otg_hs_dieptxf2 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPTXF2");
    state->u.f4.reg.otg_hs_dieptxf3 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPTXF3");
    state->u.f4.reg.otg_hs_dieptxf4 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPTXF4");
    state->u.f4.reg.otg_hs_dieptxf5 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPTXF5");
    state->u.f4.reg.otg_hs_dieptxf6 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPTXF6");
    state->u.f4.reg.otg_hs_dieptxf7 = cm_object_get_child_by_name(obj, "OTG_HS_DIEPTXF7");
    state->u.f4.reg.otg_hs_grxstsr_peripheral = cm_object_get_child_by_name(obj, "OTG_HS_GRXSTSR_Peripheral");
    state->u.f4.reg.otg_hs_grxstsp_peripheral = cm_object_get_child_by_name(obj, "OTG_HS_GRXSTSP_Peripheral");
    
    
    // OTG_HS_GOTGCTL bitfields.
    state->u.f4.fld.otg_hs_gotgctl.srqscs = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gotgctl, "SRQSCS"); 
    state->u.f4.fld.otg_hs_gotgctl.srq = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gotgctl, "SRQ"); 
    state->u.f4.fld.otg_hs_gotgctl.hngscs = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gotgctl, "HNGSCS"); 
    state->u.f4.fld.otg_hs_gotgctl.hnprq = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gotgctl, "HNPRQ"); 
    state->u.f4.fld.otg_hs_gotgctl.hshnpen = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gotgctl, "HSHNPEN"); 
    state->u.f4.fld.otg_hs_gotgctl.dhnpen = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gotgctl, "DHNPEN"); 
    state->u.f4.fld.otg_hs_gotgctl.cidsts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gotgctl, "CIDSTS"); 
    state->u.f4.fld.otg_hs_gotgctl.dbct = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gotgctl, "DBCT"); 
    state->u.f4.fld.otg_hs_gotgctl.asvld = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gotgctl, "ASVLD"); 
    state->u.f4.fld.otg_hs_gotgctl.bsvld = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gotgctl, "BSVLD");  
    
    // OTG_HS_GOTGINT bitfields.
    state->u.f4.fld.otg_hs_gotgint.sedet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gotgint, "SEDET"); 
    state->u.f4.fld.otg_hs_gotgint.srsschg = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gotgint, "SRSSCHG"); 
    state->u.f4.fld.otg_hs_gotgint.hnsschg = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gotgint, "HNSSCHG"); 
    state->u.f4.fld.otg_hs_gotgint.hngdet = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gotgint, "HNGDET"); 
    state->u.f4.fld.otg_hs_gotgint.adtochg = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gotgint, "ADTOCHG"); 
    state->u.f4.fld.otg_hs_gotgint.dbcdne = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gotgint, "DBCDNE");  
    
    // OTG_HS_GAHBCFG bitfields.
    state->u.f4.fld.otg_hs_gahbcfg.gint = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gahbcfg, "GINT"); 
    state->u.f4.fld.otg_hs_gahbcfg.hbstlen = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gahbcfg, "HBSTLEN"); 
    state->u.f4.fld.otg_hs_gahbcfg.dmaen = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gahbcfg, "DMAEN"); 
    state->u.f4.fld.otg_hs_gahbcfg.txfelvl = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gahbcfg, "TXFELVL"); 
    state->u.f4.fld.otg_hs_gahbcfg.ptxfelvl = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gahbcfg, "PTXFELVL");  
    
    // OTG_HS_GUSBCFG bitfields.
    state->u.f4.fld.otg_hs_gusbcfg.tocal = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gusbcfg, "TOCAL"); 
    state->u.f4.fld.otg_hs_gusbcfg.physel = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gusbcfg, "PHYSEL"); 
    state->u.f4.fld.otg_hs_gusbcfg.srpcap = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gusbcfg, "SRPCAP"); 
    state->u.f4.fld.otg_hs_gusbcfg.hnpcap = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gusbcfg, "HNPCAP"); 
    state->u.f4.fld.otg_hs_gusbcfg.trdt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gusbcfg, "TRDT"); 
    state->u.f4.fld.otg_hs_gusbcfg.phylpcs = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gusbcfg, "PHYLPCS"); 
    state->u.f4.fld.otg_hs_gusbcfg.ulpifsls = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gusbcfg, "ULPIFSLS"); 
    state->u.f4.fld.otg_hs_gusbcfg.ulpiar = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gusbcfg, "ULPIAR"); 
    state->u.f4.fld.otg_hs_gusbcfg.ulpicsm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gusbcfg, "ULPICSM"); 
    state->u.f4.fld.otg_hs_gusbcfg.ulpievbusd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gusbcfg, "ULPIEVBUSD"); 
    state->u.f4.fld.otg_hs_gusbcfg.ulpievbusi = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gusbcfg, "ULPIEVBUSI"); 
    state->u.f4.fld.otg_hs_gusbcfg.tsdps = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gusbcfg, "TSDPS"); 
    state->u.f4.fld.otg_hs_gusbcfg.pcci = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gusbcfg, "PCCI"); 
    state->u.f4.fld.otg_hs_gusbcfg.ptci = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gusbcfg, "PTCI"); 
    state->u.f4.fld.otg_hs_gusbcfg.ulpiipd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gusbcfg, "ULPIIPD"); 
    state->u.f4.fld.otg_hs_gusbcfg.fhmod = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gusbcfg, "FHMOD"); 
    state->u.f4.fld.otg_hs_gusbcfg.fdmod = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gusbcfg, "FDMOD"); 
    state->u.f4.fld.otg_hs_gusbcfg.ctxpkt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gusbcfg, "CTXPKT");  
    
    // OTG_HS_GRSTCTL bitfields.
    state->u.f4.fld.otg_hs_grstctl.csrst = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grstctl, "CSRST"); 
    state->u.f4.fld.otg_hs_grstctl.hsrst = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grstctl, "HSRST"); 
    state->u.f4.fld.otg_hs_grstctl.fcrst = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grstctl, "FCRST"); 
    state->u.f4.fld.otg_hs_grstctl.rxfflsh = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grstctl, "RXFFLSH"); 
    state->u.f4.fld.otg_hs_grstctl.txfflsh = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grstctl, "TXFFLSH"); 
    state->u.f4.fld.otg_hs_grstctl.txfnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grstctl, "TXFNUM"); 
    state->u.f4.fld.otg_hs_grstctl.dmareq = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grstctl, "DMAREQ"); 
    state->u.f4.fld.otg_hs_grstctl.ahbidl = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grstctl, "AHBIDL");  
    
    // OTG_HS_GINTSTS bitfields.
    state->u.f4.fld.otg_hs_gintsts.cmod = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "CMOD"); 
    state->u.f4.fld.otg_hs_gintsts.mmis = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "MMIS"); 
    state->u.f4.fld.otg_hs_gintsts.otgint = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "OTGINT"); 
    state->u.f4.fld.otg_hs_gintsts.sof = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "SOF"); 
    state->u.f4.fld.otg_hs_gintsts.rxflvl = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "RXFLVL"); 
    state->u.f4.fld.otg_hs_gintsts.nptxfe = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "NPTXFE"); 
    state->u.f4.fld.otg_hs_gintsts.ginakeff = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "GINAKEFF"); 
    state->u.f4.fld.otg_hs_gintsts.boutnakeff = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "BOUTNAKEFF"); 
    state->u.f4.fld.otg_hs_gintsts.esusp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "ESUSP"); 
    state->u.f4.fld.otg_hs_gintsts.usbsusp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "USBSUSP"); 
    state->u.f4.fld.otg_hs_gintsts.usbrst = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "USBRST"); 
    state->u.f4.fld.otg_hs_gintsts.enumdne = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "ENUMDNE"); 
    state->u.f4.fld.otg_hs_gintsts.isoodrp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "ISOODRP"); 
    state->u.f4.fld.otg_hs_gintsts.eopf = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "EOPF"); 
    state->u.f4.fld.otg_hs_gintsts.iepint = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "IEPINT"); 
    state->u.f4.fld.otg_hs_gintsts.oepint = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "OEPINT"); 
    state->u.f4.fld.otg_hs_gintsts.iisoixfr = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "IISOIXFR"); 
    state->u.f4.fld.otg_hs_gintsts.pxfr_incompisoout = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "PXFR_INCOMPISOOUT"); 
    state->u.f4.fld.otg_hs_gintsts.datafsusp = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "DATAFSUSP"); 
    state->u.f4.fld.otg_hs_gintsts.hprtint = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "HPRTINT"); 
    state->u.f4.fld.otg_hs_gintsts.hcint = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "HCINT"); 
    state->u.f4.fld.otg_hs_gintsts.ptxfe = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "PTXFE"); 
    state->u.f4.fld.otg_hs_gintsts.cidschg = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "CIDSCHG"); 
    state->u.f4.fld.otg_hs_gintsts.discint = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "DISCINT"); 
    state->u.f4.fld.otg_hs_gintsts.srqint = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "SRQINT"); 
    state->u.f4.fld.otg_hs_gintsts.wkuint = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintsts, "WKUINT");  
    
    // OTG_HS_GINTMSK bitfields.
    state->u.f4.fld.otg_hs_gintmsk.mmism = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "MMISM"); 
    state->u.f4.fld.otg_hs_gintmsk.otgint = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "OTGINT"); 
    state->u.f4.fld.otg_hs_gintmsk.sofm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "SOFM"); 
    state->u.f4.fld.otg_hs_gintmsk.rxflvlm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "RXFLVLM"); 
    state->u.f4.fld.otg_hs_gintmsk.nptxfem = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "NPTXFEM"); 
    state->u.f4.fld.otg_hs_gintmsk.ginakeffm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "GINAKEFFM"); 
    state->u.f4.fld.otg_hs_gintmsk.gonakeffm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "GONAKEFFM"); 
    state->u.f4.fld.otg_hs_gintmsk.esuspm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "ESUSPM"); 
    state->u.f4.fld.otg_hs_gintmsk.usbsuspm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "USBSUSPM"); 
    state->u.f4.fld.otg_hs_gintmsk.usbrst = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "USBRST"); 
    state->u.f4.fld.otg_hs_gintmsk.enumdnem = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "ENUMDNEM"); 
    state->u.f4.fld.otg_hs_gintmsk.isoodrpm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "ISOODRPM"); 
    state->u.f4.fld.otg_hs_gintmsk.eopfm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "EOPFM"); 
    state->u.f4.fld.otg_hs_gintmsk.epmism = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "EPMISM"); 
    state->u.f4.fld.otg_hs_gintmsk.iepint = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "IEPINT"); 
    state->u.f4.fld.otg_hs_gintmsk.oepint = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "OEPINT"); 
    state->u.f4.fld.otg_hs_gintmsk.iisoixfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "IISOIXFRM"); 
    state->u.f4.fld.otg_hs_gintmsk.pxfrm_iisooxfrm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "PXFRM_IISOOXFRM"); 
    state->u.f4.fld.otg_hs_gintmsk.fsuspm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "FSUSPM"); 
    state->u.f4.fld.otg_hs_gintmsk.prtim = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "PRTIM"); 
    state->u.f4.fld.otg_hs_gintmsk.hcim = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "HCIM"); 
    state->u.f4.fld.otg_hs_gintmsk.ptxfem = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "PTXFEM"); 
    state->u.f4.fld.otg_hs_gintmsk.cidschgm = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "CIDSCHGM"); 
    state->u.f4.fld.otg_hs_gintmsk.discint = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "DISCINT"); 
    state->u.f4.fld.otg_hs_gintmsk.srqim = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "SRQIM"); 
    state->u.f4.fld.otg_hs_gintmsk.wuim = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gintmsk, "WUIM");  
    
    // OTG_HS_GRXSTSR_Host bitfields.
    state->u.f4.fld.otg_hs_grxstsr_host.chnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxstsr_host, "CHNUM"); 
    state->u.f4.fld.otg_hs_grxstsr_host.bcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxstsr_host, "BCNT"); 
    state->u.f4.fld.otg_hs_grxstsr_host.dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxstsr_host, "DPID"); 
    state->u.f4.fld.otg_hs_grxstsr_host.pktsts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxstsr_host, "PKTSTS");  
    
    // OTG_HS_GRXSTSP_Host bitfields.
    state->u.f4.fld.otg_hs_grxstsp_host.chnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxstsp_host, "CHNUM"); 
    state->u.f4.fld.otg_hs_grxstsp_host.bcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxstsp_host, "BCNT"); 
    state->u.f4.fld.otg_hs_grxstsp_host.dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxstsp_host, "DPID"); 
    state->u.f4.fld.otg_hs_grxstsp_host.pktsts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxstsp_host, "PKTSTS");  
    
    // OTG_HS_GRXFSIZ bitfields.
    state->u.f4.fld.otg_hs_grxfsiz.rxfd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxfsiz, "RXFD");  
    
    // OTG_HS_GNPTXFSIZ_Host bitfields.
    state->u.f4.fld.otg_hs_gnptxfsiz_host.nptxfsa = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gnptxfsiz_host, "NPTXFSA"); 
    state->u.f4.fld.otg_hs_gnptxfsiz_host.nptxfd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gnptxfsiz_host, "NPTXFD");  
    
    // OTG_HS_TX0FSIZ_Peripheral bitfields.
    state->u.f4.fld.otg_hs_tx0fsiz_peripheral.tx0fsa = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_tx0fsiz_peripheral, "TX0FSA"); 
    state->u.f4.fld.otg_hs_tx0fsiz_peripheral.tx0fd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_tx0fsiz_peripheral, "TX0FD");  
    
    // OTG_HS_GNPTXSTS bitfields.
    state->u.f4.fld.otg_hs_gnptxsts.nptxfsav = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gnptxsts, "NPTXFSAV"); 
    state->u.f4.fld.otg_hs_gnptxsts.nptqxsav = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gnptxsts, "NPTQXSAV"); 
    state->u.f4.fld.otg_hs_gnptxsts.nptxqtop = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gnptxsts, "NPTXQTOP");  
    
    // OTG_HS_GCCFG bitfields.
    state->u.f4.fld.otg_hs_gccfg.pwrdwn = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gccfg, "PWRDWN"); 
    state->u.f4.fld.otg_hs_gccfg.i2cpaden = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gccfg, "I2CPADEN"); 
    state->u.f4.fld.otg_hs_gccfg.vbusasen = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gccfg, "VBUSASEN"); 
    state->u.f4.fld.otg_hs_gccfg.vbusbsen = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gccfg, "VBUSBSEN"); 
    state->u.f4.fld.otg_hs_gccfg.sofouten = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gccfg, "SOFOUTEN"); 
    state->u.f4.fld.otg_hs_gccfg.novbussens = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_gccfg, "NOVBUSSENS");  
    
    // OTG_HS_CID bitfields.
    state->u.f4.fld.otg_hs_cid.product_id = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_cid, "PRODUCT_ID");  
    
    // OTG_HS_HPTXFSIZ bitfields.
    state->u.f4.fld.otg_hs_hptxfsiz.ptxsa = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hptxfsiz, "PTXSA"); 
    state->u.f4.fld.otg_hs_hptxfsiz.ptxfd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_hptxfsiz, "PTXFD");  
    
    // OTG_HS_DIEPTXF1 bitfields.
    state->u.f4.fld.otg_hs_dieptxf1.ineptxsa = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptxf1, "INEPTXSA"); 
    state->u.f4.fld.otg_hs_dieptxf1.ineptxfd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptxf1, "INEPTXFD");  
    
    // OTG_HS_DIEPTXF2 bitfields.
    state->u.f4.fld.otg_hs_dieptxf2.ineptxsa = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptxf2, "INEPTXSA"); 
    state->u.f4.fld.otg_hs_dieptxf2.ineptxfd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptxf2, "INEPTXFD");  
    
    // OTG_HS_DIEPTXF3 bitfields.
    state->u.f4.fld.otg_hs_dieptxf3.ineptxsa = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptxf3, "INEPTXSA"); 
    state->u.f4.fld.otg_hs_dieptxf3.ineptxfd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptxf3, "INEPTXFD");  
    
    // OTG_HS_DIEPTXF4 bitfields.
    state->u.f4.fld.otg_hs_dieptxf4.ineptxsa = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptxf4, "INEPTXSA"); 
    state->u.f4.fld.otg_hs_dieptxf4.ineptxfd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptxf4, "INEPTXFD");  
    
    // OTG_HS_DIEPTXF5 bitfields.
    state->u.f4.fld.otg_hs_dieptxf5.ineptxsa = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptxf5, "INEPTXSA"); 
    state->u.f4.fld.otg_hs_dieptxf5.ineptxfd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptxf5, "INEPTXFD");  
    
    // OTG_HS_DIEPTXF6 bitfields.
    state->u.f4.fld.otg_hs_dieptxf6.ineptxsa = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptxf6, "INEPTXSA"); 
    state->u.f4.fld.otg_hs_dieptxf6.ineptxfd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptxf6, "INEPTXFD");  
    
    // OTG_HS_DIEPTXF7 bitfields.
    state->u.f4.fld.otg_hs_dieptxf7.ineptxsa = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptxf7, "INEPTXSA"); 
    state->u.f4.fld.otg_hs_dieptxf7.ineptxfd = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_dieptxf7, "INEPTXFD");  
    
    // OTG_HS_GRXSTSR_Peripheral bitfields.
    state->u.f4.fld.otg_hs_grxstsr_peripheral.epnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxstsr_peripheral, "EPNUM"); 
    state->u.f4.fld.otg_hs_grxstsr_peripheral.bcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxstsr_peripheral, "BCNT"); 
    state->u.f4.fld.otg_hs_grxstsr_peripheral.dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxstsr_peripheral, "DPID"); 
    state->u.f4.fld.otg_hs_grxstsr_peripheral.pktsts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxstsr_peripheral, "PKTSTS"); 
    state->u.f4.fld.otg_hs_grxstsr_peripheral.frmnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxstsr_peripheral, "FRMNUM");  
    
    // OTG_HS_GRXSTSP_Peripheral bitfields.
    state->u.f4.fld.otg_hs_grxstsp_peripheral.epnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxstsp_peripheral, "EPNUM"); 
    state->u.f4.fld.otg_hs_grxstsp_peripheral.bcnt = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxstsp_peripheral, "BCNT"); 
    state->u.f4.fld.otg_hs_grxstsp_peripheral.dpid = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxstsp_peripheral, "DPID"); 
    state->u.f4.fld.otg_hs_grxstsp_peripheral.pktsts = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxstsp_peripheral, "PKTSTS"); 
    state->u.f4.fld.otg_hs_grxstsp_peripheral.frmnum = cm_object_get_child_by_name(state->u.f4.reg.otg_hs_grxstsp_peripheral, "FRMNUM");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_otg_hs_global_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32OTG_HS_GLOBALState *state = STM32_OTG_HS_GLOBAL_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_otg_hs_global_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32OTG_HS_GLOBALState *state = STM32_OTG_HS_GLOBAL_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_otg_hs_global_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32OTG_HS_GLOBALState *state = STM32_OTG_HS_GLOBAL_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_otg_hs_global_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32OTG_HS_GLOBALState *state = STM32_OTG_HS_GLOBAL_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_otg_hs_global_is_enabled(Object *obj)
{
    STM32OTG_HS_GLOBALState *state = STM32_OTG_HS_GLOBAL_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_otg_hs_global_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32OTG_HS_GLOBALState *state = STM32_OTG_HS_GLOBAL_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_otg_hs_global_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_OTG_HS_GLOBAL)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32OTG_HS_GLOBALState *state = STM32_OTG_HS_GLOBAL_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "OTG_HS_GLOBAL";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_40x ) {

            stm32f40x_otg_hs_global_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_otg_hs_global_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_otg_hs_global_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_otg_hs_global_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_otg_hs_global_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/OTG_HS_GLOBALEN");


        } else {
            assert(false);
        }

        break;

    default:
        assert(false);
        break;
    }

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = OBJECT(cm_device_by_name(enabling_bit_name));

    peripheral_prepare_registers(obj);
}

static void stm32_otg_hs_global_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_OTG_HS_GLOBAL);
}

static void stm32_otg_hs_global_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_otg_hs_global_reset_callback;
    dc->realize = stm32_otg_hs_global_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_otg_hs_global_is_enabled;
}

static const TypeInfo stm32_otg_hs_global_type_info = {
    .name = TYPE_STM32_OTG_HS_GLOBAL,
    .parent = TYPE_STM32_OTG_HS_GLOBAL_PARENT,
    .instance_init = stm32_otg_hs_global_instance_init_callback,
    .instance_size = sizeof(STM32OTG_HS_GLOBALState),
    .class_init = stm32_otg_hs_global_class_init_callback,
    .class_size = sizeof(STM32OTG_HS_GLOBALClass) };

static void stm32_otg_hs_global_register_types(void)
{
    type_register_static(&stm32_otg_hs_global_type_info);
}

type_init(stm32_otg_hs_global_register_types);

// ----------------------------------------------------------------------------
