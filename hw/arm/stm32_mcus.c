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

/*
 Flash size:
 8 = 64K
 B = 128K
 C = 256K
 E = 512K
 F = 768K
 G = 1024K
 I = 2048K
 */

/* ----- STM32F051R8 ----- */
static cortex_m_core_info stm32f051r8_core_info = {
    .device_name = "STM32F051R8",
    .flash_size_kb = 64,
    .sram_size_kb = 8,
};

qemu_irq *stm32f051r8_mcu_init(MachineState *machine)
{
    get_system_memory_with_stm32_alias(&stm32f051r8_core_info);
    return cortex_m0_core_init(&stm32f051r8_core_info, machine);
}

/* ----- STM32F100RB ----- */
static cortex_m_core_info stm32f100rb_core_info = {
    .device_name = "STM32F100RB",
    .flash_size_kb = 128,
    .sram_size_kb = 8,
};

qemu_irq *stm32f100rb_mcu_init(MachineState *machine)
{
    get_system_memory_with_stm32_alias(&stm32f100rb_core_info);
    return cortex_m3_core_init(&stm32f100rb_core_info, machine);
}

/* ----- STM32F103RB ----- */
static cortex_m_core_info stm32f103rb_core_info = {
    .device_name = "STM32F103RB",
    .flash_size_kb = 128,
    .sram_size_kb = 20,
    .has_mpu = true,
};

qemu_irq *stm32f103rb_mcu_init(MachineState *machine)
{
    get_system_memory_with_stm32_alias(&stm32f103rb_core_info);
    return cortex_m3_core_init(&stm32f103rb_core_info, machine);
}

/* ----- STM32F107VC ----- */
static cortex_m_core_info stm32f107vc_core_info = {
    .device_name = "STM32F107VC",
    .flash_size_kb = 256,
    .sram_size_kb = 64,
    .has_mpu = true,
};

qemu_irq *stm32f107vc_mcu_init(MachineState *machine)
{
    get_system_memory_with_stm32_alias(&stm32f107vc_core_info);
    return cortex_m3_core_init(&stm32f107vc_core_info, machine);
}

/* ----- STM32L152RE ----- */
static cortex_m_core_info stm32l152re_core_info = {
    .device_name = "STM32L152RE",
    .flash_size_kb = 512,
    .sram_size_kb = 80,
    .has_mpu = true,
};

qemu_irq *stm32l152re_mcu_init(MachineState *machine)
{
    get_system_memory_with_stm32_alias(&stm32l152re_core_info);
    return cortex_m3_core_init(&stm32l152re_core_info, machine);
}

/* ----- STM32F205RF ----- */
static cortex_m_core_info stm32f205rf_core_info = {
    .device_name = "STM32F205RF",
    .flash_size_kb = 768,
    .sram_size_kb = 128, /* No CCM */
    .has_mpu = true,
};

qemu_irq *stm32f205rf_mcu_init(MachineState *machine)
{
    get_system_memory_with_stm32_alias(&stm32f205rf_core_info);
    return cortex_m3_core_init(&stm32f205rf_core_info, machine);
}

/* ----- STM32F303VC ----- */
static cortex_m_core_info stm32f303vc_core_info = {
    .device_name = "STM32F303VC",
    .flash_size_kb = 256,
    .sram_size_kb = 40,
    .has_mpu = true,
    .has_fpu = true,
};

qemu_irq *stm32f303vc_mcu_init(MachineState *machine)
{
    get_system_memory_with_stm32_alias(&stm32f303vc_core_info);
    return cortex_m4_core_init(&stm32f303vc_core_info, machine);
}

/* ----- STM32F334R8 ----- */
static cortex_m_core_info stm32f334r8_core_info = {
    .device_name = "STM32F334R8",
    .flash_size_kb = 64,
    .sram_size_kb = 12,
    .has_mpu = true,
    .has_fpu = true,
};

qemu_irq *stm32f334r8_mcu_init(MachineState *machine)
{
    get_system_memory_with_stm32_alias(&stm32f334r8_core_info);
    return cortex_m4_core_init(&stm32f334r8_core_info, machine);
}

/* ----- STM32F405RG ----- */
static cortex_m_core_info stm32f405rg_core_info = {
    .device_name = "STM32F405RG",
    .flash_size_kb = 1024,
    .sram_size_kb = 128, /* 64K CCM not counted */
    .has_mpu = true,
    .has_fpu = true,
};

qemu_irq *stm32f405rg_mcu_init(MachineState *machine)
{
    get_system_memory_with_stm32_alias(&stm32f405rg_core_info);
    return cortex_m4_core_init(&stm32f405rg_core_info, machine);
}

/* ----- STM32F407VG ----- */
static cortex_m_core_info stm32f407vg_core_info = {
    .device_name = "STM32F407VG",
    .flash_size_kb = 1024,
    .sram_size_kb = 128, /* 64K CCM not counted */
    .has_mpu = true,
    .has_fpu = true,
};

qemu_irq *stm32f407vg_mcu_init(MachineState *machine)
{
    get_system_memory_with_stm32_alias(&stm32f407vg_core_info);
    return cortex_m4_core_init(&stm32f407vg_core_info, machine);
}

/* ----- STM32F407ZG ----- */
static cortex_m_core_info stm32f407zg_core_info = {
    .device_name = "STM32F407ZG",
    .flash_size_kb = 1024,
    .sram_size_kb = 128, /* 64K CCM not counted */
    .has_mpu = true,
    .has_fpu = true,
};

qemu_irq *stm32f407zg_mcu_init(MachineState *machine)
{
    get_system_memory_with_stm32_alias(&stm32f407zg_core_info);
    return cortex_m4_core_init(&stm32f407zg_core_info, machine);
}

/* ----- STM32F411RE ----- */
static cortex_m_core_info stm32f411re_core_info = {
    .device_name = "STM32F411RE",
    .flash_size_kb = 512,
    .sram_size_kb = 128, /* No CCM */
    .has_mpu = true,
    .has_fpu = true,
};

qemu_irq *stm32f411re_mcu_init(MachineState *machine)
{
    get_system_memory_with_stm32_alias(&stm32f411re_core_info);
    return cortex_m4_core_init(&stm32f411re_core_info, machine);
}

/* ----- STM32F429ZI ----- */
static cortex_m_core_info stm32f429zi_core_info = {
    .device_name = "STM32F429ZI",
    .flash_size_kb = 2048,
    .sram_size_kb = 192, /* 64K CCM not counted */
    .has_mpu = true,
    .has_fpu = true,
};

qemu_irq *stm32f429zi_mcu_init(MachineState *machine)
{
    get_system_memory_with_stm32_alias(&stm32f429zi_core_info);
    return cortex_m4_core_init(&stm32f429zi_core_info, machine);
}

