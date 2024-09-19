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

    //Main Window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Asteroids", sf::Style::Titlebar | sf::Style::Close);

    //Application(Game) Loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(37, 37, 37, 0)); //Clears old frame

        window.display();
    }

    return 0;
}