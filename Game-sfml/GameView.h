#pragma once

#include <SFML/Graphics.hpp>
#include "Figure.h"
#include "Config.h"

class Game;

using namespace sf;

class GameView
{
public:
	GameView(Game* game);
	~GameView();
	void drow();

	RenderWindow* getRenderWindow() { return window; }
private:
	Game* game;
	RenderWindow* window;
	Texture* background;
	Sprite* spriteBackground;

	Figure* figuresBlack[NUM_FIGURES * NUM_FIGURES] = { nullptr };
	Figure* figuresWhite[NUM_FIGURES * NUM_FIGURES] = { nullptr };

	void initBackground();
	void initRenderWindow();
	void initFigures();
};

