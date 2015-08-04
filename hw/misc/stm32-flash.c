/*
 * STM32 MCU - flash control.
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

#include "hw/misc/stm32-flash.h"
#include "hw/arm/cortexm-helper.h"

/**
 * This file implements the STM32 flash control.
 *
 * The initial implementation is intended only to pass CMSIS initialisations.
 * The written values can be read back, but no other actions are supported.
 *
 * References:
 * - ST CD00171190.pdf, Doc ID 13902 Rev 15, "RM0008 Reference Manual,
 * STM32F101xx, STM32F102xx, STM32F103xx, STM32F105xx and STM32F107xx
 * advanced ARM®-based 32-bit MCUs"
 *
 * - Doc ID 018909 Rev 6, "ST RM0090 Reference manual,
 * STM32F405xx/07xx, STM32F415xx/17xx, STM32F42xxx and STM32F43xxx
 * advanced ARM-based 32-bit MCUs"
 *
 * - Doc ID 026448 Rev 1, "ST RM0383 Reference manual,
 * STM32F411xC/E advanced ARM-based 32-bit MCUs"
 *
 * All STM32 reference manuals available from:
 * http://www.st.com/stonline/stappl/resourceSelector/\
 * app?page=fullResourceSelector&doctype=reference_manual&FamilyID=141
 */

/* ------------------------------------------------------------------------- */

static PeripheralInfo stm32f1_flash_info = {
    .desc = "Reset and clock control (RCC)",

    .registers = (PeripheralRegisterInfo[] ) {
                {
                    .desc = "Flash access control register (FLASH_ACR)",
                    .name = "acr",
                    .offset_bytes = 0x00,
                    .reset_value = 0x00000030,
                    .bitfields = (RegisterBitfieldInfo[] ) {
                                {
                                    .name = "latency",
                                    .first_bit = 0,
                                    .width_bits = 3, },
                                {
                                    .name = "hlfcya",
                                    .desc = "Flash half cycle access enable",
                                    .first_bit = 3, },
                                {
                                    .name = "prftbe",
                                    .desc = "Prefetch buffer enable",
                                    .first_bit = 4, },
                                {
                                    .name = "prftbs",
                                    .desc = "Prefetch buffer status",
                                    .first_bit = 5,
                                    .rw_mode = REGISTER_RW_MODE_READ, },
                                { }, /**/
                            } , /**/
                },
                /* Very schematic, functional read after write only. */
                {
                    .name = "keyr",
                    .offset_bytes = 0x04, },
                {
                    .name = "optkeyr",
                    .offset_bytes = 0x08, },
                {
                    .name = "sr",
                    .offset_bytes = 0x0C, },
                {
                    .name = "cr",
                    .offset_bytes = 0x10, },
                {
                    .name = "ar",
                    .offset_bytes = 0x14, },
                /* 0x18 is reserved */
                {
                    .name = "obr",
                    .offset_bytes = 0x1C, },
                {
                    .name = "wrpr",
                    .offset_bytes = 0x20, },
                { }, /**/
            } , /**/
};

static void stm32f1_flash_create_objects(Object *obj)
{
    STM32FlashState *state = STM32_FLASH_STATE(obj);

    peripheral_new_with_info(obj, NULL, &stm32f1_flash_info);

    state->f1.reg.acr = cm_object_get_child_by_name(obj, "acr");
    state->f1.reg.keyr = cm_object_get_child_by_name(obj, "keyr");
    state->f1.reg.optkeyr = cm_object_get_child_by_name(obj, "optkeyr");
    state->f1.reg.sr = cm_object_get_child_by_name(obj, "sr");
    state->f1.reg.cr = cm_object_get_child_by_name(obj, "cr");
    state->f1.reg.ar = cm_object_get_child_by_name(obj, "ar");
    state->f1.reg.obr = cm_object_get_child_by_name(obj, "obr");
    state->f1.reg.wrpr = cm_object_get_child_by_name(obj, "wrpr");

    /* ACR bitfields. */
    state->f1.acr.prftbs = cm_object_get_child_by_name(
            OBJECT(state->f1.reg.acr), "prftbs");
}

