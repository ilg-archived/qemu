/*
 * TI Tiva Cortex-M devices emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#include "hw/arm/tiva.h"
#include "hw/arm/cortexm.h"

/* ----- TM4C123GH6PM ----- */
static CortexMCapabilities tm4c123gh6pm_core_info = {
    .device_name = "TM4C123GH6PM",
    .flash_size_kb = 256,
    .sram_size_kb = 32,
    .has_mpu = true,
    .has_fpu = true,
};

qemu_irq *tm4c123gh6pm_mcu_init(MachineState *machine)
{
    return cortex_m4_core_init(&tm4c123gh6pm_core_info, machine);
}

