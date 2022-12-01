#pragma once

// Including SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

// Including Input/Output stream
#include <iostream>


class Bullet
{
private:
	sf::Sprite shape;

	sf::Vector2f direction;
	float movementSpeed;

public:
	Bullet();
	Bullet(sf::Texture* texture, float dir_x, float dir_y, float movement_speed);
	virtual ~Bullet();

	// Functions
	void update();
	void render(sf::RenderTarget* target);
};

