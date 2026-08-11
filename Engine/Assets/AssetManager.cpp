#include <Engine/Assets/AssetManager.hpp>
#include <Engine/Assets/Serialization.hpp>
#include <Engine/Graphics/Image.hpp>
#include <Engine/Graphics/Model.hpp>
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
            {
                {".png", imageLoader},
                {".jpg", imageLoader}
            }
        }
    {
        AddType<Image>("image");
        AddType<Mesh>("mesh");

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
