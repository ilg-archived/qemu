/*
 * STM32 - DMA (DMA controller) emulation.
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

#ifndef STM32_DMA_H_
#define STM32_DMA_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_DMA DEVICE_PATH_STM32 "DMA"

// ----------------------------------------------------------------------------

// Note: the "port-index" property has type "int".
typedef enum {
    // TODO: keep this list in ascending order.
    STM32_PORT_DMA1,
    STM32_PORT_DMA2,
    STM32_PORT_DMA_UNDEFINED = 0xFF,
} stm32_dma_index_t;

// ----------------------------------------------------------------------------

#define TYPE_STM32_DMA TYPE_STM32_PREFIX "dma" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_DMA_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32DMAParentClass;
typedef PeripheralState STM32DMAParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_DMA_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32DMAClass, (obj), TYPE_STM32_DMA)
#define STM32_DMA_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32DMAClass, (klass), TYPE_STM32_DMA)

typedef struct {
    // private: 
    STM32DMAParentClass parent_class;
    // public: 

    // None, so far.
} STM32DMAClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_DMA_STATE(obj) \
    OBJECT_CHECK(STM32DMAState, (obj), TYPE_STM32_DMA)

typedef struct {
    // private:
    STM32DMAParentState parent_obj;
    // public:

    const STM32Capabilities *capabilities;

    // TODO: remove this if the peripheral is always enabled.
    // Points to the bitfield that enables the peripheral.
    Object *enabling_bit;

    // Remove it if there is only one port
    stm32_dma_index_t port_index;

    union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // F4 DMA (DMA controller) registers.
        struct { 
          Object *lisr; // 0x0 (Low interrupt status register) 
          Object *hisr; // 0x4 (High interrupt status register) 
          Object *lifcr; // 0x8 (Low interrupt flag clear register) 
          Object *hifcr; // 0xC (High interrupt flag clear register) 
          Object *s0cr; // 0x10 (Stream x configuration register) 
          Object *s0ndtr; // 0x14 (Stream x number of data register) 
          Object *s0par; // 0x18 (Stream x peripheral address register) 
          Object *s0m0ar; // 0x1C (Stream x memory 0 address register) 
          Object *s0m1ar; // 0x20 (Stream x memory 1 address register) 
          Object *s0fcr; // 0x24 (Stream x FIFO control register) 
          Object *s1cr; // 0x28 (Stream x configuration register) 
          Object *s1ndtr; // 0x2C (Stream x number of data register) 
          Object *s1par; // 0x30 (Stream x peripheral address register) 
          Object *s1m0ar; // 0x34 (Stream x memory 0 address register) 
          Object *s1m1ar; // 0x38 (Stream x memory 1 address register) 
          Object *s1fcr; // 0x3C (Stream x FIFO control register) 
          Object *s2cr; // 0x40 (Stream x configuration register) 
          Object *s2ndtr; // 0x44 (Stream x number of data register) 
          Object *s2par; // 0x48 (Stream x peripheral address register) 
          Object *s2m0ar; // 0x4C (Stream x memory 0 address register) 
          Object *s2m1ar; // 0x50 (Stream x memory 1 address register) 
          Object *s2fcr; // 0x54 (Stream x FIFO control register) 
          Object *s3cr; // 0x58 (Stream x configuration register) 
          Object *s3ndtr; // 0x5C (Stream x number of data register) 
          Object *s3par; // 0x60 (Stream x peripheral address register) 
          Object *s3m0ar; // 0x64 (Stream x memory 0 address register) 
          Object *s3m1ar; // 0x68 (Stream x memory 1 address register) 
          Object *s3fcr; // 0x6C (Stream x FIFO control register) 
          Object *s4cr; // 0x70 (Stream x configuration register) 
          Object *s4ndtr; // 0x74 (Stream x number of data register) 
          Object *s4par; // 0x78 (Stream x peripheral address register) 
          Object *s4m0ar; // 0x7C (Stream x memory 0 address register) 
          Object *s4m1ar; // 0x80 (Stream x memory 1 address register) 
          Object *s4fcr; // 0x84 (Stream x FIFO control register) 
          Object *s5cr; // 0x88 (Stream x configuration register) 
          Object *s5ndtr; // 0x8C (Stream x number of data register) 
          Object *s5par; // 0x90 (Stream x peripheral address register) 
          Object *s5m0ar; // 0x94 (Stream x memory 0 address register) 
          Object *s5m1ar; // 0x98 (Stream x memory 1 address register) 
          Object *s5fcr; // 0x9C (Stream x FIFO control register) 
          Object *s6cr; // 0xA0 (Stream x configuration register) 
          Object *s6ndtr; // 0xA4 (Stream x number of data register) 
          Object *s6par; // 0xA8 (Stream x peripheral address register) 
          Object *s6m0ar; // 0xAC (Stream x memory 0 address register) 
          Object *s6m1ar; // 0xB0 (Stream x memory 1 address register) 
          Object *s6fcr; // 0xB4 (Stream x FIFO control register) 
          Object *s7cr; // 0xB8 (Stream x configuration register) 
          Object *s7ndtr; // 0xBC (Stream x number of data register) 
          Object *s7par; // 0xC0 (Stream x peripheral address register) 
          Object *s7m0ar; // 0xC4 (Stream x memory 0 address register) 
          Object *s7m1ar; // 0xC8 (Stream x memory 1 address register) 
          Object *s7fcr; // 0xCC (Stream x FIFO control register) 
        } reg;

        struct { 
          
          // LISR (Low interrupt status register) bitfields.
          struct { 
            Object *feif0; // [0:0] Stream x FIFO error interrupt flag (x=3..0) 
            Object *dmeif0; // [2:2] Stream x direct mode error interrupt flag (x=3..0) 
            Object *teif0; // [3:3] Stream x transfer error interrupt flag (x=3..0) 
            Object *htif0; // [4:4] Stream x half transfer interrupt flag (x=3..0) 
            Object *tcif0; // [5:5] Stream x transfer complete interrupt flag (x = 3..0) 
            Object *feif1; // [6:6] Stream x FIFO error interrupt flag (x=3..0) 
            Object *dmeif1; // [8:8] Stream x direct mode error interrupt flag (x=3..0) 
            Object *teif1; // [9:9] Stream x transfer error interrupt flag (x=3..0) 
            Object *htif1; // [10:10] Stream x half transfer interrupt flag (x=3..0) 
            Object *tcif1; // [11:11] Stream x transfer complete interrupt flag (x = 3..0) 
            Object *feif2; // [16:16] Stream x FIFO error interrupt flag (x=3..0) 
            Object *dmeif2; // [18:18] Stream x direct mode error interrupt flag (x=3..0) 
            Object *teif2; // [19:19] Stream x transfer error interrupt flag (x=3..0) 
            Object *htif2; // [20:20] Stream x half transfer interrupt flag (x=3..0) 
            Object *tcif2; // [21:21] Stream x transfer complete interrupt flag (x = 3..0) 
            Object *feif3; // [22:22] Stream x FIFO error interrupt flag (x=3..0) 
            Object *dmeif3; // [24:24] Stream x direct mode error interrupt flag (x=3..0) 
            Object *teif3; // [25:25] Stream x transfer error interrupt flag (x=3..0) 
            Object *htif3; // [26:26] Stream x half transfer interrupt flag (x=3..0) 
            Object *tcif3; // [27:27] Stream x transfer complete interrupt flag (x = 3..0)  
          } lisr; 
          
          // HISR (High interrupt status register) bitfields.
          struct { 
            Object *feif4; // [0:0] Stream x FIFO error interrupt flag (x=7..4) 
            Object *dmeif4; // [2:2] Stream x direct mode error interrupt flag (x=7..4) 
            Object *teif4; // [3:3] Stream x transfer error interrupt flag (x=7..4) 
            Object *htif4; // [4:4] Stream x half transfer interrupt flag (x=7..4) 
            Object *tcif4; // [5:5] Stream x transfer complete interrupt flag (x=7..4) 
            Object *feif5; // [6:6] Stream x FIFO error interrupt flag (x=7..4) 
            Object *dmeif5; // [8:8] Stream x direct mode error interrupt flag (x=7..4) 
            Object *teif5; // [9:9] Stream x transfer error interrupt flag (x=7..4) 
            Object *htif5; // [10:10] Stream x half transfer interrupt flag (x=7..4) 
            Object *tcif5; // [11:11] Stream x transfer complete interrupt flag (x=7..4) 
            Object *feif6; // [16:16] Stream x FIFO error interrupt flag (x=7..4) 
            Object *dmeif6; // [18:18] Stream x direct mode error interrupt flag (x=7..4) 
            Object *teif6; // [19:19] Stream x transfer error interrupt flag (x=7..4) 
            Object *htif6; // [20:20] Stream x half transfer interrupt flag (x=7..4) 
            Object *tcif6; // [21:21] Stream x transfer complete interrupt flag (x=7..4) 
            Object *feif7; // [22:22] Stream x FIFO error interrupt flag (x=7..4) 
            Object *dmeif7; // [24:24] Stream x direct mode error interrupt flag (x=7..4) 
            Object *teif7; // [25:25] Stream x transfer error interrupt flag (x=7..4) 
            Object *htif7; // [26:26] Stream x half transfer interrupt flag (x=7..4) 
            Object *tcif7; // [27:27] Stream x transfer complete interrupt flag (x=7..4)  
          } hisr; 
          
          // LIFCR (Low interrupt flag clear register) bitfields.
          struct { 
            Object *cfeif0; // [0:0] Stream x clear FIFO error interrupt flag (x = 3..0) 
            Object *cdmeif0; // [2:2] Stream x clear direct mode error interrupt flag (x = 3..0) 
            Object *cteif0; // [3:3] Stream x clear transfer error interrupt flag (x = 3..0) 
            Object *chtif0; // [4:4] Stream x clear half transfer interrupt flag (x = 3..0) 
            Object *ctcif0; // [5:5] Stream x clear transfer complete interrupt flag (x = 3..0) 
            Object *cfeif1; // [6:6] Stream x clear FIFO error interrupt flag (x = 3..0) 
            Object *cdmeif1; // [8:8] Stream x clear direct mode error interrupt flag (x = 3..0) 
            Object *cteif1; // [9:9] Stream x clear transfer error interrupt flag (x = 3..0) 
            Object *chtif1; // [10:10] Stream x clear half transfer interrupt flag (x = 3..0) 
            Object *ctcif1; // [11:11] Stream x clear transfer complete interrupt flag (x = 3..0) 
            Object *cfeif2; // [16:16] Stream x clear FIFO error interrupt flag (x = 3..0) 
            Object *cdmeif2; // [18:18] Stream x clear direct mode error interrupt flag (x = 3..0) 
            Object *cteif2; // [19:19] Stream x clear transfer error interrupt flag (x = 3..0) 
            Object *chtif2; // [20:20] Stream x clear half transfer interrupt flag (x = 3..0) 
            Object *ctcif2; // [21:21] Stream x clear transfer complete interrupt flag (x = 3..0) 
            Object *cfeif3; // [22:22] Stream x clear FIFO error interrupt flag (x = 3..0) 
            Object *cdmeif3; // [24:24] Stream x clear direct mode error interrupt flag (x = 3..0) 
            Object *cteif3; // [25:25] Stream x clear transfer error interrupt flag (x = 3..0) 
            Object *chtif3; // [26:26] Stream x clear half transfer interrupt flag (x = 3..0) 
            Object *ctcif3; // [27:27] Stream x clear transfer complete interrupt flag (x = 3..0)  
          } lifcr; 
          
          // HIFCR (High interrupt flag clear register) bitfields.
          struct { 
            Object *cfeif4; // [0:0] Stream x clear FIFO error interrupt flag (x = 7..4) 
            Object *cdmeif4; // [2:2] Stream x clear direct mode error interrupt flag (x = 7..4) 
            Object *cteif4; // [3:3] Stream x clear transfer error interrupt flag (x = 7..4) 
            Object *chtif4; // [4:4] Stream x clear half transfer interrupt flag (x = 7..4) 
            Object *ctcif4; // [5:5] Stream x clear transfer complete interrupt flag (x = 7..4) 
            Object *cfeif5; // [6:6] Stream x clear FIFO error interrupt flag (x = 7..4) 
            Object *cdmeif5; // [8:8] Stream x clear direct mode error interrupt flag (x = 7..4) 
            Object *cteif5; // [9:9] Stream x clear transfer error interrupt flag (x = 7..4) 
            Object *chtif5; // [10:10] Stream x clear half transfer interrupt flag (x = 7..4) 
            Object *ctcif5; // [11:11] Stream x clear transfer complete interrupt flag (x = 7..4) 
            Object *cfeif6; // [16:16] Stream x clear FIFO error interrupt flag (x = 7..4) 
            Object *cdmeif6; // [18:18] Stream x clear direct mode error interrupt flag (x = 7..4) 
            Object *cteif6; // [19:19] Stream x clear transfer error interrupt flag (x = 7..4) 
            Object *chtif6; // [20:20] Stream x clear half transfer interrupt flag (x = 7..4) 
            Object *ctcif6; // [21:21] Stream x clear transfer complete interrupt flag (x = 7..4) 
            Object *cfeif7; // [22:22] Stream x clear FIFO error interrupt flag (x = 7..4) 
            Object *cdmeif7; // [24:24] Stream x clear direct mode error interrupt flag (x = 7..4) 
            Object *cteif7; // [25:25] Stream x clear transfer error interrupt flag (x = 7..4) 
            Object *chtif7; // [26:26] Stream x clear half transfer interrupt flag (x = 7..4) 
            Object *ctcif7; // [27:27] Stream x clear transfer complete interrupt flag (x = 7..4)  
          } hifcr; 
          
          // S0CR (Stream x configuration register) bitfields.
          struct { 
            Object *en; // [0:0] Stream enable / flag stream ready when read low 
            Object *dmeie; // [1:1] Direct mode error interrupt enable 
            Object *teie; // [2:2] Transfer error interrupt enable 
            Object *htie; // [3:3] Half transfer interrupt enable 
            Object *tcie; // [4:4] Transfer complete interrupt enable 
            Object *pfctrl; // [5:5] Peripheral flow controller 
            Object *dir; // [6:7] Data transfer direction 
            Object *circ; // [8:8] Circular mode 
            Object *pinc; // [9:9] Peripheral increment mode 
            Object *minc; // [10:10] Memory increment mode 
            Object *psize; // [11:12] Peripheral data size 
            Object *msize; // [13:14] Memory data size 
            Object *pincos; // [15:15] Peripheral increment offset size 
            Object *pl; // [16:17] Priority level 
            Object *dbm; // [18:18] Double buffer mode 
            Object *ct; // [19:19] Current target (only in double buffer mode) 
            Object *pburst; // [21:22] Peripheral burst transfer configuration 
            Object *mburst; // [23:24] Memory burst transfer configuration 
            Object *chsel; // [25:27] Channel selection  
          } s0cr; 
          
          // S0NDTR (Stream x number of data register) bitfields.
          struct { 
            Object *ndt; // [0:15] Number of data items to transfer  
          } s0ndtr; 
          
          // S0PAR (Stream x peripheral address register) bitfields.
          struct { 
            Object *pa; // [0:31] Peripheral address  
          } s0par; 
          
          // S0M0AR (Stream x memory 0 address register) bitfields.
          struct { 
            Object *m0a; // [0:31] Memory 0 address  
          } s0m0ar; 
          
          // S0M1AR (Stream x memory 1 address register) bitfields.
          struct { 
            Object *m1a; // [0:31] Memory 1 address (used in case of Double buffer mode)  
          } s0m1ar; 
          
          // S0FCR (Stream x FIFO control register) bitfields.
          struct { 
            Object *fth; // [0:1] FIFO threshold selection 
            Object *dmdis; // [2:2] Direct mode disable 
            Object *fs; // [3:5] FIFO status 
            Object *feie; // [7:7] FIFO error interrupt enable  
          } s0fcr; 
          
          // S1CR (Stream x configuration register) bitfields.
          struct { 
            Object *en; // [0:0] Stream enable / flag stream ready when read low 
            Object *dmeie; // [1:1] Direct mode error interrupt enable 
            Object *teie; // [2:2] Transfer error interrupt enable 
            Object *htie; // [3:3] Half transfer interrupt enable 
            Object *tcie; // [4:4] Transfer complete interrupt enable 
            Object *pfctrl; // [5:5] Peripheral flow controller 
            Object *dir; // [6:7] Data transfer direction 
            Object *circ; // [8:8] Circular mode 
            Object *pinc; // [9:9] Peripheral increment mode 
            Object *minc; // [10:10] Memory increment mode 
            Object *psize; // [11:12] Peripheral data size 
            Object *msize; // [13:14] Memory data size 
            Object *pincos; // [15:15] Peripheral increment offset size 
            Object *pl; // [16:17] Priority level 
            Object *dbm; // [18:18] Double buffer mode 
            Object *ct; // [19:19] Current target (only in double buffer mode) 
            Object *ack; // [20:20] ACK 
            Object *pburst; // [21:22] Peripheral burst transfer configuration 
            Object *mburst; // [23:24] Memory burst transfer configuration 
            Object *chsel; // [25:27] Channel selection  
          } s1cr; 
          
          // S1NDTR (Stream x number of data register) bitfields.
          struct { 
            Object *ndt; // [0:15] Number of data items to transfer  
          } s1ndtr; 
          
          // S1PAR (Stream x peripheral address register) bitfields.
          struct { 
            Object *pa; // [0:31] Peripheral address  
          } s1par; 
          
          // S1M0AR (Stream x memory 0 address register) bitfields.
          struct { 
            Object *m0a; // [0:31] Memory 0 address  
          } s1m0ar; 
          
          // S1M1AR (Stream x memory 1 address register) bitfields.
          struct { 
            Object *m1a; // [0:31] Memory 1 address (used in case of Double buffer mode)  
          } s1m1ar; 
          
          // S1FCR (Stream x FIFO control register) bitfields.
          struct { 
            Object *fth; // [0:1] FIFO threshold selection 
            Object *dmdis; // [2:2] Direct mode disable 
            Object *fs; // [3:5] FIFO status 
            Object *feie; // [7:7] FIFO error interrupt enable  
          } s1fcr; 
          
          // S2CR (Stream x configuration register) bitfields.
          struct { 
            Object *en; // [0:0] Stream enable / flag stream ready when read low 
            Object *dmeie; // [1:1] Direct mode error interrupt enable 
            Object *teie; // [2:2] Transfer error interrupt enable 
            Object *htie; // [3:3] Half transfer interrupt enable 
            Object *tcie; // [4:4] Transfer complete interrupt enable 
            Object *pfctrl; // [5:5] Peripheral flow controller 
            Object *dir; // [6:7] Data transfer direction 
            Object *circ; // [8:8] Circular mode 
            Object *pinc; // [9:9] Peripheral increment mode 
            Object *minc; // [10:10] Memory increment mode 
            Object *psize; // [11:12] Peripheral data size 
            Object *msize; // [13:14] Memory data size 
            Object *pincos; // [15:15] Peripheral increment offset size 
            Object *pl; // [16:17] Priority level 
            Object *dbm; // [18:18] Double buffer mode 
            Object *ct; // [19:19] Current target (only in double buffer mode) 
            Object *ack; // [20:20] ACK 
            Object *pburst; // [21:22] Peripheral burst transfer configuration 
            Object *mburst; // [23:24] Memory burst transfer configuration 
            Object *chsel; // [25:27] Channel selection  
          } s2cr; 
          
          // S2NDTR (Stream x number of data register) bitfields.
          struct { 
            Object *ndt; // [0:15] Number of data items to transfer  
          } s2ndtr; 
          
          // S2PAR (Stream x peripheral address register) bitfields.
          struct { 
            Object *pa; // [0:31] Peripheral address  
          } s2par; 
          
          // S2M0AR (Stream x memory 0 address register) bitfields.
          struct { 
            Object *m0a; // [0:31] Memory 0 address  
          } s2m0ar; 
          
          // S2M1AR (Stream x memory 1 address register) bitfields.
          struct { 
            Object *m1a; // [0:31] Memory 1 address (used in case of Double buffer mode)  
          } s2m1ar; 
          
          // S2FCR (Stream x FIFO control register) bitfields.
          struct { 
            Object *fth; // [0:1] FIFO threshold selection 
            Object *dmdis; // [2:2] Direct mode disable 
            Object *fs; // [3:5] FIFO status 
            Object *feie; // [7:7] FIFO error interrupt enable  
          } s2fcr; 
          
          // S3CR (Stream x configuration register) bitfields.
          struct { 
            Object *en; // [0:0] Stream enable / flag stream ready when read low 
            Object *dmeie; // [1:1] Direct mode error interrupt enable 
            Object *teie; // [2:2] Transfer error interrupt enable 
            Object *htie; // [3:3] Half transfer interrupt enable 
            Object *tcie; // [4:4] Transfer complete interrupt enable 
            Object *pfctrl; // [5:5] Peripheral flow controller 
            Object *dir; // [6:7] Data transfer direction 
            Object *circ; // [8:8] Circular mode 
            Object *pinc; // [9:9] Peripheral increment mode 
            Object *minc; // [10:10] Memory increment mode 
            Object *psize; // [11:12] Peripheral data size 
            Object *msize; // [13:14] Memory data size 
            Object *pincos; // [15:15] Peripheral increment offset size 
            Object *pl; // [16:17] Priority level 
            Object *dbm; // [18:18] Double buffer mode 
            Object *ct; // [19:19] Current target (only in double buffer mode) 
            Object *ack; // [20:20] ACK 
            Object *pburst; // [21:22] Peripheral burst transfer configuration 
            Object *mburst; // [23:24] Memory burst transfer configuration 
            Object *chsel; // [25:27] Channel selection  
          } s3cr; 
          
          // S3NDTR (Stream x number of data register) bitfields.
          struct { 
            Object *ndt; // [0:15] Number of data items to transfer  
          } s3ndtr; 
          
          // S3PAR (Stream x peripheral address register) bitfields.
          struct { 
            Object *pa; // [0:31] Peripheral address  
          } s3par; 
          
          // S3M0AR (Stream x memory 0 address register) bitfields.
          struct { 
            Object *m0a; // [0:31] Memory 0 address  
          } s3m0ar; 
          
          // S3M1AR (Stream x memory 1 address register) bitfields.
          struct { 
            Object *m1a; // [0:31] Memory 1 address (used in case of Double buffer mode)  
          } s3m1ar; 
          
          // S3FCR (Stream x FIFO control register) bitfields.
          struct { 
            Object *fth; // [0:1] FIFO threshold selection 
            Object *dmdis; // [2:2] Direct mode disable 
            Object *fs; // [3:5] FIFO status 
            Object *feie; // [7:7] FIFO error interrupt enable  
          } s3fcr; 
          
          // S4CR (Stream x configuration register) bitfields.
          struct { 
            Object *en; // [0:0] Stream enable / flag stream ready when read low 
            Object *dmeie; // [1:1] Direct mode error interrupt enable 
            Object *teie; // [2:2] Transfer error interrupt enable 
            Object *htie; // [3:3] Half transfer interrupt enable 
            Object *tcie; // [4:4] Transfer complete interrupt enable 
            Object *pfctrl; // [5:5] Peripheral flow controller 
            Object *dir; // [6:7] Data transfer direction 
            Object *circ; // [8:8] Circular mode 
            Object *pinc; // [9:9] Peripheral increment mode 
            Object *minc; // [10:10] Memory increment mode 
            Object *psize; // [11:12] Peripheral data size 
            Object *msize; // [13:14] Memory data size 
            Object *pincos; // [15:15] Peripheral increment offset size 
            Object *pl; // [16:17] Priority level 
            Object *dbm; // [18:18] Double buffer mode 
            Object *ct; // [19:19] Current target (only in double buffer mode) 
            Object *ack; // [20:20] ACK 
            Object *pburst; // [21:22] Peripheral burst transfer configuration 
            Object *mburst; // [23:24] Memory burst transfer configuration 
            Object *chsel; // [25:27] Channel selection  
          } s4cr; 
          
          // S4NDTR (Stream x number of data register) bitfields.
          struct { 
            Object *ndt; // [0:15] Number of data items to transfer  
          } s4ndtr; 
          
          // S4PAR (Stream x peripheral address register) bitfields.
          struct { 
            Object *pa; // [0:31] Peripheral address  
          } s4par; 
          
          // S4M0AR (Stream x memory 0 address register) bitfields.
          struct { 
            Object *m0a; // [0:31] Memory 0 address  
          } s4m0ar; 
          
          // S4M1AR (Stream x memory 1 address register) bitfields.
          struct { 
            Object *m1a; // [0:31] Memory 1 address (used in case of Double buffer mode)  
          } s4m1ar; 
          
          // S4FCR (Stream x FIFO control register) bitfields.
          struct { 
            Object *fth; // [0:1] FIFO threshold selection 
            Object *dmdis; // [2:2] Direct mode disable 
            Object *fs; // [3:5] FIFO status 
            Object *feie; // [7:7] FIFO error interrupt enable  
          } s4fcr; 
          
          // S5CR (Stream x configuration register) bitfields.
          struct { 
            Object *en; // [0:0] Stream enable / flag stream ready when read low 
            Object *dmeie; // [1:1] Direct mode error interrupt enable 
            Object *teie; // [2:2] Transfer error interrupt enable 
            Object *htie; // [3:3] Half transfer interrupt enable 
            Object *tcie; // [4:4] Transfer complete interrupt enable 
            Object *pfctrl; // [5:5] Peripheral flow controller 
            Object *dir; // [6:7] Data transfer direction 
            Object *circ; // [8:8] Circular mode 
            Object *pinc; // [9:9] Peripheral increment mode 
            Object *minc; // [10:10] Memory increment mode 
            Object *psize; // [11:12] Peripheral data size 
            Object *msize; // [13:14] Memory data size 
            Object *pincos; // [15:15] Peripheral increment offset size 
            Object *pl; // [16:17] Priority level 
            Object *dbm; // [18:18] Double buffer mode 
            Object *ct; // [19:19] Current target (only in double buffer mode) 
            Object *ack; // [20:20] ACK 
            Object *pburst; // [21:22] Peripheral burst transfer configuration 
            Object *mburst; // [23:24] Memory burst transfer configuration 
            Object *chsel; // [25:27] Channel selection  
          } s5cr; 
          
          // S5NDTR (Stream x number of data register) bitfields.
          struct { 
            Object *ndt; // [0:15] Number of data items to transfer  
          } s5ndtr; 
          
          // S5PAR (Stream x peripheral address register) bitfields.
          struct { 
            Object *pa; // [0:31] Peripheral address  
          } s5par; 
          
          // S5M0AR (Stream x memory 0 address register) bitfields.
          struct { 
            Object *m0a; // [0:31] Memory 0 address  
          } s5m0ar; 
          
          // S5M1AR (Stream x memory 1 address register) bitfields.
          struct { 
            Object *m1a; // [0:31] Memory 1 address (used in case of Double buffer mode)  
          } s5m1ar; 
          
          // S5FCR (Stream x FIFO control register) bitfields.
          struct { 
            Object *fth; // [0:1] FIFO threshold selection 
            Object *dmdis; // [2:2] Direct mode disable 
            Object *fs; // [3:5] FIFO status 
            Object *feie; // [7:7] FIFO error interrupt enable  
          } s5fcr; 
          
          // S6CR (Stream x configuration register) bitfields.
          struct { 
            Object *en; // [0:0] Stream enable / flag stream ready when read low 
            Object *dmeie; // [1:1] Direct mode error interrupt enable 
            Object *teie; // [2:2] Transfer error interrupt enable 
            Object *htie; // [3:3] Half transfer interrupt enable 
            Object *tcie; // [4:4] Transfer complete interrupt enable 
            Object *pfctrl; // [5:5] Peripheral flow controller 
            Object *dir; // [6:7] Data transfer direction 
            Object *circ; // [8:8] Circular mode 
            Object *pinc; // [9:9] Peripheral increment mode 
            Object *minc; // [10:10] Memory increment mode 
            Object *psize; // [11:12] Peripheral data size 
            Object *msize; // [13:14] Memory data size 
            Object *pincos; // [15:15] Peripheral increment offset size 
            Object *pl; // [16:17] Priority level 
            Object *dbm; // [18:18] Double buffer mode 
            Object *ct; // [19:19] Current target (only in double buffer mode) 
            Object *ack; // [20:20] ACK 
            Object *pburst; // [21:22] Peripheral burst transfer configuration 
            Object *mburst; // [23:24] Memory burst transfer configuration 
            Object *chsel; // [25:27] Channel selection  
          } s6cr; 
          
          // S6NDTR (Stream x number of data register) bitfields.
          struct { 
            Object *ndt; // [0:15] Number of data items to transfer  
          } s6ndtr; 
          
          // S6PAR (Stream x peripheral address register) bitfields.
          struct { 
            Object *pa; // [0:31] Peripheral address  
          } s6par; 
          
          // S6M0AR (Stream x memory 0 address register) bitfields.
          struct { 
            Object *m0a; // [0:31] Memory 0 address  
          } s6m0ar; 
          
          // S6M1AR (Stream x memory 1 address register) bitfields.
          struct { 
            Object *m1a; // [0:31] Memory 1 address (used in case of Double buffer mode)  
          } s6m1ar; 
          
          // S6FCR (Stream x FIFO control register) bitfields.
          struct { 
            Object *fth; // [0:1] FIFO threshold selection 
            Object *dmdis; // [2:2] Direct mode disable 
            Object *fs; // [3:5] FIFO status 
            Object *feie; // [7:7] FIFO error interrupt enable  
          } s6fcr; 
          
          // S7CR (Stream x configuration register) bitfields.
          struct { 
            Object *en; // [0:0] Stream enable / flag stream ready when read low 
            Object *dmeie; // [1:1] Direct mode error interrupt enable 
            Object *teie; // [2:2] Transfer error interrupt enable 
            Object *htie; // [3:3] Half transfer interrupt enable 
            Object *tcie; // [4:4] Transfer complete interrupt enable 
            Object *pfctrl; // [5:5] Peripheral flow controller 
            Object *dir; // [6:7] Data transfer direction 
            Object *circ; // [8:8] Circular mode 
            Object *pinc; // [9:9] Peripheral increment mode 
            Object *minc; // [10:10] Memory increment mode 
            Object *psize; // [11:12] Peripheral data size 
            Object *msize; // [13:14] Memory data size 
            Object *pincos; // [15:15] Peripheral increment offset size 
            Object *pl; // [16:17] Priority level 
            Object *dbm; // [18:18] Double buffer mode 
            Object *ct; // [19:19] Current target (only in double buffer mode) 
            Object *ack; // [20:20] ACK 
            Object *pburst; // [21:22] Peripheral burst transfer configuration 
            Object *mburst; // [23:24] Memory burst transfer configuration 
            Object *chsel; // [25:27] Channel selection  
          } s7cr; 
          
          // S7NDTR (Stream x number of data register) bitfields.
          struct { 
            Object *ndt; // [0:15] Number of data items to transfer  
          } s7ndtr; 
          
          // S7PAR (Stream x peripheral address register) bitfields.
          struct { 
            Object *pa; // [0:31] Peripheral address  
          } s7par; 
          
          // S7M0AR (Stream x memory 0 address register) bitfields.
          struct { 
            Object *m0a; // [0:31] Memory 0 address  
          } s7m0ar; 
          
          // S7M1AR (Stream x memory 1 address register) bitfields.
          struct { 
            Object *m1a; // [0:31] Memory 1 address (used in case of Double buffer mode)  
          } s7m1ar; 
          
          // S7FCR (Stream x FIFO control register) bitfields.
          struct { 
            Object *fth; // [0:1] FIFO threshold selection 
            Object *dmdis; // [2:2] Direct mode disable 
            Object *fs; // [3:5] FIFO status 
            Object *feie; // [7:7] FIFO error interrupt enable  
          } s7fcr; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32DMAState;

// ----------------------------------------------------------------------------

#endif /* STM32_DMA_H_ */
