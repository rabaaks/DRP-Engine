#pragma once

#include <Engine/Assets/Asset.hpp>
#include <Engine/Assets/AssetInfo.hpp>

#include <cstdint>
#include <filesystem>
#include <fstream>
#include <functional>
#include <string>
#include <unordered_map>

namespace Engine
{
    class AssetManager
    {
    public:
        AssetManager(std::filesystem::path projectRootPath);
        ~AssetManager();

        template <typename T>
        T& GetAssetData(Asset<T> asset);

        void Import(std::filesystem::path path);
    
    private:
        std::unordered_map<uint64_t, AssetInfo> assets;
        std::fstream configFile;

        using FileLoader = std::function<void(std::filesystem::path)>;
        static const std::unordered_map<std::filesystem::path, FileLoader> fileExtensions;
        static const std::unordered_map<std::string, AssetType> assetTypes;
    };
}

#include <Engine/Assets/AssetManager.ipp>