#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Asteroids");

    /*BUILD PLAN
    - Add a working menu
    - Add Player and Asteroid Class
    - Add Player Movement
    - Add Shooting
    - Add Asteroid Movement
    - Add a Score System (Maybe a Health System Also?)*/


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(37, 37, 37, 0)); //Ciemniejszy kolor
        window.display();
    }

    return 0;
}