#!/bin/bash
set -euo pipefail
IFS=$'\n\t'

# Script to build GNU ARM Eclipse QEMU.

# On OS X it produces an install package that expands
# in "/Applications/GNU ARM Eclipse/QEMU/version".
#
# OS X prerequisites:
#
# MacPorts with the following ports installed:
#
# sudo port install libtool automake autoconf pkgconfig wget
# sudo port install texinfo texlive

# On Debian it produces a TGZ that expands
# in "/opt/gnuarmeclipse/qemu/version".
#
# GNU/Linux Prerequisites:
#
# sudo apt-get install git g++
# sudo apt-get install texinfo texlive
# sudo apt-get install libglib2.0-dev libpixman-1-dev
# sudo apt-get install zlib1g-dev libtool

# TODO: check if complete

DISTRO_NAME=""
UNAME="$(uname)"
if [ "${UNAME}" == "Darwin" ]
then
  DISTRO_BITS="64"
  TARGET_GENERIC="osx"

  # Prepare MacPorts environment.
  export PATH=/opt/local/bin:/opt/local/sbin:$PATH
  port version >/dev/null
  if [ $? != 0 ]
  then
    echo "Please install MacPorts and rerun."
    exit 1
  fi
elif [ "${UNAME}" == "Linux" ]
then
  # ----- Determine distribution name and word size -----

  set +e
  DISTRO_NAME=$(lsb_release -si | tr "[:upper:]" "[:lower:]")
  set -e

  TARGET_GENERIC="linux"

  if [ ! -z "${DISTRO_NAME}" ]
  then
    echo $(lsb_release -i)
  else
    echo "Please install the lsb core package and rerun."
    DISTRO_NAME="linux"
  fi

  if [ "$(uname -m)" == "x86_64" ]
  then
    DISTRO_BITS="64"
    DISTRO_MACHINE="x86_64"
  elif [ "$(uname -m)" == "i686" ]
  then
    DISTRO_BITS="32"
    DISTRO_MACHINE="i386"
  else
    echo "Unknown uname -m $(uname -m)"
    exit 1
  fi
else
  echo "Unknown uname ${UNAME}"
  exit 1
fi

# ----- Parse actions and command line options -----

ACTION_CLEAN=""
ACTION_GIT=""
TARGET_BITS="${DISTRO_BITS}"

