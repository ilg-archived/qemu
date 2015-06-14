/*
 * STM32 Cortex-M device emulation.
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

#include "hw/arm/stm32-mcu.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/*
 * Common layer for all STM32 devices.
 * Alias the flash memory to 0x08000000.
 *
 * TODO: define the special CCM region for the models that include it.
 */

static void stm32_mcu_construct_callback(Object *obj,
        STM32Capabilities* capabilities, CortexMCapabilities* core_capabilities,
        MachineState *machine)
{
    qemu_log_function_name();

    CORTEXM_MCU_GET_CLASS(obj)->construct(obj, core_capabilities, machine);

    STM32MCUState *state = STM32_MCU_STATE(obj);
    assert(capabilities != NULL);
    state->capabilities = capabilities;

    const char *family;
    switch (capabilities->family) {
    case STM32_FAMILY_F1:
        family = "F1";
        break;
    case STM32_FAMILY_F4:
        family = "F4";
        break;
    default:
        family = "unknown";
    }
    qemu_log_mask(LOG_TRACE, "STM32 Family: %s\n", family);

    DeviceState *dev2;
    STM32SysBusDevice *sbd;

    /* RCC */
    {
        state->rcc = qdev_create(NULL, TYPE_STM32_RCC);
        dev2 = DEVICE(state->rcc);

        /* Copy capabilities into internal objects. */
        sbd = STM32_SYS_BUS_DEVICE_STATE(state->rcc);
        sbd->capabilities = capabilities;

        /* Copy internal oscillator frequencies from capabilities. */
        qdev_prop_set_uint32(dev2, "hsi-freq-hz",
                sbd->capabilities->hsi_freq_hz);
        qdev_prop_set_uint32(dev2, "lsi-freq-hz",
                sbd->capabilities->lsi_freq_hz);
    }

    /* FLASH */
    {
        state->flash = qdev_create(NULL, TYPE_STM32_FLASH);
        sbd = STM32_SYS_BUS_DEVICE_STATE(state->flash);
        sbd->capabilities = capabilities;
    }

    STM32GPIOState *gdev;
    /* GPIOA */
    if (capabilities->has_gpioa) {
        state->gpio[STM32_GPIO_PORT_A] = qdev_create(NULL, TYPE_STM32_GPIO);
        sbd = STM32_SYS_BUS_DEVICE_STATE(state->gpio[STM32_GPIO_PORT_A]);
        sbd->capabilities = capabilities;

        gdev = STM32_GPIO_STATE(state->gpio[STM32_GPIO_PORT_A]);
        gdev->port_index = STM32_GPIO_PORT_A;
        gdev->rcc = STM32_RCC_STATE(state->rcc);
    }

    /* GPIOB */
    if (capabilities->has_gpiob) {
        state->gpio[STM32_GPIO_PORT_B] = qdev_create(NULL, TYPE_STM32_GPIO);
        sbd = STM32_SYS_BUS_DEVICE_STATE(state->gpio[STM32_GPIO_PORT_B]);
        sbd->capabilities = capabilities;

        gdev = STM32_GPIO_STATE(state->gpio[STM32_GPIO_PORT_B]);
        gdev->port_index = STM32_GPIO_PORT_B;
        gdev->rcc = STM32_RCC_STATE(state->rcc);
    }

    /* GPIOC */
    if (capabilities->has_gpioc) {
        state->gpio[STM32_GPIO_PORT_C] = qdev_create(NULL, TYPE_STM32_GPIO);
        sbd = STM32_SYS_BUS_DEVICE_STATE(state->gpio[STM32_GPIO_PORT_C]);
        sbd->capabilities = capabilities;

        gdev = STM32_GPIO_STATE(state->gpio[STM32_GPIO_PORT_C]);
        gdev->port_index = STM32_GPIO_PORT_C;
        gdev->rcc = STM32_RCC_STATE(state->rcc);
    }

    /* GPIOD */
    if (capabilities->has_gpiod) {
        state->gpio[STM32_GPIO_PORT_D] = qdev_create(NULL, TYPE_STM32_GPIO);
        sbd = STM32_SYS_BUS_DEVICE_STATE(state->gpio[STM32_GPIO_PORT_D]);
        sbd->capabilities = capabilities;

        gdev = STM32_GPIO_STATE(state->gpio[STM32_GPIO_PORT_D]);
        gdev->port_index = STM32_GPIO_PORT_D;
        gdev->rcc = STM32_RCC_STATE(state->rcc);
    }

    /* GPIOE */
    if (capabilities->has_gpioe) {
        state->gpio[STM32_GPIO_PORT_E] = qdev_create(NULL, TYPE_STM32_GPIO);
        sbd = STM32_SYS_BUS_DEVICE_STATE(state->gpio[STM32_GPIO_PORT_E]);
        sbd->capabilities = capabilities;

        gdev = STM32_GPIO_STATE(state->gpio[STM32_GPIO_PORT_E]);
        gdev->port_index = STM32_GPIO_PORT_E;
        gdev->rcc = STM32_RCC_STATE(state->rcc);
    }

    /* GPIOF */
    if (capabilities->has_gpiof) {
        state->gpio[STM32_GPIO_PORT_F] = qdev_create(NULL, TYPE_STM32_GPIO);
        sbd = STM32_SYS_BUS_DEVICE_STATE(state->gpio[STM32_GPIO_PORT_F]);
        sbd->capabilities = capabilities;

        gdev = STM32_GPIO_STATE(state->gpio[STM32_GPIO_PORT_F]);
        gdev->port_index = STM32_GPIO_PORT_F;
        gdev->rcc = STM32_RCC_STATE(state->rcc);
    }

    /* GPIOG */
    if (capabilities->has_gpiog) {
        state->gpio[STM32_GPIO_PORT_G] = qdev_create(NULL, TYPE_STM32_GPIO);
        sbd = STM32_SYS_BUS_DEVICE_STATE(state->gpio[STM32_GPIO_PORT_G]);
        sbd->capabilities = capabilities;

        gdev = STM32_GPIO_STATE(state->gpio[STM32_GPIO_PORT_G]);
        gdev->port_index = STM32_GPIO_PORT_G;
        gdev->rcc = STM32_RCC_STATE(state->rcc);
    }
}

