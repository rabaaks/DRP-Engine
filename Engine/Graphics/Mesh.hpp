#pragma once

#include <Engine/Graphics/Triangle.hpp>
#include <Engine/Graphics/Material.hpp>
#include <Engine/Graphics/Vertex.hpp>

namespace Engine
{
    struct Mesh
    {
        std::vector<Vertex> vertices;
        std::vector<Triangle> triangles;
        Material* material;
    };
}