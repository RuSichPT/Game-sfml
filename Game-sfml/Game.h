#pragma once

#include <SFML/Graphics.hpp>

#define WIDTH (8)
#define HIGHT (8)
#define SCALE (0.3)

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

