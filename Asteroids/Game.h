#pragma once
#include <iostream>
#include "Player.h"

/*
This class basically acts as a game engine
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

	//private functions
	void InitVariables();
	void InitWindow();
	void InitPlayer();
};