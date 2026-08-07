#pragma once

#include <Engine/Graphics/Image.hpp>
#include <Engine/Window/Window.hpp>

#include <SDL3/SDL.h>

#include <cstdint>
#include <string>

namespace Engine
{
    class SDLWindow : public Window
    {
    public:
        SDLWindow(int width, int height, const std::string& title);
        ~SDLWindow();

        void PollEvents() override;
        bool ShouldClose() const override;

        int GetWidth() const override;
        int GetHeight() const override;

        void Display(const Image& image) const;

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* texture;

        bool closed{false};

        int width;
        int height;
    };
}