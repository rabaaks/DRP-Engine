#include <Engine/Core/Application.hpp>
#include <iostream>

namespace Engine
{
    Application::Application()
        : window(1280, 720, "Test"), renderer(1280, 720, window)
    {

    }

    void Application::Run()
    {
        while (running)
        {
            window.PollEvents();
            if (window.ShouldClose()) running = false;

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
        renderer.ShowFrame();
    }
}