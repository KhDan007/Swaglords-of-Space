#include "Player.h"

void Player::initVaraibles()
{
	this->movementSpeed = 5.f;

	this->attackCoolDownMax = 8.f;
	this->attackCoolDown = this->attackCoolDownMax;
}

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
	this->initVaraibles();
	this->initTexture();
	this->initSprite();
}

//Destructor
Player::~Player()
{
}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

float Player::getCenterPosX()
{
	return this->getPos().x + this->sprite.getGlobalBounds().width / 2 -5.f;
}




// Fucntions
void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(movementSpeed * dirX, movementSpeed * dirY);
}

bool Player::canAttack()
{
	if (this->attackCoolDown >= this->attackCoolDownMax)
	{
		this->attackCoolDown = 0.f;
		return true;
	}
	return false;
}


void Player::updateAttack()
{
	if (this->attackCoolDown < this->attackCoolDownMax)
	{
		this->attackCoolDown += 0.5;
	}
	else {

	}

}

// UPDATE
void Player::update()
{
	this->updateAttack();
}


// RENDER
void Player::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
