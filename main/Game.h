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

// Import map
#include <map>

// Import sstream
#include <sstream>

class Game
{
private:
	// Window
	sf::VideoMode videomode;
	sf::RenderWindow* window;
	sf::Event ev;

	// GUI
	sf::Font font;
	sf::Text pointsText;

	// World
	sf::Texture worldTexture;
	sf::Sprite worldBG;
	
	// Member variables
	bool isEndgame;
	int points;
	float bulletSpeed;

	// Resources
	std::map <std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	// Creating a player
	Player* player;

	// Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

	
	// INIT functions
	void initVariables();
	void initWindow();
	void initTextures();

	void initFonts();
	void initGUI();
	void initWorld();

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

	void updateGUI();

	void updateBullets();
	
	void updateEnemiesAndCombat();
	
	void update();
	
	// RENDER
	void renderGUI(sf::RenderTarget* target);

	void renderWorld(sf::RenderTarget* target);

	void render();
};

