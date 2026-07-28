#pragma once

#include <Engine/Graphics/Transform.hpp>
#include <Engine/Math/Matrix.hpp>

#include <cmath>

namespace Engine
{
    struct Camera
    {
        Transform transform;

        float fieldOfView;
        float aspectRatio;

        float nearPlane;
    };
}