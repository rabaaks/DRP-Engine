#pragma once

#include <cstdint>

namespace Engine
{
    union Color
    {
        std::uint32_t value;
        struct
        {
            std::uint8_t a, r, g, b;
        };
    };
}