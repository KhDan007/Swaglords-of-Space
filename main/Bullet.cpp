#include "Bullet.h"

// CONSTRUCTORS / DESTRUCTORS
Bullet::Bullet() {

}

Bullet::Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	this->shape.setTexture(*texture);
	this->shape.setPosition(pos_x, pos_y);
	this->shape.setScale(sf::Vector2f(0.6, 0.6));

	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
}

Bullet::~Bullet()
{
}

sf::FloatRect Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
}


// Functions

// UPDATE
void Bullet::update()
{
	// Movement
	this->shape.move(this->movementSpeed * this->direction);
}


// RENDER
void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
