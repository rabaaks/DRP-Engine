#pragma once

#include <Engine/Assets/Asset.hpp>
#include <Engine/Assets/AssetManager.hpp>
#include <Engine/Scene/Entity.hpp>
#include <Engine/Scripting/ScriptLibrary.hpp>

#include <vector>

namespace Engine
{
    class Scene
    {
    public:
        void AddEntityAsset(Asset<Entity> entityAsset);
        const std::vector<Asset<Entity>>& GetEntityAssets() const;

        void Instantiate(AssetManager& assetManager, ScriptLibrary& scriptLibrary);
        std::vector<Entity>& GetEntities();

        // Don't destroy immediately, wait for the end of the frame
        void DestroyEntity(std::uint64_t entityId);
        void DestroyPending();
    
    private:
        std::vector<Asset<Entity>> entityAssets;
        std::vector<Entity> entities;
        std::vector<std::uint64_t> destroyQueue;

        std::uint64_t nextEntityId;
    };
}