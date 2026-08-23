#include <Engine/Assets/AssetManager.hpp>

namespace Engine
{
    template <typename T>
    T& AssetManager::GetData(Asset<T> asset)
    {
        // Use static_pointer_cast so that the shared_ptr doesn't delete the object
        if (cachedAssets.contains(asset.id)) return *std::static_pointer_cast<T>(cachedAssets[asset.id]);
    
        const AssetInfo& assetInfo{assets.at(asset.id)};
        std::ifstream assetFile{assetInfo.path};
        nlohmann::json assetJson(nlohmann::json::parse(assetFile));
        // The deserializer creates the shared_ptr
        std::shared_ptr<T> objectPtr{std::static_pointer_cast<T>(deserializers.at(assetInfo.type)(assetJson))};
        cachedAssets[asset.id] = objectPtr;
        return *objectPtr;
    }

    template <typename T>
    Asset<T> AssetManager::Import(std::filesystem::path path)
    {
        // Construct T object using the file extension and then call Save<T>
        std::shared_ptr<T> objectPtr{std::make_shared<T>()};
        fileExtensions.at(path.extension()).get().Load(path, objectPtr.get());
        std::filesystem::path assetPath{path};
        assetPath.replace_extension(assetNames.at(typeid(T)));
        std::ofstream assetFile{assetPath};
        assetFile << serializers.at(typeid(T))(objectPtr.get());

        std::uint64_t id{nextId++};
        assets[id] = AssetInfo{assetPath, path, typeid(T)};
        cachedAssets[id] = objectPtr;
        return Asset<T>{id};
    }

    template <typename T>
    void AssetManager::AddType(const std::string& name)
    {
        assetTypes.emplace(name, typeid(T));
        assetNames.emplace(typeid(T), name);

        // Use the serialize/deserialize methods in Serialization.cpp
        serializers[typeid(T)] = [](void* object) -> nlohmann::json
        {
            return nlohmann::json(*static_cast<T*>(object));
        };

        deserializers[typeid(T)] = [](const nlohmann::json& objectJson) -> std::shared_ptr<void>
        {
            return std::make_shared<T>(objectJson.get<T>());
        };
    }
}