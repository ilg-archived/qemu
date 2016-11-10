/*
 * Freescale Kinetis Cortex-M devices emulation.
 *
 * Copyright (c) 2014 Liviu Ionescu.
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

#ifndef HW_ARM_KINETIS_H
#define HW_ARM_KINETIS_H 1

#include "qemu/osdep.h"

#include "hw/boards.h"
#include <hw/cortexm/mcu.h>

void kinetis_board_init(MachineState *machine, QEMUMachine *qm);

qemu_irq *mk20dx128vlh5_mcu_init(MachineState *machine);
qemu_irq *mk64fn1m0vll12_mcu_init(MachineState *machine);
qemu_irq *mk60fn1m0vlq12_mcu_init(MachineState *machine);
qemu_irq *mkl25z128vlk4_mcu_init(MachineState *machine);
qemu_irq *mkl26z128vlh4_mcu_init(MachineState *machine);
qemu_irq *mkl46z256vll4_mcu_init(MachineState *machine);
qemu_irq *mk22fn512vlh12_mcu_init(MachineState *machine);
qemu_irq *mkl43z256vlh4_mcu_init(MachineState *machine);

#endif /* HW_ARM_KINETIS_H */
