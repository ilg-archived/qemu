/*
 * Cortex-M System emulation.
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#include "config.h"
#include "sysemu/sysemu.h"
#include "hw/arm/cortexm.h"
#include "qemu/option.h"
#include "qemu/config-file.h"
#include "hw/arm/arm.h"
#include "exec/address-spaces.h"
#include "hw/sysbus.h"
#include "qemu/error-report.h"
#include "sysemu/qtest.h"
#include "hw/loader.h"
#include "elf.h"
#include "cpu.h"

/* Redefined from armv7m.c */
#define TYPE_BITBAND "ARM,bitband-memory"

static Property cortexm_mcu_properties[] =
{
DEFINE_PROP_STRING("kernel-filename", CortexMState, kernel_filename),
DEFINE_PROP_STRING("cpu-model", CortexMState, cpu_model),
DEFINE_PROP_UINT32("ram-sizeK", CortexMState, ram_size_kb, 0),
DEFINE_PROP_UINT32("flash-sizeK", CortexMState, flash_size_kb, 0),
DEFINE_PROP_END_OF_LIST(), //
		};


static void cortexm_mcu_instance_init(Object *obj)
{
	CortexMState *s = CORTEXM_MCU_STATE(obj);

#if defined(CONFIG_VERBOSE)
	if (verbosity_level >= VERBOSITY_DEBUG) {
		printf("cortexm_mcu_instance_init()\n");
	}
#endif

	// call object_initialize for internal objects
}

/**
 * Initialise the "cortexm-mcu" object. Currently there is no input data.
 * Called during module_call_init() in main().
 */
static void cortexm_mcu_class_init(ObjectClass *klass, void *data)
{
	DeviceClass *dc = DEVICE_CLASS(klass);

#if defined(CONFIG_VERBOSE)
	if (verbosity_level >= VERBOSITY_DEBUG) {
		printf("cortexm_mcu_class_init()\n");
	}
#endif
	dc->props = cortexm_mcu_properties;
}

static const TypeInfo cortexm_mcu_type_init =
{ //
		.name = TYPE_CORTEXM_MCU, //
				.parent = TYPE_SYS_BUS_DEVICE, //
				.instance_size = sizeof(CortexMState), //
				.instance_init = cortexm_mcu_instance_init, //
				.class_init = cortexm_mcu_class_init };

/* ----- Type inits. ----- */

static void cortexm_types_init()
{
	type_register_static(&cortexm_mcu_type_init);
}

type_init(cortexm_types_init);

/* ----- */

void cortexm_board_greeting(MachineState *machine, QEMUMachine *qm)
{
#if defined(CONFIG_VERBOSE)
	if (verbosity_level > 0) {
		printf("Board: '%s' (%s).\n", qm->name, qm->desc);
	}
#endif
}

/**
 * Create the device and set the common properties.
 */
DeviceState *cortexm_mcu_create(MachineState *machine, const char *mcu_type)
{
	DeviceState *dev;
	dev = qdev_create(NULL, mcu_type);

	if (machine->kernel_filename) {
		qdev_prop_set_string(dev, "kernel-filename", machine->kernel_filename);
	}

	if (machine->cpu_model) {
		qdev_prop_set_string(dev, "cpu-model", machine->cpu_model);
	}

	return dev;
}

/* ----- */

static void
cortexm_core_reset(void *opaque);

static void cortexm_bitband_init(void)
{
	DeviceState *dev;

	dev = qdev_create(NULL, TYPE_BITBAND);
	qdev_prop_set_uint32(dev, "base", 0x20000000);
	qdev_init_nofail(dev);
	sysbus_mmio_map(SYS_BUS_DEVICE(dev), 0, 0x22000000);

	dev = qdev_create(NULL, TYPE_BITBAND);
	qdev_prop_set_uint32(dev, "base", 0x40000000);
	qdev_init_nofail(dev);
	sysbus_mmio_map(SYS_BUS_DEVICE(dev), 0, 0x42000000);
}

