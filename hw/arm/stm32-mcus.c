/*
 * STM32 Cortex-M devices emulation.
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

#include "hw/arm/stm32-mcus.h"
#include "hw/arm/cortexm-mcu.h"
#include "exec/address-spaces.h"
#include "qemu/error-report.h"
#include "sysemu/sysemu.h"
#include "hw/arm/cortexm-helper.h"

#if defined(CONFIG_VERBOSE)
#include "verbosity.h"
#endif

/* ------------------------------------------------------------------------- */

/**
 * Define all STM32 MCUs, based on table capabilities.
 *
 * To easily reuse the definitions, each line includes a pointer
 * to the core capabilities and a pointer to the stm32 capabilities.
 * This greatly simplify adding definition that differ only in memory size.
 */

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
 * - Connectivity line devices are STM32F105xx and STM32F107xx
 * microcontrollers.
 */

/*
 * Interrupts:
 *
 * - F1
 *   - CL: 68
 *   - [LMHX]D: 60
 * - F4
 *   - TBD
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

static const STM32Capabilities stm32f103x8b = {

    .family = STM32_FAMILY_F1,
    .f1 = {
        .is_md = true },

    .hsi_freq_hz = 8000000,
    .lsi_freq_hz = 40000,
    .has_rcc = true,
    .has_pwr = true,
    .has_rtc = true,
    .num_back_bytes = 20,

    .has_crc = true,
    .has_exti = true,
    .has_dma1 = true,
    .num_dma1 = 7,
    .has_ac_tim1 = true,
    .has_gp_tim2 = true,
    .has_gp_tim3 = true,
    .has_gp_tim4 = true,
    .has_iwdg = true,
    .has_wwdg = true,
    .has_i2c1 = true,
    .has_i2c2 = true,
    .has_usart1 = true, /* 4.5Mb/s */
    .has_usart2 = true, /* 2.25 Mb/s */
    .has_usart3 = true, /* 2.25 Mb/s */
    .has_spi1 = true,
    .has_spi2 = true,
    .has_bx_can1 = true,
    .has_usb_fs = true,

    .has_gpioa = true,
    .has_gpiob = true,
    .has_gpioc = true,
    .has_gpiod = true,
    .has_gpioe = true,

    .has_adc1 = true, /* 12-bits, 16-ch */
    .has_adc2 = true, /* 12-bits, 16-ch */

    .has_ts = 1, /* ADC12_IN16 */
};

static const STM32Capabilities stm32f10_57_xx = {

    .family = STM32_FAMILY_F1,
    .f1 = {
        .is_cl = true },

    .hsi_freq_hz = 8000000,
    .lsi_freq_hz = 40000,
    .has_rcc = true,
    .has_pwr = true,
    .has_rtc = true,

    .has_crc = true,
    .has_exti = true,
    .num_exti = 20,
    .has_dma1 = true,
    .num_dma1 = 7,
    .has_dma2 = true,
    .num_dma2 = 5,
    .has_ac_tim1 = true,
    .has_gp_tim2 = true,
    .has_gp_tim3 = true,
    .has_gp_tim4 = true,
    .has_gp_tim5 = true,
    .has_bc_tim6 = true,
    .has_bc_tim7 = true,
    .has_iwdg = true,
    .has_wwdg = true,
    .has_i2c1 = true,
    .has_i2c2 = true,
    .has_usart1 = true,
    .has_usart2 = true,
    .has_usart3 = true,
    .has_uart4 = true,
    .has_uart5 = true,
    .has_spi1 = true,
    .has_spi2 = true,
    .has_spi3 = true,
    .has_i2s1 = true,
    .has_i2s2 = true,
    .has_eth = true, /* 107 only */
    .has_can1 = true,
    .has_can2 = true,
    .has_usb_otg_fs = true,
    .has_gpioa = true,
    .has_gpiob = true,
    .has_gpioc = true,
    .has_gpiod = true,
    .has_gpioe = true,
    .has_adc1 = true,
    .has_adc2 = true,
    .has_dac1 = true,
    .has_dac2 = true,
    .has_ts = true, /* ADC1_IN16 */
};

