# Original content & patches

The `*-svd.json` files were generated from the original CMSIS files:

The `*-patch.json` are patches to add content required by QEMU.


## CPUID

The `cpu.revision` value (a string like r0p0) is the value that should be read from SCB.CPUID, address 0xE000ED00.

For the STM devices, this value is usually given in the _Programming manual_, the _Core peripherals_ chapter.

## Custom definitions

### CPU core capabilities

These definitions are from the [CMSIS SVD](http://www.keil.com/pack/doc/CMSIS/SVD/html/elem_cpu.html) `<cpu>` element, with some extensions.

- `name` (CM0, CM0PLUS, CM0+, CM1, CM3, CM4, CM7)
- `revision` (r0p0, values 0-15)
- `endian` (**little**/big/selectable)
- `mpuPresent` (true/**false**)
- `fpuPresent` (true/**false**)
- `fpuDP` (true/false, but only when FPU present) 
- `nvicPrioBits` - the number of significant bits on he left of the NVIC byte; 4 for most STM, 2 for F0
- `deviceNumInterrupts` - does not include the 16 system exceptions
- `vendorSystickConfig` (true/**false**)

QEMU extensions

- `qemuItmPresent` (true/**false**)
- `qemuEtmPresent` (true/**false**)

### qemuAlignment

The alignment extension can be defined for the device, peripherals, clusters or registers nodes. If the peripheral does not define it but is derived, the value of the original peripheral is checked.

Possible values are:

- `any`
- `word-halfWord`
- `word`

### qemuGroupName

This property is added to peripherals that have multiple instances, like GPIOA, GPIOB, USART1, USART2, etc.

It is used to correctly generate the support code.

## xsvd

The external tool used to process the SVD files is [`xsvd`](https://www.npmjs.com/package/xsvd).

## Devices

The commands used to generate the specifc xsvd files are:

### STM32F0x1

```
xsvd convert \
--file "/Users/ilg/Library/xPacks/Keil/STM32F0xx_DFP/1.5.0/SVD/STM32F0x1.svd" \
--output "STM32F0x1-xsvd.json" \
--verbose

xsvd patch \
--file "STM32F0x1-xsvd.json" \
--patch "STM32F0x1-patch.json" \
--output "../STM32F0x1-qemu.json" \
--remove "NVIC" \
--verbose

xsvd code \
--file "../STM32F0x1-qemu.json" \
--verbose

```

### STM32F0x2

```
xsvd convert \
--file "/Users/ilg/Library/xPacks/Keil/STM32F0xx_DFP/1.5.0/SVD/STM32F0x2.svd" \
--output "STM32F0x2-xsvd.json" \
--verbose

xsvd patch \
--file "STM32F0x2-xsvd.json" \
--patch "STM32F0x2-patch.json" \
--output "../STM32F0x2-qemu.json" \
--remove "NVIC" \
--verbose

xsvd code \
--file "../STM32F0x2-qemu.json" \
--verbose

```

### STM32F103xx

```
xsvd convert \
--file "/Users/ilg/Library/xPacks/Keil/STM32F1xx_DFP/2.1.0/SVD/STM32F103xx.svd" \
--output "STM32F103xx-xsvd.json" \
--verbose

xsvd patch \
--file "STM32F103xx-xsvd.json" \
--patch "STM32F103xx-patch.json" \
--output "../STM32F103xx-qemu.json" \
--remove "NVIC" \
--verbose

xsvd code \
--file "../STM32F103xx-qemu.json" \
--verbose

```

### STM32F107xx

```
xsvd convert \
--file "/Users/ilg/Library/xPacks/Keil/STM32F1xx_DFP/2.1.0/SVD/STM32F107xx.svd" \
--output "STM32F107xx-xsvd.json" \
--verbose

xsvd patch \
--file "STM32F107xx-xsvd.json" \
--patch "STM32F107xx-patch.json" \
--output "../STM32F107xx-qemu.json" \
--remove "NVIC" \
--verbose

xsvd code \
--file "../STM32F107xx-qemu.json" \
--verbose

```

### STM32F40x

```
xsvd convert \
--file "/Users/ilg/Library/xPacks/Keil/STM32F4xx_DFP/2.9.0/CMSIS/SVD/STM32F40x.svd" \
--output "STM32F40x-xsvd.json" \
--verbose

xsvd patch \
--file "STM32F40x-xsvd.json" \
--patch "STM32F40x-patch.json" \
--output "../STM32F40x-qemu.json" \
--remove "NVIC" \
--group-bitfield "RCC/PLLCFGR/PLLQ" \
--group-bitfield "RCC/PLLCFGR/PLLP" \
--group-bitfield "RCC/PLLCFGR/PLLN" \
--group-bitfield "RCC/PLLCFGR/PLLM" \
--group-bitfield "RCC/CFGR/SWS" \
--group-bitfield "RCC/CFGR/SW" \
--group-bitfield "RCC/BDCR/RTCSEL" \
--verbose

xsvd code \
--file "../STM32F40x-qemu.json" \
--verbose

```

### STM32F411xx

```
xsvd convert \
--file "/Users/ilg/Library/xPacks/Keil/STM32F4xx_DFP/2.9.0/CMSIS/SVD/STM32F411xx.svd" \
--output "STM32F411xx-xsvd.json" \
--verbose

xsvd patch \
--file "STM32F411xx-xsvd.json" \
--patch "STM32F411xx-patch.json" \
--output "../STM32F411xx-qemu.json" \
--remove "NVIC" \
--group-bitfield "RCC/PLLCFGR/PLLQ" \
--group-bitfield "RCC/PLLCFGR/PLLP" \
--group-bitfield "RCC/PLLCFGR/PLLN" \
--group-bitfield "RCC/PLLCFGR/PLLM" \
--group-bitfield "RCC/CFGR/SWS" \
--group-bitfield "RCC/CFGR/SW" \
--group-bitfield "RCC/BDCR/RTCSEL" \
--verbose

xsvd code \
--file "../STM32F411xx-qemu.json" \
--verbose

```

### STM32F429x

```
xsvd \
svd-convert \
--file "/Users/ilg/Library/xPacks/Keil/STM32F4xx_DFP/2.9.0/CMSIS/SVD/STM32F429x.svd" \
--output "STM32F429x-xsvd.json"

xsvd \
svd-patch \
--file "STM32F429x-xsvd.json" \
--patch "STM32F429x-patch.json" \
--output "../STM32F429x-qemu.json" \
--group-bitfield "RCC/PLLCFGR/PLLQ" \
--group-bitfield "RCC/PLLCFGR/PLLP" \
--group-bitfield "RCC/PLLCFGR/PLLN" \
--group-bitfield "RCC/PLLCFGR/PLLM" \
--group-bitfield "RCC/CFGR/SWS" \
--group-bitfield "RCC/CFGR/SW" \
--group-bitfield "RCC/BDCR/RTCSEL" 

xsvd \
svd-code \
--file "../STM32F429x-qemu.json" 

```

# Missing from CMSIS SVD

- alignment for registers & peripherals: choice of word/word-halfword/any (see `qemuAlignment`)

- bitband regions (array of {name, address})


# Development environment details

These details are relevant in my development environments, and are here as a convenience, to easily copy/paste them to the terminal.

The location of the folder:

```
cd /Users/ilg/Work/qemu/gnuarmeclipse-qemu.git/gnuarmeclipse/devices/support
cd /Users/ilg/My\ Files/MacBookPro\ Projects/GNU\ ARM\ Eclipse/gnuarmeclipse-qemu.git/gnuarmeclipse/devices/support
```
