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

	sf::Clock clock;
	float dt = clock.restart().asSeconds();
	//Next four lines are to get the mouse direction for the bullets
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*this->window);
	auto playerPosition = this->player->playerPos();
	auto mouseDirection = (sf::Vector2f)mousePosition - playerPosition;
	const float magnitude = sqrtf((mouseDirection.x * mouseDirection.x) + (mouseDirection.y * mouseDirection.y));

	//Player Movement
	this->player->updatePlayer(dt, this->window);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canShoot())
	{
		this->bullets.push_back(new Bullet(this->loadTexture["Bullet"], (mouseDirection.x /= magnitude), (mouseDirection.y /= magnitude), this->player->playerPos().x, this->player->playerPos().y, 6.f));
	}
	this->bulletUpdates();
}

void Game::bulletUpdates()
{
	unsigned counter = 0;
	//Rendering the bullets
	for (auto* bullet : this->bullets)
	{
		bullet->Update();

		//Removing bullet, when not visible
		if (bullet->getBounds().top+bullet->getBounds().height < 0.f || bullet->getBounds().left + bullet->getBounds().width < 0.f)
		{
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin()+counter);
			--counter; //Bullet deleted
			std::cout << "Bullet deleted\n";
		}
		++counter;
	}
}

//Rendering
void Game::Render()
{
	this->window->clear(sf::Color(37,37,37,0)); //Clears old frame
	//Rendering(drawing) the objects
	this->player->renderPlayer(*this->window);
	//Rendering the bullets
	for (auto* bullet : this->bullets)
	{
		bullet->Render(this->window);
	}
	this->window->display(); //Displays new frame
}

//Initializing the variables
void Game::InitVariables()
{
	this->window = nullptr;
}

void Game::InitTextures()
{
	this->loadTexture["Bullet"] = new sf::Texture();
	this->loadTexture["Bullet"]->loadFromFile("Textures/Bullet.png");

	//Small asteroid texture
	this->loadTexture["smallAsteroid"] = new sf::Texture();
	this->loadTexture["smallAsteroid"]->loadFromFile("Textures/AsteroidSmall.png");
	//Medium asteroid texture
	this->loadTexture["mediumAsteroid"] = new sf::Texture();
	this->loadTexture["mediumAsteroid"]->loadFromFile("Textures/AsteroidMedium.png");
	//Big asteroid texture
	this->loadTexture["bigAsteroid"] = new sf::Texture();
	this->loadTexture["bigAsteroid"]->loadFromFile("Textures/AsteroidBig.png");
}


//Initializing the player object
void Game::InitPlayer()
{
	this->player = new Player(this->window);
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
	this->InitTextures();
	this->InitPlayer();
}

//Destructor
Game::~Game()
{
	delete this->window;
	delete this->player;

	//Deleting textures
	for( auto &i : this->loadTexture)
	{
		delete i.second;
	}

	//Deleting bullets
	for (auto* i: this->bullets)
	{
		delete i;
	}

	//Deleting asteroids
	for (auto* i : this->asteroids)
	{
		delete i;
	}
}