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
	this->textures["BULLET"] = new sf::Texture();
	if (!this->textures["BULLET"]->loadFromFile("Textures/bullet.png"))
		std::cout << "ERROR::GAME::INITTEXTURES::Couldn't load textures\n";
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
	this->initTextures();
	this->initPlayer();
}

// Destructor
Game::~Game()
{
	delete window;
	delete player;

	// Delete textures
	for (auto& i : this->textures)
	{
		delete i.second;
	}

	// Delete Bullets
	for (auto& i : this->bullets)
		delete i;
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


void Game::updateInput()
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

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(
			this->textures["BULLET"], this->player->getPos().x, this->player->getPos().y, 0, -1, 7
		));
	}
}

void Game::updateBullets()
{
	size_t count{};

	for (auto* bullet : this->bullets)
	{
		bullet->update();

		// Bullet culling (reached top of the screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			// Delete bullet
			delete this->bullets.at(count);
			this->bullets.erase(this->bullets.begin() + count);
			--count;
		}

		++count;
	}


}

// UPDATE
void Game::update()
{
	// POLLEVENTS
	this->pollEvents();

	this->updateInput();

	this->player->update();

	this->updateBullets();
}

// RENDER
void Game::render()
{
	this->window->clear();

	// Draw all stuff
	this->player->render(window);

	for (auto* bullet : this->bullets)
		bullet->render(this->window);


	this->window->display();
}
