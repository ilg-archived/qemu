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
        // F1 DMA (DMA controller) registers.
        struct { 
          Object *isr; // 0x0 (DMA interrupt status register (DMA_ISR)) 
          Object *ifcr; // 0x4 (DMA interrupt flag clear register (DMA_IFCR)) 
          Object *ccr1; // 0x8 (DMA channel configuration register (DMA_CCR)) 
          Object *cndtr1; // 0xC (DMA channel 1 number of data register) 
          Object *cpar1; // 0x10 (DMA channel 1 peripheral address register) 
          Object *cmar1; // 0x14 (DMA channel 1 memory address register) 
          Object *ccr2; // 0x1C (DMA channel configuration register (DMA_CCR)) 
          Object *cndtr2; // 0x20 (DMA channel 2 number of data register) 
          Object *cpar2; // 0x24 (DMA channel 2 peripheral address register) 
          Object *cmar2; // 0x28 (DMA channel 2 memory address register) 
          Object *ccr3; // 0x30 (DMA channel configuration register (DMA_CCR)) 
          Object *cndtr3; // 0x34 (DMA channel 3 number of data register) 
          Object *cpar3; // 0x38 (DMA channel 3 peripheral address register) 
          Object *cmar3; // 0x3C (DMA channel 3 memory address register) 
          Object *ccr4; // 0x44 (DMA channel configuration register (DMA_CCR)) 
          Object *cndtr4; // 0x48 (DMA channel 4 number of data register) 
          Object *cpar4; // 0x4C (DMA channel 4 peripheral address register) 
          Object *cmar4; // 0x50 (DMA channel 4 memory address register) 
          Object *ccr5; // 0x58 (DMA channel configuration register (DMA_CCR)) 
          Object *cndtr5; // 0x5C (DMA channel 5 number of data register) 
          Object *cpar5; // 0x60 (DMA channel 5 peripheral address register) 
          Object *cmar5; // 0x64 (DMA channel 5 memory address register) 
          Object *ccr6; // 0x6C (DMA channel configuration register (DMA_CCR)) 
          Object *cndtr6; // 0x70 (DMA channel 6 number of data register) 
          Object *cpar6; // 0x74 (DMA channel 6 peripheral address register) 
          Object *cmar6; // 0x78 (DMA channel 6 memory address register) 
          Object *ccr7; // 0x80 (DMA channel configuration register (DMA_CCR)) 
          Object *cndtr7; // 0x84 (DMA channel 7 number of data register) 
          Object *cpar7; // 0x88 (DMA channel 7 peripheral address register) 
          Object *cmar7; // 0x8C (DMA channel 7 memory address register) 
        } reg;

        struct { 
          
          // ISR (DMA interrupt status register (DMA_ISR)) bitfields.
          struct { 
            Object *gif1; // [0:0] Channel 1 Global interrupt flag 
            Object *tcif1; // [1:1] Channel 1 Transfer Complete flag 
            Object *htif1; // [2:2] Channel 1 Half Transfer Complete flag 
            Object *teif1; // [3:3] Channel 1 Transfer Error flag 
            Object *gif2; // [4:4] Channel 2 Global interrupt flag 
            Object *tcif2; // [5:5] Channel 2 Transfer Complete flag 
            Object *htif2; // [6:6] Channel 2 Half Transfer Complete flag 
            Object *teif2; // [7:7] Channel 2 Transfer Error flag 
            Object *gif3; // [8:8] Channel 3 Global interrupt flag 
            Object *tcif3; // [9:9] Channel 3 Transfer Complete flag 
            Object *htif3; // [10:10] Channel 3 Half Transfer Complete flag 
            Object *teif3; // [11:11] Channel 3 Transfer Error flag 
            Object *gif4; // [12:12] Channel 4 Global interrupt flag 
            Object *tcif4; // [13:13] Channel 4 Transfer Complete flag 
            Object *htif4; // [14:14] Channel 4 Half Transfer Complete flag 
            Object *teif4; // [15:15] Channel 4 Transfer Error flag 
            Object *gif5; // [16:16] Channel 5 Global interrupt flag 
            Object *tcif5; // [17:17] Channel 5 Transfer Complete flag 
            Object *htif5; // [18:18] Channel 5 Half Transfer Complete flag 
            Object *teif5; // [19:19] Channel 5 Transfer Error flag 
            Object *gif6; // [20:20] Channel 6 Global interrupt flag 
            Object *tcif6; // [21:21] Channel 6 Transfer Complete flag 
            Object *htif6; // [22:22] Channel 6 Half Transfer Complete flag 
            Object *teif6; // [23:23] Channel 6 Transfer Error flag 
            Object *gif7; // [24:24] Channel 7 Global interrupt flag 
            Object *tcif7; // [25:25] Channel 7 Transfer Complete flag 
            Object *htif7; // [26:26] Channel 7 Half Transfer Complete flag 
            Object *teif7; // [27:27] Channel 7 Transfer Error flag  
          } isr; 
          
          // IFCR (DMA interrupt flag clear register (DMA_IFCR)) bitfields.
          struct { 
            Object *cgif1; // [0:0] Channel 1 Global interrupt clear 
            Object *ctcif1; // [1:1] Channel 1 Transfer Complete clear 
            Object *chtif1; // [2:2] Channel 1 Half Transfer clear 
            Object *cteif1; // [3:3] Channel 1 Transfer Error clear 
            Object *cgif2; // [4:4] Channel 2 Global interrupt clear 
            Object *ctcif2; // [5:5] Channel 2 Transfer Complete clear 
            Object *chtif2; // [6:6] Channel 2 Half Transfer clear 
            Object *cteif2; // [7:7] Channel 2 Transfer Error clear 
            Object *cgif3; // [8:8] Channel 3 Global interrupt clear 
            Object *ctcif3; // [9:9] Channel 3 Transfer Complete clear 
            Object *chtif3; // [10:10] Channel 3 Half Transfer clear 
            Object *cteif3; // [11:11] Channel 3 Transfer Error clear 
            Object *cgif4; // [12:12] Channel 4 Global interrupt clear 
            Object *ctcif4; // [13:13] Channel 4 Transfer Complete clear 
            Object *chtif4; // [14:14] Channel 4 Half Transfer clear 
            Object *cteif4; // [15:15] Channel 4 Transfer Error clear 
            Object *cgif5; // [16:16] Channel 5 Global interrupt clear 
            Object *ctcif5; // [17:17] Channel 5 Transfer Complete clear 
            Object *chtif5; // [18:18] Channel 5 Half Transfer clear 
            Object *cteif5; // [19:19] Channel 5 Transfer Error clear 
            Object *cgif6; // [20:20] Channel 6 Global interrupt clear 
            Object *ctcif6; // [21:21] Channel 6 Transfer Complete clear 
            Object *chtif6; // [22:22] Channel 6 Half Transfer clear 
            Object *cteif6; // [23:23] Channel 6 Transfer Error clear 
            Object *cgif7; // [24:24] Channel 7 Global interrupt clear 
            Object *ctcif7; // [25:25] Channel 7 Transfer Complete clear 
            Object *chtif7; // [26:26] Channel 7 Half Transfer clear 
            Object *cteif7; // [27:27] Channel 7 Transfer Error clear  
          } ifcr; 
          
          // CCR1 (DMA channel configuration register (DMA_CCR)) bitfields.
          struct { 
            Object *en; // [0:0] Channel enable 
            Object *tcie; // [1:1] Transfer complete interrupt enable 
            Object *htie; // [2:2] Half Transfer interrupt enable 
            Object *teie; // [3:3] Transfer error interrupt enable 
            Object *dir; // [4:4] Data transfer direction 
            Object *circ; // [5:5] Circular mode 
            Object *pinc; // [6:6] Peripheral increment mode 
            Object *minc; // [7:7] Memory increment mode 
            Object *psize; // [8:9] Peripheral size 
            Object *msize; // [10:11] Memory size 
            Object *pl; // [12:13] Channel Priority level 
            Object *mem2mem; // [14:14] Memory to memory mode  
          } ccr1; 
          
          // CNDTR1 (DMA channel 1 number of data register) bitfields.
          struct { 
            Object *ndt; // [0:15] Number of data to transfer  
          } cndtr1; 
          
          // CPAR1 (DMA channel 1 peripheral address register) bitfields.
          struct { 
            Object *pa; // [0:31] Peripheral address  
          } cpar1; 
          
          // CMAR1 (DMA channel 1 memory address register) bitfields.
          struct { 
            Object *ma; // [0:31] Memory address  
          } cmar1; 
          
          // CCR2 (DMA channel configuration register (DMA_CCR)) bitfields.
          struct { 
            Object *en; // [0:0] Channel enable 
            Object *tcie; // [1:1] Transfer complete interrupt enable 
            Object *htie; // [2:2] Half Transfer interrupt enable 
            Object *teie; // [3:3] Transfer error interrupt enable 
            Object *dir; // [4:4] Data transfer direction 
            Object *circ; // [5:5] Circular mode 
            Object *pinc; // [6:6] Peripheral increment mode 
            Object *minc; // [7:7] Memory increment mode 
            Object *psize; // [8:9] Peripheral size 
            Object *msize; // [10:11] Memory size 
            Object *pl; // [12:13] Channel Priority level 
            Object *mem2mem; // [14:14] Memory to memory mode  
          } ccr2; 
          
          // CNDTR2 (DMA channel 2 number of data register) bitfields.
          struct { 
            Object *ndt; // [0:15] Number of data to transfer  
          } cndtr2; 
          
          // CPAR2 (DMA channel 2 peripheral address register) bitfields.
          struct { 
            Object *pa; // [0:31] Peripheral address  
          } cpar2; 
          
          // CMAR2 (DMA channel 2 memory address register) bitfields.
          struct { 
            Object *ma; // [0:31] Memory address  
          } cmar2; 
          
          // CCR3 (DMA channel configuration register (DMA_CCR)) bitfields.
          struct { 
            Object *en; // [0:0] Channel enable 
            Object *tcie; // [1:1] Transfer complete interrupt enable 
            Object *htie; // [2:2] Half Transfer interrupt enable 
            Object *teie; // [3:3] Transfer error interrupt enable 
            Object *dir; // [4:4] Data transfer direction 
            Object *circ; // [5:5] Circular mode 
            Object *pinc; // [6:6] Peripheral increment mode 
            Object *minc; // [7:7] Memory increment mode 
            Object *psize; // [8:9] Peripheral size 
            Object *msize; // [10:11] Memory size 
            Object *pl; // [12:13] Channel Priority level 
            Object *mem2mem; // [14:14] Memory to memory mode  
          } ccr3; 
          
          // CNDTR3 (DMA channel 3 number of data register) bitfields.
          struct { 
            Object *ndt; // [0:15] Number of data to transfer  
          } cndtr3; 
          
          // CPAR3 (DMA channel 3 peripheral address register) bitfields.
          struct { 
            Object *pa; // [0:31] Peripheral address  
          } cpar3; 
          
          // CMAR3 (DMA channel 3 memory address register) bitfields.
          struct { 
            Object *ma; // [0:31] Memory address  
          } cmar3; 
          
          // CCR4 (DMA channel configuration register (DMA_CCR)) bitfields.
          struct { 
            Object *en; // [0:0] Channel enable 
            Object *tcie; // [1:1] Transfer complete interrupt enable 
            Object *htie; // [2:2] Half Transfer interrupt enable 
            Object *teie; // [3:3] Transfer error interrupt enable 
            Object *dir; // [4:4] Data transfer direction 
            Object *circ; // [5:5] Circular mode 
            Object *pinc; // [6:6] Peripheral increment mode 
            Object *minc; // [7:7] Memory increment mode 
            Object *psize; // [8:9] Peripheral size 
            Object *msize; // [10:11] Memory size 
            Object *pl; // [12:13] Channel Priority level 
            Object *mem2mem; // [14:14] Memory to memory mode  
          } ccr4; 
          
          // CNDTR4 (DMA channel 4 number of data register) bitfields.
          struct { 
            Object *ndt; // [0:15] Number of data to transfer  
          } cndtr4; 
          
          // CPAR4 (DMA channel 4 peripheral address register) bitfields.
          struct { 
            Object *pa; // [0:31] Peripheral address  
          } cpar4; 
          
          // CMAR4 (DMA channel 4 memory address register) bitfields.
          struct { 
            Object *ma; // [0:31] Memory address  
          } cmar4; 
          
          // CCR5 (DMA channel configuration register (DMA_CCR)) bitfields.
          struct { 
            Object *en; // [0:0] Channel enable 
            Object *tcie; // [1:1] Transfer complete interrupt enable 
            Object *htie; // [2:2] Half Transfer interrupt enable 
            Object *teie; // [3:3] Transfer error interrupt enable 
            Object *dir; // [4:4] Data transfer direction 
            Object *circ; // [5:5] Circular mode 
            Object *pinc; // [6:6] Peripheral increment mode 
            Object *minc; // [7:7] Memory increment mode 
            Object *psize; // [8:9] Peripheral size 
            Object *msize; // [10:11] Memory size 
            Object *pl; // [12:13] Channel Priority level 
            Object *mem2mem; // [14:14] Memory to memory mode  
          } ccr5; 
          
          // CNDTR5 (DMA channel 5 number of data register) bitfields.
          struct { 
            Object *ndt; // [0:15] Number of data to transfer  
          } cndtr5; 
          
          // CPAR5 (DMA channel 5 peripheral address register) bitfields.
          struct { 
            Object *pa; // [0:31] Peripheral address  
          } cpar5; 
          
          // CMAR5 (DMA channel 5 memory address register) bitfields.
          struct { 
            Object *ma; // [0:31] Memory address  
          } cmar5; 
          
          // CCR6 (DMA channel configuration register (DMA_CCR)) bitfields.
          struct { 
            Object *en; // [0:0] Channel enable 
            Object *tcie; // [1:1] Transfer complete interrupt enable 
            Object *htie; // [2:2] Half Transfer interrupt enable 
            Object *teie; // [3:3] Transfer error interrupt enable 
            Object *dir; // [4:4] Data transfer direction 
            Object *circ; // [5:5] Circular mode 
            Object *pinc; // [6:6] Peripheral increment mode 
            Object *minc; // [7:7] Memory increment mode 
            Object *psize; // [8:9] Peripheral size 
            Object *msize; // [10:11] Memory size 
            Object *pl; // [12:13] Channel Priority level 
            Object *mem2mem; // [14:14] Memory to memory mode  
          } ccr6; 
          
          // CNDTR6 (DMA channel 6 number of data register) bitfields.
          struct { 
            Object *ndt; // [0:15] Number of data to transfer  
          } cndtr6; 
          
          // CPAR6 (DMA channel 6 peripheral address register) bitfields.
          struct { 
            Object *pa; // [0:31] Peripheral address  
          } cpar6; 
          
          // CMAR6 (DMA channel 6 memory address register) bitfields.
          struct { 
            Object *ma; // [0:31] Memory address  
          } cmar6; 
          
          // CCR7 (DMA channel configuration register (DMA_CCR)) bitfields.
          struct { 
            Object *en; // [0:0] Channel enable 
            Object *tcie; // [1:1] Transfer complete interrupt enable 
            Object *htie; // [2:2] Half Transfer interrupt enable 
            Object *teie; // [3:3] Transfer error interrupt enable 
            Object *dir; // [4:4] Data transfer direction 
            Object *circ; // [5:5] Circular mode 
            Object *pinc; // [6:6] Peripheral increment mode 
            Object *minc; // [7:7] Memory increment mode 
            Object *psize; // [8:9] Peripheral size 
            Object *msize; // [10:11] Memory size 
            Object *pl; // [12:13] Channel Priority level 
            Object *mem2mem; // [14:14] Memory to memory mode  
          } ccr7; 
          
          // CNDTR7 (DMA channel 7 number of data register) bitfields.
          struct { 
            Object *ndt; // [0:15] Number of data to transfer  
          } cndtr7; 
          
          // CPAR7 (DMA channel 7 peripheral address register) bitfields.
          struct { 
            Object *pa; // [0:31] Peripheral address  
          } cpar7; 
          
          // CMAR7 (DMA channel 7 memory address register) bitfields.
          struct { 
            Object *ma; // [0:31] Memory address  
          } cmar7; 
        } fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32DMAState;

// ----------------------------------------------------------------------------

#endif /* STM32_DMA_H_ */
