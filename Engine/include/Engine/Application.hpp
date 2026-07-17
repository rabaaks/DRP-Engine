#pragma once

#include <Engine/Core/Time.hpp>

namespace Engine
{
    class Application
    {
    public:
        Application();

        void Run();

    private:
        bool running;
        Time time;

        void Update(float deltaTime);
        void Render();
    };
}