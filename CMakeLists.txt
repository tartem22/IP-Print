cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(IpPrint VERSION ${PROJECT_VERSION})

add_executable(ip_print
                main.cpp
                ip_print.h)

set_target_properties(ip_print
                        PROPERTIES
                        CXX_STANDARD 17
                        CXX_STANDARD_REQUIRED ON)

if (MSVC)
    target_compile_options(ip_print PRIVATE
        /W4
)
else ()
    target_compile_options(ip_print PRIVATE
        -Wall -pedantic -Werror
    )
endif()

install(TARGETS ip_print RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)