target_sources(Engine PRIVATE
    Core/Application.cpp
    Core/Time.cpp

    Graphics/Camera.cpp
    Graphics/Image.cpp
    Graphics/SoftwareRenderer.cpp
    Graphics/SoftwareTexture.cpp

    Math/Vector.cpp

    Window/SDLWindow.cpp
)

# target_include_directories(Engine PUBLIC
#     include
#     include/Core
#     include/Graphics
#     include/Math
#     include/Window
# )

target_link_libraries(Engine PUBLIC SDL3::SDL3)