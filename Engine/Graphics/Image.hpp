#pragma once

#include <Engine/Graphics/Color.hpp>

#include <cstdint>
#include <vector>

namespace Engine
{
    class Image
    {
    public:
        Image() = default;
        Image(int width, int height);

        int GetWidth() const;
        int GetHeight() const;
        Color& GetPixel(int x, int y);
        const Color& GetPixel(int x, int y) const;

        Color* Data();
        const Color* Data() const;

    private:
        int width;
        int height;

        std::vector<Color> pixels;
    };
}