#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Game;

class EventHandler
{
public:
	EventHandler(Game* game) :game{ game } {};

	void handle();
private:
	Game* game;
};

