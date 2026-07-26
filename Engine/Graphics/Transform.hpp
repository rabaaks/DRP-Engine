#pragma once

#include <Engine/Math/Vector.hpp>

namespace Engine
{
    struct Transform
    {
        Vector<3> position{};
        Vector<3> rotation{};
        Vector<3> scale{};
    };
}