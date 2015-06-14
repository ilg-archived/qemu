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

#include "hw/misc/stm32-rcc.h"

/**
 * This file implements the STM32 RCC (Reset and Clock Control).
 *
 * The initial implementation is intended only to pass CMSIS initialisations.
 * This means all writes store the correct values and all reads return the
 * written values.
 * Status bits (like PLL ready) are set during the writes, so all application
 * loops waiting for those events will complete immediately.
 * Clock trees and the bits to enable peripheral clocks are not yet used by
 * the peripherals.
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

static void stm32_rcc_update_clocks(STM32RCCState *state);

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
    switch (offset) {
    case 0x00:
        return (state->u.f1.reg.cr & STM32F1_RCC_CR_READ_MASK);
    case 0x04:
        return (state->u.f1.reg.cfgr & STM32F1_RCC_CFGR_READ_MASK);
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
        return (state->u.f1.reg.csr & STM32F1_RCC_CSR_READ_MASK);

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
        tmp = (value & STM32F1_RCC_CR_WRITE_MASK);
        tmp &= ~0x02020002; /* Clear ready bits */
        /* All enabled oscs are ready */
        tmp |= ((tmp & 0x01010001) << 1);
        state->u.f1.reg.cr = tmp;
        stm32_rcc_update_clocks(state);
        break;
    case 0x04:
        tmp = (value & STM32F1_RCC_CFGR_WRITE_MASK);
        tmp &= ~0x0000000C; /* Clear SWS bits */
        /* Copy SWS from SW */
        tmp |= ((tmp & 0x00000003) << 2);
        state->u.f1.reg.cfgr = tmp;
        stm32_rcc_update_clocks(state);
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
        stm32_rcc_update_clocks(state);
        break;
    case 0x24:
        tmp = (value & STM32F1_RCC_CSR_WRITE_MASK);
        tmp &= ~0x00000002; /* Clear ready bits */
        /* All enabled oscs are ready */
        value |= ((tmp & 0x00000001) << 1);
        state->u.f1.reg.csr = tmp;
        stm32_rcc_update_clocks(state);
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
    switch (offset) {
    case 0x00:
        return (state->u.f1.reg.cr & STM32F1CL_RCC_CR_READ_MASK);
    case 0x04:
        return (state->u.f1.reg.cfgr & STM32F1CL_RCC_CFGR_READ_MASK);
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
        return (state->u.f1.reg.csr & STM32F1CL_RCC_CSR_READ_MASK);
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
        tmp = (value & STM32F1CL_RCC_CR_WRITE_MASK);
        tmp &= ~0x2A020002; /* Clear ready bits */
        /* All enabled oscs are ready */
        value |= ((tmp & 0x18010001) << 1);
        state->u.f1.reg.cr = tmp;
        break;
    case 0x04:
        tmp = (value & STM32F1CL_RCC_CFGR_WRITE_MASK);
        tmp &= ~0x0000000C; /* Clear SWS bits */
        /* Copy SWS from SW */
        value |= ((tmp & 0x00000003) << 2);
        state->u.f1.reg.cfgr = tmp;
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
        tmp = (value & STM32F1CL_RCC_CSR_WRITE_MASK);
        tmp &= ~0x00000002; /* Clear LSIRDY */
        /* LSRDY follows LSION */
        value |= ((tmp & 0x00000001) << 1);
        state->u.f1.reg.csr = tmp;
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

static uint64_t stm32_rcc_read_callback(void *opaque, hwaddr addr,
        unsigned size)
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

    switch (capabilities->family) {
    case STM32_FAMILY_F1:
        if (capabilities->f1.is_cl) {
            return stm32f1cl_rcc_read32(state, offset, size);
        } else {
            return stm32f1_rcc_read32(state, offset, size);
        }
        break;

    default:
        qemu_log_mask(LOG_GUEST_ERROR,
                "RCC: Read of size %d at offset 0x%x for unknown family %d\n",
                size, offset, capabilities->family);
    }

    return 0;
}

static void stm32_rcc_write_callback(void *opaque, hwaddr addr, uint64_t value,
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

    switch (capabilities->family) {
    case STM32_FAMILY_F1:
        if (capabilities->f1.is_cl) {
            stm32f1cl_rcc_write32(state, offset, value, size);
        } else {
            stm32f1_rcc_write32(state, offset, value, size);
        }
        break;

    default:
        qemu_log_mask(LOG_GUEST_ERROR,
                "RCC: Write of size %d at offset 0x%x for unknown family %d\n",
                size, offset, capabilities->family);
    }
}

static const MemoryRegionOps stm32_rcc_ops = {
    .read = stm32_rcc_read_callback,
    .write = stm32_rcc_write_callback,
    .endianness = DEVICE_NATIVE_ENDIAN, };

/* ------------------------------------------------------------------------- */

