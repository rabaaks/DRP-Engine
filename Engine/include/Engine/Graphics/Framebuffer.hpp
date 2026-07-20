#pragma once

#include <cstdint>
#include <vector>

namespace Engine
{
    class Framebuffer
    {
    public:
        Framebuffer(int width, int height);

        uint32_t* Data();
        const uint32_t* Data() const;
    
    private:
        int width;
        int height;

        std::vector<uint32_t> pixels;
    };
}