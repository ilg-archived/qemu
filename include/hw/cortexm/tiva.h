/*
 * TI Tiva devices emulation.
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

#ifndef HW_ARM_TIVA_H
#define HW_ARM_TIVA_H 1

#include "qemu/osdep.h"

#include "hw/boards.h"
#include <hw/cortexm/mcu.h>

void tiva_board_init(MachineState *machine, QEMUMachine *qm);

qemu_irq *tm4c123gh6pm_mcu_init(MachineState *machine);

#endif /* HW_ARM_TIVA_H */
