#pragma once
#include <iostream>
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

/*TODO
- Add collisions with the player, destroy the asteroid and remove 1 health from player
- Add collisions with the bullet, destroy the bullet and add score to the player
- Add a function which takes the current texture and uses it in a switch 
*/

class Asteroid
{
public:
	//Public functions
	void renderAsteroid(sf::RenderTarget* target);
	void updateAsteroid();
	void destroyAsteroid(sf::Texture asTexture);
	const sf::Vector2f& asteroidPosition() const;
	const sf::FloatRect getAsteroidBounds() const;

	//Constructor and destructor
	Asteroid();
	Asteroid(sf::Texture* aTexture, float posX, float posY, float dirX, float dirY, float speed);
	~Asteroid();

private:

	//Asteroid parameters
	int health;
	int damage;
	float asteroidSpeed;

	//player
	Player* player;

	sf::Sprite asteroidSprite;
	sf::Texture* asteroidTexture;
	sf::Vector2f asteroidDirection;
};

