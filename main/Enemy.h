#pragma once

// Including SFML
#include <SFML/Graphics.hpp>

class Enemy
{
private:
	sf::CircleShape shape;
	size_t pointCount;
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
	sf::Vector2f getPos() const;

	// Setters
	void setPos(float x, float y);

	void update();
	void render(sf::RenderTarget* target);
};

