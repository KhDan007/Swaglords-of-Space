#pragma once

/*
	Main game class. Something like a wrapper for
	whole game or Game engine.
*/

// Import player class
#include "Player.h"

// Import bullet class
#include "Bullet.h"

// Import enemy class
#include "Enemy.h"

// Include map
#include <map>


class Game
{
private:
	// Window
	sf::VideoMode videomode;
	sf::RenderWindow* window;
	sf::Event ev;

	// Resources
	std::map <std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	// Creating a player
	Player* player;

	// Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

	// Member variables
	bool isEndgame;
	
	
	// INIT functions
	void initVariables();
	void initWindow();
	void initTextures();

	void initPlayer();
	void initEnemies();

public:
	// Constructors / Destructors
	Game();
	~Game();

	// Funcitons
	void run();

	void pollEvents();


	// UPDATE
	void updateWindowBounds(sf::RenderTarget* target);
	void updateInput();
	void updateBullets();
	void updateEnemies();
	void update();
	
	// RENDER
	void render();
};

