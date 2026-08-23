#include <Engine/Scene/ComponentManager.hpp>

namespace Engine
{
    std::shared_ptr<void> ComponentManager::Create(const std::string& name) const
    {
        return componentTypes.at(name).create();
    }

    nlohmann::json ComponentManager::ToJson(const std::string& name, void* component) const
    {
        return componentTypes.at(name).toJson(component);
    }

    void ComponentManager::FromJson(const std::string& name, void* component, const nlohmann::json& componentJson) const
    {
        componentTypes.at(name).fromJson(component, componentJson);
    }
}