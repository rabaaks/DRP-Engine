#include <Runtime/Game/Game.hpp>

#include <Engine/Graphics/Image.hpp>

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
        assetManager{this->projectRootPath}
    {

    }

    // Application factory avoids issue with trying to default initialize window and renderer
    Game Game::load(std::filesystem::path projectFilePath)
    {
        std::ifstream projectFile(projectFilePath);

        nlohmann::json projectJson(nlohmann::json::parse(projectFile));

        int width{projectJson["width"].get<int>()};
        int height{projectJson["height"].get<int>()};
        std::string name{projectJson["name"].get<std::string>()};

        std::filesystem::path projectRootPath{projectFilePath.parent_path()};

        return Game{width, height, name, projectRootPath};
    }

    void Game::Run()
    {
        while (running)
        {
            window.PollEvents();
            if (window.ShouldClose()) running = false;

            time.Update();
            float deltaTime = time.DeltaTime();
            Update(deltaTime);

            Engine::Camera camera
            {
                {},
                90.0f,
                16 / 9.0f,
                1.0f
            };

            Render();
        }
        std::cout << "Done" << std::endl;
    }

    void Game::Update(float deltaTime)
    {
        
    }

    void Game::Render()
    {
        renderer.ShowFrame();
    }
}