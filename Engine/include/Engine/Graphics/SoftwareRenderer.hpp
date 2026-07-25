#pragma once

#include <Engine/Graphics/Image.hpp>
#include <Engine/Graphics/Renderer.hpp>
#include <Engine/Window/SDLWindow.hpp>

namespace Engine
{
    class SoftwareRenderer : public Renderer
    {
    public:
        SoftwareRenderer(Image image, const SDLWindow& window);

        void BeginFrame(const Camera& camera) override;
        void DrawMesh(Mesh mesh, Transform transform, Material material) override;
        void ShowFrame() override;
    
    private:
        Image image;

        const SDLWindow& window;
        const Camera& camera;
    };
}