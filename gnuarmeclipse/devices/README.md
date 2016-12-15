# Device definitions

## Overview

In **GNU ARM Eclipse QEMU**, the creation of the Cortex-M devices is entirely data driven by the definitions in these JSON files.

The files were automatically generated from the original CMSIS SVD files and then slightly patched to better match the QEMU requirements.

## Sub-family scope

Groups of similar devices share common definitions; specific devices can differ only by other characteristics, like Flash or RAM size.

The QEMU grouping reflects the vendor grouping, with one SVD file for each CMSIS sub-family.

Please note that the peripherals defined in the CMSIS SVD files are for the largest sub-family member, and some smaller members may not provide all the peripherals listed in the SVD files, thus the need for the extra capabilities structures.

## System peripherals

Some vendors also provide definitions for some system devices in the SVD files (line NVIC in STM32 files). Because there is no guarantee that the register names and fields are kept consistent, these definitions are ignored and the system peripherals are created using separate definitions.

## Data lifetime

During MCU object creation, the JSON is parsed and kept in memory during the entire lifetime of the process. To simplify things, object may refer to strings in the parsed tree (this may be changed in a future version).
