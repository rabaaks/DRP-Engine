#pragma once

#include <Engine/Assets/AssetManager.hpp>
#include <Engine/Core/Time.hpp>
#include <Engine/Graphics/SoftwareRenderer.hpp>
#include <Engine/Window/SDLWindow.hpp>

#include <filesystem>

namespace Runtime
{
    class Game
    {
    public:
        // Maybe change to project config struct later
        Game(int width, int height, std::string name, std::filesystem::path projectRootPath);

        static Game load(std::filesystem::path projectFilePath);

        void Run();

    private:
        bool running{true};
        Engine::Time time;
        std::filesystem::path projectRootPath;

        Engine::AssetManager assetManager;
        Engine::SDLWindow window;
        Engine::SoftwareRenderer renderer;

        void Update(float deltaTime);
        void Render();
    };
}