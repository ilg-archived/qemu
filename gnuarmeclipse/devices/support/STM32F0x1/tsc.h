/*
 * STM32 - TSC (Touch sensing controller) emulation.
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

#ifndef STM32_TSC_H_
#define STM32_TSC_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_TSC DEVICE_PATH_STM32 "TSC"



// ----------------------------------------------------------------------------

#define TYPE_STM32_TSC TYPE_STM32_PREFIX "tsc" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_TSC_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32TSCParentClass;
typedef PeripheralState STM32TSCParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_TSC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32TSCClass, (obj), TYPE_STM32_TSC)
#define STM32_TSC_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32TSCClass, (klass), TYPE_STM32_TSC)

typedef struct {
    // private: 
    STM32TSCParentClass parent_class;
    // public: 

    // None, so far.
} STM32TSCClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_TSC_STATE(obj) \
    OBJECT_CHECK(STM32TSCState, (obj), TYPE_STM32_TSC)

typedef struct {
    // private:
    STM32TSCParentState parent_obj;
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
        // F0 TSC (Touch sensing controller) registers.
        struct { 
          Object *cr; // 0x0 (Control register) 
          Object *ier; // 0x4 (Interrupt enable register) 
          Object *icr; // 0x8 (Interrupt clear register) 
          Object *isr; // 0xC (Interrupt status register) 
          Object *iohcr; // 0x10 (I/O hysteresis control register) 
          Object *ioascr; // 0x18 (I/O analog switch control register) 
          Object *ioscr; // 0x20 (I/O sampling control register) 
          Object *ioccr; // 0x28 (I/O channel control register) 
          Object *iogcsr; // 0x30 (I/O group control status register) 
          Object *iog1cr; // 0x34 (I/O group x counter register) 
          Object *iog2cr; // 0x38 (I/O group x counter register) 
          Object *iog3cr; // 0x3C (I/O group x counter register) 
          Object *iog4cr; // 0x40 (I/O group x counter register) 
          Object *iog5cr; // 0x44 (I/O group x counter register) 
          Object *iog6cr; // 0x48 (I/O group x counter register) 
        } reg;

        struct { 
          
          // CR (Control register) bitfields.
          struct { 
            Object *tsce; // [0:0] Touch sensing controller enable 
            Object *start; // [1:1] Start a new acquisition 
            Object *am; // [2:2] Acquisition mode 
            Object *syncpol; // [3:3] Synchronization pin polarity 
            Object *iodef; // [4:4] I/O Default mode 
            Object *mcv; // [5:7] Max count value 
            Object *pgpsc; // [12:14] Pulse generator prescaler 
            Object *sspsc; // [15:15] Spread spectrum prescaler 
            Object *sse; // [16:16] Spread spectrum enable 
            Object *ssd; // [17:23] Spread spectrum deviation 
            Object *ctpl; // [24:27] Charge transfer pulse low 
            Object *ctph; // [28:31] Charge transfer pulse high  
          } cr; 
          
          // IER (Interrupt enable register) bitfields.
          struct { 
            Object *eoaie; // [0:0] End of acquisition interrupt enable 
            Object *mceie; // [1:1] Max count error interrupt enable  
          } ier; 
          
          // ICR (Interrupt clear register) bitfields.
          struct { 
            Object *eoaic; // [0:0] End of acquisition interrupt clear 
            Object *mceic; // [1:1] Max count error interrupt clear  
          } icr; 
          
          // ISR (Interrupt status register) bitfields.
          struct { 
            Object *eoaf; // [0:0] End of acquisition flag 
            Object *mcef; // [1:1] Max count error flag  
          } isr; 
          
          // IOHCR (I/O hysteresis control register) bitfields.
          struct { 
            Object *g1_io1; // [0:0] G1_IO1 Schmitt trigger hysteresis mode 
            Object *g1_io2; // [1:1] G1_IO2 Schmitt trigger hysteresis mode 
            Object *g1_io3; // [2:2] G1_IO3 Schmitt trigger hysteresis mode 
            Object *g1_io4; // [3:3] G1_IO4 Schmitt trigger hysteresis mode 
            Object *g2_io1; // [4:4] G2_IO1 Schmitt trigger hysteresis mode 
            Object *g2_io2; // [5:5] G2_IO2 Schmitt trigger hysteresis mode 
            Object *g2_io3; // [6:6] G2_IO3 Schmitt trigger hysteresis mode 
            Object *g2_io4; // [7:7] G2_IO4 Schmitt trigger hysteresis mode 
            Object *g3_io1; // [8:8] G3_IO1 Schmitt trigger hysteresis mode 
            Object *g3_io2; // [9:9] G3_IO2 Schmitt trigger hysteresis mode 
            Object *g3_io3; // [10:10] G3_IO3 Schmitt trigger hysteresis mode 
            Object *g3_io4; // [11:11] G3_IO4 Schmitt trigger hysteresis mode 
            Object *g4_io1; // [12:12] G4_IO1 Schmitt trigger hysteresis mode 
            Object *g4_io2; // [13:13] G4_IO2 Schmitt trigger hysteresis mode 
            Object *g4_io3; // [14:14] G4_IO3 Schmitt trigger hysteresis mode 
            Object *g4_io4; // [15:15] G4_IO4 Schmitt trigger hysteresis mode 
            Object *g5_io1; // [16:16] G5_IO1 Schmitt trigger hysteresis mode 
            Object *g5_io2; // [17:17] G5_IO2 Schmitt trigger hysteresis mode 
            Object *g5_io3; // [18:18] G5_IO3 Schmitt trigger hysteresis mode 
            Object *g5_io4; // [19:19] G5_IO4 Schmitt trigger hysteresis mode 
            Object *g6_io1; // [20:20] G6_IO1 Schmitt trigger hysteresis mode 
            Object *g6_io2; // [21:21] G6_IO2 Schmitt trigger hysteresis mode 
            Object *g6_io3; // [22:22] G6_IO3 Schmitt trigger hysteresis mode 
            Object *g6_io4; // [23:23] G6_IO4 Schmitt trigger hysteresis mode  
          } iohcr; 
          
          // IOASCR (I/O analog switch control register) bitfields.
          struct { 
            Object *g1_io1; // [0:0] G1_IO1 analog switch enable 
            Object *g1_io2; // [1:1] G1_IO2 analog switch enable 
            Object *g1_io3; // [2:2] G1_IO3 analog switch enable 
            Object *g1_io4; // [3:3] G1_IO4 analog switch enable 
            Object *g2_io1; // [4:4] G2_IO1 analog switch enable 
            Object *g2_io2; // [5:5] G2_IO2 analog switch enable 
            Object *g2_io3; // [6:6] G2_IO3 analog switch enable 
            Object *g2_io4; // [7:7] G2_IO4 analog switch enable 
            Object *g3_io1; // [8:8] G3_IO1 analog switch enable 
            Object *g3_io2; // [9:9] G3_IO2 analog switch enable 
            Object *g3_io3; // [10:10] G3_IO3 analog switch enable 
            Object *g3_io4; // [11:11] G3_IO4 analog switch enable 
            Object *g4_io1; // [12:12] G4_IO1 analog switch enable 
            Object *g4_io2; // [13:13] G4_IO2 analog switch enable 
            Object *g4_io3; // [14:14] G4_IO3 analog switch enable 
            Object *g4_io4; // [15:15] G4_IO4 analog switch enable 
            Object *g5_io1; // [16:16] G5_IO1 analog switch enable 
            Object *g5_io2; // [17:17] G5_IO2 analog switch enable 
            Object *g5_io3; // [18:18] G5_IO3 analog switch enable 
            Object *g5_io4; // [19:19] G5_IO4 analog switch enable 
            Object *g6_io1; // [20:20] G6_IO1 analog switch enable 
            Object *g6_io2; // [21:21] G6_IO2 analog switch enable 
            Object *g6_io3; // [22:22] G6_IO3 analog switch enable 
            Object *g6_io4; // [23:23] G6_IO4 analog switch enable  
          } ioascr; 
          
          // IOSCR (I/O sampling control register) bitfields.
          struct { 
            Object *g1_io1; // [0:0] G1_IO1 sampling mode 
            Object *g1_io2; // [1:1] G1_IO2 sampling mode 
            Object *g1_io3; // [2:2] G1_IO3 sampling mode 
            Object *g1_io4; // [3:3] G1_IO4 sampling mode 
            Object *g2_io1; // [4:4] G2_IO1 sampling mode 
            Object *g2_io2; // [5:5] G2_IO2 sampling mode 
            Object *g2_io3; // [6:6] G2_IO3 sampling mode 
            Object *g2_io4; // [7:7] G2_IO4 sampling mode 
            Object *g3_io1; // [8:8] G3_IO1 sampling mode 
            Object *g3_io2; // [9:9] G3_IO2 sampling mode 
            Object *g3_io3; // [10:10] G3_IO3 sampling mode 
            Object *g3_io4; // [11:11] G3_IO4 sampling mode 
            Object *g4_io1; // [12:12] G4_IO1 sampling mode 
            Object *g4_io2; // [13:13] G4_IO2 sampling mode 
            Object *g4_io3; // [14:14] G4_IO3 sampling mode 
            Object *g4_io4; // [15:15] G4_IO4 sampling mode 
            Object *g5_io1; // [16:16] G5_IO1 sampling mode 
            Object *g5_io2; // [17:17] G5_IO2 sampling mode 
            Object *g5_io3; // [18:18] G5_IO3 sampling mode 
            Object *g5_io4; // [19:19] G5_IO4 sampling mode 
            Object *g6_io1; // [20:20] G6_IO1 sampling mode 
            Object *g6_io2; // [21:21] G6_IO2 sampling mode 
            Object *g6_io3; // [22:22] G6_IO3 sampling mode 
            Object *g6_io4; // [23:23] G6_IO4 sampling mode  
          } ioscr; 
          
          // IOCCR (I/O channel control register) bitfields.
          struct { 
            Object *g1_io1; // [0:0] G1_IO1 channel mode 
            Object *g1_io2; // [1:1] G1_IO2 channel mode 
            Object *g1_io3; // [2:2] G1_IO3 channel mode 
            Object *g1_io4; // [3:3] G1_IO4 channel mode 
            Object *g2_io1; // [4:4] G2_IO1 channel mode 
            Object *g2_io2; // [5:5] G2_IO2 channel mode 
            Object *g2_io3; // [6:6] G2_IO3 channel mode 
            Object *g2_io4; // [7:7] G2_IO4 channel mode 
            Object *g3_io1; // [8:8] G3_IO1 channel mode 
            Object *g3_io2; // [9:9] G3_IO2 channel mode 
            Object *g3_io3; // [10:10] G3_IO3 channel mode 
            Object *g3_io4; // [11:11] G3_IO4 channel mode 
            Object *g4_io1; // [12:12] G4_IO1 channel mode 
            Object *g4_io2; // [13:13] G4_IO2 channel mode 
            Object *g4_io3; // [14:14] G4_IO3 channel mode 
            Object *g4_io4; // [15:15] G4_IO4 channel mode 
            Object *g5_io1; // [16:16] G5_IO1 channel mode 
            Object *g5_io2; // [17:17] G5_IO2 channel mode 
            Object *g5_io3; // [18:18] G5_IO3 channel mode 
            Object *g5_io4; // [19:19] G5_IO4 channel mode 
            Object *g6_io1; // [20:20] G6_IO1 channel mode 
            Object *g6_io2; // [21:21] G6_IO2 channel mode 
            Object *g6_io3; // [22:22] G6_IO3 channel mode 
            Object *g6_io4; // [23:23] G6_IO4 channel mode  
          } ioccr; 
          
          // IOGCSR (I/O group control status register) bitfields.
          struct { 
            Object *g1e; // [0:0] Analog I/O group x enable 
            Object *g2e; // [1:1] Analog I/O group x enable 
            Object *g3e; // [2:2] Analog I/O group x enable 
            Object *g4e; // [3:3] Analog I/O group x enable 
            Object *g5e; // [4:4] Analog I/O group x enable 
            Object *g6e; // [5:5] Analog I/O group x enable 
            Object *g7e; // [6:6] Analog I/O group x enable 
            Object *g8e; // [7:7] Analog I/O group x enable 
            Object *g1s; // [16:16] Analog I/O group x status 
            Object *g2s; // [17:17] Analog I/O group x status 
            Object *g3s; // [18:18] Analog I/O group x status 
            Object *g4s; // [19:19] Analog I/O group x status 
            Object *g5s; // [20:20] Analog I/O group x status 
            Object *g6s; // [21:21] Analog I/O group x status 
            Object *g7s; // [22:22] Analog I/O group x status 
            Object *g8s; // [23:23] Analog I/O group x status  
          } iogcsr; 
          
          // IOG1CR (I/O group x counter register) bitfields.
          struct { 
            Object *cnt; // [0:13] Counter value  
          } iog1cr; 
          
          // IOG2CR (I/O group x counter register) bitfields.
          struct { 
            Object *cnt; // [0:13] Counter value  
          } iog2cr; 
          
          // IOG3CR (I/O group x counter register) bitfields.
          struct { 
            Object *cnt; // [0:13] Counter value  
          } iog3cr; 
          
          // IOG4CR (I/O group x counter register) bitfields.
          struct { 
            Object *cnt; // [0:13] Counter value  
          } iog4cr; 
          
          // IOG5CR (I/O group x counter register) bitfields.
          struct { 
            Object *cnt; // [0:13] Counter value  
          } iog5cr; 
          
          // IOG6CR (I/O group x counter register) bitfields.
          struct { 
            Object *cnt; // [0:13] Counter value  
          } iog6cr; 
        } fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32TSCState;

// ----------------------------------------------------------------------------

#endif /* STM32_TSC_H_ */
