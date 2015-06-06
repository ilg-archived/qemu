/*
 * STM32 MCU - RCC (Reset and Clock Control).
 *
 * Copyright (c) 2015 Liviu Ionescu
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

#include "hw/misc/stm32_rcc.h"

/**
 * This file implements the STM32 RCC (Reset and Clock Control).
 *
 * The initial implementation is intended only to pass CMSIS initialisations.
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

/* STM32F1[LMHX]D */

#define STM32F1_RCC_CR_READ_MASK            (0x030FFFFB)
#define STM32F1_RCC_CR_WRITE_MASK           (0x010D00F9)
#define STM32F1_RCC_CFGR_READ_MASK          (0x077FFFFF)
#define STM32F1_RCC_CFGR_WRITE_MASK         (0x077FFFF3)
#define STM32F1_RCC_CIR_READ_MASK           (0x00001F9F)
#define STM32F1_RCC_CIR_WRITE_MASK          (0x00001F00)
#define STM32F1_RCC_APB2RSTR_READ_MASK      (0x0038FFFD)
#define STM32F1_RCC_APB2RSTR_WRITE_MASK     (0x0038FFFD)
#define STM32F1_RCC_APB1RSTR_READ_MASK      (0x3AFEC9FF)
#define STM32F1_RCC_APB1RSTR_WRITE_MASK     (0x3AFEC9FF)
#define STM32F1_RCC_AHBENR_READ_MASK        (0x00000557)
#define STM32F1_RCC_AHBENR_WRITE_MASK       (0x00000557)
#define STM32F1_RCC_AHB2ENR_READ_MASK       (0x0038FFFD)
#define STM32F1_RCC_AHB2ENR_WRITE_MASK      (0x0038FFFD)
#define STM32F1_RCC_AHB1ENR_READ_MASK       (0x3AFEC9FF)
#define STM32F1_RCC_AHB1ENR_WRITE_MASK      (0x3AFEC9FF)
#define STM32F1_RCC_BDCR_READ_MASK          (0x00018307)
#define STM32F1_RCC_BDCR_WRITE_MASK         (0x00018305)
#define STM32F1_RCC_CSR_READ_MASK           (0xFD000003)
#define STM32F1_RCC_CSR_WRITE_MASK          (0xFD000001)

/**
 * STM32F1 Low-, medium-, high- and XL-density reset and clock control (RCC)
 * read 32-bits.
 */
static uint32_t stm32f1_rcc_read32(STM32RCCState *state, uint32_t offset,
        unsigned size)
{
    uint32_t value;

    switch (offset) {
    case 0x00:
        value = (state->u.f1.reg.cr & STM32F1_RCC_CR_READ_MASK);
        value &= ~0x02020002; /* Clear ready bits */
        /* All enabled oscs are ready */
        value |= ((state->u.f1.reg.cr & 0x01010001) << 1);
        return value;
    case 0x04:
        value = (state->u.f1.reg.cfgr & STM32F1_RCC_CFGR_READ_MASK);
        value &= ~0x0000000C; /* Clear SWS bits */
        /* Copy SWS from SW */
        value |= ((state->u.f1.reg.cfgr & 0x00000003) << 2);
        return value;
    case 0x08:
        return (state->u.f1.reg.cir & STM32F1_RCC_CIR_READ_MASK);
    case 0x0C:
        return (state->u.f1.reg.apb2rstr & STM32F1_RCC_APB2RSTR_READ_MASK);
    case 0x10:
        return (state->u.f1.reg.apb1rstr & STM32F1_RCC_APB1RSTR_READ_MASK);
    case 0x14:
        return (state->u.f1.reg.ahbenr & STM32F1_RCC_AHBENR_READ_MASK);
    case 0x18:
        return (state->u.f1.reg.apb2enr & STM32F1_RCC_AHB2ENR_READ_MASK);
    case 0x1C:
        return (state->u.f1.reg.apb1enr & STM32F1_RCC_AHB1ENR_READ_MASK);
    case 0x20:
        return (state->u.f1.reg.bdcr & STM32F1_RCC_BDCR_READ_MASK);
    case 0x24:
        value = (state->u.f1.reg.csr & STM32F1_RCC_CSR_READ_MASK);
        value &= ~0x00000002; /* Clear ready bits */
        /* All enabled oscs are ready */
        value |= ((state->u.f1.reg.csr & 0x00000001) << 1);
        return value;

    default:
        qemu_log_mask(LOG_UNIMP,
                "RCC: Read of size %d at offset 0x%x not implemented\n", size,
                offset);
        break;
    }

    return 0;
}

