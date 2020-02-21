#pragma once
#include <SFML/Graphics.hpp>

enum Paddledir {
	up = 1,
	down = 2,
	none = 0

};


class Paddle
{
private:
	sf::Sprite paddlesprite; // MAKE SPRITE
	sf::Texture texture1;
	sf::Vector2f velocity = { 0, 0 };
	float acceleration = 1.f;
	int edgebuffer;
	//float posMaxAcc = 10;
	//float negMaxAcc = -10;
	

public:
	Paddle(sf::Vector2f pos);
	~Paddle();
	void movepaddle(Paddledir direction, sf::RenderWindow& window);
	void update(sf::RenderWindow& window);
	void setSpeed(float speed);
	//sf::Sprite getSprite();
	//void setPosition(sf::Vector2f pos);
	void checkCollision(sf::RenderWindow& window);
	sf::FloatRect getBounds();
};

