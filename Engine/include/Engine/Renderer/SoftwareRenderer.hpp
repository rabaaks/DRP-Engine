#pragma once

#include <Engine/Renderer/Framebuffer.hpp>
#include <Engine/Renderer/Renderer.hpp>
#include <Engine/Window/Window.hpp>

namespace Engine
{
    class SoftwareRenderer : public Renderer
    {
    public:
        SoftwareRenderer(int width, int height, const Window& window);

        void Render() override;
    
    private:
        int width;
        int height;
        Framebuffer framebuffer;
        const Window& window;
    };
}