#pragma once

#include <cstddef>

namespace Engine
{
    template <std::size_t N>
    struct Vector
    {
        float data[N];
    };

    template <>
    struct Vector<2>
    {
        union
        {
            struct {float x, y;};
            float data[2];
        };
    };

    template <>
    struct Vector<3>
    {
        union
        {
            struct {float x, y, z;};
            float data[3];
        };
    };

    template <>
    struct Vector<4>
    {
        union
        {
            struct {float x, y, z, w;};
            float data[4];
        };
    };
}