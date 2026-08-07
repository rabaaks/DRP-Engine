#pragma once

#include <string>

namespace Engine
{
    // Type isn't stored as template because all asset infos are stored in single container
    struct AssetInfo
    {
        std::string path;
        std::string type;
    };
}