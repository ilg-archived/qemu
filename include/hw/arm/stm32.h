/*
 * STM32 Cortex-M devices emulation
 *
 * Copyright (c) 2014 Liviu Ionescu
 *
 * This code is licensed under the GPL.
 */

#ifndef HW_ARM_STM32_H
#define HW_ARM_STM32_H 1

#include "hw/boards.h"
#include "hw/arm/cortexm.h"
#include "hw/sysbus.h"

#define TYPE_STM32F051R8 "STM32F051R8"
#define STM32F051R8_STATE(obj) \
    OBJECT_CHECK(stm32_state, (obj), TYPE_STM32F051R8)

#define TYPE_STM32F100RB "STM32F100RB"
#define STM32F100RB_STATE(obj) \
    OBJECT_CHECK(stm32_state, (obj), TYPE_STM32F100RB)

#define TYPE_STM32F103RB "STM32F103RB"
#define STM32F103RB_STATE(obj) \
    OBJECT_CHECK(stm32_state, (obj), TYPE_STM32F103RB)

#define TYPE_STM32F107VC "STM32F107VC"
#define STM32F107VC_STATE(obj) \
    OBJECT_CHECK(stm32_state, (obj), TYPE_STM32F107VC)

#define TYPE_STM32L152RE "STM32L152RE"
#define STM32L152RE_STATE(obj) \
    OBJECT_CHECK(stm32_state, (obj), TYPE_STM32L152RE)

#define TYPE_STM32F205RF "STM32F205RF"
#define STM32F205RF_STATE(obj) \
    OBJECT_CHECK(stm32_state, (obj), TYPE_STM32F205RF)

#define TYPE_STM32F303VC "STM32F303VC"
#define STM32F303VC_STATE(obj) \
    OBJECT_CHECK(stm32_state, (obj), TYPE_STM32F303VC)

#define TYPE_STM32F334R8 "STM32F334R8"
#define STM32F334R8_STATE(obj) \
    OBJECT_CHECK(stm32_state, (obj), TYPE_STM32F334R8)

#define TYPE_STM32F405RG "STM32F405RG"
#define STM32F405RG_STATE(obj) \
    OBJECT_CHECK(stm32_state, (obj), TYPE_STM32F405RG)

#define TYPE_STM32F407VG "STM32F407VG"
#define STM32F407VG_STATE(obj) \
    OBJECT_CHECK(stm32_state, (obj), TYPE_STM32F407VG)

#define TYPE_STM32F407ZG "STM32F407ZG"
#define STM32F407ZG_STATE(obj) \
    OBJECT_CHECK(stm32_state, (obj), TYPE_STM32F407ZG)

#define TYPE_STM32F411RE "STM32F411RE"
#define STM32F411RE_STATE(obj) \
    OBJECT_CHECK(stm32_state, (obj), TYPE_STM32F411RE)

#define TYPE_STM32F429ZI "STM32F429ZI"
#define STM32F429ZI_STATE(obj) \
    OBJECT_CHECK(stm32_state, (obj), TYPE_STM32F429ZI)

typedef struct stm32_state {
	/*< private >*/
	CortexMState parent_obj;
	/*< public >*/

	/* TODO: add specific structures */
} stm32_state;

void
stm32_mcu_create(MachineState *machine, const char *mcu_type);

void
stm32_memory_alias_realize(CortexMState *cm_state);

#endif /* HW_ARM_STM32_H */
