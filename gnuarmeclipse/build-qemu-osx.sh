#!/bin/bash
set -euo pipefail
IFS=$'\n\t'

# Script to build the OS X version of QEMU. It produces an install package
# that expands in "/Applications/GNU ARM Eclipse/QEMU".

# Prerequisites:
#
# MacPorts with the following ports installed:
#
# sudo port install libtool automake autoconf pkgconfig wget
# sudo port install texinfo texlive

# TODO: check if complete

# Prepare MacPorts environment.

export PATH=/opt/local/bin:/opt/local/sbin:$PATH
port version >/dev/null
if [ $? != 0 ]
then
  echo "Mandatory MacPorts not found, quit."
  exit 1
fi

# ----- Externally configurable variables -----

# The folder where the entire build procedure will run.
# If you prefer to build in a separate folder, define it before invoking
# the script.
if [ -d /media/Work ]
then
  QEMU_WORK=${QEMU_WORK:-"/media/Work/qemu"}
else
  QEMU_WORK=${QEMU_WORK:-${HOME}/Work/qemu}
fi

# The UTC date part in the name of the archive.
NDATE=${NDATE:-$(date -u +%Y%m%d%H%M)}

# The folder where QEMU will be installed.
INSTALL_FOLDER=${INSTALL_FOLDER:-"/Applications/GNU ARM Eclipse/QEMU"}

PKG_CONFIG_PATH=${PKG_CONFIG_PATH:-""}
DYLD_LIBRARY_PATH=${DYLD_LIBRARY_PATH:-""}

# ----- Local variables -----

QEMU_TARGET="osx"

QEMU_GIT_FOLDER="${QEMU_WORK}/gnuarmeclipse-qemu.git"
QEMU_DOWNLOAD_FOLDER="${QEMU_WORK}/download"
QEMU_BUILD_FOLDER="${QEMU_WORK}/build/${QEMU_TARGET}"
QEMU_INSTALL_FOLDER="${QEMU_WORK}/install/${QEMU_TARGET}"
QEMU_OUTPUT="${QEMU_WORK}/output"

WGET="wget"
WGET_OUT="-O"

ACTION=${1:-}

