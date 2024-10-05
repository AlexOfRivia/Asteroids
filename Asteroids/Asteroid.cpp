#include "Asteroid.h"


//Rendering asteroid object
void Asteroid::renderAsteroid(sf::RenderTarget* target)
{
	target->draw(this->asteroidSprite);
	target->draw(this->asteroidShape);
}

//Updating asteroid object
void Asteroid::updateAsteroid()
{
	this->asteroidSprite.move(this->asteroidSpeed * this->asteroidDirection);
	this->asteroidShape.move(this->asteroidSpeed * this->asteroidDirection);
}

const sf::FloatRect Asteroid::getAsteroidBounds() const
{
	return this->asteroidShape.getGlobalBounds();
}

void Asteroid::destroyAsteroid(sf::Texture asTexture)
{
	if (asTexture.loadFromFile("Textures/AsteroidSmall.png"))
	{
		this->player->addScore(100);
	}
	if (asTexture.loadFromFile("Textures/AsteroidMedium.png"))
	{
		this->player->addScore(200);
	}
	if (asTexture.loadFromFile("Textures/AsteroidBig.png"))
	{
		this->player->addScore(400);
	}
}

const sf::Vector2f& Asteroid::asteroidPosition() const
{
	return this->asteroidSprite.getPosition();
}

//Constructors
Asteroid::Asteroid()
{

}

Asteroid::Asteroid(sf::Texture* aTexture, float posX, float posY, float dirX, float dirY, float speed)
{
	//Asteroid Sprite
	this->asteroidSprite.setTexture(*aTexture);
	this->asteroidSprite.setPosition(posX, posY);
	this->asteroidSprite.setOrigin(sf::Vector2f((float)this->asteroidSprite.getTexture()->getSize().x / 2, (float)this->asteroidSprite.getTexture()->getSize().y / 2));
	
	//Asteroid Shape
	this->asteroidShape.setRadius((float)this->asteroidSprite.getTexture()->getSize().x / 2);
	this->asteroidShape.setPointCount(4);
	this->asteroidShape.setOrigin(sf::Vector2f((float)this->asteroidSprite.getTexture()->getSize().x / 2, (float)this->asteroidSprite.getTexture()->getSize().y / 2));
	this->asteroidShape.setPosition(posX, posY);
	
	this->asteroidDirection.x = dirX;
	this->asteroidDirection.y = dirY;
	this->asteroidSpeed = speed;
}

//Destructor
Asteroid::~Asteroid()
{

}
