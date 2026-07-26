#include <Engine/Graphics/Camera.hpp>

namespace Engine
{
    Camera::Camera(Transform transform, float fieldOfView, float aspectRatio)
        : transform(transform), fieldOfView(fieldOfView), aspectRatio(aspectRatio)
    {
        
    }
}