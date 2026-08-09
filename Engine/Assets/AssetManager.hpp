#pragma once

#include <Engine/Assets/Asset.hpp>
#include <Engine/Assets/AssetInfo.hpp>
#include <Engine/Assets/ImageLoader.hpp>
#include <Engine/Assets/FileLoader.hpp>

#include <cstdint>
#include <filesystem>
#include <fstream>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <typeindex>

namespace Engine
{
    class AssetManager
    {
    public:
        AssetManager(std::filesystem::path projectRootPath);
        ~AssetManager() = default;

        template <typename T>
        T& GetData(Asset<T> asset);

        template <typename T>
        Asset<T> Import(std::filesystem::path path);
    
    private:
        std::unordered_map<std::uint64_t, AssetInfo> assets;
        std::unordered_map<std::uint64_t, void*> cachedAssets; 
        std::fstream configFile;

        ImageLoader imageLoader;

        std::unordered_map<std::filesystem::path, FileLoader&> fileExtensions;
        std::unordered_map<std::string, std::type_index> assetTypes;
    };
}

#include <Engine/Assets/AssetManager.ipp>