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
//Constructors
Bullet::Bullet()
{

}
Bullet::Bullet(sf::Texture & bTexture, float dirX, float dirY, float speed)
{
	this->bulletSprite.setTexture(bTexture);
	this->bulletDirection.x = dirX;
	this->bulletDirection.y = dirY;
	this->bulletSpeed = speed;
}
//Destructor
Bullet::~Bullet()
{

}
