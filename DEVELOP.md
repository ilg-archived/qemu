# Development info

For active development of QEMU, the recommended environment is an 
Ubuntu 18LTS, and a simplified build script (`build-native.sh`), 
described in the the separate 
[gnu-mcu-eclipse/qemu-build](https://github.com/gnu-mcu-eclipse/qemu-build)
project.

The result of this script is an executable with the debug info preserved,
to make debug sessions possible.

## Visual Studio Code

The recommended development tool is Visual Studio Code, and for it
there are already build and debug configurations available.

Install VSC as recommended by Microsoft, and add the C/C++ extension.

## Open qemu.git

The `build-native.sh` script downloads the Git repository in a
folder like `${HOME}/Work/qemu-dev/qemu.git`.

Open the folder in VSC; it contains the project source code. The build 
is performed in the separate `build` folder, and the result is installed 
in `install`, with the executable in `install/bin`.

## Build

There are two build tasks, one to build and one to clean.
To start these tasks, use Terminal -> Run Build Task, or Ctrl+Shift+B.

The actual definitions are in `.vscode/tasks.json`. Both run the 
`build-native.sh` script.

Two more options are available:

- `--debug`, to preserve the debugging info,
- `--develop`, to use the development repository branch.

## Clean

The `clean` step removes the `build` and `install` folders.

## Edit & IntelliSense

VSC is quite convenient for editing the project source files.

For advanced browsing, the include folders are already configured
in `c_cpp_properties.json`, so all definitions should be already
available via IntelliSense.

## The emulated images

There are multiple Cortex-M test projects in the separate GitHub project 
[`gnu-mcu-eclipse/qemu-eclipse-test-projects`](https://github.com/gnu-mcu-eclipse/qemu-eclipse-test-projects.git)

The default one is `f407-disc-blink-tutorial` the STM32F4-DISCOVERY Blinky, 
as described in the 
[blinky tutorial](https://gnu-mcu-eclipse.github.io/tutorials/blinky-arm/).

```console
$ cd ${HOME}/Work
$ git clone https://github.com/gnu-mcu-eclipse/qemu-eclipse-test-projects.git qemu-eclipse-test-projects.git
```

## Debug

VSC also provides decent debugging features. The launchers are
defined in `.vscode/launch.json`.

The executable is started from `../install/bin/qemu-system-gnuarmeclipse`.

In addition to a test showing the help message, two more launchers
are defined, to start the classical STM32F4DISCOVERY blinky project
created with the GNU MCU Eclipse plug-ins.

To start the debug sessions, switch to the debug view (using the debug
json in the left bar), and select the launcher in the top combo.

There are separate launchers using LLDB (for macOS) and GDB (for Ubuntu);
both start the Debug elf from the `f407-disc-blink-tutorial` project,
described below.

## Contributing back to the project

Contributions are welcomed, preferably as GitHub pull requests.

Use the `gnuarmeclipse-dev` branch, and make your patches relative to it.



