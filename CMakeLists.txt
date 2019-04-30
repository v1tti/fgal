cmake_minimum_required(VERSION 3.10)
project(fgal VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install")
set(CMAKE_INSTALL_INCLUDEDIR "${CMAKE_INSTALL_PREFIX}/include")
set(CMAKE_INSTALL_LIBDIR "${CMAKE_INSTALL_PREFIX}/lib")

# types header only library

add_library(types INTERFACE)

target_include_directories(types INTERFACE
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/types/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/fgal/types)

# operations shared library

add_library(operations SHARED
    "src/operations/operations.cpp")

target_include_directories(operations PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(TARGETS operations
    EXPORT fgal-targets
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}")

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/operations/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/fgal/operations)

# export library

export(EXPORT fgal-targets
    FILE "${CMAKE_INSTALL_LIBDIR}/cmake/fgal-targets.cmake"
    NAMESPACE fgal::)
configure_file("cmake/fgal-config.cmake"
    "${CMAKE_INSTALL_LIBDIR}/cmake/fgal-config.cmake")

export(PACKAGE fgal)

#[[
install(EXPORT fgal-targets
    FILE "fgal-targets.cmake"
    NAMESPACE fgal::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake")
]]