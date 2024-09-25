#include "Bullet.h"


/*TODO
-Add initializing the bullet upon mouse click
*/
void Bullet::Update()
{
	//Bullet Movement
	this->bulletSprite.move(this->bulletSpeed*this->bulletDirection);
}
void Bullet::Render(sf::RenderTarget* target)
{
	target->draw(this->bulletSprite);
}
const sf::FloatRect Bullet::getBounds() const
{
	return this->bulletSprite.getGlobalBounds();
}
//Constructors
Bullet::Bullet()
{

}
Bullet::Bullet(sf::Texture* bTexture, float dirX, float dirY, float posX, float posY, float speed)
{
	this->bulletSprite.setTexture(*bTexture);
	this->bulletSprite.scale(0.015f,0.015f);
	this->bulletSprite.setPosition(posX, posY);
	this->bulletDirection.x = dirX;
	this->bulletDirection.y = dirY;
	this->bulletSpeed = speed;
}
//Destructor
Bullet::~Bullet()
{

}
