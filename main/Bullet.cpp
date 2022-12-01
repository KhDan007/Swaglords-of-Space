#include "Bullet.h"



// CONSTRUCTORS / DESTRUCTORS
Bullet::Bullet() {

}

Bullet::Bullet(sf::Texture* texture, float dir_x, float dir_y, float movement_speed)
{
	this->shape.setTexture(*texture);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
}

Bullet::~Bullet()
{
}


// Functions

// UPDATE
void Bullet::update()
{
	// Movement
	this->shape.move(this->movementSpeed * this->direction);
}


// Render
void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
