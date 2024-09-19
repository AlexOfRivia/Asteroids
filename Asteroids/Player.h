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
	void updatePlayer();
	void renderPlayer(sf::RenderTarget& target);

	//Constructor & Destructor
	Player();
	~Player();

private:
	sf::Sprite playerSprite;
	sf::Texture playerTexture;

	//Private Functions
	void InitTexture();
	void InitSprite();


};

