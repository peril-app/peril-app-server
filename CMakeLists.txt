project(peril-app-server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

cmake_minimum_required(VERSION 3.16)

add_subdirectory(lib)

add_executable(peril-app-server main.cpp)