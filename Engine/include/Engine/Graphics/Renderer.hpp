#pragma once

#include <Engine/Graphics/Camera.hpp>
#include <Engine/Graphics/Material.hpp>
#include <Engine/Graphics/Mesh.hpp>
#include <Engine/Math/Transform.hpp>

namespace Engine
{
    class Renderer
    {
    public:
        virtual ~Renderer() = default;

        virtual void BeginFrame(Camera camera) = 0;
        virtual void DrawMesh(Mesh mesh, Transform<3> transform, Material material) = 0;
        virtual void ShowFrame() = 0;
    };
}