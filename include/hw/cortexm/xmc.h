/*
 * Infineon XMC devices emulation.
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

#ifndef HW_ARM_XMC_H
#define HW_ARM_XMC_H 1

#include "qemu/osdep.h"

#include "hw/boards.h"
#include <hw/cortexm/mcu.h>

void xmc_board_init(MachineState *machine, QEMUMachine *qm);

qemu_irq *xmc4500_f100k1024_mcu_init(MachineState *machine);
qemu_irq *xmc4500_f100f1024_mcu_init(MachineState *machine);
qemu_irq *xmc4500_f144k1024_mcu_init(MachineState *machine);
qemu_irq *xmc4400_f100k512_mcu_init(MachineState *machine);
qemu_irq *xmc4200_q48k256_mcu_init(MachineState *machine);
qemu_irq *xmc1300_t038x200_mcu_init(MachineState *machine);
qemu_irq *xmc1302_t038x200_mcu_init(MachineState *machine);
qemu_irq *xmc1201_t038x200_mcu_init(MachineState *machine);
qemu_irq *xmc1100_t038x064_mcu_init(MachineState *machine);
qemu_irq *xmc1100_q024f0064_mcu_init(MachineState *machine);

#endif /* HW_ARM_XMC_H */
