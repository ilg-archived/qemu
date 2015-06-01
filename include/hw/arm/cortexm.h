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
#include "hw/sysbus.h"

#define CORTEX_M_FPU_TYPE_NONE (0)
#define CORTEX_M_FPU_TYPE_FPV4_SP_D16 (1)
#define CORTEX_M_FPU_TYPE_FPV5_SP_D16 (2)

typedef enum {
	CORTEX_M0 = 1,
	CORTEX_M0PLUS,
	CORTEX_M1,
	CORTEX_M3,
	CORTEX_M4,
	CORTEX_M4F,
	CORTEX_M7,
	CORTEX_M7F
} cortexm_models_t;

/*
 * Used by vendor specific Cortex-M devices to pass the core
 * capabilities to the common Cortex-M initialisations. 
 *
 * It is copied into the CortexMState during *_instance_init() functions.
 */
typedef struct CortexMCapabilities {

	const char *device_name; /* the CMSIS official device name */

	cortexm_models_t cortexm_model; /* binary id to identify the core */

	/* The vendor values. */
	int flash_size_kb; /* size of main program area, in KB */
	int sram_size_kb; /* size of main RAM area, in KB */
	int sram_begin; /* begin address of main RAM area, if not 0x20000000 */

	/* Not yet used */
	int has_mpu; /* true/false */
	int has_fpu; /* true/false */
	int fpu_type; /* CORTEX_M_FPU_TYPE_* */
	int nvic_bits; /* bits used for irqs in NVIC */
} CortexMCapabilities;

#define TYPE_CORTEXM_MCU "cortexm-mcu"
#define CORTEXM_MCU_STATE(obj) \
    OBJECT_CHECK(CortexMState, (obj), TYPE_CORTEXM_MCU)

/**
 * Structure used to store the Cortex-M state.
 */
typedef struct CortexMState {
	/*< private >*/
	SysBusDevice parent_obj;
	/*< public >*/

	/**
	 * Core capabilities, set by *_instance_init().
	 */
	CortexMCapabilities *cm_capabilities;

	const char *kernel_filename;

	/*
	 * The following are the actual values used to initialise the object.
	 * May be different from capabilities, if explicitly overwriten.
	 */
	const char *cpu_model;
	uint32_t ram_size_kb;
	uint32_t flash_size_kb;

	MemoryRegion *system_memory; /* flash memory region */
	ARMCPU *cpu;

	/* TODO: add specific structures */
} CortexMState;

void
cortexm_board_greeting(MachineState *machine, QEMUMachine *qm);

DeviceState *
cortexm_mcu_create(MachineState *machine, const char *mcu_type);

qemu_irq *
cortexm_core_realize(CortexMState *dev_state);

void
cortexm_core_reset(CortexMState *dev_state);

// TODO: remove all when all old definitions are updated.
qemu_irq *
cortex_m0_core_init(CortexMCapabilities *cm_info, MachineState *machine);
qemu_irq *
cortex_m0p_core_init(CortexMCapabilities *cm_info, MachineState *machine);
qemu_irq *
cortex_m3_core_init(CortexMCapabilities *cm_info, MachineState *machine);
qemu_irq *
cortex_m4_core_init(CortexMCapabilities *cm_info, MachineState *machine);
qemu_irq *
cortex_m7_core_init(CortexMCapabilities *cm_info, MachineState *machine);

#endif /* HW_ARM_CORTEXM_H */
