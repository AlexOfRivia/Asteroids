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

//Constructor
Player::Player()
{
	this->InitTexture(); //Texture should always be initialized first
	this->InitSprite();
}

//Destructor
Player::~Player()
{

}