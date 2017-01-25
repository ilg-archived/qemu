/*
 * STM32- I2C(Inter-integrated circuit) emulation.
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

#ifndef STM32_I2C_H_
#define STM32_I2C_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_I2CDEVICE_PATH_STM32"I2C"

// ----------------------------------------------------------------------------

// Note: the "port-index" property has type "int".
typedef enum {
    // TODO: keep this list in ascending order.
STM32_PORT_I2C1,
STM32_PORT_I2C2,
STM32_PORT_I2C_UNDEFINED = 0xFF,
} stm32_i2c_index_t;
// ----------------------------------------------------------------------------

#define TYPE_STM32_I2CTYPE_STM32_PREFIX "i2c" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_I2C_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32I2CParentClass;
typedef PeripheralState STM32I2CParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_I2C_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32I2CClass, (obj), TYPE_STM32_I2C)
#define STM32_I2C_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32I2CClass, (klass), TYPE_STM32_I2C)

typedef struct {
    // private: 
    STM32I2CParentClass parent_class;
    // public: 

    // None, so far.
} STM32I2CClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_I2C_STATE(obj) \
    OBJECT_CHECK(STM32I2CState, (obj), TYPE_STM32_I2C)

typedef struct {
    // private:
    STM32I2CParentState parent_obj;
    // public:

    const STM32Capabilities *capabilities;

    // TODO: remove this if the peripheral is always enabled.
    // Points to the bitfield that enables the peripheral.
    Object *enabling_bit;

// Remove it if there is only one port
    stm32_i2c_index_t port_index;
union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // F0I2C(Inter-integrated circuit) registers.
        struct { 
Object *cr1; // 0x0(Control register 1) 
Object *cr2; // 0x4(Control register 2) 
Object *oar1; // 0x8(Own address register 1) 
Object *oar2; // 0xC(Own address register 2) 
Object *timingr; // 0x10(Timing register) 
Object *timeoutr; // 0x14(Status register 1) 
Object *isr; // 0x18(Interrupt and Status register) 
Object *icr; // 0x1C(Interrupt clear register) 
Object *pecr; // 0x20(PEC register) 
Object *rxdr; // 0x24(Receive data register) 
Object *txdr; // 0x28(Transmit data register) 
} reg;

        struct { 
// CR1(Control register 1) bitfields.
          struct { 
Object *pe; // [0:0] Peripheral enableObject *txie; // [1:1] TX Interrupt enableObject *rxie; // [2:2] RX Interrupt enableObject *addrie; // [3:3] Address match interrupt enable (slave only)Object *nackie; // [4:4] Not acknowledge received interrupt enableObject *stopie; // [5:5] STOP detection Interrupt enableObject *tcie; // [6:6] Transfer Complete interrupt enableObject *errie; // [7:7] Error interrupts enableObject *dnf; // [8:11] Digital noise filterObject *anfoff; // [12:12] Analog noise filter OFFObject *swrst; // [13:13] Software resetObject *txdmaen; // [14:14] DMA transmission requests enableObject *rxdmaen; // [15:15] DMA reception requests enableObject *sbc; // [16:16] Slave byte controlObject *nostretch; // [17:17] Clock stretching disableObject *wupen; // [18:18] Wakeup from STOP enableObject *gcen; // [19:19] General call enableObject *smbhen; // [20:20] SMBus Host address enableObject *smbden; // [21:21] SMBus Device Default address enableObject *alerten; // [22:22] SMBUS alert enableObject *pecen; // [23:23] PEC enable} cr1; 
// CR2(Control register 2) bitfields.
          struct { 
Object *sadd0; // [0:0] Slave address bit 0 (master mode)Object *sadd1; // [1:7] Slave address bit 7:1 (master mode)Object *sadd8; // [8:9] Slave address bit 9:8 (master mode)Object *rd_wrn; // [10:10] Transfer direction (master mode)Object *add10; // [11:11] 10-bit addressing mode (master mode)Object *head10r; // [12:12] 10-bit address header only read direction (master receiver mode)Object *start; // [13:13] Start generationObject *stop; // [14:14] Stop generation (master mode)Object *nack; // [15:15] NACK generation (slave mode)Object *nbytes; // [16:23] Number of bytesObject *reload; // [24:24] NBYTES reload modeObject *autoend; // [25:25] Automatic end mode (master mode)Object *pecbyte; // [26:26] Packet error checking byte} cr2; 
// OAR1(Own address register 1) bitfields.
          struct { 
Object *oa1_0; // [0:0] Interface addressObject *oa1_1; // [1:7] Interface addressObject *oa1_8; // [8:9] Interface addressObject *oa1mode; // [10:10] Own Address 1 10-bit modeObject *oa1en; // [15:15] Own Address 1 enable} oar1; 
// OAR2(Own address register 2) bitfields.
          struct { 
Object *oa2; // [1:7] Interface addressObject *oa2msk; // [8:10] Own Address 2 masksObject *oa2en; // [15:15] Own Address 2 enable} oar2; 
// TIMINGR(Timing register) bitfields.
          struct { 
Object *scll; // [0:7] SCL low period (master mode)Object *sclh; // [8:15] SCL high period (master mode)Object *sdadel; // [16:19] Data hold timeObject *scldel; // [20:23] Data setup timeObject *presc; // [28:31] Timing prescaler} timingr; 
// TIMEOUTR(Status register 1) bitfields.
          struct { 
Object *timeouta; // [0:11] Bus timeout AObject *tidle; // [12:12] Idle clock timeout detectionObject *timouten; // [15:15] Clock timeout enableObject *timeoutb; // [16:27] Bus timeout BObject *texten; // [31:31] Extended clock timeout enable} timeoutr; 
// ISR(Interrupt and Status register) bitfields.
          struct { 
Object *txe; // [0:0] Transmit data register empty (transmitters)Object *txis; // [1:1] Transmit interrupt status (transmitters)Object *rxne; // [2:2] Receive data register not empty (receivers)Object *addr; // [3:3] Address matched (slave mode)Object *nackf; // [4:4] Not acknowledge received flagObject *stopf; // [5:5] Stop detection flagObject *tc; // [6:6] Transfer Complete (master mode)Object *tcr; // [7:7] Transfer Complete ReloadObject *berr; // [8:8] Bus errorObject *arlo; // [9:9] Arbitration lostObject *ovr; // [10:10] Overrun/Underrun (slave mode)Object *pecerr; // [11:11] PEC Error in receptionObject *timeout; // [12:12] Timeout or t_low detection flagObject *alert; // [13:13] SMBus alertObject *busy; // [15:15] Bus busyObject *dir; // [16:16] Transfer direction (Slave mode)Object *addcode; // [17:23] Address match code (Slave mode)} isr; 
// ICR(Interrupt clear register) bitfields.
          struct { 
Object *addrcf; // [3:3] Address Matched flag clearObject *nackcf; // [4:4] Not Acknowledge flag clearObject *stopcf; // [5:5] Stop detection flag clearObject *berrcf; // [8:8] Bus error flag clearObject *arlocf; // [9:9] Arbitration lost flag clearObject *ovrcf; // [10:10] Overrun/Underrun flag clearObject *peccf; // [11:11] PEC Error flag clearObject *timoutcf; // [12:12] Timeout detection flag clearObject *alertcf; // [13:13] Alert flag clear} icr; 
// PECR(PEC register) bitfields.
          struct { 
Object *pec; // [0:7] Packet error checking register} pecr; 
// RXDR(Receive data register) bitfields.
          struct { 
Object *rxdata; // [0:7] 8-bit receive data} rxdr; 
// TXDR(Transmit data register) bitfields.
          struct { 
Object *txdata; // [0:7] 8-bit transmit data} txdr; 
} fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32I2CState;

// ----------------------------------------------------------------------------

#endif /* STM32_I2C_H_ */
