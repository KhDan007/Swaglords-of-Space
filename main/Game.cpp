#include "Game.h"
// INIT
// INIT VARIABLES
void Game::initVariables()
{
	this->isEndgame = false;
	this->points = 0;
	this->bulletSpeed = 10.f;
}

// INIT WINDOW
void Game::initWindow()
{
	// Size of the window
	this->videomode = sf::VideoMode(800, 600);
	
	// Name, style of the window
	this->window = new sf::RenderWindow(this->videomode, "Swaglords of Space!", sf::Style::Titlebar | sf::Style::Close);
	
	// Framerate
	this->window->setFramerateLimit(60);
	
	// Vertical sync
	this->window->setVerticalSyncEnabled(false);
}

// INIT TEXTURES
void Game::initTextures()
{
	// Creating space for textures for bullet
	this->textures["BULLET"] = new sf::Texture();

	// Loading texture from file
	if (!this->textures["BULLET"]->loadFromFile("Textures/bullet.png"))
		std::cout << "ERROR::GAME::INITTEXTURES::Couldn't load textures\n";	
}

void Game::initFonts()
{
	// Load font
	if (!this->font.loadFromFile("Fonts/PixellettersFull.ttf"))
	{
		std::cout << "ERROR::GAME::INITGUI::Couldn't load font\n";
	}
}

// INIT GUI
void Game::initGUI()
{
	// Init point text
	this->pointsText.setFont(this->font);
	this->pointsText.setCharacterSize(30);
	this->pointsText.setFillColor(sf::Color::White);
	this->pointsText.setString("NONE");
	this->pointsText.setPosition(sf::Vector2f(10, 10));
}

void Game::initWorld()
{
	if (!this->worldTexture.loadFromFile("Textures/background1.jpg"))
		std::cout << "ERROR::GAME::INITTEXTURES::Couldn't load textures\n";

	this->worldBG.setTexture(this->worldTexture);
}

// INIT PLAYER
void Game::initPlayer()
{
	this->player = new Player(0, 0);

	// Center spawn
	float centerWindow = static_cast<float>(this->window->getSize().x) / 2;
	float playerX = centerWindow - this->player->getBounds().width / 2;
	float playerY = this->window->getSize().y - this->player->getBounds().height;

	this->player->setPos(playerX, playerY);
}

// INIT ENEMIES
void Game::initEnemies()
{
	this->spawnTimerMax = 30;
	this->spawnTimer = this->spawnTimerMax;
}

// Constructor
Game::Game()
{
	this->initVariables();
	this->initWindow();

	this->initFonts();
	this->initGUI();
	this->initWorld();

	this->initTextures();
	this->initPlayer();
	this->initEnemies();
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

	// Delete enemies
	for (auto& i : this->enemies)
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

// UPDATE
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

// WINDOW BONDS COLLISION
void Game::updateWindowBounds(sf::RenderTarget* target)
{
	/*
		@return void
		Checks collisions with window bonds.
		Doesn't allow player to go out from window.
	*/
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPos(0.f, this->player->getPos().y);
	}
	if (this->player->getBounds().left + this->player->getBounds().width > target->getSize().x)
	{
		this->player->setPos(target->getSize().x - this->player->getBounds().width, this->player->getPos().y);
	}
	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPos(this->player->getPos().x, 0.f);
	}
	if (this->player->getBounds().top + this->player->getBounds().height > target->getSize().y)
	{
		this->player->setPos(this->player->getPos().x, target->getSize().y - this->player->getBounds().height);
	}
}

// INPUT FROM PLAYER
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

	// ATTACK ON LEFT CLICK
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		// Spawning a bullet
		Bullet* tempBullet = new Bullet(
			this->textures["BULLET"],
			this->player->getCenterPosX(),
			this->player->getPos().y,
			0, -1, this->bulletSpeed
		);

		

		this->bullets.push_back(tempBullet);
	}
}

void Game::updateGUI()
{
	std::stringstream Spoints;
	Spoints << "Points: " << this->points << "\n";

	this->pointsText.setString(Spoints.str());
}

// UPDATE BULLETS
void Game::updateBullets()
{
	/*
		@return void

		Updating everything about bullets
		- goes through a vector of bullets
		- bullet culling (reached top of the screen)
		- delete bullet
	*/

	// iterator count
	size_t count{};

	// going through a vector of bullets
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

// UPDATE ENEMIES
void Game::updateEnemiesAndCombat()
{
	/*
		@return void
		Updating everything about enemies
		- spawns enemies with cooldown
		- at random position
	*/

	// Spawn enemies with timer
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		// Create temp Enemy object
		Enemy* tempEnemy = new Enemy(0, 0);


		// Simple check if enemy's rand position intersects window bounds
		float randX = static_cast<float>(rand() % this->window->getSize().x);
		if (randX + tempEnemy->getBounds().width > this->window->getSize().x)
		{
			randX = randX - tempEnemy->getBounds().width;
		}

		tempEnemy->setPos(randX, -50);

		// Push to vector with enemies nwe member
		this->enemies.push_back(tempEnemy);

		this->spawnTimer = 0.f; // Reset timer
	}

	// Go through enemies vector
	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		bool isEnemyRemoved = false;

		this->enemies[i]->update();

		// COMBAT
		for (size_t j{}; j < this->bullets.size() && !isEnemyRemoved; ++j)
		{
			if (this->bullets[j]->getBounds().intersects(this->enemies[i]->getBounds()))
			{
				this->bullets.erase(this->bullets.begin() + j);
				this->enemies.erase(this->enemies.begin() + i);
				isEnemyRemoved = true;
			
				this->points += 1;
			}
		}
	
		// Remove enemies which outside the screen
		if (!isEnemyRemoved && this->enemies[i]->getBounds().top > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			isEnemyRemoved = true;
		}
	}
}

// UPDATE
void Game::update()
{
	this->pollEvents();

	this->updateInput();

	this->player->update();

	this->updateWindowBounds(this->window);

	this->updateBullets();

	this->updateEnemiesAndCombat();

	this->updateGUI();
}

void Game::renderGUI(sf::RenderTarget* target)
{
	target->draw(this->pointsText);
}

void Game::renderWorld(sf::RenderTarget* target)
{
	target->draw(this->worldBG);
}

// RENDER
void Game::render()
{
	// Clear old frame
	this->window->clear();

	// Draw world
	this->renderWorld(this->window);

	// Draw all stuff
	this->player->render(window);

	// Draw bullets
	for (auto* bullet : this->bullets)
		bullet->render(this->window);

	// Draw enemies
	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}

	// Draw GUI
	this->renderGUI(this->window);

	// Show everything
	this->window->display();
}
