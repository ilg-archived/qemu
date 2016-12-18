/*
 * Cortex-M BitBand emulation.
 *
 * Copyright (c) 2016 Liviu Ionescu.
 * Copyright (c) 2006-2007 CodeSourcery.
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

#include <hw/cortexm/bitband.h>

#include "cpu.h"

// Bitbanded IO.  Each word corresponds to a single bit.

// ----- Public ---------------------------------------------------------------

void cortexm_bitband_init(Object *parent, const char *node_name,
        uint32_t address)
{
    DeviceState *dev;

    // Make address a multiple of 32MB
    address &= ~(CORTEXM_BITBAND_OFFSET - 1);
    dev = qdev_create(NULL, TYPE_CORTEXM_BITBAND);
    cm_object_property_add_child(parent, node_name, OBJECT(dev));
    qdev_prop_set_uint32(dev, "base", address);
    qdev_init_nofail(dev);
    sysbus_mmio_map(SYS_BUS_DEVICE(dev), 0, address + CORTEXM_BITBAND_OFFSET);
}

// ----- Private --------------------------------------------------------------

// Get the byte address of the real memory for a bitband access.
static inline uint32_t cortexm_bitband_addr(void * opaque, uint32_t addr)
{
    uint32_t res;

    res = *(uint32_t *) opaque;
    res |= (addr & 0x1ffffff) >> 5;

    return res;
}

static uint32_t cortexm_bitband_readb(void *opaque, hwaddr offset)
{
    uint8_t v;
    cpu_physical_memory_read(cortexm_bitband_addr(opaque, offset), &v, 1);

    return (v & (1 << ((offset >> 2) & 7))) != 0;
}

static void cortexm_bitband_writeb(void *opaque, hwaddr offset, uint32_t value)
{
    uint32_t addr;
    uint8_t mask;
    uint8_t v;

    addr = cortexm_bitband_addr(opaque, offset);
    mask = (1 << ((offset >> 2) & 7));
    cpu_physical_memory_read(addr, &v, 1);
    if (value & 1)
        v |= mask;
    else
        v &= ~mask;

    cpu_physical_memory_write(addr, &v, 1);
}

static uint32_t cortexm_bitband_readw(void *opaque, hwaddr offset)
{
    uint32_t addr;
    uint16_t mask;
    uint16_t v;

    addr = cortexm_bitband_addr(opaque, offset) & ~1;
    mask = (1 << ((offset >> 2) & 15));
    mask = tswap16(mask);
    cpu_physical_memory_read(addr, &v, 2);

    return (v & mask) != 0;
}

static void cortexm_bitband_writew(void *opaque, hwaddr offset, uint32_t value)
{
    uint32_t addr;
    uint16_t mask;
    uint16_t v;

    addr = cortexm_bitband_addr(opaque, offset) & ~1;
    mask = (1 << ((offset >> 2) & 15));
    mask = tswap16(mask);
    cpu_physical_memory_read(addr, &v, 2);
    if (value & 1)
        v |= mask;
    else
        v &= ~mask;

    cpu_physical_memory_write(addr, &v, 2);
}

static uint32_t cortexm_bitband_readl(void *opaque, hwaddr offset)
{
    uint32_t addr;
    uint32_t mask;
    uint32_t v;

    addr = cortexm_bitband_addr(opaque, offset) & ~3;
    mask = (1 << ((offset >> 2) & 31));
    mask = tswap32(mask);
    cpu_physical_memory_read(addr, &v, 4);

    return (v & mask) != 0;
}

static void cortexm_bitband_writel(void *opaque, hwaddr offset, uint32_t value)
{
    uint32_t addr;
    uint32_t mask;
    uint32_t v;

    addr = cortexm_bitband_addr(opaque, offset) & ~3;
    mask = (1 << ((offset >> 2) & 31));
    mask = tswap32(mask);
    cpu_physical_memory_read(addr, &v, 4);
    if (value & 1)
        v |= mask;
    else
        v &= ~mask;

    cpu_physical_memory_write(addr, &v, 4);
}

static const MemoryRegionOps cortexm_bitband_ops = {
    .old_mmio = {
        .read = {
            cortexm_bitband_readb,
            cortexm_bitband_readw,
            cortexm_bitband_readl,
        /**/
        },
        .write = {
            cortexm_bitband_writeb,
            cortexm_bitband_writew,
            cortexm_bitband_writel,
        /**/
        },
    /**/
    },
    .endianness = DEVICE_NATIVE_ENDIAN,
/**/
};

// ----------------------------------------------------------------------------

static void cortexm_bitband_instance_init_callback(Object *obj)
{
    qemu_log_function_name();

    CortexMBitBandState *s = CORTEXM_BITBAND_STATE(obj);
    SysBusDevice *dev = SYS_BUS_DEVICE(obj);

    memory_region_init_io(&s->iomem, obj, &cortexm_bitband_ops, &s->base,
            "bitband", 0x02000000);
    sysbus_init_mmio(dev, &s->iomem);
}

static void cortexm_bitband_realize_callback(DeviceState *dev, Error **errp)
{
    qemu_log_function_name();

    // Call parent realize().
    if (!cm_device_parent_realize(dev, errp, TYPE_CORTEXM_BITBAND)) {
        return;
    }

    // Currently nothing to do.
}

static void cortexm_bitband_reset_callback(DeviceState *dev)
{
    qemu_log_function_name();

    // Currently nothing to do.
}

static Property cortexm_bitband_properties[] = {
        DEFINE_PROP_UINT32("base", CortexMBitBandState, base, 0),
    DEFINE_PROP_END_OF_LIST(), };

static void cortexm_bitband_class_init_callback(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->props = cortexm_bitband_properties;

    dc->reset = cortexm_bitband_reset_callback;
    dc->realize = cortexm_bitband_realize_callback;
}

static const TypeInfo cortexm_bitband_type_info = {
    .name = TYPE_CORTEXM_BITBAND,
    .parent = TYPE_CORTEXM_BITBAND_PARENT,
    .instance_init = cortexm_bitband_instance_init_callback,
    .instance_size = sizeof(CortexMBitBandState),
    .class_init = cortexm_bitband_class_init_callback,
    .class_size = sizeof(CortexMBitBandClass)
/**/
};

static void cortexm_bitband_register_types(void)
{
    type_register_static(&cortexm_bitband_type_info);
}

type_init(cortexm_bitband_register_types)

// ----------------------------------------------------------------------------
