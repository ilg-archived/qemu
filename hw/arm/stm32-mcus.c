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

/*
 * TODO: try to describe all processors via the capabilities bits, so that a
 * separate object would not be necessary.
 */

static Property stm32_mcu_properties[] = {
    /* TODO: add STM32 specific properties */
    DEFINE_PROP_END_OF_LIST(), //
        };

/* ----- STM32F051R8 ----- */
static CortexMCapabilities stm32f051r8_capabilities = {
    .flash_size_kb = 64,
    .sram_size_kb = 8,
    .cortexm_model = CORTEX_M0 };

static void stm32f051r8_mcu_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F051R8_STATE(obj);
    state->parent_obj.capabilities = &stm32f051r8_capabilities;

    // TODO: initialize inner objects
}

static void stm32f051r8_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F051R8_STATE(dev);
    STM32DeviceClass *nc = STM32F051R8_GET_CLASS(state);
    Error *local_err = NULL;
    nc->parent_realize(dev, &local_err);
    if (local_err) {
        error_propagate(errp, local_err);
        return;
    }
}

static void stm32f051r8_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    STM32DeviceClass *nc = STM32F051R8_CLASS(klass);

    nc->parent_realize = dc->realize;
    dc->realize = stm32f051r8_mcu_realize_callback;
    dc->props = stm32_mcu_properties;
}

static const TypeInfo stm32f051r8_mcu_type_info = {
    .name = TYPE_STM32F051R8,
    .parent = TYPE_STM32_MCU,
    .instance_size = sizeof(STM32MCUState),
    .instance_init = stm32f051r8_mcu_instance_init_callback,
    .class_init = stm32f051r8_mcu_class_init_callback,
    .class_size = sizeof(STM32DeviceClass) };

/* ----- STM32F100RB ----- */
static CortexMCapabilities stm32f100rb_capabilities = {
    .flash_size_kb = 128,
    .sram_size_kb = 8,
    .num_irq = 60,
    .cortexm_model = CORTEX_M3 };

static void stm32f100rb_mcu_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F100RB_STATE(obj);
    state->parent_obj.capabilities = &stm32f100rb_capabilities;

    // TODO: initialize inner objects
}

static void stm32f100rb_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F100RB_STATE(dev);
    STM32DeviceClass *nc = STM32F100RB_GET_CLASS(state);
    Error *local_err = NULL;
    nc->parent_realize(dev, &local_err);
    if (local_err) {
        error_propagate(errp, local_err);
        return;
    }
}

static void stm32f100rb_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    STM32DeviceClass *nc = STM32F100RB_CLASS(klass);

    nc->parent_realize = dc->realize;
    dc->realize = stm32f100rb_mcu_realize_callback;
    dc->props = stm32_mcu_properties;
}

static const TypeInfo stm32f100rb_mcu_type_info = {
    .name = TYPE_STM32F100RB,
    .parent = TYPE_STM32_MCU,
    .instance_size = sizeof(STM32MCUState),
    .instance_init = stm32f100rb_mcu_instance_init_callback,
    .class_init = stm32f100rb_mcu_class_init_callback,
    .class_size = sizeof(STM32DeviceClass) };

/* ----- STM32F103RB ----- */
static STM32Capabilities stm32f103rb_capabilities = {
    .cortexm = {
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
            .is_md = true } } };

static void stm32f103rb_mcu_construct_callback(Object *obj,
        MachineState *machine)
{
    qemu_log_function_name();

    STM32_MCU_GET_CLASS(obj)->construct(obj, &stm32f103rb_capabilities,
            machine);
}

static void stm32f103rb_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F103RB_STATE(dev);
    STM32DeviceClass *nc = STM32F103RB_GET_CLASS(state);
    Error *local_err = NULL;
    nc->parent_realize(dev, &local_err);
    if (local_err) {
        error_propagate(errp, local_err);
        return;
    }
}