static const STM32Capabilities stm32l15_12_xd = {

    .family = STM32_FAMILY_L1,

    .hsi_freq_hz = 16000000,
    .lsi_freq_hz = 37000,
    .has_rcc = true,
    .has_rtc = true,
    .eeprom_size_kb = 12,
    .num_back_bytes = 128,

    .has_gpioa = true,
    .has_gpiob = true,
    .has_gpioc = true,
    .has_gpiod = true,
    .has_gpioe = true,
    .has_gpiof = true,
    .has_gpiog = true,
    .has_gpioh = true,
    .has_exti = true,
    .num_exti = 24,
    .has_fsmc = true,
    .has_dma = true,
    .num_dma = 12,
    .has_adc = true, /* 12-bits, 40-ch */
    .has_ts = true, /* ADC_IN16 */
    .has_dac1 = true,
    .has_dac2 = true,
    .has_gp_tim2 = true,
    .has_gp_tim3 = true,
    .has_gp_tim4 = true,
    .has_gp_tim5 = true,
    .has_bc_tim6 = true,
    .has_bc_tim7 = true,
    .has_gp_tim9 = true,
    .has_gp_tim10 = true,
    .has_gp_tim11 = true,
    .has_iwdg = true,
    .has_wwdg = true,
    .has_i2c1 = true,
    .has_i2c2 = true,
    .has_usart1 = true,
    .has_usart2 = true,
    .has_usart3 = true,
    .has_uart4 = true,
    .has_uart5 = true,
    .has_spi1 = true,
    .has_spi2 = true,
    .has_spi3 = true,
    .has_i2s1 = true,
    .has_i2s2 = true,
    .has_sdio = true,
    .has_usb_fs = true,
    .has_crc = true,

/*
 * +LCD
 * + comparators
 * + touch sensing
 */
};

static const STM32Capabilities stm32f407xx = {

    .family = STM32_FAMILY_F4,
    .f4 = {
        .is_01_57_xx = true },

    .hsi_freq_hz = 16000000,
    //.lsi_freq_hz = 40000,
    .has_rcc = true,
    .has_pwr = true,
    .has_rtc = true,
    .num_back_bytes = 80,

    .ccm_size_kb = 64,
    .back_sram_size_kb = 4,

    .has_crc = true,
    .has_dma1 = true,
    .num_dma1 = 8,
    .has_dma2 = true,
    .num_dma2 = 8,
    .has_fsmc = true,
    .has_exti = true,
    .num_exti = 23,

    .has_ac_tim1 = true,
    .has_ac_tim8 = true,
    .has_gp_tim2 = true,
    .has_gp_tim3 = true,
    .has_gp_tim4 = true,
    .has_gp_tim5 = true,
    .has_gp_tim9 = true,
    .has_gp_tim10 = true,
    .has_gp_tim11 = true,
    .has_gp_tim12 = true,
    .has_gp_tim13 = true,
    .has_gp_tim14 = true,
    .has_bc_tim6 = true,
    .has_bc_tim7 = true,
    .has_iwdg = true,
    .has_wwdg = true,
    .has_i2c1 = true,
    .has_i2c2 = true,
    .has_i2c3 = true,
    .has_usart1 = true,
    .has_usart2 = true,
    .has_usart3 = true,
    .has_usart6 = true,
    .has_uart4 = true,
    .has_uart5 = true,
    .has_spi1 = true,
    .has_spi2 = true,
    .has_spi3 = true,
    .has_i2s1 = true,
    .has_i2s2 = true,
    .has_plli2s = true,
    .has_sdio = true,

    .has_eth = true,
    .has_bx_can1 = true,
    .has_bx_can2 = true,
    .has_usb_otg_fs = true,
    .has_usb_otg_hs = true,
    .has_dcmi = true, /* Only 407, not 405 */
    .has_rng = true,

    .has_gpioa = true,
    .has_gpiob = true,
    .has_gpioc = true,
    .has_gpiod = true,
    .has_gpioe = true,
    .has_gpiof = true,
    .has_gpiog = true,
    .has_gpioh = true,
    .has_gpioi = true,

    .has_adc1 = true, /* 12-bits, 16 channels */
    .has_adc2 = true,
    .has_adc3 = true,
    .has_ts = true, /* ADC1_IN16 */

    .has_dac1 = true, /* 12-bits */
    .has_dac2 = true, };

