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
            assets[asset["id"].get<uint64_t>()] = {asset["path"].get<std::string>(), asset["type"].get<std::string>()};
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
}