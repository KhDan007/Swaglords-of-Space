#pragma once

// Including SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Including Input/Output stream
#include <iostream>

/*
	Player class. Can:
	- move
	- shoot
	Have:
	- textures
*/

class Player
{
private:
	// Creating sprite
	sf::Sprite sprite;

	// Textures
	sf::Texture texture;

	// Member variables
	float movementSpeed;

	float attackCoolDown;
	float attackCoolDownMax;

	// INIT Funcitons
	void initVaraibles();
	void initTexture();
	void initSprite();

public:
	// Constructors / Destructors
	Player(float pos_x, float pos_y);
	~Player();

	// Getters
	const sf::Vector2f& getPos() const; // Get position of the player
	float getCenterPosX(); // Get central position of player by X

	sf::FloatRect getBounds(); // Get global bounds of player

	// Setters
	void setPos(float pos_x, float pos_y); // Set position of player

	// Functions
	void move(const float dirX, const float dirY);
	bool canAttack();

	void updateAttack();
	void update();
	
	void render(sf::RenderTarget* target);
};

