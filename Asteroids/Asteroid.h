#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

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

