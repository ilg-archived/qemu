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

#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>
#include <hw/cortexm/svd.h>
#include <hw/cortexm/bitband.h>
#include <hw/cortexm/json-parser.h>

#include "sysemu/sysemu.h"
#include "qemu/error-report.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/* ----- Public ------------------------------------------------------------ */

/* ----- Private ----------------------------------------------------------- */

/*
 * Create children GPIO nodes. Public names are "/machine/stm32/gpio[%c]".
 */
static void create_gpio(STM32MCUState *state, stm32_gpio_index_t index,
        const STM32Capabilities *capabilities)
{
    state->gpio[index] = DEVICE(stm32_gpio_create(state->container, index));
}

/*
 * Create children USART/UART nodes.
 * Public names are "/machine/stm32/usart[%c]".
 */
static void create_usart(STM32MCUState *state, stm32_usart_index_t index,
        const STM32Capabilities *capabilities)
{
    char child_name[10];
    char chardev_name[10];
    CharDriverState *chr;

    snprintf(child_name, sizeof(child_name), "usart[%c]", '1' + index);
    Object *usart = cm_object_new(state->container, child_name,
    TYPE_STM32_USART);

    object_property_set_int(usart, index, "port-index", NULL);
    // TODO: get rid of pointers
    qdev_prop_set_ptr(DEVICE(usart), "capabilities", (void *) capabilities);
    qdev_prop_set_ptr(DEVICE(usart), "rcc", state->rcc);
    qdev_prop_set_ptr(DEVICE(usart), "nvic", state->parent_obj.nvic);

    if ((int) index >= MAX_SERIAL_PORTS) {
        hw_error("Cannot assign usart %d: QEMU supports only %d ports\n", index,
        MAX_SERIAL_PORTS);
    }
    chr = serial_hds[index];
    if (!chr) {
        snprintf(chardev_name, ARRAY_SIZE(chardev_name), "serial%d", index);
        chr = qemu_chr_new(chardev_name, "null", NULL);
        if (!(chr)) {
            hw_error("Can't assign serial port to %s.\n", child_name);
        }
    }
    qdev_prop_set_chr(DEVICE(usart), "chardev", chr);

    cm_object_realize(usart);

    state->usart[index] = DEVICE(usart);
}

/*
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
    STM32Capabilities *capabilities = g_new0(STM32Capabilities, 1);

    if (state->param_capabilities) {
        /* Copy R/O structure to a local R/W copy, to update it. */
        memcpy(capabilities, state->param_capabilities,
                sizeof(STM32Capabilities));
    }

    assert(capabilities != NULL);
    state->capabilities = capabilities;

    CortexMState *cm_state = CORTEXM_MCU_STATE(dev);
    const char *svd_device_name = cm_state->capabilities->svd_device_name;

    /* Based on the SVD device name, set some capabilities fields,
     * for faster access. */
    if (strcmp("STM32F40x", svd_device_name) == 0) {
        capabilities->family = STM32_FAMILY_F4;
        capabilities->f4.is_40x = true;
    } else {
        error_printf("Unsupported device name '%s'.\n", svd_device_name);
        // TODO: uncomment when all devices use svd
        // exit(1)
    }

    const char *family;
    const char *device_file_name;
    switch (capabilities->family) {
    case STM32_FAMILY_F0:
        family = "F0";
        device_file_name = "stm32f0.json";
        break;
    case STM32_FAMILY_F1:
        family = "F1";
        device_file_name = "stm32f1.json";
        break;
    case STM32_FAMILY_F2:
        family = "F2";
        device_file_name = "stm32f2.json";
        break;
    case STM32_FAMILY_F3:
        family = "F3";
        device_file_name = "stm32f3.json";
        break;
    case STM32_FAMILY_F4:
        family = "F4";
        device_file_name = "stm32f4.json";
        break;
    case STM32_FAMILY_F7:
        family = "F7";
        device_file_name = "stm32f7.json";
        break;
    case STM32_FAMILY_H7:
        family = "H7";
        device_file_name = "stm32h7.json";
        break;
    case STM32_FAMILY_L0:
        family = "L0";
        device_file_name = "stm32l0.json";
        break;
    case STM32_FAMILY_L1:
        family = "L1";
        device_file_name = "stm32l1.json";
        break;
    case STM32_FAMILY_L4:
        family = "L4";
        device_file_name = "stm32l4.json";
        break;
    default:
        family = "unknown";
    }
    qemu_log_mask(LOG_FUNC, "STM32 Family: %s\n", family);

    const char *device_full_name = qemu_find_file(QEMU_FILE_TYPE_DEVICES,
            device_file_name);
    if (device_full_name == NULL) {
        error_printf("Device file '%s' not found.\n", device_full_name);
        exit(1);
    }

