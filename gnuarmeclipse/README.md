These are additional files added to **GNU ARM Eclipse QEMU**; some of them are required by the build procedures.

## Build related folders

- **info** - informative files copied to the distributed **info** folder;
- **nsis** - files required by [NSIS (Nullsoft Scriptable Install System)](http://nsis.sourceforge.net/Main_Page);
- **patches** - small patches to correct some problems identified in the official packages;
- **pkgconfig** - configuration files missing in some of the official packages (currently empty);
- **images** - images of supported boards;
- **scripts** - the build scripts and some other support scripts.

## Other folders

- docs - files documenting various development aspects
- templates - sample files for new devices

## OS X update

On OS X 10.11 El Capitan, the images rendering with SDL_Image 1.2.12 has
some glitches. Older version 1.2.10 seems fine.
