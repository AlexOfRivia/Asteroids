#pragma once
#include <iostream>
#include <map>
#include <ctime>
#include "Player.h"
#include "Bullet.h"
#include "Asteroid.h"

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
	float spawnTimer;
	float spawnTimerMax;

	std::map<std::string, sf::Texture*> loadTexture;
	sf::Texture asteroidTextures[3];
	std::vector<Bullet*> bullets;
	std::vector<Asteroid*> asteroids;

	//private functions
	void InitVariables();
	void InitTextures();
	void bulletUpdates();
	void asteroidUpdates();
	void InitWindow();
	void InitPlayer();
};