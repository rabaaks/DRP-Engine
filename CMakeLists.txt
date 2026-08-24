cmake_minimum_required(VERSION 3.20)

project(DRPEngine)

set(CMAKE_CXX_STANDARD 20)

option(ENGINE_BUILD_APPS "Build the Runtime and Editor executables" ON)

add_subdirectory(vendor/SDL3)
add_subdirectory(vendor/SDL3_image)

add_subdirectory(vendor/json)

add_library(Engine STATIC)
target_include_directories(Engine PRIVATE .)
add_subdirectory(Engine)

if(ENGINE_BUILD_APPS)
    add_executable(Runtime)
    target_include_directories(Runtime PRIVATE .)
    add_subdirectory(Runtime)

    add_executable(Editor)
    target_include_directories(Editor PRIVATE .)
    add_subdirectory(Editor)
endif()