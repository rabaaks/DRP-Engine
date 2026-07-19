add_library(Engine STATIC)

target_sources(Engine PRIVATE
    src/Core/Application.cpp
    src/Core/Time.cpp

    src/Renderer/Framebuffer.cpp
    src/Renderer/SoftwareRenderer.cpp

    src/Window/SDLWindow.cpp
)

target_include_directories(Engine PUBLIC
    include
    include/Core
    include/Renderer
    include/Window
)

target_link_libraries(Engine PUBLIC SDL3::SDL3)