/*
 * Freescale Kinetis Cortex-M devices emulation.
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

#include <hw/cortexm/kinetis.h>
#include <hw/cortexm/mcu.h>

/*
 Package identifier:
 FM = 32 QFN (5 mm x 5 mm)
 FT = 48 QFN (7 mm x 7 mm)
 LF = 48 LQFP (7 mm x 7 mm)
 LH = 64 LQFP (10 mm x 10 mm)
 MP = 64 MAPBGA (5 mm x 5 mm)
 LK = 80 LQFP (12 mm x 12 mm)
 MB = 81 MAPBGA (8 mm x 8 mm)
 LL = 100 LQFP (14 mm x 14 mm)
 ML = 104 MAPBGA (8 mm x 8 mm)
 MC = 121 MAPBGA (8 mm x 8 mm)
 LQ = 144 LQFP (20 mm x 20 mm)
 MD = 144 MAPBGA (13 mm x 13 mm)
 MJ = 256 MAPBGA (17 mm x 17 mm)
 */

/* ----- MK20DX128VLH5 ----- */
static CortexMCoreCapabilities mk20dx128vlh5_core_info = {
    //.flash_size_kb = 128, /* +32K FlexNVM at 0x10000000 */
    //.sram_size_kb = 8, /* +8K SRAM_L */
    .has_mpu = false,
    .has_fpu = false };

qemu_irq *mk20dx128vlh5_mcu_init(MachineState *machine)
{
    return cortex_m4_core_init(&mk20dx128vlh5_core_info, machine);
}

/* ----- MK22FN512VLH12 ----- */
static CortexMCoreCapabilities mk22fn512vlh12_core_info = {
    //.flash_size_kb = 512,
    //.sram_size_kb = 64, /* +64K SRAM_L */
    .has_mpu = false,
    .has_fpu = false };

qemu_irq *mk22fn512vlh12_mcu_init(MachineState *machine)
{
    return cortex_m4_core_init(&mk22fn512vlh12_core_info, machine);
}

/* ----- MK64FN1M0VLL12 ----- */
static CortexMCoreCapabilities mk64fn1m0vll12_core_info = {
    //.flash_size_kb = 1024,
    //.sram_size_kb = 192, /* +64K SRAM_L */
    .has_mpu = true,
    .has_fpu = true };

qemu_irq *mk64fn1m0vll12_mcu_init(MachineState *machine)
{
    return cortex_m4_core_init(&mk64fn1m0vll12_core_info, machine);
}

/* ----- MK60FN1M0VLQ12 ----- */
static CortexMCoreCapabilities mk60fn1m0vlq12_core_info = {
    //.flash_size_kb = 1024,
    //.sram_size_kb = 192, /* +64K SRAM_L */
    .has_mpu = true,
    .has_fpu = true };

qemu_irq *mk60fn1m0vlq12_mcu_init(MachineState *machine)
{
    return cortex_m4_core_init(&mk60fn1m0vlq12_core_info, machine);
}

/* ----- MKL25Z128VLK4 ----- */
static CortexMCoreCapabilities mkl25z128vlk4_core_info = {
    //.flash_size_kb = 128,
    //.sram_size_kb = 12, /* +4K SRAM_L */
    .has_mpu = false };

qemu_irq *mkl25z128vlk4_mcu_init(MachineState *machine)
{
    return cortex_m0p_core_init(&mkl25z128vlk4_core_info, machine);
}

/* ----- MKL26Z128VLH4 ----- */
static CortexMCoreCapabilities mkl26z128vlh4_core_info = {
    //.flash_size_kb = 128,
    //.sram_size_kb = 12, /* +4K SRAM_L */
    .has_mpu = false, };

qemu_irq *mkl26z128vlh4_mcu_init(MachineState *machine)
{
    return cortex_m0p_core_init(&mkl26z128vlh4_core_info, machine);
}

/* ----- MKL43Z256VLH4 ----- */
static CortexMCoreCapabilities mkl43z256vlh4_core_info = {
    //.flash_size_kb = 256,
    //.sram_size_kb = 24, /* +8K SRAM_L */
    .has_mpu = false };

qemu_irq *mkl43z256vlh4_mcu_init(MachineState *machine)
{
    return cortex_m0p_core_init(&mkl43z256vlh4_core_info, machine);
}

/* ----- MKL46Z256VLL4 ----- */
static CortexMCoreCapabilities mkl46z256vll4_core_info = {
    //.flash_size_kb = 256,
    //.sram_size_kb = 24, /* +8K SRAM_L */
    .has_mpu = false };

qemu_irq *mkl46z256vll4_mcu_init(MachineState *machine)
{
    return cortex_m0p_core_init(&mkl46z256vll4_core_info, machine);
}

