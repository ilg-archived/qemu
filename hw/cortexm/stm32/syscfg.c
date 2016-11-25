/*
 * STM32 MCU - EXTI (system configuration controller) emulation.
 *
 * Copyright (c) 2016 Liviu Ionescu.
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

#include <hw/cortexm/stm32/syscfg.h>
#include <hw/cortexm/stm32/mcu.h>
#include <hw/cortexm/helper.h>

/*
 * This file implements the STM32 SYSCFG.
 *
 * References:
 * - Doc ID 018909 Rev 6, "ST RM0090 Reference manual,
 * STM32F405xx/07xx, STM32F415xx/17xx, STM32F42xxx and STM32F43xxx
 * advanced ARM-based 32-bit MCUs"
 *
 * - Doc ID 026448 Rev 1, "ST RM0383 Reference manual,
 * STM32F411xC/E advanced ARM-based 32-bit MCUs"
 *
 * - Doc 13902 Rev 15, "ST RM0008 Reference manual,
 * STM32F101xx, STM32F102xx, STM32F103xx, STM32F105xx and STM32F107xx
 * advanced ARM-based 32-bit MCUs"
 *
 * All STM32 reference manuals are available from:
 * http://www.st.com/content/st_com/en/support/resources/resource-selector.html?querycriteria=productId=SC1169$$resourceCategory=technical_literature$$resourceType=reference_manual
 */

/* ----- Private ----------------------------------------------------------- */

/* ------------------------------------------------------------------------- */

