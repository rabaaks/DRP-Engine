cmake_minimum_required(VERSION 3.20)

project(DRPEngine)

set(CMAKE_CXX_STANDARD 20)

set(SDL3_DIR "${CMAKE_SOURCE_DIR}/vendor/SDL3/lib/cmake/SDL3")
find_package(SDL3 REQUIRED)

add_subdirectory(Engine)
add_subdirectory(Sandbox)