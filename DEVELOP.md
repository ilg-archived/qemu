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
folder like `${HOME}/Work/qemu-2.8.0-4-dev/qemu.git`.

Open the folder in VSC; it contains the project source code. The build 
is performed in the separate `build` folder, and the result is installed 
in `install`, with the executable in `install/bin`.

## Build

There are two build tasks, one to build and one to clean.

The actual definitions are in `.vscode/tasks.json`. Both run the 
`build-native.sh` script.

The `clean` step removes the `build` and `install` folders.

To start these steps, use Terminal -> Run Build Task, or Ctrl+Shift+B.

## Edit & IntelliSense

VSC is quite convenient for editing the project source files.

For advanced browsing, the include folders are already configured
in `c_cpp_properties.json`, so all definitions should be already
available via IntelliSense.

## Debug

VSC also provides decent debugging features. The launchers are
defined in `.vscode/launch.json`.

The executable is started from `../install/bin/qemu-system-gnuarmeclipse`.

In addition to a test showing the help message, two more launchers
are defined, to start the classical STM32F4DISCOVERY blinky project
created with the GNU MCU Eclipse plug-ins.

To start the debug sessions, switch to the debug view (using the debug
ison in the left bar), and select the launcer in the top combo.

## The emulated image

To obtain the elf image to be emulated, create the project in the
`Work` folder; be sure you select the 'Use system calls: Semihosting',
so the test will also check if arguments are passed properly.

## Contributing back to the project

Contributions are welcomed, preferably as GitHub pull requests.

Use the `gnuarmeclipse-dev` branch, and make your patches relative to it.



