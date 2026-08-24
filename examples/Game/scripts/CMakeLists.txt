cmake_minimum_required(VERSION 3.20)

project(GameScripts)

set(CMAKE_CXX_STANDARD 20)

set(ENGINE_ROOT "" CACHE PATH "Path to the DRP-Engine repo root")

# Don't also build Runtime.exe/Editor.exe as a side effect of building this project's scripts
option(ENGINE_BUILD_APPS "Build the Runtime and Editor executables" OFF)
add_subdirectory(${ENGINE_ROOT} ${CMAKE_BINARY_DIR}/engine)

add_library(GameScripts SHARED PlayerController.cpp Pickup.cpp)
set_target_properties(GameScripts PROPERTIES PREFIX "")
target_include_directories(GameScripts PRIVATE ${ENGINE_ROOT})
target_link_libraries(GameScripts PRIVATE Engine)

add_custom_command(TARGET GameScripts POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/GameScripts.scripts.json $<TARGET_FILE_DIR:GameScripts>/GameScripts.scripts.json
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:GameScripts> ${CMAKE_CURRENT_SOURCE_DIR}/..
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/GameScripts.scripts.json ${CMAKE_CURRENT_SOURCE_DIR}/..
)
