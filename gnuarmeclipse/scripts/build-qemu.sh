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
#

# On Ubuntu it can cross build Windows 32/64-bit setups.
#
# Prerequisites:
#
# sudo apt-get install gcc g++ git make m4 python sed tar unzip wget
# sudo apt-get install libtool pkg-config automake autoconf autotools-dev
# sudo apt-get install texinfo texlive bison flex doxygen
# sudo apt-get install nsis dos2unix
#
# MinGW-W64 prerequisites:
# sudo apt-get install mingw-w64 mingw-w64-tools mingw-w64-i686-dev mingw-w64-x86-64-dev
#

# On Debian x86 and x64 it generates a TGZ that expands
# in "/opt/gnuarmeclipse/qemu/version".
#
# Prerequisites:
#
# sudo apt-get install gcc g++ git make m4 python sed tar unzip
# sudo apt-get libtool automake autoconf pkgconfig wget autotools-dev
# sudo apt-get install texinfo texlive bison flex doxygen
#

BEGIN_SEC=$(date +%s)

DISTRO_NAME=""
UNAME="$(uname)"
if [ "${UNAME}" == "Darwin" ]
then
  DISTRO_BITS="64"
  DISTRO_MACHINE="x86_64"
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

  if [ -z "${DISTRO_NAME}" ]
  then
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
  elif [ "$1" == "-win32" ]
  then
    TARGET_GENERIC="win"
    TARGET_BITS="32"
  elif [ "$1" == "-win64" ]
  then
    TARGET_GENERIC="win"
    TARGET_BITS="64"
  elif [ "$1" == "--help" ]
  then
    echo "Build GNU ARM Eclipse QEMU distributions."
    echo "Usage:"
    echo "\tbash build-qemu.sh [-win32|-win64] [clean|pull|checkput-dev|checkout-stable]"
    echo
    exit 1
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

  # Decide which cross toolchain to use.
  if [ ${TARGET_BITS} == "32" ]
  then
    CROSS_COMPILE_PREFIX="i686-w64-mingw32"
  elif [ ${TARGET_BITS} == "64" ]
  then
    CROSS_COMPILE_PREFIX="x86_64-w64-mingw32"
  else
    exit 1
  fi

  MAKE_JOBS=${MAKE_JOBS:-"-j4"}
  QEMU_TARGET_LONG="${TARGET_GENERIC}${TARGET_BITS}"

fi

PKG_CONFIG_PATH=${PKG_CONFIG_PATH:-""}
PKG_CONFIG_LIBDIR=${PKG_CONFIG_LIBDIR:-""}

# ----- Local variables -----

QEMU_GIT_FOLDER="${QEMU_WORK_FOLDER}/gnuarmeclipse-qemu.git"
QEMU_PATCHES_FOLDER="${QEMU_GIT_FOLDER}/gnuarmeclipse/patches"
QEMU_DOWNLOAD_FOLDER="${QEMU_WORK_FOLDER}/download"
QEMU_BUILD_FOLDER="${QEMU_WORK_FOLDER}/build/${QEMU_TARGET_LONG}"
QEMU_INSTALL_FOLDER="${QEMU_WORK_FOLDER}/install/${QEMU_TARGET_LONG}"
QEMU_OUTPUT="${QEMU_WORK_FOLDER}/output"

WGET="wget"
WGET_OUT="-O"

# ----- Process clean -----

if [ "${ACTION_CLEAN}" == "clean" ]
then
  # Remove most build and temporary folders
  echo
  echo "Remove build and install folders for target \"${QEMU_TARGET_LONG}\"..."

  rm -rf "${QEMU_BUILD_FOLDER}"
  rm -rf "${QEMU_INSTALL_FOLDER}"

  echo
  echo "Clean completed. Proceed with a regular build."
  exit 0
fi

# ----- Test if main tools are present -----

echo
echo "Validate tools..."
echo
gcc --version 2>/dev/null | egrep -e 'gcc|clang'
git --version
automake --version 2>/dev/null | grep automake
if [ "${TARGET_GENERIC}" == "win" ]
then
  ${CROSS_COMPILE_PREFIX}-gcc --version | grep gcc
  unix2dos --version 2>&1 | grep unix2dos
  echo "makensis $(makensis -VERSION)"
fi

echo
echo "Build on ${UNAME} for target \"${QEMU_TARGET_LONG}\"."


# ----- Global exports -----

export LC_ALL="C"
export CONFIG_SHELL="/bin/bash"


# ----- Process git actions -----

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

# ----- Build the Zlib library -----

# The Zlib library is available from
#   http://www.zlib.net
# with source files ready to download from SourceForge
#   https://sourceforge.net/projects/libpng/files/zlib

ZLIB_VERSION="1.2.8"
ZLIB_FOLDER="zlib-${ZLIB_VERSION}"
ZLIB_ARCHIVE="${ZLIB_FOLDER}.tar.gz"
ZLIB_DOWNLOAD_URL="http://sourceforge.net/projects/libpng/files/\
zlib/${ZLIB_VERSION}/${ZLIB_ARCHIVE}"

if [ ! -f "${QEMU_DOWNLOAD_FOLDER}/${ZLIB_ARCHIVE}" ]
then
  mkdir -p "${QEMU_DOWNLOAD_FOLDER}"

  cd "${QEMU_DOWNLOAD_FOLDER}"
  "${WGET}" "${ZLIB_DOWNLOAD_URL}" "${WGET_OUT}" "${ZLIB_ARCHIVE}"
