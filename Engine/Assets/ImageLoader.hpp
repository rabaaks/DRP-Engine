#pragma once

#include <Engine/Assets/FileLoader.hpp>

namespace Engine
{
    class ImageLoader : public FileLoader
    {
    public:
        void Load(std::filesystem::path path, void* object) override;
    };
}