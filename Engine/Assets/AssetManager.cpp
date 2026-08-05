#include <Engine/Assets/AssetManager.hpp>

namespace Engine
{
    AssetManager::AssetManager()
        : configFile("assets.json", ios::in | ios::out)
    {

    }

    AssetManager::~AssetManager()
    {
        configFile.close();
    }
}