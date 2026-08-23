#include <Engine/Scripting/Script.hpp>
#include <Engine/Scripting/ScriptLibrary.hpp>

#include <nlohmann/json.hpp>

#include <fstream>

namespace Engine
{
    void ScriptLibrary::LoadModule(std::filesystem::path path)
    {
        modules.push_back(std::make_unique<DynamicLibrary>(path));
        DynamicLibrary& library{*modules.back()};

        // The json will list which scripts are contained within the module
        std::filesystem::path jsonPath{path};
        jsonPath.replace_extension(".scripts.json");
        std::ifstream jsonFile{jsonPath};
        nlohmann::json json(nlohmann::json::parse(jsonFile));

        for (const std::string& scriptName : json.at("scripts").get<std::vector<std::string>>())
        {
            Script* (*create)(){reinterpret_cast<Script* (*)()>(library.GetSymbol("Create_" + scriptName))};
            void (*destroy)(Script*){reinterpret_cast<void (*)(Script*)>(library.GetSymbol("Destroy_" + scriptName))};

            scriptTypes[scriptName] = ScriptInfo{create, destroy};
        }
    }

    std::unique_ptr<Script, void(*)(Script*)> ScriptLibrary::Create(const std::string& name) const
    {
        const ScriptInfo& scriptInfo{scriptTypes.at(name)};
        return std::unique_ptr<Script, void(*)(Script*)>{scriptInfo.create(), scriptInfo.destroy};
    }
}