#pragma once

namespace Engine
{
    class Renderer
    {
    public:
        virtual ~Renderer() = default;
        
        virtual void Render() = 0;
    };
}