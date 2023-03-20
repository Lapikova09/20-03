#pragma once
#include "settings.h"
#include <SFML/Graphics.hpp>
class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speedX = 0.f;
public:
	Player() {
		texture.loadFromFile("playerShip.png");
		sprite.setTexture(texture);
		sprite.setPosition(START_POS);
	}
	void update() {
		speedX = 0.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			speedX = -SPEED_X;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			speedX = SPEED_X;
		}
		if (sprite.getPosition().x < 0) {
			sprite.setPosition(0.f, sprite.getPosition().y);
		}
		else if (sprite.getPosition().x > WINDOW_WIDTH - sprite.getGlobalBounds().width) {
			sprite.setPosition(WINDOW_WIDTH - sprite.getGlobalBounds().width, sprite.getPosition().y);
		}
	}
	sf::Sprite getSprite() { return sprite; }
	
};