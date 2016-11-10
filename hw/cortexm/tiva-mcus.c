/*
 * TI Tiva Cortex-M devices emulation.
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

#include "qemu/osdep.h"

#include <hw/cortexm/tiva.h>
#include <hw/cortexm/mcu.h>

/* ----- TM4C123GH6PM ----- */
static CortexMCoreCapabilities tm4c123gh6pm_core_info = {
    //.flash_size_kb = 256,
    //.sram_size_kb = 32,
    .has_mpu = true,
    .has_fpu = true };

qemu_irq *tm4c123gh6pm_mcu_init(MachineState *machine)
{
    return cortex_m4_core_init(&tm4c123gh6pm_core_info, machine);
}

