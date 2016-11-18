/*
 * Infineon XMC Cortex-M devices emulation.
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

#include <hw/cortexm/xmc.h>
#include <hw/cortexm/mcu.h>

/* ----- XMC4500-F144K1024 ----- */
static CortexMCoreCapabilities xmc4500_f144k1024_core_info = {
    //.flash_size_kb = 1024,
    //.sram_size_kb = 64, /* +64K @1000 0000, +32K @3000 0000 */
    .has_mpu = true,
    .has_fpu = true };

qemu_irq *xmc4500_f144k1024_mcu_init(MachineState *machine)
{
    return cortex_m4_core_init(&xmc4500_f144k1024_core_info, machine);
}

/* ----- XMC4500-F100K1024 ----- */
static CortexMCoreCapabilities xmc4500_f100k1024_core_info = {
    //.flash_size_kb = 1024,
    //.sram_size_kb = 64, /* +64K @1000 0000, +32K @3000 0000 */
    .has_mpu = true,
    .has_fpu = true };

qemu_irq *xmc4500_f100k1024_mcu_init(MachineState *machine)
{
    return cortex_m4_core_init(&xmc4500_f100k1024_core_info, machine);
}

/* ----- XMC4500-F100F1024 ----- */
static CortexMCoreCapabilities xmc4500_f100f1024_core_info = {
    //.flash_size_kb = 1024,
    //.sram_size_kb = 64, /* +64K @1000 0000, +32K @3000 0000 */
    .has_mpu = true,
    .has_fpu = true };

qemu_irq *xmc4500_f100f1024_mcu_init(MachineState *machine)
{
    return cortex_m4_core_init(&xmc4500_f100f1024_core_info, machine);
}

/* ----- XMC4400-F100K512 ----- */
static CortexMCoreCapabilities xmc4400_f100k512_core_info = {
    //.flash_size_kb = 512,
    //.sram_size_kb = 32, /* +16K @1FFFC000, +32K @20008000 */
    .has_mpu = true,
    .has_fpu = true };

qemu_irq *xmc4400_f100k512_mcu_init(MachineState *machine)
{
    return cortex_m4_core_init(&xmc4400_f100k512_core_info, machine);
}

/* ----- XMC4200-Q48K256 ----- */
static CortexMCoreCapabilities xmc4200_q48k256_core_info = {
    //.flash_size_kb = 256,
    //.sram_size_kb = 24, /* +16K @1FFFC000 */
    .has_mpu = true,
    .has_fpu = true };

qemu_irq *xmc4200_q48k256_mcu_init(MachineState *machine)
{
    return cortex_m4_core_init(&xmc4200_q48k256_core_info, machine);
}

/* ----- XMC1302-T038X200 ----- */
static CortexMCoreCapabilities xmc1302_t038x200_core_info = {
//.flash_size_kb = 200,
//.sram_size_kb = 16
        };

qemu_irq *xmc1302_t038x200_mcu_init(MachineState *machine)
{
    return cortex_m0_core_init(&xmc1302_t038x200_core_info, machine);
}

/* ----- XMC1201-T038X200 ----- */
static CortexMCoreCapabilities xmc1201_t038x200_core_info = {
//.flash_size_kb = 200,
//.sram_size_kb = 16
        };

qemu_irq *xmc1201_t038x200_mcu_init(MachineState *machine)
{
    return cortex_m0_core_init(&xmc1201_t038x200_core_info, machine);
}

/* ----- XMC1100-T038X200 ----- */
static CortexMCoreCapabilities xmc1100_t038x064_core_info = {
//.flash_size_kb = 64,
//.sram_size_kb = 16
        };

qemu_irq *xmc1100_t038x064_mcu_init(MachineState *machine)
{
    return cortex_m0_core_init(&xmc1100_t038x064_core_info, machine);
}

/* ----- XMC1100-Q024F0064 ----- */
static CortexMCoreCapabilities xmc1100_q024f0064_core_info = {
//.flash_size_kb = 64,
//.sram_size_kb = 16
        };

qemu_irq *xmc1100_q024f0064_mcu_init(MachineState *machine)
{
    return cortex_m0_core_init(&xmc1100_q024f0064_core_info, machine);
}
