#pragma once
#include "SFML/Graphics.hpp"
#include "const.h"

class Player {
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Player() {
		texture.loadFromFile(IMAGES_FOLDER + "bunny1_ready.png");
		sprite.setTexture(texture);
	}
	void update();
	void draw(sf::RenderWindow& window);
};