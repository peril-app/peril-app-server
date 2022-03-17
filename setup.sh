#!/bin/bash

echo "[WARNING] THIS IS FOR TESTING ONLY!"

apt update -y

apt install cmake wget -y

wget https://github.com/CrowCpp/Crow/releases/download/v0.3%2B4/crow-v0.3+4.deb

apt install ./crow-v0.3+4.deb -y

cmake ./src

cmake --build ./src