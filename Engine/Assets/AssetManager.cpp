#include <Engine/Assets/AssetManager.hpp>
#include <Engine/Assets/Serialization.hpp>

#include <Engine/Graphics/Image.hpp>
#include <Engine/Graphics/MeshRenderer.hpp>
#include <Engine/Graphics/Model.hpp>
#include <Engine/Graphics/Transform.hpp>

#include <Engine/Scene/Entity.hpp>
#include <Engine/Scene/Scene.hpp>

#include <nlohmann/json.hpp>

#include <iostream>
#include <utility>

namespace Engine
{
    AssetManager::AssetManager(std::filesystem::path projectRootPath) :
        configFile{projectRootPath / "assets.json"},
        fileExtensions
        {
            {".png", imageLoader},
            {".jpg", imageLoader},
            {".stl", modelLoader}
        }
    {
        AddType<Image>("image");
        AddType<Model>("model");
        AddType<Scene>("scene");

        // Serialization methods for Entity requires the componentManager
        assetTypes.emplace("Entity", typeid(Entity));
        assetNames.emplace(typeid(Entity), "entity");

        serializers[typeid(Entity)] = 
        [this](void* object) -> nlohmann::json
        {
            nlohmann::json entityJson;
            to_json(entityJson, *static_cast<Entity*>(object), componentManager);
            return entityJson;
        };

        deserializers[typeid(Entity)] =
        [this](const nlohmann::json& entityJson) ->std::shared_ptr<void>
        {
            std::shared_ptr<Entity> entity{std::make_shared<Entity>()};
            from_json(entityJson, *entity, componentManager);
            return entity;
        };

        componentManager.AddComponent<Transform>("Transform");
        componentManager.AddComponent<MeshRenderer>("MeshRenderer");

        nlohmann::json configJson(nlohmann::json::parse(configFile));
        for (nlohmann::json asset : configJson)
        {
            assets[asset["id"].get<std::uint64_t>()] = 
            AssetInfo
            {
                asset["path"].get<std::string>(),
                asset["sourcePath"].get<std::string>(),
                assetTypes.at(asset["type"].get<std::string>())
            };
            std::cout << asset["id"] << std::endl << asset["path"] << asset["type"];
        }
    }

    AssetManager::~AssetManager()
    {
        Save();
    }

    void AssetManager::Save()
    {
        nlohmann::json configJson{nlohmann::json::array()};
        // Structured binding, have to use auto
        for (auto& [id, info] : assets)
        {
            configJson.push_back
            (
                {
                    {"id", id},
                    {"path", info.path.string()},
                    {"sourcePath", info.sourcePath.string()},
                    {"type", assetNames.at(info.type)}
                }
            );
        }
        configFile.seekp(0);
        configFile << configJson.dump(4);
    }
}
