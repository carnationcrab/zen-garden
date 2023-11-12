#include <SDL.h>
#include <cstdio>

// constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// SDL processes
bool init();
bool loadMedia();
void close();

// window, surface, background image
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gImageToLoad = NULL;

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "Zen Garden", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}

bool loadMedia()
{
    // flag
    bool success = true;

    // Load bg image
    gImageToLoad = SDL_LoadBMP("C:\\Users\\samma\\CLionProjects\\zen_garden\\hello_world.bmp" );
    if(gImageToLoad == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}

void close()
{
    //Deallocate surface, destroy windows, and quit SDL
    SDL_FreeSurface(gImageToLoad );
    SDL_DestroyWindow( gWindow );

    gImageToLoad = NULL;
    gWindow = NULL;

    SDL_Quit();
}

int main( int argc, char* args[] )
{
    // start up SDL, create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        // load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            // apply bg image
            SDL_BlitSurface(gImageToLoad, NULL, gScreenSurface, NULL );
            SDL_UpdateWindowSurface( gWindow );

            // hack to get window to stay up
            // THIS HAS GOT TO GO WHAT THE HECK IS THIS.
            SDL_Event e; bool quit = false; while( quit == false ) { while( SDL_PollEvent( &e )) { if( e.type == SDL_QUIT ) quit = true;}}
        }
    }

    // free resources, close SDL
    close();

    return 0;
}
