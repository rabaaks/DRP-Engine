#include <Engine/Graphics/SoftwareTexture.hpp>

#include <algorithm>
#include <utility>

namespace Engine
{
    SoftwareTexture::SoftwareTexture(Image image) : image{std::move(image)}
    {

    }

    Color SoftwareTexture::Sample(const Vector<2>& uv) const
    {
        return image.GetPixel
        (
            static_cast<std::uint32_t>(uv.x * (image.GetWidth() - 1)),
            static_cast<std::uint32_t>(uv.y * (image.GetHeight() - 1))
        );
    }
}