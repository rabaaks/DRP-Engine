#include <Engine/Core/Time.hpp>

#include <chrono>

namespace Engine
{
    void Time::Update()
    {
        const auto currentTime{std::chrono::steady_clock::now()};

        // No delta time is recorded for the first frame.
        if (firstFrame)
        {
            lastFrameTime = currentTime;
            firstFrame = false;
            return;
        }

        deltaTime = std::chrono::duration<float>(currentTime - lastFrameTime).count();
        lastFrameTime = currentTime;
    }

    float Time::DeltaTime() const
    {
        return deltaTime;
    }
}
