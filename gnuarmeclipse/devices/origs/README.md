# Original content & patches

The `*-svd.json` files were generated from the original CMSIS files:

The `*-patch.json` are patches to add content required by QEMU.

```
cd /Users/ilg/Work/qemu/gnuarmeclipse-qemu.git/gnuarmeclipse/devices
```

The commands used to generate the specifc xsvd files are:

## STM32F40x

```
xcdl \
generate-xsvd \
-i /Users/ilg/Library/xPacks/Keil/STM32F4xx_DFP/2.9.0/CMSIS/SVD/STM32F40x.svd \
-o origs/STM32F40x-xsvd.json

xcdl \
patch-xsvd \
--ifile "origs/STM32F40x-xsvd.json" \
--patch-file "origs/STM32F40x-patch.json" \
--ofile "STM32F40xx-qemu.json" \
--code "origs/STM32F40x-code.c" \
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

