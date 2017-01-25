/*
 * STM32- SDIO(Secure digital input/output interface) emulation.
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

#ifndef STM32_SDIO_H_
#define STM32_SDIO_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_SDIODEVICE_PATH_STM32"SDIO"

// ----------------------------------------------------------------------------

#define TYPE_STM32_SDIOTYPE_STM32_PREFIX "sdio" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_SDIO_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32SDIOParentClass;
typedef PeripheralState STM32SDIOParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_SDIO_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32SDIOClass, (obj), TYPE_STM32_SDIO)
#define STM32_SDIO_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32SDIOClass, (klass), TYPE_STM32_SDIO)

typedef struct {
    // private: 
    STM32SDIOParentClass parent_class;
    // public: 

    // None, so far.
} STM32SDIOClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_SDIO_STATE(obj) \
    OBJECT_CHECK(STM32SDIOState, (obj), TYPE_STM32_SDIO)

typedef struct {
    // private:
    STM32SDIOParentState parent_obj;
    // public:

    const STM32Capabilities *capabilities;

    // TODO: remove this if the peripheral is always enabled.
    // Points to the bitfield that enables the peripheral.
    Object *enabling_bit;

union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // F1SDIO(Secure digital input/output interface) registers.
        struct { 
Object *power; // 0x0(Bits 1:0 = PWRCTRL: Power supply control bits) 
Object *clkcr; // 0x4(SDI clock control register (SDIO_CLKCR)) 
Object *arg; // 0x8(Bits 31:0 = : Command argument) 
Object *cmd; // 0xC(SDIO command register (SDIO_CMD)) 
Object *respcmd; // 0x10(SDIO command register) 
Object *respi1; // 0x14(Bits 31:0 = CARDSTATUS1) 
Object *resp2; // 0x18(Bits 31:0 = CARDSTATUS2) 
Object *resp3; // 0x1C(Bits 31:0 = CARDSTATUS3) 
Object *resp4; // 0x20(Bits 31:0 = CARDSTATUS4) 
Object *dtimer; // 0x24(Bits 31:0 = DATATIME: Data timeout period) 
Object *dlen; // 0x28(Bits 24:0 = DATALENGTH: Data length value) 
Object *dctrl; // 0x2C(SDIO data control register (SDIO_DCTRL)) 
Object *dcount; // 0x30(Bits 24:0 = DATACOUNT: Data count value) 
Object *sta; // 0x34(SDIO status register (SDIO_STA)) 
Object *icr; // 0x38(SDIO interrupt clear register (SDIO_ICR)) 
Object *mask; // 0x3C(SDIO mask register (SDIO_MASK)) 
Object *fifocnt; // 0x48(Bits 23:0 = FIFOCOUNT: Remaining number of words to be written to or read from the FIFO) 
Object *fifo; // 0x80(Bits 31:0 = FIFOData: Receive and transmit FIFO data) 
} reg;

        struct { 
// POWER(Bits 1:0 = PWRCTRL: Power supply control bits) bitfields.
          struct { 
Object *pwrctrl; // [0:1] PWRCTRL} power; 
// CLKCR(SDI clock control register (SDIO_CLKCR)) bitfields.
          struct { 
Object *clkdiv; // [0:7] Clock divide factorObject *clken; // [8:8] Clock enable bitObject *pwrsav; // [9:9] Power saving configuration bitObject *bypass; // [10:10] Clock divider bypass enable bitObject *widbus; // [11:12] Wide bus mode enable bitObject *negedge; // [13:13] SDIO_CK dephasing selection bitObject *hwfc_en; // [14:14] HW Flow Control enable} clkcr; 
// ARG(Bits 31:0 = : Command argument) bitfields.
          struct { 
Object *cmdarg; // [0:31] Command argument} arg; 
// CMD(SDIO command register (SDIO_CMD)) bitfields.
          struct { 
Object *cmdindex; // [0:5] CMDINDEXObject *waitresp; // [6:7] WAITRESPObject *waitint; // [8:8] WAITINTObject *waitpend; // [9:9] WAITPENDObject *cpsmen; // [10:10] CPSMENObject *sdiosuspend; // [11:11] SDIOSuspendObject *encmdcompl; // [12:12] ENCMDcomplObject *nien; // [13:13] NIENObject *ce_atacmd; // [14:14] CE_ATACMD} cmd; 
// RESPCMD(SDIO command register) bitfields.
          struct { 
Object *respcmd; // [0:5] RESPCMD} respcmd; 
// RESPI1(Bits 31:0 = CARDSTATUS1) bitfields.
          struct { 
Object *cardstatus1; // [0:31] CARDSTATUS1} respi1; 
// RESP2(Bits 31:0 = CARDSTATUS2) bitfields.
          struct { 
Object *cardstatus2; // [0:31] CARDSTATUS2} resp2; 
// RESP3(Bits 31:0 = CARDSTATUS3) bitfields.
          struct { 
Object *cardstatus3; // [0:31] CARDSTATUS3} resp3; 
// RESP4(Bits 31:0 = CARDSTATUS4) bitfields.
          struct { 
Object *cardstatus4; // [0:31] CARDSTATUS4} resp4; 
// DTIMER(Bits 31:0 = DATATIME: Data timeout period) bitfields.
          struct { 
Object *datatime; // [0:31] Data timeout period} dtimer; 
// DLEN(Bits 24:0 = DATALENGTH: Data length value) bitfields.
          struct { 
Object *datalength; // [0:24] Data length value} dlen; 
// DCTRL(SDIO data control register (SDIO_DCTRL)) bitfields.
          struct { 
Object *dten; // [0:0] DTENObject *dtdir; // [1:1] DTDIRObject *dtmode; // [2:2] DTMODEObject *dmaen; // [3:3] DMAENObject *dblocksize; // [4:7] DBLOCKSIZEObject *pwstart; // [8:8] PWSTARTObject *pwstop; // [9:9] PWSTOPObject *rwmod; // [10:10] RWMODObject *sdioen; // [11:11] SDIOEN} dctrl; 
// DCOUNT(Bits 24:0 = DATACOUNT: Data count value) bitfields.
          struct { 
Object *datacount; // [0:24] Data count value} dcount; 
// STA(SDIO status register (SDIO_STA)) bitfields.
          struct { 
Object *ccrcfail; // [0:0] CCRCFAILObject *dcrcfail; // [1:1] DCRCFAILObject *ctimeout; // [2:2] CTIMEOUTObject *dtimeout; // [3:3] DTIMEOUTObject *txunderr; // [4:4] TXUNDERRObject *rxoverr; // [5:5] RXOVERRObject *cmdrend; // [6:6] CMDRENDObject *cmdsent; // [7:7] CMDSENTObject *dataend; // [8:8] DATAENDObject *stbiterr; // [9:9] STBITERRObject *dbckend; // [10:10] DBCKENDObject *cmdact; // [11:11] CMDACTObject *txact; // [12:12] TXACTObject *rxact; // [13:13] RXACTObject *txfifohe; // [14:14] TXFIFOHEObject *rxfifohf; // [15:15] RXFIFOHFObject *txfifof; // [16:16] TXFIFOFObject *rxfifof; // [17:17] RXFIFOFObject *txfifoe; // [18:18] TXFIFOEObject *rxfifoe; // [19:19] RXFIFOEObject *txdavl; // [20:20] TXDAVLObject *rxdavl; // [21:21] RXDAVLObject *sdioit; // [22:22] SDIOITObject *ceataend; // [23:23] CEATAEND} sta; 
// ICR(SDIO interrupt clear register (SDIO_ICR)) bitfields.
          struct { 
Object *ccrcfailc; // [0:0] CCRCFAILCObject *dcrcfailc; // [1:1] DCRCFAILCObject *ctimeoutc; // [2:2] CTIMEOUTCObject *dtimeoutc; // [3:3] DTIMEOUTCObject *txunderrc; // [4:4] TXUNDERRCObject *rxoverrc; // [5:5] RXOVERRCObject *cmdrendc; // [6:6] CMDRENDCObject *cmdsentc; // [7:7] CMDSENTCObject *dataendc; // [8:8] DATAENDCObject *stbiterrc; // [9:9] STBITERRCObject *dbckendc; // [10:10] DBCKENDCObject *sdioitc; // [22:22] SDIOITCObject *ceataendc; // [23:23] CEATAENDC} icr; 
// MASK(SDIO mask register (SDIO_MASK)) bitfields.
          struct { 
Object *ccrcfailie; // [0:0] CCRCFAILIEObject *dcrcfailie; // [1:1] DCRCFAILIEObject *ctimeoutie; // [2:2] CTIMEOUTIEObject *dtimeoutie; // [3:3] DTIMEOUTIEObject *txunderrie; // [4:4] TXUNDERRIEObject *rxoverrie; // [5:5] RXOVERRIEObject *cmdrendie; // [6:6] CMDRENDIEObject *cmdsentie; // [7:7] CMDSENTIEObject *dataendie; // [8:8] DATAENDIEObject *stbiterrie; // [9:9] STBITERRIEObject *dbackendie; // [10:10] DBACKENDIEObject *cmdactie; // [11:11] CMDACTIEObject *txactie; // [12:12] TXACTIEObject *rxactie; // [13:13] RXACTIEObject *txfifoheie; // [14:14] TXFIFOHEIEObject *rxfifohfie; // [15:15] RXFIFOHFIEObject *txfifofie; // [16:16] TXFIFOFIEObject *rxfifofie; // [17:17] RXFIFOFIEObject *txfifoeie; // [18:18] TXFIFOEIEObject *rxfifoeie; // [19:19] RXFIFOEIEObject *txdavlie; // [20:20] TXDAVLIEObject *rxdavlie; // [21:21] RXDAVLIEObject *sdioitie; // [22:22] SDIOITIEObject *ceatendie; // [23:23] CEATENDIE} mask; 
// FIFOCNT(Bits 23:0 = FIFOCOUNT: Remaining number of words to be written to or read from the FIFO) bitfields.
          struct { 
Object *fif0count; // [0:23] FIF0COUNT} fifocnt; 
// FIFO(Bits 31:0 = FIFOData: Receive and transmit FIFO data) bitfields.
          struct { 
Object *fifodata; // [0:31] FIFOData} fifo; 
} fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32SDIOState;

// ----------------------------------------------------------------------------

#endif /* STM32_SDIO_H_ */
