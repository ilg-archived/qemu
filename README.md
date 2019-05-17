[![GitHub release](https://img.shields.io/github/release/gnumcueclipse/qemu.svg)](https://github.com/gnu-mcu-eclipse/qemu/releases/latest) [![Github Releases](https://img.shields.io/github/downloads/gnumcueclipse/qemu/latest/total.svg)](https://github.com/gnu-mcu-eclipse/qemu/releases/latest) [![Github All Releases](https://img.shields.io/github/downloads/gnumcueclipse/qemu/total.svg)](https://github.com/gnu-mcu-eclipse/qemu/releases/latest)

# GNU MCU Eclipse QEMU

## Rationale

The [GNU MCU Eclipse QEMU](http://gnumcueclipse.github.io/qemu) subproject 
is a fork of [QEMU](https://www.qemu.org) (an open source machine 
emulator), intended to provide support for Cortex-M emulation in GNU MCU 
Eclipse.

## Changes

Compared to the original QEMU release, there are many functional changes,
including a graphical view of the emulated boards, with animated LEDs.

## Releases

The **GNU MCU Eclipse QEMU** releases are planned to follow the original
QEMU releases, but there are no guarantees for any specific schedule.

### 2.8.0-6 (2019-05-17)

Version 2.8.0-6 20190517 is a maintenance release, to fix the bug 
affecting the graphical mode in GNU/Linux, introduced in the previous release.

### 2.8.0-5 (2019-04-24)

Version 2.8.0-5 20190424 is a maintenance release, to fix several bugs.

### 2.8.0-4 (2019-02-11)

Version v2.8.0-4-20190211 is a maintenance release, to fix a bug in the 
STM32F GPIO emulation.

### 2.8.0-3 (2018-05-23)

Version 2.8.0-3-20180523 is a maintenance release, created using the 
new build scripts.


## Install

The procedure to install **GNU MCU Eclipse QEMU** is platform 
specific, but relatively straight forward (a .zip archive on Windows, 
a compressed tar archive on macOS and GNU/Linux).

A portable method is to use [`xpm`](https://www.npmjs.com/package/xpm):

```console
$ xpm install --global @gnu-mcu-eclipse/qemu
```

More details are available on the 
[How to install the QEMU binaries?](https://gnu-mcu-eclipse.github.io/qemu/install/) 
page.

## Build

The build scripts are part of the separate 
[gnu-mcu-eclipse/qemu-build](https://github.com/gnu-mcu-eclipse/qemu-build)
project.

There are separate scripts to build either a local/native version that can run
on the local machine, or multi-platform distribution builds, that can
run on most recent systems.

## Publish

The procedure used to publish the binaries is documented in the separate
[PUBLISH](PUBLISH.md) page in this project.

The metadata files used to publish the xPacks on the `npmjs.com` server 
are available from the 
[gnu-mcu-eclipse/qemu-xpack](https://github.com/gnu-mcu-eclipse/qemu-xpack)
project.

## Development

Details on the development environment are provided in the separate
[DEVELOP.md](DEVELOP.md) page in this project.

## Download analytics

* GitHub [gnu-mcu-eclipse/qemu.git](https://github.com/gnu-mcu-eclipse/qemu/)
  * latest release
[![Github All Releases](https://img.shields.io/github/downloads/gnu-mcu-eclipse/qemu/latest/total.svg)](https://github.com/gnu-mcu-eclipse/qemu/releases/)
  * all releases [![Github All Releases](https://img.shields.io/github/downloads/gnu-mcu-eclipse/qemu/total.svg)](https://github.com/gnu-mcu-eclipse/qemu/releases/)
* xPack [@gnu-mcu-eclipse/qemu](https://github.com/gnu-mcu-eclipse/qemu-xpack/)
  * latest release, per month 
[![npm (scoped)](https://img.shields.io/npm/v/@gnu-mcu-eclipse/qemu.svg)](https://www.npmjs.com/package/@gnu-mcu-eclipse/qemu/)
[![npm](https://img.shields.io/npm/dm/@gnu-mcu-eclipse/qemu.svg)](https://www.npmjs.com/package/@gnu-mcu-eclipse/qemu/)
  * all releases [![npm](https://img.shields.io/npm/dt/@gnu-mcu-eclipse/qemu.svg)](https://www.npmjs.com/package/@gnu-mcu-eclipse/qemu/)
* [individual file counters](https://www.somsubhra.com/github-release-stats/?username=gnu-mcu-eclipse&repository=qemu) (grouped per release)
  
Credit to [Shields IO](https://shields.io) and [Somsubhra/github-release-stats](https://github.com/Somsubhra/github-release-stats).