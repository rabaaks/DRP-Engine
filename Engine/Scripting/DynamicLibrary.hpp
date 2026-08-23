#pragma once

#include <filesystem>
#include <string>

namespace Engine
{
    class DynamicLibrary
    {
    public:
        DynamicLibrary(std::filesystem::path path);
        ~DynamicLibrary();

        void* GetSymbol(const std::string& name) const;
    
    private:
        // void* so it could later be used on other os
        void* handle;
    };
}