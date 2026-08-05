#include <Runtime/Application/Application.hpp>

#include <Engine/Graphics/Image.hpp>

#include <iostream>

namespace Engine
{
    Application::Application()
        : window(1280, 720, "Test"), renderer(Image(1280, 720), window)
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

            Camera camera
            {
                {},
                90.0f,
                16 / 9.0f,
                1.0f
            };

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