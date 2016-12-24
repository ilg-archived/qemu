/*
 * STM32 - I2C (Inter integrated circuit) emulation.
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

#define DEVICE_PATH_STM32_I2C DEVICE_PATH_STM32 "I2C"

// ----------------------------------------------------------------------------

// Note: the "port-index" property has type "int".
typedef enum {
    // TODO: keep this list in ascending order.
    STM32_PORT_I2C1,
    STM32_PORT_I2C2,
    STM32_PORT_I2C_UNDEFINED = 0xFF,
} stm32_i2c_index_t;

// ----------------------------------------------------------------------------

#define TYPE_STM32_I2C TYPE_STM32_PREFIX "i2c" TYPE_PERIPHERAL_SUFFIX

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
        // F1 I2C (Inter integrated circuit) registers.
        struct { 
          Object *cr1; // 0x0 (Control register 1) 
          Object *cr2; // 0x4 (Control register 2) 
          Object *oar1; // 0x8 (Own address register 1) 
          Object *oar2; // 0xC (Own address register 2) 
          Object *dr; // 0x10 (Data register) 
          Object *sr1; // 0x14 (Status register 1) 
          Object *sr2; // 0x18 (Status register 2) 
          Object *ccr; // 0x1C (Clock control register) 
          Object *trise; // 0x20 (TRISE register) 
        } reg;

        struct { 
          
          // CR1 (Control register 1) bitfields.
          struct { 
            Object *pe; // [0:0] Peripheral enable 
            Object *smbus; // [1:1] SMBus mode 
            Object *smbtype; // [3:3] SMBus type 
            Object *enarp; // [4:4] ARP enable 
            Object *enpec; // [5:5] PEC enable 
            Object *engc; // [6:6] General call enable 
            Object *nostretch; // [7:7] Clock stretching disable (Slave mode) 
            Object *start; // [8:8] Start generation 
            Object *stop; // [9:9] Stop generation 
            Object *ack; // [10:10] Acknowledge enable 
            Object *pos; // [11:11] Acknowledge/PEC Position (for data reception) 
            Object *pec; // [12:12] Packet error checking 
            Object *alert; // [13:13] SMBus alert 
            Object *swrst; // [15:15] Software reset  
          } cr1; 
          
          // CR2 (Control register 2) bitfields.
          struct { 
            Object *freq; // [0:5] Peripheral clock frequency 
            Object *iterren; // [8:8] Error interrupt enable 
            Object *itevten; // [9:9] Event interrupt enable 
            Object *itbufen; // [10:10] Buffer interrupt enable 
            Object *dmaen; // [11:11] DMA requests enable 
            Object *last; // [12:12] DMA last transfer  
          } cr2; 
          
          // OAR1 (Own address register 1) bitfields.
          struct { 
            Object *add0; // [0:0] Interface address 
            Object *add7; // [1:7] Interface address 
            Object *add10; // [8:9] Interface address 
            Object *addmode; // [15:15] Addressing mode (slave mode)  
          } oar1; 
          
          // OAR2 (Own address register 2) bitfields.
          struct { 
            Object *endual; // [0:0] Dual addressing mode enable 
            Object *add2; // [1:7] Interface address  
          } oar2; 
          
          // DR (Data register) bitfields.
          struct { 
            Object *dr; // [0:7] 8-bit data register  
          } dr; 
          
          // SR1 (Status register 1) bitfields.
          struct { 
            Object *sb; // [0:0] Start bit (Master mode) 
            Object *addr; // [1:1] Address sent (master mode)/matched (slave mode) 
            Object *btf; // [2:2] Byte transfer finished 
            Object *add10; // [3:3] 10-bit header sent (Master mode) 
            Object *stopf; // [4:4] Stop detection (slave mode) 
            Object *rxne; // [6:6] Data register not empty (receivers) 
            Object *txe; // [7:7] Data register empty (transmitters) 
            Object *berr; // [8:8] Bus error 
            Object *arlo; // [9:9] Arbitration lost (master mode) 
            Object *af; // [10:10] Acknowledge failure 
            Object *ovr; // [11:11] Overrun/Underrun 
            Object *pecerr; // [12:12] PEC Error in reception 
            Object *timeout; // [14:14] Timeout or Tlow error 
            Object *smbalert; // [15:15] SMBus alert  
          } sr1; 
          
          // SR2 (Status register 2) bitfields.
          struct { 
            Object *msl; // [0:0] Master/slave 
            Object *busy; // [1:1] Bus busy 
            Object *tra; // [2:2] Transmitter/receiver 
            Object *gencall; // [4:4] General call address (Slave mode) 
            Object *smbdefault; // [5:5] SMBus device default address (Slave mode) 
            Object *smbhost; // [6:6] SMBus host header (Slave mode) 
            Object *dualf; // [7:7] Dual flag (Slave mode) 
            Object *pec; // [8:15] Acket error checking register  
          } sr2; 
          
          // CCR (Clock control register) bitfields.
          struct { 
            Object *ccr; // [0:11] Clock control register in Fast/Standard mode (Master mode) 
            Object *duty; // [14:14] Fast mode duty cycle 
            Object *f_s; // [15:15] I2C master mode selection  
          } ccr; 
          
          // TRISE (TRISE register) bitfields.
          struct { 
            Object *trise; // [0:5] Maximum rise time in Fast/Standard mode (Master mode)  
          } trise; 
        } fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32I2CState;

// ----------------------------------------------------------------------------

#endif /* STM32_I2C_H_ */
