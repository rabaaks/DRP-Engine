cmake_minimum_required(VERSION 3.20)

project(DRPEngine)

set(CMAKE_CXX_STANDARD 20)

set(SDL3_DIR "${CMAKE_SOURCE_DIR}/vendor/SDL3/lib/cmake/SDL3")
find_package(SDL3 REQUIRED)

add_library(Engine STATIC)
target_include_directories(Engine PRIVATE .)
add_subdirectory(Engine)

add_executable(Runtime)
target_include_directories(Runtime PRIVATE .)
add_subdirectory(Runtime)

add_executable(Editor)
target_include_directories(Editor PRIVATE .)
add_subdirectory(Editor)
