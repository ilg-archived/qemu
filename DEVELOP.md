# Development info

## Prerequisites

For active development of QEMU, the supported environments are macOS and 
Ubuntu 18 LTS.

To create these environments, use the scripts provided in the separate
[xpack/xpack-build-box](https://github.com/xpack/xpack-build-box) project.

XBB, or _The xPack Build Box_ is a project intended to provide 
build environments for the [xPack](https://github.com/xpack) tools.

### macOS

The macOS XBB is a Homebrew instance installed in a 
custom folder (`${HOME}/opt/homebrew/xbb`).

To install it, please read the separate
[The macOS XBB](https://github.com/xpack/xpack-build-box/tree/master/macos) 
page.

The current macOS XBB is based on macOS 10.13. If you manage to build
it on a more recent macOS, please contribute back the changes to the script.

### Ubuntu

The Ubuntu XBB is currently a dedicated Ubuntu Desktop 18 LTS 64-bit virtual 
machine running on VirtualBox. It obviously can run on any virtualisation
platform, or even be a physical machine. However, for consistent and 
reproducible results, it is recommended to do not install other packages.

To install it, please read the separate
[The Ubuntu XBB](https://github.com/xpack/xpack-build-box/tree/master/ubuntu) 
page.

### Windows

There is currently no functional development environment for Windows.

The QEMU build scripts use mingw-w64 and POSIX tools, so building with
the legacy Microsoft tools alone might not be realistic.

There are good chances that the new 
[Windows Subsystem for Linux ](https://docs.microsoft.com/en-us/windows/wsl/install-win10)
might be used, but this was not yet tested. If you manage to install
Ubuntu packages on WSL and pass the build, please contribute back the 
changes to the scripts.

A second choice would be [MSYS2](https://www.msys2.org), but neither it
was yet tested. 

The venerable Cygwin might also be considered, but generally it is no longer
recommended for new designs.

### Visual Studio Code

The recommended development tool is Visual Studio Code, and for it
there are already build tasks and debug launchers available.

Install VSC as recommended by Microsoft, and add the C/C++ extension.

Obviously any other editor can be used, but you'll need to recreate 
the details of the configuration. Probably a good strategy would be
to first use VSC to get a functional environment, and later migrate
it to your favourite tools.

### Git client

Since SourceTree is not available for GNU/Linux, the second choice is
Git Kraken, which can be downloaded for free from 
[gitkraken.com](https://www.gitkraken.com/download).

This is an optional step and your selection is not relevant for this
project, any other Git client is perfectly ok, even the command line one.

Amongst the alternate solutions are:

- [ungit](https://www.npmjs.com/package/ungit), the easiest way to use git. 
  On any platform, since it runs in a browser; available as a `npm` module
- [Fork](https://git-fork.com), a fast and friendly git client for Mac 
  and Windows 
- etc

## How to use

### Download the build scripts

The build scripts are available from the separate
[gnu-mcu-eclipse/qemu-build](https://github.com/gnu-mcu-eclipse/qemu-build) 
project.

To download it, run the following command, which will clone the repository,
including the submodules:

```console
$ curl -L https://github.com/gnu-mcu-eclipse/qemu-build/raw/master/scripts/git-clone.sh | bash
```

### Initial build

To build a binary which is suitable for debug sessions, run the 
`build-native.sh` script with the shown options:

```console
$ bash ~/Downloads/qemu-build.git/scripts/build-native.sh --debug --develop
```

The result is the `${HOME}/Work/qemu-dev/` folder. The build 
is performed in the separate `build` folder, and the result is installed 
in `install`, with the executable in `install/bin`.

### Open qemu.git

The `build-native.sh` script clones the QEMU Git repository in a
folder like `${HOME}/Work/qemu-dev/qemu.git`.

Open this folder in VSC; it contains the project source code.

If you used the `--develop` option, the development branch is checked out.

### VSC build tasks

There are two build tasks, one to build and one to clean.
To start these tasks, use **Terminal** -> **Run Build Task**, or 
**Ctrl+Shift+B**, adn select the desired task.

The actual task definitions are in `.vscode/tasks.json`. Both tasks run the 
`build-native.sh` script, with different options.

The build options are:

- `--debug`, to preserve the debugging info,
- `--develop`, to use the development repository branch.

### Clean

The `clean` task removes the `build/qemu` and `install/qemu` folders, in 
preparation for a new build.

The operation can also be performed manually:

```console
$ bash ~/Downloads/qemu-build.git/scripts/build-native.sh clean
```

To remove the library folders, use:

```console
$ bash ~/Downloads/qemu-build.git/scripts/build-native.sh cleanlibs
```

To remove all:

```console
$ bash ~/Downloads/qemu-build.git/scripts/build-native.sh cleanall
```

### Edit & IntelliSense

VSC is quite convenient for editing the project source files.

For advanced browsing, the include folders are already configured
in `c_cpp_properties.json`, so all definitions should be already
available via IntelliSense.

### The emulated images

There are multiple Cortex-M test projects in the separate GitHub project 
[`gnu-mcu-eclipse/qemu-eclipse-test-projects`](https://github.com/gnu-mcu-eclipse/qemu-eclipse-test-projects.git)

The default one is `f407-disc-blink-tutorial`, the STM32F4-DISCOVERY Blinky, 
as described in the 
[blinky tutorial](https://gnu-mcu-eclipse.github.io/tutorials/blinky-arm/).

Clone the repository in the same `Work` folder:

```console
$ cd ${HOME}/Work
$ git clone https://github.com/gnu-mcu-eclipse/qemu-eclipse-test-projects.git qemu-eclipse-test-projects.git
```

### Debug

VSC also provides decent debugging features. The launchers are
defined in `.vscode/launch.json`.

The executable is started from `${env:HOME}/Work/qemu-dev/${platform}-${arch}/install/qemu//bin/qemu-system-gnuarmeclipse`.

In addition to a test showing the help message, two more launchers
are defined, to start the classical STM32F4DISCOVERY blinky project
created with the GNU MCU Eclipse plug-ins.

To start the debug sessions, switch to the debug view (using the debug
icon in the left bar), and select the launcher in the top combo.

There are separate launchers using LLDB (for macOS) and GDB (for Ubuntu);
both start the Debug elf from the `f407-disc-blink-tutorial` project,
described above.

## Contributing back to the project

Contributions are welcomed, preferably as GitHub pull requests.

For this, the workflow is:

- fork the [gnu-mcu-eclipse/qemu](https://github.com/gnu-mcu-eclipse/qemu) 
project
- clone it to a place of your choice
- create a new branch based on the `gnuarmeclipse-dev` branch
- link the fork folder to `${HOME}/Work/qemu-dev/` instead of the 
  existing `qemu.git` folder
- edit-compile-debug until ready
- commit & push the changes, and mark them as pull requests
