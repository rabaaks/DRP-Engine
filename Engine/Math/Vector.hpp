#pragma once

#include <cstddef>

namespace Engine
{
    template <std::size_t N>
    struct VectorBase
    {
        float data[N];
    };

    template <>
    struct VectorBase<2>
    {
        union
        {
            struct {float x, y;};
            float data[2];
        };
    };

    template <>
    struct VectorBase<3>
    {
        union
        {
            struct {float x, y, z;};
            float data[3];
        };
    };

    template <>
    struct VectorBase<4>
    {
        union
        {
            struct {float x, y, z, w;};
            float data[4];
        };
    };

    template <std::size_t N>
    struct Vector : public VectorBase<N>
    {

        float Dot(const Vector& other) const;

        Vector Cross(const Vector& other) const requires (N == 3);

        float& operator[](std::size_t index);

        Vector operator+(const Vector& other) const;
        Vector operator-(const Vector& other) const;
        Vector operator*(float scalar) const;
        Vector operator/(float scalar) const;
    };
}

#include <Engine/Math/Vector.ipp>