/* Common Cortex-M core initialisation routine.  */
qemu_irq *
cortexm_core_realize(cortex_m_core_info *cm_info, CortexMState *dev_state)
{
#if defined(CONFIG_VERBOSE)
	if (verbosity_level >= VERBOSITY_DEBUG) {
		printf("cortexm_core_realize()\n");
	}
#endif

	const char *kernel_filename = NULL;
	const char *cpu_model_arg = NULL;
	int ram_size_arg_kb = 0;
	int flash_size_arg_kb = 0;
	if (dev_state) {
		kernel_filename = dev_state->kernel_filename;
		cpu_model_arg = dev_state->cpu_model;
		ram_size_arg_kb = dev_state->ram_size_kb;
		flash_size_arg_kb = dev_state->flash_size_kb;
	}

	if (cpu_model_arg) {
		/* If explicitly given via the --cpu command line option,
		 * overwrite the board MCU definition. */
		if (strcmp(cpu_model_arg, "cortex-m0") == 0) {
			cm_info->cortexm_model = CORTEX_M0;
		} else if (strcmp(cpu_model_arg, "cortex-m0p") == 0) {
			cm_info->cortexm_model = CORTEX_M0PLUS;
		} else if (strcmp(cpu_model_arg, "cortex-m1") == 0) {
			cm_info->cortexm_model = CORTEX_M1;
		} else if (strcmp(cpu_model_arg, "cortex-m3") == 0) {
			cm_info->cortexm_model = CORTEX_M3;
		} else if (strcmp(cpu_model_arg, "cortex-m4") == 0) {
			cm_info->cortexm_model = CORTEX_M4;
			cm_info->has_mpu = false;
		} else if (strcmp(cpu_model_arg, "cortex-m4f") == 0) {
			cm_info->cortexm_model = CORTEX_M4F;
			cm_info->has_mpu = true;
		} else if (strcmp(cpu_model_arg, "cortex-m7") == 0) {
			cm_info->cortexm_model = CORTEX_M7;
			cm_info->has_mpu = false;
		} else if (strcmp(cpu_model_arg, "cortex-m7f") == 0) {
			cm_info->cortexm_model = CORTEX_M7F;
			cm_info->has_mpu = true;
		} else {
			fprintf(stderr, "Illegal --cpu %s, only cortex-m* supported.\n",
					cpu_model_arg);
			exit(1);
		}
	}

	int sram_size_kb;
	if (ram_size_arg_kb != 0) {
		/* If explicitly given via the -m command line option,
		 * or by --global,
		 * overwrite the board MCU definition. */
		sram_size_kb = ram_size_arg_kb;
	} else {
		sram_size_kb = cm_info->sram_size_kb;
	}

	/* Max 32 MB ram, to avoid overlapping with the bit-banding area */
	if (sram_size_kb > 32*1024){
		sram_size_kb = 32*1024;
	}

	int flash_size_kb;
	if (flash_size_arg_kb) {
		/* If explicitly given via the  --global command line option,
		 * overwrite the board MCU definition. */
		flash_size_kb = flash_size_arg_kb;
	} else {
		flash_size_kb = cm_info->flash_size_kb;
	}
	const char *cpu_model = "?";
	const char *display_model = "?";

	switch (cm_info->cortexm_model) {
	case CORTEX_M0:
		display_model = "Cortex-M0";
		cpu_model = "cortex-m0";
		cm_info->has_mpu = false;
		cm_info->has_fpu = false;
		cm_info->fpu_type = CORTEX_M_FPU_TYPE_NONE;
		break;

	case CORTEX_M0PLUS:
		display_model = "Cortex-M0+";
		cpu_model = "cortex-m0p";
		cm_info->has_mpu = false;
		cm_info->has_fpu = false;
		cm_info->fpu_type = CORTEX_M_FPU_TYPE_NONE;
		break;

	case CORTEX_M1:
		display_model = "Cortex-M1";
		cpu_model = "cortex-m1";
		break;

	case CORTEX_M3:
		display_model = "Cortex-M3";
		cpu_model = "cortex-m3";
		cm_info->has_fpu = false;
		cm_info->fpu_type = CORTEX_M_FPU_TYPE_NONE;
		break;

	case CORTEX_M4:
		display_model = "Cortex-M4";
		cpu_model = "cortex-m4";
		cm_info->has_fpu = false;
		cm_info->fpu_type = CORTEX_M_FPU_TYPE_NONE;
		break;

	case CORTEX_M4F:
		display_model = "Cortex-M4F";
		cpu_model = "cortex-mf4";
		cm_info->has_fpu = true;
		cm_info->fpu_type = CORTEX_M_FPU_TYPE_FPV4_SP_D16;
		break;

	case CORTEX_M7:
		display_model = "Cortex-M7";
		cpu_model = "cortex-m7";
		cm_info->has_fpu = false;
		cm_info->fpu_type = CORTEX_M_FPU_TYPE_NONE;
		break;

	case CORTEX_M7F:
		display_model = "Cortex-M7F";
		cpu_model = "cortex-m7f";
		cm_info->has_fpu = true;
		cm_info->fpu_type = CORTEX_M_FPU_TYPE_FPV5_SP_D16;
		break;

	default:
		fprintf(stderr, "Illegal cortexm_model %d.\n", cm_info->cortexm_model);
		exit(1);
	}

#if defined(CONFIG_VERBOSE)
	if (verbosity_level > 0) {
		const char *cmdline;

		printf("Device: '%s' (%s", cm_info->device_name, display_model);
		if (cm_info->has_mpu) {
			printf(", MPU");
		}
		if (cm_info->has_fpu) {
			printf(", FPU");
		}
		printf("), Flash: %d KB, RAM: %d KB.\n", flash_size_kb, sram_size_kb);
		if (kernel_filename) {
			printf("Image: '%s'.\n", kernel_filename);
		}

		cmdline = semihosting.cmdline;
		if (cmdline != NULL) {
			printf("Command line: '%s' (%d bytes).\n", cmdline,
					(int) strlen(cmdline));
		}
	}
#endif

	/* ----- Create CPU based on model. ----- */
	ARMCPU *cpu;
	cpu = cpu_arm_init(cpu_model);
	if (cpu == NULL) {
		fprintf(stderr, "Unable to find CPU definition %s\n", cpu_model);
		exit(1);
	}
	dev_state->cpu = cpu;

	CPUARMState *env;
	env = &cpu->env;

	/* ----- Create memory regions. ----- */
	/* Get the system memory region, it must start at 0. */
	MemoryRegion *system_memory = get_system_memory();

	int flash_size = flash_size_kb * 1024;
	int sram_size = sram_size_kb * 1024;

	MemoryRegion *flash_mem = g_new(MemoryRegion, 1);
	/* Flash programming is done via the SCU, so pretend it is ROM.  */
	memory_region_init_ram(flash_mem, NULL, "cortexm.flash_mem", flash_size,
			&error_abort);
	vmstate_register_ram_global(flash_mem);
	memory_region_set_readonly(flash_mem, true);
	memory_region_add_subregion(system_memory, 0, flash_mem);

	MemoryRegion *sram_mem = g_new(MemoryRegion, 1);
	memory_region_init_ram(sram_mem, NULL, "cortexm.sram_mem", sram_size, &error_abort);
	vmstate_register_ram_global(sram_mem);
	memory_region_add_subregion(system_memory, 0x20000000, sram_mem);
	cortexm_bitband_init();

	MemoryRegion *hack_mem = g_new(MemoryRegion, 1);
	/* Hack to map an additional page of ram at the top of the address
	 * space.  This stops qemu complaining about executing code outside RAM
	 * when returning from an exception.  */
	memory_region_init_ram(hack_mem, NULL, "cortexm.hack_mem", 0x1000, &error_abort);
	vmstate_register_ram_global(hack_mem);
	memory_region_add_subregion(system_memory, 0xfffff000, hack_mem);

	/* Pass back to the MCU inits, to add further regions, like flash alias */
	cm_info->system_memory = system_memory;

	/* ----- Create the NVIC device. ----- */
	DeviceState *nvic;
	/* FIXME: make this local state.  */
	static qemu_irq pic[64];
	nvic = qdev_create(NULL, "armv7m_nvic");
	env->nvic = nvic;
	qdev_init_nofail(nvic);
	sysbus_connect_irq(SYS_BUS_DEVICE(nvic), 0,
			qdev_get_gpio_in(DEVICE(cpu), ARM_CPU_IRQ));
	for (int i = 0; i < 64; i++) {
		pic[i] = qdev_get_gpio_in(nvic, i);
	}

	/* ----- Load image. ----- */
	if (!kernel_filename && !qtest_enabled() && !with_gdb) {
		fprintf(stderr, "Guest image must be specified (using -kernel)\n");
		exit(1);
	}

	/* Fill-in a minimal boot info, required for semihosting.  */
	static struct arm_boot_info cortexm_binfo;
	cortexm_binfo.kernel_cmdline = "";
	cortexm_binfo.kernel_filename = kernel_filename;

	env->boot_info = &cortexm_binfo;

	if (kernel_filename) {
		int big_endian;
#ifdef TARGET_WORDS_BIGENDIAN
		big_endian = 1;
#else
		big_endian = 0;
#endif
		int image_size;
		uint64_t entry;
		uint64_t lowaddr;
		image_size = load_elf(kernel_filename, NULL, NULL, &entry, &lowaddr,
		NULL, big_endian, ELF_MACHINE, 1);
		if (image_size < 0) {
			image_size = load_image_targphys(kernel_filename, 0, flash_size);
			lowaddr = 0;
		}
		if (image_size < 0) {
			error_report("Could not load image '%s'", kernel_filename);
			exit(1);
		}
	}

	qemu_register_reset(cortexm_core_reset, cpu);

	/* Assume 8000000 Hz */
	/* TODO: compute according to board clock & pll settings */
	system_clock_scale = 80;

#if defined(CONFIG_VERBOSE)
	if (verbosity_level > 0) {
		printf("Cortex-M core initialised.\n");
	}
#endif

	return pic;
}

