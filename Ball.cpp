#include "Ball.h"
#include <iostream>

Ball::Ball(sf::Vector2f pos) {
	texture1.loadFromFile("man.png");
	ballsprite.setTexture(texture1);
	ballsprite.setOrigin(ballsprite.getLocalBounds().width / 2, ballsprite.getLocalBounds().height / 2);
	ballsprite.setPosition(pos);
	srand(time(NULL));
	int launchXDir = rand() % 2;
	float launchYDir = rand() % 20 - 10;
	if (launchXDir == 1) { velocity = { 10.0f, launchYDir }; }
	else { velocity = { -10.0f, launchYDir }; }

	//shape.setPosition(desktop.width / 2.f, desktop.height / 2.f);
}

Ball::~Ball() {


	
}

void Ball::update(sf::RenderWindow &window, Paddle& padl, Paddle& padl2) {
	ballsprite.move(velocity);
	checkCollision(window, padl, padl2);
	checkWin(window, padl, padl2);
	window.draw(ballsprite);
	

}



void Ball::checkCollision(sf::RenderWindow& window, Paddle& padl, Paddle& padl2) {


	if (padl.getBounds().contains(ballsprite.getPosition() - sf::Vector2f(ballsprite.getLocalBounds().width /2, 0))) {
		velocity.x = 0 - velocity.x;
		
	}
	else if (padl2.getBounds().contains(ballsprite.getPosition() + sf::Vector2f(ballsprite.getLocalBounds().width / 2, 0))) {
		velocity.x = 0 - velocity.x;

	}
	else if (ballsprite.getPosition().y - ballsprite.getLocalBounds().height / 2 <= 0) {
		std::cout << "TOP COLLISION" << std::endl;
		velocity.y = 0 - velocity.y;
	}
	else if (ballsprite.getPosition().y + ballsprite.getLocalBounds().height / 2 >= window.getSize().y) {
		std::cout << "BOTTOM COLLISION" << std::endl;
		velocity.y = 0 - velocity.y;

	}
	
}

void Ball::checkWin(sf::RenderWindow& window, Paddle& padl, Paddle& padl2) {

	if (ballsprite.getPosition().x - ballsprite.getLocalBounds().width / 2 <= 0) {
	std::cout << "Loser! Loser! Loser! Loser! Loser! Loser! Loser! Loser! Loser! " << std::endl;
	}
	else if (ballsprite.getPosition().x + ballsprite.getLocalBounds().width / 2 >= window.getSize().x) {
		std::cout << "Win! Win! Win! Win! Win! Win! Win! Win! Win! Win! Win!" << std::endl;
	}

	

}