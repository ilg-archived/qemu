/*
 * STM32- SPI(Serial peripheral interface) emulation.
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

#ifndef STM32_SPI_H_
#define STM32_SPI_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_SPIDEVICE_PATH_STM32"SPI"

// ----------------------------------------------------------------------------

// Note: the "port-index" property has type "int".
typedef enum {
    // TODO: keep this list in ascending order.
STM32_PORT_SPI1,
STM32_PORT_SPI2,
STM32_PORT_SPI_UNDEFINED = 0xFF,
} stm32_spi_index_t;
// ----------------------------------------------------------------------------

#define TYPE_STM32_SPITYPE_STM32_PREFIX "spi" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_SPI_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32SPIParentClass;
typedef PeripheralState STM32SPIParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_SPI_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32SPIClass, (obj), TYPE_STM32_SPI)
#define STM32_SPI_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32SPIClass, (klass), TYPE_STM32_SPI)

typedef struct {
    // private: 
    STM32SPIParentClass parent_class;
    // public: 

    // None, so far.
} STM32SPIClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_SPI_STATE(obj) \
    OBJECT_CHECK(STM32SPIState, (obj), TYPE_STM32_SPI)

typedef struct {
    // private:
    STM32SPIParentState parent_obj;
    // public:

    const STM32Capabilities *capabilities;

    // TODO: remove this if the peripheral is always enabled.
    // Points to the bitfield that enables the peripheral.
    Object *enabling_bit;

// Remove it if there is only one port
    stm32_spi_index_t port_index;
union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // F0SPI(Serial peripheral interface) registers.
        struct { 
Object *cr1; // 0x0(Control register 1) 
Object *cr2; // 0x4(Control register 2) 
Object *sr; // 0x8(Status register) 
Object *dr; // 0xC(Data register) 
Object *crcpr; // 0x10(CRC polynomial register) 
Object *rxcrcr; // 0x14(RX CRC register) 
Object *txcrcr; // 0x18(TX CRC register) 
Object *i2scfgr; // 0x1C(I2S configuration register) 
Object *i2spr; // 0x20(I2S prescaler register) 
} reg;

        struct { 
// CR1(Control register 1) bitfields.
          struct { 
Object *cpha; // [0:0] Clock phaseObject *cpol; // [1:1] Clock polarityObject *mstr; // [2:2] Master selectionObject *br; // [3:5] Baud rate controlObject *spe; // [6:6] SPI enableObject *lsbfirst; // [7:7] Frame formatObject *ssi; // [8:8] Internal slave selectObject *ssm; // [9:9] Software slave managementObject *rxonly; // [10:10] Receive onlyObject *dff; // [11:11] Data frame formatObject *crcnext; // [12:12] CRC transfer nextObject *crcen; // [13:13] Hardware CRC calculation enableObject *bidioe; // [14:14] Output enable in bidirectional modeObject *bidimode; // [15:15] Bidirectional data mode enable} cr1; 
// CR2(Control register 2) bitfields.
          struct { 
Object *rxdmaen; // [0:0] Rx buffer DMA enableObject *txdmaen; // [1:1] Tx buffer DMA enableObject *ssoe; // [2:2] SS output enableObject *nssp; // [3:3] NSS pulse managementObject *frf; // [4:4] Frame formatObject *errie; // [5:5] Error interrupt enableObject *rxneie; // [6:6] RX buffer not empty interrupt enableObject *txeie; // [7:7] Tx buffer empty interrupt enableObject *ds; // [8:11] Data sizeObject *frxth; // [12:12] FIFO reception thresholdObject *ldma_rx; // [13:13] Last DMA transfer for receptionObject *ldma_tx; // [14:14] Last DMA transfer for transmission} cr2; 
// SR(Status register) bitfields.
          struct { 
Object *rxne; // [0:0] Receive buffer not emptyObject *txe; // [1:1] Transmit buffer emptyObject *chside; // [2:2] Channel sideObject *udr; // [3:3] Underrun flagObject *crcerr; // [4:4] CRC error flagObject *modf; // [5:5] Mode faultObject *ovr; // [6:6] Overrun flagObject *bsy; // [7:7] Busy flagObject *tifrfe; // [8:8] TI frame format errorObject *frlvl; // [9:10] FIFO reception levelObject *ftlvl; // [11:12] FIFO transmission level} sr; 
// DR(Data register) bitfields.
          struct { 
Object *dr; // [0:15] Data register} dr; 
// CRCPR(CRC polynomial register) bitfields.
          struct { 
Object *crcpoly; // [0:15] CRC polynomial register} crcpr; 
// RXCRCR(RX CRC register) bitfields.
          struct { 
Object *rxcrc; // [0:15] Rx CRC register} rxcrcr; 
// TXCRCR(TX CRC register) bitfields.
          struct { 
Object *txcrc; // [0:15] Tx CRC register} txcrcr; 
// I2SCFGR(I2S configuration register) bitfields.
          struct { 
Object *chlen; // [0:0] Channel length (number of bits per audio channel)Object *datlen; // [1:2] Data length to be transferredObject *ckpol; // [3:3] Steady state clock polarityObject *i2sstd; // [4:5] I2S standard selectionObject *pcmsync; // [7:7] PCM frame synchronizationObject *i2scfg; // [8:9] I2S configuration modeObject *i2se; // [10:10] I2S EnableObject *i2smod; // [11:11] I2S mode selection} i2scfgr; 
// I2SPR(I2S prescaler register) bitfields.
          struct { 
Object *i2sdiv; // [0:7] I2S Linear prescalerObject *odd; // [8:8] Odd factor for the prescalerObject *mckoe; // [9:9] Master clock output enable} i2spr; 
} fld;
      } f0;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32SPIState;

// ----------------------------------------------------------------------------

#endif /* STM32_SPI_H_ */
