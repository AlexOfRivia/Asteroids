#include "Game.h"

//Checking wether the window is running
const bool Game::isRunning() const
{
	return this->window->isOpen();
}

//Updating
void Game::Update()
{
	this->updateEvents();
}

//Updating pollEvents
void Game::updateEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}

	//Player Movement will go here
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		this->player->playerMovement(-1.f,0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		this->player->playerMovement(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		this->player->playerMovement(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		this->player->playerMovement(0.f, 1.f);
	}
}

//Rendering
void Game::Render()
{
	this->window->clear(sf::Color(37,37,37,0)); //Clears old frame
	//Rendering(drawing) the objects
	this->player->renderPlayer(*this->window);
	this->window->display(); //Displays new frame
}

//Initializing the variables
void Game::InitVariables()
{
	this->window = nullptr;
}

//Initializing the player object
void Game::InitPlayer()
{
	this->player = new Player();
}

//Initializing the window
void Game::InitWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Asteroids", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

//Constructor
Game::Game()
{
	this->InitVariables(); //this function must be first, because of window being set to nullptr
	this->InitWindow();
	this->InitPlayer();
}

//Destructor
Game::~Game()
{
	delete this->window;
	delete this->player;
}