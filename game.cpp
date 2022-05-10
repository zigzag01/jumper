#include "game.h"
#include "const.h"
Game::Game() :
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Jumper"),
	p1(0, WINDOW_HEIGHT - 55.f, WINDOW_WIDTH, 55.f)
{
	window.setVerticalSyncEnabled(true);
}
void Game::play() {
	while (window.isOpen()) {
		check_events();
		update();
		check_collisions();
		draw();
	}
}
void Game::check_events() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
void Game::update() {
	player.update();
	p1.update();
}
void Game::draw() {
	window.clear();
	player.draw(window);
	p1.draw(window);
	window.display();
}
void Game::check_collisions() {
	if (player.getHitBox().intersects(p1.getHitBox())) {
		player.getIsJumping(false);
		player.resetSpeed();
		sf::Vector2f platform_pos = p1.getPosition();
		sf::Vector2f player_new_pos = sf::Vector2f(player.getPosition().x, platform_pos.y - player.getHitBox().height);
		player.setPosition(player_new_pos);
}
