Some following files need to be updated after merging new QEMU versions.

To check the new changes, use SourceTree, select the file, right click 

## cortex-nvic.c

Must follow `hw/intc/armv7m_nvic.c`.

* 20160402: patches from 2.5.1
* 20160727: checked for 2.6.0
* 20161024: patched from 2.7.0 (use `qemu_get_cpu(0)`)

## cortexm-mcu.c

Some updates in `hw/arm/armv7m.c`

* 20161024: checked for 2.7.0

# Other files

## gdb-xml/arm-cortexm.xml

Follow `gdb-xml/arm-core.xml`.


# Check for changes

* 20161024: checked for 2.7.0

## hw/arm/netduino2.c

## hw/arm/stellaris.c

## hw/arm/stm32f205_soc.c

## hw/char/stm32f2xx_usart.c

## hw/core/machine.c

## hw/misc/stm32f2xx_syscfg.c

## hw/timer/stm32f2xx_timer.c

## include/hw/arm/stm32f205_soc.h

## include/hw/misc/stm32f2xx_syscfg.h

## include/hw/timer/stm32f2xx_timer.h

## target-arm/cpu.c

