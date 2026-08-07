#include <Engine/Graphics/SoftwareRenderer.hpp>
#include <Engine/Graphics/Triangle.hpp>
#include <Engine/Graphics/Vertex.hpp>

#include <Engine/Math/Vector.hpp>

#include <cmath>
#include <cstddef>
#include <utility>

namespace Engine
{
    SoftwareRenderer::SoftwareRenderer(const SDLWindow& window)
        : image{window.GetWidth(), window.GetHeight()}, window{window}
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

    void SoftwareRenderer::DrawMesh(Mesh mesh, Transform transform)
    {
        float angleOfViewHorizontal = camera.fieldOfView * M_PI / 180;
        float angleofViewVertical = atan(tan(camera.fieldOfView / 2) / image.GetWidth() / image.GetHeight());

        float right = tan(angleOfViewHorizontal / 2) * camera.nearPlane;
        float top = tan(angleofViewVertical / 2) * camera.nearPlane;
        float left = -right;
        float bottom = -top;

        for (Triangle triangle : mesh.triangles)
        {
            for (std::size_t i{}; i < 3; i++)
            {
                Vertex vertex{mesh.vertices[triangle.indices[i]]};
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

                image.GetPixel(static_cast<int>(raster.x), static_cast<int>(raster.y)).value = 0xFFFFFFFF;
            }
        }
    }

    void SoftwareRenderer::ShowFrame()
    {
        uint32_t* pixels = &image.Data().value;

        window.Display(image);
    }
}