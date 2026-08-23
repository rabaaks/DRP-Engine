#include <Engine/Scripting/DynamicLibrary.hpp>

#include <windows.h>

namespace Engine
{
    DynamicLibrary::DynamicLibrary(std::filesystem::path path)
    {
        handle = LoadLibraryW(path.wstring().c_str());
    }

    DynamicLibrary::~DynamicLibrary()
    {
        FreeLibrary(static_cast<HMODULE>(handle));
    }

    void* DynamicLibrary::GetSymbol(const std::string& name) const
    {
        return reinterpret_cast<void*>(GetProcAddress(static_cast<HMODULE>(handle), name.c_str()));
    }
}