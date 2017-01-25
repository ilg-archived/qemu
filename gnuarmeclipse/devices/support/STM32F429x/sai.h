/*
 * STM32 - SAI (Serial audio interface) emulation.
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

#ifndef STM32_SAI_H_
#define STM32_SAI_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_SAI DEVICE_PATH_STM32 "SAI"



// ----------------------------------------------------------------------------

#define TYPE_STM32_SAI TYPE_STM32_PREFIX "sai" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_SAI_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32SAIParentClass;
typedef PeripheralState STM32SAIParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_SAI_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32SAIClass, (obj), TYPE_STM32_SAI)
#define STM32_SAI_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32SAIClass, (klass), TYPE_STM32_SAI)

typedef struct {
    // private: 
    STM32SAIParentClass parent_class;
    // public: 

    // None, so far.
} STM32SAIClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_SAI_STATE(obj) \
    OBJECT_CHECK(STM32SAIState, (obj), TYPE_STM32_SAI)

typedef struct {
    // private:
    STM32SAIParentState parent_obj;
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
        // F4 SAI (Serial audio interface) registers.
        struct { 
          Object *bcr1; // 0x24 (BConfiguration register 1) 
          Object *bcr2; // 0x28 (BConfiguration register 2) 
          Object *bfrcr; // 0x2C (BFRCR) 
          Object *bslotr; // 0x30 (BSlot register) 
          Object *bim; // 0x34 (BInterrupt mask register2) 
          Object *bsr; // 0x38 (BStatus register) 
          Object *bclrfr; // 0x3C (BClear flag register) 
          Object *bdr; // 0x40 (BData register) 
          Object *acr1; // 0x4 (AConfiguration register 1) 
          Object *acr2; // 0x8 (AConfiguration register 2) 
          Object *afrcr; // 0xC (AFRCR) 
          Object *aslotr; // 0x10 (ASlot register) 
          Object *aim; // 0x14 (AInterrupt mask register2) 
          Object *asr; // 0x18 (AStatus register) 
          Object *aclrfr; // 0x1C (AClear flag register) 
          Object *adr; // 0x20 (AData register) 
        } reg;

        struct { 
          
          // BCR1 (BConfiguration register 1) bitfields.
          struct { 
            Object *mode; // [0:1] Audio block mode 
            Object *prtcfg; // [2:3] Protocol configuration 
            Object *ds; // [5:7] Data size 
            Object *lsbfirst; // [8:8] Least significant bit first 
            Object *ckstr; // [9:9] Clock strobing edge 
            Object *syncen; // [10:11] Synchronization enable 
            Object *mono; // [12:12] Mono mode 
            Object *outdri; // [13:13] Output drive 
            Object *saiben; // [16:16] Audio block B enable 
            Object *dmaen; // [17:17] DMA enable 
            Object *nodiv; // [19:19] No divider 
            Object *mcjdiv; // [20:23] Master clock divider  
          } bcr1; 
          
          // BCR2 (BConfiguration register 2) bitfields.
          struct { 
            Object *fth; // [0:2] FIFO threshold 
            Object *fflus; // [3:3] FIFO flush 
            Object *tris; // [4:4] Tristate management on data line 
            Object *mute; // [5:5] Mute 
            Object *muteval; // [6:6] Mute value 
            Object *mutecn; // [7:12] Mute counter 
            Object *cpl; // [13:13] Complement bit 
            Object *comp; // [14:15] Companding mode  
          } bcr2; 
          
          // BFRCR (BFRCR) bitfields.
          struct { 
            Object *frl; // [0:7] Frame length 
            Object *fsall; // [8:14] Frame synchronization active level length 
            Object *fsdef; // [16:16] Frame synchronization definition 
            Object *fspol; // [17:17] Frame synchronization polarity 
            Object *fsoff; // [18:18] Frame synchronization offset  
          } bfrcr; 
          
          // BSLOTR (BSlot register) bitfields.
          struct { 
            Object *fboff; // [0:4] First bit offset 
            Object *slotsz; // [6:7] Slot size 
            Object *nbslot; // [8:11] Number of slots in an audio frame 
            Object *sloten; // [16:31] Slot enable  
          } bslotr; 
          
          // BIM (BInterrupt mask register2) bitfields.
          struct { 
            Object *ovrudrie; // [0:0] Overrun/underrun interrupt enable 
            Object *mutedet; // [1:1] Mute detection interrupt enable 
            Object *wckcfg; // [2:2] Wrong clock configuration interrupt enable 
            Object *freqie; // [3:3] FIFO request interrupt enable 
            Object *cnrdyie; // [4:4] Codec not ready interrupt enable 
            Object *afsdetie; // [5:5] Anticipated frame synchronization detection interrupt enable 
            Object *lfsdetie; // [6:6] Late frame synchronization detection interrupt enable  
          } bim; 
          
          // BSR (BStatus register) bitfields.
          struct { 
            Object *ovrudr; // [0:0] Overrun / underrun 
            Object *mutedet; // [1:1] Mute detection 
            Object *wckcfg; // [2:2] Wrong clock configuration flag 
            Object *freq; // [3:3] FIFO request 
            Object *cnrdy; // [4:4] Codec not ready 
            Object *afsdet; // [5:5] Anticipated frame synchronization detection 
            Object *lfsdet; // [6:6] Late frame synchronization detection 
            Object *flvl; // [16:18] FIFO level threshold  
          } bsr; 
          
          // BCLRFR (BClear flag register) bitfields.
          struct { 
            Object *ovrudr; // [0:0] Clear overrun / underrun 
            Object *mutedet; // [1:1] Mute detection flag 
            Object *wckcfg; // [2:2] Clear wrong clock configuration flag 
            Object *cnrdy; // [4:4] Clear codec not ready flag 
            Object *cafsdet; // [5:5] Clear anticipated frame synchronization detection flag 
            Object *lfsdet; // [6:6] Clear late frame synchronization detection flag  
          } bclrfr; 
          
          // BDR (BData register) bitfields.
          struct { 
            Object *data; // [0:31] Data  
          } bdr; 
          
          // ACR1 (AConfiguration register 1) bitfields.
          struct { 
            Object *mode; // [0:1] Audio block mode 
            Object *prtcfg; // [2:3] Protocol configuration 
            Object *ds; // [5:7] Data size 
            Object *lsbfirst; // [8:8] Least significant bit first 
            Object *ckstr; // [9:9] Clock strobing edge 
            Object *syncen; // [10:11] Synchronization enable 
            Object *mono; // [12:12] Mono mode 
            Object *outdri; // [13:13] Output drive 
            Object *saiaen; // [16:16] Audio block A enable 
            Object *dmaen; // [17:17] DMA enable 
            Object *nodiv; // [19:19] No divider 
            Object *mcjdiv; // [20:23] Master clock divider  
          } acr1; 
          
          // ACR2 (AConfiguration register 2) bitfields.
          struct { 
            Object *fth; // [0:2] FIFO threshold 
            Object *fflus; // [3:3] FIFO flush 
            Object *tris; // [4:4] Tristate management on data line 
            Object *mute; // [5:5] Mute 
            Object *muteval; // [6:6] Mute value 
            Object *mutecn; // [7:12] Mute counter 
            Object *cpl; // [13:13] Complement bit 
            Object *comp; // [14:15] Companding mode  
          } acr2; 
          
          // AFRCR (AFRCR) bitfields.
          struct { 
            Object *frl; // [0:7] Frame length 
            Object *fsall; // [8:14] Frame synchronization active level length 
            Object *fsdef; // [16:16] Frame synchronization definition 
            Object *fspol; // [17:17] Frame synchronization polarity 
            Object *fsoff; // [18:18] Frame synchronization offset  
          } afrcr; 
          
          // ASLOTR (ASlot register) bitfields.
          struct { 
            Object *fboff; // [0:4] First bit offset 
            Object *slotsz; // [6:7] Slot size 
            Object *nbslot; // [8:11] Number of slots in an audio frame 
            Object *sloten; // [16:31] Slot enable  
          } aslotr; 
          
          // AIM (AInterrupt mask register2) bitfields.
          struct { 
            Object *ovrudrie; // [0:0] Overrun/underrun interrupt enable 
            Object *mutedet; // [1:1] Mute detection interrupt enable 
            Object *wckcfg; // [2:2] Wrong clock configuration interrupt enable 
            Object *freqie; // [3:3] FIFO request interrupt enable 
            Object *cnrdyie; // [4:4] Codec not ready interrupt enable 
            Object *afsdetie; // [5:5] Anticipated frame synchronization detection interrupt enable 
            Object *lfsdet; // [6:6] Late frame synchronization detection interrupt enable  
          } aim; 
          
          // ASR (AStatus register) bitfields.
          struct { 
            Object *ovrudr; // [0:0] Overrun / underrun 
            Object *mutedet; // [1:1] Mute detection 
            Object *wckcfg; // [2:2] Wrong clock configuration flag. This bit is read only. 
            Object *freq; // [3:3] FIFO request 
            Object *cnrdy; // [4:4] Codec not ready 
            Object *afsdet; // [5:5] Anticipated frame synchronization detection 
            Object *lfsdet; // [6:6] Late frame synchronization detection 
            Object *flvl; // [16:18] FIFO level threshold  
          } asr; 
          
          // ACLRFR (AClear flag register) bitfields.
          struct { 
            Object *ovrudr; // [0:0] Clear overrun / underrun 
            Object *mutedet; // [1:1] Mute detection flag 
            Object *wckcfg; // [2:2] Clear wrong clock configuration flag 
            Object *cnrdy; // [4:4] Clear codec not ready flag 
            Object *cafsdet; // [5:5] Clear anticipated frame synchronization detection flag. 
            Object *lfsdet; // [6:6] Clear late frame synchronization detection flag  
          } aclrfr; 
          
          // ADR (AData register) bitfields.
          struct { 
            Object *data; // [0:31] Data  
          } adr; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32SAIState;

// ----------------------------------------------------------------------------

#endif /* STM32_SAI_H_ */
