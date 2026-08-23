#pragma once

#include <Engine/Scene/ComponentInfo.hpp>

namespace Engine
{
    class ComponentManager
    {
    public:
        template <typename T>
        void AddComponent(const std::string& name);
    }
}