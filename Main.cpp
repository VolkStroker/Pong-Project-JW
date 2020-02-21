//  SFML Demo

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Ball.h"
#include "Paddle.h"

int main() {
	
	Paddledir direction = Paddledir::none;
	
	sf::RenderWindow window(sf::VideoMode(1440, 900), "ScrumBums SFML: Look it works!"); // WINDOW MODE
	//sf::VideoMode desktop = sf::VideoMode().getDesktopMode(); // FULLSCREEN MODE
	//sf::RenderWindow window(desktop, "SFML works!", sf::Style::None); // FULLSCREEN MODE
	window.setVerticalSyncEnabled(true);


	sf::Vector2f centerpoint = { window.getSize().x / 2.f, window.getSize().y / 2.f };
	sf::Vector2f leftPadPos = { window.getSize().x * .05f, window.getSize().y / 2.f };
	sf::Vector2f rightPadPos = { window.getSize().x * .95f, window.getSize().y / 2.f };
	float paddleSpeed = 20.0f;

	
	Paddle paddleL(leftPadPos);
	paddleL.setSpeed(paddleSpeed);

	Paddle paddleR(rightPadPos);
	paddleR.setSpeed(paddleSpeed*2);

	Ball ball1(centerpoint);


	


	sf::Sprite background; // MAKE BACKGROUND
	sf::Texture backgroundtex;
	backgroundtex.loadFromFile("background.png");
	background.setTexture(backgroundtex);
	backgroundtex.setSmooth(true);
	background.setPosition(0,0);
	background.setScale(window.getSize().x / background.getLocalBounds().width, window.getSize().y / background.getLocalBounds().height);

	
	
	
	while (window.isOpen()) {    // RUN THE LOOP
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				if (event.key.code == sf::Keyboard::Up) {
					direction = Paddledir::up;
				}
				if (event.key.code == sf::Keyboard::Down) {
					direction = Paddledir::down;
				}
				break;
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Right)
					direction = Paddledir::none;
				if (event.key.code == sf::Keyboard::Left)
					direction = Paddledir::none;
				if (event.key.code == sf::Keyboard::Up)
					direction = Paddledir::none;
				if (event.key.code == sf::Keyboard::Down)
					direction = Paddledir::none;
				break;
			}
		}

		
		
		
		window.clear();
		window.draw(background);
		paddleL.movepaddle(direction, window);
		paddleL.update(window);		
		paddleR.movepaddle(direction, window);
		paddleR.update(window);
		ball1.update(window, paddleL, paddleR);
		window.display();
	}

	return 0;
}