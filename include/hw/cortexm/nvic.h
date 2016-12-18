/*
 * Cortex-M NVIC emulation.
 *
 * Copyright (c) 2015 Liviu Ionescu.
 * Copyright (c) 2006-2007 CodeSourcery.
 * Written by Paul Brook.
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

#ifndef CORTEXM_NVIC_H
#define CORTEXM_NVIC_H

#include "qemu/osdep.h"

#include "hw/intc/gic_internal.h"
#include <hw/cortexm/peripheral.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_CORTEXM_NVIC "/machine/mcu/cortexm/nvic"

/* The GIC incoming interrupts are currently unnamed. */
#define IRQ_NVIC_IN     NULL

/*
 * System exceptions numbers.
 */
#define NVIC_EXCEPTION_RESET            1
#define NVIC_EXCEPTION_NMI              2
#define NVIC_EXCEPTION_HARD_FAULT       3
#define NVIC_EXCEPTION_MEM_MANAGE       4
#define NVIC_EXCEPTION_BUS_FAULT        5
#define NVIC_EXCEPTION_USAGE_FAULT      6
#define NVIC_EXCEPTION_SVCALL           11
#define NVIC_EXCEPTION_DEBUG_MONITOR    12
#define NVIC_EXCEPTION_PENDSV           14
#define NVIC_EXCEPTION_SYSTICK          15

// In addition to these 16 exceptions, each device also has a vendor specific
// number of peripheral interrupts (`num_irq`).

// ----------------------------------------------------------------------------

#define TYPE_CORTEXM_NVIC TYPE_CORTEXM_PREFIX "nvic" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_CORTEXM_NVIC_PARENT TYPE_ARM_GIC_COMMON
typedef ARMGICClass CortexMNVICParentClass;
typedef GICState CortexMNVICParentState;

// ----------------------------------------------------------------------------

typedef struct {

} CortexMNVICConstruct;

// Class definitions.
#define CORTEXM_NVIC_GET_CLASS(obj) \
    OBJECT_GET_CLASS(CortexMNVICClass, (obj), TYPE_CORTEXM_NVIC)
#define CORTEXM_NVIC_CLASS(klass) \
    OBJECT_CLASS_CHECK(CortexMNVICClass, (klass), TYPE_CORTEXM_NVIC)

typedef struct {
    // private:
    CortexMNVICParentClass parent_class;
    // public:

} CortexMNVICClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define CORTEXM_NVIC_STATE(obj) \
    OBJECT_CHECK(CortexMNVICState, (obj), TYPE_CORTEXM_NVIC)

// Inspired by the nvic_state defined in hw/intc/armv7m_nvic.c
typedef struct {
    // private:
    CortexMNVICParentState gic;
    // public:

    struct {
        uint32_t control;
        uint32_t reload;
        int64_t tick;
        QEMUTimer *timer;
    } systick;
    MemoryRegion sysregmem;
    MemoryRegion gic_iomem_alias;
    MemoryRegion container;

    // Number of vendor specific interrupts, multiple of 32.
    uint32_t num_irq;

    qemu_irq sysresetreq;

    // System Control Block 0xE000ED00 - 0xE000ED8C
    struct {
        uint32_t scr; // 0xE000ED10, RW, 0x00000000, System Control Block
        uint32_t ccr; // 0xE000ED14, RW, IMPL, Configuration & Control Register
                      // 0xE000ED24, RW, System Handler Control and State Register
        uint32_t cfsr; // 0xE000ED28, RW, 0x00000000, Configurable Fault Status Register
        uint32_t hfsr; // 0xE000ED2C, RW, 0x00000000, Hard Fault Status Register
        uint32_t dfsr; // 0xE000ED30, RW, 0x00000000, Debug Fault Status Register
        uint32_t mmfar; // 0xE000ED34, RW, UNK, MemManage Fault Address Register
        uint32_t bfar; // 0xE000ED38, RW, UNK, Bus Fault Address Register
        uint32_t afsr; // 0xE000ED3C, RW, UNK, Auxiliary Fault Status Register
    } scb;

    // Debug Control Block 0xE000EDF0 - 0xE000EEFF
    // All registers are 32-bits wide.
    struct {
        uint32_t dhcsr; // 0xE000EDF0, RW, Debug Halting Control and Status Register,
        uint32_t dcrsr; // 0xE000EDF4, WO, Debug Core Register Selector Register
        uint32_t dcrdr; // 0xE000EDF8, RW, Debug Core Register Data Register
        uint32_t demcr; // 0xE000EDFC, RW, 0x00000000, Debug Exception and Monitor Control Register
    } dcb;

} CortexMNVICState;

// ----------------------------------------------------------------------------

void cortexm_nvic_set_pending_exception(void *opaque, int exception);
void cortexm_nvic_set_pending_interrupt(void *opaque, int irq);

//void cortexm_nvic_set_pending(void *opaque, int irq);
int cortexm_nvic_acknowledge_irq(void *opaque);
void cortexm_nvic_complete_irq(void *opaque, int irq);

// ----------------------------------------------------------------------------

#endif /* CORTEXM_NVIC_H */
