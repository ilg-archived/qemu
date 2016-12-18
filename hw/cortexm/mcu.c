/*
 * Cortex-M MCU emulation.
 *
 * Copyright (c) 2014 Liviu Ionescu.
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

#include <hw/cortexm/nvic.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/bitband.h>
#include <hw/cortexm/board.h>
#include <hw/cortexm/svd.h>
#include <hw/cortexm/mcu.h>

#include "sysemu/sysemu.h"
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
#include "exec/semihost.h"
#include "qapi/error.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

#define DEFAULT_NUM_IRQ		256

// ----- Private --------------------------------------------------------------

static void cortexm_mcu_do_unassigned_access_callback(CPUState *cpu,
        hwaddr addr,
        bool is_write, bool is_exec, int opaque, unsigned size)
{
    qemu_log_mask(LOG_FUNC,
            "%s(addr=0x%08"PRIX64", size=%d, is_write=%s, is_exec=%s)\n",
            __FUNCTION__, addr, size, is_write ? "true" : "false",
            is_exec ? "true" : "false");

    //CPUARMState *env;
    //env = cpu->env_ptr;

    // TODO: check for flag and raise ARMV7M_EXCP_MEM
    // cortexm_nvic_set_pending(???, ARMV7M_EXCP_HARD);
}

// ----------------------------------------------------------------------------

static void cortexm_mcu_registered_reset_callback(void *opaque)
{
    DeviceState *dev = opaque;

    // This will actually go to derived class reset.
    device_reset(dev);
}

// ----------------------------------------------------------------------------

static void cortexm_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_CORTEXM_MCU)) {
        return;
    }

    CortexMState *cm_state = CORTEXM_MCU_STATE(dev);

    // The param_capabilities property was set in `*_mcus_realize()`
    // to &part_info->cortexm , which is R/O; to be able to update it,
    // make a local copy in RAM. */
    CortexMCapabilities* capabilities = g_new(CortexMCapabilities, 1);
    memcpy(capabilities, cm_state->param_capabilities,
            sizeof(CortexMCapabilities));

    CortexMCoreCapabilities* core_capabilities = g_new0(CortexMCoreCapabilities,
            1);
    if (cm_state->param_capabilities->core != NULL) {
        error_printf("Core capabilities must be defined in SVD files.\n");
        exit(1);
        // memcpy(core_capabilities, cm_state->param_capabilities->core,
        //        sizeof(CortexMCoreCapabilities));
    }
    capabilities->core = core_capabilities;

    // Remember the local copy for future use.
    cm_state->capabilities = (const CortexMCapabilities*) capabilities;

    // TODO: in the end make this mandatory.
    if (capabilities->svd_file_name != NULL) {

        const char *svd_full_name = qemu_find_file(QEMU_FILE_TYPE_DEVICES,
                capabilities->svd_file_name);
        if (svd_full_name == NULL) {
            error_printf("JSON SVD file '%s' not found.\n", svd_full_name);
            exit(1);
        }

#if defined(CONFIG_VERBOSE)
        if (verbosity_level >= VERBOSITY_DETAILED) {
            printf("Device file: '%s'.\n", svd_full_name);
        }
#endif

        JSON_Value *value = json_parse_file(svd_full_name);
        cm_state->svd_json = json_value_get_object(value);

        svd_validate_device_name(cm_state->svd_json,
                capabilities->svd_device_name);

        svd_process_cpu(cm_state->svd_json, core_capabilities);

        JSON_Object *device = json_object_get_object(cm_state->svd_json,
                "device");
        svd_set_register_properties_group(device, OBJECT(dev));
    }

    const MachineState *machine = MACHINE(cortexm_board_get());
    const char *image_filename = NULL;
    // Use either the --image or the --kernel
    if (machine->image_filename) {
        image_filename = machine->image_filename;
    } else if (machine->kernel_filename) {
        image_filename = machine->kernel_filename;
    }

    cm_state->image_filename = image_filename;

    const char *cpu_model = "?";
    if (machine->cpu_model) {
        cpu_model = machine->cpu_model;
    } else if (core_capabilities->cpu_model) {
        cpu_model = core_capabilities->cpu_model;
    }

    cm_state->cpu_model = cpu_model;

    // The /machine/mcu/cortexm container will hold all
    // ARM internal peripherals.
    cm_state->container = container_get(OBJECT(dev), "/cortexm");

    CPUARMState *env;
    {
        // ----- Create CPU based on model. -----
        ARMCPU *cpu;
        // TODO: pass version bits.
        cpu = cm_cpu_arm_create(cm_state->container, cm_state->cpu_model);

        CPUClass *cc;
        cc = CPU_GET_CLASS(cpu);
        // Hook on the CPU unassigned access
        cc->do_unassigned_access = cortexm_mcu_do_unassigned_access_callback;

        cm_state->cpu = cpu;
        env = &cpu->env;
    }

    // There may be 3 substrings, like "cortex-m3-r2p1"
    char **substr = g_strsplit(cpu_model, "-", 3);

    const char *display_model = "?";

    int max_num_irq = 496;

    // Some capabilities are hard-wired.
    char *sub_model = substr[1];
    if (strcmp(sub_model, "m0") == 0) {
        display_model = "Cortex-M0";
        core_capabilities->model = CORTEX_M0;
        core_capabilities->has_mpu = false;
        core_capabilities->has_fpu = false;
        core_capabilities->fpu_type = CORTEX_M_FPU_TYPE_NONE;
    } else if (strcmp(sub_model, "m0p") == 0) {
        display_model = "Cortex-M0+";
        core_capabilities->model = CORTEX_M0PLUS;
        core_capabilities->has_mpu = false;
        core_capabilities->has_fpu = false;
        core_capabilities->fpu_type = CORTEX_M_FPU_TYPE_NONE;
    } else if (strcmp(sub_model, "m1") == 0) {
        display_model = "Cortex-M1";
        core_capabilities->model = CORTEX_M1;
        /* TODO: Check if it has no MPU/FPU. */
        core_capabilities->has_mpu = false;
        core_capabilities->has_fpu = false;
        core_capabilities->fpu_type = CORTEX_M_FPU_TYPE_NONE;
    } else if (strcmp(sub_model, "m3") == 0) {
        display_model = "Cortex-M3";
        core_capabilities->model = CORTEX_M3;
        max_num_irq = 240;
        core_capabilities->has_fpu = false;
        core_capabilities->fpu_type = CORTEX_M_FPU_TYPE_NONE;
    } else if (strcmp(sub_model, "m4") == 0) {
        display_model = "Cortex-M4";
        core_capabilities->model = CORTEX_M4;
        core_capabilities->has_fpu = false;
        core_capabilities->fpu_type = CORTEX_M_FPU_TYPE_NONE;
#if 0
    } else if (strcmp(sub_model, "m4f") == 0) {
        display_model = "Cortex-M4F";
        core_capabilities->model = CORTEX_M4F;
        core_capabilities->has_fpu = true;
        core_capabilities->fpu_type = CORTEX_M_FPU_TYPE_FPV4_SP_D16;
#endif
    } else if (strcmp(sub_model, "m7") == 0) {
        display_model = "Cortex-M7";
        core_capabilities->model = CORTEX_M7;
        core_capabilities->has_fpu = false;
        core_capabilities->fpu_type = CORTEX_M_FPU_TYPE_NONE;
#if 0
    } else if (strcmp(sub_model, "m7f") == 0) {
        display_model = "Cortex-M7F";
        core_capabilities->model = CORTEX_M7F;
        core_capabilities->has_fpu = true;
        core_capabilities->fpu_type = CORTEX_M_FPU_TYPE_FPV5_DP_D16;
#endif
    } else {
        error_report("Unsupported '--cpu %s' "
                "(cortex-m0,m0p,m1,m3,m4,m7 only).", cpu_model);
        exit(1);
    }

    unsigned int major = (cm_state->cpu->midr >> 20) & 0xF;
    unsigned int minor = cm_state->cpu->midr & 0xF;

    char *display_model_rp = malloc(strlen(display_model) + 10);
    sprintf(display_model_rp, "%s r%dp%d", display_model, major, minor);

    cm_state->display_model = display_model_rp;

    // The cm_state value might have been set by --global
    int sram_size_kb = cm_state->sram_size_kb;
    if (sram_size_kb == 0) {
        /* Otherwise use the MCU value */
        sram_size_kb = capabilities->sram_size_kb;
    }

    // Max 32 MB ram, to avoid overlapping with the bit-banding area
    if (sram_size_kb > 32 * 1024) {
        sram_size_kb = 32 * 1024;
    }
    cm_state->sram_size_kb = sram_size_kb;

    // The cm_state value might have been set by --global
    int flash_size_kb = cm_state->flash_size_kb;
    if (flash_size_kb == 0) {
        /* Otherwise use the MCU value */
        flash_size_kb = capabilities->flash_size_kb;
    }
    cm_state->flash_size_kb = flash_size_kb;

