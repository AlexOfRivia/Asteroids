#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


class Player
{
public:
	//Public Functions
	void playerMovement(const float& dirX, const float& dirY);
	void playerRotation(float dt, sf::Vector2f mousePosition);
	void updatePlayer(float dt, sf::RenderWindow* win); //This function is for controlling the player basically - it makes the process of adding new controlls easier
	void renderPlayer(sf::RenderTarget& target);

	const sf::Vector2f& playerPos() const;

	const bool canShoot();

	//Constructor & Destructor
	Player();
	~Player();

private:
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
	
	//Attack Cooldown
	float bulletCooldown;
	float bulletCooldownMax; //Whenever the max is hit, you can shoot the bullet again

	float movementSpeed;

	int playerHealth;
	int score;

	//Private Functions
	void addScore(int &points);
	void updateCooldown();
	void initVariavles();
	void InitTexture();
	void InitSprite();


};

