/*
 * ARM Instrumentation Trace Macrocell emulation.
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

#include <hw/cortexm/itm.h>

/*
 * This file implements a minimal ITM peripheral, intended to display
 * the trace messages sent via byte writes to stimulus port 0.
 */

// ----- Private --------------------------------------------------------------
// Read from ITM registers.
//
// Only word operations are currently supported.
static uint64_t cortexm_itm_read_callback(void *opaque, hwaddr addr,
        unsigned size)
{
    CortexMITMState *state = (CortexMITMState *) opaque;
    uint32_t offset = addr;

    if (offset < 0x400) {
        if ((offset & 0x3) == 0) {
            // Word aligned reads return the busy flag
            return 1; // All ports are set as not busy
        } else {
            return 1;
        }
    }

    if (size != 4) {
        qemu_log_mask(LOG_GUEST_ERROR,
                "ITM: Read of size %d at offset 0x%x not implemented\n", size,
                offset);
        return 0;
    }

    if ((offset >= 0xE00) && (offset < 0xE20)) {
        int ix = (offset - 0xE00) / 4;
        return state->reg.ter[ix];
    } else if (offset == 0xE40) {
        return state->reg.tpr;
    } else if (offset == 0xE80) {
        return state->reg.tcr & 0x007F00F1F; /* BUSY = 0 */
    } else if (offset == 0xE84) {
        // TODO: check if some special value must be returned
        return state->reg.lsr;
    } else {
        return 0;
    }
}

// Write to ITM registers.
//
// Byte writes to stimulus port 0 are forwarded to stderr.
//
// Word writes to the other registers
static void cortexm_itm_write_callback(void *opaque, hwaddr addr,
        uint64_t value, unsigned size)
{
    CortexMITMState *state = (CortexMITMState *) opaque;
    uint32_t offset = addr;

    if (offset < 0x400) {

        if ((state->reg.tcr & 0x00000001) == 0) {
            return; // Ignore writes if ITM disabled
        }

        // Compute index of stimulus port (4 bytes each)
        int ix = (offset - 0x000) / 4;

        if (ix >= state->num_ports) {
            return; // Ignore unsupported stimulus ports
        }
        // Compute index of Enable register (32 stimulus ports / register)
        int eix = ix / 32;
        uint32_t mask = 1 << (ix - eix * 32);
        if ((state->reg.ter[ix] & mask) == 0) {
            return; // Ignore not enabled stimulus ports
        }

        if (ix == 0) {
            // Currently only stimulus port 0 is used for trace, byte size
            if (size == 1) {
                uint8_t byte;
                byte = value;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
                write(2, &byte, 1); /* Write on stderr */
#pragma GCC diagnostic pop

            } else {
                qemu_log_mask(LOG_GUEST_ERROR,
                        "ITM: Stimulus write size %d at offset 0x%x not implemented\n",
                        size, offset);
            }
            return;
        }

        qemu_log_mask(LOG_GUEST_ERROR,
                "ITM: Stimulus write size %d at offset 0x%x not implemented\n",
                size, offset);
        return;
    }

    if (size != 4) {
        qemu_log_mask(LOG_GUEST_ERROR,
                "ITM: Write of size %d at offset 0x%x not implemented\n", size,
                offset);
        return;
    }

    if ((offset >= 0xE00) && (offset < 0xE20)) {
        int ix = (offset - 0xE00) / 4;
        if (ix >= (state->num_ports + 31) / 32) {
            return; // Ignore unsupported stimulus ports
        }

        state->reg.ter[ix] = value;
    } else if (offset == 0xE40) {
        state->reg.tpr = value;
    } else if (offset == 0xE80) {
        state->reg.tcr = value & 0x007F00F1F;
    }
}

static const MemoryRegionOps armv7m_itm_ops = {
    .read = cortexm_itm_read_callback,
    .write = cortexm_itm_write_callback,
    .endianness = DEVICE_NATIVE_ENDIAN,
/**/
};

// ----------------------------------------------------------------------------

static void cortexm_itm_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    CortexMITMState *state = CORTEXM_ITM_STATE(obj);

    // TODO: make it configurable
    state->num_ports = CORTEXM_ITM_DEFAULT_NUM_PORTS;
}

static void cortexm_itm_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_CORTEXM_ITM)) {
        return;
    }

    CortexMITMState *state = CORTEXM_ITM_STATE(dev);

    uint64_t size = 0x1000;
    hwaddr addr = 0xE0000000;

    memory_region_init_io(&state->mmio, OBJECT(dev), &armv7m_itm_ops, state,
            "mmio", size);

    sysbus_init_mmio(SYS_BUS_DEVICE(dev), &state->mmio);
    sysbus_mmio_map(SYS_BUS_DEVICE(dev), 0, addr);
}

static void cortexm_itm_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    CortexMITMState *state = CORTEXM_ITM_STATE(dev);
    int i;
    for (i = 0; i < state->num_ports; ++i) {
        state->reg.stim[i] = 0x00000000;
    }

    for (i = 0; i < ((state->num_ports + 31) / 32); ++i) {
        state->reg.ter[i] = 0x00000000;
    }

    state->reg.tpr = 0x00000000;
    state->reg.tcr = 0x00000000;

    state->reg.lsr = 0x00000000;

    // To simplify startup, enable port and stimulus[0]
    state->reg.ter[0] = 0x0000001;
    state->reg.tcr = 0x00000001; /* ITMENA=1 */
}

static void cortexm_itm_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = cortexm_itm_reset_callback;
    dc->realize = cortexm_itm_realize_callback;
}

static const TypeInfo cortexm_itm_type_info = {
    .name = TYPE_CORTEXM_ITM,
    .parent = TYPE_CORTEXM_ITM_PARENT,
    .instance_init = cortexm_itm_instance_init_callback,
    .instance_size = sizeof(CortexMITMState),
    .class_init = cortexm_itm_class_init_callback,
    .class_size = sizeof(CortexMITMClass)
/**/
};

static void cortexm_itm_register_types(void)
{
    type_register_static(&cortexm_itm_type_info);
}

type_init(cortexm_itm_register_types);

// ----------------------------------------------------------------------------
