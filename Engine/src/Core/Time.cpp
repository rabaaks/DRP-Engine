#include <Engine/Core/Time.hpp>

#include <chrono>

namespace Engine
{
    void Time::Update()
    {
        float currentTime
        {
            std::chrono::duration<float>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
            ).count()
        };
        // No delta time recorded for last frame on the first frame
        if (firstFrame)
        {
            lastFrameTime = currentTime;
            firstFrame = false;
        }
        deltaTime = currentTime - lastFrameTime;
        lastFrameTime = currentTime;
    }

    float Time::DeltaTime() const
    {
        return deltaTime;
    }
}