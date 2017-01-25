/*
 * STM32 - CAN (Controller area network) emulation.
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

#ifndef STM32_CAN_H_
#define STM32_CAN_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_CAN DEVICE_PATH_STM32 "CAN"

// ----------------------------------------------------------------------------

// Note: the "port-index" property has type "int".
typedef enum {
    // TODO: keep this list in ascending order.
    STM32_PORT_CAN1,
    STM32_PORT_CAN2,
    STM32_PORT_CAN_UNDEFINED = 0xFF,
} stm32_can_index_t;

// ----------------------------------------------------------------------------

#define TYPE_STM32_CAN TYPE_STM32_PREFIX "can" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_CAN_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32CANParentClass;
typedef PeripheralState STM32CANParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_CAN_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32CANClass, (obj), TYPE_STM32_CAN)
#define STM32_CAN_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32CANClass, (klass), TYPE_STM32_CAN)

typedef struct {
    // private: 
    STM32CANParentClass parent_class;
    // public: 

    // None, so far.
} STM32CANClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_CAN_STATE(obj) \
    OBJECT_CHECK(STM32CANState, (obj), TYPE_STM32_CAN)

typedef struct {
    // private:
    STM32CANParentState parent_obj;
    // public:

    const STM32Capabilities *capabilities;

    // TODO: remove this if the peripheral is always enabled.
    // Points to the bitfield that enables the peripheral.
    Object *enabling_bit;

    // Remove it if there is only one port
    stm32_can_index_t port_index;

    union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // F4 CAN (Controller area network) registers.
        struct { 
          Object *mcr; // 0x0 (Master control register) 
          Object *msr; // 0x4 (Master status register) 
          Object *tsr; // 0x8 (Transmit status register) 
          Object *rf0r; // 0xC (Receive FIFO 0 register) 
          Object *rf1r; // 0x10 (Receive FIFO 1 register) 
          Object *ier; // 0x14 (Interrupt enable register) 
          Object *esr; // 0x18 (Interrupt enable register) 
          Object *btr; // 0x1C (Bit timing register) 
          Object *ti0r; // 0x180 (TX mailbox identifier register) 
          Object *tdt0r; // 0x184 (Mailbox data length control and time stamp register) 
          Object *tdl0r; // 0x188 (Mailbox data low register) 
          Object *tdh0r; // 0x18C (Mailbox data high register) 
          Object *ti1r; // 0x190 (Mailbox identifier register) 
          Object *tdt1r; // 0x194 (Mailbox data length control and time stamp register) 
          Object *tdl1r; // 0x198 (Mailbox data low register) 
          Object *tdh1r; // 0x19C (Mailbox data high register) 
          Object *ti2r; // 0x1A0 (Mailbox identifier register) 
          Object *tdt2r; // 0x1A4 (Mailbox data length control and time stamp register) 
          Object *tdl2r; // 0x1A8 (Mailbox data low register) 
          Object *tdh2r; // 0x1AC (Mailbox data high register) 
          Object *ri0r; // 0x1B0 (Receive FIFO mailbox identifier register) 
          Object *rdt0r; // 0x1B4 (Mailbox data high register) 
          Object *rdl0r; // 0x1B8 (Mailbox data high register) 
          Object *rdh0r; // 0x1BC (Receive FIFO mailbox data high register) 
          Object *ri1r; // 0x1C0 (Mailbox data high register) 
          Object *rdt1r; // 0x1C4 (Mailbox data high register) 
          Object *rdl1r; // 0x1C8 (Mailbox data high register) 
          Object *rdh1r; // 0x1CC (Mailbox data high register) 
          Object *fmr; // 0x200 (Filter master register) 
          Object *fm1r; // 0x204 (Filter mode register) 
          Object *fs1r; // 0x20C (Filter scale register) 
          Object *ffa1r; // 0x214 (Filter FIFO assignment register) 
          Object *fa1r; // 0x21C (Filter activation register) 
          Object *f0r1; // 0x240 (Filter bank 0 register 1) 
          Object *f0r2; // 0x244 (Filter bank 0 register 2) 
          Object *f1r1; // 0x248 (Filter bank 1 register 1) 
          Object *f1r2; // 0x24C (Filter bank 1 register 2) 
          Object *f2r1; // 0x250 (Filter bank 2 register 1) 
          Object *f2r2; // 0x254 (Filter bank 2 register 2) 
          Object *f3r1; // 0x258 (Filter bank 3 register 1) 
          Object *f3r2; // 0x25C (Filter bank 3 register 2) 
          Object *f4r1; // 0x260 (Filter bank 4 register 1) 
          Object *f4r2; // 0x264 (Filter bank 4 register 2) 
          Object *f5r1; // 0x268 (Filter bank 5 register 1) 
          Object *f5r2; // 0x26C (Filter bank 5 register 2) 
          Object *f6r1; // 0x270 (Filter bank 6 register 1) 
          Object *f6r2; // 0x274 (Filter bank 6 register 2) 
          Object *f7r1; // 0x278 (Filter bank 7 register 1) 
          Object *f7r2; // 0x27C (Filter bank 7 register 2) 
          Object *f8r1; // 0x280 (Filter bank 8 register 1) 
          Object *f8r2; // 0x284 (Filter bank 8 register 2) 
          Object *f9r1; // 0x288 (Filter bank 9 register 1) 
          Object *f9r2; // 0x28C (Filter bank 9 register 2) 
          Object *f10r1; // 0x290 (Filter bank 10 register 1) 
          Object *f10r2; // 0x294 (Filter bank 10 register 2) 
          Object *f11r1; // 0x298 (Filter bank 11 register 1) 
          Object *f11r2; // 0x29C (Filter bank 11 register 2) 
          Object *f12r1; // 0x2A0 (Filter bank 4 register 1) 
          Object *f12r2; // 0x2A4 (Filter bank 12 register 2) 
          Object *f13r1; // 0x2A8 (Filter bank 13 register 1) 
          Object *f13r2; // 0x2AC (Filter bank 13 register 2) 
          Object *f14r1; // 0x2B0 (Filter bank 14 register 1) 
          Object *f14r2; // 0x2B4 (Filter bank 14 register 2) 
          Object *f15r1; // 0x2B8 (Filter bank 15 register 1) 
          Object *f15r2; // 0x2BC (Filter bank 15 register 2) 
          Object *f16r1; // 0x2C0 (Filter bank 16 register 1) 
          Object *f16r2; // 0x2C4 (Filter bank 16 register 2) 
          Object *f17r1; // 0x2C8 (Filter bank 17 register 1) 
          Object *f17r2; // 0x2CC (Filter bank 17 register 2) 
          Object *f18r1; // 0x2D0 (Filter bank 18 register 1) 
          Object *f18r2; // 0x2D4 (Filter bank 18 register 2) 
          Object *f19r1; // 0x2D8 (Filter bank 19 register 1) 
          Object *f19r2; // 0x2DC (Filter bank 19 register 2) 
          Object *f20r1; // 0x2E0 (Filter bank 20 register 1) 
          Object *f20r2; // 0x2E4 (Filter bank 20 register 2) 
          Object *f21r1; // 0x2E8 (Filter bank 21 register 1) 
          Object *f21r2; // 0x2EC (Filter bank 21 register 2) 
          Object *f22r1; // 0x2F0 (Filter bank 22 register 1) 
          Object *f22r2; // 0x2F4 (Filter bank 22 register 2) 
          Object *f23r1; // 0x2F8 (Filter bank 23 register 1) 
          Object *f23r2; // 0x2FC (Filter bank 23 register 2) 
          Object *f24r1; // 0x300 (Filter bank 24 register 1) 
          Object *f24r2; // 0x304 (Filter bank 24 register 2) 
          Object *f25r1; // 0x308 (Filter bank 25 register 1) 
          Object *f25r2; // 0x30C (Filter bank 25 register 2) 
          Object *f26r1; // 0x310 (Filter bank 26 register 1) 
          Object *f26r2; // 0x314 (Filter bank 26 register 2) 
          Object *f27r1; // 0x318 (Filter bank 27 register 1) 
          Object *f27r2; // 0x31C (Filter bank 27 register 2) 
        } reg;

        struct { 
          
          // MCR (Master control register) bitfields.
          struct { 
            Object *inrq; // [0:0] INRQ 
            Object *sleep; // [1:1] SLEEP 
            Object *txfp; // [2:2] TXFP 
            Object *rflm; // [3:3] RFLM 
            Object *nart; // [4:4] NART 
            Object *awum; // [5:5] AWUM 
            Object *abom; // [6:6] ABOM 
            Object *ttcm; // [7:7] TTCM 
            Object *reset; // [15:15] RESET 
            Object *dbf; // [16:16] DBF  
          } mcr; 
          
          // MSR (Master status register) bitfields.
          struct { 
            Object *inak; // [0:0] INAK 
            Object *slak; // [1:1] SLAK 
            Object *erri; // [2:2] ERRI 
            Object *wkui; // [3:3] WKUI 
            Object *slaki; // [4:4] SLAKI 
            Object *txm; // [8:8] TXM 
            Object *rxm; // [9:9] RXM 
            Object *samp; // [10:10] SAMP 
            Object *rx; // [11:11] RX  
          } msr; 
          
          // TSR (Transmit status register) bitfields.
          struct { 
            Object *rqcp0; // [0:0] RQCP0 
            Object *txok0; // [1:1] TXOK0 
            Object *alst0; // [2:2] ALST0 
            Object *terr0; // [3:3] TERR0 
            Object *abrq0; // [7:7] ABRQ0 
            Object *rqcp1; // [8:8] RQCP1 
            Object *txok1; // [9:9] TXOK1 
            Object *alst1; // [10:10] ALST1 
            Object *terr1; // [11:11] TERR1 
            Object *abrq1; // [15:15] ABRQ1 
            Object *rqcp2; // [16:16] RQCP2 
            Object *txok2; // [17:17] TXOK2 
            Object *alst2; // [18:18] ALST2 
            Object *terr2; // [19:19] TERR2 
            Object *abrq2; // [23:23] ABRQ2 
            Object *code; // [24:25] CODE 
            Object *tme0; // [26:26] Lowest priority flag for mailbox 0 
            Object *tme1; // [27:27] Lowest priority flag for mailbox 1 
            Object *tme2; // [28:28] Lowest priority flag for mailbox 2 
            Object *low0; // [29:29] Lowest priority flag for mailbox 0 
            Object *low1; // [30:30] Lowest priority flag for mailbox 1 
            Object *low2; // [31:31] Lowest priority flag for mailbox 2  
          } tsr; 
          
          // RF0R (Receive FIFO 0 register) bitfields.
          struct { 
            Object *fmp0; // [0:1] FMP0 
            Object *full0; // [3:3] FULL0 
            Object *fovr0; // [4:4] FOVR0 
            Object *rfom0; // [5:5] RFOM0  
          } rf0r; 
          
          // RF1R (Receive FIFO 1 register) bitfields.
          struct { 
            Object *fmp1; // [0:1] FMP1 
            Object *full1; // [3:3] FULL1 
            Object *fovr1; // [4:4] FOVR1 
            Object *rfom1; // [5:5] RFOM1  
          } rf1r; 
          
          // IER (Interrupt enable register) bitfields.
          struct { 
            Object *tmeie; // [0:0] TMEIE 
            Object *fmpie0; // [1:1] FMPIE0 
            Object *ffie0; // [2:2] FFIE0 
            Object *fovie0; // [3:3] FOVIE0 
            Object *fmpie1; // [4:4] FMPIE1 
            Object *ffie1; // [5:5] FFIE1 
            Object *fovie1; // [6:6] FOVIE1 
            Object *ewgie; // [8:8] EWGIE 
            Object *epvie; // [9:9] EPVIE 
            Object *bofie; // [10:10] BOFIE 
            Object *lecie; // [11:11] LECIE 
            Object *errie; // [15:15] ERRIE 
            Object *wkuie; // [16:16] WKUIE 
            Object *slkie; // [17:17] SLKIE  
          } ier; 
          
          // ESR (Interrupt enable register) bitfields.
          struct { 
            Object *ewgf; // [0:0] EWGF 
            Object *epvf; // [1:1] EPVF 
            Object *boff; // [2:2] BOFF 
            Object *lec; // [4:6] LEC 
            Object *tec; // [16:23] TEC 
            Object *rec; // [24:31] REC  
          } esr; 
          
          // BTR (Bit timing register) bitfields.
          struct { 
            Object *brp; // [0:9] BRP 
            Object *ts1; // [16:19] TS1 
            Object *ts2; // [20:22] TS2 
            Object *sjw; // [24:25] SJW 
            Object *lbkm; // [30:30] LBKM 
            Object *silm; // [31:31] SILM  
          } btr; 
          
          // TI0R (TX mailbox identifier register) bitfields.
          struct { 
            Object *txrq; // [0:0] TXRQ 
            Object *rtr; // [1:1] RTR 
            Object *ide; // [2:2] IDE 
            Object *exid; // [3:20] EXID 
            Object *stid; // [21:31] STID  
          } ti0r; 
          
          // TDT0R (Mailbox data length control and time stamp register) bitfields.
          struct { 
            Object *dlc; // [0:3] DLC 
            Object *tgt; // [8:8] TGT 
            Object *time; // [16:31] TIME  
          } tdt0r; 
          
          // TDL0R (Mailbox data low register) bitfields.
          struct { 
            Object *data0; // [0:7] DATA0 
            Object *data1; // [8:15] DATA1 
            Object *data2; // [16:23] DATA2 
            Object *data3; // [24:31] DATA3  
          } tdl0r; 
          
          // TDH0R (Mailbox data high register) bitfields.
          struct { 
            Object *data4; // [0:7] DATA4 
            Object *data5; // [8:15] DATA5 
            Object *data6; // [16:23] DATA6 
            Object *data7; // [24:31] DATA7  
          } tdh0r; 
          
          // TI1R (Mailbox identifier register) bitfields.
          struct { 
            Object *txrq; // [0:0] TXRQ 
            Object *rtr; // [1:1] RTR 
            Object *ide; // [2:2] IDE 
            Object *exid; // [3:20] EXID 
            Object *stid; // [21:31] STID  
          } ti1r; 
          
          // TDT1R (Mailbox data length control and time stamp register) bitfields.
          struct { 
            Object *dlc; // [0:3] DLC 
            Object *tgt; // [8:8] TGT 
            Object *time; // [16:31] TIME  
          } tdt1r; 
          
          // TDL1R (Mailbox data low register) bitfields.
          struct { 
            Object *data0; // [0:7] DATA0 
            Object *data1; // [8:15] DATA1 
            Object *data2; // [16:23] DATA2 
            Object *data3; // [24:31] DATA3  
          } tdl1r; 
          
          // TDH1R (Mailbox data high register) bitfields.
          struct { 
            Object *data4; // [0:7] DATA4 
            Object *data5; // [8:15] DATA5 
            Object *data6; // [16:23] DATA6 
            Object *data7; // [24:31] DATA7  
          } tdh1r; 
          
          // TI2R (Mailbox identifier register) bitfields.
          struct { 
            Object *txrq; // [0:0] TXRQ 
            Object *rtr; // [1:1] RTR 
            Object *ide; // [2:2] IDE 
            Object *exid; // [3:20] EXID 
            Object *stid; // [21:31] STID  
          } ti2r; 
          
          // TDT2R (Mailbox data length control and time stamp register) bitfields.
          struct { 
            Object *dlc; // [0:3] DLC 
            Object *tgt; // [8:8] TGT 
            Object *time; // [16:31] TIME  
          } tdt2r; 
          
          // TDL2R (Mailbox data low register) bitfields.
          struct { 
            Object *data0; // [0:7] DATA0 
            Object *data1; // [8:15] DATA1 
            Object *data2; // [16:23] DATA2 
            Object *data3; // [24:31] DATA3  
          } tdl2r; 
          
          // TDH2R (Mailbox data high register) bitfields.
          struct { 
            Object *data4; // [0:7] DATA4 
            Object *data5; // [8:15] DATA5 
            Object *data6; // [16:23] DATA6 
            Object *data7; // [24:31] DATA7  
          } tdh2r; 
          
          // RI0R (Receive FIFO mailbox identifier register) bitfields.
          struct { 
            Object *rtr; // [1:1] RTR 
            Object *ide; // [2:2] IDE 
            Object *exid; // [3:20] EXID 
            Object *stid; // [21:31] STID  
          } ri0r; 
          
          // RDT0R (Mailbox data high register) bitfields.
          struct { 
            Object *dlc; // [0:3] DLC 
            Object *fmi; // [8:15] FMI 
            Object *time; // [16:31] TIME  
          } rdt0r; 
          
          // RDL0R (Mailbox data high register) bitfields.
          struct { 
            Object *data0; // [0:7] DATA0 
            Object *data1; // [8:15] DATA1 
            Object *data2; // [16:23] DATA2 
            Object *data3; // [24:31] DATA3  
          } rdl0r; 
          
          // RDH0R (Receive FIFO mailbox data high register) bitfields.
          struct { 
            Object *data4; // [0:7] DATA4 
            Object *data5; // [8:15] DATA5 
            Object *data6; // [16:23] DATA6 
            Object *data7; // [24:31] DATA7  
          } rdh0r; 
          
          // RI1R (Mailbox data high register) bitfields.
          struct { 
            Object *rtr; // [1:1] RTR 
            Object *ide; // [2:2] IDE 
            Object *exid; // [3:20] EXID 
            Object *stid; // [21:31] STID  
          } ri1r; 
          
          // RDT1R (Mailbox data high register) bitfields.
          struct { 
            Object *dlc; // [0:3] DLC 
            Object *fmi; // [8:15] FMI 
            Object *time; // [16:31] TIME  
          } rdt1r; 
          
          // RDL1R (Mailbox data high register) bitfields.
          struct { 
            Object *data0; // [0:7] DATA0 
            Object *data1; // [8:15] DATA1 
            Object *data2; // [16:23] DATA2 
            Object *data3; // [24:31] DATA3  
          } rdl1r; 
          
          // RDH1R (Mailbox data high register) bitfields.
          struct { 
            Object *data4; // [0:7] DATA4 
            Object *data5; // [8:15] DATA5 
            Object *data6; // [16:23] DATA6 
            Object *data7; // [24:31] DATA7  
          } rdh1r; 
          
          // FMR (Filter master register) bitfields.
          struct { 
            Object *finit; // [0:0] FINIT 
            Object *can2sb; // [8:13] CAN2SB  
          } fmr; 
          
          // FM1R (Filter mode register) bitfields.
          struct { 
            Object *fbm0; // [0:0] Filter mode 
            Object *fbm1; // [1:1] Filter mode 
            Object *fbm2; // [2:2] Filter mode 
            Object *fbm3; // [3:3] Filter mode 
            Object *fbm4; // [4:4] Filter mode 
            Object *fbm5; // [5:5] Filter mode 
            Object *fbm6; // [6:6] Filter mode 
            Object *fbm7; // [7:7] Filter mode 
            Object *fbm8; // [8:8] Filter mode 
            Object *fbm9; // [9:9] Filter mode 
            Object *fbm10; // [10:10] Filter mode 
            Object *fbm11; // [11:11] Filter mode 
            Object *fbm12; // [12:12] Filter mode 
            Object *fbm13; // [13:13] Filter mode 
            Object *fbm14; // [14:14] Filter mode 
            Object *fbm15; // [15:15] Filter mode 
            Object *fbm16; // [16:16] Filter mode 
            Object *fbm17; // [17:17] Filter mode 
            Object *fbm18; // [18:18] Filter mode 
            Object *fbm19; // [19:19] Filter mode 
            Object *fbm20; // [20:20] Filter mode 
            Object *fbm21; // [21:21] Filter mode 
            Object *fbm22; // [22:22] Filter mode 
            Object *fbm23; // [23:23] Filter mode 
            Object *fbm24; // [24:24] Filter mode 
            Object *fbm25; // [25:25] Filter mode 
            Object *fbm26; // [26:26] Filter mode 
            Object *fbm27; // [27:27] Filter mode  
          } fm1r; 
          
          // FS1R (Filter scale register) bitfields.
          struct { 
            Object *fsc0; // [0:0] Filter scale configuration 
            Object *fsc1; // [1:1] Filter scale configuration 
            Object *fsc2; // [2:2] Filter scale configuration 
            Object *fsc3; // [3:3] Filter scale configuration 
            Object *fsc4; // [4:4] Filter scale configuration 
            Object *fsc5; // [5:5] Filter scale configuration 
            Object *fsc6; // [6:6] Filter scale configuration 
            Object *fsc7; // [7:7] Filter scale configuration 
            Object *fsc8; // [8:8] Filter scale configuration 
            Object *fsc9; // [9:9] Filter scale configuration 
            Object *fsc10; // [10:10] Filter scale configuration 
            Object *fsc11; // [11:11] Filter scale configuration 
            Object *fsc12; // [12:12] Filter scale configuration 
            Object *fsc13; // [13:13] Filter scale configuration 
            Object *fsc14; // [14:14] Filter scale configuration 
            Object *fsc15; // [15:15] Filter scale configuration 
            Object *fsc16; // [16:16] Filter scale configuration 
            Object *fsc17; // [17:17] Filter scale configuration 
            Object *fsc18; // [18:18] Filter scale configuration 
            Object *fsc19; // [19:19] Filter scale configuration 
            Object *fsc20; // [20:20] Filter scale configuration 
            Object *fsc21; // [21:21] Filter scale configuration 
            Object *fsc22; // [22:22] Filter scale configuration 
            Object *fsc23; // [23:23] Filter scale configuration 
            Object *fsc24; // [24:24] Filter scale configuration 
            Object *fsc25; // [25:25] Filter scale configuration 
            Object *fsc26; // [26:26] Filter scale configuration 
            Object *fsc27; // [27:27] Filter scale configuration  
          } fs1r; 
          
          // FFA1R (Filter FIFO assignment register) bitfields.
          struct { 
            Object *ffa0; // [0:0] Filter FIFO assignment for filter 0 
            Object *ffa1; // [1:1] Filter FIFO assignment for filter 1 
            Object *ffa2; // [2:2] Filter FIFO assignment for filter 2 
            Object *ffa3; // [3:3] Filter FIFO assignment for filter 3 
            Object *ffa4; // [4:4] Filter FIFO assignment for filter 4 
            Object *ffa5; // [5:5] Filter FIFO assignment for filter 5 
            Object *ffa6; // [6:6] Filter FIFO assignment for filter 6 
            Object *ffa7; // [7:7] Filter FIFO assignment for filter 7 
            Object *ffa8; // [8:8] Filter FIFO assignment for filter 8 
            Object *ffa9; // [9:9] Filter FIFO assignment for filter 9 
            Object *ffa10; // [10:10] Filter FIFO assignment for filter 10 
            Object *ffa11; // [11:11] Filter FIFO assignment for filter 11 
            Object *ffa12; // [12:12] Filter FIFO assignment for filter 12 
            Object *ffa13; // [13:13] Filter FIFO assignment for filter 13 
            Object *ffa14; // [14:14] Filter FIFO assignment for filter 14 
            Object *ffa15; // [15:15] Filter FIFO assignment for filter 15 
            Object *ffa16; // [16:16] Filter FIFO assignment for filter 16 
            Object *ffa17; // [17:17] Filter FIFO assignment for filter 17 
            Object *ffa18; // [18:18] Filter FIFO assignment for filter 18 
            Object *ffa19; // [19:19] Filter FIFO assignment for filter 19 
            Object *ffa20; // [20:20] Filter FIFO assignment for filter 20 
            Object *ffa21; // [21:21] Filter FIFO assignment for filter 21 
            Object *ffa22; // [22:22] Filter FIFO assignment for filter 22 
            Object *ffa23; // [23:23] Filter FIFO assignment for filter 23 
            Object *ffa24; // [24:24] Filter FIFO assignment for filter 24 
            Object *ffa25; // [25:25] Filter FIFO assignment for filter 25 
            Object *ffa26; // [26:26] Filter FIFO assignment for filter 26 
            Object *ffa27; // [27:27] Filter FIFO assignment for filter 27  
          } ffa1r; 
          
          // FA1R (Filter activation register) bitfields.
          struct { 
            Object *fact0; // [0:0] Filter active 
            Object *fact1; // [1:1] Filter active 
            Object *fact2; // [2:2] Filter active 
            Object *fact3; // [3:3] Filter active 
            Object *fact4; // [4:4] Filter active 
            Object *fact5; // [5:5] Filter active 
            Object *fact6; // [6:6] Filter active 
            Object *fact7; // [7:7] Filter active 
            Object *fact8; // [8:8] Filter active 
            Object *fact9; // [9:9] Filter active 
            Object *fact10; // [10:10] Filter active 
            Object *fact11; // [11:11] Filter active 
            Object *fact12; // [12:12] Filter active 
            Object *fact13; // [13:13] Filter active 
            Object *fact14; // [14:14] Filter active 
            Object *fact15; // [15:15] Filter active 
            Object *fact16; // [16:16] Filter active 
            Object *fact17; // [17:17] Filter active 
            Object *fact18; // [18:18] Filter active 
            Object *fact19; // [19:19] Filter active 
            Object *fact20; // [20:20] Filter active 
            Object *fact21; // [21:21] Filter active 
            Object *fact22; // [22:22] Filter active 
            Object *fact23; // [23:23] Filter active 
            Object *fact24; // [24:24] Filter active 
            Object *fact25; // [25:25] Filter active 
            Object *fact26; // [26:26] Filter active 
            Object *fact27; // [27:27] Filter active  
          } fa1r; 
          
          // F0R1 (Filter bank 0 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f0r1; 
          
          // F0R2 (Filter bank 0 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f0r2; 
          
          // F1R1 (Filter bank 1 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f1r1; 
          
          // F1R2 (Filter bank 1 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f1r2; 
          
          // F2R1 (Filter bank 2 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f2r1; 
          
          // F2R2 (Filter bank 2 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f2r2; 
          
          // F3R1 (Filter bank 3 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f3r1; 
          
          // F3R2 (Filter bank 3 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f3r2; 
          
          // F4R1 (Filter bank 4 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f4r1; 
          
          // F4R2 (Filter bank 4 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f4r2; 
          
          // F5R1 (Filter bank 5 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f5r1; 
          
          // F5R2 (Filter bank 5 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f5r2; 
          
          // F6R1 (Filter bank 6 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f6r1; 
          
          // F6R2 (Filter bank 6 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f6r2; 
          
          // F7R1 (Filter bank 7 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f7r1; 
          
          // F7R2 (Filter bank 7 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f7r2; 
          
          // F8R1 (Filter bank 8 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f8r1; 
          
          // F8R2 (Filter bank 8 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f8r2; 
          
          // F9R1 (Filter bank 9 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f9r1; 
          
          // F9R2 (Filter bank 9 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f9r2; 
          
          // F10R1 (Filter bank 10 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f10r1; 
          
          // F10R2 (Filter bank 10 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f10r2; 
          
          // F11R1 (Filter bank 11 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f11r1; 
          
          // F11R2 (Filter bank 11 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f11r2; 
          
          // F12R1 (Filter bank 4 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f12r1; 
          
          // F12R2 (Filter bank 12 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f12r2; 
          
          // F13R1 (Filter bank 13 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f13r1; 
          
          // F13R2 (Filter bank 13 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f13r2; 
          
          // F14R1 (Filter bank 14 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f14r1; 
          
          // F14R2 (Filter bank 14 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f14r2; 
          
          // F15R1 (Filter bank 15 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f15r1; 
          
          // F15R2 (Filter bank 15 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f15r2; 
          
          // F16R1 (Filter bank 16 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f16r1; 
          
          // F16R2 (Filter bank 16 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f16r2; 
          
          // F17R1 (Filter bank 17 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f17r1; 
          
          // F17R2 (Filter bank 17 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f17r2; 
          
          // F18R1 (Filter bank 18 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f18r1; 
          
          // F18R2 (Filter bank 18 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f18r2; 
          
          // F19R1 (Filter bank 19 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f19r1; 
          
          // F19R2 (Filter bank 19 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f19r2; 
          
          // F20R1 (Filter bank 20 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f20r1; 
          
          // F20R2 (Filter bank 20 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f20r2; 
          
          // F21R1 (Filter bank 21 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f21r1; 
          
          // F21R2 (Filter bank 21 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f21r2; 
          
          // F22R1 (Filter bank 22 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f22r1; 
          
          // F22R2 (Filter bank 22 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f22r2; 
          
          // F23R1 (Filter bank 23 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f23r1; 
          
          // F23R2 (Filter bank 23 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f23r2; 
          
          // F24R1 (Filter bank 24 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f24r1; 
          
          // F24R2 (Filter bank 24 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f24r2; 
          
          // F25R1 (Filter bank 25 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f25r1; 
          
          // F25R2 (Filter bank 25 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f25r2; 
          
          // F26R1 (Filter bank 26 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f26r1; 
          
          // F26R2 (Filter bank 26 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f26r2; 
          
          // F27R1 (Filter bank 27 register 1) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f27r1; 
          
          // F27R2 (Filter bank 27 register 2) bitfields.
          struct { 
            Object *fb0; // [0:0] Filter bits 
            Object *fb1; // [1:1] Filter bits 
            Object *fb2; // [2:2] Filter bits 
            Object *fb3; // [3:3] Filter bits 
            Object *fb4; // [4:4] Filter bits 
            Object *fb5; // [5:5] Filter bits 
            Object *fb6; // [6:6] Filter bits 
            Object *fb7; // [7:7] Filter bits 
            Object *fb8; // [8:8] Filter bits 
            Object *fb9; // [9:9] Filter bits 
            Object *fb10; // [10:10] Filter bits 
            Object *fb11; // [11:11] Filter bits 
            Object *fb12; // [12:12] Filter bits 
            Object *fb13; // [13:13] Filter bits 
            Object *fb14; // [14:14] Filter bits 
            Object *fb15; // [15:15] Filter bits 
            Object *fb16; // [16:16] Filter bits 
            Object *fb17; // [17:17] Filter bits 
            Object *fb18; // [18:18] Filter bits 
            Object *fb19; // [19:19] Filter bits 
            Object *fb20; // [20:20] Filter bits 
            Object *fb21; // [21:21] Filter bits 
            Object *fb22; // [22:22] Filter bits 
            Object *fb23; // [23:23] Filter bits 
            Object *fb24; // [24:24] Filter bits 
            Object *fb25; // [25:25] Filter bits 
            Object *fb26; // [26:26] Filter bits 
            Object *fb27; // [27:27] Filter bits 
            Object *fb28; // [28:28] Filter bits 
            Object *fb29; // [29:29] Filter bits 
            Object *fb30; // [30:30] Filter bits 
            Object *fb31; // [31:31] Filter bits  
          } f27r2; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32CANState;

// ----------------------------------------------------------------------------

#endif /* STM32_CAN_H_ */
