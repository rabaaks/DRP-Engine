#pragma once

#include <Engine/Core/Input.hpp>
#include <Engine/Scene/Entity.hpp>

namespace Engine
{
    
    // Interface that is extended by user defined scripts
    class Script
    {
    public:
        virtual ~Script() = default;

        virtual void Create(Entity& entity) = 0;
        virtual void Update(Entity& entity, const Input& input, float deltaTime) = 0;
        virtual void Destroy(Entity& entity) = 0;
    };
}