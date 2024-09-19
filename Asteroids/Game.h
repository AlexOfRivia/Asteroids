#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

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

	const bool isRunning() const;

	Game();
	~Game();

	private:
		sf::RenderWindow* window;
		sf::Event event;
		//private functions
		void InitVariables();
		void InitWindow();
};