if [ $# > 0 ]
then
  if [ "${ACTION}" == "clean" ]
  then
    # Remove most build and temporary folders
    rm -rfv "${QEMU_BUILD_FOLDER}"
    rm -rfv "${QEMU_INSTALL_FOLDER}"

    # exit 0
    # Continue with build
  fi
fi

# Create the work folder.
mkdir -p "${QEMU_WORK}"

# Get the GNU ARM Eclipse QEMU git repository.

# The custom QEMU branch is available from the dedicated Git repository
# which is part of the GNU ARM Eclipse project hosted on SourceForge.
# Generally this branch follows the official QEMU master branch,
# with updates after every QEMU public release.

if [ ! -d "${QEMU_GIT_FOLDER}" ]
then
  cd "${QEMU_WORK}"

  if [ "$(whoami)" == "ilg" ]
  then
    # Shortcut for ilg, who has full access to the repo.
    git clone ssh://ilg-ul@git.code.sf.net/p/gnuarmeclipse/qemu gnuarmeclipse-qemu.git
  else
    # For regular read/only access, use the git url.
    git clone http://git.code.sf.net/p/gnuarmeclipse/qemu gnuarmeclipse-qemu.git
  fi

  # Change to the gnuarmeclipse branch. On subsequent runs use "git pull".
  cd "${QEMU_GIT_FOLDER}"
  git checkout gnuarmeclipse

  # Prepare autotools.
  cd "${QEMU_GIT_FOLDER}"
  ./bootstrap
fi

# On first run, create the build folder.
mkdir -p "${QEMU_BUILD_FOLDER}/qemu"

# On subsequent runs, clear it to always force a configure.
if [ -f "${QEMU_BUILD_FOLDER}/qemu/config-host.h" ]
then
  cd "${QEMU_BUILD_FOLDER}/qemu"
  make distclean
fi

# Configure QEMU.

mkdir -p "${QEMU_BUILD_FOLDER}/qemu"

# All variables below are passed on the command line before 'configure'.
# Be sure all these lines end in '\' to ensure lines are concatenated.

cd "${QEMU_BUILD_FOLDER}/qemu"
"${QEMU_GIT_FOLDER}/configure" \
--target-list="gnuarmeclipse-softmmu" \
--prefix="${QEMU_INSTALL_FOLDER}/qemu" \
--docdir="${QEMU_INSTALL_FOLDER}/qemu/doc" \
--mandir="${QEMU_INSTALL_FOLDER}/qemu/man"

# Do a full build, with documentation.

# The bindir and pkgdatadir are required to configure bin and scripts folders
# at the same level in the hierarchy.
cd "${QEMU_BUILD_FOLDER}/qemu"
make  all pdf
strip gnuarmeclipse-softmmu/qemu-system-gnuarmeclipse

# Always clear the destination folder, to have a consistent package.
rm -rfv "${QEMU_INSTALL_FOLDER}/qemu"

# Exhaustive install, including documentation.

cd "${QEMU_BUILD_FOLDER}/qemu"
make install install-pdf

# Copy the dynamic libraries to the same folder where the application file is.
# Post-process dynamic libraries paths to be relative to executable folder.

# otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse"
install_name_tool -change "/opt/local/lib/libz.1.dylib" "@executable_path/libz.1.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse"
install_name_tool -change "/opt/local/lib/libgthread-2.0.0.dylib" "@executable_path/libgthread-2.0.0.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse"
install_name_tool -change "/opt/local/lib/libglib-2.0.0.dylib" "@executable_path/libglib-2.0.0.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse"
install_name_tool -change "/opt/local/lib/libintl.8.dylib" "@executable_path/libintl.8.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse"
install_name_tool -change "/opt/local/lib/libpixman-1.0.dylib" "@executable_path/libpixman-1.0.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse"
install_name_tool -change "/opt/local/lib/libgnutls.28.dylib" "@executable_path/libgnutls.28.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse"
install_name_tool -change "/opt/local/lib/libusb-1.0.0.dylib" "@executable_path/libusb-1.0.0.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse"
otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse"

# Different input name
ILIB=libz.1.dylib
cp "/opt/local/lib/libz.1.2.8.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
# otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -id ${ILIB} "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"

ILIB=libgthread-2.0.0.dylib
cp "/opt/local/lib/${ILIB}" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
# otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -id ${ILIB} "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -change "/opt/local/lib/libglib-2.0.0.dylib" "@executable_path/libglib-2.0.0.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -change "/opt/local/lib/libiconv.2.dylib" "@executable_path/libiconv.2.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -change "/opt/local/lib/libintl.8.dylib" "@executable_path/libintl.8.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"

ILIB=libglib-2.0.0.dylib
cp "/opt/local/lib/${ILIB}" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
# otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -id ${ILIB} "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -change "/opt/local/lib/libiconv.2.dylib" "@executable_path/libiconv.2.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -change "/opt/local/lib/libintl.8.dylib" "@executable_path/libintl.8.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"

ILIB=libintl.8.dylib
cp "/opt/local/lib/${ILIB}" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
# otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -id ${ILIB} "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -change "/opt/local/lib/libiconv.2.dylib" "@executable_path/libiconv.2.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"

ILIB=libpixman-1.0.dylib
cp "/opt/local/lib/${ILIB}" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
# otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -id ${ILIB} "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"

ILIB=libgnutls.28.dylib
cp "/opt/local/lib/${ILIB}" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
# otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -id libgnutls.28.dylib "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -change "/opt/local/lib/libz.1.dylib" "@executable_path/libz.1.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -change "/opt/local/lib/libiconv.2.dylib" "@executable_path/libiconv.2.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -change "/opt/local/lib/libp11-kit.0.dylib" "@executable_path/libp11-kit.0.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -change "/opt/local/lib/libtasn1.6.dylib" "@executable_path/libtasn1.6.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -change "/opt/local/lib/libnettle.4.dylib" "@executable_path/libnettle.4.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -change "/opt/local/lib/libhogweed.2.dylib" "@executable_path/libhogweed.2.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -change "/opt/local/lib/libgmp.10.dylib" "@executable_path/libgmp.10.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -change "/opt/local/lib/libintl.8.dylib" "@executable_path/libintl.8.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"

ILIB=libusb-1.0.0.dylib
cp "/opt/local/lib/${ILIB}" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
# otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -id libusb-1.0.0.dylib "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"

ILIB=libiconv.2.dylib
cp "/opt/local/lib/${ILIB}" "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
# otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -id "${ILIB}" "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"

ILIB=libp11-kit.0.dylib
cp "/opt/local/lib/${ILIB}" "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
# otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -id "${ILIB}" "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -change "/opt/local/lib/libffi.6.dylib" "@executable_path/libffi.6.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -change "/opt/local/lib/libintl.8.dylib" "@executable_path/libintl.8.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"

ILIB=libtasn1.6.dylib
cp "/opt/local/lib/${ILIB}" "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
# otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -id "${ILIB}" "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"

ILIB=libnettle.4.dylib
cp "/opt/local/lib/${ILIB}" "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
# otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -id "${ILIB}" "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"

ILIB=libhogweed.2.dylib
cp "/opt/local/lib/${ILIB}" "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
# otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -id "${ILIB}" "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -change "/opt/local/lib/libnettle.4.dylib" "@executable_path/libnettle.4.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -change "/opt/local/lib/libgmp.10.dylib" "@executable_path/libgmp.10.dylib" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"

ILIB=libgmp.10.dylib
cp "/opt/local/lib/${ILIB}" "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
# otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -id "${ILIB}" "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"

ILIB=libffi.6.dylib
cp "/opt/local/lib/${ILIB}" "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
# otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
install_name_tool -id "${ILIB}" "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"
otool -L "${QEMU_INSTALL_FOLDER}/qemu/bin/${ILIB}"


# Copy the license files.
mkdir -p "${QEMU_INSTALL_FOLDER}/qemu/license/qemu"
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/COPYING" \
  "${QEMU_INSTALL_FOLDER}/qemu/license/qemu"
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/LICENSE" \
  "${QEMU_INSTALL_FOLDER}/qemu/license/qemu"
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/"README* \
  "${QEMU_INSTALL_FOLDER}/qemu/license/qemu"

# Copy the GNU ARM Eclipse info files.
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/gnuarmeclipse/INFO-osx.txt" \
  "${QEMU_INSTALL_FOLDER}/qemu/INFO.txt"
mkdir -p "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse"
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/gnuarmeclipse/BUILD-osx.txt" \
  "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse/BUILD.txt"
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/gnuarmeclipse/CHANGES.txt" \
  "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse/"
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/gnuarmeclipse/build-qemu-osx.sh" \
  "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse/"

# Remove useless files

rm -rfv "${QEMU_INSTALL_FOLDER}/qemu/etc"

# Create the distribution installer.

mkdir -p "${QEMU_OUTPUT}"

OUTFILE_VERSION=$(cat "${QEMU_GIT_FOLDER}/VERSION")
QEMU_INSTALLER=${QEMU_WORK}/output/gnuarmeclipse-qemu-${QEMU_TARGET}-${OUTFILE_VERSION}-${NDATE}.pkg

# Create the installer package, with content from the
# ${QEMU_INSTALL_FOLDER}/qemu folder.
# The "${INSTALL_FOLDER:1}" is a substring that skips first char.
cd "${QEMU_WORK}"
echo
pkgbuild --identifier ilg.gnuarmeclipse.qemu \
--root "${QEMU_INSTALL_FOLDER}/qemu" \
--version "${OUTFILE_VERSION}" \
--install-location "${INSTALL_FOLDER:1}" \
"${QEMU_INSTALLER}"

echo
ls -l "${QEMU_INSTALL_FOLDER}/qemu/bin"

# Check if the application starts (if all dynamic libraries are available).
echo
"${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse" --version
RESULT="$?"

echo
if [ "${RESULT}" == "0" ]
then
  echo "Build completed."
else
  echo "Buld failed."
fi

exit 0
