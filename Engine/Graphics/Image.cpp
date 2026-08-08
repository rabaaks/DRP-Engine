#include <Engine/Graphics/Image.hpp>

#include <cstddef>

namespace Engine
{
    Image::Image(int width, int height) :
        width{width}, height{height}, pixels{static_cast<std::size_t>(width * height)}
    {

    }

    int Image::GetWidth() const
    {
        return width;
    }

    int Image::GetHeight() const
    {
        return height;
    }

    Color& Image::GetPixel(int x, int y)
    {
        return pixels[y * width + x];
    }

    const Color& Image::GetPixel(int x, int y) const
    {
        return pixels[y * width + x];
    }

    Color& Image::Data()
    {
        return pixels.front();
    }

    const Color& Image::Data() const
    {
        return pixels.front();
    }
}