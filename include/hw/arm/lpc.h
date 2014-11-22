/*
 * NXP LPC Cortex-M devices emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#ifndef HW_ARM_LPC_H
#define HW_ARM_LPC_H 1

#include "hw/boards.h"
#include "hw/arm/cortexm.h"

void lpc_board_init(MachineState *machine, QEMUMachine *qm);

qemu_irq *lpc1769fbd100_mcu_init(MachineState *machine);

#endif /* HW_ARM_LPC_H */