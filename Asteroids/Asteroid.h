#pragma once
#include <iostream>
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

/*TODO
- Add spawning asteroids, give them the player direction
- Add collisions with the player, destroy the asteroid and remove 1 health from player
- Add collisions with the bullet, destroy the bullet and add score to the player
*/

class Asteroid
{
public:
	//Public functions
	void renderAsteroid();
	void updateAsteroid();

	//Constructor and destructor
	Asteroid();
	~Asteroid();

private:

	//Asteroid parameters
	int health;
	bool isdestroyed;
	int damage;

	sf::Sprite asteroidSprite;
	sf::Texture asteroidTexture;

	//Private functions
	void initVariavles();
	void InitTexture();
	void InitSprite();
};

