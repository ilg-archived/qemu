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

void get_system_memory_with_stm32_alias(cortex_m_core_info *cm_info);

qemu_irq *stm32f407vg_init(MachineState *machine);
qemu_irq *stm32f407zg_init(MachineState *machine);
qemu_irq *stm32f103rb_init(MachineState *machine);
qemu_irq *stm32f107vc_init(MachineState *machine);


#endif /* HW_ARM_STM32_H */