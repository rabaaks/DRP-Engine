#include <Engine/Window/SDLWindow.hpp>

#include <iostream>

namespace Engine
{
    SDLWindow::SDLWindow(int width, int height, const std::string& title) :
        width{width}, height{height}
    {
        !SDL_Init(SDL_INIT_VIDEO);

        window = SDL_CreateWindow(title.c_str(), width, height, 0);
        renderer = SDL_CreateRenderer(window, nullptr);
        texture = SDL_CreateTexture
        (
            renderer,
            SDL_PIXELFORMAT_ARGB8888,
            SDL_TEXTUREACCESS_STREAMING,
            width,
            height
        );
    }

    SDLWindow::~SDLWindow()
    {
        SDL_DestroyTexture(texture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void SDLWindow::PollEvents()
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                closed = true;
            }
        }
    }

    bool SDLWindow::ShouldClose() const
    {
        return closed;
    }

    int SDLWindow::GetWidth() const
    {
        return width;
    }

    int SDLWindow::GetHeight() const
    {
        return height;
    }

    void SDLWindow::Display(const Image& image) const
    {
        SDL_UpdateTexture
        (
            texture,
            nullptr,
            &image.Data().value,
            width * sizeof(uint32_t)
        );
        SDL_RenderTexture
        (
            renderer,
            texture,
            nullptr,
            nullptr
        );
        SDL_RenderPresent(renderer);
    }
}