static void stm32f103rb_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    STM32DeviceClass *st_class = STM32F103RB_CLASS(klass);

    st_class->parent_realize = dc->realize;
    dc->realize = stm32f103rb_mcu_realize_callback;
    dc->props = stm32_mcu_properties;

    st_class->construct = stm32f103rb_mcu_construct_callback;
}

static const TypeInfo stm32f103rb_mcu_type_info = {
    .name = TYPE_STM32F103RB,
    .parent = TYPE_STM32_MCU,
    .instance_size = sizeof(STM32MCUState),
    .class_init = stm32f103rb_mcu_class_init_callback,
    .class_size = sizeof(STM32DeviceClass) };

/* ----- STM32F107VC ----- */
static CortexMCapabilities stm32f107vc_capabilities = {
    .flash_size_kb = 256,
    .sram_size_kb = 64,
    .has_mpu = true,
    .num_irq = 68,
    .cortexm_model = CORTEX_M3 };

static void stm32f107vc_mcu_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F107VC_STATE(obj);
    state->parent_obj.capabilities = &stm32f107vc_capabilities;

    // TODO: initialize inner objects
}

static void stm32f107vc_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F107VC_STATE(dev);
    STM32DeviceClass *nc = STM32F107VC_GET_CLASS(state);
    Error *local_err = NULL;
    nc->parent_realize(dev, &local_err);
    if (local_err) {
        error_propagate(errp, local_err);
        return;
    }
}

static void stm32f107vc_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    STM32DeviceClass *nc = STM32F107VC_CLASS(klass);

    nc->parent_realize = dc->realize;
    dc->realize = stm32f107vc_mcu_realize_callback;
    dc->props = stm32_mcu_properties;
}

static const TypeInfo stm32f107vc_mcu_type_info = {
    .name = TYPE_STM32F107VC,
    .parent = TYPE_STM32_MCU,
    .instance_size = sizeof(STM32MCUState),
    .instance_init = stm32f107vc_mcu_instance_init_callback,
    .class_init = stm32f107vc_mcu_class_init_callback,
    .class_size = sizeof(STM32DeviceClass) };

/* ----- STM32L152RE ----- */
static CortexMCapabilities stm32l152re_capabilities = {
    .flash_size_kb = 512,
    .sram_size_kb = 80,
    .has_mpu = true,
    .cortexm_model = CORTEX_M3 };

static void stm32l152re_mcu_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32L152RE_STATE(obj);
    state->parent_obj.capabilities = &stm32l152re_capabilities;

    // TODO: initialize inner objects
}

static void stm32l152re_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32L152RE_STATE(dev);
    STM32DeviceClass *nc = STM32L152RE_GET_CLASS(state);
    Error *local_err = NULL;
    nc->parent_realize(dev, &local_err);
    if (local_err) {
        error_propagate(errp, local_err);
        return;
    }
}

static void stm32l152re_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    STM32DeviceClass *nc = STM32L152RE_CLASS(klass);

    nc->parent_realize = dc->realize;
    dc->realize = stm32l152re_mcu_realize_callback;
    dc->props = stm32_mcu_properties;
}

static const TypeInfo stm32l152re_mcu_type_info = {
    .name = TYPE_STM32L152RE,
    .parent = TYPE_STM32_MCU,
    .instance_size = sizeof(STM32MCUState),
    .instance_init = stm32l152re_mcu_instance_init_callback,
    .class_init = stm32l152re_mcu_class_init_callback,
    .class_size = sizeof(STM32DeviceClass) };

/* ----- STM32F205RF ----- */
static CortexMCapabilities stm32f205rf_capabilities = {
    .flash_size_kb = 768,
    .sram_size_kb = 128, /* No CCM */
    .has_mpu = true,
    .cortexm_model = CORTEX_M3 };

static void stm32f205rf_mcu_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F205RF_STATE(obj);
    state->parent_obj.capabilities = &stm32f205rf_capabilities;

    // TODO: initialize inner objects
}

