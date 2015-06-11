/*
 * STM32 Olimex boards emulation.
 *
 * Copyright (c) 2014 Liviu Ionescu
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

#include "hw/arm/stm32.h"
#include "hw/arm/stm32-mcu.h"
#include "qemu/module.h"
#include "sysemu/sysemu.h"

/*
 * This file defines several Olimex STM32 boards.
 */

//static uint64_t get_time_stamp()
//{
//    struct timeval tv;
//    gettimeofday(&tv, NULL);
//    return (tv.tv_sec * (uint64_t) 1000000 + tv.tv_usec) / 1000;
//}
/* ----- Olimex STM32-H103 ----- */

static void h103_green_led_active_low_irq_handler(void *opaque, int n,
        int level)
{
    /* There should only be one IRQ for the LED */
    assert(n == 0);

//    static uint64_t prev_time;
//    uint64_t crt_time = get_time_stamp();
//    int delta_time = crt_time - prev_time;
//    if (delta_time > 10000){
//        delta_time = 0;
//    }
    /* Assume that the IRQ is only triggered if the LED has changed state.
     * If this is not correct, we may get multiple LED Offs or Ons in a row.
     */
    switch (level) {
    case 0:
        // printf("%llu: Green LED On (+%d ms)\n", get_time_stamp(), delta_time);
        fprintf(stderr, "Green LED On\n");
        break;
    case 1:
        // printf("%llu: Green LED Off (+%d ms)\n", get_time_stamp(), delta_time);
        fprintf(stderr, "Green LED Off\n");
        break;
    }

    // prev_time = crt_time;
}

static void
stm32_h103_board_init_callback(MachineState *machine);

static QEMUMachine stm32_h103_machine = {
    .name = "STM32-H103",
    .desc = "Olimex Header Board for STM32F103RBT6 (Experimental)",
    .init = stm32_h103_board_init_callback };

/**
 * The first step to initialise the board.
 * Called by 'machine_class->init(current_machine);' in main().
 */
static void stm32_h103_board_init_callback(MachineState *machine)
{
    cortexm_board_greeting(machine);
    DeviceState *dev = cortexm_mcu_create(machine, TYPE_STM32F103RB);

    /* Set the oscillator frequencies. */
    DeviceState *rcc = stm32_mcu_get_rcc_dev(dev);
    assert(rcc);
    qdev_prop_set_uint32(rcc, "hse-freq-hz", 8000000); /* 8.0 MHz */
    qdev_prop_set_uint32(rcc, "lse-freq-hz", 32768); /* 32 KHz */

    qdev_realize(dev);

    DeviceState *gpio_c = stm32_mcu_get_gpio_dev(dev, STM32_GPIO_PORT_C);
    assert(gpio_c);

    /* Connect LED to GPIO C pin 12, active low */
    qemu_irq *led_irq = qemu_allocate_irqs(
            h103_green_led_active_low_irq_handler, NULL, 1);
    qdev_connect_gpio_out(gpio_c, 12, led_irq[0]);

}

/* ----- Olimex STM32-P103 ----- */
static void
stm32_p103_board_init_callback(MachineState *machine);

static QEMUMachine stm32_p103_machine = {
    .name = "STM32-P103",
    .desc = "Olimex Prototype Board for STM32F103RBT6 (Experimental)",
    .init = stm32_p103_board_init_callback };

static void stm32_p103_board_init_callback(MachineState *machine)
{
    cortexm_board_greeting(machine);
    cortexm_mcu_create(machine, TYPE_STM32F103RB);

    /* TODO: Add board inits */
}

/* ----- Olimex OLIMEXINO-STM32 ----- */
static void
olimexino_stm32_board_init_callback(MachineState *machine);

static QEMUMachine olimexino_stm32_machine = {
    .name = "OLIMEXINO-STM32",
    .desc = "Olimex Mapple (Arduino-like) Development Board (Experimental)",
    .init = olimexino_stm32_board_init_callback };

static void olimexino_stm32_board_init_callback(MachineState *machine)
{
    cortexm_board_greeting(machine);
    cortexm_mcu_create(machine, TYPE_STM32F103RB);

    /* TODO: Add board inits */
}

/* ----- Olimex STM32-P107 ----- */
static void
stm32_p107_board_init_callback(MachineState *machine);

static QEMUMachine stm32_p107_machine = {
    .name = "STM32-P107",
    .desc = "Olimex Prototype Board for STM32F107VCT6 (Experimental)",
    .init = stm32_p107_board_init_callback };

static void stm32_p107_board_init_callback(MachineState *machine)
{
    cortexm_board_greeting(machine);
    cortexm_mcu_create(machine, TYPE_STM32F107VC);

    /* TODO: Add board inits */
}

/* ----- Olimex STM32-P407 ----- */
static void
stm32_e407_board_init_callback(MachineState *machine);

static QEMUMachine stm32_e407_machine = {
    .name = "STM32-E407",
    .desc = "Olimex Development Board for STM32F407ZGT6 (Experimental)",
    .init = stm32_e407_board_init_callback };

static void stm32_e407_board_init_callback(MachineState *machine)
{
    cortexm_board_greeting(machine);
    cortexm_mcu_create(machine, TYPE_STM32F407ZG);

    /* TODO: Add board inits */
}

/* ----- Boards inits ----- */
static void stm32_olimex_machines_init(void)
{
    qemu_register_machine(&stm32_e407_machine);
    qemu_register_machine(&stm32_p107_machine);
    qemu_register_machine(&stm32_p103_machine);
    qemu_register_machine(&stm32_h103_machine);
    qemu_register_machine(&olimexino_stm32_machine);
}

#if defined(CONFIG_GNU_ARM_ECLIPSE)
machine_init(stm32_olimex_machines_init);
#endif
