#ifndef QDEV_H
#define QDEV_H

#include "hw/hw.h"
#include "hw/qdev-core.h"
#include "hw/qdev-properties.h"

#if defined(CONFIG_GNU_ARM_ECLIPSE)
#define qdev_realize(dev) qdev_init_nofail(dev)
#endif

#endif
