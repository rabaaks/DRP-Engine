#pragma once

#include <Engine/Scene/ComponentInfo.hpp>

#include <string>
#include <unordered_map>

namespace Engine
{
    class ComponentManager
    {
    public:
        template <typename T>
        void AddComponent(const std::string& name);

        // Store each component directly to its own json file
        std::shared_ptr<void> Create(const std::string& name) const;
        nlohmann::json ToJson(const std::string& name, void* component) const;
        void FromJson(const std::string& name, void* component, const nlohmann::json& componentJson) const;
    
    private:
        std::unordered_map<std::string, ComponentInfo> componentTypes;
    };
}

#include <Engine/Scene/ComponentManager.ipp>