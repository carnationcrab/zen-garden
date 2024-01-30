//
// Created by carnationcrab on 1/30/2024.
//

#include <SDL.h>
#include <cstdio>
#include <string>

#ifndef ZEN_GARDEN_SCREEN_H
#define ZEN_GARDEN_SCREEN_H


class Screen {
public:
    Screen();
    ~Screen();

    bool init();
    bool loadMedia();
    void close();

    void handleEvents();
    void applyCurrentSurface();
    void updateWindowSurface();

private:
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    enum KeyPressSurfaces {
        KEY_PRESS_SURFACE_DEFAULT,
        KEY_PRESS_SURFACE_UP,
        KEY_PRESS_SURFACE_DOWN,
        KEY_PRESS_SURFACE_LEFT,
        KEY_PRESS_SURFACE_RIGHT,
        KEY_PRESS_SURFACE_TOTAL
    };

    SDL_Window* gWindow = nullptr;
    SDL_Surface* gScreenSurface = nullptr;
    SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
    SDL_Surface* gCurrentSurface = nullptr;

    static SDL_Surface* loadSurface(std::string path);
};

#endif //ZEN_GARDEN_SCREEN_H
