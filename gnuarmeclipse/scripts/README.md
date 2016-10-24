These are the scripts used to build QEMU.

# build-orig-qemu.sh

This is a script to build the original QEMU, from the public repository or from Stefan Weil's repository.

It runs on a Debian 8 x64 Docker container.

# cross-pkg-config

For MinGW-w64 cross builds it is necessary to use a custom pkg-config, that will search only in the cross toolchain location, and never search the standard system locations, otherwise cross definitions will be messed with native definitions.

# pkg-config-dbg 

When using custom pkg-config files, and you are not sure the configure or cmake understand them correctly, you can temporarily use a debugging version of pkg-config that will dump more info on stderr.

For **configure**, add the following to the environment before invoking configure:

	PKG_CONFIG="${QEMU_GIT_FOLDER}/gnuarmeclipse/scripts/pkg-config-dbg" \

