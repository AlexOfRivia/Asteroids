#include "Asteroid.h"


//Rendering asteroid object
void Asteroid::renderAsteroid(sf::RenderTarget* target)
{
	target->draw(this->asteroidSprite);
}

//Updating asteroid object
void Asteroid::updateAsteroid()
{
	this->asteroidSprite.move(this->asteroidSpeed * this->asteroidDirection);
}

//Constructors
Asteroid::Asteroid()
{

}

Asteroid::Asteroid(sf::Texture* aTexture, float posX, float posY, float dirX, float dirY, float speed)
{
	this->initVariables();
	this->asteroidSprite.setTexture(*aTexture);
	this->asteroidSprite.scale(0.25f, 0.25f);
	this->asteroidSprite.setPosition(posX, posY);
	this->asteroidDirection.x = dirX;
	this->asteroidDirection.y = dirY;
	this->asteroidSpeed = speed;
}

//Destructor
Asteroid::~Asteroid()
{

}

//Initializing asteroid variables
void Asteroid::initVariables()
{
	this->isdestroyed = false;
}