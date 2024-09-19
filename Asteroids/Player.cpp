#include "Player.h"


//Updating the player
void Player::updatePlayer()
{

}

//Rendering the player object
void Player::renderPlayer(sf::RenderTarget& target)
{
	target.draw(this->playerSprite);
}

//Initializing the player sprite
void Player::InitSprite()
{
	//Set texture to sprite
	this->playerSprite.setTexture(this->playerTexture);
	//Resizing Sprite
	this->playerSprite.scale(0.10f,0.10f);
}

//Initializing the player texture
void Player::InitTexture()
{
	//Load Texture from file
	if (!this->playerTexture.loadFromFile("Textures/Ship.png"))
	{
		std::cout << "ERROR: Unable to load player texture\n";
	} 
}

/*TODO
Improve player movement:
- A Key to move forward
- Use mouse to choose direction & initialize projectiles*/

//Player movement
void Player::playerMovement(const float& dirX, const float& dirY)
{
	this->playerSprite.move(this->movementSpeed*dirX,this->movementSpeed*dirY);
}

//Constructor
Player::Player()
{
	this->movementSpeed = 5.f;

	this->InitTexture(); //Texture should always be initialized first
	this->InitSprite();
}

//Destructor
Player::~Player()
{

}