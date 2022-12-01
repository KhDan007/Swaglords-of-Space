#pragma once

#include "Player.h"

class Game
{
private:
	sf::VideoMode videomode;
	sf::RenderWindow* window;
	sf::Event ev;

	bool isEndgame;

	// Creating a player
	Player* player;

	// INIT functions
	void initVariables();
	void initWindow();
	void initPlayer();

public:
	Game();
	~Game();

	// Funcitons
	void run();

	void pollEvents();



	// UPDATE
	void updateMove();
	void update();
	
	// RENDER
	void render();
};