static void stm32f205rf_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F205RF_STATE(dev);
    STM32DeviceClass *nc = STM32F205RF_GET_CLASS(state);
    Error *local_err = NULL;
    nc->parent_realize(dev, &local_err);
    if (local_err) {
        error_propagate(errp, local_err);
        return;
    }
}

static void stm32f205rf_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    STM32DeviceClass *nc = STM32F205RF_CLASS(klass);

    nc->parent_realize = dc->realize;
    dc->realize = stm32f205rf_mcu_realize_callback;
    dc->props = stm32_mcu_properties;
}

static const TypeInfo stm32f205rf_mcu_type_info = {
    .name = TYPE_STM32F205RF,
    .parent = TYPE_STM32_MCU,
    .instance_size = sizeof(STM32MCUState),
    .instance_init = stm32f205rf_mcu_instance_init_callback,
    .class_init = stm32f205rf_mcu_class_init_callback,
    .class_size = sizeof(STM32DeviceClass) };

/* ----- STM32F303VC ----- */
static CortexMCapabilities stm32f303vc_capabilities = {
    .flash_size_kb = 256,
    .sram_size_kb = 40,
    .has_mpu = true,
    .cortexm_model = CORTEX_M4F };

static void stm32f303vc_mcu_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F303VC_STATE(obj);
    state->parent_obj.capabilities = &stm32f303vc_capabilities;

    // TODO: initialize inner objects
}

static void stm32f303vc_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F303VC_STATE(dev);
    STM32DeviceClass *nc = STM32F303VC_GET_CLASS(state);
    Error *local_err = NULL;
    nc->parent_realize(dev, &local_err);
    if (local_err) {
        error_propagate(errp, local_err);
        return;
    }
}

static void stm32f303vc_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    STM32DeviceClass *nc = STM32F303VC_CLASS(klass);

    nc->parent_realize = dc->realize;
    dc->realize = stm32f303vc_mcu_realize_callback;
    dc->props = stm32_mcu_properties;
}

static const TypeInfo stm32f303vc_mcu_type_info = {
    .name = TYPE_STM32F303VC,
    .parent = TYPE_STM32_MCU,
    .instance_size = sizeof(STM32MCUState),
    .instance_init = stm32f303vc_mcu_instance_init_callback,
    .class_init = stm32f303vc_mcu_class_init_callback,
    .class_size = sizeof(STM32DeviceClass) };

/* ----- STM32F334R8 ----- */
static CortexMCapabilities stm32f334r8_capabilities = {
    .flash_size_kb = 64,
    .sram_size_kb = 12,
    .has_mpu = true,
    .cortexm_model = CORTEX_M4F };

static void stm32f334r8_mcu_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F334R8_STATE(obj);
    state->parent_obj.capabilities = &stm32f334r8_capabilities;

    // TODO: initialize inner objects
}

static void stm32f334r8_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F334R8_STATE(dev);
    STM32DeviceClass *nc = STM32F334R8_GET_CLASS(state);
    Error *local_err = NULL;
    nc->parent_realize(dev, &local_err);
    if (local_err) {
        error_propagate(errp, local_err);
        return;
    }
}

static void stm32f334r8_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    STM32DeviceClass *nc = STM32F334R8_CLASS(klass);

    nc->parent_realize = dc->realize;
    dc->realize = stm32f334r8_mcu_realize_callback;
    dc->props = stm32_mcu_properties;
}

static const TypeInfo stm32f334r8_mcu_type_info = {
    .name = TYPE_STM32F334R8,
    .parent = TYPE_STM32_MCU,
    .instance_size = sizeof(STM32MCUState),
    .instance_init = stm32f334r8_mcu_instance_init_callback,
    .class_init = stm32f334r8_mcu_class_init_callback,
    .class_size = sizeof(STM32DeviceClass) };

/* ----- STM32F405RG ----- */
static CortexMCapabilities stm32f405rg_capabilities = {
    .flash_size_kb = 1024,
    .sram_size_kb = 128, /* 64K CCM not counted */
    .has_mpu = true,
    .cortexm_model = CORTEX_M4F };