#if defined(CONFIG_VERBOSE)
    if (verbosity_level >= VERBOSITY_DETAILED) {
        printf("Device file: '%s'.\n", device_full_name);
    }
#endif

    state->family_json = json_parse_file(device_full_name);

    /* Devices will be addressed below "/machine/mcu/stm32". */
    state->container = container_get(OBJECT(dev), "/stm32");

    /* Memory alias */
    {
        /*
         * The STM32 family stores its Flash memory at some base address
         * in memory (0x08000000 for medium density devices), and then
         * aliases it to the boot memory space, which starts at 0x00000000
         * (the "System Memory" can also be aliased to 0x00000000,
         * but this is not implemented here).
         * The processor executes the code in the aliased memory at 0x00000000.
         * We need to make a QEMU alias so that reads in the 0x08000000 area
         * are passed through to the 0x00000000 area. Note that this is the
         * opposite of real hardware, where the memory at 0x00000000 passes
         * reads through the "real" flash memory at 0x08000000, but it works
         * the same either way.
         */
        int flash_size = cm_state->flash_size_kb * 1024;

        /* Allocate a new region for the alias */
        MemoryRegion *flash_alias_mem = g_malloc(sizeof(MemoryRegion));

        Object *mem_container = container_get(cm_state->container, "/memory");

        /* Initialise the new region */
        memory_region_init_alias(flash_alias_mem, mem_container,
                "mem-flash-alias", &cm_state->flash_mem, 0, flash_size);
        memory_region_set_readonly(flash_alias_mem, true);

        /* Alias it as the STM specific 0x08000000 */
        memory_region_add_subregion(get_system_memory(), 0x08000000,
                flash_alias_mem);
    }

    /* Peripheral bitband. */
    {
        if (capabilities->has_periph_bitband) {
            cortexm_bitband_init(state->container, "periph-bitband",
                    0x40000000);
        }
    }

    /* RCC */
    {
        /* RCC will be named "/machine/mcu/stm32/RCC" */
        Object *rcc = cm_object_new(state->container, "RCC", TYPE_STM32_RCC);

        /* Copy internal oscillator frequencies from capabilities. */
        cm_object_property_set_int(rcc, capabilities->hsi_freq_hz,
                "hsi-freq-hz");
        cm_object_property_set_int(rcc, capabilities->lsi_freq_hz,
                "lsi-freq-hz");

        /* Forward properties from MCU to RCC. */
        cm_object_property_set_int(rcc, state->hse_freq_hz, "hse-freq-hz");
        cm_object_property_set_int(rcc, state->lse_freq_hz, "lse-freq-hz");

        cm_object_realize(rcc);

        state->rcc = DEVICE(rcc);
    }

    /* FLASH */
    if (svd_has_named_peripheral(cm_state->svd_json, "FLASH")) {
        /* FLASH will be named "/machine/mcu/stm32/FLASH" */
        Object *flash = cm_object_new(state->container, "FLASH",
        TYPE_STM32_FLASH);

        cm_object_realize(flash);

        state->flash = DEVICE(flash);
    }

    /* PWR */
    if (svd_has_named_peripheral(cm_state->svd_json, "PWR")) {
        /* PWRR will be named "/machine/mcu/stm32/PWR". */
        Object *pwr = cm_object_new(state->container, "PWR",
        TYPE_STM32_PWR);

        cm_object_realize(pwr);

        state->pwr = DEVICE(pwr);
    }

    /* SYSCFG */
    if (svd_has_named_peripheral(cm_state->svd_json, "SYSCFG")) {
        /*
         * SYSCFG will be named "/machine/mcu/stm32/SYSCFG".
         * It controls, among other, which GPIO pins are
         * connected to EXTI.
         */
        Object *syscfg = cm_object_new(state->container, "SYSCFG",
        TYPE_STM32_SYSCFG);

        cm_object_realize(syscfg);

        state->syscfg = DEVICE(syscfg);
    }

    /* EXTI */
    if (svd_has_named_peripheral(cm_state->svd_json, "EXTI")) {
        /* EXTI will be named "/machine/mcu/stm32/EXTI".
         * It is referred by the GPIOs, to forward interrupts, so
         * it must be constructed before the GPIOs. */
        Object *exti = cm_object_new(state->container, "EXTI",
        TYPE_STM32_EXTI);

        cm_object_realize(exti);

        state->exti = DEVICE(exti);
    }

    state->num_gpio = 0;

    /* GPIOA */
    if (svd_has_named_peripheral(cm_state->svd_json, "GPIOA")) {
        create_gpio(state, STM32_GPIO_PORT_A, capabilities);
        state->num_gpio = 1;
    }

    /* GPIOB */
    if (svd_has_named_peripheral(cm_state->svd_json, "GPIOB")) {
        create_gpio(state, STM32_GPIO_PORT_B, capabilities);
        state->num_gpio = 2;
    }

    /* GPIOC */
    if (svd_has_named_peripheral(cm_state->svd_json, "GPIOC")) {
        create_gpio(state, STM32_GPIO_PORT_C, capabilities);
        state->num_gpio = 3;
    }

    /* GPIOD */
    if (svd_has_named_peripheral(cm_state->svd_json, "GPIOD")) {
        create_gpio(state, STM32_GPIO_PORT_D, capabilities);
        state->num_gpio = 4;
    }

    /* GPIOE */
    if (svd_has_named_peripheral(cm_state->svd_json, "GPIOE")) {
        create_gpio(state, STM32_GPIO_PORT_E, capabilities);
        state->num_gpio = 5;
    }

    /* GPIOF */
    if (svd_has_named_peripheral(cm_state->svd_json, "GPIOF")) {
        create_gpio(state, STM32_GPIO_PORT_F, capabilities);
        state->num_gpio = 6;
    }

    /* GPIOG */
    if (svd_has_named_peripheral(cm_state->svd_json, "GPIOG")) {
        create_gpio(state, STM32_GPIO_PORT_G, capabilities);
        state->num_gpio = 7;
    }

    /* GPIOH */
    if (svd_has_named_peripheral(cm_state->svd_json, "GPIOH")) {
        create_gpio(state, STM32_GPIO_PORT_H, capabilities);
        state->num_gpio = 8;
    }

    /* GPIOI */
    if (svd_has_named_peripheral(cm_state->svd_json, "GPIOI")) {
        create_gpio(state, STM32_GPIO_PORT_I, capabilities);
        state->num_gpio = 9;
    }

    /* GPIOJ */
    if (svd_has_named_peripheral(cm_state->svd_json, "GPIOJ")) {
        create_gpio(state, STM32_GPIO_PORT_J, capabilities);
        state->num_gpio = 10;
    }

    /* GPIOK */
    if (svd_has_named_peripheral(cm_state->svd_json, "GPIOK")) {
        create_gpio(state, STM32_GPIO_PORT_K, capabilities);
        state->num_gpio = 11;
    }

    /* USART1 */
    if (svd_has_named_peripheral(cm_state->svd_json, "USART1")) {
        create_usart(state, STM32_USART_1, capabilities);
    }

    /* USART2 */
    if (svd_has_named_peripheral(cm_state->svd_json, "USART2")) {
        create_usart(state, STM32_USART_2, capabilities);
    }

    /* USART3 */
    if (svd_has_named_peripheral(cm_state->svd_json, "USART3")) {
        create_usart(state, STM32_USART_3, capabilities);
    }

