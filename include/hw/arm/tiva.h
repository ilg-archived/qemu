/*
 * TI Tiva devices emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#ifndef HW_ARM_TIVA_H
#define HW_ARM_TIVA_H 1

#include "hw/boards.h"
#include "hw/arm/cortexm.h"

void tiva_board_init(MachineState *machine, QEMUMachine *qm);

qemu_irq *tm4c123gh6pm_mcu_init(MachineState *machine);

#endif /* HW_ARM_TIVA_H */
