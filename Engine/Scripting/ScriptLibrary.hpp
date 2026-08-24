#pragma once

#include <Engine/Scripting/DynamicLibrary.hpp>
#include <Engine/Scripting/ScriptInfo.hpp>

#include <Engine/Scene/ComponentManager.hpp>

#include <filesystem>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace Engine
{
    class ScriptLibrary
    {
    public:
        void LoadModule(std::filesystem::path path, ComponentManager& componentManager);
        std::unique_ptr<Script, void(*)(Script*)> Create(const std::string& name) const;
    
    private:
        std::vector<std::unique_ptr<DynamicLibrary>> modules;
        std::unordered_map<std::string, ScriptInfo> scriptTypes;
    };
}