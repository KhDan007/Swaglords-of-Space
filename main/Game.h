#pragma once

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

#include <map>

class Game
{
private:
	// Window
	sf::VideoMode videomode;
	sf::RenderWindow* window;
	sf::Event ev;

	bool isEndgame;

	// Resources
	std::map <std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;


	// Creating a player
	Player* player;

	// Enemies
	Enemy* enemy;

	// INIT functions
	void initVariables();
	void initWindow();
	void initTextures();
	void initPlayer();

public:
	Game();
	~Game();

	// Funcitons
	void run();

	void pollEvents();


	// UPDATE
	void updateWindowBounds(sf::RenderTarget* target);
	void updateInput();
	void updateBullets();
	
	void update();
	
	// RENDER
	void render();
};

