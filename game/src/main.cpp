#include <Game.h>
#include "settings.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // init game object
    Game game{ screenWidth,screenHeight,fps,"game" };
    while (!game.gameShouldClose())
    {
        game.tick();
    }

    return 0;
}