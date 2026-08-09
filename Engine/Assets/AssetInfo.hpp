#pragma once

#include <filesystem>
#include <typeindex>

namespace Engine
{
    // Type isn't stored as template because all asset infos are stored in single container
    struct AssetInfo
    {
        std::filesystem::path path;
        std::type_index type{typeid(void)};
    };
}