fi

# Build and install the Zlib library.
if [ ! \( -d "${QEMU_BUILD_FOLDER}/${ZLIB_FOLDER}" \) -o \
     ! \( -f "${QEMU_INSTALL_FOLDER}/lib/libz.a" -o \
          -f "${QEMU_INSTALL_FOLDER}/lib64/libz.a" \) ]
then
  # Clean build folder.
  rm -rf "${QEMU_BUILD_FOLDER}/${ZLIB_FOLDER}"

  # Prepare install folder.
  mkdir -p "${QEMU_INSTALL_FOLDER}"

  # Unpack locally.
  cd "${QEMU_BUILD_FOLDER}"
  tar -xzf "${QEMU_DOWNLOAD_FOLDER}/${ZLIB_ARCHIVE}"

  if [ "${TARGET_GENERIC}" == "win" ]
  then

    # See https://aur.archlinux.org/packages/mingw-w64-zlib/
    cd "${QEMU_BUILD_FOLDER}/${ZLIB_FOLDER}"
    sed -ie "s/dllwrap/${CROSS_COMPILE_PREFIX}-dllwrap/p" win32/Makefile.gcc

    echo
    echo "make ${ZLIB_FOLDER}..."

    # Build & install. Definitions added inside make
    make -f win32/Makefile.gcc ${MAKE_JOBS} install \
    CFLAGS="-m${TARGET_BITS} -pipe -O2 -g -Wall -Wp,-D_FORTIFY_SOURCE=2 -fexceptions --param=ssp-buffer-size=4 -Wno-implicit-function-declaration" \
    PREFIX="${CROSS_COMPILE_PREFIX}-" \
    BINARY_PATH="${QEMU_INSTALL_FOLDER}/bin" \
    INCLUDE_PATH="${QEMU_INSTALL_FOLDER}/include" \
    LIBRARY_PATH="${QEMU_INSTALL_FOLDER}/lib" \

    # Only the static version is used.
    install -m644 -t "${QEMU_INSTALL_FOLDER}/lib" libz.a
    #install -m644 -t "${QEMU_INSTALL_FOLDER}/lib" libz.dll.a

    "${CROSS_COMPILE_PREFIX}-ranlib" "${QEMU_INSTALL_FOLDER}/lib/libz.a"

  else

    # See: https://www.archlinux.org/packages/core/x86_64/zlib/

    echo
    echo "configure ${ZLIB_FOLDER}..."

    cd "${QEMU_BUILD_FOLDER}/${ZLIB_FOLDER}"

    # Configure native
    CFLAGS="-m${TARGET_BITS} -pipe" \
    \
    bash "./configure" \
      --static \
      --prefix="${QEMU_INSTALL_FOLDER}" \

    echo
    echo "make ${ZLIB_FOLDER}..."

    # Build. 'all' better be explicit.
    make ${MAKE_JOBS} all docs
    make install

  fi

  # Please note that Zlib generates a lib/pkgconfig/zlib.pc file.
fi


# ----- Build the iconv library -----

# The iconv library is available from
#   https://www.gnu.org/software/libiconv/
# with source files ready to download from
#   http://ftpmirror.gnu.org/libiconv

ICONV_VERSION="1.14"
ICONV_VERSION_RELEASE="${ICONV_VERSION}"
ICONV_FOLDER="libiconv-${ICONV_VERSION_RELEASE}"
ICONV_ARCHIVE="${ICONV_FOLDER}.tar.gz"
ICONV_DOWNLOAD_URL="http://ftpmirror.gnu.org/libiconv/${ICONV_ARCHIVE}"

if [ ! -f "${QEMU_DOWNLOAD_FOLDER}/${ICONV_ARCHIVE}" ]
then
  mkdir -p "${QEMU_DOWNLOAD_FOLDER}"

  cd "${QEMU_DOWNLOAD_FOLDER}"
  "${WGET}" "${ICONV_DOWNLOAD_URL}" "${WGET_OUT}" "${ICONV_ARCHIVE}"
fi

# Build and install the iconv library.
if [ ! \( -d "${QEMU_BUILD_FOLDER}/${ICONV_FOLDER}" \) -o \
     ! \( -f "${QEMU_INSTALL_FOLDER}/lib/libiconv.a" -o \
          -f "${QEMU_INSTALL_FOLDER}/lib64/libiconv.a" \) ]