/**
 * STM32F1 - Low-, medium-, high- and XL-density reset and clock control (RCC)
 * write 32-bits.
 */
static void stm32f1_rcc_write32(STM32RCCState *state, uint32_t offset,
        uint32_t value, unsigned size)
{
    uint32_t tmp;

    switch (offset) {
    case 0x00:
        state->u.f1.reg.cr = (value & STM32F1_RCC_CR_WRITE_MASK);
        break;
    case 0x04:
        state->u.f1.reg.cfgr = (value & STM32F1_RCC_CFGR_WRITE_MASK);
        break;
    case 0x08:
        /* Preserve old value */
        tmp = state->u.f1.reg.cir & ~STM32F1_RCC_CIR_WRITE_MASK;
        tmp |= (value & STM32F1_RCC_CIR_WRITE_MASK);
        /* Clear flags */
        tmp &= ~((value >> 16) & 0x9F);
        state->u.f1.reg.cir = tmp;
        break;
    case 0x0C:
        state->u.f1.reg.apb2rstr = (value & STM32F1_RCC_APB2RSTR_WRITE_MASK);
        break;
    case 0x10:
        state->u.f1.reg.apb1rstr = (value & STM32F1_RCC_APB1RSTR_WRITE_MASK);
        break;
    case 0x14:
        state->u.f1.reg.ahbenr = (value & STM32F1_RCC_AHBENR_WRITE_MASK);
        break;
    case 0x18:
        state->u.f1.reg.apb2enr = (value & STM32F1_RCC_AHB2ENR_WRITE_MASK);
        break;
    case 0x1C:
        state->u.f1.reg.apb1enr = (value & STM32F1_RCC_AHB1ENR_WRITE_MASK);
        break;
    case 0x20:
        state->u.f1.reg.bdcr = (value & STM32F1_RCC_BDCR_WRITE_MASK);
        break;
    case 0x24:
        state->u.f1.reg.csr = (value & STM32F1_RCC_CSR_WRITE_MASK);
        break;

    default:
        qemu_log_mask(LOG_UNIMP,
                "RCC: Write of size %d at offset 0x%x not implemented\n", size,
                offset);
    }
}

/* ------------------------------------------------------------------------- */

/* STM32F1CL */

