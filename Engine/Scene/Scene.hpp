#pragma once

#include <Engine/Assets/Asset.hpp>
#include <Engine/Scene/Entity.hpp>

#include <vector>

namespace Engine
{
    class Scene
    {
    public:
        void AddEntityAsset(Asset<Entity> entityAsset);
        const std::vector<Asset<Entity>>& GetEntityAssets() const;

        std::vector<Entity>& GetEntities();
    
    private:
        std::vector<Asset<Entity>> entityAssets;
        std::vector<Entity> entities;
    };
}