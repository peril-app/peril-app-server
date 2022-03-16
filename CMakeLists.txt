project(peril-app-server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

link_libraries(-lpthread)

cmake_minimum_required(VERSION 3.16)

add_executable(peril-app-server main.cpp)