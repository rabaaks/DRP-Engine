#include <Engine/Scene/Entity.hpp>

namespace Engine
{
    template <typename T>
    T* Entity::GetComponent(const std::string& name)
    {
        return static_cast<T*>(components.at(name).get());
    }
}