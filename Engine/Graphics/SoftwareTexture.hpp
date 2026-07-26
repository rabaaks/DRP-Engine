#pragma once

#include <Engine/Graphics/Image.hpp>
#include <Engine/Graphics/Texture.hpp>
#include <Engine/Math/Vector.hpp>

#include <cstdint>
#include <vector>

namespace Engine
{
    class SoftwareTexture : public Texture
    {
    public:
        SoftwareTexture(Image Image);

        Color Sample(const Vector<2>& uv) const;
    
    private:
        Image image;
    };
}