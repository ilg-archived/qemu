/*
 * STM32 Cortex-M devices emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#ifndef HW_ARM_STM32_H
#define HW_ARM_STM32_H 1

#include "hw/boards.h"
#include "hw/arm/cortexm.h"

void stm32_board_init(MachineState *machine, QEMUMachine *qm);

void get_system_memory_with_stm32_alias(cortex_m_core_info *cm_info);

qemu_irq *stm32f407vg_init(MachineState *machine);
qemu_irq *stm32f407zg_init(MachineState *machine);
qemu_irq *stm32f405rg_init(MachineState *machine);
qemu_irq *stm32f411re_init(MachineState *machine);
qemu_irq *stm32f429zi_init(MachineState *machine);
qemu_irq *stm32f334r8_init(MachineState *machine);
qemu_irq *stm32f303vc_init(MachineState *machine);
qemu_irq *stm32f205rf_init(MachineState *machine);
qemu_irq *stm32f107vc_init(MachineState *machine);
qemu_irq *stm32f103rb_init(MachineState *machine);
qemu_irq *stm32f100rb_init(MachineState *machine);
qemu_irq *stm32f051r8_init(MachineState *machine);
qemu_irq *stm32l152re_init(MachineState *machine);

#endif /* HW_ARM_STM32_H */