#include "Utils.hpp"
#include <SDL2/SDL.h>

float utils::TimeInSeconds()
{
    return static_cast<float>(SDL_GetTicks()) / 1000.0f;
}