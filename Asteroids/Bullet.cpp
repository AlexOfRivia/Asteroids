#include "Bullet.h"



void Bullet::Update()
{
	//Bullet Movement
	this->bulletSprite.move(this->bulletSpeed*this->bulletDirection);
}

//Rendering the bullet sprite
void Bullet::Render(sf::RenderTarget* target)
{
	target->draw(this->bulletSprite);
}

const sf::FloatRect Bullet::getBounds() const
{
	return this->bulletSprite.getGlobalBounds();
}

const sf::Vector2f& Bullet::bulletPosition() const
{
	return this->bulletSprite.getPosition();
}

//Constructors
Bullet::Bullet()
{

}
Bullet::Bullet(sf::Texture* bTexture, float dirX, float dirY, float posX, float posY, float speed)
{
	this->bulletSprite.setTexture(*bTexture);
	this->bulletSprite.setPosition(posX, posY);
	this->bulletSprite.scale(0.02f,0.02f);
	this->bulletSprite.setOrigin(sf::Vector2f((float)this->bulletSprite.getTexture()->getSize().x / 2, (float)this->bulletSprite.getTexture()->getSize().y / 2));
	this->bulletDirection.x = dirX;
	this->bulletDirection.y = dirY;
	this->bulletSpeed = speed;

}
//Destructor
Bullet::~Bullet()
{

}