#if 0
    /* UART4 */
    if (svd_has_named_peripheral(cm_state->svd_json, "UART4")) {
        create_uart(state, STM32_UART_4, capabilities);
    }

    /* UART5 */
    if (svd_has_named_peripheral(cm_state->svd_json, "UART5")) {
        create_uart(state, STM32_UART_5, capabilities);
    }
#endif

    /* USART6 */
    if (svd_has_named_peripheral(cm_state->svd_json, "USART6")) {
        create_usart(state, STM32_USART_6, capabilities);
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

    for (i = 0; i < STM32_MAX_USART; ++i) {
        if (state->usart[i]) {
            device_reset(state->usart[i]);
        }
    }
}

/*
 * Virtual function, overriding (in fact extending) the Cortex-M code.
 */
static void stm32_mcu_memory_regions_create_callback(DeviceState *dev)
{
    qemu_log_function_name();

    /* Create the parent (Cortex-M) memory regions */
    CortexMClass *parent_class = CORTEXM_MCU_CLASS(
            object_class_by_name(TYPE_CORTEXM_MCU));
    parent_class->memory_regions_create(dev);
}

// TODO: get rid of the pointer property.
#define DEFINE_PROP_STM32CAPABILITIES_PTR(_n, _s, _f) \
    DEFINE_PROP(_n, _s, _f, qdev_prop_ptr, const STM32Capabilities*)

static Property stm32_mcu_properties[] = {
        DEFINE_PROP_STM32CAPABILITIES_PTR("stm32-capabilities",
                STM32MCUState, param_capabilities),
    DEFINE_PROP_END_OF_LIST(), /**/
};

static void stm32_mcu_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    STM32MCUState *state = STM32_MCU_STATE(obj);

    cm_object_property_add_uint32(obj, "hse-freq-hz", &state->hse_freq_hz);
    state->hse_freq_hz = 0;

    cm_object_property_add_uint32(obj, "lse-freq-hz", &state->lse_freq_hz);
    state->lse_freq_hz = 0;
}

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
    .instance_init = stm32_mcu_instance_init_callback,
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

