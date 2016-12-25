/*
 * STM32 - RTC (Real-time clock) emulation.
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

#ifndef STM32_RTC_H_
#define STM32_RTC_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_RTC DEVICE_PATH_STM32 "RTC"



// ----------------------------------------------------------------------------

#define TYPE_STM32_RTC TYPE_STM32_PREFIX "rtc" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_RTC_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32RTCParentClass;
typedef PeripheralState STM32RTCParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_RTC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32RTCClass, (obj), TYPE_STM32_RTC)
#define STM32_RTC_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32RTCClass, (klass), TYPE_STM32_RTC)

typedef struct {
    // private: 
    STM32RTCParentClass parent_class;
    // public: 

    // None, so far.
} STM32RTCClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_RTC_STATE(obj) \
    OBJECT_CHECK(STM32RTCState, (obj), TYPE_STM32_RTC)

typedef struct {
    // private:
    STM32RTCParentState parent_obj;
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
        // F4 RTC (Real-time clock) registers.
        struct { 
          Object *tr; // 0x0 (Time register) 
          Object *dr; // 0x4 (Date register) 
          Object *cr; // 0x8 (Control register) 
          Object *isr; // 0xC (Initialization and status register) 
          Object *prer; // 0x10 (Prescaler register) 
          Object *wutr; // 0x14 (Wakeup timer register) 
          Object *calibr; // 0x18 (Calibration register) 
          Object *alrmar; // 0x1C (Alarm A register) 
          Object *alrmbr; // 0x20 (Alarm B register) 
          Object *wpr; // 0x24 (Write protection register) 
          Object *ssr; // 0x28 (Sub second register) 
          Object *shiftr; // 0x2C (Shift control register) 
          Object *tstr; // 0x30 (Time stamp time register) 
          Object *tsdr; // 0x34 (Time stamp date register) 
          Object *tsssr; // 0x38 (Timestamp sub second register) 
          Object *calr; // 0x3C (Calibration register) 
          Object *tafcr; // 0x40 (Tamper and alternate function configuration register) 
          Object *alrmassr; // 0x44 (Alarm A sub second register) 
          Object *alrmbssr; // 0x48 (Alarm B sub second register) 
          Object *bkp0r; // 0x50 (Backup register) 
          Object *bkp1r; // 0x54 (Backup register) 
          Object *bkp2r; // 0x58 (Backup register) 
          Object *bkp3r; // 0x5C (Backup register) 
          Object *bkp4r; // 0x60 (Backup register) 
          Object *bkp5r; // 0x64 (Backup register) 
          Object *bkp6r; // 0x68 (Backup register) 
          Object *bkp7r; // 0x6C (Backup register) 
          Object *bkp8r; // 0x70 (Backup register) 
          Object *bkp9r; // 0x74 (Backup register) 
          Object *bkp10r; // 0x78 (Backup register) 
          Object *bkp11r; // 0x7C (Backup register) 
          Object *bkp12r; // 0x80 (Backup register) 
          Object *bkp13r; // 0x84 (Backup register) 
          Object *bkp14r; // 0x88 (Backup register) 
          Object *bkp15r; // 0x8C (Backup register) 
          Object *bkp16r; // 0x90 (Backup register) 
          Object *bkp17r; // 0x94 (Backup register) 
          Object *bkp18r; // 0x98 (Backup register) 
          Object *bkp19r; // 0x9C (Backup register) 
        } reg;

        struct { 
          
          // TR (Time register) bitfields.
          struct { 
            Object *su; // [0:3] Second units in BCD format 
            Object *st; // [4:6] Second tens in BCD format 
            Object *mnu; // [8:11] Minute units in BCD format 
            Object *mnt; // [12:14] Minute tens in BCD format 
            Object *hu; // [16:19] Hour units in BCD format 
            Object *ht; // [20:21] Hour tens in BCD format 
            Object *pm; // [22:22] AM/PM notation  
          } tr; 
          
          // DR (Date register) bitfields.
          struct { 
            Object *du; // [0:3] Date units in BCD format 
            Object *dt; // [4:5] Date tens in BCD format 
            Object *mu; // [8:11] Month units in BCD format 
            Object *mt; // [12:12] Month tens in BCD format 
            Object *wdu; // [13:15] Week day units 
            Object *yu; // [16:19] Year units in BCD format 
            Object *yt; // [20:23] Year tens in BCD format  
          } dr; 
          
          // CR (Control register) bitfields.
          struct { 
            Object *wcksel; // [0:2] Wakeup clock selection 
            Object *tsedge; // [3:3] Time-stamp event active edge 
            Object *refckon; // [4:4] Reference clock detection enable (50 or 60 Hz) 
            Object *bypshad; // [5:5] Bypass the shadow registers 
            Object *fmt; // [6:6] Hour format 
            Object *dce; // [7:7] Coarse digital calibration enable 
            Object *alrae; // [8:8] Alarm A enable 
            Object *alrbe; // [9:9] Alarm B enable 
            Object *wute; // [10:10] Wakeup timer enable 
            Object *tse; // [11:11] Time stamp enable 
            Object *alraie; // [12:12] Alarm A interrupt enable 
            Object *alrbie; // [13:13] Alarm B interrupt enable 
            Object *wutie; // [14:14] Wakeup timer interrupt enable 
            Object *tsie; // [15:15] Time-stamp interrupt enable 
            Object *add1h; // [16:16] Add 1 hour (summer time change) 
            Object *sub1h; // [17:17] Subtract 1 hour (winter time change) 
            Object *bkp; // [18:18] Backup 
            Object *cosel; // [19:19] Calibration Output selection 
            Object *pol; // [20:20] Output polarity 
            Object *osel; // [21:22] Output selection 
            Object *coe; // [23:23] Calibration output enable  
          } cr; 
          
          // ISR (Initialization and status register) bitfields.
          struct { 
            Object *alrawf; // [0:0] Alarm A write flag 
            Object *alrbwf; // [1:1] Alarm B write flag 
            Object *wutwf; // [2:2] Wakeup timer write flag 
            Object *shpf; // [3:3] Shift operation pending 
            Object *inits; // [4:4] Initialization status flag 
            Object *rsf; // [5:5] Registers synchronization flag 
            Object *initf; // [6:6] Initialization flag 
            Object *init; // [7:7] Initialization mode 
            Object *alraf; // [8:8] Alarm A flag 
            Object *alrbf; // [9:9] Alarm B flag 
            Object *wutf; // [10:10] Wakeup timer flag 
            Object *tsf; // [11:11] Time-stamp flag 
            Object *tsovf; // [12:12] Time-stamp overflow flag 
            Object *tamp1f; // [13:13] Tamper detection flag 
            Object *tamp2f; // [14:14] TAMPER2 detection flag 
            Object *recalpf; // [16:16] Recalibration pending Flag  
          } isr; 
          
          // PRER (Prescaler register) bitfields.
          struct { 
            Object *prediv_s; // [0:14] Synchronous prescaler factor 
            Object *prediv_a; // [16:22] Asynchronous prescaler factor  
          } prer; 
          
          // WUTR (Wakeup timer register) bitfields.
          struct { 
            Object *wut; // [0:15] Wakeup auto-reload value bits  
          } wutr; 
          
          // CALIBR (Calibration register) bitfields.
          struct { 
            Object *dc; // [0:4] Digital calibration 
            Object *dcs; // [7:7] Digital calibration sign  
          } calibr; 
          
          // ALRMAR (Alarm A register) bitfields.
          struct { 
            Object *su; // [0:3] Second units in BCD format 
            Object *st; // [4:6] Second tens in BCD format 
            Object *msk1; // [7:7] Alarm A seconds mask 
            Object *mnu; // [8:11] Minute units in BCD format 
            Object *mnt; // [12:14] Minute tens in BCD format 
            Object *msk2; // [15:15] Alarm A minutes mask 
            Object *hu; // [16:19] Hour units in BCD format 
            Object *ht; // [20:21] Hour tens in BCD format 
            Object *pm; // [22:22] AM/PM notation 
            Object *msk3; // [23:23] Alarm A hours mask 
            Object *du; // [24:27] Date units or day in BCD format 
            Object *dt; // [28:29] Date tens in BCD format 
            Object *wdsel; // [30:30] Week day selection 
            Object *msk4; // [31:31] Alarm A date mask  
          } alrmar; 
          
          // ALRMBR (Alarm B register) bitfields.
          struct { 
            Object *su; // [0:3] Second units in BCD format 
            Object *st; // [4:6] Second tens in BCD format 
            Object *msk1; // [7:7] Alarm B seconds mask 
            Object *mnu; // [8:11] Minute units in BCD format 
            Object *mnt; // [12:14] Minute tens in BCD format 
            Object *msk2; // [15:15] Alarm B minutes mask 
            Object *hu; // [16:19] Hour units in BCD format 
            Object *ht; // [20:21] Hour tens in BCD format 
            Object *pm; // [22:22] AM/PM notation 
            Object *msk3; // [23:23] Alarm B hours mask 
            Object *du; // [24:27] Date units or day in BCD format 
            Object *dt; // [28:29] Date tens in BCD format 
            Object *wdsel; // [30:30] Week day selection 
            Object *msk4; // [31:31] Alarm B date mask  
          } alrmbr; 
          
          // WPR (Write protection register) bitfields.
          struct { 
            Object *key; // [0:7] Write protection key  
          } wpr; 
          
          // SSR (Sub second register) bitfields.
          struct { 
            Object *ss; // [0:15] Sub second value  
          } ssr; 
          
          // SHIFTR (Shift control register) bitfields.
          struct { 
            Object *subfs; // [0:14] Subtract a fraction of a second 
            Object *add1s; // [31:31] Add one second  
          } shiftr; 
          
          // TSTR (Time stamp time register) bitfields.
          struct { 
            Object *su; // [0:3] Second units in BCD format 
            Object *st; // [4:6] Second tens in BCD format 
            Object *mnu; // [8:11] Minute units in BCD format 
            Object *mnt; // [12:14] Minute tens in BCD format 
            Object *hu; // [16:19] Hour units in BCD format 
            Object *ht; // [20:21] Hour tens in BCD format 
            Object *pm; // [22:22] AM/PM notation  
          } tstr; 
          
          // TSDR (Time stamp date register) bitfields.
          struct { 
            Object *du; // [0:3] Date units in BCD format 
            Object *dt; // [4:5] Date tens in BCD format 
            Object *mu; // [8:11] Month units in BCD format 
            Object *mt; // [12:12] Month tens in BCD format 
            Object *wdu; // [13:15] Week day units  
          } tsdr; 
          
          // TSSSR (Timestamp sub second register) bitfields.
          struct { 
            Object *ss; // [0:15] Sub second value  
          } tsssr; 
          
          // CALR (Calibration register) bitfields.
          struct { 
            Object *calm; // [0:8] Calibration minus 
            Object *calw16; // [13:13] Use a 16-second calibration cycle period 
            Object *calw8; // [14:14] Use an 8-second calibration cycle period 
            Object *calp; // [15:15] Increase frequency of RTC by 488.5 ppm  
          } calr; 
          
          // TAFCR (Tamper and alternate function configuration register) bitfields.
          struct { 
            Object *tamp1e; // [0:0] Tamper 1 detection enable 
            Object *tamp1trg; // [1:1] Active level for tamper 1 
            Object *tampie; // [2:2] Tamper interrupt enable 
            Object *tamp2e; // [3:3] Tamper 2 detection enable 
            Object *tamp2trg; // [4:4] Active level for tamper 2 
            Object *tampts; // [7:7] Activate timestamp on tamper detection event 
            Object *tampfreq; // [8:10] Tamper sampling frequency 
            Object *tampflt; // [11:12] Tamper filter count 
            Object *tampprch; // [13:14] Tamper precharge duration 
            Object *tamppudis; // [15:15] TAMPER pull-up disable 
            Object *tamp1insel; // [16:16] TAMPER1 mapping 
            Object *tsinsel; // [17:17] TIMESTAMP mapping 
            Object *alarmouttype; // [18:18] AFO_ALARM output type  
          } tafcr; 
          
          // ALRMASSR (Alarm A sub second register) bitfields.
          struct { 
            Object *ss; // [0:14] Sub seconds value 
            Object *maskss; // [24:27] Mask the most-significant bits starting at this bit  
          } alrmassr; 
          
          // ALRMBSSR (Alarm B sub second register) bitfields.
          struct { 
            Object *ss; // [0:14] Sub seconds value 
            Object *maskss; // [24:27] Mask the most-significant bits starting at this bit  
          } alrmbssr; 
          
          // BKP0R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp0r; 
          
          // BKP1R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp1r; 
          
          // BKP2R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp2r; 
          
          // BKP3R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp3r; 
          
          // BKP4R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp4r; 
          
          // BKP5R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp5r; 
          
          // BKP6R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp6r; 
          
          // BKP7R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp7r; 
          
          // BKP8R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp8r; 
          
          // BKP9R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp9r; 
          
          // BKP10R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp10r; 
          
          // BKP11R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp11r; 
          
          // BKP12R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp12r; 
          
          // BKP13R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp13r; 
          
          // BKP14R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp14r; 
          
          // BKP15R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp15r; 
          
          // BKP16R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp16r; 
          
          // BKP17R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp17r; 
          
          // BKP18R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp18r; 
          
          // BKP19R (Backup register) bitfields.
          struct { 
            Object *bkp; // [0:31] BKP  
          } bkp19r; 
        } fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32RTCState;

// ----------------------------------------------------------------------------

#endif /* STM32_RTC_H_ */
