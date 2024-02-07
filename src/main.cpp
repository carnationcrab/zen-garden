#include "Game.hpp"

int main(int argc, char* args[])
{
    try
    {
        Game game;
        game.run();
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
        return -1;
    }
}