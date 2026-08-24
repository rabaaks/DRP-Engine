#pragma once

#include <cstdint>
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
        std::uint64_t GetId() const;

        const std::string& GetName() const;
        void SetName(std::string name);
        
        template <typename T>
        T* GetComponent(const std::string& name);
        
        void AddComponent(const std::string& name, std::shared_ptr<void> component);
        const std::unordered_map<std::string, std::shared_ptr<void>>& GetComponents() const;

        const std::vector<std::string>& GetScriptNames() const;
        void AddScriptName(const std::string& name);

        std::vector<std::unique_ptr<Script, void(*)(Script*)>>& GetScripts();
        Scene* GetScene() const;
        
    private:
        std::uint64_t id{};
        std::string name;
        std::unordered_map<std::string, std::shared_ptr<void>> components;
        std::vector<std::string> scriptNames;

        Scene* scene{nullptr};
        // Only owned by the entity
        std::vector<std::unique_ptr<Script, void(*)(Script*)>> scripts;

        // Allows the scene to fill in scripts when instantiated
        friend class Scene;
    };
}

#include <Engine/Scene/Entity.ipp>