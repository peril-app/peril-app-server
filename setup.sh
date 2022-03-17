#!/bin/bash

echo "[WARNING] THIS IS FOR TESTING ONLY!"

apt update -y

apt install cmake wget libsqlite3-dev clang -y

wget https://github.com/CrowCpp/Crow/releases/download/v0.3%2B4/crow-v0.3+4.deb

apt install ./crow-v0.3+4.deb -y

cd src

cmake .

cmake --build .