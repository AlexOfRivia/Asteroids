#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class Bullet
{
private:
	sf::Sprite bulletSprite;
	sf::Texture* bulletTexture;
	sf::Vector2f bulletDirection;
	float bulletSpeed;
	int damage;

public:
	void Update();
	void Render(sf::RenderTarget* target);
	//Constructors & Destructor
	Bullet();
	Bullet(sf::Texture* bTexture, float dirX, float dirY, float posX, float posY, float speed);
	~Bullet();
};

