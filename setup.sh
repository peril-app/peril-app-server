#!/bin/bash

apt update -y

apt install \
libboost-atomic1.67-dev \
libboost-chrono1.67-dev \
libboost-container1.67-dev \
libboost-context1.67-dev \
libboost-coroutine1.67-dev \
libboost-date-time1.67-dev \
libboost-exception1.67-dev \
libboost-fiber1.67-dev \
libboost-filesystem1.67-dev \
libboost-graph-parallel1.67-dev \
libboost-graph1.67-dev \
libboost-iostreams1.67-dev \
libboost-locale1.67-dev \
libboost-log1.67-dev \
libboost-math1.67-dev \
libboost-mpi-python1.67-dev \
libboost-mpi1.67-dev \
libboost-numpy1.67-dev \
libboost-program-options1.67-dev \
libboost-python1.67-dev \
libboost-random1.67-dev \
libboost-regex1.67-dev \
libboost-serialization1.67-dev \
libboost-signals1.67-dev \
libboost-stacktrace1.67-dev \
libboost-system1.67-dev \
libboost-test1.67-dev \
libboost-thread1.67-dev \
libboost-timer1.67-dev \
libboost-type-erasure1.67-dev \
libboost-wave1.67-dev \
libboost1.67-dev \
libboost1.67-tools-dev \
libboost-mpi-python1.67.0 \
-y

apt install libboost-all-dev cmake -y

cmake .

cmake --build .