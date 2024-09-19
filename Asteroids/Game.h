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
	void Update();
	void Render();
	Game();
	~Game();

	private:
		sf::RenderWindow* window;
		sf::Event event;
		void InitVariables();
		void InitWindow();
};

