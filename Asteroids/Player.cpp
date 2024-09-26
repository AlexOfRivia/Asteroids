#include "Player.h"


//Updating the player
void Player::updatePlayer(float dt, sf::RenderWindow* win)
{
	//General Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		this->playerMovement(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		this->playerMovement(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		this->playerMovement(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		this->playerMovement(0.f, 1.f);
	}

	this->updateCooldown();

	//Sprite rotation
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*win);
	this->playerRotation(dt, (sf::Vector2f)mousePosition);
}

const bool Player::canShoot()
{
	if(this->bulletCooldown >= this->bulletCooldownMax)
	{
		this->bulletCooldown = 0.f;
		return true;
	} 
	return false;
}

//Get players position for bullet Instantiating
const sf::Vector2f& Player::playerPos() const
{
	return this->playerSprite.getPosition(); 
}

//Rendering the player object
void Player::renderPlayer(sf::RenderTarget& target)
{
	target.draw(this->playerSprite);
}

//Updating the attack cooldown
void Player::updateCooldown()
{
	if(this->bulletCooldown < this->bulletCooldownMax)
	{
		this->bulletCooldown += 0.5f;
	}
}

void Player::initVariavles()
{
	this->bulletCooldownMax = 20.f;
	this->bulletCooldown = this->bulletCooldownMax;
}

//Initializing the player sprite
void Player::InitSprite()
{
	//Set texture to sprite
	this->playerSprite.setTexture(this->playerTexture);

	//Find Center of the sprite
	this->playerSprite.setOrigin(sf::Vector2f((float)this->playerSprite.getTexture()->getSize().x / 2, (float)this->playerSprite.getTexture()->getSize().y / 2));
	
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

//Player movement
void Player::playerMovement(const float& dirX, const float& dirY)
{
	this->playerSprite.move(this->movementSpeed*dirX,this->movementSpeed*dirY);
}

//Player rotation based on mouse position
void Player::playerRotation(float dt, sf::Vector2f mousePosition)
{
	auto playerPosition = this->playerSprite.getPosition();
	
	// vector pointing from center of player to mouse
	auto mouseDirection = mousePosition - playerPosition;

	// normalize the direction
	const float magnitude = sqrtf((mouseDirection.x * mouseDirection.x) + (mouseDirection.y * mouseDirection.y));

	mouseDirection.x /= magnitude;
	mouseDirection.y /= magnitude;

	// find angle using x-cord
	float angle = acosf(mouseDirection.x);
	// converting angle to deg
	angle *= (180.0f / 3.14159f);

	// check quadrant
	if (mouseDirection.y < 0.0f) angle = 360.0f - angle;

	this->playerSprite.setRotation(angle);
}

//Constructor
Player::Player()
{
	this->movementSpeed = 3.f;
	this->initVariavles();
	this->InitTexture(); //Texture should always be initialized first
	this->InitSprite();
}

//Destructor
Player::~Player()
{

}