#pragma once

#include "Player.h"
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
	std::map <std::string, sf::Texture> textures;


	// Creating a player
	Player* player;

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
	void updateMove();
	void update();
	
	// RENDER
	void render();
};

