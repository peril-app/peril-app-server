#!/bin/bash

# alert the user that the requirements are being downloaded
echo "[build.sh] DOWNLOADING ALL REQUIREMENTS"

# requirements
apt update -y
apt install git cmake build-essential -y

# alert user that the program is building
echo "[build.sh] BUILDING OATAPP"

# oatapp
git clone https://github.com/oatpp/oatpp.git
cd oatpp/
mkdir build && cd build
cmake ..
make install

# done
echo "[build.sh] DONE"