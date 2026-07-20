#include <Engine/Graphics/SoftwareRenderer.hpp>
#include <cmath>

namespace Engine
{
    SoftwareRenderer::SoftwareRenderer(int width, int height, const Window& window)
        : width(width), height(height), framebuffer(width, height), window(window)
    {

    }

    void SoftwareRenderer::BeginFrame(Camera camera)
    {

    }

    void SoftwareRenderer::DrawMesh(Mesh mesh, Transform<3> transform, Material material)
    {

    }

    void SoftwareRenderer::ShowFrame()
    {
        uint32_t* pixels = framebuffer.Data();

        for (int i{}; i < width * height; i++) {
            int distance = std::sqrt(std::pow(i % width, 2) + std::pow(i / width, 2));
            distance %= 100;
            pixels[i] = (0xFF << 24) | ((uint8_t) (sin(distance * 0.05f) * 127 + 128) << 16) | ((uint8_t) (sin(distance * 0.05f + 2.09f) * 127 + 128) << 8) | ((uint8_t) (sin(distance * 0.05f + 4.19f) * 127 + 128) << 0); 
        }

        window.Display(framebuffer);
    }
}