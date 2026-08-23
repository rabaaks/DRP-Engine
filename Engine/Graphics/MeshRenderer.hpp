#pragma once

#include <Engine/Assets/Asset.hpp>
#include <Engine/Graphics/Model.hpp>

namespace Engine
{
    struct MeshRenderer
    {
        Asset<Model> model;
    };
}