STM32 is the main Cortex-M family emulated by **GNU ARM Eclipse QEMU**, and as such, provides the most accurate emulation.

Currently only the F1 family is implemented, but support for F4 and other families is provisioned, there are some switch case branches to be added.

## RCC

All RCC registers are present in the emulator, although some provide only limited functionality.

The peripheral clock enable bits are not yet made available to peripherals.

## GPIO

Setting the Set/Reset bits is reflected in the ODR bits, so using the GPIO for output operations is functional, but the input bits are not linked to the output bits, nor interrupts are triggered.

## FLASH

The FLASH device is used during the CMSIS initialisation to configure some wait states, and as such is mandatory for the emulator.

Using this device to reprogram the flash will be implemented at a later date, since it will require the flash region to be persistent.

## PWR

The PWR device is used during the CMSIS initialisation and as such it is mandatory for the emulator.

## EXTI

The EXTI device is used to route external interrupts to NVIC, and was added when support for the push buttons was needed.

Support for events is currently not provided.

## SYSCFG

The SYSCFG device is used for devices rom the F4 family, among other things, to configure which GPIO bits are connected to EXTI interrupts.

## USART

Support for USART is currently experimental, and incomplete.

