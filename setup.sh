#!/bin/bash

apt update -y

apt install libboost-all-dev cmake -y

cmake .

cmake --build .