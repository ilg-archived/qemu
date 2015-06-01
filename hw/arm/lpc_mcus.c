/*
 * NXP LPC Cortex-M devices emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#include "hw/arm/lpc.h"
#include "hw/arm/cortexm.h"

/* ----- LPC1769FBD100 ----- */
static CortexMCapabilities lpc1769fbd100_core_info = {
    .device_name = "LPC1769FBD100",
    .flash_size_kb = 512,
    .sram_size_kb = 32, /* +32K peripheral ram @0x2007C000 */
    .sram_begin = 0x10000000,
    .has_mpu = true,
};

qemu_irq *lpc1769fbd100_mcu_init(MachineState *machine)
{
    /* TODO: make the initialisations set proper SRAM begin address */
    return cortex_m3_core_init(&lpc1769fbd100_core_info, machine);
}

