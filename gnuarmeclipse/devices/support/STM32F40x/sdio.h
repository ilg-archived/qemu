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
        // F4SDIO(Secure digital input/output interface) registers.
        struct { 
Object *power; // 0x0(Power control register) 
Object *clkcr; // 0x4(SDI clock control register) 
Object *arg; // 0x8(Argument register) 
Object *cmd; // 0xC(Command register) 
Object *respcmd; // 0x10(Command response register) 
Object *resp1; // 0x14(Response 1..4 register) 
Object *resp2; // 0x18(Response 1..4 register) 
Object *resp3; // 0x1C(Response 1..4 register) 
Object *resp4; // 0x20(Response 1..4 register) 
Object *dtimer; // 0x24(Data timer register) 
Object *dlen; // 0x28(Data length register) 
Object *dctrl; // 0x2C(Data control register) 
Object *dcount; // 0x30(Data counter register) 
Object *sta; // 0x34(Status register) 
Object *icr; // 0x38(Interrupt clear register) 
Object *mask; // 0x3C(Mask register) 
Object *fifocnt; // 0x48(FIFO counter register) 
Object *fifo; // 0x80(Data FIFO register) 
} reg;

        struct { 
// POWER(Power control register) bitfields.
          struct { 
Object *pwrctrl; // [0:1] PWRCTRL} power; 
// CLKCR(SDI clock control register) bitfields.
          struct { 
Object *clkdiv; // [0:7] Clock divide factorObject *clken; // [8:8] Clock enable bitObject *pwrsav; // [9:9] Power saving configuration bitObject *bypass; // [10:10] Clock divider bypass enable bitObject *widbus; // [11:12] Wide bus mode enable bitObject *negedge; // [13:13] SDIO_CK dephasing selection bitObject *hwfc_en; // [14:14] HW Flow Control enable} clkcr; 
// ARG(Argument register) bitfields.
          struct { 
Object *cmdarg; // [0:31] Command argument} arg; 
// CMD(Command register) bitfields.
          struct { 
Object *cmdindex; // [0:5] Command indexObject *waitresp; // [6:7] Wait for response bitsObject *waitint; // [8:8] CPSM waits for interrupt requestObject *waitpend; // [9:9] CPSM Waits for ends of data transfer (CmdPend internal signal).Object *cpsmen; // [10:10] Command path state machine (CPSM) Enable bitObject *sdiosuspend; // [11:11] SD I/O suspend commandObject *encmdcompl; // [12:12] Enable CMD completionObject *nien; // [13:13] Not Interrupt EnableObject *ce_atacmd; // [14:14] CE-ATA command} cmd; 
// RESPCMD(Command response register) bitfields.
          struct { 
Object *respcmd; // [0:5] Response command index} respcmd; 
// RESP1(Response 1..4 register) bitfields.
          struct { 
Object *cardstatus1; // [0:31] See Table 132.} resp1; 
// RESP2(Response 1..4 register) bitfields.
          struct { 
Object *cardstatus2; // [0:31] See Table 132.} resp2; 
// RESP3(Response 1..4 register) bitfields.
          struct { 
Object *cardstatus3; // [0:31] See Table 132.} resp3; 
// RESP4(Response 1..4 register) bitfields.
          struct { 
Object *cardstatus4; // [0:31] See Table 132.} resp4; 
// DTIMER(Data timer register) bitfields.
          struct { 
Object *datatime; // [0:31] Data timeout period} dtimer; 
// DLEN(Data length register) bitfields.
          struct { 
Object *datalength; // [0:24] Data length value} dlen; 
// DCTRL(Data control register) bitfields.
          struct { 
Object *dten; // [0:0] DTENObject *dtdir; // [1:1] Data transfer direction selectionObject *dtmode; // [2:2] Data transfer mode selection 1: Stream or SDIO multibyte data transfer.Object *dmaen; // [3:3] DMA enable bitObject *dblocksize; // [4:7] Data block sizeObject *rwstart; // [8:8] Read wait startObject *rwstop; // [9:9] Read wait stopObject *rwmod; // [10:10] Read wait modeObject *sdioen; // [11:11] SD I/O enable functions} dctrl; 
// DCOUNT(Data counter register) bitfields.
          struct { 
Object *datacount; // [0:24] Data count value} dcount; 
// STA(Status register) bitfields.
          struct { 
Object *ccrcfail; // [0:0] Command response received (CRC check failed)Object *dcrcfail; // [1:1] Data block sent/received (CRC check failed)Object *ctimeout; // [2:2] Command response timeoutObject *dtimeout; // [3:3] Data timeoutObject *txunderr; // [4:4] Transmit FIFO underrun errorObject *rxoverr; // [5:5] Received FIFO overrun errorObject *cmdrend; // [6:6] Command response received (CRC check passed)Object *cmdsent; // [7:7] Command sent (no response required)Object *dataend; // [8:8] Data end (data counter, SDIDCOUNT, is zero)Object *stbiterr; // [9:9] Start bit not detected on all data signals in wide bus modeObject *dbckend; // [10:10] Data block sent/received (CRC check passed)Object *cmdact; // [11:11] Command transfer in progressObject *txact; // [12:12] Data transmit in progressObject *rxact; // [13:13] Data receive in progressObject *txfifohe; // [14:14] Transmit FIFO half empty: at least 8 words can be written into the FIFOObject *rxfifohf; // [15:15] Receive FIFO half full: there are at least 8 words in the FIFOObject *txfifof; // [16:16] Transmit FIFO fullObject *rxfifof; // [17:17] Receive FIFO fullObject *txfifoe; // [18:18] Transmit FIFO emptyObject *rxfifoe; // [19:19] Receive FIFO emptyObject *txdavl; // [20:20] Data available in transmit FIFOObject *rxdavl; // [21:21] Data available in receive FIFOObject *sdioit; // [22:22] SDIO interrupt receivedObject *ceataend; // [23:23] CE-ATA command completion signal received for CMD61} sta; 
// ICR(Interrupt clear register) bitfields.
          struct { 
Object *ccrcfailc; // [0:0] CCRCFAIL flag clear bitObject *dcrcfailc; // [1:1] DCRCFAIL flag clear bitObject *ctimeoutc; // [2:2] CTIMEOUT flag clear bitObject *dtimeoutc; // [3:3] DTIMEOUT flag clear bitObject *txunderrc; // [4:4] TXUNDERR flag clear bitObject *rxoverrc; // [5:5] RXOVERR flag clear bitObject *cmdrendc; // [6:6] CMDREND flag clear bitObject *cmdsentc; // [7:7] CMDSENT flag clear bitObject *dataendc; // [8:8] DATAEND flag clear bitObject *stbiterrc; // [9:9] STBITERR flag clear bitObject *dbckendc; // [10:10] DBCKEND flag clear bitObject *sdioitc; // [22:22] SDIOIT flag clear bitObject *ceataendc; // [23:23] CEATAEND flag clear bit} icr; 
// MASK(Mask register) bitfields.
          struct { 
Object *ccrcfailie; // [0:0] Command CRC fail interrupt enableObject *dcrcfailie; // [1:1] Data CRC fail interrupt enableObject *ctimeoutie; // [2:2] Command timeout interrupt enableObject *dtimeoutie; // [3:3] Data timeout interrupt enableObject *txunderrie; // [4:4] Tx FIFO underrun error interrupt enableObject *rxoverrie; // [5:5] Rx FIFO overrun error interrupt enableObject *cmdrendie; // [6:6] Command response received interrupt enableObject *cmdsentie; // [7:7] Command sent interrupt enableObject *dataendie; // [8:8] Data end interrupt enableObject *stbiterrie; // [9:9] Start bit error interrupt enableObject *dbckendie; // [10:10] Data block end interrupt enableObject *cmdactie; // [11:11] Command acting interrupt enableObject *txactie; // [12:12] Data transmit acting interrupt enableObject *rxactie; // [13:13] Data receive acting interrupt enableObject *txfifoheie; // [14:14] Tx FIFO half empty interrupt enableObject *rxfifohfie; // [15:15] Rx FIFO half full interrupt enableObject *txfifofie; // [16:16] Tx FIFO full interrupt enableObject *rxfifofie; // [17:17] Rx FIFO full interrupt enableObject *txfifoeie; // [18:18] Tx FIFO empty interrupt enableObject *rxfifoeie; // [19:19] Rx FIFO empty interrupt enableObject *txdavlie; // [20:20] Data available in Tx FIFO interrupt enableObject *rxdavlie; // [21:21] Data available in Rx FIFO interrupt enableObject *sdioitie; // [22:22] SDIO mode interrupt received interrupt enableObject *ceataendie; // [23:23] CE-ATA command completion signal received interrupt enable} mask; 
// FIFOCNT(FIFO counter register) bitfields.
          struct { 
Object *fifocount; // [0:23] Remaining number of words to be written to or read from the FIFO.} fifocnt; 
// FIFO(Data FIFO register) bitfields.
          struct { 
Object *fifodata; // [0:31] Receive and transmit FIFO data} fifo; 
} fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32SDIOState;

// ----------------------------------------------------------------------------

#endif /* STM32_SDIO_H_ */
