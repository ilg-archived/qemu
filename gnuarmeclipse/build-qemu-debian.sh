#!/bin/bash
set -euo pipefail
IFS=$'\n\t'

# Script to build the GNU/Linux version of QEMU on Debian.

# Prerequisites:
#
# sudo apt-get install git g++
# sudo apt-get install texinfo texlive
# sudo apt-get install libglib2.0-dev libpixman-1-dev
# sudo apt-get install zlib1g-dev libtool

# TODO: check if complete

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
INSTALL_FOLDER=${INSTALL_FOLDER:-"/opt/gnuarmeclipse"}

PKG_CONFIG_PATH=${PKG_CONFIG_PATH:-""}
DYLD_LIBRARY_PATH=${DYLD_LIBRARY_PATH:-""}

# ----- Local variables -----

QEMU_TARGET="debian64"

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

  # Add DTC module.
  cd "${QEMU_GIT_FOLDER}"
  git submodule update --init dtc

  # Change to the gnuarmeclipse branch. On subsequent runs use "git pull".
  cd "${QEMU_GIT_FOLDER}"
  git checkout gnuarmeclipse
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

# TODO: add shared libraries


# Copy the license files.
mkdir -p "${QEMU_INSTALL_FOLDER}/qemu/license/qemu"
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/COPYING" \
  "${QEMU_INSTALL_FOLDER}/qemu/license/qemu"
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/LICENSE" \
  "${QEMU_INSTALL_FOLDER}/qemu/license/qemu"
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/"README* \
  "${QEMU_INSTALL_FOLDER}/qemu/license/qemu"

# Copy the GNU ARM Eclipse info files.
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/gnuarmeclipse/INFO-linux.txt" \
  "${QEMU_INSTALL_FOLDER}/qemu/INFO.txt"
mkdir -p "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse"
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/gnuarmeclipse/BUILD-linux.txt" \
  "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse/BUILD.txt"
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/gnuarmeclipse/CHANGES.txt" \
  "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse/"
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/gnuarmeclipse/build-qemu-linux.sh" \
  "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse/"

# Remove useless files

rm -rfv "${QEMU_INSTALL_FOLDER}/qemu/etc"

# Create the distribution installer.

mkdir -p "${QEMU_OUTPUT}"

OUTFILE_VERSION=$(cat "${QEMU_GIT_FOLDER}/VERSION")
QEMU_ARCHIVE=${QEMU_WORK}/output/gnuarmeclipse-qemu-${QEMU_TARGET}-${OUTFILE_VERSION}-${NDATE}.tgz

cd "${QEMU_INSTALL_FOLDER}"
tar czf "${QEMU_ARCHIVE}" --owner root --group root qemu

# Display some information about the created application.
echo
readelf -d "${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse"

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
echo "Build failed."
fi

exit 0
