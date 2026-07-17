add_library(Engine STATIC)

target_sources(Engine PRIVATE
    src/Application.cpp

    src/Core/Time.cpp
)

target_include_directories(Engine PUBLIC
    include
)