#if defined(CONFIG_VERBOSE)
    if (verbosity_level >= VERBOSITY_COMMON) {
        const char *cmdline;

        printf("Device: '%s' (%s", object_get_typename(OBJECT(dev)),
                cm_state->display_model);
        if (capabilities->core->has_mpu) {
            printf(", MPU");
        }
        if (capabilities->core->has_fpu) {
            printf(", FPU");
        }
        if (capabilities->core->has_itm) {
            printf(", ITM");
        }
        printf(", %d NVIC prio bits", capabilities->core->nvic_bits);
        printf(", %d IRQs", capabilities->core->num_irq);

        printf("), Flash: %d kB, RAM: %d kB.\n", flash_size_kb, sram_size_kb);
        if (image_filename) {
            printf("Image: '%s'.\n", image_filename);
        }

        cmdline = semihosting_get_cmdline();
        if (cmdline != NULL) {
            printf("Command line: '%s' (%d bytes).\n", cmdline,
                    (int) strlen(cmdline));
        } else {
            printf("Command line: (none).\n");
        }
    }
#endif

    // ----- Realize the CPU (derived from a device). -----
    cm_object_realize(OBJECT(cm_state->cpu));

    // ----- Construct the NVIC object. -----
    {
        // The NVIC will be available via "/machine/mcu/cortexm/nvic"
        Object *nvic = cm_object_new(cm_state->container, "nvic",
        TYPE_CORTEXM_NVIC);

        int num_irq;
        if (capabilities->core->num_irq != 0) {
            num_irq = capabilities->core->num_irq;
        } else {
            num_irq = DEFAULT_NUM_IRQ;
        }

        if (num_irq > max_num_irq) {
            num_irq = max_num_irq;
        }
        // Must be a multiple of 32
        num_irq = (num_irq + 31) & (~31);
        cm_state->num_irq = num_irq;

        // This currently goes to GIC, which uses a different numbering.
        object_property_set_int(nvic, num_irq + 32, "num-irq", NULL);

        cm_object_realize(nvic);
        cm_state->nvic = DEVICE(nvic);

        env->nvic = nvic;

        // Route the ARM CPU_INTERRUPT_HARD to NVIC 0
        sysbus_connect_irq(SYS_BUS_DEVICE(cm_state->nvic), 0,
                qdev_get_gpio_in(DEVICE(cm_state->cpu), ARM_CPU_IRQ));

        GICState *gs = ARM_GIC_COMMON(nvic);
        gs->basepri_ptr = &env->v7m.basepri;

#if 0
        // Create the CPU exception handler interrupts. Peripherals
        // will connect to them and set interrupts to be delivered to
        // the guest application.
        qemu_irq *pic = g_new(qemu_irq, num_irq);
        int i;
        for (i = 0; i < num_irq; i++) {
            pic[i] = qdev_get_gpio_in(DEVICE(cm_state->nvic), i);
        }
        cm_state->pic = pic;
#endif
    }

    // ----- Construct the ITM object. -----
    if (capabilities->core->has_itm) {
        /* The ITM will be available via "/machine/cortexm/itm" */
        Object *itm = cm_object_new(cm_state->container, "itm",
        TYPE_CORTEXM_ITM);

        cm_object_realize(itm);

        cm_state->itm = DEVICE(itm);
    }

    // ----- Create memory regions. -----
    {
        CortexMClass *cm_class = CORTEXM_MCU_GET_CLASS(dev);
        (*cm_class->memory_regions_create)(dev);
    }

    // ----- Connect peripheral interrupts to NVIC -----
    {

    }

    // ----- Load image. -----
    if (!cm_state->image_filename && !qtest_enabled() && !with_gdb) {
        error_report("Guest image must be specified (using --image)");
        exit(1);
    }

    if (cm_state->image_filename) {
        // The image is loaded in two steps, first here
        // in some local structures then in rom_reset(),
        // after all memory regions are mapped.
        CortexMClass *cm_class = CORTEXM_MCU_GET_CLASS(cm_state);
        cm_class->image_load(DEVICE(cm_state));
    }

    // Arrange for the MCU to be reset.
    // The reset itself is not needed if the image is not given
    // and will be loaded by GDB, but the reset needs to be
    // registered, for the system_reset to be effective.
    qemu_register_reset(cortexm_mcu_registered_reset_callback, cm_state);

    // The default processor clock is 8000000 Hz.
    //
    // The scale should be recomputed later, in the vendor clock
    // related peripherals.
    system_clock_scale = NANOSECONDS_PER_SECOND / 8000000;

