#pragma once
#include <iostream>
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

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
	sf::CircleShape asteroidShape;
	int health;
	int damage;
	float asteroidSpeed;

	//player
	Player* player;

	sf::Sprite asteroidSprite;
	sf::Texture* asteroidTexture;
	sf::Vector2f asteroidDirection;
};

