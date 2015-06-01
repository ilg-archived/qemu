/*
 * Atmel SAM Cortex-M devices emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#include "hw/arm/sam.h"
#include "hw/arm/cortexm.h"

/* ----- SAM3S4B ----- */
static CortexMCapabilities sam3s4b_core_info = {
    .device_name = "SAM3S4B",
    .flash_size_kb = 256,
    .sram_size_kb = 48,
    .has_mpu = true,
};

qemu_irq *sam3s4b_mcu_init(MachineState *machine)
{
    return cortex_m3_core_init(&sam3s4b_core_info, machine);
}

