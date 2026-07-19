#pragma once

#include <Engine/Core/Time.hpp>
#include <Engine/Renderer/SoftwareRenderer.hpp>
#include <Engine/Window/SDLWindow.hpp>

namespace Engine
{
    class Application
    {
    public:
        Application();

        void Run();

    private:
        bool running{true};
        Time time;

        SDLWindow window;
        SoftwareRenderer renderer;

        void Update(float deltaTime);
        void Render();
    };
}