#include "Player.h"

// INIT
void Player::initTexture()
{
	// Load a texture from file
	if (!this->texture.loadFromFile("Textures/ship.png"))
		std::cout << "ERROR::PLAYER::INITTEXTURE::Couldn't load texture from file\n";
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
