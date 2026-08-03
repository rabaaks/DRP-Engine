#pragma once

#include <Engine/Graphics/Camera.hpp>
#include <Engine/Graphics/Material.hpp>
#include <Engine/Graphics/Mesh.hpp>
#include <Engine/Graphics/Transform.hpp>

namespace Engine
{
    class Renderer
    {
    public:
        virtual ~Renderer() = default;

        virtual void BeginFrame(const Camera& camera) = 0;
        virtual void DrawMesh(Mesh mesh, Transform transform) = 0;
        virtual void ShowFrame() = 0;
    };
}