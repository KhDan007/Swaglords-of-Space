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
}

// INIT SHAPE
void Enemy::initShape()
{
	this->shape.setRadius(rand()%30+10);
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


// Functions
void Enemy::update()
{
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
