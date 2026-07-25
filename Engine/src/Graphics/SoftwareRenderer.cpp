#include <Engine/Graphics/SoftwareRenderer.hpp>

#include <cmath>
#include <utility>

namespace Engine
{
    SoftwareRenderer::SoftwareRenderer(Image image, const SDLWindow& window)
        : image(std::move(image)), window(window)
    {

    }

    void SoftwareRenderer::BeginFrame(const Camera& camera)
    {
        for (int x{}; x < image.GetWidth(); x++)
        {
            for (int y{}; y < image.GetHeight(); y++)
            {
                image.GetPixel(x, y).value = 0;
            }
        }
    }

    void SoftwareRenderer::DrawMesh(Mesh mesh, Transform transform, Material material)
    {
        
    }

    void SoftwareRenderer::ShowFrame()
    {
        uint32_t* pixels = &image.Data().value;

        int width = image.GetWidth();
        int height = image.GetHeight();

        for (int i{}; i < width * height; i++) {
            int distance = std::sqrt(std::pow(i % width, 2) + std::pow(i / width, 2));
            distance %= 100;
            pixels[i] = (0xFF << 24) | ((uint8_t) (sin(distance * 0.05f) * 127 + 128) << 16) | ((uint8_t) (sin(distance * 0.05f + 2.09f) * 127 + 128) << 8) | ((uint8_t) (sin(distance * 0.05f + 4.19f) * 127 + 128) << 0); 
        }

        window.Display(image);
    }
}