then
  # Clean build folder.
  rm -rf "${QEMU_BUILD_FOLDER}/${ICONV_FOLDER}"

  # Prepare install folder.
  mkdir -p "${QEMU_INSTALL_FOLDER}"

  cd "${QEMU_BUILD_FOLDER}"
  tar -xzf "${QEMU_DOWNLOAD_FOLDER}/${ICONV_ARCHIVE}"

  echo
  echo "configure ${ICONV_FOLDER}..."

  if [ "${TARGET_GENERIC}" == "win" ]
  then

    # See: https://aur.archlinux.org/packages/mingw-w64-libiconv/

    ICONV_ARCH_FOLDER="mingw-w64-libiconv"
    ICONV_ARCH_VERSION_RELEASE="${ICONV_VERSION}-9"
    ICONV_ARCH_ARCHIVE="${ICONV_ARCH_FOLDER}-${ICONV_ARCH_VERSION_RELEASE}.tar.gz"

    rm -rf "${QEMU_BUILD_FOLDER}/${ICONV_ARCH_FOLDER}"
    cd "${QEMU_BUILD_FOLDER}"
    tar -xzf "${QEMU_PATCHES_FOLDER}/arch/${ICONV_ARCH_ARCHIVE}"

    cd "${QEMU_BUILD_FOLDER}/${ICONV_FOLDER}"
    if [ "${ICONV_VERSION}" == "1.14" ]
    then

      patch -p2 -i "../${ICONV_ARCH_FOLDER}/00-wchar-libiconv-1.14.patch"
      patch -p2 -i "../${ICONV_ARCH_FOLDER}/01-reloc-libiconv-1.14.patch"
      patch -p2 -i "../${ICONV_ARCH_FOLDER}/02-reloc-libiconv-1.14.patch"
      patch -p2 -i "../${ICONV_ARCH_FOLDER}/03-cygwin-libiconv-1.14.patch"
      patch -p2 -i "../${ICONV_ARCH_FOLDER}/libiconv-1.14-2-mingw.patch"

    fi

    # Configure cross
    # The bash is required to keep libtool happy, otherwise it crashes.
    # "--enable-shared" is required by later builds when shared.
    cd "${QEMU_BUILD_FOLDER}/${ICONV_FOLDER}"

    CONFIG_SHELL="/bin/bash" \
    CFLAGS="-m${TARGET_BITS}" \
    \
    bash "./configure" \
      --host="${CROSS_COMPILE_PREFIX}" \
      --program-prefix="${CROSS_COMPILE_PREFIX}" \
      \
      --prefix=${QEMU_INSTALL_FOLDER} \
      --enable-static \
      --disable-shared \
      --disable-nls \


  else

    # See: https://aur.archlinux.org/packages/libiconv/

    # Configure native
    cd "${QEMU_BUILD_FOLDER}/${ICONV_FOLDER}"

    CONFIG_SHELL="/bin/bash" \
    CFLAGS="-m${TARGET_BITS}" \
    \
    bash "./configure" \
      --prefix=${QEMU_INSTALL_FOLDER} \
      --enable-static \
      --disable-shared \
      --disable-nls \


    cp -f /usr/include/stdio.h srclib/stdio.in.h
    # There is a "cp -f /usr/include/stdio.h srclib/stdio.in.h" in arch,
    # but it is not clear if it is needed.
  fi

  echo
  echo "make ${ICONV_FOLDER}..."

  # Build. 'all' must be explicit.
  make ${MAKE_JOBS} all SHELL=/bin/bash
  make install

  # Please note that libiconv does not create pkgconfig files and needs to be
  # refered manually.

fi


# ----- Build the gettext library -----

# The gettext library is available from
#   https://www.gnu.org/software/gettext/
# with source files ready to download from
#   http://ftp.gnu.org/gnu/gettext/

GETTEXT_VERSION="0.19"
GETTEXT_VERSION_RELEASE="${GETTEXT_VERSION}.4"
GETTEXT_FOLDER="gettext-${GETTEXT_VERSION_RELEASE}"
GETTEXT_ARCHIVE="${GETTEXT_FOLDER}.tar.gz"
GETTEXT_DOWNLOAD_URL="http://ftp.gnu.org/gnu/gettext/${GETTEXT_ARCHIVE}"

if [ ! -f "${QEMU_DOWNLOAD_FOLDER}/${GETTEXT_ARCHIVE}" ]
then
  mkdir -p "${QEMU_DOWNLOAD_FOLDER}"

  cd "${QEMU_DOWNLOAD_FOLDER}"
  "${WGET}" "${GETTEXT_DOWNLOAD_URL}" "${WGET_OUT}" "${GETTEXT_ARCHIVE}"
fi

# Build and install the gettext library.
if [ ! \( -d "${QEMU_BUILD_FOLDER}/${GETTEXT_FOLDER}" \) -o \
     ! \( -f "${QEMU_INSTALL_FOLDER}/lib/libasprintf.a" -o \
          -f "${QEMU_INSTALL_FOLDER}/lib64/libasprintf.a" \) ]
then
  # Clean build folder.
  rm -rf "${QEMU_BUILD_FOLDER}/${GETTEXT_FOLDER}"

  # Prepare install folder.
  mkdir -p "${QEMU_INSTALL_FOLDER}"

  cd "${QEMU_BUILD_FOLDER}"
  tar -xzf "${QEMU_DOWNLOAD_FOLDER}/${GETTEXT_ARCHIVE}"

  echo
  echo "configure ${GETTEXT_FOLDER}/gettext-runtime..."

  if [ "${TARGET_GENERIC}" == "win" ]
  then

    # See: https://aur.archlinux.org/packages/mingw-w64-gettext/

    # Configure cross
    cd "${QEMU_BUILD_FOLDER}/${GETTEXT_FOLDER}/gettext-runtime"

    CONFIG_SHELL="/bin/bash" \
    CFLAGS="-m${TARGET_BITS} -I${QEMU_INSTALL_FOLDER}/include" \
    LDFLAGS="-L${QEMU_INSTALL_FOLDER}/lib" \
    \
    bash "./configure" \
      --host="${CROSS_COMPILE_PREFIX}" \
      --enable-threads=win32 \
      \
      --prefix="${QEMU_INSTALL_FOLDER}" \
      --disable-java \
      --disable-native-java \
      --disable-csharp \
      --without-emacs \
      --enable-static \
      --disable-shared \
      --disable-libtool-lock \

  else

    # See: https://www.archlinux.org/packages/core/x86_64/gettext/

    # Configure native
    cd "${QEMU_BUILD_FOLDER}/${GETTEXT_FOLDER}/gettext-runtime"

    CONFIG_SHELL="/bin/bash" \
    CFLAGS="-m${TARGET_BITS} -I${QEMU_INSTALL_FOLDER}/include" \
    LDFLAGS="-L${QEMU_INSTALL_FOLDER}/lib" \
    \
    bash "./configure" \
      --prefix="${QEMU_INSTALL_FOLDER}" \
      --disable-java \
      --disable-native-java \
      --disable-csharp \
      --without-emacs \
      --enable-static \
      --disable-shared \
      --disable-libtool-lock \

  fi

  echo
  echo "make ${GETTEXT_FOLDER}..."

  # Build
  make ${MAKE_JOBS}
  make install

  # Please note that gettext does not create pkgconfig files and needs to be
  # refered manually.

