#!/usr/bin/env bash

# Install a newer CMake version
curl -sSL https://cmake.org/files/v3.6/cmake-3.6.1-Linux-x86_64.sh -o install-cmake.sh
chmod +x install-cmake.sh
sudo ./install-cmake.sh --prefix=/usr/local --skip-license

