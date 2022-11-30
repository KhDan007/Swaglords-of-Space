#pragma once

// Including SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

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

