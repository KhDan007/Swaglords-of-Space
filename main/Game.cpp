#include "Game.h"
// INIT
// VARIABLES
void Game::initVariables()
{
	this->isEndgame = false;
}

// WINDOW
void Game::initWindow()
{
	this->videomode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videomode, "Swaglords of Space!", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	// INIT TEXTURES
}

void Game::initPlayer()
{
	this->player = new Player;
}

// Constructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initPlayer();
}

// Destructor
Game::~Game()
{
	delete window;
	delete player;
}

// Functions
// Run functon
void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

// Poll events
void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
		}
	}
}


void Game::updateMove()
{
	// Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);
}

// UPDATE
void Game::update()
{
	// POLLEVENTS
	this->pollEvents();


	this->updateMove();
}

// RENDER
void Game::render()
{
	this->window->clear();

	// Draw all stuff
	this->player->render(window);


	this->window->display();
}
