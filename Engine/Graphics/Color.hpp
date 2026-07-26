#pragma once

#include <cstdint>

namespace Engine
{
    union Color
    {
        uint32_t value;
        struct
        {
            uint8_t a, r, g, b;
        };
    };
}