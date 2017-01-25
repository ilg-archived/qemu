/*
 * STM32 - OTG_FS_GLOBAL (USB on the go full speed) emulation.
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

#include <hw/cortexm/stm32/otg_fs_global.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>

// ----- Generated code -------------------------------------------------------
//
// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// DO NOT EDIT! Automatically generated!
static void stm32f429x_otg_fs_global_create_objects(Object *obj, JSON_Object *svd, const char *name)
{
    STM32OTG_FS_GLOBALState *state = STM32_OTG_FS_GLOBAL_STATE(obj);

    JSON_Object *periph = svd_get_peripheral_by_name(svd, name);
    svd_add_peripheral_properties_and_children(obj, periph, svd);

    // Registers. 
    state->u.f4.reg.fs_gotgctl = cm_object_get_child_by_name(obj, "FS_GOTGCTL");
    state->u.f4.reg.fs_gotgint = cm_object_get_child_by_name(obj, "FS_GOTGINT");
    state->u.f4.reg.fs_gahbcfg = cm_object_get_child_by_name(obj, "FS_GAHBCFG");
    state->u.f4.reg.fs_gusbcfg = cm_object_get_child_by_name(obj, "FS_GUSBCFG");
    state->u.f4.reg.fs_grstctl = cm_object_get_child_by_name(obj, "FS_GRSTCTL");
    state->u.f4.reg.fs_gintsts = cm_object_get_child_by_name(obj, "FS_GINTSTS");
    state->u.f4.reg.fs_gintmsk = cm_object_get_child_by_name(obj, "FS_GINTMSK");
    state->u.f4.reg.fs_grxstsr_device = cm_object_get_child_by_name(obj, "FS_GRXSTSR_Device");
    state->u.f4.reg.fs_grxstsr_host = cm_object_get_child_by_name(obj, "FS_GRXSTSR_Host");
    state->u.f4.reg.fs_grxfsiz = cm_object_get_child_by_name(obj, "FS_GRXFSIZ");
    state->u.f4.reg.fs_gnptxfsiz_device = cm_object_get_child_by_name(obj, "FS_GNPTXFSIZ_Device");
    state->u.f4.reg.fs_gnptxfsiz_host = cm_object_get_child_by_name(obj, "FS_GNPTXFSIZ_Host");
    state->u.f4.reg.fs_gnptxsts = cm_object_get_child_by_name(obj, "FS_GNPTXSTS");
    state->u.f4.reg.fs_gccfg = cm_object_get_child_by_name(obj, "FS_GCCFG");
    state->u.f4.reg.fs_cid = cm_object_get_child_by_name(obj, "FS_CID");
    state->u.f4.reg.fs_hptxfsiz = cm_object_get_child_by_name(obj, "FS_HPTXFSIZ");
    state->u.f4.reg.fs_dieptxf1 = cm_object_get_child_by_name(obj, "FS_DIEPTXF1");
    state->u.f4.reg.fs_dieptxf2 = cm_object_get_child_by_name(obj, "FS_DIEPTXF2");
    state->u.f4.reg.fs_dieptxf3 = cm_object_get_child_by_name(obj, "FS_DIEPTXF3");
    
    
    // FS_GOTGCTL bitfields.
    state->u.f4.fld.fs_gotgctl.srqscs = cm_object_get_child_by_name(state->u.f4.reg.fs_gotgctl, "SRQSCS"); 
    state->u.f4.fld.fs_gotgctl.srq = cm_object_get_child_by_name(state->u.f4.reg.fs_gotgctl, "SRQ"); 
    state->u.f4.fld.fs_gotgctl.hngscs = cm_object_get_child_by_name(state->u.f4.reg.fs_gotgctl, "HNGSCS"); 
    state->u.f4.fld.fs_gotgctl.hnprq = cm_object_get_child_by_name(state->u.f4.reg.fs_gotgctl, "HNPRQ"); 
    state->u.f4.fld.fs_gotgctl.hshnpen = cm_object_get_child_by_name(state->u.f4.reg.fs_gotgctl, "HSHNPEN"); 
    state->u.f4.fld.fs_gotgctl.dhnpen = cm_object_get_child_by_name(state->u.f4.reg.fs_gotgctl, "DHNPEN"); 
    state->u.f4.fld.fs_gotgctl.cidsts = cm_object_get_child_by_name(state->u.f4.reg.fs_gotgctl, "CIDSTS"); 
    state->u.f4.fld.fs_gotgctl.dbct = cm_object_get_child_by_name(state->u.f4.reg.fs_gotgctl, "DBCT"); 
    state->u.f4.fld.fs_gotgctl.asvld = cm_object_get_child_by_name(state->u.f4.reg.fs_gotgctl, "ASVLD"); 
    state->u.f4.fld.fs_gotgctl.bsvld = cm_object_get_child_by_name(state->u.f4.reg.fs_gotgctl, "BSVLD");  
    
    // FS_GOTGINT bitfields.
    state->u.f4.fld.fs_gotgint.sedet = cm_object_get_child_by_name(state->u.f4.reg.fs_gotgint, "SEDET"); 
    state->u.f4.fld.fs_gotgint.srsschg = cm_object_get_child_by_name(state->u.f4.reg.fs_gotgint, "SRSSCHG"); 
    state->u.f4.fld.fs_gotgint.hnsschg = cm_object_get_child_by_name(state->u.f4.reg.fs_gotgint, "HNSSCHG"); 
    state->u.f4.fld.fs_gotgint.hngdet = cm_object_get_child_by_name(state->u.f4.reg.fs_gotgint, "HNGDET"); 
    state->u.f4.fld.fs_gotgint.adtochg = cm_object_get_child_by_name(state->u.f4.reg.fs_gotgint, "ADTOCHG"); 
    state->u.f4.fld.fs_gotgint.dbcdne = cm_object_get_child_by_name(state->u.f4.reg.fs_gotgint, "DBCDNE");  
    
    // FS_GAHBCFG bitfields.
    state->u.f4.fld.fs_gahbcfg.gint = cm_object_get_child_by_name(state->u.f4.reg.fs_gahbcfg, "GINT"); 
    state->u.f4.fld.fs_gahbcfg.txfelvl = cm_object_get_child_by_name(state->u.f4.reg.fs_gahbcfg, "TXFELVL"); 
    state->u.f4.fld.fs_gahbcfg.ptxfelvl = cm_object_get_child_by_name(state->u.f4.reg.fs_gahbcfg, "PTXFELVL");  
    
    // FS_GUSBCFG bitfields.
    state->u.f4.fld.fs_gusbcfg.tocal = cm_object_get_child_by_name(state->u.f4.reg.fs_gusbcfg, "TOCAL"); 
    state->u.f4.fld.fs_gusbcfg.physel = cm_object_get_child_by_name(state->u.f4.reg.fs_gusbcfg, "PHYSEL"); 
    state->u.f4.fld.fs_gusbcfg.srpcap = cm_object_get_child_by_name(state->u.f4.reg.fs_gusbcfg, "SRPCAP"); 
    state->u.f4.fld.fs_gusbcfg.hnpcap = cm_object_get_child_by_name(state->u.f4.reg.fs_gusbcfg, "HNPCAP"); 
    state->u.f4.fld.fs_gusbcfg.trdt = cm_object_get_child_by_name(state->u.f4.reg.fs_gusbcfg, "TRDT"); 
    state->u.f4.fld.fs_gusbcfg.fhmod = cm_object_get_child_by_name(state->u.f4.reg.fs_gusbcfg, "FHMOD"); 
    state->u.f4.fld.fs_gusbcfg.fdmod = cm_object_get_child_by_name(state->u.f4.reg.fs_gusbcfg, "FDMOD"); 
    state->u.f4.fld.fs_gusbcfg.ctxpkt = cm_object_get_child_by_name(state->u.f4.reg.fs_gusbcfg, "CTXPKT");  
    
    // FS_GRSTCTL bitfields.
    state->u.f4.fld.fs_grstctl.csrst = cm_object_get_child_by_name(state->u.f4.reg.fs_grstctl, "CSRST"); 
    state->u.f4.fld.fs_grstctl.hsrst = cm_object_get_child_by_name(state->u.f4.reg.fs_grstctl, "HSRST"); 
    state->u.f4.fld.fs_grstctl.fcrst = cm_object_get_child_by_name(state->u.f4.reg.fs_grstctl, "FCRST"); 
    state->u.f4.fld.fs_grstctl.rxfflsh = cm_object_get_child_by_name(state->u.f4.reg.fs_grstctl, "RXFFLSH"); 
    state->u.f4.fld.fs_grstctl.txfflsh = cm_object_get_child_by_name(state->u.f4.reg.fs_grstctl, "TXFFLSH"); 
    state->u.f4.fld.fs_grstctl.txfnum = cm_object_get_child_by_name(state->u.f4.reg.fs_grstctl, "TXFNUM"); 
    state->u.f4.fld.fs_grstctl.ahbidl = cm_object_get_child_by_name(state->u.f4.reg.fs_grstctl, "AHBIDL");  
    
    // FS_GINTSTS bitfields.
    state->u.f4.fld.fs_gintsts.cmod = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "CMOD"); 
    state->u.f4.fld.fs_gintsts.mmis = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "MMIS"); 
    state->u.f4.fld.fs_gintsts.otgint = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "OTGINT"); 
    state->u.f4.fld.fs_gintsts.sof = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "SOF"); 
    state->u.f4.fld.fs_gintsts.rxflvl = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "RXFLVL"); 
    state->u.f4.fld.fs_gintsts.nptxfe = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "NPTXFE"); 
    state->u.f4.fld.fs_gintsts.ginakeff = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "GINAKEFF"); 
    state->u.f4.fld.fs_gintsts.goutnakeff = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "GOUTNAKEFF"); 
    state->u.f4.fld.fs_gintsts.esusp = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "ESUSP"); 
    state->u.f4.fld.fs_gintsts.usbsusp = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "USBSUSP"); 
    state->u.f4.fld.fs_gintsts.usbrst = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "USBRST"); 
    state->u.f4.fld.fs_gintsts.enumdne = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "ENUMDNE"); 
    state->u.f4.fld.fs_gintsts.isoodrp = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "ISOODRP"); 
    state->u.f4.fld.fs_gintsts.eopf = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "EOPF"); 
    state->u.f4.fld.fs_gintsts.iepint = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "IEPINT"); 
    state->u.f4.fld.fs_gintsts.oepint = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "OEPINT"); 
    state->u.f4.fld.fs_gintsts.iisoixfr = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "IISOIXFR"); 
    state->u.f4.fld.fs_gintsts.ipxfr_incompisoout = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "IPXFR_INCOMPISOOUT"); 
    state->u.f4.fld.fs_gintsts.hprtint = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "HPRTINT"); 
    state->u.f4.fld.fs_gintsts.hcint = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "HCINT"); 
    state->u.f4.fld.fs_gintsts.ptxfe = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "PTXFE"); 
    state->u.f4.fld.fs_gintsts.cidschg = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "CIDSCHG"); 
    state->u.f4.fld.fs_gintsts.discint = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "DISCINT"); 
    state->u.f4.fld.fs_gintsts.srqint = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "SRQINT"); 
    state->u.f4.fld.fs_gintsts.wkupint = cm_object_get_child_by_name(state->u.f4.reg.fs_gintsts, "WKUPINT");  
    
    // FS_GINTMSK bitfields.
    state->u.f4.fld.fs_gintmsk.mmism = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "MMISM"); 
    state->u.f4.fld.fs_gintmsk.otgint = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "OTGINT"); 
    state->u.f4.fld.fs_gintmsk.sofm = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "SOFM"); 
    state->u.f4.fld.fs_gintmsk.rxflvlm = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "RXFLVLM"); 
    state->u.f4.fld.fs_gintmsk.nptxfem = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "NPTXFEM"); 
    state->u.f4.fld.fs_gintmsk.ginakeffm = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "GINAKEFFM"); 
    state->u.f4.fld.fs_gintmsk.gonakeffm = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "GONAKEFFM"); 
    state->u.f4.fld.fs_gintmsk.esuspm = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "ESUSPM"); 
    state->u.f4.fld.fs_gintmsk.usbsuspm = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "USBSUSPM"); 
    state->u.f4.fld.fs_gintmsk.usbrst = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "USBRST"); 
    state->u.f4.fld.fs_gintmsk.enumdnem = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "ENUMDNEM"); 
    state->u.f4.fld.fs_gintmsk.isoodrpm = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "ISOODRPM"); 
    state->u.f4.fld.fs_gintmsk.eopfm = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "EOPFM"); 
    state->u.f4.fld.fs_gintmsk.epmism = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "EPMISM"); 
    state->u.f4.fld.fs_gintmsk.iepint = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "IEPINT"); 
    state->u.f4.fld.fs_gintmsk.oepint = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "OEPINT"); 
    state->u.f4.fld.fs_gintmsk.iisoixfrm = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "IISOIXFRM"); 
    state->u.f4.fld.fs_gintmsk.ipxfrm_iisooxfrm = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "IPXFRM_IISOOXFRM"); 
    state->u.f4.fld.fs_gintmsk.prtim = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "PRTIM"); 
    state->u.f4.fld.fs_gintmsk.hcim = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "HCIM"); 
    state->u.f4.fld.fs_gintmsk.ptxfem = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "PTXFEM"); 
    state->u.f4.fld.fs_gintmsk.cidschgm = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "CIDSCHGM"); 
    state->u.f4.fld.fs_gintmsk.discint = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "DISCINT"); 
    state->u.f4.fld.fs_gintmsk.srqim = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "SRQIM"); 
    state->u.f4.fld.fs_gintmsk.wuim = cm_object_get_child_by_name(state->u.f4.reg.fs_gintmsk, "WUIM");  
    
    // FS_GRXSTSR_Device bitfields.
    state->u.f4.fld.fs_grxstsr_device.epnum = cm_object_get_child_by_name(state->u.f4.reg.fs_grxstsr_device, "EPNUM"); 
    state->u.f4.fld.fs_grxstsr_device.bcnt = cm_object_get_child_by_name(state->u.f4.reg.fs_grxstsr_device, "BCNT"); 
    state->u.f4.fld.fs_grxstsr_device.dpid = cm_object_get_child_by_name(state->u.f4.reg.fs_grxstsr_device, "DPID"); 
    state->u.f4.fld.fs_grxstsr_device.pktsts = cm_object_get_child_by_name(state->u.f4.reg.fs_grxstsr_device, "PKTSTS"); 
    state->u.f4.fld.fs_grxstsr_device.frmnum = cm_object_get_child_by_name(state->u.f4.reg.fs_grxstsr_device, "FRMNUM");  
    
    // FS_GRXSTSR_Host bitfields.
    state->u.f4.fld.fs_grxstsr_host.epnum = cm_object_get_child_by_name(state->u.f4.reg.fs_grxstsr_host, "EPNUM"); 
    state->u.f4.fld.fs_grxstsr_host.bcnt = cm_object_get_child_by_name(state->u.f4.reg.fs_grxstsr_host, "BCNT"); 
    state->u.f4.fld.fs_grxstsr_host.dpid = cm_object_get_child_by_name(state->u.f4.reg.fs_grxstsr_host, "DPID"); 
    state->u.f4.fld.fs_grxstsr_host.pktsts = cm_object_get_child_by_name(state->u.f4.reg.fs_grxstsr_host, "PKTSTS"); 
    state->u.f4.fld.fs_grxstsr_host.frmnum = cm_object_get_child_by_name(state->u.f4.reg.fs_grxstsr_host, "FRMNUM");  
    
    // FS_GRXFSIZ bitfields.
    state->u.f4.fld.fs_grxfsiz.rxfd = cm_object_get_child_by_name(state->u.f4.reg.fs_grxfsiz, "RXFD");  
    
    // FS_GNPTXFSIZ_Device bitfields.
    state->u.f4.fld.fs_gnptxfsiz_device.tx0fsa = cm_object_get_child_by_name(state->u.f4.reg.fs_gnptxfsiz_device, "TX0FSA"); 
    state->u.f4.fld.fs_gnptxfsiz_device.tx0fd = cm_object_get_child_by_name(state->u.f4.reg.fs_gnptxfsiz_device, "TX0FD");  
    
    // FS_GNPTXFSIZ_Host bitfields.
    state->u.f4.fld.fs_gnptxfsiz_host.nptxfsa = cm_object_get_child_by_name(state->u.f4.reg.fs_gnptxfsiz_host, "NPTXFSA"); 
    state->u.f4.fld.fs_gnptxfsiz_host.nptxfd = cm_object_get_child_by_name(state->u.f4.reg.fs_gnptxfsiz_host, "NPTXFD");  
    
    // FS_GNPTXSTS bitfields.
    state->u.f4.fld.fs_gnptxsts.nptxfsav = cm_object_get_child_by_name(state->u.f4.reg.fs_gnptxsts, "NPTXFSAV"); 
    state->u.f4.fld.fs_gnptxsts.nptqxsav = cm_object_get_child_by_name(state->u.f4.reg.fs_gnptxsts, "NPTQXSAV"); 
    state->u.f4.fld.fs_gnptxsts.nptxqtop = cm_object_get_child_by_name(state->u.f4.reg.fs_gnptxsts, "NPTXQTOP");  
    
    // FS_GCCFG bitfields.
    state->u.f4.fld.fs_gccfg.pwrdwn = cm_object_get_child_by_name(state->u.f4.reg.fs_gccfg, "PWRDWN"); 
    state->u.f4.fld.fs_gccfg.vbusasen = cm_object_get_child_by_name(state->u.f4.reg.fs_gccfg, "VBUSASEN"); 
    state->u.f4.fld.fs_gccfg.vbusbsen = cm_object_get_child_by_name(state->u.f4.reg.fs_gccfg, "VBUSBSEN"); 
    state->u.f4.fld.fs_gccfg.sofouten = cm_object_get_child_by_name(state->u.f4.reg.fs_gccfg, "SOFOUTEN");  
    
    // FS_CID bitfields.
    state->u.f4.fld.fs_cid.product_id = cm_object_get_child_by_name(state->u.f4.reg.fs_cid, "PRODUCT_ID");  
    
    // FS_HPTXFSIZ bitfields.
    state->u.f4.fld.fs_hptxfsiz.ptxsa = cm_object_get_child_by_name(state->u.f4.reg.fs_hptxfsiz, "PTXSA"); 
    state->u.f4.fld.fs_hptxfsiz.ptxfsiz = cm_object_get_child_by_name(state->u.f4.reg.fs_hptxfsiz, "PTXFSIZ");  
    
    // FS_DIEPTXF1 bitfields.
    state->u.f4.fld.fs_dieptxf1.ineptxsa = cm_object_get_child_by_name(state->u.f4.reg.fs_dieptxf1, "INEPTXSA"); 
    state->u.f4.fld.fs_dieptxf1.ineptxfd = cm_object_get_child_by_name(state->u.f4.reg.fs_dieptxf1, "INEPTXFD");  
    
    // FS_DIEPTXF2 bitfields.
    state->u.f4.fld.fs_dieptxf2.ineptxsa = cm_object_get_child_by_name(state->u.f4.reg.fs_dieptxf2, "INEPTXSA"); 
    state->u.f4.fld.fs_dieptxf2.ineptxfd = cm_object_get_child_by_name(state->u.f4.reg.fs_dieptxf2, "INEPTXFD");  
    
    // FS_DIEPTXF3 bitfields.
    state->u.f4.fld.fs_dieptxf3.ineptxsa = cm_object_get_child_by_name(state->u.f4.reg.fs_dieptxf3, "INEPTXSA"); 
    state->u.f4.fld.fs_dieptxf3.ineptxfd = cm_object_get_child_by_name(state->u.f4.reg.fs_dieptxf3, "INEPTXFD");  
}

// ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

// ----- Private --------------------------------------------------------------

#if 0
static peripheral_register_t stm32_otg_fs_global_xxx_pre_write_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32OTG_FS_GLOBALState *state = STM32_OTG_FS_GLOBAL_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);

    // TODO: Add code to adjust the value (like applying some masks,
    // for example prevent setting interrupts not enabled).
    // Also process cleared/set by write 1/0 bits.
    // The returned value will be stored in the register value.

    return full_value;
}

static void stm32_otg_fs_global_xxx_post_write_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size,
        peripheral_register_t value, peripheral_register_t full_value)
{
    STM32OTG_FS_GLOBALState *state = STM32_OTG_FS_GLOBAL_STATE(periph);

    peripheral_register_t prev_value = peripheral_register_get_raw_prev_value(reg);
    // The new register value is full_value, the old one is prev_value.

    // TODO: Add code to send the value to the consumer.
}

static peripheral_register_t stm32_otg_fs_global_xxx_pre_read_callback(Object *reg,
        Object *periph, uint32_t addr, uint32_t offset, unsigned size)
{
    STM32OTG_FS_GLOBALState *state = STM32_OTG_FS_GLOBAL_STATE(periph);

    peripheral_register_t value = 0;

    // Add code to get the value from the producer, and return it.

    // This value, possibly masked, will be stored in the register
    // and returned when the register is read.
    return value;
}

static void stm32_otg_fs_global_xxx_post_read_callback(Object *reg, Object *periph,
        uint32_t addr, uint32_t offset, unsigned size)
{
    STM32OTG_FS_GLOBALState *state = STM32_OTG_FS_GLOBAL_STATE(periph);

    peripheral_register_t value = peripheral_register_get_raw_value(reg);

    // TODO: add code to perform the post read actions, like clearing some bits.
}
#endif

// ----------------------------------------------------------------------------

// TODO: remove this if the peripheral is always enabled.
static bool stm32_otg_fs_global_is_enabled(Object *obj)
{
    STM32OTG_FS_GLOBALState *state = STM32_OTG_FS_GLOBAL_STATE(obj);

    if (register_bitfield_is_non_zero(state->enabling_bit)) {
        return true; // Positive logic, bit == 1 means enabled.
    }

    // Not enabled
    return false;
}

static void stm32_otg_fs_global_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32OTG_FS_GLOBALState *state = STM32_OTG_FS_GLOBAL_STATE(obj);

    // Capabilities are not yet available.

    // TODO: remove this if the peripheral is always enabled.
    state->enabling_bit = NULL;
    
    // TODO: Add code to initialise all members.
}

static void stm32_otg_fs_global_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_OTG_FS_GLOBAL)) {
        return;
    }

    STM32MCUState *mcu = stm32_mcu_get();
    CortexMState *cm_state = CORTEXM_MCU_STATE(mcu);

    STM32OTG_FS_GLOBALState *state = STM32_OTG_FS_GLOBAL_STATE(dev);
    // First thing first: get capabilities from MCU, needed everywhere.
    state->capabilities = mcu->capabilities;

    // Also keep a local pointer, to access them easier.
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    const char *periph_name = "OTG_FS_GLOBAL";

    svd_set_peripheral_address_block(cm_state->svd_json, periph_name, obj);
    peripheral_create_memory_region(obj);

    // TODO: remove this if the peripheral is always enabled.
    char enabling_bit_name[STM32_RCC_SIZEOF_ENABLING_BITFIELD];

    switch (capabilities->family) {
    case STM32_FAMILY_F4:

        if (capabilities->f4.is_429x ) {

            stm32f429x_otg_fs_global_create_objects(obj, cm_state->svd_json, periph_name);

            // TODO: add actions.
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "follows");
            // cm_object_property_set_str(state->u.f4.fld.xxx.fff, "GGG", "cleared-by");

            // TODO: add callbacks.
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_otg_fs_global_xxx_pre_read_callback);
            // peripheral_register_set_post_read(state->f4.reg.xxx, &stm32_otg_fs_global_xxx_post_read_callback);
            // peripheral_register_set_pre_read(state->f4.reg.xxx, &stm32_otg_fs_global_xxx_pret_read_callback);
            // peripheral_register_set_post_write(state->f4.reg.xxx, &stm32_otg_fs_global_xxx_post_write_callback);

            // TODO: add interrupts.

            // TODO: remove this if the peripheral is always enabled.
            snprintf(enabling_bit_name, sizeof(enabling_bit_name) - 1,
                DEVICE_PATH_STM32_RCC "/AHB1ENR/OTG_FS_GLOBALEN");


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

static void stm32_otg_fs_global_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset(); this will reset all children registers.
    cm_device_parent_reset(dev, TYPE_STM32_OTG_FS_GLOBAL);
}

static void stm32_otg_fs_global_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_otg_fs_global_reset_callback;
    dc->realize = stm32_otg_fs_global_realize_callback;

    // TODO: remove this if the peripheral is always enabled.
    PeripheralClass *per_class = PERIPHERAL_CLASS(klass);
    per_class->is_enabled = stm32_otg_fs_global_is_enabled;
}

static const TypeInfo stm32_otg_fs_global_type_info = {
    .name = TYPE_STM32_OTG_FS_GLOBAL,
    .parent = TYPE_STM32_OTG_FS_GLOBAL_PARENT,
    .instance_init = stm32_otg_fs_global_instance_init_callback,
    .instance_size = sizeof(STM32OTG_FS_GLOBALState),
    .class_init = stm32_otg_fs_global_class_init_callback,
    .class_size = sizeof(STM32OTG_FS_GLOBALClass) };

static void stm32_otg_fs_global_register_types(void)
{
    type_register_static(&stm32_otg_fs_global_type_info);
}

type_init(stm32_otg_fs_global_register_types);

// ----------------------------------------------------------------------------