fi


# ----- Build the libffi library -----

LIBFFI_VERSION="3.2.1"
LIBFFI_FOLDER="libffi-${LIBFFI_VERSION}"
LIBFFI_ARCHIVE="${LIBFFI_FOLDER}.tar.gz"
LIBFFI_DOWNLOAD_URL="ftp://sourceware.org/pub/\
libffi/${LIBFFI_ARCHIVE}"

if [ ! -f "${QEMU_DOWNLOAD_FOLDER}/${LIBFFI_ARCHIVE}" ]
then
  mkdir -p "${QEMU_DOWNLOAD_FOLDER}"

  cd "${QEMU_DOWNLOAD_FOLDER}"
  "${WGET}" "${LIBFFI_DOWNLOAD_URL}" "${WGET_OUT}" "${LIBFFI_ARCHIVE}"
fi

# Build and install the new Zlib library.
if [ ! \( -d "${QEMU_BUILD_FOLDER}/${LIBFFI_FOLDER}" \) -o \
     ! \( -f "${QEMU_INSTALL_FOLDER}/lib/libffi.a" -o \
          -f "${QEMU_INSTALL_FOLDER}/lib64/libffi.a" \) ]
then
  # Clean build folder.
  rm -rf "${QEMU_BUILD_FOLDER}/${LIBFFI_FOLDER}"

  # Prepare install folder.
  mkdir -p "${QEMU_INSTALL_FOLDER}"

  # Unpack locally.
  cd "${QEMU_BUILD_FOLDER}"
  tar -xzf "${QEMU_DOWNLOAD_FOLDER}/${LIBFFI_ARCHIVE}"

  if [ "${TARGET_GENERIC}" == "win" ]
  then

    # See https://aur.archlinux.org/packages/mingw-w64-libffi/

    echo
    echo "configure ${LIBFFI_FOLDER}..."

    cd "${QEMU_BUILD_FOLDER}/${LIBFFI_FOLDER}"
    # Configure cross
    CONFIG_SHELL="/bin/bash" \
    CFLAGS="-m${TARGET_BITS} -pipe" \
    \
    bash "./configure" \
      --host="${CROSS_COMPILE_PREFIX}" \
      \
      --prefix="${QEMU_INSTALL_FOLDER}" \
      --enable-pax_emutramp \
      --enable-static \
      --disable-shared \

  else

    # See: https://www.archlinux.org/packages/core/x86_64/libffi/

    echo
    echo "configure ${LIBFFI_FOLDER}..."

    cd "${QEMU_BUILD_FOLDER}/${LIBFFI_FOLDER}"
    # Configure native
    CONFIG_SHELL="/bin/bash" \
    CFLAGS="-m${TARGET_BITS} -pipe" \
    \
    bash "./configure" \
      --prefix="${QEMU_INSTALL_FOLDER}" \
      --enable-pax_emutramp \
      --enable-static \
      --disable-shared \

  fi

  echo
  echo "make ${LIBFFI_FOLDER}..."

  # Build. 'all' better be explicit.
  make ${MAKE_JOBS} all
  make install

  # Please note that LIBFFI generates a lib/pkgconfig/libffi.pc file.
fi


# ----- Build the GLib library -----

# The GLib library is available from
#   https://developer.gnome.org/glib/
# with source files ready to download from
#   http://ftp.gnome.org/pub/GNOME/sources/glib/

GLIB_VERSION="2.42"
GLIB_VERSION_RELEASE="${GLIB_VERSION}.2"
GLIB_FOLDER="glib-${GLIB_VERSION_RELEASE}"
GLIB_ARCHIVE="${GLIB_FOLDER}.tar.xz"
GLIB_DOWNLOAD_URL="http://ftp.gnome.org/pub/GNOME/sources/glib/\
${GLIB_VERSION}/${GLIB_ARCHIVE}"

if [ ! -f "${QEMU_DOWNLOAD_FOLDER}/${GLIB_ARCHIVE}" ]
then
  mkdir -p "${QEMU_DOWNLOAD_FOLDER}"

  cd "${QEMU_DOWNLOAD_FOLDER}"
  "${WGET}" "${GLIB_DOWNLOAD_URL}" "${WGET_OUT}" "${GLIB_ARCHIVE}"
fi

