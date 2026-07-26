#pragma once

#include <Engine/Graphics/Transform.hpp>
#include <Engine/Math/Matrix.hpp>

#include <cmath>

namespace Engine
{
    class Camera
    {
    public:
        Camera(Transform transform, float fieldOfView, float aspectRatio);

        Matrix<4> GetViewMatrix() const;
        Matrix<4> GetProjectionMatrix() const;

    private:
        Transform transform;

        float fieldOfView;
        float aspectRatio;
    };
}