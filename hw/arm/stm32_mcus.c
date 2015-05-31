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
#include "qemu/error-report.h"
#include "sysemu/sysemu.h"

/* The STM32 family stores its Flash memory at some base address in memory
 * (0x08000000 for medium density devices), and then aliases it to the
 * boot memory space, which starts at 0x00000000 (the "System Memory" can also
 * be aliased to 0x00000000, but this is not implemented here). The processor
 * executes the code in the aliased memory at 0x00000000.  We need to make a
 * QEMU alias so that reads in the 0x08000000 area are passed through to the
 * 0x00000000 area. Note that this is the opposite of real hardware, where the
 * memory at 0x00000000 passes reads through the "real" flash memory at
 * 0x08000000, but it works the same either way. */

void stm32_memory_alias_realize(cortex_m_core_info *cm_info)
{
	assert(cm_info != NULL);

	int flash_size_kb = cm_info->flash_size_kb;

	/* Get system memory region, it must start at 0 */
	MemoryRegion *system_memory = cm_info->system_memory;

	/* Allocate a new region alias */
	MemoryRegion *flash_alias_mem = g_malloc(sizeof(MemoryRegion));

	/* Initialise the new region */
	memory_region_init_alias(flash_alias_mem,
	NULL, "stm32.flash_mem_alias", system_memory, 0, flash_size_kb);

	/* Alias it as the STM specific 0x08000000 */
	memory_region_add_subregion(system_memory, 0x08000000, flash_alias_mem);
}