static void stm32f405rg_mcu_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F405RG_STATE(obj);
    state->parent_obj.capabilities = &stm32f405rg_capabilities;

    // TODO: initialize inner objects
}

static void stm32f405rg_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F405RG_STATE(dev);
    STM32DeviceClass *nc = STM32F405RG_GET_CLASS(state);
    Error *local_err = NULL;
    nc->parent_realize(dev, &local_err);
    if (local_err) {
        error_propagate(errp, local_err);
        return;
    }
}

static void stm32f405rg_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    STM32DeviceClass *nc = STM32F405RG_CLASS(klass);

    nc->parent_realize = dc->realize;
    dc->realize = stm32f405rg_mcu_realize_callback;
    dc->props = stm32_mcu_properties;
}

static const TypeInfo stm32f405rg_mcu_type_info = {
    .name = TYPE_STM32F405RG,
    .parent = TYPE_STM32_MCU,
    .instance_size = sizeof(STM32MCUState),
    .instance_init = stm32f405rg_mcu_instance_init_callback,
    .class_init = stm32f405rg_mcu_class_init_callback,
    .class_size = sizeof(STM32DeviceClass) };

/* ----- STM32F407VG ----- */
static CortexMCapabilities stm32f407vg_capabilities = {
    .flash_size_kb = 1024,
    .sram_size_kb = 128, /* 64K CCM not counted */
    .has_mpu = true,
    .cortexm_model = CORTEX_M4F };

static void stm32f407vg_mcu_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F407VG_STATE(obj);
    state->parent_obj.capabilities = &stm32f407vg_capabilities;

    // TODO: initialize inner objects
}

static void stm32f407vg_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F407VG_STATE(dev);
    STM32DeviceClass *nc = STM32F407VG_GET_CLASS(state);
    Error *local_err = NULL;
    nc->parent_realize(dev, &local_err);
    if (local_err) {
        error_propagate(errp, local_err);
        return;
    }
}

static void stm32f407vg_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    STM32DeviceClass *nc = STM32F407VG_CLASS(klass);

    nc->parent_realize = dc->realize;
    dc->realize = stm32f407vg_mcu_realize_callback;
    dc->props = stm32_mcu_properties;
}

static const TypeInfo stm32f407vg_mcu_type_info = {
    .name = TYPE_STM32F407VG,
    .parent = TYPE_STM32_MCU,
    .instance_size = sizeof(STM32MCUState),
    .instance_init = stm32f407vg_mcu_instance_init_callback,
    .class_init = stm32f407vg_mcu_class_init_callback,
    .class_size = sizeof(STM32DeviceClass) };

/* ----- STM32F407ZG ----- */
static CortexMCapabilities stm32f407zg_capabilities = {
    .flash_size_kb = 1024,
    .sram_size_kb = 128, /* 64K CCM not counted */
    .has_mpu = true,
    .cortexm_model = CORTEX_M4F };

static void stm32f407zg_mcu_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F407ZG_STATE(obj);
    state->parent_obj.capabilities = &stm32f407zg_capabilities;

    // TODO: initialize inner objects
}

static void stm32f407zg_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F407ZG_STATE(dev);
    STM32DeviceClass *nc = STM32F407ZG_GET_CLASS(state);
    Error *local_err = NULL;
    nc->parent_realize(dev, &local_err);
    if (local_err) {
        error_propagate(errp, local_err);
        return;
    }
}

static void stm32f407zg_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    STM32DeviceClass *nc = STM32F407ZG_CLASS(klass);

    nc->parent_realize = dc->realize;
    dc->realize = stm32f407zg_mcu_realize_callback;
    dc->props = stm32_mcu_properties;
}

static const TypeInfo stm32f407zg_mcu_type_info = {
    .name = TYPE_STM32F407ZG,
    .parent = TYPE_STM32_MCU,
    .instance_size = sizeof(STM32MCUState),
    .instance_init = stm32f407zg_mcu_instance_init_callback,
    .class_init = stm32f407zg_mcu_class_init_callback,
    .class_size = sizeof(STM32DeviceClass) };

