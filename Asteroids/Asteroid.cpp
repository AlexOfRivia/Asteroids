#include "Asteroid.h"


//Rendering asteroid object
void Asteroid::renderAsteroid()
{

}

//Updating asteroid object
void Asteroid::updateAsteroid()
{

}

//Constructor
Asteroid::Asteroid()
{

}

//Destructor
Asteroid::~Asteroid()
{

}

//Initializing asteroid variables
void Asteroid::initVariavles()
{
	this->isdestroyed = false;
}

//Initializing asteroid textures
void Asteroid::InitTexture()
{
	//Load Texture from file
	if (!this->asteroidTexture.loadFromFile("AsteroidSmall/Ship.png"))
	{
		std::cout << "ERROR: Unable to load player texture\n";
	}
}

//Initializing asteroid sprite
void Asteroid::InitSprite()
{
	this->asteroidSprite.setTexture(this->asteroidTexture);
	this->asteroidSprite.scale(0.10f, 0.10f);
}