#define STM32F1CL_RCC_CR_READ_MASK          (0x3F0FFFFB)
#define STM32F1CL_RCC_CR_WRITE_MASK         (0x150D00F9)
#define STM32F1CL_RCC_CFGR_READ_MASK        (0x0F7FFFFF)
#define STM32F1CL_RCC_CFGR_WRITE_MASK       (0x0F7FFFF3)
#define STM32F1CL_RCC_CIR_READ_MASK         (0x00007FFF)
#define STM32F1CL_RCC_CIR_WRITE_MASK        (0x00FF7F00)
#define STM32F1CL_RCC_APB2RSTR_READ_MASK    (0x00005E7D)
#define STM32F1CL_RCC_APB2RSTR_WRITE_MASK   (0x00005E7D)
#define STM32F1CL_RCC_APB1RSTR_READ_MASK    (0x3E7EC83F)
#define STM32F1CL_RCC_APB1RSTR_WRITE_MASK   (0x3E7EC83F)
#define STM32F1CL_RCC_AHBENR_READ_MASK      (0x0001D057)
#define STM32F1CL_RCC_AHBENR_WRITE_MASK     (0x0001D057)
#define STM32F1CL_RCC_AHB2ENR_READ_MASK     (0x00005E7D)
#define STM32F1CL_RCC_AHB2ENR_WRITE_MASK    (0x00005E7D)
#define STM32F1CL_RCC_AHB1ENR_READ_MASK     (0x3E7EE87F)
#define STM32F1CL_RCC_AHB1ENR_WRITE_MASK    (0x3E7EE87F)
#define STM32F1CL_RCC_BDCR_READ_MASK        (0x00018307)
#define STM32F1CL_RCC_BDCR_WRITE_MASK       (0x00018305)
#define STM32F1CL_RCC_CSR_READ_MASK         (0xFD000003)
#define STM32F1CL_RCC_CSR_WRITE_MASK        (0xFD000001)
#define STM32F1CL_RCC_AHBRSTR_READ_MASK     (0x00007000)
#define STM32F1CL_RCC_AHBRSTR_WRITE_MASK    (0x00007000)
#define STM32F1CL_RCC_CFGR2_READ_MASK       (0x0007FFFF)
#define STM32F1CL_RCC_CFGR2_WRITE_MASK      (0x0007FFFF)

/**
 * STM32F1CL - Connectivity line devices: reset and clock control (RCC)
 * read 32-bits.
 */
static uint32_t stm32f1cl_rcc_read32(STM32RCCState *state, uint32_t offset,
        unsigned size)
{
    uint32_t value;

    switch (offset) {
    case 0x00:
        value = (state->u.f1.reg.cr & STM32F1CL_RCC_CR_READ_MASK);
        value &= ~0x2A020002; /* Clear ready bits */
        /* All enabled oscs are ready */
        value |= ((state->u.f1.reg.cr & 0x18010001) << 1);
        return value;
    case 0x04:
        value = (state->u.f1.reg.cfgr & STM32F1CL_RCC_CFGR_READ_MASK);
        value &= ~0x0000000C; /* Clear SWS bits */
        /* Copy SWS from SW */
        value |= ((state->u.f1.reg.cfgr & 0x00000003) << 2);
        return value;
    case 0x08:
        return (state->u.f1.reg.cir & STM32F1CL_RCC_CIR_READ_MASK);
    case 0x0C:
        return (state->u.f1.reg.apb2rstr & STM32F1CL_RCC_APB2RSTR_READ_MASK);
    case 0x10:
        return (state->u.f1.reg.apb1rstr & STM32F1CL_RCC_APB1RSTR_READ_MASK);
    case 0x14:
        return (state->u.f1.reg.ahbenr & STM32F1CL_RCC_AHBENR_READ_MASK);
    case 0x18:
        return (state->u.f1.reg.apb2enr & STM32F1CL_RCC_AHB2ENR_READ_MASK);
    case 0x1C:
        return (state->u.f1.reg.apb1enr & STM32F1CL_RCC_AHB1ENR_READ_MASK);
    case 0x20:
        return (state->u.f1.reg.bdcr & STM32F1CL_RCC_BDCR_READ_MASK);
    case 0x24:
        value = (state->u.f1.reg.csr & STM32F1CL_RCC_CSR_READ_MASK);
        value &= ~0x00000002; /* Clear LSIRDY */
        /* LSRDY follows LSION */
        value |= ((state->u.f1.reg.csr & 0x00000001) << 1);
        return value;
    case 0x28:
        return (state->u.f1.reg.ahbrstr & STM32F1CL_RCC_AHBRSTR_READ_MASK);
    case 0x2C:
        return (state->u.f1.reg.cfgr2 & STM32F1CL_RCC_CFGR2_READ_MASK);

    default:
        qemu_log_mask(LOG_UNIMP,
                "RCC: Read of size %d at offset 0x%x not implemented\n", size,
                offset);
        break;
    }

    return 0;
}