/* ------------------------------------------------------------------------- */

static const CortexMCoreCapabilities stm32f0xx_core = {
    .cpu_model = "cortex-m0",
    .has_mpu = false, /* itm? irqs? */
    .nvic_bits = 4, /**/
};

static const CortexMCoreCapabilities stm32f100_core = {
    .cpu_model = "cortex-m3",
    .has_mpu = true,
    .has_itm = true,
    .num_irq = 60,
    .nvic_bits = 4, /**/
};

static const CortexMCoreCapabilities stm32f1xx_core = {
    .cpu_model = "cortex-m3",
    .has_mpu = true,
    .has_itm = true, /* no ETM? */
    .num_irq = 44,
    .nvic_bits = 4 /**/
};

static const CortexMCoreCapabilities stm32f1cl_core = {
    .cpu_model = "cortex-m3",
    .has_mpu = true,
    .has_etm = true,
    .has_itm = true,
    .num_irq = 68,
    .nvic_bits = 4, /**/
};

static const CortexMCoreCapabilities stm32f152_core = {
    .cpu_model = "cortex-m3",
    .has_mpu = true,
    .has_itm = true, /* TODO: check */
    .has_etm = true,
    .num_irq = 57, /* TODO: check */
    .nvic_bits = 4, /**/
};

static const CortexMCoreCapabilities stm32f2xx_core = {
    .cpu_model = "cortex-m3",
    .has_mpu = true,
    .has_itm = true,
    .nvic_bits = 4, /**/
};

static const CortexMCoreCapabilities stm32f3xx_core = {
    .cpu_model = "cortex-m4f",
    .has_mpu = true,
    .has_itm = true,
    .nvic_bits = 4, /**/
};

static const CortexMCoreCapabilities stm32f4xx_core = {
    .cpu_model = "cortex-m4f",
    .has_mpu = true,
    .has_itm = true,
    .nvic_bits = 4, /**/
};

static const CortexMCoreCapabilities stm32f4_01_57_xx_core = {
    .cpu_model = "cortex-m4", /* TODO: make 4f when possible */
    .has_mpu = true,
    .has_itm = true,
    .num_irq = 82,
    .nvic_bits = 4, /**/
};

static const CortexMCoreCapabilities stm32f4_23_xxx_core = {
    .cpu_model = "cortex-m4", /* TODO: make 4f when possible */
    .has_mpu = true,
    .has_itm = true,
    .num_irq = 91,
    .nvic_bits = 4, /**/
};

/* ------------------------------------------------------------------------- */

