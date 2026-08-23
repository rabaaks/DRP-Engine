target_sources(Engine PRIVATE
    Assets/AssetManager.cpp
    Assets/ImageLoader.cpp
    Assets/ModelLoader.cpp
    Assets/Serialization.cpp

    Core/Input.cpp
    Core/Time.cpp

    Graphics/Image.cpp
    Graphics/SoftwareRenderer.cpp
    Graphics/SoftwareTexture.cpp

    Scene/ComponentManager.cpp
    Scene/Entity.cpp
    Scene/Scene.
    
    Scripting/DynamicLibrary.cpp

    Window/SDLWindow.cpp
)

target_link_libraries(Engine PUBLIC SDL3::SDL3 SDL3_image::SDL3_image)
target_link_libraries(Engine PUBLIC nlohmann_json::nlohmann_json)