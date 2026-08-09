#include <Engine/Assets/ImageLoader.hpp>
#include <Engine/Graphics/Color.hpp>
#include <Engine/Graphics/Image.hpp>

#include <SDL3_image/SDL_image.h>

#include <cstddef>
#include <cstring>

namespace Engine
{
    void ImageLoader::Load(std::filesystem::path path, void* object)
    {
        SDL_Surface* loaded{IMG_Load(path.string().c_str())};
        SDL_Surface* surface{SDL_ConvertSurface(loaded, SDL_PIXELFORMAT_ARGB8888)};

        Image& image{*static_cast<Image*>(object)};
        image = Image{surface->w, surface->h};
        Color* pixelsPtr{image.Data()};

        std::size_t rowSize = surface->w * sizeof(Color);
        for (int y{}; y < surface->h; ++y)
        {
            std::memcpy
            (
                pixelsPtr + y * rowSize,
                static_cast<Color*>(surface->pixels) + y * surface->pitch,
                rowSize
            );
        }
    }
}