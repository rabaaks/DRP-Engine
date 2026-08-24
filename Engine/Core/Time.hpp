#pragma once

#include <chrono>

namespace Engine
{
    class Time
    {
    public:
        void Update();

        float DeltaTime() const;
    
    private:
        float deltaTime{0.0f};
        std::chrono::steady_clock::time_point lastFrameTime;
        bool firstFrame{true};
    };
}
