/*
 * STM32 boards emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#include "hw/arm/stm32.h"
#include "qemu/module.h"
#include "sysemu/sysemu.h"

/*
 * This file defines several STM32 boards.
 * Where available, the board names follow the CMSIS Packs names.
 *
 * In time, this file should probably be split into several specific files
 * (for example stm32_olimex_bords.c)
 */

#if 0
typedef const struct {
    
} stm32_board_info;
#endif

/* Common inits for all STM32 boards */
void stm32_board_init(MachineState *machine, QEMUMachine *qm)
{
#if defined(CONFIG_VERBOSE)
    if (verbosity_level > 0) {
        printf("Board: '%s' (%s).\n", qm->name, qm->desc);
    }
#endif
}

/* ----- ST NUCLEO-F411RE ----- */
static void nucleo_f411re_board_init(MachineState *machine);

static QEMUMachine nucleo_f411re_machine = {
    .name = "NUCLEO-F411RE",
    .desc = "ST Nucleo development board for STM32 F4 series (Experimental)",
    .init = nucleo_f411re_board_init,
};

static void nucleo_f411re_board_init(MachineState *machine)
{
    stm32_board_init(machine, &nucleo_f411re_machine);
    stm32f411re_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- ST NUCLEO-F334R8 ----- */
static void nucleo_f334r8_board_init(MachineState *machine);

static QEMUMachine nucleo_f334r8_machine = {
    .name = "NUCLEO-F334R8",
    .desc = "ST Nucleo development board for STM32 F3 series (Experimental)",
    .init = nucleo_f334r8_board_init,
};

static void nucleo_f334r8_board_init(MachineState *machine)
{
    stm32_board_init(machine, &nucleo_f334r8_machine);
    stm32f334r8_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- ST NUCLEO-F103RB ----- */
static void nucleo_f103rb_board_init(MachineState *machine);

static QEMUMachine nucleo_f103rb_machine = {
    .name = "NUCLEO-F103RB",
    .desc = "ST Nucleo development board for STM32 F1 series (Experimental)",
    .init = nucleo_f103rb_board_init,
};

static void nucleo_f103rb_board_init(MachineState *machine)
{
    stm32_board_init(machine, &nucleo_f103rb_machine);
    stm32f103rb_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- ST NUCLEO-L152RE ----- */
static void nucleo_l152re_board_init(MachineState *machine);

static QEMUMachine nucleo_l152re_machine = {
    .name = "NUCLEO-L152RE",
    .desc = "ST Nucleo development board with STM32L152RET6 (Experimental)",
    .init = nucleo_l152re_board_init,
};

static void nucleo_l152re_board_init(MachineState *machine)
{
    stm32_board_init(machine, &nucleo_l152re_machine);
    stm32l152re_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- ST STM32F4-Discovery ----- */
static void stm32f4_discovery_board_init(MachineState *machine);

static QEMUMachine stm32f4_discovery_machine = {
    .name = "STM32F4-Discovery",
    .desc = "ST Discovery kit for STM32F407/417 lines (Experimental)",
    .init = stm32f4_discovery_board_init,
};

static void stm32f4_discovery_board_init(MachineState *machine)
{
    stm32_board_init(machine, &stm32f4_discovery_machine);
    stm32f407vg_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- ST STM32F429I-Discovery ----- */
static void stm32f429i_discovery_board_init(MachineState *machine);

static QEMUMachine stm32f429i_discovery_machine = {
    .name = "STM32F429I-Discovery",
    .desc = "ST Discovery kit for STM32F429/439 lines (Experimental)",
    .init = stm32f429i_discovery_board_init,
};

static void stm32f429i_discovery_board_init(MachineState *machine)
{
    stm32_board_init(machine, &stm32f429i_discovery_machine);
    stm32f429zi_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- ST STM32F3-Discovery ----- */
static void stm32f3_discovery_board_init(MachineState *machine);

static QEMUMachine stm32f3_discovery_machine = {
    .name = "STM32F3-Discovery",
    .desc = "ST Discovery kit for STM32F303 line (Experimental)",
    .init = stm32f3_discovery_board_init,
};

static void stm32f3_discovery_board_init(MachineState *machine)
{
    stm32_board_init(machine, &stm32f3_discovery_machine);
    stm32f303vc_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- ST STM32F0-Discovery ----- */
static void stm32f0_discovery_board_init(MachineState *machine);

static QEMUMachine stm32f0_discovery_machine = {
    .name = "STM32F0-Discovery",
    .desc = "ST Discovery kit for STM32F051 line (Experimental)",
    .init = stm32f0_discovery_board_init,
};

static void stm32f0_discovery_board_init(MachineState *machine)
{
    stm32_board_init(machine, &stm32f0_discovery_machine);
    stm32f051r8_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- ST STM32VL-Discovery ----- */
static void stm32vl_discovery_init(MachineState *machine);

static QEMUMachine stm32vl_discovery_machine = {
    .name = "STM32VL-Discovery",
    .desc = "ST Discovery kit for STM32F100 Value Line (Experimental)",
    .init = stm32vl_discovery_init,
};

static void stm32vl_discovery_init(MachineState *machine)
{
    stm32_board_init(machine, &stm32vl_discovery_machine);
    stm32f100rb_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- Olimex STM32-H103 ----- */
static void stm32_h103_board_init(MachineState *machine);

static QEMUMachine stm32_h103_machine = {
    .name = "STM32-H103",
    .desc = "Olimex Header Board for STM32F103RBT6 (Experimental)",
    .init = stm32_h103_board_init,
};

static void stm32_h103_board_init(MachineState *machine)
{
    stm32_board_init(machine, &stm32_h103_machine);
    stm32f103rb_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- Olimex STM32-P103 ----- */
static void stm32_p103_board_init(MachineState *machine);

static QEMUMachine stm32_p103_machine = {
    .name = "STM32-P103",
    .desc = "Olimex Prototype Board for STM32F103RBT6 (Experimental)",
    .init = stm32_p103_board_init,
};

static void stm32_p103_board_init(MachineState *machine)
{
    stm32_board_init(machine, &stm32_p103_machine);
    stm32f103rb_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- Olimex OLIMEXINO-STM32 ----- */
static void olimexino_stm32_board_init(MachineState *machine);

static QEMUMachine olimexino_stm32_machine = {
    .name = "OLIMEXINO-STM32",
    .desc = "Olimex Mapple (Arduino-like) Development Board (Experimental)",
    .init = olimexino_stm32_board_init,
};

static void olimexino_stm32_board_init(MachineState *machine)
{
    stm32_board_init(machine, &olimexino_stm32_machine);
    stm32f103rb_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- Olimex STM32-P107 ----- */
static void stm32_p107_board_init(MachineState *machine);

static QEMUMachine stm32_p107_machine = {
    .name = "STM32-P107",
    .desc = "Olimex Prototype Board for STM32F107VCT6 (Experimental)",
    .init = stm32_p107_board_init,
};

static void stm32_p107_board_init(MachineState *machine)
{
    stm32_board_init(machine, &stm32_p107_machine);
    stm32f107vc_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- Olimex STM32-P407 ----- */
static void stm32_p407_board_init(MachineState *machine);

static QEMUMachine stm32_p407_machine = {
    .name = "STM32-P407",
    .desc = "Olimex Development Board for STM32F407ZGT6 (Experimental)",
    .init = stm32_p407_board_init,
};

static void stm32_p407_board_init(MachineState *machine)
{
    stm32_board_init(machine, &stm32_p407_machine);
    stm32f407zg_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- Netduino 2 ----- */
static void netduino2_board_init(MachineState *machine);

static QEMUMachine netduino2_machine = {
    .name = "Netduino2",
    .desc = "Netduino Development Board with STM32F2 (Experimental)",
    .init = netduino2_board_init,
};

static void netduino2_board_init(MachineState *machine)
{
    stm32_board_init(machine, &netduino2_machine);
    stm32f205rf_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- Netduino Plus 2 ----- */
static void netduinoplus2_board_init(MachineState *machine);

static QEMUMachine netduinoplus2_machine = {
    .name = "NetduinoPlus2",
    .desc = "Netduino Development Board with STM32F4 (Experimental)",
    .init = netduinoplus2_board_init,
};

static void netduinoplus2_board_init(MachineState *machine)
{
    stm32_board_init(machine, &netduinoplus2_machine);
    stm32f405rg_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- Netduino Go ----- */
static void netduinogo_board_init(MachineState *machine);

static QEMUMachine netduinogo_machine = {
    .name = "NetduinoGo",
    .desc = "Netduino GoBus Development Board with STM32F4 (Experimental)",
    .init = netduinogo_board_init,
};

static void netduinogo_board_init(MachineState *machine)
{
    stm32_board_init(machine, &netduinogo_machine);
    stm32f405rg_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- Mapple ----- */
static void mapple_board_init(MachineState *machine);

static QEMUMachine mapple_machine = {
    .name = "Mapple",
    .desc = "LeafLab Arduino-style STM32 microcontroller board (Experimental)",
    .init = mapple_board_init,
};

static void mapple_board_init(MachineState *machine)
{
    stm32_board_init(machine, &mapple_machine);
    stm32f103rb_mcu_init(machine);
    /* TODO: Add board inits */
}

/* ----- Boards inits ----- */
static void stm32_machine_init(void)
{
    qemu_register_machine(&nucleo_f411re_machine);
    qemu_register_machine(&nucleo_f334r8_machine);
    qemu_register_machine(&nucleo_f103rb_machine);
    qemu_register_machine(&nucleo_l152re_machine);
    qemu_register_machine(&stm32f429i_discovery_machine);
    qemu_register_machine(&stm32f4_discovery_machine);
    qemu_register_machine(&stm32f3_discovery_machine);
    qemu_register_machine(&stm32f0_discovery_machine);
    qemu_register_machine(&stm32vl_discovery_machine);
    qemu_register_machine(&stm32_p407_machine);
    qemu_register_machine(&stm32_p107_machine);
    qemu_register_machine(&stm32_p103_machine);
    qemu_register_machine(&stm32_h103_machine);
    qemu_register_machine(&olimexino_stm32_machine);
    qemu_register_machine(&netduino2_machine);
    qemu_register_machine(&netduinoplus2_machine);
    qemu_register_machine(&netduinogo_machine);
    qemu_register_machine(&mapple_machine);
}

machine_init(stm32_machine_init);
