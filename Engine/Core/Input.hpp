#pragma once

#include <SDL3/SDL.h>

#include <unordered_set>

namespace Engine
{
    class Input
    {
    public:
        void KeyDown(SDL_Scancode key);
        void KeyUp(SDL_Scancode key);

        bool IsKeyDown(SDL_Scancode key) const;
    
    private:
        // Don't need to be ordered
        std::unordered_set<SDL_Scancode> keysDown;
    };
}