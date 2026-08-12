#pragma once

#include <Engine/Assets/FileLoader.hpp>

namespace Engine
{
    class ModelLoader : public FileLoader
    {
    public:
        void Load(std::filesystem::path path, void* object) override;
    };
}