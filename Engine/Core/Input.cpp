#include <Engine/Core/Input.hpp>

namespace Engine
{
    void Input::KeyDown(SDL_Scancode key)
    {
        keysDown.insert(key);
    }

    void Input::KeyUp(SDL_Scancode key)
    {
        keysDown.erase(key);
    }

    bool Input::IsKeyDown(SDL_Scancode key) const
    {
        return keysDown.contains(key);
    }
}