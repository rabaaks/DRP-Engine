#pragma once

#include <Engine/Math/Vector.hpp>

#include <cstddef>

namespace Engine
{
    template <std::size_t M, std::size_t N = M>
    struct Matrix
    {
        Vector<N> data[M];

        Vector<N>& operator[](std::size_t index);

        template <std::size_t P>
        Matrix<M, P> operator*(const Matrix<N, P>& other) const;

        Vector<M> operator*(const Vector<N>& vector) const;
    };
}

#include <Engine/Math/Matrix.ipp>