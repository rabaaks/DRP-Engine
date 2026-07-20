#pragma once

#include <Engine/Graphics/Framebuffer.hpp>
#include <Engine/Graphics/Renderer.hpp>
#include <Engine/Window/Window.hpp>

namespace Engine
{
    class SoftwareRenderer : public Renderer
    {
    public:
        SoftwareRenderer(int width, int height, const Window& window);

        void BeginFrame(Camera camera) override;
        void DrawMesh(Mesh mesh, Transform<3> transform, Material material) override;
        void ShowFrame() override;
    
    private:
        int width;
        int height;
        Framebuffer framebuffer;
        const Window& window;
    };
}