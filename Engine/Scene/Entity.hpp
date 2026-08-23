#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace Engine
{
    class Scene;
    class Script;

    class Entity
    {
    public:
        const std::string& GetName() const;
        void SetName(std::string name);
        
        template <typename T>
        T* GetComponent(const std::string& name);
        

        void AddComponent(const std::string& name, std::shared_ptr<void> component);
        const std::unordered_map<std::string, std::shared_ptr<void>>& GetComponents() const;

        const std::vector<std::string>& GetScriptNames() const;
        void AddScriptName(const std::string& name);
        
    private:
        std::string name;
        std::unordered_map<std::string, std::shared_ptr<void>> components;
        std::vector<std::string> scriptNames;

        Scene* scene;
        // Only owned by the entity
        std::vector<std::unique_ptr<Script, void(*)(Script*)>> scripts;
    };
}

#include <Engine/Scene/Entity.ipp>