/*
 * Cortex-M MCU emulation.
 * 
 * Copyright (c) 2015 Liviu Ionescu.
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

#ifndef CORTEXM_MCU_H_
#define CORTEXM_MCU_H_

#include "qemu/osdep.h"

#include "exec/memory.h"
#include "hw/irq.h"
#include "hw/boards.h"
#include "hw/sysbus.h"
#include "target-arm/cpu.h"

#include <hw/cortexm/itm.h>
#include <hw/cortexm/json-parser.h>

// ----------------------------------------------------------------------------

#define CORTEX_M_FPU_TYPE_NONE (0)
#define CORTEX_M_FPU_TYPE_FPV4_SP_D16 (1)
#define CORTEX_M_FPU_TYPE_FPV5_SP_D16 (2)
#define CORTEX_M_FPU_TYPE_FPV5_DP_D16 (3)

typedef enum {
    CORTEX_UNDEFINED = 0,
    CORTEX_M0,
    CORTEX_M0PLUS,
    CORTEX_M1,
    CORTEX_M3,
    CORTEX_M4,
    CORTEX_M4F,
    CORTEX_M7,
    CORTEX_M7F
} cortexm_models_t;

typedef struct {

    // The cpu_model naming convention is "cortex-m3-r1p2".
    const char *cpu_model;

    // Values computed from cpu_model
    cortexm_models_t model; // binary value to easily identify the core
    uint8_t major; // rN, 4 bits
    uint8_t minor; // pN, 4 bits

    // Capabilities bits; keep them compact.
    unsigned int has_mpu :1; // true/false
    unsigned int has_fpu :1; // true/false
    unsigned int has_etm :1; // true/false
    unsigned int has_itm :1; // true/false

    unsigned int fpu_type; // CORTEX_M_FPU_TYPE_*; may be not needed

    // number of interrupts (excluding first 16 core interrupts).
    unsigned int num_irq;

    unsigned int nvic_bits; // bits used for irqs in NVIC.
} CortexMCoreCapabilities;

// Used by vendor specific Cortex-M devices to pass the core
// capabilities to the common Cortex-M initialisations.
//
// It is copied into the CortexMState during *_instance_init() functions.
typedef struct {

    // TODO: make this an array of structs.
    // size of main program area, in KB
    const uint32_t flash_size_kb;
    // size of main RAM area, in KB
    const uint32_t sram_size_kb;

    const CortexMCoreCapabilities *core;

    // The JSON file with the device definitions.
    // Must include core capabilities.
    const char *svd_file_name;

    // The device name, as it appears in the SVD.
    // Used mainly for validation.
    const char *svd_device_name;

} CortexMCapabilities;

// ----------------------------------------------------------------------------

#define TYPE_CORTEXM_MCU TYPE_CORTEXM_PREFIX "mcu"

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_CORTEXM_MCU_PARENT TYPE_SYS_BUS_DEVICE
typedef SysBusDeviceClass CortexMParentClass;
typedef SysBusDevice CortexMParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define CORTEXM_MCU_GET_CLASS(obj) \
    OBJECT_GET_CLASS(CortexMClass, (obj), TYPE_CORTEXM_MCU)
#define CORTEXM_MCU_CLASS(klass) \
    OBJECT_CLASS_CHECK(CortexMClass, (klass), TYPE_CORTEXM_MCU)

typedef struct {
    // private:
    CortexMParentClass parent_class;
    // public:

    void (*memory_regions_create)(DeviceState *dev);
    void (*image_load)(DeviceState *dev);
} CortexMClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define CORTEXM_MCU_STATE(obj) \
    OBJECT_CHECK(CortexMState, (obj), TYPE_CORTEXM_MCU)

typedef struct {
    // private:
    SysBusDevice parent_obj;
    // public:

    // Constructor parameters.
    const CortexMCapabilities *param_capabilities;

    // R/W copy of core capabilities, set by *_instance_init().
    const CortexMCapabilities *capabilities;

    JSON_Object *svd_json;

    const char *image_filename;

    // The following are the actual values used to initialise the object.
    // May be different from capabilities, if explicitly overwritten.
    const char *cpu_model;
    const char *display_model;

    // Internal RAM size, in KB.
    uint32_t sram_size_kb;

    // Internal flash size, in KB.
    uint32_t flash_size_kb;

    // The number of vendor specific interrupts.
    uint32_t num_irq;

    Object *container;

    MemoryRegion flash_mem;
    MemoryRegion sram_mem;
    MemoryRegion hack_mem;

    // CPU state, as returned by cpu_arm_init().
    ARMCPU *cpu;

    // Pointer to array of num-irq elements. Does not include system interrupts.
    DeviceState *nvic;

    // Optional
    DeviceState *itm;

    struct {
        const char *size;
        const char *access;
        const char *protection;
        const char *reset_value;
        const char *reset_mask;
    } svd;

} CortexMState;

// ----------------------------------------------------------------------------

// TODO: remove all when all old definitions are updated.
qemu_irq *
cortex_m0_core_init(CortexMCoreCapabilities *cm_info, MachineState *machine);
qemu_irq *
cortex_m0p_core_init(CortexMCoreCapabilities *cm_info, MachineState *machine);
qemu_irq *
cortex_m3_core_init(CortexMCoreCapabilities *cm_info, MachineState *machine);
qemu_irq *
cortex_m4_core_init(CortexMCoreCapabilities *cm_info, MachineState *machine);
qemu_irq *
cortex_m7_core_init(CortexMCoreCapabilities *cm_info, MachineState *machine);

// ----------------------------------------------------------------------------

#endif /* CORTEXM_MCU_H_ */
