#include <iostream>
#include "Game.h"

int main()
{

    /*BUILD PLAN
    - Add a working menu
    - Add Player and Asteroid Class
    - Add Player Movement
    - Add Shooting
    - Add Asteroid Movement
    - Add a Score System (Maybe a Health System Also?)*/

    //Initializing a Game Object
    Game game;

    //Application(Game) Loop
    while(game.isRunning())
    { 
        //Update
        game.Update();
        //Rendering
        game.Render();
    }

    return 0;
}