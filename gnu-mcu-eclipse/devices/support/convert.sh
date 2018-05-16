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

XPACKS_FOLDER=${XPACKS_FOLDER:-"$HOME/Library/xPacks"}

echo
xsvd convert \
--file "${XPACKS_FOLDER}/Keil/STM32F0xx_DFP/1.5.0/SVD/STM32F0x1.svd" \
--output "STM32F0x1-xsvd.json" \
--verbose

echo
xsvd convert \
--file "${XPACKS_FOLDER}/Keil/STM32F0xx_DFP/1.5.0/SVD/STM32F0x2.svd" \
--output "STM32F0x2-xsvd.json" \
--verbose

echo
xsvd convert \
--file "${XPACKS_FOLDER}/Keil/STM32F1xx_DFP/2.1.0/SVD/STM32F103xx.svd" \
--output "STM32F103xx-xsvd.json" \
--verbose

echo
xsvd convert \
--file "${XPACKS_FOLDER}/Keil/STM32F1xx_DFP/2.1.0/SVD/STM32F107xx.svd" \
--output "STM32F107xx-xsvd.json" \
--verbose

echo
xsvd convert \
--file "${XPACKS_FOLDER}/Keil/STM32F4xx_DFP/2.9.0/CMSIS/SVD/STM32F40x.svd" \
--output "STM32F40x-xsvd.json" \
--verbose

echo
xsvd convert \
--file "${XPACKS_FOLDER}/Keil/STM32F4xx_DFP/2.9.0/CMSIS/SVD/STM32F429x.svd" \
--output "STM32F429x-xsvd.json" \
--verbose

echo
