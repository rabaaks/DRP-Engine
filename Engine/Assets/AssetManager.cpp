#include <Engine/Assets/AssetManager.hpp>

#include <nlohmann/json.hpp>

#include <iostream>

namespace Engine
{
    AssetManager::AssetManager(std::filesystem::path projectRootPath) :
        configFile{projectRootPath / "assets.json"}
    {
        nlohmann::json configJson(nlohmann::json::parse(configFile));
        for (nlohmann::json asset : configJson)
        {
            assets[asset["id"].get<uint64_t>()] = 
            AssetInfo
            {
                asset["path"].get<std::string>(),
                assetTypes.at(asset["type"].get<std::string>())
            };
            std::cout << asset["id"] << std::endl << asset["path"] << asset["type"];
        }
    }

    AssetManager::~AssetManager()
    {
        configFile.close();
    }

    void AssetManager::Import(std::filesystem::path path)
    {
        
    }

    const std::unordered_map<std::filesystem::path, AssetManager::FileLoader> AssetManager::fileExtensions = 
    {
        {
            ".png",
            [](std::filesystem::path filePath) -> void
            {

            }
        }
    };

    const std::unordered_map<std::string, AssetType> AssetManager::assetTypes = 
    {
        {"entity", AssetType::Entity},
        {"scene", AssetType::Scene},
        {"script", AssetType::Script},
        {"model", AssetType::Model},
        {"image", AssetType::Image},
        {"sound", AssetType::Sound}
    };
}
