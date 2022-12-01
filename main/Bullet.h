#pragma once

// Including SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

// Including Input/Output stream
#include <iostream>


class Bullet
{
private:
	sf::Sprite sprite;
	sf::Texture* texture;

public:
	Bullet();
	virtual ~Bullet();

	// Functions
	void update();
	void render();
};

