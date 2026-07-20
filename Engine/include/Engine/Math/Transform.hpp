#pragma once

#include <Engine/Math/Vector.hpp>

namespace Engine
{
    template <size_t N>
    struct Transform
    {
        Vector<N> position{};
        Vector<N> rotation{};
        Vector<N> scale{};
    };
}