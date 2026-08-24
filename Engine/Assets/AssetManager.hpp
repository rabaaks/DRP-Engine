#pragma once

#include <Engine/Assets/Asset.hpp>
#include <Engine/Assets/AssetInfo.hpp>
#include <Engine/Assets/FileLoader.hpp>
#include <Engine/Assets/ImageLoader.hpp>
#include <Engine/Assets/ModelLoader.hpp>

#include <Engine/Scene/ComponentManager.hpp>
#include <Engine/Scene/Entity.hpp>

#include <nlohmann/json.hpp>

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
        ~AssetManager();

        AssetManager(AssetManager&&) = default;
        AssetManager& operator=(AssetManager&&) = default;

        void Save();

        template <typename T>
        T& GetData(Asset<T> asset);

        template <typename T>
        Asset<T> Import(std::filesystem::path path);

        template <typename T>
        void AddComponent(const std::string& name);

        ComponentManager& GetComponentManager();

        template <typename T>
        T Clone(const T& entity);
    
    private:
        std::filesystem::path projectRootPath;
        std::uint64_t nextId{};
        std::unordered_map<std::uint64_t, AssetInfo> assets;
        std::unordered_map<std::uint64_t, std::shared_ptr<void>> cachedAssets; 
        std::fstream configFile;

        ImageLoader imageLoader;
        ModelLoader modelLoader;

        std::unordered_map<std::filesystem::path, std::reference_wrapper<FileLoader>> fileExtensions;
        std::unordered_map<std::string, std::type_index> assetTypes;
        std::unordered_map<std::type_index, std::string> assetNames;

        std::unordered_map<std::type_index, std::function<nlohmann::json(void*)>> serializers;
        std::unordered_map<std::type_index, std::function<std::shared_ptr<void>(const nlohmann::json&)>> deserializers;

        ComponentManager componentManager;

        template <typename T>
        void AddType(const std::string& name);
    };
}

#include <Engine/Assets/AssetManager.ipp>