#if defined(CONFIG_VERBOSE)
    if (verbosity_level >= VERBOSITY_COMMON) {
        printf("%s core initialised.\n", cm_state->display_model);
    }
#endif
}

static int cortexm_mcu_reset_object(Object *obj, void *opaque)
{
    if (cm_object_is_instance_of_typename(obj, TYPE_DEVICE)) {
        device_reset(DEVICE(obj));
    }
    return 0; // Non-0 will break the iterator.
}

static void cortexm_mcu_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Call parent reset().
    cm_device_parent_reset(dev, TYPE_CORTEXM_MCU);

    CortexMState *cm_state = CORTEXM_MCU_STATE(dev);

#if defined(CONFIG_VERBOSE)
    if (verbosity_level >= VERBOSITY_COMMON) {
        printf("%s core reset.\n\n", cm_state->display_model);
    }
#endif

    // Ensure the image is copied into memory before reset
    // fetches MSP & PC
    rom_reset(NULL);

    // With the new image available, MSP & PC are correct
    // and execution will start.
    cpu_reset(CPU(cm_state->cpu));

    object_child_foreach(cm_state->container, cortexm_mcu_reset_object, NULL);
}

static void cortexm_mcu_memory_regions_create_callback(DeviceState *dev)
{
    qemu_log_function_name();

    CortexMState *cm_state = CORTEXM_MCU_STATE(dev);

    // Get the system memory region, it must start at 0.
    MemoryRegion *system_memory = get_system_memory();

    int flash_size = cm_state->flash_size_kb * 1024;
    int sram_size = cm_state->sram_size_kb * 1024;

    Object *mem_container = container_get(cm_state->container, "/memory");

    MemoryRegion *flash_mem = &cm_state->flash_mem;
    // Flash programming is done via the SCU, so pretend it is ROM.
    memory_region_init_ram(flash_mem, mem_container, "flash", flash_size,
            &error_fatal);
    vmstate_register_ram_global(flash_mem);
    memory_region_set_readonly(flash_mem, true);
    memory_region_add_subregion(system_memory, 0x00000000, flash_mem);

    MemoryRegion *sram_mem = &cm_state->sram_mem;
    memory_region_init_ram(sram_mem, mem_container, "sram", sram_size,
            &error_fatal);
    vmstate_register_ram_global(sram_mem);
    memory_region_add_subregion(system_memory, 0x20000000, sram_mem);

    // Bitband the 1 MB from 0x20000000-0x200FFFFF area to
    // 32 MB at 0x22000000-0x23FFFFFF.
    cortexm_bitband_init(mem_container, "sram-bitband", 0x20000000);

    MemoryRegion *hack_mem = &cm_state->hack_mem;
    // Hack to map an additional page of ram at the top of the address
    // space.  This stops qemu complaining about executing code outside RAM
    // when returning from an exception.  */
    memory_region_init_ram(hack_mem, mem_container, "hack", 0x1000,
            &error_fatal);
    vmstate_register_ram_global(hack_mem);
    memory_region_add_subregion(system_memory, 0xFFFFF000, hack_mem);
}

