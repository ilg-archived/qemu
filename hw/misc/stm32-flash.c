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
 * All STM32 reference manuals available from:
 * http://www.st.com/stonline/stappl/resourceSelector/\
 * app?page=fullResourceSelector&doctype=reference_manual&FamilyID=141
 */

/* ------------------------------------------------------------------------- */

static RegisterInfo stm32f1_regs[] = {
    {
        .name = "acr",
        .desc = "Flash access control register (FLASH_ACR)",
        .offset = 0x00,
        .reset_value = 0x00000030,
        .readable_bits = 0x0000003F,
        .writable_bits = 0x0000001F,
        .auto_bits = (RegisterAutoBits[] ) {
                    {
                        0x00000010, /* reflect PRFTBE -> PRFTBS */
                        1 },
                    { } /**/
                } /**/
                },
#if 0
    /* TODO: implement */
    {
        .name = "keyr",
        .offset = 0x04,},
    {
        .name = "optkeyr",
        .offset = 0x08,},
    {
        .name = "sr",
        .offset = 0x0C,},
    {
        .name = "cr",
        .offset = 0x10,},
    {
        .name = "ar",
        .offset = 0x14,},
    /* 0x18 is reserved */
    {
        .name = "obr",
        .offset = 0x1C,},
    {
        .name = "wrpr",
        .offset = 0x20,},
#endif
    { } };

/* In addition to the above, the XL density has a few more registers. */
static RegisterInfo stm32f1xd_extra_regs[] = {
#if 0
    /* TODO: implement */
    {
        .name = "keyr2",
        .offset = 0x44,},
    {
        .name = "sr2",
        .offset = 0x4C,},
    {
        .name = "cr2",
        .offset = 0x50,},
    {
        .name = "ar2",
        .offset = 0x54,},
#endif
    { } };

static void stm32_flash_instance_init_callback(Object *obj)
{
    qemu_log_function_name();
}

static void stm32_flash_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    /*
     * Parent realize() is called after setting properties
     * and adding registers.
     */
    STM32FlashState *state = STM32_FLASH_STATE(dev);

    Object *obj = OBJECT(dev);

    const STM32Capabilities *capabilities = state->capabilities;
    assert(capabilities != NULL);

    uint64_t size;
    hwaddr addr;

    switch (capabilities->family) {
    case STM32_FAMILY_F1:
        addr = 0x40022000;
        size = 0x400;

        peripheral32_add_registers(dev, stm32f1_regs);
        if (capabilities->f1.is_xd) {
            peripheral32_add_registers(dev, stm32f1xd_extra_regs);
        }
        break;

    default:
        /*
         * This will trigger an assertion to fail when creating the
         * memory region in the parent class.
         */
        addr = 0;
        size = 0;
    }

    object_property_set_str(obj, TYPE_STM32_FLASH, "mmio-name", NULL);
    object_property_set_int(obj, addr, "mmio-address", NULL);
    object_property_set_int(obj, size, "mmio-size", NULL);

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
