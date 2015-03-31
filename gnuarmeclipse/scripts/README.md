These are the scripts used during the **GNU ARM Eclipse QEMU** build procedure.

The build script:

* build-qemu.sh

## cross-pkg-config

For MinGW-w64 cross builds it is necessary to use a custom pkg-config, that will search only in the cross toolchain location, and never search the standard system locations, otherwise cross definitions will be messed with native definitions.

