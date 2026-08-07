#pragma once

namespace Engine
{
    class Window
    {
    public:
        virtual ~Window() = default;

        virtual void PollEvents() = 0;
        virtual bool ShouldClose() const = 0;

        virtual int GetWidth() const = 0;
        virtual int GetHeight() const = 0;
    };
}