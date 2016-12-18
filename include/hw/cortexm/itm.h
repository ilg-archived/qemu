/*
 * Cortex-M Instrumentation Trace Macrocell emulation.
 *
 * Copyright (c) 2015 Liviu Ionescu.
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

#ifndef CORTEXM_ITM_H_
#define CORTEXM_ITM_H_

#include "qemu/osdep.h"

#include "hw/sysbus.h"
#include "exec/address-spaces.h"
#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/helper.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_CORTEXM_ITM "/machine/mcu/cortexm/itm"

#define CORTEXM_ITM_DEFAULT_NUM_PORTS	32
#define CORTEXM_ITM_MAX_NUM_PORTS		256

// ----------------------------------------------------------------------------

#define TYPE_CORTEXM_ITM TYPE_CORTEXM_PREFIX "itm" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_CORTEXM_ITM_PARENT TYPE_SYS_BUS_DEVICE
typedef SysBusDeviceClass CortexMITMParentClass;
typedef SysBusDevice CortexMITMParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define CORTEXM_ITM_GET_CLASS(obj) \
    OBJECT_GET_CLASS(CortexMITMClass, (obj), TYPE_CORTEXM_ITM)
#define CORTEXM_ITM_CLASS(klass) \
    OBJECT_CLASS_CHECK(CortexMITMClass, (klass), TYPE_CORTEXM_ITM)

typedef struct {
    // private:
    CortexMITMParentClass parent_class;
    // public:

} CortexMITMClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define CORTEXM_ITM_STATE(obj) \
    OBJECT_CHECK(CortexMITMState, (obj), TYPE_CORTEXM_ITM)

typedef struct {
    // private:
    CortexMITMParentState parent_obj;
    // public:

    // Must be a multiple of 8
    int num_ports;

    // The memory area 0xE0000000-0xE0000FFF.
    MemoryRegion mmio;

    struct {
        /*
         * Stimulus Ports.	(UNKNOWN)
         * [31:0] STIMULUS 	WO 	Data write
         * [31:1] RESERVED 	RO
         * [0] FIFOREADY 	RO	0: port FIFO full, or port disabled
         * 					1: FIFO can accept at least one word
         *
         * Byte access [7:0]
         * Halfword access [15:0]
         * Word access [31:0]
         */
        uint32_t stim[CORTEXM_ITM_MAX_NUM_PORTS];

        /*
         * Trace Enable.	(0x0)
         * [31:0] STIMENA	RW	For bit STIMENA[n], in register TERx
         * 						0 = Port (32x+n) disabled
         * 						1 = Port (32x+n) enabled
         */
        uint32_t ter[CORTEXM_ITM_MAX_NUM_PORTS / 32];

        /*
         * Trace Privilege.	(0x0)
         * [31:0] PRIVMASK	RW	Bit [n] controls stimulus port 8n to 8n+7
         * 						0 = Unprivileged access permitted
         * 						1 = Privileged access only.
         *
         * 	Currently ignored, unprivileged access permitted.
         */
        uint32_t tpr;		// RW, 0

        /*
         * Trace Control.	RW 	(0x0) See C1.7.6
         */
        uint32_t tcr;

        /*
         * Lock Status.		RO	(0x0)
         *
         * Currently ignored.
         */
        uint32_t lsr;		// RO, 0
    } reg;

} CortexMITMState;

// ----------------------------------------------------------------------------

#endif /* CORTEXM_ITM_H_ */
