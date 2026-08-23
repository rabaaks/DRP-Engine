#include <Engine/Graphics/Transform.hpp>

#include <cmath>

namespace Engine
{
    Matrix<4> Transform::GetMatrix()
    {
        float radiansX{rotation.x * static_cast<float>(M_PI) / 180.0f};
        float radiansY{rotation.y * static_cast<float>(M_PI) / 180.0f};
        float radiansZ{rotation.z * static_cast<float>(M_PI) / 180.0f};

        Matrix<4> scaleMatrix
        {{
            {scale.x, 0.0f, 0.0f, 0.0f},
            {0.0f, scale.y, 0.0f, 0.0f},
            {0.0f, 0.0f, scale.z, 0.0f},
            {0.0f, 0.0f, 0.0f, 1.0f}
        }};

        Matrix<4> rotationX
        {{
            {1.0f, 0.0f, 0.0f, 0.0f},
            {0.0f, cos(radiansX), -sin(radiansX), 0.0f},
            {0.0f, sin(radiansX), cos(radiansX), 0.0f},
            {0.0f, 0.0f, 0.0f, 1.0f}
        }};

        Matrix<4> rotationY
        {{
            {cos(radiansY), 0.0f, sin(radiansY), 0.0f},
            {0.0f, 1.0f, 0.0f, 0.0f},
            {-sin(radiansY), 0.0f, cos(radiansY), 0.0f},
            {0.0f, 0.0f, 0.0f, 1.0f}
        }};

        Matrix<4> rotationZ
        {{
            {cos(radiansZ), -sin(radiansZ), 0.0f, 0.0f},
            {sin(radiansZ), cos(radiansZ), 0.0f, 0.0f},
            {0.0f, 0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 0.0f, 1.0f}
        }};

        Matrix<4> translationMatrix
        {{
            {1.0f, 0.0f, 0.0f, position.x},
            {0.0f, 1.0f, 0.0f, position.y},
            {0.0f, 0.0f, 1.0f, position.z},
            {0.0f, 0.0f, 0.0f, 1.0f}
        }};

        return translationMatrix * rotationZ * rotationY * rotationX * scaleMatrix;
    }
}