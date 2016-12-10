# Original content & patches

The `*-svd.json` files were generated from the original CMSIS files:

The `*-patch.json` are patches to add content required by QEMU.

```
cd /Users/ilg/Work/qemu/gnuarmeclipse-qemu.git/gnuarmeclipse/devices
```

The development version of `xcdl` is:

```
/Users/ilg/My\ Files/MacBookPro\ Projects/XCDL/xcdl-js.git/bin/xcdl
```

## CPUID

The `cpu.revision` value (a string like r0p0) is taken from SCB.CPUID, address 0xE000ED00.

For the STM devices, this value is usually gives in the _Programming manual_, the _Core peripherals_ chapter.


## Devices

The commands used to generate the specifc xsvd files are:

### STM32F0x1

```
xcdl \
generate-xsvd \
-i /Users/ilg/Library/xPacks/Keil/STM32F0xx_DFP/1.5.0/SVD/STM32F0x1.svd \
-o support/STM32F0x1-xsvd.json

xcdl \
patch-xsvd \
--ifile "support/STM32F0x1-xsvd.json" \
--patch-file "support/STM32F0x1-patch.json" \
--ofile "STM32F0x1-qemu.json" \
--code "support/STM32F0x1-code.c" \
--vendor-prefix "STM32" \
--device-family "F0" \
--remove "NVIC" \

```

### STM32F103xx

```
xcdl \
generate-xsvd \
-i /Users/ilg/Library/xPacks/Keil/STM32F1xx_DFP/2.1.0/SVD/STM32F103xx.svd \
-o support/STM32F103xx-xsvd.json

xcdl \
patch-xsvd \
--ifile "support/STM32F103xx-xsvd.json" \
--patch-file "support/STM32F103xx-patch.json" \
--ofile "STM32F103xx-qemu.json" \
--code "support/STM32F103xx-code.c" \
--vendor-prefix "STM32" \
--device-family "F1" \
--remove "NVIC" \

```

### STM32F40x

```
xcdl \
generate-xsvd \
-i /Users/ilg/Library/xPacks/Keil/STM32F4xx_DFP/2.9.0/CMSIS/SVD/STM32F40x.svd \
-o support/STM32F40x-xsvd.json

xcdl \
patch-xsvd \
--ifile "support/STM32F40x-xsvd.json" \
--patch-file "support/STM32F40x-patch.json" \
--ofile "STM32F40xx-qemu.json" \
--code "support/STM32F40x-code.c" \
--vendor-prefix "STM32" \
--device-family "F4" \
--remove "NVIC" \
--group-bitfield "RCC/PLLCFGR/PLLQ" \
--group-bitfield "RCC/PLLCFGR/PLLP" \
--group-bitfield "RCC/PLLCFGR/PLLN" \
--group-bitfield "RCC/PLLCFGR/PLLM" \
--group-bitfield "RCC/CFGR/SWS" \
--group-bitfield "RCC/CFGR/SW" \
--group-bitfield "RCC/BDCR/RTCSEL" \

```

# Missing from CMSIS SVD

- alignment for registers & peripherals: choice of word/word-halfword/any

- bitband regions (array of {name, address})