/* ----- STM32F411RE ----- */
static CortexMCapabilities stm32f411re_capabilities = {
    .flash_size_kb = 512,
    .sram_size_kb = 128, /* No CCM */
    .has_mpu = true,
    .cortexm_model = CORTEX_M4F };

static void stm32f411re_mcu_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F411RE_STATE(obj);
    state->parent_obj.capabilities = &stm32f411re_capabilities;

    // TODO: initialize inner objects
}

static void stm32f411re_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F411RE_STATE(dev);
    STM32DeviceClass *nc = STM32F411RE_GET_CLASS(state);
    Error *local_err = NULL;
    nc->parent_realize(dev, &local_err);
    if (local_err) {
        error_propagate(errp, local_err);
        return;
    }
}

static void stm32f411re_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    STM32DeviceClass *nc = STM32F411RE_CLASS(klass);

    nc->parent_realize = dc->realize;
    dc->realize = stm32f411re_mcu_realize_callback;
    dc->props = stm32_mcu_properties;
}

static const TypeInfo stm32f411re_mcu_type_info = {
    .name = TYPE_STM32F411RE,
    .parent = TYPE_STM32_MCU,
    .instance_size = sizeof(STM32MCUState),
    .instance_init = stm32f411re_mcu_instance_init_callback,
    .class_init = stm32f411re_mcu_class_init_callback,
    .class_size = sizeof(STM32DeviceClass) };

/* ----- STM32F429ZI ----- */
static CortexMCapabilities stm32f429zi_capabilities = {
    .flash_size_kb = 2048,
    .sram_size_kb = 192, /* 64K CCM not counted */
    .has_mpu = true,
    .cortexm_model = CORTEX_M4F };

static void stm32f429zi_mcu_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F429ZI_STATE(obj);
    state->parent_obj.capabilities = &stm32f429zi_capabilities;

    // TODO: initialize inner objects
}

static void stm32f429zi_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32F429ZI_STATE(dev);
    STM32DeviceClass *nc = STM32F429ZI_GET_CLASS(state);
    Error *local_err = NULL;
    nc->parent_realize(dev, &local_err);
    if (local_err) {
        error_propagate(errp, local_err);
        return;
    }
}

static void stm32f429zi_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    STM32DeviceClass *nc = STM32F429ZI_CLASS(klass);

    nc->parent_realize = dc->realize;
    dc->realize = stm32f429zi_mcu_realize_callback;
    dc->props = stm32_mcu_properties;
}

static const TypeInfo stm32f429zi_mcu_type_info = {
    .name = TYPE_STM32F429ZI,
    .parent = TYPE_STM32_MCU,
    .instance_size = sizeof(STM32MCUState),
    .instance_init = stm32f429zi_mcu_instance_init_callback,
    .class_init = stm32f429zi_mcu_class_init_callback,
    .class_size = sizeof(STM32DeviceClass) };

/* ----- Type inits. ----- */

static void stm32_types_init()
{
    type_register_static(&stm32f051r8_mcu_type_info);
    type_register_static(&stm32f100rb_mcu_type_info);
    type_register_static(&stm32f103rb_mcu_type_info);
    type_register_static(&stm32f107vc_mcu_type_info);
    type_register_static(&stm32l152re_mcu_type_info);
    type_register_static(&stm32f205rf_mcu_type_info);
    type_register_static(&stm32f303vc_mcu_type_info);
    type_register_static(&stm32f334r8_mcu_type_info);
    type_register_static(&stm32f405rg_mcu_type_info);
    type_register_static(&stm32f407vg_mcu_type_info);
    type_register_static(&stm32f407zg_mcu_type_info);
    type_register_static(&stm32f411re_mcu_type_info);
    type_register_static(&stm32f429zi_mcu_type_info);
}

#if defined(CONFIG_GNU_ARM_ECLIPSE)
type_init(stm32_types_init);
#endif
