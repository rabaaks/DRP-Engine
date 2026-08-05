#pragma once

#include <Engine/Assets/Asset.hpp>
#include <Engine/Assets/AssetInfo.hpp>

#include <unordered_map>

namespace Engine
{
    class AssetManager
    {
    public:
        template <typename T>
        T& GetAssetData(Asset<T> asset);
    
    private:
        std::unordered_map<AssetInfo> assets;
    };
}

#include <Engine/Assets/AssetManager.ipp>