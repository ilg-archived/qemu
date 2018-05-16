# All

- make the flash persistent (use a file to save at the end, if it was written)

## System memory
- add flash size
	- F1: 0x1FFFF7E0
	- F1: 0x1FFF7A22
- add device ID
	- F1: 1FFFF7E8 (12 bytes)
	- F4: 1FFF7A10 (12 bytes)
- add content for System Memory
	- F1: 0x1FFFF000-0x1FFFF7FF (2K)
	- F4: 0x1FFF0000-0x1FFF77FF
- add Option bytes

## NVIC

Reimplement NVIC as a separate object

## SysTick

Move the SysTick code outside the NVIC source file.

## ITM configuration

Add a configuration mechanism to enable/disable ITM externally, and to configure the stimulus port enable bits.

## ARMv6-M 

Add separate code to implement the simplified M0/M0+ (armv6m) excetion specifics.


# STM32

## RCC
- add an API to get access to the clock tree

## GPIO 
- check the peripheral clocks from RCC

