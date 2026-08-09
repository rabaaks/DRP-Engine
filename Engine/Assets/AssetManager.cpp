#include <Engine/Assets/AssetManager.hpp>
#include <Engine/Graphics/Image.hpp>
#include <Engine/Graphics/Model.hpp>
#include <Engine/Scene/Entity.hpp>
#include <Engine/Scene/Scene.hpp>

#include <nlohmann/json.hpp>

#include <iostream>

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
        },
        assetTypes
        {
            {
                {"entity", typeid(Entity)},
                {"scene", typeid(Scene)},
                {"script", typeid(void)},
                {"model", typeid(Model)},
                {"image", typeid(Image)},
                {"sound", typeid(void)}
            }
        }
    {
        nlohmann::json configJson(nlohmann::json::parse(configFile));
        for (nlohmann::json asset : configJson)
        {
            assets[asset["id"].get<std::uint64_t>()] = 
            AssetInfo
            {
                asset["path"].get<std::string>(),
                assetTypes.at(asset["type"].get<std::string>())
            };
            std::cout << asset["id"] << std::endl << asset["path"] << asset["type"];
        }
    }
}
