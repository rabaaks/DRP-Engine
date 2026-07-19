#pragma once

#include <Engine/Window/Window.hpp>
#include <SDL3/SDL.h>
#include <cstdint>

namespace Engine
{
    class SDLWindow : public Window
    {
    public:
        SDLWindow(int width, int height, const char* title);
        ~SDLWindow();

        void PollEvents() override;
        bool ShouldClose() const override;
        void Present(const Framebuffer& framebuffer) const override;

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* texture;

        bool closed{false};

        int width;
        int height;
    };
}