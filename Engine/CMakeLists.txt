target_sources(Engine PRIVATE
    Core/Application.cpp
    Core/Time.cpp

    Graphics/Image.cpp
    Graphics/SoftwareRenderer.cpp
    Graphics/SoftwareTexture.cpp

    Window/SDLWindow.cpp
)

target_link_libraries(Engine PUBLIC SDL3::SDL3)