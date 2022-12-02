#include "Enemy.h"


void Enemy::initVariables()
{
	this->type	= 0;
	this->hpMax	= 10;
	this->hp		= hpMax;
	this->damage	= 1;	
	this->points	= 0;
}

void Enemy::initShape()
{
	this->shape.setRadius(rand()%30+10);
	this->shape.setPointCount(4);
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