static PeripheralInfo stm32f4xxxx_syscfg_info =
        {
            .desc = "System configuration controller (SYSCFG)",

            .registers =
                    (PeripheralRegisterInfo[] ) {
                                {
                                    .desc =
                                            "Memory remap register (SYSCFG_MEMRMP)",
                                    .name = "memrmp",
                                    .offset_bytes = 0x00,
                                    .reset_value = 0x00000000,
                                    .access_flags =
                                    PERIPHERAL_REGISTER_32BITS_ALL,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .desc =
                                                                    "Memory mapping selection",
                                                            .name = "mem-mode",
                                                            .first_bit = 0,
                                                            .width_bits = 2,
                                                        /**/
                                                        },
                                                        { } /**/
                                                    } ,
                                /**/
                                },
                                {
                                    .desc =
                                            "Peripheral mode configuration register (SYSCFG_PMC)",
                                    .name = "pmc",
                                    .offset_bytes = 0x04,
                                    .reset_value = 0x00000000,
                                    .access_flags =
                                    PERIPHERAL_REGISTER_32BITS_ALL,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .desc =
                                                                    "Ethernet PHY interface selection",
                                                            .name =
                                                                    "mii-rmii-sel",
                                                            .first_bit = 7,
                                                            .width_bits = 1,
                                                        /**/
                                                        },
                                                        { } /**/
                                                    } ,
                                /**/
                                },
                                {
                                    .desc =
                                            "External interrupt configuration register 1 (SYSCFG_EXTICR1)",
                                    .name = "exticr1",
                                    .offset_bytes = 0x08,
                                    .reset_value = 0x00000000,
                                    .access_flags =
                                    PERIPHERAL_REGISTER_32BITS_ALL,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .desc =
                                                                    "EXTI 0 configuration",
                                                            .name = "exti0",
                                                            .first_bit = 0,
                                                            .width_bits = 4,
                                                        /**/
                                                        },
                                                        {
                                                            .desc =
                                                                    "EXTI 1 configuration",
                                                            .name = "exti1",
                                                            .first_bit = 4,
                                                            .width_bits = 4,
                                                        /**/
                                                        },
                                                        {
                                                            .desc =
                                                                    "EXTI 2 configuration",
                                                            .name = "exti2",
                                                            .first_bit = 8,
                                                            .width_bits = 4,
                                                        /**/
                                                        },
                                                        {
                                                            .desc =
                                                                    "EXTI 3 configuration",
                                                            .name = "exti3",
                                                            .first_bit = 12,
                                                            .width_bits = 4,
                                                        /**/
                                                        },
                                                        { } /**/
                                                    } ,
                                /**/
                                },
                                {
                                    .desc =
                                            "External interrupt configuration register 2 (SYSCFG_EXTICR2)",
                                    .name = "exticr2",
                                    .offset_bytes = 0x0C,
                                    .reset_value = 0x00000000,
                                    .access_flags =
                                    PERIPHERAL_REGISTER_32BITS_ALL,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .desc =
                                                                    "EXTI 4 configuration",
                                                            .name = "exti4",
                                                            .first_bit = 0,
                                                            .width_bits = 4,
                                                        /**/
                                                        },
                                                        {
                                                            .desc =
                                                                    "EXTI 5 configuration",
                                                            .name = "exti5",
                                                            .first_bit = 4,
                                                            .width_bits = 4,
                                                        /**/
                                                        },
                                                        {
                                                            .desc =
                                                                    "EXTI 6 configuration",
                                                            .name = "exti6",
                                                            .first_bit = 8,
                                                            .width_bits = 4,
                                                        /**/
                                                        },
                                                        {
                                                            .desc =
                                                                    "EXTI 7 configuration",
                                                            .name = "exti7",
                                                            .first_bit = 12,
                                                            .width_bits = 4,
                                                        /**/
                                                        },
                                                        { } /**/
                                                    } ,
                                /**/
                                },
                                {
                                    .desc =
                                            "External interrupt configuration register 3 (SYSCFG_EXTICR3)",
                                    .name = "exticr3",
                                    .offset_bytes = 0x10,
                                    .reset_value = 0x00000000,
                                    .access_flags =
                                    PERIPHERAL_REGISTER_32BITS_ALL,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .desc =
                                                                    "EXTI 8 configuration",
                                                            .name = "exti8",
                                                            .first_bit = 0,
                                                            .width_bits = 4,
                                                        /**/
                                                        },
                                                        {
                                                            .desc =
                                                                    "EXTI 9 configuration",
                                                            .name = "exti9",
                                                            .first_bit = 4,
                                                            .width_bits = 4,
                                                        /**/
                                                        },
                                                        {
                                                            .desc =
                                                                    "EXTI 10 configuration",
                                                            .name = "exti10",
                                                            .first_bit = 8,
                                                            .width_bits = 4,
                                                        /**/
                                                        },
                                                        {
                                                            .desc =
                                                                    "EXTI 11 configuration",
                                                            .name = "exti11",
                                                            .first_bit = 12,
                                                            .width_bits = 4,
                                                        /**/
                                                        },
                                                        { } /**/
                                                    } ,
                                /**/
                                },
                                {
                                    .desc =
                                            "External interrupt configuration register 4 (SYSCFG_EXTICR1)",
                                    .name = "exticr4",
                                    .offset_bytes = 0x14,
                                    .reset_value = 0x00000000,
                                    .access_flags =
                                    PERIPHERAL_REGISTER_32BITS_ALL,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .desc =
                                                                    "EXTI 12 configuration",
                                                            .name = "exti12",
                                                            .first_bit = 0,
                                                            .width_bits = 4,
                                                        /**/
                                                        },
                                                        {
                                                            .desc =
                                                                    "EXTI 13 configuration",
                                                            .name = "exti13",
                                                            .first_bit = 4,
                                                            .width_bits = 4,
                                                        /**/
                                                        },
                                                        {
                                                            .desc =
                                                                    "EXTI 14 configuration",
                                                            .name = "exti14",
                                                            .first_bit = 8,
                                                            .width_bits = 4,
                                                        /**/
                                                        },
                                                        {
                                                            .desc =
                                                                    "EXTI 15 configuration",
                                                            .name = "exti15",
                                                            .first_bit = 12,
                                                            .width_bits = 4,
                                                        /**/
                                                        },
                                                        { } /**/
                                                    } ,
                                /**/
                                },
                                {
                                    .desc =
                                            "Compensation cell control register (SYSCFG_CMPCR)",
                                    .name = "cmpcr",
                                    .offset_bytes = 0x20,
                                    .reset_value = 0x00000000,
                                    .access_flags =
                                    PERIPHERAL_REGISTER_32BITS_ALL,
                                    .bitfields =
                                            (RegisterBitfieldInfo[] ) {
                                                        {
                                                            .desc =
                                                                    "Compensation cell power-down",
                                                            .name = "cmp-pd",
                                                            .first_bit = 0,
                                                            .width_bits = 1,
                                                        /**/
                                                        },
                                                        {
                                                            .desc =
                                                                    "Compensation cell ready flag",
                                                            .name = "ready",
                                                            .first_bit = 8,
                                                            .width_bits = 1,
                                                            .rw_mode =
                                                                    REGISTER_RW_MODE_READ,
                                                        /**/
                                                        },
                                                        { } /**/
                                                    } ,
                                /**/
                                },
                                { }, /**/
                            } , /**/
        };

/* ------------------------------------------------------------------------- */

static void stm32_syscfg_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    // STM32SYSCFGState *state = STM32_SYSCFG_STATE(obj);

    /* capabilities are not yet available. */

    /* No interrupts for now, maybe add boot mode bits. */
}