// TODO: check if this really needs to be a callback.
static void cortexm_mcu_image_load_callback(DeviceState *dev)
{
    qemu_log_function_name();

    CortexMState *cm_state = CORTEXM_MCU_STATE(dev);

    const char *image_filename = cm_state->image_filename;
    assert(image_filename);

    int big_endian;
#ifdef TARGET_WORDS_BIGENDIAN
    big_endian = 1;
#else
    big_endian = 0;
#endif
    int image_size;
    uint64_t entry;
    uint64_t lowaddr;
    image_size = load_elf(image_filename, NULL, NULL, &entry, &lowaddr,
    NULL, big_endian, EM_ARM, 1, 0);
    if (image_size < 0) {
        image_size = load_image_targphys(image_filename, 0,
                cm_state->flash_size_kb * 1024);
        lowaddr = 0;
    }
    if (image_size < 0) {
        error_report("Could not load image '%s'", image_filename);
        exit(1);
    }
}

// ----------------------------------------------------------------------------

#define DEFINE_PROP_MACHINE_PTR(_n, _s, _f) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_ptr, const MachineState*)

#define DEFINE_PROP_CORTEXMCAPABILITIES_PTR(_n, _s, _f) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_ptr, const CortexMCapabilities*)

// Properties for the 'cortexm_mcu' object, used as parent for
// all vendor MCUs.
static Property cortexm_mcu_properties[] = {
        DEFINE_PROP_CORTEXMCAPABILITIES_PTR("cortexm-capabilities",
                CortexMState, param_capabilities),
    DEFINE_PROP_END_OF_LIST()
/**/
};

