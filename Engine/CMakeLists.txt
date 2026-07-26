add_library(Engine STATIC)

target_sources(Engine PRIVATE
    src/Core/Application.cpp
    src/Core/Time.cpp

    src/Graphics/Camera.cpp
    src/Graphics/Image.cpp
    src/Graphics/SoftwareRenderer.cpp
    src/Graphics/SoftwareTexture.cpp

    src/Math/Vector.cpp

    src/Window/SDLWindow.cpp
)

target_include_directories(Engine PUBLIC
    include
    include/Core
    include/Graphics
    include/Math
    include/Window
)

target_link_libraries(Engine PUBLIC SDL3::SDL3)