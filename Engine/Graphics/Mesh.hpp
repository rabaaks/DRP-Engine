#pragma once

#include <Engine/Graphics/Triangle.hpp>

#include <vector>

namespace Engine
{
    struct Mesh
    {
        std::vector<Triangle> triangles;
    };
}