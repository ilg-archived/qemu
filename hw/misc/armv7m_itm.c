/*
 * ARM Instrumentation Trace Macrocell.
 *
 * Copyright (c) 2015 Liviu Ionescu
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "hw/sysbus.h"
#include "hw/misc/armv7m_itm.h"

/**
 * This file implements a minimal ITM peripheral, intended to display
 * the trace messages sent via byte writes to stimulus port 0.
 */

/**
 * Read from ITM registers.
 *
 * Only word operations are currently supported.
 */
static uint64_t itm_read(void *opaque, hwaddr addr, unsigned size)
{
	ITMState *state = (ITMState *) opaque;
	uint32_t offset = addr;

	if (offset < 0x400) {
		if ((offset & 0x3) == 0) {
			/* Word aligned reads return the busy flag */
			return 1; /* All ports are set as not busy */
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
		return state->ter[ix];
	} else if (offset == 0xE40) {
		return state->tpr;
	} else if (offset == 0xE80) {
		return state->tcr & 0x007F00F1F; /* BUSY = 0 */
	} else if (offset == 0xE84) {
		/* TODO: check if some special value must be returned */
		return state->lsr;
	} else {
		return 0;
	}
}

/**
 * Write to ITM registers.
 *
 * Byte writes to stimulus port 0 are forwarded to stderr.
 *
 * Word writes to the other registers
 */
static void itm_write(void *opaque, hwaddr addr, uint64_t value, unsigned size)
{
	ITMState *state = (ITMState *) opaque;
	uint32_t offset = addr;

	if (offset < 0x400) {

		if ((state->tcr & 0x00000001) == 0) {
			return; /* Ignore writes if ITM disabled */
		}

		/* Compute index of stimulus port (4 bytes each)  */
		int ix = (offset - 0x000) / 4;

		if (ix >= state->num_ports) {
			return; /* Ignore unsupported stimulus ports */
		}
		/* Compute index of Enable register (32 stimus ports / register) */
		int eix = ix / 32;
		uint32_t mask = 1 << (ix - eix * 32);
		if ((state->ter[ix] & mask) == 0) {
			return; /* Ignore not enabled stimulus ports */
		}

		if (ix == 0) {
			/* Currently only stimulus port 0 is used for trace, byte size */
			if (size == 1) {
				uint8_t byte;
				byte = value;
				write(2, &byte, 1); /* Write on stderr */
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
			return; /* Ignore unsupported stimulus ports */
		}

		state->ter[ix] = value;
	} else if (offset == 0xE40) {
		state->tpr = value;
	} else if (offset == 0xE80) {
		state->tcr = value & 0x007F00F1F;
	}
}

static const MemoryRegionOps itm_ops =
{
	.read = itm_read,
	.write = itm_write,
	.endianness = DEVICE_NATIVE_ENDIAN, };

static void armv7m_itm_reset(DeviceState *dev)
{
	qemu_log_function_name();

	ITMState *state = ITM_STATE(dev);

	for (int i = 0; i < state->num_ports; ++i) {
		state->stim[i] = 0x00000000;
	}

	for (int i = 0; i < ((state->num_ports + 31) / 32); ++i) {
		state->ter[i] = 0x00000000;
	}

	state->tpr = 0x00000000;
	state->tcr = 0x00000000;

	state->lsr = 0x00000000;

	/* To simplify startup, enable port and stimulus[0] */
	state->ter[0] = 0x0000001;
	state->tcr = 0x00000001; /* ITMENA=1 */
}

static void armv7m_itm_realize(DeviceState *dev, Error **errp)
{
	qemu_log_function_name();

	ITMState *state = ITM_STATE(dev);

	memory_region_init_io(&state->mmio, OBJECT(dev), &itm_ops, state, "itm",
			0x1000);

	sysbus_init_mmio(SYS_BUS_DEVICE(dev), &state->mmio);
	sysbus_mmio_map(SYS_BUS_DEVICE(dev), 0, 0xE0000000);
}

static void armv7m_itm_instance_init(Object *obj)
{
	qemu_log_function_name();

	ITMState *state = ITM_STATE(obj);

	/* TODO: make it configurable */
	state->num_ports = DEFAULT_ITM_NUM_PORTS;
}

static void armv7m_itm_class_init(ObjectClass *klass, void *data)
{
	DeviceClass *dc = DEVICE_CLASS(klass);

	// TODO: check if VMStateDescription is required
	// dc->vmsd = &vmstate_itm;
	dc->reset = armv7m_itm_reset;
	dc->realize = armv7m_itm_realize;
}

static const TypeInfo armv7m_itm_type_info =
{
	.name = TYPE_ITM,
	.parent = TYPE_SYS_BUS_DEVICE,
	.instance_init = armv7m_itm_instance_init,
	.instance_size = sizeof(ITMState),
	.class_init = armv7m_itm_class_init,
	.class_size = sizeof(ITMClass) };

static void armv7m_itm_register_types(void)
{
	type_register_static(&armv7m_itm_type_info);
}

#if defined(CONFIG_GNU_ARM_ECLIPSE)
type_init(armv7m_itm_register_types)
#endif
