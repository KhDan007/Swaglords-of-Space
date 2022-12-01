#pragma once

// Including SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Including Input/Output stream
#include <iostream>

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;

	float attackCoolDown;
	float attackCoolDownMax;

	// INIT Funcitons
	void initVaraibles();
	void initTexture();
	void initSprite();

public:
	Player();
	~Player();

	// Accessors
	const sf::Vector2f& getPos() const;
	float getCenterPosX();

	// Functions
	void move(const float dirX, const float dirY);
	bool canAttack();

	void updateAttack();
	void update();
	
	void render(sf::RenderTarget* target);
};

