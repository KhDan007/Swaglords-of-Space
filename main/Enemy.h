#pragma once

// Including SFML
#include <SFML/Graphics.hpp>

class Enemy
{
private:
	sf::CircleShape shape;
	int type;
	int hp;
	int hpMax;
	int damage;
	int points;
	float speed;

	void initVariables();
	void initShape();

public:
	// Constructors / Destructors
	Enemy(float pos_x, float pos_y);
	~Enemy();

	// Accessors
	sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget* target);
};

