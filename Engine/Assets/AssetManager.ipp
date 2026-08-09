#include <Engine/Assets/AssetManager.hpp>

namespace Engine
{
    template <typename T>
    T& AssetManager::GetData(Asset<T> asset)
    {
        if (cachedAssets.contains(asset.id)) return static_cast<T>(cachedAssets[asset.id]);
    
        
    }

    template <typename T>
    Asset<T> AssetManager::Import(std::filesystem::path path)
    {
        // Construct T object using the file extension and then call Save<T>
    }
}