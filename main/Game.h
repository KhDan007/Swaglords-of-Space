#pragma once

#include "Player.h"

class Game
{
private:
	sf::VideoMode videomode;
	sf::RenderWindow* window;
	sf::Event ev;

	bool isEndgame;

	// INIT functions
	void initVariables();
	void initWindow();

public:
	Game();
	~Game();

	// Funcitons
	void run();

	void pollEvents();

	void update();
	void render();
};