void stm32_mcu_create(MachineState *machine, const char *mcu_type)
{
	DeviceState *dev;
	dev = cortexm_mcu_create(machine, mcu_type);

	Error *err = NULL;
	object_property_set_bool(OBJECT(dev), true, "realized", &err);
	if (err != NULL) {
		error_report("%s", error_get_pretty(err));
		exit(1);
	}
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
static cortex_m_core_info stm32f051r8_core_info =
{ .device_name = "STM32F051R8", .flash_size_kb = 64, .sram_size_kb = 8, };

qemu_irq *
stm32f051r8_mcu_init(MachineState *machine)
{
	stm32_memory_alias_realize(&stm32f051r8_core_info);
	return cortex_m0_core_init(&stm32f051r8_core_info, machine);
}

/* ----- STM32F100RB ----- */
static cortex_m_core_info stm32f100rb_core_info =
{ .device_name = "STM32F100RB", .flash_size_kb = 128, .sram_size_kb = 8, };

qemu_irq *
stm32f100rb_mcu_init(MachineState *machine)
{
	stm32_memory_alias_realize(&stm32f100rb_core_info);
	return cortex_m3_core_init(&stm32f100rb_core_info, machine);
}

/* ----- STM32F103RB ----- */
static cortex_m_core_info stm32f103rb_core_info =
{ //
		.device_name = TYPE_STM32F103RB, //
				.flash_size_kb = 128, //
				.sram_size_kb = 20, //
				.has_mpu = true, //
				.cortexm_model = CORTEX_M3, //
		};

qemu_irq *
stm32f103rb_mcu_init(MachineState *machine)
{
	stm32_memory_alias_realize(&stm32f103rb_core_info);
	return cortex_m3_core_init(&stm32f103rb_core_info, machine);
}

// ---

static void stm32f103rb_mcu_instance_init(Object *obj)
{
	// stm32f1_state *s = STM32F103RBC_STATE(obj);
	// object_initialize
#if defined(CONFIG_VERBOSE)
	if (verbosity_level >= VERBOSITY_DEBUG) {
		printf("stm32f103rb_mcu_instance_init()\n");
	}
#endif
}

static void stm32f103rb_mcu_realize(DeviceState *dev_state, Error **errp)
{
	stm32f1_state *s = STM32F103RBC_STATE(dev_state);

#if defined(CONFIG_VERBOSE)
	if (verbosity_level >= VERBOSITY_DEBUG) {
		printf("stm32f103rb_mcu_realize()\n");
	}
#endif

	cortexm_core_realize(&stm32f103rb_core_info, CORTEXM_MCU_STATE(dev_state));
	stm32_memory_alias_realize(&stm32f103rb_core_info);
}

static Property stm32f1_mcu_properties[] =
{
DEFINE_PROP_END_OF_LIST(), //
		};

static void stm32f103rb_mcu_class_init(ObjectClass *klass, void *data)
{
	DeviceClass *dc = DEVICE_CLASS(klass);

#if defined(CONFIG_VERBOSE)
	if (verbosity_level >= VERBOSITY_DEBUG) {
		printf("stm32f103rb_mcu_class_init()\n");
	}
#endif
	dc->realize = stm32f103rb_mcu_realize;
	dc->props = stm32f1_mcu_properties;
}

static const TypeInfo stm32f103rb_mcu_type_init =
{ //
		.name = TYPE_STM32F103RB, //
				.parent = TYPE_CORTEXM_MCU, //
				.instance_size = sizeof(stm32f1_state), //
				.instance_init = stm32f103rb_mcu_instance_init, //
				.class_init = stm32f103rb_mcu_class_init, };

/* ----- STM32F107VC ----- */
static cortex_m_core_info stm32f107vc_core_info =
{ .device_name = "STM32F107VC", .flash_size_kb = 256, .sram_size_kb = 64,
		.has_mpu = true, };

qemu_irq *
stm32f107vc_mcu_init(MachineState *machine)
{
	stm32_memory_alias_realize(&stm32f107vc_core_info);
	return cortex_m3_core_init(&stm32f107vc_core_info, machine);
}

/* ----- STM32L152RE ----- */
static cortex_m_core_info stm32l152re_core_info =
{ .device_name = "STM32L152RE", .flash_size_kb = 512, .sram_size_kb = 80,
		.has_mpu = true, };

qemu_irq *
stm32l152re_mcu_init(MachineState *machine)
{
	stm32_memory_alias_realize(&stm32l152re_core_info);
	return cortex_m3_core_init(&stm32l152re_core_info, machine);
}

/* ----- STM32F205RF ----- */
static cortex_m_core_info stm32f205rf_core_info =
{ .device_name = "STM32F205RF", .flash_size_kb = 768, .sram_size_kb = 128, /* No CCM */
.has_mpu = true, };

qemu_irq *
stm32f205rf_mcu_init(MachineState *machine)
{
	stm32_memory_alias_realize(&stm32f205rf_core_info);
	return cortex_m3_core_init(&stm32f205rf_core_info, machine);
}

/* ----- STM32F303VC ----- */
static cortex_m_core_info stm32f303vc_core_info =
{ .device_name = "STM32F303VC", .flash_size_kb = 256, .sram_size_kb = 40,
		.has_mpu = true, .has_fpu = true, };

qemu_irq *
stm32f303vc_mcu_init(MachineState *machine)
{
	stm32_memory_alias_realize(&stm32f303vc_core_info);
	return cortex_m4_core_init(&stm32f303vc_core_info, machine);
}

/* ----- STM32F334R8 ----- */
static cortex_m_core_info stm32f334r8_core_info =
{ .device_name = "STM32F334R8", .flash_size_kb = 64, .sram_size_kb = 12,
		.has_mpu = true, .has_fpu = true, };

qemu_irq *
stm32f334r8_mcu_init(MachineState *machine)
{
	stm32_memory_alias_realize(&stm32f334r8_core_info);
	return cortex_m4_core_init(&stm32f334r8_core_info, machine);
}

/* ----- STM32F405RG ----- */
static cortex_m_core_info stm32f405rg_core_info =
{ .device_name = "STM32F405RG", .flash_size_kb = 1024, .sram_size_kb = 128, /* 64K CCM not counted */
.has_mpu = true, .has_fpu = true, };

qemu_irq *
stm32f405rg_mcu_init(MachineState *machine)
{
	stm32_memory_alias_realize(&stm32f405rg_core_info);
	return cortex_m4_core_init(&stm32f405rg_core_info, machine);
}

/* ----- STM32F407VG ----- */
static cortex_m_core_info stm32f407vg_core_info =
{ .device_name = "STM32F407VG", .flash_size_kb = 1024, .sram_size_kb = 128, /* 64K CCM not counted */
.has_mpu = true, .has_fpu = true, };

qemu_irq *
stm32f407vg_mcu_init(MachineState *machine)
{
	stm32_memory_alias_realize(&stm32f407vg_core_info);
	return cortex_m4_core_init(&stm32f407vg_core_info, machine);
}

/* ----- STM32F407ZG ----- */
static cortex_m_core_info stm32f407zg_core_info =
{ .device_name = "STM32F407ZG", .flash_size_kb = 1024, .sram_size_kb = 128, /* 64K CCM not counted */
.has_mpu = true, .has_fpu = true, };

qemu_irq *
stm32f407zg_mcu_init(MachineState *machine)
{
	stm32_memory_alias_realize(&stm32f407zg_core_info);
	return cortex_m4_core_init(&stm32f407zg_core_info, machine);
}

/* ----- STM32F411RE ----- */
static cortex_m_core_info stm32f411re_core_info =
{ .device_name = "STM32F411RE", .flash_size_kb = 512, .sram_size_kb = 128, /* No CCM */
.has_mpu = true, .has_fpu = true, };

qemu_irq *
stm32f411re_mcu_init(MachineState *machine)
{
	stm32_memory_alias_realize(&stm32f411re_core_info);
	return cortex_m4_core_init(&stm32f411re_core_info, machine);
}

/* ----- STM32F429ZI ----- */
static cortex_m_core_info stm32f429zi_core_info =
{ .device_name = "STM32F429ZI", .flash_size_kb = 2048, .sram_size_kb = 192, /* 64K CCM not counted */
.has_mpu = true, .has_fpu = true, };

qemu_irq *
stm32f429zi_mcu_init(MachineState *machine)
{
	stm32_memory_alias_realize(&stm32f429zi_core_info);
	return cortex_m4_core_init(&stm32f429zi_core_info, machine);
}

/* ----- Type inits. ----- */

static void stm32_types_init()
{
	type_register_static(&stm32f103rb_mcu_type_init);
}

type_init(stm32_types_init);
