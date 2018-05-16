#!/usr/bin/env bash

# -----------------------------------------------------------------------------
# Safety settings (see https://gist.github.com/ilg-ul/383869cbb01f61a51c4d).

if [[ ! -z ${DEBUG} ]]
then
  set ${DEBUG} # Activate the expand mode if DEBUG is -x.
else
  DEBUG=""
fi

set -o errexit # Exit if command failed.
set -o pipefail # Exit if pipe failed.
set -o nounset # Exit if variable not set.

# Remove the initial space and instead use '\n'.
IFS=$'\n\t'

# ------------------------------------------------------------------

cd "$(dirname "$0")"

echo
xsvd patch \
--file "STM32F0x1-xsvd.json" \
--patch "STM32F0x1-patch.json" \
--output "../STM32F0x1-qemu.json" \
--remove "NVIC" \
--verbose

echo
xsvd patch \
--file "STM32F0x2-xsvd.json" \
--patch "STM32F0x2-patch.json" \
--output "../STM32F0x2-qemu.json" \
--remove "NVIC" \
--verbose

echo
xsvd patch \
--file "STM32F103xx-xsvd.json" \
--patch "STM32F103xx-patch.json" \
--output "../STM32F103xx-qemu.json" \
--remove "NVIC" \
--verbose

echo
xsvd patch \
--file "STM32F107xx-xsvd.json" \
--patch "STM32F107xx-patch.json" \
--output "../STM32F107xx-qemu.json" \
--remove "NVIC" \
--verbose

echo
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

echo
xsvd patch \
--file "STM32F429x-xsvd.json" \
--patch "STM32F429x-patch.json" \
--output "../STM32F429x-qemu.json" \
--remove "NVIC" \
--group-bitfield "RCC/PLLCFGR/PLLQ" \
--group-bitfield "RCC/PLLCFGR/PLLP" \
--group-bitfield "RCC/PLLCFGR/PLLN" \
--group-bitfield "RCC/PLLCFGR/PLLM" \
--group-bitfield "RCC/CFGR/SWS" \
--group-bitfield "RCC/CFGR/SW" \
--group-bitfield "RCC/BDCR/RTCSEL" \
--verbose

echo


