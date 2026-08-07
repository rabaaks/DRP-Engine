#pragma once

#include <Engine/Graphics/Camera.hpp>
#include <Engine/Graphics/Image.hpp>
#include <Engine/Graphics/Material.hpp>
#include <Engine/Graphics/Mesh.hpp>
#include <Engine/Graphics/Renderer.hpp>
#include <Engine/Graphics/Transform.hpp>

#include <Engine/Math/Matrix.hpp>

#include <Engine/Window/SDLWindow.hpp>

namespace Engine
{
    class SoftwareRenderer : public Renderer
    {
    public:
        SoftwareRenderer(const SDLWindow& window);

        void BeginFrame(const Camera& camera) override;
        void DrawMesh(Mesh mesh, Transform transform) override;
        void ShowFrame() override;
    
    private:
        Image image;

        const SDLWindow& window;

        Camera camera;
    };
}