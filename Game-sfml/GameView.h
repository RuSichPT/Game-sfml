#pragma once

#include <SFML/Graphics.hpp>
#include "Figure.h"
#include "Config.h"


using namespace sf;

class GameView
{
public:
	GameView(Cell** gameField);
	~GameView();
	void drow();

	RenderWindow* getRenderWindow() { return window; }
private:
	RenderWindow* window;
	Texture* background;
	Sprite* spriteBackground;
	Cell** gameField;

	Figure* figuresBlack[NUM_FIGURES * NUM_FIGURES] = { nullptr };
	Figure* figuresWhite[NUM_FIGURES * NUM_FIGURES] = { nullptr };

	void initBackground();
	void initRenderWindow();
	void initFigures();
};

