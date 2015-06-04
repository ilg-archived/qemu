/*
 * ARM Instrumentation Trace Macrocell.
 *
 * Copyright (c) 2015 Liviu Ionescu
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

#include "exec/address-spaces.h"

#ifndef ARMV7M_ITM_H_
#define ARMV7M_ITM_H_

#define DEFAULT_ITM_NUM_PORTS	32
#define MAX_ITM_NUM_PORTS		256

#define TYPE_ITM "armv7m_itm"
#define ITM_GET_CLASS(obj) \
    OBJECT_GET_CLASS(ITMClass, (obj), TYPE_ITM)
#define ITM_CLASS(klass) \
    OBJECT_CLASS_CHECK(ITMClass, (klass), TYPE_ITM)
#define ITM_STATE(obj) \
    OBJECT_CHECK(ITMState, (obj), TYPE_ITM)

typedef struct ITMClass {
    /*< private >*/
    SysBusDeviceClass parent_class;
    /*< public >*/

    /* No local virtual functions */
} ITMClass;

typedef struct ITMState {
    /*< private >*/
    SysBusDevice parent_obj;
    /*< public >*/

    /* Must be a multiple of 8 */
    int num_ports;

    /**
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
    uint32_t stim[MAX_ITM_NUM_PORTS];

    /**
     * Trace Enable.	(0x0)
     * [31:0] STIMENA	RW	For bit STIMENA[n], in register TERx
     * 						0 = Port (32x+n) disabled
     * 						1 = Port (32x+n) enabled
     */
    uint32_t ter[MAX_ITM_NUM_PORTS / 32];

    /**
     * Trace Privilege.	(0x0)
     * [31:0] PRIVMASK	RW	Bit [n] controls stimulus port 8n to 8n+7
     * 						0 = Unprivileged access permitted
     * 						1 = Privileged access only.
     *
     * 	Currently ignored, unprivileged access permitted.
     */
    uint32_t tpr;		// RW, 0

    /**
     * Trace Control.	RW 	(0x0) See C1.7.6
     */
    uint32_t tcr;

    /**
     * Lock Status.		RO	(0x0)
     *
     * Currently ignored.
     */
    uint32_t lsr;		// RO, 0

    /**
     * The memory area 0xE0000000-0xE0000FFF.
     */
    MemoryRegion mmio;

} ITMState;

#endif /* ARMV7M_ITM_H_ */