static void cortexm_mcu_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    CortexMState *state = CORTEXM_MCU_STATE(obj);

    cm_object_property_add_uint32(obj, "sram-size-kb", &state->sram_size_kb);
    state->sram_size_kb = 0;

    cm_object_property_add_uint32(obj, "flash-size-kb", &state->flash_size_kb);
    state->flash_size_kb = 0;

    // -----

    cm_object_property_add_const_str(obj, "svd-size", &state->svd.size);
    state->svd.size = NULL;

    cm_object_property_add_const_str(obj, "svd-access", &state->svd.access);
    state->svd.access = NULL;

    cm_object_property_add_const_str(obj, "svd-protection",
            &state->svd.protection);
    state->svd.protection = NULL;

    cm_object_property_add_const_str(obj, "svd-reset-value",
            &state->svd.reset_value);
    state->svd.reset_value = NULL;

    cm_object_property_add_const_str(obj, "svd-reset-mask",
            &state->svd.reset_mask);
    state->svd.reset_mask = NULL;

}

// Initialise the "cortexm-mcu" object. Currently there is no input data.
// Called during module_call_init() in main().
static void cortexm_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->props = cortexm_mcu_properties;
    dc->realize = cortexm_mcu_realize_callback;
    dc->reset = cortexm_mcu_reset_callback;

    CortexMClass *cm_class = CORTEXM_MCU_CLASS(klass);
    cm_class->memory_regions_create =
            cortexm_mcu_memory_regions_create_callback;
    cm_class->image_load = cortexm_mcu_image_load_callback;
}

static const TypeInfo cortexm_mcu_type_init = {
    .abstract = true,
    .name = TYPE_CORTEXM_MCU,
    .parent = TYPE_CORTEXM_MCU_PARENT,
    .instance_init = cortexm_mcu_instance_init_callback,
    .instance_size = sizeof(CortexMState),
    .class_init = cortexm_mcu_class_init_callback,
    .class_size = sizeof(CortexMClass)
/**/
};

static void cortexm_types_init(void)
{
    type_register_static(&cortexm_mcu_type_init);
}

type_init(cortexm_types_init);

// ----------------------------------------------------------------------------

// TODO: remove all following functions

// Cortex-M0 initialisation routine.
qemu_irq *
cortex_m0_core_init(CortexMCoreCapabilities *cm_info, MachineState *machine)
{
    return NULL;
}

// Cortex-M0+ initialisation routine.
qemu_irq *
cortex_m0p_core_init(CortexMCoreCapabilities *cm_info, MachineState *machine)
{
    return NULL;
}

// Cortex-M3 initialisation routine.
qemu_irq *
cortex_m3_core_init(CortexMCoreCapabilities *cm_info, MachineState *machine)
{
    return NULL;
}

// Cortex-M4 initialisation routine.
qemu_irq *
cortex_m4_core_init(CortexMCoreCapabilities *cm_info, MachineState *machine)
{
    return NULL;
}

// Cortex-M7 initialisation routine.
qemu_irq *
cortex_m7_core_init(CortexMCoreCapabilities *cm_info, MachineState *machine)
{
    return NULL;
}

// ----------------------------------------------------------------------------

