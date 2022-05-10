cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(IpPrint VERSION ${PROJECT_VERSION})

add_executable(ip_print
                main.cpp
                ip_print.h)

set_target_properties(ip_print
                        PROPERTIES
                        CXX_STANDARD 14
                        CXX_STANDARD_REQUIRED ON)