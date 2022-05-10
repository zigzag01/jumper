#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

class Player {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f acc = sf::Vector2f(0.f, 0.f);
	sf::Vector2f speed = sf::Vector2f(0.f, 0.f);
	sf::Vector2f pos = sf::Vector2f(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT - 250.f);
public:
	Player() {
		texture.loadFromFile(
			IMAGES_FOLDER +
			PLAYER_IMAGES_FOLDER +
			PLAYER_IMAGE_FILENAME);
		sprite.setTexture(texture);
	}
	void update() {
		if (!isJumping) {
			acc = sf::Vector2f(0.f, GRAVITY);
		}
		else if (!isJumping) { acc = sf::Vector2f(0.f, 0.f); }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			acc.x = -PLAYER_ACC_X;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			acc.x = PLAYER_ACC_X;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			jump();
			isJumping = true;
		}

		acc.x += speed.x * FRICTION;
		speed += acc;
		pos += speed + sf::Vector2f(0.5f * acc.x, 0.5f * acc.y);
		if (pos.x > WINDOW_WIDTH - getHitBox().width/2.f) {
			pos.x = 0 - getHitBox().width / 2.f;
		}
		if (pos.x < 0 - getHitBox().width / 2.f) {
			pos.x = WINDOW_WIDTH - getHitBox().width / 2.f;
		}

		sprite.setPosition(pos);

	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}

	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }

	void jump() {
		if (!isJumping) speed.y = JUMP_SPEED;
	}
	bool getIsJumping() { return isJumping; }
	void setIsJumping(bool param) { isJumping = param; }
	void resetSpeed() { speed.y = 0.f; }
	void setPosition(sf::Vector2f position) { sprite.setPosition(pos); }
};