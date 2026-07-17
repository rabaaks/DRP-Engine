#include <Engine/Application.hpp>
#include <iostream>

namespace Engine
{
    Application::Application()
    {
        running = true;
    }

    void Application::Run()
    {
        while (running)
        {
            time.Update();

            float deltaTime = time.DeltaTime();

            Update(deltaTime);

            Render();

            std::cout << "Frame\n";
        }
    }

    void Application::Update(float deltaTime)
    {
        std::cout << "Delta time: " << deltaTime;
    }

    void Application::Render()
    {
        
    }
}