static const STM32PartInfo stm32_mcus[] = {
    {
        .name = TYPE_STM32F051R8,
        .cortexm = {
            .flash_size_kb = 64,
            .sram_size_kb = 8,
            .core = &stm32f0xx_core, /* TODO: Add .stm32 */
        }, /**/
    },
    {
        .name = TYPE_STM32F100RB,
        .cortexm = {
            .flash_size_kb = 128,
            .sram_size_kb = 8,
            .core = &stm32f100_core, /* TODO: Add .stm32 */
        }, /**/
    },
    {
        .name = TYPE_STM32F103RB, /* STM32F103x[8B] */
        .cortexm = {
            .flash_size_kb = 128,
            .sram_size_kb = 20,
            .core = &stm32f1xx_core, /**/
        },
        .stm32 = &stm32f103x8b, /**/
    },
    {
        .name = TYPE_STM32F107VC,
        .cortexm = {
            .flash_size_kb = 256,
            .sram_size_kb = 64,
            .core = &stm32f1cl_core, /**/
        },
        .stm32 = &stm32f10_57_xx, /**/
    },
    {
        .name = TYPE_STM32L152RE,
        .cortexm = {
            .flash_size_kb = 384, /* 384+12 EEPROM */
            .sram_size_kb = 48,
            .core = &stm32f152_core, /**/
        },
        .stm32 = &stm32l15_12_xd, /**/
    },
    {
        .name = TYPE_STM32F205RF,
        .cortexm = {
            .flash_size_kb = 768,
            .sram_size_kb = 128, /* No CCM */
            .core = &stm32f2xx_core, /* TODO: Add .stm32 */
        }, /**/
    },
    {
        .name = TYPE_STM32F303VC,
        .cortexm = {
            .flash_size_kb = 256,
            .sram_size_kb = 40,
            .core = &stm32f3xx_core, /* TODO: Add .stm32 */
        }, /**/
    },
    {
        .name = TYPE_STM32F334R8,
        .cortexm = {
            .flash_size_kb = 64,
            .sram_size_kb = 12,
            .core = &stm32f3xx_core, /* TODO: Add .stm32 */
        }, /**/
    },
    {
        .name = TYPE_STM32F405RG,
        .cortexm = {
            .flash_size_kb = 1024,
            .sram_size_kb = 128, /* 64K CCM not counted */
            .core = &stm32f4_01_57_xx_core, /* TODO: Add .stm32 */
        }, /**/
    },
    {
        .name = TYPE_STM32F407VG,
        .cortexm = {
            .flash_size_kb = 1024,
            .sram_size_kb = 128, /* 64K CCM not counted */
            .core = &stm32f4_01_57_xx_core, /* TODO: Add .stm32 */
        },
        .stm32 = &stm32f407xx, /**/
    },
    {
        .name = TYPE_STM32F407ZG,
        .cortexm = {
            .flash_size_kb = 1024,
            .sram_size_kb = 128, /* 64K CCM not counted */
            .core = &stm32f4_01_57_xx_core, },
        .stm32 = &stm32f407xx /**/
    },
    {
        .name = TYPE_STM32F411RE,
        .cortexm = {
            .flash_size_kb = 512,
            .sram_size_kb = 128, /* No CCM */
            .core = &stm32f4xx_core, /* TODO: Add .stm32 */
        }, /**/
    },
    {
        .name = TYPE_STM32F429ZI,
        .cortexm = {
            .flash_size_kb = 2048,
            .sram_size_kb = 192, /* 64K CCM not counted */
            .core = &stm32f4_23_xxx_core, /* TODO: Add .stm32 */
        }, /**/
    },
    {
        .name = 0 /* End of array. */
    } /**/
};

/* ------------------------------------------------------------------------- */

static void stm32_mcus_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    STM32DeviceClass *st_class = STM32_DEVICE_GET_CLASS(dev);
    STM32PartInfo *part_info = st_class->part_info;

    /*
     * Set additional constructor parameters, that were passed via
     * the .class_data and copied to custom class member.
     */
    qdev_prop_set_ptr(dev, "cortexm-capabilities",
            (void *) &part_info->cortexm);
    qdev_prop_set_ptr(dev, "stm32-capabilities", (void *) part_info->stm32);

    /*
     * Call parent realize().
     * We do not know the current typename, since it was generated
     * with a table, so we use the parent typename.
     */
    if (!cm_device_by_name_realize(dev, errp, TYPE_STM32_DEVICE_PARENT)) {
        return;
    }
}

static void stm32_mcus_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    /* Call parent reset(). */
    cm_device_by_name_reset(dev, TYPE_STM32_MCU);
}

static Property stm32_mcus_properties[] = {
    /* TODO: add STM32 specific properties */
    DEFINE_PROP_END_OF_LIST(), /**/
};

static void stm32_mcus_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    dc->realize = stm32_mcus_realize_callback;
    dc->reset = stm32_mcus_reset_callback;
    dc->props = stm32_mcus_properties;

    STM32DeviceClass *st_class = (STM32DeviceClass *) (klass);
    /*
     * Copy the 'data' param, pointing to a ParamInfo, to the class
     * structure, to be retrieved by the constructor.
     */
    st_class->part_info = data;
}

/**
 * Register all devices described in the table.
 * Pass the pointer to the table element as .class_data
 * to the .class_init.
 */
static void stm32_mcus_types_init(void)
{
    int i;
    for (i = 0; stm32_mcus[i].name; ++i) {

        TypeInfo ti = {
            .name = stm32_mcus[i].name,
            .parent = TYPE_STM32_DEVICE_PARENT,
            .instance_size = sizeof(STM32DeviceState),
            .class_init = stm32_mcus_class_init_callback,
            .class_size = sizeof(STM32DeviceClass),
            .class_data = (void *) &stm32_mcus[i] };
        type_register(&ti);
    }
}

type_init(stm32_mcus_types_init);

/* ------------------------------------------------------------------------- */
