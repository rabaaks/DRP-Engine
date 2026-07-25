#pragma once

#include <Engine/Math/Vector.hpp>

#include <cstddef>

namespace Engine
{
    template <std::size_t M, std::size_t N>
    struct Matrix
    {
        Vector<N> rows[M];
    };
}