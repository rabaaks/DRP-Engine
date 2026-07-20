#include <Engine/Graphics/Framebuffer.hpp>

namespace Engine
{
    Framebuffer::Framebuffer(int width, int height)
        : width(width), height(height), pixels(width * height) 
    {

    }

    uint32_t* Framebuffer::Data()
    {
        return pixels.data();
    }

    const uint32_t* Framebuffer::Data() const
    {
        return pixels.data();
    }
}