static PeripheralInfo stm32f1xd_flash_info = {
    .desc = "Reset and clock control (RCC)",

    .registers = (PeripheralRegisterInfo[] ) {
                {
                    .desc = "Flash access control register (FLASH_ACR)",
                    .name = "acr",
                    .offset_bytes = 0x00,
                    .reset_value = 0x00000030,
                    .bitfields = (RegisterBitfieldInfo[] ) {
                                {
                                    .name = "latency",
                                    .first_bit = 0,
                                    .width_bits = 3, },
                                {
                                    .name = "hlfcya",
                                    .desc = "Flash half cycle access enable",
                                    .first_bit = 3, },
                                {
                                    .name = "prftbe",
                                    .desc = "Prefetch buffer enable",
                                    .first_bit = 4, },
                                {
                                    .name = "prftbs",
                                    .desc = "Prefetch buffer status",
                                    .first_bit = 5,
                                    .rw_mode = REGISTER_RW_MODE_READ, },
                                { }, /**/
                            } , /**/
                },
                /* Very schematic, functional read after write only. */
                {
                    .name = "keyr",
                    .offset_bytes = 0x04, },
                {
                    .name = "optkeyr",
                    .offset_bytes = 0x08, },
                {
                    .name = "sr",
                    .offset_bytes = 0x0C, },
                {
                    .name = "cr",
                    .offset_bytes = 0x10, },
                {
                    .name = "ar",
                    .offset_bytes = 0x14, },
                /* 0x18 is reserved */
                {
                    .name = "obr",
                    .offset_bytes = 0x1C, },
                {
                    .name = "wrpr",
                    .offset_bytes = 0x20, },

                /*
                 * XL density devices specific.
                 */
                {
                    .name = "keyr2",
                    .offset_bytes = 0x44, },
                {
                    .name = "sr2",
                    .offset_bytes = 0x4C, },
                {
                    .name = "cr2",
                    .offset_bytes = 0x50, },
                {
                    .name = "ar2",
                    .offset_bytes = 0x54, },

                { }, /**/
            } , /**/
};

static void stm32f1xd_flash_create_objects(Object *obj)
{
    STM32FlashState *state = STM32_FLASH_STATE(obj);

    peripheral_new_with_info(obj, NULL, &stm32f1xd_flash_info);

    state->f1.reg.acr = cm_object_get_child_by_name(obj, "acr");
    state->f1.reg.keyr = cm_object_get_child_by_name(obj, "keyr");
    state->f1.reg.optkeyr = cm_object_get_child_by_name(obj, "optkeyr");
    state->f1.reg.sr = cm_object_get_child_by_name(obj, "sr");
    state->f1.reg.cr = cm_object_get_child_by_name(obj, "cr");
    state->f1.reg.ar = cm_object_get_child_by_name(obj, "ar");
    state->f1.reg.obr = cm_object_get_child_by_name(obj, "obr");
    state->f1.reg.wrpr = cm_object_get_child_by_name(obj, "wrpr");

    state->f1.reg.keyr2 = cm_object_get_child_by_name(obj, "keyr2");
    state->f1.reg.sr2 = cm_object_get_child_by_name(obj, "sr2");
    state->f1.reg.cr2 = cm_object_get_child_by_name(obj, "cr2");
    state->f1.reg.ar2 = cm_object_get_child_by_name(obj, "ar2");

    /* ACR bitfields. */
    state->f1.acr.prftbs = cm_object_get_child_by_name(
            OBJECT(state->f1.reg.acr), "prftbs");
}

static PeripheralInfo stm32f4_01_57_xx_flash_info = {
    .desc = "Reset and clock control (RCC)",

    .registers = (PeripheralRegisterInfo[] ) {
                {
                    .desc = "Flash access control register (FLASH_ACR)",
                    .name = "acr",
                    .offset_bytes = 0x00,
                    .reset_value = 0x00000030,
                    .bitfields = (RegisterBitfieldInfo[] ) {
                                {
                                    .name = "latency",
                                    .first_bit = 0,
                                    .width_bits = 3, },
                                {
                                    .name = "prften",
                                    .desc = "Prefetch enable",
                                    .first_bit = 8, },
                                {
                                    .name = "icen",
                                    .desc = "Prefetch enable",
                                    .first_bit = 9, },
                                {
                                    .name = "dcen",
                                    .desc = "Data cache enable",
                                    .first_bit = 10, },
                                {
                                    .name = "icrst",
                                    .desc = "Instruction cache reset",
                                    .first_bit = 11,
                                    .rw_mode = REGISTER_RW_MODE_READ, },
                                {
                                    .name = "dcrst",
                                    .desc = "Data cache reset",
                                    .first_bit = 12, },
                                { }, /**/
                            } , /**/
                },
                /* Very schematic, functional read after write only. */
                {
                    .name = "keyr",
                    .offset_bytes = 0x04, },
                {
                    .name = "optkeyr",
                    .offset_bytes = 0x08, },
                {
                    .name = "sr",
                    .offset_bytes = 0x0C, },
                {
                    .name = "cr",
                    .offset_bytes = 0x10, },
                {
                    .name = "ar",
                    .offset_bytes = 0x14, },
                /* 0x18 is reserved */
                {
                    .name = "obr",
                    .offset_bytes = 0x1C, },
                {
                    .name = "wrpr",
                    .offset_bytes = 0x20, },

                /*
                 * XL density devices specific.
                 */
                {
                    .name = "keyr2",
                    .offset_bytes = 0x44, },
                {
                    .name = "sr2",
                    .offset_bytes = 0x4C, },
                {
                    .name = "cr2",
                    .offset_bytes = 0x50, },
                {
                    .name = "ar2",
                    .offset_bytes = 0x54, },

                { }, /**/
            } , /**/
};

