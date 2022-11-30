#include "Player.h"

// INIT
void Player::initTexture()
{

}

void Player::initSprite()
{
	// Set the texture to the sprite
	this->sprite.setTexture(this->texture);
}

// Constructor
Player::Player()
{
	this->initTexture();
	this->initSprite();
}

//Destructor
Player::~Player()
{
}


// Fucntions
void Player::update()
{
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
