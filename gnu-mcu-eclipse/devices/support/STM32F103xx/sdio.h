/*
 * STM32 - SDIO (Secure digital input/output interface) emulation.
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

#define DEVICE_PATH_STM32_SDIO DEVICE_PATH_STM32 "SDIO"



// ----------------------------------------------------------------------------

#define TYPE_STM32_SDIO TYPE_STM32_PREFIX "sdio" TYPE_PERIPHERAL_SUFFIX

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
        // F1 SDIO (Secure digital input/output interface) registers.
        struct { 
          Object *power; // 0x0 (Bits 1:0 = PWRCTRL: Power supply control bits) 
          Object *clkcr; // 0x4 (SDI clock control register (SDIO_CLKCR)) 
          Object *arg; // 0x8 (Bits 31:0 = : Command argument) 
          Object *cmd; // 0xC (SDIO command register (SDIO_CMD)) 
          Object *respcmd; // 0x10 (SDIO command register) 
          Object *respi1; // 0x14 (Bits 31:0 = CARDSTATUS1) 
          Object *resp2; // 0x18 (Bits 31:0 = CARDSTATUS2) 
          Object *resp3; // 0x1C (Bits 31:0 = CARDSTATUS3) 
          Object *resp4; // 0x20 (Bits 31:0 = CARDSTATUS4) 
          Object *dtimer; // 0x24 (Bits 31:0 = DATATIME: Data timeout period) 
          Object *dlen; // 0x28 (Bits 24:0 = DATALENGTH: Data length value) 
          Object *dctrl; // 0x2C (SDIO data control register (SDIO_DCTRL)) 
          Object *dcount; // 0x30 (Bits 24:0 = DATACOUNT: Data count value) 
          Object *sta; // 0x34 (SDIO status register (SDIO_STA)) 
          Object *icr; // 0x38 (SDIO interrupt clear register (SDIO_ICR)) 
          Object *mask; // 0x3C (SDIO mask register (SDIO_MASK)) 
          Object *fifocnt; // 0x48 (Bits 23:0 = FIFOCOUNT: Remaining number of words to be written to or read from the FIFO) 
          Object *fifo; // 0x80 (Bits 31:0 = FIFOData: Receive and transmit FIFO data) 
        } reg;

        struct { 
          
          // POWER (Bits 1:0 = PWRCTRL: Power supply control bits) bitfields.
          struct { 
            Object *pwrctrl; // [0:1] PWRCTRL  
          } power; 
          
          // CLKCR (SDI clock control register (SDIO_CLKCR)) bitfields.
          struct { 
            Object *clkdiv; // [0:7] Clock divide factor 
            Object *clken; // [8:8] Clock enable bit 
            Object *pwrsav; // [9:9] Power saving configuration bit 
            Object *bypass; // [10:10] Clock divider bypass enable bit 
            Object *widbus; // [11:12] Wide bus mode enable bit 
            Object *negedge; // [13:13] SDIO_CK dephasing selection bit 
            Object *hwfc_en; // [14:14] HW Flow Control enable  
          } clkcr; 
          
          // ARG (Bits 31:0 = : Command argument) bitfields.
          struct { 
            Object *cmdarg; // [0:31] Command argument  
          } arg; 
          
          // CMD (SDIO command register (SDIO_CMD)) bitfields.
          struct { 
            Object *cmdindex; // [0:5] CMDINDEX 
            Object *waitresp; // [6:7] WAITRESP 
            Object *waitint; // [8:8] WAITINT 
            Object *waitpend; // [9:9] WAITPEND 
            Object *cpsmen; // [10:10] CPSMEN 
            Object *sdiosuspend; // [11:11] SDIOSuspend 
            Object *encmdcompl; // [12:12] ENCMDcompl 
            Object *nien; // [13:13] NIEN 
            Object *ce_atacmd; // [14:14] CE_ATACMD  
          } cmd; 
          
          // RESPCMD (SDIO command register) bitfields.
          struct { 
            Object *respcmd; // [0:5] RESPCMD  
          } respcmd; 
          
          // RESPI1 (Bits 31:0 = CARDSTATUS1) bitfields.
          struct { 
            Object *cardstatus1; // [0:31] CARDSTATUS1  
          } respi1; 
          
          // RESP2 (Bits 31:0 = CARDSTATUS2) bitfields.
          struct { 
            Object *cardstatus2; // [0:31] CARDSTATUS2  
          } resp2; 
          
          // RESP3 (Bits 31:0 = CARDSTATUS3) bitfields.
          struct { 
            Object *cardstatus3; // [0:31] CARDSTATUS3  
          } resp3; 
          
          // RESP4 (Bits 31:0 = CARDSTATUS4) bitfields.
          struct { 
            Object *cardstatus4; // [0:31] CARDSTATUS4  
          } resp4; 
          
          // DTIMER (Bits 31:0 = DATATIME: Data timeout period) bitfields.
          struct { 
            Object *datatime; // [0:31] Data timeout period  
          } dtimer; 
          
          // DLEN (Bits 24:0 = DATALENGTH: Data length value) bitfields.
          struct { 
            Object *datalength; // [0:24] Data length value  
          } dlen; 
          
          // DCTRL (SDIO data control register (SDIO_DCTRL)) bitfields.
          struct { 
            Object *dten; // [0:0] DTEN 
            Object *dtdir; // [1:1] DTDIR 
            Object *dtmode; // [2:2] DTMODE 
            Object *dmaen; // [3:3] DMAEN 
            Object *dblocksize; // [4:7] DBLOCKSIZE 
            Object *pwstart; // [8:8] PWSTART 
            Object *pwstop; // [9:9] PWSTOP 
            Object *rwmod; // [10:10] RWMOD 
            Object *sdioen; // [11:11] SDIOEN  
          } dctrl; 
          
          // DCOUNT (Bits 24:0 = DATACOUNT: Data count value) bitfields.
          struct { 
            Object *datacount; // [0:24] Data count value  
          } dcount; 
          
          // STA (SDIO status register (SDIO_STA)) bitfields.
          struct { 
            Object *ccrcfail; // [0:0] CCRCFAIL 
            Object *dcrcfail; // [1:1] DCRCFAIL 
            Object *ctimeout; // [2:2] CTIMEOUT 
            Object *dtimeout; // [3:3] DTIMEOUT 
            Object *txunderr; // [4:4] TXUNDERR 
            Object *rxoverr; // [5:5] RXOVERR 
            Object *cmdrend; // [6:6] CMDREND 
            Object *cmdsent; // [7:7] CMDSENT 
            Object *dataend; // [8:8] DATAEND 
            Object *stbiterr; // [9:9] STBITERR 
            Object *dbckend; // [10:10] DBCKEND 
            Object *cmdact; // [11:11] CMDACT 
            Object *txact; // [12:12] TXACT 
            Object *rxact; // [13:13] RXACT 
            Object *txfifohe; // [14:14] TXFIFOHE 
            Object *rxfifohf; // [15:15] RXFIFOHF 
            Object *txfifof; // [16:16] TXFIFOF 
            Object *rxfifof; // [17:17] RXFIFOF 
            Object *txfifoe; // [18:18] TXFIFOE 
            Object *rxfifoe; // [19:19] RXFIFOE 
            Object *txdavl; // [20:20] TXDAVL 
            Object *rxdavl; // [21:21] RXDAVL 
            Object *sdioit; // [22:22] SDIOIT 
            Object *ceataend; // [23:23] CEATAEND  
          } sta; 
          
          // ICR (SDIO interrupt clear register (SDIO_ICR)) bitfields.
          struct { 
            Object *ccrcfailc; // [0:0] CCRCFAILC 
            Object *dcrcfailc; // [1:1] DCRCFAILC 
            Object *ctimeoutc; // [2:2] CTIMEOUTC 
            Object *dtimeoutc; // [3:3] DTIMEOUTC 
            Object *txunderrc; // [4:4] TXUNDERRC 
            Object *rxoverrc; // [5:5] RXOVERRC 
            Object *cmdrendc; // [6:6] CMDRENDC 
            Object *cmdsentc; // [7:7] CMDSENTC 
            Object *dataendc; // [8:8] DATAENDC 
            Object *stbiterrc; // [9:9] STBITERRC 
            Object *dbckendc; // [10:10] DBCKENDC 
            Object *sdioitc; // [22:22] SDIOITC 
            Object *ceataendc; // [23:23] CEATAENDC  
          } icr; 
          
          // MASK (SDIO mask register (SDIO_MASK)) bitfields.
          struct { 
            Object *ccrcfailie; // [0:0] CCRCFAILIE 
            Object *dcrcfailie; // [1:1] DCRCFAILIE 
            Object *ctimeoutie; // [2:2] CTIMEOUTIE 
            Object *dtimeoutie; // [3:3] DTIMEOUTIE 
            Object *txunderrie; // [4:4] TXUNDERRIE 
            Object *rxoverrie; // [5:5] RXOVERRIE 
            Object *cmdrendie; // [6:6] CMDRENDIE 
            Object *cmdsentie; // [7:7] CMDSENTIE 
            Object *dataendie; // [8:8] DATAENDIE 
            Object *stbiterrie; // [9:9] STBITERRIE 
            Object *dbackendie; // [10:10] DBACKENDIE 
            Object *cmdactie; // [11:11] CMDACTIE 
            Object *txactie; // [12:12] TXACTIE 
            Object *rxactie; // [13:13] RXACTIE 
            Object *txfifoheie; // [14:14] TXFIFOHEIE 
            Object *rxfifohfie; // [15:15] RXFIFOHFIE 
            Object *txfifofie; // [16:16] TXFIFOFIE 
            Object *rxfifofie; // [17:17] RXFIFOFIE 
            Object *txfifoeie; // [18:18] TXFIFOEIE 
            Object *rxfifoeie; // [19:19] RXFIFOEIE 
            Object *txdavlie; // [20:20] TXDAVLIE 
            Object *rxdavlie; // [21:21] RXDAVLIE 
            Object *sdioitie; // [22:22] SDIOITIE 
            Object *ceatendie; // [23:23] CEATENDIE  
          } mask; 
          
          // FIFOCNT (Bits 23:0 = FIFOCOUNT: Remaining number of words to be written to or read from the FIFO) bitfields.
          struct { 
            Object *fif0count; // [0:23] FIF0COUNT  
          } fifocnt; 
          
          // FIFO (Bits 31:0 = FIFOData: Receive and transmit FIFO data) bitfields.
          struct { 
            Object *fifodata; // [0:31] FIFOData  
          } fifo; 
        } fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32SDIOState;

// ----------------------------------------------------------------------------

#endif /* STM32_SDIO_H_ */
