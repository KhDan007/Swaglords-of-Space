#pragma once

// Including SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

// Including Input/Output stream
#include <iostream>


class Bullet
{
private:
	// creating sprite
	sf::Sprite shape;

	// Member varialbes
	sf::Vector2f direction;
	float movementSpeed = 0;

public:
	// Constructors / Destructors
	Bullet();
	Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed);
	virtual ~Bullet();

	// Accessor
	sf::FloatRect getBounds() const; // Get global bounds of bullet

	// Setters

	// Functions
	void update();
	void render(sf::RenderTarget* target);
};