/* TODO: remove all following functions */

/* Cortex-M0 initialisation routine.  */
qemu_irq *
cortex_m0_core_init(cortex_m_core_info *cm_info, MachineState *machine)
{
	machine->cpu_model = "cortex-m0";
	cm_info->cortexm_model = CORTEX_M0;
	return cortexm_core_realize(cm_info, NULL);
}

/* Cortex-M0+ initialisation routine.  */
qemu_irq *
cortex_m0p_core_init(cortex_m_core_info *cm_info, MachineState *machine)
{
	machine->cpu_model = "cortex-m0p";
	cm_info->cortexm_model = CORTEX_M0PLUS;
	return cortexm_core_realize(cm_info, NULL);
}

/* Cortex-M3 initialisation routine.  */
qemu_irq *
cortex_m3_core_init(cortex_m_core_info *cm_info, MachineState *machine)
{
	machine->cpu_model = "cortex-m3";
	cm_info->cortexm_model = CORTEX_M3;
	return cortexm_core_realize(cm_info, NULL);
}

/* Cortex-M4 initialisation routine.  */
qemu_irq *
cortex_m4_core_init(cortex_m_core_info *cm_info, MachineState *machine)
{
	machine->cpu_model = "cortex-m4";
	cm_info->cortexm_model = CORTEX_M4;
	return cortexm_core_realize(cm_info, NULL);
}

/* Cortex-M7 initialisation routine.  */
qemu_irq *
cortex_m7_core_init(cortex_m_core_info *cm_info, MachineState *machine)
{
	machine->cpu_model = "cortex-m7";
	cm_info->cortexm_model = CORTEX_M7;
	return cortexm_core_realize(cm_info, NULL);
}

static void cortexm_core_reset(void *opaque)
{
	ARMCPU *cpu = opaque;

#if defined(CONFIG_VERBOSE)
	if (verbosity_level >= VERBOSITY_COMMON) {
		printf("Cortex-M core reset.\n");
	}
#endif
	cpu_reset(CPU(cpu));
}

/* -------------------------------------------------------------------------- */

