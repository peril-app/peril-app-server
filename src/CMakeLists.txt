cmake_minimum_required(VERSION 3.1)

project(peril_app_server)

set(CMAKE_CXX_STANDARD 17)

add_executable(peril_app_server_exe Main.cpp)

find_package(oatpp 1.3.0 REQUIRED)
find_package(oatpp-swagger 1.3.0 REQUIRED)
find_package(oatpp-sqlite 1.3.0 REQUIRED)

target_link_libraries(peril_app_server_libs
    PUBLIC oatpp::oatpp
    PUBLIC oatpp::oatpp-swagger
    PUBLIC oatpp::oatpp-sqlite
)

set_target_properties(peril_app_server_libs PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(peril_app_server_exe peril_app_server_libs)