# Build and install the GLib library.
if [ ! \( -d "${QEMU_BUILD_FOLDER}/${GLIB_FOLDER}" \) -o \
     ! \( -f "${QEMU_INSTALL_FOLDER}/lib/libglib-2.0.a" -o \
          -f "${QEMU_INSTALL_FOLDER}/lib64/libglib-2.0.a" \) ]
then

  # See: https://aur.archlinux.org/packages/mingw-w64-glib2/

  # Clean build folder.
  rm -rf "${QEMU_BUILD_FOLDER}/${GLIB_FOLDER}"

  # Prepare install folder.
  mkdir -p "${QEMU_INSTALL_FOLDER}"

  cd "${QEMU_BUILD_FOLDER}"
  tar -xJf "${QEMU_DOWNLOAD_FOLDER}/${GLIB_ARCHIVE}"

  echo
  echo "configure ${GLIB_FOLDER}..."

  if [ "${TARGET_GENERIC}" == "win" ]
  then

    GLIB_ARCH_FOLDER="mingw-w64-glib2"
    GLIB_ARCH_VERSION_RELEASE="${GLIB_VERSION_RELEASE}-1"
    GLIB_ARCH_ARCHIVE="${GLIB_ARCH_FOLDER}-${GLIB_ARCH_VERSION_RELEASE}.tar.gz"

    rm -rf "${QEMU_BUILD_FOLDER}/${GLIB_ARCH_FOLDER}"
    cd "${QEMU_BUILD_FOLDER}"
    tar -xzf "${QEMU_PATCHES_FOLDER}/arch/${GLIB_ARCH_ARCHIVE}"

    cd "${QEMU_BUILD_FOLDER}/${GLIB_FOLDER}"
    if [ "${GLIB_VERSION_RELEASE}" == "2.42.2" ]
    then
      patch -Np1 -i "../${GLIB_ARCH_FOLDER}/0001-Use-CreateFile-on-Win32-to-make-sure-g_unlink-always.patch"
      patch -Np1 -i "../${GLIB_ARCH_FOLDER}/0003-g_abort.all.patch"
      patch -Np1 -i "../${GLIB_ARCH_FOLDER}/glib-prefer-constructors-over-DllMain.patch"
      patch -Np0 -i "../${GLIB_ARCH_FOLDER}/glib-send-log-messages-to-correct-stdout-and-stderr.patch"
      patch -Np1 -i "../${GLIB_ARCH_FOLDER}/0015-fix-stat.all.patch"
      patch -Np1 -i "../${GLIB_ARCH_FOLDER}/0021-use-64bit-stat-for-localfile-size-calc.all.patch"
      patch -Np1 -i "../${GLIB_ARCH_FOLDER}/0024-return-actually-written-data-in-printf.all.patch"
      patch -Np1 -i "../${GLIB_ARCH_FOLDER}/0001-gsocket-block-when-errno-says-it-will-block.patch"
      patch -Np1 -i "../${GLIB_ARCH_FOLDER}/0027-no_sys_if_nametoindex.patch"

      # Add -lole32 to the list of the refered libraries, it is required by QEMU
      patch -p0 < "${QEMU_PATCHES_FOLDER}/${GLIB_FOLDER}.patch"

      # detection of if_nametoindex fails as part of libiphlpapi.a
      sed -i "s|#undef HAVE_IF_NAMETOINDEX|#define HAVE_IF_NAMETOINDEX 1|g" config.h.in
  
      NOCONFIGURE=1 bash "./autogen.sh"

    else

      echo "Unsupported GLIB version"
      exit 1
    fi

    # Configure cross
    cd "${QEMU_BUILD_FOLDER}/${GLIB_FOLDER}"

    CONFIG_SHELL="/bin/bash" \
    CFLAGS="-m${TARGET_BITS} -I${QEMU_INSTALL_FOLDER}/include" \
    LDFLAGS="-v -L${QEMU_INSTALL_FOLDER}/lib" \
    \
    PKG_CONFIG="${QEMU_GIT_FOLDER}/gnuarmeclipse/scripts/cross-pkg-config" \
    PKG_CONFIG_PATH=\
"${QEMU_INSTALL_FOLDER}/lib/pkgconfig":\
"${QEMU_INSTALL_FOLDER}/lib64/pkgconfig" \
    \
    bash "./configure" \
      --host="${CROSS_COMPILE_PREFIX}" \
      \
      --prefix="${QEMU_INSTALL_FOLDER}" \
      --with-libiconv=gnu \
      --enable-static \
      --disable-shared \
      --disable-selinux \
      --with-pcre=internal \
      --disable-fam \

  else

    # Configure native; --with-libiconv=gnu mandatory
    cd "${QEMU_BUILD_FOLDER}/${GLIB_FOLDER}"

    CONFIG_SHELL="/bin/bash" \
    CFLAGS="-m${TARGET_BITS} -I${QEMU_INSTALL_FOLDER}/include" \
    LDFLAGS="-v -L${QEMU_INSTALL_FOLDER}/lib" \
    \
    PKG_CONFIG="${QEMU_GIT_FOLDER}/gnuarmeclipse/scripts/pkg-config-dbg" \
    PKG_CONFIG_PATH=\
