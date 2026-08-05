#pragma once

#include <Engine/Assets/Asset.hpp>
#include <Engine/Assets/AssetInfo.hpp>

#include <cstdint>
#include <fstream>
#include <string>
#include <unordered_map>

namespace Engine
{
    class AssetManager
    {
    public:
        AssetManager();
        ~AssetManager();

        template <typename T>
        T& GetAssetData(Asset<T> asset);

        template <typename T>
        void Import(std::string path);
    
    private:
        std::unordered_map<AssetInfo, uint64_t> assets;
        std::fstream configFile;
    };
}

#include <Engine/Assets/AssetManager.ipp>