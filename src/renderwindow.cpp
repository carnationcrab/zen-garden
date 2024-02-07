#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cassert>

#include "RenderWindow.hpp"
#include "Entity.hpp"

// Member initialization :window(nullptr), renderer(nullptr)
RenderWindow::RenderWindow(const char* p_title, int p_width, int p_height)
:window(nullptr), renderer(nullptr), refreshRate(60)
{
    assert(p_title && "Null title passed to RenderWindow constructor!");

    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width, p_height, SDL_WINDOW_SHOWN);

    assert(window && "SDL_CreateWindow failed to load window!");

    // Creates renderer. -1 chooses the first graphics driver that satisfies all requirements
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    assert(renderer && "SDL_CreateRenderer failed to create renderer!");
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
    assert(p_filePath && "Null file path passed to RenderWindow::loadTexture!");

    SDL_Texture* texture = IMG_LoadTexture(renderer, p_filePath);

    assert(texture && "SDL_Texture failed to load textures!");

    return texture;
}

// Gopher time
int RenderWindow::getRefreshRate()
{
    assert(window && "Null window in RenderWindow::getRefreshRate!");

    int displayIndex = SDL_GetWindowDisplayIndex(window);

    SDL_DisplayMode mode;

    SDL_GetDisplayMode(displayIndex, 0, &mode);

    assert(mode.refresh_rate >= 0 && "Negative refresh rate in RenderWindow::getRefreshRate!");

    return mode.refresh_rate;
}

void RenderWindow::clear()
{
    assert(renderer && "Null renderer in RenderWindow::clear!");

    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_entity)
{
    assert(renderer && "Null renderer in RenderWindow::render!");

    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_entity.getPos().x * 4;
    dst.y = p_entity.getPos().y * 4;
    dst.w = p_entity.getCurrentFrame().w * 4;
    dst.h = p_entity.getCurrentFrame().h * 4;

    SDL_RenderCopy(renderer, p_entity.getTx(), &src, &dst);
}

void RenderWindow::display()
{
    assert(renderer && "Null renderer in RenderWindow::display!");

    SDL_RenderPresent(renderer);
}

// On quit
void RenderWindow::destroyWindow()
{
    assert(window && "Null window in RenderWindow::destroyWindow!");

    SDL_DestroyWindow(window);
}