while [ $# -gt 0 ]
do
  if [ "$1" == "clean" ]
  then
    ACTION_CLEAN="$1"
  elif [ "$1" == "pull" ]
  then
    ACTION_GIT="$1"
  elif [ "$1" == "checkout-dev" ]
  then
    ACTION_GIT="$1"
  elif [ "$1" == "checkout-stable" ]
  then
    ACTION_GIT="$1"
  else
    echo "Unknown action/option $1"
    exit 1
  fi

  shift
done


# ----- Externally configurable variables -----

# The folder where the entire build procedure will run.
# If you prefer to build in a separate folder, define it before invoking
# the script.
QEMU_WORK_FOLDER=${QEMU_WORK_FOLDER:-""}
if [ ! -d "${QEMU_WORK_FOLDER}" ]
then
  if [ -d "/media/psf/Home/Work" ]
  then
    QEMU_WORK_FOLDER="/media/psf/Home/Work/qemu"
  elif [ -d "/media/${USER}/Work" ]
  then
    QEMU_WORK_FOLDER="/media/${USER}/Work/qemu"
  elif [ -d /media/Work ]
  then
    QEMU_WORK_FOLDER="/media/Work/qemu"
  else
    QEMU_WORK_FOLDER="${HOME}/Work/qemu"
  fi
fi

# Create the work folder.
mkdir -p "${QEMU_WORK_FOLDER}"

if [ "${TARGET_GENERIC}" == "osx" ]
then
  # The folder where QEMU will be installed.
  INSTALL_FOLDER=${INSTALL_FOLDER:-"/Applications/GNU ARM Eclipse/QEMU"}
  DYLD_LIBRARY_PATH=${DYLD_LIBRARY_PATH:-""}
  MAKE_JOBS=${MAKE_JOBS:-"-j8"}

  QEMU_TARGET_LONG="osx"
elif [ "${TARGET_GENERIC}" == "linux" ]
then
  LD_LIBRARY_PATH=${LD_LIBRARY_PATH:-""}
  MAKE_JOBS=${MAKE_JOBS:-"-j4"}

  QEMU_TARGET_LONG="${DISTRO_NAME}${TARGET_BITS}"
elif [ "${TARGET_GENERIC}" == "win" ]
then
  exit 1
fi

# PKG_CONFIG_PATH=${PKG_CONFIG_PATH:-""}
PKG_CONFIG_LIBDIR=${PKG_CONFIG_LIBDIR:-""}

# ----- Local variables -----

QEMU_GIT_FOLDER="${QEMU_WORK_FOLDER}/gnuarmeclipse-qemu.git"
QEMU_DOWNLOAD_FOLDER="${QEMU_WORK_FOLDER}/download"
QEMU_BUILD_FOLDER="${QEMU_WORK_FOLDER}/build/${QEMU_TARGET_LONG}"
QEMU_INSTALL_FOLDER="${QEMU_WORK_FOLDER}/install/${QEMU_TARGET_LONG}"
QEMU_OUTPUT="${QEMU_WORK_FOLDER}/output"

WGET="wget"
WGET_OUT="-O"

# ----- Test if some tools are present -----

echo
echo "Test tools..."
echo
gcc --version
git --version
automake --version

# ----- Process actions -----

if [ "${ACTION_CLEAN}" == "clean" ]
then
  # Remove most build and temporary folders
  echo
  echo "Remove most build folders..."

  rm -rf "${QEMU_BUILD_FOLDER}"
  rm -rf "${QEMU_INSTALL_FOLDER}"

  echo
  echo "Clean completed. Proceed with a regular build."
  exit 0
fi

if [ "${ACTION_GIT}" == "pull" ]
then
  if [ -d "${QEMU_GIT_FOLDER}" ]
  then
    echo
    if [ "${USER}" == "ilg" ]
    then
      echo "Enter SourceForge password for git pull"
    fi
    cd "${QEMU_GIT_FOLDER}"
    git pull
    git submodule update

    rm -rf "${QEMU_BUILD_FOLDER}/openocd"

    # Prepare autotools.
    echo
    echo "bootstrap..."

    cd "${QEMU_GIT_FOLDER}"
    ./bootstrap

    echo
    echo "Pull completed. Proceed with a regular build."
    exit 0
  else
	echo "No git folder."
    exit 1
  fi
fi


# Get the GNU ARM Eclipse QEMU git repository.

# The custom QEMU branch is available from the dedicated Git repository
# which is part of the GNU ARM Eclipse project hosted on SourceForge.
# Generally this branch follows the official QEMU master branch,
# with updates after every QEMU public release.

if [ ! -d "${QEMU_GIT_FOLDER}" ]
then
  cd "${QEMU_WORK_FOLDER}"

  if [ "${USER}" == "ilg" ]
  then
    # Shortcut for ilg, who has full access to the repo.
    echo
    echo "Enter SourceForge password for git clone"
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
  git checkout gnuarmeclipse-dev
  git submodule update

  # Prepare autotools.
  cd "${QEMU_GIT_FOLDER}"
  echo
  echo "bootstrap..."

  ./bootstrap
fi

# Get the current Git branch name, to know if we are building the stable or
# the development release.
cd "${QEMU_GIT_FOLDER}"
QEMU_GIT_HEAD=$(git symbolic-ref -q --short HEAD)


# On first run, create the build folder.
mkdir -p "${QEMU_BUILD_FOLDER}/qemu"

# Configure QEMU.

if [ ! -f "${QEMU_BUILD_FOLDER}/qemu/config-host.h" ]
then

  echo
  echo "configure..."

  # All variables below are passed on the command line before 'configure'.
  # Be sure all these lines end in '\' to ensure lines are concatenated.

if [ "${TARGET_GENERIC}" == "osx" ]
then

  cd "${QEMU_BUILD_FOLDER}/qemu"
  "${QEMU_GIT_FOLDER}/configure" \
    --extra-cflags="-DGNU_ARM_ECLIPSE=1 -pipe" \
    --target-list="gnuarmeclipse-softmmu" \
    --prefix="${QEMU_INSTALL_FOLDER}/qemu" \
    --docdir="${QEMU_INSTALL_FOLDER}/qemu/doc" \
    --mandir="${QEMU_INSTALL_FOLDER}/qemu/man"

elif [ "${TARGET_GENERIC}" == "linux" ]
then

  # Linux target
  cd "${QEMU_BUILD_FOLDER}/qemu"
  LDFLAGS='-Wl,-rpath=\$$ORIGIN' \
  "${QEMU_GIT_FOLDER}/configure" \
    --extra-cflags="-DGNU_ARM_ECLIPSE=1 -pipe" \
    --target-list="gnuarmeclipse-softmmu" \
    --prefix="${QEMU_INSTALL_FOLDER}/qemu" \
    --docdir="${QEMU_INSTALL_FOLDER}/qemu/doc" \
    --mandir="${QEMU_INSTALL_FOLDER}/qemu/man"

  # Note: a very important detail here is LDFLAGS='-Wl,-rpath=\$$ORIGIN which
  # adds a special record to the ELF file asking the loader to search for the
  # libraries first in the same folder where the executable is located. The
  # task is complicated due to the multiple substitutions that are done on
  # the way, and need to be escaped.

elif [ "${TARGET_GENERIC}" == "win" ]
then
  exit 1
fi

fi


# Do a full build, with documentation.

# The bindir and pkgdatadir are required to configure bin and scripts folders
# at the same level in the hierarchy.
cd "${QEMU_BUILD_FOLDER}/qemu"
make ${MAKE_JOBS} all pdf

# Always clear the destination folder, to have a consistent package.
rm -rf "${QEMU_INSTALL_FOLDER}/qemu"

# Exhaustive install, including documentation.

cd "${QEMU_BUILD_FOLDER}/qemu"
make install install-pdf

strip "${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse"

if [ "${TARGET_GENERIC}" == "osx" ]
then

# ----- Copy OS X dynamic libraries -----

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

elif [ "${TARGET_GENERIC}" == "linux" ]
then

# ----- Copy GNU/Linux dynamic libraries -----

# Copy the dynamic libraries to the same folder where the application file is.
ILIB=$(find /lib/${DISTRO_MACHINE}-linux-gnu /usr/lib/${DISTRO_MACHINE}-linux-gnu -type f -name 'libz.so.1.*' -print)
if [ ! -z "${ILIB}" ]
then
  /usr/bin/install -c -m 644 "${ILIB}" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin"
  (cd "${QEMU_INSTALL_FOLDER}/qemu/bin"; ln -s "$(basename ${ILIB})" "libz.so.1")
else
  echo 'WARNING: libz.so.1 not copied locally!'
fi

ILIB=$(find /lib/${DISTRO_MACHINE}-linux-gnu /usr/lib/${DISTRO_MACHINE}-linux-gnu -type f -name 'libgthread-2.0.so.0.*' -print)
if [ ! -z "${ILIB}" ]
then
  /usr/bin/install -c -m 644 "${ILIB}" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin"
  (cd "${QEMU_INSTALL_FOLDER}/qemu/bin"; ln -s "$(basename ${ILIB})" "libgthread-2.0.so.0")
else
  echo 'WARNING: libgthread-2.0.so.0 not copied locally!'
fi

ILIB=$(find /lib/${DISTRO_MACHINE}-linux-gnu /usr/lib/${DISTRO_MACHINE}-linux-gnu -type f -name 'librt.so.1.*' -print)
if [ ! -z "${ILIB}" ]
then
  /usr/bin/install -c -m 644 "${ILIB}" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin"
  (cd "${QEMU_INSTALL_FOLDER}/qemu/bin"; ln -s "$(basename ${ILIB})" "librt.so.1")
else
  echo 'WARNING: librt.so.1 not copied locally!'
fi

if [ -f "/lib/${DISTRO_MACHINE}-linux-gnu/librt.so.1" -o -L "/lib/${DISTRO_MACHINE}-linux-gnu/librt.so.1" ]
then
  /usr/bin/install -c -m 644 "/lib/${DISTRO_MACHINE}-linux-gnu/librt.so.1" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin"
  (cd "${QEMU_INSTALL_FOLDER}/qemu/bin"; ln -s "librt.so.1" "librt.so")
else
  echo 'WARNING: librt.so not copied locally!'
fi

ILIB=$(find /lib/${DISTRO_MACHINE}-linux-gnu /usr/lib/${DISTRO_MACHINE}-linux-gnu -type f -name 'libglib-2.0.so.0.*' -print)
if [ ! -z "${ILIB}" ]
then
  /usr/bin/install -c -m 644 "${ILIB}" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin"
  (cd "${QEMU_INSTALL_FOLDER}/qemu/bin"; ln -s "$(basename ${ILIB})" "libglib-2.0.so.0")
else
  echo 'WARNING: libglib-2.0.so.0 not copied locally!'
fi

ILIB=$(find /lib/${DISTRO_MACHINE}-linux-gnu /usr/lib/${DISTRO_MACHINE}-linux-gnu -type f -name 'libpixman-1.so.0.*' -print)
if [ ! -z "${ILIB}" ]
then
  /usr/bin/install -c -m 644 "${ILIB}" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin"
  (cd "${QEMU_INSTALL_FOLDER}/qemu/bin"; ln -s "$(basename ${ILIB})" "libpixman-1.so.0")
else
  echo 'WARNING: libpixman-1.so.0 not copied locally!'
fi

if [ -f "/lib/${DISTRO_MACHINE}-linux-gnu/libutil.so.1" -o -L "/lib/${DISTRO_MACHINE}-linux-gnu/libutil.so.1" ]
then
  /usr/bin/install -c -m 644 "/lib/${DISTRO_MACHINE}-linux-gnu/libutil.so.1" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin"
  (cd "${QEMU_INSTALL_FOLDER}/qemu/bin"; ln -s "libutil.so.1" "libutil.so")
else
  echo 'WARNING: libutil.so.1 not copied locally!'
fi

if [ -f "/lib/${DISTRO_MACHINE}-linux-gnu/libpthread.so.0" -o -L "/lib/${DISTRO_MACHINE}-linux-gnu/libpthread.so.0" ]
then
  /usr/bin/install -c -m 644 "/lib/${DISTRO_MACHINE}-linux-gnu/libpthread.so.0" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin"
  (cd "${QEMU_INSTALL_FOLDER}/qemu/bin"; ln -s "libpthread.so.0" "libpthread.so")
else
  echo 'WARNING: libpthread.so.0 not copied locally!'
fi

ILIB=$(find /lib/${DISTRO_MACHINE}-linux-gnu /usr/lib/${DISTRO_MACHINE}-linux-gnu -type f -name 'libpcre.so.3.*' -print)
if [ ! -z "${ILIB}" ]
then
  /usr/bin/install -c -m 644 "${ILIB}" \
  "${QEMU_INSTALL_FOLDER}/qemu/bin"
  (cd "${QEMU_INSTALL_FOLDER}/qemu/bin"; ln -s "$(basename ${ILIB})" "libpcre.so.3")
else
  echo 'WARNING: libpcre.so.3 not copied locally!'
fi

elif [ "${TARGET_GENERIC}" == "win" ]
then
  exit 1
fi

# ----- Copy the license files -----

echo
echo "copy license files..."

mkdir -p "${QEMU_INSTALL_FOLDER}/qemu/license/qemu"
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/COPYING" \
  "${QEMU_INSTALL_FOLDER}/qemu/license/qemu"
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/LICENSE" \
  "${QEMU_INSTALL_FOLDER}/qemu/license/qemu"
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/"README* \
  "${QEMU_INSTALL_FOLDER}/qemu/license/qemu"

# ----- Copy the GNU ARM Eclipse info files -----

echo
echo "copy info files..."

/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/gnuarmeclipse/info/INFO-${TARGET_GENERIC}.txt" \
  "${QEMU_INSTALL_FOLDER}/qemu/INFO.txt"
mkdir -p "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse"
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/gnuarmeclipse/info/BUILD-${TARGET_GENERIC}.txt" \
  "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse/BUILD.txt"
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/gnuarmeclipse/info/CHANGES.txt" \
  "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse/"
/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/gnuarmeclipse/scripts/build-qemu.sh" \
  "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse/"

# Remove useless files

rm -rf "${QEMU_INSTALL_FOLDER}/qemu/etc"


# ----- Create the distribution package -----

mkdir -p "${QEMU_OUTPUT}"

# The UTC date part in the name of the archive.
OUTFILE_DATE=${OUTFILE_DATE:-$(date -u +%Y%m%d%H%M)}

OUTFILE_VERSION=$(cat "${QEMU_GIT_FOLDER}/VERSION")-${OUTFILE_DATE}

echo
echo "create distribution package..."
echo

if [ "${TARGET_GENERIC}" == "osx" ]
then

  QEMU_DISTRIBUTION=${QEMU_OUTPUT}/gnuarmeclipse-qemu-\
${QEMU_TARGET_LONG}-${OUTFILE_VERSION}.pkg

  # Create the installer package, with content from the
  # ${QEMU_INSTALL_FOLDER}/qemu folder.
  # The "${INSTALL_FOLDER:1}" is a substring that skips first char.
  cd "${QEMU_WORK_FOLDER}"
  pkgbuild --identifier ilg.gnuarmeclipse.qemu \
    --root "${QEMU_INSTALL_FOLDER}/qemu" \
    --version "${OUTFILE_VERSION}" \
    --install-location "${INSTALL_FOLDER:1}/${OUTFILE_VERSION}" \
    "${QEMU_DISTRIBUTION}"

  echo
  ls -l "${QEMU_INSTALL_FOLDER}/qemu/bin"

  # Check if the application starts (if all dynamic libraries are available).
  echo
  "${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse" --version
  RESULT="$?"

elif [ "${TARGET_GENERIC}" == "linux" ]
then

  QEMU_DISTRIBUTION=${QEMU_OUTPUT}/gnuarmeclipse-qemu-\
${QEMU_TARGET_LONG}-${OUTFILE_VERSION}.tgz

  cd "${QEMU_INSTALL_FOLDER}"
  mkdir ${OUTFILE_VERSION}
  mv qemu/* ${OUTFILE_VERSION}
  mv ${OUTFILE_VERSION} qemu
  tar czf "${QEMU_DISTRIBUTION}" --owner root --group root qemu

  # Display some information about the created application.
  echo
  readelf -d "${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse"

  echo
  ls -l "${QEMU_INSTALL_FOLDER}/qemu/bin"

  # Check if the application starts (if all dynamic libraries are available).
  echo
  "${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse" --version
  RESULT="$?"

elif [ "${TARGET_GENERIC}" == "win" ]
then
  exit 1
fi

echo
if [ "${RESULT}" == "0" ]
then
  echo "Build completed."
  echo "Distribution file ${QEMU_DISTRIBUTION} created."
else
  echo "Buld failed."
fi

exit 0
