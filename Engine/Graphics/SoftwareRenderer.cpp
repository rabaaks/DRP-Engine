#include <Engine/Graphics/SoftwareRenderer.hpp>
#include <Engine/Graphics/Triangle.hpp>
#include <Engine/Graphics/Vertex.hpp>

#include <Engine/Math/Vector.hpp>

#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <utility>

namespace Engine
{
    SoftwareRenderer::SoftwareRenderer(const SDLWindow& window) :
        image{window.GetWidth(), window.GetHeight()}, window{window}
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

    void SoftwareRenderer::DrawLine(Vector<2> from, Vector<2> to)
    {
        int x0{static_cast<int>(from.x)};
        int y0{static_cast<int>(from.y)};
        int x1{static_cast<int>(to.x)};
        int y1{static_cast<int>(to.y)};

        int dx{std::abs(x1 - x0)};
        int dy{-std::abs(y1 - y0)};
        int stepX{x0 < x1 ? 1 : -1};
        int stepY{y0 < y1 ? 1 : -1};
        int error{dx + dy};

        while (true)
        {
            if (x0 >= 0 && x0 < image.GetWidth() && y0 >= 0 && y0 < image.GetHeight())
            {
                image.GetPixel(x0, y0).value = 0xFFFFFFFF;
            }

            if (x0 == x1 && y0 == y1) break;

            int doubleError{2 * error};
            if (doubleError >= dy)
            {
                error += dy;
                x0 += stepX;
            }
            if (doubleError <= dx)
            {
                error += dx;
                y0 += stepY;
            }
        }
    }

    void SoftwareRenderer::DrawMesh(Mesh mesh, Transform transform)
    {
        float angleOfViewHorizontal = camera.fieldOfView * M_PI / 180;
        // Derive the vertical FOV from the horizontal FOV and the camera's aspect ratio
        float angleofViewVertical = 2 * atan(tan(angleOfViewHorizontal / 2) / camera.aspectRatio);

        float right = tan(angleOfViewHorizontal / 2) * camera.nearPlane;
        float top = tan(angleofViewVertical / 2) * camera.nearPlane;
        float left = -right;
        float bottom = -top;

        Matrix<4> modelMatrix{transform.GetMatrix()};

        for (Triangle triangle : mesh.triangles)
        {
            Vector<2> screenPositions[3];

            for (std::size_t i{}; i < 3; i++)
            {
                Vertex vertex{mesh.vertices[triangle.indices[i]]};
                Vector<4> local{vertex.position.x, vertex.position.y, vertex.position.z, 1.0f};
                Vector<4> world{modelMatrix * local};

                // Only the camera's position is applied here, not its rotation - the camera
                // is assumed to be looking straight down +Z in world space for now
                Vector<3> viewPosition
                {
                    world.x - camera.transform.position.x,
                    world.y - camera.transform.position.y,
                    camera.transform.position.z - world.z
                };

                Vector<2> screen
                {
                    camera.nearPlane * viewPosition.x / -viewPosition.z,
                    camera.nearPlane * viewPosition.y / -viewPosition.z
                };

                Vector<2> ndc
                {
                    2 * screen.x / (right - left) - (right + left) / (right - left),
                    2 * screen.y / (top - bottom) - (top + bottom) / (top - bottom)
                };

                screenPositions[i] =
                {
                    (ndc.x + 1) / 2 * image.GetWidth(),
                    (1 - ndc.y) / 2 * image.GetHeight()
                };
            }

            DrawLine(screenPositions[0], screenPositions[1]);
            DrawLine(screenPositions[1], screenPositions[2]);
            DrawLine(screenPositions[2], screenPositions[0]);
        }
    }

    void SoftwareRenderer::ShowFrame()
    {
        window.Display(image);
    }
}