static void stm32_syscfg_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /*
     * Parent realize() is called after setting properties and creating
     * registers.
     */

    STM32MCUState *mcu = stm32_mcu_get();

    STM32SYSCFGState *state = STM32_SYSCFG_STATE(dev);
    /* First thing first: get capabilities from MCU, needed everywhere. */
    state->capabilities = mcu->capabilities;

    /* Also keep a local pointer, to access them easier. */
    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    uint32_t size;
    hwaddr addr;
    switch (capabilities->family) {
    case STM32_FAMILY_F4:
        addr = 0x40013800;
        size = 0x400;
        break;

    default:
        /*
         * This will trigger an assertion to fail when creating the
         * memory region in the parent class.
         */
        size = 0;
        addr = 0;
        break;
    }

    cm_object_property_set_int(obj, addr, "mmio-address");
    cm_object_property_set_int(obj, size, "mmio-size-bytes");

    peripheral_add_properties_and_children(obj, &stm32f4xxxx_syscfg_info);

    state->reg.memrmp = cm_object_get_child_by_name(obj, "memrmp");
    state->memrmp.mem_mode = cm_object_get_child_by_name(state->reg.memrmp,
            "mem-mode");

    state->reg.pmc = cm_object_get_child_by_name(obj, "pmc");
    state->reg.exticr1 = cm_object_get_child_by_name(obj, "exticr1");
    state->reg.exticr2 = cm_object_get_child_by_name(obj, "exticr2");
    state->reg.exticr3 = cm_object_get_child_by_name(obj, "exticr3");
    state->reg.exticr4 = cm_object_get_child_by_name(obj, "exticr4");

    state->exticr.exti[0] = cm_object_get_child_by_name(state->reg.exticr1,
            "exti0");
    state->exticr.exti[1] = cm_object_get_child_by_name(state->reg.exticr1,
            "exti1");
    state->exticr.exti[2] = cm_object_get_child_by_name(state->reg.exticr1,
            "exti2");
    state->exticr.exti[3] = cm_object_get_child_by_name(state->reg.exticr1,
            "exti3");

    state->exticr.exti[4] = cm_object_get_child_by_name(state->reg.exticr2,
            "exti4");
    state->exticr.exti[5] = cm_object_get_child_by_name(state->reg.exticr2,
            "exti5");
    state->exticr.exti[6] = cm_object_get_child_by_name(state->reg.exticr2,
            "exti6");
    state->exticr.exti[7] = cm_object_get_child_by_name(state->reg.exticr2,
            "exti7");

    state->exticr.exti[8] = cm_object_get_child_by_name(state->reg.exticr3,
            "exti8");
    state->exticr.exti[9] = cm_object_get_child_by_name(state->reg.exticr3,
            "exti9");
    state->exticr.exti[10] = cm_object_get_child_by_name(state->reg.exticr3,
            "exti10");
    state->exticr.exti[11] = cm_object_get_child_by_name(state->reg.exticr3,
            "exti11");

    state->exticr.exti[12] = cm_object_get_child_by_name(state->reg.exticr4,
            "exti12");
    state->exticr.exti[13] = cm_object_get_child_by_name(state->reg.exticr4,
            "exti13");
    state->exticr.exti[14] = cm_object_get_child_by_name(state->reg.exticr4,
            "exti14");
    state->exticr.exti[15] = cm_object_get_child_by_name(state->reg.exticr4,
            "exti15");

    state->reg.cmpcr = cm_object_get_child_by_name(obj, "cmpcr");
    state->cmpcr.cmp_pd = cm_object_get_child_by_name(state->reg.cmpcr,
            "cmp-pd");
    state->cmpcr.ready = cm_object_get_child_by_name(state->reg.cmpcr, "ready");

    cm_object_property_set_str(state->cmpcr.ready, "cmp-pd", "follows");

    cm_object_property_set_str(obj, "syscfg", "name");

    /* Call parent realize(). */
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_SYSCFG)) {
        return;
    }
}

static void stm32_syscfg_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    /* Call parent reset(). */
    cm_device_parent_reset(dev, TYPE_STM32_SYSCFG);
}

static void stm32_syscfg_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = stm32_syscfg_reset_callback;
    dc->realize = stm32_syscfg_realize_callback;
}

static const TypeInfo stm32_syscfg_type_info = {
    .name = TYPE_STM32_SYSCFG,
    .parent = TYPE_STM32_SYSCFG_PARENT,
    .instance_init = stm32_syscfg_instance_init_callback,
    .instance_size = sizeof(STM32SYSCFGState),
    .class_init = stm32_syscfg_class_init_callback,
    .class_size = sizeof(STM32SYSCFGClass) };

static void stm32_syscfg_register_types(void)
{
    type_register_static(&stm32_syscfg_type_info);
}

type_init(stm32_syscfg_register_types);

/* ------------------------------------------------------------------------- */