/**
 * STM32F1CL - Connectivity line devices: reset and clock control (RCC)
 * write 32-bits.
 */
static void stm32f1cl_rcc_write32(STM32RCCState *state, uint32_t offset,
        uint32_t value, unsigned size)
{
    uint32_t tmp;

    switch (offset) {
    case 0x00:
        state->u.f1.reg.cr = (value & STM32F1CL_RCC_CR_WRITE_MASK);
        break;
    case 0x04:
        state->u.f1.reg.cfgr = (value & STM32F1CL_RCC_CFGR_WRITE_MASK);
        break;
    case 0x08:
        /* Preserve old value */
        tmp = state->u.f1.reg.cir & ~STM32F1CL_RCC_CIR_WRITE_MASK;
        tmp |= (value & STM32F1CL_RCC_CIR_WRITE_MASK);
        /* Clear flags */
        tmp &= ~((value >> 16) & 0xFF);
        state->u.f1.reg.cir = tmp;
        break;
    case 0x0C:
        state->u.f1.reg.apb2rstr = (value & STM32F1CL_RCC_APB2RSTR_WRITE_MASK);
        break;
    case 0x10:
        state->u.f1.reg.apb1rstr = (value & STM32F1CL_RCC_APB1RSTR_WRITE_MASK);
        break;
    case 0x14:
        state->u.f1.reg.ahbenr = (value & STM32F1CL_RCC_AHBENR_WRITE_MASK);
        break;
    case 0x18:
        state->u.f1.reg.apb2enr = (value & STM32F1CL_RCC_AHB2ENR_WRITE_MASK);
        break;
    case 0x1C:
        state->u.f1.reg.apb1enr = (value & STM32F1CL_RCC_AHB1ENR_WRITE_MASK);
        break;
    case 0x20:
        state->u.f1.reg.bdcr = (value & STM32F1CL_RCC_BDCR_WRITE_MASK);
        break;
    case 0x24:
        state->u.f1.reg.csr = (value & STM32F1CL_RCC_CSR_WRITE_MASK);
        break;
    case 0x28:
        state->u.f1.reg.ahbrstr = (value & STM32F1CL_RCC_AHBRSTR_WRITE_MASK);
        break;
    case 0x2C:
        state->u.f1.reg.cfgr2 = (value & STM32F1CL_RCC_CFGR2_WRITE_MASK);
        break;

    default:
        qemu_log_mask(LOG_UNIMP,
                "RCC: Write of size %d at offset 0x%x not implemented\n", size,
                offset);
    }
}

/* ------------------------------------------------------------------------- */

static uint64_t stm32_rcc_read(void *opaque, hwaddr addr, unsigned size)
{
    STM32RCCState *state = (STM32RCCState *) opaque;
    uint32_t offset = addr;

    if (size != 4) {
        qemu_log_mask(LOG_UNIMP,
                "RCC: Read of size %d at offset 0x%x not implemented\n", size,
                offset);
        return 0;
    }

    STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;

    switch (capabilities->stm32.family) {
    case STM32_FAMILY_F1:
        if (capabilities->stm32.f1.is_cl) {
            return stm32f1cl_rcc_read32(state, offset, size);
        } else {
            return stm32f1_rcc_read32(state, offset, size);
        }
        break;

    default:
        qemu_log_mask(LOG_GUEST_ERROR,
                "RCC: Read of size %d at offset 0x%x for unknown family %d\n",
                size, offset, capabilities->stm32.family);
    }

    return 0;
}

