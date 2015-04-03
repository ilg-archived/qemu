/*
 * Cortex-M System emulation
 * 
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#ifndef HW_ARM_CORTEXM_H
#define HW_ARM_CORTEXM_H 1

#include "exec/memory.h"
#include "hw/irq.h"
#include "hw/boards.h"

#define CORTEX_M_FPU_TYPE_NONE (0)
#define CORTEX_M_FPU_TYPE_FPV4_SP_D16 (1)
#define CORTEX_M_FPU_TYPE_FPV5_SP_D16 (2)

/*
 * Used by vendor specific Cortex-M devices to pass the core
 * capabilities to the common Cortex-M initialisations. 
 */
typedef struct cortex_m_core_info {

    const char *device_name; /* the CMSIS official device name */

    MemoryRegion *system_memory; /* flash memory region, possibly with alias */
    int flash_size_kb;  /* size of main program area, in KB */
    int sram_size_kb;   /* size of main RAM area, in KB */
    int sram_begin;     /* begin address of main RAM area, if not 0x20000000 */
    
    /* Not yet used */
    int has_mpu;        /* true/false */
    int has_fpu;        /* true/false */
    int fpu_type;       /* CORTEX_M_FPU_TYPE_* */
    int nvic_bits;      /* bits used for irqs in NVIC */
} cortex_m_core_info;

qemu_irq *cortex_m_core_init(cortex_m_core_info *cm_info, MachineState *machine);
qemu_irq *cortex_m0_core_init(cortex_m_core_info *cm_info, MachineState *machine);
qemu_irq *cortex_m0p_core_init(cortex_m_core_info *cm_info, MachineState *machine);
qemu_irq *cortex_m3_core_init(cortex_m_core_info *cm_info, MachineState *machine);
qemu_irq *cortex_m4_core_init(cortex_m_core_info *cm_info, MachineState *machine);
qemu_irq *cortex_m7_core_init(cortex_m_core_info *cm_info, MachineState *machine);

#endif /* HW_ARM_CORTEXM_H */
