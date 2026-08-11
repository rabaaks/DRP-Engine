#pragma once

#include <Engine/Graphics/Mesh.hpp>

#include <vector>

namespace Engine
{
    struct Model
    {
        std::vector<Mesh> meshes;
    };
}