#define STM32F1_RCC_CFGR_SWS ((uint32_t)0x0000000C)
#define STM32F1_RCC_CFGR_PLLMULL ((uint32_t)0x003C0000)
#define STM32F1_RCC_CFGR_PLLSRC ((uint32_t)0x00010000)
#define STM32F1_RCC_CFGR_PLLXTPRE ((uint32_t)0x00020000)
#define STM32F1_RCC_CFGR_HPRE ((uint32_t)0x000000F0)

#define STM32F1_RCC_CFGR2_PREDIV1SRC ((uint32_t)0x00010000)
#define STM32F1_RCC_CFGR2_PREDIV1 ((uint32_t)0x0000000F)
#define STM32F1_RCC_CFGR2_PREDIV2 ((uint32_t)0x000000F0)
#define STM32F1_RCC_CFGR2_PLL2MUL ((uint32_t)0x00000F00)

#define RESET 0

static uint8_t AHBPrescTable[16] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    2,
    3,
    4,
    6,
    7,
    8,
    9 };

extern int system_clock_scale;

static void stm32_rcc_update_clocks(STM32RCCState *state)
{
    // qemu_log_function_name();

    STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;

    uint32_t prediv1factor = 0;
    uint32_t tmp = 0;
    uint32_t pllmull = 0;
    uint32_t pllsource = 0;
    uint32_t cpu_freq_hz = 0;

    uint32_t prediv1source = 0;
    uint32_t prediv2factor = 0;
    uint32_t pll2mull = 0;

    switch (capabilities->family) {
    case STM32_FAMILY_F1:

        /* The following code was copied from the CMSIS system_stm32f10x.c  */

        tmp = state->u.f1.reg.cfgr & STM32F1_RCC_CFGR_SWS;

        switch (tmp) {
        case 0x00: /* HSI used as system clock */
            cpu_freq_hz = state->hsi_freq_hz;
            break;
        case 0x04: /* HSE used as system clock */
            cpu_freq_hz = state->hse_freq_hz;
            break;
        case 0x08: /* PLL used as system clock */

            /* Get PLL clock source and multiplication factor ---------------*/
            pllmull = state->u.f1.reg.cfgr & STM32F1_RCC_CFGR_PLLMULL;
            pllsource = state->u.f1.reg.cfgr & STM32F1_RCC_CFGR_PLLSRC;

            if (!capabilities->f1.is_cl) {
                pllmull = (pllmull >> 18) + 2;

                if (pllsource == 0x00) {
                    /* HSI oscillator clock divided by 2 selected as PLL
                     * clock entry */
                    cpu_freq_hz = (state->hsi_freq_hz >> 1) * pllmull;
                } else {
                    if (capabilities->f1.is_ldvl || capabilities->f1.is_mdvl
                            || capabilities->f1.is_hdvl) {
                        prediv1factor = (state->u.f1.reg.cfgr2
                                & STM32F1_RCC_CFGR2_PREDIV1) + 1;
                        /* HSE oscillator clock selected as PREDIV1
                         * clock entry */
                        cpu_freq_hz = (state->hse_freq_hz / prediv1factor)
                                * pllmull;
                    } else {
                        /* HSE selected as PLL clock entry */
                        if ((state->u.f1.reg.cfgr & STM32F1_RCC_CFGR_PLLXTPRE)
                                != (uint32_t) RESET) {
                            /* HSE oscillator clock divided by 2 */
                            cpu_freq_hz = (state->hse_freq_hz >> 1) * pllmull;
                        } else {
                            cpu_freq_hz = state->hse_freq_hz * pllmull;
                        }
                    }
                }
            } else {
                pllmull = pllmull >> 18;

                if (pllmull != 0x0D) {
                    pllmull += 2;
                } else {
                    /* PLL multiplication factor = PLL input clock * 6.5 */
                    pllmull = 13 / 2;
                }

                if (pllsource == 0x00) {
                    /* HSI oscillator clock divided by 2 selected as PLL
                     * clock entry */
                    cpu_freq_hz = (state->hsi_freq_hz >> 1) * pllmull;
                } else {
                    /* PREDIV1 selected as PLL clock entry */
                    /* Get PREDIV1 clock source and division factor */
                    prediv1source = state->u.f1.reg.cfgr2
                            & STM32F1_RCC_CFGR2_PREDIV1SRC;
                    prediv1factor = (state->u.f1.reg.cfgr2
                            & STM32F1_RCC_CFGR2_PREDIV1) + 1;

                    if (prediv1source == 0) {
                        /* HSE oscillator clock selected as PREDIV1
                         * clock entry */
                        cpu_freq_hz = (state->hse_freq_hz / prediv1factor)
                                * pllmull;
                    } else {/* PLL2 clock selected as PREDIV1 clock entry */

                        /* Get PREDIV2 division factor and PLL2
                         * multiplication factor */
                        prediv2factor = ((state->u.f1.reg.cfgr2
                                & STM32F1_RCC_CFGR2_PREDIV2) >> 4) + 1;
                        pll2mull = ((state->u.f1.reg.cfgr2
                                & STM32F1_RCC_CFGR2_PLL2MUL) >> 8) + 2;
                        cpu_freq_hz = (((state->hse_freq_hz / prediv2factor)
                                * pll2mull) / prediv1factor) * pllmull;
                    }
                }
            }
            break;

        default:
            cpu_freq_hz = state->hsi_freq_hz;
            break;
        }

        /* Compute HCLK clock frequency */
        /* Get HCLK prescaler */
        tmp =
                AHBPrescTable[((state->u.f1.reg.cfgr & STM32F1_RCC_CFGR_HPRE)
                        >> 4)];
        /* HCLK clock frequency */
        cpu_freq_hz >>= tmp;

        break;
    default:
        break;
    }

    if (cpu_freq_hz == 0) {
        cpu_freq_hz = state->hsi_freq_hz; /* Should be non-zero */
    }
    state->cpu_freq_hz = cpu_freq_hz;

    system_clock_scale = get_ticks_per_sec() / cpu_freq_hz;
    if (system_clock_scale == 0) {
        system_clock_scale = 1;
    }
    qemu_log_mask(LOG_TRACE, "%s() %d, system_clock_scale=%d\n", __FUNCTION__,
            cpu_freq_hz, system_clock_scale);

}

