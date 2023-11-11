#include <iostream>
#include <SDL.h>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Quit();
    std::cout << "MAIN: Hello." << std::endl;
    return 0;
}
