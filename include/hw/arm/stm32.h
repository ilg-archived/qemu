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
#include "hw/sysbus.h"

#define TYPE_STM32F103RB "STM32F103RB"
#define STM32F103RBC_STATE(obj) \
    OBJECT_CHECK(stm32f1_state, (obj), TYPE_STM32F103RB)

typedef struct stm32f1_state {
	/*< private >*/
	SysBusDevice parent_obj;
	/*< public >*/

	char *kernel_filename;
	char *cpu_model;
	uint32_t ram_size;

	/* TODO: add specific structures */
} stm32f1_state;

void
stm32_board_init(MachineState *machine, QEMUMachine *qm);
void
stm32_mcu_init(MachineState *machine, const char *mcu_type);

void
stm32_get_system_memory_with_alias(cortex_m_core_info *cm_info);

/* TODO: remove them */
qemu_irq *
stm32f407vg_mcu_init(MachineState *machine);
qemu_irq *
stm32f407zg_mcu_init(MachineState *machine);
qemu_irq *
stm32f405rg_mcu_init(MachineState *machine);
qemu_irq *
stm32f411re_mcu_init(MachineState *machine);
qemu_irq *
stm32f429zi_mcu_init(MachineState *machine);
qemu_irq *
stm32f334r8_mcu_init(MachineState *machine);
qemu_irq *
stm32f303vc_mcu_init(MachineState *machine);
qemu_irq *
stm32f205rf_mcu_init(MachineState *machine);
qemu_irq *
stm32f107vc_mcu_init(MachineState *machine);
qemu_irq *
stm32f103rb_mcu_init(MachineState *machine);
qemu_irq *
stm32f100rb_mcu_init(MachineState *machine);
qemu_irq *
stm32f051r8_mcu_init(MachineState *machine);
qemu_irq *
stm32l152re_mcu_init(MachineState *machine);

#endif /* HW_ARM_STM32_H */
