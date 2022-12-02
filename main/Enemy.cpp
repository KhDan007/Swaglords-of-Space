#include "Enemy.h"

// INIT
// INIT VARIABLES
void Enemy::initVariables()
{
	this->pointCount = static_cast<size_t>(rand() % 9 + 2); // min 3 max 10
	this->type	= 0;
	this->speed		= static_cast<float>(pointCount);
	this->hpMax	= this->pointCount;
	this->hp		= this->hpMax;
	this->damage	= this->pointCount;
	this->points	= this->pointCount;
}

// INIT SHAPE
void Enemy::initShape()
{
	this->shape.setRadius(this->pointCount * 4);
	this->shape.setPointCount(this->pointCount);
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
