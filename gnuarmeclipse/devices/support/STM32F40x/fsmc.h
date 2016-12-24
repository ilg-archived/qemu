/*
 * STM32 - FSMC (Flexible static memory controller) emulation.
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

#ifndef STM32_FSMC_H_
#define STM32_FSMC_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_FSMC DEVICE_PATH_STM32 "FSMC"



// ----------------------------------------------------------------------------

#define TYPE_STM32_FSMC TYPE_STM32_PREFIX "fsmc" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_FSMC_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32FSMCParentClass;
typedef PeripheralState STM32FSMCParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_FSMC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32FSMCClass, (obj), TYPE_STM32_FSMC)
#define STM32_FSMC_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32FSMCClass, (klass), TYPE_STM32_FSMC)

typedef struct {
    // private: 
    STM32FSMCParentClass parent_class;
    // public: 

    // None, so far.
} STM32FSMCClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_FSMC_STATE(obj) \
    OBJECT_CHECK(STM32FSMCState, (obj), TYPE_STM32_FSMC)

typedef struct {
    // private:
    STM32FSMCParentState parent_obj;
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
        // F4 FSMC (Flexible static memory controller) registers.
        struct { 
          Object *bcr1; // 0x0 (SRAM/NOR-Flash chip-select control register 1) 
          Object *btr1; // 0x4 (SRAM/NOR-Flash chip-select timing register 1) 
          Object *bcr2; // 0x8 (SRAM/NOR-Flash chip-select control register 2) 
          Object *btr2; // 0xC (SRAM/NOR-Flash chip-select timing register 2) 
          Object *bcr3; // 0x10 (SRAM/NOR-Flash chip-select control register 3) 
          Object *btr3; // 0x14 (SRAM/NOR-Flash chip-select timing register 3) 
          Object *bcr4; // 0x18 (SRAM/NOR-Flash chip-select control register 4) 
          Object *btr4; // 0x1C (SRAM/NOR-Flash chip-select timing register 4) 
          Object *pcr2; // 0x60 (PC Card/NAND Flash control register 2) 
          Object *sr2; // 0x64 (FIFO status and interrupt register 2) 
          Object *pmem2; // 0x68 (Common memory space timing register 2) 
          Object *patt2; // 0x6C (Attribute memory space timing register 2) 
          Object *eccr2; // 0x74 (ECC result register 2) 
          Object *pcr3; // 0x80 (PC Card/NAND Flash control register 3) 
          Object *sr3; // 0x84 (FIFO status and interrupt register 3) 
          Object *pmem3; // 0x88 (Common memory space timing register 3) 
          Object *patt3; // 0x8C (Attribute memory space timing register 3) 
          Object *eccr3; // 0x94 (ECC result register 3) 
          Object *pcr4; // 0xA0 (PC Card/NAND Flash control register 4) 
          Object *sr4; // 0xA4 (FIFO status and interrupt register 4) 
          Object *pmem4; // 0xA8 (Common memory space timing register 4) 
          Object *patt4; // 0xAC (Attribute memory space timing register 4) 
          Object *pio4; // 0xB0 (I/O space timing register 4) 
          Object *bwtr1; // 0x104 (SRAM/NOR-Flash write timing registers 1) 
          Object *bwtr2; // 0x10C (SRAM/NOR-Flash write timing registers 2) 
          Object *bwtr3; // 0x114 (SRAM/NOR-Flash write timing registers 3) 
          Object *bwtr4; // 0x11C (SRAM/NOR-Flash write timing registers 4) 
        } reg;

        struct { 
          
          // BCR1 (SRAM/NOR-Flash chip-select control register 1) bitfields.
          struct { 
            Object *mbken; // [0:0] MBKEN 
            Object *muxen; // [1:1] MUXEN 
            Object *mtyp; // [2:3] MTYP 
            Object *mwid; // [4:5] MWID 
            Object *faccen; // [6:6] FACCEN 
            Object *bursten; // [8:8] BURSTEN 
            Object *waitpol; // [9:9] WAITPOL 
            Object *waitcfg; // [11:11] WAITCFG 
            Object *wren; // [12:12] WREN 
            Object *waiten; // [13:13] WAITEN 
            Object *extmod; // [14:14] EXTMOD 
            Object *asyncwait; // [15:15] ASYNCWAIT 
            Object *cburstrw; // [19:19] CBURSTRW  
          } bcr1; 
          
          // BTR1 (SRAM/NOR-Flash chip-select timing register 1) bitfields.
          struct { 
            Object *addset; // [0:3] ADDSET 
            Object *addhld; // [4:7] ADDHLD 
            Object *datast; // [8:15] DATAST 
            Object *busturn; // [16:19] BUSTURN 
            Object *clkdiv; // [20:23] CLKDIV 
            Object *datlat; // [24:27] DATLAT 
            Object *accmod; // [28:29] ACCMOD  
          } btr1; 
          
          // BCR2 (SRAM/NOR-Flash chip-select control register 2) bitfields.
          struct { 
            Object *mbken; // [0:0] MBKEN 
            Object *muxen; // [1:1] MUXEN 
            Object *mtyp; // [2:3] MTYP 
            Object *mwid; // [4:5] MWID 
            Object *faccen; // [6:6] FACCEN 
            Object *bursten; // [8:8] BURSTEN 
            Object *waitpol; // [9:9] WAITPOL 
            Object *wrapmod; // [10:10] WRAPMOD 
            Object *waitcfg; // [11:11] WAITCFG 
            Object *wren; // [12:12] WREN 
            Object *waiten; // [13:13] WAITEN 
            Object *extmod; // [14:14] EXTMOD 
            Object *asyncwait; // [15:15] ASYNCWAIT 
            Object *cburstrw; // [19:19] CBURSTRW  
          } bcr2; 
          
          // BTR2 (SRAM/NOR-Flash chip-select timing register 2) bitfields.
          struct { 
            Object *addset; // [0:3] ADDSET 
            Object *addhld; // [4:7] ADDHLD 
            Object *datast; // [8:15] DATAST 
            Object *busturn; // [16:19] BUSTURN 
            Object *clkdiv; // [20:23] CLKDIV 
            Object *datlat; // [24:27] DATLAT 
            Object *accmod; // [28:29] ACCMOD  
          } btr2; 
          
          // BCR3 (SRAM/NOR-Flash chip-select control register 3) bitfields.
          struct { 
            Object *mbken; // [0:0] MBKEN 
            Object *muxen; // [1:1] MUXEN 
            Object *mtyp; // [2:3] MTYP 
            Object *mwid; // [4:5] MWID 
            Object *faccen; // [6:6] FACCEN 
            Object *bursten; // [8:8] BURSTEN 
            Object *waitpol; // [9:9] WAITPOL 
            Object *wrapmod; // [10:10] WRAPMOD 
            Object *waitcfg; // [11:11] WAITCFG 
            Object *wren; // [12:12] WREN 
            Object *waiten; // [13:13] WAITEN 
            Object *extmod; // [14:14] EXTMOD 
            Object *asyncwait; // [15:15] ASYNCWAIT 
            Object *cburstrw; // [19:19] CBURSTRW  
          } bcr3; 
          
          // BTR3 (SRAM/NOR-Flash chip-select timing register 3) bitfields.
          struct { 
            Object *addset; // [0:3] ADDSET 
            Object *addhld; // [4:7] ADDHLD 
            Object *datast; // [8:15] DATAST 
            Object *busturn; // [16:19] BUSTURN 
            Object *clkdiv; // [20:23] CLKDIV 
            Object *datlat; // [24:27] DATLAT 
            Object *accmod; // [28:29] ACCMOD  
          } btr3; 
          
          // BCR4 (SRAM/NOR-Flash chip-select control register 4) bitfields.
          struct { 
            Object *mbken; // [0:0] MBKEN 
            Object *muxen; // [1:1] MUXEN 
            Object *mtyp; // [2:3] MTYP 
            Object *mwid; // [4:5] MWID 
            Object *faccen; // [6:6] FACCEN 
            Object *bursten; // [8:8] BURSTEN 
            Object *waitpol; // [9:9] WAITPOL 
            Object *wrapmod; // [10:10] WRAPMOD 
            Object *waitcfg; // [11:11] WAITCFG 
            Object *wren; // [12:12] WREN 
            Object *waiten; // [13:13] WAITEN 
            Object *extmod; // [14:14] EXTMOD 
            Object *asyncwait; // [15:15] ASYNCWAIT 
            Object *cburstrw; // [19:19] CBURSTRW  
          } bcr4; 
          
          // BTR4 (SRAM/NOR-Flash chip-select timing register 4) bitfields.
          struct { 
            Object *addset; // [0:3] ADDSET 
            Object *addhld; // [4:7] ADDHLD 
            Object *datast; // [8:15] DATAST 
            Object *busturn; // [16:19] BUSTURN 
            Object *clkdiv; // [20:23] CLKDIV 
            Object *datlat; // [24:27] DATLAT 
            Object *accmod; // [28:29] ACCMOD  
          } btr4; 
          
          // PCR2 (PC Card/NAND Flash control register 2) bitfields.
          struct { 
            Object *pwaiten; // [1:1] PWAITEN 
            Object *pbken; // [2:2] PBKEN 
            Object *ptyp; // [3:3] PTYP 
            Object *pwid; // [4:5] PWID 
            Object *eccen; // [6:6] ECCEN 
            Object *tclr; // [9:12] TCLR 
            Object *tar; // [13:16] TAR 
            Object *eccps; // [17:19] ECCPS  
          } pcr2; 
          
          // SR2 (FIFO status and interrupt register 2) bitfields.
          struct { 
            Object *irs; // [0:0] IRS 
            Object *ils; // [1:1] ILS 
            Object *ifs; // [2:2] IFS 
            Object *iren; // [3:3] IREN 
            Object *ilen; // [4:4] ILEN 
            Object *ifen; // [5:5] IFEN 
            Object *fempt; // [6:6] FEMPT  
          } sr2; 
          
          // PMEM2 (Common memory space timing register 2) bitfields.
          struct { 
            Object *memsetx; // [0:7] MEMSETx 
            Object *memwaitx; // [8:15] MEMWAITx 
            Object *memholdx; // [16:23] MEMHOLDx 
            Object *memhizx; // [24:31] MEMHIZx  
          } pmem2; 
          
          // PATT2 (Attribute memory space timing register 2) bitfields.
          struct { 
            Object *attsetx; // [0:7] ATTSETx 
            Object *attwaitx; // [8:15] ATTWAITx 
            Object *attholdx; // [16:23] ATTHOLDx 
            Object *atthizx; // [24:31] ATTHIZx  
          } patt2; 
          
          // ECCR2 (ECC result register 2) bitfields.
          struct { 
            Object *eccx; // [0:31] ECCx  
          } eccr2; 
          
          // PCR3 (PC Card/NAND Flash control register 3) bitfields.
          struct { 
            Object *pwaiten; // [1:1] PWAITEN 
            Object *pbken; // [2:2] PBKEN 
            Object *ptyp; // [3:3] PTYP 
            Object *pwid; // [4:5] PWID 
            Object *eccen; // [6:6] ECCEN 
            Object *tclr; // [9:12] TCLR 
            Object *tar; // [13:16] TAR 
            Object *eccps; // [17:19] ECCPS  
          } pcr3; 
          
          // SR3 (FIFO status and interrupt register 3) bitfields.
          struct { 
            Object *irs; // [0:0] IRS 
            Object *ils; // [1:1] ILS 
            Object *ifs; // [2:2] IFS 
            Object *iren; // [3:3] IREN 
            Object *ilen; // [4:4] ILEN 
            Object *ifen; // [5:5] IFEN 
            Object *fempt; // [6:6] FEMPT  
          } sr3; 
          
          // PMEM3 (Common memory space timing register 3) bitfields.
          struct { 
            Object *memsetx; // [0:7] MEMSETx 
            Object *memwaitx; // [8:15] MEMWAITx 
            Object *memholdx; // [16:23] MEMHOLDx 
            Object *memhizx; // [24:31] MEMHIZx  
          } pmem3; 
          
          // PATT3 (Attribute memory space timing register 3) bitfields.
          struct { 
            Object *attsetx; // [0:7] ATTSETx 
            Object *attwaitx; // [8:15] ATTWAITx 
            Object *attholdx; // [16:23] ATTHOLDx 
            Object *atthizx; // [24:31] ATTHIZx  
          } patt3; 
          
          // ECCR3 (ECC result register 3) bitfields.
          struct { 
            Object *eccx; // [0:31] ECCx  
          } eccr3; 
          
          // PCR4 (PC Card/NAND Flash control register 4) bitfields.
          struct { 
            Object *pwaiten; // [1:1] PWAITEN 
            Object *pbken; // [2:2] PBKEN 
            Object *ptyp; // [3:3] PTYP 
            Object *pwid; // [4:5] PWID 
            Object *eccen; // [6:6] ECCEN 
            Object *tclr; // [9:12] TCLR 
            Object *tar; // [13:16] TAR 
            Object *eccps; // [17:19] ECCPS  
          } pcr4; 
          
          // SR4 (FIFO status and interrupt register 4) bitfields.
          struct { 
            Object *irs; // [0:0] IRS 
            Object *ils; // [1:1] ILS 
            Object *ifs; // [2:2] IFS 
            Object *iren; // [3:3] IREN 
            Object *ilen; // [4:4] ILEN 
            Object *ifen; // [5:5] IFEN 
            Object *fempt; // [6:6] FEMPT  
          } sr4; 
          
          // PMEM4 (Common memory space timing register 4) bitfields.
          struct { 
            Object *memsetx; // [0:7] MEMSETx 
            Object *memwaitx; // [8:15] MEMWAITx 
            Object *memholdx; // [16:23] MEMHOLDx 
            Object *memhizx; // [24:31] MEMHIZx  
          } pmem4; 
          
          // PATT4 (Attribute memory space timing register 4) bitfields.
          struct { 
            Object *attsetx; // [0:7] ATTSETx 
            Object *attwaitx; // [8:15] ATTWAITx 
            Object *attholdx; // [16:23] ATTHOLDx 
            Object *atthizx; // [24:31] ATTHIZx  
          } patt4; 
          
          // PIO4 (I/O space timing register 4) bitfields.
          struct { 
            Object *iosetx; // [0:7] IOSETx 
            Object *iowaitx; // [8:15] IOWAITx 
            Object *ioholdx; // [16:23] IOHOLDx 
            Object *iohizx; // [24:31] IOHIZx  
          } pio4; 
          
          // BWTR1 (SRAM/NOR-Flash write timing registers 1) bitfields.
          struct { 
            Object *addset; // [0:3] ADDSET 
            Object *addhld; // [4:7] ADDHLD 
            Object *datast; // [8:15] DATAST 
            Object *clkdiv; // [20:23] CLKDIV 
            Object *datlat; // [24:27] DATLAT 
            Object *accmod; // [28:29] ACCMOD  
          } bwtr1; 
          
          // BWTR2 (SRAM/NOR-Flash write timing registers 2) bitfields.
          struct { 
            Object *addset; // [0:3] ADDSET 
            Object *addhld; // [4:7] ADDHLD 
            Object *datast; // [8:15] DATAST 
            Object *clkdiv; // [20:23] CLKDIV 
            Object *datlat; // [24:27] DATLAT 
            Object *accmod; // [28:29] ACCMOD  
          } bwtr2; 
          
          // BWTR3 (SRAM/NOR-Flash write timing registers 3) bitfields.
          struct { 
            Object *addset; // [0:3] ADDSET 
            Object *addhld; // [4:7] ADDHLD 
            Object *datast; // [8:15] DATAST 
            Object *clkdiv; // [20:23] CLKDIV 
            Object *datlat; // [24:27] DATLAT 
            Object *accmod; // [28:29] ACCMOD  
          } bwtr3; 
          
          // BWTR4 (SRAM/NOR-Flash write timing registers 4) bitfields.
          struct { 
            Object *addset; // [0:3] ADDSET 
            Object *addhld; // [4:7] ADDHLD 
            Object *datast; // [8:15] DATAST 
            Object *clkdiv; // [20:23] CLKDIV 
            Object *datlat; // [24:27] DATLAT 
            Object *accmod; // [28:29] ACCMOD  
          } bwtr4; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32FSMCState;

// ----------------------------------------------------------------------------

#endif /* STM32_FSMC_H_ */
