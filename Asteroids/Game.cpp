#include "Game.h"

void Game::Update()
{
}

void Game::Render()
{

}

void Game::InitVariables()
{
	this->window = nullptr;
}

void Game::InitWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Asteroids", sf::Style::Titlebar | sf::Style::Close);
}

Game::Game()
{
	this->InitVariables(); //this function must be first, because of window being set to nullptr
	this->InitWindow();
}

Game::~Game()
{
	delete this->window;
}