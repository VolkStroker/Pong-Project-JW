#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"




class Ball
{
private:
	sf::Sprite ballsprite; // MAKE SPRITE
	sf::Texture texture1;
	sf::Vector2f velocity;
	

public:
	Ball(sf::Vector2f pos);
	~Ball();
	void update(sf::RenderWindow& window, Paddle& padl, Paddle& padl2);
	void checkCollision(sf::RenderWindow& window, Paddle& padl, Paddle& padl2);
	void checkWin(sf::RenderWindow& window, Paddle& padl, Paddle& padl2);
	
};

