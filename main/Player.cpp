#include "Player.h"

// INIT
// INIT VARIABLES
void Player::initVaraibles()
{
	this->movementSpeed = 10.f;

	this->attackCoolDownMax = 10.f;
	this->attackCoolDown = this->attackCoolDownMax;

	this->hpMax = 100;
	this->hp = this->hpMax;
}

// INIT TEXTURES
void Player::initTexture()
{
	// Load a texture from file
	if (!this->texture.loadFromFile("Textures/ship.png"))
		std::cout << "ERROR::PLAYER::INITTEXTURE::Couldn't load texture from file\n";
}

// INIT SPRITE
void Player::initSprite()
{
	// Set the texture to the sprite
	this->sprite.setTexture(this->texture);

	// Resize
	this->sprite.scale(0.08f, 0.08f);
}

// Constructor
Player::Player(float pos_x, float pos_y)
{
	this->sprite.setPosition(pos_x, pos_y);

	this->initVaraibles();
	this->initTexture();
	this->initSprite();
}

//Destructor
Player::~Player()
{
}

// Getters
// Get position of player
const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

float Player::getCenterPosX()
{
	return this->getPos().x + this->sprite.getGlobalBounds().width / 2 -2.5f;
}

sf::FloatRect Player::getBounds()
{
	return this->sprite.getGlobalBounds();
}

const int Player::getHp() const
{
	return this->hp;
}

const int Player::getHpMax() const
{
	return this->hpMax;
}

// Setters
void Player::setPos(float pos_x, float pos_y)
{
	this->sprite.setPosition(sf::Vector2f(pos_x, pos_y));
}

void Player::setHp(int value)
{
	this->hp = value;
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

void Player::loseHp(int value)
{
	this->hp -= value;

	if (this->hp < 0)
		this->hp = 0;
}


// UPDATE
void Player::updateAttack()
{
	if (this->attackCoolDown < this->attackCoolDownMax)
	{
		this->attackCoolDown += 1;
	}
}

void Player::update()
{
	this->updateAttack();
}


// RENDER
void Player::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
