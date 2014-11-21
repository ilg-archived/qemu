/*
 * STM32 Cortex-M devices emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 * Copyright (c) 2010 Andre Beckus
 *
 * This code is licensed under the GPL.
 */

#include "hw/arm/stm32.h"
#include "hw/arm/cortexm.h"
#include "exec/address-spaces.h"

/* The STM32 family stores its Flash memory at some base address in memory
 * (0x08000000 for medium density devices), and then aliases it to the
 * boot memory space, which starts at 0x00000000 (the "System Memory" can also
 * be aliased to 0x00000000, but this is not implemented here). The processor
 * executes the code in the aliased memory at 0x00000000.  We need to make a
 * QEMU alias so that reads in the 0x08000000 area are passed through to the
 * 0x00000000 area. Note that this is the opposite of real hardware, where the
 * memory at 0x00000000 passes reads through the "real" flash memory at
 * 0x08000000, but it works the same either way. */

void get_system_memory_with_stm32_alias(cortex_m_core_info *cm_info)
{
    assert(cm_info != NULL);

    int flash_size_kb = cm_info->flash_size_kb;

    /* Get system memory region, it must start at 0 */
    MemoryRegion *address_space_mem = get_system_memory();

    /* Allocate a new region alias */
    MemoryRegion *flash_alias_mem = g_malloc(sizeof(MemoryRegion));

    /* Initialise the new region */
    memory_region_init_alias(
                             flash_alias_mem,
                             NULL,
                             "stm32-flash-alias-mem",
                             address_space_mem,
                             0,
                             flash_size_kb);

    /* Alias it as the STM specific 0x08000000 */
    memory_region_add_subregion(address_space_mem, 0x08000000, flash_alias_mem);

    /* Store the adjusted region in the structure passed to cortex_m_init() */
    cm_info->system_memory = address_space_mem;
}

/* ----- STM32F103RB ----- */
static cortex_m_core_info stm32f103rb_core_info = {
    .device_name = "STM32F103RB",
    .flash_size_kb = 128,
    .sram_size_kb = 20
};

qemu_irq *stm32f103rb_init(MachineState *machine)
{
    get_system_memory_with_stm32_alias(&stm32f103rb_core_info);
    return cortex_m3_init(&stm32f103rb_core_info, machine);
}

/* ----- STM32F107VC ----- */
static cortex_m_core_info stm32f107vc_core_info = {
    .device_name = "STM32F107VC",
    .flash_size_kb = 256,
    .sram_size_kb = 64
};

qemu_irq *stm32f107vc_init(MachineState *machine)
{
    get_system_memory_with_stm32_alias(&stm32f107vc_core_info);
    return cortex_m3_init(&stm32f107vc_core_info, machine);
}

/* ----- STM32F407VG ----- */
static cortex_m_core_info stm32f407vg_core_info = {
    .device_name = "STM32F407VG",
    .flash_size_kb = 1024,
    .sram_size_kb = 196,
    .has_mmu = true,
    .has_fpu = true,
};

qemu_irq *stm32f407vg_init(MachineState *machine)
{
    get_system_memory_with_stm32_alias(&stm32f407vg_core_info);
    return cortex_m4_init(&stm32f407vg_core_info, machine);
}

/* ----- STM32F407ZG ----- */
static cortex_m_core_info stm32f407zg_core_info = {
    .device_name = "STM32F407ZG",
    .flash_size_kb = 1024,
    .sram_size_kb = 196,
    .has_mmu = true,
    .has_fpu = true,
};

qemu_irq *stm32f407zg_init(MachineState *machine)
{
    get_system_memory_with_stm32_alias(&stm32f407zg_core_info);
    return cortex_m4_init(&stm32f407zg_core_info, machine);
}