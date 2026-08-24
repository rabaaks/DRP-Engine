#include <Engine/Graphics/Transform.hpp>

#include <cmath>

namespace Engine
{
    Matrix<4> Transform::GetMatrix()
    {
        float radiansX{rotation.x * static_cast<float>(M_PI) / 180.0f};
        float radiansY{rotation.y * static_cast<float>(M_PI) / 180.0f};
        float radiansZ{rotation.z * static_cast<float>(M_PI) / 180.0f};

        // Cache these as floats up front - unqualified cos/sin can resolve to the global
        // double-returning ::cos/::sin instead of std::cos/std::sin's float overload,
        // which narrows when placed directly into a float-initializer list below
        float cosX{static_cast<float>(std::cos(radiansX))};
        float sinX{static_cast<float>(std::sin(radiansX))};
        float cosY{static_cast<float>(std::cos(radiansY))};
        float sinY{static_cast<float>(std::sin(radiansY))};
        float cosZ{static_cast<float>(std::cos(radiansZ))};
        float sinZ{static_cast<float>(std::sin(radiansZ))};

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
            {0.0f, cosX, -sinX, 0.0f},
            {0.0f, sinX, cosX, 0.0f},
            {0.0f, 0.0f, 0.0f, 1.0f}
        }};

        Matrix<4> rotationY
        {{
            {cosY, 0.0f, sinY, 0.0f},
            {0.0f, 1.0f, 0.0f, 0.0f},
            {-sinY, 0.0f, cosY, 0.0f},
            {0.0f, 0.0f, 0.0f, 1.0f}
        }};

        Matrix<4> rotationZ
        {{
            {cosZ, -sinZ, 0.0f, 0.0f},
            {sinZ, cosZ, 0.0f, 0.0f},
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