"${QEMU_INSTALL_FOLDER}/lib/pkgconfig":\
"${QEMU_INSTALL_FOLDER}/lib64/pkgconfig" \
    \
    bash "./configure" \
      --prefix="${QEMU_INSTALL_FOLDER}" \
      --with-libiconv=gnu \
      --enable-static \
      --disable-shared \
      --disable-selinux \
      --with-pcre=internal \
      --disable-fam \

  fi

  echo
  echo "make ${GLIB_FOLDER}..."

  # Build
  make ${MAKE_JOBS}
  make install

  # Please note that GLIB generates a lot of lib/pkgconfig/*.pc files.

fi


# ----- Build QEMU -----

# Configure QEMU.

if [ ! -f "${QEMU_BUILD_FOLDER}/qemu/config-host.mak" ]
then

  echo
  echo "configure QEMU..."

  # All variables are passed on the command line before 'configure'.
  # Be sure all these lines end in '\' to ensure lines are concatenated.

  if [ "${TARGET_GENERIC}" == "osx" ]
  then

    # OS X target
    cd "${QEMU_BUILD_FOLDER}/qemu"

    LDFLAGS="-v" \
    \
    PKG_CONFIG="${QEMU_GIT_FOLDER}/gnuarmeclipse/scripts/pkg-config-dbg" \
    PKG_CONFIG_PATH=\
"${QEMU_INSTALL_FOLDER}/lib/pkgconfig":\
"${QEMU_INSTALL_FOLDER}/lib64/pkgconfig" \
    \
    bash "${QEMU_GIT_FOLDER}/configure" \
      --extra-cflags="-pipe -I${QEMU_INSTALL_FOLDER}/include" \
      --extra-ldflags="-v -L${QEMU_INSTALL_FOLDER}/lib" \
      --target-list="gnuarmeclipse-softmmu" \
      --prefix="${QEMU_INSTALL_FOLDER}/qemu" \
      --bindir="${QEMU_INSTALL_FOLDER}/qemu/bin" \
      --docdir="${QEMU_INSTALL_FOLDER}/qemu/doc" \
      --mandir="${QEMU_INSTALL_FOLDER}/qemu/man" \
      --without-system-pixman \

  elif [ "${TARGET_GENERIC}" == "linux" ]
  then

    # Linux target
    cd "${QEMU_BUILD_FOLDER}/qemu"

    LDFLAGS='-v -Wl,-rpath=\$$ORIGIN' \
    \
    PKG_CONFIG="${QEMU_GIT_FOLDER}/gnuarmeclipse/scripts/pkg-config-dbg" \
    PKG_CONFIG_PATH=\
"${QEMU_INSTALL_FOLDER}/lib/pkgconfig":\
"${QEMU_INSTALL_FOLDER}/lib64/pkgconfig" \
    \
    bash "${QEMU_GIT_FOLDER}/configure" \
      --extra-cflags="-pipe -I${QEMU_INSTALL_FOLDER}/include" \
      --extra-ldflags="-L${QEMU_INSTALL_FOLDER}/lib" \
      --target-list="gnuarmeclipse-softmmu" \
      --prefix="${QEMU_INSTALL_FOLDER}/qemu" \
      --bindir="${QEMU_INSTALL_FOLDER}/qemu/bin" \
      --docdir="${QEMU_INSTALL_FOLDER}/qemu/doc" \
      --mandir="${QEMU_INSTALL_FOLDER}/qemu/man" \
      --without-system-pixman \

    # Note: a very important detail here is LDFLAGS='-Wl,-rpath=\$$ORIGIN which
    # adds a special record to the ELF file asking the loader to search for the
    # libraries first in the same folder where the executable is located. The
    # task is complicated due to the multiple substitutions that are done on
    # the way, and need to be escaped.

  elif [ "${TARGET_GENERIC}" == "win" ]
  then

    # Windows target, 32/64-bit
    cd "${QEMU_BUILD_FOLDER}/qemu"

    LDFLAGS="-v -L${QEMU_INSTALL_FOLDER}/lib" \
    \
    PKG_CONFIG="${QEMU_GIT_FOLDER}/gnuarmeclipse/scripts/cross-pkg-config" \
    PKG_CONFIG_PATH=\
"${QEMU_INSTALL_FOLDER}/lib/pkgconfig":\
"${QEMU_INSTALL_FOLDER}/lib64/pkgconfig" \
    \
    bash "${QEMU_GIT_FOLDER}/configure" \
      --cross-prefix="${CROSS_COMPILE_PREFIX}-" \
      \
      --extra-cflags="-pipe -I${QEMU_INSTALL_FOLDER}/include" \
      --extra-ldflags="-L${QEMU_INSTALL_FOLDER}/lib" \
      --target-list="gnuarmeclipse-softmmu" \
      --prefix="${QEMU_INSTALL_FOLDER}/qemu" \
      --bindir="${QEMU_INSTALL_FOLDER}/qemu/bin" \
      --docdir="${QEMU_INSTALL_FOLDER}/qemu/doc" \
      --mandir="${QEMU_INSTALL_FOLDER}/qemu/man" \
      --without-system-pixman \

  fi

fi


# Do a full build, with documentation.

echo
echo "make QEMU..."
# The bindir and pkgdatadir are required to configure bin and scripts folders
# at the same level in the hierarchy.
cd "${QEMU_BUILD_FOLDER}/qemu"
make ${MAKE_JOBS} all pdf

# Always clear the destination folder, to have a consistent package.
rm -rf "${QEMU_INSTALL_FOLDER}/qemu"

# Exhaustive install, including documentation.

