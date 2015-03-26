/*
 * Cortex-M System emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#include "hw/arm/cortexm.h"
#include "sysemu/sysemu.h"
#include "qemu/option.h"
#include "qemu/config-file.h"
#include "hw/arm/arm.h"
#include "exec/address-spaces.h"

/* Common Cortex-M core initialisation routine.  */
qemu_irq *cortex_m_core_init(cortex_m_core_info *cm_info, MachineState *machine)
{
    int flash_size_kb = cm_info->flash_size_kb;
    int sram_size_kb = cm_info->sram_size_kb;
    
#if defined(CONFIG_VERBOSE)
    if (verbosity_level > 0) {
        QemuOpts *opts;
        const char *cmdline;
        const char *kernel_filename = machine->kernel_filename;
        const char *cpu_model = machine->cpu_model;
        
        printf("Device: '%s' (%s", cm_info->device_name, cpu_model);
        if (cm_info->has_mpu) {
            printf(", MPU");
        }
        if (cm_info->has_fpu) {
            printf(", FPU");
        }
        printf("), Flash: %d KB, RAM: %d KB.\n", flash_size_kb, sram_size_kb);
        if (kernel_filename){
            printf("Image: '%s'.\n", kernel_filename);
        }
        
        opts = qemu_opts_find(qemu_find_opts("semihosting-config"), NULL);
        cmdline = qemu_opt_get(opts, "cmdline");
        
        if (cmdline == NULL) {
            cmdline = machine->kernel_cmdline;
        }
        
        if (cmdline != NULL) {
            printf("Command line: '%s' (%d bytes).\n", cmdline,
                   (int)strlen(cmdline));
        }
    }
#endif
    
    MemoryRegion *system_memory = cm_info->system_memory;
    if (system_memory == NULL) {
        system_memory = get_system_memory();
    }
    qemu_irq *pic;
    pic = cortexm_armv7m_init(system_memory, flash_size_kb, sram_size_kb, machine);
    
    /* Assume 8000000 Hz */
    /* TODO: compute according to board clock & pll settings */
    system_clock_scale = 80;
    
    return pic;
}

/* Cortex-M0 initialisation routine.  */
qemu_irq *cortex_m0_core_init(cortex_m_core_info *cm_info, MachineState *machine)
{
    machine->cpu_model = "cortex-m0";
    cm_info->has_mpu = false;
    cm_info->has_fpu = false;
    cm_info->fpu_type = CORTEX_M_FPU_TYPE_NONE;
    return cortex_m_core_init(cm_info, machine);
}

/* Cortex-M0+ initialisation routine.  */
qemu_irq *cortex_m0p_core_init(cortex_m_core_info *cm_info, MachineState *machine)
{
    machine->cpu_model = "cortex-m0p";
    cm_info->has_mpu = false;
    cm_info->has_fpu = false;
    cm_info->fpu_type = CORTEX_M_FPU_TYPE_NONE;
    return cortex_m_core_init(cm_info, machine);
}

/* Cortex-M3 initialisation routine.  */
qemu_irq *cortex_m3_core_init(cortex_m_core_info *cm_info, MachineState *machine)
{
    machine->cpu_model = "cortex-m3";
    cm_info->has_fpu = false;
    cm_info->fpu_type = CORTEX_M_FPU_TYPE_NONE;
    return cortex_m_core_init(cm_info, machine);
}

/* Cortex-M4 initialisation routine.  */
qemu_irq *cortex_m4_core_init(cortex_m_core_info *cm_info, MachineState *machine)
{
    machine->cpu_model = "cortex-m4";
    cm_info->fpu_type = CORTEX_M_FPU_TYPE_FPV4_SP_D16;
    return cortex_m_core_init(cm_info, machine);
}

/* Cortex-M7 initialisation routine.  */
qemu_irq *cortex_m7_core_init(cortex_m_core_info *cm_info, MachineState *machine)
{
    machine->cpu_model = "cortex-m7";
    cm_info->fpu_type = CORTEX_M_FPU_TYPE_FPV5_SP_D16;
    return cortex_m_core_init(cm_info, machine);
}

/* -------------------------------------------------------------------------- */

