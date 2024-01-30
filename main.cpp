#include <SDL.h>
#include <cstdio>

#include "Screen.h"

int main( int argc, char* args[] )
{
    Screen screen;

    //Event handler
    SDL_Event e;

    if (!screen.init()) {
        printf("Failed to initialize!\n");
    } else {
        if (!screen.loadMedia()) {
            printf("Failed to load media!\n");
        } else {
            bool quit = false;

            while (!quit) {
                //User requests quit
                if( e.type == SDL_QUIT ) {
                    quit = true;
                }

                screen.handleEvents();
                screen.applyCurrentSurface();
                screen.updateWindowSurface();
            }
        }
    }

    return 0;
}
