#pragma once

#include <Engine/Assets/AssetType.hpp>

#include <filesystem>

namespace Engine
{
    // Type isn't stored as template because all asset infos are stored in single container
    struct AssetInfo
    {
        std::filesystem::path path;
        AssetType type;
    };
}