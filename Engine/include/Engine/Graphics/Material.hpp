#pragma once

#include <Engine/Graphics/Color.hpp>
#include <Engine/Graphics/Texture.hpp>

namespace Engine
{
    struct Material
    {
        // Might be null, use pointer to avoid copying texture data
        Texture* texture;
        Color color;
    };
}