static void stm32f4_01_57_xx_flash_create_objects(Object *obj)
{
    //STM32FlashState *state = STM32_FLASH_STATE(obj);

    peripheral_new_with_info(obj, NULL, &stm32f4_01_57_xx_flash_info);
}

static PeripheralInfo stm32f411xx_flash_info = {
    .desc = "Reset and clock control (RCC)",

    .registers = (PeripheralRegisterInfo[] ) {
                {
                    .desc = "Flash access control register (FLASH_ACR)",
                    .name = "acr",
                    .offset_bytes = 0x00,
                    .reset_value = 0x00000030,
                    .bitfields = (RegisterBitfieldInfo[] ) {
                                {
                                    .name = "latency",
                                    .first_bit = 0,
                                    .width_bits = 4, },
                                {
                                    .name = "prften",
                                    .desc = "Prefetch enable",
                                    .first_bit = 8, },
                                {
                                    .name = "icen",
                                    .desc = "Prefetch enable",
                                    .first_bit = 9, },
                                {
                                    .name = "dcen",
                                    .desc = "Data cache enable",
                                    .first_bit = 10, },
                                {
                                    .name = "icrst",
                                    .desc = "Instruction cache reset",
                                    .first_bit = 11,
                                    .rw_mode = REGISTER_RW_MODE_READ, },
                                {
                                    .name = "dcrst",
                                    .desc = "Data cache reset",
                                    .first_bit = 12, },
                                { }, /**/
                            } , /**/
                },
                /* Very schematic, functional read after write only. */
                {
                    .name = "keyr",
                    .offset_bytes = 0x04, },
                {
                    .name = "optkeyr",
                    .offset_bytes = 0x08, },
                {
                    .name = "sr",
                    .offset_bytes = 0x0C, },
                {
                    .name = "cr",
                    .offset_bytes = 0x10, },
                {
                    .name = "optcr",
                    .offset_bytes = 0x14, },
                { }, /**/
            } , /**/
};

static void stm32f411xx_flash_create_objects(Object *obj)
{
    //STM32FlashState *state = STM32_FLASH_STATE(obj);

    peripheral_new_with_info(obj, NULL, &stm32f411xx_flash_info);
}

static PeripheralInfo stm32f4_23_xxx_flash_info = {
    .desc = "Reset and clock control (RCC)",

    .registers = (PeripheralRegisterInfo[] ) {
                {
                    .desc = "Flash access control register (FLASH_ACR)",
                    .name = "acr",
                    .offset_bytes = 0x00,
                    .reset_value = 0x00000030,
                    .bitfields = (RegisterBitfieldInfo[] ) {
                                {
                                    .name = "latency",
                                    .first_bit = 0,
                                    .width_bits = 4, },
                                {
                                    .name = "prften",
                                    .desc = "Prefetch enable",
                                    .first_bit = 8, },
                                {
                                    .name = "icen",
                                    .desc = "Prefetch enable",
                                    .first_bit = 9, },
                                {
                                    .name = "dcen",
                                    .desc = "Data cache enable",
                                    .first_bit = 10, },
                                {
                                    .name = "icrst",
                                    .desc = "Instruction cache reset",
                                    .first_bit = 11,
                                    .rw_mode = REGISTER_RW_MODE_READ, },
                                {
                                    .name = "dcrst",
                                    .desc = "Data cache reset",
                                    .first_bit = 12, },
                                { }, /**/
                            } , /**/
                },
                /* Very schematic, functional read after write only. */
                {
                    .name = "keyr",
                    .offset_bytes = 0x04, },
                {
                    .name = "optkeyr",
                    .offset_bytes = 0x08, },
                {
                    .name = "sr",
                    .offset_bytes = 0x0C, },
                {
                    .name = "cr",
                    .offset_bytes = 0x10, },
                {
                    .name = "ar",
                    .offset_bytes = 0x14, },
                /* 0x18 is reserved */
                {
                    .name = "obr",
                    .offset_bytes = 0x1C, },
                {
                    .name = "wrpr",
                    .offset_bytes = 0x20, },

                /*
                 * XL density devices specific.
                 */
                {
                    .name = "keyr2",
                    .offset_bytes = 0x44, },
                {
                    .name = "sr2",
                    .offset_bytes = 0x4C, },
                {
                    .name = "cr2",
                    .offset_bytes = 0x50, },
                {
                    .name = "ar2",
                    .offset_bytes = 0x54, },

                { }, /**/
            } , /**/
};

