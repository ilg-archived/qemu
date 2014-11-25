/*
 * Infineon XMC devices emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#ifndef HW_ARM_XMC_H
#define HW_ARM_XMC_H 1

#include "hw/boards.h"
#include "hw/arm/cortexm.h"

void xmc_board_init(MachineState *machine, QEMUMachine *qm);

qemu_irq *xmc4500_f100k1024_mcu_init(MachineState *machine);
qemu_irq *xmc4500_f100f1024_mcu_init(MachineState *machine);
qemu_irq *xmc4500_f144k1024_mcu_init(MachineState *machine);
qemu_irq *xmc4400_f100k512_mcu_init(MachineState *machine);
qemu_irq *xmc4200_q48k256_mcu_init(MachineState *machine);
qemu_irq *xmc1300_t038x200_mcu_init(MachineState *machine);
qemu_irq *xmc1302_t038x200_mcu_init(MachineState *machine);
qemu_irq *xmc1201_t038x200_mcu_init(MachineState *machine);
qemu_irq *xmc1100_t038x064_mcu_init(MachineState *machine);
qemu_irq *xmc1100_q024f0064_mcu_init(MachineState *machine);

#endif /* HW_ARM_XMC_H */
