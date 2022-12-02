#include "Enemy.h"

// INIT
// INIT VARIABLES
void Enemy::initVariables()
{
	this->type	= 0;
	this->hpMax	= 10;
	this->hp		= hpMax;
	this->damage	= 1;	
	this->points	= 0;
	this->speed		= 4.f;
}

// INIT SHAPE
void Enemy::initShape()
{
	this->shape.setRadius(rand() % 20 + 20);
	this->shape.setPointCount(static_cast<float>(rand() % 4 + 3));
	this->shape.setFillColor(sf::Color(rand() % 200 + 55, rand() % 200 + 55, rand() % 200 + 55, 255));
}

// Constructors / Destructors
Enemy::Enemy(float pos_x, float pos_y)
{
	this->shape.setPosition(sf::Vector2f(pos_x, pos_y));

	this->initVariables();
	this->initShape();
}

Enemy::~Enemy()
{
}


// Accessors
sf::FloatRect Enemy::getBounds() const
{
	return this->shape.getGlobalBounds();
}

sf::Vector2f Enemy::getPos() const
{
	return this->shape.getPosition();
}

void Enemy::setPos(float x, float y)
{
	this->shape.setPosition(sf::Vector2f(x, y));
}

// Functions
void Enemy::update()
{
	// Move enemies down
	this->shape.move(0.f, this->speed);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