static void stm32f4_23_xxx_flash_create_objects(Object *obj)
{
    //STM32FlashState *state = STM32_FLASH_STATE(obj);

    peripheral_new_with_info(obj, NULL, &stm32f4_23_xxx_flash_info);
}

/* ------------------------------------------------------------------------- */

static void stm32_flash_instance_init_callback(Object *obj)
{
    qemu_log_function_name();
}

static void stm32_flash_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /*
     * Parent realize() is called after setting properties and creating
     * registers.
     */
    STM32FlashState *state = STM32_FLASH_STATE(dev);

    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    Object *obj = OBJECT(dev);

    /* Must be defined before creating registers. */
    cm_object_property_set_int(obj, 4, "register-size-bytes");

    /* TODO: get it from MCU */
    cm_object_property_set_bool(obj, true, "is-little-endian");

    uint64_t size;
    hwaddr addr;

    switch (capabilities->family) {
    case STM32_FAMILY_F1:
        addr = 0x40022000;
        size = 0x400;
        break;

    case STM32_FAMILY_F4:
        addr = 0x40023C00;
        size = 0x400;
        break;

    default:
        /*
         * This will trigger an assertion to fail when creating the
         * memory region in the parent class.
         */
        addr = 0;
        size = 0;
    }

    cm_object_property_set_int(obj, addr, "mmio-address");
    cm_object_property_set_int(obj, size, "mmio-size-bytes");

    switch (capabilities->family) {
    case STM32_FAMILY_F1:

        if (!capabilities->f1.is_xd) {
            stm32f1_flash_create_objects(obj);

            /* Auto bits. */
            cm_object_property_set_str(state->f1.acr.prftbs, "prftbe",
                    "follows");
        } else {
            stm32f1xd_flash_create_objects(obj);

            /* Auto bits. */
            cm_object_property_set_str(state->f1.acr.prftbs, "prftbe",
                    "follows");
        }

        break;

    case STM32_FAMILY_F4:

        if (capabilities->f4.is_01_57_xx) {
            stm32f4_01_57_xx_flash_create_objects(obj);
        } else if (capabilities->f4.is11xx) {
            stm32f411xx_flash_create_objects(obj);
        } else if (capabilities->f4.is_23_xxx) {
            stm32f4_23_xxx_flash_create_objects(obj);
        }
        break;

    default:
        break;
    }

    /* Call parent realize(). */
    if (!cm_device_parent_realize(dev, errp, TYPE_STM32_FLASH)) {
        return;
    }
}

static void stm32_flash_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    /* Call parent reset(). */
    cm_device_parent_reset(dev, TYPE_STM32_FLASH);
}

static Property stm32_flash_properties[] = {
        DEFINE_PROP_NON_VOID_PTR("capabilities", STM32FlashState,
                capabilities, const STM32Capabilities *),
    DEFINE_PROP_END_OF_LIST() };

static void stm32_flash_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    dc->reset = stm32_flash_reset_callback;
    dc->realize = stm32_flash_realize_callback;
    dc->props = stm32_flash_properties;
}

static const TypeInfo stm32_flash_type_info = {
    .name = TYPE_STM32_FLASH,
    .parent = TYPE_STM32_FLASH_PARENT,
    .instance_init = stm32_flash_instance_init_callback,
    .instance_size = sizeof(STM32FlashState),
    .class_init = stm32_flash_class_init_callback,
    .class_size = sizeof(STM32FlashClass) /**/
};

static void stm32_flash_register_types(void)
{
    type_register_static(&stm32_flash_type_info);
}

type_init(stm32_flash_register_types);

/* ------------------------------------------------------------------------- */
