#pragma once
#include <iostream>
#include <map>
#include "Player.h"
#include "Bullet.h"

/*
This class basically could be called a "Game engine".
In it, we are rendering everything that is going on in the game/app.
*/

class Game
{
	public:
	//public functions
	void updateEvents();
	void Update();
	void Render();


	//bool for checking if the window is runing
	const bool isRunning() const;

	//Constructor & Destructor
	Game();
	~Game();

	private:
	bool endGame;
	sf::RenderWindow* window;
	sf::Event event;
	
	//Player
	Player* player;

	//Resources
	std::map<std::string, sf::Texture*> loadTexture;

	//private functions
	void InitVariables();
	void InitWindow();
	void InitPlayer();
};