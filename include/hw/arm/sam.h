/*
 * Atmel SAM devices emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#ifndef HW_ARM_SAM_H
#define HW_ARM_SAM_H 1

#include "hw/boards.h"
#include "hw/arm/cortexm.h"

void sam_board_init(MachineState *machine, QEMUMachine *qm);

qemu_irq *sam3s4b_mcu_init(MachineState *machine);

#endif /* HW_ARM_SAM_H */
