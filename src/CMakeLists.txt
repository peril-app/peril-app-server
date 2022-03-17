project(peril-app-server)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

link_libraries(-lpthread -lsqlite3)

add_compile_definitions(_GLIBCXX_USE_CXX11_ABI=0)

cmake_minimum_required(VERSION 3.16)

add_executable(peril-app-server main.cpp)