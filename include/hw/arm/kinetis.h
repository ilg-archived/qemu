/*
 * Freescale Kinetis Cortex-M devices emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#ifndef HW_ARM_KINETIS_H
#define HW_ARM_KINETIS_H 1

#include "hw/boards.h"
#include "hw/arm/cortexm.h"

void kinetis_board_init(MachineState *machine, QEMUMachine *qm);

qemu_irq *mk20dx128vlh5_mcu_init(MachineState *machine);
qemu_irq *mk64fn1m0vll12_mcu_init(MachineState *machine);
qemu_irq *mk60fn1m0vlq12_mcu_init(MachineState *machine);
qemu_irq *mkl25z128vlk4_mcu_init(MachineState *machine);
qemu_irq *mkl26z128vlh4_mcu_init(MachineState *machine);
qemu_irq *mkl46z256vll4_mcu_init(MachineState *machine);
qemu_irq *mk22fn512vlh12_mcu_init(MachineState *machine);
qemu_irq *mkl43z256vlh4_mcu_init(MachineState *machine);

#endif /* HW_ARM_KINETIS_H */