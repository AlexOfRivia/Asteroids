#pragma once
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

private:
	sf::Sprite playerSprite;
	sf::Texture payerTexture;

	//Private Functions
	void InitTexture();
	void InitSprite();

	//Constructor & Destructor
	Player();
	~Player();

};

