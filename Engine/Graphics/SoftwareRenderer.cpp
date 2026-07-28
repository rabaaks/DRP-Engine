#include <Engine/Graphics/SoftwareRenderer.hpp>
#include <Engine/Graphics/Triangle.hpp>
#include <Engine/Graphics/Vertex.hpp>

#include <Engine/Math/Vector.hpp>

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

        this->camera = camera;
    }

    void SoftwareRenderer::DrawMesh(Mesh mesh, Transform transform, Material material)
    {
        float angleOfViewHorizontal = camera.fieldOfView * M_PI / 180;
        float angleofViewVertical = camera.fieldOfView * M_PI / 180 * image.GetWidth() / image.GetHeight();

        float right = tan(angleOfViewHorizontal / 2) * camera.nearPlane;
        float top = tan(angleofViewVertical / 2) * camera.nearPlane;
        float left = -right;
        float bottom = -top;

        for (Triangle triangle : mesh.triangles)
        {
            for (Vertex vertex : triangle.vertices)
            {
                Vector<2> screen
                {
                    camera.nearPlane * vertex.position.x / -vertex.position.z,
                    camera.nearPlane * vertex.position.y / -vertex.position.z
                };

                Vector<2> ndc
                {
                    2 * screen.x / (right - left) - (right + left) / (right - left),
                    2 * screen.y / (top - bottom) - (top + bottom) / (top - bottom)
                };

                Vector<3> raster
                {
                    (ndc.x + 1) / 2 * image.GetWidth(),
                    (1 - ndc.y) / 2 * image.GetHeight(),
                    -vertex.position.z
                };
            }
        }
    }

    void SoftwareRenderer::ShowFrame()
    {
        uint32_t* pixels = &image.Data().value;

        int width = image.GetWidth();
        int height = image.GetHeight();

        for (int i{}; i < width * height; ++i) {
            int distance = std::sqrt(std::pow(i % width, 2) + std::pow(i / width, 2));
            distance %= 100;
            pixels[i] = (0xFF << 24) | ((uint8_t) (sin(distance * 0.05f) * 127 + 128) << 16) | ((uint8_t) (sin(distance * 0.05f + 2.09f) * 127 + 128) << 8) | ((uint8_t) (sin(distance * 0.05f + 4.19f) * 127 + 128) << 0); 
        }

        window.Display(image);
    }
}