static void stm32_rcc_write(void *opaque, hwaddr addr, uint64_t value,
        unsigned size)
{
    STM32RCCState *state = (STM32RCCState *) opaque;
    uint32_t offset = addr;

    if (size != 4) {
        qemu_log_mask(LOG_UNIMP,
                "RCC: Write of size %d at offset 0x%x not implemented\n", size,
                offset);
        return;
    }

    STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;

    switch (capabilities->stm32.family) {
    case STM32_FAMILY_F1:
        if (capabilities->stm32.f1.is_cl) {
            stm32f1cl_rcc_write32(state, offset, value, size);
        } else {
            stm32f1_rcc_write32(state, offset, value, size);
        }
        break;

    default:
        qemu_log_mask(LOG_GUEST_ERROR,
                "RCC: Write of size %d at offset 0x%x for unknown family %d\n",
                size, offset, capabilities->stm32.family);
    }
}

static const MemoryRegionOps stm32_rcc_ops = {
    .read = stm32_rcc_read,
    .write = stm32_rcc_write,
    .endianness = DEVICE_NATIVE_ENDIAN, };

/* ------------------------------------------------------------------------- */

static void stm32_rcc_reset(DeviceState *dev)
{
    qemu_log_function_name();

    STM32RCCState *state = STM32_RCC_STATE(dev);

    STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;

    switch (capabilities->stm32.family) {
    case STM32_FAMILY_F1:

        state->u.f1.reg.cr = 0x00000083;
        state->u.f1.reg.cfgr = 0x00000000;
        state->u.f1.reg.cir = 0x00000000;
        state->u.f1.reg.apb2rstr = 0x00000000;
        state->u.f1.reg.apb1rstr = 0x00000000;
        state->u.f1.reg.ahbenr = 0x00000014;
        state->u.f1.reg.apb2enr = 0x00000000;
        state->u.f1.reg.apb1enr = 0x00000000;
        state->u.f1.reg.bdcr = 0x00000000;
        state->u.f1.reg.csr = 0x0C000000;
        if (capabilities->stm32.f1.is_cl) {
            state->u.f1.reg.ahbrstr = 0x00000000;
            state->u.f1.reg.cfgr2 = 0x00000000;
        }

        break;
    default:
        break;
    }
}

static void stm32_rcc_realize(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32RCCState *state = STM32_RCC_STATE(dev);

    STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;
    assert(capabilities != NULL);

    uint64_t size;
    switch (capabilities->stm32.family) {
    case STM32_FAMILY_F1:
        if (capabilities->stm32.f1.is_cl) {
            size = 0x30;
        } else {
            size = 0x28;
        }
        break;
    default:
        size = 0; /* This will trigger an assertion to fail */
    }

    memory_region_init_io(&state->mmio, OBJECT(dev), &stm32_rcc_ops, state,
            TYPE_STM32_RCC, size);

    sysbus_init_mmio(SYS_BUS_DEVICE(dev), &state->mmio);
    sysbus_mmio_map(SYS_BUS_DEVICE(dev), 0, 0x40021000);
}

static void stm32_rcc_instance_init(Object *obj)
{
    qemu_log_function_name();

    STM32RCCState *state = STM32_RCC_STATE(obj);

    /* Not yet used */
    state->osc_freq = HSI_FREQ_HZ;
    state->rtc_freq = LSI_FREQ_HZ;
}

static void stm32_rcc_class_init(ObjectClass *klass, void *data)
{
    STM32RCCClass *nc = STM32_RCC_CLASS(klass);
    DeviceClass *dc = DEVICE_CLASS(klass);

    nc->parent_realize = dc->realize;

    dc->reset = stm32_rcc_reset;
    dc->realize = stm32_rcc_realize;
}

static const TypeInfo stm32_rcc_type_info = {
    .name = TYPE_STM32_RCC,
    .parent = TYPE_STM32_SYS_BUS_DEVICE,
    .instance_init = stm32_rcc_instance_init,
    .instance_size = sizeof(STM32RCCState),
    .class_init = stm32_rcc_class_init };

static void stm32_rcc_register_types(void)
{
    type_register_static(&stm32_rcc_type_info);
}

#if defined(CONFIG_GNU_ARM_ECLIPSE)
type_init(stm32_rcc_register_types)
#endif

/* ------------------------------------------------------------------------- */
