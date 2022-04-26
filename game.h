#pragma once
#include <SFML/Graphics.hpp>

class Game {
public:
	enum class GameState { INTRO, PLAY, GAME_OVER };
	Game();
	void play();

private:
	sf::RenderWindow window;
	GameState game_state = GameState::PLAY;

	void check_events();
	void update();
	void draw();
	void check_collisions();
};