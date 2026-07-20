#pragma once

#include <Engine/Graphics/Framebuffer.hpp>

namespace Engine
{
    class Window
    {
    public:
        virtual ~Window() = default;

        virtual void PollEvents() = 0;
        virtual bool ShouldClose() const = 0;
        virtual void Display(const Framebuffer& framebuffer) const = 0;
    };
}