cd "${QEMU_BUILD_FOLDER}/qemu"
make install install-pdf

# ----- Functions ------

function do_unix2dos {

  if [ "${TARGET_GENERIC}" == "win" ]
  then
    while (($#))
    do
      unix2dos "$1"
      shift
    done
  fi
}


# ----- Post processing -----
if [ "${TARGET_GENERIC}" == "osx" ]
then

#strip "${QEMU_INSTALL_FOLDER}/lib/"*.a

strip "${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse"

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

#strip "${QEMU_INSTALL_FOLDER}/lib/"*.a

strip "${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse"

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

  ${CROSS_COMPILE_PREFIX}-strip "${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse.exe"

  echo
  echo "Copy dynamic libs..."


  function copy_gcc_dll {

    # First try Ubuntu specific locations,
    # then do a long full search.

    if [ -f "/usr/lib/gcc/${CROSS_COMPILE_PREFIX}/${CROSS_GCC_VERSION}/$1" ]
    then
      cp -v "/usr/lib/gcc/${CROSS_COMPILE_PREFIX}/${CROSS_GCC_VERSION}/$1" \
        "${QEMU_INSTALL_FOLDER}/qemu/bin"
    elif [ -f "/usr/lib/gcc/${CROSS_COMPILE_PREFIX}/${CROSS_GCC_VERSION_SHORT}/$1" ]
    then
      cp -v "/usr/lib/gcc/${CROSS_COMPILE_PREFIX}/${CROSS_GCC_VERSION_SHORT}/$1" \
        "${QEMU_INSTALL_FOLDER}/qemu/bin"
    else
      echo "Searching /usr for $1..."
      SJLJ_PATH=$(find /usr \! -readable -prune -o -name $1 -print | grep ${CROSS_COMPILE_PREFIX})
      cp -v ${SJLJ_PATH} "${QEMU_INSTALL_FOLDER}/qemu/bin"
    fi

  }

  # Identify the current cross gcc version, to locate the specific dll folder.
  CROSS_GCC_VERSION=$(${CROSS_COMPILE_PREFIX}-gcc --version | grep 'gcc' | sed -e 's/.*\s\([0-9]*\)[.]\([0-9]*\)[.]\([0-9]*\).*/\1.\2.\3/')
  CROSS_GCC_VERSION_SHORT=$(echo $CROSS_GCC_VERSION | sed -e 's/\([0-9]*\)[.]\([0-9]*\)[.]\([0-9]*\).*/\1.\2/')

  copy_gcc_dll "libgcc_s_sjlj-1.dll"
  copy_gcc_dll "libssp-0.dll"
  copy_gcc_dll "libstdc++-6.dll"

  if [ -f "/usr/${CROSS_COMPILE_PREFIX}/lib/libwinpthread-1.dll" ]
  then
    cp "/usr/${CROSS_COMPILE_PREFIX}/lib/libwinpthread-1.dll" \
      "${QEMU_INSTALL_FOLDER}/qemu/bin"
  else
    echo "Searching /usr for libwinpthread-1.dll..."
    PTHREAD_PATH=$(find /usr \! -readable -prune -o -name 'libwinpthread-1.dll' -print | grep ${CROSS_COMPILE_PREFIX})
    cp -v "${PTHREAD_PATH}" "${QEMU_INSTALL_FOLDER}/qemu/bin"
  fi

  # Update list if new libs are added.

  # Actually not referred (the static versions were used).
  # cp "${QEMU_INSTALL_FOLDER}/bin/libintl-8.dll" "${QEMU_INSTALL_FOLDER}/qemu/bin"
  # cp "${QEMU_INSTALL_FOLDER}/bin/libiconv-2.dll" "${QEMU_INSTALL_FOLDER}/qemu/bin"

  # Actually not referred (the static versions were used).
  # cp "${QEMU_INSTALL_FOLDER}/bin/libffi-6.dll" "${QEMU_INSTALL_FOLDER}/qemu/bin"
  # cp "${QEMU_INSTALL_FOLDER}/bin/libcharset-1.dll" "${QEMU_INSTALL_FOLDER}/qemu/bin"
  # cp "${QEMU_INSTALL_FOLDER}/bin/libasprintf-0.dll" "${QEMU_INSTALL_FOLDER}/qemu/bin"

  ${CROSS_COMPILE_PREFIX}-strip "${QEMU_INSTALL_FOLDER}/qemu/bin/"*.dll

  # Remove some unexpected files.
  rm -f "${QEMU_INSTALL_FOLDER}/qemu/bin/target-x86_64.conf"
  rm -f "${QEMU_INSTALL_FOLDER}/qemu/bin/trace-events"

fi

# ----- Copy the license files -----

echo
echo "Copy license files..."

function copy_info {


  for f in "$1/"*
  do
    if [ -f "$f" ]
    then
      if [[ "$f" =~ AUTHORS.*|NEWS.*|COPYING.*|README.*|LICENSE.*|FAQ.*|DEPENDENCIES.*|THANKS.* ]]
      then
        /usr/bin/install -d -m 0755 "${QEMU_INSTALL_FOLDER}/qemu/license/$2"
        /usr/bin/install -v -c -m 644 "$f" "${QEMU_INSTALL_FOLDER}/qemu/license/$2"
      fi
    fi
  done
}

copy_info "${QEMU_GIT_FOLDER}" "qemu-$(cat ${QEMU_GIT_FOLDER}/VERSION)"

copy_info "${QEMU_BUILD_FOLDER}/${ZLIB_FOLDER}" "${ZLIB_FOLDER}"
copy_info "${QEMU_BUILD_FOLDER}/${ICONV_FOLDER}" "${ICONV_FOLDER}"
copy_info "${QEMU_BUILD_FOLDER}/${GETTEXT_FOLDER}" "${GETTEXT_FOLDER}"
copy_info "${QEMU_BUILD_FOLDER}/${LIBFFI_FOLDER}" "${LIBFFI_FOLDER}"
copy_info "${QEMU_BUILD_FOLDER}/${GLIB_FOLDER}" "${GLIB_FOLDER}"

if [ "${TARGET_GENERIC}" == "win" ]
then
  # For Windows, process cr lf
  find "${QEMU_INSTALL_FOLDER}/qemu/license" -type f \
    -exec unix2dos {} \;
fi

# ----- Copy the GNU ARM Eclipse info files -----

echo
echo "Copy info files..."

/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/gnuarmeclipse/info/INFO-${TARGET_GENERIC}.txt" \
  "${QEMU_INSTALL_FOLDER}/qemu/INFO.txt"
do_unix2dos "${QEMU_INSTALL_FOLDER}/qemu/INFO.txt"

mkdir -p "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse"

/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/gnuarmeclipse/info/BUILD-${TARGET_GENERIC}.txt" \
  "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse/BUILD.txt"
do_unix2dos "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse/BUILD.txt"

/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/gnuarmeclipse/info/CHANGES.txt" \
  "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse/"
do_unix2dos "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse/CHANGES.txt"

/usr/bin/install -c -m 644 "${QEMU_GIT_FOLDER}/gnuarmeclipse/scripts/build-qemu.sh" \
  "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse/"
do_unix2dos "${QEMU_INSTALL_FOLDER}/qemu/gnuarmeclipse/build-qemu.sh"

# Remove useless files

rm -rf "${QEMU_INSTALL_FOLDER}/qemu/etc"


# ----- Create the distribution package -----

mkdir -p "${QEMU_OUTPUT}"

# The UTC date part in the name of the archive.
OUTFILE_DATE=${OUTFILE_DATE:-$(date -u +%Y%m%d%H%M)}

if [ "${QEMU_GIT_HEAD}" == "gnuarmeclipse" ]
then
  OUTFILE_VERSION=$(cat "${QEMU_GIT_FOLDER}/VERSION")-${OUTFILE_DATE}
elif [ "${QEMU_GIT_HEAD}" == "gnuarmeclipse-dev" ]
then
  OUTFILE_VERSION=$(cat "${QEMU_GIT_FOLDER}/VERSION")-${OUTFILE_DATE}-dev
fi


echo
echo "Create the distribution package ${OUTFILE_VERSION}..."
echo

if [ "${TARGET_GENERIC}" == "osx" ]
then

  QEMU_DISTRIBUTION=${QEMU_OUTPUT}/gnuarmeclipse-qemu-\
${QEMU_TARGET_LONG}-${OUTFILE_VERSION}.pkg

  INSTALL_FOLDER=${INSTALL_FOLDER:-"/Applications/GNU ARM Eclipse/QEMU"}

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

  QEMU_DISTRIBUTION=${QEMU_OUTPUT}/gnuarmeclipse-qemu-\
${QEMU_TARGET_LONG}-${OUTFILE_VERSION}-setup.exe

  # Not passed as it, used by makensis for the MUI_PAGE_LICENSE; must be DOS.
  cp "${QEMU_GIT_FOLDER}/COPYING" \
    "${QEMU_INSTALL_FOLDER}/qemu/COPYING"
  unix2dos "${QEMU_INSTALL_FOLDER}/qemu/COPYING"

  NSIS_FOLDER="${QEMU_GIT_FOLDER}/gnuarmeclipse/nsis"
  NSIS_FILE="${NSIS_FOLDER}/gnuarmeclipse-qemu.nsi"

  cd "${QEMU_BUILD_FOLDER}"
  makensis -V4 -NOCD \
    -DINSTALL_FOLDER="${QEMU_INSTALL_FOLDER}/qemu" \
    -DNSIS_FOLDER="${NSIS_FOLDER}" \
    -DOUTFILE="${QEMU_DISTRIBUTION}" \
    -DW${TARGET_BITS} \
    -DBITS=${TARGET_BITS} \
    -DVERSION=${OUTFILE_VERSION} \
    "${NSIS_FILE}"
  RESULT="$?"

  # Display some information about the created application.
  echo
  echo "DLLs:"
  ${CROSS_COMPILE_PREFIX}-objdump -x "${QEMU_INSTALL_FOLDER}/qemu/bin/qemu-system-gnuarmeclipse.exe" | grep -i 'DLL Name'

fi

echo
if [ "${RESULT}" == "0" ]
then
  echo "Build completed."
  echo "Distribution file ${QEMU_DISTRIBUTION} created."
else
  echo "Buld failed."
fi

END_SEC=$(date +%s)
DELTA_SEC=$((END_SEC-BEGIN_SEC))
if [ ${DELTA_SEC} -lt 100 ]
then
  echo "Duration: ${DELTA_SEC} seconds."
else
  DELTA_MIN=$(((DELTA_SEC+30)/60))
  echo "Duration: ${DELTA_MIN} minutes."
fi

exit ${RESULT}
