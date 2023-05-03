#pragma once

#include <SFML/Graphics.hpp>
#include "Config.h"

using namespace sf;

class Game
{
public:

	Game();
	~Game();
	void start();

private:
	RenderWindow* window;
	Texture* background;
	Sprite* spriteBackground;

	static int gameField[WIDTH][HIGHT];
};

