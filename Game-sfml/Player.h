#pragma once
#include "Config.h"

class Game;

class Player
{
public:
	Player(Game* game) :game{ game } {};
	void act();
private:
	Game* game;
	Cell from;
	Cell to;
};

