#pragma once

#include <Engine/Math/Vector.hpp>

namespace Engine
{
    struct Vertex
    {
        Vector<3> position;
        Vector<3> normal;
        Vector<2> uv;
    };
}