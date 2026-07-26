#pragma once

namespace Engine
{
    class Time
    {
    public:
        void Update();

        float DeltaTime() const;
    
    private:
        float deltaTime{0.0f};
        float lastFrameTime{0.0f};
        bool firstFrame{true};
    };
}