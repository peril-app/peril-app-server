cmake_minimum_required(VERSION 3.1)

project(peril_app_server)

set(CMAKE_CXX_STANDARD 17)

find_package(oatpp 1.3.0 REQUIRED)
find_package(oatpp-swagger 1.3.0 REQUIRED)
find_package(oatpp-sqlite 1.3.0 REQUIRED)

add_executable(peril_app_server.o Main.cpp)