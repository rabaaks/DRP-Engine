#include <Engine/Scene/Scene.hpp>

#include <Engine/Assets/AssetManager.hpp>
#include <Engine/Scripting/ScriptLibrary.hpp>

#include <algorithm>

namespace Engine
{
    void Scene::AddEntityAsset(Asset<Entity> entityAsset)
    {
        entityAssets.push_back(entityAsset);
    }

    const std::vector<Asset<Entity>>& Scene::GetEntityAssets() const
    {
        return entityAssets;
    }

    void Scene::Instantiate(AssetManager& assetManager, ScriptLibrary& scriptLibrary)
    {
        // Clone all of the components so they can be edited
        for (const Asset<Entity>& entityAsset : entityAssets)
        {
            Entity instance{assetManager.Clone(assetManager.GetData(entityAsset))};
            instance.id = nextEntityId++;
            instance.scene = this;

            for (const std::string& scriptName : instance.GetScriptNames())
            {
                // instance.scripts.push_back(scriptLibrary.Create(scriptName));
                // instance.scripts.back()->OnCreate(instance);
            }

            entities.push_back(std::move(instance));
        }
    }

    std::vector<Entity>& Scene::GetEntities()
    {
        return entities;
    }

    void Scene::DestroyEntity(std::uint64_t entityId)
    {
        destroyQueue.push_back(entityId);
    }

    void Scene::DestroyPending()
    {
        entities.erase
        (
            std::remove_if
            (
                entities.begin(),
                entities.end(),
                [this](const Entity& entity)
                {
                    return std::find(destroyQueue.begin(), destroyQueue.end(), entity.GetId()) != destroyQueue.end();
                }
            ),
            entities.end()
        );

        destroyQueue.clear();
    }
}