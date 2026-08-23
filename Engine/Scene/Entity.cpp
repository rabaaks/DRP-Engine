#include <Engine/Scene/Entity.hpp>

namespace Engine
{
    std::uint64_t Entity::GetId() const
    {
        return id;
    }

    const std::string& Entity::GetName() const
    {
        return name;
    }

    void Entity::SetName(std::string name)
    {
        name = std::move(name);
    }

    void Entity::AddComponent(const std::string& name, std::shared_ptr<void> component)
    {
        components[name] = component;
    }

    const std::vector<std::string>& Entity::GetScriptNames() const
    {
        return scriptNames;
    }

    void Entity::AddScriptName(const std::string& name)
    {
        scriptNames.push_back(name);
    }

    const std::unordered_map<std::string, std::shared_ptr<void>>& Entity::GetComponents() const
    {
        return components;
    }

    Scene* Entity::GetScene() const
    {
        return scene;
    }
}