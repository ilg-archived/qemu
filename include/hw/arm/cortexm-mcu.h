/*
 * Cortex-M System emulation.
 * 
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HW_ARM_CORTEXM_H
#define HW_ARM_CORTEXM_H 1

#include "hw/misc/armv7m-itm.h"
#include "exec/memory.h"
#include "hw/irq.h"
#include "hw/boards.h"
#include "hw/sysbus.h"

/* ------------------------------------------------------------------------- */

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
typedef struct {

    cortexm_models_t cortexm_model; /* binary id to identify the core */

    /* The vendor values. */
    int flash_size_kb; /* size of main program area, in KB */
    int sram_size_kb; /* size of main RAM area, in KB */
    int sram_begin; /* begin address of main RAM area, if not 0x20000000 */

    /* Capabilities bits; keep them compact. */
    int has_mpu :1; /* true/false */
    int has_fpu :1; /* true/false */
    int has_itm :1; /* true/false */

    int fpu_type; /* CORTEX_M_FPU_TYPE_*; may be not needed */

    int num_irq; /* number of interrupts (excluding first 15 core interrupts) */
    int nvic_bits; /* bits used for irqs in NVIC */
} CortexMCapabilities;

/* ------------------------------------------------------------------------- */

#define CORTEXM_MCU_GET_CLASS(obj) \
    OBJECT_GET_CLASS(CortexMClass, (obj), TYPE_CORTEXM_MCU)
#define CORTEXM_MCU_CLASS(obj) \
    OBJECT_CLASS_CHECK(CortexMClass, (obj), TYPE_CORTEXM_MCU)

typedef struct {
    /*< private >*/
    SysBusDeviceClass parent_class;
    /*< public >*/

    void (*construct)(Object *obj, CortexMCapabilities* capabilities,
            MachineState *machine);
    void (*memory_regions_create)(DeviceState *dev);
    void (*image_load)(DeviceState *dev);
} CortexMClass;

/* ------------------------------------------------------------------------- */

#define TYPE_CORTEXM_MCU "cortexm-mcu"
#define CORTEXM_MCU_STATE(obj) \
    OBJECT_CHECK(CortexMState, (obj), TYPE_CORTEXM_MCU)

/**
 * Structure used to store the Cortex-M state.
 */
typedef struct {
    /*< private >*/
    SysBusDevice parent_obj;
    /*< public >*/

    /**
     * Core capabilities, set by *_instance_init().
     */
    CortexMCapabilities *capabilities;

    const char *kernel_filename;

    /*
     * The following are the actual values used to initialise the object.
     * May be different from capabilities, if explicitly overwriten.
     */
    const char *cpu_model;
    const char *display_model;

    uint32_t sram_size_kb;
    uint32_t flash_size_kb;
    uint32_t num_irq;

    Object *container;

    MemoryRegion flash_mem;
    MemoryRegion sram_mem;
    MemoryRegion hack_mem;

    /**
     * CPU state, as returned by cpu_arm_init().
     */
    ARMCPU *cpu;

    /**
     * Pointer to array of num-irq elements. Does not include system interrupts.
     */
    qemu_irq *pic; /* pointer to array of num-irq elements */

    DeviceState *nvic;

    /* Optional */
    DeviceState *itm;

} CortexMState;

/* ------------------------------------------------------------------------- */

void
cortexm_board_greeting(MachineState *machine);

/* Helper functions. */
ARMCPU *cpu_arm_create(const char *cpu_model);
void qdev_realize(DeviceState *dev);
DeviceState *qdev_alloc(BusState *bus, const char *name);

/* ------------------------------------------------------------------------- */

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

/* ------------------------------------------------------------------------- */

#endif /* HW_ARM_CORTEXM_H */
