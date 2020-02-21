#include "Paddle.h"
#include <iostream>

Paddle::Paddle(sf::Vector2f pos) {
	texture1.loadFromFile("paddle.png");
	paddlesprite.setTexture(texture1);
	paddlesprite.setOrigin(paddlesprite.getLocalBounds().width / 2, paddlesprite.getLocalBounds().height / 2);
	edgebuffer = 20;
	paddlesprite.setPosition(pos);
	//shape.setPosition(desktop.width / 2.f, desktop.height / 2.f);
}

Paddle::~Paddle() {


	
}

void Paddle::setSpeed(float speed) {
	acceleration = speed;
	//posMaxAcc = acceleration * 10;
	//negMaxAcc = acceleration * -10;
}

void Paddle::update(sf::RenderWindow& window) {
	paddlesprite.move(velocity);
	checkCollision(window);
	window.draw(paddlesprite);
	

}



void Paddle::movepaddle(Paddledir direction, sf::RenderWindow& window) {
	if (direction == Paddledir::down) {
			velocity.y = acceleration;
	}
	else if (direction == Paddledir::up) {
			velocity.y = -acceleration;
	}

	else {
		velocity.y = 0;
		//paddlesprite.setPosition(sf::Vector2f(paddlesprite.getPosition().x, window.getSize().y - paddlesprite.getLocalBounds().height / 2));
	}
}

//void Paddle::setPosition(sf::Vector2f pos) {
//	paddlesprite.setPosition(pos);
//}

//sf::Sprite Paddle::getSprite() {
//
//	return paddlesprite;
//
//}

void Paddle::checkCollision(sf::RenderWindow& window) {

	if (paddlesprite.getPosition().y + paddlesprite.getLocalBounds().height / 2 >= window.getSize().y) {
		paddlesprite.setPosition(sf::Vector2f(paddlesprite.getPosition().x, (window.getSize().y - paddlesprite.getLocalBounds().height / 2) - edgebuffer));
	}

	if (paddlesprite.getPosition().y - paddlesprite.getLocalBounds().height / 2 <= 0) {
		paddlesprite.setPosition(sf::Vector2f(paddlesprite.getPosition().x, paddlesprite.getLocalBounds().height / 2 + edgebuffer));
	}

	

}

sf::FloatRect Paddle::getBounds() {

	return paddlesprite.getGlobalBounds();

}