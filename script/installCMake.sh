#!/bin/bash

VERSION="3.15.2"
BASE_DIR=$(pwd)
TEMP_DIR=${BASE_DIR}/temp

sudo apt-get remove --purge --auto-remove cmake
mkdir -p ${TEMP_DIR}
cd ${TEMP_DIR}
wget https://github.com/Kitware/CMake/releases/download/v${VERSION}/cmake-${VERSION}.tar.gz
tar xzvf cmake-${VERSION}.tar.gz
cd cmake-${VERSION}/
./bootstrap
sudo make -j4
sudo make install
cd ${BASE_DIR}
sudo rm -rf ${TEMP_DIR}

VERSION_DATA=$(cmake --version)
if [[ $VERSION_DATA == *${VERSION}* ]]; then
	echo "CMake Installed Successfully"
	exit 0
else
	echo "CMake Failed To Install"
	exit 1
fi