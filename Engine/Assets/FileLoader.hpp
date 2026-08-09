#pragma once

#include <filesystem>

namespace Engine
{
    class FileLoader
    {
        public:
            virtual ~FileLoader() = default;

            virtual void Load(std::filesystem::path path, void* object) = 0;
    };
}