/* ------------------------------------------------------------------------- */

static void stm32_rcc_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    STM32RCCState *state = STM32_RCC_STATE(dev);

    STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;

    switch (capabilities->family) {
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
        if (capabilities->f1.is_cl) {
            state->u.f1.reg.ahbrstr = 0x00000000;
            state->u.f1.reg.cfgr2 = 0x00000000;
        }

        break;
    default:
        break;
    }

    stm32_rcc_update_clocks(state);
}

static void stm32_rcc_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    DeviceClass *parent_class = DEVICE_CLASS(
            object_class_get_parent(object_class_by_name(TYPE_STM32_RCC)));
    Error *local_err = NULL;
    parent_class->realize(dev, &local_err);
    if (local_err) {
        error_propagate(errp, local_err);
        return;
    }

    STM32RCCState *state = STM32_RCC_STATE(dev);

    STM32Capabilities *capabilities =
    STM32_SYS_BUS_DEVICE_STATE(state)->capabilities;
    assert(capabilities != NULL);

    uint64_t size;
    hwaddr addr;
    switch (capabilities->family) {
    case STM32_FAMILY_F1:
        size = 0x400;
        addr = 0x40021000;
        break;
    default:
        size = 0; /* This will trigger an assertion to fail */
        addr = 0;
    }

    memory_region_init_io(&state->mmio, OBJECT(dev), &stm32_rcc_ops, state,
    TYPE_STM32_RCC, size);

    SysBusDevice *sbd = SYS_BUS_DEVICE(dev);
    sysbus_init_mmio(sbd, &state->mmio);
    sysbus_mmio_map(sbd, 0, addr);

    // sysbus_init_irq(sbd, &state->irq);

    // qemu_set_irq(state->irq, 1);

    /* Set defaults, need to be non-zero */
    if (state->hsi_freq_hz == 0) {
        state->hsi_freq_hz = HSI_FREQ_HZ;
    }

    if (state->lsi_freq_hz == 0) {
        state->lsi_freq_hz = LSI_FREQ_HZ;
    }
}

static void stm32_rcc_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    // STM32RCCState *state = STM32_RCC_STATE(obj);
}

static Property stm32_rcc_properties[] = {
        DEFINE_PROP_UINT32("hse-freq-hz", STM32RCCState, hse_freq_hz,
                DEFAULT_HSE_FREQ_HZ),
        DEFINE_PROP_UINT32("lse-freq-hz", STM32RCCState, lse_freq_hz,
                DEFAULT_RTC_FREQ_HZ),
        DEFINE_PROP_UINT32("hsi-freq-hz", STM32RCCState, hsi_freq_hz,
                HSI_FREQ_HZ),
        DEFINE_PROP_UINT32("lsi-freq-hz", STM32RCCState, lsi_freq_hz,
                LSI_FREQ_HZ),
    DEFINE_PROP_END_OF_LIST(), };

static void stm32_rcc_class_init_callback(ObjectClass *klass, void *data)
{
    STM32RCCClass *nc = STM32_RCC_CLASS(klass);
    DeviceClass *dc = DEVICE_CLASS(klass);

    nc->parent_realize = dc->realize;

    dc->reset = stm32_rcc_reset_callback;
    dc->realize = stm32_rcc_realize_callback;

    dc->props = stm32_rcc_properties;
}

static const TypeInfo stm32_rcc_type_info = {
    .name = TYPE_STM32_RCC,
    .parent = TYPE_STM32_SYS_BUS_DEVICE,
    .instance_init = stm32_rcc_instance_init_callback,
    .instance_size = sizeof(STM32RCCState),
    .class_init = stm32_rcc_class_init_callback };

static void stm32_rcc_register_types(void)
{
    type_register_static(&stm32_rcc_type_info);
}

#if defined(CONFIG_GNU_ARM_ECLIPSE)
type_init(stm32_rcc_register_types);
#endif

/* ------------------------------------------------------------------------- */
