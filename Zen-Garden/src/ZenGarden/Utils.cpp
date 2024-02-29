#include <SDL.h>

#include "Utils.h"

// reciprocal multiplication is faster than division
float utils::TimeInSeconds()
{
    static const float kTicksToSeconds = 1.0f / 1000.0f;
    return static_cast<float>(SDL_GetTicks()) * kTicksToSeconds;
}
