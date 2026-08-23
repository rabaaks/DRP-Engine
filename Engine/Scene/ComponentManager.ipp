#include <Engine/Scene/ComponentManager.hpp>

namespace Engine
{
    template <typename T>
    void ComponentManager::AddComponent(const std::string& name)
    {
        componentTypes[name] =
        ComponentInfo
        {
            []() -> std::shared_ptr<void> {return std::make_shared<T>();},
            [](void* component) -> nlohmann::json {return nlohmann::json(*static_cast<T*>(component));},
            [](void* component, const nlohmann::json& componentJson) {*static_cast<T*>(component) = componentJson.get<T>();}
        };
    }
}