static void stm32_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32_MCU_STATE(dev);
    STM32MCUClass *nc = STM32_MCU_GET_CLASS(state);
    Error *local_err = NULL;
    nc->parent_realize(dev, &local_err);
    if (local_err) {
        error_propagate(errp, local_err);
        return;
    }

    CortexMState *cm_state = CORTEXM_MCU_STATE(dev);
    STM32Capabilities *capabilities =
            (STM32Capabilities *) cm_state->capabilities;
    assert(capabilities != NULL);

    /* RCC */
    qdev_realize(DEVICE(state->rcc));

    /* FLASH */
    qdev_realize(DEVICE(state->flash));

    /* GPIO[A-G] */
    for (int i = 0; i < STM32_MAX_GPIO; ++i) {
        /* Realize all initialised GPIOs */
        if (state->gpio[i]) {
            qdev_realize(DEVICE(state->gpio[i]));
        }
    }
}

static void stm32_mcu_memory_regions_create_callback(DeviceState *dev)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32_MCU_STATE(dev);
    STM32MCUClass *st_class = STM32_MCU_GET_CLASS(state);

    /* Create the parent (Cortex-M) memory regions */
    st_class->parent_memory_regions_create(dev);

    /**
     * The STM32 family stores its Flash memory at some base address in memory
     * (0x08000000 for medium density devices), and then aliases it to the
     * boot memory space, which starts at 0x00000000 (the "System Memory" can
     * also be aliased to 0x00000000, but this is not implemented here).
     * The processor executes the code in the aliased memory at 0x00000000.
     * We need to make a QEMU alias so that reads in the 0x08000000 area
     * are passed through to the 0x00000000 area. Note that this is the
     * opposite of real hardware, where the memory at 0x00000000 passes
     * reads through the "real" flash memory at 0x08000000, but it works
     * the same either way.
     */
    CortexMState *cm_state = CORTEXM_MCU_STATE(dev);
    int flash_size = cm_state->flash_size_kb * 1024;

    /* Allocate a new region for the alias */
    MemoryRegion *flash_alias_mem = g_malloc(sizeof(MemoryRegion));

    /* Initialise the new region */
    memory_region_init_alias(flash_alias_mem, NULL, "stm32-mem-flash-alias",
            &cm_state->flash_mem, 0, flash_size);
    memory_region_set_readonly(flash_alias_mem, true);

    /* Alias it as the STM specific 0x08000000 */
    memory_region_add_subregion(get_system_memory(), 0x08000000,
            flash_alias_mem);
}

static Property stm32_mcu_properties[] = {
    /* TODO: add STM32 specific properties */
    DEFINE_PROP_END_OF_LIST(), //
        };

static void stm32_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    STM32MCUClass *st_class = STM32_MCU_CLASS(klass);
    st_class->construct = stm32_mcu_construct_callback;

    DeviceClass *dc = DEVICE_CLASS(klass);
    st_class->parent_realize = dc->realize;
    dc->realize = stm32_mcu_realize_callback;
    dc->props = stm32_mcu_properties;

    CortexMClass *cm_class = CORTEXM_MCU_CLASS(klass);
    st_class->parent_memory_regions_create = cm_class->memory_regions_create;
    cm_class->memory_regions_create = stm32_mcu_memory_regions_create_callback;
}

static const TypeInfo stm32_mcu_type_info = {
    .abstract = true,
    .name = TYPE_STM32_MCU,
    .parent = TYPE_CORTEXM_MCU,
    .instance_size = sizeof(STM32MCUState),
    .class_init = stm32_mcu_class_init_callback,
    .class_size = sizeof(STM32MCUClass) };

/* ----- Type inits. ----- */

static void stm32_type_init()
{
    type_register_static(&stm32_mcu_type_info);

}

#if defined(CONFIG_GNU_ARM_ECLIPSE)
type_init(stm32_type_init);
#endif
