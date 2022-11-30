#pragma once

// Including SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	// INIT Funcitons
	void initTexture();
	void initSprite();

public:
	Player();
	~Player();


	// Functions
	void update();
	void render(sf::RenderTarget* target);
};

