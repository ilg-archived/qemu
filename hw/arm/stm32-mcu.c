/*
 * STM32 Cortex-M device emulation.
 *
 * Copyright (c) 2014 Liviu Ionescu.
 * Copyright (c) 2010 Andre Beckus.
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
#include "hw/arm/cortexm-helper.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/* ----- Private ----------------------------------------------------------- */

/**
 * Create children GPIO nodes. Public names are "/machine/stm32/gpio[%c]".
 */
static void create_gpio(STM32MCUState *state, stm32_gpio_index_t index,
        const STM32Capabilities *capabilities)
{
    Object *gpio = object_new(TYPE_STM32_GPIO);
    char child_name[10];
    snprintf(child_name, sizeof(child_name), "gpio[%c]", 'a' + index);
    object_property_add_child(state->container, child_name, gpio, NULL);

    object_property_set_int(gpio, index, "port-index", NULL);

    // TODO: get rid of pointers
    qdev_prop_set_ptr(DEVICE(gpio), "capabilities", (void *) capabilities);
    qdev_prop_set_ptr(DEVICE(gpio), "rcc", state->rcc);

    cm_object_realize(gpio);

    state->gpio[index] = DEVICE(gpio);
}

/**
 * Constructor for all STM32 devices, based on capabilities.
 *
 * Alias the flash memory to 0x08000000.
 *
 * TODO: define the special CCM region for the models that include it.
 */
static void stm32_mcu_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /* Call parent realize(). */
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_MCU)) {
        return;
    }

    STM32MCUState *state = STM32_MCU_STATE(dev);
    const STM32Capabilities *capabilities = state->param_capabilities;
    assert(capabilities != NULL);
    state->capabilities = capabilities;

    const char *family;
    switch (capabilities->family) {
    case STM32_FAMILY_F1:
        family = "F1";
        break;
    case STM32_FAMILY_F2:
        family = "F2";
        break;
    case STM32_FAMILY_F3:
        family = "F3";
        break;
    case STM32_FAMILY_F4:
        family = "F4";
        break;
    case STM32_FAMILY_L1:
        family = "L1";
        break;
    default:
        family = "unknown";
    }
    qemu_log_mask(LOG_TRACE, "STM32 Family: %s\n", family);

    /* Devices will be addressed below "/machine/stm32". */
    state->container = container_get(qdev_get_machine(), "/stm32");

    /* RCC */
    {
        Object *rcc = object_new(TYPE_STM32_RCC);
        /* RCC will be named "/machine/stm32/rcc" */
        object_property_add_child(state->container, "rcc", rcc, NULL);

        // TODO: get rid of pointers
        /* Copy capabilities into internal objects. */
        qdev_prop_set_ptr(DEVICE(rcc), "capabilities", (void *) capabilities);

        /* Copy internal oscillator frequencies from capabilities. */
        object_property_set_int(rcc, capabilities->hsi_freq_hz, "hsi-freq-hz",
        NULL);
        object_property_set_int(rcc, capabilities->lsi_freq_hz, "lsi-freq-hz",
        NULL);

        /* Forward properties to RCC. */
        object_property_set_int(rcc, state->hse_freq_hz, "hse-freq-hz", NULL);
        object_property_set_int(rcc, state->lse_freq_hz, "lse-freq-hz", NULL);

        cm_object_realize(rcc);

        state->rcc = DEVICE(rcc);
    }

    /* FLASH */
    {
        Object *flash = object_new(TYPE_STM32_FLASH);
        /* FLASH will be named "/machine/stm32/flash" */
        object_property_add_child(state->container, "flash", flash,
        NULL);

        // TODO: get rid of pointers
        qdev_prop_set_ptr(DEVICE(flash), "capabilities", (void *) capabilities);

        cm_object_realize(flash);

        state->flash = DEVICE(flash);
    }

    /* GPIOA */
    if (capabilities->has_gpioa) {
        create_gpio(state, STM32_GPIO_PORT_A, capabilities);
    }

    /* GPIOB */
    if (capabilities->has_gpiob) {
        create_gpio(state, STM32_GPIO_PORT_B, capabilities);
    }

    /* GPIOC */
    if (capabilities->has_gpioc) {
        create_gpio(state, STM32_GPIO_PORT_C, capabilities);
    }

    /* GPIOD */
    if (capabilities->has_gpiod) {
        create_gpio(state, STM32_GPIO_PORT_D, capabilities);
    }

    /* GPIOE */
    if (capabilities->has_gpioe) {
        create_gpio(state, STM32_GPIO_PORT_E, capabilities);
    }

    /* GPIOF */
    if (capabilities->has_gpiof) {
        create_gpio(state, STM32_GPIO_PORT_F, capabilities);
    }

    /* GPIOG */
    if (capabilities->has_gpiog) {
        create_gpio(state, STM32_GPIO_PORT_G, capabilities);
    }

    /* TODO: add more devices. */

}

static void stm32_mcu_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    /* Call parent reset(). */
    cm_device_parent_reset(dev, TYPE_STM32_MCU);

    STM32MCUState *state = STM32_MCU_STATE(dev);
    if (state->rcc) {
        device_reset(state->rcc);
    }

    if (state->flash) {
        device_reset(state->flash);
    }

    int i;
    for (i = 0; i < STM32_MAX_GPIO; ++i) {
        if (state->gpio[i]) {
            device_reset(state->gpio[i]);
        }
    }
}

/**
 * Virtual function, overriding (in fact extending) the Cortex-M code.
 */
static void stm32_mcu_memory_regions_create_callback(DeviceState *dev)
{
    qemu_log_function_name();

    /* Create the parent (Cortex-M) memory regions */
    CortexMClass *parent_class = CORTEXM_MCU_CLASS(
            object_class_by_name(TYPE_CORTEXM_MCU));
    parent_class->memory_regions_create(dev);

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

#define DEFINE_PROP_STM32CAPABILITIES_PTR(_n, _s, _f) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_ptr, const STM32Capabilities*)

static Property stm32_mcu_properties[] = {
        DEFINE_PROP_STM32CAPABILITIES_PTR("stm32-capabilities",
                STM32MCUState, param_capabilities),
        DEFINE_PROP_UINT32("hse-freq-hz", STM32MCUState, hse_freq_hz,
                DEFAULT_HSE_FREQ_HZ),
        DEFINE_PROP_UINT32("lse-freq-hz", STM32MCUState, lse_freq_hz,
                DEFAULT_RTC_FREQ_HZ),
    DEFINE_PROP_END_OF_LIST(), /**/
};

static void stm32_mcu_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    dc->realize = stm32_mcu_realize_callback;
    dc->props = stm32_mcu_properties;
    dc->reset = stm32_mcu_reset_callback;

    CortexMClass *cm_class = CORTEXM_MCU_CLASS(klass);
    cm_class->memory_regions_create = stm32_mcu_memory_regions_create_callback;
}

static const TypeInfo stm32_mcu_type_info = {
    .abstract = true,
    .name = TYPE_STM32_MCU,
    .parent = TYPE_STM32_MCU_PARENT,
    .instance_size = sizeof(STM32MCUState),
    .class_init = stm32_mcu_class_init_callback,
    .class_size = sizeof(STM32MCUClass) /**/
};

/* ----- Type inits. ----- */

static void stm32_type_init(void)
{
    type_register_static(&stm32_mcu_type_info);
}

type_init(stm32_type_init);

/* ------------------------------------------------------------------------- */

