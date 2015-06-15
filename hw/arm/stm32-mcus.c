/*
 * STM32 Cortex-M devices emulation.
 *
 * Copyright (c) 2014 Liviu Ionescu
 * Copyright (c) 2010 Andre Beckus
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

#include "hw/arm/stm32-mcus.h"
#include "hw/arm/cortexm-mcu.h"
#include "exec/address-spaces.h"
#include "qemu/error-report.h"
#include "sysemu/sysemu.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/*
 * - Low-density devices are STM32F101xx, STM32F102xx and STM32F103xx
 * microcontrollers where the Flash memory density ranges between 16
 * and 32 Kbytes.
 * - Medium-density devices are STM32F101xx, STM32F102xx and STM32F103xx
 * microcontrollers where the Flash memory density ranges between 64
 * and 128 Kbytes.
 * - High-density devices are STM32F101xx and STM32F103xx microcontrollers
 * where the Flash memory density ranges between 256 and 512 Kbytes.
 * - XL-density devices are STM32F101xx and STM32F103xx microcontrollers
 * where the Flash memory density ranges between 768 Kbytes and 1 Mbyte.
 * - Connectivity line devices are STM32F105xx and STM32F107xx microcontrollers.
 */

/*
 * Interrupts:
 *
 * - F1
 *   - CL: 68
 *   - [LMHX]D: 60
 * - F4 TBD
 */

/*
 * STM32 pin count and package encoding (first char after number):
 *
 * I = BGA/LQFP 176
 * V = LQFP/UFBGA 100
 * Z = LQFP/UFPGA/UFBGA 144, WLCSP 143
 * B = LQFP 208
 * R = LQFP 64
 * N = TFBGA
 * A = UFBGA 169, WLCSP 168
 * C = UFQFPN 48, WLCSP 49
 * M = WLCSP 81
 * O = WLCSP 90
 */

/*
 * STM32 Flash sizes encoding (second char after number):
 *
 * 8 = 64K
 * B = 128K
 * C = 256K
 * E = 512K
 * F = 768K
 * G = 1024K
 * I = 2048K
 */

/* ------------------------------------------------------------------------- */

static Property stm32_mcus_properties[] = {
    /* TODO: add STM32 specific properties */
    DEFINE_PROP_END_OF_LIST(), //
        };

static const STM32PartInfo stm32_mcus[] = {
    {
        .name = TYPE_STM32F051R8,
        .core = {
            .cortexm_model = CORTEX_M0,
            .flash_size_kb = 64,
            .sram_size_kb = 8, } },
    {
        .name = TYPE_STM32F100RB,
        .core = {
            .cortexm_model = CORTEX_M3,
            .flash_size_kb = 128,
            .sram_size_kb = 8,
            .num_irq = 60, } },
    {
        .name = TYPE_STM32F103RB,
        .core = {
            .cortexm_model = CORTEX_M3,
            .flash_size_kb = 128,
            .sram_size_kb = 20,
            .has_mpu = true,
            .has_itm = true,
            .num_irq = 60,
            .nvic_bits = 4 },
        .stm32 = {
            .family = STM32_FAMILY_F1,
            .hsi_freq_hz = 8000000,
            .lsi_freq_hz = 40000,
            .has_gpioa = true,
            .has_gpiob = true,
            .has_gpioc = true,
            .has_gpiod = true,
            .has_gpioe = true,
            .f1 = {
                .is_md = true } } },
    {
        .name = TYPE_STM32F107VC,
        .core = {
            .cortexm_model = CORTEX_M3,
            .flash_size_kb = 256,
            .sram_size_kb = 64,
            .has_mpu = true,
            .num_irq = 68, } },
    {
        .name = TYPE_STM32L152RE,
        .core = {
            .cortexm_model = CORTEX_M3,
            .flash_size_kb = 512,
            .sram_size_kb = 80,
            .has_mpu = true, } },
    {
        .name = TYPE_STM32F205RF,
        .core = {
            .cortexm_model = CORTEX_M3,
            .flash_size_kb = 768,
            .sram_size_kb = 128, /* No CCM */
            .has_mpu = true, } },
    {
        .name = TYPE_STM32F303VC,
        .core = {
            .cortexm_model = CORTEX_M4F,
            .flash_size_kb = 256,
            .sram_size_kb = 40,
            .has_mpu = true, } },
    {
        .name = TYPE_STM32F334R8,
        .core = {
            .cortexm_model = CORTEX_M4F,
            .flash_size_kb = 64,
            .sram_size_kb = 12,
            .has_mpu = true, } },
    {
        .name = TYPE_STM32F405RG,
        .core = {
            .cortexm_model = CORTEX_M4F,
            .flash_size_kb = 1024,
            .sram_size_kb = 128, /* 64K CCM not counted */
            .has_mpu = true, } },
    {
        .name = TYPE_STM32F407VG,
        .core = {
            .cortexm_model = CORTEX_M4F,
            .flash_size_kb = 1024,
            .sram_size_kb = 128, /* 64K CCM not counted */
            .has_mpu = true, } },
    {
        .name = TYPE_STM32F407ZG,
        .core = {
            .cortexm_model = CORTEX_M4F,
            .flash_size_kb = 1024,
            .sram_size_kb = 128, /* 64K CCM not counted */
            .has_mpu = true, } },
    {
        .name = TYPE_STM32F411RE,
        .core = {
            .cortexm_model = CORTEX_M4F,
            .flash_size_kb = 512,
            .sram_size_kb = 128, /* No CCM */
            .has_mpu = true, } },
    {
        .name = TYPE_STM32F429ZI,
        .core = {
            .cortexm_model = CORTEX_M4F,
            .flash_size_kb = 2048,
            .sram_size_kb = 192, /* 64K CCM not counted */
            .has_mpu = true, } },
    {
        .name = 0 }

};

/* ------------------------------------------------------------------------- */

static void stm32_mcus_construct_callback(Object *obj, MachineState *machine)
{
    qemu_log_function_name();

    STM32DeviceClass *st_class = STM32_DEVICE_GET_CLASS(obj);

    STM32_MCU_GET_CLASS(obj)->construct(obj, &st_class->part_info->stm32,
            &st_class->part_info->core, machine);
}

static void stm32_mcus_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /* Call the parent realize(). */
    DeviceClass *parent_class = DEVICE_CLASS(
            object_class_by_name(TYPE_STM32_MCU));
    Error *local_err = NULL;
    parent_class->realize(dev, &local_err);
    if (local_err) {
        error_propagate(errp, local_err);
        return;
    }
}

static void stm32_mcus_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    STM32DeviceClass *st_class = (STM32DeviceClass*)(klass);

    dc->realize = stm32_mcus_realize_callback;
    dc->props = stm32_mcus_properties;

    st_class->construct = stm32_mcus_construct_callback;

    /*
     * Copy the 'data' param, pointing to a ParamInfo, to the class
     * structure, to be retrieved by the constructor.
     */
    st_class->part_info = data;
}

static void stm32_mcus_types_init()
{

    for (int i = 0; stm32_mcus[i].name; ++i) {

        TypeInfo ti = {
            .name = stm32_mcus[i].name,
            .parent = TYPE_STM32_MCU,
            .instance_size = sizeof(STM32DeviceState),
            .class_init = stm32_mcus_class_init_callback,
            .class_size = sizeof(STM32DeviceClass),
            .class_data = (void *) &stm32_mcus[i] };
        type_register(&ti);
    }
}

#if defined(CONFIG_GNU_ARM_ECLIPSE)
type_init(stm32_mcus_types_init);
#endif
