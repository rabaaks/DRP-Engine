#include <Runtime/Game/Game.hpp>

#include <Engine/Scripting/Script.hpp>

#include <nlohmann/json.hpp>

#include <fstream>
#include <iostream>
#include <utility>

namespace Runtime
{
    Game::Game(int width, int height, std::string name, std::filesystem::path projectRootPath) :
        window{width, height, name},
        renderer{window},
        projectRootPath{std::move(projectRootPath)},
        assetManager{this->projectRootPath},
        camera
        {
            Engine::Transform{{0.0f, 2.0f, -6.0f}, {}, {1.0f, 1.0f, 1.0f}},
            90.0f,
            static_cast<float>(width) / height,
            0.1f
        }
    {

    }

    // Application factory avoids issue with trying to default initialize window
    Game Game::load(std::filesystem::path projectFilePath)
    {
        std::ifstream projectFile(projectFilePath);

        nlohmann::json projectJson(nlohmann::json::parse(projectFile));

        int width{projectJson["width"].get<int>()};
        int height{projectJson["height"].get<int>()};
        std::string name{projectJson["name"].get<std::string>()};

        std::filesystem::path projectRootPath{projectFilePath.parent_path()};

        Game game{width, height, name, projectRootPath};

        for (const std::string& moduleName : projectJson.value("scriptModules", std::vector<std::string>{}))
        {
            game.scriptLibrary.LoadModule(projectRootPath / moduleName, game.assetManager.GetComponentManager());
        }

        // Only copy the entity references out of the loaded scene, not the whole Scene object -
        // Scene isn't copy-assignable since Entity holds a unique_ptr to its scripts
        Engine::Asset<Engine::Scene> startScene{projectJson.at("startScene").get<std::uint64_t>()};
        Engine::Scene& sceneTemplate{game.assetManager.GetData(startScene)};
        for (const Engine::Asset<Engine::Entity>& entityAsset : sceneTemplate.GetEntityAssets())
        {
            game.scene.AddEntityAsset(entityAsset);
        }
        game.scene.Instantiate(game.assetManager, game.scriptLibrary);

        return game;
    }

    void Game::Run()
    {
        while (running)
        {
            window.PollEvents();
            if (window.ShouldClose()) running = false;

            time.Update();
            float deltaTime{time.DeltaTime()};
            Update(deltaTime);
            Render();
        }
        std::cout << "Done" << std::endl;
    }

    void Game::Update(float deltaTime)
    {
        for (Engine::Entity& entity : scene.GetEntities())
        {
            for (auto& script : entity.GetScripts())
            {
                script->Update(entity, window.GetInput(), deltaTime);
            }
        }

        scene.DestroyPending();
    }

    void Game::Render()
    {
        renderer.BeginFrame(camera);
        for (Engine::Entity& entity : scene.GetEntities())
        {
            if (!entity.GetComponents().contains("MeshRenderer") || !entity.GetComponents().contains("Transform")) continue;

            Engine::MeshRenderer* meshRenderer{entity.GetComponent<Engine::MeshRenderer>("MeshRenderer")};
            Engine::Transform* transform{entity.GetComponent<Engine::Transform>("Transform")};

            Engine::Model& model{assetManager.GetData(meshRenderer->model)};
            for (Engine::Mesh& mesh : model.meshes)
            {
                renderer.DrawMesh(mesh, *transform);
            }
        }
        renderer.ShowFrame();
    }
}
