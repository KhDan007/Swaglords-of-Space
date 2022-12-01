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

	// Resize
	this->sprite.scale(0.08f, 0.08f);
}

// Constructor
Player::Player()
{
	this->movementSpeed = 5.f;

	this->initTexture();
	this->initSprite();
}

//Destructor
Player::~Player()
{
}




// Fucntions
void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(movementSpeed * dirX, movementSpeed * dirY);
}


// UPDATE
void Player::update()
{
}


// RENDER
void Player::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
