#!/bin/bash

sudo apt-get remove --purge --auto-remove cmake
mkdir temp
cd temp/
wget https://github.com/Kitware/CMake/releases/download/v3.15.2/cmake-3.15.2.tar.gz
tar xzvf cmake-3.15.2.tar.gz
cd cmake-3.15.2/
./bootstrap
sudo make -j4 install
rm -rf temp