#! /bin/bash
set -euo pipefail
IFS=$'\n\t'

NAME=orig
BITS=64
while [ $# -gt 0 ]
do
  if [ "$1" == "--stefan" ]
  then
    NAME="stefan"
  elif [ "$1" == "--orig" ]
  then
    NAME="orig"
  elif [ "$1" == "--win64" ]
  then
    BITS="64"
  elif [ "$1" == "--win32" ]
  then
    BITS="32"
  elif [ "$1" == "--help" ]
  then
    echo "* Build original QEMU for ARM *"
    echo "Usage:"
    echo "\$ bash build-orig-qemu.sh [--orig|--stefan] [--win64|--win32]"
    exit 1
  fi

  shift
done

echo
echo "Building \"${NAME}\" for ${BITS} bits."

# If docker is not installed, it should exit.
docker --version

WORK="${HOME}/Work/${NAME}-qemu"
mkdir -p "${WORK}"
cd "${WORK}"

if [ ! -d qemu.git ]
then
  if [ "${NAME}" == "orig" ]
  then
    URL="git://git.qemu.org/qemu.git"
  elif [ "${NAME}" == "stefan" ]
  then
    URL="git://repo.or.cz/qemu/ar7.git"
  fi

  echo
  echo "Cloning ${URL}"
  git clone "${URL}" qemu.git
fi

DOCKER_HOST_WORK="/root/Host/Work/${NAME}-qemu"
DOCKER_HOST_OUTPUT="${DOCKER_HOST_WORK}/output-${BITS}"
DOCKER_GIT_FOLDER="${DOCKER_HOST_WORK}/qemu.git"
DOCKER_BUILD="/root/build"

if [ "${BITS}" == "64" ]
then
  CROSS_PREFIX=x86_64-w64-mingw32
elif [ "${BITS}" == "32" ]
then
  CROSS_PREFIX=i686-w64-mingw32
else
  echo "No BITS."
  exit 1
fi

cat <<'EOF' >"${WORK}/cross-pkg-config"
#!/bin/sh -e

# Copyright (C) 2011 Stefan Weil

# This work is licensed under the terms of the GNU GPL, version 2 or later.
# See the file COPYING in the top-level directory.

# This script provides a cross pkg-config for QEMU cross compilations.
# It will use the standard pkg-config with special options for the
# cross environment which is assumed to be in /usr/{cross-prefix}.

# Installation (Debian and similar distributions):
# Simply copy or link it to /usr/bin/{cross-prefix}-pkg-config.

# Examples (Debian, Ubuntu):
# /usr/bin/amd64-mingw32msvc-pkg-config
# /usr/bin/i586-mingw32msvc-pkg-config
# /usr/bin/arm-linux-gnueabi-pkg-config
# /usr/bin/mipsel-linux-gnu-pkg-config

basename=`basename "$0"`
prefix="/usr/${basename%-pkg-config}"
export PKG_CONFIG_LIBDIR=$prefix/lib/pkgconfig
exec pkg-config --define-variable=prefix="$prefix" "$@"

EOF

# Do not quote EOF, to make substitutions here. (All, except \${f}).
cat <<EOF > "${WORK}/docker-${BITS}.sh"
mkdir -p /root/build && cd /root/build

# Copy the custom pkg-config script in the system folder
cp "${DOCKER_HOST_WORK}/cross-pkg-config" "/usr/bin/${CROSS_PREFIX}-pkg-config"
chmod +x "/usr/bin/${CROSS_PREFIX}-pkg-config"

# Remove and recreate the output folder.
rm -rf "${DOCKER_HOST_OUTPUT}"
mkdir -p "${DOCKER_HOST_OUTPUT}"

echo
echo "Configuring..."
# Configure
"${DOCKER_GIT_FOLDER}/configure" \
  --cross-prefix=${CROSS_PREFIX}- \
  --enable-trace-backend=stderr \
  --extra-cflags=-Wno-missing-format-attribute \
  --target-list="arm-softmmu" \
| tee configure-output.txt

cp configure-output.txt "${DOCKER_HOST_OUTPUT}"
cp config.log "${DOCKER_HOST_OUTPUT}"

echo
echo "Building..."
# Build.
make | tee make-output.txt
cp make-output.txt "${DOCKER_HOST_OUTPUT}"

# Create installer
make installer | tee installer-output.txt
cp installer-output.txt "${DOCKER_HOST_OUTPUT}"
cp qemu-setup-*.exe "${DOCKER_HOST_OUTPUT}"

# Since the installer is not trustworthy, also create a bin folder, and copy
# the executable and all DLLs here.
mkdir -p "${DOCKER_HOST_OUTPUT}/bin"
cp arm-softmmu/qemu-system-arm.exe "${DOCKER_HOST_OUTPUT}/bin"

echo
echo "Copying DLLs..."

# Copy GCC DLLs.
(cd /usr/lib/gcc/${CROSS_PREFIX}; for f in \$(find . -name '*.dll'); do mkdir -p \$(dirname "${DOCKER_HOST_OUTPUT}/bin/\${f}"); cp "\${f}" "${DOCKER_HOST_OUTPUT}/bin/\${f}"; done; )

# Copy a lot of library DLLs.
(cd /usr/${CROSS_PREFIX}; for f in \$(find . -name '*.dll'); do mkdir -p \$(dirname "${DOCKER_HOST_OUTPUT}/bin/\${f}"); cp "\${f}" "${DOCKER_HOST_OUTPUT}/bin/\${f}"; done; )

ls -lR "${DOCKER_HOST_OUTPUT}"

echo
echo "Docker done."

EOF


set +e
# Remove a possible previously crashed container.
docker rm -f "qemu-win-build-${NAME}" > /dev/null 2> /dev/null
set -e

# Run the newly created script in a Debian 8 x64 container.
time \
docker run \
  --name="qemu-win-build-${NAME}" \
  --tty \
  --workdir="/root" \
  --volume="${HOME}/Work:/root/Host/Work" \
  ilegeul/qemu-builds:d8-x64-mingw \
  /bin/bash "${DOCKER_HOST_WORK}/docker-${BITS}.sh"

# Remove the container.
docker rm -f "qemu-win-build-${NAME}"

echo
echo "Script done."
