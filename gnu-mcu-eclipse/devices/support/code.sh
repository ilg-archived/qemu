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
xsvd code \
--file "../STM32F0x1-qemu.json" \
--verbose

echo
xsvd code \
--file "../STM32F0x2-qemu.json" \
--verbose

echo
xsvd code \
--file "../STM32F103xx-qemu.json" \
--verbose

echo
xsvd code \
--file "../STM32F107xx-qemu.json" \
--verbose

echo
xsvd code \
--file "../STM32F40x-qemu.json" \
--verbose

echo
xsvd code \
--file "../STM32F429x-qemu.json" \
--verbose

echo


