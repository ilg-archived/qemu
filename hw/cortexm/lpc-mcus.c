/*
 * NXP LPC Cortex-M devices emulation.
 *
 * Copyright (c) 2014 Liviu Ionescu.
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

#include "hw/arm/lpc.h"
#include <hw/cortexm/mcu.h>

/* ----- LPC1769FBD100 ----- */
static CortexMCoreCapabilities lpc1769fbd100_core_info = {
    //.flash_size_kb = 512,
    //.sram_size_kb = 32, /* +32K peripheral ram @0x2007C000 */
    //.sram_begin = 0x10000000,
    .has_mpu = true };

qemu_irq *lpc1769fbd100_mcu_init(MachineState *machine)
{
    /* TODO: make the initialisations set proper SRAM begin address */
    return cortex_m3_core_init(&lpc1769fbd100_core_info, machine);
}

