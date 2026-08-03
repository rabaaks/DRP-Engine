#pragma once

#include <Engine/Math/Vector.hpp>
#include <Engine/Math/Matrix.hpp>

namespace Engine
{
    struct Transform
    {
        Vector<3> position{};
        Vector<3> rotation{};
        Vector<3> scale{};

        Matrix<4> GetMatrix();
    };
}